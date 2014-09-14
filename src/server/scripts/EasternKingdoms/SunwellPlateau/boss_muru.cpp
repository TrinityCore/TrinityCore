/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Muru
SD%Complete: 80
SDComment: all sounds, black hole effect triggers to often (46228)
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sunwell_plateau.h"
#include "Player.h"
#include "SpellInfo.h"

// Muru & Entropius's spells
enum Spells
{
    SPELL_ENRAGE                 = 26662,

    // Muru's spells
    SPELL_NEGATIVE_ENERGY        = 46009, //(this trigger 46008)
    SPELL_DARKNESS               = 45999,
    SPELL_OPEN_ALL_PORTALS       = 46177,
    SPELL_OPEN_PORTAL            = 45977,
    SPELL_OPEN_PORTAL_2          = 45976,
    SPELL_SUMMON_BERSERKER       = 46037,
    SPELL_SUMNON_FURY_MAGE       = 46038,
    SPELL_SUMMON_VOID_SENTINEL   = 45988,
    SPELL_SUMMON_ENTROPIUS       = 46217,

    // Entropius's spells
    SPELL_DARKNESS_E             = 46269,
    SPELL_BLACKHOLE              = 46282,
    SPELL_NEGATIVE_ENERGY_E      = 46284,
    SPELL_ENTROPIUS_SPAWN        = 46223,

    // Shadowsword Berserker's spells
    SPELL_FLURRY                 = 46160,
    SPELL_DUAL_WIELD             = 29651,

    // Shadowsword Fury Mage's spells
    SPELL_FEL_FIREBALL           = 46101,
    SPELL_SPELL_FURY             = 46102,

    // Void Sentinel's spells
    SPELL_SHADOW_PULSE           = 46087,
    SPELL_VOID_BLAST             = 46161,

    // Void Spawn's spells
    SPELL_SHADOW_BOLT_VOLLEY     = 46082,

    //Dark Fiend Spells
    SPELL_DARKFIEND_AOE          = 45944,
    SPELL_DARKFIEND_VISUAL       = 45936,
    SPELL_DARKFIEND_SKIN         = 45934,

    //Black Hole Spells
    SPELL_BLACKHOLE_SPAWN        = 46242,
    SPELL_BLACKHOLE_GROW         = 46228
};

enum Events
{
    // M'uru
    EVENT_DARKNESS = 1,
    EVENT_SUMMON_HUMANOIDS,
    EVENT_SUMMON_SENTINEL,
    EVENT_PHASE_TRANSITION, // Delayed phase transition.
    EVENT_ENRAGE,

    // Entropius
    EVENT_SUMMON_BLACK_HOLE
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO,
};

enum CreatureGroups
{
    CREATURE_GROUP_HUMANOIDS,
    CREATURE_GROUP_DARKFIENDS
};

class boss_entropius : public CreatureScript
{
public:
    boss_entropius() : CreatureScript("boss_entropius") { }

    struct boss_entropiusAI : public BossAI
    {
        boss_entropiusAI(Creature* creature) : BossAI(creature, DATA_MURU) { }

        void Reset() override
        {
            DoCastAOE(SPELL_NEGATIVE_ENERGY_E);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            DoCastAOE(SPELL_NEGATIVE_ENERGY_E, true);
            DoCast(me, SPELL_ENTROPIUS_SPAWN);
            events.ScheduleEvent(EVENT_SUMMON_BLACK_HOLE, 15000);
        }

        void JustSummoned(Creature* summoned) override
        {
            switch (summoned->GetEntry())
            {
                case NPC_DARK_FIENDS:
                    summoned->CastSpell(summoned, SPELL_DARKFIEND_VISUAL);
                    break;
                case NPC_DARKNESS:
                    summoned->AddUnitState(UNIT_STATE_STUNNED);
                    float x, y, z, o;
                    summoned->GetHomePosition(x, y, z, o);
                    me->SummonCreature(NPC_DARK_FIENDS, x, y, z, o, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
            }
            summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true));
            summons.Summon(summoned);
        }

        void ExecuteEvent(uint32 eventId) override
        {
            if (eventId == EVENT_SUMMON_BLACK_HOLE)
            {
                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(random, SPELL_DARKNESS_E);
                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    random->CastSpell(random, SPELL_BLACKHOLE);
                events.ScheduleEvent(EVENT_SUMMON_BLACK_HOLE, 15000);
            }
        }

        void EnterEvadeMode() override
        {
            if (Creature* muru = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_MURU)))
                muru->AI()->Reset(); // Reset encounter.
            me->DisappearAndDie();
            summons.DespawnAll();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_entropiusAI>(creature);
    }
};

class boss_muru : public CreatureScript
{
public:
    boss_muru() : CreatureScript("boss_muru") { }

    struct boss_muruAI : public BossAI
    {
        boss_muruAI(Creature* creature) : BossAI(creature, DATA_MURU)
        {
            Initialize();
            SetCombatMovement(false);
        }

