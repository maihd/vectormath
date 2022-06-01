#include "Renderer.h"
#include "GLLoader.h"
#include "Native/Window.h"

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>

#include <memory.h>
#define stackalloc(size)    _malloca(size)
#define stackfree(ptr)      _freea(ptr)

#define WIN32_LEAN_AND_MEAN
#define VK_USE_PLATFORM_WIN32_KHR
#include <windows.h>
#include <vulkan/vulkan_win32.h>

#define STB_IMAGE_IMPLEMENTATION
#include <3rd_party/stb/stb_image.h>
#include <3rd_party/stb/stb_easy_font.h>

static WindowDesc*          gMainWindow;

static VkInstance           gVulkanInstance;

static VkDevice             gVulkanDevice;
static VkPhysicalDevice     gVulkanPhysicalDevice;

static VkQueue              gVulkanGraphicsQueue;
static VkQueue              gVulkanPresentQueue;

static VkSurfaceKHR         gVulkanSurface;
static VkSwapchainKHR       gVulkanSwapchain;

static uint32_t             gVulkanSwapchainImageCount;
static VkImage              gVulkanSwapchainImages[8];

static uint32_t             gVulkanSwapchainImageViewCount;
static VkImageView          gVulkanSwapchainImageViews[8];

constexpr const char* gVulkanWantedExtensions[] = {
    VK_KHR_SURFACE_EXTENSION_NAME,

#ifdef VK_USE_PLATFORM_WIN32_KHR
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
#endif

#if 0
    VK_EXT_DEBUG_UTILS_EXTENSION_NAME,
#else
    VK_EXT_DEBUG_REPORT_EXTENSION_NAME,
#endif

    //VK_KHR_SWAPCHAIN_EXTENSION_NAME,
    VK_EXT_SWAPCHAIN_COLOR_SPACE_EXTENSION_NAME,
};

constexpr const char* gVulkanWantedValidationLayers[] = {
#if !defined(NDEBUG)
    "VK_LAYER_KHRONOS_validation"
#endif
};

static void Renderer_LogInfo(const char* format, ...)
{
    printf("[Renderer] ");

    va_list argv;
    va_start(argv, format);
    vprintf(format, argv);
    va_end(argv);

    printf("\n");
}

