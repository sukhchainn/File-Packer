#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lexer.h"

void tokenizer(FILE *file)
{
    FILE *fp = fopen("tokens.txt", "w");
    char ch, buff[250];
    bool flag;
    int buff_count = 0, line_no = 1, char_pos = 0;

    // breaking strings into tokens
    while(ch != EOF)
    {
        ch = getc(file);
        char_pos++;
        printf("%c", ch);

        if (ch == '\n')
        {
            line_no++;
            char_pos = 0;
        }

        // check if it's a character or just a whitespace
        flag = (ch == ' ' || ch == '\t' || ch == '\n' || ch == EOF) ? 0 : 1;

        // if it's a character then put it in the token buffer 
        // else just put it in the token file and clear the buffer
        if (flag == true)
        {
            buff[buff_count] = ch;
            buff_count++;
        } else {
            buff[buff_count] = '\0';
            fprintf(fp, "token: %s %d:%d\n", buff, line_no, char_pos);
            buff_count = 0;
        }
    }

    if (feof(file))
        printf("\n End of file reached.\n");
    else
        printf("\n Something went wrong.\n");

    fclose(fp);
    //return tokens;
}
