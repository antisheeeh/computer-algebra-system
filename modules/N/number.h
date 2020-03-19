/* Structure for long number
first field - array of ninth of digits
second field - amount of ninths in number
*/

#define GREATER 2
#define LESS 1
#define EQUAL 0

typedef struct {
    int* num;
    int len;
} longNumber;