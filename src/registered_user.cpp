#include "registered_user.hpp"

RegisteredUser::RegisteredUser(string _name,vector<Movie*> _watched,const vector<string> _ratings)
              :name(_name), watched_movies(_watched), ratings(_ratings) {}

string RegisteredUser::get_name() const {return name;}

vector<pair<Movie*, float>> RegisteredUser::recommend_by_genre( const string& genre, const vector<Movie*>& movies, const vector<RegisteredUser*>& users){
    cout << "[DEBUG] Personalized genre recommendation not implemented yet.\n";
    return {};
}

// Stub for cast recommendation
void RegisteredUser::recommend_by_cast()  {
    cout << "[DEBUG] Personalized cast recommendation not implemented yet.\n";
}