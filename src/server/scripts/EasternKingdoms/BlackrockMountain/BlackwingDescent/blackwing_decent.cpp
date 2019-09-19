/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GameObjectAI.h"
#include "GameObject.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "blackwing_descent.h"

struct go_bwd_ancient_bell : public GameObjectAI
{
    go_bwd_ancient_bell(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool GossipHello(Player* /*player*/) override
    {
        if (_instance->GetData(DATA_ATRAMEDES_INTRO) == DONE)
            return true;

        if (GameObject* bell = me->ToGameObject())
        {
            _instance->SetData(DATA_ATRAMEDES_INTRO, DONE);
            me->SendCustomAnim(0);
            me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

            if (Creature* column = _instance->GetCreature(DATA_COLUMN_OF_LIGHT))
                column->DespawnOrUnsummon();

            me->DespawnOrUnsummon(7s + 400ms);
        }
        return true;
    }
private:
    InstanceScript* _instance;
};

enum DragonOrb
{
    SPELL_DRAGON_ORB_1 = 78219
};

Position const DragonOrb1Offset = { -28.80208f, -216.4497f, 71.34686f };
Position const DragonOrb2Offset = { -28.80208f, -232.4497f, 71.34686f };

class spell_bwd_dragon_orb : public SpellScript
{
    PrepareSpellScript(spell_bwd_dragon_orb);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRAGON_ORB_1 });
    }

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        if (GetSpellInfo()->Id == SPELL_DRAGON_ORB_1)
            dest.Relocate(DragonOrb1Offset);
        else
            dest.Relocate(DragonOrb2Offset);
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_bwd_dragon_orb::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

class at_bwd_intro: public AreaTriggerScript
{
    public:
        at_bwd_intro() : AreaTriggerScript("at_bwd_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript * instance = player->GetInstanceScript())
                instance->SetData(DATA_ENTRANCE_INTRO, IN_PROGRESS);
            return true;
        }
};

void AddSC_blackwing_descent()
{
    RegisterGameObjectAI(go_bwd_ancient_bell);
    RegisterSpellScript(spell_bwd_dragon_orb);
    new at_bwd_intro();
}
