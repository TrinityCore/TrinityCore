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
SDName: Boss_Astromancer
SD%Complete: 80
SDComment:
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "ScriptPCH.h"
#include "the_eye.h"

enum eEnums
{
    SAY_AGGRO                           = -1550007,
    SAY_SUMMON1                         = -1550008,
    SAY_SUMMON2                         = -1550009,
    SAY_KILL1                           = -1550010,
    SAY_KILL2                           = -1550011,
    SAY_KILL3                           = -1550012,
    SAY_DEATH                           = -1550013,
    SAY_VOIDA                           = -1550014,
    SAY_VOIDB                           = -1550015,

    SPELL_ARCANE_MISSILES               = 33031,
    SPELL_WRATH_OF_THE_ASTROMANCER      = 42783,
    SPELL_BLINDING_LIGHT                = 33009,
    SPELL_FEAR                          = 34322,
    SPELL_VOID_BOLT                     = 39329,

    SPELL_SPOTLIGHT                     = 25824,
    NPC_ASTROMANCER_SOLARIAN_SPOTLIGHT  = 18928,

    NPC_SOLARIUM_AGENT                  = 18925,
    NPC_SOLARIUM_PRIEST                 = 18806,

    MODEL_HUMAN                         = 18239,
    MODEL_VOIDWALKER                    = 18988,

    SPELL_SOLARIUM_GREAT_HEAL           = 33387,
    SPELL_SOLARIUM_HOLY_SMITE           = 25054,
    SPELL_SOLARIUM_ARCANE_TORRENT       = 33390,

    WV_ARMOR                            = 31000
};

const float CENTER_X                    = 432.909f;
const float CENTER_Y                    = -373.424f;
const float CENTER_Z                    = 17.9608f;
const float CENTER_O                    = 1.06421f;
const float SMALL_PORTAL_RADIUS         = 12.6f;
const float LARGE_PORTAL_RADIUS         = 26.0f;
const float PORTAL_Z                    = 17.005f;

/* not used                        // x,          y,      z,         o
static float SolarianPos[4] = {432.909f, -373.424f, 17.9608f, 1.06421f};
*/

class boss_high_astromancer_solarian : public CreatureScript
{
    public:

        boss_high_astromancer_solarian()
            : CreatureScript("boss_high_astromancer_solarian")
        {
        }

        struct boss_high_astromancer_solarianAI : public ScriptedAI
        {
            boss_high_astromancer_solarianAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
            {
                pInstance = pCreature->GetInstanceScript();

                defaultarmor = pCreature->GetArmor();
                defaultsize = pCreature->GetFloatValue(OBJECT_FIELD_SCALE_X);
            }

            InstanceScript *pInstance;
            SummonList Summons;

            uint8 Phase;

            uint32 ArcaneMissiles_Timer;
            uint32 m_uiWrathOfTheAstromancer_Timer;
            uint32 BlindingLight_Timer;
            uint32 Fear_Timer;
            uint32 VoidBolt_Timer;
            uint32 Phase1_Timer;
            uint32 Phase2_Timer;
            uint32 Phase3_Timer;
            uint32 AppearDelay_Timer;
            uint32 defaultarmor;
            uint32 Wrath_Timer;

            float defaultsize;
            float Portals[3][3];

            bool AppearDelay;
            bool BlindingLight;

            void Reset()
            {
                ArcaneMissiles_Timer = 2000;
                m_uiWrathOfTheAstromancer_Timer = 15000;
                BlindingLight_Timer = 41000;
                Fear_Timer = 20000;
                VoidBolt_Timer = 10000;
                Phase1_Timer = 50000;
                Phase2_Timer = 10000;
                Phase3_Timer = 15000;
                AppearDelay_Timer = 2000;
                BlindingLight = false;
                AppearDelay = false;
                Wrath_Timer = 20000+rand()%5000;//twice in phase one
                Phase = 1;
                Wrath_Timer = 20000+rand()%5000;//twice in phase one

                if (pInstance)
                    pInstance->SetData(DATA_HIGHASTROMANCERSOLARIANEVENT, NOT_STARTED);

                me->SetArmor(defaultarmor);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetVisible(true);
                me->SetFloatValue(OBJECT_FIELD_SCALE_X, defaultsize);
                me->SetDisplayId(MODEL_HUMAN);

                Summons.DespawnAll();
            }

            void KilledUnit(Unit * /*victim*/)
            {
                DoScriptText(RAND(SAY_KILL1, SAY_KILL2, SAY_KILL3), me);
            }

            void JustDied(Unit * /*victim*/)
            {
                me->SetFloatValue(OBJECT_FIELD_SCALE_X, defaultsize);
                me->SetDisplayId(MODEL_HUMAN);
                DoScriptText(SAY_DEATH, me);
                if (pInstance)
                    pInstance->SetData(DATA_HIGHASTROMANCERSOLARIANEVENT, DONE);
            }

