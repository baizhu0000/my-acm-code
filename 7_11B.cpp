#include <iostream>
#include <string>
using namespace std;
class Node2D {
   protected:
    string location;

   public:
    Node2D(string l) : location(l) {}
    virtual string getlocation() const = 0;
    virtual void setlocation(string l) = 0;
    virtual ~Node2D() {}
};
class Body : virtual public Node2D {
   protected:
    int maxhealth, health, defense;

   public:
    Body(string l, int ma, int d) : Node2D(l), maxhealth(ma), health(ma), defense(d) {}
    virtual int gethealth() const = 0;
    virtual int getdefense() const = 0;
    virtual void takedamage(int d) = 0;
    virtual bool isalive() const = 0;
};
class Weapon : virtual public Node2D {
   protected:
    string wname;
    int damage;

   public:
    Weapon(string l, string w, int d) : Node2D(l), wname(w), damage(d) {}
    virtual string getwname() const = 0;
    virtual int getdamage() const = 0;
};
class Player : public Body, public Weapon {
   private:
    string name;

   public:
    Player(string n, int ma, int def, string w, int dam, string l)
        : Node2D(l), Body(l, ma, def), Weapon(l, w, dam), name(n) {}
    string getname() const { return name; }
    string getlocation() const override { return location; }
    void setlocation(string l) override { location = l; }
    int gethealth() const override { return health; }
    int getdefense() const override { return defense; }
    void takedamage(int d) override {
        health -= d;
        if (health < 0) {
            health = 0;
        }
    }
    bool isalive() const override { return health > 0; }
    string getwname() const override { return wname; }
    int getdamage() const override { return damage; }
    void attack(Player& target) {
        int actualdamage = damage - target.defense;
        if (actualdamage < 0) {
            actualdamage = 0;
        }
        target.takedamage(actualdamage);
        cout << name << " deal " << actualdamage << " damage to " << target.name << endl;
        if (target.isalive()) {
            cout << target.name << " still have " << target.health << " health" << endl;
            cout << endl;
        }
    }
};
int main() {
    string location;
    string n1, n2;
    int h1, def1, dam1;
    int h2, def2, dam2;
    string w1, w2;
    cin >> location;
    cin >> n1 >> h1 >> def1 >> w1 >> dam1;
    cin >> n2 >> h2 >> def2 >> w2 >> dam2;
    Player p1(n1, h1, def1, w1, dam1, location);
    Player p2(n2, h2, def2, w2, dam2, location);
    while (p1.isalive() && p2.isalive()) {
        p1.attack(p2);
        if (!p2.isalive()) {
            cout << p1.getname() << " defeated " << p2.getname() << " by " << p1.getwname() << " in "
                 << p1.getlocation() << endl;
            break;
        }
        p2.attack(p1);
        if (!p1.isalive()) {
            cout << p2.getname() << " defeated " << p1.getname() << " by " << p2.getwname() << " in "
                 << p2.getlocation() << endl;
            break;
        }
    }

    return 0;
}