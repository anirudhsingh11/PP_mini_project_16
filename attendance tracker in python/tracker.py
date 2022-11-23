
import csv
import pandas
import pandas as pd
def studentview():
    print("welcome")
    print("mark my attendance")
    view()
    # reading the csv file
    userinput = int(input("whats your attendance"))
    location = int(input("whats your number"))
    df = pd.read_csv("students1.csv")
  
    # updating the column value/data
    df.loc[location, 'attendance'] = userinput
  
    # writing into the file
    df.to_csv("students1.csv", index=False)
  
    print(df)


def register():
    student_name = input("student name:")
    roll_no = int(input("roll no:"))
    attendance = int(input("attendance:"))
    username = input("username")
    password = input("password")
   
    data = [[student_name , roll_no , attendance , username , password]]
    
    filename = 'students1.csv'
    with open(filename, 'a+', newline="") as file:
        csvwriter = csv.writer(file) # create a csvwriter object
        
        csvwriter.writerow(data) # write the rest of the data
def view():
    # reading the CSV file
    File1 = pandas.read_csv('students1.csv')

    # displaying the contents of the CSV file
    print(File1)
def adminpage():
    print("1. register student")
    print("2. view all data")
    print("0. main page")
    userChoice = int(input("Enter the choice"))
    if userChoice == 1:
        register()
    elif userChoice == 2:
        view()

def adminlogin():
    print("welcome to admin login page")
    print("login")
    checking_username = input("USERNAME:") 
    if checking_username == "admin":
        checking_password = input("PASSWORD:")
        if checking_password == "123":
            print("login successfull")
            adminpage()
    else:
        print("invalid choice")


def choice_maker(choice):
    # choice = int(choice)
    if choice == 1:
        studentview()
    elif (choice == 2):
        adminlogin()
    elif choice == 0:
        exit()
    else :
        print("invalid choice.")
                     
while True:
    print("Attendance management system")
    print("1. student login")
    print("2. admin login")
    print("0. exit")
    choice = int(input("enter your choiceoo!!"))
    choice_maker(choice)
    continue
