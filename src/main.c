#include <sys/lcd.h>
#include <keypadc.h>
#include <string.h>
#include <ti/getcsc.h>
#include <ti/screen.h>
#include <stdlib.h>

/* Function Prototypes */
void FillScreen(uint8_t color);
struct question 
{
    char myQuestion[200];
};
struct answer 
{
    char myAnswer[200];
};

int main(void)
{
    int count = 0;
    struct question questions[2];
    struct answer answers[2];
    
    // Set the initial questions and answers
    strcpy(questions[0].myQuestion, "A(n) ___ bond is formed when atoms share electrons?");
    strcpy(answers[0].myAnswer, "Covalent");
    
    strcpy(questions[1].myQuestion, "the process by which one molecule is separated into two by the addition of a water molecule is called ___?");
    strcpy(answers[1].myAnswer, "Hydrolysis");

    
    os_ClrHome();
    os_PutStrFull("A(n) ___ bond is formed when atoms share electrons?");
    os_NewLine();
    os_PutStrFull("Hello World.");
    /* Key variable */
    // kb_key_t key;
    /* Loop until 2nd is pressed */
    do
    {
        /* Update kb_Data */
        kb_Scan();
    if(kb_Data[3] == kb_7)
    {
        count--;
        if(count < 0)
        {
            count = 0;
        }
        os_ClrHome();
        os_PutStrFull("The question is:");
        os_NewLine();
        os_PutStrFull(questions[count].myQuestion);
    }
    else if(kb_Data[4] == kb_8)
    {
        os_ClrHome();
        os_PutStrFull("The answer is:");
        os_NewLine();
        os_PutStrFull(answers[count].myAnswer);
    }
    else if(kb_Data[5]== kb_9)
    {
        count++;
        if(count >=2)
        {
            count = 1;
        }
        os_ClrHome();
        os_PutStrFull("The question is:");
        os_NewLine();
        os_PutStrFull(questions[count].myQuestion);
        
    }


    } while (kb_Data[1] != kb_2nd);

    return 0;
}

/* Simple way to fill the screen with a given color */
void FillScreen(uint8_t color)
{
    memset((void*)lcd_Ram, color, LCD_SIZE);
}