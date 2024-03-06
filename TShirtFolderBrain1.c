#pragma config(Sensor, S2,     StartButton,    sensorEV3_Touch)
#pragma config(Motor,  motorA,          leftarm,       tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightarm,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          middleright,   tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          middleleft,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true) {
		// if the start button is pushed
		if (SensorValue [StartButton]) {
			// resetting all the motor encoders
			resetMotorEncoder(leftarm);
			resetMotorEncoder(rightarm);
			resetMotorEncoder(middleright);
			resetMotorEncoder(middleleft);
			// spin the arms 180 degrees to fold the sleeves
			setMotorTarget(leftarm, 180, 60);
			setMotorTarget(rightarm, 180, 60);
			sleep(500);
			setMotorSpeed(leftarm, 0);
			setMotorSpeed(rightarm, 0);
			sleep(300);
			// spin the arm motors back to their original position
			setMotorTarget(leftarm, -10, 20);
			setMotorTarget(rightarm, -10, 20);
			sleep(600);
			// spin the middle part 200 degrees to fold the t-shirt in half
			setMotorTarget(middleleft, 200, 50);
			setMotorTarget(middleright, 200, 50);
			sleep(1000);
			// set the middle back to its original spot where it's flat
			sleep(500);
			setMotorTarget(middleleft, 0, 20);
			setMotorTarget(middleright, 0, 20);
			sleep(900);
			setMotorSpeed(middleleft, 0);
			setMotorSpeed(middleright, 0);
		}
	}
}
