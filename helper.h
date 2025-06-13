#ifndef _HELPER_H
#define _HELPER_H
#include <vector> 
#include <algorithm> 

template<typename T>
    std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2) {
    std::vector<T> vr(v1);
    vr.insert(vr.end(), v2.begin(), v2.end());
    return vr;
}

template <typename T,typename R, typename S> 
std::vector<T> mapKeysToVector(const std::map<R,S> & m)
{
    std::vector<T> v; 
    for (const auto & myPair : m)
    {
        v.emplace_back(myPair.first);
    }
    return v;
}

#endif 