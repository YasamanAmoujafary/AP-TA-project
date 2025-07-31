#include "io_handler.hpp"

IOHandler::IOHandler(const string &user_file, const string &movie_file)
{
    movie_recommender = new MovieRecommender();
    parse_movies_file(movie_file);
    parse_users_file(user_file);
}

void IOHandler::parse_movies_file(const string& filename) 
{
    ifstream file(filename);
    string line;
    getline(file, line);
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        if (tokens.size() != 5) {
            throw BadRequest();
        }
        string name = tokens[0];
        string director = tokens[1];
        string cast = tokens[2];
        string genre = tokens[3];
        int imdb = stoi(tokens[4]);
        Movie* movie = new Movie(name, director, cast, genre, imdb);
        movie_recommender->addMovie(movie);
    }
    file.close();
}


vector<Movie*> IOHandler::map_titles_to_movies(const vector<string>& titles)  {
    vector<Movie*> result;
    const vector<Movie*>& all_movies = movie_recommender->getMovies();

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


void IOHandler::parse_users_file(const string &file_name)
{
    ifstream file(file_name);
    string line;
    getline(file, line);

    while(getline(file, line))
    {
        cout << line <<endl;
        vector<string> tokens = split(line, DIFF_TYPE_DELIM);
        if(tokens.size() != USER_INPUT_PART_SIZE){
           throw BadRequest(); 
        }
        string name = tokens[0];
        vector<string> watched = split(tokens[1], ONE_TYPE_DELIM);
        vector<string> ratings = split(tokens[2], ONE_TYPE_DELIM);

        vector<Movie*> watched_movies = map_titles_to_movies(watched);

        RegisteredUser* user = new RegisteredUser(name, watched_movies, ratings);

        movie_recommender->addUser(user);
    }
    file.close();
}

void IOHandler::check_user()
{
    vector<RegisteredUser*>users = movie_recommender->getUsers();
    // vector<Movie*> movies = movie_recommender->getMovies();
    cout << users.size()<<endl;
    for(auto user : users){
        cout << user->get_name() <<endl;
        vector<Movie*> movies = user->get_movies();
        vector<string> ratings = user->get_ratings();
        cout << ratings.size() <<endl;
        cout << movies.size() <<endl;

        for (int i=0; i<movies.size(); i++){
            cout <<ratings[i];
            cout << movies[i]->getName()<<"...."<<movies[i]->getCast()<<"...."<<movies[i]->getDirector()<<"...."<<movies[i]->getGenre()<<"..."<<movies[i]->getIMDb()<<endl;
        }
    }
}

void IOHandler::runCommandLoop() 
{
    string line;
    while(getline(cin, line))
    {
        if(line.empty()) continue;
        handleCommand(line);
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
        print_genre_recommanded_movies(scored_movies);

    }
    else if(command == CAST_RECOMMANDATION_COMMAND)
    {
        handleCastRecommandation(parts);
    }
    else
    {
        throw BadRequest();
    }
}

vector<string> IOHandler::parseCommand(const string &inputLine)
{
    vector<string> parts = split(inputLine, INPUT_COMMAND_DELIM);

    for(string& part : parts)
    {
        if(part.front() == QUOTE_DEILM && part.back() == QUOTE_DEILM)
        {
            part = part.substr(1, part.size() - 2);
        }
    }
    return parts;
}

vector<pair<Movie*, float>> IOHandler::handleGenreRecommandation(const vector<string> &parts)
{
    string username;
    string genre;
    if(parts.size() == 2)
    {
        username = parts[0];
        genre = parts[1];
        
    }
    else if(parts.size() == 1)
    {
        username = "";
        genre = parts[0];
        
    }
    else
    {
        throw BadRequest();
    }
    return movie_recommender->recommandMoviesByGenre(username, genre);
}

void IOHandler::handleCastRecommandation(const vector<string> &parts)
{
    string username;
    string cast;
    if(parts.size() == 2)
    {
        username = parts[0];
        cast = parts[1];
        
    }
    else if(parts.size() == 1)
    {
        username = "";
        cast = parts[0];
        
    }
    else
    {
        throw BadRequest();
    }
    return movie_recommender->recommandMoviesByCast(username, cast);

}

void IOHandler::print_genre_recommanded_movies(vector<pair<Movie*, float>>& scored_movies)
{
    for (int i = 0; i < min(3, (int)scored_movies.size()); ++i) {
    Movie* m = scored_movies[i].first;
    cout << (i + 1) << ". " << m->getName() << ": " << m->getDirector()
         << " (" << m->getIMDb() << ")" << endl;
}
}