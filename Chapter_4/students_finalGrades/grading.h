#ifndef GAURD_grading_H
#define GAURD_grading_H

#include <iostream>
#include <vector>

double grade(double mid, double final, const std::vector<double> &hw, double (*hw_reduce) (const std::vector<double> &hw));

double grade(double mid, double final, double reduced_hw);

double median(const std::vector<double> &hw);

double average (const std::vector<double> &hw);

#endif
