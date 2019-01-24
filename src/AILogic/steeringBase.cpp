#include "steeringBase.h"

float AIProject::SteeringBase::GetNewOrientation(const float & i_orientation, const ofVec2f & i_velocity)
{
	if (i_velocity.lengthSquared() > 0)
	{
		return atan2f(i_velocity.y, i_velocity.x);
	}

	return i_orientation;
}
