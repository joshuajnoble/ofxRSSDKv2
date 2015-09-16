

#include "pxchanddata.h"
#include "pxchandmodule.h"
#include "pxcsensemanager.h"
#include <sstream>
#include <vector>
#include <array>

#include "ofGraphics.h"

namespace ofxRSSDK
{
	class RSHandData
	{
	public:
		
		RSHandData();

		void update(PXCHandData *handAnalyzer);
		void draw();

		void setNodes(PXCHandData *handTracker);

		void showExtremities(bool extremities);
		void showNormalizedSkeleton(bool normalizedSkeleton);

		// returns array of position data
		std::array<PXCHandData::JointData, PXCHandData::NUMBER_OF_JOINTS>& getLeftHand() {
			return nodes[0];
		}
		std::array<PXCHandData::JointData, PXCHandData::NUMBER_OF_JOINTS> &getRightHand() {
			return nodes[1];
		}

		// returns the raw ihand interface
		PXCHandData::IHand* getRawRightHand() {
			if (rightHandData != NULL)
			{
				return rightHandData;
			}
			return NULL;
		}

		PXCHandData::IHand* getRawLeftHand() {
			if (leftHandData != NULL)
			{
				return leftHandData;
			}
			return NULL;
		}

	private:
		//std::vector<PXCHandData::JointData> nodes[2];// [PXCHandData::NUMBER_OF_JOINTS];
		//std::vector<PXCHandData::ExtremityData> extremitiesPointsNodes[2]; // [PXCHandData::NUMBER_OF_EXTREMITIES];

		std::array<PXCHandData::JointData, PXCHandData::NUMBER_OF_JOINTS> nodes[2];
		std::array<PXCHandData::ExtremityData, PXCHandData::NUMBER_OF_EXTREMITIES> extremityNodes[2];

		PXCHandData::IHand* leftHandData;
		PXCHandData::IHand* rightHandData;

		bool mNormalizedSkeleton;
		bool mExtremities;
	};
}