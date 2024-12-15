#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 100     // Maximum number of tokens
#define MAX_TOKEN_LENGTH 1024 // Maximum length of each token

// Function to allocate memory for the tokens array
char	**allocate_tokens() {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    if (!tokens) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return tokens;
}

// Function to allocate memory for an individual token
char	*allocate_token() {
    char *token = malloc(MAX_TOKEN_LENGTH * sizeof(char));
    if (!token) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return token;
}

// Function to skip leading spaces
const char	*skip_spaces(const char *ptr) {
    while (isspace(*ptr)) {
        ptr++;
    }
    return ptr;
}

// Function to extract a quoted string (single or double quotes)
const char	*extract_quoted_string(const char *ptr, char *token) {
    char quote = *ptr; // Remember the type of quote (' or ")
    ptr++; // Skip opening quote
    int i = 0;
    while (*ptr != '\0' && *ptr != quote) {
        token[i++] = *ptr++;
    }
    if (*ptr == quote) {
        ptr++; // Skip closing quote
    }
    token[i] = '\0'; // Null-terminate the token
    return ptr;
}

// Function to extract an unquoted string
const char	*extract_unquoted_string(const char *ptr, char *token) {
    int i = 0;
    while (*ptr != '\0' && !isspace(*ptr)) {
        token[i++] = *ptr++;
    }
    token[i] = '\0'; // Null-terminate the token
    return ptr;
}

// Main split function
char	**split_with_quotes(const char *input, int *count) {
    *count = 0;
    char **tokens = allocate_tokens();
    const char *ptr = input;

    while (*ptr != '\0' && *count < MAX_TOKENS) {
        ptr = skip_spaces(ptr);
        if (*ptr == '\0') break;

        char *token = allocate_token();
        if (*ptr == '"' || *ptr == '\'') { // Check for either type of quote
            ptr = extract_quoted_string(ptr, token);
        } else {
            ptr = extract_unquoted_string(ptr, token);
        }

        tokens[(*count)++] = token;
    }

    return tokens;
}

// Function to free allocated memory
void free_split_result(char **tokens, int count) {
    for (int i = 0; i < count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

// Main function to test the code
int main() {
    const char *input = "Hello \"'this is a test'\" 'and another' world";
    int count;
    char **tokens = split_with_quotes(input, &count);

    printf("Tokens:\n");
    for (int i = 0; i < count; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
    }

    free_split_result(tokens, count);
    return 0;
}
