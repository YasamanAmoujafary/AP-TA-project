#ifndef USER
#define USER

#include "movie.hpp"

class RegisteredUser;

class User
{
public:
    virtual vector<pair<Movie*, float>> recommend_by_genre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users) = 0;
    virtual void recommend_by_cast() = 0;
    
    virtual ~User() = default;
};


#endif