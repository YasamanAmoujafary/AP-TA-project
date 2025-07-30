#include "registered_user.hpp"

RegisteredUser::RegisteredUser(string _name,vector<Movie*> _watched,const vector<string> _ratings)
              :name(_name), watched_movies(_watched), ratings(_ratings) {}

string RegisteredUser::get_name() const {return name;}

void RegisteredUser::recommend_by_genre()  {
    cout << "[DEBUG] Personalized genre recommendation not implemented yet.\n";
}

// Stub for cast recommendation
void RegisteredUser::recommend_by_cast()  {
    cout << "[DEBUG] Personalized cast recommendation not implemented yet.\n";
}