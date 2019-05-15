#include<iostream>
#include<windows.h>
#include<cstdio>
#include<limits>
#include<ios>
#include<fstream>
#include<string>
#include<iomanip>
#include<conio.h>

class BOOK
{
public:
    void display_data();

    char copies[3];
    char price[5];
    char shelf[5];
    char row[5];
    char book_name[100];
    char author_name[100];
    char publisher[100];
    char acc_no[100];
};

struct student
{
    char student_name[20];
    char student_id[20];
    char book_issued[40];
};

constexpr int box_length(90);
constexpr int box_height(25);

void menu();
void box(int box_length, int box_height);
void add_book();
void issue_book(BOOK);
void search_book();
void search_book_by_name();
void search_book_by_acc();
void display_all_records();
int total_records_calculator();
void display_issue_records(student);
void search_issue_records();
void credits();
void gotoxy(int , int);

int main()
{
    menu();
    return 0;
}

void BOOK::display_data()
{
    system("cls");
    box(90,25);
    gotoxy(35,3);
    std::cout<<"DETAILED  RECORD  OF  THE  BOOK";
    gotoxy(20,7);
    std::cout<<"Book";
    gotoxy(40,7);
    std::cout<<":     "<<book_name;
    gotoxy(20,9);
    std::cout<<"Author/Writer";
    gotoxy(40,9);
    std::cout<<":     "<<author_name;
    gotoxy(20,11);
    std::cout<<"Publisher";
    gotoxy(40,11);
    std::cout<<":     "<<publisher;
    gotoxy(20,13);
    std::cout<<"Acc No";
    gotoxy(40,13);
    std::cout<<":     "<<acc_no;
    gotoxy(20,15);
    std::cout<<"Copies";
    gotoxy(40,15);
    std::cout<<":     "<<copies;
    gotoxy(20,17);
    std::cout<<"Price";
    gotoxy(40,17);
    std::cout<<":     "<<price;
    gotoxy(20,19);
    std::cout<<"Shelf";
    gotoxy(40,19);
    std::cout<<":     "<<shelf;
    gotoxy(20,21);
    std::cout<<"Rows";
    gotoxy(40,21);
    std::cout<<":     "<<row;
}

void menu()
{
    do
    {
        char ch;
        box(90,25);
        gotoxy(30,5);
        std::cout<<"Welcome to the LIBRARY";
        gotoxy(29,7);
        std::cout<<"__________________________";
        gotoxy(35,9);
        std::cout<<"1. Add a book";
        gotoxy(35,11);
        std::cout<<"2. Search a book: ";
        gotoxy(35,13);
        std::cout<<"3. Display all books";
        gotoxy(35,15);
        std::cout<<"4. Credits";
        gotoxy(35,17);
        std::cout<<"5. See your record";
        gotoxy(35,19);
        std::cout<<"6. Exit";
        gotoxy(30,25);
        std::cout<<"Enter your choice: ";
        std::cin>>ch;

        switch(ch)
        {
            case '1':   char ch;
                        do
                        {
                            add_book();
                            gotoxy(25,15);
                            std::cout<<"Would you like to add more books(y/n): ";
                            ch=getch();
                        }while(ch=='y'||ch=='Y');
                        break;
            case '2': search_book();
                    break;
            case '3': display_all_records();
                    break;
            case '4': credits();
                        getch();
                        system("cls");
                        break;
            case '6':   Sleep(1000);
                        system("cls");
                        exit(0);
            case '5':   search_issue_records();
            getch();
                        break;
            default: gotoxy(25,22);
                     std::cout<<"Wrong choice! Please enter valid options!";
                     Sleep(2500);
        }
    }while(1);
}
void box(int box_length=90 , int box_height=25)
{
    int i,j;
    gotoxy(5,2);
    std::cout<<static_cast<char>(201);
    for(int i=1;i<=box_length;i++)
        std::cout<<static_cast<char>(205);
    std::cout<<static_cast<char>(187);
    for(i=1;i<=box_height;i++)
    {
        gotoxy(5,3+i-1);
        std::cout<<static_cast<char>(186);
        for(j=1;j<=box_length;j++)
        std::cout<<" ";
        std::cout<<static_cast<char>(186);
    }
    gotoxy(5,3+box_height);
    std::cout<<static_cast<char>(200);
    for(int i=1;i<=box_length;i++)
        std::cout<<static_cast<char>(205);
    std::cout<<static_cast<char>(188);
}

