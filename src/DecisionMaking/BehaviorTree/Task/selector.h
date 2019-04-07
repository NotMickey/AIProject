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
		// Otherwise it returns a FAILURE at the end
		// -----------

		class Selector : public Task
		{
		public:
			Selector();

		protected:
			virtual void OnOpen(const Tick &i_tick) override;
			virtual Status OnExecute(Tick &i_tick) override;

		private:

		};
	}
}