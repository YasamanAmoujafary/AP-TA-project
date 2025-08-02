#include "movie_recommender.hpp"

MovieRecommender::MovieRecommender() {}

void MovieRecommender::addUser(RegisteredUser* user) {
    registeredUsers.push_back(user);
}

void MovieRecommender::addMovie(Movie* movie) {
    movies.push_back(movie);
}

const vector<RegisteredUser*>& MovieRecommender::getUsers(){
    return registeredUsers;
}

const vector<Movie*>& MovieRecommender::getMovies(){
    return movies;
}

RegisteredUser* MovieRecommender::findUserByName(const string& username) const {
    for (RegisteredUser* user : registeredUsers) {
        if (user && user->get_name() == username) {
            return user;
        }
    }
    throw NotFound();
}

vector<pair<Movie*, float>> MovieRecommender::recommandMoviesByGenre(const string &username,const string &genre)
{
    if(username == "")
    {
        NonRegisteredUser nonRegisteredUser;
        return nonRegisteredUser.recommendByGenre(genre, movies,registeredUsers);

    }
    else
    {
        RegisteredUser* registeredUser = findUserByName(username);
        if(registeredUser)
        {
            return registeredUser->recommendByGenre(genre, movies, registeredUsers);
        }
        else
        {
            throw NotFound();
        }
    }

}

vector<Movie*> MovieRecommender::recommandMoviesByCast(const string &username,const string &cast)
{
    if(username == "")
    {
        NonRegisteredUser nonRegisteredUser;
        return nonRegisteredUser.recommendByCast(cast, movies);

    }
    else
    {
        RegisteredUser* registeredUser = findUserByName(username);
        if(registeredUser)
        {
            return registeredUser->recommendByCast(cast, movies);
        }
        else
        {
            throw NotFound();
        }
    }
}

