#ifndef StringUtil_h
#define StringUtil_h

#include <string>

namespace StringUtil {
	std::string head(const std::string& word);
	std::string tail(const std::string& word);
	std::string zeroPad(const std::string& text, size_t toLength);
	std::string upperFront(const std::string& string);
}

#endif // StringUtil_h
