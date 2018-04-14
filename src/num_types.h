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
	void *unused1;
	int (*add)(void*, int, int*);
	void *unused2;
	void (*notify_added)(void *, int, int*);
	void *unused3;
	void *arg;
	void *unused4;
};
struct num_state_s {
	int unused5;
	int value;
	int unused6;
	int * memory_value;
	int unused7;
};

bool _is_restricted_in(const void *pnta, size_t pntasize, const void *pntb, size_t pntbsize) {
	const char * const abeg = pnta,
			* const aend = (char*)pnta + pntasize,
			* const bbeg = pntb,
			* const bend = (char*)pntb + pntbsize;
	return (abeg < bbeg && bend < abeg) || (aend < bbeg && bend < aend);
}
#define is_restricted(pnta, pntb) _is_restricted_in(pnta, sizeof(*pnta), pntb, sizeof(*pntb))

#endif /* SRC_NUM_TYPES_H_ */
