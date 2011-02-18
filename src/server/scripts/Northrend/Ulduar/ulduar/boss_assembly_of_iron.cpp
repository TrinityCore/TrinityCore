/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Assembly of Iron
Author: PrinceCreed
SD%Complete: 100%
SDComment:
EndScriptData */

#include "ScriptPCH.h"
#include "ulduar.h"

enum Spells
{
    // Any boss
    SPELL_SUPERCHARGE                           = 61920,
    SPELL_BERSERK                               = 47008,    // Hard enrage, don't know the correct ID.

    // Steelbreaker
    SPELL_HIGH_VOLTAGE                          = 61890,
    SPELL_FUSION_PUNCH                          = 61903,
    SPELL_STATIC_DISRUPTION                     = 44008, //63494
    SPELL_OVERWHELMING_POWER                    = 64637,
    SPELL_ELECTRICAL_CHARGE                     = 61902,

    // Runemaster Molgeim
    SPELL_SHIELD_OF_RUNES                       = 62274,
    SPELL_RUNE_OF_POWER                         = 61973,
    SPELL_RUNE_OF_POWER_VISUAL                  = 61974,
    SPELL_RUNE_OF_DEATH                         = 62269,
    SPELL_RUNE_OF_SUMMONING                     = 62273,
    SPELL_RUNE_OF_SUMMONING_VISUAL              = 62019,
    SPELL_RUNE_OF_SUMMONING_SUMMON              = 62020,
    SPELL_LIGHTNING_BLAST                       = 62054,

    // Stormcaller Brundir
    SPELL_CHAIN_LIGHTNING                       = 61879,
    SPELL_OVERLOAD                              = 61869,
    SPELL_LIGHTNING_WHIRL                       = 61915,
    SPELL_LIGHTNING_TENDRILS                    = 61887,
    SPELL_LIGHTNING_TENDRILS_SELF_VISUAL        = 61883,
    SPELL_STORMSHIELD                           = 64187
};

enum eEnums
{
    EVENT_ENRAGE,
    // Steelbreaker
    EVENT_FUSION_PUNCH,
    EVENT_STATIC_DISRUPTION,
    EVENT_OVERWHELMING_POWER,
    // Molgeim
    EVENT_RUNE_OF_POWER,
    EVENT_SHIELD_OF_RUNES,
    EVENT_RUNE_OF_DEATH,
    EVENT_RUNE_OF_SUMMONING,
    EVENT_LIGHTNING_BLAST,
    // Brundir
    EVENT_CHAIN_LIGHTNING,
    EVENT_OVERLOAD,
    EVENT_LIGHTNING_WHIRL,
    EVENT_LIGHTNING_TENDRILS,
    EVENT_FLIGHT,
    EVENT_ENDFLIGHT,
    EVENT_GROUND,
    EVENT_LAND,
    EVENT_MOVE_POS
};

enum Actions
{
    ACTION_STEELBREAKER,
    ACTION_MOLGEIM,
    ACTION_BRUNDIR
};

// Achievements
#define ACHIEVEMENT_ON_YOUR_SIDE                RAID_MODE(2945, 2946) // TODO
#define ACHIEVEMENT_CANT_WHILE_STUNNED          RAID_MODE(2947, 2948) // TODO
#define ACHIEVEMENT_CHOOSE_STEELBREAKER         RAID_MODE(2941, 2944)
#define ACHIEVEMENT_CHOOSE_MOLGEIM              RAID_MODE(2939, 2942)
#define ACHIEVEMENT_CHOOSE_BRUNDIR              RAID_MODE(2940, 2943)

#define EMOTE_OVERLOAD              "Stormcaller Brundir begins to Overload!"

