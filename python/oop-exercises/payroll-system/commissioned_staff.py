from employee import Employee

class CommissionedStaff(Employee):
    def __init__(self, employeeNo, employeeName, department, baseSalary, targetsCompleted, bonusPerTarget):
        super().__init__(employeeNo, employeeName, department)
        self.baseSalary = baseSalary
        self.targetsCompleted = targetsCompleted
        self.bonusPerTarget = bonusPerTarget

    def salary(self):
        return self.baseSalary + (self.targetsCompleted * self.bonusPerTarget)

    def display(self):
        super().display()
        print("Base Salary: £", self.baseSalary)
        print("Targets Completed:", self.targetsCompleted)
        print("Bonus Per Target: £", self.bonusPerTarget)
        print("Salary: £", self.salary())
        print("------------------------")