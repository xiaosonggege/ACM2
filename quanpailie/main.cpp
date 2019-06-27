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
#include "Pga.h"
#include "Champ.h"
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
	const string p = "C:\\Users\\xiaosong\\Desktop\\english.txt";
	shared_ptr<Champ> c = make_shared<Champ>(p);
	c->sort_change(cout);
	//shared_ptr<Pga> pga = make_shared<Pga>("song 70 70 70 70");
	//auto tup = pga->information();
	//cout << get<0>(tup) << endl;
	//for (auto &e : get<1>(tup)) cout << e << " ";
	//cout << endl;
	//cout << get<2>(tup) << endl;
	//cout << get<3>(tup) << endl;
	//cout << get<4>(tup) << endl;
	//vector<Pga> pp;
	//pp.push_back(*pga);
	return 0;
}
