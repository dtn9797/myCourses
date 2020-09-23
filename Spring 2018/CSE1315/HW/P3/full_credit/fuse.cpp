#include "fuse.h"

Fuse::Fuse(int time) : _time{time} { }

bool Fuse::burn() {
  _time = (_time > 0) ? --_time : _time;
  return _time > 0;
}

string Fuse::to_string() {
  string result = "   ";
  for(int i = 0; i < _time; ++i) result += '_';
  result += "*\n  /\n,+,\n| |\n|_|\n";
  return result;
}

