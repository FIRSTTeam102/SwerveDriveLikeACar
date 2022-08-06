#include "subsystems/SwerveDriveLikeACar.h"

SwerveDriveLikeACar::SwerveDriveLikeACar() = default;

void SwerveDriveLikeACar::drive() {
	if (isBraking) {
		stop();
		return;
	}

	double accelerator = 0.85 * (
		SwerveDriveConstants::useSteeringWheel ?
		// (1.0 - mpDriverController->GetRawAxis(1))
		(mpDriverController->GetRawButton(5) ? 0.7 : 0.0) // temp fix for no pedals
		: mpDriverController->GetRightTriggerAxis()
	);
	if (-0.1 < accelerator && accelerator < 0.1) accelerator = 0;
	accelerator = accelerator*accelerator;

	double wheel = (SwerveDriveConstants::useSteeringWheel ? 1.2 * mpDriverController->GetRawAxis(0) : mpDriverController->GetLeftX());
	if (-0.1 < wheel && wheel < 0.1) wheel = 0;

	switch (mGear) {
		case Gear::Forward: break;
		case Gear::Reverse:
			accelerator *= -1.0;
			wheel *= -1.0;
			break;
		case Gear::Neutral: accelerator = 0; break;
		case Gear::Park: break;
	}

	// printf("Gear: %s\n", gearStrings[mGear]);

	setSpeeds(accelerator);
	setFrontAngles(65 * wheel);
}

void SwerveDriveLikeACar::setSpeeds(double speed) {
	mWheelFL.setSpeed(speed);
	mWheelFR.setSpeed(speed);
	mWheelBR.setSpeed(speed);
	mWheelBL.setSpeed(speed);
}

void SwerveDriveLikeACar::setFrontAngles(double angle) {
	mWheelFL.setAngle(angle);
	mWheelFR.setAngle(angle);
}

void SwerveDriveLikeACar::stop() {
	setSpeeds(0);
}

void SwerveDriveLikeACar::setNeutralMode(ctre::phoenix::motorcontrol::NeutralMode mode) {
	mWheelFL.setDriveNeutralMode(mode);
	mWheelBL.setDriveNeutralMode(mode);
	mWheelBR.setDriveNeutralMode(mode);
	mWheelFR.setDriveNeutralMode(mode);
}
	
void SwerveDriveLikeACar::Periodic() {}
