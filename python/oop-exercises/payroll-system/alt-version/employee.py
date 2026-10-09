class Employee:
    def __init__(self, employee_no, employee_name, department):
        self.employee_no = employee_no
        self.employee_name = employee_name
        self.department = department

    def display(self):
        print(f"Employee No : {self.employee_no}")
        print(f"Name        : {self.employee_name}")
        print(f"Department  : {self.department}")