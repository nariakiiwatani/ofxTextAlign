#include "ofxTextAlignTTF.h"

const char* ofxTextAlignTTF::drawChar(const char *str, float x, float y)
{
	string ch;
	ch.assign(str, 1);
	drawString(ch, x, y);
	return str+1;
}

float ofxTextAlignTTF::getAdvance(char ch) const
{
	return cps[ch-NUM_CHARACTER_TO_START].advance;
}
float ofxTextAlignTTF::getLineHeight() const
{
	return ofTrueTypeFont::getLineHeight();
}
float ofxTextAlignTTF::getAscenderHeight() const
{
	return ofTrueTypeFont::getAscenderHeight();
}

/* EOF */
