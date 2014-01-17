/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Omar_The_Unscarred
SD%Complete: 90
SDComment: Temporary solution for orbital/shadow whip-ability. Needs more core support before making it more proper.
SDCategory: Hellfire Citadel, Hellfire Ramparts
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "hellfire_ramparts.h"

enum Says
{
    SAY_AGGRO                    = 0,
    SAY_SUMMON                   = 1,
    SAY_CURSE                    = 2,
    SAY_KILL_1                   = 3,
    SAY_DIE                      = 4,
    SAY_WIPE                     = 5
};

enum Spells
{
    SPELL_ORBITAL_STRIKE         = 30637,
    SPELL_SHADOW_WHIP            = 30638,
    SPELL_TREACHEROUS_AURA       = 30695,
    H_SPELL_BANE_OF_TREACHERY    = 37566,
    SPELL_DEMONIC_SHIELD         = 31901,
    SPELL_SHADOW_BOLT            = 30686,
    H_SPELL_SHADOW_BOLT          = 39297,
    SPELL_SUMMON_FIENDISH_HOUND  = 30707
};

class boss_omor_the_unscarred : public CreatureScript
{
    public:

        boss_omor_the_unscarred() : CreatureScript("boss_omor_the_unscarred") { }

        struct boss_omor_the_unscarredAI : public BossAI
        {
            boss_omor_the_unscarredAI(Creature* creature) : BossAI(creature, DATA_OMOR_THE_UNSCARRED)
            {
                SetCombatMovement(false);
            }

            void Reset() OVERRIDE
            {
                Talk(SAY_WIPE);

                OrbitalStrike_Timer = 25000;
                ShadowWhip_Timer = 2000;
                Aura_Timer = 10000;
                DemonicShield_Timer = 1000;
                Shadowbolt_Timer = 2000;
                Summon_Timer = 10000;
                SummonedCount = 0;
                PlayerGUID = 0;
                CanPullBack = false;

                _Reset();
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                if (rand()%2)
                    return;

                Talk(SAY_KILL_1);
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                Talk(SAY_SUMMON);

                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    summoned->AI()->AttackStart(random);

                ++SummonedCount;
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                Talk(SAY_DIE);
                _JustDied();
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                //only two may be wrong, perhaps increase timer and spawn periodically instead.
                if (SummonedCount < 2)
                {
                    if (Summon_Timer <= diff)
                    {
                        me->InterruptNonMeleeSpells(false);
                        DoCast(me, SPELL_SUMMON_FIENDISH_HOUND);
                        Summon_Timer = 15000+rand()%15000;
                    }
                    else
                        Summon_Timer -= diff;
                }

                if (CanPullBack)
                {
                    if (ShadowWhip_Timer <= diff)
                    {
                        if (Player* temp = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                        {
                            //if unit dosen't have this flag, then no pulling back (script will attempt cast, even if orbital strike was resisted)
                            if (temp->HasUnitMovementFlag(MOVEMENTFLAG_FALLING_FAR))
                            {
                                me->InterruptNonMeleeSpells(false);
                                DoCast(temp, SPELL_SHADOW_WHIP);
                            }
                        }
                        PlayerGUID = 0;
                        ShadowWhip_Timer = 2000;
                        CanPullBack = false;
                    }
                    else
                        ShadowWhip_Timer -= diff;
                }
                else
                    if (OrbitalStrike_Timer <= diff)
                    {
                        Unit* temp = NULL;
                        if (me->IsWithinMeleeRange(me->GetVictim()))
                            temp = me->GetVictim();
                        else temp = SelectTarget(SELECT_TARGET_RANDOM, 0);

                        if (temp && temp->GetTypeId() == TYPEID_PLAYER)
                        {
                            DoCast(temp, SPELL_ORBITAL_STRIKE);
                            OrbitalStrike_Timer = 14000+rand()%2000;
                            PlayerGUID = temp->GetGUID();

                            if (PlayerGUID)
                                CanPullBack = true;
                        }
                    }
                    else
                        OrbitalStrike_Timer -= diff;

                if (HealthBelowPct(20))
                {
                    if (DemonicShield_Timer <= diff)
                    {
                        DoCast(me, SPELL_DEMONIC_SHIELD);
                        DemonicShield_Timer = 15000;
                    }
                    else
                        DemonicShield_Timer -= diff;
                }

                if (Aura_Timer <= diff)
                {
                    Talk(SAY_CURSE);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoCast(target, SPELL_TREACHEROUS_AURA);
                        Aura_Timer = 8000+rand()%8000;
                    }
                }
                else
                    Aura_Timer -= diff;

                if (Shadowbolt_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if (target)
                            target = me->GetVictim();

                        DoCast(target, SPELL_SHADOW_BOLT);
                        Shadowbolt_Timer = 4000+rand()%2500;
                    }
                }
                else
                    Shadowbolt_Timer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                uint32 OrbitalStrike_Timer;
                uint32 ShadowWhip_Timer;
                uint32 Aura_Timer;
                uint32 DemonicShield_Timer;
                uint32 Shadowbolt_Timer;
                uint32 Summon_Timer;
                uint32 SummonedCount;
                uint64 PlayerGUID;
                bool CanPullBack;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_omor_the_unscarredAI>(creature);
        }
};

void AddSC_boss_omor_the_unscarred()
{
    new boss_omor_the_unscarred();
}

