/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include "ScriptPCH.h"
#include "throne_of_the_tides.h"

Creature* erunak;
Creature* mindbender;

#define SPELL_ABSORB_MAGIC           DUNGEON_MODE(76307,91492)
#define SPELL_LAVA_BOLT              DUNGEON_MODE(76171,91412)

enum Spells
{
// Erunak Stonespeaker
    SPELL_EARTH_SHARDS           = 84931, // VISUAL - missle?
    SPELL_EARTH_SHARD_AURA       = 84935,
    SPELL_EARTH_SHARD_SUMMON     = 84934,
    SPELL_EMBERSTRIKE            = 76165,
    SPELL_MAGMA_SPLASH           = 76170,
// Mindbender Ghur'sha
    SPELL_ENSLAVE                = 76207,
    SPELL_ENSLAVE_BUFF           = 76213, // Should be in SPELL_LINKED_SPELL with SPELL_ENSLAVE

    SPELL_MIND_FOG_SUMMON        = 76234,
    SPELL_MIND_FOG_AURA          = 76230,
    SPELL_MIND_FOG_VISUAL        = 76231,
    SPELL_UNRELENTING_AGONY      = 76339,
};

enum Yells
{
    SAY_PHASE_1_END_MINDBENDER      = -1643011,
    SAY_PHASE_1_END_ERUNAK          = -1643012,
    SAY_MIND_CONTROL_1              = -1643013,
    SAY_MIND_CONTROL_2              = -1643014,
    SAY_MIND_CONTROL_3              = -1643015,
    SAY_MIND_FOG                    = -1643016,
    SAY_DEATH                       = -1643017,
    SAY_WIN_ERUNAK                  = -1643018,
};

// predicate function to select not charmed target
struct NotCharmedTargetSelector : public std::unary_function<Unit*, bool>
{
    NotCharmedTargetSelector() {}

    bool operator()(Unit const* target) const
    {
        return !target->isCharmed();
    }
};

class boss_erunak_stonespeaker : public CreatureScript
{
public:
    boss_erunak_stonespeaker() : CreatureScript("boss_erunak_stonespeaker") {}

    struct boss_erunak_stonespeakerAI : public ScriptedAI
    {
        boss_erunak_stonespeakerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            erunak = me;
        }

        std::list<uint64> SummonList;

        uint32 EarthShardsTimer;
        uint32 EmberstrikeTimer;
        uint32 LavaBoltTimer;
        uint32 MagmaSplashTimer;

        bool phased;

        InstanceScript* instance;

        void Reset()
        {
            EarthShardsTimer = 20000;
            EmberstrikeTimer = urand(12000,20000);
            LavaBoltTimer = 10000;
            MagmaSplashTimer = 15000;
            phased = false;

            if (instance)
                instance->SetData(DATA_ERUNAK_STONESPEAKER_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();

            EarthShardsTimer = 20000;
            EmberstrikeTimer = 11000;
            LavaBoltTimer = 6500;
            MagmaSplashTimer = 17000;

            if (instance)
                instance->SetData(DATA_ERUNAK_STONESPEAKER_EVENT, IN_PROGRESS);
        }

        void JustSummoned(Creature* summon)
        {
            switch (summon->GetEntry())
            {
                case BOSS_MINDBENDER_GHURSHA:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        summon->AI()->AttackStart(target);
                    break;
                case NPC_EARTH_SHARD:
                    SummonList.push_back(summon->GetGUID());
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (EarthShardsTimer <= diff && phased == false)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_EARTH_SHARDS);
                DoCast(me, SPELL_EARTH_SHARD_SUMMON);
                EarthShardsTimer = 20000;
            } else EarthShardsTimer -= diff;

            if (EmberstrikeTimer <= diff && phased == false)
            {
                DoCastVictim(SPELL_EMBERSTRIKE);
                EmberstrikeTimer = 15000;
            } else EmberstrikeTimer -= diff;

            if (LavaBoltTimer <= diff && phased == false)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_LAVA_BOLT);
                LavaBoltTimer = 10000;
            } else LavaBoltTimer -= diff;

            if (MagmaSplashTimer <= diff && phased == false)
            {
                DoCastVictim(SPELL_MAGMA_SPLASH);
                MagmaSplashTimer = 15000;
            } else MagmaSplashTimer -= diff;

            if (HealthBelowPct(50) && phased == false)
            {
                me->CombatStop(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(35);
                me->HandleEmoteCommand(68);
                DoScriptText(SAY_PHASE_1_END_ERUNAK, me);
                Position pos;
                me->GetPosition(&pos);
                me->SummonCreature(BOSS_MINDBENDER_GHURSHA, pos, TEMPSUMMON_MANUAL_DESPAWN);
                phased = true;
            }

            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_erunak_stonespeakerAI (creature);
    }
};

