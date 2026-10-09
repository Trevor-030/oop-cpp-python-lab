from employee import Employee

class CommissionedStaff(Employee):
    def __init__(self, employee_no, employee_name, department,
                 base_salary, targets_completed, bonus_per_target):
        super().__init__(employee_no, employee_name, department)
        self.base_salary = base_salary
        self.targets_completed = targets_completed
        self.bonus_per_target = bonus_per_target

    def salary(self):
        return self.base_salary + (self.targets_completed * self.bonus_per_target)

    def display(self):
        super().display()
        print("Category    : Commissioned Staff")
        print(f"Base Salary : GHS {self.base_salary:.2f}")
        print(f"Targets Met : {self.targets_completed}")
        print(f"Bonus/Target: GHS {self.bonus_per_target:.2f}")
        print(f"Salary      : GHS {self.salary():.2f}")