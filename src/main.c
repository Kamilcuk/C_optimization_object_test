
#include <stdio.h>
#include <stdint.h>

#ifndef USE_NUM
#define USE_NUM 2
#endif
#if USE_NUM == 1
#include "num1.h"
#elif USE_NUM == 2
#include "num2.h"
#else
#error USE_NUM not defined or bad value
#endif

//int (*add)(void*, int, int*);
static int myadd(void *arg0, int value, int *adding) {
	printf("A %d %d\n", value, *adding);
	return value + 2 * *adding;
}

//void (*notify_added)(void *, int, int*);
static void myadd_notify(void *arg0, int value, int *added) {
	int arg = (int)(uintptr_t)arg0;
	printf("N %d ?+%d=%d\n", arg, value, *added);
}

static struct num_s num1 = NUM_INIT_CONF(NULL, NULL, (void*)500);

void use_no_functions(void) {
	struct num_s * const num = &num1;
	num_init(num, 2);
	int a = 1;
	num_add_number(num, &a);
	printf("=%d\n", num_get_number(num));
	int b = 5;
	num_add_number(num, &b);
	printf("=%d\n", num_get_number(num));
	num_fini(num);
}

static struct num_s num2 = NUM_INIT_CONF(&myadd, &myadd_notify, (void*)10);

void use_with_functions(void) {
	struct num_s * const num = &num2;
	num_init(num, 2);
	int a = 1;
	num_add_number(num, &a);
	printf("=%d\n", num_get_number(num));
	int b = 5;
	num_add_number(num, &b);
	printf("=%d\n", num_get_number(num));
	num_fini(num);
}

int main(void) {
	use_no_functions();
	use_with_functions();
	return 0;
}
