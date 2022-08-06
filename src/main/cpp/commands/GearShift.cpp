#include "commands/GearShift.h"

GearShift::GearShift(SwerveDriveLikeACar *pSwerveLikeACar, SwerveDriveLikeACar::Gear gear) : mpSwerveLikeACar{pSwerveLikeACar}, mGear{gear} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(mpSwerveLikeACar);
}

// Called when the command is initially scheduled.
void GearShift::Initialize() {
	if (mGear == SwerveDriveLikeACar::Gear::Park) {
		mpSwerveLikeACar->stop();
		mpSwerveLikeACar->isBraking = true;
	} else {
		mpSwerveLikeACar->isBraking = false;
	}
	mpSwerveLikeACar->mGear = mGear;

	printf("Switched Gear to %s\n", mpSwerveLikeACar->gearStrings[mGear]);
}
