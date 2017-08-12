#include "ScriptPCH.h"

/*   
UPDATE item_template SET spellid_1 = 0,
                   spellcooldown_1 = 0,   
                   spellcategorycooldown_1 = 0,
                   spellcategorycooldown_2 = 0,   
                   spellcategorycooldown_3 = 0,   
                   spellcategorycooldown_4 = 0,   
                   spellcategorycooldown_5 = 0,   
                   ScriptName = "hearthstone_without_cooldown" WHERE entry = 6948;
*/

class hearthstone_without_cooldown : public ItemScript {
public:
    hearthstone_without_cooldown() : ItemScript("hearthstone_without_cooldown") {}

    bool OnUse(Player *p, Item *pItem, SpellCastTargets const &) {
        if ((p->IsInCombat()) || (p->IsInFlight()) || (p->isDead())) {
            p->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
            return false;
        }

        if (p->IsMounted()) {
            p->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, pItem, NULL);
            return false;
        }

        p->CastSpell(p, 8690);
        p->UpdateHomebindTime(IN_MILLISECONDS * 30);

        return false;
    }
};

void AddSC_hearthstone_without_cooldown() {
    new hearthstone_without_cooldown();
}

