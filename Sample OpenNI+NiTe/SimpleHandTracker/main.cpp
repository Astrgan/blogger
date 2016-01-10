/*******************************************************************************
*                                                                              *
*   PrimeSense NiTE 2.0 - Simple Tracker Sample                                *
*   Copyright (C) 2012 PrimeSense Ltd.                                         *
*                                                                              *
*******************************************************************************/

#include "nite/NiTE.h"

#include "Common/NiteSampleUtilities.h"

int main(int argc, char** argv)
{
	nite::HandTracker handTracker;
	nite::Status niteRc;

	niteRc = nite::NiTE::initialize();
	if (niteRc != nite::STATUS_OK)
	{
		printf("NiTE initialization failed\n");
		return 1;
	}

	niteRc = handTracker.create();
	if (niteRc != nite::STATUS_OK)
	{
		printf("Couldn't create user tracker\n");
		return 3;
	}

    //Виды жестов    
	//handTracker.startGestureDetection(nite::GESTURE_WAVE);
	//handTracker.startGestureDetection(nite::GESTURE_CLICK);
	handTracker.startGestureDetection(nite::GESTURE_HAND_RAISE);
	printf("\nСовершите щест...\n");

	nite::HandTrackerFrameRef handTrackerFrame;
	while (!wasKeyboardHit())
	{
		niteRc = handTracker.readFrame(&handTrackerFrame);
		if (niteRc != nite::STATUS_OK)
		{
			printf("Не удалось получить следующий кадр\n");
			continue;
		}

		const nite::Array<nite::GestureData>& gestures = handTrackerFrame.getGestures();
//                printf("%d gestures\n", gestures.getSize());
		for (int i = 0; i < gestures.getSize(); ++i) //Цикол по количеству рук для слежения
		{
			if (gestures[i].isComplete())
			{
                            printf("Жест найден: ");
                            if(gestures[i].getType() == nite::GESTURE_WAVE)
                                printf("Wave\n");
                            else if(gestures[i].getType() == nite::GESTURE_CLICK)
                                printf("Click\n");
                            else if(gestures[i].getType() == nite::GESTURE_HAND_RAISE)
                                printf("Hand raise\n");
				nite::HandId newId;
				handTracker.startHandTracking(gestures[i].getCurrentPosition(), &newId); //Слежения
			}
		}
//Для каждого движения x,y,z
		const nite::Array<nite::HandData>& hands = handTrackerFrame.getHands();
		for (int i = 0; i < hands.getSize(); ++i)
		{
			const nite::HandData& hand = hands[i];
			
			if (hand.isTracking())
			{
				printf("%d. (%5.2f, %5.2f, %5.2f)\n", hand.getId(), hand.getPosition().x, hand.getPosition().y, hand.getPosition().z);
			}
		}
	}

	nite::NiTE::shutdown();

}