static bool Renderer_CreateVkInstance(const char* appName)
{
    uint32_t layersCount = 0;
    vkEnumerateInstanceLayerProperties(&layersCount, nullptr);

    uint32_t extensionsCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionsCount, nullptr);

    Renderer_LogInfo("Vulkan layers count: %d", layersCount);
    Renderer_LogInfo("Vulkan extensions count: %d", extensionsCount);

    VkLayerProperties* layers = (VkLayerProperties*)stackalloc(sizeof(VkLayerProperties) * layersCount);
    vkEnumerateInstanceLayerProperties(&layersCount, layers);

    VkExtensionProperties* extensions = (VkExtensionProperties*)stackalloc(sizeof(VkExtensionProperties) * extensionsCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionsCount, extensions);

    for (const char* wantedLayerName : gVulkanWantedValidationLayers)
    {
        bool layerFound = false;
        for (uint32_t i = 0; i < layersCount; i++)
        {
            Renderer_LogInfo("VkInstanceLayer: %s", layers[i].layerName);
            if (strcmp(layers[i].layerName, wantedLayerName) == 0)
            {
                layerFound = true;
                break;
            }
        }

        if (!layerFound)
        {
            Renderer_LogInfo("Validation layer not found: %s", wantedLayerName);
            return false;
        }
    }

    for (uint32_t i = 0; i < extensionsCount; i++)
    {
        Renderer_LogInfo("VkInstanceExtension: %s", extensions[i].extensionName);
    }

    stackfree(extensions);
    stackfree(layers);

    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = appName;
    appInfo.applicationVersion = VK_MAKE_API_VERSION(1, 0, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_API_VERSION(1, 0, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo instanceCreateInfo = {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;

    instanceCreateInfo.enabledExtensionCount = sizeof(gVulkanWantedExtensions) / sizeof(gVulkanWantedExtensions[0]);
    instanceCreateInfo.ppEnabledExtensionNames = gVulkanWantedExtensions;

    instanceCreateInfo.enabledLayerCount = sizeof(gVulkanWantedValidationLayers) / sizeof(gVulkanWantedValidationLayers[0]);
    instanceCreateInfo.ppEnabledLayerNames = gVulkanWantedValidationLayers;
   
    VkResult result = vkCreateInstance(&instanceCreateInfo, nullptr, &gVulkanInstance);
    return result == VK_SUCCESS;
}

static void Renderer_DestroyVkInstance()
{
    vkDestroyInstance(gVulkanInstance, nullptr);
    gVulkanInstance = VK_NULL_HANDLE;
}

static VkPhysicalDevice Renderer_SelectVkPhysicalDevice(VkInstance instance)
{
    VkPhysicalDevice pickedDevice = VK_NULL_HANDLE;
    
    uint32_t availableDeviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &availableDeviceCount, nullptr);

    if (availableDeviceCount == 0)
    {
        return pickedDevice;
    }

    VkPhysicalDevice* availableDevices = (VkPhysicalDevice*)stackalloc(availableDeviceCount * sizeof(VkPhysicalDevice));
    vkEnumeratePhysicalDevices(instance, &availableDeviceCount, availableDevices);

    for (uint32_t i = 0; i < availableDeviceCount; i++)
    {
        VkPhysicalDevice device = availableDevices[i];

        VkPhysicalDeviceProperties deviceProperties;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);

        VkPhysicalDeviceFeatures deviceFeatures;
        vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

        uint32_t extensionsCount = 0;
        vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionsCount, nullptr);

        VkExtensionProperties* extensions = (VkExtensionProperties*)stackalloc(extensionsCount * sizeof(VkExtensionProperties));
        vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionsCount, extensions);
        
        bool foundRequiredExtensions = false;
        for (uint32_t extensionsIndex = 0; extensionsIndex < extensionsCount; extensionsIndex++)
        {
            if (strcmp(extensions[extensionsIndex].extensionName, VK_KHR_SWAPCHAIN_EXTENSION_NAME) == 0)
            {
                foundRequiredExtensions = true;
                break;
            }
        }

        if (device != VK_NULL_HANDLE
            && foundRequiredExtensions
            && deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU 
            && deviceFeatures.geometryShader)
        {
            pickedDevice = device;
            break;
        }
    }

    stackfree(availableDevices);
    
    return pickedDevice;
}

static int Renderer_SelectGraphicsQueueFamilyIndex(VkPhysicalDevice device)
{
    int result = -1;

    uint32_t queueFamiliesCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamiliesCount, nullptr);

    VkQueueFamilyProperties* queueFamilies = (VkQueueFamilyProperties*)stackalloc(queueFamiliesCount * sizeof(VkQueueFamilyProperties));
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamiliesCount, queueFamilies);

    for (uint32_t i = 0; i < queueFamiliesCount; i++)
    {
        const VkQueueFamilyProperties* queueFamily = queueFamilies + i;

        if (queueFamily->queueFlags & VK_QUEUE_GRAPHICS_BIT)
        {
            result = i;
            break;
        }
    }

    stackfree(queueFamilies);

    return result;
}

static int Renderer_SelectPresentQueueFamilyIndex(VkPhysicalDevice device, uint32_t graphicsQueueFamilyIndex, VkSurfaceKHR surface)
{
    int result = -1;

    uint32_t queueFamiliesCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamiliesCount, nullptr);

    VkQueueFamilyProperties* queueFamilies = (VkQueueFamilyProperties*)stackalloc(queueFamiliesCount * sizeof(VkQueueFamilyProperties));
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamiliesCount, queueFamilies);

    for (uint32_t i = 0; i < queueFamiliesCount; i++)
    {
        if (graphicsQueueFamilyIndex == i)
        {
            continue;
        }

        const VkQueueFamilyProperties* queueFamily = queueFamilies + i;

        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);

        if (presentSupport)
        {
            result = i;
            break;
        }
    }

    stackfree(queueFamilies);

    return result;
}

