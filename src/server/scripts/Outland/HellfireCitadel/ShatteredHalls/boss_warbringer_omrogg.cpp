/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
npc_omrogg_heads
boss_warbringer_omrogg
EndContentData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "shattered_halls.h"

enum Yells
{
    YELL_DIE_L                  = 0,
    YELL_DIE_R                  = 1,
    EMOTE_ENRAGE                = 2,
};

enum Spells
{
    SPELL_BLAST_WAVE            = 30600,
    SPELL_FEAR                  = 30584,
    SPELL_THUNDERCLAP           = 30633,

    SPELL_BURNING_MAUL          = 30598,
    H_SPELL_BURNING_MAUL        = 36056,
};

enum Creatures
{
    NPC_LEFT_HEAD               = 19523,
    NPC_RIGHT_HEAD              = 19524
};

enum SetData
{
    SETDATA_DATA                = 1,
    SETDATA_YELL                = 1
};

enum Events
{
    // Omrogg Heads
    EVENT_DEATH_YELL            = 1
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

// ########################################################
// Warbringer_Omrogg
// ########################################################

class boss_warbringer_omrogg : public CreatureScript
{
    public:
        boss_warbringer_omrogg() : CreatureScript("boss_warbringer_omrogg") { }

        struct boss_warbringer_omroggAI : public BossAI
        {
            boss_warbringer_omroggAI(Creature* creature) : BossAI(creature, DATA_OMROGG)
            {
                Initialize();
                iaggro = 0;
                ithreat = 0;
                ikilling = 0;
            }

            void Initialize()
            {
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
            }

            void Reset() override
            {
                _Reset();
                if (Unit* LeftHead  = ObjectAccessor::GetUnit(*me, LeftHeadGUID))
                {
                    LeftHead->setDeathState(JUST_DIED);
                    LeftHeadGUID.Clear();
                }

                if (Unit* RightHead  = ObjectAccessor::GetUnit(*me, RightHeadGUID))
                {
                    RightHead->setDeathState(JUST_DIED);
                    RightHeadGUID.Clear();
                }

                Initialize();

                instance->SetData(DATA_OMROGG, NOT_STARTED);   //End boss can use this later. O'mrogg must be defeated(DONE) or he will come to aid.
            }

            void DoYellForThreat()
            {
                Creature* LeftHead  = ObjectAccessor::GetCreature(*me, LeftHeadGUID);
                Creature* RightHead = ObjectAccessor::GetCreature(*me, RightHeadGUID);

                if (!LeftHead || !RightHead)
                    return;

                ithreat = rand32() % 4;

                Creature* source = (LeftHead->GetEntry() == Threat[ithreat].creature ? LeftHead : RightHead);

                source->AI()->Talk(Threat[ithreat].id);

                Delay_Timer = 3500;
                ThreatYell = true;
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                me->SummonCreature(NPC_LEFT_HEAD, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);
                me->SummonCreature(NPC_RIGHT_HEAD, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);

                if (Creature* LeftHead = ObjectAccessor::GetCreature(*me, LeftHeadGUID))
                {
                    iaggro = rand32() % 3;

                    LeftHead->AI()->Talk(GoCombat[iaggro].id);

                    Delay_Timer = 3500;
                    AggroYell = true;
                }

                instance->SetBossState(DATA_OMROGG, IN_PROGRESS);
            }

