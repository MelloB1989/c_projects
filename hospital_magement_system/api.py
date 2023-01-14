import mysql.connector
import sys

#GET THE DATA FROM THE C PROGRAM-----------------------------------------
func = sys.argv[1]
#------------------------------------------------------------------------

#CONNECT TO MYSQL--------------------------------------------------------
mydb = mysql.connector.connect(
  host="test.mellob.co",
  user="admin",
  password="Mellob1989@SQL",
  database="hospital_management"
)
db = mydb.cursor()
#------------------------------------------------------------------------

#CHECK THE FUNCTION------------------------------------------------------
if func == "debug":
    query = "SELECT * FROM `doctors` WHERE `doctors`.`doctor_name` = 'kk'"
    db.execute(query)
    for x in db:
        print(x)

if func == "add_doctor":
    doctor_name = input("Please input doctor's name: ")
    query = "INSERT INTO `doctors` (id, doctor_name) VALUES (NULL, '"+doctor_name+"')"
    db.execute(query)
    mydb.commit()
    query = "SELECT * FROM `doctors` WHERE `doctors`.`doctor_name` = '"+doctor_name+"'"   
    db.execute(query)
    for x in db:
        print("Added "+x[1]+" successfully in the database!")
        print("Doctor id: "+str(x[0]))

if func == "add_patient":
    patient_name = input("Please input patient's name: ")
    query = "INSERT INTO `patients` (id, patient_name) VALUE (NULL, '"+patient_name+"')"
    db.execute(query)
    mydb.commit()
    query = "SELECT * FROM `patients` WHERE `patients`.`patient_name` = '"+patient_name+"'"   
    db.execute(query)
    for x in db:
        print("Added "+x[1]+" successfully in the database!")
        print("Patient id: "+str(x[0]))





#query = "INSERT INTO `movies` (available_tickets, movie_name) VALUE (%s, %s)"
#values = ("69", "Avatar: The way of waters")
#query = "SELECT * FROM `movies`"
#db.execute(query, values)
#mydb.commit()
#print(db)
