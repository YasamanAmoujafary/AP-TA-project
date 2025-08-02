#ifndef USER
#define USER

#include "movie.hpp"

class RegisteredUser;

class User
{
public:
    virtual vector<pair<Movie*, float>> recommendByGenre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users) = 0;
    virtual vector<Movie*> recommendByCast(const string& cast, const vector<Movie*>& movies) = 0;
    virtual float calculateMovieScore(const string &genre,const Movie* movie, const vector<RegisteredUser*>& users) = 0;
    void sortScoredMovies(vector<pair<Movie*, float>>& scored);
    void sortMoviesByImdbAndName(vector<Movie*>& movies);

    virtual ~User() = default;
};


#endif