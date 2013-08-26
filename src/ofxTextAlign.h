#pragma once

#include "ofConstants.h"

class ofxTextAlign
{
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
	ofxTextAlign();
	void draw(string str, float x, float y, unsigned int flags=FLAG_DEFAULT);
	void setMaxWidth(float width) { max_width_=width; }
	void setMinWidth(float width) { min_width_=width; }
	void setMaxHeight(float height) { max_height_=height; }
	void setMinHeight(float height) { min_height_=height; }
	void setCharSize(float width, float height) { char_width_=width; char_height_=height; }
	void setLetterSpacing(float space) { letter_spacing_=space; }
	void setLineHeight(float height) { line_height_=height; }
protected:
	virtual const char* drawChar(const char *str, float x, float y)=0;
	virtual bool isHalfChar(const char *str) { return false; }
protected:
	bool enable_half_width_;
	float max_width_, min_width_;
	float max_height_, min_height_;
	float char_width_;
	float char_height_;
	float letter_spacing_;
	float line_height_;
private:
	float getOffsetX(const char *str, unsigned int flags, bool single_line);
	float getLetterSpacing(const char *str);
	float getWidth(const char *str, bool single_line);
	float getWidthWithoutSpacing(const char *str, bool single_line);
	float getDrawWidth(const char *str, bool single_line);
	int getLetterCount(const char *str, bool single_line);

	float getOffsetY(const char *str, unsigned int flags, bool single_line);
	float getHeight(const char *str, bool single_line);
	float getHeightWithoutSpacing(const char *str, bool single_line);
	float getDrawHeight(const char *str, bool single_line);
	float getLineHeight(const char *str);
	int getLineCount(const char *str);

	const char* drawLine(const char *str, float x, float y);
};

/* EOF */