void add_book()
{
    BOOK book;
    system("cls");
    box(90,25);
    gotoxy(30,5);
    std::cout<<"Add a book to LIBRARY";
    gotoxy(29,7);
    std::cout<<"__________________________";
    gotoxy(15,9);
    std::cout<<"Book Name: ";
    gotoxy(30,9);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    gets(book.book_name);
    gotoxy(15,11);
    std::cout<<"Author/Writer: ";
    gotoxy(30,11);
    gets(book.author_name);
    gotoxy(15,13);
    std::cout<<"Publisher: ";
    gotoxy(30,13);
    gets(book.publisher);
    gotoxy(15,15);
    std::cout<<"Acc No: ";
    gotoxy(30,15);
    gets(book.acc_no);
    gotoxy(15,17);
    std::cout<<"Price: ";
    gotoxy(30,17);
    gets(book.price);
    gotoxy(15,19);
    std::cout<<"Copies: ";
    gotoxy(30,19);
    gets(book.copies);
    gotoxy(15,21);
    std::cout<<"Shelf No: ";
    gotoxy(30,21);
    gets(book.shelf);
    gotoxy(15,23);
    std::cout<<"Row No: ";
    gotoxy(30,23);
    gets(book.row);

    std::fstream f;
    f.open("BOOKS.dat",std::ios::out | std::ios::binary | std::ios::app);
    f.write((char *)&book , sizeof(book));
    system("cls");
    box(90,25);
    gotoxy(30,12);
    std::cout<<"Book added successfully!";
    f.close();
}

void search_book()
{
    char ch;
    system("cls");
    box(90,25);
    gotoxy(35,7);
    std::cout<<"SEARCH THE BOOK YOU NEED";
    gotoxy(34,8);
    std::cout<<"_________________________";
    gotoxy(35,11);
    std::cout<<"1. Search by Name";
    gotoxy(35,13);
    std::cout<<"2. Search by Acc No";
    gotoxy(35,17);
    std::cout<<"Enter your choice: ";
    std::cin>>ch;

    switch(ch)
    {
        case '1':   search_book_by_name();
                    break;
        case '2':   search_book_by_acc();
                    break;
        default:    std::cout<<"Invalid Case!";

    }
}

void search_book_by_name()
{
    std::fstream f,k;
    BOOK b,c;
    int i;
    char book[40];
    char ch;
    int record=0;
    int best_no_of_matched_keys=0;
    int best_match_record_no=0;
    gotoxy(10,20);
    std::cout<<"Enter the name of the book: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    gets(book);
    f.open("BOOKS.dat", std::ios::in | std::ios::binary);
    if(f==NULL)
    {
        std::cout<<"File opening error!";
        exit(-1);
    }
    while(f.read((char *)&b, sizeof(b)))
    {
        i=0;
        ++record;
        while(book[i]==b.book_name[i])
        {
            ++i;
        }
        if(i>best_no_of_matched_keys)
        {
            best_no_of_matched_keys=i;
            best_match_record_no=record;
        }
    }
    f.close();
    k.open("BOOKS.dat", std::ios::in | std::ios::out | std::ios::binary);
    k.seekg((best_match_record_no-1)*sizeof(c),std::ios::beg);
    k.read((char *)&c, sizeof(c));
    gotoxy(25,25);
    std::cout<<"Book found: "<<c.book_name;
    gotoxy(27,26);
    std::cout<<"Displaying records!";
    Sleep(2000);
    c.display_data();
    gotoxy(25,25);
    std::cout<<"Press 'i' to issue and 'e' to exit: ";
    ch=getch();
    if(ch=='i' || ch=='I')
        issue_book(c);
    f.close();
    k.close();
}

void search_book_by_acc()
{
    int task=0;
    std::fstream f;
    char searched_acc[100];
    BOOK obj;
    system("cls");
    box(90,25);
    gotoxy(30,17);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Enter Acc. No of book: ";
    gets(searched_acc);
    f.open("BOOKS.dat",std::ios::in | std::ios::binary);
    while(f.read((char *)&obj, sizeof(obj)))
    {
        if(strcmp(searched_acc,obj.acc_no)==0)
        {
            task=1;
            obj.display_data();
            getch();
        }
    }
    if(task!=1)
        std::cout<<"Book not found!";
        f.close();
}


