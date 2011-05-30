/*
* Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

//
//  Emerald Dragon NPCs and IDs (kept here for reference)
//

enum EmeraldDragonNPC
{
    NPC_DREAM_FOG                   = 15224,
    NPC_DEMENTED_DRUID              = 15260,

    DRAGON_YSONDRE                  = 14887,
    DRAGON_LETHON                   = 14888,
    DRAGON_EMERISS                  = 14889,
    DRAGON_TAERAR                   = 14890,
};

//
// Emerald Dragon Spells (used for the dragons)
//

enum EmeraldDragonSpells
{
    SPELL_TAIL_SWEEP                = 15847,    // tail sweep - slap everything behind dragon (2 seconds interval)
    SPELL_SUMMON_PLAYER             = 24776,    // teleport highest threat player in front of dragon if wandering off
    SPELL_DREAM_FOG                 = 24777,    // used by summoned NPC (Dream Fog/15224)
    SPELL_SEEPING_FOG_LEFT          = 24813,    // dream fog - summon left
    SPELL_SEEPING_FOG_RIGHT         = 24814,    // dream fog - summon right
    SPELL_NOXIOUS_BREATH            = 24818,
    SPELL_MARK_OF_NATURE            = 25040,    // Mark of Nature trigger (applied on target death - 15 minutes of being suspectible to Aura Of Nature)
    SPELL_MARK_OF_NATURE_AURA       = 25041,    // Mark of Nature (passive marker-test, runs every 10 seconds from boss, triggers spellID 25042 (spell_dbc or script needed)
    SPELL_AURA_OF_NATURE            = 25043,    // Stun for 2 minutes (used when SPELL_MARK_OF_NATURE exists on the target)
};

//
// Emerald Dragon Eventlists (shared and specials)
//

enum EmeraldDragonEvents
{
    EVENT_SEEPING_FOG               = 1,
    EVENT_NOXIOUS_BREATH            = 2,
    EVENT_TAIL_SWEEP                = 3,
};

enum YsondreEvents
{
    EVENT_LIGHTNING_WAVE            = 11,
    EVENT_SUMMON_DRUID_SPIRITS      = 12,
};

enum LethonEvents
{
    EVENT_SHADOW_BOLT_WHIRL         = 21,
    EVENT_DRAW_SPIRIT               = 22,
};

enum EmerissEvents
{
    EVENT_VOLATILE_INFECTION        = 31,
    EVENT_CORRUPTION_OF_EARTH       = 32,
};

enum TaerarEvents
{
    EVENT_ARCANE_BLAST              = 41,
    EVENT_BELLOWING_ROAR            = 42,
};

/*
 * ---
 * --- Emerald Dragons : Base AI-structure used for all the Emerald dragons
 * ---
 *
 * TODO
 * - Fix player teleportation when running off too far from the dragon (emerald_dragonAI)
 * - Verify handling of Mark Of Nature / Aura of Nature
 *
 */

struct emerald_dragonAI : public WorldBossAI
{
    emerald_dragonAI(Creature* creature) : WorldBossAI(creature)
    {
        // Emerald Dragons are immune to nature
        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
    }

