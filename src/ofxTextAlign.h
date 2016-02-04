#pragma once

#include "ofConstants.h"

namespace ofx { namespace textalign {

class TextAlign {
public:
	enum {
		HORIZONTAL_ALIGN_LEFT	= 0x00000000,
		HORIZONTAL_ALIGN_CENTER	= 0x00000001,
		HORIZONTAL_ALIGN_RIGHT	= 0x00000002,
		HORIZONTAL_ALIGN_MASK	= 0x00000003,
		
		VERTICAL_ALIGN_TOP		= 0x00000000,
		VERTICAL_ALIGN_MIDDLE	= 0x00000004,
		VERTICAL_ALIGN_BOTTOM	= 0x00000008,
		VERTICAL_ALIGN_MASK		= 0x0000000C,
		
		FLAG_DEFAULT = HORIZONTAL_ALIGN_LEFT | VERTICAL_ALIGN_BOTTOM,
	};
public:
	void draw(string str, float x, float y, unsigned int flags=FLAG_DEFAULT);
	void setMaxWidth(float width) { max_width_=width; }
	void setMinWidth(float width) { min_width_=width; }
	void setMaxHeight(float height) { max_height_=height; }
	void setMinHeight(float height) { min_height_=height; }
protected:
	virtual const char* drawChar(const char *str, float x, float y)=0;
	virtual float getCharWidth(char ch) const=0;
	virtual float getLineHeight() const=0;
	virtual float getAscenderHeight() const { return 0; }
	virtual float getKerning(char ch, char prev) const { return 0; };
protected:
	float max_width_=0, min_width_=0;
	float max_height_=0, min_height_=0;
private:
	float getOffsetX(const char *str, unsigned int flags, bool single_line);
	float getWidth(const char *str, bool single_line);
	float getDrawWidth(const char *str, bool single_line);
	int getLetterCount(const char *str, bool single_line);
	
	float getOffsetY(const char *str, unsigned int flags, bool single_line);
	float getHeight(const char *str, bool single_line);
	float getDrawHeight(const char *str, bool single_line);
	int getLineCount(const char *str);
	
	const char* drawLine(const char *str, float x, float y);
};
}}

using ofxTextAlign = ofx::textalign::TextAlign;
/* EOF */