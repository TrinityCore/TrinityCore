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
            : CreatureScript("mob_av_marshal_or_warmaster") {}

        struct mob_av_marshal_or_warmasterAI : public ScriptedAI
        {
            mob_av_marshal_or_warmasterAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 ChargeTimer;
            uint32 CleaveTimer;
            uint32 DemoralizingShoutTimer;
            uint32 Whirlwind1Timer;
            uint32 Whirlwind2Timer;
            uint32 EnrageTimer;
            uint32 ResetTimer;

            bool bHasAura;

            void Reset()
            {
                ChargeTimer             = urand(2 * IN_MILLISECONDS, 12 * IN_MILLISECONDS);
                CleaveTimer             = urand(1 * IN_MILLISECONDS, 11 * IN_MILLISECONDS);
                DemoralizingShoutTimer  = urand(2 * IN_MILLISECONDS, 2 * IN_MILLISECONDS);
                Whirlwind1Timer         = urand(1 * IN_MILLISECONDS, 12 * IN_MILLISECONDS);
                Whirlwind2Timer         = urand(5 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
                EnrageTimer             = urand(5 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
                ResetTimer              = 5 * IN_MILLISECONDS;

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

                if (ChargeTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CHARGE);
                    ChargeTimer = urand(10 * IN_MILLISECONDS, 25 * IN_MILLISECONDS);
                } else ChargeTimer -= diff;

                if (CleaveTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CLEAVE);
                    CleaveTimer =  urand(10 * IN_MILLISECONDS, 16 * IN_MILLISECONDS);
                } else CleaveTimer -= diff;

                if (DemoralizingShoutTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_DEMORALIZING_SHOUT);
                    DemoralizingShoutTimer = urand(10 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
                } else DemoralizingShoutTimer -= diff;

                if (Whirlwind1Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_WHIRLWIND1);
                    Whirlwind1Timer = urand(6 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
                } else Whirlwind1Timer -= diff;

                if (Whirlwind2Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_WHIRLWIND2);
                    Whirlwind2Timer = urand(10 * IN_MILLISECONDS, 25 * IN_MILLISECONDS);
                } else Whirlwind2Timer -= diff;

                if (EnrageTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_ENRAGE);
                    EnrageTimer = urand(10 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
                }else EnrageTimer -= diff;

                // check if creature is not outside of building
                if (ResetTimer <= diff)
                {
                    if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                        EnterEvadeMode();
                    ResetTimer = 5 * IN_MILLISECONDS;
                } else ResetTimer -= diff;

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
