all: driver

driver: driver.cpp BST.cpp
	g++ -o driver driver.cpp BST.cpp

clean:
	rm -f driver
