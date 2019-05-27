#pragma once

#include <vector>
#include <memory>

namespace AIProject
{
	namespace DecisionMaking
	{
		enum Status;
		class Tick;

		class Task
		{
		public:
			Task(const int &i_id) : m_id(i_id) {}

			inline std::vector<std::shared_ptr<Task>> GetChildren() { return m_vChildren; }
			void AddChildTask(const std::shared_ptr<Task> &i_childTask);

			Status Run(Tick &i_tick);

			void Enter(const Tick &i_tick);
			void Open(Tick &i_tick);     

			Status Execute(Tick &i_tick);

			void Close(Tick &i_tick);                
			void Exit(const Tick &i_tick);

			// Task ID
			// -------
			int m_id;

			virtual ~Task() {}

		protected:
			virtual void OnEnter(const Tick &i_tick) {}
			virtual void OnOpen(const Tick &i_tick) {}
			virtual Status OnExecute(Tick &i_tick) { return Status(); }
			virtual void OnClose(const Tick &i_tick) {}
			virtual void OnExit(const Tick &i_tick) {}
			
			std::vector<std::shared_ptr<Task>> m_vChildren;
		};

		bool operator==(const Task &lhs, const Task &rhs);
	}
}