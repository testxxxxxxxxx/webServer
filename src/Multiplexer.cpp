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
	struct epoll_event event, events[this->maxEvents];
        event.events = EPOLLIN;
	event.data.fd = this->s->getServerfd();
      	epoll_ctl(this->efd, EPOLL_CTL_ADD, this->s->getServerfd(), &event);
	while(true) {
		int countReady = epoll_wait(this->efd, events, this->maxEvents, -1);

		for(int i = 0; i < countReady; i++) {
			if(events[i].data.fd == this->s->getServerfd()) {
				int cfd = this->s->acceptConnection();
				this->s->setnonblock(cfd);
				event.events = EPOLLIN;
				event.data.fd = cfd;
				epoll_ctl(this->efd, EPOLL_CTL_ADD, cfd, &event);
			} else {
				if(events[i].events & EPOLLIN) {
					char buf[1024] = {};
					int rc = read(events[i].data.fd, buf, 1024);

					//HTTP Request checker	

				}
				if(events[i].events & EPOLLOUT) {

				}
			}
		}
	}	
}
void Multiplexing::Multiplexer::notifyWritable(int fd) {
	epoll_event ev{};
	ev.events = EPOLLIN | EPOLLOUT;
	ev.data.fd = fd;
	epoll_ctl(this->efd, EPOLL_CTL_MOD, fd, &ev);
}
