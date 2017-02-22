import sys
import cs50

def main():
    print("Number:", end="")
    card = cs50.get_string()
    lenCar = len(card)
    
    result1 = check(card, lenCar)
    
    result2 = calcul(card, lenCar)

    verdict(result1, result2)
    
    exit(0)
def verdict(result1, result2):
    if result2 == 0:
        if result1 == 1:
            print("AMEX")
        elif result1 == 2:
            print("VISA")
        elif result1 == 3:
            print("MASCARD")
        else:
            print("INVALID")
            exit(3)
    else:
        print("INVALID")
        exit(2)

def calcul(card, lenCar):
    summ = 0
    for i in reversed(range(1, lenCar, 2)):
         temp = int(card[i])*2
         summ += temp%10 + int(temp/10)
    for i in reversed(range(0, lenCar, 2)):
        summ += int(card[i])
    return summ%10
        
def check(card, lenCar):
    integ0 = int(card[0])
    integ1 = int(card[1])
    if (lenCar == 15) and ((integ0 == 3) and ((integ1 == 4) or (integ1 == 7))):
        return 1 #AE
    elif (lenCar == 13 or lenCar == 16) and integ0 == 4:
        return 2 #VS
    elif lenCar == 16 and (integ0 == 5 and (integ1 == 1 or integ1 == 2 or integ1 == 3 or integ1 == 4 or integ1 == 5)):
        return 3 #MC
    else:
        print("INVALID")
        exit(1)

    
if __name__ == "__main__":
    main()