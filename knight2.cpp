#include "knight2.h"

//some support functions
static bool prime(int hacPe) {
    if (hacPe < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(hacPe); i++) {
        if (hacPe % i == 0) {
            return false;
        }
    }
    return true;
}

static bool pythago(int num){
    if (num>999 || num<100) return false;
    int a = num / 100;
    int b = (num / 10) % 10;
    int c = num % 10;
    if (pow(c,2)==pow(a,2)+pow(b,2)) return true;
    if (pow(b,2)==pow(a,2)+pow(c,2)) return true;
    if (pow(a,2)==pow(c,2)+pow(b,2)) return true;
    return false;
}

/* * * BEGIN implementation of class BaseBag * * */
class EachBag:public BaseBag{
public:
    int nItem;
    int curItems=0;
    BaseItem *head=nullptr;
    ~EachBag(){
        /*BaseItem *next=nullptr;
        BaseItem *tmp=head;
        while (tmp!=nullptr){
        next = tmp->next;
        delete tmp;
        tmp = next;
        }
        head=nullptr;*/
    }
    virtual bool insertFirst (BaseItem *item)=0;
    BaseItem * get(ItemType itemType){
        //hmm
    }
    string toString()const{
        //hmm
    }
};

class DBag:public EachBag{ // DRAGON Bag
public:
    DBag(){
        nItem=14;
    }
    bool insertFirst (BaseItem *item){
        //hmm
        return 1;
    }
};

class LBag:public EachBag{ // LANCELOT Bag
public:
    LBag(){
        nItem=16;
    }
    bool insertFirst (BaseItem *item){
        //hmm
        return 1;
    }
};

class NBag:public EachBag{ // NORMAL Bag
public:
    NBag(){
        nItem=19;
    }
    bool insertFirst (BaseItem *item){
        //hmm
        return 1;
    }
};

class PBag:public EachBag{ // PALADIN Bag
public:
    PBag(){
        nItem=-1; // infinite number
    }
    bool insertFirst (BaseItem *item){
        //hmm
        return 1;
    }
};
/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseItem * * */
class Antidote:public BaseItem{
public:
    bool canUse (BaseKnight *knight){
        //check bag
        return 1;
    }
    void use ( BaseKnight * knight ){
        //use
        return 1;
    }
    bool bePoison(BaseKnight *knight){
        //check if the knight is poisoned
        return 1;
    }
};

class PhoenixDownI:public BaseItem{
public:
    bool canUse (BaseKnight *knight){
        //check bag
        return 1;
    }
    void use ( BaseKnight * knight ){
        //use
    }
};

class PhoenixDownII:public BaseItem{
public:
    bool canUse (BaseKnight *knight){
        //check bag
        return 1;
    }
    void use ( BaseKnight * knight ){
        //use
    }
};

class PhoenixDownIII:public BaseItem{
public:
    bool canUse (BaseKnight *knight){
        //check bag
        return 1;
    }
    void use ( BaseKnight * knight ){
        //use
    }
};

class PhoenixDownIV:public BaseItem{
public:
    bool canUse (BaseKnight *knight){
        //check bag
        return 1;
    }
    void use ( BaseKnight * knight ){
        //use
    }
};
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class BaseOpponent * * */
class MadBear:public BaseOpponent{
public:
    //hmm
};

class Bandit:public BaseOpponent{
public:
    //hmm
};

class LordLupin:public BaseOpponent{
public:
    //hmm
};

class Elf:public BaseOpponent{
public:
    //hmm
};

class Troll:public BaseOpponent{
public:
    //hmm
};

class Tornbery:public BaseOpponent{
public:
    //hmm
};

class QueenOfCards:public BaseOpponent{
public:
    //hmm
};

class NinaDeRings:public BaseOpponent{
public:
    //hmm
};

class DurianGarden:public BaseOpponent{
public:
    //hmm
};

class OmegaWeapon:public BaseOpponent{
public:
    //hmm
};

