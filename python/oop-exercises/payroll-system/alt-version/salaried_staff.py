from employee import Employee

class SalariedStaff(Employee):
    def __init__(self, employee_no, employee_name, department, monthly_salary):
        super().__init__(employee_no, employee_name, department)
        self.monthly_salary = monthly_salary

    def salary(self):
        return self.monthly_salary

    def display(self):
        super().display()
        print("Category    : Salaried Staff")
        print(f"Salary      : GHS {self.salary():.2f}")