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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "halls_of_valor.h"

enum odynHoVSpells
{
    SPELL_RADIANT_TEMPEST       = 198263,
    SPELL_SPEAR_OF_LIGHT        = 198072,
    SPELL_SPEAR_OF_LIGHT_DMG    = 200988,
    SPELL_SHATTER_SPEARS        = 231013,
    SPELL_SHATTER_SPEARS_DMG    = 231019,
    SPELL_GLOWING_FRAGMENTS     = 198088,
    SPELL_RUNIC_BRAND           = 197961,
    SPELL_UNWORTHY              = 198190,
    SPELL_STORMFORGED           = 201215,
    SPELL_SURGE                 = 198750,
    SPELL_RUNIC_MARK1           = 197963,
    SPELL_RUNIC_MARK2           = 197964,
    SPELL_RUNIC_MARK3           = 197965,
    SPELL_RUNIC_MARK4           = 197966,
    SPELL_RUNIC_MARK5           = 197967,
    SPELL_RUNIC_MARK_AT1        = 197968,
    SPELL_RUNIC_MARK_AT2        = 197971,
    SPELL_RUNIC_MARK_AT3        = 197972,
    SPELL_RUNIC_MARK_AT4        = 197975,
    SPELL_RUNIC_MARK_AT5        = 197977,
    SPELL_BRANDED               = 197996,
    SPELL_AEGIS_SUMMON          = 193781,
};

enum odynHoVEvents
{
    EVENT_RADIANT_TEMPEST = 1,
    EVENT_SPEAR_OF_LIGHT,
    EVENT_SHATTER_SPEARS,
    EVENT_GLOWING_FRAGMENTS,
    EVENT_RUNIC_BRAND,
    EVENT_UNWORTHY,
    EVENT_STORMFORGED,
    EVENT_SURGE,
    EVENT_START_TALK,
    EVENT_TALK,
    EVENT_SAY_PRE_COMBAT,
};

enum odynHoVSays
{
    SAY_EVENT_1         = 1,
    SAY_EVENT_2         = 10,
    SAY_PRE_COMBAT      = 2,
    SAY_COMBAT_START    = 3,
};

