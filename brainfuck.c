#include <stdio.h>

//Fonction "parse" qui permet d'interpréter le code en brainfuck.
//Elle prend en paramètre la chaine de caractère et la mémoire.
void parse(char *expr, int *mem)
{
    int loop_count = 0;                             //On initie le nombre de boucles à zéro.

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

            case ']':                               //Quand on atteint la fin d'une boucle,
                if (*mem)                           //Si le poineur " n'est pas nul "
                {
                    loop_count = 1;                 //Par défault le nombre de boucle est 1
                    char c;

                    while (loop_count > 0)          //Tant que on est dans une boucle
                    {
                        c = *(--expr);              //Le caractère est le précédent         

                        if (c == '[')               //Si on atteint le début d'une boucle, on enlève 1 au compteur
                        {
                            loop_count--;
                        }
                        else if (c == ']')          //Si on atteint la fin d'une boucle, on l'incrémente
                        {
                            loop_count++;
                        }
                    }
                }

                                            break;
            
            default:                        break;  //Par défaut, on ne fais rien
        }
        ++expr;                                     //On avance
    }
}

int main()
{
    int memory[3000];
    char *expr = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    
    //char *expr = "+++[> +++ [.-] <-]"; // <--- Exemple de boucle imbriquée
    parse(expr, memory);
}