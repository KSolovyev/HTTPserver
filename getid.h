#ifndef HASHWRAPPER_H
#define HASHWRAPPER_H

#include<set>
#include<unordered_map>


template<typename T>
class getId
{
public:
    getId(){}

    ~getId(){}

    size_t operator()(T* object)
    {
        auto savedObjectId = objectToId.find(object);
        if(savedObjectId!=objectToId.end())
        {
            return (*savedObjectId).second;
        }
        else
        {
            if(!freeId.empty())
            {
                auto it_b = freeId.begin();
                id = *it_b;
                freeId.erase(it_b);
                return id;
            }
            else
            {
                id = ++maxId;
                objectToId.insert({{object,id}});
                return id;
            }
        }
    }
private:
    size_t id;
    static size_t maxId;
    static std::set<size_t> freeId;
    static std::unordered_map<T*,size_t> objectToId;


};

template<typename T>
size_t getId<T>::maxId = 0;

template<typename T>
std::set<size_t> getId<T>::freeId;

template<typename T>
std::unordered_map<T*,size_t> getId<T>::objectToId;


#endif // HASHWRAPPER_H