static bool Renderer_CreateVkDevice()
{
    VkPhysicalDevice physicalDevice = Renderer_SelectVkPhysicalDevice(gVulkanInstance);
    if (physicalDevice == VK_NULL_HANDLE)
    {
        return false;
    }

    float queuePriority = 1.0f;

    int graphicsQueueFamilyIndex = Renderer_SelectGraphicsQueueFamilyIndex(physicalDevice);
    if (graphicsQueueFamilyIndex < 0)
    {
        return false;
    }

    int presentQueueFamilyIndex = Renderer_SelectPresentQueueFamilyIndex(physicalDevice, (uint32_t)graphicsQueueFamilyIndex, gVulkanSurface);
    if (presentQueueFamilyIndex < 0)
    {
        return false;
    }
    
    VkDeviceQueueCreateInfo queueCreateInfos[2] = {};

    VkDeviceQueueCreateInfo* graphicsQueueCreateInfo = &queueCreateInfos[0];
    graphicsQueueCreateInfo->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    graphicsQueueCreateInfo->queueFamilyIndex = (uint32_t)graphicsQueueFamilyIndex;
    graphicsQueueCreateInfo->queueCount = 1;
    graphicsQueueCreateInfo->pQueuePriorities = &queuePriority;

    VkDeviceQueueCreateInfo* presentQueueCreateInfo = &queueCreateInfos[1];
    presentQueueCreateInfo->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    presentQueueCreateInfo->queueFamilyIndex = (uint32_t)presentQueueFamilyIndex;
    presentQueueCreateInfo->queueCount = 1;
    presentQueueCreateInfo->pQueuePriorities = &queuePriority;

    VkPhysicalDeviceFeatures deviceFeatures = {};

    VkDeviceCreateInfo deviceCreateInfo = {};
    deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceCreateInfo.pQueueCreateInfos = queueCreateInfos;
    deviceCreateInfo.queueCreateInfoCount = sizeof(queueCreateInfos) / sizeof(queueCreateInfos[0]);
    deviceCreateInfo.pEnabledFeatures = &deviceFeatures;

    const char* extensions[] = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
    deviceCreateInfo.enabledExtensionCount = sizeof(extensions) / sizeof(extensions[0]);
    deviceCreateInfo.ppEnabledExtensionNames = extensions;

    VkDevice device;
    if (vkCreateDevice(physicalDevice, &deviceCreateInfo, nullptr, &device) != VK_SUCCESS)
    {
        return false;
    }
    gVulkanDevice = device;
    gVulkanPhysicalDevice = physicalDevice;

    vkGetDeviceQueue(device, (uint32_t)graphicsQueueFamilyIndex, 0, &gVulkanGraphicsQueue);
    vkGetDeviceQueue(device, (uint32_t)presentQueueFamilyIndex, 0, &gVulkanPresentQueue);

    return true;
}

static void Renderer_DestroyVkDevice()
{
    vkDestroyDevice(gVulkanDevice, nullptr);
    gVulkanDevice = VK_NULL_HANDLE;
}

static bool Renderer_CreateVkSurface(WindowDesc* window)
{
    VkWin32SurfaceCreateInfoKHR createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    createInfo.hwnd = (HWND)window->handle;
    createInfo.hinstance = GetModuleHandleA(nullptr);

    VkSurfaceKHR surface;
    if (vkCreateWin32SurfaceKHR(gVulkanInstance, &createInfo, nullptr, &surface) != VK_SUCCESS)
    {
        return false;
    }
    gVulkanSurface = surface;
    return true;
}

static void Renderer_DestroyVkSurface()
{
    vkDestroySurfaceKHR(gVulkanInstance, gVulkanSurface, nullptr);
    gVulkanSurface = VK_NULL_HANDLE;
}

