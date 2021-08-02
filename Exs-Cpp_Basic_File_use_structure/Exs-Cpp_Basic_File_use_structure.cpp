
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

int choise,i,m,elements;
void SelectFile();
void DisplayFile();
void DispElement();
void AddStruct();
void SelectNewFile();
int quit();
FILE* orgFile;
struct MyStruct
{
    int number;
    char type[15];
    char text[100];
};
MyStruct initFile[100];

int main()
{    
    
    printf("\n---------File with structure----------\n");
    printf("\nThe File contains structure of elements:\n- Number\n- Type\n- Text\n\n---------------------------------------\n");
    printf("\nChoose from the menu.\n");
    do {
        printf("\n1 Load a file.\n2 Display the file.\n3 Display exact element from the structures.\n4 Load new file.\n5 quit\n");
        printf("\nChoise: "); scanf_s("%d", &choise);
        switch (choise)
        {
        case 1: SelectFile(); break;
        case 2: DisplayFile(); break;
        case 3: DispElement(); break;
        case 4: AddStruct(); break;
        case 5: SelectNewFile(); break;
        case 6: quit(); break;
        default: printf("\nChoose from 1 to 6\n"); break;
        };
    }
    while (choise != 6);
};

void SelectFile()
{
    errno_t err;
    char nameFile[10];
    std::cout << "\nSelect the file you want to use.\nChoose between File.txt and File2.txt\n";
    std::cin >> nameFile;
    err = fopen_s(&orgFile, nameFile, "r");
    if (err == 0)
    {
       printf("\nFile selected: %s\n", nameFile);
       for (;;) {
           char arrFile[200];
           fgets(arrFile, 200, orgFile);
           if (arrFile[0] == '.') break;
           initFile[i].number = atoi(arrFile);
           fgets(arrFile, 200, orgFile);
           strcpy_s(initFile[i].type, arrFile);
           fgets(arrFile, 200, orgFile);
           strcpy_s(initFile[i].text, arrFile);
           elements = i + 1;
           i = i + 1;
       };
       std::cout << "File initialized.\n";
       printf("\nNumber of structures in the file: %d\n", elements);
    }
    else
    {
        printf("\nNo such file.\n");
    };
};

void DisplayFile()
{ 
    for (i=0;i<elements;i++)
    {
        printf("\n%d\n%s%s", initFile[i].number, initFile[i].type, initFile[i].text);
    };
};

void DispElement()
{
    int el;
    do{
        std::cout << "Element to display:\n1 numer\n2 type\n3 text\n";
        std::cin >> el;
        switch (el)
        {
        case 1: for (i = 0; i < elements; i++) printf("%d\n", initFile[i].number); break;
        case 2: for (i = 0; i < elements; i++) printf("%s", initFile[i].type); std::cout << "\n"; break;
        case 3: for (i = 0; i < elements; i++) printf("%s", initFile[i].text); std::cout << "\n"; break;
        default: printf("\nChoose from 1 to 3\n"); break;
        };
     }
    while (el < 1 || el>3);
 };

void AddStruct()
{
    fclose(orgFile);
    fopen(orgFile, "r+");
};

void SelectNewFile()
{
    errno_t err;
    err = fclose(orgFile);
    if (err==0)
    {
        std::cout << "\nFile closed.\nSelect 1 from the menu.";
    }
    delete initFile; /* Throws exeption.Searching for solution.Intent: 
    Clear the initFile srtucture array so can be repopulated with the elements from the next file.
    Currently the program appends in the structure array the elements from the 2nd opened file after the elements from the first.
    */
};

int quit()
{
    std::cout << "\nquake :D\n"; fclose(orgFile); return 0;
};