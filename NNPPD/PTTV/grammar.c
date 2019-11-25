/**
 * Nguyễn Việt An - 20158002
 * Version 0.1 : Chưa chỉ ra được vị trí của lỗi
 * Version 0.1.1 : Chỉ ra dòng gây ra lỗi
 * Version 0.1.2 : In toàn bộ chương trình ra và dừng lại tại dòng sinh lỗi,  
 * định dạng không giống với chương trình ban đầu mà người dùng nhập vào
 * Version 0.1.3 : Dùng constant và enum thay thế cho các số báo lỗi hoặc TokenType
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "scanner.c"
#include "grammar.h"

#define MAX_NUMBER_LIMIT 999999

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
  case PLUS:
    printf("+");
    break;
  case MINUS:
    printf("-");
    break;
  case TIMES:
    printf("*");
    break;
  case SLASH:
    printf("/");
    break;
  case EQU:
    printf("=");
    break;
  case NEQ:
    printf("<>");
    break;
  case LSS:
    printf("<");
    break;
  case LEQ:
    printf("<=");
    break;
  case GTR:
    printf(">");
    break;
  case GEQ:
    printf(">=");
    break;
  case LPARENT:
    printf("(");
    break;
  case RPARENT:
    printf(")");
    break;
  case LBRACK:
    printf("[");
    break;
  case RBRACK:
    printf("]");
    break;
  case PERIOD:
    printf(".");
    break;
  case COMMA:
    printf(",");
    break;
  case SEMICOLON:
    printf(";");
    break;
  case ASSIGN:
    printf(":=");
    break;
  case PERCENT:
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
    if (Num > MAX_NUMBER_LIMIT)
    {
      error(NUMBER_EXCEED_LIMIT);
    }
  }
  else if (Token == IDENT)
  {
    printf("%s", Id);
  }
  else if (Token >= PLUS && Token <= PERCENT)
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
  case SYNTAX_ERROR:
    printf("Error: Syntax Error");
    break;
    // Missing Keyword
  case MISSING_KEYWORD_BEGIN:
    printf("Error: Missing keyword Begin");
    break;
  case MISSING_KEYWORD_CALL:
    printf("Error: Missing keyword Call");
    break;
  case MISSING_KEYWORD_CONST:
    printf("Error: Missing keyword Const");
    break;
  case MISSING_KEYWORD_DO:
    printf("Error: Missing keyword Do");
    break;
  case MISSING_KEYWORD_END:
    printf("Error: Missing keyword End");
    break;
  case MISSING_KEYWORD_ELSE:
    printf("Error: Missing keyword Else");
    break;
  case MISSING_KEYWORD_FOR:
    printf("Error: Missing keyword For");
    break;
  case MISSING_KEYWORD_IF:
    printf("Error: Missing keyword If");
    break;
  case MISSING_KEYWORD_ODD:
    printf("Error: Missing keyword Odd");
    break;
  case MISSING_KEYWORD_PROCEDURE:
    printf("Error: Missing keyword Procedure");
    break;
  case MISSING_KEYWORD_PROGRAM:
    printf("Error: Missing keyword Program");
    break;
  case MISSING_KEYWORD_THEN:
    printf("Error: Missing keyword Then");
    break;
  case MISSING_KEYWORD_TO:
    printf("Error: Missing keyword To");
    break;
  case MISSING_KEYWORD_VAR:
    printf("Error: Missing keyword Var");
    break;
  case MISSING_KEYWORD_WHILE:
    printf("Error: Missing keyword While");
    break;
  // Missing punctuation
  case MISSING_PUNCTUATION_LEFT_PARENTHESIS:
    printf("Error: Missing punctuation Left-Parenthesis (");
    break;
  case MISSING_PUNCTUATION_RIGHT_PARENTHESIS:
    printf("Error: Missing punctuation Right-Parenthesis )");
    break;
  case MISSING_PUNCTUATION_LEFT_BRACKET:
    printf("Error: Missing punctuation Left-Bracket [");
    break;
  case MISSING_PUNCTUATION_RIGHT_BRACKET:
    printf("Error: Missing punctuation Right-Bracket ]");
    break;
  case MISSING_PUNCTUATION_COMMA:
    printf("Error: Missing punctuation Comma ,");
    break;
  case MISSING_PUNCTUATION_SEMICOLON:
    printf("Error: Missing punctuation Semicolon ;");
    break;
  case MISSING_PUNCTUATION_PERIOD:
    printf("Error: Missing punctuation Period .");
    break;
  case MISSING_PUNCTUATION_EQUAL:
    printf("Error: Missing punctuation Equal =");
    break;
  // Missing operator
  case MISSING_OPERATOR_ASSIGN:
    printf("Error: Missing operator Assign :=");
    break;
  // Missing operand
  case MISSING_OPERAND:
    printf("Error: Missing operand");
    break;
  // Missing name
  case MISSING_PROGRAM_NAME:
    printf("Error: Missing program name");
    break;
  case MISSING_CONSTANT_NAME:
    printf("Error: Missing constant name");
    break;
  case MISSING_VARIABLE_NAME:
    printf("Error: Missing variable name");
    break;
  case MISSING_PROCEDURE_NAME:
    printf("Error: Missing procedure name");
    break;
  // Miscs
  case MISSING_RANGE_NUMBER:
    printf("Error: Missing range number");
    break;
  case MISSING_PARAMETER_NAME:
    printf("Error: Missing parameter name");
    break;
  case NUMBER_EXCEED_LIMIT:
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
        error(MISSING_PUNCTUATION_RIGHT_BRACKET);
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
      error(MISSING_PUNCTUATION_RIGHT_PARENTHESIS);
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
        error(MISSING_PUNCTUATION_RIGHT_BRACKET);
      }
    }
    if (Token == ASSIGN)
    {
      printToken();
      expression();
    }
    else
    {
      error(MISSING_OPERATOR_ASSIGN);
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
          error(MISSING_PUNCTUATION_RIGHT_PARENTHESIS);
        }
      }
    }
    else
    {
      error(MISSING_PROCEDURE_NAME);
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
      error(MISSING_KEYWORD_END);
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
      error(MISSING_KEYWORD_THEN);
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
      error(MISSING_KEYWORD_DO);
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
            error(MISSING_KEYWORD_DO);
          }
        }
        else
        {
          error(MISSING_KEYWORD_TO);
        }
      }
      else
      {
        error(MISSING_OPERATOR_ASSIGN);
      }
    }
    else
    {
      error(MISSING_VARIABLE_NAME);
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
                    error(MISSING_OPERAND);
                  }
                }
                else
                {
                  error(MISSING_PUNCTUATION_EQUAL);
                }
              }
              else
              {
                error(MISSING_CONSTANT_NAME);
              }
            }
            if (Token == SEMICOLON)
            {
              printToken();
            }
            else
            {
              error(MISSING_PUNCTUATION_SEMICOLON);
            }
          }
          else
          {
            error(MISSING_OPERAND);
          }
        }
        else
        {
          error(MISSING_PUNCTUATION_EQUAL);
        }
      }
      else
      {
        error(MISSING_CONSTANT_NAME);
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
              error(MISSING_PUNCTUATION_RIGHT_BRACKET);
            }
          }
          else
          {
            error(MISSING_RANGE_NUMBER);
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
                  error(MISSING_PUNCTUATION_RIGHT_BRACKET);
                }
              }
              else
              {
                error(MISSING_RANGE_NUMBER);
              }
            }
          }
          else
          {
            error(MISSING_VARIABLE_NAME);
          }
        }
        if (Token == SEMICOLON)
        {
          printToken();
        }
        else
        {
          error(MISSING_PUNCTUATION_SEMICOLON);
        }
      }
      else
      {
        error(MISSING_VARIABLE_NAME);
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
                error(MISSING_PARAMETER_NAME);
              }
            }
            if (Token == RPARENT)
            {
              printToken();
            }
            else
            {
              error(MISSING_PUNCTUATION_RIGHT_PARENTHESIS);
            }
          }
          else
          {
            error(MISSING_PARAMETER_NAME);
          }
        }
        if (Token == SEMICOLON)
        {
          printToken();
        }
        else
        {
          error(MISSING_PUNCTUATION_SEMICOLON);
        }
        block();
        if (Token == SEMICOLON)
        {
          printToken();
        }
        else
        {
          error(MISSING_PUNCTUATION_SEMICOLON);
        }
      }
      else
      {
        error(MISSING_PROCEDURE_NAME);
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
      error(MISSING_KEYWORD_END);
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
          error(MISSING_PUNCTUATION_PERIOD);
        }
      }
      else
      {
        error(MISSING_PUNCTUATION_SEMICOLON);
      }
    }
    else
    {
      error(MISSING_PROGRAM_NAME);
    }
  }
  else
  {
    error(MISSING_KEYWORD_PROGRAM);
  }
}