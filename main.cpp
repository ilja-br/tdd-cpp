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
    ASSERT_EQ(soundex.encode("Ax"), "A200");
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
    ASSERT_EQ(soundex.encode("A$"), "A000");
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
    ASSERT_EQ(soundex.encode("Armf"), "A651");
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
	ASSERT_EQ(soundex.encode("Dcdlb").length(), 4u);
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
	ASSERT_EQ(soundex.encode("BaAeEiIoOuUhHyYcdl"), "B234");
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
	ASSERT_EQ(soundex.encodedDigit('b'), soundex.encodedDigit('p'));
	ASSERT_EQ(soundex.encodedDigit('c'), soundex.encodedDigit('g'));
	ASSERT_EQ(soundex.encodedDigit('d'), soundex.encodedDigit('t'));

	ASSERT_EQ(soundex.encode("Abfcgdt"), "A123");
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
	ASSERT_EQ(soundex.encode("abcd"), "A123");
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants) {
	ASSERT_EQ(soundex.encode("BCDL"), soundex.encode("Bcdl"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
