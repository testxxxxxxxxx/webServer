#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP
#include "Server.hpp"
#include <sys/epoll.h>

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
			void loopEvent();
			void notifyWritable(int fd);
	};
};
#endif