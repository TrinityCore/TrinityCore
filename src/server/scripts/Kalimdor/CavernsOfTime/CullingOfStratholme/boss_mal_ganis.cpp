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

/* Script Data Start
SDName: Boss mal_ganis
SDAuthor: Tartalo
SD%Complete: 80
SDComment: @todo Intro & outro
SDCategory:
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "culling_of_stratholme.h"
#include "Player.h"

enum Spells
{
    SPELL_CARRION_SWARM                         = 52720, //A cresting wave of chaotic magic splashes over enemies in front of the caster, dealing 3230 to 3570 Shadow damage and 380 to 420 Shadow damage every 3 sec. for 15 sec.
    SPELL_MIND_BLAST                            = 52722, //Inflicts 4163 to 4837 Shadow damage to an enemy.
    SPELL_SLEEP                                 = 52721, //Puts an enemy to sleep for up to 10 sec. Any damage caused will awaken the target.
    SPELL_VAMPIRIC_TOUCH                        = 52723, //Heals the caster for half the damage dealt by a melee attack.
    SPELL_MAL_GANIS_KILL_CREDIT                 = 58124, // Quest credit
    SPELL_KILL_CREDIT                           = 58630  // Non-existing spell as encounter credit, created in spell_dbc
};

enum Yells
{
    SAY_AGGRO                                   = 2,
    SAY_KILL                                    = 3,
    SAY_SLAY                                    = 4,
    SAY_SLEEP                                   = 5,
    SAY_30HEALTH                                = 6,
    SAY_15HEALTH                                = 7,
    SAY_ESCAPE_SPEECH_1                         = 8,
    SAY_ESCAPE_SPEECH_2                         = 9,
    SAY_OUTRO                                   = 10
};

enum CombatPhases
{
    COMBAT,
    OUTRO
};

class boss_mal_ganis : public CreatureScript
{
public:
    boss_mal_ganis() : CreatureScript("boss_mal_ganis") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_mal_ganisAI>(creature);
    }

    struct boss_mal_ganisAI : public ScriptedAI
    {
        boss_mal_ganisAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            uiOutroStep = 0;
        }

        void Initialize()
        {
            bYelled = false;
            bYelled2 = false;
            Phase = COMBAT;
            uiCarrionSwarmTimer = 6000;
            uiMindBlastTimer = 11000;
            uiVampiricTouchTimer = urand(10000, 15000);
            uiSleepTimer = urand(15000, 20000);
            uiOutroTimer = 1000;
        }

        uint32 uiCarrionSwarmTimer;
        uint32 uiMindBlastTimer;
        uint32 uiVampiricTouchTimer;
        uint32 uiSleepTimer;

        uint8 uiOutroStep;
        uint32 uiOutroTimer;

        bool bYelled;
        bool bYelled2;

        CombatPhases Phase;

        InstanceScript* instance;

        void Reset() override
        {
            Initialize();
            instance->SetBossState(DATA_MAL_GANIS, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            instance->SetBossState(DATA_MAL_GANIS, IN_PROGRESS);
        }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            if (damage >= me->GetHealth() && done_by != me)
                damage = me->GetHealth()-1;
        }

        void UpdateAI(uint32 diff) override
        {
            switch (Phase)
            {
                case COMBAT:
                    //Return since we have no target
                    if (!UpdateVictim())
                        return;

                    if (!bYelled && HealthBelowPct(30))
                    {
                        Talk(SAY_30HEALTH);
                        bYelled = true;
                    }

                    if (!bYelled2 && HealthBelowPct(15))
                    {
                        Talk(SAY_15HEALTH);
                        bYelled2 = true;
                    }

                    if (HealthBelowPct(1))
                    {
                        //Handle Escape Event: Don't forget to add Player::RewardPlayerAndGroupAtEvent
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        uiOutroStep = 1;
                        Phase = OUTRO;
                        return;
                    }

                    if (Creature* pArthas = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ARTHAS)))
                        if (pArthas->isDead())
                        {
                            EnterEvadeMode();
                            me->DisappearAndDie();
                            instance->SetBossState(DATA_MAL_GANIS, FAIL);
                        }

                    if (uiCarrionSwarmTimer < diff)
                    {
                        DoCastVictim(SPELL_CARRION_SWARM);
                        uiCarrionSwarmTimer = 7000;
                    } else uiCarrionSwarmTimer -= diff;

                    if (uiMindBlastTimer < diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_MIND_BLAST);
                        uiMindBlastTimer = 6000;
                    } else uiMindBlastTimer -= diff;

                    if (uiVampiricTouchTimer < diff)
                    {
                        DoCast(me, SPELL_VAMPIRIC_TOUCH);
                        uiVampiricTouchTimer = 32000;
                    } else uiVampiricTouchTimer -= diff;

                    if (uiSleepTimer < diff)
                    {
                        Talk(SAY_SLEEP);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_SLEEP);
                        uiSleepTimer = urand(15000, 20000);
                    } else uiSleepTimer -= diff;

                    DoMeleeAttackIfReady();
                    break;
                case OUTRO:
                    if (uiOutroTimer < diff)
                    {
                        switch (uiOutroStep)
                        {
                            case 1:
                                Talk(SAY_OUTRO);
                                me->GetMotionMaster()->MoveTargetedHome();
                                ++uiOutroStep;
                                uiOutroTimer = 8000;
                                break;
                            case 2:
                                me->SetTarget(instance->GetGuidData(DATA_ARTHAS));
                                me->HandleEmoteCommand(29);
                                Talk(SAY_ESCAPE_SPEECH_2);
                                ++uiOutroStep;
                                uiOutroTimer = 9000;
                                break;
                            case 3:
                                Talk(SAY_OUTRO);
                                ++uiOutroStep;
                                //uiOutroTimer = 16000;
                                break;
                            case 4:
                                me->HandleEmoteCommand(33);
                                ++uiOutroStep;
                                uiOutroTimer = 500;
                                break;
                            case 5:
                                me->SetVisible(false);
                                me->Kill(me);
                                break;

                        }
                    } else uiOutroTimer -= diff;
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetBossState(DATA_MAL_GANIS, DONE);
            DoCastAOE(SPELL_MAL_GANIS_KILL_CREDIT, true);
            // give achievement credit and LFG rewards to players. criteria use spell 58630 which doesn't exist, but it was created in spell_dbc
            DoCastAOE(SPELL_KILL_CREDIT);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_SLAY);
        }
    };

};

void AddSC_boss_mal_ganis()
{
    new boss_mal_ganis();
}
