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

string getFileName();
vector<Movie> readMoviesFromFile(string fileName);

int main() {
	// Get some basic information
	string userName;
	cout << "What is your name?" << endl;
	getline(cin, userName);

	cout << "Would you like to read from a file? (y/n)" << endl;
	char response;
	cin >> response;

	if (response == 'y') {
		string fileName = getFileName();
		vector<Movie> movies = readMoviesFromFile(fileName);
	}

	return 0;
}
