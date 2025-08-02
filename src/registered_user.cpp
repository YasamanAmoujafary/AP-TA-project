#include "registered_user.hpp"

RegisteredUser::RegisteredUser(string _name,vector<Movie*> _watched,const vector<string> _ratings)
              :name(_name), watchedMovies(_watched), ratings(_ratings) {}

string RegisteredUser::get_name() const {return name;}

vector<pair<Movie*, float>> RegisteredUser::recommendByGenre(const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users){
    vector<Movie*> moviesInOneGenre = getMovieOfOneGenre(genre, movies);
    moviesInOneGenre = checkUserWatchedMovies(moviesInOneGenre);
    vector<pair<Movie*, float>> scoredMovies;
    for(Movie* movie: moviesInOneGenre)
    {
        float score = calculateMovieScore(genre, movie, users);
        scoredMovies.push_back({movie, score});
    }

    if (scoredMovies.empty()) {
        throw NotFound();
    }
    sortScoredMovies(scoredMovies);
    return scoredMovies;
}

float RegisteredUser::calculateMovieScore(const string &genre,const Movie* movie, const vector<RegisteredUser*>& users)
{
    float score;
    int IMDb = movie->getIMDb();
    int directorEffect = calculateDirectorEffect(movie);
    int castEffect = calculateCastEffect(movie);
    score = (IMDb * REG_IMDB_WEIGHT) + (directorEffect * REG_DIR_WEIGHT) + (castEffect * REG_CAST_WEIGHT);
    return score;
}

int RegisteredUser::calculateDirectorEffect(const Movie* movie)
{
    for(int i=0; i<watchedMovies.size(); i++)
    {
        if((watchedMovies[i]->getGenre() == movie->getGenre()) && (watchedMovies[i]->getDirector() == movie->getDirector()))
        {
            if(ratings[i] == PERFECT)
            {
                return REG_DIR_EFFECT_PERFECT_WEIGHT;
            }
            else if(ratings[i] == AVERAGE)
            {
                return REG_DIR_EFFECT_AVERAGE_WEIGHT;
            }
            else if(ratings[i] == POOR)
            {
                return REG_DIR_EFFECT_POOR_WEIGHT;
            }
            else return 0;
        }
    }
    return 0;
}

int RegisteredUser::calculateCastEffect(const Movie* movie)
{
    for(int i=0; i<watchedMovies.size(); i++)
    {
        if((watchedMovies[i]->getGenre() == movie->getGenre()) && (watchedMovies[i]->getCast() == movie->getCast()))
        {
            if(ratings[i] == PERFECT)
            {
                return REG_CAST_EFFECT_PERFECT_WEIGHT;
            }
            else if(ratings[i] == AVERAGE)
            {
                return REG_CAST_EFFECT_AVERAGE_WEIGHT;
            }
            else if(ratings[i] == POOR)
            {
                return REG_CAST_EFFECT_POOR_WEIGHT;
            }
            else return 0;
        }
    }
    return 0;
}

vector<Movie*> RegisteredUser::getMovieOfOneGenre(const string &genre, const vector<Movie*>& movies)
{
    vector<Movie*> moviesInOneGenre;
    for(Movie* movie: movies)
    {
        if(movie->getGenre() == genre)
        {
            moviesInOneGenre.push_back(movie);
        }
    }
    return moviesInOneGenre;
}

vector<Movie*> RegisteredUser::checkUserWatchedMovies(const vector<Movie*> &movies)
{
    vector<Movie*> movieNotInCommon;
    for(Movie* movie: movies)
    {
        if(!checkMovieExist(movie))
        {
            movieNotInCommon.push_back(movie);
        }
    }
    return movieNotInCommon;
}

bool RegisteredUser::checkMovieExist(const Movie *movie)
{
    for(Movie* watchedMovie : watchedMovies)
    {
        if(watchedMovie->getName() == movie->getName())
        {
            return true;
        }
    }
    return false;
}

vector<Movie*> RegisteredUser::recommendByCast(const string& cast, const vector<Movie*>& movies) {
    string favorite_genre = findFavoriteGenre();

    vector<Movie*> filtered = filterUnwatchedMatchingCastAndGenre(cast, favorite_genre, movies);

    if (filtered.empty()) {
        throw NoSuitableMovie();
    }

    sortMoviesByImdbAndName(filtered);

    return filtered;
}

string RegisteredUser::findFavoriteGenre() {
    unordered_map<string, int> genreCount;
    for (Movie* m : watchedMovies) {
        genreCount[m->getGenre()]++;
    }

    if (genreCount.empty()) {
        throw NotFound();
    }

    string favoriteGenre;
    int maxCount = 0;
    for (const auto& p : genreCount) {
        if (p.second > maxCount) {
            maxCount = p.second;
            favoriteGenre = p.first;
        }
    }
    return favoriteGenre;
}

vector<Movie*> RegisteredUser::filterUnwatchedMatchingCastAndGenre(const string& cast,const string& genre,const vector<Movie*>& movies) {
    vector<Movie*> result;
    for (Movie* m : movies) {
        if (m->getCast() == cast && m->getGenre() == genre && !checkMovieExist(m)) {
            result.push_back(m);
        }
    }
    return result;
}

