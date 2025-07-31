#ifndef NONREGISTEREDUSER
#define NONREGISTEREDUSER

#include "registered_user.hpp"

class NonRegisteredUser : public User
{
public:
    NonRegisteredUser();
    vector<pair<Movie*, float>> recommend_by_genre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users);
    void recommend_by_cast();
    float calculate_movie_score(const string &genre,const Movie* movie, const vector<RegisteredUser*>& users);
    int count_ratings(const string &type, const Movie* movie, const vector<RegisteredUser*>& users);
    void sort_scored_movies(vector<pair<Movie*, float>>& scored);
};


#endif