enum Yells
{
    SAY_STEELBREAKER_AGGRO                      = -1603020,
    SAY_STEELBREAKER_SLAY_1                     = -1603021,
    SAY_STEELBREAKER_SLAY_2                     = -1603022,
    SAY_STEELBREAKER_POWER                      = -1603023,
    SAY_STEELBREAKER_DEATH_1                    = -1603024,
    SAY_STEELBREAKER_DEATH_2                    = -1603025,
    SAY_STEELBREAKER_BERSERK                    = -1603026,

    SAY_MOLGEIM_AGGRO                           = -1603030,
    SAY_MOLGEIM_SLAY_1                          = -1603031,
    SAY_MOLGEIM_SLAY_2                          = -1603032,
    SAY_MOLGEIM_RUNE_DEATH                      = -1603033,
    SAY_MOLGEIM_SUMMON                          = -1603034,
    SAY_MOLGEIM_DEATH_1                         = -1603035,
    SAY_MOLGEIM_DEATH_2                         = -1603036,
    SAY_MOLGEIM_BERSERK                         = -1603037,

    SAY_BRUNDIR_AGGRO                           = -1603040,
    SAY_BRUNDIR_SLAY_1                          = -1603041,
    SAY_BRUNDIR_SLAY_2                          = -1603042,
    SAY_BRUNDIR_SPECIAL                         = -1603043,
    SAY_BRUNDIR_FLIGHT                          = -1603044,
    SAY_BRUNDIR_DEATH_1                         = -1603045,
    SAY_BRUNDIR_DEATH_2                         = -1603046,
    SAY_BRUNDIR_BERSERK                         = -1603047,
};

bool IsEncounterComplete(InstanceScript* pInstance, Creature* me)
{
   if (!pInstance || !me)
        return false;

    for (uint8 i = 0; i < 3; ++i)
    {
        uint64 guid = pInstance->GetData64(DATA_STEELBREAKER+i);
        if (!guid)
            return false;

        if (Creature *boss = Unit::GetCreature(*me, guid))
        {
            if (boss->isAlive())
                return false;
        }
        else
            return false;
    }
    return true;
}

// Avoid killing bosses one to one
void CallBosses(InstanceScript* pInstance, uint32 caller, Unit *who)
{
    // Respawn if dead
    if (Creature* Steelbreaker = who->GetCreature(*who, pInstance->GetData64(DATA_STEELBREAKER)))
        if (Steelbreaker->isDead())
        {            
            Steelbreaker->Respawn(true);
            Steelbreaker->GetMotionMaster()->MoveTargetedHome();
        }
    if (Creature* Brundir = who->GetCreature(*who, pInstance->GetData64(DATA_BRUNDIR)))
        if (Brundir->isDead())
        {
            Brundir->Respawn(true);
            Brundir->GetMotionMaster()->MoveTargetedHome();
        }
    if (Creature* Molgeim = who->GetCreature(*who, pInstance->GetData64(DATA_MOLGEIM)))
        if (Molgeim->isDead())
        {
            Molgeim->Respawn(true);
            Molgeim->GetMotionMaster()->MoveTargetedHome();
        }
    
    for (uint8 i = 0; i < 3; ++i)
    {
        if (caller == DATA_STEELBREAKER+i) continue;
        uint64 guid = pInstance->GetData64(DATA_STEELBREAKER+i);
        if (!guid) return;
        if (Creature* m_boss = pInstance->instance->GetCreature(guid))
        {
            if (m_boss->isAlive())
            {
                m_boss->AddThreat(who, 100.0f);
                m_boss->AI()->AttackStart(who);
            }
        }
    }
}

