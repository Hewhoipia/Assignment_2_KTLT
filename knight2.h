#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType {Anti, PhoI, PhoII, PhoIII, PhoIV};
enum OppoType {MB, Ban, Lupin, E, Tr, Torn, Queen, Omega, Ha, Ulti};

// some support functions
static bool prime(int hacPe);
static bool pythago(int num);

class BaseItem;
class BaseBag {
protected:
    int nItem;
    int curItems=0;
    BaseItem *head=nullptr;
public:
    BaseBag(int PhoxeI, int Antinek);
    ~BaseBag();
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
    virtual bool is_Full()const;
    virtual void front();
};

// Derived class for BaseBag
class DBag:public BaseBag{ // DRAGON Bag
public:
    DBag(int PhoxeI); // DRAGON Knight cannot have Antinote in Bag
};

class LBag:public BaseBag{ // LANCELOT Bag
public:
    LBag(int PhoxeI, int Anti);
};

class NBag:public BaseBag{ // NORMAL Bag
public:
    NBag(int PhoxeI, int Anti);
};

class PBag:public BaseBag{ // PALADIN Bag
public:
    PBag(int PhoxeI, int Anti);
};
// Derived class for BaseBag

class BaseOpponent{
public:
    int hp=5000; // only use for Ultimecia
    int gil=0;
    int baseDmg=0;
    int lvo=0;
    OppoType type;
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
    BaseBag * bag=nullptr;
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
    bool can_Add(BaseItem * item);
    bool can_gain_gil(int &cash);
    bool is_dead()const;
    void use_item(BaseItem * item);
    void modify_hp();
    bool be_Poison(); // do not use for DRAGON
    void nina_de_rings();
    void sau_rieng();
    string new_to_string() const;
};


// Start class Paladin, Lancelot, Dragon, Normal
class PaladinKnight:public BaseKnight{
public:
    PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    bool fight (BaseOpponent * opponent);
};

class LancelotKnight:public BaseKnight{
public:
    LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    bool fight (BaseOpponent * opponent);
};

class DragonKnight:public BaseKnight{
public:
    DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    bool fight (BaseOpponent * opponent);
};

class NormalKnight:public BaseKnight{
public:
    NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    bool fight (BaseOpponent * opponent);
};
// End class Paladin, Lancelot, Dragon, Normal

class Events;
class ArmyKnights {
private:
    int armyNum;
    BaseKnight *head=nullptr;
    BaseKnight *tail=nullptr;
    bool meet_Omega=0, meet_Hades=0;
    int num_of_tresure=0;
    bool shield=0, spear=0, hairpiece=0, sword=0;
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;
    void readKnight(string eachKnight, int id);
    void back(); //delete last element of ArmyKnight
    void pick_Item(BaseItem * item) const;
    void gain_gil(int cash) const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
    void printALL() const;
};

class BaseItem {
public:
    BaseItem();
    ~BaseItem();
    BaseItem *next=nullptr;
    BaseItem *pre=nullptr;
    ItemType type;
    virtual bool canAddI (BaseKnight * knight); // can add
    virtual bool canUse ( BaseKnight * knight )=0;
    virtual void use ( BaseKnight * knight )=0;
};

class Antidote:public BaseItem{
public:
    Antidote();
    bool canUse (BaseKnight *knight);
    void use ( BaseKnight * knight );
};

class PhoenixDown:public BaseItem{
public:
    PhoenixDown(ItemType Pho_Type);
    bool canUse (BaseKnight *knight);
    void use ( BaseKnight * knight );
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