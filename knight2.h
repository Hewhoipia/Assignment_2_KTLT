#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType {Antidote, PhoI, PhoII, PhoIII, PhoIV};

// some support functions
static bool prime(int hacPe);
static bool pythago(int num);

class BaseItem;
class BaseBag {
public:
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};

class BaseOpponent{
public:
    virtual void blabla()=0;
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
    virtual bool fight(BaseOpponent * opponent)=0;
    void back(); //delete last element of ArmyKnight
};


// Start class Paladin, Lancelot, Dragon, Normal
class PaladinKnight:public BaseKnight{
public:
    PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
        knightType=PALADIN;
    }
    bool fight (BaseOpponent * opponent);
};

class LancelotKnight:public BaseKnight{
public:
    LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
        
    }
    bool fight (BaseOpponent * opponent);
};

class DragonKnight:public BaseKnight{
public:
    DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
        
    }
    bool fight (BaseOpponent * opponent);
};

class NormalKnight:public BaseKnight{
public:
    NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
        
    }
    bool fight (BaseOpponent * opponent);
};
// End class Paladin, Lancelot, Dragon, Normal

class Events;
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