/**
 * Nguyễn Việt An - 20158002
 * Version 0.1 : Chưa chỉ ra được vị trí của lỗi
 * Version 0.1.1 : Chỉ ra dòng gây ra lỗi
 * Version 0.1.2 : In toàn bộ chương trình ra và dừng lại tại dòng sinh lỗi,  
 * định dạng không giống với chương trình ban đầu mà người dùng nhập vào
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "scanner.c"

// Declaration
void error(int errorType);
void factor();
void term();
void expression();
void condition();
void statement();
void block();
void program();

/*
 * New in Version 0.2
*/
void enter();
void location();
void checkIdent();
void getKind();
/*
 * End of new Ver 0.2
*/

void printPunc(int token)
{
  switch (token)
  {
  case 18:
    printf("+");
    break;
  case 19:
    printf("-");
    break;
  case 20:
    printf("*");
    break;
  case 21:
    printf("/");
    break;
  case 22:
    printf("=");
    break;
  case 23:
    printf("<>");
    break;
  case 24:
    printf("<");
    break;
  case 25:
    printf("<=");
    break;
  case 26:
    printf(">");
    break;
  case 27:
    printf(">=");
    break;
  case 28:
    printf("(");
    break;
  case 29:
    printf(")");
    break;
  case 30:
    printf("[");
    break;
  case 31:
    printf("]");
    break;
  case 32:
    printf(".");
    break;
  case 33:
    printf(",");
    break;
  case 34:
    printf(";");
    break;
  case 35:
    printf(":=");
    break;
  case 36:
    printf("%%");
    break;
  }
}

// Debug tool
void printToken()
{
  // Token = getToken();
  if (Token == NUMBER)
  {
    printf("%d", Num);
    if (Num > 999999)
    {
      error(37);
    }
  }
  else if (Token == IDENT)
  {
    printf("%s", Id);
  }
  else if (Token > 17 && Token < 37)
  {
    printPunc(Token);
  }
  else
  {
    printf("%s", Token_Tab[Token]);
  }
  Token = getToken();
}

void error(int errorType)
{
  printf("\nLine %d: ", lineNumber);
  switch (errorType)
  {
  case 1:
    printf("Error: Syntax Error");
    break;
    // Missing Keyword
  case 2:
    printf("Error: Missing keyword Begin");
    break;
  case 3:
    printf("Error: Missing keyword Call");
    break;
  case 4:
    printf("Error: Missing keyword Const");
    break;
  case 5:
    printf("Error: Missing keyword Do");
    break;
  case 6:
    printf("Error: Missing keyword End");
    break;
  case 7:
    printf("Error: Missing keyword Else");
    break;
  case 8:
    printf("Error: Missing keyword For");
    break;
  case 9:
    printf("Error: Missing keyword If");
    break;
  case 10:
    printf("Error: Missing keyword Odd");
    break;
  case 11:
    printf("Error: Missing keyword Procedure");
    break;
  case 12:
    printf("Error: Missing keyword Program");
    break;
  case 13:
    printf("Error: Missing keyword Then");
    break;
  case 14:
    printf("Error: Missing keyword To");
    break;
  case 15:
    printf("Error: Missing keyword Var");
    break;
  case 16:
    printf("Error: Missing keyword While");
    break;
  // Missing punctuation
  case 17:
    printf("Error: Missing punctuation Left-Parenthesis (");
    break;
  case 18:
    printf("Error: Missing punctuation Right-Parenthesis )");
    break;
  case 19:
    printf("Error: Missing punctuation Left-Bracket [");
    break;
  case 20:
    printf("Error: Missing punctuation Right-Bracket ]");
    break;
  case 21:
    printf("Error: Missing punctuation Comma ,");
    break;
  case 22:
    printf("Error: Missing punctuation Semicolon ;");
    break;
  case 23:
    printf("Error: Missing punctuation Period .");
    break;
  case 24:
    printf("Error: Missing punctuation Equal =");
    break;
  // Missing operator
  case 25:
    printf("Error: Missing operator Assign :=");
    break;
  // Missing operand
  case 30:
    printf("Error: Missing operand");
    break;
  // Missing name
  case 31:
    printf("Error: Missing program name");
    break;
  case 32:
    printf("Error: Missing constant name");
    break;
  case 33:
    printf("Error: Missing variable name");
    break;
  case 34:
    printf("Error: Missing procedure name");
    break;
  // Miscs
  case 35:
    printf("Error: Missing range number");
    break;
  case 36:
    printf("Error: Missing parameter name");
    break;
  case 37:
    printf("Error: Number exceed limit");
    break;
  default:
    printf("Error: Syntax Error");
    break;
  }
  printf("\n");
  exit(-1);
}

void factor()
{
  if (Token == IDENT)
  {
    printToken();
    if (Token == LBRACK)
    {
      printToken();
      expression();
      if (Token == RBRACK)
      {
        printToken();
      }
      else
      {
        error(20);
      }
    }
  }
  else if (Token == NUMBER)
  {
    printToken();
  }
  else if (Token == LPARENT)
  {
    printToken();
    expression();
    if (Token == RPARENT)
    {
      printToken();
    }
    else
    {
      error(18);
    }
  }
  else
  {
    error(1);
  }
}

void term()
{
  factor();
  while (Token == TIMES || Token == SLASH || Token == PERCENT)
  {
    printToken();
    factor();
  }
}

void expression()
{
  if (Token == PLUS || Token == MINUS)
  {
    printToken();
  }
  term();
  while (Token == PLUS || Token == MINUS)
  {
    printToken();
    term();
  }
}

