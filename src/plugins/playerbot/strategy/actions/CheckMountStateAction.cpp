#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "../../../Spells/Auras/SpellAuraEffects.h"
#include "CheckMountStateAction.h"

using namespace ai;

uint64 extractGuid(WorldPacket& packet);

bool CheckMountStateAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!bot->GetGroup() || !master)
        return false;

    if (bot->IsFlying())
        return false;

    if (master->IsMounted() && !bot->IsMounted())
    {
        return Mount();
    }
    else if (!master->IsMounted() && bot->IsMounted())
    {
        WorldPacket emptyPacket;
        bot->GetSession()->HandleCancelMountAuraOpcode(emptyPacket);
        return true;
    }
    return false;
}


bool CheckMountStateAction::Mount()
{
    Player* master = GetMaster();
    ai->RemoveShapeshift();

    Unit::AuraEffectList const& auras = master->GetAuraEffectsByType(SPELL_AURA_MOUNTED);
    if (auras.empty()) return false;
    AuraEffect* front = auras.front();
    if (!front) return false;

    const SpellInfo* masterSpell = front->GetSpellInfo();
    int32 masterSpeed = max(masterSpell->Effects[1].BasePoints, masterSpell->Effects[2].BasePoints);

    map<uint32, map<int32, vector<uint32> > > allSpells;
    for(PlayerSpellMap::iterator itr = bot->GetSpellMap().begin(); itr != bot->GetSpellMap().end(); ++itr)
    {
        uint32 spellId = itr->first;
        const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);

        if (!spellInfo || spellInfo->Effects[0].ApplyAuraName != SPELL_AURA_MOUNTED)
            continue;

        if(itr->second->state == PLAYERSPELL_REMOVED || itr->second->disabled || spellInfo->IsPassive())
            continue;

        int32 effect = max(spellInfo->Effects[1].BasePoints, spellInfo->Effects[2].BasePoints);
        if (effect < masterSpeed)
            continue;

        uint32 index = (spellInfo->Effects[1].ApplyAuraName == SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED ||
                spellInfo->Effects[2].ApplyAuraName == SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) ? 1 : 0;
        allSpells[index][effect].push_back(spellId);
    }

    int masterMountType = (masterSpell->Effects[1].ApplyAuraName == SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED ||
            masterSpell->Effects[2].ApplyAuraName == SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) ? 1 : 0;

    map<int32, vector<uint32> >& spells = allSpells[masterMountType];
    for (map<int32,vector<uint32> >::iterator i = spells.begin(); i != spells.end(); ++i)
    {
		vector<uint32>& ids = i->second;
        int index = urand(0, ids.size() - 1);
        if (index >= ids.size())
            continue;

        ai->CastSpell(ids[index], bot);
        return true;
    }

    return false;
}
