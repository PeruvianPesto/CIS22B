#include <iostream>
#include <string>
using namespace std;

class Employee {
    private:
        string name;
        int number;
        int hireDate;
    public:
        Employee();
        Employee(string n, int num, int d);
        void setName(string n);
        void setNumber(int num);
        void setDate(int d);
        string getName();
        int getNumber();
        int getDate();
};

void Employee::setName(string n)
{
    name = n;
}

void Employee::setNumber(int num)
{
    number = num;
}

void Employee::setDate(int d)
{
    hireDate = d;
}

string Employee::getName()
{
    return name;
}

int Employee::getNumber()
{
    return number;
}

int Employee::getDate()
{
    return hireDate;
}

Employee::Employee()
{
    name = "";
    number = 0;
    hireDate = 0;
}

Employee::Employee(string n, int num, int d)
{
    name = n;
    number = num;
    hireDate = d;
}

class ProductionWorker : public Employee {
    private:
        int shift;
        double hourlyPay;
    public:
        void setShift(int s);
        void setHourlyPay(double p);
        int getShift() const;
        double getHourlyPay() const;
        ProductionWorker();
        ProductionWorker(int s, double p);
};

void ProductionWorker::setShift(int s)
{
    shift = s;
}

void ProductionWorker::setHourlyPay(double p)
{
    hourlyPay = p;
}

int ProductionWorker::getShift() const
{
    return shift;
}

double ProductionWorker::getHourlyPay() const
{
    return hourlyPay;
}

ProductionWorker::ProductionWorker()
{
    shift = 0;
    hourlyPay = 0.0;
}

ProductionWorker::ProductionWorker(int s, double p)
{
    shift = s;
    hourlyPay = p;
}


class ShiftSupervisor : public Employee {
    private:
        double annualSalary;
        double annualProductionBonus;
    public:
        ShiftSupervisor();
        ShiftSupervisor(double a, double p);
        double getAnnualSalary() const;
        double getAnnualProductionBonus() const;
        void setAnnualSalary(double a);
        void setAnnualProductionBonus(double p);
};

double ShiftSupervisor::getAnnualSalary() const
{
    return annualSalary;
}

double ShiftSupervisor::getAnnualProductionBonus() const
{
    return annualProductionBonus;
}

void ShiftSupervisor::setAnnualSalary(double a)
{
    annualSalary = a;
}

void ShiftSupervisor::setAnnualProductionBonus(double p)
{
    annualProductionBonus = p;
}

ShiftSupervisor::ShiftSupervisor()
{
    annualSalary = 0.0;
    annualProductionBonus = 0.0;
}

ShiftSupervisor::ShiftSupervisor(double a, double p)
{
    annualSalary = a;
    annualProductionBonus = p;
}

class TeamLeader : public ProductionWorker {
    private:
        double monthlyBonus;
        int requiredTrainingHours;
        int attendedTrainingHours;
    public:
        TeamLeader();
        TeamLeader(double m, int r, int a);
        double getMonthlyBonus() const;
        int getRequiredHours() const;
        int getAttendedHours() const;
        void setMonthlyBonus(double m);
        void setRequiredHours(int r);
        void setAttendedHours(int a);
};

double TeamLeader::getMonthlyBonus() const
{
    return monthlyBonus;
}

int TeamLeader::getRequiredHours() const
{
    return requiredTrainingHours;
}

int TeamLeader::getAttendedHours() const
{
    return attendedTrainingHours;
}

void TeamLeader::setMonthlyBonus(double m)
{
    monthlyBonus = m;
}

void TeamLeader::setRequiredHours(int r)
{
    requiredTrainingHours = r;
}

void TeamLeader::setAttendedHours(int a)
{
    attendedTrainingHours = a;
}

TeamLeader::TeamLeader()
{
    monthlyBonus = 0.0;
    requiredTrainingHours = 0;
    attendedTrainingHours = 0;
}

TeamLeader::TeamLeader(double m, int r, int a)
{
    monthlyBonus = m;
    requiredTrainingHours = r;
    attendedTrainingHours = a;
}