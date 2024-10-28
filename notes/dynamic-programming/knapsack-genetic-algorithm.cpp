#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

struct Item {
    int value;
    int weight;
};

const int MAX_WEIGHT = 50;
const int POPULATION_SIZE = 50;
const int NUM_GENERATIONS = 100;
const double CROSSOVER_RATE = 0.7;
const double MUTATION_RATE = 0.01;

std::vector<Item> items = {{10, 10},{10, 10},{10, 10},{10, 10},{10, 10}, {40, 40},{20, 10}, {20, 10}};
int numItems = items.size();
std::mt19937 gen(time(0));

// Genera una solución aleatoria
std::vector<int> generateRandomSolution() {
    std::vector<int> solution(numItems);
    for (int &bit : solution) bit = gen() % 2; // 0 o 1
    return solution;
}

// Evalúa la aptitud (fitness) de una solución
int calculateFitness(const std::vector<int>& solution) {
    int totalValue = 0, totalWeight = 0;
    for (int i = 0; i < numItems; ++i) {
        if (solution[i] == 1) {
            totalValue += items[i].value;
            totalWeight += items[i].weight;
        }
    }
    return (totalWeight > MAX_WEIGHT) ? 0 : totalValue;
}

// Selecciona un individuo usando selección por torneo
std::vector<int> tournamentSelection(const std::vector<std::vector<int>>& population, const std::vector<int>& fitness) {
    int tournamentSize = 3;
    std::vector<int> best = population[gen() % POPULATION_SIZE];
    int bestFitness = calculateFitness(best);

    for (int i = 1; i < tournamentSize; ++i) {
        std::vector<int> individual = population[gen() % POPULATION_SIZE];
        int indFitness = calculateFitness(individual);
        if (indFitness > bestFitness) {
            best = individual;
            bestFitness = indFitness;
        }
    }
    return best;
}

// Aplica cruce de un punto entre dos individuos
std::vector<int> crossover(const std::vector<int>& parent1, const std::vector<int>& parent2) {
    std::vector<int> child(numItems);
    int crossoverPoint = gen() % numItems;
    for (int i = 0; i < numItems; ++i) {
        child[i] = (i < crossoverPoint) ? parent1[i] : parent2[i];
    }
    return child;
}

// Aplica mutación a un individuo
void mutate(std::vector<int>& individual) {
    for (int i = 0; i < numItems; ++i) {
        if ((double)gen() / gen.max() < MUTATION_RATE) {
            individual[i] = 1 - individual[i];
        }
    }
}

// Imprime la mejor solución encontrada
void printSolution(const std::vector<int>& solution) {
    int totalValue = calculateFitness(solution);
    int totalWeight = 0;
    std::cout << "Best solution: ";
    for (int i = 0; i < numItems; ++i) {
        if (solution[i] == 1) {
            std::cout << "Item " << i + 1 << " ";
            totalWeight += items[i].weight;
        }
    }
    std::cout << "\nTotal value: " << totalValue << "\nTotal weight: " << totalWeight << "\n";
}

int main() {
    std::vector<std::vector<int>> population(POPULATION_SIZE);
    for (std::vector<int>& individual : population) {
        individual = generateRandomSolution();
    }

    for (int generation = 0; generation < NUM_GENERATIONS; ++generation) {
        std::vector<int> fitness(POPULATION_SIZE);
        for (int i = 0; i < POPULATION_SIZE; ++i) {
            fitness[i] = calculateFitness(population[i]);
        }

        std::vector<std::vector<int>> newPopulation;
        while (newPopulation.size() < POPULATION_SIZE) {
            std::vector<int> parent1 = tournamentSelection(population, fitness);
            std::vector<int> parent2 = tournamentSelection(population, fitness);

            std::vector<int> child;
            if ((double)gen() / gen.max() < CROSSOVER_RATE) {
                child = crossover(parent1, parent2);
            } else {
                child = parent1;
            }

            mutate(child);
            newPopulation.push_back(child);
        }
        population = newPopulation;
    }

    std::vector<int> bestIndividual = *std::max_element(population.begin(), population.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return calculateFitness(a) < calculateFitness(b);
    });

    printSolution(bestIndividual);
    return 0;
}
