// Get three pieces of information from the user: a dog¡¯s name, its breed, and its age. Then print a sentence combining all this information.

#include <iostream>

using namespace std;

int main()
{
    string dog_name, dog_breed;
    string dog_age;

    cout << "Name of the dog: ";
    getline(cin, dog_name);

    cout << "Breed of the dog: ";
    getline(cin, dog_breed);

    cout << "Age of the dog: ";
    getline(cin, dog_age);

    string str;

    str = "The dog is named " + dog_name + ", a " + dog_breed + " breed " + " and it is " + dog_age + " years old.";

    cout << endl << str << endl;

    return 0;
}
