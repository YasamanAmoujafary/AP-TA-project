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


vector<Movie*> IOHandler::map_titles_to_movies(const vector<string>& titles) const {
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