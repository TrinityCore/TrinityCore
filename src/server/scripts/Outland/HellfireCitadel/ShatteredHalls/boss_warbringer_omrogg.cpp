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
SDName: Boss_Warbringer_Omrogg
SD%Complete: 85
SDComment: Heroic enabled. Spell timing may need additional tweaks
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

/* ContentData
mob_omrogg_heads
boss_warbringer_omrogg
EndContentData */

#include "ScriptPCH.h"
#include "shattered_halls.h"

enum eEnums
{
    YELL_DIE_L                  = -1540039,
    YELL_DIE_R                  = -1540040,
    EMOTE_ENRAGE                = -1540041,

    SPELL_BLAST_WAVE            = 30600,
    SPELL_FEAR                  = 30584,
    SPELL_THUNDERCLAP           = 30633,

    SPELL_BURNING_MAUL          = 30598,
    H_SPELL_BURNING_MAUL        = 36056,

    NPC_LEFT_HEAD               = 19523,
    NPC_RIGHT_HEAD              = 19524
};

struct Yell
{
    int32 id;
    uint32 creature;
};

static Yell GoCombat[]=
{
    {-1540018, NPC_LEFT_HEAD},
    {-1540019, NPC_LEFT_HEAD},
    {-1540020, NPC_LEFT_HEAD},
};
static Yell GoCombatDelay[]=
{
    {-1540021, NPC_RIGHT_HEAD},
    {-1540022, NPC_RIGHT_HEAD},
    {-1540023, NPC_RIGHT_HEAD},
};

static Yell Threat[]=
{
    {-1540024, NPC_LEFT_HEAD},
    {-1540025, NPC_RIGHT_HEAD},
    {-1540026, NPC_LEFT_HEAD},
    {-1540027, NPC_LEFT_HEAD},
};
static Yell ThreatDelay1[]=
{
    {-1540028, NPC_RIGHT_HEAD},
    {-1540029, NPC_LEFT_HEAD},
    {-1540030, NPC_RIGHT_HEAD},
    {-1540031, NPC_RIGHT_HEAD},
};
static Yell ThreatDelay2[]=
{
    {-1540032, NPC_LEFT_HEAD},
    {-1540033, NPC_RIGHT_HEAD},
    {-1540034, NPC_LEFT_HEAD},
    {-1540035, NPC_LEFT_HEAD},
};

static Yell Killing[]=
{
    {-1540036, NPC_LEFT_HEAD},
    {-1540037, NPC_RIGHT_HEAD},
};

static Yell KillingDelay[]=
{
    {-1540038, NPC_RIGHT_HEAD},
    {-1000000, NPC_LEFT_HEAD},
};

class mob_omrogg_heads : public CreatureScript
{
    public:

        mob_omrogg_heads()
            : CreatureScript("mob_omrogg_heads")
        {
        }

        struct mob_omrogg_headsAI : public ScriptedAI
        {
            mob_omrogg_headsAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            bool DeathYell;
            uint32 Death_Timer;

            void Reset()
            {
                Death_Timer = 4000;
                DeathYell = false;
            }
            void EnterCombat(Unit* /*who*/) {}

            void DoDeathYell()
            {
                DeathYell = true;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!DeathYell)
                    return;

                if (Death_Timer <= diff)
                {
                    DoScriptText(YELL_DIE_R, me);
                    Death_Timer = false;
                    me->setDeathState(JUST_DIED);
                } else Death_Timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new mob_omrogg_headsAI (Creature);
        }
};

class boss_warbringer_omrogg : public CreatureScript
{
    public:

        boss_warbringer_omrogg()
            : CreatureScript("boss_warbringer_omrogg")
        {
        }

        struct boss_warbringer_omroggAI : public ScriptedAI
        {
            boss_warbringer_omroggAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                LeftHeadGUID  = 0;
                RightHeadGUID = 0;
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            uint64 LeftHeadGUID;
            uint64 RightHeadGUID;
            int iaggro;
            int ithreat;
            int ikilling;

            bool AggroYell;
            bool ThreatYell;
            bool ThreatYell2;
            bool KillingYell;

            uint32 Delay_Timer;
            uint32 BlastWave_Timer;
            uint32 BlastCount;
            uint32 Fear_Timer;
            uint32 BurningMaul_Timer;
            uint32 ThunderClap_Timer;
            uint32 ResetThreat_Timer;

            void Reset()
            {
                if (Unit* pLeftHead  = Unit::GetUnit(*me,LeftHeadGUID))
                {
                    pLeftHead->setDeathState(JUST_DIED);
                    LeftHeadGUID = 0;
                }

                if (Unit* pRightHead  = Unit::GetUnit(*me,RightHeadGUID))
                {
                    pRightHead->setDeathState(JUST_DIED);
                    RightHeadGUID = 0;
                }

                AggroYell = false;
                ThreatYell = false;
                ThreatYell2 = false;
                KillingYell = false;

                Delay_Timer = 4000;
                BlastWave_Timer = 0;
                BlastCount = 0;
                Fear_Timer = 8000;
                BurningMaul_Timer = 25000;
                ThunderClap_Timer = 15000;
                ResetThreat_Timer = 30000;

                if (pInstance)
                    pInstance->SetData(TYPE_OMROGG, NOT_STARTED);   //End boss can use this later. O'mrogg must be defeated(DONE) or he will come to aid.
            }

            void DoYellForThreat()
            {
                Unit *pLeftHead  = Unit::GetUnit(*me,LeftHeadGUID);
                Unit *pRightHead = Unit::GetUnit(*me,RightHeadGUID);

                if (!pLeftHead || !pRightHead)
                    return;

                ithreat = rand()%4;

                Unit *source = (pLeftHead->GetEntry() == Threat[ithreat].creature ? pLeftHead : pRightHead);

                DoScriptText(Threat[ithreat].id, source);

                Delay_Timer = 3500;
                ThreatYell = true;
            }

