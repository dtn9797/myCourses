 #ifndef __NEWSPAPER_H
 #define __NEWSPAPER_H 201609
 #include "publication.h"
 #include "patron.h"
 
 #include "media.h"
 #include "genre.h"
 #include "age.h"

 #include <iostream>
 #include <string>

 using namespace std;


 class Newspaper : public Publication {
   public:
     Newspaper (string p_title, 
           string p_author, 
           string p_copyright,
           Genre p_genre, 
           Media p_media, 
           Age p_target_age,
           string p_isbn,
           string p_city) : 

           city(p_city),
           Publication(p_title, p_author, p_copyright,
                       p_genre, p_media, p_target_age, p_isbn)
           { }

     virtual string to_string();

     friend ostream& operator<<(ostream& os, Publication& p);

   protected:
     string city;
 };
 #endif
