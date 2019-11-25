#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "scanner.h"

FILE *f;
char Ch;

TokenType Token;            //Token nhận dạng được
int Num;                    //Từ vựng khi Token là NUMBER
char Id[MAX_IDENT_LEN + 1]; //Từ vựng khi Token là IDENT
int lineNumber = 1;

TokenType checkKeywork(char *Id)
{
  int i = 0;
  for (i = 0; i < 15; i++)
  {
    if (strcmp(Id, KW_TAB[i].KW) == 0)
      return KW_TAB[i].KW_TOKEN;
  }
  return IDENT;
}

char getCh()
{
  return toupper(fgetc(f));
}

TokenType getToken()
{
  while (Ch == ' ' || Ch == '\t' || Ch == '\n')
  {
    if (Ch == '\n')
    {
      ++lineNumber;
    }
    printf("%c", Ch);
    Ch = getCh();
  }
  if (isalpha(Ch))
  {
    int l = 0;
    do
    {
      if (l < MAX_IDENT_LEN)
        Id[l++] = Ch;
      Ch = getCh();
    } while (isalpha(Ch) || isdigit(Ch));
    Id[l] = '\0';
    return checkKeywork(Id);
  }
  else if (isdigit(Ch))
  {
    Num = 0;
    do
    {
      Num = 10 * Num + Ch - 48;
      Ch = getCh();
    } while (isdigit(Ch));
    return NUMBER;
  }
  else if (Ch == ':')
  {
    Ch = getCh();
    if (Ch == '=')
    {
      Ch = getCh();
      return ASSIGN;
    }
    else
      return NONE;
  }
  else if (Ch == '+')
  {
    Ch = getCh();
    return PLUS;
  }
  else if (Ch == '-')
  {
    Ch = getCh();
    return MINUS;
  }
  else if (Ch == '*')
  {
    Ch = getCh();
    return TIMES;
  }
  else if (Ch == '/')
  {
    Ch = getCh();
    return SLASH;
  }
  else if (Ch == '=')
  {
    Ch = getCh();
    return EQU;
  }
  else if (Ch == '<')
  {
    Ch = getCh();
    if (Ch == '=')
    {
      Ch = getCh();
      return LEQ;
    }
    else if (Ch == '>')
    {
      Ch = getCh();
      return NEQ;
    }
    return LSS;
  }
  else if (Ch == '>')
  {
    Ch = getCh();
    if (Ch == '=')
    {
      Ch = getCh();
      return GEQ;
    }
    return GTR;
  }
  else if (Ch == ';')
  {
    Ch = getCh();
    return SEMICOLON;
  }
  else if (Ch == '.')
  {
    Ch = getCh();
    return PERIOD;
  }
  else if (Ch == ',')
  {
    Ch = getCh();
    return COMMA;
  }
  else if (Ch == '%')
  {
    Ch = getCh();
    return PERCENT;
  }
  else if (Ch == '(')
  {
    Ch = getCh();
    return LPARENT;
  }
  else if (Ch == ')')
  {
    Ch = getCh();
    return RPARENT;
  }
  else if (Ch == '[')
  {
    Ch = getCh();
    return LBRACK;
  }
  else if (Ch == ']')
  {
    Ch = getCh();
    return RBRACK;
  }
  else
    return NONE;
}