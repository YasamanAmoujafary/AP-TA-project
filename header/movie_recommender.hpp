#ifndef MOVIERECOMMENDER
#define MOVIERECOMMENDER

#include "non_registered_user.hpp"

class MovieRecommender
{
public:
    MovieRecommender();
    void addUser(RegisteredUser* user);
    void addMovie(Movie* movie);

    const vector<RegisteredUser*>& getUsers();
    const vector<Movie*>& getMovies();

    RegisteredUser* findUserByName(const string& username) const;
    vector<pair<Movie*, float>> recommandMoviesByGenre(const string &username,const string &genre);
    void recommandMoviesByCast(const string &username,const string &cast);

    

private:
    vector<RegisteredUser*> registered_users;
    vector<Movie*> movies;
};

#endif