#pragma once
#include <vector>
#include <string>

struct Word {
    std::string display;
    std::string answer;
};

void setupEncoding();
std::vector<Word> createWordList();
int generateFakeVisitorCount();
void printWelcomeMessage(int visitorCount);
void runGame(const std::vector<Word>& wordList);
void showResult(int correctCount, int maxQuestions);
