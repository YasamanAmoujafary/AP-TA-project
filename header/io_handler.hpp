#ifndef IOHANDLER
#define IOHANDLER

#include "movie_recommender.hpp"

class IOHandler
{
public:
    IOHandler(const string &user_file, const string &movie_file);
    vector<Movie*> map_titles_to_movies(const vector<string>& titles) ;
    void check_user();
    void runCommandLoop();
    void handleCommand(const string &line);
    vector<string> parseCommand(const string &inputLine);
    vector<pair<Movie*, float>> handleGenreRecommandation(const vector<string> &parts);
    void handleCastRecommandation(const vector<string> &parts);
    void print_genre_recommanded_movies(vector<pair<Movie*, float>>& scored_movies);

private:
    MovieRecommender *movie_recommender;
    void parse_users_file(const string &file_name);
    void parse_movies_file(const string &file_name);
};

#endif