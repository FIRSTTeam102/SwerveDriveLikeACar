#pragma once

#include <ctre/Phoenix.h>
#include <frc/AnalogInput.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/Encoder.h>

namespace SwerveDriveConstants {
	// Motor ports
	const int kFLDrive = 21;
	const int kFLTurn = 22;
	const int kFRDrive = 23;
	const int kFRTurn = 24;
	const int kBRDrive = 25;
	const int kBRTurn = 26;
	const int kBLDrive = 27;
	const int kBLTurn = 28;

	// Encoder Ports
	const int kFLEnc = 0;
	const int kFREnc = 1;
	const int kBREnc = 2;
	const int kBLEnc = 3;

	// Calibration Values
	const int kFLOffset = 562;
	const int kFROffset = 440;
	const int kBROffset = 2694;
	const int kBLOffset = 2222;

	const double kMaxSpeed = 1.00;

	const double kDeadzone = 0.1;

	// Motor Max Speeds
	const double kFLMaxSpeed = 490;
	const double kFRMaxSpeed = 507;
	const double kBRMaxSpeed = 494;
	const double kBLMaxSpeed = 513;
	const double kSlowestSpeed = kFLMaxSpeed;

	const bool useSteeringWheel = false;
}

class SwerveWheel : public frc2::SubsystemBase {
	public:
		SwerveWheel(int drivePort, int turnPort, int encPort, int encOffset, double maxSpeed, int encPort2 = -1);

		void setAngle(double angle);
		void setSpeed(double speed);

		int getEnc() {
			return (mpHallEnc != nullptr) ? mpEnc->GetValue() : mpHallEnc->Get();
		}
		void setCalibration(bool enabled) {
			mCalibration = enabled;
			if (enabled) mTurnMotor.SetNeutralMode(NeutralMode::Coast);
			else mTurnMotor.SetNeutralMode(NeutralMode::Brake);
		}
		void setOffset(int offset) {
			mAngleOffset = offset;
			printf("wheel %d offset set to %d\n", mWheelNum, mAngleOffset);
		}

		void setDriveNeutralMode(ctre::phoenix::motorcontrol::NeutralMode mode);

		void Periodic();

	private:
		TalonSRX mDriveMotor;
		TalonSRX mTurnMotor;
		frc::AnalogInput* mpEnc;
		frc::Encoder* mpHallEnc;
		int circScale(int i);
		int mWheelNum; // for debugging
		int mAngleOffset;
		double mMaxSpeed;
		int target = 0;
		int scaledTarg;
		int scaledPos, posCurrent;
		bool inverted = false;
		bool mCalibration = false;
};