class Hades:public BaseOpponent{
public:
    //hmm
};
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class BaseKnight * * */
BaseKnight *BaseKnight::create (int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    BaseKnight *hold=nullptr;
    if (prime(maxhp)) {
        hold = new PaladinKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else if (maxhp==888){
        hold = new LancelotKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else if(pythago(maxhp)){
        hold = new DragonKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else{
        hold = new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    return hold;
}

BaseKnight::BaseKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    this->id=id;
    this->maxhp=maxhp;
    this->hp=maxhp;
    this->level=level;
    this->gil=gil;
    this->antidote=antidote;
    // knightType
    //bag
}

BaseKnight::~BaseKnight(){
    delete [] bag;
    bag=nullptr;
}

void BaseKnight::back(){
    //hmm
}

string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

// class Paladin, Lancelot, Dragon, Normal

bool PaladinKnight::fight(BaseOpponent * opponent){
    //hmm
}

bool LancelotKnight::fight (BaseOpponent * opponent){
    //hmm
}

bool DragonKnight::fight(BaseOpponent * opponent){
    //hmm
}

bool NormalKnight::fight(BaseOpponent * opponent){
    //hmm
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights::ArmyKnights(const string & file_armyknights){
    // Knights array
    ifstream myFile(file_armyknights);
    if (myFile.is_open()){
        myFile >> armyNum;
        for (int i=1; i<=armyNum; i++){
            string eachKnight;
            getline(myFile, eachKnight);
            getline(myFile, eachKnight);
            ifstream myKnight(eachKnight);
            readKnight(eachKnight, i);
        }
        myFile.close();
    }
    else cout << "Cannot open the f*cking file!"<<endl;
}
ArmyKnights::~ArmyKnights(){
    BaseKnight *next=nullptr;
    BaseKnight *tmp=head;
    while (tmp!=nullptr){
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    head=nullptr;
    tail=nullptr;
}

bool ArmyKnights::fight(BaseOpponent * opponent){
    BaseKnight* curKnight = lastKnight();
    return curKnight->fight(opponent);
}

bool ArmyKnights::adventure(Events * events){
    for (int i=1; i<=events->count(); i++){
        int curEvent = events->get (i);
        //do sth
    }
    return false; //not defeat Ultimecia
}

int ArmyKnights::count() const{
    return armyNum;
}

void ArmyKnights::readKnight(string& eachKnight, int id){
    ifstream myK(eachKnight);
    int maxhp, level, pho, gil, anti;
    myK >> maxhp >> level >> pho >> gil >> anti;
    if (head == nullptr){
        head = BaseKnight::create (id, maxhp, level, gil, anti, pho);
        tail=head;
    }
    else{
        tail->next=BaseKnight::create (id, maxhp, level, gil, anti, pho);
        tail->next->pre=tail;
        tail=tail->next;
    }
}

BaseKnight *ArmyKnights:: lastKnight() const{
    return tail;
}

bool ArmyKnights::hasPaladinShield()const{
    //hmm
}

bool ArmyKnights::hasLancelotSpear()const{
    //hmm
}

bool ArmyKnights::hasGuinevereHair() const{
    //hmm
}

bool ArmyKnights::hasExcaliburSword() const{
    //hmm
}

void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure(){
    delete [] armyKnights;
    delete [] events;
    armyKnights=nullptr;
    events=nullptr;
}
void KnightAdventure::loadArmyKnights(const string & file){
    armyKnights = new ArmyKnights(file);
}
void KnightAdventure::loadEvents(const string & file){
    events = new Events(file);
}
void KnightAdventure::run(){
    cout << "run!!!"<<endl;
    armyKnights->printInfo();
}

/* * * END implementation of class KnightAdventure * * */

/* * * BEGIN implementation of class Events * * */
Events::Events(const string &file_events){
    ifstream myFile(file_events);
    if (myFile.is_open()){
        myFile >> eNum;
        string endLine;
        getline (myFile, endLine);
        eArr=new int();
        for (int i=1; i<=eNum; i++){
            myFile >> eArr[i];
        }
        myFile.close();
    }
    else cout << "Cannot open the f*cking file!"<<endl;
}
Events::~Events(){
    delete [] eArr;
    eArr=nullptr;
}
int Events::count() const{
    return eNum;
}
int Events::get(int i) const{
    return eArr[i];
}
void Events::printEvent() const{
    for (int i=1; i<=eNum; i++){
        cout << eArr[i] << " ";
    }
    cout << endl;
}
/* * * END implementation of class Events * * */