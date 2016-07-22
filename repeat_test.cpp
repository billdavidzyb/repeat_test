/*
 * repeat_test.cpp
 *
 *  Created on: 2016Äê7ÔÂ21ÈÕ
 *      Author: zyb
 */

#include "repeat_test.hpp"

using namespace std;
using namespace Eigen;

repeat_test::repeat_test(const char* file_name):
m_file(file_name){
	// TODO Auto-generated constructor stub
}

repeat_test::~repeat_test() {
	// TODO Auto-generated destructor stub
}

int repeat_test::read_data(vec3d& rep_pos){
	ifstream fin(m_file);
	if (fin.fail()){
			cout << "Cannot open the PosFile" << endl;
			exit(1);
	}

	char s1;
	string buf_str,data_str;
	Vector3d tmp;

	vector<Vector3d>().swap(rep_pos);

	while (!fin.eof())
		getline(fin, buf_str);
		data_str = buf_str.substr(buf_str.find("{")+1);
		scanf(data_str.c_str(), "%lf,%lf,%lf %s\n", &tmp(0),&tmp(1),&tmp(2),&s1);
		rep_pos.push_back(tmp);
	}

	fin.close();

	return 0;
}

int repeat_test::calc_rep_res(){
	vec3d rep_pos;
	read_data(rep_pos);

	int num = rep_pos.size();

	Vector3d mean_value = Vector3d::Zero();
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < num; ++j){
			mean_value(i) += rep_pos[j](i);
		}
		mean_value(i) /= num;
	}

	Vector3d rep_err = Vector3d::Zero();
	Vector3d sigma;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < num; ++j){
			rep_err(i) += pow(mean_value(i) - rep_pos[j](i), 2);
		}
		rep_err(i) /= (num - 1);
		sigma(i) = sqrt(rep_err(i));
	}

	cout << "The standard error of x, y and z are:" << endl;
	cout << sigma(0) << " " << sigma(1) << " "  << sigma(2) << endl;

	return 0;
}