            void EnterCombat(Unit * /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
                DoZoneInCombat();

                if (pInstance)
                    pInstance->SetData(DATA_HIGHASTROMANCERSOLARIANEVENT, IN_PROGRESS);
            }

            void SummonMinion(uint32 entry, float x, float y, float z)
            {
                Creature* Summoned = me->SummonCreature(entry, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                if (Summoned)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        Summoned->AI()->AttackStart(pTarget);

                    Summons.Summon(Summoned);
                }
            }

            float Portal_X(float radius)
            {
                if (urand(0, 1))
                    radius = -radius;

                return radius * (float)(rand()%100)/100.0f + CENTER_X;
            }

            float Portal_Y(float x, float radius)
            {
                float z = RAND(1.0f, -1.0f);

                return (z*sqrt(radius*radius - (x - CENTER_X)*(x - CENTER_X)) + CENTER_Y);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                if (AppearDelay)
                {
                    me->StopMoving();
                    me->AttackStop();
                    if (AppearDelay_Timer <= diff)
                    {
                        AppearDelay = false;
                        if (Phase == 2)
                        {
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->SetVisible(false);
                        }
                        AppearDelay_Timer = 2000;
                    }
                    else
                        AppearDelay_Timer -= diff;
                }
                if (Phase == 1)
                {
                    if (BlindingLight_Timer <= diff)
                    {
                        BlindingLight = true;
                        BlindingLight_Timer = 45000;
                    }
                    else
                        BlindingLight_Timer -= diff;

                    if (Wrath_Timer <= diff)
                    {
                        me->InterruptNonMeleeSpells(false);
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                            DoCast(pTarget, SPELL_WRATH_OF_THE_ASTROMANCER, true);
                        Wrath_Timer = 20000+rand()%5000;
                    }
                    else
                        Wrath_Timer -= diff;

                    if (ArcaneMissiles_Timer <= diff)
                    {
                        if (BlindingLight)
                        {
                            DoCast(me->getVictim(), SPELL_BLINDING_LIGHT);
                            BlindingLight = false;
                        }
                        else
                        {
                            Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                            if (!me->HasInArc(2.5f, pTarget))
                                pTarget = me->getVictim();
                            if (pTarget)
                                DoCast(pTarget, SPELL_ARCANE_MISSILES);
                        }
                        ArcaneMissiles_Timer = 3000;
                    }
                    else
                        ArcaneMissiles_Timer -= diff;

                    if (m_uiWrathOfTheAstromancer_Timer <= diff)
                    {
                        me->InterruptNonMeleeSpells(false);
                        //Target the tank ?
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        {
                            if (pTarget->GetTypeId() == TYPEID_PLAYER)
                            {
                                DoCast(pTarget, SPELL_WRATH_OF_THE_ASTROMANCER);
                                m_uiWrathOfTheAstromancer_Timer = 25000;
                            }
                            else
                                m_uiWrathOfTheAstromancer_Timer = 1000;
                        }
                    }
                    else
                        m_uiWrathOfTheAstromancer_Timer -= diff;

                    //Phase1_Timer
                    if (Phase1_Timer <= diff)
                    {
                        Phase = 2;
                        Phase1_Timer = 50000;
                        //After these 50 seconds she portals to the middle of the room and disappears, leaving 3 light portals behind.
                        me->GetMotionMaster()->Clear();
                        me->GetMap()->CreatureRelocation(me, CENTER_X, CENTER_Y, CENTER_Z, CENTER_O);
                        for (uint8 i=0; i <= 2; ++i)
                        {
                            if (!i)
                            {
                                Portals[i][0] = Portal_X(SMALL_PORTAL_RADIUS);
                                Portals[i][1] = Portal_Y(Portals[i][0], SMALL_PORTAL_RADIUS);
                                Portals[i][2] = CENTER_Z;
                            }
                            else
                            {
                                Portals[i][0] = Portal_X(LARGE_PORTAL_RADIUS);
                                Portals[i][1] = Portal_Y(Portals[i][0], LARGE_PORTAL_RADIUS);
                                Portals[i][2] = PORTAL_Z;
                            }
                        }
                        if ((abs(Portals[2][0] - Portals[1][0]) < 7) && (abs(Portals[2][1] - Portals[1][1]) < 7))
                        {
                            int i=1;
                            if (abs(CENTER_X + 26.0f - Portals[2][0]) < 7)
                                i = -1;
                            Portals[2][0] = Portals[2][0]+7*i;
                            Portals[2][1] = Portal_Y(Portals[2][0], LARGE_PORTAL_RADIUS);
                        }
                        for (int i=0; i <= 2; ++i)
                        {
                            if (Creature* Summoned = me->SummonCreature(NPC_ASTROMANCER_SOLARIAN_SPOTLIGHT, Portals[i][0], Portals[i][1], Portals[i][2], CENTER_O, TEMPSUMMON_TIMED_DESPAWN, Phase2_Timer+Phase3_Timer+AppearDelay_Timer+1700))
                            {
                                Summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                Summoned->CastSpell(Summoned, SPELL_SPOTLIGHT, false);
                            }
                        }
                        AppearDelay = true;
                    }
                    else
                        Phase1_Timer-=diff;
                }
                else
                    if (Phase == 2)
                    {
                        //10 seconds after Solarian disappears, 12 mobs spawn out of the three portals.
                        me->AttackStop();
                        me->StopMoving();
                        if (Phase2_Timer <= diff)
                        {
                            Phase = 3;
                            for (int i=0; i <= 2; ++i)
                                for (int j=1; j <= 4; j++)
                                    SummonMinion(NPC_SOLARIUM_AGENT, Portals[i][0], Portals[i][1], Portals[i][2]);

                            DoScriptText(SAY_SUMMON1, me);
                            Phase2_Timer = 10000;
                        }
                        else
                            Phase2_Timer -= diff;
                    }
                    else
                        if (Phase == 3)
                        {
                            me->AttackStop();
                            me->StopMoving();
                            //Check Phase3_Timer
                            if (Phase3_Timer <= diff)
                            {
                                Phase = 1;
                                //15 seconds later Solarian reappears out of one of the 3 portals. Simultaneously, 2 healers appear in the two other portals.
                                int i = rand()%3;
                                me->GetMotionMaster()->Clear();
                                me->GetMap()->CreatureRelocation(me, Portals[i][0], Portals[i][1], Portals[i][2], CENTER_O);

                                for (int j=0; j <= 2; j++)
                                    if (j != i)
                                        SummonMinion(NPC_SOLARIUM_PRIEST, Portals[j][0], Portals[j][1], Portals[j][2]);

                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                me->SetVisible(true);

                                DoScriptText(SAY_SUMMON2, me);
                                AppearDelay = true;
                                Phase3_Timer = 15000;
                            }
                            else
                                Phase3_Timer -= diff;
                        }
                        else
                            if (Phase == 4)
                            {
                                //Fear_Timer
                                if (Fear_Timer <= diff)
                                {
                                    DoCast(me, SPELL_FEAR);
                                    Fear_Timer = 20000;
                                }
                                else
                                    Fear_Timer -= diff;
                                //VoidBolt_Timer
                                if (VoidBolt_Timer <= diff)
                                {
                                    DoCast(me->getVictim(), SPELL_VOID_BOLT);
                                    VoidBolt_Timer = 10000;
                                }
                                else
                                    VoidBolt_Timer -= diff;
                            }
                            //When Solarian reaches 20% she will transform into a huge void walker.
                            if (Phase != 4 && me->HealthBelowPct(20))
                            {
                                Phase = 4;
                                //To make sure she wont be invisible or not selecatble
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                me->SetVisible(true);
                                DoScriptText(SAY_VOIDA, me);
                                DoScriptText(SAY_VOIDB, me);
                                me->SetArmor(WV_ARMOR);
                                me->SetDisplayId(MODEL_VOIDWALKER);
                                me->SetFloatValue(OBJECT_FIELD_SCALE_X, defaultsize*2.5f);
                            }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_high_astromancer_solarianAI (creature);
        }
};

class mob_solarium_priest : public CreatureScript
{
    public:

