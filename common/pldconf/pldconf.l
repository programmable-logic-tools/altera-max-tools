
%option noyywrap
%option nodefault
%option yylineno
%option case-insensitive

%{
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "pldconf.tab.h"

int yyerror(char *s);

int oldstate;
%}

%x COMMENT

%%

"device_family" { printf("DEVICE_FAMILY "); return DEVICE_FAMILY; }
"max7000s"      { return MAX7000S; }

"device_type"   { return DEVICE_TYPE; }
"epm7032s"      { return EPM7032S; }

"package_type"  { return PACKAGE_TYPE; }
"plcc"          { return PLCC; }

"package_pin_count"             { return PACKAGE_PIN_COUNT; }
"speed_grade"                   { return SPEED_GRADE; }
"isp_via_jtag_enabled"          { return ISP_VIA_JTAG_ENABLED; }
"jtag_bst_enabled"              { return JTAG_BST_ENABLED; }
"readback_protection_enabled"   { return READBACK_PROTECTION_ENABLED; }

"lab["[a-hA-H]"]"          { return LAB; }
"logic_cell["[0-9]+"]"     { return LOGIC_CELL; }

"register_bypass"          { return REGISTER_BYPASS; }
"fast_input_select"        { return FAST_INPUT_SELECT; }

"clock_and_enable_select"       { return CLOCK_AND_ENABLE_SELECT; }
"global_clock_and_local_enable" { return GLOBAL_CLOCK_AND_LOCAL_ENABLE; }

"global_clock_select"      { return GLOBAL_CLOCK_SELECT; }
"gclk1"                    { return GCLK1; }
"gclk2"                    { return GCLK2; }

"clear_select"             { return CLEAR_SELECT; }
"global_clear"             { return GLOBAL_CLEAR; }
"gclr"                     { return GLOBAL_CLEAR; }
"pt"[1-5]                  { yylval = atoi((char*)yytext+2); return PRODUCT_TERM; }

"xor_enable"               { return XOR_ENABLE; }

"/*"              { oldstate = YY_START; BEGIN COMMENT; }
<COMMENT>"*/"     { /* TODO: Unopened comment; multiply closed comment */ BEGIN oldstate; }
<COMMENT>.|\n
<COMMENT><<EOF>>  { yyerror("Unclosed comment"); }
"//".*

[0-9]+  { yylval = atoi(yytext); return NUMBER; }
"true"  { yylval = true;  printf("true\n"); return BOOL; }
"false" { yylval = false; printf("false\n");  return BOOL; }

"." { return DOT; }
"=" { printf("EQUALS "); return EQUALS; }
";" { return SEMICOLON; }

[ \t\n\r]    /* Ignore whitespace */

[a-zA-Z0-9\-_]+ {
    fprintf(stderr, "Error: Unrecognized token '%s' on line %d.\n", yytext, yylineno);
    exit(1);
    }

. {
    fprintf(stderr, "Error: Illegal character '%s' on line %d.\n", yytext, yylineno);
    exit(1);
    }

%%

int yyerror(char* s)
{
	fprintf(stderr, "Error: %s on line %d\n", s, yylineno);
}

