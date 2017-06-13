#include "CharUtil.h"

#include <string>
#include <cctype>

using namespace std;

namespace CharUtil
{
	bool isVowel(char letter)
	{
		return string("aeiouy").find(lower(letter)) != string::npos;
	}

	char upper(char c)
	{
		return toupper(static_cast<unsigned char>(c));
	}

	char lower(char c)
	{
		return tolower(static_cast<unsigned char>(c));
	}
}
