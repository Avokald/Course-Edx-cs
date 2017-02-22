import string
import sys

def encrypt(plText, shift):
    shiftDict = {}
    lowerChar = string.ascii_lowercase
    upperChar = string.ascii_uppercase
    for i in range(len(lowerChar)):
        shiftDict[lowerChar[i]] = lowerChar[(i+shift)%26]
    for i in range(len(upperChar)):
        shiftDict[upperChar[i]] = upperChar[(i+shift)%26]
    shiftedText = ""
    for i in plText:
        if i.isalpha():
            shiftedText += shiftDict[i]
        else:
            shiftedText += i
    return shiftedText


def main():
    if len(sys.argv) != 2:
        print("Caesar uses 2 command line arguments")
        return -1
    key = int(sys.argv[1])
    plText = str(input("Text: "))
    
    print(encrypt(plText, key))
    
if __name__ == "__main__":
    main()