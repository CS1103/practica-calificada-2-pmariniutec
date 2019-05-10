#ifndef FIGHT_H
#define FIGHT_H

#include <iostream>
#include "fighter.h"

class Fight {
  public:
	Fight(Fighter *a, Fighter *b) : a(a), b(b) { }

	void calculateScore() {
	  std::printf("A: %d %d\nB: %d %d\n", a->attack(), a->defense(), b->attack(), b->defense());
	  int scoreB = a->defense() - b->attack();
	  int scoreA = b->defense() - a->attack();

	  if (scoreB > scoreA) {
		score = scoreB;
		std::cout << "Winner is Fighter A\n";
		winner = a;
	  } else if (scoreB < scoreA){
		score = scoreA;
		std::cout << "Winner is Fighter B\n";
		winner = b;
	  } else { // same score
		std::cout << "Tie\n";
		score = 0;
		winner = nullptr;
	  }
	}

  private:
	std::shared_ptr<Fighter> a, b;
	std::shared_ptr<Fighter> winner;
	int score;
};

#endif
