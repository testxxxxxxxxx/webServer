#include <iostream>
#include "../include/Multiplexer.hpp"
#include <unistd.h>

void Multiplexing::Multiplexer::init() {
	this->efd = epoll_create1(0);
	if(this->efd == -1) {
		perror("epoll_create1 error");
		exit(1);
	}
}
void Multiplexing::Multiplexer::loopEvent() {
	struct epoll_event event, events[this->maxEvent];
        event.events = EPOLLIN;
	event.data.fd = this->s->getServerfd();
      	epoll_ctl(this->efd, EPOLL_CTL_ADD, this->s->getServerfd(), &event);	
}
void Multiplexing::Multiplexer::notifyWritable(int fd) {

}
