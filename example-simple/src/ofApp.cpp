#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(1280, 480);
<<<<<<< HEAD
	mRSSDK = RSDevice::createUniquePtr();
=======
	mRSSDK = RSDevice::createUniquePtr();	
>>>>>>> 3542ac5556c79d3ba3a7806714031b61a2406d61
	
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

		mTexRgb.allocate(mRSSDK->getRgbWidth(), mRSSDK->getRgbHeight(),GL_RGBA);
		mTexDepth.allocate(mRSSDK->getDepthWidth(), mRSSDK->getDepthHeight(), GL_RGBA);

		mRSSDK->enableHandTracking();

		mRSSDK->start();

	}

	ofEnableAlphaBlending();
=======
		mRSSDK->initDepth(DepthRes::R200_SD, 30, true);
		mRSSDK->initRgb(RGBRes::VGA, 30);
		mTexRgb.allocate(mRSSDK->getRgbWidth(), mRSSDK->getRgbHeight(),GL_RGBA);
		mTexDepth.allocate(mRSSDK->getDepthWidth(), mRSSDK->getDepthHeight(), GL_RGBA);
		mRSSDK->start();
	}
>>>>>>> 3542ac5556c79d3ba3a7806714031b61a2406d61
}

//--------------------------------------------------------------
void ofApp::update()
{
	mRSSDK->update();
<<<<<<< HEAD

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

=======
>>>>>>> 3542ac5556c79d3ba3a7806714031b61a2406d61
	mTexRgb.loadData(mRSSDK->getRgbFrame(), GL_BGRA);
	mTexDepth.loadData(mRSSDK->getDepth8uFrame());
}

//--------------------------------------------------------------
void ofApp::draw()
{
<<<<<<< HEAD
	//ofClear(ofColor::black);
	ofBackground(0, 0, 0);
=======
	ofClear(ofColor::black);
>>>>>>> 3542ac5556c79d3ba3a7806714031b61a2406d61
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