        void Initialize()
        {
            DarkFiend = false;
            HasEnraged = false;
            EntropiusGUID.Clear();
        }

        void Reset() override
        {
            Initialize();
            _Reset();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetVisible(true);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.SetPhase(PHASE_ONE);
            events.ScheduleEvent(EVENT_ENRAGE, 600000);
            events.ScheduleEvent(EVENT_DARKNESS, 45000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_SUMMON_HUMANOIDS, 10000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_SUMMON_SENTINEL, 31500, 0, PHASE_ONE);
            DoCastAOE(SPELL_NEGATIVE_ENERGY);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage > me->GetHealth() && events.IsInPhase(PHASE_ONE))
            {
                damage = 0;
                me->RemoveAllAuras();
                DoCast(me, SPELL_OPEN_ALL_PORTALS);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                events.SetPhase(PHASE_TWO);
                events.ScheduleEvent(EVENT_PHASE_TRANSITION, 2000);
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            switch (summoned->GetEntry())
            {
                case NPC_ENTROPIUS:
                    me->SetVisible(false);
                    EntropiusGUID = summoned->GetGUID();
                    if (HasEnraged) // If we hit phase transition while enraged, enrage Entropius as well.
                        summoned->CastSpell(summoned, SPELL_ENRAGE);
                    break;
                case NPC_DARK_FIENDS:
                    summoned->CastSpell(summoned, SPELL_DARKFIEND_VISUAL);
                    break;
            }
            summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true));
            summons.Summon(summoned);
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_DARKNESS:
                    if (!DarkFiend)
                    {
                        DarkFiend = true;
                        DoCastAOE(SPELL_DARKNESS);
                    }
                    else
                    {
                        DarkFiend = false;
                        me->SummonCreatureGroup(CREATURE_GROUP_DARKFIENDS);
                    }
                    events.ScheduleEvent(EVENT_DARKNESS, DarkFiend ? 3000 : 42000, 0, PHASE_ONE);
                    break;
                case EVENT_SUMMON_HUMANOIDS:
                    me->SummonCreatureGroup(CREATURE_GROUP_DARKFIENDS);
                    events.ScheduleEvent(EVENT_SUMMON_HUMANOIDS, 60000, 0, PHASE_ONE);
                    break;
                case EVENT_SUMMON_SENTINEL:
                    DoCastAOE(SPELL_OPEN_PORTAL_2);
                    events.ScheduleEvent(EVENT_SUMMON_SENTINEL, 30000, 0, PHASE_ONE);
                    break;
                case EVENT_PHASE_TRANSITION:
                    DoCast(me, SPELL_SUMMON_ENTROPIUS);
                    break;
                case EVENT_ENRAGE:
                    if (Creature* entropius = ObjectAccessor::GetCreature(*me, EntropiusGUID))
                        entropius->CastSpell(entropius, SPELL_ENRAGE);
                    DoCast(me, SPELL_ENRAGE);
                    HasEnraged = true;
                    break;
                default:
                    break;
            }
        }

    private:
        bool DarkFiend;
        bool HasEnraged;
        ObjectGuid EntropiusGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_muruAI>(creature);
    }
};

class npc_muru_portal : public CreatureScript
{
public:
    npc_muru_portal() : CreatureScript("npc_muru_portal") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_muru_portalAI>(creature);
    }

    struct npc_muru_portalAI : public ScriptedAI
    {
        npc_muru_portalAI(Creature* creature) : ScriptedAI(creature), Summons(creature)
        {
            Initialize();
            SetCombatMovement(false);
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            SummonTimer = 5000;

            InAction = false;
            SummonSentinel = false;
        }

        InstanceScript* instance;

        SummonList Summons;

        bool SummonSentinel;
        bool InAction;

        uint32 SummonTimer;

        void Reset() override
        {
            Initialize();

            me->AddUnitState(UNIT_STATE_STUNNED);

            Summons.DespawnAll();
        }

        void JustSummoned(Creature* summoned) override
        {
            if (Player* target = ObjectAccessor::GetPlayer(*me, instance->GetData64(DATA_PLAYER_GUID)))
                summoned->AI()->AttackStart(target);

            Summons.Summon(summoned);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* Spell) override
        {
            float x, y, z, o;
            me->GetHomePosition(x, y, z, o);
            me->NearTeleportTo(x, y, z, o);
            InAction = true;
            switch (Spell->Id)
            {
                case SPELL_OPEN_ALL_PORTALS:
                    DoCastAOE(SPELL_OPEN_PORTAL);
                    break;
                case SPELL_OPEN_PORTAL_2:
                    DoCastAOE(SPELL_OPEN_PORTAL);
                    SummonSentinel = true;
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!SummonSentinel)
            {
                if (InAction && instance->GetBossState(DATA_MURU) == NOT_STARTED)
                    Reset();
                return;
            }

            if (SummonTimer <= diff)
            {
                DoCastAOE(SPELL_SUMMON_VOID_SENTINEL, false);
                SummonTimer = 5000;
                SummonSentinel = false;
            } else SummonTimer -= diff;
        }
    };
};

