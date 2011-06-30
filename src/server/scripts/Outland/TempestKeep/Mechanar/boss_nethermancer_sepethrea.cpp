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
SDName: Boss_Nethermancer_Sepethrea
SD%Complete: 90
SDComment: Need adjustments to initial summons
SDCategory: Tempest Keep, The Mechanar
EndScriptData */

#include "ScriptPCH.h"
#include "mechanar.h"

enum eSays
{
    SAY_AGGRO                      = -1554013,
    SAY_SUMMON                     = -1554014,
    SAY_DRAGONS_BREATH_1           = -1554015,
    SAY_DRAGONS_BREATH_2           = -1554016,
    SAY_SLAY1                      = -1554017,
    SAY_SLAY2                      = -1554018,
    SAY_DEATH                      = -1554019,
};

enum eSpells
{
    SPELL_SUMMON_RAGIN_FLAMES      = 35275,
    SPELL_FROST_ATTACK             = 35263,
    SPELL_ARCANE_BLAST             = 35314,
    SPELL_DRAGONS_BREATH           = 35250,
    SPELL_KNOCKBACK                = 37317,
    SPELL_SOLARBURN                = 35267,
    H_SPELL_SUMMON_RAGIN_FLAMES    = 39084,
    SPELL_INFERNO                  = 35268,
    H_SPELL_INFERNO                = 39346,
    SPELL_FIRE_TAIL                = 35278,
};

class boss_nethermancer_sepethrea : public CreatureScript
{
    public:

        boss_nethermancer_sepethrea()
            : CreatureScript("boss_nethermancer_sepethrea")
        {
        }
        struct boss_nethermancer_sepethreaAI : public ScriptedAI
        {
            boss_nethermancer_sepethreaAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript *pInstance;

            uint32 frost_attack_Timer;
            uint32 arcane_blast_Timer;
            uint32 dragons_breath_Timer;
            uint32 knockback_Timer;
            uint32 solarburn_Timer;

            void Reset()
            {
                frost_attack_Timer = 7000 + rand()%3000;
                arcane_blast_Timer = 12000 + rand()%6000;
                dragons_breath_Timer = 18000 + rand()%4000;
                knockback_Timer = 22000 + rand()%6000;
                solarburn_Timer = 30000;

                if (pInstance)
                    pInstance->SetData(DATA_NETHERMANCER_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* who)
            {
                if (pInstance)
                    pInstance->SetData(DATA_NETHERMANCER_EVENT, IN_PROGRESS);

                DoScriptText(SAY_AGGRO, me);
                DoCast(who, SPELL_SUMMON_RAGIN_FLAMES);
                DoScriptText(SAY_SUMMON, me);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY1, SAY_SLAY2), me);
            }

            void JustDied(Unit* /*Killer*/)
            {
                DoScriptText(SAY_DEATH, me);
                if (pInstance)
                    pInstance->SetData(DATA_NETHERMANCER_EVENT, DONE);
            }

            void UpdateAI(const uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Frost Attack
                if (frost_attack_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FROST_ATTACK);

                    frost_attack_Timer = 7000 + rand()%3000;
                }
                else
                    frost_attack_Timer -= diff;

                //Arcane Blast
                if (arcane_blast_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_ARCANE_BLAST);
                    arcane_blast_Timer = 15000;
                }
                else
                    arcane_blast_Timer -= diff;
                //Dragons Breath
                if (dragons_breath_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_DRAGONS_BREATH);
                    {
                        if (rand()%2)
                            return;
                        DoScriptText(RAND(SAY_DRAGONS_BREATH_1, SAY_DRAGONS_BREATH_2), me);
                    }
                    dragons_breath_Timer = 12000 + rand()%10000;
                }
                else
                    dragons_breath_Timer -= diff;

                //Knockback
                if (knockback_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_KNOCKBACK);
                    knockback_Timer = 15000 + rand()%10000;
                }
                else
                    knockback_Timer -= diff;

                //Solarburn
                if (solarburn_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SOLARBURN);
                    solarburn_Timer = 30000;
                }
                else
                    solarburn_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_nethermancer_sepethreaAI(creature);
        }
};
class mob_ragin_flames : public CreatureScript
{
    public:
        mob_ragin_flames()
            : CreatureScript("mob_ragin_flames")
        {
        }

            struct mob_ragin_flamesAI : public ScriptedAI
            {
                mob_ragin_flamesAI(Creature* pCreature) : ScriptedAI(pCreature)
                {
                    pInstance = pCreature->GetInstanceScript();
                }

                InstanceScript *pInstance;

                uint32 inferno_Timer;
                uint32 flame_timer;
                uint32 Check_Timer;

                bool onlyonce;

                void Reset()
                {
                    inferno_Timer = 10000;
                    flame_timer = 500;
                    Check_Timer = 2000;
                    onlyonce = false;
                    me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
                    me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
                    me->SetSpeed(MOVE_RUN, DUNGEON_MODE(0.5f, 0.7f));
                }

                void EnterCombat(Unit* /*who*/)
                {
                }

                void UpdateAI(const uint32 diff)
                {
                    //Check_Timer
                    if (Check_Timer <= diff)
                    {
                        if (pInstance)
                        {
                            if (pInstance->GetData(DATA_NETHERMANCER_EVENT) != IN_PROGRESS)
                            {
                                //remove
                                me->setDeathState(JUST_DIED);
                                me->RemoveCorpse();
                            }
                        }
                        Check_Timer = 1000;
                    } else Check_Timer -= diff;

                    if (!UpdateVictim())
                        return;

                    if (!onlyonce)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            me->GetMotionMaster()->MoveChase(pTarget);
                        onlyonce = true;
                    }

                    if (inferno_Timer <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_INFERNO);
                        me->TauntApply(me->getVictim());
                        inferno_Timer = 10000;
                    } else inferno_Timer -= diff;

                    if (flame_timer <= diff)
                    {
                        DoCast(me, SPELL_FIRE_TAIL);
                        flame_timer = 500;
                    } else flame_timer -=diff;

                    DoMeleeAttackIfReady();
                }

            };
            CreatureAI* GetAI(Creature* creature) const
            {
                return new mob_ragin_flamesAI(creature);
            }
};
void AddSC_boss_nethermancer_sepethrea()
{
    new boss_nethermancer_sepethrea();
    new mob_ragin_flames();
}