class boss_steelbreaker : public CreatureScript
{
public:
    boss_steelbreaker() : CreatureScript("boss_steelbreaker") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_steelbreakerAI (pCreature);
    }

    struct boss_steelbreakerAI : public ScriptedAI
    {
        boss_steelbreakerAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }
        
        EventMap events;
        InstanceScript* pInstance;
        uint32 phase;

        void Reset()
        {
            events.Reset();
            phase = 0;
            me->RemoveAllAuras();
            me->ResetLootMode();
            if (pInstance)
                pInstance->SetBossState(BOSS_ASSEMBLY, NOT_STARTED);
            
            // Respawn
            if (Creature* Brundir = me->GetCreature(*me, pInstance->GetData64(DATA_BRUNDIR)))
                if (Brundir->isDead())
                {
                    Brundir->Respawn(true);
                    Brundir->GetMotionMaster()->MoveTargetedHome();
                }
            if (Creature* Molgeim = me->GetCreature(*me, pInstance->GetData64(DATA_MOLGEIM)))
                if (Molgeim->isDead())
                {
                    Molgeim->Respawn(true);
                    Molgeim->GetMotionMaster()->MoveTargetedHome();
                }
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_STEELBREAKER_AGGRO, me);
            DoZoneInCombat();
            CallBosses(pInstance, DATA_STEELBREAKER, who);
            DoCast(me, SPELL_HIGH_VOLTAGE);
            phase = 1;
            events.SetPhase(phase);
            events.ScheduleEvent(EVENT_ENRAGE, 900000);
            events.ScheduleEvent(EVENT_FUSION_PUNCH, 15000);
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(RAND(SAY_STEELBREAKER_DEATH_1, SAY_STEELBREAKER_DEATH_2), me);
    
            if (IsEncounterComplete(pInstance, me) && pInstance)
            {
                pInstance->SetBossState(BOSS_ASSEMBLY, DONE);
                pInstance->DoCompleteAchievement(ACHIEVEMENT_CHOOSE_STEELBREAKER);
                pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 65195);
            }
            else me->SetLootRecipient(NULL);
            
            if (Creature* Brundir = me->GetCreature(*me, pInstance->GetData64(DATA_BRUNDIR)))
                if (Brundir->isAlive())
                    Brundir->AI()->DoAction(ACTION_BRUNDIR);

            if (Creature* Molgeim = me->GetCreature(*me, pInstance->GetData64(DATA_MOLGEIM)))
                if (Molgeim->isAlive())
                    Molgeim->AI()->DoAction(ACTION_MOLGEIM);
        }

        void KilledUnit(Unit * /*who*/)
        {
            DoScriptText(RAND(SAY_STEELBREAKER_SLAY_1,SAY_STEELBREAKER_SLAY_2), me);

            if (phase == 3)
                DoCast(me, SPELL_ELECTRICAL_CHARGE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_ENRAGE:
                        DoScriptText(SAY_STEELBREAKER_BERSERK, me);
                        DoCast(SPELL_BERSERK);
                        break;
                    case EVENT_FUSION_PUNCH:
                        if (me->IsWithinMeleeRange(me->getVictim()))
                            DoCastVictim(SPELL_FUSION_PUNCH);
                        events.ScheduleEvent(EVENT_FUSION_PUNCH, urand(15000, 20000));
                        break;
                    case EVENT_STATIC_DISRUPTION:
                        if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_STATIC_DISRUPTION);
                        events.ScheduleEvent(EVENT_STATIC_DISRUPTION, 20000 + (rand()%20)*1000);
                        break;
                    case EVENT_OVERWHELMING_POWER:
                        DoScriptText(SAY_STEELBREAKER_POWER, me);
                        DoCastVictim(SPELL_OVERWHELMING_POWER);
                        events.ScheduleEvent(EVENT_OVERWHELMING_POWER, RAID_MODE(60000, 35000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case ACTION_STEELBREAKER:
                    me->SetFullHealth();
                    me->AddAura(SPELL_SUPERCHARGE, me);
                    ++phase;
                    events.SetPhase(phase);
                    if (phase >= 2)
                        events.RescheduleEvent(EVENT_STATIC_DISRUPTION, 30000);
                    if (phase >= 3)
                    {
                        events.RescheduleEvent(EVENT_OVERWHELMING_POWER, urand(2000, 5000));
                        // Add HardMode Loot
                        me->AddLootMode(LOOT_MODE_HARD_MODE_2);
                    }
                    break;
            }
        }
    };

};