            void EnterCombat(Unit * /*who*/)
            {
                me->SummonCreature(NPC_LEFT_HEAD, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);
                me->SummonCreature(NPC_RIGHT_HEAD, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);

                if (Unit *pLeftHead = Unit::GetUnit(*me,LeftHeadGUID))
                {
                    iaggro = rand()%3;

                    DoScriptText(GoCombat[iaggro].id, pLeftHead);

                    Delay_Timer = 3500;
                    AggroYell = true;
                }

                if (pInstance)
                    pInstance->SetData(TYPE_OMROGG, IN_PROGRESS);
            }

            void JustSummoned(Creature *summoned)
            {
                if (summoned->GetEntry() == NPC_LEFT_HEAD)
                    LeftHeadGUID = summoned->GetGUID();

                if (summoned->GetEntry() == NPC_RIGHT_HEAD)
                    RightHeadGUID = summoned->GetGUID();

                //summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                //summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                summoned->SetVisible(false);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Unit* pLeftHead  = Unit::GetUnit(*me,LeftHeadGUID);
                Unit* pRightHead = Unit::GetUnit(*me,RightHeadGUID);

                if (!pLeftHead || !pRightHead)
                    return;

                ikilling = rand()%2;

                Unit *source = (pLeftHead->GetEntry() == Killing[ikilling].creature ? pLeftHead : pRightHead);

                switch(ikilling)
                {
                    case 0:
                        DoScriptText(Killing[ikilling].id, source);
                        Delay_Timer = 3500;
                        KillingYell = true;
                        break;
                    case 1:
                        DoScriptText(Killing[ikilling].id, source);
                        KillingYell = false;
                        break;
                }
            }

            void JustDied(Unit* /*Killer*/)
            {
                Unit* pLeftHead  = Unit::GetUnit(*me,LeftHeadGUID);
                Unit* pRightHead = Unit::GetUnit(*me,RightHeadGUID);

                if (!pLeftHead || !pRightHead)
                    return;

                DoScriptText(YELL_DIE_L, pLeftHead);

                CAST_AI(mob_omrogg_heads::mob_omrogg_headsAI, CAST_CRE(pRightHead)->AI())->DoDeathYell();

                if (pInstance)
                    pInstance->SetData(TYPE_OMROGG, DONE);
            }

            void UpdateAI(const uint32 diff)
            {
                if (Delay_Timer <= diff)
                {
                    Delay_Timer = 3500;

                    Unit* pLeftHead  = Unit::GetUnit(*me,LeftHeadGUID);
                    Unit* pRightHead = Unit::GetUnit(*me,RightHeadGUID);

                    if (!pLeftHead || !pRightHead)
                        return;

                    if (AggroYell)
                    {
                        DoScriptText(GoCombatDelay[iaggro].id, pRightHead);
                        AggroYell = false;
                    }

                    if (ThreatYell2)
                    {
                        Unit *source = (pLeftHead->GetEntry() == ThreatDelay2[ithreat].creature ? pLeftHead : pRightHead);

                        DoScriptText(ThreatDelay2[ithreat].id, source);
                        ThreatYell2 = false;
                    }

                    if (ThreatYell)
                    {
                        Unit *source = (pLeftHead->GetEntry() == ThreatDelay1[ithreat].creature ? pLeftHead : pRightHead);

                        DoScriptText(ThreatDelay1[ithreat].id, source);
                        ThreatYell = false;
                        ThreatYell2 = true;
                    }

                    if (KillingYell)
                    {
                        Unit *source = (pLeftHead->GetEntry() == KillingDelay[ikilling].creature ? pLeftHead : pRightHead);

                        DoScriptText(KillingDelay[ikilling].id, source);
                        KillingYell = false;
                    }
                } else Delay_Timer -= diff;

                if (!UpdateVictim())
                    return;

                if (BlastCount && BlastWave_Timer <= diff)
                {
                    DoCast(me, SPELL_BLAST_WAVE);
                    BlastWave_Timer = 5000;
                    ++BlastCount;

                    if (BlastCount == 3)
                        BlastCount = 0;
                }
                else
                    BlastWave_Timer -= diff;

                if (BurningMaul_Timer <= diff)
                {
                    DoScriptText(EMOTE_ENRAGE, me);
                    DoCast(me, SPELL_BURNING_MAUL);
                    BurningMaul_Timer = 40000;
                    BlastWave_Timer = 16000;
                    BlastCount = 1;
                }
                else
                    BurningMaul_Timer -= diff;

                if (ResetThreat_Timer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    {
                        DoYellForThreat();
                        DoResetThreat();
                        me->AddThreat(pTarget, 0.0f);
                    }
                    ResetThreat_Timer = 25000+rand()%15000;
                }
                else
                    ResetThreat_Timer -= diff;

                if (Fear_Timer <= diff)
                {
                    DoCast(me, SPELL_FEAR);
                    Fear_Timer = 15000+rand()%20000;
                }
                else
                    Fear_Timer -= diff;

                if (ThunderClap_Timer <= diff)
                {
                    DoCast(me, SPELL_THUNDERCLAP);
                    ThunderClap_Timer = 15000+rand()%15000;
                }
                else
                    ThunderClap_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_warbringer_omroggAI (pCreature);
        }
};
void AddSC_boss_warbringer_omrogg()
{
    new boss_warbringer_omrogg();
    new mob_omrogg_heads();
}

