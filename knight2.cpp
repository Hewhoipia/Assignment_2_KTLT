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
    BaseItem *hold=head;
    head = item;
    head->next=hold;
    if(hold!=nullptr)hold->pre=head;
    curItems++;
    return 1;
}

BaseBag::BaseBag(int PhoxeI, int Antinek){
    while (PhoxeI>0 && curItems<nItem){
        BaseItem * item = new PhoenixDown(PhoI);
        insertFirst(item);
        PhoxeI--;
        curItems++;
    }
    while (Antinek>0 && curItems<nItem){
        BaseItem * item = new Antidote();
        insertFirst(item);
        Antinek--;
        curItems++;
    }
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

BaseItem* BaseBag::get (ItemType itemType){
    if (itemType==PhoI){
        BaseItem * tmp=head;
        while (tmp!=nullptr){
            if (tmp->type==PhoI || tmp->type==PhoII || tmp->type==PhoIII || tmp->type==PhoIV){
                if (tmp==head){
                    head=head->next;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
                else if (tmp==head->next){
                    tmp->pre=nullptr;
                    head->next=tmp->next;
                    if(tmp->next!=nullptr) tmp->next->pre=head;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
                else{
                    BaseItem * hold=head->next;
                    tmp->pre->next=head;
                    if(tmp->next!=nullptr)tmp->next->pre=head;
                    head->pre=tmp->pre;
                    head->next=tmp->next;
                    tmp->pre=nullptr;
                    tmp->next=nullptr;
                    head=hold;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
            }
            tmp=tmp->next;
        }
        return nullptr;
    }
    else if (itemType==PhoII){
        BaseItem * tmp=head;
        while (tmp!=nullptr){
            if (tmp->type==PhoII || tmp->type==PhoIII || tmp->type==PhoIV){
                if (tmp==head){
                    head=head->next;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
                else if (tmp==head->next){
                    tmp->pre=nullptr;
                    head->next=tmp->next;
                    if(tmp->next!=nullptr) tmp->next->pre=head;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
                else{
                    BaseItem * hold=head->next;
                    tmp->pre->next=head;
                    if(tmp->next!=nullptr)tmp->next->pre=head;
                    head->pre=tmp->pre;
                    head->next=tmp->next;
                    tmp->pre=nullptr;
                    tmp->next=nullptr;
                    head=hold;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
            }
            tmp=tmp->next;
        }
        return nullptr;
    }
     else if (itemType==PhoIII){
        BaseItem * tmp=head;
        while (tmp!=nullptr){
            if (tmp->type==PhoIII || tmp->type==PhoIV){
                if (tmp==head){
                    head=head->next;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
                else if (tmp==head->next){
                    tmp->pre=nullptr;
                    head->next=tmp->next;
                    if(tmp->next!=nullptr) tmp->next->pre=head;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
                else{
                    BaseItem * hold=head->next;
                    tmp->pre->next=head;
                    if(tmp->next!=nullptr)tmp->next->pre=head;
                    head->pre=tmp->pre;
                    head->next=tmp->next;
                    tmp->pre=nullptr;
                    tmp->next=nullptr;
                    head=hold;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
            }
            tmp=tmp->next;
        }
        return nullptr;
    }
     else{
        BaseItem * tmp=head;
        while (tmp!=nullptr){
            if (tmp->type==itemType){
                if (tmp==head){
                    head=head->next;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
                else if (tmp==head->next){
                    tmp->pre=nullptr;
                    head->next=tmp->next;
                    if(tmp->next!=nullptr) tmp->next->pre=head;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
                else{
                    BaseItem * hold=head->next;
                    tmp->pre->next=head;
                    if(tmp->next!=nullptr)tmp->next->pre=head;
                    head->pre=tmp->pre;
                    head->next=tmp->next;
                    tmp->pre=nullptr;
                    tmp->next=nullptr;
                    head=hold;
                    tmp->next=nullptr;
                    curItems--;
                    return tmp;
                }
            }
            tmp=tmp->next;
        }
        return nullptr;
    }
}

string BaseBag::toString()const{
    string list_item="";
    BaseItem * tmp=head;
    while (tmp!=nullptr){
        ItemType type=tmp->type;
        switch (type)
        {
        case Anti:
            list_item+="Antidote,";
            break;
        case PhoI:
            list_item+="PhoenixI,";
            break;
        case PhoII:
            list_item+="PhoenixII,";
            break;
        case PhoIII:
            list_item+="PhoenixIII,";
            break;
        case PhoIV:
            list_item+="PhoenixIV,";
            break;
        default:
            break;
        }
        tmp=tmp->next;
    }
    if (curItems > 0){
        list_item.erase(list_item.end());
    }
    string s="Bag[count=" + nItem + (char)59 + list_item + "]";
    return s;
}

bool BaseBag::is_Full() const{
    if (nItem == -1 || curItems < nItem){
        return 0;
    }
    else return 1;
}

void BaseBag::front(){
    BaseItem * tmp = head;
    if (curItems==1) {
        delete head;
        head=nullptr;
        curItems--;
    }
    else if (curItems>1){
        head=head->next;
        head->pre=nullptr;
        delete tmp;
        curItems--;
    }
}

// class DBag
    DBag::DBag(int PhoxeI):BaseBag(PhoI, 0){
        nItem=14;
    }

//class LBag
    LBag::LBag(int PhoxeI, int Anti):BaseBag(PhoxeI, Anti){
        nItem=16;
    }

//class NBag
    NBag::NBag(int PhoxeI, int Anti):BaseBag(PhoxeI, Anti){
        nItem=19;
    }

//class PBag
    PBag::PBag(int PhoxeI, int Anti):BaseBag(PhoxeI, Anti){
        nItem=-1; // infinite number
    }

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseItem * * */
BaseItem::BaseItem(){}

BaseItem::~BaseItem(){
    cout << "deleted Item"<<endl;
}

bool BaseItem::canAddI(BaseKnight *knight){
    if (knight->can_Add(this)) return 1;
    return 0;
}

Antidote::Antidote(){
        type=Anti;
    }
bool Antidote::canUse (BaseKnight *knight){
    // do nth
    return 1;
}
void Antidote::use ( BaseKnight * knight ){
    // nothing here
}

PhoenixDown::PhoenixDown(ItemType Pho_Type){
    type=Pho_Type;
}
bool PhoenixDown::canUse (BaseKnight *knight){
    // do nth
    return 1;
}
void PhoenixDown::use ( BaseKnight * knight ){
    // nothing here
}

/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class BaseOpponent * * */

class MadBear:public BaseOpponent{
public:
    MadBear(int i, int eventid){
        gil=100;
        baseDmg=10;
        lvo=(i+eventid)%10+1;
        type=MB;
    }
};

class Bandit:public BaseOpponent{
public:
    Bandit(int i, int eventid){
        gil=150;
        baseDmg=15;
        lvo=(i+eventid)%10+1;
        type=Ban;
    }
};

class LordLupin:public BaseOpponent{
public:
    LordLupin(int i, int eventid){
        gil=450;
        baseDmg=45;
        lvo=(i+eventid)%10+1;
        type=Lupin;
    }
};

class Elf:public BaseOpponent{
public:
    Elf(int i, int eventid){
        gil=750;
        baseDmg=75;
        lvo=(i+eventid)%10+1;
        type=E;
    }
};

class Troll:public BaseOpponent{
public:
    Troll(int i, int eventid){
        gil=800;
        baseDmg=95;
        lvo=(i+eventid)%10+1;
        type=Tr;
    }
};

class Tornbery:public BaseOpponent{
public:
    Tornbery(int i, int eventid){
        gil=baseDmg=0;
        lvo=(i+eventid)%10+1;
        type=Torn;
    }
};

class QueenOfCards:public BaseOpponent{
public:
    QueenOfCards(int i, int eventid){
        gil=baseDmg=0;
        lvo=(i+eventid)%10+1;
        type=Queen;
    }
};

class OmegaWeapon:public BaseOpponent{
public:
    OmegaWeapon(int i, int eventid){
        gil=baseDmg=0;
        lvo=10;
        type=Omega;
    }
};

class Hades:public BaseOpponent{
public:
    Hades(int i, int eventid){
        gil=baseDmg=0;
        lvo=10;
        type=Ha;
    }
};

class Ultimecia:public BaseOpponent{
public:
    Ultimecia(int i, int eventid){
        gil=baseDmg=0;
        lvo=0;
        type=Ulti;
    }
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

bool BaseKnight::is_dead()const{
    if (hp>0)return 0;
    return 1;
}

void BaseKnight::use_item(BaseItem * item){
    switch (item->type)
    {
    case PhoI:
        hp=maxhp;
        break;
    case PhoII:
        hp=maxhp;
        break;
    case PhoIII:
        if (hp<=0) hp=maxhp/3;
        else hp+=maxhp/4;
        break;
    case PhoIV:
        if (hp<=0) hp=maxhp/2;
        else hp+=maxhp/5;
        break;
    case Anti:
        antidote--;
        break;
    default:
        break;
    }
    if (hp>maxhp) hp=maxhp;
    delete item;
}

void BaseKnight::modify_hp(){
    if (hp<maxhp/2){
        BaseItem * item = bag->get(PhoIV);
        if (item!=nullptr){
            use_item(item);
        }
    }
    else if (hp<maxhp/3){
        BaseItem * item = bag->get(PhoIII);
        if (item!=nullptr){
            use_item(item);
        }
    }
    else if (hp<maxhp/4){
        BaseItem * item = bag->get(PhoII);
        if (item!=nullptr){
            use_item(item);
        }
    }
    else if (hp<=0){
        BaseItem * item = bag->get(PhoI);
        if (item!=nullptr){
            use_item(item);
        }
    }
    if (hp<=0 && gil >= 100){
        gil-=100;
        hp=maxhp/2;
    }
}

bool BaseKnight::be_Poison(){
    BaseItem * item = bag->get(Anti);
    if (item!=nullptr){
        use_item(item);
        return 0;
    }
    return 1;
}

void BaseKnight::nina_de_rings(){
    if (knightType==PALADIN){
        if (hp<maxhp/3) hp+=(maxhp/5);
    }
    if (gil<50){
        return;
    }
    else {
        if(hp<maxhp/3){
            gil-=50;
            hp+=(maxhp/5);
        }
    }
}

void BaseKnight::sau_rieng(){
    hp=maxhp;
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
    bag=new PBag (phoenixdownI, antidote);
}

bool PaladinKnight::fight(BaseOpponent * opponent){
    if (opponent->type==Ulti){
        opponent->hp-=(hp*level*0.06);
        if (opponent->hp <= 0) return 1;
        hp=0;
        return 0;
    }
    if (opponent->type==MB || opponent->type==Ban || opponent->type==Lupin
        || opponent->type==E || opponent->type==Tr) return 1;
    if (opponent->type==Ha && level>=8) return 1;
    if (this->level>=opponent->lvo){
        if (opponent->type==Torn && level<10)level++;
        if (opponent->type==Queen) opponent->gil=gil;
        if (opponent->type==Omega){
            if (hp==maxhp){ // win branch
                level=10;
                gil=999;
            }
            else { // lose branch
                hp=0;
                modify_hp();
                return 0;
            }
        }
        return 1;
    }
    else{
        if (opponent->type==Torn){
            if (be_Poison()){
                for (int i=0; i<3; i++){
                    bag->front();
                }
                hp=hp-10;
                modify_hp();
            }
        }
        else if (opponent->type==Ha) {
            hp=0;
            modify_hp();
        }
        else{
            hp=hp - opponent->baseDmg*(opponent->lvo-level);
            modify_hp();
        }
        return 0;
    }
}

LancelotKnight::LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
    knightType=LANCELOT;
    bag=new LBag(phoenixdownI, antidote);
}

bool LancelotKnight::fight (BaseOpponent * opponent){
    if (opponent->type==Ulti){
        opponent->hp-=(hp*level*0.05);
        if (opponent->hp <= 0) return 1;
        hp=0;
        return 0;
    }
    if (opponent->type==MB || opponent->type==Ban || opponent->type==Lupin
        || opponent->type==E || opponent->type==Tr) return 1;
    if (this->level>=opponent->lvo){
        if (opponent->type==Torn && level<10)level++;
        if (opponent->type==Queen) opponent->gil=gil;
        if (opponent->type==Omega){
            if (hp==maxhp){ // win branch
                level=10;
                gil=999;
            }
            else { // lose branch
                hp=0;
                modify_hp();
                return 0;
            }
        }
        return 1;
    }
    else{
        if (opponent->type==Torn){
            if (be_Poison()){
                for (int i=0; i<3; i++){
                    bag->front();
                }
                hp=hp-10;
                modify_hp();
            }
        }
        else if (opponent->type==Queen) gil=gil/2;
        else if (opponent->type==Ha) {
            hp=0;
            modify_hp();
        }
        else{
            hp=hp - opponent->baseDmg*(opponent->lvo-level);
            modify_hp();
        }
        return 0;
    }
}

DragonKnight::DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
    knightType=DRAGON;
    bag=new DBag(phoenixdownI);
}

bool DragonKnight::fight(BaseOpponent * opponent){
    if (opponent->type==Ulti){
        opponent->hp-=(hp*level*0.075);
        if (opponent->hp <= 0) return 1;
        hp=0;
        return 0;
    }
    if (opponent->type==Omega){
        level=10;
        gil=999;
        return 1;
    }
    if (this->level>=opponent->lvo){
        if (opponent->type==Torn && level<10)level++;
        if (opponent->type==Queen) opponent->gil=gil;
        return 1;
    }
    else{
        if (opponent->type==Queen) gil=gil/2;
        else if (opponent->type==Ha) {
            hp=0;
            modify_hp();
        }
        else{
            hp=hp - opponent->baseDmg*(opponent->lvo-level);
            modify_hp();
        }
        return 0;
    }
}

NormalKnight::NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, level, gil, antidote, phoenixdownI){
    knightType=NORMAL;
    bag = new NBag(phoenixdownI, antidote);
}

bool NormalKnight::fight(BaseOpponent * opponent){
    if (opponent->type==Ulti){
        hp=0;
        return 0;
    }
    if (this->level>=opponent->lvo){
        if (opponent->type==Torn && level<10)level++;
        if (opponent->type==Queen) opponent->gil=gil;
        if (opponent->type==Omega){
            if (hp==maxhp){ // win branch
                level=10;
                gil=999;
            }
            else { // lose branch
                hp=0;
                modify_hp();
                return 0;
            }
        }
        return 1;
    }
    else{
        if (opponent->type==Torn){
            if (be_Poison()){
                for (int i=0; i<3; i++){
                    bag->front();
                }
                hp=hp-10;
                modify_hp();
            }
        }
        else if (opponent->type==Queen) gil=gil/2;
        else if (opponent->type==Ha) {
            hp=0;
            modify_hp();
        }
        else{
            hp=hp - opponent->baseDmg*(opponent->lvo-level);
            modify_hp();
        }
        return 0;
    }
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
    if (curKnight==nullptr) return 0;
    if(curKnight->fight(opponent)){
        gain_gil(opponent->gil);
        if (opponent->type==Ha){
            shield=1;
            num_of_tresure++;
        }
    }
    else{
        if (curKnight->is_dead()){
            back();
            if(armyNum==0) return 0;
        }
        if (opponent->type==Ulti) return fight(opponent);
    }
    delete opponent;
    return 1;
}

bool ArmyKnights::adventure(Events * events){
    for (int i=0; i<events->count(); i++){
        BaseOpponent*opponent=nullptr;
        BaseKnight * curKnight = nullptr;
        BaseItem * item = nullptr;
        int curEvent = events->get (i);
        switch (curEvent)
        {
        case 1: // MadBear
            opponent=new MadBear(i, curEvent);
            fight(opponent);
            break;
        case 2: // Bandit
            opponent=new Bandit(i, curEvent);
            fight(opponent);
            break;
        case 3: // LordLupin
            opponent=new LordLupin(i, curEvent);
            fight(opponent);
            break;
        case 4: // Elf
            opponent=new Elf(i, curEvent);
            fight(opponent);
            break;
        case 5: // Troll
            opponent=new Troll(i, curEvent);
            fight(opponent);
            break;
        case 6: // Tornbery
            opponent=new Tornbery(i, curEvent);
            fight(opponent);
            break;
        case 7: // Queen of Cards
            opponent=new QueenOfCards(i, curEvent);
            fight(opponent);
            break;
        case 8: // Nina de Rings
            curKnight = lastKnight();
            curKnight->nina_de_rings();
            break;
        case 9: // VuonSauRieng
            curKnight = lastKnight();
            curKnight->sau_rieng();
            break;
        case 10: // Omega Weapon
            if(!meet_Omega){
                opponent=new OmegaWeapon(i, curEvent);
                fight(opponent);
                meet_Omega=1;
            }
            break;
        case 11: // Hades
            if(!meet_Hades){
                opponent=new Hades(i, curEvent);
                fight(opponent);
                meet_Hades=1;
            }
            break;
        case 112: // Pho II
            item = new PhoenixDown(PhoII);
            pick_Item(item);
            break;
        case 113: // Pho III
            item = new PhoenixDown(PhoIII);
            pick_Item(item);
            break;
        case 114: // Pho IV
            item = new PhoenixDown(PhoIV);
            pick_Item(item);
            break;
        case 95: // Pick up Paladin's shield
            if (!shield){
                shield=1;
                num_of_tresure++;
            }
            break;
        case 96: // Pick up Lancelot's spear
            if (!spear){
                spear=1;
                num_of_tresure++;
            }
            break;
        case 97: // Pick up Guinevere's hairpiece
            if (!hairpiece){
                hairpiece=1;
                num_of_tresure++;
            }
            break;
        case 98: // Excalibur
            if (num_of_tresure==3){
                sword=1;
            }
            break;
        case 99: // win Ultimecia, or lose, maybe
            if (sword) return true;
            else if(num_of_tresure==3){
                opponent=new Ultimecia(i, curEvent);
                if(fight(opponent))return true;
                else return false;
            }
            else return false;
        default:
            cout << "The event "<< i <<" is invalid. Please check input again!";
            break;
        }
        if (armyNum==0) return false;
        printInfo();
    }
    return false; //not defeat Ultimecia still the last event
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
    if (armyNum<=0) return;
    else if (armyNum==1){
        delete head;
        head=tail=nullptr;
        armyNum=0;
    }
    else{
        BaseKnight *hold = lastKnight();
        tail = tail->pre;
        tail->next=nullptr;
        delete hold;
        armyNum--;
    }
}

void ArmyKnights::pick_Item(BaseItem * item) const{
    BaseKnight * tmp=tail;
    while (tmp!=nullptr){
        if (item->canAddI(tmp)){
            return;
        }
        tmp=tmp->pre;
    }
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
    return shield;
}

bool ArmyKnights::hasLancelotSpear()const{
    return spear;
}

bool ArmyKnights::hasGuinevereHair() const{
    return hairpiece;
}

bool ArmyKnights::hasExcaliburSword() const{
    return sword;
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
    bool win = armyKnights->adventure(events);
    armyKnights->printResult(win);
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
        for (int i=0; i<eNum; i++){
            myFile >> eArr[i];
        }
        myFile.close();
    }
    else cout << "Cannot open the f*cking file!"<<endl;
}
Events::~Events(){
    delete eArr;
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
    for (int i=0; i<eNum; i++){
        cout << eArr[i] << " ";
    }
    cout << endl;
}
/* * * END implementation of class Events * * */