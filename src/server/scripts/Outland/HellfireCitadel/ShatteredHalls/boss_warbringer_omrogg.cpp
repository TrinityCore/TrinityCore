/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shattered_halls.h"

enum eEnums
{
    YELL_DIE_L                  = 0,
    YELL_DIE_R                  = 1,
    EMOTE_ENRAGE                = 2,

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
    {0, NPC_LEFT_HEAD},
    {1, NPC_LEFT_HEAD},
    {2, NPC_LEFT_HEAD},
};
static Yell GoCombatDelay[]=
{
    {0, NPC_RIGHT_HEAD},
    {1, NPC_RIGHT_HEAD},
    {2, NPC_RIGHT_HEAD},
};

static Yell Threat[]=
{
    {3, NPC_LEFT_HEAD},
    {3, NPC_RIGHT_HEAD},
    {4, NPC_LEFT_HEAD},
    {5, NPC_LEFT_HEAD},
};
static Yell ThreatDelay1[]=
{
    {4, NPC_RIGHT_HEAD},
    {6, NPC_LEFT_HEAD},
    {5, NPC_RIGHT_HEAD},
    {6, NPC_RIGHT_HEAD},
};
static Yell ThreatDelay2[]=
{
    {7, NPC_LEFT_HEAD},
    {7, NPC_RIGHT_HEAD},
    {8, NPC_LEFT_HEAD},
    {9, NPC_LEFT_HEAD},
};

static Yell Killing[]=
{
    {10, NPC_LEFT_HEAD},
    {8, NPC_RIGHT_HEAD},
};

static Yell KillingDelay[]=
{
    {9, NPC_RIGHT_HEAD},
    {11, NPC_LEFT_HEAD},
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
            mob_omrogg_headsAI(Creature* creature) : ScriptedAI(creature) {}

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
                    Talk(YELL_DIE_R);
                    Death_Timer = false;
                    me->setDeathState(JUST_DIED);
                } else Death_Timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_omrogg_headsAI(creature);
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
            boss_warbringer_omroggAI(Creature* creature) : ScriptedAI(creature)
            {
                LeftHeadGUID  = 0;
                RightHeadGUID = 0;
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

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
                if (Unit* pLeftHead  = Unit::GetUnit(*me, LeftHeadGUID))
                {
                    pLeftHead->setDeathState(JUST_DIED);
                    LeftHeadGUID = 0;
                }

                if (Unit* pRightHead  = Unit::GetUnit(*me, RightHeadGUID))
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

                if (instance)
                    instance->SetData(TYPE_OMROGG, NOT_STARTED);   //End boss can use this later. O'mrogg must be defeated(DONE) or he will come to aid.
            }

            void DoYellForThreat()
            {
                Creature* pLeftHead  = Creature::GetCreature(*me, LeftHeadGUID);
                Creature* pRightHead = Unit::GetCreature(*me, RightHeadGUID);

                if (!pLeftHead || !pRightHead)
                    return;

                ithreat = rand()%4;

                Creature* source = (pLeftHead->GetEntry() == Threat[ithreat].creature ? pLeftHead : pRightHead);

                source->AI()->Talk(Threat[ithreat].id);

                Delay_Timer = 3500;
                ThreatYell = true;
            }

            void EnterCombat(Unit* /*who*/)
            {
                me->SummonCreature(NPC_LEFT_HEAD, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);
                me->SummonCreature(NPC_RIGHT_HEAD, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);

                if (Creature* pLeftHead = Creature::GetCreature(*me, LeftHeadGUID))
                {
                    iaggro = rand()%3;

                    pLeftHead->AI()->Talk(GoCombat[iaggro].id);

                    Delay_Timer = 3500;
                    AggroYell = true;
                }

                if (instance)
                    instance->SetData(TYPE_OMROGG, IN_PROGRESS);
            }

            void JustSummoned(Creature* summoned)
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
                Creature* pLeftHead  = Creature::GetCreature(*me, LeftHeadGUID);
                Creature* pRightHead = Creature::GetCreature(*me, RightHeadGUID);

                if (!pLeftHead || !pRightHead)
                    return;

                ikilling = rand()%2;

                Creature* source = (pLeftHead->GetEntry() == Killing[ikilling].creature ? pLeftHead : pRightHead);

                switch (ikilling)
                {
                    case 0:
                        source->AI()->Talk(Killing[ikilling].id);
                        Delay_Timer = 3500;
                        KillingYell = true;
                        break;
                    case 1:
                        source->AI()->Talk(Killing[ikilling].id);
                        KillingYell = false;
                        break;
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                Creature* pLeftHead  = Creature::GetCreature(*me, LeftHeadGUID);
                Creature* pRightHead = Creature::GetCreature(*me, RightHeadGUID);

                if (!pLeftHead || !pRightHead)
                    return;

                pLeftHead->AI()->Talk(YELL_DIE_L);

                CAST_AI(mob_omrogg_heads::mob_omrogg_headsAI, CAST_CRE(pRightHead)->AI())->DoDeathYell();

                if (instance)
                    instance->SetData(TYPE_OMROGG, DONE);
            }

            void UpdateAI(const uint32 diff)
            {
                if (Delay_Timer <= diff)
                {
                    Delay_Timer = 3500;

                    Creature* pLeftHead  = Creature::GetCreature(*me, LeftHeadGUID);
                    Creature* pRightHead = Creature::GetCreature(*me, RightHeadGUID);

                    if (!pLeftHead || !pRightHead)
                        return;

                    if (AggroYell)
                    {
                        pRightHead->AI()->Talk(GoCombatDelay[iaggro].id);
                        AggroYell = false;
                    }

                    if (ThreatYell2)
                    {
                        Creature* source = (pLeftHead->GetEntry() == ThreatDelay2[ithreat].creature ? pLeftHead : pRightHead);

                        source->AI()->Talk(ThreatDelay2[ithreat].id);
                        ThreatYell2 = false;
                    }

                    if (ThreatYell)
                    {
                        Creature* source = (pLeftHead->GetEntry() == ThreatDelay1[ithreat].creature ? pLeftHead : pRightHead);

                        source->AI()->Talk(ThreatDelay1[ithreat].id);
                        ThreatYell = false;
                        ThreatYell2 = true;
                    }

                    if (KillingYell)
                    {
                        Creature* source = (pLeftHead->GetEntry() == KillingDelay[ikilling].creature ? pLeftHead : pRightHead);

                        source->AI()->Talk(KillingDelay[ikilling].id);
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
                    Talk(EMOTE_ENRAGE);
                    DoCast(me, SPELL_BURNING_MAUL);
                    BurningMaul_Timer = 40000;
                    BlastWave_Timer = 16000;
                    BlastCount = 1;
                }
                else
                    BurningMaul_Timer -= diff;

                if (ResetThreat_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoYellForThreat();
                        DoResetThreat();
                        me->AddThreat(target, 0.0f);
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_warbringer_omroggAI (creature);
        }
};
void AddSC_boss_warbringer_omrogg()
{
    new boss_warbringer_omrogg();
    new mob_omrogg_heads();
}

