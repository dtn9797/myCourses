#include "puzzle.h"
#include <cctype>

Puzzle::Puzzle(string solution) {
        for (char c : solution) _solution += tolower(c);
        for(int i=0; i<256; ++i) 
            _guesses.push_back(i < 'a' || i > 'z');
}

bool Puzzle::guess(char c) {
  char cc = tolower(c);
  if (cc<'a' || cc>'z' || _guesses[c])  {
    return false;
  } else {
    _guesses[cc] = true;
    return true;
  }
}

bool Puzzle::solve(string proposed_solution) {
  return (proposed_solution == _solution);
}

string Puzzle::to_string() {
  string result = "";
  for (char c: _solution) 
    result += _guesses[c] ? c : '_';
  return result;
}

string Puzzle::get_solution() {
  return _solution;
}


