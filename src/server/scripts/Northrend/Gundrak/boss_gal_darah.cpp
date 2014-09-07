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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "gundrak.h"

//Spells
enum Spells
{
    SPELL_ENRAGE                                  = 55285,
    H_SPELL_ENRAGE                                = 59828,
    SPELL_IMPALING_CHARGE                         = 54956,
    H_SPELL_IMPALING_CHARGE                       = 59827,
    SPELL_STOMP                                   = 55292,
    H_SPELL_STOMP                                 = 59829,
    SPELL_PUNCTURE                                = 55276,
    H_SPELL_PUNCTURE                              = 59826,
    SPELL_STAMPEDE                                = 55218,
    SPELL_WHIRLING_SLASH                          = 55250,
    H_SPELL_WHIRLING_SLASH                        = 59824,
};

//Yells
enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_SUMMON_RHINO                              = 3,
    SAY_TRANSFORM_1                               = 4,
    SAY_TRANSFORM_2                               = 5
};

enum Displays
{
    DISPLAY_RHINO                                 = 26265,
    DISPLAY_TROLL                                 = 27061
};

enum CombatPhase
{
    TROLL,
    RHINO
};

enum Misc
{
    DATA_SHARE_THE_LOVE                         = 1
};

class boss_gal_darah : public CreatureScript
{
public:
    boss_gal_darah() : CreatureScript("boss_gal_darah") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_gal_darahAI>(creature);
    }

    struct boss_gal_darahAI : public ScriptedAI
    {
        boss_gal_darahAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiStampedeTimer = 10 * IN_MILLISECONDS;
            uiWhirlingSlashTimer = 21 * IN_MILLISECONDS;
            uiPunctureTimer = 10 * IN_MILLISECONDS;
            uiEnrageTimer = 15 * IN_MILLISECONDS;
            uiImpalingChargeTimer = 21 * IN_MILLISECONDS;
            uiStompTimer = 25 * IN_MILLISECONDS;
            uiTransformationTimer = 9 * IN_MILLISECONDS;
            uiPhaseCounter = 0;

            shareTheLove = 0;
            bStartOfTransformation = true;
            Phase = TROLL;
        }

        uint32 uiStampedeTimer;
        uint32 uiWhirlingSlashTimer;
        uint32 uiPunctureTimer;
        uint32 uiEnrageTimer;
        uint32 uiImpalingChargeTimer;
        uint32 uiStompTimer;
        uint32 uiTransformationTimer;
        std::list<uint64> impaledList;
        uint8 shareTheLove;

        CombatPhase Phase;

        uint8 uiPhaseCounter;

        bool bStartOfTransformation;

        InstanceScript* instance;

        void Reset() override
        {
            Initialize();

            impaledList.clear();

            me->SetDisplayId(DISPLAY_TROLL);

            instance->SetData(DATA_GAL_DARAH_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            instance->SetData(DATA_GAL_DARAH_EVENT, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            switch (Phase)
            {
                case TROLL:
                    if (uiPhaseCounter == 2)
                    {
                        if (uiTransformationTimer <= diff)
                        {
                            me->SetDisplayId(DISPLAY_RHINO);
                            Phase = RHINO;
                            uiPhaseCounter = 0;
                            Talk(SAY_TRANSFORM_1);
                            uiTransformationTimer = 5*IN_MILLISECONDS;
                            bStartOfTransformation = true;
                            me->ClearUnitState(UNIT_STATE_STUNNED|UNIT_STATE_ROOT);
                            me->SetReactState(REACT_AGGRESSIVE);
                        }
                        else
                        {
                            uiTransformationTimer -= diff;

                            if (bStartOfTransformation)
                            {
                                bStartOfTransformation = false;
                                me->AddUnitState(UNIT_STATE_STUNNED|UNIT_STATE_ROOT);
                                me->SetReactState(REACT_PASSIVE);
                            }
                        }
                    }
                    else
                    {
                        if (uiStampedeTimer <= diff)
                        {
                            DoCast(me, SPELL_STAMPEDE);
                            Talk(SAY_SUMMON_RHINO);
                            uiStampedeTimer = 15*IN_MILLISECONDS;
                        } else uiStampedeTimer -= diff;

                        if (uiWhirlingSlashTimer <= diff)
                        {
                            DoCastVictim(SPELL_WHIRLING_SLASH);
                            uiWhirlingSlashTimer = 21*IN_MILLISECONDS;
                            ++uiPhaseCounter;
                        } else uiWhirlingSlashTimer -= diff;
                    }
                break;
                case RHINO:
                    if (uiPhaseCounter == 2)
                    {
                        if (uiTransformationTimer <= diff)
                        {
                            me->SetDisplayId(DISPLAY_TROLL);
                            Phase = TROLL;
                            uiPhaseCounter = 0;
                            Talk(SAY_TRANSFORM_2);
                            uiTransformationTimer = 9*IN_MILLISECONDS;
                            bStartOfTransformation = true;
                            me->ClearUnitState(UNIT_STATE_STUNNED|UNIT_STATE_ROOT);
                            me->SetReactState(REACT_AGGRESSIVE);
                        }
                        else
                        {
                            uiTransformationTimer -= diff;

                            if (bStartOfTransformation)
                            {
                                bStartOfTransformation = false;
                                me->AddUnitState(UNIT_STATE_STUNNED|UNIT_STATE_ROOT);
                                me->SetReactState(REACT_PASSIVE);
                            }
                        }
                    }
                    else
                    {
                        if (uiPunctureTimer <= diff)
                        {
                            DoCastVictim(SPELL_PUNCTURE);
                            uiPunctureTimer = 8*IN_MILLISECONDS;
                        } else uiPunctureTimer -= diff;

                        if (uiEnrageTimer <= diff)
                        {
                            DoCastVictim(SPELL_ENRAGE);
                            uiEnrageTimer = 20*IN_MILLISECONDS;
                        } else uiEnrageTimer -= diff;

                        if (uiStompTimer <= diff)
                        {
                            DoCastVictim(SPELL_STOMP);
                            uiStompTimer = 20*IN_MILLISECONDS;
                        } else uiStompTimer -= diff;

                        if (uiImpalingChargeTimer <= diff)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                DoCast(target, SPELL_IMPALING_CHARGE);
                                CheckAchievement(target->GetGUID());
                            }
                            uiImpalingChargeTimer = 31*IN_MILLISECONDS;
                            ++uiPhaseCounter;
                        } else uiImpalingChargeTimer -= diff;
                    }
                break;
            }

            DoMeleeAttackIfReady();
        }

        // 5 UNIQUE party members
        void CheckAchievement(uint64 guid)
        {
            bool playerExists = false;
            for (std::list<uint64>::iterator itr = impaledList.begin(); itr != impaledList.end(); ++itr)
                if (guid != *itr)
                    playerExists = true;

            if (playerExists)
                ++shareTheLove;

            impaledList.push_back(guid);
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_SHARE_THE_LOVE)
                return shareTheLove;

            return 0;
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            instance->SetData(DATA_GAL_DARAH_EVENT, DONE);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_SLAY);
        }
    };

};

class achievement_share_the_love : public AchievementCriteriaScript
{
    public:
        achievement_share_the_love() : AchievementCriteriaScript("achievement_share_the_love")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* GalDarah = target->ToCreature())
                if (GalDarah->AI()->GetData(DATA_SHARE_THE_LOVE) >= 5)
                    return true;

            return false;
        }
};

void AddSC_boss_gal_darah()
{
    new boss_gal_darah();
    new achievement_share_the_love();
}
