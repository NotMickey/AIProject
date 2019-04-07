#pragma once

#include "TaskBase/task.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class Selector : Task
		{
		public:
			Selector();
			~Selector();

		protected:
			virtual void OnOpen(const Tick &i_tick) override;
			virtual Status OnExecute(Tick &i_tick) override;

		private:

		};
	}
}