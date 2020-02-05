
#include<iostream>
#include <string>
using namespace std;
#include"User"
class User
{
    string name;
    string surname;
    int age;
  public:
    User();
    string get_name();
    string get_surname();
    int get_age();

    void Input();
    void set_name(string Name);
    void set_surname(string Surname);
    void set_age(int Age);
  };

User::User()
{
  age = 0;
}
string User::get_name()
{
  return name;
}
string User::get_surname()
{
  return surname;
}
int User::get_age()
{
  return age;
}
void User::set_name(string Name)
{
  name = Name;
}
void User::set_surname(string Surname)
{
  surname = Surname;
}
void User::set_age(int Age)
{
  age = Age;
}
void User::Input()
{
  cout<<"Enter name: ";
  cin>>name;
  cout<<"Enter surname: ";
  cin>>surname;
  cout<<"Enter age: ";
  cin>>age;
}
class Phonebook
{
  User * ptr;
  int count;
public:
  Phonebook();

  void add_user();
  void delete_user();
  void show_users();

  void Test();
};
Phonebook::Phonebook()
{
  ptr = NULL;
  count = 0;
}
void Phonebook::add_user()
{
  if(count == 0)
  {
    count++;
    ptr = new User[count];
    User user;
    user.Input();
    ptr[count-1] = user;

  }
  else
  {
    count++;
    User * buff = new User[count];
    for(int i=0;i<count-1;i++)
    {
      buff[i]=ptr[i];
    }
    User user;
    user.Input();
    buff[count-1] = user;
    delete[] ptr;
    ptr = buff;
  }
}
сиськи аиста

void Phonebook::Test()
{
    for(int i = 0 ; i < count;i++)
    {
      cout<<ptr[i].get_name()<<endl;
    }
}

int main()
{
  Phonebook phonebook;
  phonebook.add_user();
  phonebook.add_user();
  phonebook.Test();
  return 0;
}