struct boss_odyn_hov : public BossAI
{
    boss_odyn_hov(Creature* creature) : BossAI(creature, DATA_ODYN)
    {
        me->SetReactState(REACT_DEFENSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->setFaction(35);
        me->SetCanFly(false);
    }

    std::list<Creature*> creatureList;
    bool canSummonSpear = true;
    bool startCombat = false;
    bool startEvent = false;
    uint8 spearOfLightCount;
    uint8 players = 1;
    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();

    void Reset() override
    {
        _Reset();

        me->SetReactState(REACT_DEFENSIVE);

        spearOfLightCount = 0;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        me->SetWalk(true);

        events.ScheduleEvent(EVENT_RADIANT_TEMPEST, 60 * IN_MILLISECONDS);
        events.ScheduleEvent(EVENT_SPEAR_OF_LIGHT, 8 * IN_MILLISECONDS);
    }

    void UpdateAI(uint32 diff) override
    {
        if (instance->GetBossState(DATA_KING_RANULF) == DONE
            && instance->GetBossState(DATA_KING_HALDOR) == DONE
            && instance->GetBossState(DATA_KING_BJORN) == DONE
            && instance->GetBossState(DATA_KING_TOR) == DONE && !startEvent)
        {
            Talk(SAY_EVENT_1);

            me->SummonCreature(98364, 2402.76f, 528.64f, 748.99f, 0.0f, TEMPSUMMON_MANUAL_DESPAWN);

            events.ScheduleEvent(EVENT_START_TALK, 5 * IN_MILLISECONDS);
            startEvent = true;
        }

        if (instance->GetBossState(DATA_KING_RANULF) == DONE
            && instance->GetBossState(DATA_KING_HALDOR) == DONE
            && instance->GetBossState(DATA_KING_BJORN) == DONE
            && instance->GetBossState(DATA_KING_TOR) == DONE
            && instance->GetBossState(DATA_GODKING_SKOVALD) == DONE && !startCombat)
        {
            Talk(SAY_PRE_COMBAT);

            startCombat = true;
            events.ScheduleEvent(EVENT_SAY_PRE_COMBAT, 7 * IN_MILLISECONDS);
        }

        if (!UpdateVictim() && me->IsInCombat())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RADIANT_TEMPEST:
                    DoCast(SPELL_RADIANT_TEMPEST);

                    canSummonSpear = false;

                    events.ScheduleEvent(EVENT_RADIANT_TEMPEST, 60 * IN_MILLISECONDS);
                    break;

                case EVENT_SPEAR_OF_LIGHT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    {
                        me->CastSpell(target, SPELL_SPEAR_OF_LIGHT, true);
                        ++spearOfLightCount;
                        if (spearOfLightCount >= 3)
                        {
                            spearOfLightCount = 0;
                            events.ScheduleEvent(EVENT_SHATTER_SPEARS, 1 * IN_MILLISECONDS);
                        }
                    }

                    if (canSummonSpear)
                        events.ScheduleEvent(EVENT_SPEAR_OF_LIGHT, 8 * IN_MILLISECONDS);

                    break;

                case EVENT_SHATTER_SPEARS:
                    DoCast(SPELL_SHATTER_SPEARS);

                    events.ScheduleEvent(EVENT_RUNIC_BRAND, 1 * IN_MILLISECONDS);
                    break;

                case EVENT_RUNIC_BRAND:

                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (Player *player = i->GetSource())
                            {
                                if (player->IsAlive() && player->GetDistance(me) <= 150.0f)
                                {
                                    if (players == 1)
                                        me->AddAura(SPELL_RUNIC_MARK1, player);
                                    else if (players == 2)
                                        me->AddAura(SPELL_RUNIC_MARK2, player);
                                    else if (players == 3)
                                        me->AddAura(SPELL_RUNIC_MARK3, player);
                                    else if (players == 4)
                                        me->AddAura(SPELL_RUNIC_MARK4, player);
                                    else if (players == 5)
                                        me->AddAura(SPELL_RUNIC_MARK5, player);

                                    ++players;
                                }
                            }
                        }
                    }

                    me->CastSpell(2437.733f, 497.3854f, 749.4288f, SPELL_RUNIC_MARK_AT1, true);
                    me->CastSpell(2403.48f, 509.241f, 749.66f, SPELL_RUNIC_MARK_AT2, true);
                    me->CastSpell(2403.48f, 547.997f, 749.716f, SPELL_RUNIC_MARK_AT3, true);
                    me->CastSpell(2437.67f, 559.781f, 749.638f, SPELL_RUNIC_MARK_AT4, true);
                    me->CastSpell(2461.51f, 528.667f, 749.589f, SPELL_RUNIC_MARK_AT5, true);

                    break;

                case EVENT_UNWORTHY:
                    break;

                case EVENT_STORMFORGED:
                    break;

                case EVENT_SURGE:
                    break;

                case EVENT_START_TALK:
                    if (Creature* kovald = instance->GetCreature(BOSS_GOD_KING_SKOVALD))
                        kovald->AI()->DoAction(ACTION_EVENT_START);

                    events.ScheduleEvent(EVENT_TALK, 12 * IN_MILLISECONDS);
                    break;

                case EVENT_TALK:
                    Talk(SAY_EVENT_2);

                    break;

                case EVENT_SAY_PRE_COMBAT:
                    me->setFaction(14);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetWalk(false);
                    me->GetMotionMaster()->MoveJump(2402.76f, 528.64f, 748.99f, 0.0f, 20.0f, 5.0f);
                    me->SetHomePosition(2402.76f, 528.64f, 748.99f, 0.0f);
                    Talk(SAY_COMBAT_START);
                    break;

                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct areatrigger_glowing_fragment : AreaTriggerAI
{
    areatrigger_glowing_fragment(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        Position pos;
        GetPositionWithDistInFront(at, 40.f, pos);

        at->SetDestination(pos, at->GetDuration());
    }
};

struct areatrigger_runic_mark_1 : AreaTriggerAI
{
    areatrigger_runic_mark_1(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Player* player = unit->ToPlayer())
        {
            if (player->HasAura(SPELL_RUNIC_MARK1))
            {
                player->RemoveAurasDueToSpell(SPELL_RUNIC_MARK1);
                player->CastSpell(player, SPELL_BRANDED, true);
            }
        }
    }
};

