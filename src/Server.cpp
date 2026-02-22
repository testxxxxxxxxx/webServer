#include <iostream>
#include "../include/Server.hpp"
#include <fcntl.h>
#include <unistd.h>

void SocketServer::Server::init() {
	this->fd = socket(AF_INET, SOCK_STREAM, 0);

	this->saddr.sin_family = AF_INET;
	this->saddr.sin_addr.s_addr = INADDR_ANY;
	this->saddr.sin_port = htons(this->port);

	int opt = 1;

	if(setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
		perror("Socket error");
		exit(1);
	}

	if(bind(this->fd, (struct sockaddr*)&this->saddr, sizeof(this->saddr)) < 0) {
		perror("Bind error");
		exit(1);
	}

	if(listen(this->fd, 10) < 0) {
		perror("Listen error");
		exit(1);
	}
	this->setnonblock(this->fd);
}
int SocketServer::Server::getServerfd() {
	return this->fd;
}
int SocketServer::Server::acceptConnection() {
	socklen_t caddrLen = sizeof(this->caddr);
	int cfd = accept(this->fd, (struct sockaddr*)&this->caddr, &caddrLen);
	if(cfd == -1) {
		if(errno == EAGAIN || errno == EWOULDBLOCK)
			return -1;
		perror("Accept error");
		return -1;
	}
	return cfd;	
}
void SocketServer::Server::setnonblock(int fd) {
	int flags = fcntl(fd, F_GETFL);
	fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}
void SocketServer::Server::closeConnection() {
	close(this->fd);
}
