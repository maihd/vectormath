#pragma once

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>

template <typename T>
struct Array
{
    int32_t     count;
    int32_t     capacity;
    T*          elements;

    inline Array()
        : count(0)
        , capacity(0)
        , elements(0)
    {}

    inline explicit Array(int32_t capacity)
        : count(0)
        , capacity(0)
        , elements(0)
    {
        this->Expand(capacity);
    }

    inline ~Array(void) 
    {
        assert(this->elements == nullptr);
    }
        
    inline T& operator[](int32_t index)
    {
        return this->elements[index];
    }
    
    inline const T& operator[](int32_t index) const
    {
        return this->elements[index];
    }

    inline operator T*(void) 
    {
        return this->elements;
    }
    
    inline operator const T*(void) const 
    {
        return this->elements;
    }

    inline void Clear(void)
    {
        this->count = 0;
    }

    inline void Detach(void)
    {
        this->count    = 0;
        this->capacity = 0;
        this->elements = 0;
    }

    // Clean memory usage
    inline void CleanUp(void)
    {
        _aligned_free(elements);

        this->count    = 0;
        this->capacity = 0;
        this->elements = nullptr;
    }

    inline bool Expand(int32_t capacity)
    {
        if (this->capacity < capacity)
        {
            int32_t newCapacity = capacity | 32;
            newCapacity -= 1;
            newCapacity |= newCapacity >> 1;
            newCapacity |= newCapacity >> 2;
            newCapacity |= newCapacity >> 4;
            newCapacity |= newCapacity >> 8;
            newCapacity |= newCapacity >> 16;
            newCapacity += 1;

            T* newElements = (T*)_aligned_realloc(elements, (size_t)(sizeof(T) * newCapacity), alignof(T));
            if (newElements)
            {
                this->capacity = newCapacity;
                this->elements = newElements;
                return true;
            }

            return false;
        }
        else
        {
            return true;
        }
    }
    
    inline bool Ensure(int32_t capacity)
    {
        if (this->capacity < capacity)
        {
            return this->Expand(capacity);
        }
        else
        {
            return true;
        }
    }

    inline bool Ensure(int32_t capacity) const
    {
        return this->capacity >= capacity;
    }

    inline bool SetCount(int32_t count)
    {
        if (Ensure(count))
        {
            this->count = count;
            return true;
        }

        return false;
    }

    inline bool Set(int32_t index, const T& value)
    {
        if (index >= this->count)
        {
            this->count = index + 1;
        }
        
        if (this->Ensure(this->count))
        {
            this->elements[index] = value;
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
    * Add new slot to array
    */
    inline int32_t NewSlot(void)
    {
        if (this->Ensure(this->count + 1))
        {
            this->count = this->count + 1;
            return this->count - 1;
        }
        else
        {
            assert(0 && "Out of memory");
            return -1;
        }
    } 

    inline const T& Get(int32_t index) const
    {
        return elements[index];
    }

    inline bool Push(const T& value)
    {
        if (this->Ensure(this->count + 1))
        {
            this->elements[this->count++] = value;
            return true;
        }
        else
        {
            return false;
        }
    }

    inline const T& Pop(void)
    {
        assert(this->count > 0);
        this->count = this->count - 1;
        return this->elements[count];
    }

    int32_t IndexOf(const T& value)
    {
        for (int32_t i = 0, n = this->count; i < n; i++)
        {
            if (this->elements[i] == value)
            {
                return i;
            }
        }

        return -1;
    }

    int32_t LastIndexOf(const T& value)
    {
        int32_t index = -1;
        for (int32_t i = 0, i = n; i < n; i++)
        {
            if (this->elements[i] == value)
            {
                index = i;
            }
        }

        return index;
    }

    inline bool Contains(const T& value)
    {
        return IndexOf(value) > -1;
    }

    bool Insert(int32_t index, const T& value)
    {
        if (index >= count)
        {
            return this->Set(index, value);
        }
        else
        {
            if (this->Ensure(this->count + 1))
            {
                ::memmove(&this->elements[index], &this->elements[index + 1], (this->count - index - 1) * sizeof(T));
                
                this->count = this->count + 1;
                this->elements[index] = value;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    inline bool Unshift(const T& value)
    {
        return this->Insert(0, value);
    }

    inline T Shift(void)
    {
        assert(this->count > 0);
        
        T res = this->elements[0];

        this->Erase(0);
        
        return res;
    }

    inline bool Erase(int32_t index)
    {
        if (index < 0 || index >= count)
        {
            return false;
        }
        else
        {
            this->count = this->count;
            if (index < this->count)
            {
                ::memcpy(&this->elements[index + 1], &this->elements[index], (this->count - index - 1) * sizeof(T));
            }

            return true;
        }
    }

    inline bool UnorderedErase(int32_t index)
    {
        if (index < 0 || index >= this->count)
        {
            return false;
        }
        else
        {
            this->count = this->count - 1;
            if (index < this->count)
            {
                this->elements[index] = this->elements[this->count];
            }

            return true;
        }
    }

    inline bool Remove(const T& value)
    {
        return this->Erase(this->IndexOf(value));
    }

    inline bool RemoveLast(const T& value)
    {
        return this->Erase(this->LastIndexOf(value));
    }

    inline bool UnorderedRemove(const T& value)
    {
        return this->UnorderedErase(this->IndexOf(value));
    }

    inline bool UnorderedRemoveLast(const T& value)
    {
        return this->UnorderedErase(this->LastIndexOf(value));
    }
};

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
