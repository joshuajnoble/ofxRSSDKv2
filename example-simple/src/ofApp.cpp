#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 480);
	mRSSDK = RSDevice::createUniquePtr();
	
	if(!mRSSDK->init())
	{
		ofLogError("Unable to create ofxRSSDK object");
		exit();
	}
	else
	{
		mRSSDK->initDepth(DepthRes::F200_VGA, 30, true);
		mRSSDK->initRgb(RGBRes::HD720, 30);

		mTexRgb.allocate(mRSSDK->getRgbWidth(), mRSSDK->getRgbHeight(),GL_RGBA);
		mTexDepth.allocate(mRSSDK->getDepthWidth(), mRSSDK->getDepthHeight(), GL_RGBA);

		mRSSDK->enableHandTracking();

		mRSSDK->start();

	}

	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update()
{
	mRSSDK->update();

	/*PXCHandData::FingerData lindex, lmiddle;
	if (mRSSDK->getHandData().getRawLeftHand() != NULL)
	{
		mRSSDK->getHandData().getRawLeftHand()->QueryFingerData(PXCHandData::FINGER_INDEX, lindex);
		mRSSDK->getHandData().getRawLeftHand()->QueryFingerData(PXCHandData::FINGER_MIDDLE, lmiddle);

		cout << " left " << lindex.foldedness << " " << lmiddle.foldedness << " " << endl;
	}

	PXCHandData::FingerData rindex, rmiddle;
	if (mRSSDK->getHandData().getRawRightHand() != NULL)
	{
		mRSSDK->getHandData().getRawLeftHand()->QueryFingerData(PXCHandData::FINGER_INDEX, rindex);
		mRSSDK->getHandData().getRawLeftHand()->QueryFingerData(PXCHandData::FINGER_MIDDLE, rmiddle);

		cout << " right " << rindex.foldedness << " " << rmiddle.foldedness << " " << endl;
	}*/

	mTexRgb.loadData(mRSSDK->getRgbFrame(), GL_BGRA);
	mTexDepth.loadData(mRSSDK->getDepth8uFrame());
}

//--------------------------------------------------------------
void ofApp::draw()
{
	//ofClear(ofColor::black);
	ofBackground(0, 0, 0);
	mTexRgb.draw(0, 0);
	ofDrawBitmapString("Raw Color", ofPoint(10, 20));
	ofPushMatrix();
	ofTranslate(640, 0);
	mTexDepth.draw(0,0,640,480);
	ofDrawBitmapString("Depth Pixels", ofPoint(10, 20));
	ofPopMatrix();
}


void ofApp::exit()
{
	mRSSDK->stop();
}
