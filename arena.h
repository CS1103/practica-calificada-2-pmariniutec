#ifndef ARENA_H
#define ARENA_H

#include "fight.h"

class Arena {
  public:
	Arena();

	void load_fights(std::string filename);
	void run();

	inline auto get_fights() { return fights; }

  private:
	std::vector<Fight> fights;
};

#endif
