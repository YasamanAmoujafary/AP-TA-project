#include "user.hpp"

void User::sortScoredMovies(vector<pair<Movie*, float>>& scored) {
    sort(scored.begin(), scored.end(), [](const pair<Movie*, float>& a, const pair<Movie*, float>& b) {
        if (a.second != b.second)
            return a.second > b.second;
        if (a.first->getIMDb() != b.first->getIMDb())
            return a.first->getIMDb() > b.first->getIMDb();
        return a.first->getName() < b.first->getName();
    });
}

void User::sortMoviesByImdbAndName(vector<Movie*>& movies) {
    sort(movies.begin(), movies.end(), [](Movie* a, Movie* b) {
        if (a->getIMDb() != b->getIMDb())
            return a->getIMDb() > b->getIMDb();
        return a->getName() < b->getName();    
    });
}