#include "ofxTextAlign.h"

#include "ofConstants.h"

void ofxTextAlign::draw(string str, float x, float y, unsigned int flags)
{
	const char *ptr = str.c_str();
	float cursor_y = y+getOffsetY(ptr, flags, false);
	int line_count = getLineCount(ptr);
	float y_interval = line_count>1?(getDrawHeight(ptr, false)-getLineHeight())/(float)(line_count-1):0;
	while(*ptr != '\0') {
		float cursor_x = x+getOffsetX(ptr, flags, true);
		ptr = drawLine(ptr, cursor_x, cursor_y);
		cursor_y += y_interval;
	}
}

const char* ofxTextAlign::drawLine(const char *str, float x, float y)
{
	const char *ptr = str;
	int letter_count = getLetterCount(str, true);
	float extra_spacing = letter_count>1?(getDrawWidth(str, true)-getWidth(str, true))/(float)(letter_count-1):0;
	while(*ptr != '\0') {
		if(*ptr=='\n') {
			++ptr;
			break;
		}
		float interval = getCharWidth(*ptr) + getKerning(*(ptr+1), *ptr) + extra_spacing;
		ptr = drawChar(ptr, x, y);
		x += interval;
	}
	return ptr;
}

float ofxTextAlign::getOffsetX(const char *str, unsigned int flags, bool single_line)
{
	unsigned int flag = flags&HORIZONTAL_ALIGN_MASK;
	if(HORIZONTAL_ALIGN_LEFT == flag) {
		return 0;
	}
	else if(single_line && getLetterCount(str, true) < 2) {
		float width = getCharWidth(*str);
		switch(flag) {
			case HORIZONTAL_ALIGN_CENTER:	return -width/2.f;
			case HORIZONTAL_ALIGN_RIGHT:	return -width;
		}
	}
	else {
		float width = getDrawWidth(str, single_line);
		switch(flag) {
			case HORIZONTAL_ALIGN_CENTER:	return -width/2.f;
			case HORIZONTAL_ALIGN_RIGHT:	return -width;
		}
	}
	return 0;
}

int ofxTextAlign::getLetterCount(const char *str, bool single_line)
{
	int ret = 0;
	const char *ptr = str;
	while(*ptr != '\0' && !(single_line && *ptr == '\n')) {
		if(*ptr != '\n') {
			++ret;
		}
		++ptr;
	}
	return ret;
}

float ofxTextAlign::getWidth(const char *str, bool single_line)
{
	float ret = 0;
	float tmp = 0;
	const char *ptr = str;
	char prev = -1;
	while(*ptr != '\0' && !(single_line && *ptr == '\n')) {
		switch(*ptr) {
		case '\n':
			ret = max(ret, tmp);
			tmp = 0;
			prev = -1;
			break;
		default:
			if(prev != -1) {
				tmp += getKerning(*ptr, prev);
			}
			prev = *ptr;
			tmp += getCharWidth(*ptr);
			break;
		}
		++ptr;
	}
	return max(ret, tmp);
}
float ofxTextAlign::getDrawWidth(const char *str, bool single_line)
{
	float width = getWidth(str, single_line);
	if(max_width_ != 0 && width > max_width_) {
		width = max_width_;
	}
	if(min_width_ != 0 && width < min_width_) {
		width = min_width_;
	}
	return width;
}

float ofxTextAlign::getOffsetY(const char *str, unsigned int flags, bool single_line)
{
	unsigned int flag = flags&VERTICAL_ALIGN_MASK;
	if(VERTICAL_ALIGN_TOP == flag) {
		return getAscenderHeight();
	}
	else if(!single_line && getLineCount(str) < 2) {
		float height = getLineHeight();
		switch(flag) {
			case VERTICAL_ALIGN_MIDDLE:	return getAscenderHeight()-height/2.f;
			case VERTICAL_ALIGN_BOTTOM:	return getAscenderHeight()-height;
		}
	}
	else {
		float height = getDrawHeight(str, single_line);
		switch(flag) {
			case VERTICAL_ALIGN_MIDDLE:	return getAscenderHeight()-height/2.f;
			case VERTICAL_ALIGN_BOTTOM:	return getAscenderHeight()-height;
		}
	}
	return 0;
}

float ofxTextAlign::getHeight(const char *str, bool single_line)
{
	const char *ptr = str;
	if(*ptr=='\0') {
		return 0;
	}
	float ret = getLineHeight();
	if(single_line) {
		return ret;
	}
	while(*ptr != '\0') {
		if(*ptr == '\n' && *(ptr+1) != '\0') {
			ret += getLineHeight();
		}
		++ptr;
	}
	return ret;
}
float ofxTextAlign::getDrawHeight(const char *str, bool single_line)
{
	float height = getHeight(str, single_line);
	if(max_height_ != 0 && height > max_height_) {
		height = max_height_;
	}
	if(min_height_ != 0 && height < min_height_) {
		height = min_height_;
	}
	return height;
}

int ofxTextAlign::getLineCount(const char *str)
{
	const char *ptr = str;
	if(*ptr=='\0') {
		return 0;
	}
	int ret = 1;
	while(*ptr != '\0') {
		if(*ptr == '\n' && *(ptr+1) != '\0') {
			++ret;
		}
		++ptr;
	}
	return ret;
}

/* EOF */