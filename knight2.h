#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
#ifdef DEBUG
    std::cout << "Debugging information" << std::endl;
#endif

enum ItemType {Antidote, PhoI, PhoII, PhoIII, PhoIV};

class BaseBag {
public:
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};

class BaseOpponent{
public:
    //hmm
};

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag * bag;
    KnightType knightType;
public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    //addition
    BaseKnight *next=nullptr;
    BaseKnight *pre=nullptr;
    BaseKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    ~BaseKnight();
    void checkKnight();
    bool prime(int hacPe);
    bool pythago(int num);
    bool fight(BaseOpponent * opponent);
    void back(); //delete last element of ArmyKnight
};

// Start class Paladin, Lancelot, Dragon, Normal

class PaladinKnight:private BaseKnight{
public:
    bool fight (BaseOpponent * opponent);
};

class LancelotKnight:private BaseKnight{
public:
    bool fight (BaseOpponent * opponent);
};

class DragonKnight:private BaseKnight{
public:
    bool fight (BaseOpponent * opponent);
};

class NormalKnight:private BaseKnight{
public:
    bool fight (BaseOpponent * opponent);
};

// End class Paladin, Lancelot, Dragon, Normal

class ArmyKnights {
private:
    int armyNum;
    BaseKnight *head=nullptr;
    BaseKnight *tail=nullptr;
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;
    void readKnight(string& eachKnight, int id);

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
};

class BaseItem {
public:
    BaseItem *next=nullptr;
    ItemType type;
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};

class Events {
private:
    int* eArr=nullptr;
    int eNum;
public:
    Events(const string &);
    ~Events();
    int count() const;
    int get(int i) const;
    void printEvent() const;
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__