class boss_mindbender_ghursha : public CreatureScript
{
public:
    boss_mindbender_ghursha() : CreatureScript("boss_mindbender_ghursha") { }

    struct boss_mindbender_ghurshaAI : public ScriptedAI
    {
        boss_mindbender_ghurshaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            mindbender = me;
        }

        std::list<uint64> SummonList;

        InstanceScript *instance;

        bool Enslaved;

        uint32 TargetTimer;
        uint32 EnslaveTimer;
        uint32 AbsorbMagicTimer;
        uint32 MindFogTimer;
        uint32 UnrelentingAgonyTimer;
        uint32 CastTimer;
        uint32 EnslaveEndTimer;
        Unit* EnslaveTarget;

        void Reset()
        {
            RemoveSummons();
        }

        void JustReachedHome()
        {
            erunak->SetReactState(REACT_AGGRESSIVE);
            erunak->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            erunak->setFaction(16);
            CAST_AI(boss_erunak_stonespeaker::boss_erunak_stonespeakerAI, erunak->AI())->phased = false;
            erunak->GetMotionMaster()->MoveTargetedHome();
            me->DespawnOrUnsummon();

            if (instance)
                instance->SetData(DATA_ERUNAK_STONESPEAKER_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Enslaved = false;
            erunak->HandleEmoteCommand(68);
            erunak->setFaction(35);
            me->SetReactState(REACT_AGGRESSIVE);
            DoScriptText(SAY_PHASE_1_END_MINDBENDER, me);

            TargetTimer = 3000;
            EnslaveTimer = 5000;
            AbsorbMagicTimer = 20000;
            MindFogTimer = urand(6000, 12000);
            UnrelentingAgonyTimer = 10000;
        }

        void RemoveSummons()
        {
            if (SummonList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
            {
                if (Creature* temp = Unit::GetCreature(*me, *itr))
                    if (temp)
                        temp->DisappearAndDie();
            }
            SummonList.clear();
        }

        void JustSummoned(Creature* summon)
        {
            summon->CastSpell(summon,SPELL_MIND_FOG_AURA, false);
            summon->CastSpell(summon,SPELL_MIND_FOG_VISUAL, false);
            summon->SetReactState(REACT_PASSIVE);
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            SummonList.push_back(summon->GetGUID());
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (TargetTimer <= diff && Enslaved == false)
            {
                EnslaveTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                TargetTimer = 1000;
            } else TargetTimer -= diff;

            if (EnslaveEndTimer <= diff && Enslaved == true)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                EnslaveTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                EnslaveTarget->RemoveAurasDueToSpell(SPELL_ENSLAVE);
                EnslaveTarget->RemoveAurasDueToSpell(SPELL_ENSLAVE_BUFF);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                Enslaved = false;
                EnslaveTimer = 30000;
                AbsorbMagicTimer = 20000;
                MindFogTimer = urand(6000,12000);
                UnrelentingAgonyTimer = 10000;
                EnslaveEndTimer = 90000;
            } else EnslaveEndTimer -= diff;

            if (EnslaveTimer <= diff && Enslaved == false)
            {
                if (EnslaveTarget)
                {
                    DoZoneInCombat();
                    me->SetReactState(REACT_PASSIVE);
                    DoCast(EnslaveTarget, SPELL_ENSLAVE);
                    DoCast(EnslaveTarget, SPELL_ENSLAVE_BUFF);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    DoScriptText(RAND(SAY_MIND_CONTROL_1,SAY_MIND_CONTROL_2,SAY_MIND_CONTROL_3), me);
                    Enslaved = true;
                    EnslaveTimer = 180000;
                    AbsorbMagicTimer = 180000;
                    MindFogTimer = 180000;
                    UnrelentingAgonyTimer = 180000;
                    EnslaveEndTimer = DUNGEON_MODE(60000,30000);
                    CastTimer = 2000;
                }
                EnslaveTimer = 1000;
            } else EnslaveTimer -= diff;

            if (EnslaveTarget && Enslaved == true)
                if (EnslaveTarget->HealthBelowPct(50))
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    EnslaveTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                    EnslaveTarget->RemoveAurasDueToSpell(SPELL_ENSLAVE);
                    EnslaveTarget->RemoveAurasDueToSpell(SPELL_ENSLAVE_BUFF);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    Enslaved = false;
                    EnslaveTimer = 30000;
                    AbsorbMagicTimer = 20000;
                    MindFogTimer = urand(6000,12000);
                    UnrelentingAgonyTimer = 10000;
                }

            if (CastTimer <= diff && Enslaved == true)
            {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, NotCharmedTargetSelector()))
                {
                    switch(EnslaveTarget->getClass())
                    {
                        case CLASS_DRUID:
                            if (urand(0, 1))
                                EnslaveTarget->CastSpell(target, 8921, false);
                            else
                                EnslaveTarget->CastSpell(me, 774, false);
                            break;
                        case CLASS_HUNTER:
                            EnslaveTarget->CastSpell(target, RAND(2643, 1978), false);
                            break;
                        case CLASS_MAGE:
                            EnslaveTarget->CastSpell(target, RAND(44614, 30455), false);
                            break;
                        case CLASS_WARLOCK:
                            EnslaveTarget->CastSpell(target, RAND(980, 686), true);
                            break;
                        case CLASS_WARRIOR:
                            EnslaveTarget->CastSpell(target, RAND(46924, 845), false);
                            break;
                        case CLASS_PALADIN:
                            if (urand(0, 1))
                                EnslaveTarget->CastSpell(target, 853, false);
                            else
                                EnslaveTarget->CastSpell(me, 20473, false);
                            break;
                        case CLASS_PRIEST:
                            if (urand(0,1))
                                EnslaveTarget->CastSpell(target, 34914, false);
                            else
                                EnslaveTarget->CastSpell(me, 139, false);
                            break;
                        case CLASS_SHAMAN:
                            if (urand(0,1))
                                EnslaveTarget->CastSpell(target, 421, false);
                            else
                                EnslaveTarget->CastSpell(me, 61295, false);
                            break;
                        case CLASS_ROGUE:
                            EnslaveTarget->CastSpell(target, RAND(16511, 1329), false);
                            break;
                        case CLASS_DEATH_KNIGHT:
                            if (urand(0,1))
                                EnslaveTarget->CastSpell(target, 45462, true);
                            else
                                EnslaveTarget->CastSpell(target, 49184, true);
                            break;
                    }
                }
                CastTimer = 3000;
            } else CastTimer -= diff;

            if (AbsorbMagicTimer <= diff && Enslaved == false)
            {
                DoCast(me, SPELL_ABSORB_MAGIC);
                AbsorbMagicTimer = urand(15000, 20000);
            } else AbsorbMagicTimer -= diff;

            if (MindFogTimer <= diff && Enslaved == false)
            {
                DoCast(me, SPELL_MIND_FOG_SUMMON);
                DoScriptText(SAY_MIND_FOG, me);
                MindFogTimer = 18000;
            } else MindFogTimer -= diff;

            if (UnrelentingAgonyTimer <= diff && Enslaved == false)
            {
                DoCastAOE(SPELL_UNRELENTING_AGONY);
                UnrelentingAgonyTimer = 20000;
            } else UnrelentingAgonyTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            DoScriptText(SAY_WIN_ERUNAK, erunak);
            RemoveSummons();
            erunak->setFaction(35);

            if (instance)
                instance->SetData(DATA_ERUNAK_STONESPEAKER_EVENT, DONE);
        }
    };

    CreatureAI* GetAI(Creature* creature)const
    {
        return new boss_mindbender_ghurshaAI(creature);
    }
};

void AddSC_boss_erunak_stonespeaker()
{
    new boss_erunak_stonespeaker();
    new boss_mindbender_ghursha();
}