void condition()
{
  if (Token == ODD)
  {
    printToken();
    expression();
  }
  else
  {
    expression();
    if (Token == EQU || Token == NEQ || Token == LSS || Token == LEQ || Token == GTR || Token == GEQ)
    {
      printToken();
      expression();
    }
    else
    {
      error(1);
    }
  }
}

void statement()
{
  if (Token == IDENT)
  {
    printToken();
    if (Token == LBRACK)
    {
      printToken();
      expression();
      if (Token == RBRACK)
      {
        printToken();
      }
      else
      {
        error(20);
      }
    }
    if (Token == ASSIGN)
    {
      printToken();
      expression();
    }
    else
    {
      error(25);
    }
  }
  if (Token == CALL)
  {
    printToken();
    if (Token == IDENT)
    {
      printToken();
      if (Token == LPARENT)
      {
        printToken();
        expression();
        while (Token == COMMA)
        {
          printToken();
          expression();
        }
        if (Token == RPARENT)
        {
          printToken();
        }
        else
        {
          error(18);
        }
      }
    }
    else
    {
      error(34);
    }
  }
  if (Token == BEGIN)
  {
    printToken();
    statement();
    while (Token == SEMICOLON)
    {
      printToken();
      statement();
    }
    if (Token == END)
    {
      printToken();
    }
    else
    {
      error(6);
    }
  }
  if (Token == IF)
  {
    printToken();
    condition();
    if (Token == THEN)
    {
      printToken();
      statement();
      if (Token == ELSE)
      {
        printToken();
        statement();
      }
    }
    else
    {
      error(13);
    }
  }
  if (Token == WHILE)
  {
    printToken();
    condition();
    if (Token == DO)
    {
      printToken();
      statement();
    }
    else
    {
      error(5);
    }
  }
  if (Token == FOR)
  {
    printToken();
    if (Token == IDENT)
    {
      printToken();
      if (Token == ASSIGN)
      {
        printToken();
        expression();
        if (Token == TO)
        {
          printToken();
          expression();
          if (Token == DO)
          {
            printToken();
            statement();
          }
          else
          {
            error(5);
          }
        }
        else
        {
          error(14);
        }
      }
      else
      {
        error(25);
      }
    }
    else
    {
      error(33);
    }
  }
}

void block()
{
  while (Token == CONST || Token == VAR || Token == PROCEDURE)
  {
    while (Token == CONST)
    {
      printToken();
      if (Token == IDENT)
      {
        printToken();
        if (Token == EQU)
        {
          printToken();
          if (Token == NUMBER)
          {
            printToken();
            while (Token == COMMA)
            {
              printToken();
              if (Token == IDENT)
              {
                printToken();
                if (Token == EQU)
                {
                  printToken();
                  if (Token == NUMBER)
                  {
                    printToken();
                  }
                  else
                  {
                    error(30);
                  }
                }
                else
                {
                  error(24);
                }
              }
              else
              {
                error(32);
              }
            }
            if (Token == SEMICOLON)
            {
              printToken();
            }
            else
            {
              error(22);
            }
          }
          else
          {
            error(30);
          }
        }
        else
        {
          error(24);
        }
      }
      else
      {
        error(32);
      }
    }
    while (Token == VAR)
    {
      printToken();
      if (Token == IDENT)
      {
        printToken();
        if (Token == LBRACK)
        {
          printToken();
          if (Token == NUMBER)
          {
            printToken();
            if (Token == RBRACK)
            {
              printToken();
            }
            else
            {
              error(20);
            }
          }
          else
          {
            error(35);
          }
        }
        while (Token == COMMA)
        {
          printToken();
          if (Token == IDENT)
          {
            printToken();
            if (Token == LBRACK)
            {
              printToken();
              if (Token == NUMBER)
              {
                printToken();
                if (Token == RBRACK)
                {
                  printToken();
                }
                else
                {
                  error(20);
                }
              }
              else
              {
                error(35);
              }
            }
          }
          else
          {
            error(33);
          }
        }
        if (Token == SEMICOLON)
        {
          printToken();
        }
        else
        {
          error(22);
        }
      }
      else
      {
        error(33);
      }
    }
    while (Token == PROCEDURE)
    {
      printToken();
      if (Token == IDENT)
      {
        printToken();
        if (Token == LPARENT)
        {
          printToken();
          if (Token == VAR)
          {
            printToken();
          }
          if (Token == IDENT)
          {
            printToken();
            while (Token == SEMICOLON)
            {
              printToken();
              if (Token == VAR)
              {
                printToken();
              }
              if (Token == IDENT)
              {
                printToken();
              }
              else
              {
                error(36);
              }
            }
            if (Token == RPARENT)
            {
              printToken();
            }
            else
            {
              error(18);
            }
          }
          else
          {
            error(36);
          }
        }
        if (Token == SEMICOLON)
        {
          printToken();
        }
        else
        {
          error(22);
        }
        block();
        if (Token == SEMICOLON)
        {
          printToken();
        }
        else
        {
          error(22);
        }
      }
      else
      {
        error(34);
      }
    }
  }

  if (Token == BEGIN)
  {
    printToken();
    statement();
    while (Token == SEMICOLON)
    {
      printToken();
      statement();
    }
    if (Token == END)
    {
      printToken();
    }
    else
    {
      error(6);
    }
  }
}

void program()
{
  if (Token == PROGRAM)
  {
    printToken();
    if (Token == IDENT)
    {
      printToken();
      if (Token == SEMICOLON)
      {
        printToken();
        block();
        if (Token == PERIOD)
        {
          printToken();
          printf("\nSuccessful!\n");
        }
        else
        {
          error(23);
        }
      }
      else
      {
        error(22);
      }
    }
    else
    {
      error(31);
    }
  }
  else
  {
    error(12);
  }
}