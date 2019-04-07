#pragma once


namespace AIProject
{
	namespace DecisionMaking
	{
		enum Status;
		class Tick;

		class Task
		{
		public:
			inline std::vector<Task> GetChildren() { return m_vChildren; };

			Status Run(const Tick &i_tick);

			void Enter(const Tick &i_tick);
			void Open(Tick &i_tick);                 
			Status Execute(const Tick &i_tick);
			void Close(Tick &i_tick);                
			void Exit(const Tick &i_tick);

			// Task ID
			// -------
			int m_id;

		protected:
			virtual void OnEnter(const Tick &i_tick) {}
			virtual void OnOpen(const Tick &i_tick) {}
			virtual Status OnExecute(const Tick &i_tick) {}
			virtual void OnClose(const Tick &i_tick) {}
			virtual void OnExit(const Tick &i_tick) {}
			
		private:
			std::vector<Task> m_vChildren;
		};

		bool operator==(const Task &lhs, const Task &rhs);
	}
}