#include "StringUtil.h"
#include "CharUtil.h"

namespace StringUtil
{
	std::string head(const std::string& word)
	{
		return word.substr(0, 1);
	}

	std::string tail(const std::string& word)
	{
		return word.substr(1);
	}
	std::string zeroPad(const std::string& text, size_t toLength)
	{
		auto zerosNeeded = toLength - text.length();
		return text + std::string(zerosNeeded, '0');
	}


	std::string upperFront(const std::string& string)
	{
		return std::string(1, CharUtil::upper(string.front()));
	}
}
