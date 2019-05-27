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
		// It runs until either all children return SUCCESS or if a child returns FAILURE 
		// It returns a SUCCESS at the end
		// -----------

		class RandomDecorator : public Task
		{
		public:
			RandomDecorator(const int &i_id) : Task(i_id) {}

		protected:
			virtual void OnOpen(const Tick &i_tick) override;
			virtual Status OnExecute(Tick &i_tick) override;

		private:

		};
	}
}