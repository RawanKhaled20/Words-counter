#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

// Function to count characters, words, and sentences
void countStats(const std::string& text, int& charCount, int& wordCount, int& sentenceCount) {
    charCount = text.length()-1;

    // Initialize word and sentence counts
    wordCount = 0;
    sentenceCount = 0;

    bool inWord = false;

    for (char c : text) {
        if (std::isalpha(c) || std::isdigit(c)) {
            inWord = true;
        } else if (inWord && (c == ' ' || c == '\n' || c == '\t' || c == '\r')) {
            wordCount++;
            inWord = false;
        } else if (c == '.' || c == '!' || c == '?') {
            sentenceCount++;
        }
    }

    // If the text ends with a word, count it
    if (inWord) {
        wordCount++;
    }
}

int main() {
    // Ask the user for the file name
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::cin >> filename;

    // Open the file
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file. Please make sure the file exists." << std::endl;
        return 1; // Exit with an error code
    }

    // Read the content of the file into a string
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Close the file
    file.close();

    // Initialize counters
    int charCount = 0, wordCount = 0, sentenceCount = 0;

    // Count characters, words, and sentences
    countStats(content, charCount, wordCount, sentenceCount);

    // Display the results
    std::cout << "Character count: " << charCount << std::endl;
    std::cout << "Word count: " << wordCount << std::endl;
    std::cout << "Sentence count: " << sentenceCount << std::endl;

    return 0;
}
