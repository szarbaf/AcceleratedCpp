#ifndef _GRADE_STUDENTS_
#define _GRADE_STUDENTS_ 

#include <vector>
#include "student_class.h"

typedef enum Grade{
P,
F
} Grade_t;

class GradeStudents{

		public:
				GradeStudents() {}
				GradeStudents(std::vector<student_class> students) : students_(students) {}

				void calcPassFail();
				void ShowPassFail() const;

		private:
				std::vector<student_class> students_;
				std::vector<Grade_t> grades_;
};

#endif
