#include "employee.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    // Example for Employee
    Employee emp1;
    emp1.setName("John Doe");
    emp1.setNumber(123);
    emp1.setDate(20220101);

    std::cout << "Employee Information:\n";
    std::cout << "Name: " << emp1.getName() << "\n";
    std::cout << "Number: " << emp1.getNumber() << "\n";
    std::cout << "Hire Date: " << emp1.getDate() << "\n\n";

    // Example for ProductionWorker
    ProductionWorker worker1;
    worker1.setShift(1);
    worker1.setHourlyPay(15.50);

    std::cout << "Production Worker Information:\n";
    std::cout << "Shift: " << worker1.getShift() << "\n";
    std::cout << "Hourly Pay: " << worker1.getHourlyPay() << "\n\n";

    // Example for ShiftSupervisor
    ShiftSupervisor supervisor1;
    supervisor1.setAnnualSalary(60000.00);
    supervisor1.setAnnualProductionBonus(5000.00);

    std::cout << "Shift Supervisor Information:\n";
    std::cout << "Annual Salary: " << supervisor1.getAnnualSalary() << "\n";
    std::cout << "Annual Production Bonus: " << supervisor1.getAnnualProductionBonus() << "\n\n";

    // Example for TeamLeader
    TeamLeader leader1;
    leader1.setMonthlyBonus(1000.00);
    leader1.setRequiredHours(50);
    leader1.setAttendedHours(45);

    std::cout << "Team Leader Information:\n";
    std::cout << "Monthly Bonus: " << leader1.getMonthlyBonus() << "\n";
    std::cout << "Required Training Hours: " << leader1.getRequiredHours() << "\n";
    std::cout << "Attended Training Hours: " << leader1.getAttendedHours() << "\n";

    return 0;
}
