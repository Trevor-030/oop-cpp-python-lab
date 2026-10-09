from employee import Employee

class HourlyStaff(Employee):
    def __init__(self, employee_no, employee_name, department, hours_worked, rate_per_hour):
        super().__init__(employee_no, employee_name, department)
        self.hours_worked = hours_worked
        self.rate_per_hour = rate_per_hour

    def salary(self):
        return self.hours_worked * self.rate_per_hour

    def display(self):
        super().display()
        print("Category    : Hourly Staff")
        print(f"Hours Worked: {self.hours_worked}")
        print(f"Rate/Hour   : GHS {self.rate_per_hour:.2f}")
        print(f"Salary      : GHS {self.salary():.2f}")