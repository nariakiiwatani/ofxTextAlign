#include "TextureAlign.h"
#include "ofImage.h"

void TextureAlign::loadTexture(string name, int char_width, int char_height)
{
	ofLoadImage(texture_, name);
	setCharSize(char_width, char_height);
	setLetterSpacing(0);
	setLineHeight(char_width*1.43f);
}

const char* TextureAlign::drawChar(const char *str, float x, float y)
{
	int index = str[0]-'0';
	float tex_w = texture_.getWidth()/10.f;
	float tex_h = texture_.getHeight();
	float tex_s = index*tex_w;
	float tex_t = 0;
	texture_.drawSubsection(x, y, char_width_, char_height_, tex_s, tex_t, tex_w, tex_h);
	return str+1;
}

/* EOF */