class boss_runemaster_molgeim : public CreatureScript
{
public:
    boss_runemaster_molgeim() : CreatureScript("boss_runemaster_molgeim") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_runemaster_molgeimAI (pCreature);
    }

    struct boss_runemaster_molgeimAI : public ScriptedAI
    {
        boss_runemaster_molgeimAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }

        InstanceScript* pInstance;
        EventMap events;
        uint32 phase;

        void Reset()
        {
            if (pInstance)
                pInstance->SetBossState(BOSS_ASSEMBLY, NOT_STARTED);
            events.Reset();
            me->ResetLootMode();
            me->RemoveAllAuras();
            phase = 0;
        
            // Respawn
            if (Creature* Brundir = me->GetCreature(*me, pInstance->GetData64(DATA_BRUNDIR)))
                if (Brundir->isDead())
                {
                    Brundir->Respawn(true);
                    Brundir->GetMotionMaster()->MoveTargetedHome();
                }
            if (Creature* Steelbreaker = me->GetCreature(*me, pInstance->GetData64(DATA_STEELBREAKER)))
                if (Steelbreaker->isDead())
                {            
                    Steelbreaker->Respawn(true);
                    Steelbreaker->GetMotionMaster()->MoveTargetedHome();
                }
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_MOLGEIM_AGGRO, me);
            DoZoneInCombat();
            CallBosses(pInstance, DATA_MOLGEIM, who);
            phase = 1;
            pInstance->SetBossState(BOSS_ASSEMBLY, IN_PROGRESS);
            events.ScheduleEvent(EVENT_ENRAGE, 900000);
            events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, 30000);
            events.ScheduleEvent(EVENT_RUNE_OF_POWER, 20000);
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(RAND(SAY_MOLGEIM_DEATH_1, SAY_MOLGEIM_DEATH_2), me);
    
            if (IsEncounterComplete(pInstance, me) && pInstance)
            {
                pInstance->SetBossState(BOSS_ASSEMBLY, DONE);
                pInstance->DoCompleteAchievement(ACHIEVEMENT_CHOOSE_MOLGEIM);
                pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 65195);
            }
            else me->SetLootRecipient(NULL);
            
            if (Creature* Brundir = me->GetCreature(*me, pInstance->GetData64(DATA_BRUNDIR)))
                if (Brundir->isAlive())
                    Brundir->AI()->DoAction(ACTION_BRUNDIR);

            if (Creature* Steelbreaker = me->GetCreature(*me, pInstance->GetData64(DATA_STEELBREAKER)))
                if (Steelbreaker->isAlive())
                    Steelbreaker->AI()->DoAction(ACTION_STEELBREAKER);
        }

        void KilledUnit(Unit * /*who*/)
        {
            DoScriptText(RAND(SAY_MOLGEIM_SLAY_1,SAY_MOLGEIM_SLAY_2), me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_ENRAGE:
                        DoScriptText(SAY_MOLGEIM_BERSERK, me);
                        DoCast(SPELL_BERSERK);
                        break;
                    case EVENT_RUNE_OF_POWER: // random alive friendly
                    {
                        Creature* bosschoosed;
                        uint32 choice = urand(0,2);

                        if (!pInstance) break;
                    
                        bosschoosed = me->GetCreature(*me, pInstance->GetData64(DATA_STEELBREAKER+choice));

                        if (!bosschoosed || !bosschoosed->isAlive())
                        {
                            choice = ((choice == 2) ? 0 : choice++);
                            bosschoosed = me->GetCreature(*me, pInstance->GetData64(DATA_STEELBREAKER+choice));
                            if (!bosschoosed || !bosschoosed->isAlive())
                            {
                                choice = ((choice == 2) ? 0 : choice++);
                                bosschoosed = me->GetCreature(*me, pInstance->GetData64(DATA_STEELBREAKER+choice));
                            }
                        }

                        if (!bosschoosed || !bosschoosed->isAlive())
                            bosschoosed = me->GetCreature(*me, pInstance->GetData64(DATA_MOLGEIM));
                    
                        DoCast(bosschoosed, SPELL_RUNE_OF_POWER);
                        events.ScheduleEvent(EVENT_RUNE_OF_POWER, 35000);
                        break;
                    }
                    case EVENT_SHIELD_OF_RUNES:
                        DoCast(me, SPELL_SHIELD_OF_RUNES);
                        events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, urand(60000, 80000));
                        break;
                    case EVENT_RUNE_OF_DEATH:
                        DoScriptText(SAY_MOLGEIM_RUNE_DEATH, me);
                        if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_RUNE_OF_DEATH);
                        events.ScheduleEvent(EVENT_RUNE_OF_DEATH, 30000);
                        break;
                    case EVENT_RUNE_OF_SUMMONING:
                        DoScriptText(SAY_MOLGEIM_SUMMON, me);
                        if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_RUNE_OF_SUMMONING);
                        events.ScheduleEvent(EVENT_RUNE_OF_SUMMONING, urand(40000, 50000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case ACTION_MOLGEIM:
                    me->SetFullHealth();
                    me->AddAura(SPELL_SUPERCHARGE, me);
                    ++phase;
                    events.SetPhase(phase);
                    events.RescheduleEvent(EVENT_SHIELD_OF_RUNES, 30000);
                    events.RescheduleEvent(EVENT_RUNE_OF_POWER, 20000);
                    if (phase >= 2)
                        events.RescheduleEvent(EVENT_RUNE_OF_DEATH, 35000);
                    if (phase >= 3)
                    {
                        events.RescheduleEvent(EVENT_RUNE_OF_SUMMONING, 40000);
                        me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                    }
                    break;
            }
        }
    };

};

