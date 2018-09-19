if __name__ == "__main__":
    time = input().strip().split()[0]
    if time[8:10] == "PM":
        temp = str(int(time[0:2])+(0 if time[0:8] == '12:00:00' else 12))
        print(temp[0:2]+time[2:8])
    else:
        if time[0:8] == '12:00:00':
            print('00:00:00')
        else:
            print(time[0:8])
        