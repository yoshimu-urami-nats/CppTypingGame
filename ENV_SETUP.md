
# CppTypingGame 開発環境構築メモ

## 使用環境

- OS：Windows 10 / 11
- ターミナル：**Git Bash（MINGW64）**
- エディタ：VSCode（拡張機能：C/C++、CMake など）
- コンパイラ：`g++`（MSYS2 または MinGW-w64）

---

## プロジェクト構成（最低限）

```
CppTypingGame/
├── src/
│   └── main.cpp
├── Makefile
├── typing_game.exe（ビルド結果）
└── README.md
```

---

## main.cpp の雛形と日本語対策

```cpp
#include <windows.h>
#include <iostream>
#include <locale>

int main() {
    // ロケール設定（日本語対応）
    setlocale(LC_ALL, "");

    // コンソールの出力コードページをUTF-8に
    SetConsoleOutputCP(CP_UTF8);

    // UTF-8で出力
    std::cout << u8"ようこそ タイピングゲームへ！\n";

    return 0;
}
```

ポイント：
- `#include <windows.h>` と `SetConsoleOutputCP(CP_UTF8);` で出力の文字化け防止
- `u8` プレフィックスでUTF-8明示

---

## ビルド方法（Git Bash）

### 手動ビルド

```bash
g++ src/main.cpp -o typing_game -Wall -O2
./typing_game
```

### Makefile 使用
⚠ Windows環境では `make` ではなく `mingw32-make` を使用してください。

```bash
mingw32-make clean
mingw32-make
./typing_game
```

---

## 実行成功時

```bash
ようこそ タイピングゲームへ！
```

---

## よくあるトラブルと対策

| 症状 | 原因 | 解決策 |
|------|------|--------|
| `????` や `╬▒╣┼` のような文字化け | 出力コードページがUTF-8でない | `SetConsoleOutputCP(CP_UTF8);` を追加 |
| 入力の日本語が文字化け | ロケール未設定 | `setlocale(LC_ALL, "");` を追加 |
| `SetConsoleOutputCP` が使えない | `<windows.h>` が未インクルード | `#include <windows.h>` を入れる |

---

## VSCode 設定の例

```json
"files.encoding": "utf8",
"terminal.integrated.defaultProfile.windows": "Git Bash",
"editor.fontFamily": "'Cascadia Code', 'Meiryo', 'Consolas', monospace"
```

---
