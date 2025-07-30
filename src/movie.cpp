#include "movie.hpp"


Movie::Movie(string _name, string _director, string _cast, string _genre, int _IMDb)
    : name(_name), director(_director), cast(_cast), genre(_genre), IMDb(_IMDb) {}

string Movie::getName() const {
    return name;
}

string Movie::getDirector() const {
    return director;
}

string Movie::getCast() const {
    return cast;
}

string Movie::getGenre() const {
    return genre;
}

int Movie::getIMDb() const {
    return IMDb;
}
