#include <iostream>
#include <fstream>
#include <charconv>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/mman.h>
#include <signal.h>
enum {
	READ_END=0,
	WRITE_END=1,
};
enum {
	STDIN = 0,
	STDOUT = 1,
	STDERR = 2,
};
enum {
	ALL_GOOD=0,
	ERROR_CREATING_PIPE,
	ERROR_CHILD_ARGS,
	ERROR_CREATING_PROCESS,
	ERROR_EXECUTING_PROGRAM,
	ERROR_READING_INPUT,
	ERROR_WRITING_PIPE,
	ERROR_READING_PIPE,
	ERROR_WRITING_ERR,
	MMAP_FAILED,
};
enum {
    NO_FD = -1,
	NO_OFFSET = 0,
};

const char error_creating_pipe[] = "can't create pipe\n";
const char error_child_args[] = "num of descriptor is too large\n";
const char error_creating_process[] = "can't create another process\n";
const char error_executing_program[] = "can't exec prog\n";
const char error_reading_input[] = "error reading from input\n";
const char error_writing_pipe[] = "error writing to pipe\n";
const char error_reading_pipe[] = "error reading from pipe\n";

/*struct send_this {
	send_this(int *ma, char z)
		: mapped_area(ma), zero(z){};
	int* mapped_area;
	char zero;
};*/

/*void set_mapping_pointer_file(int* mapping_area) {
	std::fstream file("take_here.mapping",\
					  std::ios::trunc | std::ios::out | std::ios::binary);
	file.write(reinterpret_cast<char*>(&mapping_area), sizeof(mapping_area));
	file.close(); //errors?
}*/


void function(int num) {
	std::cerr << "\tchild handler\n";
}
int main() {
/*	sigset_t wait_parent;
	sigemptyset(&wait_parent);
	sigaddset(&wait_parent, SIGCONT);
	while(true) {
		std::cout << "child" << std::endl;
		kill(getppid(), SIGCONT);
		sigsuspend(&wait_parent);
	}
*/
/*
	while(true) {
		std::cout << "child" << std::endl;
		kill(getppid(), SIGCONT);
		kill(getpid(), SIGSTOP);
	}
*/
/*
	sigset_t wait_child;
	sigemptyset(&wait_child);
	sigaddset(&wait_child, SIGUSR1);
	while(true) {
		std::cout << "child" << std::endl;
		kill(getppid(), SIGUSR1);
		sigsuspend(&wait_child);
	}
*/
//	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR1, function);
	kill(getppid(), SIGUSR2);
	pause();
	while(true) {
		std::cout << "child" << std::endl;
		kill(getppid(), SIGUSR1);
		pause();
	}
	return ALL_GOOD;
}

