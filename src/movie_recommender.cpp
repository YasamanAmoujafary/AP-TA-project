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

vector<pair<Movie*, float>> MovieRecommender::recommandMoviesByGenre(const string &username,const string &genre)
{
    cout << registered_users.size() << endl;
    cout << movies.size() << endl;


    if(username == "")
    {
        NonRegisteredUser nonRegisteredUser;
        return nonRegisteredUser.recommend_by_genre(genre, movies,registered_users);

    }
    else
    {
        RegisteredUser* registeredUser = findUserByName(username);
        if(registeredUser)
        {
            return registeredUser->recommend_by_genre(genre, movies, registered_users);
        }
        else
        {
            cout << "i m here"<< endl;
            throw NotFound();
        }
    }

}

void MovieRecommender::recommandMoviesByCast(const string &username,const string &cast)
{

}

