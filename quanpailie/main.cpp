﻿#include "pch.h"
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
#include "Updating.h"
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
	shared_ptr<Updating> u = make_shared<Updating>(p);
	u->operator()(cout);
	return 0;
}
