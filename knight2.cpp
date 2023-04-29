#include "knight2.h"

/* * * BEGIN implementation of class BaseBag * * */

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
BaseKnight *BaseKnight::create (int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    BaseKnight *hold = new BaseKnight (id, maxhp, level, gil, antidote, phoenixdownI);
    return hold;
}

BaseKnight::BaseKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    this->id=id;
    this->maxhp=maxhp;
    this->hp=maxhp;
    this->level=level;
    this->gil=gil;
    this->antidote=antidote;
    checkKnight(); // knightType
    bag=nullptr;
    //phoenix
}

BaseKnight::~BaseKnight(){
    delete [] next;
    delete [] bag;
}

void BaseKnight::checkKnight(){
    if (prime(hp)) {
        knightType=PALADIN;
        return;
    }
    if (hp==888){
        knightType=LANCELOT;
        return;
    }
    if(pythago(hp)){
        knightType=DRAGON;
        return;
    }
    knightType=NORMAL;
    return;
}

bool BaseKnight::prime(int hacPe) {
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

bool BaseKnight::pythago(int num){
    if (num>999 || num<100) return false;
    int a = num / 100;
    int b = (num / 10) % 10;
    int c = num % 10;
    if (pow(c,2)==pow(a,2)+pow(b,2)) return true;
    if (pow(b,2)==pow(a,2)+pow(c,2)) return true;
    if (pow(a,2)==pow(c,2)+pow(b,2)) return true;
    return false;
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
    delete [] head;
}

bool ArmyKnights::fight(BaseOpponent * opponent){
    //hmm
}

bool ArmyKnights::adventure(Events *events){
    //hmm
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
}
void KnightAdventure::loadArmyKnights(const string & file){
    armyKnights = new ArmyKnights(file);
}
void KnightAdventure::loadEvents(const string & file){
    events = new Events(file);
}
void KnightAdventure::run(){
    cout << "run!!!"<<endl;
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
}
int Events::count() const{
    return eNum;
}
int Events::get(int i) const{
    return eArr[i];
}
/* * * END implementation of class Events * * */