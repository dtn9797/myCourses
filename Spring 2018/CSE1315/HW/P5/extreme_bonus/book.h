 #ifndef __BOOK_H
 #define __BOOK_H 201609
 #include "publication.h"
 #include "patron.h"
 
 #include "media.h"
 #include "genre.h"
 #include "age.h"

 #include <iostream>
 #include <string>

 using namespace std;


 class Book : public Publication {
   public:
     Book (string p_title, 
           string p_author, 
           string p_copyright,
           Genre p_genre, 
           Media p_media, 
           Age p_target_age,
           string p_isbn,
           bool hard_cover) : 

           hardcover(hard_cover),
           Publication(p_title, p_author, p_copyright,
                       p_genre, p_media, p_target_age, p_isbn)
           { }

     virtual string to_string();

     friend ostream& operator<<(ostream& os, Publication& p);

   protected:
     bool hardcover;
 };
 #endif