class npc_lightning_elemental : public CreatureScript
{
public:
    npc_lightning_elemental() : CreatureScript("npc_lightning_elemental") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lightning_elementalAI (pCreature);
    }

    struct npc_lightning_elementalAI : public ScriptedAI
    {
        npc_lightning_elementalAI(Creature *c) : ScriptedAI(c)
        {
            Charge();
            Casted = false;
        }

        bool Casted;

        void Charge()
        {
            Unit* pTarget = me->SelectNearestTarget();
            me->AddThreat(pTarget, 5000000.0f);
            AttackStart(pTarget);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            if (me->IsWithinMeleeRange(me->getVictim()) && !Casted)
            {
                me->CastSpell(me, SPELL_LIGHTNING_BLAST, true);
                me->ForcedDespawn(500);
                Casted = true;
            }
        }
    };

};

class npc_rune_of_summoning : public CreatureScript
{
public:
    npc_rune_of_summoning() : CreatureScript("npc_rune_of_summoning") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_rune_of_summoningAI (pCreature);
    }

    struct npc_rune_of_summoningAI : public Scripted_NoMovementAI
    {
        npc_rune_of_summoningAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
        }

        uint32 SummonTimer;

        void Reset()
        {
            SummonTimer = 1500;
            me->ForcedDespawn(12500);
            DoCast(me, SPELL_RUNE_OF_SUMMONING_VISUAL);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (SummonTimer <= uiDiff)
            {
                DoCast(me, SPELL_RUNE_OF_SUMMONING_SUMMON);
                SummonTimer = 1500;
            } 
            else SummonTimer -= uiDiff;
        }
    };

};

class npc_rune_of_power : public CreatureScript
{
public:
    npc_rune_of_power() : CreatureScript("npc_rune_of_power") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_rune_of_powerAI (pCreature);
    }

    struct npc_rune_of_powerAI : public Scripted_NoMovementAI
    {
        npc_rune_of_powerAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
            me->setFaction(16);
        }

        void Reset()
        {
            DoCast(me, SPELL_RUNE_OF_POWER_VISUAL, true);
            me->ForcedDespawn(35000);
        }
    };

};


