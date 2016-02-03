#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	text_.load(OF_TTF_MONO, 30);
	
	x_.setup("x", 0, 0, ofGetWidth());
	y_.setup("y", 0, 0, ofGetHeight());
	halign_.setup("h_align", 0, 0, 2);
	valign_.setup("v_align", 0, 0, 2);
	halign_.addListener(this, &ofApp::refreshAlignStr);
	valign_.addListener(this, &ofApp::refreshAlignStr);
	align_str_.setup("align", "left-top");
	panel_.setup();
	panel_.add(&x_);
	panel_.add(&y_);
	panel_.add(&halign_);
	panel_.add(&valign_);
	panel_.add(&align_str_);
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
	text_.draw("this is an example of\nofxTextAlign.\nit supports\nhorizontal and\nvertical align. ", x_, y_, flags);
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
