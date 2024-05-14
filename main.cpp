/*
		Created by: Trevor Dunn and Sameer Merchant
		Creation Date: February 28, 2024
		Project Name: Movie Rental Database
		Purpose: Create a database of movies to help ensure that we have a firm
		grasp on classes for upcoming labs and projects in Programming
		Fundamentals II

*/

#include "movie.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// Constants
const string DEFAULT_INVENTORY_LIST = "default_inventory.txt";

// Setup Functions
void presentMenu(vector<Movie> &movies);
string getfileName();
vector<Movie> readMoviesFromFile(vector<Movie> movies, string fileName);

// Menu Functions
void listMovies(vector<Movie> &movies);
void searchMovies(vector<Movie> &movies);
vector<Movie> rentMovie(vector<Movie> &movies);
vector<Movie> returnMovie(vector<Movie> &movies);

int main() {
	// Create a vector of movies
	vector<Movie> movies;
	string fileName;

	// Get the file name, if necessary
	fileName = getfileName();
	presentMenu(movies);
	readMoviesFromFile(movies, fileName);

	return 0;
}

void presentMenu(vector<Movie> &movies) {
	// Create a menu
	cout << "Movie Rental Database" << endl;
	cout << "Please select an option from the menu below:" << endl;
	cout << "1) List all movies" << endl;
	cout << "2) Search for a movie" << endl;
	cout << "3) Rent a movie" << endl;
	cout << "4) Return a movie" << endl;
	cout << "5) Exit" << endl;

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		listMovies(movies);
		break;
	case 2:
		searchMovies(movies);
		break;
	case 3:
		rentMovie(movies);
		break;
	case 4:
		returnMovie(movies);
		break;
	case 5:
		// Exit
		cout << "Thank you for using the Movie Rental Database. Goodbye!"
			 << endl;
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		break;
	}
}

string getfileName() {
	string fileName;
	char fileResponse;

	cout << "Would you like to read from a file? (y/n)" << endl;
	cin >> fileResponse;
	if (fileResponse == 'y') {
		cout << "Enter the full name of the file you would like to read from: ";
		cin >> fileName;
	} else {
		fileName = DEFAULT_INVENTORY_LIST;
	}

	// Attempt to open the file and set file to default if it cannot be opened.
	ifstream file(fileName);
	if (!file) {
		cout << "Could not open file. Using default inventory list." << endl;
		fileName = DEFAULT_INVENTORY_LIST;
	}

	return fileName;
}

vector<Movie> readMoviesFromFile(vector<Movie> movies, string fileName) {
	ifstream file(fileName);
	if (!file) {
		throw runtime_error("Could not open file.");
	}

	string title;
	string synopsis;
	string runtime;
	string director;
	int rating;
	double price;
	int quantity; // It would be better to find a way to do this so that when an
				  // identical movie is added, it adds to the quantity. Or it
				  // would be better to remove the quantity parameter
				  // altogether.

	while (getline(file, title)) {
		getline(file, synopsis);
		getline(file, runtime);
		getline(file, director);
		file >> rating;
		file >> price;
		file >> quantity;
		file.ignore(); // Ignore the newline character

		// Create a new Movie object and add it to the vector
		Movie movie(title, synopsis, runtime, director, rating, price,
					quantity);
		movies.push_back(movie);
	}

	return movies;
}

void listMovies(vector<Movie> &movies) {
	for (Movie movie : movies) {
		movie.printMovieTitle();
	}
}

void searchMovies(vector<Movie> &movies) {
	string search;
	cout << "Enter the title of the movie you would like to search for: ";
	getline(cin, search);

	// Search for the movie
	auto it = find_if(movies.begin(), movies.end(), [&search](Movie movie) {
		return movie.getMovieTitle() == search;
	});

	if (it != movies.end()) {
		it->printMovieInfo();
	} else {
		cout << "Movie not found." << endl;
	}
	cout << "Not yet implemented.\n";
}

vector<Movie> rentMovie(vector<Movie> &movies) {
	cout << "What is the title of the movie you would like to rent?\n";
	string title;
	cin.ignore();
	getline(cin, title);

	// Search for the movie
	auto it = find_if(movies.begin(), movies.end(), [&title](Movie movie) {
		return movie.getMovieTitle() == title;
	});

	if (it != movies.end()) {
		it->setMovieQuantity(-1);
	} else {
		cout << "Movie not found." << endl;
	}

	return movies;
}

vector<Movie> returnMovie(vector<Movie> &movies) {

	cout << "Not yet implemented.\n";
	return movies;
}