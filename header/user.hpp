#ifndef USER
#define USER

#include "movie.hpp"

class User
{
public:
    virtual void recommend_by_genre() = 0;
    virtual void recommend_by_cast() = 0;

    virtual ~User() = default;
};


#endif