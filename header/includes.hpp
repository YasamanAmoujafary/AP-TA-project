#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <algorithm>



using namespace std;

const char DIFF_TYPE_DELIM = ',';
const char ONE_TYPE_DELIM = ';';
const char INPUT_COMMAND_DELIM = ' ';
const char QUOTE_DEILM = '"';

const string NOT_FOUND = "Not Found";
const string EMPTY = "Empty";
const string BAD_REQUEST = "Bad Request";

const string GENRE_RECOMMANDATION_COMMAND = "genre_recommandation";
const string CAST_RECOMMANDATION_COMMAND = "cast_recommandation";


const int USER_INPUT_PART_SIZE = 3;


const string DRAMA_GENRE = "Drama";
const string COMEDY_GENRE = "Comedy";
const string ACTION_GENRE = "Action";
const string SCI_FIC_GENRE = "Science Fiction";
const string HORROR_GENRE = "Horror";

const string PERFECT = "Perfect";
const string AVERAGE = "Average";
const string POOR = "Poor";

const float NON_REG_PERFECT_WEIGHT = 0.7f;
const float NON_REG_AVERAGE_WEIGHT = 0.5f;
const float NON_REG_POOR_WEIGHT = -0.2f;



