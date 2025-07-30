#ifndef MOVIE
#define MOVIE

#include "utilities.hpp"

class Movie
{
public:
    Movie(string _name, string _director, string _cast, string _genre, int _IMDb);
    string getName() const;
    string getDirector() const;
    string getCast() const;
    string getGenre() const;
    int getIMDb() const;
private:
    string name;
    string director;
    string cast;
    string genre;
    int IMDb;
};

#endif