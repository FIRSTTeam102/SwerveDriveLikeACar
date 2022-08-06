#include "commands/RunSwerveLikeACar.h"

RunSwerveLikeACar::RunSwerveLikeACar(SwerveDriveLikeACar *pSwerveLikeACar) : mpSwerveLikeACar{pSwerveLikeACar} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(mpSwerveLikeACar);
}

// Called when the command is initially scheduled.
void RunSwerveLikeACar::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunSwerveLikeACar::Execute() {
	mpSwerveLikeACar->drive();
}

// Called once the command ends or is interrupted.
void RunSwerveLikeACar::End(bool interrupted) {}

// Returns true when the command should end.
bool RunSwerveLikeACar::IsFinished() {
	return false;
}
