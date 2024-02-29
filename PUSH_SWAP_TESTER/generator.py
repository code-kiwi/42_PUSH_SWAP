import sys
from random import randint


def main():
    if len(sys.argv) != 2:
        print("ERROR - One and only one argument is expected")
        return
    nb_elts = sys.argv[1]
    if not (nb_elts.isnumeric()):
        print("ERROR - The given argument should be a number")
        return
    nb_elts = int(nb_elts)
    if nb_elts > 2000:
        print("ERROR - The maximum number of elements is 500")
        return
    res = []
    for _ in range(nb_elts):
        while True:
            nb = randint(-2147483648, 2147483647)
            if nb not in res:
                break
        res.append(nb)
    for nb in res:
        print(nb, end=" ")
    print()


if __name__ == "__main__":
    main()
