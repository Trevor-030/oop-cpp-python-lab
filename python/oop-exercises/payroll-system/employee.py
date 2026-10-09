class Employee:
    def __init__(self, employeeNo, employeeName, department):
        self.employeeNo = employeeNo
        self.employeeName = employeeName
        self.department = department

    def display(self):
        print("Employee No:", self.employeeNo)
        print("Employee Name:", self.employeeName)
        print("Department:", self.department)