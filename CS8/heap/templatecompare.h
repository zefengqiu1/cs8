#ifndef TEMPLATECOMPARE_H
#define TEMPLATECOMPARE_H

template<typename T>
class Bigger{
public:
    bool operator()(const T& left,const T& right) const
    {
        return left<right;
    }

};

template<typename T>
class Smaller{
public:
    bool operator()(const T& left, const T& right) const
    {
        return left>right;
    }
};



#endif // TEMPLATECOMPARE_H
