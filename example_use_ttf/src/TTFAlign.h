#pragma once

#include "ofxTextAlign.h"
#include "ofTrueTypeFont.h"

class TTFAlign : public ofxTextAlign
{
public:
	void loadFont(string name, int font_size);
private:
	const char* drawChar(const char *str, float x, float y);
	bool isHalfChar(const char *str);
private:
	ofTrueTypeFont font_;
};

/* EOF */