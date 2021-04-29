import serial
import time

print("File has started")

port='COM5'
bluetooth=serial.Serial(port, 38400)

print("Connected")
bluetooth.flushInput() 

for i in range(5):
	print("Ping")

	#These need to be bytes not unicode, plus a number
	bluetooth.write(b"BOOP "+str.encode(str(i)))

	#This reads the incoming data. In this particular example it will be the "Hello from Blue" line
	input_data=bluetooth.readline()

	#These are bytes coming in so a decode is needed
	print(input_data.decode())
	time.sleep(0.1)

bluetooth.close()
print("Done")