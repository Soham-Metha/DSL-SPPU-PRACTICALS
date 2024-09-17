#include <iostream>
using namespace std;

void Horzbound(int16_t n)
{
    printf("\t\t  ✖ ");
    for (int16_t i = 0; i < n; i++)
        printf("───");
    printf(" ✖ \n");
}
void showScreen(int16_t n)
{
    printf("\n\n\t ✖ ");
    for (int16_t i = 0; i < n * 2; i++)
        printf(" ✖ ");
    printf("\n\n\t\t\t SCREEN HERE\n\n");
}
void printStyled(const char str[])
{
    cout << "\033[1;" << str;
}

void endStyled()
{
    cout << "\033[0m";
}
