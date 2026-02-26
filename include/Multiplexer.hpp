#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP
#include "Server.hpp"
#include "Client.hpp"
#include <sys/epoll.h>
#include <queue>

namespace Multiplexing {
	class Multiplexer {
		int efd, maxEvents;
		SocketServer::Server* s;
		public:

			Multiplexer(SocketServer::Server* s, int maxEvents): s(s), maxEvents(maxEvents) {
			}
			~Multiplexer() {
				delete this->s;
			}

			void init();
			void loopEvent(std::queue<ClientRequest::Client*> requestQueue);
			void notifyWritable(int fd);
	};
};
#endif