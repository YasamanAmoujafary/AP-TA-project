#include "utilities.hpp"

vector<string> split(const string& str, char delimiter) 
{
    vector<string> tokens;
    string token;
    for (char c : str) {
        if (c == delimiter) {
            if (!token.empty()) tokens.push_back(token);
            token.clear();
        } else {
            token += c;
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}