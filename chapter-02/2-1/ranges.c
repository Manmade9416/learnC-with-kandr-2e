#include <stdio.h>
#include <limits.h>

void pvf_range(void);

int main(void)
{
    /*
     * Print range of char dt*/
    printf("CHAR Range:\n");
    printf("%d to %d\n\n", CHAR_MIN, CHAR_MAX);

    // Signed char range
    printf("SCHAR Range:\n");
    printf("%d to %d\n\n", SCHAR_MIN, SCHAR_MAX);

    // Unsigned char range
    printf("UCHAR Range:\n");
    printf("%u to %u\n", 0 ,UCHAR_MAX);

    printf("=====================================\n\n");
    /*
     * Print range of the short dt
     */
    printf("SHRT Range:\n");
    printf("%d to %d\n\n", SHRT_MIN, SHRT_MAX);

    // Unsigned short range
    printf("USHRT Range:\n");
    printf("%u to %u\n", 0, USHRT_MAX);

    printf("=====================================\n\n");
     /*
     * Print range of the int dt
     */
    printf("INT Range:\n");
    printf("%d to %d\n\n", INT_MIN, INT_MAX);

    // Unsigned int range
    printf("UINT Range:\n");
    printf("%u to %u\n", 0, UINT_MAX);
    
    printf("=====================================\n\n");
    /*
     * Print range of the long dt
     */
    printf("LONG Range:\n");
    printf("%ld to %ld\n\n", LONG_MIN, LONG_MAX);

    // Unsigned long range
    printf("ULONG Range:\n");
    printf("%lu to %lu\n", (long) 0, ULONG_MAX);

    printf("=====================================\n\n");
  
    pvf_range();

    return 0;
}

void pvf_range(void)
{
    /*
     * Print the flout dt range
     */
    printf("FLT Range:\n");
    printf("%f to %f\n", FLT_MIN, FLT_MAX);
    printf("====================================\n\n");
    printf("DBL Range:\n");
    printf("%f to %f\n", DBL_MIN, DBL_MAX);
    printf("====================================\n\n");
    printf("LONG DBL Range:\n");
    printf("%Lf to %Lf\n", LDBL_MIN, LDBL_MAX);
    printf("====================================\n\n");

    return;
}
