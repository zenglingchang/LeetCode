
def reverse_word(s):
    return s[::-1]
    
if __name__ == "__main__":
    list = map(str,input().strip().split())
    result = []
    for e in list:
        result.append(reverse_word(e))
    print(' '.join(result))