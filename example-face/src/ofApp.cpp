#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(640, 480);
	mRSSDK = RSDevice::createUniquePtr();	
	
	if(!mRSSDK->init())
	{
		ofLogError("Unable to create ofxRSSDK object");
		exit();
	}
	else
	{
<<<<<<< HEAD
		mRSSDK->initDepth(DepthRes::F200_VGA, 30, true);
		mRSSDK->initRgb(RGBRes::HD720, 30);
=======
		mRSSDK->initDepth(DepthRes::R200_SD, 30, true);
		mRSSDK->initRgb(RGBRes::VGA, 30);
>>>>>>> 3542ac5556c79d3ba3a7806714031b61a2406d61
		mTexRgb.allocate(mRSSDK->getRgbWidth(), mRSSDK->getRgbHeight(),GL_RGBA);
		mRSSDK->start();
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	mRSSDK->update();
	mTexRgb.loadData(mRSSDK->getRgbFrame(), GL_BGRA);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::black);
	mTexRgb.draw(0, 0);
	ofDrawBitmapString("Raw Color", ofPoint(10, 20));
}


void ofApp::exit()
{
	mRSSDK->stop();
}
