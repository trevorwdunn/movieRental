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

// Function prototypes
void presentMenu();
string getfileName();
vector<Movie> readMoviesFromFile(vector<Movie> movies, string fileName);

int main() {
	// Create a vector of movies
	vector<Movie> movies;
	string userName;
	string fileName;

	// Get some basic information
	cout << "What is your name?" << endl;
	getline(cin, userName);

	getfileName();
	presentMenu();
	readMoviesFromFile(movies, fileName);

	return 0;
}

void presentMenu() {
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
		// List all movies
		break;
	case 2:
		// Search for a movie
		break;
	case 3:
		// Rent a movie
		break;
	case 4:
		// Return a movie
		break;
	case 5:
		// Exit
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
		cout << "Enter the name of the file you would like to read from: ";
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