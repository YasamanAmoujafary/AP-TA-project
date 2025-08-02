#include "io_handler.hpp"

IOHandler::IOHandler(const string &user_file, const string &movie_file)
{
    movieRecommender = new MovieRecommender();
    parseMoviesFile(movie_file);
    parseUsersFile(user_file);
}

void IOHandler::parseMoviesFile(const string& filename) 
{
    ifstream file(filename);
    string line;
    getline(file, line);
    while (getline(file, line)) {
        vector<string> tokens = split(line, DIFF_TYPE_DELIM);
        if (tokens.size() != 5) {
            throw BadRequest();
        }
        string name = tokens[0];
        string director = tokens[1];
        string cast = tokens[2];
        string genre = tokens[3];
        int imdb = stoi(tokens[4]);
        Movie* movie = new Movie(name, director, cast, genre, imdb);
        movieRecommender->addMovie(movie);
    }
    file.close();
}


vector<Movie*> IOHandler::mapTitlesToMovies(const vector<string>& titles)  {
    vector<Movie*> result;
    const vector<Movie*>& all_movies = movieRecommender->getMovies();

    for (const string& title : titles) {
        for (Movie* m : all_movies) {
            if (m->getName() == title) {
                result.push_back(m);
                break;
            }
        }
    }

    return result;
}


void IOHandler::parseUsersFile(const string &filename)
{
    ifstream file(filename);
    string line;
    getline(file, line);

    while(getline(file, line))
    {
        vector<string> tokens = split(line, DIFF_TYPE_DELIM);
        if(tokens.size() != USER_INPUT_PART_SIZE){
           throw BadRequest(); 
        }
        string name = tokens[0];
        vector<string> watched = split(tokens[1], ONE_TYPE_DELIM);
        vector<string> ratings = split(tokens[2], ONE_TYPE_DELIM);

        vector<Movie*> watchedMovies = mapTitlesToMovies(watched);

        RegisteredUser* user = new RegisteredUser(name, watchedMovies, ratings);

        movieRecommender->addUser(user);
    }
    file.close();
}


void IOHandler::runCommandLoop() 
{
    string line;
    while(getline(cin, line))
    {
        if(line.empty()) continue;
        try
        {

            handleCommand(line);
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
}

void IOHandler::handleCommand(const string &line)
{
    vector<string> parts = parseCommand(line);
    string command = parts[0];
    parts = {parts.begin() + 1, parts.end()};
    if(command == GENRE_RECOMMANDATION_COMMAND)
    {
        vector<pair<Movie*, float>> scored_movies = handleGenreRecommandation(parts);
        printGenreRecommandedMovies(scored_movies);

    }
    else if(command == CAST_RECOMMANDATION_COMMAND)
    {
        
        vector<Movie*> cast_movies = handleCastRecommandation(parts);
        printCastRecommandedMovies(cast_movies);
    }
    else
    {
        throw BadRequest();
    }
}

vector<string> IOHandler::parseCommand(const string &inputLine)
{
    vector<string> parts;
    string current;
    bool inQuotes = false;

    for (char ch : inputLine) {
        if (ch == QUOTE_DEILM) {
            inQuotes = !inQuotes;
            if (!inQuotes && !current.empty()) {
                parts.push_back(current);
                current.clear();
            }
        }
        else if (ch == INPUT_COMMAND_DELIM && !inQuotes) {
            if (!current.empty()) {
                parts.push_back(current);
                current.clear();
            }
        }
        else {
            current += ch;
        }
    }

    if (!current.empty()) {
        parts.push_back(current);
    }

    return parts;
}


vector<pair<Movie*, float>> IOHandler::handleGenreRecommandation(const vector<string> &parts)
{
    string username;
    string genre;
    if(parts.size() == REGISTER_USER_PART_SIZE)
    {
        username = parts[0];
        genre = parts[1];
        
    }
    else if(parts.size() == NON_REGISTER_USER_PART_SIZE)
    {
        username = "";
        genre = parts[0];
        
    }
    else
    {
        throw BadRequest();
    }
    return movieRecommender->recommandMoviesByGenre(username, genre);
}

vector<Movie*> IOHandler::handleCastRecommandation(const vector<string> &parts)
{
    string username;
    string cast;
    if(parts.size() == REGISTER_USER_PART_SIZE)
    {
        username = parts[0];
        cast = parts[1];
        
    }
    else if(parts.size() == NON_REGISTER_USER_PART_SIZE)
    {
        username = "";
        cast = parts[0];
        
    }
    else
    {

        throw BadRequest();
    }
    return movieRecommender->recommandMoviesByCast(username, cast);

}

void IOHandler::printGenreRecommandedMovies(vector<pair<Movie*, float>>& scoredMovies)
{
    for (int i = 0; i < min(MAXIMUM_GENRE_RECOMMANDED_MOVIES, (int)scoredMovies.size()); ++i) {
    Movie* m = scoredMovies[i].first;
    cout << (i + 1) << ". " << m->getName() << ": " << m->getDirector()
         << " (" << m->getIMDb() << ")" <<endl;
    }
}

void IOHandler::printCastRecommandedMovies(vector<Movie*>& castMovies)
{
    for (int i = 0; i < min(MAXIMUM_CAST_RECOMMANDED_MOVIES, (int)castMovies.size()); ++i) {
    Movie* m = castMovies[i];
    cout << (i + 1) << ". " << m->getName() << ": " << m->getDirector()
         << " (" << m->getIMDb() << ")" << endl;
    }
}