#include "global.h"
#include "UI.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    UI session;
    session.StartWindow();
    return 0;
}