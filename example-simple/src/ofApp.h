#ifndef __OFAPP_H__
#define __OFAPP_H__

#include "ofxRSSDKv2.h"
<<<<<<< HEAD
#include "ofxMosquitto.h"
=======
>>>>>>> 3542ac5556c79d3ba3a7806714031b61a2406d61

using namespace ofxRSSDK;

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void depthToColor();
	void exit();

<<<<<<< HEAD
	ofxMosquitto mosquitto;
	void onMosquittoConnect(int &rc);
	void onMosquittoMessageReceived(ofxMosquittoMessage &msg);
	string messageStr;

=======
>>>>>>> 3542ac5556c79d3ba3a7806714031b61a2406d61
private:
	RSDevicePtr mRSSDK;
	ofTexture	mTexRgb,
				mTexDepth;
};
#endif