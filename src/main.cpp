#include <windows.h>  // コンソールのコードページ変更(API)
#include <iostream>   // 入出力
#include <locale>     // setlocale
#include <vector>     // 単語リスト
#include <random>     // 乱数
#include <ctime>      // 時刻シード
#include <string>     // 文字列
#include <algorithm>  // shuffle

//日本語を見せつつ、入力はローマ字で判定するために Word 構造体で表示と答えを分離
struct Word {
    std::string display; // 画面に見せる日本語
    std::string answer;  // プレイヤーに打ってほしいローマ字
};

int main() {
    //これで Windows のコンソールが UTF-8 で入出力する
    //以前の不正文字化けの主因をここで解消
    setlocale(LC_ALL, "");
    SetConsoleCP(CP_UTF8);        // 入力もUTF-8
    SetConsoleOutputCP(CP_UTF8);  // 出力をUTF-8

    // 出題リスト（日本語表示＋ローマ字判定）
    //ここを増やせば題材が増える。表示は日本語、判定はローマ字。
    std::vector<Word> wordList = {
        {"ぷーちく", "pu-tiku"},
        {"チュッチュカ", "tyuttyuka"},
        {"メンゴ", "mengo"},
        {"タイピング", "taipingu"},
        {"おにぎり", "onigiri"},
        {"りんご", "ringo"}
    };

    // 乱数の準備とシャッフル
    //mt19937 は高品質な擬似乱数エンジン。時刻で初期化。
    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(0, wordList.size() - 1);

    int correctCount = 0;
    const int maxQuestions = 5;

    std::cout << "ようこそ タイピングゲームへ！\n";

    std::cin.sync();   // 入力バッファの同期
    std::cin.ignore(); // 直前に残ってる1文字(改行)を捨てる

    // 出題前にリストを並べ替え。重複なしでランダム順にするため、以降は wordList[i] を順に出すだけでOK
    std::shuffle(wordList.begin(), wordList.end(), rng);

    //出題ループ
    //wordList[i] はシャッフル済みなので重複なし
    //getline を使うことでスペースや全角を含む入力にも対応（今回はローマ字なので主に安全策）
    for (int i = 0; i < maxQuestions; ++i) {
        const Word& target = wordList[i];
        std::cout << "\nお題 " << (i + 1) << "： " << target.display << std::endl;

        std::string userInput;
        std::cout << "入力：";        
        std::getline(std::cin, userInput); // ←日本語対応

        if (userInput == target.answer) {
            std::cout << "正解！\n";
            ++correctCount;
        } else {
            std::cout << "不正解！（あなたの入力：" << userInput
                      << " / 正解：" << target.answer << "）\n";
        }
    }

    //リザルト表示
    std::cout << "\nゲーム終了! 正解数：" << correctCount << " / " << maxQuestions << std::endl;

    return 0;
}
