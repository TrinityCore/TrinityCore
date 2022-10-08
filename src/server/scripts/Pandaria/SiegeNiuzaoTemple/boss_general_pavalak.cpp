/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "siege_of_the_niuzao_temple.h"

enum eSpells
{
    SPELL_BLADE_RUSH_CHARGE      = 124312,
    SPELL_BLADE_RUSH_VISUAL      = 124307,
    SPELL_BLADE_RUSH_TRDMG       = 124290,
    SPELL_BLADE_RUSH_KNOCK       = 124317,
    SPELL_BLADE_RUSH_DUMMY       = 124288,
    SPELL_DISARM                 = 124327,
    SPELL_TEMPEST                = 119875,
    SPELL_BULWARK                = 119476,
    SPEL_SIEGE_EXPLOSIVES        = 119376,
    SPEL_SIEGE_EXPLOSIVES_SUMMON = 119377,
    SPEL_SIEGE_EXPLOSIVES_VISUAL = 119380, 
    SPEL_SIEGE_EXPLOSIVES_CLICK  = 119388,
};

class boss_general_pavalak : public CreatureScript
{
    public:
        boss_general_pavalak() : CreatureScript("boss_general_pavalak") {}

        struct boss_general_pavalakAI : public BossAI
        {
            boss_general_pavalakAI(Creature* creature) : BossAI(creature, NPC_PAVALAK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 bladeprepare;
            uint32 bladeprogress;
            uint32 tempest;
            uint32 explosives;
            uint64 bladeguid;
            
            bool bulwark75;
            bool bulwark35;
            bool bulwarkCheck;

            void Reset()
            {
                _Reset();
                tempest = 0;
                bladeguid = 0;
                bladeprepare = 0;
                bladeprogress = 0;
                explosives = 0;
                bulwark75 = false;
                bulwark35 = false;
                bulwarkCheck = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                bladeprepare = 5000;
            }

          /*  void BladeRush()
            {
                if (!bladeguid)
                    return;

                if (Creature* blade = me->GetCreature(me, bladeguid))
                {
                    me->SetReactState(REACT_PASSIVE);
                    DoCast(me, SPELL_DISARM);
                    blade->CastSpell(blade, SPELL_BLADE_RUSH_TRDMG, true);
                    blade->CastSpell(blade, SPELL_BLADE_RUSH_VISUAL);
                    DoCast(blade, SPELL_BLADE_RUSH_CHARGE);
                    blade->CastSpell(blade, SPELL_BLADE_RUSH_KNOCK);
                    if (me->HasAura(SPELL_DISARM))
                    {
                        if (blade)
                            blade->DespawnOrUnsummon();
                        me->RemoveAura(SPELL_DISARM);
                    }
                    me->SetReactState(REACT_AGGRESSIVE);
                    bladeguid = 0;
                    tempest = 3000;
                    bladeprepare = 15000;
                }
            }
            */
            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (me->HealthBelowPct(75) && !bulwark75)
                {
                    bulwark75 = true;
                    bulwarkCheck = true;
                    BulwarkEvent();
                }
                if (me->HealthBelowPct(35) && !bulwark35)
                {
                    bulwark35 = true;
                    bulwarkCheck = true;
                    BulwarkEvent();
                }
                if (!me->HasAura(SPELL_BULWARK) && !bulwarkCheck)
                    me->SetReactState(REACT_AGGRESSIVE);
            }

            void BulwarkEvent()
            {
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->GetMotionMaster()->MoveTargetedHome();
            }

            void JustReachedHome()
            {
                if (bulwark75 || bulwark35)
                {
                    DoCast(SPELL_BULWARK);
                    explosives = 1000;
                }
                bulwarkCheck = false;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (explosives && me->HasAura(SPELL_BULWARK))
                    if (explosives <= diff)
                    {
                        DoCast(me, SPEL_SIEGE_EXPLOSIVES_SUMMON, true);
                        explosives = 3000;
                    }
                    else
                        explosives -= diff;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (bladeprepare)
                {
                    if (bladeprepare <= diff)
                    {
                        bladeprepare = 0;
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        {
                            Position pos;
                            //target->GetPosition(&pos);
                            if (Creature* blade = me->SummonCreature(63720, pos, TEMPSUMMON_TIMED_DESPAWN, 10000))
                            {
                              //  bladeguid = blade->GetGUID();
                                bladeprogress = 4000;
                            }
                        }
                    }
                    else
                        bladeprepare -= diff;
                }

                if (bladeprogress)
                {
                    if (bladeprogress <= diff)
                    {
                        bladeprogress = 0;
                     //   BladeRush();
                    }
                    else
                        bladeprogress -= diff;
                }

                if (tempest)
                {
                    if (tempest <= diff)
                    {
                        tempest = 0;
                        if (me->GetVictim())
                            DoCast(me->GetVictim(), SPELL_TEMPEST);
                    }
                    else
                        tempest -= diff;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_general_pavalakAI(creature);
        }
};


// Siege Explosives - 61452
class npc_siege_explosive : public CreatureScript
{
    public:
        npc_siege_explosive() : CreatureScript("npc_siege_explosive") {}

        struct npc_siege_explosiveAI : public Scripted_NoMovementAI
        {
            npc_siege_explosiveAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
            }

            InstanceScript* instance;

            void Reset()
            {
                me->AddAura(SPEL_SIEGE_EXPLOSIVES_VISUAL, me);
                me->DespawnOrUnsummon(5000);
            }

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_explosiveAI(creature);
        }
};

void AddSC_boss_general_pavalak()
{
    new boss_general_pavalak();
    new npc_siege_explosive();
}
