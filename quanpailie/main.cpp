#include "pch.h"
//#include "Quanpai.h"
//#include "Light.h"
//#include "shexingtianshu.h"
//#include "compare.h"
//#include "Circularseq.h"
//#include "Puzzle.h"
//#include "CrossWord.h"
//#include "Finding.h"
//#include "Hangman.h"
//#include "Dolequeue.h"
//#include "Coding.h"
//#include "Xiangqi.h"
//#include "Squares.h"
//#include "Morse.h"
//#include "Sleeping.h"
//#include "Pga.h"
//#include "Champ.h"
//#include "Symmetry.h"
//#include "Printer.h"
//#include "Updating.h"
//#include "Fibonacci.h"
//#include "Tree.h"
//#include "DropingBalls.h"
//#include "NoMobile.h"
//#include "Tnode.h"
#include "Node2.h"
#include "Fallingleaves.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <cmath>
#include <map>
#include <iterator>
#include <omp.h>
#include <utility>
#include <fstream>
#include <set>
#include <sstream>
#include <numeric>
#include <tuple>
using namespace std;
int main()
{
	const string p = "C:\\Users\\xiaosong\\Desktop\\text.txt";
	shared_ptr<Fallingleaves> f = make_shared<Fallingleaves>(p);
	f->print(cout);
	return 0;
}
