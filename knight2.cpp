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

bool BaseBag::insertFirst(BaseItem * item){
    // do sth
    return 0;
}

BaseItem* BaseBag::get(ItemType itemType){
    return nullptr;
}

string BaseBag::toString()const{
    return "bag";
}

BaseBag::BaseBag(){
    curItems=0;
    head=nullptr;
}

BaseBag::~BaseBag(){
    BaseItem *next=nullptr;
    BaseItem *tmp=head;
    while (tmp!=nullptr){
    next = tmp->next;
    delete tmp;
    tmp = next;
    }
    head=nullptr;
    cout << "deleted Bag\n";
}

bool BaseBag::hasItem()const{
    if (head==nullptr) return 0;
    return 1;
}

bool BaseBag::is_Full() const{
    if (nItem == -1 || curItems < nItem){
        return 0;
    }
    else return 1;
}

// class DBag
    DBag::DBag():BaseBag(){
        nItem=14;
    }

//class LBag
    LBag::LBag():BaseBag(){
        nItem=16;
    }

//class NBag
    NBag::NBag():BaseBag(){
        nItem=19;
    }

//class PBag
    PBag::PBag():BaseBag(){
        nItem=-1; // infinite number
    }

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseItem * * */

BaseItem::~BaseItem(){
    cout << "deleted Item"<<endl;
}

bool BaseItem::canUse (BaseKnight *knight){
    if (knight->can_Add(this)) return 1;
    return 0;
}

class Antidote:public BaseItem{
public:
    Antidote(){
        type=Anti;
    }
    void use ( BaseKnight * knight ){
        //use
    }
    bool bePoison(BaseKnight *knight){
        //check if the knight is poisoned
        return 1;
    }
};

class PhoenixDownI:public BaseItem{
public:
    PhoenixDownI(){
        type=PhoI;
    }
    void use ( BaseKnight * knight ){
        //use
    }
};

class PhoenixDownII:public BaseItem{
public:
    PhoenixDownII(){
        type=PhoII;
    }
    void use ( BaseKnight * knight ){
        //use
    }
};

class PhoenixDownIII:public BaseItem{
public:
    PhoenixDownIII(){
        type=PhoIII;
    }
    void use ( BaseKnight * knight ){
        //use
    }
};

class PhoenixDownIV:public BaseItem{
public:
    PhoenixDownIV(){
        type=PhoIV;
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
    delete bag;
    bag=nullptr;
    cout << "deleted BaseKnight"<<endl;
}

bool BaseKnight::can_Add(BaseItem * item){
    if (this->bag->is_Full()==0){
        if (knightType==DRAGON && item->type==Anti) return 0;
        this->bag->insertFirst(item);
        return 1;
    }
    return 0;
}

bool BaseKnight::can_gain_gil(int &cash){
    int numCash=999-gil;
    if (numCash < cash){
        gil=gil+numCash;
        cash=cash-numCash;
        return 1;
    }
    else{
        gil=gil+cash;
        return 0;
    }
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
PaladinKnight::PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
    knightType=PALADIN;
    //bag
    bag=new PBag ();
}

bool PaladinKnight::fight(BaseOpponent * opponent){
    //hmm
    return 1;
}

LancelotKnight::LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
    knightType=LANCELOT;
    //bag
    bag=new LBag();
}

bool LancelotKnight::fight (BaseOpponent * opponent){
    //hmm
    return 1;
}

DragonKnight::DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
    knightType=DRAGON;
    //bag
    bag=new DBag();
}

bool DragonKnight::fight(BaseOpponent * opponent){
    //hmm
    return 1;
}

NormalKnight::NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
    knightType=NORMAL;
    //bag
    bag = new NBag();
}

bool NormalKnight::fight(BaseOpponent * opponent){
    //hmm
    return 1;
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights::ArmyKnights(const string & file_armyknights){
    // Knights array
    ifstream myFile(file_armyknights);
    if (myFile.is_open()){
        myFile >> armyNum;
        string eachKnight;
        getline(myFile, eachKnight);
        for (int i=1; i<=armyNum; i++){
            getline(myFile, eachKnight);
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
    cout << "deleted ArmyKnight"<<endl;
}

bool ArmyKnights::fight(BaseOpponent * opponent){
    BaseKnight* curKnight = lastKnight();
    return curKnight->fight(opponent);
}

bool ArmyKnights::adventure(Events * events){
    for (int i=1; i<=events->count(); i++){
        int curEvent = events->get (i);
        switch (curEvent)
        {
        case 1: // MadBear
            /* code */
            break;
        
        case 2: // Bandit

            break;
        
        case 3: // LordLupin
        case 4: // Elf
        case 5: // Troll
        case 6: // Tornbery
        case 7: // Queen of Cards
        case 8: // Nina de Rings
        case 9: // VuonSauRieng
        case 10: // Omega Weapon
        case 11: // Hades
        case 112: // Pho II
        case 113: // Pho III
        case 114: // Pho IV
        case 95: // Pick up Paladin's shield
        case 96: // Pick up Lancelot's spear
        case 97: // Pick up Guinevere's hairpiece
        case 98: // Excalibur
        case 99: // win Ultimecia, or lose, maybe

            return true;
        default:
            cout << "The current event is invalid. Please check input again!";
            break;
        }
    }
    return false; //not defeat Ultimecia in the last event
}

int ArmyKnights::count() const{
    return armyNum;
}

void ArmyKnights::readKnight(string eachKnight, int id){
    stringstream myK(eachKnight);
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

void ArmyKnights::back(){
    BaseKnight *hold = lastKnight();
    tail = tail->pre;
    tail->next=nullptr;
    delete hold;
}

void ArmyKnights::pick_Item(BaseItem * item) const{
    BaseKnight * tmp=tail;
    while (tmp!=nullptr){
        if (item->canUse(tmp)){
            return;
        }
        tmp=tmp->pre;
    }
    delete item;
}

void ArmyKnights::gain_gil(int cash)const{
    BaseKnight * tmp=tail;
    while (tmp!=nullptr){
        if (tmp->can_gain_gil(cash)==0){
            return;
        }
        tmp=tmp->pre;
    }
}

BaseKnight *ArmyKnights:: lastKnight() const{
    return tail;
}

bool ArmyKnights::hasPaladinShield()const{
    //hmm
    return 1;
}

bool ArmyKnights::hasLancelotSpear()const{
    //hmm
    return 1;
}

bool ArmyKnights::hasGuinevereHair() const{
    //hmm
    return 1;
}

bool ArmyKnights::hasExcaliburSword() const{
    //hmm
    return 1;
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

void ArmyKnights::printALL() const{
    BaseKnight *tmp=head;
    while (tmp!=nullptr){
        cout << tmp->toString() << endl;
        tmp=tmp->next;
    }
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure(){
    delete armyKnights;
    delete events;
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
    armyKnights->printALL();
    cout << "Event: ";
    events->printEvent();
    cout << "run!!!"<<endl;
    //bool win = armyKnights->adventure(events);
    //armyKnights->printResult(win);
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
    cout << "deleted Event"<<endl;
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