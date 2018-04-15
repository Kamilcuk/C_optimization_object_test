/*
 * num1.h
 *
 *  Created on: 14 kwi 2018
 *      Author: kamil
 */

#ifndef SRC_NUM1_H_
#define SRC_NUM1_H_

#include "num_types.h"

struct num_s {
	const struct num_conf_s conf;
	struct num_state_s this;
};

#define NUM_INIT_CONF(_add, _notify_added, _arg, _volatile_up, _volatile_down) { \
		.conf = { \
			.add = _add, \
			.notify_added = _notify_added, \
			.arg = _arg, \
			.volatile_up = _volatile_up, \
			.volatile_down = _volatile_down, \
		}, \
		.this = {0}, \
	}


NUM_DECLARE_FUCNTIONS(__P(struct num_s * restrict t), t->this, t->conf)

#endif /* SRC_NUM1_H_ */
