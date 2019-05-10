#include <fstream>
#include <sstream>
#include "fighter.h"
#include "arena.h"

std::vector<std::string> split_string(std::string s, std::string delimiter) {

  std::vector<std::string> result{};
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
	token = s.substr(0, pos);
	result.push_back(token);
	s.erase(0, pos + delimiter.length());
  }
  result.push_back(s);
  return result;

}

Attack *parse_attack(std::string token) {
  if (token == "P")
	return new Punch();
  else if (token == "S")
	return new Saber();
  else
	return new Firearm();
}

Defense *parse_defense(std::string token) {
  if (token == "E")
	return new Elude();
  else if (token == "S")
	return new Shield();
  else
	return new Armor();
}

Arena::Arena() { }

void Arena::load_fights(std::string filename) {
  std::ifstream in(filename);

  std::vector<std::string> fighters;
  std::vector<std::string> defenses, defenses2;
  std::vector<std::string> attacks, attacks2;

  int lineCount = 0;
  std::string line;
  std::vector<std::string> v;
  while(std::getline(in, line)) {

	if(lineCount == 0) {
		fighters.push_back(line);
	} else if (lineCount == 1) {
		v = split_string(line, ", ");
		defenses.insert(defenses.end(), v.begin(), v.end());
	} else if (lineCount == 2) {
		v = split_string(line, ", ");
		attacks.insert(attacks.end(), v.begin(), v.end());
	} else if (lineCount == 3) {
		fighters.push_back(line);
	} else if (lineCount == 4) {
		v = split_string(line, ", ");
		defenses2.insert(defenses2.end(), v.begin(), v.end());
	} else if (lineCount == 5) {
		v = split_string(line, ", ");
		attacks2.insert(attacks2.end(), v.begin(), v.end());
	}
	v.clear();

	// reset
	lineCount++;
	if (lineCount == 6) lineCount = 0;
  }

  for (int i = 0; i < fighters.size(); i += 2) {

	Fighter *a, *b;
	auto fighter = fighters[i];
	auto fighter2 = fighters[i+1];

	if(fighter == "BL") {
	  a = new BruceLee(); 
	} else if (fighter == "CN") {
	  a = new ChuckNorris();
	} else { // JS
	  a = new JasonStatham();
	}

	if(fighter2 == "BL") {
	  b = new BruceLee(); 
	} else if (fighter2 == "CN") {
	  b = new ChuckNorris();
	} else { // JS
	  b = new JasonStatham();
	}

	for (auto &t : attacks) {
	  a->addAttack(parse_attack(t));
	}

	for (auto &t : defenses) {
	  a->addDefense(parse_defense(t));
	}

	for (auto &t : attacks2) {
	  b->addAttack(parse_attack(t));
	}

	for (auto &t : defenses2) {
	  b->addDefense(parse_defense(t));
	}

	// no need to delete a and b because the class takes ownership with a shared_ptr
	fights.emplace_back(a, b);
  }

}

void Arena::run() {
  for (auto &fight : fights) {
	fight.calculateScore();
  }
}
