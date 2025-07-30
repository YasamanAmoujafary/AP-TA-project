#ifndef NONREGISTEREDUSER
#define NONREGISTEREDUSER

#include "user.hpp"

class NonRegisteredUser : public User
{
public:
    void recommend_by_genre();
    void recommend_by_cast();
};


#endif