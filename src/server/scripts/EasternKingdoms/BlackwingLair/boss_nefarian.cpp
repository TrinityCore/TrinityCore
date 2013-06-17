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
SDName: Boss_Nefarian
SD%Complete: 80
SDComment: Some issues with class calls effecting more than one class
SDCategory: Blackwing Lair
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Say
{
    SAY_RANDOM              = 0,
    SAY_RAISE_SKELETONS     = 1,
    SAY_SLAY                = 2,
    SAY_DEATH               = 3,

    SAY_MAGE                = 4,
    SAY_WARRIOR             = 5,
    SAY_DRUID               = 6,
    SAY_PRIEST              = 7,
    SAY_PALADIN             = 8,
    SAY_SHAMAN              = 9,
    SAY_WARLOCK             = 10,
    SAY_HUNTER              = 11,
    SAY_ROGUE               = 12,
};

enum Spells
{
    SPELL_SHADOWFLAME_INITIAL   = 22972,
    SPELL_SHADOWFLAME           = 22539,
    SPELL_BELLOWINGROAR         = 22686,
    SPELL_VEILOFSHADOW          = 7068,
    SPELL_CLEAVE                = 20691,
    SPELL_TAILLASH              = 23364,
    SPELL_BONECONTRUST          = 23363,     //23362, 23361

    SPELL_MAGE                  = 23410,     //wild magic
    SPELL_WARRIOR               = 23397,     //beserk
    SPELL_DRUID                 = 23398,     // cat form
    SPELL_PRIEST                = 23401,     // corrupted healing
    SPELL_PALADIN               = 23418,     //syphon blessing
    SPELL_SHAMAN                = 23425,     //totems
    SPELL_WARLOCK               = 23427,     //infernals
    SPELL_HUNTER                = 23436,     //bow broke
    SPELL_ROGUE                 = 23414     //Paralise
};

class boss_nefarian : public CreatureScript
{
public:
    boss_nefarian() : CreatureScript("boss_nefarian") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_nefarianAI (creature);
    }

    struct boss_nefarianAI : public ScriptedAI
    {
        boss_nefarianAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 ShadowFlame_Timer;
        uint32 BellowingRoar_Timer;
        uint32 VeilOfShadow_Timer;
        uint32 Cleave_Timer;
        uint32 TailLash_Timer;
        uint32 ClassCall_Timer;
        bool Phase3;

        uint32 DespawnTimer;

        void Reset()
        {
            ShadowFlame_Timer = 12000;                          // These times are probably wrong
            BellowingRoar_Timer = 30000;
            VeilOfShadow_Timer = 15000;
            Cleave_Timer = 7000;
            TailLash_Timer = 10000;
            ClassCall_Timer = 35000;                            // 35-40 seconds
            Phase3 = false;

            DespawnTimer = 5000;
        }

        void KilledUnit(Unit* Victim)
        {
            if (rand()%5)
                return;

            Talk(SAY_SLAY, Victim->GetGUID());
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* who)
        {
            Talk(SAY_RANDOM);

            DoCast(who, SPELL_SHADOWFLAME_INITIAL);
            DoZoneInCombat();
        }

        void UpdateAI(uint32 diff)
        {
            if (DespawnTimer <= diff)
            {
                if (!UpdateVictim())
                    me->DespawnOrUnsummon();
                DespawnTimer = 5000;
            } else DespawnTimer -= diff;

            if (!UpdateVictim())
                return;

            //ShadowFlame_Timer
            if (ShadowFlame_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_SHADOWFLAME);
                ShadowFlame_Timer = 12000;
            } else ShadowFlame_Timer -= diff;

            //BellowingRoar_Timer
            if (BellowingRoar_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_BELLOWINGROAR);
                BellowingRoar_Timer = 30000;
            } else BellowingRoar_Timer -= diff;

            //VeilOfShadow_Timer
            if (VeilOfShadow_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_VEILOFSHADOW);
                VeilOfShadow_Timer = 15000;
            } else VeilOfShadow_Timer -= diff;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_CLEAVE);
                Cleave_Timer = 7000;
            } else Cleave_Timer -= diff;

            //TailLash_Timer
            if (TailLash_Timer <= diff)
            {
                //Cast NYI since we need a better check for behind target
                //DoCast(me->GetVictim(), SPELL_TAILLASH);

                TailLash_Timer = 10000;
            } else TailLash_Timer -= diff;

            //ClassCall_Timer
            if (ClassCall_Timer <= diff)
            {
                //Cast a random class call
                //On official it is based on what classes are currently on the hostil list
                //but we can't do that yet so just randomly call one

                switch (urand(0, 8))
                {
                    case 0:
                        Talk(SAY_MAGE);
                        DoCast(me, SPELL_MAGE);
                        break;
                    case 1:
                        Talk(SAY_WARRIOR);
                        DoCast(me, SPELL_WARRIOR);
                        break;
                    case 2:
                        Talk(SAY_DRUID);
                        DoCast(me, SPELL_DRUID);
                        break;
                    case 3:
                        Talk(SAY_PRIEST);
                        DoCast(me, SPELL_PRIEST);
                        break;
                    case 4:
                        Talk(SAY_PALADIN);
                        DoCast(me, SPELL_PALADIN);
                        break;
                    case 5:
                        Talk(SAY_SHAMAN);
                        DoCast(me, SPELL_SHAMAN);
                        break;
                    case 6:
                        Talk(SAY_WARLOCK);
                        DoCast(me, SPELL_WARLOCK);
                        break;
                    case 7:
                        Talk(SAY_HUNTER);
                        DoCast(me, SPELL_HUNTER);
                        break;
                    case 8:
                        Talk(SAY_ROGUE);
                        DoCast(me, SPELL_ROGUE);
                        break;
                }

                ClassCall_Timer = 35000 + (rand() % 5000);
            } else ClassCall_Timer -= diff;

            //Phase3 begins when we are below X health
            if (!Phase3 && HealthBelowPct(20))
            {
                Phase3 = true;
                Talk(SAY_RAISE_SKELETONS);
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_nefarian()
{
    new boss_nefarian();
}
