#include <iostream>
#include <string>

char* Encrypt(char* input, int secret)
{
    int size = sizeof(input)/sizeof(input[0]);

    for (int i = 0; i < size; i++)
    {
        input[i] = input[i] + secret;
    }

    for (int i = 0; i < size / 2; i++)
    {
        char temp = input[i];
        input[i] = input[size - 1 - i];
        input[size - 1 - i] = temp;
    }

    return input;
}   

char* Decrypt(char* input, int secret)
{
    int size = sizeof(input)/sizeof(input[0]);

    for (int i = 0; i < size; i++)
    {
        input[i] = input[i] - secret;
    }

    for (int i = 0; i < size / 2; i++)
    {
        char temp = input[i];
        input[i] = input[size - 1 - i];
        input[size - 1 - i] = temp;
    }

    return input;
}

int main()
{
    int secret;
    std:: string text;
    std:: string operation;

    std::cout << "Enter an integer value as the secret key" << std::endl;
    std::cin >> secret;

    std::cout << "Enter text to be input/decrypted" << std::endl;
    while (std::getline(std::cin, text))
    {
        std::cout << "Choose operation (encrypt or decrypt)" << std::endl;
        std::cin >> operation;

        if (operation == "encrypt")
        {
            char* encryptedText = Encrypt(&text[0], secret);
            std::cout << "Encrypted text: " << encryptedText;
            system("pause");
        }
        else if (operation == "decrypt")
        {
            char* decryptedText = Decrypt(&text[0], secret);
            std::cout << "Decrypted text: " << decryptedText;
            system("pause");
        }
        else
        {
            std::cout << "Invalid operation";
            system("pause");
        }
    }
    
    return 0;
}