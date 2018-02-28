#include <vector>
#include <algorithm>
#include <numeric>
#include "student_class.h"
#include "grade_students.h"


using namespace std;

bool CompareTotalGrade(const student_class& a, const student_class& b){
		return a.GetTotalGrade() < b.GetTotalGrade();
}

void GradeStudents::calcPassFail(){

		for (auto& it : students_){
				if (it.valid() && it.grade() ){
						Grade_t grade;
						if (it.GetTotalGrade() > 60)
								grade = P;
						else
								grade = F;
						grades_.push_back(grade);
				}
		}
}

void GradeStudents::ShowPassFail() const{

		int num_students = students_.size();
		vector<int> indices(num_students);
		iota(indices.begin(), indices.end(), 0);


		const vector<student_class>& students_ref = students_;
		sort(indices.begin(), indices.end(), 
						[students_ref] (int a, int b) -> bool
						{return students_ref[a].GetName() < students_ref[b].GetName();}
						);

		for (auto it = indices.begin(); it != indices.end(); it++){
				string letter_grade = (grades_[*it] == P) ? "Pass" : "Fail";
				cout << students_[*it].GetName() << " : " << letter_grade << endl;
		}
}
