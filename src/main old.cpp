#include <iostream>
#include <string>
#include <chrono>
#include <clocale>  // ←追加

int main() {
    std::setlocale(LC_ALL, "");  // ←追加！
    
    std::string target = "hello world";
    std::string input;

    std::cout << "タイピングゲーム開始！\n";
    std::cout << "次の文章を正確に入力してください：\n";
    std::cout << "👉 " << target << "\n\n";

    // 時間計測スタート
    auto start = std::chrono::steady_clock::now();

    std::getline(std::cin, input);

    // 時間計測エンド
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    if (input == target) {
        std::cout << "✅ 正解！ (" << elapsed.count() / 1000.0 << " 秒)\n";
    } else {
        std::cout << "❌ 間違いです。もう一度やってみよう！\n";
    }

    return 0;
}
