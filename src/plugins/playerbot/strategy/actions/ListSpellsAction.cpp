#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ListSpellsAction.h"
#include "../ItemVisitors.h"

using namespace ai;

bool ListSpellsAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    int loc = master->GetSession()->GetSessionDbcLocale();

    std::ostringstream posOut;
    std::ostringstream negOut;

    string filter = event.getParam();

    const std::string ignoreList = ",Opening,Closing,Stuck,Remove Insignia,Opening - No Text,Grovel,Duel,Honorless Target,";
    std::string alreadySeenList = ",";

    for (PlayerSpellMap::iterator itr = bot->GetSpellMap().begin(); itr != bot->GetSpellMap().end(); ++itr) {
        const uint32 spellId = itr->first;

        const SpellInfo* const pSpellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!pSpellInfo)
            continue;

        if (itr->second->state == PLAYERSPELL_REMOVED || itr->second->disabled || pSpellInfo->IsPassive())
            continue;

        //|| name.find("Teleport") != -1

        std::string comp = ",";
        comp.append(pSpellInfo->SpellName[loc]);
        comp.append(",");

        if (!(ignoreList.find(comp) == std::string::npos && alreadySeenList.find(comp) == std::string::npos))
            continue;

        if (!filter.empty() && !strstri(pSpellInfo->SpellName[loc], filter.c_str()))
            continue;

        alreadySeenList += pSpellInfo->SpellName[loc];
        alreadySeenList += ",";

        if (pSpellInfo->IsPositive())
            posOut << " |cffffffff|Hspell:" << spellId << "|h["
            << pSpellInfo->SpellName[loc] << "]|h|r";
        else
            negOut << " |cffffffff|Hspell:" << spellId << "|h["
            << pSpellInfo->SpellName[loc] << "]|h|r";
    }

    ai->TellMaster("here's my non-attack spells:");
    ai->TellMaster(posOut);

    ai->TellMaster("here's my attack spells:");
    ai->TellMaster(negOut);

    return true;
}

