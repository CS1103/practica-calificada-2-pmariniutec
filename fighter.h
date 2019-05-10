#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>
#include <vector>
#include <memory>
#include <numeric>
#include "attacks.h"

class Fighter {
  public:
	Fighter(std::string id) : identifier(id) {}

	int attack() {
	  int total = 0;
	  for (auto &a : attacks) {
		total += a->attack(); 
	  }
	  return total;
	}

	int defense() {
	  int total = 0;
	  for (auto &d : defenses) {
		total += d->defense(); 
	  }
	  return total;
	}

	void addDefense(Defense *d) {
	  // std::cout << "Create defense with val " << d->defense() << '\n';
	  defenses.emplace_back(d);
	}

	void addAttack(Attack *a) {
	  // std::cout << "Create attack with val " << a->attack() << '\n';
	  attacks.emplace_back(a);
	}

  private:
	std::vector<std::unique_ptr<Defense>> defenses;
	std::vector<std::unique_ptr<Attack>> attacks;
	std::string identifier;
};

class BruceLee : public Fighter {
  public:
	BruceLee() : Fighter("BL") { }
};

class ChuckNorris : public Fighter {
  public:
	ChuckNorris() : Fighter("CN") { }
};

class JasonStatham : public Fighter {
  public:
	JasonStatham() : Fighter("JS") { }
};

#endif
