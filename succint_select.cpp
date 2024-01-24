#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
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

    s::rrr_vector<127> rrrBitArray(bitArray);
    s::rrr_vector<127>::select_1_type select_rrrBitArray(&rrrBitArray);

    cout << select_rrrBitArray(888484) << "\n";

    auto endTime = sc::high_resolution_clock::now();
    auto duration = sc::duration_cast<sc::microseconds>(endTime - startTime);

    cout << "Time taken to execute: " << 1000 * duration.count() << " nanoseconds\n";

    return 0;
}

