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
  database="bus_reservation_system"
)
db = mydb.cursor()
#------------------------------------------------------------------------

#CHECK THE FUNCTION------------------------------------------------------
if func == "get_buses":
    print("Bus ID\t \t\t\tBus Route\t \t \tAvailable Seats\n")
    query = "SELECT * FROM `buses`"
    db.execute(query)
    for x in db:
        print(str(x[0])+"\t \t \t"+x[2]+"\t \t\t\t"+str(x[1]))


if func == "book_bus":
    #GET SOME DATA----------------------------------------------------------------------------------
    username = input("Please enter your username/customer_id (MAX_LIMIT=50): ")
    movie_id = input("Please enter Bus ID: ")
    tickets_booked_cancelled = input("Please input number of seats: ")
    #-----------------------------------------------------------------------------------------------
    query = "INSERT INTO `booked_tickets` (username, tickets_booked, movie_id) VALUE (%s, %s, %s)"
    values = (username, tickets_booked_cancelled, movie_id)
    db.execute(query, values)
    mydb.commit()

    #UPDATING THE AVAILABLE NUMBER OF TICKETS-------------------------------------------------------
    query = "SELECT * FROM `buses` WHERE id = "+str(movie_id)
    db.execute(query)
    for x in db:
        available_tickets = x[1]
    query = "UPDATE `buses` SET `available_tickets` = '"+str(available_tickets-int(tickets_booked_cancelled))+"' WHERE `buses`.`id` = "+str(movie_id)
    #net = available_tickets-int(tickets_booked_cancelled)
    db.execute(query)
    mydb.commit()
    #-----------------------------------------------------------------------------------------------
    

if func == "cancel_bus":
    #GET SOME DATA----------------------------------------------------------------------------------
    username = input("Please enter your username/customer_id (MAX_LIMIT=50): ")
    movie_id = input("Please enter Bus ID: ")
    tickets_booked_cancelled = input("Please input number of seats: ")
    #-----------------------------------------------------------------------------------------------
    query = "INSERT INTO `cancelled_tickets` (username, tickets_booked, movie_id) VALUE (%s, %s, %s)"
    values = (username, tickets_booked_cancelled, movie_id)
    db.execute(query, values)
    mydb.commit()

    #UPDATING THE AVAILABLE NUMBER OF TICKETS-------------------------------------------------------
    query = "SELECT * FROM `buses` WHERE id = "+str(movie_id)
    db.execute(query)
    for x in db:
        available_tickets = x[1]
    query = "UPDATE `buses` SET `available_tickets` = '"+str(available_tickets+int(tickets_booked_cancelled))+"' WHERE `buses`.`id` = "+str(movie_id)
    #net = available_tickets-int(tickets_booked_cancelled)
    db.execute(query)
    mydb.commit()
    #-----------------------------------------------------------------------------------------------





#query = "INSERT INTO `movies` (available_tickets, movie_name) VALUE (%s, %s)"
#values = ("69", "Avatar: The way of waters")
#query = "SELECT * FROM `movies`"
#db.execute(query, values)
#mydb.commit()
#print(db)
