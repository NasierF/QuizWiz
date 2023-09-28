
#ifndef Flash_Cards
#define Flash_Cards 

void FlashCards();
void PrintCentered(const char *string);
void ClearKeyboardBuffer();

struct question 
{
    char myQuestion[150];
};
struct answer 
{
    char myAnswer[100];
};

#endif