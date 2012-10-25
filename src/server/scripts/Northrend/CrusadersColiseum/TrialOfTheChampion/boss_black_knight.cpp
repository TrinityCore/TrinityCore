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

/* ScriptData
SDName: Boss Black Knight
SD%Complete: 80%
SDComment: missing yells. not sure about timers.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"

enum eEnums
{
    SAY_INTRO_1             = -1999928, // You spoiled my grand entrance, Rat.
    SAY_INTRO_2             = -1999952, // What is the meaning of this? -Tirion
    SAY_INTRO_3             = -1999929, // Did you honestly think an agent of the Lich King would be bested on the field of your pathetic little tournament?
    SAY_INTRO_4             = -1999930, // I have come to finish my task
    SAY_AGGRO               = -1999931, // This farce ends here!
    SAY_AGGRO_A             = -1999998, // Don't just stand there; kill him!
    SAY_AGGRO_H             = -1999999, // Tear him apart!
    SAY_KILL_1              = -1999969, // Pathetic
    SAY_KILL_2              = -1999970, // A waste of flesh.
    SAY_PHASE_1             = -1999933, // My roting flash was just getting in the way!
    SAY_PHASE_2             = -1999934, // I have no need for bones to best you!
    SAY_DEATH               = -1999935, // No! I must not fail...again...
    SAY_START11             = -1999953, // I am too young.
};

enum eSpells
{
    //phase 1
    SPELL_PLAGUE_STRIKE     = 67724,
    SPELL_ICY_TOUCH         = 67718,
    SPELL_ICY_TOUCH_H       = 67881,
    SPELL_DEATH_RESPITE     = 67745,
    SPELL_DEATH_RESPITE_H   = 68306,
    SPELL_OBLITERATE        = 67725,
    SPELL_OBLITERATE_H      = 67883,
    ZOMBIE_JAEREN           = 67715,
    ZOMBIE_ARELAS           = 67705,
    KILL_HERALD             = 66804,
    SPELL_RESPITE_HERALD    = 66798,

    //phase 2 - During this phase, the Black Knight will use the same abilities as in phase 1, except for Death's Respite
    SPELL_ARMY_DEAD         = 67761,
    SPELL_DESECRATION       = 68766,
    SPELL_GHOUL_EXPLODE     = 67751,

    //phase 3
    SPELL_DEATH_BITE        = 67808,
    SPELL_DEATH_BITE_H      = 67875,
    SPELL_MARKED_DEATH      = 67882,

    SPELL_BLACK_KNIGHT_RES  = 67693,

    SPELL_LEAP              = 67749,
    SPELL_LEAP_H            = 67880,
    SPELL_CLAW              = 67774,
    SPELL_CLAW_H            = 67879,

    SPELL_KILL_CREDIT       = 68663
};

enum eModels
{
    MODEL_SKELETON          = 29846,
    MODEL_GHOST             = 21300
};

enum eEquip
{
    EQUIP_SWORD             = 40343
};

enum IntroPhase
{
    IDLE,
    INTRO,
    NORMAL,
    FINISHED,
};

enum ePhases
{
    PHASE_UNDEAD            = 3,
    PHASE_SKELETON          = 4,
    PHASE_GHOST             = 5,

};

enum Creatures
{
    CREATURE_HIGHLORD       = 34996,
    CREATURE_ANNOUNCER      = 35004,
};

const Position MoveKnightPos = {746.993286f, 622.990784f, 411.417237f, 4.712464f}; // Jaina/Sylvanas walks to throne

class boss_black_knight : public CreatureScript
{
public:
    boss_black_knight() : CreatureScript("boss_black_knight") { }

    struct boss_black_knightAI : public ScriptedAI
    {
        boss_black_knightAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            Phase = IDLE;
            bCredit = false;
        }

        InstanceScript* instance;

        std::list<uint64> SummonList;

        bool bEventInProgress;
        bool bEvent;
        bool bSummonArmy;
        bool bDeathArmyDone;
        bool bEventInBattle;
        bool bFight;
        bool bCredit;

        uint8 uiPhase;
        uint8 uiIntroPhase;

        Creature* pHighlord;
        Creature* pAnnouncer;

        IntroPhase Phase;

        uint32 uiIntroTimer;
        uint32 uiPlagueStrikeTimer;
        uint32 uiPlagueStrike1Timer;
        uint32 uiIcyTouchTimer;
        uint32 uiIcyTouch1Timer;
        uint32 uiDeathRespiteTimer;
        uint32 uiObliterateTimer;
        uint32 uiObliterate1Timer;
        uint32 uiDesecrationTimer;
        uint32 uiResurrectTimer;
        uint32 uiDeathArmyCheckTimer;
        uint32 uiGhoulExplodeTimer;
        uint32 uiDeathBiteTimer;
        uint32 uiMarkedDeathTimer;

        void Reset()
        {
            RemoveSummons();
            me->SetDisplayId(me->GetNativeDisplayId());
            me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);

            bEventInProgress = false;
            bEvent = false;
            bSummonArmy = false;
            bDeathArmyDone = false;
            bFight = false;
            pAnnouncer = NULL;

            if (instance)
            {
                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                    instance->HandleGameObject(go->GetGUID(), false);

                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(go->GetGUID(), true);
            }

            if (bEventInBattle)
            {
                me->GetMotionMaster()->MovePoint(1, 743.396f, 635.411f, 411.575f);
                me->setFaction(14);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }

            uiPhase = PHASE_UNDEAD;

            uiIcyTouchTimer = urand(5000, 9000);
            uiIcyTouch1Timer = urand(15000, 15000);
            uiPlagueStrikeTimer = urand(10000, 13000);
            uiDeathRespiteTimer = 17000;
            uiPlagueStrike1Timer = urand(14000, 14000);
            uiObliterateTimer = urand(17000, 19000);
            uiObliterate1Timer = urand(15000, 15000);
            uiDesecrationTimer = urand(15000, 16000);
            uiDesecrationTimer = 22000;
            uiDeathArmyCheckTimer = 7000;
            uiResurrectTimer = 4000;
            uiGhoulExplodeTimer = 8000;
            uiDeathBiteTimer = urand (2000, 4000);
            uiMarkedDeathTimer = urand (5000, 7000);
            uiIntroTimer = 15000;
            uiIntroPhase = 0;
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who)
                return;

            if (Phase == IDLE && me->IsValidAttackTarget(who) && me->IsWithinDistInMap(who, 200))
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                Phase = INTRO;
            }
        }

        void RemoveSummons()
        {
            if (SummonList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
            {
                if (Creature* temp = Unit::GetCreature(*me, *itr))
                {
                    if (temp)
                    {
                        // Let all remaining ghouls explode
                        if ((temp->GetEntry() == 35590 || temp->GetEntry() == 12444) && temp->isAlive())
                        {
                            me->CastSpell(temp, SPELL_GHOUL_EXPLODE, true);
                        }
                        else
                            temp->DisappearAndDie();
                    }
                }
            }
            SummonList.clear();
        }

        void JustSummoned(Creature* summon)
        {
            SummonList.push_back(summon->GetGUID());
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (Phase == IDLE)
                return;

            if (Phase == INTRO)
            {
                if (uiIntroTimer <= uiDiff)
                {
                    switch (uiIntroPhase)
                    {
                        case 0:
                            me->SetFacingTo(4.665f);
                            ++uiIntroPhase;
                            uiIntroTimer = 3000;
                            break;
                        case 1:
                        {
                            Creature* pAnnouncer = Unit::GetCreature(*me, instance->GetData64(DATA_ANNOUNCER));
                            DoScriptText(SAY_START11, pAnnouncer);
                            ++uiIntroPhase;
                            uiIntroTimer = 2000;
                            break;
                        }
                        case 2:
                        {
                            Creature* pAnnouncer = Unit::GetCreature(*me, instance->GetData64(DATA_ANNOUNCER));
                            pAnnouncer->DisappearAndDie();
                            me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                            me->GetMotionMaster()->MovePoint(0, MoveKnightPos);
                            ++uiIntroPhase;
                            uiIntroTimer = 2000;
                            break;
                        }
                        case 3:
                            DoScriptText(SAY_INTRO_3, me);
                            ++uiIntroPhase;
                            uiIntroTimer = 6000;
                            break;
                        case 4:
                            DoScriptText(SAY_INTRO_4, me);
                            ++uiIntroPhase;
                            uiIntroTimer = 3000;
                            break;
                        case 5:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->AI()->AttackStart(me->getVictim());
                            Phase = NORMAL;
                            break;
                    }
                } 
                else
                    uiIntroTimer -= uiDiff;
                return;
            }

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) || me->GetVehicle())
                return;

            if (bEventInProgress)
                if (uiResurrectTimer <= uiDiff)
                {
                    me->SetFullHealth();
                    me->AttackStop();

                    switch (uiPhase)
                    {
                        case PHASE_UNDEAD:
                            DoScriptText(SAY_PHASE_1, me);
                            break;
                        case PHASE_SKELETON:
                            DoScriptText(SAY_PHASE_2, me);
                            break;
                    }

                    DoCast(me, SPELL_BLACK_KNIGHT_RES, true);
                           me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    uiPhase++;
                    uiResurrectTimer = 3000;
                    bEventInProgress = false;
                    me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                }
                else
                    uiResurrectTimer -= uiDiff;

                switch (uiPhase)
                {
                    case PHASE_UNDEAD:
                    {
                        if (uiPlagueStrikeTimer <= uiDiff)
                        {
                            DoCastVictim(SPELL_PLAGUE_STRIKE);
                            uiPlagueStrikeTimer = urand(12000, 15000);
                        }
                        else
                            uiPlagueStrikeTimer -= uiDiff;
                    
                        if (uiObliterateTimer <= uiDiff)
                        {
                            DoCastVictim(DUNGEON_MODE(SPELL_OBLITERATE, SPELL_OBLITERATE_H));
                            uiObliterateTimer = urand(17000, 19000);
                        }
                        else
                            uiObliterateTimer -= uiDiff;
                    
                        if (uiIcyTouchTimer <= uiDiff)
                        {
                            DoCastVictim(DUNGEON_MODE(SPELL_ICY_TOUCH, SPELL_ICY_TOUCH_H));
                            uiIcyTouchTimer = urand(5000, 7000);
                        }
                        else
                            uiIcyTouchTimer -= uiDiff;
                        break;
                    }
                    case PHASE_SKELETON:
                    {
                        if (!bSummonArmy)
                        {
                            bSummonArmy = true;
                            me->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            DoCast(me, SPELL_ARMY_DEAD);
                        }

                        if (!bDeathArmyDone)
                            if (uiDeathArmyCheckTimer <= uiDiff)
                            {
                                me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                uiDeathArmyCheckTimer = 0;
                                bDeathArmyDone = true;
                            }
                            else
                                uiDeathArmyCheckTimer -= uiDiff;
                    
                        if (uiDesecrationTimer <= uiDiff)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                if (target->isAlive())
                                    DoCast(target, SPELL_DESECRATION);
                            }

                            uiDesecrationTimer = urand(15000, 16000);
                        }
                        else
                            uiDesecrationTimer -= uiDiff;
                        
                        if (uiGhoulExplodeTimer <= uiDiff)
                        {
                            if (!SummonList.empty())
                            {
                                for(std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
                                {
                                    if (Creature* temp = Unit::GetCreature(*me, *itr))
                                    {
                                        if (temp)
                                        {
                                            // Let all remaining ghouls explode
                                            if (temp->GetEntry() == 35590 || temp->GetEntry() == 12444)
                                            {
                                                if (temp->isAlive())
                                                {
                                                    me->CastSpell(temp, SPELL_GHOUL_EXPLODE, true);
                                                    break;
                                                }
                                                else
                                                    continue;
                                            }
                                        }
                                    }
                                }
                            }

                            uiGhoulExplodeTimer = 8000;
                        }
                        else
                            uiGhoulExplodeTimer -= uiDiff;
                    
                        if (uiPlagueStrike1Timer <= uiDiff)
                        {
                            DoCastVictim(SPELL_PLAGUE_STRIKE);
                            uiPlagueStrike1Timer = urand(12000, 15000);
                        }
                        else
                            uiPlagueStrike1Timer -= uiDiff;
                    
                        if (uiObliterate1Timer <= uiDiff)
                        {
                            DoCastVictim(SPELL_OBLITERATE);
                            uiObliterate1Timer = urand(17000, 19000);
                        }
                        else
                            uiObliterate1Timer -= uiDiff;
                    
                        if (uiIcyTouch1Timer <= uiDiff)
                        {
                            DoCastVictim(SPELL_ICY_TOUCH);
                            uiIcyTouch1Timer = urand(5000, 7000);
                        }
                        else
                            uiIcyTouch1Timer -= uiDiff;
                    
                        if (uiDeathRespiteTimer <= uiDiff)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                if (target && target->isAlive())
                                DoCast(target, SPELL_DEATH_RESPITE);
                            }

                            uiDeathRespiteTimer = urand(15000, 16000);
                        }
                        else
                            uiDeathRespiteTimer -= uiDiff;
                        break;
                    }

                    case PHASE_GHOST:
                    {
                        if (uiDeathBiteTimer <= uiDiff)
                        {
                            SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
                            DoCast(me, DUNGEON_MODE(SPELL_DEATH_BITE, SPELL_DEATH_BITE_H));
                            uiDeathBiteTimer = urand (2000, 4000);
                        }
                        else
                            uiDeathBiteTimer -= uiDiff;
                
                        if (uiMarkedDeathTimer <= uiDiff)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                if (target && target->isAlive())
                                    DoCast(target, SPELL_MARKED_DEATH);
                            }

                            uiMarkedDeathTimer = urand (10000, 12000);
                        }
                        else
                            uiMarkedDeathTimer -= uiDiff;
                        break;
                    }
                }

                if (!me->HasUnitState(UNIT_STATE_ROOT) && !me->HealthBelowPct(1))
                    DoMeleeAttackIfReady();
        }

        void EnterCombat(Unit* who)
        {
            bEventInBattle = true;
            DoScriptText(SAY_AGGRO, me);
            SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);

            if (me->ToTempSummon())
            {
                me->ToTempSummon()->InitStats(9000000);
                me->ToTempSummon()->SetTempSummonType(TEMPSUMMON_CORPSE_TIMED_DESPAWN);
            }

            if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                DoCast(me, ZOMBIE_JAEREN);
            else
                DoCast(me, ZOMBIE_ARELAS);

            if (instance)
            {
                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(go->GetGUID(), false);

                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                    instance->HandleGameObject(go->GetGUID(), false);
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(urand(0, 1) ? SAY_KILL_1 : SAY_KILL_2, me);
            if (instance)
                instance->SetData(BOSS_BLACK_KNIGHT, IN_PROGRESS);
        }

        void DamageTaken(Unit* /*who*/, uint32& uiDamage)
        {
            if (uiDamage >= me->GetHealth() && uiPhase <= PHASE_SKELETON)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                uiDamage = 0;
                me->SetHealth(0);
                me->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                RemoveSummons();
                switch (uiPhase)
                {
                    case PHASE_UNDEAD:
                        me->SetDisplayId(MODEL_SKELETON);
                        break;
                    case PHASE_SKELETON:
                        me->SetDisplayId(MODEL_GHOST);
                        SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
                        break;
                }
                bEventInProgress = true;
            }
            else if (uiDamage >= me->GetHealth() && uiPhase == PHASE_GHOST && !bCredit)
            {
                bCredit = true;
                HandleSpellOnPlayersInInstanceToC5(me, 68663);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            if (TempSummon* summ = me->ToTempSummon())
                summ->SetTempSummonType(TEMPSUMMON_DEAD_DESPAWN);

            if (instance)
            {
                instance->SetData(BOSS_BLACK_KNIGHT, DONE);

                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE1)))
                    instance->HandleGameObject(go->GetGUID(), true);
            }
        }

        private:
            EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_black_knightAI (creature);
    }

};

