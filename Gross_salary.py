# Function to calculate gross salary
def calculate_gross_salary (basic, grade):
    hra = 0.20 * basic
    da = 0.50 * basic
    
    if grade == 'A':
        allow = 1700
    elif grade == 'B':
        allow = 1500
    else:
        allow = 1300
    
    pf = 0.11 * basic
    
    gross_salary = basic + hra + da + allow - pf
    return gross_salary

# Input
basic = int (input ("Enter basic salary: "))
grade = input ("Enter grade (A/B/C): ")

# Calculate gross salary
gross_salary = calculate_gross_salary (basic, grade)
print (f"Gross Salary: {gross_salary:.2f}")

