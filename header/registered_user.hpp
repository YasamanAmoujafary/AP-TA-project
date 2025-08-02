#ifndef REGISTEREDUSER
#define REGISTEREDUSER

#include "user.hpp"

class RegisteredUser : public User
{
public:
    RegisteredUser(string _name,vector<Movie*> _watched,const vector<string> _ratings);
    string get_name() const;
    string findFavoriteGenre();

    vector<string> getRatings(){return ratings;}
    vector<Movie*> recommendByCast(const string& cast, const vector<Movie*>& movies);
    vector<Movie*> getMovies(){return watchedMovies;}
    vector<Movie*> getMovieOfOneGenre(const string &genre, const vector<Movie*>& movies);
    vector<Movie*> checkUserWatchedMovies(const vector<Movie*> &movies);
    vector<Movie*> filterUnwatchedMatchingCastAndGenre(const string& cast,const string& genre,const vector<Movie*>& movies);
    vector<pair<Movie*, float>> recommendByGenre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users);
    
    bool checkMovieExist(const Movie *movie);
    
    float calculateMovieScore(const string &genre,const Movie* movie, const vector<RegisteredUser*>& users);
    int calculateDirectorEffect(const Movie* movie);
    int calculateCastEffect(const Movie* movie);

private:
    string name;
    vector<Movie*> watchedMovies;
    vector<string> ratings;
};


#endif