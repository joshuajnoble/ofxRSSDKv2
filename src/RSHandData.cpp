#include "RSHandData.h"

namespace ofxRSSDK
{

	RSHandData::RSHandData()
	{
		rightHandData = 0;
		leftHandData = 0;
	}

	void RSHandData::update(PXCHandData *handAnalyzer)
	{

	}

	void RSHandData::setNodes(PXCHandData *handTracker)
	{

		int numHands = handTracker->QueryNumberOfHands();

		cout << " have " << numHands << " hands " << endl;

		for (pxcI32 i = 0; i < numHands; i++)
		{
			PXCHandData::IHand* handData;
			//Get hand by time of appearence
			if (handTracker->QueryHandData(PXCHandData::AccessOrderType::ACCESS_ORDER_BY_ID, i, handData) == PXC_STATUS_NO_ERROR)
			{

				pxcF32 r1 = handData->QueryPalmRadiusImage();
				pxcF32 r2 = handData->QueryPalmRadiusWorld();
				pxcI32 c = handData->QueryTrackingStatus();

				cout <<  " radisu " << r1 << " radius 2 " << r2 << " status " << c << " body side " << handData->QueryBodySide() << " " << endl;

				if (handData->QueryBodySide() == PXCHandData::BodySideType::BODY_SIDE_RIGHT) {
					rightHandData = handData;
				}
				else {
					leftHandData = handData;
				}

				PXCHandData::FingerData index, middle;
				std::string hand = "";

				if (handData->QueryBodySide() == PXCHandData::BodySideType::BODY_SIDE_RIGHT) {
					hand = "right";
				}
				else {
					hand = "left";
				}


				handData->QueryFingerData(PXCHandData::FINGER_INDEX, index);
				handData->QueryFingerData(PXCHandData::FINGER_MIDDLE, middle);

				std::cout << hand << " " << index.foldedness << " " << middle.foldedness << " " << std::endl;

				PXCHandData::JointData jointData;
				//Iterate Joints
				for (int j = 0; j < PXCHandData::NUMBER_OF_JOINTS; j++)
				{

					if (mNormalizedSkeleton == false)
					{
						handData->QueryTrackedJoint((PXCHandData::JointType)j, jointData);
					}
					else
					{
						handData->QueryNormalizedJoint((PXCHandData::JointType)j, jointData);
					}

					nodes[i][j] = jointData;

				}
				if (mExtremities == true){
					for (int j = 0; j < PXCHandData::NUMBER_OF_EXTREMITIES; j++)
					{
						handData->QueryExtremityPoint((PXCHandData::ExtremityType)j, extremityNodes[i][j]);
					}
				}
			}
		}
	}

	void RSHandData::draw() {
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < PXCHandData::NUMBER_OF_JOINTS; ++j)
			{
				if (nodes[i][j].confidence == 0) continue;

				int sz = 1; //joint circle size

				int x = (int)nodes[i][j].positionImage.x;
				int y = (int)nodes[i][j].positionImage.y;

				//Wrist
				if (j == 0)
				{
					//SelectObject(dc2, black);
				}
				//Center
				if (j == 1)
				{
					//SelectObject(dc2, red);
					sz += 4;
				}
				//Thumb
				if (j == 2 || j == 3 || j == 4 || j == 5)
				{
					//SelectObject(dc2, green);
				}
				//Index Finger
				if (j == 6 || j == 7 || j == 8 || j == 9)
				{
					//SelectObject(dc2, blue);
				}
				//Finger
				if (j == 10 || j == 11 || j == 12 || j == 13)
				{
					//SelectObject(dc2, yellow);
				}
				//Ring Finger
				if (j == 14 || j == 15 || j == 16 || j == 17)
				{
					//SelectObject(dc2, cyan);
				}
				//Pinkey
				if (j == 18 || j == 19 || j == 20 || j == 21)
				{
					//SelectObject(dc2, orange);
				}

				//if finger tip draw larger circle
				if (j == 5 || j == 9 || j == 13 || j == 17 || j == 21)
				{
					sz += 3;
				}

				//MoveToEx(dc2, x, y, 0);
				
				ofBezier(x - sz, y - sz, x + sz, y + sz, x + sz, y + sz, x + sz, y + sz);

			}//end for joints					
	}//end if jointNodes
	}
}