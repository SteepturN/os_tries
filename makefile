##
# Project Title
#
# @file
# @version 0.1
yes: child.cpp parent.cpp
	g++ -Wall -pedantic -g -o child child.cpp
	g++ -Wall -pedantic -g -o parent parent.cpp

# end