class npc_dark_fiend : public CreatureScript
{
public:
    npc_dark_fiend() : CreatureScript("npc_dark_fiend") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dark_fiendAI(creature);
    }

    struct npc_dark_fiendAI : public ScriptedAI
    {
        npc_dark_fiendAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            WaitTimer = 2000;
            InAction = false;
        }

        uint32 WaitTimer;
        bool InAction;

        void Reset() override
        {
            Initialize();

            me->AddUnitState(UNIT_STATE_STUNNED);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* Spell) override
        {
            for (uint8 i = 0; i < 3; ++i)
                if (Spell->Effects[i].Effect == 38)
                    me->DisappearAndDie();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (WaitTimer <= diff)
            {
                if (!InAction)
                {
                    me->ClearUnitState(UNIT_STATE_STUNNED);
                    DoCastAOE(SPELL_DARKFIEND_SKIN, false);
                    AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true));
                    InAction = true;
                    WaitTimer = 500;
                }
                else
                {
                    if (me->IsWithinDist(me->GetVictim(), 5))
                    {
                        DoCastAOE(SPELL_DARKFIEND_AOE, false);
                        me->DisappearAndDie();
                    }
                    WaitTimer = 500;
                }
            } else WaitTimer -= diff;
        }
    };
};

class npc_void_sentinel : public CreatureScript
{
public:
    npc_void_sentinel() : CreatureScript("npc_void_sentinel") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_void_sentinelAI(creature);
    }

    struct npc_void_sentinelAI : public ScriptedAI
    {
        npc_void_sentinelAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            PulseTimer = 3000;
            VoidBlastTimer = 45000; //is this a correct timer?
        }

        uint32 PulseTimer;
        uint32 VoidBlastTimer;

        void Reset() override
        {
            Initialize();

            float x, y, z, o;
            me->GetHomePosition(x, y, z, o);
            me->NearTeleportTo(x, y, 71, o);
        }

        void JustDied(Unit* killer) override
        {
            for (uint8 i = 0; i < 8; ++i)
                if (Creature* temp = me->SummonCreature(NPC_VOID_SPAWN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), float(rand32() % 6), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000))
                    temp->AI()->AttackStart(killer);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (PulseTimer <= diff)
            {
                DoCastAOE(SPELL_SHADOW_PULSE, true);
                PulseTimer = 3000;
            } else PulseTimer -= diff;

            if (VoidBlastTimer <= diff)
            {
                DoCastVictim(SPELL_VOID_BLAST, false);
                VoidBlastTimer = 45000;
            } else VoidBlastTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_blackhole : public CreatureScript
{
public:
    npc_blackhole() : CreatureScript("npc_blackhole") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_blackholeAI>(creature);
    }

    struct npc_blackholeAI : public ScriptedAI
    {
        npc_blackholeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            DespawnTimer = 15000;
            SpellTimer = 5000;
            Phase = 0;
            NeedForAHack = 0;
        }

        InstanceScript* instance;

        uint32 DespawnTimer;
        uint32 SpellTimer;
        uint8 Phase;
        uint8 NeedForAHack;

        void Reset() override
        {
            Initialize();

            me->AddUnitState(UNIT_STATE_STUNNED);
            DoCastAOE(SPELL_BLACKHOLE_SPAWN, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (SpellTimer <= diff)
            {
                Unit* Victim = ObjectAccessor::GetUnit(*me, instance->GetData64(DATA_PLAYER_GUID));
                switch (NeedForAHack)
                {
                    case 0:
                        me->ClearUnitState(UNIT_STATE_STUNNED);
                        DoCastAOE(SPELL_BLACKHOLE_GROW, false);
                        if (Victim)
                            AttackStart(Victim);
                        SpellTimer = 700;
                        NeedForAHack = 2;
                        break;
                    case 1:
                        me->AddAura(SPELL_BLACKHOLE_GROW, me);
                        NeedForAHack = 2;
                        SpellTimer = 600;
                        break;
                    case 2:
                        SpellTimer = 400;
                        NeedForAHack = 3;
                        me->RemoveAura(SPELL_BLACKHOLE_GROW, 1);
                        break;
                    case 3:
                        SpellTimer = urand(400, 900);
                        NeedForAHack = 1;
                        if (Unit* Temp = me->GetVictim())
                        {
                            if (Temp->GetPositionZ() > 73 && Victim)
                                AttackStart(Victim);
                        } else
                            return;
                }
            } else SpellTimer -= diff;

            if (DespawnTimer <= diff)
                me->DisappearAndDie();
            else DespawnTimer -= diff;
        }
    };
};

void AddSC_boss_muru()
{
    new boss_muru();
    new boss_entropius();
    new npc_muru_portal();
    new npc_dark_fiend();
    new npc_void_sentinel();
    new npc_blackhole();
}
