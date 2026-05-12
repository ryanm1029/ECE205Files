#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
    private:
        string author;
        string title;
        int year;
    public:
        Book(string a, string t, int y){
            author = a;
            title = t;
            year = y;
        }
        string getAuth(Book a){
            return a.author;
        }
        string getTitle(Book a){
            return a.title;
        }

        friend ostream& operator<<(ostream& out, const Book a);
};

bool compareAuth(Book a, Book b);

int main(){

    vector<Book> books;

    while(1){
        
        int choice;
        string tempName;
        string tempAuth;
        int tempYear;

        cout << "Select from the following choices:" << endl;
        cout << "1: Add new book" << endl;
        cout << "2: Delete book" << endl;
        cout << "3: Print all books" << endl;
        cout << "4: quit" << endl;
        cin >> choice;
        getline(cin, tempName);

        switch (choice) {
            case 1:
                cout << "Enter book title:" << endl;
                getline(cin, tempName);
                cout << "Enter author name:" << endl;
                getline(cin, tempAuth);
                cout << "Enter publishing year:" << endl;
                cin >> tempYear;

                books.push_back(Book(tempName, tempAuth, tempYear));
                sort(books.begin(), books.end(), compareAuth);
                break;
            case 2:
                cout << "Enter a title to delete:" << endl;
                cin >> tempName;
                
                for (int i = 0; i < books.size(); i++){
                    if (tempName == books[i].getTitle(books[i])){
                        books.erase(books.begin() + i);
                        break;
                    }
                }
                cout << "Invalid title!" << endl;
                break;
            case 3:
                for (int i = 0; i < books.size(); i++){
                    cout << books[i] << endl;
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }


    }

    return 0;
}

bool compareAuth(Book a, Book b){
    return a.getAuth(a)[0] < b.getAuth(b)[0];
}

ostream& operator<<(std::ostream& out,  const Book a) {
    out << "Book Title: " << a.title << " | Author: " << a.author << " | Publishing Year: " << a.year << endl;
    return out;
}