#include "view.h"
#include "genre.h"
#include "age.h"
#include "media.h"
#include "dialogs.h"
#include <iostream>
#include <string>

int View::select_from_menu() {
  std::string menu = R"(
=================================
CSE1325 Library Management System
=================================

Publications
------------
(1) Add publication
(2) List all publications
(3) Check out publication
(4) Check in publication

Patrons
-------
(5) Add patron
(6) List all patrons

Utility
-------
(9) Help
(0) Exit

)";

  std::string result = Dialogs::input(menu, "Main Menu");
  try {
    return (result == "CANCEL") ? 0 : std::stoi(result);
  } catch (...) {
    return -1;
  }
}

std::string View::get_publications() {
  std::string publications = "";
  for (int i=0; i<library.number_of_publications(); ++i) {
    publications += std::to_string(i) + ") " + library.publication_to_string(i) + '\n';
  }
  return publications;
}

void View::list_publications() {
  Dialogs::message(get_publications(), "List of Library Publications");
}


int View::select_publication() {
  std::string result = Dialogs::input(get_publications(), "Select a Publication");
  try {
    return (result == "CANCEL") ? -1 : std::stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}

std::string View::get_patrons() {
  std::string patrons = "";
  for (int i=0; i<library.number_of_patrons(); ++i) {
    patrons += std::to_string(i) + ") " + library.patron_to_string(i) + '\n';
  }
  return patrons;
}


void View::list_patrons() {
  Dialogs::message(get_patrons(), "List of Beloved Patrons");
}

int View::select_patron() {
  std::string patrons = get_patrons();

  std::string result = Dialogs::input(patrons, "Select a Beloved Patron");
  try {
    return (result == "CANCEL") ? -1 : std::stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}

int View::select_genre() {
    std::string genres = "";
    for (int i = 0; i < Genre::num_genres; ++i)
      genres += std::to_string(i) + ") " + Genre(i).to_string() + '\n';

  std::string result = Dialogs::input(genres, "Select a genre");
  try {
    return (result == "CANCEL") ? -1 : std::stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}

int View::select_age() {
    std::string ages = "";
    for (int i = 0; i < Age::num_ages; ++i)
      ages += std::to_string(i) + ") " + Age(i).to_string() + '\n';

  std::string result = Dialogs::input(ages, "Select an Age Category");
  try {
    return (result == "CANCEL") ? -1 : std::stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}

int View::select_media() {
    std::string media = "";
    for (int i = 0; i < Media::num_media; ++i)
      media += std::to_string(i) + ") " + Media(i).to_string() + '\n';

  std::string result = Dialogs::input(media, "Select Media Type");
  try {
    return (result == "CANCEL") ? -1 : std::stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}


void View::help() {
  std::string helptext = R"(
The LMS tracks publication assets for a library, including those who
check out and return those publications.

(1) Add publication - This allows the librarian to enter data
    associated with a new publication.
(2) List all publications - All data known about each publication
    in the library is listed.
(3) Check out publication - Enter the data for patrons who check out
    a publication, and mark that publication as checked out.
(4) Check in publication - Select a publication and mark it as checked in.

(5) Add patron - This allows the librarian to enter data associated
    with a new library patron.
(6) List patrons - All data know about each patron of the library.

(9) Help - Print this text.
(0) Exit - Exit the program. WARNING: The current version does NOT
    save any entered data. This feature will be added in the "next version".

Use the '99' command to pre-populate test data.
  )";
  Dialogs::message(helptext, "Help");
}


