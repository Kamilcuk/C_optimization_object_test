/*
 * num_types.h
 *
 *  Created on: 14 kwi 2018
 *      Author: kamil
 */

#ifndef SRC_NUM_TYPES_H_
#define SRC_NUM_TYPES_H_

#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <stdbool.h>

struct num_conf_s {
	long unused1;
	int (*add)(void*, int, int*);
	long unused2;
	void (*notify_added)(void *, int, int*);
	long unused3;
	void (*volatile_up)();
	long unused4;
	void (*volatile_down)();
	long unused5;
	void *arg;
	long unused6;
};
struct num_state_s {
	int unused5;
	int value;
	int unused6;
	int * memory_value;
	int unused7;
};

#define NUM_DECLARE_FUCNTIONS(args, state, conf) \
\
static inline void num_init(args, int value) { \
	assert(&state != NULL); \
	assert(&conf != NULL); \
	state.value = value; \
} \
\
static inline void num_add_number(args, int * restrict value) { \
	if (conf.volatile_up != NULL) \
		conf.volatile_up(); \
	if (conf.add != NULL) { \
		state.value = conf.add(conf.arg, state.value, value); \
	} else { \
		state.value = state.value + *value; \
	} \
	if (conf.notify_added != NULL) \
		conf.notify_added(conf.arg, state.value, value); \
	if (conf.volatile_down != NULL) \
		conf.volatile_down(); \
} \
\
static inline int num_get_number(args) { \
	return state.value; \
} \
\
static inline void num_fini(args) { \
}

#ifndef __P
#define __P(...) __VA_ARGS__
#endif

#endif /* SRC_NUM_TYPES_H_ */
