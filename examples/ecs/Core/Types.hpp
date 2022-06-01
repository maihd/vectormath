#pragma once

#include <bitset>
#include <stdint.h>

// Source: https://gist.github.com/Lee-R/3839813
constexpr uint32_t ConstHashRecursive(const char* s, size_t count)
{
	return ((count ? ConstHashRecursive(s, count - 1) : 2166136261u) ^ s[count]) * 16777619u; // NOLINT (hicpp-signed-bitwise)
}

constexpr uint32_t operator "" _hash(char const* s, size_t count)
{
	return ConstHashRecursive(s, count);
}

constexpr uint32_t ConstHash(const char* s)
{
	uint32_t result = 2166136261u;
	while (*s)
	{
		result ^= *s;
		result *= 16777619u;
		s++;
	}
	return result;
}

inline uint32_t Hash(const char* s)
{
	uint32_t result = 2166136261u;
	while (*s)
	{
		result ^= *s;
		result *= 16777619u;
		s++;
	}
	return result;
}

template <typename T>
constexpr auto GetTypeNameHelper()
{
#if defined(_MSC_VER)
#define __FUNC__ __FUNCSIG__
#else
#define __FUNC__ __PRETTY_FUNCTION__
#endif

    int head = 0;
    int tail = 0;
    for (int i = 0; i < sizeof(__FUNC__); i++)
    {
        if (__FUNC__[i] == '<')
        {
            if (head == 0)
            {
                head = i + 1;
            }
        }
        else if (__FUNC__[i] == '>')
        {
            tail = i - 1;
        }
    }

    struct Result
    {
        char TypeName[sizeof(__FUNC__)];
    };

    Result result = { "" };

    int index = head;
    char* typeName = result.TypeName;
    const char* funcName = __FUNC__ + head;
    while (*funcName != '\0' && index <= tail)
    {
        // Skip 'struct' modifier
        if (true
            && funcName[0] == 's'
            && funcName[1] == 't'
            && funcName[2] == 'r'
            && funcName[3] == 'u'
            && funcName[4] == 'c'
            && funcName[5] == 't'
            && funcName[6] == ' ')
        {
            funcName += 7;
            index += 7;
            continue;
        }

        // Skip 'class' modifier
        if (true
            && funcName[0] == 'c'
            && funcName[1] == 'l'
            && funcName[2] == 'a'
            && funcName[3] == 's'
            && funcName[4] == 's'
            && funcName[5] == ' ')
        {
            funcName += 6;
            index += 6;
            continue;
        }

        // Skip 'union' modifier
        if (true
            && funcName[0] == 'u'
            && funcName[1] == 'n'
            && funcName[2] == 'i'
            && funcName[3] == 'o'
            && funcName[4] == 'n'
            && funcName[5] == ' ')
        {
            funcName += 6;
            index += 6;
            continue;
        }

        // Skip 'enum' modifier
        if (true
            && funcName[0] == 'e'
            && funcName[1] == 'n'
            && funcName[2] == 'u'
            && funcName[3] == 'm'
            && funcName[4] == ' ')
        {
            funcName += 5;
            index += 5;
            continue;
        }

        *typeName++ = *funcName++;
        index++;
    }

#undef __FUNC__ // Release __FUNC__ to other usages
    return result;
}

template <typename T>
constexpr const char* GetTypeName()
{
    static auto data = GetTypeNameHelper<T>();
    return data.TypeName;
}

template <typename T>
constexpr uint32_t GetTypeHash()
{
    return ConstHash(GetTypeName<T>());
}

// ECS
using Entity = uint32_t;
using ComponentType = uint8_t;

const Entity MAX_ENTITIES = 10000;
const ComponentType MAX_COMPONENTS = 32;

struct Signature
{
    uint32_t flags = 0;

    inline void Set(const ComponentType type, const bool value = true)
    {
        if (value)
        {
            flags |= (1u << type);
        }
        else
        {
            flags &= ~(1u << type);
        }
    }

    inline bool Get(const ComponentType type) const
    {
        return flags & (1u << type);
    }

    inline void Reset()
    {
        flags = 0;
    }

    inline Signature operator&(const Signature& other)
    {
        return Signature{ flags & other.flags };
    }

    inline Signature operator|(const Signature& other)
    {
        return Signature{ flags | other.flags };
    }

    inline bool operator==(const Signature& other)
    {
        return flags == other.flags;
    }

    inline bool operator!=(const Signature& other)
    {
        return flags != other.flags;
    }
};


// Input
enum class InputButtons
{
	W,
	A,
	S,
	D,
	Q,
	E
};


// Events
using EventId = std::uint32_t;
using ParamId = std::uint32_t;

#define METHOD_LISTENER(EventType, Listener) EventType, std::bind(&Listener, this, std::placeholders::_1)
#define FUNCTION_LISTENER(EventType, Listener) EventType, std::bind(&Listener, std::placeholders::_1)

// TODO: Make these easier to define and use (macro?)
// TODO: Add some kind of enforcement/automation that a SetParam type and a GetParam type match

namespace Events
{
	namespace Window
	{
		const EventId QUIT = "Events::Window::QUIT"_hash;
		const EventId RESIZED = "Events::Window::RESIZED"_hash;
		const EventId INPUT = "Events::Window::INPUT"_hash;

		namespace Input
		{
			const ParamId INPUT = "Events::Window::Input::INPUT"_hash;
		}

		namespace Resized
		{
			const ParamId WIDTH = "Events::Window::Resized::WIDTH"_hash;
			const ParamId HEIGHT = "Events::Window::Resized::HEIGHT"_hash;
		}
	}
}
