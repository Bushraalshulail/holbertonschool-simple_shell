#include "utils.h"
#include <stdlib.h>

/**
* _strlen - returns the length of a string
* @s: the string
* Return: length
*/
int _strlen(const char *s)
{
int len = 0;

while (s[len])
len++;
return (len);
}

/**
* _strcmp - compares two strings
* @s1: first string
* @s2: second string
* Return: 0 if equal, positive or negative if not
*/
int _strcmp(const char *s1, const char *s2)
{
int i = 0;

while (s1[i] && s2[i] && s1[i] == s2[i])
i++;
return (s1[i] - s2[i]);
}

/**
* _strcpy - copies the string from src to dest
* @dest: destination buffer
* @src: source string
* Return: pointer to dest
*/
char *_strcpy(char *dest, const char *src)
{
int i = 0;

while ((dest[i] = src[i]) != '\0')
i++;
return (dest);
}

/**
* _strdup - duplicates a string (custom strdup)
* @str: the input string
* Return: pointer to newly allocated copy
*/
char *_strdup(const char *str)
{
char *copy;
int len, i;

if (!str)
return (NULL);

len = _strlen(str);
copy = malloc(sizeof(char) * (len + 1));
if (!copy)
return (NULL);

for (i = 0; i <= len; i++)
copy[i] = str[i];

return (copy);
}

