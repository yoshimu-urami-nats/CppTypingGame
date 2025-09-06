#include <windows.h>
#include <iostream>
#include <locale>

int main() {
    // ロケール設定
    setlocale(LC_ALL, "");

    // コンソールのコードページをUTF-8にする
    SetConsoleOutputCP(CP_UTF8);

    // UTF-8文字列出力
    std::cout << u8"ようこそ タイピングゲームへ！" << std::endl;

    return 0;
}
