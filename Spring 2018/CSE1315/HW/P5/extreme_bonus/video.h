 #ifndef __VIDEO_H
 #define __VIDEO_H 201609
 #include "publication.h"
 #include "patron.h"
 
 #include "media.h"
 #include "genre.h"
 #include "age.h"

 #include <iostream>
 #include <string>

 using namespace std;


 class Video : public Publication {
   public:
     Video (string p_title, 
           string p_author, 
           string p_copyright,
           Genre p_genre, 
           Media p_media, 
           Age p_target_age,
           string p_isbn,
           bool p_mp4,
           bool p_dvd,
           bool p_bluray) : 

           mp4(p_mp4),
           dvd(p_dvd),
           bluray(p_bluray),
           Publication(p_title, p_author, p_copyright,
                       p_genre, p_media, p_target_age, p_isbn)
           { }

     virtual string to_string();

     friend ostream& operator<<(ostream& os, Publication& p);

   protected:
     bool mp4;
     bool dvd;
     bool bluray; // default VHS
 };
 #endif
