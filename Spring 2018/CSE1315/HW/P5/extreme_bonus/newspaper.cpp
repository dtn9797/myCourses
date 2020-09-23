 #include "newspaper.h"
 #include <string>
 #include <iostream>

 using namespace std;


 string Newspaper::to_string() {
   string pub = "\"" + title + "\"" + " by " + author + ", " + copyright 
         + " (" + target_age.to_string() + " " + genre.to_string() + " "  
         + city + ") " 
         + media.to_string() 
         + " ISBN: " + isbn;
   if (checked_out) {
      pub += "\nChecked out to " + patron.get_patron_name() + 
             " (" + patron.get_patron_phone_number() + ")";
   }
   return pub;
 }

 ostream& operator<<(ostream& os, Newspaper& p) {
     os << p.to_string();
     return os;
 }
