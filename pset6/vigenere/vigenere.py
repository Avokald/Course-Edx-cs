import sys
import cs50

def main():
    if len(sys.argv) != 2:
        print("Insert your key")
        exit(1)
        
    key = sys.argv[1]
    keylen = len(sys.argv[1])
    
    print("Plaintext: ", end="")
    pltext = cs50.get_string()
    
    j = 0
    encText = ""
    for i in pltext:
        if i.isalpha():
            tempKeyChar = key[j]
            if i.isupper():
                if tempKeyChar.isupper():
                    encText += chr(65 + (ord(i) + 13 + (ord(tempKeyChar)+ 13) ) %26 )
                elif tempKeyChar.islower():
                    encText += chr(65 + (ord(i) + 13 + (ord(tempKeyChar)+ 7) ) %26 )
                else:
                    raise KeyError("Error")
            elif i.islower():
                if tempKeyChar.isupper():
                    encText += chr(97 + (ord(i) + 7 + (ord(tempKeyChar)+ 13) ) %26 )
                elif tempKeyChar.islower():
                    encText += chr(97 + (ord(i) + 7 + (ord(tempKeyChar)+ 7) ) %26 )
                else:
                    raise KeyError("ERROR")
            else:
                print("Error")
                quit(2)
        else:
            print("Error")
            quit(1)
    
        j = (j + 1)%keylen
    print("Result:", encText)

if __name__ == "__main__":
    main()
    