    void Reset()
    {
        WorldBossAI::Reset();
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE);
        me->SetReactState(REACT_AGGRESSIVE);
        events.ScheduleEvent(EVENT_TAIL_SWEEP, 4000);
        events.ScheduleEvent(EVENT_NOXIOUS_BREATH, 8000);
        events.ScheduleEvent(EVENT_SEEPING_FOG, urand(10000, 20000));
    }

    // Test if the player has been killed before, and if so, put them to sleep
    void MoveInLineOfSight(Unit* who)
    {
        if (who && me->IsHostileTo(who))
            if (who->HasAura(SPELL_MARK_OF_NATURE_AURA) && !who->HasAura(SPELL_AURA_OF_NATURE))
                DoCast(who, SPELL_AURA_OF_NATURE, true);
    }

    // Target killed during encounter, mark them as suspectible for Aura Of Nature
    void KilledUnit(Unit* who)
    {
        DoCast(who, SPELL_MARK_OF_NATURE, true);
    }

    // Execute and reschedule base events shared between all Emerald Dragons
    void ExecuteEvent(uint32 const eventId)
    {
        switch (eventId)
        {
            case EVENT_SEEPING_FOG:
                DoCast(me, SPELL_SEEPING_FOG_LEFT);
                DoCast(me, SPELL_SEEPING_FOG_RIGHT);
                events.ScheduleEvent(EVENT_SEEPING_FOG, urand(7500,17500));
                break;
            case EVENT_NOXIOUS_BREATH:
                DoCast(me, SPELL_NOXIOUS_BREATH);
                events.ScheduleEvent(EVENT_NOXIOUS_BREATH, urand(15000, 20000));
                break;
            case EVENT_TAIL_SWEEP:
                DoCast(me, SPELL_TAIL_SWEEP);
                events.ScheduleEvent(EVENT_TAIL_SWEEP, 2000);
                break;
        }
    }

    void UpdateAI(uint32 const diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STAT_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
            ExecuteEvent(eventId);

        DoMeleeAttackIfReady();
    }
};

/*
 * --- Dream Fog NPC
 *
 * TODO:
 * - Change to random targets on random intervals (?)
 * - Check if targets are selected based on threatlevel(?)
 *
 */

class npc_dream_fog : public CreatureScript
{
    public:
        npc_dream_fog() : CreatureScript("npc_dream_fog") { }

        struct npc_dream_fogAI : public ScriptedAI
        {
            npc_dream_fogAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _activeFog = false;
                _roamTimer = 0;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE);
            }

            void UpdateAI(const uint32 /*diff*/)
            {
                if (!UpdateVictim())
                    return;

                if (!_activeFog)
                {
                    DoCast(SPELL_DREAM_FOG);
                    _activeFog = true;
                }

                if (!_roamTimer)
                {
                    // Chase target, but don't attack - otherwise just roam around
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM);
                    if (target)
                        me->GetMotionMaster()->MoveChase(target);
                    else
                        me->GetMotionMaster()->MoveIdle();
                    _roamTimer = 15000;
                }
                --_roamTimer;
            }

        private:
            bool _activeFog;
            uint32 _roamTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_dream_fogAI(creature);
        }
};

/*
 * ---
 * --- Dragonspecific scripts and handling: YSONDRE
 * ---
 *
 * TODO:
 * - Bugtesting... (?)
 */

enum YsondreTexts
{
    SAY_YSONDRE_AGGRO               = 0,
    SAY_YSONDRE_SUMMON_DRUIDS       = 1,
};

enum YsondreSpells
{
    SPELL_LIGHTNING_WAVE            = 24819,
    SPELL_SUMMON_DRUID_SPIRITS      = 24795,
};

class boss_ysondre : public CreatureScript
{
    public:
        boss_ysondre() : CreatureScript("boss_ysondre") { }

        struct boss_ysondreAI : public emerald_dragonAI
        {
            boss_ysondreAI(Creature* creature) : emerald_dragonAI(creature)
            {
            }

            void Reset()
            {
                _stage = 1;
                _Reset();
                emerald_dragonAI::Reset();
                events.ScheduleEvent(EVENT_LIGHTNING_WAVE, 12000);
            }

            void EnterCombat(Unit* who)
            {
                Talk(SAY_YSONDRE_AGGRO);
                WorldBossAI::EnterCombat(who);
            }

            // Summon druid spirits on 75%, 50% and 25% health
            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                if (!HealthAbovePct(100 - 25 * _stage))
                {
                    Talk(SAY_YSONDRE_SUMMON_DRUIDS);
                    for (int count = 0 ; count < 10 ; ++count)
                        DoCast(me, SPELL_SUMMON_DRUID_SPIRITS);
                    ++_stage;
                }
            }

