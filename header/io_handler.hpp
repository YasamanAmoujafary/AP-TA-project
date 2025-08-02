#ifndef IOHANDLER
#define IOHANDLER

#include "movie_recommender.hpp"

class IOHandler
{
public:
    IOHandler(const string &user_file, const string &movie_file);

    void runCommandLoop();
    void handleCommand(const string &line);
    void printGenreRecommandedMovies(vector<pair<Movie*, float>>& scoredMovies);
    void printCastRecommandedMovies(vector<Movie*>& castMovies);

    vector<string> parseCommand(const string &inputLine);

    vector<pair<Movie*, float>> handleGenreRecommandation(const vector<string> &parts);
    
    vector<Movie*> mapTitlesToMovies(const vector<string>& titles) ;
    vector<Movie*> handleCastRecommandation(const vector<string> &parts);

private:
    MovieRecommender *movieRecommender;
    void parseUsersFile(const string &filename);
    void parseMoviesFile(const string &filename);
};

#endif