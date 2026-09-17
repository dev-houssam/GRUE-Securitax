
#include "hitechnic-angle.h"


task main()
{
//Reglage du volume
setSoundVolume(1);

//Musique
playTone(695, 14); while(bSoundActive){}
playTone(695, 14); while(bSoundActive){}
playTone(695, 14); while(bSoundActive){}
playTone(929, 83); while(bSoundActive){}

playTone(1054, 14); while(bSoundActive){}

playTone(1251, 14); while(bSoundActive){}
playTone(1188, 14); while(bSoundActive){}

playTone(1188, 14); while(bSoundActive){}
playTone(1251, 14); while(bSoundActive){}
playTone(1054, 55); while(bSoundActive){}


	while(!(getButtonPress(buttonRight)==true && getButtonPress(buttonUp)==true)){
		displayCenteredTextLine(1,"Bienvenue dans Grue securitax");
	}
	int mode = 0;

	SensorType[S2] = sensorEV3_Touch;
	SensorType[S4] = sensorEV3_Touch;

	resetMotorEncoder(motorA); //Reinitialisation de l'angle à 0. position d'origine
	eraseDisplay();
	int angle=0;
	int monter=0;
	setSoundVolume(7);

	  // Create struct to hold sensor data
  tHTANG angleSensor;

  // Initialise and configure struct and port
  initSensor(&angleSensor, S1);


	while(!(getButtonPress(buttonLeft)==1) || !(getButtonPress(buttonDown)==1)){
		//Les modes :
		displayTextLine(1, "Mode");
		displayTextLine(3, "1 - Manuel");
		displayTextLine(5, "2 - Enregistrement");
		if((getButtonPress(buttonDown)==1) && (getButtonPress(buttonUp)==1)){
			//Mode manuel
			eraseDisplay();
			displayTextLine(3,"Mode Manuel");
			mode = 1;

		}
		if((getButtonPress(buttonLeft)==1) && (getButtonPress(buttonRight)==1)){
			//Mode enregistrement
			eraseDisplay();
			displayTextLine(3,"Mode Enregistrement");
			mode = 2;
		}




		//////////////////////////////////////////////////////////////
		//                      MANOEUVRE														//
		//////////////////////////////////////////////////////////////


		while(mode == 1){
			//Mode Manuel
			displayTextLine(3, "Mode Manuel");
			//Capteur de contact pour Descendre la grue
			if(SensorValue[S2]==1){
				//SECURITÉ
				angle = getMotorEncoder(motorA);
				if((angle > -30) && (angle <= 50)){
					monter = 0; // Quand monter est à 0 on ne peut pas monter
				}else{
					monter=1;
				}
				//////////////
				displayTextLine(9, "value : %d", monter);
				displayTextLine(7, "value angle: %d", angle);

				setMotorSpeed(motorA, 15);
				//Obtention de l'angle
        playTone(450, 2);
        readSensor(&angleSensor);
    		displayTextLine(13, "Tot: %7d deg", angleSensor.accumlatedAngle);

			}//Capteur de contact pour Lever la grue
			else if(SensorValue[S4] && (monter==1)){
				//SECURITÉ
				angle = getMotorEncoder(motorA);
				if((angle > -30) && (angle <= 50)){
					monter = 0; //Quand monter est à 0 on ne peut pas monter
				}else{
					monter=1;
				}
				displayTextLine(9, "value : %d", monter);
				displayTextLine(7, "value angle: %d", angle);
				setMotorSpeed(motorA, -15);
				playTone(650, 2);
				readSensor(&angleSensor);
    		displayTextLine(13, "Tot: %7d deg", angleSensor.accumlatedAngle);
			}
			else{stopMotor(motorA);}


			if(getButtonPress(buttonLeft)==1){
			eraseDisplay();
			mode = 0;
			}
		}
		// Switch en mode enregistrement
		while(mode == 2){
			//Mode Enregistrement
			displayTextLine(3, "Mode Enregistrement");
			if(getButtonPress(buttonUp)==1){
			sleep(1000);
			eraseDisplay();
			mode = 0;
			}
		}

	}

}
