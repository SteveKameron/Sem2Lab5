#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#include <unordered_set>
#include <string>
#include <functional>

class Book {
public:
    std::string FIO;
    std::string Book_Name;
    std::string Book_Publishing_Office;
    int Year_Of_Publishing, Amount_of_pages;

    Book(std::string fio, std::string name, std::string office, int year, int pages) {
        FIO = fio;
        Book_Name = name;
        Book_Publishing_Office = office;
        Year_Of_Publishing = year;
        Amount_of_pages = pages;
    }

    Book() {}

    //Constructor of copying
    Book(const Book& Other_Book) {
        this->FIO = Other_Book.FIO;
        this->Book_Name = Other_Book.Book_Name;
        this->Book_Publishing_Office = Other_Book.Book_Publishing_Office;
        this->Year_Of_Publishing = Other_Book.Year_Of_Publishing;
        this->Amount_of_pages = Other_Book.Amount_of_pages;
    }
    // = 
    Book& operator = (const Book& Other_Book) {
        this->FIO = Other_Book.FIO;
        this->Book_Name = Other_Book.Book_Name;
        this->Book_Publishing_Office = Other_Book.Book_Publishing_Office;
        this->Year_Of_Publishing = Other_Book.Year_Of_Publishing;
        this->Amount_of_pages = Other_Book.Amount_of_pages;
        return *this;
    }
    size_t hash() const {
        return std::hash<std::string>()(FIO);
    }
};

class HashFunction {
public:
    std::string operator()(const Book& First) {
        return First.FIO;
    }
};


std::ostream& operator << (std::ostream& Output, Book& Other_Book) {
    Output << Other_Book.FIO << '\n';
    Output << Other_Book.Book_Name << '\n';
    Output << Other_Book.Book_Publishing_Office << '\n';
    Output << Other_Book.Year_Of_Publishing << '\n';
    Output << Other_Book.Amount_of_pages << '\n';
    return Output;
}

bool operator < (const Book& First, const Book& Second) {
    return First.FIO < Second.FIO;
}

bool operator <= (const Book& First, const Book& Second) {
    return First.FIO <= Second.FIO;
}

bool operator > (const Book& First, const Book& Second) {
    return First.FIO > Second.FIO;
}

bool operator >= (const Book& First, const Book& Second) {
    return First.FIO >= Second.FIO;
}

bool operator == (const Book& First, const Book& Second) {
    return First.FIO == Second.FIO;
}

bool operator != (const Book& First, const Book& Second) {
    return First.FIO != Second.FIO;
}

class Hasher {
public:
    size_t operator()(const Book& First) const {
        return First.hash();
    }
};

int main() {
    std::set<Book> Book_Set;
    std::unordered_set<Book, Hasher> Book_Unordered;
    std::ifstream file("input.txt");
    std::string Temp_FIO, Temp_Book_Name, Temp_Office;
    int Temp_Year, Temp_Pages;
    std::string Another;

    while (!file.eof()) {
        getline(file, Temp_FIO);
        getline(file, Temp_Book_Name);
        file >> Temp_Office;
        file >> Temp_Year;
        file >> Temp_Pages;
        Book Temp_Book(Temp_FIO, Temp_Book_Name, Temp_Office, Temp_Year, Temp_Pages);
        Book_Set.insert(Temp_Book);
        Book_Unordered.insert(Book(Temp_Book));
        getline(file, Another);
    }

    std::cout << "==========Set==========" << '\n';
    for (Book i : Book_Set) {
        std::cout << i << '\n';
    }
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "==========Unordered_Set==========" << '\n';
    for (Book i : Book_Unordered) {
        std::cout << i << '\n';
    }

    return 0;
}