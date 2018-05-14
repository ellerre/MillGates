/*
 * IterativeDeepeningAI.h
 *
 *  Created on: May 10, 2018
 *      Author: Luca
 */

#ifndef ITERATIVEDEEPENINGAI_H_
#define ITERATIVEDEEPENINGAI_H_

#include "NegaScoutAI.h"

void * timer(void * args);

class IterativeDeepeningAI {
private:
	AI * _ai;
	Action _tempAction;

public:
	IterativeDeepeningAI();

	virtual void setAI(AI * ai);
	virtual void setDepth(uint8 depth);
	virtual Action choose(State * state);
	virtual void clear();
	virtual void stop();
	virtual void print(State * root, int depth);
	virtual ~IterativeDeepeningAI();

	void * refreshResult(State * state);
	void * timer();
};

#endif /* ITERATIVEDEEPENINGAI_H_ */
