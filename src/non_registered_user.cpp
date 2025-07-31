#include "non_registered_user.hpp"

NonRegisteredUser::NonRegisteredUser(){}


vector<pair<Movie*, float>> NonRegisteredUser::recommend_by_genre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users)
{
    vector<pair<Movie*, float>> scored_movies;
    for (Movie* movie : movies) {
        if (movie->getGenre() != genre) continue;

        float score = calculate_movie_score(genre, movie, users);
        scored_movies.push_back({movie, score});
    }
    if (scored_movies.empty()) {
        cout << "iam here 2"<< endl;
        throw NotFound();
    }
    sort_scored_movies(scored_movies);
    return scored_movies;
}

float NonRegisteredUser::calculate_movie_score(const string &genre,const Movie* movie, const vector<RegisteredUser*>& users)
{
    float score;
    int perfect_count = count_ratings(PERFECT,movie, users);
    int average_count = count_ratings(AVERAGE,movie, users);
    int poor_count = count_ratings(POOR,movie, users);

    score = (perfect_count * NON_REG_PERFECT_WEIGHT) + (average_count * NON_REG_AVERAGE_WEIGHT) + (poor_count * NON_REG_POOR_WEIGHT);

    return score;
}

int NonRegisteredUser::count_ratings(const string &type, const Movie* movie, const vector<RegisteredUser*>& users) {
    int count = 0;

    for (RegisteredUser* user : users) {
        const vector<Movie*>& watched = user->get_movies();
        const vector<string>& ratings = user->get_ratings();

        for (size_t i = 0; i < watched.size(); ++i) {
            if (watched[i]->getName() == movie->getName() && ratings[i] == type) {
                count++;
            }
        }
    }

    return count;
}


// Stub for cast recommendation
void NonRegisteredUser::recommend_by_cast(){
    cout << "[DEBUG] Personalized cast recommendation not implemented yetnn.\n";
}

void NonRegisteredUser::sort_scored_movies(vector<pair<Movie*, float>>& scored) {
    sort(scored.begin(), scored.end(), [](const pair<Movie*, float>& a, const pair<Movie*, float>& b) {
        if (a.second != b.second)
            return a.second > b.second;
        if (a.first->getIMDb() != b.first->getIMDb())
            return a.first->getIMDb() > b.first->getIMDb();
        return a.first->getName() < b.first->getName();
    });
}



