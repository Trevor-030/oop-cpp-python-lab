from employee import Employee

class HourlyStaff(Employee):
    def __init__(self, employeeNo, employeeName, department, hoursWorked, ratePerHour):
        super().__init__(employeeNo, employeeName, department)
        self.hoursWorked = hoursWorked
        self.ratePerHour = ratePerHour

    def salary(self):
        return self.hoursWorked * self.ratePerHour

    def display(self):
        super().display()
        print("Hours Worked:", self.hoursWorked)
        print("Rate Per Hour: £", self.ratePerHour)
        print("Salary: £", self.salary())
        print("------------------------")