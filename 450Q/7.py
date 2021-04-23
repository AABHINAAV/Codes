#https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

def rotate( a, n):
    x=a.pop()
    a.insert(0,x)
    return a
    
    


#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        rotate(a, n)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()
