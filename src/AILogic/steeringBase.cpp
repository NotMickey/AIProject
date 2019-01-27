#include "steeringBase.h"

float AIProject::SteeringBase::GetNewOrientation(const float & i_orientation, const ofVec2f & i_velocity)
{
	if (i_velocity.lengthSquared() > 0)
	{
		return atan2f(i_velocity.y, i_velocity.x);
	}

	return i_orientation;
}

float AIProject::MapToRange(const float & i_orientation)
{
	float inDeg = 180 / PI * i_orientation;

	inDeg = inDeg - 360 * (floorf((inDeg + 180) / 360));

	return PI / 180 * inDeg;
}
