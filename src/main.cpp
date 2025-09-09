#include "game.h"

int main() {
    setupEncoding();
    std::vector<Word> wordList = createWordList();
    int visitorCount = generateFakeVisitorCount();
    printWelcomeMessage(visitorCount);
    runGame(wordList);
    return 0;
}
