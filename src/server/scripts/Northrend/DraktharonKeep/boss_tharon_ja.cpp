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

#include "ScriptPCH.h"
#include "drak_tharon_keep.h"

enum Spells
{
    //skeletal spells (phase 1)
    SPELL_CURSE_OF_LIFE                           = 49527,
    H_SPELL_CURSE_OF_LIFE                         = 59972,
    SPELL_RAIN_OF_FIRE                            = 49518,
    H_SPELL_RAIN_OF_FIRE                          = 59971,
    SPELL_SHADOW_VOLLEY                           = 49528,
    H_SPELL_SHADOW_VOLLEY                         = 59973,
    SPELL_DECAY_FLESH                             = 49356, //casted at end of phase 1, starts phase 2
    //flesh spells (phase 2)
    SPELL_GIFT_OF_THARON_JA                       = 52509,
    SPELL_EYE_BEAM                                = 49544,
    H_SPELL_EYE_BEAM                              = 59965,
    SPELL_LIGHTNING_BREATH                        = 49537,
    H_SPELL_LIGHTNING_BREATH                      = 59963,
    SPELL_POISON_CLOUD                            = 49548,
    H_SPELL_POISON_CLOUD                          = 59969,
    SPELL_RETURN_FLESH                            = 53463, //Channeled spell ending phase two and returning to phase 1. This ability will stun the party for 6 seconds.
    SPELL_ACHIEVEMENT_CHECK                       = 61863,
};

enum Yells
{
    SAY_AGGRO                                     = -1600011,
    SAY_KILL_1                                    = -1600012,
    SAY_KILL_2                                    = -1600013,
    SAY_FLESH_1                                   = -1600014,
    SAY_FLESH_2                                   = -1600015,
    SAY_SKELETON_1                                = -1600016,
    SAY_SKELETON_2                                = -1600017,
    SAY_DEATH                                     = -1600018
};
enum Models
{
    MODEL_FLESH                                   = 27073,
    MODEL_SKELETON                                = 27511
};
enum CombatPhase
{
    SKELETAL,
    GOING_FLESH,
    FLESH,
    GOING_SKELETAL
};

class boss_tharon_ja : public CreatureScript
{
public:
    boss_tharon_ja() : CreatureScript("boss_tharon_ja") { }

    struct boss_tharon_jaAI : public ScriptedAI
    {
        boss_tharon_jaAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiPhaseTimer;
        uint32 uiCurseOfLifeTimer;
        uint32 uiRainOfFireTimer;
        uint32 uiShadowVolleyTimer;
        uint32 uiEyeBeamTimer;
        uint32 uiLightningBreathTimer;
        uint32 uiPoisonCloudTimer;

        CombatPhase Phase;

        InstanceScript* instance;

