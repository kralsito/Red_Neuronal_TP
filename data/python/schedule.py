import schedule
import time

def tarea():
    print("Tarea ejecutada")

schedule.every().day.at("10:00").do(tarea)

while True:
    schedule.run_pending()
    time.sleep(1)
