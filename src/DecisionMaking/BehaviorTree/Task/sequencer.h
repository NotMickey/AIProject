#pragma once

#include "TaskBase/task.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		// -----------
		// SEQUENCER Task
		// This task loops through all its childern, running them
		// It immediately terminates and returns the status code of the first child with a RUNNING status 
		// Otherwise it returns a SUCCESS at the end
		// -----------

		class Sequencer : public Task
		{
		public:
			Sequencer();

		protected:
			virtual void OnOpen(const Tick &i_tick) override;
			virtual Status OnExecute(Tick &i_tick) override;

		private:

		};
	}
}