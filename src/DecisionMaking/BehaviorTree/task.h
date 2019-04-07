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

			Status Run(const Tick &i_Tick);

			void Enter(const Tick &i_Tick);
			void Open(const Tick &i_Tick);
			void Execute(const Tick &i_Tick);
			void Close(const Tick &i_Tick);
			void Exit(const Tick &i_Tick);

		protected:
			virtual void OnEnter(const Tick &i_Tick) {}
			virtual void OnOpen(const Tick &i_Tick) {}
			virtual void OnExecute(const Tick &i_Tick) {}
			virtual void OnClose(const Tick &i_Tick) {}
			virtual void OnExit(const Tick &i_Tick) {}

		private:
			int m_id;
			std::vector<Task> m_vChildren;
		};
	}
}