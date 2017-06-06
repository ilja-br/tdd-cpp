#include <iostream>
#include <gtest/gtest.h>

class Soundex {
public:
    std::string encode(const std::string& word) const {
        return "A";
    }
};

TEST(SanityCheck, FrameworkWorks) {
    ASSERT_EQ(1, 1);
}

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;

    auto encoded = soundex.encode("A");
    ASSERT_EQ(encoded, "A");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}