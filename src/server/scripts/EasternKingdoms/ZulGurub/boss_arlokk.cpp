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

/* ScriptData
SDName: Boss_Arlokk
SD%Complete: 95
SDComment: Wrong cleave and red aura is missing.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptPCH.h"
#include "zulgurub.h"

enum eYells
{
    SAY_AGGRO                   = -1309011,
    SAY_FEAST_PANTHER           = -1309012,
    SAY_DEATH                   = -1309013,
};

enum eSpells
{
    SPELL_SHADOWWORDPAIN        = 23952,
    SPELL_GOUGE                 = 24698,
    SPELL_MARK                  = 24210,
    SPELL_CLEAVE                = 26350,                    //Perhaps not right. Not a red aura...
    SPELL_PANTHER_TRANSFORM     = 24190,

    MODEL_ID_NORMAL             = 15218,
    MODEL_ID_PANTHER            = 15215,
    MODEL_ID_BLANK              = 11686,

    NPC_ZULIAN_PROWLER          = 15101
};

class boss_arlokk : public CreatureScript
{
    public:

        boss_arlokk()
            : CreatureScript("boss_arlokk")
        {
        }

        struct boss_arlokkAI : public ScriptedAI
        {
            boss_arlokkAI(Creature* creature) : ScriptedAI(creature)
            {
                m_pInstance = creature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

            uint32 m_uiShadowWordPain_Timer;
            uint32 m_uiGouge_Timer;
            uint32 m_uiMark_Timer;
            uint32 m_uiCleave_Timer;
            uint32 m_uiVanish_Timer;
            uint32 m_uiVisible_Timer;

            uint32 m_uiSummon_Timer;
            uint32 m_uiSummonCount;

            Unit* m_pMarkedTarget;
            uint64 MarkedTargetGUID;

            bool m_bIsPhaseTwo;
            bool m_bIsVanished;

            void Reset()
            {
                m_uiShadowWordPain_Timer = 8000;
                m_uiGouge_Timer = 14000;
                m_uiMark_Timer = 35000;
                m_uiCleave_Timer = 4000;
                m_uiVanish_Timer = 60000;
                m_uiVisible_Timer = 6000;

                m_uiSummon_Timer = 5000;
                m_uiSummonCount = 0;

                m_bIsPhaseTwo = false;
                m_bIsVanished = false;

                MarkedTargetGUID = 0;

                me->SetDisplayId(MODEL_ID_NORMAL);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
            }

            void JustReachedHome()
            {
                if (m_pInstance)
                    m_pInstance->SetData(DATA_ARLOKK, NOT_STARTED);

                //we should be summoned, so despawn
                me->DespawnOrUnsummon();
            }

            void JustDied(Unit* /*killer*/)
            {
                DoScriptText(SAY_DEATH, me);

                me->SetDisplayId(MODEL_ID_NORMAL);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                if (m_pInstance)
                    m_pInstance->SetData(DATA_ARLOKK, DONE);
            }

            void DoSummonPhanters()
            {
                if (Unit* pMarkedTarget = Unit::GetUnit(*me, MarkedTargetGUID))
                    DoScriptText(SAY_FEAST_PANTHER, me, pMarkedTarget);

                me->SummonCreature(NPC_ZULIAN_PROWLER, -11532.7998f, -1649.6734f, 41.4800f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                me->SummonCreature(NPC_ZULIAN_PROWLER, -11532.9970f, -1606.4840f, 41.2979f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
            }

            void JustSummoned(Creature* pSummoned)
            {
                if (Unit* pMarkedTarget = Unit::GetUnit(*me, MarkedTargetGUID))
                    pSummoned->AI()->AttackStart(pMarkedTarget);

                ++m_uiSummonCount;
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (!m_bIsPhaseTwo)
                {
                    if (m_uiShadowWordPain_Timer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_SHADOWWORDPAIN);
                        m_uiShadowWordPain_Timer = 15000;
                    }
                    else
                        m_uiShadowWordPain_Timer -= uiDiff;

                    if (m_uiMark_Timer <= uiDiff)
                    {
                        Unit* pMarkedTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);

                        if (pMarkedTarget)
                        {
                            DoCast(pMarkedTarget, SPELL_MARK);
                            MarkedTargetGUID = pMarkedTarget->GetGUID();
                        }
                        else
                            sLog->outError("TSCR: boss_arlokk could not accuire pMarkedTarget.");

                        m_uiMark_Timer = 15000;
                    }
                    else
                        m_uiMark_Timer -= uiDiff;
                }
                else
                {
                    //Cleave_Timer
                    if (m_uiCleave_Timer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        m_uiCleave_Timer = 16000;
                    }
                    else
                        m_uiCleave_Timer -= uiDiff;

                    //Gouge_Timer
                    if (m_uiGouge_Timer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_GOUGE);

                        DoModifyThreatPercent(me->getVictim(), -80);

                        m_uiGouge_Timer = 17000+rand()%10000;
                    }
                    else
                        m_uiGouge_Timer -= uiDiff;
                }

                if (m_uiSummonCount <= 30)
                {
                    if (m_uiSummon_Timer <= uiDiff)
                    {
                        DoSummonPhanters();
                        m_uiSummon_Timer = 5000;
                    }
                    else
                        m_uiSummon_Timer -= uiDiff;
                }

                if (m_uiVanish_Timer <= uiDiff)
                {
                    //Invisble Model
                    me->SetDisplayId(MODEL_ID_BLANK);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    me->AttackStop();
                    DoResetThreat();

                    m_bIsVanished = true;

                    m_uiVanish_Timer = 45000;
                    m_uiVisible_Timer = 6000;
                }
                else
                    m_uiVanish_Timer -= uiDiff;

                if (m_bIsVanished)
                {
                    if (m_uiVisible_Timer <= uiDiff)
                    {
                        //The Panther Model
                        me->SetDisplayId(MODEL_ID_PANTHER);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                        const CreatureTemplate *cinfo = me->GetCreatureInfo();
                        me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 35)));
                        me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 35)));
                        me->UpdateDamagePhysical(BASE_ATTACK);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            AttackStart(target);

                        m_bIsPhaseTwo = true;
                        m_bIsVanished = false;
                    }
                    else
                        m_uiVisible_Timer -= uiDiff;
                }
                else
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_arlokkAI(creature);
        }
};

class go_gong_of_bethekk : public GameObjectScript
{
    public:
        go_gong_of_bethekk() : GameObjectScript("go_gong_of_bethekk")
        {
        }

        bool OnGossipHello(Player* /*player*/, GameObject* pGo)
        {
            if (InstanceScript* m_pInstance = pGo->GetInstanceScript())
            {
                if (m_pInstance->GetData(DATA_ARLOKK) == DONE || m_pInstance->GetData(DATA_ARLOKK) == IN_PROGRESS)
                    return true;

                m_pInstance->SetData(DATA_ARLOKK, IN_PROGRESS);
                return true;
            }

            return true;
        }
};

void AddSC_boss_arlokk()
{
    new boss_arlokk();
    new go_gong_of_bethekk();
}

