#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

template <typename T>
struct HashTable
{
    int32_t     count;
    int32_t     capacity;
                
    int32_t*    hashs;
    int32_t     hashCount;
                
    int32_t*    nexts;
    uint32_t*   keys;
    T*          values;

    inline HashTable(int32_t hashCount = 64)
        : count(0)
        , capacity(0)
        , hashs(nullptr)
        , hashCount(hashCount)
        , nexts(nullptr)
        , keys(nullptr)
        , values(nullptr)
    {
    }

    inline ~HashTable()
    {
        assert(hashs    == nullptr);
        assert(nexts    == nullptr);
        assert(keys     == nullptr);
        assert(values   == nullptr);
    }

    // Clear the this
    inline void Clear(void)
    {
        this->count = 0;
    }

    // Unref the this
    inline void Detach(void)
    {
        this->count     = 0;
        this->capacity  = 0;

        this->hashs     = nullptr;
        this->hashCount = 64;

        this->nexts     = nullptr;
        this->keys      = nullptr;
        this->values    = nullptr;
    }

    // Clean memory usage
    inline void CleanUp(void)
    {
        free(nexts);
        free(hashs);

        this->count     = 0;
        this->capacity  = 0;

        this->hashs     = nullptr;
        this->hashCount = 0;

        this->nexts     = nullptr;
        this->keys      = nullptr;
        this->values    = nullptr;
    }

    // Find index of entry with key
    inline int32_t IndexOf(uint32_t key, int32_t* outHash = nullptr, int32_t* outPrev = nullptr) const
    {
        if (!this->hashs)
        {
            return -1;
        }

        int hash = (int)(key % (uint32_t)this->hashCount);
        int curr = this->hashs[hash];
        int prev = -1;

        while (curr > -1)
        {
            if (this->keys[curr] == key)
            {
                break;
            }

            prev = curr;
            curr = this->nexts[curr];
        }

        if (outHash) *outHash = hash;
        if (outPrev) *outPrev = prev;
        return curr;
    }

    // Determine if hash table contains the entry with key
    inline bool ContainsKey(uint32_t key) const
    {
        return IndexOf(key) > -1;
    }

    // Get value of entry with key
    const T& GetValue(uint32_t key) const
    {
        int curr = IndexOf(key);
        return values[curr];
    }

    // Get value of entry with key
    const T& GetValue(uint32_t key, const T& defaultValue) const
    {
        int curr = IndexOf(key);
        return (curr > -1) ? values[curr] : defaultValue;
    }

    // Get value of entry with key. If entry exists return true, false otherwise.
    bool TryGetValue(uint32_t key, T* outValue) const
    {
        int curr = IndexOf(key);
        if (curr > -1)
        {
            *outValue = values[curr];
            return true;
        }
        else
        {
            return false;
        }
    }

    // Get value entry, if not exists create new. 
    // Return true if success, false otherwise.
    bool GetValueOrNewSlot(uint32_t key, T** value)
    {
        int hash, prev;
        int curr = this->IndexOf(key, &hash, &prev);

        if (curr < 0)
        {
            if (!this->hashs)
            {
                this->hashs = (int*)malloc(sizeof(int) * hashCount);
                assert(this->hashs && "Out of memory");
                
                for (int i = 0; i < hashCount; i++)
                {
                    this->hashs[i] = -1;
                }

                // Re-calculate hash
                prev = -1;
                hash = (int)(key % (uint32_t)this->hashCount);
            }

            if (this->count + 1 > this->capacity)
            {
                const int oldCapacity = this->capacity;
                const int newCapactiy = oldCapacity > 0 ? oldCapacity * 2 : 32;

                void* newNexts  = malloc(newCapactiy * (sizeof(int) + sizeof(uint32_t) + sizeof(T)));
                void* newKeys   = (char*)newNexts + newCapactiy * sizeof(int);
                void* newValues = (char*)newKeys + newCapactiy * sizeof(uint32_t);

                if (!newNexts)
                {
                    return false;
                }
                else
                {
                    ::memcpy(newNexts, this->nexts, oldCapacity * sizeof(int));
                    ::memcpy(newKeys, this->keys, oldCapacity * sizeof(uint32_t));
                    ::memcpy(newValues, this->values, oldCapacity * sizeof(T));

                    ::free(this->nexts);
                
                    this->capacity = newCapactiy;
                    this->nexts    = (int*)newNexts;
                    this->keys     = (uint32_t*)newKeys;
                    this->values   = (T*)newValues;
                }
            }

            curr = this->count;
            if (prev > -1)
            {
                this->nexts[prev] = curr;
            }
            else
            {
                this->hashs[hash] = curr;
            }
            this->nexts[curr] = -1;
            this->keys[curr] = key;
            this->count++;
        }

        *value = &this->values[curr];
        return true;
    }

    // Get value entry, if not exists create new.
    // Return a reference to value entry if success, otherwise abort the process.
    inline T& GetValueOrNewSlot(uint32_t key)
    {
        T* innerValue;
        if (!this->GetValueOrNewSlot(key, &innerValue))
        {
            assert(false && "Out of memory.");
        }
        return *innerValue;
    }

    // Set entry's value, if not exists create new
    inline bool SetValue(uint32_t key, const T& value)
    {
        T* innerValue;
        if (this->GetValueOrNewSlot(key, &innerValue))
        {
            *innerValue = value;
            return true;
        }
        else
        {
            return false;
        }
    }

    // Remove an entry that has given key
    inline bool Remove(uint32_t key)
    {
        int prev;
        int hash;
        int curr = this->IndexOf(key, &hash, &prev);
        return this->Erase(curr, hash, prev);
    }
    
    // Remove the entry at given index
    inline bool Erase(int32_t index)
    {
        if (index > -1 && index < this->count)
        {
            return this->Remove(this->keys[index]);
        }
        else
        {
            return false;
        }
    }

    // Remove the entry at given index, hash entry, and previous entry
    inline bool Erase(int32_t curr, int32_t hash, int32_t prev)
    {
        if (curr > -1)
        {
            if (prev > -1)
            {
                this->nexts[prev] = -1;
            }
            else
            {
                this->hashs[hash] = -1;
            }

            if (curr < this->count - 1)
            {
                int last = this->count - 1;
                this->nexts[curr]  = this->nexts[last];
                this->keys[curr]   = this->keys[last];
                this->values[curr] = this->values[last];

                this->IndexOf(this->keys[curr], &hash, &prev);
                if (prev > -1)
                {
                    this->nexts[prev] = curr;
                }
                else
                {
                    this->hashs[hash] = curr;
                }
            }

            this->count = this->count - 1;
            return true;
        }
        else
        {
            return false;
        }
    }
};
