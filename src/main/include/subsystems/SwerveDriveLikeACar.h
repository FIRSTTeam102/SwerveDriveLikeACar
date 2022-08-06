#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/XboxController.h>

#include "SwerveWheel.h"

class SwerveDriveLikeACar : public frc2::SubsystemBase {
	public:
		SwerveDriveLikeACar();
		bool isBraking = false;

		void setDriverController(frc::XboxController* pDriverController) {
			mpDriverController = pDriverController;
		}

		void drive();
		void stop();
		void setNeutralMode(ctre::phoenix::motorcontrol::NeutralMode mode);

		void setSpeeds(double speed);
		void setFrontAngles(double angle);

		void Periodic() override;

		enum Gear {
			Forward,
			Reverse,
			Neutral,
			Park
		};

		const char* gearStrings[4] = {"Forward", "Reverse", "Neutral", "Park"}; 

		Gear mGear = Gear::Park;

	private:

		frc::XboxController* mpDriverController;

		SwerveWheel mWheelFL{21, 22, 0, SwerveDriveConstants::kFLOffset, SwerveDriveConstants::kFLMaxSpeed};
		SwerveWheel mWheelFR{23, 24, 1, SwerveDriveConstants::kFROffset, SwerveDriveConstants::kFRMaxSpeed};
		SwerveWheel mWheelBR{25, 26, 2, SwerveDriveConstants::kBROffset, SwerveDriveConstants::kBRMaxSpeed};
		SwerveWheel mWheelBL{27, 28, 3, SwerveDriveConstants::kBLOffset, SwerveDriveConstants::kBLMaxSpeed};
};
