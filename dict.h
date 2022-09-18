#ifndef DICT_H
#define DICT_H

#include <bits/stdc++.h>

template<class Key, class Value>
class Dictionary
{
public:
    virtual ~Dictionary() = default;

    virtual const Value& Get(const Key& key) const = 0;
    virtual void Set(const Key& key, const Value& value) = 0;
    virtual bool isSet(const Key& key) const = 0;
};

template<class Key>
class not_found_exception : public std::exception
{
public:
    virtual const Key& getKey() const noexcept = 0;
};

template<class Key>
class my_not_found_exception : public not_found_exception<Key>
{
public:
    virtual const Key& getKey() const noexcept
    {
        return k;
    }

    my_not_found_exception(const Key& key) : k(key) { }

private:
    Key k;
};

template<class Key, class Value>
class myDictionary : public Dictionary<Key, Value>
{
public:
    virtual const Value& Get(const Key& key) const
    {
        auto it = map.find(key);
        if (it == map.end())
            throw my_not_found_exception<Key>(key);
        return it->second;
    }

    virtual void Set(const Key& key, const Value& value)
    {
        map[key] = value;
    }

    virtual bool isSet(const Key& key) const
    {
        return map.find(key) != map.end();
    }

private:
    std::map<Key, Value> map;
};

#endif // DICT_H
