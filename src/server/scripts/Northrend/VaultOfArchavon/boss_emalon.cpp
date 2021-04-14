/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "vault_of_archavon.h"

enum EmalonTexts
{
    EMOTE_OVERCHARGE            = 0,
    EMOTE_MINION_RESPAWN        = 1,
    EMOTE_BERSERK               = 2
};

enum EmalonSpells
{
    SPELL_OVERCHARGE            = 64218,    // Cast every 45 sec on a random Tempest Minion
    SPELL_BERSERK               = 26662,

    SPELL_SHOCK                 = 64363,
    SPELL_OVERCHARGED           = 64217,
    SPELL_OVERCHARGED_BLAST     = 64219,    // Cast when Overcharged reaches 10 stacks. Mob dies after that
    SPELL_CHAIN_LIGHTNING       = 64213,
    SPELL_LIGHTNING_NOVA        = 64216
};

enum EmalonEvents
{
    EVENT_CHAIN_LIGHTNING = 1,
    EVENT_LIGHTNING_NOVA,
    EVENT_OVERCHARGE,
    EVENT_BERSERK,
    EVENT_SHOCK
};

enum EmalonMisc
{
    NPC_TEMPEST_MINION          = 33998,
    MAX_TEMPEST_MINIONS         = 4
};

Position const TempestMinions[MAX_TEMPEST_MINIONS] =
{
    {-203.980103f, -281.287720f, 91.650223f, 1.598807f},
    {-233.489410f, -281.139282f, 91.652412f, 1.598807f},
    {-233.267578f, -297.104645f, 91.681915f, 1.598807f},
    {-203.842529f, -297.097015f, 91.745163f, 1.598807f}
};

struct boss_emalon : public BossAI
{
    boss_emalon(Creature* creature) : BossAI(creature, DATA_EMALON) { }

    void Reset() override
    {
        _Reset();

        for (uint8 i = 0; i < MAX_TEMPEST_MINIONS; ++i)
            me->SummonCreature(NPC_TEMPEST_MINION, TempestMinions[i], TEMPSUMMON_CORPSE_DESPAWN);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (!summons.empty())
        {
            for (SummonList::const_iterator itr = summons.begin(); itr != summons.end(); ++itr)
            {
                Creature* minion = ObjectAccessor::GetCreature(*me, *itr);
                if (minion && minion->IsAlive() && !minion->GetVictim() && minion->AI())
                    minion->AI()->AttackStart(who);
            }
        }

        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 5s);
        events.ScheduleEvent(EVENT_LIGHTNING_NOVA, 40s);
        events.ScheduleEvent(EVENT_BERSERK, 6min);
        events.ScheduleEvent(EVENT_OVERCHARGE, 45s);

        BossAI::JustEngagedWith(who);
    }

    void JustSummoned(Creature* summoned) override
    {
        BossAI::JustSummoned(summoned);

        // AttackStart has nullptr-check for victim
        if (summoned->AI())
            summoned->AI()->AttackStart(me->GetVictim());
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHAIN_LIGHTNING:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 25s);
                    break;
                case EVENT_LIGHTNING_NOVA:
                    DoCastAOE(SPELL_LIGHTNING_NOVA);
                    events.ScheduleEvent(EVENT_LIGHTNING_NOVA, 40s);
                    break;
                case EVENT_OVERCHARGE:
                    if (!summons.empty())
                    {
                        Creature* minion = ObjectAccessor::GetCreature(*me, Trinity::Containers::SelectRandomContainerElement(summons));
                        if (minion && minion->IsAlive())
                        {
                            minion->CastSpell(me, SPELL_OVERCHARGED, true);
                            minion->SetFullHealth();
                            Talk(EMOTE_OVERCHARGE);
                            events.ScheduleEvent(EVENT_OVERCHARGE, 45s);
                        }
                    }
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    Talk(EMOTE_BERSERK);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_tempest_minion : public ScriptedAI
{
    npc_tempest_minion(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        _instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        _overchargedTimer = 0;
    }

    void Reset() override
    {
        _events.Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        DoZoneInCombat();
        _events.ScheduleEvent(EVENT_SHOCK, 20s);

        if (Creature* pEmalon = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_EMALON)))
        {
            if (!pEmalon->GetVictim() && pEmalon->AI())
                pEmalon->AI()->AttackStart(who);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* emalon = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_EMALON)))
        {
            if (emalon->IsAlive())
            {
                emalon->SummonCreature(NPC_TEMPEST_MINION, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN);
                Talk(EMOTE_MINION_RESPAWN);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (Aura const* overchargedAura = me->GetAura(SPELL_OVERCHARGED))
        {
            if (overchargedAura->GetStackAmount() < 10)
            {
                if (_overchargedTimer <= diff)
                {
                    DoCast(me, SPELL_OVERCHARGED);
                    _overchargedTimer = 2000; // ms
                }
                else
                    _overchargedTimer -= diff;
            }
            else
            {
                if (overchargedAura->GetStackAmount() == 10)
                {
                    DoCast(me, SPELL_OVERCHARGED_BLAST);
                    me->DespawnOrUnsummon();
                    Talk(EMOTE_MINION_RESPAWN);
                }
            }
        }

        if (_events.ExecuteEvent() == EVENT_SHOCK)
        {
            DoCastVictim(SPELL_SHOCK);
            _events.ScheduleEvent(EVENT_SHOCK, 20s);
        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    uint32 _overchargedTimer;
};

void AddSC_boss_emalon()
{
    RegisterVaultOfArchavonCreatureAI(boss_emalon);
    RegisterVaultOfArchavonCreatureAI(npc_tempest_minion);
}
