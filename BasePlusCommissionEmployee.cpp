// Fig. 11.11: BasePlusCommissionEmployee.cpp
// Class BasePlusCommissionEmployee member-function definitions.
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
const string& first, const string& last, const string& ssn,
double sales, double rate, double salary)
// explicitly call base-class constructor
: CommissionEmployee(first, last, ssn, sales, rate) {
setBaseSalary(salary); // validate and store base salary
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
	if (salary < 0.0) {
		throw invalid_argument("Salary must be >= 0.0");
	}
	baseSalary = salary;
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const {
	return baseSalary;
}

// calculate earnings
double BasePlusCommissionEmployee::earnings() const {
	return getBaseSalary() + CommissionEmployee::earnings();
}

string BasePlusCommissionEmployee::toString() const {
	ostringstream output;
	output << "base-salaried " << CommissionEmployee::toString() 
		<< "\nbase salary: " << getBaseSalary();
	return output.str();
}
