#include <windows.h>
#include <iostream>
#include <locale>
#include <vector>
#include <random>
#include <ctime>

int main() {
    // Windows UTF-8対応（文字化け対策）
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);

    // 単語リスト
    std::vector<std::string> wordList = {
        "ぷーちく", "チュッチュカ", "apple", "banana", "Unreal", "GitHub", "タイピング", "メンゴ", "C++"
    };

    // 乱数初期化
    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(0, wordList.size() - 1);

    int correctCount = 0;
    const int maxQuestions = 5;

    std::cout << "ようこそ タイピングゲームへ！\n";

    for (int i = 0; i < maxQuestions; ++i) {
        std::string targetWord = wordList[dist(rng)];
        std::cout << "\nお題 " << (i + 1) << "： " << targetWord << std::endl;

        std::string userInput;
        std::cout << "入力：";
        std::cin >> userInput;

        if (userInput == targetWord) {
            std::cout << "正解！\n";
            ++correctCount;
        } else {
            std::cout << "不正解!（あなたの入力：" << userInput << "）\n";
        }
    }

    std::cout << "\nゲーム終了! 正解数：" << correctCount << " / " << maxQuestions << std::endl;

    return 0;
}
