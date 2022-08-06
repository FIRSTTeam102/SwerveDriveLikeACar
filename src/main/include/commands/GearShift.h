#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/SwerveDriveLikeACar.h"

class GearShift
	: public frc2::CommandHelper<frc2::InstantCommand,
								 GearShift> {
	public:
		GearShift(SwerveDriveLikeACar* pSwerveLikeACar, SwerveDriveLikeACar::Gear gear);

		void Initialize() override;
	
	private: 
		SwerveDriveLikeACar* mpSwerveLikeACar;
		SwerveDriveLikeACar::Gear mGear;
};
