/*
 * num2.h
 *
 *  Created on: 14 kwi 2018
 *      Author: kamil
 */

#ifndef SRC_NUM2_H_
#define SRC_NUM2_H_

#include "num_types.h"

struct num_s {
	const struct num_conf_s * restrict conf;
	struct num_state_s * restrict this;
};

#define NUM_INIT_CONF(_add, _notify_added, _arg) \
	{.conf = \
		&(const struct num_conf_s){.add = _add, .notify_added = _notify_added, .arg = _arg }, \
	.this = &(struct num_state_s){0} \
	}

static inline void num_init(struct num_s * restrict t, int value) {
	assert(t != NULL);
	t->this->value = value;
	t->this->memory_value = malloc(sizeof(*t->this->memory_value));
	assert(t->this->memory_value != NULL);
}

static inline void num_add_number(struct num_s * restrict t, int * restrict value) {
	assert(t != NULL); assert(value != NULL);
	if (t->conf->add != NULL) {
		t->this->value = t->conf->add(t->conf->arg, t->this->value, value);
	} else {
		t->this->value = t->this->value + *value;
	}
	if (t->conf->notify_added != NULL) {
		t->conf->notify_added(t->conf->arg, t->this->value, value);
	}
}

static inline int num_get_number(struct num_s * restrict t) {
	return t->this->value;
}

static inline void num_fini(struct num_s * restrict t) {
	free(t->this->memory_value);
}

#endif /* SRC_NUM2_H_ */
