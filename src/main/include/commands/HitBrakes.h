#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/SwerveDriveLikeACar.h"

class HitBrakes : public frc2::CommandHelper<frc2::CommandBase, HitBrakes> {
	public:
		HitBrakes(SwerveDriveLikeACar* pSwerveLikeACar);

		void Initialize() override;

		void Execute() override;

		void End(bool interrupted) override;

		bool IsFinished() override;

	private:
		SwerveDriveLikeACar* mpSwerveLikeACar;
};
