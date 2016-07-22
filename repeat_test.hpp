/*
 * repeat_test.hpp
 *
 *  Created on: 2016Äê7ÔÂ21ÈÕ
 *      Author: zyb
 */

#ifndef REPEAT_TEST_HPP_
#define REPEAT_TEST_HPP_

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <fstream>
#include <iostream>
#include <cmath>

typedef std::vector<Eigen::Vector3d> vec3d;

class repeat_test {
public:
	repeat_test(const char* file_name);
	virtual ~repeat_test();
	int read_data(vec3d&);
	int calc_rep_res();
private:
	char* m_file;
};

#endif /* REPEAT_TEST_HPP_ */
