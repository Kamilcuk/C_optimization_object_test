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

#define NUM_INIT_CONF(_add, _notify_added, _arg, _volatile_up, _volatile_down) { \
		.conf = &(const struct num_conf_s){ \
			.add = _add, \
			.notify_added = _notify_added, \
			.arg = _arg, \
			.volatile_up = _volatile_up, \
			.volatile_down = _volatile_down, \
		}, \
		.this = &(struct num_state_s){0}, \
	}



NUM_DECLARE_FUCNTIONS(__P(struct num_s * restrict t), (*(t->this)), (*(t->conf)))

#endif /* SRC_NUM2_H_ */
