#include <stdio.h>

//Fonction "parse" qui permet d'interpréter le code en brainfuck.
//Elle prend en paramètre la chaine de caractère et la mémoire.
void parse(char *expr, int *mem)
{
    while (*expr)                                   //Tant que nous ne somme pas à la fin de la chaîne
    {
        switch (*expr)                              //Switch sur le caractère
        {
            case '>':   ++mem;              break;  //On incrémente le pointeur
            case '<':   --mem;              break;  //On décrémente le pointeur
            case '+':   ++(*mem);           break;  //On incrémente la VALEURE du pointeur
            case '-':   --(*mem);           break;  //On décréménte la VALEURE du pointeur
            case '.':   putchar(*mem);      break;  //On affiche le caractère de la valeure pointée
            case ',':   (*mem) = getchar(); break;  //On met le caractère de la valeure pointée

            case ']':                               //Si on atteint une fin de boucle,
                if (*mem)                           //Et que *ptr
                {
                    while (*expr != '[')            //On va reculer jusqu'à trouver le début de la boucle
                    {
                        --expr;
                    }
                }
                                            break;
            
            default:                        break;
        }
        ++expr;                                     //On avance
    }
}

int main()
{
    int memory[3000];
    char *expr = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    parse(expr, memory);
}