#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "DisableMgr.h"
#include "WorldSession.h"
#include "Player.h"

using namespace std;

class aa_damage_script : public UnitScript
{
private:
//    static std::map<>
public:
    aa_damage_script() : UnitScript("aa_damage_script") { }
    void OnDamage(Unit* attacker, Unit* victim, uint32& damage) override
    {
//        if (victim->GetEntry() == ) {
//            
//        }
    }
};

void AddAA_Damage_Script()
{
    new aa_damage_script();
}