            void JustSummoned(Creature* summoned) override
            {
                if (summoned->GetEntry() == NPC_LEFT_HEAD)
                    LeftHeadGUID = summoned->GetGUID();

                if (summoned->GetEntry() == NPC_RIGHT_HEAD)
                    RightHeadGUID = summoned->GetGUID();

                //summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                //summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                summoned->SetVisible(false);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Creature* LeftHead  = ObjectAccessor::GetCreature(*me, LeftHeadGUID);
                Creature* RightHead = ObjectAccessor::GetCreature(*me, RightHeadGUID);

                if (!LeftHead || !RightHead)
                    return;

                ikilling = rand32() % 2;

                Creature* source = (LeftHead->GetEntry() == Killing[ikilling].creature ? LeftHead : RightHead);

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

            void JustDied(Unit* /*killer*/) override
            {
                Creature* LeftHead  = ObjectAccessor::GetCreature(*me, LeftHeadGUID);
                Creature* RightHead = ObjectAccessor::GetCreature(*me, RightHeadGUID);

                _JustDied();

                if (!LeftHead || !RightHead)
                    return;

                LeftHead->AI()->Talk(YELL_DIE_L);

                RightHead->AI()->SetData(SETDATA_DATA, SETDATA_YELL);
            }

            void UpdateAI(uint32 diff) override
            {
                if (Delay_Timer <= diff)
                {
                    Delay_Timer = 3500;

                    Creature* LeftHead  = ObjectAccessor::GetCreature(*me, LeftHeadGUID);
                    Creature* RightHead = ObjectAccessor::GetCreature(*me, RightHeadGUID);

                    if (!LeftHead || !RightHead)
                        return;

                    if (AggroYell)
                    {
                        RightHead->AI()->Talk(GoCombatDelay[iaggro].id);
                        AggroYell = false;
                    }

                    if (ThreatYell2)
                    {
                        Creature* source = (LeftHead->GetEntry() == ThreatDelay2[ithreat].creature ? LeftHead : RightHead);

                        source->AI()->Talk(ThreatDelay2[ithreat].id);
                        ThreatYell2 = false;
                    }

                    if (ThreatYell)
                    {
                        Creature* source = (LeftHead->GetEntry() == ThreatDelay1[ithreat].creature ? LeftHead : RightHead);

                        source->AI()->Talk(ThreatDelay1[ithreat].id);
                        ThreatYell = false;
                        ThreatYell2 = true;
                    }

                    if (KillingYell)
                    {
                        Creature* source = (LeftHead->GetEntry() == KillingDelay[ikilling].creature ? LeftHead : RightHead);

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
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    {
                        DoYellForThreat();
                        ResetThreatList();
                        AddThreat(target, 0.0f);
                    }
                    ResetThreat_Timer = 25000 + rand32() % 15000;
                }
                else
                    ResetThreat_Timer -= diff;

                if (Fear_Timer <= diff)
                {
                    DoCast(me, SPELL_FEAR);
                    Fear_Timer = 15000 + rand32() % 20000;
                }
                else
                    Fear_Timer -= diff;

                if (ThunderClap_Timer <= diff)
                {
                    DoCast(me, SPELL_THUNDERCLAP);
                    ThunderClap_Timer = 15000 + rand32() % 15000;
                }
                else
                    ThunderClap_Timer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                ObjectGuid LeftHeadGUID;
                ObjectGuid RightHeadGUID;
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
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetShatteredHallsAI<boss_warbringer_omroggAI>(creature);
        }
};

// ########################################################
// Omrogg Heads
// ########################################################

class npc_omrogg_heads : public CreatureScript
{
    public:
        npc_omrogg_heads() : CreatureScript("npc_omrogg_heads") { }

        struct npc_omrogg_headsAI : public ScriptedAI
        {
            npc_omrogg_headsAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset() override { }

            void JustEngagedWith(Unit* /*who*/) override { }

            void SetData(uint32 data, uint32 value) override
            {
                if (data == SETDATA_DATA && value == SETDATA_YELL)
                {
                    events.ScheduleEvent(EVENT_DEATH_YELL, 4s);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_DEATH_YELL)
                {
                    Talk(YELL_DIE_R);
                    me->setDeathState(JUST_DIED);
                }
            }

            private:
                InstanceScript* instance;
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetShatteredHallsAI<npc_omrogg_headsAI>(creature);
        }
};

void AddSC_boss_warbringer_omrogg()
{
    new boss_warbringer_omrogg();
    new npc_omrogg_heads();
}
