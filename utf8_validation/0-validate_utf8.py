#!/usr/bin/python3
"""
    Script to UTF-8 validation
"""


def validUTF8(data):
    """
         method that determines if a given data set represents
         a valid UTF-8 encoding

        :param data: list of integer

        :return: True if data valid UTF-8, else False
    """
    successive_10 = 0
    for num in data:
        # return binary representation, remove 0b prefix, add 0 to have 8 char
        num = bin(num).replace('0b', '').rjust(8, '0')

        # check if multibyte sequence is attend
        if successive_10 != 0:
            successive_10 -= 1
            if not num.startswith('10'):
                return False
        # check if beginning of a multibyte character
        elif num[0] == '1':
            # give number supplementary octet
            successive_10 = len(num.split('0')[0]) - 1

    return True
