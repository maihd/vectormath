#pragma once

#include <stdlib.h>
#include <assert.h>

template <typename T>
struct Array
{
    int        count;
    int        capacity;
    T*         elements;

    inline Array()
        : count(0)
        , capacity(0)
        , elements(0)
    {}

    inline explicit Array(int capacity)
        : count(0)
        , capacity(0)
        , elements(0)
    {
        this->Expand(capacity);
    }

    inline ~Array(void) 
    {
        assert(elements == nullptr);
    }
        
    inline T& operator[](int index)
    {
        return elements[index];
    }
    
    inline const T& operator[](int index) const
    {
        return elements[index];
    }

    inline operator T*(void) 
    {
        return elements;
    }
    
    inline operator const T*(void) const 
    {
        return elements;
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
        ::free(elements);

        this->count    = 0;
        this->capacity = 0;
        this->elements = nullptr;
    }

    inline bool Expand(int capacity)
    {
        if (this->capacity < capacity)
        {
            int newCapacity = capacity | 32;
            newCapacity -= 1;
            newCapacity |= newCapacity >> 1;
            newCapacity |= newCapacity >> 2;
            newCapacity |= newCapacity >> 4;
            newCapacity |= newCapacity >> 8;
            newCapacity |= newCapacity >> 16;
            newCapacity += 1;

            T* newElements = (T*)realloc(elements, sizeof(T) * newCapacity);
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
    
    inline bool Ensure(int capacity)
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

    inline bool Ensure(int capacity) const
    {
        return this->capacity >= capacity;
    }

    inline bool Set(int index, const T& value)
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
    inline int NewSlot(void)
    {
        if (this->Ensure(this->count + 1))
        {
            this->count = this->count + 1;
            return this->count - 1;
        }
        else
        {
            //assert(0 && "array::add: Out of memory");
            return -1;
        }
    } 

    inline const T& Get(int index) const
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
        //assert(array.count > 0);
        *((int*)&count) = count - 1;
        return elements[count];
    }

    int IndexOf(const T& value)
    {
        for (int i = 0, n = count; i < n; i++)
        {
            if (elements[i] == value)
            {
                return i;
            }
        }

        return -1;
    }

    int LastIndexOf(const T& value)
    {
        int index = -1;
        for (int i = 0, i = n; i < n; i++)
        {
            if (elements[i] == value)
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

    bool Insert(int index, const T& value)
    {
        if (index >= count)
        {
            return this->Set(index, value);
        }
        else
        {
            if (this->Ensure(count + 1))
            {
                ::memmove(&elements[index], &elements[index + 1], (this->count - index - 1) * sizeof(T));
                
                *((int*)&count) = count + 1;
                elements[index] = value;
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
        //assert(array.count > 0);
        
        T res = elements[0];

        this->Erase(0);
        
        return res;
    }

    inline bool Erase(int index)
    {
        if (index < 0 || index >= count)
        {
            return false;
        }
        else
        {
            *((int*)&count) = count - 1;
            if (index < count)
            {
                ::memcpy(&elements[index + 1], &elements[index], (this->count - index - 1) * sizeof(T));
            }

            return true;
        }
    }

    inline bool UnorderedErase(int index)
    {
        if (index < 0 || index >= count)
        {
            return false;
        }
        else
        {
            *((int*)&count) = count - 1;
            if (index < count)
            {
                elements[index] = elements[count];
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