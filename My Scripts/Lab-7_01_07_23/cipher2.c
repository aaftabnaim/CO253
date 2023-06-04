def cipher(k, s):
    decoded_string = ""
    for i in range(len(s)):
        if i % k == 0:
            decoded_string += s[i]
        else:
            decoded_string += str(int(s[i]) ^ int(decoded_string[i - 1]))
    return decoded_string

k = 3
s = "1110110100"

decoded_string = cipher(k, s)
print(decoded_string);
