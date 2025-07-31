#ifndef REGISTEREDUSER
#define REGISTEREDUSER

#include "user.hpp"

class RegisteredUser : public User
{
public:
    RegisteredUser(string _name,vector<Movie*> _watched,const vector<string> _ratings);
    vector<pair<Movie*, float>> recommend_by_genre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users);
    void recommend_by_cast();
    string get_name() const;
    vector<Movie*> get_movies(){return watched_movies;}
    vector<string> get_ratings(){return ratings;}
private:
    string name;
    vector<Movie*> watched_movies;
    vector<string> ratings;
};


#endif