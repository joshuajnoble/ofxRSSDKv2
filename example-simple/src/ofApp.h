#ifndef __OFAPP_H__
#define __OFAPP_H__

#include "ofxRSSDKv2.h"
#include "ofxMosquitto.h"

using namespace ofxRSSDK;

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void depthToColor();
	void exit();

	ofxMosquitto mosquitto;
	void onMosquittoConnect(int &rc);
	void onMosquittoMessageReceived(ofxMosquittoMessage &msg);
	string messageStr;

private:
	RSDevicePtr mRSSDK;
	ofTexture	mTexRgb,
				mTexDepth;
};
#endif