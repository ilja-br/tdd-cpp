#include <gtest/gtest.h>
#include "Soundex.h"

using namespace testing;

class SoundexEncoding : public Test {
public:
    Soundex soundex;
};

TEST(SanityCheck, FrameworkWorks) {
    ASSERT_EQ(1, 1);
}

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    ASSERT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    ASSERT_EQ(soundex.encode("I"), "I000");
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
    EXPECT_EQ(soundex.encode("Ax"), "A200");
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
    EXPECT_EQ(soundex.encode("A$"), "A000");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}