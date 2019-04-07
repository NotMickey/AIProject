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
			void Open(const Tick &i_tick);
			Status Execute(const Tick &i_tick);
			void Close(const Tick &i_tick);
			void Exit(const Tick &i_tick);

		protected:
			virtual void OnEnter(const Tick &i_tick) {}
			virtual void OnOpen(const Tick &i_tick) {}
			virtual Status OnExecute(const Tick &i_tick) {}
			virtual void OnClose(const Tick &i_tick) {}
			virtual void OnExit(const Tick &i_tick) {}

		private:
			int m_id;
			std::vector<Task> m_vChildren;
		};
	}
}