        mob_solarium_priest()
            : CreatureScript("mob_solarium_priest")
        {
        }

        struct mob_solarium_priestAI : public ScriptedAI
        {
            mob_solarium_priestAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript *pInstance;

            uint32 healTimer;
            uint32 holysmiteTimer;
            uint32 aoesilenceTimer;

            void Reset()
            {
                healTimer = 9000;
                holysmiteTimer = 1;
                aoesilenceTimer = 15000;
            }

            void EnterCombat(Unit * /*who*/)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (healTimer <= diff)
                {
                    Unit *pTarget = NULL;
                    switch (urand(0, 1))
                    {
                        case 0:
                            if (pInstance)
                                pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_ASTROMANCER));
                            break;
                        case 1:
                            pTarget = me;
                            break;
                    }

                    if (pTarget)
                    {
                        DoCast(pTarget, SPELL_SOLARIUM_GREAT_HEAL);
                        healTimer = 9000;
                    }
                }
                else
                    healTimer -= diff;

                if (holysmiteTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SOLARIUM_HOLY_SMITE);
                    holysmiteTimer = 4000;
                }
                else
                    holysmiteTimer -= diff;

                if (aoesilenceTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SOLARIUM_ARCANE_TORRENT);
                    aoesilenceTimer = 13000;
                }
                else
                    aoesilenceTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new mob_solarium_priestAI (Creature);
        }
};
void AddSC_boss_high_astromancer_solarian()
{
    new boss_high_astromancer_solarian();
    new mob_solarium_priest();
}