static bool Renderer_CreateVkSwapchain(VkDevice device, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface)
{
    VkSurfaceCapabilitiesKHR surfaceCapabilities;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, &surfaceCapabilities);

    uint32_t formatCount = 0;
    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, nullptr);

    VkSurfaceFormatKHR* formats = (VkSurfaceFormatKHR*)stackalloc(formatCount * sizeof(VkSurfaceFormatKHR));
    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, formats);

    uint32_t presentModeCount = 0;
    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, nullptr);

    VkPresentModeKHR* presentModes = (VkPresentModeKHR*)stackalloc(presentModeCount * sizeof(VkPresentModeKHR));
    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, presentModes);

    bool swapChainAdequate = formatCount > 0 && presentModeCount > 0;
    if (!swapChainAdequate)
    {
        return false;
    }

    VkSurfaceFormatKHR selectedFormat = formats[0];
    for (uint32_t i = 0; i < formatCount; i++)
    {
        if (formats[i].format == VK_FORMAT_R8G8B8A8_SRGB && formats[i].colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
        {
            selectedFormat = formats[i];
            break;
        }
    }

    VkPresentModeKHR selectedPresentMode = VK_PRESENT_MODE_FIFO_KHR;
    for (uint32_t i = 0; i < presentModeCount; i++)
    {
        if (presentModes[i] == VK_PRESENT_MODE_MAILBOX_KHR)
        {
            selectedPresentMode = presentModes[i];
            break;
        }
    }

    VkExtent2D imageExtent;
    if (surfaceCapabilities.currentExtent.width != UINT32_MAX)
    {
        imageExtent = surfaceCapabilities.currentExtent;
    }
    else if (gMainWindow != nullptr)
    {
        VkExtent2D minExtent = surfaceCapabilities.minImageExtent;
        VkExtent2D maxExtent = surfaceCapabilities.maxImageExtent;
        imageExtent.width = clamp((uint32_t)gMainWindow->width, minExtent.width, maxExtent.width);
        imageExtent.height = clamp((uint32_t)gMainWindow->height, minExtent.height, maxExtent.height);
    }

    uint32_t imageCount = surfaceCapabilities.minImageCount + 1;
    if (imageCount > surfaceCapabilities.maxImageCount && surfaceCapabilities.maxImageCount > 0)
    {
        imageCount = surfaceCapabilities.maxImageCount;
    }

    VkSwapchainCreateInfoKHR swapchainCreateInfo = {};
    swapchainCreateInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    swapchainCreateInfo.surface = surface;
    swapchainCreateInfo.minImageCount = imageCount;
    swapchainCreateInfo.imageFormat = selectedFormat.format;
    swapchainCreateInfo.imageColorSpace = selectedFormat.colorSpace;
    swapchainCreateInfo.imageExtent = imageExtent;
    swapchainCreateInfo.imageArrayLayers = 1;
    swapchainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

    int graphicsQueueFamilyIndex = Renderer_SelectGraphicsQueueFamilyIndex(gVulkanPhysicalDevice);
    if (graphicsQueueFamilyIndex < 0)
    {
        return false;
    }

    int presentQueueFamilyIndex = Renderer_SelectPresentQueueFamilyIndex(gVulkanPhysicalDevice, (uint32_t)graphicsQueueFamilyIndex, surface);
    if (presentQueueFamilyIndex < 0)
    {
        return false;
    }

    if (graphicsQueueFamilyIndex != presentQueueFamilyIndex)
    {
        uint32_t queueFamilyIndices[] = { graphicsQueueFamilyIndex, presentQueueFamilyIndex };
        swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        swapchainCreateInfo.queueFamilyIndexCount = 2;
        swapchainCreateInfo.pQueueFamilyIndices = queueFamilyIndices;
    }
    else
    {
        swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        swapchainCreateInfo.queueFamilyIndexCount = 0;
        swapchainCreateInfo.pQueueFamilyIndices = nullptr;
    }

    swapchainCreateInfo.preTransform = surfaceCapabilities.currentTransform;
    swapchainCreateInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    swapchainCreateInfo.presentMode = selectedPresentMode;
    swapchainCreateInfo.clipped = VK_TRUE;
    swapchainCreateInfo.oldSwapchain = VK_NULL_HANDLE;

    VkSwapchainKHR swapchain;
    if (vkCreateSwapchainKHR(device, &swapchainCreateInfo, nullptr, &swapchain) != VK_SUCCESS)
    {
        return false;
    }

    vkGetSwapchainImagesKHR(device, swapchain, &gVulkanSwapchainImageCount, nullptr);
    vkGetSwapchainImagesKHR(device, swapchain, &gVulkanSwapchainImageCount, gVulkanSwapchainImages);
    
    gVulkanSwapchainImageViewCount = gVulkanSwapchainImageCount;
    for (uint32_t i = 0; i < gVulkanSwapchainImageCount; i++)
    {
        VkImageViewCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        createInfo.image = gVulkanSwapchainImages[i];
        createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        createInfo.format = selectedFormat.format;
        createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        createInfo.subresourceRange.baseMipLevel = 0;
        createInfo.subresourceRange.levelCount = 1;
        createInfo.subresourceRange.baseArrayLayer = 0;
        createInfo.subresourceRange.layerCount = 1;
        
        if (vkCreateImageView(device, &createInfo, nullptr, gVulkanSwapchainImageViews + i) != VK_SUCCESS)
        {
            return false;
        }
    }

    gVulkanSwapchain = swapchain;
    return true;
}

