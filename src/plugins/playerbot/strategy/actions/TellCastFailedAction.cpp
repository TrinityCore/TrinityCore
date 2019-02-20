#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TellCastFailedAction.h"


using namespace ai;

bool TellCastFailedAction::Execute(Event event)
{
    WorldPacket p(event.getPacket());
    p.rpos(0);
    uint8 castCount, result;
    uint32 spellId;
    p >> castCount >> spellId >> result;
    ai->SpellInterrupted(spellId);

    if (result == SPELL_CAST_OK)
        return false;

    const SpellInfo *const pSpellInfo =  sSpellMgr->GetSpellInfo(spellId);
    ostringstream out; out << chat->formatSpell(pSpellInfo) << ": ";
    switch (result)
    {
    case SPELL_FAILED_NOT_READY:
        out << "not ready";
        break;
    case SPELL_FAILED_REQUIRES_SPELL_FOCUS:
        out << "requires spell focus";
        break;
    case SPELL_FAILED_REQUIRES_AREA:
        out << "cannot cast here";
        break;
    case SPELL_FAILED_TOTEMS:
    case SPELL_FAILED_TOTEM_CATEGORY:
        out << "requires totem";
        break;
    case SPELL_FAILED_EQUIPPED_ITEM_CLASS:
        out << "requires item";
        break;
    case SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND:
    case SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND:
        out << "requires weapon";
        break;
    case SPELL_FAILED_PREVENTED_BY_MECHANIC:
        out << "interrupted";
        break;
    default:
        out << "cannot cast";
    }
    Spell *spell = new Spell(bot, pSpellInfo, TRIGGERED_NONE);
    int32 castTime = spell->GetCastTime();
    delete spell;

    if (castTime >= 2000)
        ai->TellMasterNoFacing(out.str());

    return true;
}


bool TellSpellAction::Execute(Event event)
{
    string spell = event.getParam();
    uint32 spellId = AI_VALUE2(uint32, "spell id", spell);
    if (!spellId)
        return false;

    SpellInfo const *spellInfo = sSpellMgr->GetSpellInfo(spellId );
    if (!spellInfo)
        return false;

    ostringstream out; out << chat->formatSpell(spellInfo);
    ai->TellMaster(out);
    return true;
}
