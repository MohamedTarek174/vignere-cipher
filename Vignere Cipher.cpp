//FCAI - Programming 1 - 2022 - Assignment 2
//Program Name : Vignere Cipher.cpp
//Program description: program to Encrypt and Decrypt messages with keyword
//LAst modification Date: 16 / 03 / 2022
// Author1 and ID and Group: Mohamed Tarek abdelsattar , 20210343
// Teaching Assistant: xxxxx xxxxx
// Purpose: Learn c++



#include <iostream>
#include <string>

using namespace std;
string message;
string mappedkey;

void Mes_a_Key(){
    //Enter the message you want to encrypt
    string msg;

    string key;
    cout<<"The maximum number of characters \nthat can be entered for encryption is 80 "<<endl;
    cout<<"Enter the message : ";
    getline(cin,msg);
    if (msg.length() > 80){
        cout<<"Wrong"<<endl;
        Mes_a_Key();
    }

    //message to upper
    for(int i = 0; i < msg.length() ; i++){
        msg[i] = toupper(msg[i]);
    }

    //Enter the key word
    cout<<"The maximum number of characters \nthat can be entered for keyword is 8"<<endl;
    cout<<"Enter the key word: ";
    getline(cin,key);
    if (key.length() > 8){
        cout<<"Wrong"<<endl;
        Mes_a_Key();
    }

     //key word to upper
     for(int i = 0; i < key.length() ; i++){
        key[i] = toupper(key[i]);
     }
     // repeated message
     string keymap = "";
     for (int i = 0,j = 0; i < msg.length() ; i++){
        if(j<key.length()){
            keymap += key[j];
            j++;
        }else {
            j = 0;
            keymap += key[j];
            j++;
        }
     }
     cout<<"message: "<<msg<<"\n"<<"repeated keyword: "<<keymap<<"\n";
     message = msg;
     mappedkey = keymap;

}


void Cipherencryption(){
//convert the message and the key to ASCII
    int ci , x;
    char cii;
    cout<<"encrypted message: ";
    for (int i = 0 ; i < message.length() ; i++){
        int asciimes = message[i];//convert the message to ASCII
        int asciikey = mappedkey[i];//convert the keyword to ASCII
        //if there are space or symbols or numbers , it keeps it
        if (message[i] > 90 || message[i] < 65){
            mappedkey[i] == 0;
            cii = char(message[i]);
            cout<<cii;
        }
        else

        {
            ci = message[i]+mappedkey[i];
            ci = ci % 26;
            ci = ci + 65;
            cii = char(ci);

            cout<<cii;
        }

    }

}
void Cipherdecrypt(){
    string key;
    string enc;
    int mesasci;
    char mes;

    cout<<"The maximum number of characters \nthat can be entered for decryption is 80 "<<endl;
    cout<<"Enter the encrypted message: ";
    getline(cin,enc);

    if (enc.length() > 80){
        cout<<"Wrong"<<endl;
        Cipherdecrypt();
    }

    cout<<"The maximum number of characters \nthat can be entered for keyword is 8"<<endl;
    cout<<"Enter the keyword: ";
    getline(cin,key);
    if (key.length() > 8){
        cout<<"Wrong"<<endl;
        Cipherdecrypt();
    }
    //convert the encrypt message to upper
    for(int i = 0; i < enc.length() ; i++){
        enc[i] = toupper(enc[i]);
    }
    //convert the keyword to upper
    for(int i = 0; i < key.length() ; i++){
        key[i] = toupper(key[i]);
    }
    //repeat the keyword
    string keymap = "";
    for (int i = 0,j = 0; i < enc.length() ; i++){
        if(j<key.length()){
            keymap += key[j];
            j++;
        }else {
            j = 0;
            keymap += key[j];
            j++;
        }
    }//end the repeating
    cout<<"encrypt message:  "<<enc<<"\n"<<"repeated keyword: "<<keymap<<"\n";

     for (int i = 0 ; i < enc.length() ; i++){
        int asciienc = enc[i];//convert the message to ASCII
        int asciikey = keymap[i];//convert the keyword to ASCII

        if (enc[i] < 57 && enc[i] > 48){//if there are numbers , it keeps it
            cout<<char(enc[i]);
        }
        else if (enc[i] == 32 ){//if there are spaces , it keeps it
            cout<<char(enc[i]);
        }else{
            enc[i] = enc[i] - 65;
            for (int j = 130 ; j < 180 ; j++ ){
                if( j % 26 == enc[i]){
                    mesasci = j - keymap[i];
                    if (mesasci > 90 || mesasci < 65){//if the word is symbol , it remove it
                        continue;
                    }
                    mes = char(mesasci) ;
                    cout<<mes;
                }//if
            }//for

        }//else
    }//for i

}


int main()
{
    int choice;
    cout<<"Ahlan ya user ya habibi.\nWhat do you like to do today?"<<endl;
    cout<<"1.Encrypt\n2.Decrypt\n3.End\nChoose(1,2,3): ";
    cin>>choice;
    cin.ignore();

    if (choice == 1 )
    {
        cout<<"Encryption"<<endl;
        Mes_a_Key();
        Cipherencryption();
    }

    else if (choice == 2)
    {
      cout<<"Decryption"<<endl;
      Cipherdecrypt();

    }

    else if (choice == 3)
    {
        cout<<"";
    }
    else
    {
        cout<<"wrong choice"<<endl;
        return main();
    }
    return 0;
}
