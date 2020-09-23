 #ifndef __PUBLICATION_H
 #define __PUBLICATION_H 201609
 
 #include "media.h"
 #include "genre.h"
 #include "age.h"

 #include <iostream>
 #include <string>

 using namespace std;


 class Publication {
   public:
     Publication(string p_title, 
                 string p_author, 
                 string p_copyright,
                 Genre p_genre, 
                 Media p_media, 
                 Age p_target_age,
                 string p_isbn) : 

                 title(p_title), 
                 author(p_author),
                 copyright(p_copyright), 
                 genre(p_genre), 
                 media(p_media),
                 target_age(p_target_age), 
                 isbn(p_isbn), 
                 patron(""),
                 patron_phone(""),
                 checked_out(false) { }

     bool is_checked_out();

     void check_out(string name, string phone);
     void check_in();

     string to_string();

     // Thrown on check_in if publication isn't checked out
     //   or on cheeck_out if publication is already checked out
     class Invalid_transaction { }; 

   private:
     string title;
     string author;
     string copyright;
     Genre genre;
     Media media;
     Age target_age;
     string isbn;
     string patron;
     string patron_phone;
     bool checked_out;
 };
 #endif
