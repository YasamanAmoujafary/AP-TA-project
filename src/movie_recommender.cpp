#include "movie_recommender.hpp"

MovieRecommender::MovieRecommender() {}

void MovieRecommender::addUser(RegisteredUser* user) {
    registered_users.push_back(user);
}

void MovieRecommender::addMovie(Movie* movie) {
    movies.push_back(movie);
}

const vector<RegisteredUser*>& MovieRecommender::getUsers(){
    return registered_users;
}

const vector<Movie*>& MovieRecommender::getMovies(){
    return movies;
}

RegisteredUser* MovieRecommender::findUserByName(const string& username) const {
    for (RegisteredUser* user : registered_users) {
        if (user && user->get_name() == username) {
            return user;
        }
    }
    throw NotFound();
}