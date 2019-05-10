#ifndef ATTACKS_H
#define ATTACKS_H

class Defense {
  public:
	Defense(int l, char id) : level(l), identifier(id) {}
	int defense() const { return level; }

  private:
	int level;
	char identifier;
};

class Elude : public Defense {
  public:
	Elude() : Defense(1, 'E') { }
};

class Shield : public Defense {
  public:
	Shield() : Defense(4, 'S') { }
};

class Armor : public Defense {
  public:
	Armor() : Defense(8, 'A') { }
};

class Attack {
  public:
	Attack(int p, char id) : power(p), identifier(id) {}
	int attack() const { return power; }

  private:
	int power;
	char identifier;
};

class Punch : public Attack {
  public:
	Punch() : Attack(1, 'P') {}
};

class Saber : public Attack {
  public:
	Saber() : Attack(5, 'S') {}
};

class Firearm : public Attack {
  public:
	Firearm() : Attack(10, 'F') {}
};

#endif
