#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include "sdsl/bit_vectors.hpp"

namespace s = sdsl;
namespace sc = std::chrono;
using namespace std;

int main() {
    int lineCount = 0;
    string sequence = "";

    string filePath = "sequence.fasta";
    ifstream fileReader(filePath);

    while (getline(fileReader, sequence)) {
        if (lineCount > 0) {
            sequence += sequence;
        }
        lineCount++;
    }

    auto startTime = sc::high_resolution_clock::now();

    s::bit_vector bitArray(sequence.length(), 0);

    for (size_t i = 0; i < sequence.length(); ++i) {
        bitArray[i] = (sequence[i] == 'A');
    }

    s::rank_support_v<> rankSupport(&bitArray);

    int positionToQuery = 14343555;
    int result = rankSupport(positionToQuery);

    cout << "Result of rank query at position " << positionToQuery << ": " << result << "\n";

    auto endTime = sc::high_resolution_clock::now();
    auto duration = sc::duration_cast<sc::microseconds>(endTime - startTime);

    cout << "Time taken to execute: " << 1000 * duration.count() << " nanoseconds\n";

    return 0;
}

