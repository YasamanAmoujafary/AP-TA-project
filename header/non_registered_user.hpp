#ifndef NONREGISTEREDUSER
#define NONREGISTEREDUSER

#include "registered_user.hpp"

class NonRegisteredUser : public User
{
public:
    NonRegisteredUser();
    vector<pair<Movie*, float>> recommendByGenre(const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users);
    vector<Movie*> recommendByCast(const string& cast, const vector<Movie*>& movies);
    float calculateMovieScore(const string &genre,const Movie* movie, const vector<RegisteredUser*>& users);
    int countRatings(const string &type, const Movie* movie, const vector<RegisteredUser*>& users);
};


#endif