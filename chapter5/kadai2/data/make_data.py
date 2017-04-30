import random
import sys
import datetime

def main(data_size, file_num):
    file_name = "data" + str(file_num) + ".txt"
    with open(file_name, "w") as f:
        track = random.randint(1, data_size - 2)
        f.write(str(data_size) + " " + str(track) + "\n")
         
        for i in range(0, data_size):
            w = random.randint(0, 10000)
            f.write(str(w) + "\n")
            
if __name__ == "__main__":
    if not (len(sys.argv) == 3):
        print "Invalide argment"
    random.seed(datetime.datetime.today().second)
    main(int(sys.argv[1]), sys.argv[2])
    
