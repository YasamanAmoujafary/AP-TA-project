#ifndef MOVIERECOMMENDER
#define MOVIERECOMMENDER

#include "non_registered_user.hpp"
#include "registered_user.hpp"
#include "movie.hpp"


class MovieRecommender
{
public:
    MovieRecommender();
    void addUser(RegisteredUser* user);
    void addMovie(Movie* movie);

    const vector<RegisteredUser*>& getUsers();
    const vector<Movie*>& getMovies();

    RegisteredUser* findUserByName(const string& username) const;

private:
    vector<RegisteredUser*> registered_users;
    vector<Movie*> movies;
};

#endif