#pragma once

#include "TaskBase/task.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		// -----------
		// SELECTOR Task
		// This task loops through all its childern, running them
		// It immediately terminates and returns the status code of the first child with a RUNNING status 
		// It runs until either all children return FAILURE or if a child returns SUCCESS
		// It returns a SUCCESS at the end
		// -----------

		class Selector : public Task
		{
		public:
			Selector(const int &i_id) : Task(i_id) {}

		protected:
			virtual void OnOpen(const Tick &i_tick) override;
			virtual Status OnExecute(Tick &i_tick) override;
		};
	}
}