        void Reset()
        {
            uiPhaseTimer = 20*IN_MILLISECONDS;
            uiCurseOfLifeTimer = 1*IN_MILLISECONDS;
            uiRainOfFireTimer = urand(14*IN_MILLISECONDS, 18*IN_MILLISECONDS);
            uiShadowVolleyTimer = urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS);
            Phase = SKELETAL;
            me->SetDisplayId(me->GetNativeDisplayId());
            if (instance)
                instance->SetData(DATA_THARON_JA_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (instance)
                instance->SetData(DATA_THARON_JA_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            switch (Phase)
            {
                case SKELETAL:
                    if (uiCurseOfLifeTimer < diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_CURSE_OF_LIFE);
                        uiCurseOfLifeTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
                    } else uiCurseOfLifeTimer -= diff;

                    if (uiShadowVolleyTimer < diff)
                    {
                        DoCastVictim(SPELL_SHADOW_VOLLEY);
                        uiShadowVolleyTimer = urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS);
                    } else uiShadowVolleyTimer -= diff;

                    if (uiRainOfFireTimer < diff)
                    {
                        DoCastAOE(SPELL_RAIN_OF_FIRE);
                        uiRainOfFireTimer = urand(14*IN_MILLISECONDS, 18*IN_MILLISECONDS);
                    } else uiRainOfFireTimer -= diff;

                    if (uiPhaseTimer < diff)
                    {
                        DoCast(SPELL_DECAY_FLESH);
                        Phase = GOING_FLESH;
                        uiPhaseTimer = 6*IN_MILLISECONDS;
                    } else uiPhaseTimer -= diff;

                    DoMeleeAttackIfReady();
                    break;
                case GOING_FLESH:
                    if (uiPhaseTimer < diff)
                    {
                        DoScriptText(RAND(SAY_FLESH_1, SAY_FLESH_2), me);
                        me->SetDisplayId(MODEL_FLESH);

                        std::list<Unit*> playerList;
                        SelectTargetList(playerList, 5, SELECT_TARGET_TOPAGGRO, 0, true);
                        for (std::list<Unit*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                        {
                            Unit* temp = (*itr);
                            me->AddAura(SPELL_GIFT_OF_THARON_JA, temp);
                            temp->SetDisplayId(MODEL_SKELETON);
                        }
                        uiPhaseTimer = 20*IN_MILLISECONDS;
                        uiLightningBreathTimer = urand(3*IN_MILLISECONDS, 4*IN_MILLISECONDS);
                        uiEyeBeamTimer = urand(4*IN_MILLISECONDS, 8*IN_MILLISECONDS);
                        uiPoisonCloudTimer = urand(6*IN_MILLISECONDS, 7*IN_MILLISECONDS);
                        Phase = FLESH;
                    } else uiPhaseTimer -= diff;
                    break;
                case FLESH:
                    if (uiLightningBreathTimer < diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_LIGHTNING_BREATH);
                        uiLightningBreathTimer = urand(6*IN_MILLISECONDS, 7*IN_MILLISECONDS);
                    } else uiLightningBreathTimer -= diff;

                    if (uiEyeBeamTimer < diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_EYE_BEAM);
                        uiEyeBeamTimer = urand(4*IN_MILLISECONDS, 6*IN_MILLISECONDS);
                    } else uiEyeBeamTimer -= diff;

                    if (uiPoisonCloudTimer < diff)
                    {
                        DoCastAOE(SPELL_POISON_CLOUD);
                        uiPoisonCloudTimer = urand(10*IN_MILLISECONDS, 12*IN_MILLISECONDS);
                    } else uiPoisonCloudTimer -= diff;

                    if (uiPhaseTimer < diff)
                    {
                        DoCast(SPELL_RETURN_FLESH);
                        Phase = GOING_SKELETAL;
                        uiPhaseTimer = 6*IN_MILLISECONDS;
                    } else uiPhaseTimer -= diff;
                    DoMeleeAttackIfReady();
                    break;
                case GOING_SKELETAL:
                    if (uiPhaseTimer < diff)
                    {
                        DoScriptText(RAND(SAY_SKELETON_1, SAY_SKELETON_2), me);
                        me->DeMorph();
                        Phase = SKELETAL;
                        uiPhaseTimer = 20*IN_MILLISECONDS;
                        uiCurseOfLifeTimer = 1*IN_MILLISECONDS;
                        uiRainOfFireTimer = urand(14*IN_MILLISECONDS, 18*IN_MILLISECONDS);
                        uiShadowVolleyTimer = urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS);

                        std::list<Unit*> playerList;
                        SelectTargetList(playerList, 5, SELECT_TARGET_TOPAGGRO, 0, true);
                        for (std::list<Unit*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                        {
                            Unit* temp = (*itr);
                            if (temp->HasAura(SPELL_GIFT_OF_THARON_JA))
                                temp->RemoveAura(SPELL_GIFT_OF_THARON_JA);
                            temp->DeMorph();
                        }
                    } else uiPhaseTimer -= diff;
                    break;
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (instance)
            {
                // clean morph on players
                Map::PlayerList const &PlayerList = instance->instance->GetPlayers();

                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (Player* player = i->getSource())
                        player->DeMorph();
                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, SPELL_ACHIEVEMENT_CHECK);

                instance->SetData(DATA_THARON_JA_EVENT, DONE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_tharon_jaAI(creature);
    }
};

void AddSC_boss_tharon_ja()
{
    new boss_tharon_ja;
}
