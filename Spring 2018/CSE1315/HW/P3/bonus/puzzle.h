#include <string>
#include <vector>
#include <exception>
#include <functional>
using namespace std;

class Puzzle {
  public:
    Puzzle(string solution);
    class Bad_char : public exception { };
    bool guess(char c);                   // true if char is in solution
                                          // throws Bad_char is invalid
    bool solve(string proposed_solution); // true if correctly guessed
    string to_string();
    string get_solution();
  private:
    string _solution;
    vector<bool> _guesses;
};
