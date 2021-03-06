/*
        LagLang is a game engine language for developing AI systems
        Copyright (C) 2017  William W. Westlake (wwestlake@lagdaemon.com)

        This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/



//============================================================================
// Name        : LagLang.cpp
// Author      : William Westlake
// Version     :
// Copyright   : Copyright (C)2017, All Rights Reserved
// Description : LagLang main entry point
//============================================================================
#include "config.h"
#include <iostream>
#include <vector>
#include <boost/program_options.hpp>
using namespace std;

namespace po = boost::program_options;

const string version = string("0.0.1");

po::options_description desc("Allowed options");
po::variables_map vm;



void setup_program_options(int argc, char* argv[]) {

	desc.add_options()
	    ("help", "produce help message")
	    ("input-file", po::value< vector<string> >(), "input file")
	;

	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

}


int main(int argc, char* argv[]) {
	cout << "LagLang v" << version << endl;
	cout << "Copyright (C)2017, All Rights Reserved" << endl;
	cout << "Distributed under the GNU GPL v3.0" << endl;
	setup_program_options(argc, argv);


	if (argc < 2 || vm.count("help")) {
		cout << desc << "\n";
		return 0;
	}



	return 0;
}