void display_all_records()
{
    char needle;
    int record=0;
    std::fstream f;
    BOOK obj;
    f.open("BOOKS.dat", std::ios::in | std::ios::binary);
    if(!f)
    {
        std::cout<<"Books file not found!";
        return;
    }
    system("cls");
    box(90,25);
    while(f.read((char *)&obj, sizeof(obj)))
    {
        ++record;
        label:
        gotoxy(30,5);
        obj.display_data();
        gotoxy(27,27);
        std::cout<<"Enter 'n' for next,'p' for previous, 'i' for issue and 'e' for exit: ";
        needle=getche();
        lc:
        if(needle=='n' || needle=='N')
        {

            if((record+1)<=total_records_calculator())
            {

            }
            else
            {
                    gotoxy(6,27);
                    std::cout<<"This is the last record! Please press 'p' for previous and 'e' for exit";
                    needle=getche();
                    goto lc;
            }
        }
        else if(needle=='p' || needle=='P')
        {
            gotoxy(30,27);
            if((record-2)<0)
            {
                std::cout<<"It is the first book! Please press 'RETURN' to continue";
                getche();
            }

            else
            {
                f.seekg((record-2)*sizeof(obj) , std::ios::beg);
                record=record-2;
            }
        }
         else if(needle=='e' || needle=='E')
            return;

         else if(needle=='i' || needle=='I')
         {
             issue_book(obj);
         }

         else
            goto label;
    }
f.close();
}

int total_records_calculator()
{
    std::fstream f;
    BOOK obj;
    int count=0;
    f.open("BOOKS.dat", std::ios::in | std::ios::binary);
    if(f==NULL)
    {
        std::cout<<"Can't check for number of records!";
        exit(0);
    }
    while(f.read((char *)&obj, sizeof(obj)))
        ++count;
        f.close();
    return count;
}

void issue_book(BOOK obj)
{
    std::fstream f, f2;
    student si;
    f.open("ISSUE_RECORDS.dat", std::ios::out | std::ios::binary);
    f2.open("BOOKS.dat", std::ios::in | std::ios::out | std::ios::binary);
    if(f2==NULL)
    {
        std::cout<<"Books directory not found!";
        exit(0);
    }
    system("cls");
    box(90,25);
    gotoxy(7,5);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    gotoxy(35,9);
    std::cout<<std::setw(25)<<"Name of issuing person: ";
    gets(si.student_name);
    gotoxy(35,11);
    std::cout<<std::setw(25)<<"Student ID: ";
    gets(si.student_id);
    strcpy(si.book_issued,obj.book_name);
    system("cls");
    box(90,25);
    gotoxy(30,13);
    std::cout<<"Issuing book to your record...";
    gotoxy(20,15);
    for(int i=0;i<=50;i++)
    {
        std::cout<<static_cast<char>(219);
        Sleep(20);
    }
    f.write((char *)&si, sizeof(si));
    gotoxy(30,17);
    std::cout<<"Book successfully issued!";
    getch();
}

void search_issue_records()
{
    std::fstream f;
    student s;
    char s_id[10];
    system("cls");
    box(90,25);
    gotoxy(38,5);
    std::cout<<"SEARCH YOUR RECORD HERE";
    gotoxy(35,6);
    std::cout<<"============================";
    gotoxy(30,10);
    std::cout<<"Enter your Student ID: ";
    std::cin>>s_id;
    f.open("ISSUE_RECORDS.dat", std::ios::in | std::ios::binary);
    if(!f)
    {
        std::cout<<"Issue  register not found!";
        exit(-1);
    }
    while(f.read((char *)&s , sizeof(s)))
    {
        if(strcmp(s_id , s.student_id)==0)
        {
            display_issue_records(s);
        }
    }
    f.close();
}

void display_issue_records(student s)
{
    system("cls");
    box(90,25);
    gotoxy(30,5);
    std::cout<<"DISPLAYING THE RECORDS OF THE STUDENT";
    gotoxy(28,6);
    std::cout<<"========================================";
    gotoxy(35,11);
    std::cout<<"Name of student: "<<s.student_name;
    gotoxy(35,13);
    std::cout<<"Book issued: "<<s.book_issued;
    gotoxy(35,15);
    std::cout<<"Student ID: "<<s.student_id;
}

void credits()
{
    char ch;
    std::fstream f;
    system("cls");
    f.open("CREDITS.txt", std::ios::in);
    if(!f)
    {
        std::cout<<"Credits file not opening! Program is exiting!";
        Sleep(1000);
        exit(-1);
    }
    gotoxy(40,2);
    std::cout<<"CREDITS";
    gotoxy(39,3);
    std::cout<<"_________\n\n\n";
    while(!f.eof())
    {
        f.get(ch);
        std::cout<<ch;
        Sleep(10);
    }
}

void gotoxy (int x, int y)
{
    COORD coord;    // coordinates
    coord.X = x; coord.Y = y;    // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