struct areatrigger_runic_mark_2 : AreaTriggerAI
{
    areatrigger_runic_mark_2(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Player* player = unit->ToPlayer())
        {
            if (player->HasAura(SPELL_RUNIC_MARK2))
            {
                player->RemoveAurasDueToSpell(SPELL_RUNIC_MARK2);
                player->CastSpell(player, SPELL_BRANDED, true);
            }
        }
    }
};

struct areatrigger_runic_mark_3 : AreaTriggerAI
{
    areatrigger_runic_mark_3(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Player* player = unit->ToPlayer())
        {
            if (player->HasAura(SPELL_RUNIC_MARK3))
            {
                player->RemoveAurasDueToSpell(SPELL_RUNIC_MARK3);
                player->CastSpell(player, SPELL_BRANDED, true);
            }
        }
    }
};

struct areatrigger_runic_mark_4 : AreaTriggerAI
{
    areatrigger_runic_mark_4(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit->GetTypeId() != TYPEID_PLAYER)
            return;

        if (Player* player = unit->ToPlayer())
        {
            if (player->HasAura(SPELL_RUNIC_MARK4))
            {
                player->RemoveAurasDueToSpell(SPELL_RUNIC_MARK4);
                player->CastSpell(player, SPELL_BRANDED, true);
            }
        }
    }
};

struct areatrigger_runic_mark_5 : AreaTriggerAI
{
    areatrigger_runic_mark_5(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Player* player = unit->ToPlayer())
        {
            if (player->HasAura(SPELL_RUNIC_MARK5))
            {
                player->RemoveAurasDueToSpell(SPELL_RUNIC_MARK5);
                player->CastSpell(player, SPELL_BRANDED, true);
            }
        }
    }
};

// 198072 - Spear of Light
class spell_odyn_spear_of_light : public SpellScript
{
    PrepareSpellScript(spell_odyn_spear_of_light);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetHitUnit())
                caster->CastSpell(target, 198060, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_odyn_spear_of_light::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 100575 - Spear of Light
struct npc_spear_of_light : public ScriptedAI
{
    npc_spear_of_light(Creature* creature) : ScriptedAI(creature) { }

    void Reset()
    {
        me->SetLevel(110);
        me->CastSpell(me, 198059, true);
        me->setFaction(14);
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(11686);
        me->DespawnOrUnsummon(30000);
    }
};

struct areatrigger_spear_of_light : AreaTriggerAI
{
    areatrigger_spear_of_light(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Player* player = unit->ToPlayer())
            if (!player->HasAura(SPELL_SPEAR_OF_LIGHT_DMG))
                player->CastSpell(player, SPELL_SPEAR_OF_LIGHT_DMG, true);
    }

    void OnUnitExit(Unit* unit)
    {
        unit->RemoveAurasDueToSpell(SPELL_SPEAR_OF_LIGHT_DMG);
    }
};

void AddSC_boss_odyn_hov()
{
    RegisterCreatureAI(boss_odyn_hov);
    RegisterAreaTriggerAI(areatrigger_glowing_fragment);
    RegisterAreaTriggerAI(areatrigger_runic_mark_1);
    RegisterAreaTriggerAI(areatrigger_runic_mark_2);
    RegisterAreaTriggerAI(areatrigger_runic_mark_3);
    RegisterAreaTriggerAI(areatrigger_runic_mark_4);
    RegisterAreaTriggerAI(areatrigger_runic_mark_5);
    RegisterSpellScript(spell_odyn_spear_of_light);
    RegisterCreatureAI(npc_spear_of_light);
    RegisterAreaTriggerAI(areatrigger_spear_of_light);
}
