class Salary:
    def compute_salary_a(self):
        basic = 641.2
        allowance = 146/100 * basic
        tax = 20/100 * basic

        salary = basic + allowance - tax
        return salary
    
    
    def compute_salary_b(self):
        basic = 641.2 * 70/100
        allowance = 112.2/100 * basic
        tax = 10/100 * basic

        salary = basic + allowance - tax
        return salary

    
    def compute_salary_c(self):
        basic = 641.2 * 62.2/100
        allowance = 150.8/100 * basic
        tax = 8.1/100 * basic

        salary = basic + allowance - tax
        return salary


program = True
staff = Salary()
while program:
    print("Salary Calculator\n1. Staff A\n2. Staff B\n3. Staff C\n4. Exit")
    option = input("Enter a Number: ")
    if option == "1":
        print(staff.compute_salary_a())

    elif option == "2":
        print(staff.compute_salary_b())

    elif option == "3":
        print(staff.compute_salary_c())
        
    elif option == "4":
        print("Thank You for Using Our Services")
        program = False

    else:
        print("Invalid Number")