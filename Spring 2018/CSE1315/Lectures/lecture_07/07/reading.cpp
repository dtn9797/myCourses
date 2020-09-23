#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Reading { // a temperature reading
    public:
        Reading(int p_hour, double p_temp)
            : hour(p_hour), temperature(p_temp) {validate();}
        int get_hour() {return hour;}
        double get_temp() {return temperature;}
        friend istream &operator>>(istream  &ist, Reading &r);
        void validate() {
          if (hour < 0 || 23 < hour) {
            throw runtime_error("hour out of range");
          }
        }
    private:
        int hour;       // hour after midnight [0:23]
        double temperature;
};

istream& operator>>(istream  &ist, Reading &r) {
  ist >> r.hour >> r.temperature;
  r.validate();
  return ist;
}

int main()
{
        vector<Reading> temps;       // create a vector to store the readings
        Reading reading{0,0};        // temporary to hold input

        while (cin >> reading) temps.push_back(reading);  // read and store
}

