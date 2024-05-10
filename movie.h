/*
The "Movie" Object will have the following characteristics:
1) Title
2) Synopsis
3) Runtime
4) Rating
6) Price
7) Quantity
*/

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

class Movie {
  private:
	std::string movieTitle;
	std::string movieSynopsis;
	std::string movieRuntime;
	std::string director;
	int movieRating;
	double moviePrice;
	int movieQuantity;

  public:
	Movie(std::string movieTitle, std::string MovieSynopsis,
		  std::string movieRuntime, std::string director, int movieRating,
		  double moviePrice, int movieQuantity);

	// Setters
	void setMovieTitle();
	void setMovieSynpsis();
	void setMovieRuntime();
	void setMovieRating();
	void setMoviePrice();
	void setMovieQuantity();
	void setDirector();

	// Getters
	std::string getMovieTitle() const;
	std::string getMovieSynposis() const;
	std::string getMovieRuntime() const;
	std::string getDirector() const;
	int getMovieRating() const;
	double getMoviePrice() const;
	int getMovieQuantity() const;

	void printMovieTitle();
	void printMovieInfo();
};

#endif // !MOVIE_H
