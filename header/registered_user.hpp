#ifndef REGISTEREDUSER
#define REGISTEREDUSER

#include "user.hpp"

class RegisteredUser : public User
{
public:
    RegisteredUser(string _name,vector<Movie*> _watched,const vector<string> _ratings);
    vector<pair<Movie*, float>> recommendByGenre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users);
    vector<Movie*> recommendByCast(const string& cast, const vector<Movie*>& movies);
    string get_name() const;
    vector<Movie*> getMovies(){return watchedMovies;}
    vector<string> getRatings(){return ratings;}
    vector<Movie*> getMovieOfOneGenre(const string &genre, const vector<Movie*>& movies);
    vector<Movie*> checkUserWatchedMovies(const vector<Movie*> &movies);
    bool checkMovieExist(const Movie *movie);
    float calculateMovieScore(const string &genre,const Movie* movie, const vector<RegisteredUser*>& users);
    int calculateDirectorEffect(const Movie* movie);
    int calculateCastEffect(const Movie* movie);
    string findFavoriteGenre();
    vector<Movie*> filterUnwatchedMatchingCastAndGenre(const string& cast,const string& genre,const vector<Movie*>& movies);

private:
    string name;
    vector<Movie*> watchedMovies;
    vector<string> ratings;
};


#endif