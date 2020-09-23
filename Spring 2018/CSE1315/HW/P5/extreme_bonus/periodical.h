 #ifndef __PERIODICAL_H
 #define __PERIODICAL_H 201609
 #include "publication.h"
 #include "patron.h"
 
 #include "media.h"
 #include "genre.h"
 #include "age.h"

 #include <iostream>
 #include <string>

 using namespace std;


 class Periodical : public Publication {
   public:
     Periodical (string p_title, 
           string p_author, 
           string p_copyright,
           Genre p_genre, 
           Media p_media, 
           Age p_target_age,
           string p_isbn,
           bool by_week,
           bool by_month) : 

           weekly(by_week),
           monthly(by_month),
           Publication(p_title, p_author, p_copyright,
                       p_genre, p_media, p_target_age, p_isbn)
           { }

     virtual string to_string();

     friend ostream& operator<<(ostream& os, Publication& p);

   protected:
     bool weekly;
     bool monthly; // default quarterly
 };
 #endif
