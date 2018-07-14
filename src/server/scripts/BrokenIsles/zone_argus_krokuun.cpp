/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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


#include "ScriptMgr.h"
#include "Player.h"
#include "SpellMgr.h"

enum
{
    ZONE_KROKUUN            = 8574,
    AREA_KROKUUN_VINDICAAR  = 8714
};

// Zone 8574
class zone_argus_krokuun : public ZoneScript
{
public:
    zone_argus_krokuun() : ZoneScript("zone_argus_krokuun") { }

    void OnPlayerEnter(Player* player) override
    {
        player->GetScheduler().Schedule(Milliseconds(2s), ZONE_KROKUUN, [](TaskContext context)
        {
            if (Player* player = GetContextPlayer())
                if (player->GetAreaId() == AREA_KROKUUN_VINDICAAR)
                    if (player->GetPositionZ() <= 700.0f)
                        player->NearTeleportTo(383.17f, 1413.87f, 770.0f, 0.438168f);

            context.Repeat();
        });
    }

    void OnPlayerExit(Player* player) override
    {
        player->GetScheduler().CancelGroup(ZONE_KROKUUN);
    }
};

// 251924
class spell_garothi_obliterator_fiery_mortars : public SpellScript
{
    PrepareSpellScript(spell_garothi_obliterator_fiery_mortars);

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_garothi_obliterator_fiery_mortars::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 125820
struct npc_imp_mother_laglath : public ScriptedAI
{
    npc_imp_mother_laglath(Creature* creature) : ScriptedAI(creature) {}

    enum SpellData
    {
        SPELL_ELDER_WRATH   = 251683,
        SPELL_MATRON_RAGE   = 251689,
        SPELL_WRATH_BOLT    = 251703
    };

    void Reset() override
    {
        me->GetScheduler().SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });

        me->GetScheduler().Schedule(20s, [this](TaskContext context)
        {
            GetContextUnit()->CastSpell(nullptr, SPELL_MATRON_RAGE, false);
            context.Repeat();
        })
        .Schedule(3s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                GetContextUnit()->CastSpell(target, SPELL_WRATH_BOLT, false);
            context.Repeat();
        })
        .Schedule(1s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                if (me->IsWithinCombatRange(target, 5.f))
                    GetContextUnit()->CastSpell(target, SPELL_ELDER_WRATH, false);

            context.Repeat();
        });
    }
};

void AddSC_zone_argus_krokuun()
{
    new zone_argus_krokuun();
    RegisterSpellScript(spell_garothi_obliterator_fiery_mortars);
    RegisterCreatureAI(npc_imp_mother_laglath);
}
