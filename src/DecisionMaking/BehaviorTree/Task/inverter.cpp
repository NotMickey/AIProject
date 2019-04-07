#include "inverter.h"

#include "../status.h"

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Inverter::OnExecute(Tick & i_tick)
{
	Status stat = (GetChildren()[0])->Run(i_tick);

	switch (stat)
	{
	case Status::SUCCESS:
		return Status::FAILURE;
		break;

	case Status::FAILURE:
		return Status::SUCCESS;
		break;

	default:
		break;
	}

	return stat;
}
