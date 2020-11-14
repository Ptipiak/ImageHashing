#pragma once
#include "core/Base.h"

namespace Hasher {

	class EXPORT Application {
		 public:
			Application(); 
			virtual ~Application();
			static Application& get() { return *instance_; }
		private:
			static Application* instance_;
	};

	EXPORT Application* CreateApplication();
}
