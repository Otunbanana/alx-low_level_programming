#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* main - Generates and prints passwords for the crackme5 executable.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: Always 0.
*/
int main(int argc, char *argv[])
{
char password[7], *codex;
int len = strlen(argv[1]), i, tmp;

codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

password[0] = codex[(len ^ 59) & 63];
password[1] = codex[((tmp = 0) + (tmp ^= 79) + (tmp ^= 85)) & 63];
password[2] = codex[(tmp = 1, tmp *= tmp) & 63];

tmp = argv[1][0];
for (i = 0; i < len; i++)
tmp = (tmp > argv[1][i]) ? tmp : argv[1][i];
srand(tmp ^ 14);
password[3] = codex[rand() & 63];

password[4] = codex[((tmp = 0) + (tmp += argv[1][0] * argv[1][0])) ^ 239) & 63];

for (i = 0; i < argv[1][0]; i++)
tmp = rand();
password[5] = codex[(tmp ^= 229) & 63];

password[6] = '\0';
printf("%s", password);

return (0);
}
