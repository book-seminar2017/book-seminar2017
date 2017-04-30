import random
import sys
import datetime

def main(data_size, file_num):
    file_name = "data" + str(file_num) + ".txt"
    char_list = ["A", "T", "G", "C"]
    with open(file_name, "w") as f:
        f.write(str(data_size) + "\n")
        data = []
        for i in range(0, data_size):
            if (random.randint(0, 10000) % 3) < 1:
                length = (random.randint(0, 10000) % 12) + 1
                print length
                f.write("find ")
                if (len(data) == 0) or ((random.randint(0, 10000) % 3) < 1):
                    #make random
                    for j in range(0, length):
                        f.write(char_list[random.randint(0, 10000) % 4])
                    f.write("\n")
                else:
                    #exit key
                    key = random.randint(0, 10000) % len(data)
                    f.write(data[key] + "\n")
                    
            else:
                length = (random.randint(0, 10000) % 12) + 1
                f.write("insert ")
                ss = ""
                #make random
                for j in range(0, length):
                    s = char_list[random.randint(0, 10000) % 4]
                    f.write(s)
                    ss = ss + s
                f.write("\n")
                data.append(ss)
            
if __name__ == "__main__":
    if not (len(sys.argv) == 3):
        print "Invalide argment"
    random.seed(datetime.datetime.today().second)
    main(int(sys.argv[1]), sys.argv[2])
    
