#ifndef IOHANDLER
#define IOHANDLER

#include "movie_recommender.hpp"

class IOHandler
{
public:
    IOHandler(const string &user_file, const string &movie_file);
    vector<Movie*> map_titles_to_movies(const vector<string>& titles) const;
    void check_user();
private:
    MovieRecommender *movie_recommender;
    void parse_users_file(const string &file_name);
    void parse_movies_file(const string &file_name);
};

#endif