class npc_risen_ghoul : public CreatureScript
{
public:
    npc_risen_ghoul() : CreatureScript("npc_risen_ghoul") { }

    struct npc_risen_ghoulAI : public ScriptedAI
    {
        npc_risen_ghoulAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 uiAttackTimer;

        void Reset()
        {
            uiAttackTimer = 3500;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiAttackTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                {
                    if (target && target->isAlive())
                        DoCast(target, DUNGEON_MODE(SPELL_LEAP, SPELL_LEAP_H));
                }

                uiAttackTimer = 3500;
            }
            else
                uiAttackTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_risen_ghoulAI(creature);
    }
};

class npc_risen_announcer : public CreatureScript
{
public:
    npc_risen_announcer() : CreatureScript("npc_risen_announcer") { }

    struct npc_risen_announcerAI : public ScriptedAI
    {
        npc_risen_announcerAI(Creature* creature) : ScriptedAI(creature)
        {
            me->setFaction(14);
        }

        uint32 uiLeapTimer;
        uint32 uiClawTimer;

        void Reset()
        {
            uiLeapTimer = 10000;
            uiClawTimer = 1000;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiLeapTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                {
                    if (target && target->isAlive())
                        DoCast(target, DUNGEON_MODE(SPELL_LEAP, SPELL_LEAP_H));
                }

                uiLeapTimer = 10000;
            }
            else
                uiLeapTimer -= uiDiff;

