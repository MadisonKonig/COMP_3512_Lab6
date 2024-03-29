#pragma once

#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>
#include "City.hpp"

class Tour : public City{
public:
	static constexpr int CITIES_IN_TOUR = 20;
	static constexpr int POPULATION_SIZE = 30;
	static constexpr int NUMBER_OF_ELITES = 1;
	static constexpr int NUMBER_OF_PARENTS = 2;
	static constexpr int PARENT_POOL_SIZE = 5;
	static constexpr int SHUFFLES = 32;
	const double FITNESS_SCALER = 10000.0;
	const double MUTATION_RATE = 0.15;
	double fitness;
	City permutation[CITIES_IN_TOUR];
	void shuffle_cities(City *);
	double get_distance_between_cities(City, City);
	double get_tour_distance(Tour);
	int determine_fitness(Tour *, int);
	void swap_cities(int, int , City*);
	Tour* select_parents(Tour *);
	Tour* crossover(Tour *);
	void mutate(Tour *);
	int contains_city(Tour *, int, City *);
	double random(double, double);
	int getPop() {
		return POPULATION_SIZE;
	}
};