static void Renderer_DestroyVkSwapchain()
{
    for (uint32_t i = 0; i < gVulkanSwapchainImageViewCount; i++)
    {
        vkDestroyImageView(gVulkanDevice, gVulkanSwapchainImageViews[i], nullptr);
    }

    gVulkanSwapchainImageCount = 0;
    gVulkanSwapchainImageViewCount = 0;

    vkDestroySwapchainKHR(gVulkanDevice, gVulkanSwapchain, nullptr);
    gVulkanSwapchain = VK_NULL_HANDLE;
}

int Renderer_Setup(struct WindowDesc* window)
{
    assert(gMainWindow == nullptr);

    if (!Renderer_CreateVkInstance(window->title))
    {
        return -1;
    }

    if (!Renderer_CreateVkSurface(window))
    {
        return -1;
    }

    if (!Renderer_CreateVkDevice())
    {
        return -1;
    }

    if (!Renderer_CreateVkSwapchain(gVulkanDevice, gVulkanPhysicalDevice, gVulkanSurface))
    {
        return -1;
    }

    gMainWindow = window;

    // Make black window
    Renderer_Clear();
    Renderer_Present();

    return 0;
}

void Renderer_Shutdown(struct WindowDesc* window)
{
    Renderer_DestroyVkSwapchain();

    Renderer_DestroyVkDevice();
    Renderer_DestroyVkSurface();
    Renderer_DestroyVkInstance();

    gMainWindow = nullptr;
}

void Renderer_Clear()
{
    assert(gMainWindow != nullptr);
}

void Renderer_Present()
{
    assert(gMainWindow != nullptr);
}

void Renderer_LoadSpriteSheet(SpriteSheet* spriteSheet, const char* file, int spriteCount)
{
    int width, height, channels;
    void* pixels = stbi_load(file, &width, &height, &channels, 0);
    free(pixels);

    spriteSheet->sprites = (Sprite*)malloc(spriteCount * sizeof(Sprite));
    spriteSheet->spritesCount = spriteCount;

    const float spriteWidth = (float)width / (float)spriteCount;
    const float spriteHeight = (float)height;
    
    const float invSpriteCount = 1.0f / (float)spriteCount;

    for (int i = 0; i < spriteCount; i++)
    {
        Sprite* sprite = &spriteSheet->sprites[i];
        sprite->textureId = spriteSheet->textureId;
        sprite->width = spriteWidth;
        sprite->height = spriteHeight;

        const vec2 pos0 = vec2(-0.5f, -0.5f);
        const vec2 pos1 = vec2( 0.5f,  0.5f);

        const vec2 uv0 = vec2((float)i * invSpriteCount, 1.0f);
        const vec2 uv1 = vec2((float)(i + 1) * invSpriteCount, 0.0f);

        sprite->uv0 = uv0;
        sprite->uv1 = uv1;

        const float vertices[] = {
            // pos              // tex
            pos0.x, pos0.y,     uv0.x, uv0.y,
            pos1.x, pos1.y,     uv1.x, uv1.y,
            pos0.x, pos1.y,     uv0.x, uv1.y,

            pos0.x, pos0.y,     uv0.x, uv0.y,
            pos1.x, pos0.y,     uv1.x, uv0.y,
            pos1.x, pos1.y,     uv1.x, uv1.y,
        };
    }
}

void Renderer_UnloadSpriteSheet(SpriteSheet* spriteSheet)
{
    for (int i = 0, n = spriteSheet->spritesCount; i < n; i++)
    {
        Sprite sprite = spriteSheet->sprites[i];
    }


    free(spriteSheet->sprites);

    spriteSheet->textureId = 0;

    spriteSheet->sprites = nullptr;
    spriteSheet->spritesCount = 0;
}

void Renderer_DrawSprite(const Sprite* sprite, const vec2& position, float rotation, const vec2& scale, const vec3& color)
{
    
}

vec2 Renderer_TextSize(const char* text)
{
    return vec2(stb_easy_font_width((char*)text), stb_easy_font_height((char*)text)) * 3.0f;
}

