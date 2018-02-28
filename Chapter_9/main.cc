#include <iostream>
#include <vector>

#include "student_class.h"
#include "grade_students.h"

using namespace std;


int main(){
	
		vector<student_class> students({
						{"Shahrooz", 80, 90},
						{"Shapal", 80, 80},
						{"Ablah", 100, 95},
						{"Okuz", 40, 30}
						}
						);
	
		GradeStudents grade(students);

		grade.calcPassFail();
		grade.ShowPassFail();

		return 0;

}
