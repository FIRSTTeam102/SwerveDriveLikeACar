#include "commands/HitBrakes.h"

HitBrakes::HitBrakes(SwerveDriveLikeACar *pSwerveLikeACar) : mpSwerveLikeACar{pSwerveLikeACar} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(mpSwerveLikeACar);
}

// Called when the command is initially scheduled.
void HitBrakes::Initialize() {
	mpSwerveLikeACar->setNeutralMode(Brake);

	mpSwerveLikeACar->isBraking = true;
}

// Called repeatedly when this Command is scheduled to run
void HitBrakes::Execute() {
	mpSwerveLikeACar->stop();
}

// Called once the command ends or is interrupted.
void HitBrakes::End(bool interrupted) {
	mpSwerveLikeACar->setNeutralMode(Coast);
	mpSwerveLikeACar->isBraking = false;
}

// Returns true when the command should end.
bool HitBrakes::IsFinished() {
	return false;
}
