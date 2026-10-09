from employee import Employee

class SalariedStaff(Employee):
    def __init__(self, employeeNo, employeeName, department, monthlySalary):
        super().__init__(employeeNo, employeeName, department)
        self.monthlySalary = monthlySalary

    def salary(self):
        return self.monthlySalary

    def display(self):
        super().display()
        print("Salary: £", self.salary())
        print("------------------------")