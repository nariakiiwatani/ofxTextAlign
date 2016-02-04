#include "ofxTextAlignTTF.h"

const char* ofxTextAlignTTF::drawChar(const char *str, float x, float y)
{
	string ch;
	ch.assign(str, 1);
	drawString(ch, x, y);
	return str+1;
}

float ofxTextAlignTTF::getCharWidth(char ch) const
{
	return cps[ch-NUM_CHARACTER_TO_START].advance;
}
float ofxTextAlignTTF::getKerning(char ch, char prev) const
{
	return ofTrueTypeFont::getKerning(ch, prev);
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