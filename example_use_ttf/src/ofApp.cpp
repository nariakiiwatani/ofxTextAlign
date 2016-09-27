#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	text_.load(OF_TTF_SANS, 30);
	
	x_.setup("x", 0, 0, ofGetWidth());
	y_.setup("y", 0, 0, ofGetHeight());
	halign_.setup("h_align", 0, 0, 2);
	halign_.addListener(this, &ofApp::refreshAlignStr);
	valign_.addListener(this, &ofApp::refreshAlignStr);
	valign_.setup("v_align", 0, 0, 2);
	align_str_.setup("align", "left-top");
	min_width_.setup("min width", 0, 0, ofGetWidth());
	min_width_.addListener(this, &ofApp::callbackMinWidth);
	max_width_.setup("max width", 0, 0, ofGetWidth());
	max_width_.addListener(this, &ofApp::callbackMaxWidth);
	min_height_.setup("min height", 0, 0, ofGetHeight());
	min_height_.addListener(this, &ofApp::callbackMinHeight);
	max_height_.setup("max height", 0, 0, ofGetHeight());
	max_height_.addListener(this, &ofApp::callbackMaxHeight);
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

void ofApp::refreshAlignStr(int&)
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

void ofApp::callbackMinWidth(int &val)
{
	text_.setMinWidth(val);
}

void ofApp::callbackMaxWidth(int &val)
{
	text_.setMaxWidth(val);
}

void ofApp::callbackMinHeight(int &val)
{
	text_.setMinHeight(val);
}

void ofApp::callbackMaxHeight(int &val)
{
	text_.setMaxHeight(val);
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushStyle();
	ofSetColor(ofColor::yellow);
	ofDrawLine(0, y_, ofGetWidth(), y_);
	ofDrawLine(x_, 0, x_, ofGetHeight());
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
	text_.draw("The quick\nbrown fox\njumps over\nthe lazy dog", x_, y_, flags);
	panel_.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	
}