            void ExecuteEvent(uint32 const eventId)
            {
                switch (eventId)
                {
                    case EVENT_LIGHTNING_WAVE:
                        DoCastVictim(SPELL_LIGHTNING_WAVE);
                        events.ScheduleEvent(EVENT_LIGHTNING_WAVE, urand(7000, 12000));
                        break;
                    default:
                        emerald_dragonAI::ExecuteEvent(eventId);
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                    ExecuteEvent(eventId);

                DoMeleeAttackIfReady();
            }

        private:
            uint8   _stage;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_ysondreAI(creature);
        }
};

/*
 * Ysondres' demented druids
 *
 * TODO:
 * - Fix summoned druid lifetime (unsummon after 10 minutes)
 *
 */

enum DementedEvent
{
    EVENT_DRUID_MOONFIRE        = 1,
    EVENT_DRUID_CURSE_OF_THORNS = 2,
    EVENT_DRUID_SILENCE         = 3,
};

enum DementedSpell
{
    SPELL_SILENCE               = 6726,
    SPELL_CURSE_OF_THORNS       = 16247,
    SPELL_MOONFIRE              = 21669,
};

class npc_demented_druid : public CreatureScript
{
    public:
        npc_demented_druid() : CreatureScript("npc_demented_druid") { }

        struct npc_demented_druidAI : public ScriptedAI
        {
            npc_demented_druidAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _lifeTimer = 600000;
                _events.ScheduleEvent(EVENT_DRUID_MOONFIRE, 2500);
                _events.ScheduleEvent(EVENT_DRUID_SILENCE, 15000);
                _events.ScheduleEvent(EVENT_DRUID_CURSE_OF_THORNS, 10000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DRUID_MOONFIRE:
                            DoCastVictim(SPELL_MOONFIRE);
                            _events.ScheduleEvent(EVENT_DRUID_MOONFIRE, urand(10000, 15000));
                            break;
                        case EVENT_DRUID_SILENCE:
                            DoCastVictim(SPELL_SILENCE);
                            _events.ScheduleEvent(EVENT_DRUID_SILENCE, urand(15000,20000));
                            break;
                        case EVENT_DRUID_CURSE_OF_THORNS:
                            DoCastVictim(SPELL_SILENCE);
                            _events.ScheduleEvent(EVENT_DRUID_CURSE_OF_THORNS, urand(15000,20000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            uint32 _lifeTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_demented_druidAI(creature);
        }
};

/*
 * ---
 * --- Dragonspecific scripts and handling: LETHON
 * ---
 *
 * TODO:
 * - Fix EVENT_DRAW_SPIRIT:
 *     Spirit Shade NPC helper needs to appear and walk toward Lethon and heal if they reach him
 *     Each shade heals for 15000 HP
 * -Fix up EVENT_SHADOW_BOLT_WHIRL properly
 *
 */

enum LethonTexts
{
    SAY_LETHON_AGGRO                = 0,
    SAY_LETHON_DRAW_SPIRIT          = 1,
};

enum LethonSpells
{
    SPELL_SHADOW_BOLT_WHIRL         = 24834,
    SPELL_DRAW_SPIRIT               = 24811,
};

class boss_lethon : public CreatureScript
{
    public:
        boss_lethon() : CreatureScript("boss_lethon") { }

        struct boss_lethonAI : public emerald_dragonAI
        {
            boss_lethonAI(Creature* creature) : emerald_dragonAI(creature)
            {
            }

            void Reset()
            {
                _stage = 1;
                _Reset();
                emerald_dragonAI::Reset();
                events.ScheduleEvent(EVENT_SHADOW_BOLT_WHIRL, 5000);
            }

            void EnterCombat(Unit* who)
            {
                Talk(SAY_LETHON_AGGRO);
                WorldBossAI::EnterCombat(who);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                if (!HealthAbovePct(100 - 25 * _stage))
                {
                    Talk(SAY_LETHON_DRAW_SPIRIT);
                    DoCast(me, SPELL_DRAW_SPIRIT);
                    ++_stage;
                }
            }

            void ExecuteEvent(uint32 const eventId)
            {
                switch (eventId)
                {
                    case EVENT_LIGHTNING_WAVE:
                        DoCast(SPELL_LIGHTNING_WAVE);
                        events.ScheduleEvent(EVENT_LIGHTNING_WAVE, 5000);
                        break;
                    default:
                        emerald_dragonAI::ExecuteEvent(eventId);
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                    ExecuteEvent(eventId);

                DoMeleeAttackIfReady();
            }

        private:
            uint8   _stage;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_lethonAI(creature);
        }
};

// ---
// --- Dragonspecific scripts and handling: EMERISS
// ---

enum EmerissTexts
{
    SAY_EMERISS_AGGRO               = 0,
    SAY_EMERISS_CAST_CORRUPTION     = 1,
};


enum EmerissSpells
{
    SPELL_PUTRID_MUSHROOM           = 24904,
    SPELL_CORRUPTION_OF_EARTH       = 24910,
    SPELL_VOLATILE_INFECTION        = 24928,
};

class boss_emeriss : public CreatureScript
{
    public:
        boss_emeriss() : CreatureScript("boss_emeriss") { }

        struct boss_emerissAI : public emerald_dragonAI
        {
            boss_emerissAI(Creature* creature) : emerald_dragonAI(creature)
            {
            }

            void Reset()
            {
                _stage = 1;
                _Reset();
                emerald_dragonAI::Reset();
                events.ScheduleEvent(EVENT_VOLATILE_INFECTION, 12000);
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    DoCast(who, SPELL_PUTRID_MUSHROOM, true);
                emerald_dragonAI::KilledUnit(who);
            }

            void EnterCombat(Unit* who)
            {
                Talk(SAY_EMERISS_AGGRO);
                WorldBossAI::EnterCombat(who);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                if (!HealthAbovePct(100 - 25 * _stage))
                {
                    Talk(SAY_EMERISS_CAST_CORRUPTION);
                    DoCast(me, SPELL_CORRUPTION_OF_EARTH);
                    ++_stage;
                }
            }

            void ExecuteEvent(uint32 const eventId)
            {
                switch (eventId)
                {
                    case EVENT_VOLATILE_INFECTION:
                        DoCastVictim(SPELL_VOLATILE_INFECTION);
                        events.ScheduleEvent(EVENT_VOLATILE_INFECTION, 120000);
                        break;
                    default:
                        emerald_dragonAI::ExecuteEvent(eventId);
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                    ExecuteEvent(eventId);

                DoMeleeAttackIfReady();
            }

        private:
            uint8   _stage;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_emerissAI(creature);
        }
};

// ---
// --- Dragonspecific scripts and handling: TAERAR
// ---

enum TaerarTexts
{
    SAY_TAERAR_AGGRO                = 0,
    SAY_TAERAR_SUMMON_SHADES        = 1,
};

enum TaerarSpells
{
    SPELL_BELLOWING_ROAR            = 22686,
    SPELL_SHADE                     = 24313,
    SPELL_SUMMON_SHADE_1            = 24841,
    SPELL_SUMMON_SHADE_2            = 24842,
    SPELL_SUMMON_SHADE_3            = 24843,
    SPELL_ARCANE_BLAST              = 24857,
};

uint32 const TaerarShadeSpells[] =
{
    SPELL_SUMMON_SHADE_1, SPELL_SUMMON_SHADE_2, SPELL_SUMMON_SHADE_3
};

class boss_taerar : public CreatureScript
{
    public:
        boss_taerar() : CreatureScript("boss_taerar") { }

        struct boss_taerarAI : public emerald_dragonAI
        {
            boss_taerarAI(Creature* creature) : emerald_dragonAI(creature)
            {
                _stage = 1;
                _shades = 0;
                _banished = false;
                _banishedTimer = 0;
            }

            void Reset()
            {
                me->RemoveAurasDueToSpell(SPELL_SHADE);
                _stage = 1;

                _shades = 0;
                _banished = false;
                _banishedTimer = 0;

                _Reset();
                emerald_dragonAI::Reset();
                events.ScheduleEvent(EVENT_ARCANE_BLAST, 12000);
                events.ScheduleEvent(EVENT_BELLOWING_ROAR, 30000);
            }

            void EnterCombat(Unit* who)
            {
                Talk(SAY_TAERAR_AGGRO);
                emerald_dragonAI::EnterCombat(who);
            }

            void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/)
            {
                --_shades;
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                // At 75, 50 or 25 percent health, we need to activate the shades and go "banished"
                // Note: _stage holds the amount of times they have been summoned
                if (!_banished && !HealthAbovePct(100 - 25 * _stage))
                {
                    _banished = true;
                    _banishedTimer = 60000;

                    me->InterruptNonMeleeSpells(false);
                    DoStopAttack();

                    Talk(SAY_TAERAR_SUMMON_SHADES);

                    int count = sizeof(TaerarShadeSpells) / sizeof(uint32);
                    for (int i = 0; i < count; ++i)
                        DoCastVictim(TaerarShadeSpells[i], true);
                    _shades += count;

                    DoCast(SPELL_SHADE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_PASSIVE);

                    ++_stage;
                }
            }

            void ExecuteEvent(uint32 const eventId)
            {
                switch (eventId)
                {
                    case EVENT_ARCANE_BLAST:
                        DoCast(SPELL_ARCANE_BLAST);
                        events.ScheduleEvent(EVENT_ARCANE_BLAST, urand(7000, 12000));
                        break;
                    case EVENT_BELLOWING_ROAR:
                        DoCast(SPELL_BELLOWING_ROAR);
                        events.ScheduleEvent(EVENT_BELLOWING_ROAR, urand(20000, 30000));
                        break;
                    default:
                        emerald_dragonAI::ExecuteEvent(eventId);
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                if (_banished)
                {
                    // If all three shades are dead, OR it has taken too long, end the current event and get Taerar back into business
                    if (_banishedTimer <= diff || !_shades)
                    {
                        _banished = false;

                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveAurasDueToSpell(SPELL_SHADE);
                        me->SetReactState(REACT_AGGRESSIVE);
                    }
                    // _banishtimer has not expired, and we still have active shades:
                    else
                        _banishedTimer -= diff;
                    return;
                }

                while (uint32 eventId = events.ExecuteEvent())
                    ExecuteEvent(eventId);

                DoMeleeAttackIfReady();
            }

        private:
            bool    _banished;                              // used for shades activation testing
            uint32  _banishedTimer;                         // counter for banishment timeout
            uint8   _shades;                                // keep track of how many shades are dead
            uint8   _stage;                                 // check which "shade phase" we're at (75-50-25 percentage counters)
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_taerarAI(creature);
        }
};

/*
 * Taerars shades
 */

enum ShadeEvents
{
    EVENT_SHADE_POISON_CLOUD    = 1,
    EVENT_SHADE_ACID_BREATH     = 2,
};

enum ShadeSpells
{
    SPELL_POISON_CLOUD          = 24840,
    SPELL_ACID_BREATH           = 20667,
};

class boss_shadeoftaerar : public CreatureScript
{
    public:
        boss_shadeoftaerar() : CreatureScript("boss_shade_of_taerar") { }

        struct boss_shadeoftaerarAI : public ScriptedAI
        {
            boss_shadeoftaerarAI(Creature* creature) : ScriptedAI(creature)
            {
                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_SHADE_ACID_BREATH, 12000);
                _events.ScheduleEvent(EVENT_SHADE_POISON_CLOUD, 30000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADE_ACID_BREATH:
                            DoCast(SPELL_ACID_BREATH);
                            _events.ScheduleEvent(EVENT_SHADE_ACID_BREATH, urand(10000, 14000));
                            break;
                        case EVENT_SHADE_POISON_CLOUD:
                            DoCast(SPELL_POISON_CLOUD);
                            _events.ScheduleEvent(EVENT_SHADE_POISON_CLOUD, urand(25000, 30000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_shadeoftaerarAI(creature);
        }
};

void AddSC_emerald_dragons()
{
    // helper NPC scripts
    new npc_dream_fog();

    // ysondre and summons
    new boss_ysondre();
    new npc_demented_druid();

    // taerar and summons
    new boss_taerar();
    new boss_shadeoftaerar();

    // emeriss
    new boss_emeriss();

    // lethon and summons
    new boss_lethon();
};
