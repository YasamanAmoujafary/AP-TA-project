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
    vector<Movie*> recommandMoviesByCast(const string &username,const string &cast);

    

private:
    vector<RegisteredUser*> registeredUsers;
    vector<Movie*> movies;
};

#endif