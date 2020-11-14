#pragma once

namespace Hasher {
	class Core {
		public:
			Core();
			~Core();
			void init();
			int run();


		private:
			bool running_;
	};
}
