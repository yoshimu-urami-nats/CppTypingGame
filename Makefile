# 実行ファイル名
TARGET = typing_game

# ソースファイル
SRC = src/main.cpp

# ビルドルール
all:
	g++ $(SRC) -o $(TARGET) -Wall -O2 

# クリーン（削除）ルール
clean:
	rm -f $(TARGET)
