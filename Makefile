# 実行ファイル名
TARGET = typing_game

# ソースファイル（複数対応）
SRC = src/main.cpp src/game.cpp

# 出力先ディレクトリ
DIST   = dist/typing_game_win64

# gitのタグ or コミットハッシュをZIP名に使用
VER ?= $(shell git describe --tags --always --dirty --abbrev=7 2>/dev/null)
ZIP  = dist/typing_game_win64_$(VER).zip

# phonyルール
.PHONY: all release release-zip clean

# 通常ビルド（最適化付き）
all:
	g++ $(SRC) -o $(TARGET) -Wall -O2

# release: exeとDLL、READMEをまとめる
release: all
	rm -rf $(DIST)
	mkdir -p $(DIST)
	cp $(TARGET) $(DIST)/
	cp "$(shell which libstdc++-6.dll)" $(DIST)/
	cp "$(shell which libgcc_s_seh-1.dll)" $(DIST)/
	cp "$(shell which libwinpthread-1.dll)" $(DIST)/
	cp README_DIST.txt $(DIST)/README.txt
	@echo "Packed -> $(DIST)"

# release-zip: zip圧縮して配布用にまとめる
release-zip: release
	powershell -NoProfile -Command "Compress-Archive -Path '$(DIST)\\*' -DestinationPath '$(ZIP)' -Force"
	@echo "ZIP -> $(ZIP)"

# 実行ファイルの削除
clean:
	rm -f $(TARGET) $(TARGET).exe
