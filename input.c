#include <stdio.h>
#include <stdlib.h>
#include "input.h"
void init_input(Input *I)
{
    I->left = 0;
    I->right = 0;
    I->down = 0;
    I->jump = 0;
    I->attack = 0;
    I->e = 0; 
    I->btn_right = 0;
    I->btn_left = 0;
    I->btn_jump = 0;
}
