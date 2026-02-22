#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP
#include "Server.hpp"
#include <sys/epoll.h>

namespace Multiplexing {
	class Multiplexer {
		int efd, maxEvent;
		SocketServer::Server* s;
		public:

			Multiplexer(SocketServer::Server* s, int maxEvent): s(s), maxEvent(maxEvent) {
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