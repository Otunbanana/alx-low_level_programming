#ifndef DOG_H
#define DOG_H
/**
* dog_t - Typedef for struct dog
*/
typedef struct dog dog_t;
/**
* struct dog - struct for dog
* @name: name of dog
* @age: age of dog
* @owner: owner of dog
*
* Return: Always 0.
*/
struct dog
{
char *name;
float age;
char *owner;
}
my_dog;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
