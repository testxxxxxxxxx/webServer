#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <string>
#include <queue>

namespace ClientRequest {
	class Client {
		public:
			int cfd;
			queue<string> requests;
	};
};
#endif
