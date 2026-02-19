#ifndef SERVER_HPP

#define SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace MainServer {

	class Server {
		int fd, port;

		void init();
		struct sockaddr_in saddr, caddr;

		public:
			
			Server(int port): port(port) {
				this->saddr = {};
				this->caddr = {};	
			}
			~Server() {

			}

			int acceptConnection();
			void setnonblock(int fd);
	};
};
#endif
