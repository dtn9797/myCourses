
 #ifndef __ENUMS_H
 #define __ENUMS_H 201709

 #include <vector>
 #include <string>
 using namespace std;

 // To convert an enumerated value to a string, subscript its vector
 // E.g., given "Age age = Age::teen;", "ages[age]" will return the string version

 enum Age {children, teen, adult, restricted};
 const vector<string> ages = {"children", "teen", "adult", "restricted"};

 enum Genre {fiction, nonfiction, selfhelp, performance};
 const vector<string> genres = {"fiction", "nonfiction", "self help", "performance"};

 enum Media {book, periodical, newspaper, audio, video};
 const vector<string> medias = {"book", "periodical", "newspaper", "audio", "video"};

 #endif
