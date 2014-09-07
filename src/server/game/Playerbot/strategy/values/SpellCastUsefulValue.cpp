#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "SpellCastUsefulValue.h"
#include "LastSpellCastValue.h"

using namespace ai;

bool SpellCastUsefulValue::Calculate()
{
    uint32 spellid = AI_VALUE2(uint32, "spell id", qualifier);
	if (!spellid)
		return true; // there can be known alternatives

	SpellInfo const *spellInfo = sSpellMgr->GetSpellInfo(spellid);
	if (!spellInfo)
		return true; // there can be known alternatives

	if (spellInfo->Attributes & SPELL_ATTR0_ON_NEXT_SWING ||
		spellInfo->Attributes & SPELL_ATTR0_ON_NEXT_SWING_2)
	{
		Spell* spell = bot->GetCurrentSpell(CURRENT_MELEE_SPELL);
		if (spell && spell->m_spellInfo->Id == spellid && spell->IsNextMeleeSwingSpell())
			return false;
	}

    uint32 lastSpellId = AI_VALUE(LastSpellCast&, "last spell cast").id;
    if (spellid == lastSpellId)
    {
        Spell* const pSpell = bot->FindCurrentSpellBySpellId(lastSpellId);
        if (pSpell)
            return false;
    }

    // TODO: workaround
    if (qualifier == "windfury weapon" || qualifier == "flametongue weapon" || qualifier == "frostbrand weapon" ||
            qualifier == "rockbiter weapon" || qualifier == "earthliving weapon" || qualifier == "spellstone")
    {
        Item *item = AI_VALUE2(Item*, "item for spell", spellid);
        if (item && item->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT))
            return false;
    }

	return true;
}
