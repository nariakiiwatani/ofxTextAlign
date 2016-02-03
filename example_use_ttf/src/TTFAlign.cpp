#include "TTFAlign.h"

void TTFAlign::load(string name, int font_size)
{
	font_.load(name, font_size);
	setCharSize(font_size, font_size);
	setLetterSpacing(font_.getLetterSpacing());
	setLineHeight(font_.getLineHeight());
}

const char* TTFAlign::drawChar(const char *str, float x, float y)
{
	string ch;
	ch.assign(str, 1);
	font_.drawString(ch, x, y);
	return str+1;
}

bool TTFAlign::isHalfChar(const char *str)
{
	switch(*str) {
		case ' ':
		case '.':
		case ',':
			return true;
	}
	return false;
}

/* EOF */