#include <iostream>
#include <string>

/*
Name: Stefano Pinna Segovia
Date: 11/1/2023
Lab 4 - Encrypt / Decrypt Data
Task: Encrypts a string by downshifting each character in the ASCII set by the number given
and then decrypts it to the original message.
Pseudocode:
Function Encrypt first calculates the size of the input array by itterating through it and
increasing the size int by 1 every increment. It then creates a new character array for the
encrypted text, with plus 1 being added for the null-terminator. It then encrypts the input 
by downshifting it down the ASCII set by the secret int. It is cast as a char so that nothing
goes wrong. It then null terminates the encrypted text and proceeds to reverse the character 
array through itteration. Finally, it returns the encrypted text.
For the Decrypt function, it has the same parameters and type as the Encrypt function. Just 
like Encrypt, it calculates size of input array and creates a new character array. It then 
does everything in the Encrypt function just in the opposite way. It reverses the characters 
in the array and then decrypts it by upshifting. 
Finally, in the main function, the system asks the user for a number, which is the secret key, 
and a line of text, which can multiple lines. To make the multiple lines possible, the loop 
makes it so it continues to recieve lines until tab and enter are pressed at the exact same 
time. It then displays the encrypted and decrypted code. As a bonus, I deleted the encrypted
and decrypted text in order to allocate memory. 
*/

char *Encrypt(char *input, int secret)
{
    int size = 0;
    char *p = input;
    while (*p != '\0')
    {
        size++;
        p++;
    }

    char *encryptedText = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        encryptedText[i] = static_cast<char>(input[i] + secret);
    }

    encryptedText[size] = '\0';

    for (int i = 0; i < size / 2; i++)
    {
        char temp = encryptedText[i];
        encryptedText[i] = encryptedText[size - 1 - i];
        encryptedText[size - 1 - i] = temp;
    }

    return encryptedText;
}

char *Decrypt(char *input, int secret)
{

    int size = 0;
    char *p = input;
    while (*p != '\0')
    {
        size++;
        p++;
    }

    char *decryptedText = new char[size + 1];

    for (int i = 0; i < size; i++)
    {
        decryptedText[i] = input[i];
    }

    for (int i = 0; i < size / 2; i++)
    {
        char temp = decryptedText[i];
        decryptedText[i] = decryptedText[size - 1 - i];
        decryptedText[size - 1 - i] = temp;
    }

    for (int i = 0; i < size; i++)
    {
        decryptedText[i] = static_cast<char>(decryptedText[i] - secret);
    }

    decryptedText[size] = '\0';

    return decryptedText;
}

int main()
{
    int secret;
    std::string text;
    std::string inputLine;

    std::cout << "Enter an integer value as the secret key" << std::endl;
    std::cin >> secret;

    std::cout << "Enter text to be encrypted/decrypted (press Tab + Enter to finish):\n";

    while (getline(std::cin, inputLine))
    {
        if (inputLine == "\t")
        {
            break;
        }
        text += inputLine + "\n";
    }

    char *encryptedText = Encrypt(&text[0], secret);
    std::cout << "Encrypted text:\n"
              << encryptedText << std::endl;
    char *decryptedText = Decrypt(encryptedText, secret);
    std::cout << "Decrypted text:\n"
              << decryptedText << std::endl;

    delete[] encryptedText;
    delete[] decryptedText;

    system("pause");
    return 0;
}
