#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>

#include "subsystems/SwerveDriveLikeACar.h"
#include "commands/RunSwerveLikeACar.h"
#include "commands/HitBrakes.h"
#include "commands/GearShift.h"

class RobotContainer {
	public:
		RobotContainer();

		frc2::Command *GetAutonomousCommand();

	private:
		// The robot's subsystems and commands are defined here...
		void ConfigureButtonBindings();

		frc::XboxController mDriverController{0};
		frc2::Button mDriverButtonA{[&] { return mDriverController.GetAButton(); }};
		frc2::Button mDriverButtonB{[&] { return mDriverController.GetBButton(); }};
		frc2::Button mDriverButtonX{[&] { return mDriverController.GetXButton(); }};
		frc2::Button mDriverButtonY{[&] { return mDriverController.GetYButton(); }};
		frc2::Button mDriverButtonLB{[&] { return mDriverController.GetLeftBumper(); }};
		frc2::Button mDriverButtonRB{[&] { return mDriverController.GetRightBumper(); }};
		frc2::Button mDriverButtonLMenu{[&] { return mDriverController.GetBackButton(); }};
		frc2::Button mDriverButtonRMenu{[&] { return mDriverController.GetStartButton(); }};
		//frc2::Button mDriverLT{[&] { return DriveConstants::useSteeringWheel ? (mDriverController.GetRawAxis(2) < 0.95) : (mDriverController.GetLeftTriggerAxis() > 0.5); }};
		frc2::Button mDriverLT{[&] { return mDriverController.GetRawButton(6); }}; // temp fix for no pedals
		frc2::Button mDriverRT{[&] { return (mDriverController.GetRightTriggerAxis() > 0.5); }};
		frc2::Button mDriverUpDPad{[&] { return (mDriverController.GetPOV() == 0); }};
		frc2::Button mDriverLeftDPad{[&] { return (mDriverController.GetPOV() == 90); }};
		frc2::Button mDriverDownDPad{[&] { return (mDriverController.GetPOV() == 180); }};
		frc2::Button mDriverRightDPad{[&] { return (mDriverController.GetPOV() == 270); }};

		SwerveDriveLikeACar mSwerveLikeACar;
		RunSwerveLikeACar mRunSwerveLikeACar{&mSwerveLikeACar};
		HitBrakes mHitBrakes{&mSwerveLikeACar};
		GearShift mForwardGear{&mSwerveLikeACar, SwerveDriveLikeACar::Gear::Forward};
		GearShift mReverseGear{&mSwerveLikeACar, SwerveDriveLikeACar::Gear::Reverse};
		GearShift mNeutralGear{&mSwerveLikeACar, SwerveDriveLikeACar::Gear::Neutral};
		GearShift mParkGear{&mSwerveLikeACar, SwerveDriveLikeACar::Gear::Park};
};
