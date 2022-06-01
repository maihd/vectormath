#pragma once

#include "Container/Array.h"

struct Component;
struct GameObject;

struct Component
{
    GameObject*         gameObject;

                        Component() : gameObject(nullptr) {}
    virtual             ~Component() {}

    virtual void        Start() {}
    virtual void        Update(float time, float deltaTime) {}
};

struct GameObject
{
    const char*                 name;
    Array<Component*>           components;

                                GameObject(const char* name);
                                ~GameObject();

    template <typename T> T*    GetComponent();
    template <typename T> T*    AddComponent();

    void                        AddComponent(Component* component);

    void                        Start();
    void                        Update(float time, float deltaTime);
};

inline GameObject::GameObject(const char* name)
    : name(name)
{
}

inline GameObject::~GameObject()
{
    for (int i = 0, n = components.count; i < n; i++)
    {
        delete components[i];
    }

    components.CleanUp();
}

template <typename T>
inline T* GameObject::GetComponent()
{
    for (int i = 0, n = components.count; i < n; i++)
    {
        T* component = dynamic_cast<T*>(components[i]);
        if (component != nullptr)
        {
            return component;
        }
    }

    return nullptr;
}

template <typename T>
inline T* GameObject::AddComponent()
{
    T* component = new T();
    AddComponent(component);
    return component;
}

inline void GameObject::AddComponent(Component* component)
{
    component->gameObject = this;
    components.Push(component);
}

inline void GameObject::Start()
{
    for (int i = 0, n = components.count; i < n; i++)
    {
        components[i]->Start();
    }
}

inline void GameObject::Update(float time, float deltaTime)
{
    for (int i = 0, n = components.count; i < n; i++)
    {
        components[i]->Update(time, deltaTime);
    }
}

// -------------------------------------------------------------
// Game
// -------------------------------------------------------------

extern Array<GameObject*> gGameObjects;

void Game_Setup(struct SpriteBatch* spriteBatch, int objectCount);
void Game_Shutdown();

void Game_Update(float time, float deltaTime);
void Game_Render();

template <typename T>
inline int Game_FindAllComponentsOfType(Array<Component*>& outComponents)
{
    for (int i = 0, n = gGameObjects.count; i < n; i++)
    {
        T* component = gGameObjects[i]->GetComponent<T>();
        if (component)
        {
            outComponents.Push(component);
        }
    }

    return outComponents.count;
}

template <typename T>
inline T* Game_FindOfType()
{
    for (int i = 0, n = gGameObjects.count; i < n; i++)
    {
        T* component = gGameObjects[i]->GetComponent<T>();
        if (component)
        {
            return component;
        }
    }
    
    return nullptr;
}
