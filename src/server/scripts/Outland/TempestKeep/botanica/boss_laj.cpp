/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Laj
SD%Complete: 90
SDComment: Immunities are wrong, must be adjusted to use resistance from creature_templates. Most spells require database support.
SDCategory: Tempest Keep, The Botanica
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_botanica.h"

enum eSpells
{
    SPELL_ALLERGIC_REACTION    = 34697,
    SPELL_TELEPORT_SELF        = 34673,

    SPELL_SUMMON_LASHER_1      = 34681,
    SPELL_SUMMON_FLAYER_1      = 34682,
    SPELL_SUMMON_LASHER_2      = 34684,
    SPELL_SUMMON_FLAYER_2      = 34685,
    SPELL_SUMMON_LASHER_3      = 34686,
    SPELL_SUMMON_FLAYER_4      = 34687,
    SPELL_SUMMON_LASHER_4      = 34688,
    SPELL_SUMMON_FLAYER_3      = 34690
};
enum eOthers
{
    EMOTE_SUMMON               = 0,
    MODEL_DEFAULT              = 13109,
    MODEL_ARCANE               = 14213,
    MODEL_FIRE                 = 13110,
    MODEL_FROST                = 14112,
    MODEL_NATURE               = 14214
};

class boss_laj : public CreatureScript
{
    public:

        boss_laj()
            : CreatureScript("boss_laj")
        {
        }

        struct boss_lajAI : public BossAI
        {
            boss_lajAI(Creature* creature) : BossAI(creature, DATA_LAJ) { }

            bool CanSummon;
            uint32 Teleport_Timer;
            uint32 Summon_Timer;
            uint32 Transform_Timer;
            uint32 Allergic_Timer;

            void Reset()
            {
                me->SetDisplayId(MODEL_DEFAULT);
                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, true);
                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, false);
                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, false);
                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, false);
                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);

                CanSummon = false;
                Teleport_Timer = 20000;
                Summon_Timer = 2500;
                Transform_Timer = 30000;
                Allergic_Timer = 5000;
            }

            void DoTransform()
            {
                switch (rand()%5)
                {
                    case 0:
                        me->SetDisplayId(MODEL_DEFAULT);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, true);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);
                        break;
                    case 1:
                        me->SetDisplayId(MODEL_ARCANE);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);
                        break;
                    case 2:
                        me->SetDisplayId(MODEL_FIRE);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);
                        break;
                    case 3:
                        me->SetDisplayId(MODEL_FROST);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);
                        break;
                    case 4:
                        me->SetDisplayId(MODEL_NATURE);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, false);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
                        break;
                }
            }

            void DoSummons()
            {
                switch (rand()%4)
                {
                    case 0:
                        DoCast(me, SPELL_SUMMON_LASHER_1, true);
                        DoCast(me, SPELL_SUMMON_FLAYER_1, true);
                        break;
                    case 1:
                        DoCast(me, SPELL_SUMMON_LASHER_2, true);
                        DoCast(me, SPELL_SUMMON_FLAYER_2, true);
                        break;
                    case 2:
                        DoCast(me, SPELL_SUMMON_LASHER_3, true);
                        DoCast(me, SPELL_SUMMON_FLAYER_3, true);
                        break;
                    case 3:
                        DoCast(me, SPELL_SUMMON_LASHER_4, true);
                        DoCast(me, SPELL_SUMMON_FLAYER_4, true);
                        break;
                }
                CanSummon = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void JustSummoned(Creature* summon)
            {
                if (summon && me->GetVictim())
                    summon->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (CanSummon)
                {
                    if (Summon_Timer <= diff)
                    {
                        Talk(EMOTE_SUMMON);
                        DoSummons();
                        Summon_Timer = 2500;
                    }
                    else
                        Summon_Timer -= diff;
                }

                if (Allergic_Timer <= diff)
                {
                    DoCastVictim(SPELL_ALLERGIC_REACTION);
                    Allergic_Timer = 25000+rand()%15000;
                }
                else
                    Allergic_Timer -= diff;

                if (Teleport_Timer <= diff)
                {
                    DoCast(me, SPELL_TELEPORT_SELF);
                    Teleport_Timer = 30000+rand()%10000;
                    CanSummon = true;
                }
                else
                    Teleport_Timer -= diff;

                if (Transform_Timer <= diff)
                {
                    DoTransform();
                    Transform_Timer = 25000+rand()%15000;
                }
                else
                    Transform_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_lajAI(creature);
        }
};

void AddSC_boss_laj()
{
    new boss_laj();
}