            if (uiClawTimer <= uiDiff)
            {
                DoCastVictim(DUNGEON_MODE(SPELL_CLAW, SPELL_CLAW_H));
                uiClawTimer = 1000;
            }
            else
                uiClawTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_risen_announcerAI(creature);
    }
};

class npc_black_knight_skeletal_gryphon : public CreatureScript
{
public:
    npc_black_knight_skeletal_gryphon() : CreatureScript("npc_black_knight_skeletal_gryphon") { }

    struct npc_black_knight_skeletal_gryphonAI : public npc_escortAI
    {
        npc_black_knight_skeletal_gryphonAI(Creature* creature) : npc_escortAI(creature)
        {
            Start(false, true, 0, NULL);
            instance = creature->GetInstanceScript();
        }

        Creature* pHighlord;
        InstanceScript* instance;

        void Reset()
        {
            pHighlord = NULL;
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                case 1:
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    break;
                case 2:
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    DoScriptText(SAY_INTRO_1, me);
                    break;
                case 3:
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    break;
                case 4:
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                        break;
                case 5:
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    break;
                case 6:
                {
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    Creature* pHighlord = Unit::GetCreature(*me, instance->GetData64(DATA_HIGHLORD));
                    DoScriptText(SAY_INTRO_2, pHighlord);
                    break;
                }
                case 7:
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    break;
                case 8:
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    break;
                case 9:
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    break;
                case 10:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    me->SetSpeed(MOVE_RUN, 2.0f);
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_black_knight_skeletal_gryphonAI(creature);
    }
};

void AddSC_boss_black_knight()
{
    new boss_black_knight();
    new npc_risen_ghoul();
    new npc_risen_announcer();
    new npc_black_knight_skeletal_gryphon();
}
