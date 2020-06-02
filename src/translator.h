#ifndef TRANSLATION_TOKENS_H
#define TRANSLATION_TOKENS_H

typedef enum {  NULL_TOKEN = 1,
                OPERATION_TOKEN,
                SINGLE_OPERATION_TOKEN,
                IF_TOKEN,
                WHILE_TOKEN,
                RETURN_TOKEN,
                STATEMENT_TOKEN,
                STATEMENTS_TOKEN,
                NEGATION_TOKEN,
                PRINT_TOKEN,
                STRING_TOKEN,
                CONSTANT_TOKEN,
                FUNCTION_DEF_TOKEN,
                FUNCTION_CALL_TOKEN,
                COORDINATES_TOKEN,
                VARIABLE_TOKEN,
                BLOCK_TOKEN,
                SIGMA_PI_TOKEN,
                SIGMA_PI_COND_TOKEN,
                SLOPE_TOKEN
} TokenType;

typedef enum {  
            
            DATA_CHORD,
            DATA_NUMBER,
            DATA_SET

} DataType;

/* Token structures that hold the token information */

/* Shared struct */
typedef struct basicInfo {
  DataType    dataType;
  
} BasicInfo;

/* Basic token */
typedef struct Token {
  BasicInfo   basicInfo;
} Token;


#endif