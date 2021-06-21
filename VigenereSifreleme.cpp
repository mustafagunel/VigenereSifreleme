#include <iostream>
#include <string>

using namespace std;

string encryptData(string plainText, string key);
string decryptData(string encryptedText, string key);

int main()
{
	// küçük harfler 97-122
	string key = "anahtar";
	string plainText = "thiscryptosystemisnotsecure";
	string encrypted = encryptData(plainText,key);
	string decrypted = decryptData(encrypted, key);

	cout << plainText << endl <<"Encrypted: "<< encrypted << endl <<"Decrypted: " << decrypted;
	
	
}
string encryptData(string plainText, string key) {
	string encrypted;

	int j = 0;
	for (int i = 0;i < plainText.length();i++) {

		if (j == key.length())
			j = 0;
		encrypted += (char)(((int)plainText[i] + (int)key[j] - 97*2)%26+97);

		j++;
	}
	return encrypted;
}

string decryptData(string encryptedText, string key) {
	string decrypted;

	int j = 0;
	for (int i = 0;i < encryptedText.length();i++) {

		if (j == key.length())
			j = 0;
		if(((int)encryptedText[i] - (int)key[j]) < 0 )
			decrypted += (char)(((int)encryptedText[i] - (int)key[j]) + 26 + 97);
		else
			decrypted += (char)(((int)encryptedText[i] - (int)key[j]) % 26 + 97);
		j++;
	}
	return decrypted;
}