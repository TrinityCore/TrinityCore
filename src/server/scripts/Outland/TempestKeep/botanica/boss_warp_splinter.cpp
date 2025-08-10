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
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "the_botanica.h"

enum Texts
{
    SAY_AGGRO                 = 0,
    SAY_SLAY                  = 1,
    SAY_SUMMON                = 2,
    SAY_DEATH                 = 3
};

enum Spells
{
    SPELL_STOMP               = 34716,
    SPELL_ARCANE_VOLLEY       = 36705,

    SPELL_SUMMON_SAPLING_1    = 34727,
    SPELL_SUMMON_SAPLING_2    = 34731,
    SPELL_SUMMON_SAPLING_3    = 34733,
    SPELL_SUMMON_SAPLING_4    = 34734,
    SPELL_SUMMON_SAPLING_5    = 34736,
    SPELL_SUMMON_SAPLING_6    = 34739,
    SPELL_SUMMON_SAPLINGS     = 34741,
    SPELL_ANCESTRAL_LIFE      = 34742,
    SPELL_MOONFIRE_VISUAL     = 36704
};

enum Events
{
    EVENT_SUMMON              = 1,
    EVENT_STOMP,
    EVENT_ARCANE_VOLLEY
};

uint32 const SummonSaplingsSpells[] =
{
    SPELL_SUMMON_SAPLING_1, SPELL_SUMMON_SAPLING_2, SPELL_SUMMON_SAPLING_3,
    SPELL_SUMMON_SAPLING_4, SPELL_SUMMON_SAPLING_5, SPELL_SUMMON_SAPLING_6
};

struct boss_warp_splinter : public BossAI
{
    boss_warp_splinter(Creature* creature) : BossAI(creature, DATA_WARP_SPLINTER) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_SUMMON, 25s, 30s);
        events.ScheduleEvent(EVENT_STOMP, 10s, 15s);
        events.ScheduleEvent(EVENT_ARCANE_VOLLEY, 15s, 20s);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SUMMON_SAPLINGS)
        {
            for (uint32 summonSpells : SummonSaplingsSpells)
                DoCastSelf(summonSpells, true);
            Talk(SAY_SUMMON);
        }
    }

    // Do not despawn them
    void JustSummoned(Creature* summon) override
    {
        if (me->IsEngaged())
            DoZoneInCombat(summon);

        if (me->GetVictim())
            summon->AI()->AttackStart(me->GetVictim());
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
                case EVENT_SUMMON:
                    // Ignore shared cooldown because otherwise both spells will be not used in too many cases
                    // It looks like both spells indeed should have shared cooldown but it doesn't really blocks spell
                    // cast but delays it. Maybe not in all cases. Really long sniff can tell more
                    DoCastSelf(SPELL_SUMMON_SAPLINGS, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
                    events.Repeat(40s, 50s);
                    break;
                case EVENT_STOMP:
                    DoCastSelf(SPELL_STOMP, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_ARCANE_VOLLEY:
                    DoCastSelf(SPELL_ARCANE_VOLLEY);
                    events.Repeat(20s, 35s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

struct npc_warp_splinter_sapling : public ScriptedAI
{
    npc_warp_splinter_sapling(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(2, true);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        // This spell currently can miss, maybe it's fine, maybe not
        if (spellInfo->Id == SPELL_ANCESTRAL_LIFE)
        {
            me->SetReactState(REACT_PASSIVE);
            DoCastSelf(SPELL_MOONFIRE_VISUAL);
            me->DespawnOrUnsummon(2s);
        }
    }
};

void AddSC_boss_warp_splinter()
{
    RegisterBotanicaCreatureAI(boss_warp_splinter);
    RegisterBotanicaCreatureAI(npc_warp_splinter_sapling);
}
