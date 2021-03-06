/*
 * NegaScoutAI.h
 *
 *  Created on: May 11, 2018
 *      Author: Luca
 */

#ifndef AI_NEGASCOUTAI_H_
#define AI_NEGASCOUTAI_H_

#include "../Utils/ExpVector.h"
#include "../Utils/HashSet.h"
#include "AI.h"
#include "Hash/ZobristHashing.h"
#include "Heuristic/HeuristicFunction.h"
#include "Heuristic/PawnCountHeuristic.h"
#include "Heuristic/RomanianHeuristic.h"

typedef enum entryFlag_t {EXACT, ALPHA_PRUNE, BETA_PRUNE} entryFlag_t;

typedef struct {
	uint8 depth;
	entryFlag_t entryFlag;
	eval_t eval;
} entry;

class NegaScoutAI: public AI {
private:

	HashSet<entry> * _table;
	HashSet<bool> * _history;
	ZobristHashing * _hasher;
	HeuristicFunction * _heuristic;
	uint8 _depth;
	bool _stopFlag;

	void recurprint(State * state, int depth, int curdepth);

	uint8 partition(State * state, ExpVector<State*> * states, ExpVector<hashcode> * hashes, ExpVector<eval_t> * values, ExpVector<Action> * actions, eval_t p, eval_t q, sint8 color, hashcode quickhash);

public:
	NegaScoutAI();
	virtual uint8 getDepth();
	virtual void setDepth(uint8 depth);
	virtual Action choose(State * state);
	virtual void clear();
	virtual void stop();
	virtual void print(State * root, int depth);
	virtual void addHistory(State * state);
	virtual void clearHistory();

	eval_t negaScout(State * state, hashcode quickhash, uint8 depth, eval_t alpha, eval_t beta, sint8 color);
	void parallel_negaScout(State * state);

	void quickSort(State * state, ExpVector<State*> * states, ExpVector<hashcode> * hashes, ExpVector<eval_t> * values, ExpVector<Action> * actions, eval_t p, eval_t q, sint8 color, hashcode quickhash);
	void setMaxFirst(ExpVector<State*> * states, ExpVector<hashcode> * hashes, ExpVector<eval_t> * values, ExpVector<Action> * actions);

	virtual ~NegaScoutAI();
};

#endif /* AI_NEGASCOUTAI_H_ */
