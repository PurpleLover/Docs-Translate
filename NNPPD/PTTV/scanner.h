#define MAX_IDENT_LEN 10
#define MAX_keywork 15

typedef enum
{ //Các lo_i Token ___c s_ d_ng trong PL/0
	NONE = 0,
	IDENT,
	NUMBER,
	BEGIN,
	CALL,
	CONST,
	DO,
	ELSE,
	END,
	FOR,
	IF,
	ODD,
	PROCEDURE,
	PROGRAM,
	THEN,
	TO,
	VAR,
	WHILE,
	PLUS,
	MINUS,
	TIMES,
	SLASH,
	EQU,
	NEQ,
	LSS,
	LEQ,
	GTR,
	GEQ,
	LPARENT,
	RPARENT,
	LBRACK,
	RBRACK,
	PERIOD,
	COMMA,
	SEMICOLON,
	ASSIGN,
	PERCENT
} TokenType;

char Token_Tab[][15] = { //Các lo_i Token ___c s_ d_ng trong PL/0
		"NONE", "IDENT", "NUMBER",
		"BEGIN", "CALL", "CONST", "DO", "ELSE", "END", "FOR", "IF", "ODD",
		"PROCEDURE", "PROGRAM", "THEN", "TO", "VAR", "WHILE",
		"PLUS", "MINUS", "TIMES", "SLASH", "EQU", "NEQ", "LSS", "LEQ", "GTR", "GEQ", "LPARENT", "RPARENT", "LBRACK", "RBRACK", "PERIOD", "COMMA", "SEMICOLON", "ASSIGN", "PERCENT"};

struct
{
	char KW[10];
	TokenType KW_TOKEN;
} KW_TAB[] = {
		{"BEGIN", BEGIN},
		{"END", END},
		{"PROGRAM", PROGRAM},
		{"THEN", THEN},
		{"WHILE", WHILE},
		{"DO", DO},
		{"CALL", CALL},
		{"ODD", ODD},
		{"TO", TO},
		{"CONST", CONST},
		{"VAR", VAR},
		{"PROCEDURE", PROCEDURE},
		{"ELSE", ELSE},
		{"FOR", FOR},
		{"IF", IF}};