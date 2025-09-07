# 実行ファイル名
TARGET = typing_game

# ソースファイル
SRC = src/main.cpp

DIST   = dist/typing_game_win64

# ビルドルール
VER ?= $(shell git describe --tags --always --dirty --abbrev=7 2>/dev/null)
ZIP  = dist/typing_game_win64_$(VER).zip

.PHONY: all release release-zip clean

all:
	g++ $(SRC) -o $(TARGET) -Wall -O2 

release: all
	rm -rf $(DIST)
	mkdir -p $(DIST)
	cp $(TARGET) $(DIST)/
	cp "$(shell which libstdc++-6.dll)" $(DIST)/
	cp "$(shell which libgcc_s_seh-1.dll)" $(DIST)/
	cp "$(shell which libwinpthread-1.dll)" $(DIST)/
	cp README_DIST.txt $(DIST)/README.txt
	@echo "Packed -> $(DIST)"

release-zip: release
	powershell -NoProfile -Command "Compress-Archive -Path '$(DIST)\*' -DestinationPath '$(ZIP)' -Force"
	@echo "ZIP -> $(ZIP)"

# クリーン（削除）ルール
clean:
	rm -f $(TARGET) $(TARGET).exe
