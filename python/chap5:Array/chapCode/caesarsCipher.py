
'''
Cryptography is science of secret messages and their applications.
Plain Text ---encryption---> Cipher Text ---decryption---> Plain Text
Rotation of r is done by using (i+r)%26 and decryption is done by (i-r)%26.

For encryption, we create a string, whose index represents the letter to be
encrypted, i.e. 0 is 'A', 1 is 'B' and so on, and elemet

'''

class CaesarCipher:

    def __init__(self, shift):
        self._shift = shift
        encoder = [None]*26
        decoder = [None]*26
        for k in range(26):
            encoder[k] = chr ((k+shift)%26 + ord('A'))
            decoder[k] = chr ((k-shift)%26 + ord('A'))
        self._forward = ''.join(encoder)
        self._backward = ''.join(decoder)

    def transform(self, text, key):
        script = []
        for k in text:
            if k.isupper():
                script.append(key[ord(k) - ord('A')])
            elif k.islower():
                script.append(key[ord(k) - ord('a')].lower())
            else :
                script.append(k)
        return ''.join(script)

    def encrypt(self, plain):
        return self.transform(plain, self._forward)

    def decrypt(self, cipher):
        return self.transform(cipher, self._backward)



cipher = CaesarCipher(3)
message = "THE EAGLE IS IN PLAY; MEET AT JOE'S. And bring your stuff along."
coded = cipher.encrypt(message)
print( 'Secret:  ', coded)
answer = cipher.decrypt(coded)
print( 'Message: ', answer)
