#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <locale>
#include "game.h"

void setupEncoding() {
    setlocale(LC_ALL, "");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}

std::vector<Word> createWordList() {
    return {
        {"ぷーちく", "pu-tiku"},
        {"チュッチュカ", "tyuttyuka"},
        {"メンゴ", "mengo"},
        {"タイピング", "taipingu"},
        {"おにぎり", "onigiri"},
        {"りんご", "ringo"}
    };
}

int generateFakeVisitorCount() {
    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    return 10000 + (rng() % 90000);
}

void printWelcomeMessage(int visitorCount) {
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    std::cout << "　 あなたは " << visitorCount << "人目のお客様です！\n";
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    std::cout << "ようこそ タイピングゲームへ！\n";
}

void runGame(const std::vector<Word>& wordList) {
    std::cin.sync();
    std::cin.ignore();

    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    std::vector<Word> shuffled = wordList;
    std::shuffle(shuffled.begin(), shuffled.end(), rng);

    int correctCount = 0;
    const int maxQuestions = 5;

    for (int i = 0; i < maxQuestions; ++i) {
        const Word& target = shuffled[i];
        std::cout << "\nお題 " << (i + 1) << "： " << target.display << std::endl;

        std::string userInput;
        std::cout << "入力：";
        std::getline(std::cin, userInput);

        if (userInput == target.answer) {
            std::cout << "正解！\n";
            ++correctCount;
        } else {
            std::cout << "不正解！（あなたの入力：" << userInput
                      << " / 正解：" << target.answer << "）\n";
        }
    }

    showResult(correctCount, maxQuestions);
}

void showResult(int correctCount, int maxQuestions) {
    std::cout << "\nゲーム終了! 正解数：" << correctCount << " / " << maxQuestions << std::endl;
    std::cout << "\nEnterで終了...";
    std::string dummy;
    std::getline(std::cin, dummy);
}
