#include "controller.h"
#include "view.h"
#include "library.h"
#include "publication.h"
#include "patron.h"
#include "genre.h"
#include "media.h"
#include "age.h"
#include <iostream>
#include <string>

using namespace std;

void Controller::cli() {
  int cmd = -1;
  while (cmd != 0) {
    view.show_menu();
    cout << "Command? ";
    cin >> cmd;
    cin.ignore(); // consume \n
    execute_cmd(cmd);
  }
}

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add publication
    string title, author, copyright, isbn;
    int genre, media, age;

    cout << "Title? ";
    getline(cin, title);
    if (title.size() == 0) return;

    cout << "Author? ";
    getline(cin, author);
    if (author.size() == 0) return;

    cout << "Copyright date? ";
    getline(cin, copyright);
    if (copyright.size() == 0) return;

    for (int i = 0; i < Genre::num_genres; ++i) 
      cout << "  " << i << ") " << Genre(i).to_string() << endl;
    cout << "Genre? ";
    cin >> genre;
    cin.ignore(65535, '\n'); // consume \n
    if (0 > genre || genre >= Genre::num_genres) return;

    for (int i = 0; i < Media::num_media; ++i) 
      cout << "  " << i << ") " << Media(i).to_string() << endl;
    cout << "Media? ";
    cin >> media;
    cin.ignore(65535, '\n'); // consume \n
    if (0 > media || media >= Media::num_media) return;

    for (int i = 0; i < Age::num_ages; ++i) 
      cout << "  " << i << ") " << Age(i).to_string() << endl;
    cout << "Age? ";
    cin >> age;
    cin.ignore(65535, '\n'); // consume \n
    if (0 > age || age >= Age::num_ages) return;

    cout << "ISBN? ";
    getline(cin, isbn);
    if (isbn.size() == 0) return;

    library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));

 } else if (cmd == 2) { // List all publications
    view.list_publications();

 } else if (cmd == 3) { // Check out publication
    int pub, pat;

    view.list_publications();
    cout << "Publication number? ";
    cin >> pub;
    cin.ignore(65535, '\n'); // consume \n
    if (0 > pub || pub >= library.number_of_publications()) return;

    view.list_patrons();
    cout << "Patron number? ";
    cin >> pat;
    cin.ignore(65535, '\n'); // consume \n
    if (0 > pat || pat >= library.number_of_patrons()) return;

    try {
      library.check_out(pub, pat);
    } catch (Publication::Invalid_transaction e) {
      cerr << "ERROR: That publication is already checked out!" << endl;
    }
    
 } else if (cmd == 4) { // Check in publication
    int pub;
    view.list_publications();
    cout << "Publication number? ";
    cin >> pub;
    cin.ignore(65535, '\n'); // consume \n
    if (0 > pub || pub >= library.number_of_publications()) return;

    try {
      library.check_in(pub);
    } catch (Publication::Invalid_transaction e) {
      cerr << "ERROR: That publication is already checked in!" << endl;
    }

 } else if (cmd == 5) { // Add patron
    string name, number;

    cout << "Name? ";
    getline(cin, name);
    if (name.size() == 0) return;

    cout << "Phone number? ";
    getline(cin, number);
    if (number.size() == 0) return;

    library.add_patron(Patron(name, number));
    
 } else if (cmd == 6) { // List all patrons
    view.list_patrons();

 } else if (cmd == 9) { // Help
    view.help();
 } else if (cmd == 0) { // Exit
 } else if (cmd == 99) { // Easter Egg
   library.easter_egg();
 } else {
   cerr << "**** Invalid command - type 9 for help" << endl << endl;
 }
}

