import os, re

def p1():
    
    sum = 0

    with open(os.path.abspath('input.txt'), 'rt') as f:
        lines = f.readlines()

        for line in lines:
            digits = re.findall(r'[\d+]', line)
            temp = int(digits[0] + digits[-1])
            sum += temp

        return sum

def p2():
    
    sum = 0
    digits = {'zero':0, 'one':1, 'two':2, 'three':3, 'four':4, 'five':5, 'six':6, 'seven':7, 'eight':8, 'nine':9}
    regex = r'(?=(one|two|three|four|five|six|seven|eight|nine|\d))'

    with open(os.path.abspath('input.txt'), 'rt') as f:
        lines = f.readlines()

        for line in lines:
            words = []
            
            for word in re.findall(regex, line):
                if(word in digits):
                    words.append(str(digits[word]))
                else:
                    words.append(word)

            sum += int(words[0] + words[-1])
        
        return sum

def main():
    part1 = p1()
    part2 = p2()

    print(f'Part 1: {part1} \nPart 2: {part2}\n')

if __name__ == "__main__":
    main()