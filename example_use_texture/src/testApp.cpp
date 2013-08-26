#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	text_.loadTexture("number.png", 30, 45);
	
	x_.setup("x", 0, 0, ofGetWidth());
	y_.setup("y", 0, 0, ofGetHeight());
	halign_.setup("h_align", 0, 0, 2);
	halign_.addListener(this, &testApp::refreshAlignStr);
	valign_.addListener(this, &testApp::refreshAlignStr);
	valign_.setup("v_align", 0, 0, 2);
	align_str_.setup("align", "left-top");
	min_width_.setup("min width", 0, 0, ofGetWidth());
	min_width_.addListener(this, &testApp::callbackMinWidth);
	max_width_.setup("max width", 0, 0, ofGetWidth());
	max_width_.addListener(this, &testApp::callbackMaxWidth);
	min_height_.setup("min height", 0, 0, ofGetHeight());
	min_height_.addListener(this, &testApp::callbackMinHeight);
	max_height_.setup("max height", 0, 0, ofGetHeight());
	max_height_.addListener(this, &testApp::callbackMaxHeight);
	letter_spacing_.setup("letter spacing", 0, 0, 100);
	letter_spacing_.addListener(this, &testApp::callbackLetterSpacing);
	line_height_.setup("line height", 0, 0, 100);
	line_height_.addListener(this, &testApp::callbackLineHeight);
	panel_.setup();
	panel_.add(&x_);
	panel_.add(&y_);
	panel_.add(&halign_);
	panel_.add(&valign_);
	panel_.add(&align_str_);
	panel_.add(&min_width_);
	panel_.add(&max_width_);
	panel_.add(&min_height_);
	panel_.add(&max_height_);
	panel_.add(&letter_spacing_);
	panel_.add(&line_height_);
}

void testApp::refreshAlignStr(int&)
{
	string str = "-";
	switch(halign_) {
		case 0:	str.insert(0, "left");		break;
		case 1:	str.insert(0, "center");	break;
		case 2:	str.insert(0, "right");		break;
	}
	switch(valign_) {
		case 0:	str.append("top");		break;
		case 1:	str.append("middle");	break;
		case 2:	str.append("bottom");	break;
	}
	align_str_ = str;
}

void testApp::callbackMinWidth(int &val)
{
	text_.setMinWidth(val);
}

void testApp::callbackMaxWidth(int &val)
{
	text_.setMaxWidth(val);
}

void testApp::callbackMinHeight(int &val)
{
	text_.setMinHeight(val);
}

void testApp::callbackMaxHeight(int &val)
{
	text_.setMaxHeight(val);
}

void testApp::callbackLetterSpacing(int &val)
{
	text_.setLetterSpacing(val);
}

void testApp::callbackLineHeight(int &val)
{
	text_.setLineHeight(val);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofPushStyle();
	ofSetColor(ofColor::yellow);
	ofLine(0, y_, ofGetWidth(), y_);
	ofLine(x_, 0, x_, ofGetHeight());
	ofPopStyle();
	unsigned int flags = 0;
	switch(halign_) {
		case 0:	flags |= ofxTextAlign::HORIZONTAL_ALIGN_LEFT;		break;
		case 1:	flags |= ofxTextAlign::HORIZONTAL_ALIGN_CENTER;		break;
		case 2:	flags |= ofxTextAlign::HORIZONTAL_ALIGN_RIGHT;		break;
	}
	switch(valign_) {
		case 0:	flags |= ofxTextAlign::VERTICAL_ALIGN_TOP;		break;
		case 1:	flags |= ofxTextAlign::VERTICAL_ALIGN_MIDDLE;	break;
		case 2:	flags |= ofxTextAlign::VERTICAL_ALIGN_BOTTOM;	break;
	}
	text_.draw("0123456789\n012345678\n01234567\n0123456\n012345\n01234\n0123\n012\n01\n0", x_, y_, flags);
	panel_.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
