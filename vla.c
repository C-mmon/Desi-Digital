#include <stdio.h>
    struct point  {int x, int y;};

int main(void)
{
    int n;
    scanf("%d",&n);
    char *arr =malloc(n* (sizeof *arr));
    free(arr);
    return 0;

    //main difference with variable lenght is
    if (arr == NULL) {
        perror("malloc()"); // output: "malloc(): Cannot allocate memory"
    }
    //device not using maloc

    // Such device rather is not going to have a lot of stack either. So instead of allocating dynamically, you (probably) should determine 
    // how much you need and just always use that fixed amount.

    // When using aVLA on system with small amounts of stack, it's really easy to make something which seems to work,
    // but which blows your stack if your function gets called from a deep call stack combined with the large amount of data.

    // If you always allocate fixed amounts of stack space everywhere, and you test it, you know you're good. 
    //If you dynamically allocate on stack, you have to test all your code paths with all the largest sizes of allocated space, which is much harder and much easier to make a mistake. Don't make it even easier to shoot yourself in the foot for no real advantage.

    int array[10];
    int *apo= arr; //array decay to pointer 
    //apo[2]

    //proper pointer to array 
    int *(ap1)[10]= &array;
    // *(ap1)[2]

    //y explicitly stating that the variable is a pointer to an array, not just a pointer to an individual element.

    int a[6] = { [4] = 29, [2] = 15 };

    int widths[] = { [0 ... 9] = 1, [10 ... 99] = 2, [100] = 3 };

    struct point p = {.y=yvalue, .x=xvalue};

    //or
    struct point p = {yvalue, xvalue};

}