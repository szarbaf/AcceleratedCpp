#include <vector>
#include "student_class.h"
#include "grade_students.h"

void GradeStudents::calcPassFail(){

		for (auto& it : students_){
			it.grade();
		}



}
