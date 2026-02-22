#ifndef SERVER_HPP
#define SERVER_HPP
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace SocketServer {

	class Server {
		int fd, port;
		struct sockaddr_in saddr, caddr;

		public:
			
			Server(int port): port(port) {
				this->saddr = {};
				this->caddr = {};
			}
			virtual ~Server() = default;

			void init();
			int getServerfd();
			int acceptConnection();
			void setnonblock(int fd);
			void closeConnection(); 
	};
};
#endif
