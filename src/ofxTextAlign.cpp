#include "ofxTextAlign.h"

#include "ofConstants.h"

ofxTextAlign::ofxTextAlign()
{
	max_width_ = min_width_ = 0;
	max_height_ = min_height_ = 0;
	letter_spacing_ = 0;
	line_height_ = 0;
	enable_half_width_ = true;
}

void ofxTextAlign::draw(string str, float x, float y, unsigned int flags)
{
	const char *ptr = str.c_str();
	float cursor_y = y+getOffsetY(ptr, flags, false);
	float line_height = getLineHeight(ptr);
	while(*ptr != '\0') {
		float cursor_x = x+getOffsetX(ptr, flags, true);
		ptr = drawLine(ptr, cursor_x, cursor_y);
		cursor_y += line_height;
	}
}

const char* ofxTextAlign::drawLine(const char *str, float x, float y)
{
	const char *ptr = str;
	float spacing = getLetterSpacing(ptr);
	while(*ptr != '\0') {
		if(*ptr=='\n') {
			++ptr;
			break;
		}
		float interval = ((enable_half_width_&&isHalfChar(ptr))?char_width_/2.f:char_width_) + spacing;
		ptr = drawChar(ptr, x, y);
		x += interval;
	}
	return ptr;
}

//const char* ofxTextAlign::drawChar(const char *str, float x, float y)
//{
//	int index = getIndex(str);
//	
//	float tex_w = texture_.getWidth()/(float)div_u_;
//	float tex_h = texture_.getHeight()/(float)div_v_;
//	float tex_s = index%div_u_*tex_w;
//	float tex_t = index/div_u_*tex_h;
//	texture_.drawSubsection(x, y, char_width_, char_height_, tex_s, tex_t, tex_w, tex_h);
//	return str+1;
//}
//
float ofxTextAlign::getOffsetX(const char *str, unsigned int flags, bool single_line)
{
	unsigned int flag = flags&HORIZONTAL_ALIGN_MASK;
	if(HORIZONTAL_ALIGN_LEFT == flag) {
		return 0;
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
float ofxTextAlign::getLetterSpacing(const char *str)
{
	int letter_count = getLetterCount(str, true);
	if(letter_count > 1) {
		return (getDrawWidth(str, true)-getWidthWithoutSpacing(str, true))/(float)(letter_count-1);
	}
	else {
		return letter_spacing_;
	}
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
	bool new_line = true;
	const char *ptr = str;
	while(*ptr != '\0' && !(single_line && *ptr == '\n')) {
		switch(*ptr) {
		case '\n':
			ret = max(ret, tmp);
			tmp = 0;
			new_line = true;
			break;
		default:
			if(!new_line) {
				tmp += letter_spacing_;
			}
			tmp += (enable_half_width_&&isHalfChar(ptr))?char_width_/2.f:char_width_;
			new_line = false;
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
float ofxTextAlign::getWidthWithoutSpacing(const char *str, bool single_line)
{
	float ret = 0;
	float tmp = 0;
	const char *ptr = str;
	while(*ptr != '\0' && !(single_line && *ptr == '\n')) {
		switch(*ptr) {
		case '\n':
			ret = max(ret, tmp);
			tmp = 0;
			break;
		default:
			tmp += (enable_half_width_&&isHalfChar(ptr))?char_width_/2.f:char_width_;
			break;
		}
		++ptr;
	}
	return max(ret, tmp);
}

float ofxTextAlign::getOffsetY(const char *str, unsigned int flags, bool single_line)
{
	unsigned int flag = flags&VERTICAL_ALIGN_MASK;
	if(VERTICAL_ALIGN_TOP == flag) {
		return 0;
	}
	else {
		float height = getDrawHeight(str, single_line);
		switch(flag) {
			case VERTICAL_ALIGN_MIDDLE:	return -height/2.f;
			case VERTICAL_ALIGN_BOTTOM:	return -height;
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
	if(single_line) {
		return char_height_;
	}
	float ret = char_height_;
	while(*ptr != '\0') {
		if(*ptr == '\n' && *(ptr+1) != '\0') {
			ret += line_height_;
		}
		++ptr;
	}
	return ret;
}
float ofxTextAlign::getHeightWithoutSpacing(const char *str, bool single_line)
{
	const char *ptr = str;
	if(*ptr=='\0') {
		return 0;
	}
	if(single_line) {
		return char_height_;
	}
	float ret = char_height_;
	while(*ptr != '\0') {
		if(*ptr == '\n' && *(ptr+1) != '\0') {
			ret += char_height_;
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

float ofxTextAlign::getLineHeight(const char *str)
{
	int line_count = getLineCount(str);
	if(line_count > 1) {
		return char_height_+(getDrawHeight(str, false)-getHeightWithoutSpacing(str, false))/(float)(line_count-1);
	}
	else {
		return line_height_;
	}
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

//bool ofxTextAlign::isHalfChar(const char *str)
//{
//	switch(*str) {
//	case '.':
//	case ' ':
//		return true;
//	}
//	return false;
//}

/* EOF */