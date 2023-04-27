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
    this->level=level;
    this->gil=gil;
    this->antidote=antidote;
    //phoenix
    //basebag
    //knightType
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

        myFile.close();
    }
    else cout << "Cannot open the f*cking file!"<<endl;
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

/* * * END implementation of class KnightAdventure * * */