#ifndef REGISTEREDUSER
#define REGISTEREDUSER

#include "user.hpp"

class RegisteredUser : public User
{
public:
    RegisteredUser(string _name,vector<Movie*> _watched,const vector<string> _ratings);
    void recommend_by_genre();
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