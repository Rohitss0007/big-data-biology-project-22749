#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<ctime>
#include<chrono>
using namespace std;

int main() {
    
    string filePath = "D:/sequence.fasta";
    

    
    ifstream fastaFile(filePath.c_str());

   
    if (!fastaFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    // Variables to store header and sequence
    string header;
    string sequence;
    string line;

    // Vector to store the bit array
    vector<bool> bitArray;

    
    while (getline(fastaFile, line)) {
        // Check if the line is empty or a comment line
        if (line.empty() || line[0] == '>') {
            // If it's a header line
            if (!header.empty()) {
                // Process the previous sequence (if any)
                cout << "Header: " << header << endl;

                // Process the bit array based on the presence of 'A' in the sequence
                for (size_t i = 0; i < sequence.size(); ++i) {
                    bitArray.push_back(sequence[i] == 'A');
                }


               
                header.clear();
                sequence.clear();
            }

            
            if (line[0] == '>') {
                header = line.substr(1); 
            }
        } else {
            
            sequence += line;
        }
    }

    
    if (!header.empty()) {
        cout << "Header: " << header << endl;

        
        for (size_t i = 0; i < sequence.size(); ++i) {
            bitArray.push_back(sequence[i] == 'A');
        }

        cout << endl;
    }

    
    fastaFile.close();

    
    int num = 14343555;
    int ans = 0;
    for (size_t i = 0; i < bitArray.size(); i++) {
        if (i == num) break;
        if (bitArray[i]) {
            ans++;
        }
    }
    cout << "ans: " << ans << endl;
    
    
    
    auto end = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

   cout << "Time taken to execute: " << 1000*duration.count() << " nanoseconds\n";
    return 0;

   
}

