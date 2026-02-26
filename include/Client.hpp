#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <unordered_map>

namespace ClientRequest {
	class Client {
		public:
			int cfd;
			char* method,* resource,* httpVersion;
			std::unordered_map<char*, char*> headers;
	};
};
#endif
