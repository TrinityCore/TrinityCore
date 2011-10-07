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

enum Spells
{
    SPELL_CHARGE                                  = 22911,
    SPELL_CLEAVE                                  = 40504,
    SPELL_DEMORALIZING_SHOUT                      = 23511,
    SPELL_ENRAGE                                  = 8599,
    SPELL_WHIRLWIND1                              = 15589,
    SPELL_WHIRLWIND2                              = 13736,
    SPELL_NORTH_MARSHAL                           = 45828,
    SPELL_SOUTH_MARSHAL                           = 45829,
    SPELL_STONEHEARTH_MARSHAL                     = 45830,
    SPELL_ICEWING_MARSHAL                         = 45831,
    SPELL_ICEBLOOD_WARMASTER                      = 45822,
    SPELL_TOWER_POINT_WARMASTER                   = 45823,
    SPELL_WEST_FROSTWOLF_WARMASTER                = 45824,
    SPELL_EAST_FROSTWOLF_WARMASTER                = 45826
};

enum Creatures
{
    NPC_NORTH_MARSHAL                             = 14762,
    NPC_SOUTH_MARSHAL                             = 14763,
    NPC_ICEWING_MARSHAL                           = 14764,
    NPC_STONEHEARTH_MARSHAL                       = 14765,
    NPC_EAST_FROSTWOLF_WARMASTER                  = 14772,
    NPC_ICEBLOOD_WARMASTER                        = 14773,
    NPC_TOWER_POINT_WARMASTER                     = 14776,
    NPC_WEST_FROSTWOLF_WARMASTER                  = 14777
};

class mob_av_marshal_or_warmaster : public CreatureScript
{
    public:

        mob_av_marshal_or_warmaster()
            : CreatureScript("mob_av_marshal_or_warmaster")
        {
        }

        struct mob_av_marshal_or_warmasterAI : public ScriptedAI
        {
            mob_av_marshal_or_warmasterAI(Creature* c) : ScriptedAI(c) {}

            uint32 uiChargeTimer;
            uint32 uiCleaveTimer;
            uint32 uiDemoralizingShoutTimer;
            uint32 uiWhirlwind1Timer;
            uint32 uiWhirlwind2Timer;
            uint32 uiEnrageTimer;
            uint32 uiResetTimer;

            bool bHasAura;

            void Reset()
            {
                uiChargeTimer = urand(2*IN_MILLISECONDS, 12*IN_MILLISECONDS);
                uiCleaveTimer = urand(1*IN_MILLISECONDS, 11*IN_MILLISECONDS);
                uiDemoralizingShoutTimer = urand(2*IN_MILLISECONDS, 2*IN_MILLISECONDS);
                uiWhirlwind1Timer = urand(1*IN_MILLISECONDS, 12*IN_MILLISECONDS);
                uiWhirlwind2Timer = urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS);
                uiEnrageTimer = urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS);
                uiResetTimer = 5*IN_MILLISECONDS;

                bHasAura = false;
            }

            void JustRespawned()
            {
                Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!bHasAura)
                {
                    switch (me->GetEntry())
                    {
                        case NPC_NORTH_MARSHAL:
                            DoCast(me, SPELL_NORTH_MARSHAL);
                            break;
                        case NPC_SOUTH_MARSHAL:
                            DoCast(me, SPELL_SOUTH_MARSHAL);
                            break;
                        case NPC_STONEHEARTH_MARSHAL:
                            DoCast(me, SPELL_STONEHEARTH_MARSHAL);
                            break;
                        case NPC_ICEWING_MARSHAL:
                            DoCast(me, SPELL_ICEWING_MARSHAL);
                            break;
                        case NPC_EAST_FROSTWOLF_WARMASTER:
                            DoCast(me, SPELL_EAST_FROSTWOLF_WARMASTER);
                            break;
                        case NPC_WEST_FROSTWOLF_WARMASTER:
                            DoCast(me, SPELL_WEST_FROSTWOLF_WARMASTER);
                            break;
                        case NPC_ICEBLOOD_WARMASTER:
                            DoCast(me, SPELL_ICEBLOOD_WARMASTER);
                            break;
                        case NPC_TOWER_POINT_WARMASTER:
                            DoCast(me, SPELL_TOWER_POINT_WARMASTER);
                            break;
                    }

                    bHasAura = true;
                }

                if (!UpdateVictim())
                    return;

                if (uiChargeTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CHARGE);
                    uiChargeTimer = urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS);
                } else uiChargeTimer -= diff;

                if (uiCleaveTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CLEAVE);
                    uiCleaveTimer =  urand(10*IN_MILLISECONDS, 16*IN_MILLISECONDS);
                } else uiCleaveTimer -= diff;

                if (uiDemoralizingShoutTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_DEMORALIZING_SHOUT);
                    uiDemoralizingShoutTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
                } else uiDemoralizingShoutTimer -= diff;

                if (uiWhirlwind1Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_WHIRLWIND1);
                    uiWhirlwind1Timer = urand(6*IN_MILLISECONDS, 20*IN_MILLISECONDS);
                } else uiWhirlwind1Timer -= diff;

                if (uiWhirlwind2Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_WHIRLWIND2);
                    uiWhirlwind2Timer = urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS);
                } else uiWhirlwind2Timer -= diff;

                if (uiEnrageTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_ENRAGE);
                    uiEnrageTimer = urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                }else uiEnrageTimer -= diff;

                // check if creature is not outside of building
                if (uiResetTimer <= diff)
                {
                    if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                        EnterEvadeMode();
                    uiResetTimer = 5*IN_MILLISECONDS;
                } else uiResetTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_av_marshal_or_warmasterAI(creature);
        }
};

void AddSC_alterac_valley()
{
    new mob_av_marshal_or_warmaster();
}
