#include "MazeSolver.h"
#include <iostream>
#include <fstream>
using namespace std;
/*
Name: Angela Lim
Professor: Tiziana Ligorio
Project Description: This project builds a mazesolver from an input file and solves it using stacks
*/
//constructor that reads the input and intializies and fills the maze
MazeSolver::MazeSolver(string input_file){
  int row, col;
  ifstream fin(input_file);
  if(fin.fail()){
    cerr << "Cannot read from input_file_name" << endl;
    exit(1);
  }
  else {
    fin >> row >> col;
    initializeMaze(row, col);
    fillMaze(fin);
    initializeSolution();
    maze_ready = true;
    fin.close();
  }
}
//destructor
MazeSolver::~MazeSolver() {
  if (maze_ready == true) {
    delete maze_;
    delete solution_;
  }
}
//member function that intializes the array
void MazeSolver::initializeMaze(int rows, int columns){
  maze_rows_ = rows;
  maze_columns_ = columns;
  maze_ = new char*[rows];
  for (int i = 0; i < rows; ++i) {
    maze_[i] = new char[columns];
  }
}
//member function that fills the array with the characters
void MazeSolver::fillMaze(ifstream& input_stream){
  char c;
  for (size_t i = 0; i < maze_rows_; i++) {
    for (size_t j = 0; j < maze_columns_; j++) {
      input_stream >> c;
      maze_[i][j] = c;
    }
  }
}
//member function that intalizes the solution array
void MazeSolver::initializeSolution(){
  solution_ = new char*[maze_rows_];
  for (int i = 0; i < maze_rows_; ++i) {
    solution_[i] = new char[maze_columns_];
  }
  copyMazetoSolution();
  maze_ready = true;
}
//member function that adds the character to the solution array
void MazeSolver::copyMazetoSolution(){
  for (size_t i = 0; i < maze_rows_; i++) {
    for (size_t j = 0; j < maze_columns_; j++) {
      solution_[i][j] = maze_[i][j];
    }
  }
}
//returns true if maze_ready is true
bool MazeSolver::mazeIsReady() {
  return maze_ready;
}
//helper function that takes the current position and pushes it onto the stack if extensible
//uses isExtensible and getNewPosition
bool MazeSolver::extendPath(Position current_position) {
  bool extended = false;
  if (isExtensible(current_position,SOUTH)){
    backtrack_stack_.push(getNewPosition(current_position,SOUTH));
    extended = true;
  }
  if (isExtensible(current_position,EAST)){
    backtrack_stack_.push(getNewPosition(current_position,EAST));
    extended = true;
  }
  return extended;
}
//gets the new position of using direction
Position MazeSolver::getNewPosition(Position old_position, direction dir) {
  Position south = {old_position.row +1, old_position.column};
  Position east = {old_position.row, old_position.column+1};
  if(dir == SOUTH){
    return south;
  }
  else if(dir == EAST){
    return east;
  }
  return {-1, -1}; //no move

}
//returns true if the SOUTH or EAST direction can be moved into or is the exit
bool MazeSolver::isExtensible(Position current_position, direction dir) {
  int r = current_position.row;
  int c = current_position.column;
  if ((r+1 < maze_rows_) && (dir==SOUTH) && (maze_[r+1][c]=='_' || maze_[r+1][c]=='$')){
    return true;
  }
  else if ((c+1 < maze_columns_) && (dir==EAST) && (maze_[r][c+1]=='_' || maze_[r][c+1]=='$')){
    return true;
  }
  return false;
}
//pushing the current position onto the stack if extensible and pops the stack if not
bool MazeSolver::solveMaze() {
  Position curr_position = {0,0};
  backtrack_stack_.push(curr_position);
  while(!backtrack_stack_.empty()){
    if(solution_[curr_position.row][curr_position.column]=='$'){
      cout << "Found the exit!!!" << endl;
      return true;
    }
    else if(extendPath(curr_position)){
      solution_[curr_position.row][curr_position.column] = '>';
      curr_position = backtrack_stack_.top();
    }
    else{
      maze_[curr_position.row][curr_position.column] = 'X';
      solution_[curr_position.row][curr_position.column] = '@';
      backtrack_stack_.pop();
      if(!backtrack_stack_.empty()){
        curr_position = backtrack_stack_.top();
      }
      else{
        cout << "This maze has no solution." << endl;
        return false;
      }
    }
  }
  return false;
}
//prints the solution maze
void MazeSolver::printSolution() {
  cout << "The solution to this maze is:" << endl;
  for (size_t i = 0; i < maze_rows_; i++) {
    for (size_t j = 0; j< maze_columns_; j++) {
      cout << solution_[i][j] << " ";
    }
    cout << endl;
  }
}
