#include "non_registered_user.hpp"

NonRegisteredUser::NonRegisteredUser(){}


vector<pair<Movie*, float>> NonRegisteredUser::recommendByGenre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users)
{
    vector<pair<Movie*, float>> scoredMovies;
    for (Movie* movie : movies) {
        if (movie->getGenre() != genre) continue;

        float score = calculateMovieScore(genre, movie, users);
        scoredMovies.push_back({movie, score});
    }
    if (scoredMovies.empty()) {
        throw NotFound();
    }
    sortScoredMovies(scoredMovies);
    return scoredMovies;
}

vector<Movie*> NonRegisteredUser::recommendByCast(const string& cast, const vector<Movie*>& movies) {
    vector<Movie*> matchingMovies;

    for (Movie* movie : movies) {
        if (movie->getCast() == cast) {
            matchingMovies.push_back(movie);
        }
    }
    if (matchingMovies.empty()) {
        throw NoSuitableMovie();
    }
    sortMoviesByImdbAndName(matchingMovies); 
    return matchingMovies;
}


float NonRegisteredUser::calculateMovieScore(const string &genre,const Movie* movie, const vector<RegisteredUser*>& users)
{
    float score;
    int perfectCount = countRatings(PERFECT,movie, users);
    int averageCount = countRatings(AVERAGE,movie, users);
    int poorCount = countRatings(POOR,movie, users);

    score = (perfectCount * NON_REG_PERFECT_WEIGHT) + (averageCount * NON_REG_AVERAGE_WEIGHT) + (poorCount * NON_REG_POOR_WEIGHT);

    return score;
}

int NonRegisteredUser::countRatings(const string &type, const Movie* movie, const vector<RegisteredUser*>& users) {
    int count = 0;

    for (RegisteredUser* user : users) {
        const vector<Movie*>& watched = user->getMovies();
        const vector<string>& ratings = user->getRatings();

        for (size_t i = 0; i < watched.size(); ++i) {
            if (watched[i]->getName() == movie->getName() && ratings[i] == type) {
                count++;
            }
        }
    }

    return count;
}