class boss_stormcaller_brundir : public CreatureScript
{
public:
    boss_stormcaller_brundir() : CreatureScript("boss_stormcaller_brundir") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_stormcaller_brundirAI (pCreature);
    }

    struct boss_stormcaller_brundirAI : public ScriptedAI
    {
        boss_stormcaller_brundirAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }
        
        EventMap events;
        InstanceScript* pInstance;
        uint32 phase;
        uint32 Position;

        void Reset()
        {
            if (pInstance)
                pInstance->SetBossState(BOSS_ASSEMBLY, NOT_STARTED);
            me->RemoveAllAuras();
            me->ResetLootMode();
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING | MOVEMENTFLAG_WALKING);
            events.Reset();
            phase = 0;
        
            // Respawn
            if (Creature* Molgeim = me->GetCreature(*me, pInstance->GetData64(DATA_MOLGEIM)))
                if (Molgeim->isDead())
                {
                    Molgeim->Respawn(true);
                    Molgeim->GetMotionMaster()->MoveTargetedHome();
                }
            if (Creature* Steelbreaker = me->GetCreature(*me, pInstance->GetData64(DATA_STEELBREAKER)))
                if (Steelbreaker->isDead())
                {            
                    Steelbreaker->Respawn(true);
                    Steelbreaker->GetMotionMaster()->MoveTargetedHome();
                }
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_BRUNDIR_AGGRO, me);
            DoZoneInCombat();
            CallBosses(pInstance, DATA_BRUNDIR, who);
            phase = 1;
            events.ScheduleEvent(EVENT_MOVE_POS, 1000);
            events.ScheduleEvent(EVENT_ENRAGE, 900000);
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 2000);
            events.ScheduleEvent(EVENT_OVERLOAD, urand(60000, 120000));
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(RAND(SAY_BRUNDIR_DEATH_1, SAY_BRUNDIR_DEATH_2), me);
    
            if (IsEncounterComplete(pInstance, me) && pInstance)
            {
                pInstance->SetBossState(BOSS_ASSEMBLY, DONE);
                pInstance->DoCompleteAchievement(ACHIEVEMENT_CHOOSE_BRUNDIR);
                pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 65195);
                if (me->GetPositionZ() > 428)
                    me->GetMotionMaster()->MoveFall(427.28f);
            }
            else me->SetLootRecipient(NULL);

            if (Creature* Molgeim = me->GetCreature(*me, pInstance->GetData64(DATA_MOLGEIM)))
                if (Molgeim->isAlive())
                    Molgeim->AI()->DoAction(ACTION_MOLGEIM);

            if (Creature* Steelbreaker = me->GetCreature(*me, pInstance->GetData64(DATA_STEELBREAKER)))
                if (Steelbreaker->isAlive())
                    Steelbreaker->AI()->DoAction(ACTION_STEELBREAKER);
        }

        void KilledUnit(Unit* /*who*/)
        {
            DoScriptText(RAND(SAY_BRUNDIR_SLAY_1,SAY_BRUNDIR_SLAY_2), me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            
            events.Update(diff);
        
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_MOVE_POS:
                        MovePos();
                        events.RescheduleEvent(EVENT_MOVE_POS, 10000);
                        break;            
                    case EVENT_ENRAGE:
                        DoScriptText(SAY_BRUNDIR_BERSERK, me);
                        DoCast(SPELL_BERSERK);
                        break;
                    case EVENT_CHAIN_LIGHTNING:
                        if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_CHAIN_LIGHTNING);
                        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(4000, 6000));
                        break;
                    case EVENT_OVERLOAD:
                        me->MonsterTextEmote(EMOTE_OVERLOAD, 0, true);
                        DoScriptText(SAY_BRUNDIR_SPECIAL, me);
                        me->GetMotionMaster()->Initialize();
                        DoCast(SPELL_OVERLOAD);
                        events.ScheduleEvent(EVENT_OVERLOAD, urand(60000, 120000));
                        break;
                    case EVENT_LIGHTNING_WHIRL:
                        me->GetMotionMaster()->Initialize();
                        DoCast(SPELL_LIGHTNING_WHIRL);
                        events.ScheduleEvent(EVENT_LIGHTNING_WHIRL, urand(15000, 20000));
                        break;
                    case EVENT_LIGHTNING_TENDRILS:
                        DoScriptText(SAY_BRUNDIR_FLIGHT, me);
                        DoCast(SPELL_LIGHTNING_TENDRILS);
                        DoCast(SPELL_LIGHTNING_TENDRILS_SELF_VISUAL);
                        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), 435);
                        events.DelayEvents(34000);
                        events.ScheduleEvent(EVENT_FLIGHT, 2500);
                        events.ScheduleEvent(EVENT_ENDFLIGHT, 28000);
                        events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS, 90000);
                        break;
                    case EVENT_FLIGHT:
                        if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            me->GetMotionMaster()->MovePoint(0, pTarget->GetPositionX(), pTarget->GetPositionY(), 435);
                        events.ScheduleEvent(EVENT_FLIGHT, 6000);
                        break;
                    case EVENT_ENDFLIGHT:
                        me->GetMotionMaster()->MovePoint(0, 1586.920f, 119.849f, 435);
                        events.CancelEvent(EVENT_FLIGHT);
                        events.ScheduleEvent(EVENT_LAND, 4000);
                        break;
                    case EVENT_LAND:
                        me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), 427.28f);
                        events.ScheduleEvent(EVENT_GROUND, 1500);
                        break;
                    case EVENT_GROUND:
                        me->RemoveAurasDueToSpell(SPELL_LIGHTNING_TENDRILS);
                        me->RemoveAurasDueToSpell(SPELL_LIGHTNING_TENDRILS_SELF_VISUAL);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SendMovementFlagUpdate();
                        break;
                }
            }
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case ACTION_BRUNDIR:
                    me->SetFullHealth();
                    me->AddAura(SPELL_SUPERCHARGE, me);
                    ++phase;
                    events.SetPhase(phase);
                    events.RescheduleEvent(EVENT_CHAIN_LIGHTNING, urand(6000, 12000));
                    events.RescheduleEvent(EVENT_OVERLOAD, 40000);
                    if (phase >= 2)
                        events.RescheduleEvent(EVENT_LIGHTNING_WHIRL, urand(15000, 20000));
                    if (phase >= 3)
                    {
                        me->AddAura(SPELL_STORMSHIELD, me);
                        events.RescheduleEvent(EVENT_LIGHTNING_TENDRILS, 60000);
                        me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                    }
                    break;
            }
        }
    
        void MovePos()
        {
            switch(Position)
            {
                case 0:
                    me->GetMotionMaster()->MovePoint(0, 1587.28f, 97.030f, 427.28f);
                    break;
                case 1:
                    me->GetMotionMaster()->MovePoint(0, 1587.18f, 121.03f, 427.28f);
                    break;
                case 2:
                    me->GetMotionMaster()->MovePoint(0, 1587.34f, 142.58f, 427.28f);
                    break;
                case 3:
                    me->GetMotionMaster()->MovePoint(0, 1587.18f, 121.03f, 427.28f);
                    break;
            }

            Position++;
            if (Position > 3)
            {
                Position = 0;
            }
        }
    };

};


void AddSC_boss_assembly_of_iron()
{
    new boss_steelbreaker();
    new boss_runemaster_molgeim();
    new boss_stormcaller_brundir();
    new npc_lightning_elemental();
    new npc_rune_of_summoning();
    new npc_rune_of_power();
}
