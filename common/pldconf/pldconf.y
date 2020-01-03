
%{
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

extern int yyerror(char*);
extern int yylex();
%}

%token DEVICE_FAMILY
%token MAX7000S

%token DEVICE_TYPE
%token EPM7032S

%token PACKAGE_TYPE
%token PLCC

%token PACKAGE_PIN_COUNT
%token SPEED_GRADE
%token ISP_VIA_JTAG_ENABLED
%token JTAG_BST_ENABLED
%token READBACK_PROTECTION_ENABLED

%token LAB
%token LOGIC_CELL
%token DOT
%token EQUALS
%token SEMICOLON

%token REGISTER_BYPASS
%token FAST_INPUT_SELECT

%token CLOCK_AND_ENABLE_SELECT
%token GLOBAL_CLOCK_AND_LOCAL_ENABLE

%token GLOBAL_CLOCK_SELECT
%token GCLK1
%token GCLK2

%token CLEAR_SELECT
%token GLOBAL_CLEAR
%token PRODUCT_TERM

%token XOR_ENABLE

%token NUMBER
%token BOOL

%%

assignment_list:
    | assignment
    | assignment_list assignment
    ;

assignment:
	| key EQUALS value SEMICOLON { printf("register_assignment\n"); }
	;

key
	: top_level_property
	| LOGIC_CELL DOT logic_cell_property
	;

top_level_property
	: DEVICE_FAMILY
	| DEVICE_TYPE
	| PACKAGE_TYPE
	| PACKAGE_PIN_COUNT
	| SPEED_GRADE
	| ISP_VIA_JTAG_ENABLED
	| JTAG_BST_ENABLED
	| READBACK_PROTECTION_ENABLED
	;

logic_cell_property
	: REGISTER_BYPASS
	| FAST_INPUT_SELECT
	| CLOCK_AND_ENABLE_SELECT
	| GLOBAL_CLOCK_SELECT
	| CLEAR_SELECT
	| XOR_ENABLE
	;

device_family_enum: MAX7000S;
device_type_enum: EPM7032S;
package_type_enum: PLCC;
clock_and_enable_select_enum
	: GLOBAL_CLOCK_AND_LOCAL_ENABLE
	| PRODUCT_TERM
	;

value
	: NUMBER
	| BOOL
	| device_family_enum
	| device_type_enum
	| package_type_enum
	| clock_and_enable_select_enum
	;

%%

void main()
{
	yyparse();
}
