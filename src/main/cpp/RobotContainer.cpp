#include "RobotContainer.h"

RobotContainer::RobotContainer() {
	// Initialize all of your commands and subsystems here
	mSwerveLikeACar.SetDefaultCommand(std::move(mRunSwerveLikeACar));
	mSwerveLikeACar.setDriverController(&mDriverController);
	// Configure the button bindings
	ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
	// Configure your button bindings here
	mDriverLT.WhenHeld(&mHitBrakes, true);
	mDriverButtonY.WhenPressed(&mForwardGear, false);
	mDriverButtonX.WhenPressed(&mNeutralGear, false);
	mDriverButtonB.WhenPressed(&mParkGear, false);
	mDriverButtonA.WhenPressed(&mReverseGear, false);
}

frc2::Command *RobotContainer::GetAutonomousCommand() {
	// An example command will be run in autonomous
	return nullptr;
}
