 #ifndef __AUDIO_H
 #define __AUDIO_H 201609
 #include "publication.h"
 #include "patron.h"
 
 #include "media.h"
 #include "genre.h"
 #include "age.h"

 #include <iostream>
 #include <string>

 using namespace std;


 class Audio : public Publication {
   public:
     Audio (string p_title, 
           string p_author, 
           string p_copyright,
           Genre p_genre, 
           Media p_media, 
           Age p_target_age,
           string p_isbn,
           bool p_mp3,
           bool p_cd) : 

           mp3(p_mp3),
           cd(p_cd),
           Publication(p_title, p_author, p_copyright,
                       p_genre, p_media, p_target_age, p_isbn)
           { }

     virtual string to_string();

     friend ostream& operator<<(ostream& os, Publication& p);

   protected:
     bool mp3;
     bool cd; // default cassette
 };
 #endif
