#include <iostream>
#include <utility>
#include "lib/image.h"
#include "deque.hpp"

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: compare"
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  Image<Pixel> img;
  try{img = readFromFile(input_file);}
  catch(std::exception e) {std::cerr << "Cannot Read Image\n"; return EXIT_FAILURE;}
  int yMax = img.height();
  int xMax = img.width();
  int yStart = 0;
  int xStart = 0;
  int redPixelNum = 0;
  bool done = false;

  for(int i = 0; i < yMax; i++) {
    for(int j = 0; j < xMax; j++) {
	    if(img(i, j) != BLACK && img(i, j) != WHITE && img(i, j) != RED) {
	    	std::cerr << "Invalid Color Detected\n";
		return EXIT_FAILURE;
	    }
	    else if(img(i, j) == RED) {redPixelNum++; yStart = j; xStart = i;}
    }
  }

  if(redPixelNum > 1) {std::cerr << "Multiple Red Pixels\n"; return EXIT_FAILURE;}
  
  std::pair<int, int> s(xStart, yStart);
  Deque<std::pair<int, int>> frontier;
  frontier.pushFront(s);
  bool explored[xMax][yMax];

  int x = 0;
  int y = 0;
  while(!done) {
    if(frontier.isEmpty()) {return EXIT_FAILURE;}
    x = frontier.front().first;
    y = frontier.front().second;
    frontier.popFront();
    explored[x][y] = true;

    if(img(x, y) == WHITE) {
      if(x == 0 || y == 0 || x == xMax - 1 || y == yMax - 1) {img(x, y) = GREEN; done = true; break;}
    }

    if(img(x, y-1) == WHITE) {
      if(!explored[x][y-1]) {frontier.pushBack(std::pair<int, int> (x, y-1)); explored[x][y-1] = true;}
    }

    if(img(x-1, y) == WHITE) {
      if(!explored[x-1][y]) {frontier.pushBack(std::pair<int, int> (x-1, y)); explored[x-1][y] = true;}
    }

    if(img(x, y+1) == WHITE) {
      if(!explored[x][y+1]) {frontier.pushBack(std::pair<int, int> (x, y+1)); explored[x][y+1] = true;}
    }

    if(img(x+1, y) == WHITE) {
      if(!explored[x+1][y]) {frontier.pushBack(std::pair<int, int> (x+1, y)); explored[x+1][y] = true;}
    }
  }

  writeToFile(img, output_file);
  if(done) {std::cout << "Solution Found\n";}
  else {std::cout << "No Solution Found\n";}
  return EXIT_SUCCESS;
}
