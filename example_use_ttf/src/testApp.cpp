#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	text_.loadFont("verdana.ttf", 30);
	
	x_.setup("x", 0, 0, ofGetWidth());
	y_.setup("y", 0, 0, ofGetHeight());
	halign_.setup("h_align", 0, 0, 2);
	valign_.setup("v_align", 0, 0, 2);
	halign_.addListener(this, &testApp::refreshAlignStr);
	valign_.addListener(this, &testApp::refreshAlignStr);
	align_str_.setup("align", "left-top");
	panel_.setup();
	panel_.add(&x_);
	panel_.add(&y_);
	panel_.add(&halign_);
	panel_.add(&valign_);
	panel_.add(&align_str_);
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
	text_.draw("this is an example of\nofxTextAlign.\nit supports\nhorizontal and\nvertical align. ", x_, y_, flags);
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
