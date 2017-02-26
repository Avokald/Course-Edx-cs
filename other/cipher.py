def decrypt(pltext, key):
    keylen = len(key)
    j = 0
    encText = ""
    for i in pltext:
        if i.isalpha():
            tempKeyChar = key[j]
            if i.isupper():
                if tempKeyChar.isupper():
                    encText += chr(65 + (ord(i) + 13 - (ord(tempKeyChar)+ 13) ) %26 )
                elif tempKeyChar.islower():
                    encText += chr(65 + (ord(i) + 13 - (ord(tempKeyChar)+ 7) ) %26 )
                else:
                    raise KeyError("Error")
            elif i.islower():
                if tempKeyChar.isupper():
                    encText += chr(97 + (ord(i) + 7 - (ord(tempKeyChar)+ 13) ) %26 )
                elif tempKeyChar.islower():
                    encText += chr(97 + (ord(i) + 7 - (ord(tempKeyChar)+ 7) ) %26 )
                else:
                    raise KeyError("ERROR")
            else:
                print("Error")
                quit(2)
        else:
            encText += i
    
        j = (j + 1)%keylen
    print("Result:", encText)
    return encText

def encrypt(pltext, key):
    keylen = len(key)
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
            encText += i
        j = (j + 1)%keylen
    print("Result:", encText)
    return encText
    
def main():
    text = str(input("Text: "))
    key = str(input("Keyword: "))
    encText = encrypt(text, key)
    decrypt(encText, key)
if __name__ == "__main__":
    main()
