#include "movie.h"

// Constructor
Movie::Movie(std::string movieTitle, std::string MovieSynopsis,
			 std::string movieRuntime, std::string director, int movieRating,
			 double moviePrice,
			 int movieQuantity) // Remove the semicolon at the end of the
								// function declaration
{}

// Setters
void Movie::setMovieTitle() {
	std::cout << "Enter the movie title: ";
	std::getline(std::cin, movieTitle);
}

void Movie::setMovieSynpsis() {
	std::cout << "Enter the movie synopsis: ";
	std::getline(std::cin, movieSynopsis);
}

void Movie::setMovieRuntime() {
	std::cout << "Enter the movie runtime: ";
	std::getline(std::cin, movieRuntime);
}

void Movie::setMovieRating() {
	std::cout << "Enter the movie rating: ";
	std::cin >> movieRating;
}

void Movie::setMoviePrice() {
	std::cout << "Enter the movie price: ";
	std::cin >> moviePrice;
}

void Movie::setMovieQuantity() {
	std::cout << "Enter the movie quantity: ";
	std::cin >> movieQuantity;
}

void Movie::setDirector() {
	std::cout << "Enter the director: ";
	std::getline(std::cin, director);
}

// Getters
std::string Movie::getMovieTitle() const { return movieTitle; }

std::string Movie::getMovieSynposis() const { return movieSynopsis; }

std::string Movie::getMovieRuntime() const { return movieRuntime; }

std::string Movie::getDirector() const { return director; }

int Movie::getMovieRating() const { return movieRating; }

double Movie::getMoviePrice() const { return moviePrice; }

int Movie::getMovieQuantity() const { return movieQuantity; }

void Movie::printMovieTitle() {
	std::cout << "Movie Title: " << movieTitle << std::endl;
}

// Other member functions
void Movie::printMovieInfo() {
	std::cout << "Movie Title: " << movieTitle << std::endl;
	std::cout << "Movie Synopsis: " << movieSynopsis << std::endl;
	std::cout << "Movie Runtime: " << movieRuntime << std::endl;
	std::cout << "Director: " << director << std::endl;
	std::cout << "Movie Rating: " << movieRating << std::endl;
	std::cout << "Movie Price: " << moviePrice << std::endl;
	std::cout << "Movie Quantity: " << movieQuantity << std::endl;
}

// Path: main.cpp