void Renderer_DrawText(const char* text, const vec2& position, const vec3& color)
{
    static float    vertices[4 * 10 * 1024]; // ~2000 chars
    static uint16_t indices[(sizeof(vertices) / sizeof(vertices[0])) / 4 * 6];
    
    const int quadsCount = stb_easy_font_print(0, 0, (char*)text, NULL, vertices, sizeof(vertices));
    const int vertexCount = quadsCount * 4;
    const int indexCount = quadsCount * 6;

    uint16_t* ptr = indices;
    for (int i = 0; i < quadsCount; i++)
    {
        uint16_t startIndex = i * 4;
        *ptr++ = startIndex + 0U;
        *ptr++ = startIndex + 1U;
        *ptr++ = startIndex + 2U;
        *ptr++ = startIndex + 0U;
        *ptr++ = startIndex + 2U;
        *ptr++ = startIndex + 3U;
    }
}

void Renderer_DrawQuad(const vec2& start, const vec2& end, const vec3& color)
{
    const vec2 pos0 = start;
    const vec2 pos1 = end;
    
    const vec2 uv0 = vec2(0.0f);
    const vec2 uv1 = vec2(0.0f);

    const float vertices[] = {
        // pos              // tex
        pos0.x, pos0.y,     uv0.x, uv0.y,
        pos1.x, pos1.y,     uv1.x, uv1.y,
        pos0.x, pos1.y,     uv0.x, uv1.y,

        pos0.x, pos0.y,     uv0.x, uv0.y,
        pos1.x, pos0.y,     uv1.x, uv0.y,
        pos1.x, pos1.y,     uv1.x, uv1.y,
    };

    
}

void SpriteBatch_Init(SpriteBatch* spriteBatch, const SpriteSheet* sheet, int vertexCount)
{
    spriteBatch->textureId = sheet->textureId;

    spriteBatch->vertices.Ensure(vertexCount);
    spriteBatch->uvs.Ensure(vertexCount);
    spriteBatch->colors.Ensure(vertexCount);
}

void SpriteBatch_CleanUp(SpriteBatch* spriteBatch)
{
    spriteBatch->vertices.CleanUp();
    spriteBatch->uvs.CleanUp();
    spriteBatch->colors.CleanUp();

    spriteBatch->textureId = 0;
    spriteBatch->vertexArrayId = 0;

    spriteBatch->verticesBufferId = 0;
    spriteBatch->uvsBufferId = 0;
    spriteBatch->colorsBufferId = 0;
}

void SpriteBatch_Begin(SpriteBatch* spriteBatch)
{
    spriteBatch->vertices.SetCount(0);
    spriteBatch->uvs.SetCount(0);
    spriteBatch->colors.SetCount(0);
}

void SpriteBatch_End(SpriteBatch* spriteBatch)
{
    
}

void SpriteBatch_DrawSprite(SpriteBatch* spriteBatch, const Sprite* sprite, const vec2& position, float rotation, const vec2& scale, const vec3& color)
{
    const mat4 model = mul(mul(mat4Translation(position), mat4RotationZ(rotation)), mat4Scalation(scale * vec2(sprite->width, sprite->height)));

    const vec2 pos0 = vec2(mul(model, vec3(-0.5f, -0.5f)));
    const vec2 pos1 = vec2(mul(model, vec3(0.5f, 0.5f)));

    const vec2 uv0 = sprite->uv0;
    const vec2 uv1 = sprite->uv1;

    spriteBatch->vertices.Push(vec2(pos0.x, pos0.y));
    spriteBatch->vertices.Push(vec2(pos1.x, pos1.y));
    spriteBatch->vertices.Push(vec2(pos0.x, pos1.y));

    spriteBatch->vertices.Push(vec2(pos0.x, pos0.y));
    spriteBatch->vertices.Push(vec2(pos1.x, pos0.y));
    spriteBatch->vertices.Push(vec2(pos1.x, pos1.y));

    spriteBatch->uvs.Push(vec2(uv0.x, uv0.y));
    spriteBatch->uvs.Push(vec2(uv1.x, uv1.y));
    spriteBatch->uvs.Push(vec2(uv0.x, uv1.y));

    spriteBatch->uvs.Push(vec2(uv0.x, uv0.y));
    spriteBatch->uvs.Push(vec2(uv1.x, uv0.y));
    spriteBatch->uvs.Push(vec2(uv1.x, uv1.y));

    spriteBatch->colors.Push(color);
    spriteBatch->colors.Push(color);
    spriteBatch->colors.Push(color);

    spriteBatch->colors.Push(color);
    spriteBatch->colors.Push(color);
    spriteBatch->colors.Push(color);
}
