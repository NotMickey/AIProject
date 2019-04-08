#pragma once

#include "TaskBase/task.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		// -----------
		// INVERTER Task
		// This task flips the Status code of it child
		// If it was a SUCCESS, this task return a FAILURE
		// And vice versa
		// -----------

		class Inverter : public Task
		{
		public:
			Inverter(const int &i_id) : Task(i_id) {}

			virtual Status OnExecute(Tick &i_tick) override;

		private:

		};
	}
}