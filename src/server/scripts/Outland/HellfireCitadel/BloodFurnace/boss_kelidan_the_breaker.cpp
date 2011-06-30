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
SDName: Boss_Kelidan_The_Breaker
SD%Complete: 100
SDComment:
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

/* ContentData
boss_kelidan_the_breaker
mob_shadowmoon_channeler
EndContentData */

#include "ScriptPCH.h"
#include "blood_furnace.h"

enum eKelidan
{
    SAY_WAKE                    = -1542000,
    SAY_ADD_AGGRO_1             = -1542001,
    SAY_ADD_AGGRO_2             = -1542002,
    SAY_ADD_AGGRO_3             = -1542003,
    SAY_KILL_1                  = -1542004,
    SAY_KILL_2                  = -1542005,
    SAY_NOVA                    = -1542006,
    SAY_DIE                     = -1542007,

    SPELL_CORRUPTION            = 30938,
    SPELL_EVOCATION             = 30935,

    SPELL_FIRE_NOVA             = 33132,
    H_SPELL_FIRE_NOVA           = 37371,

    SPELL_SHADOW_BOLT_VOLLEY    = 28599,
    H_SPELL_SHADOW_BOLT_VOLLEY  = 40070,

    SPELL_BURNING_NOVA          = 30940,
    SPELL_VORTEX                = 37370,

    ENTRY_KELIDAN               = 17377,
    ENTRY_CHANNELER             = 17653
};

const float ShadowmoonChannelers[5][4]=
{
    {302.0f, -87.0f, -24.4f, 0.157f},
    {321.0f, -63.5f, -24.6f, 4.887f},
    {346.0f, -74.5f, -24.6f, 3.595f},
    {344.0f, -103.5f, -24.5f, 2.356f},
    {316.0f, -109.0f, -24.6f, 1.257f}
};

class boss_kelidan_the_breaker : public CreatureScript
{
    public:

        boss_kelidan_the_breaker()
            : CreatureScript("boss_kelidan_the_breaker")
        {
        }

        struct boss_kelidan_the_breakerAI : public ScriptedAI
        {
            boss_kelidan_the_breakerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                for (uint8 i=0; i<5; ++i)
                    Channelers[i] = 0;
            }

            InstanceScript* pInstance;

            uint32 ShadowVolley_Timer;
            uint32 BurningNova_Timer;
            uint32 Firenova_Timer;
            uint32 Corruption_Timer;
            uint32 check_Timer;
            bool Firenova;
            bool addYell;
            uint64 Channelers[5];

            void Reset()
            {
                ShadowVolley_Timer = 1000;
                BurningNova_Timer = 15000;
                Corruption_Timer = 5000;
                check_Timer = 0;
                Firenova = false;
                addYell = false;
                SummonChannelers();
                if (pInstance)
                    pInstance->SetData(TYPE_KELIDAN_THE_BREAKER_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* who)
            {
                DoScriptText(SAY_WAKE, me);
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(true);
                DoStartMovement(who);
                if (pInstance)
                    pInstance->SetData(TYPE_KELIDAN_THE_BREAKER_EVENT, IN_PROGRESS);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                if (rand()%2)
                    return;

                DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
            }

            void ChannelerEngaged(Unit* who)
            {
                if (who && !addYell)
                {
                    addYell = true;
                    DoScriptText(RAND(SAY_ADD_AGGRO_1, SAY_ADD_AGGRO_2, SAY_ADD_AGGRO_3), me);
                }
                for (uint8 i=0; i<5; ++i)
                {
                    Creature* channeler = Unit::GetCreature(*me, Channelers[i]);
                    if (who && channeler && !channeler->isInCombat())
                        channeler->AI()->AttackStart(who);
                }
            }

            void ChannelerDied(Unit* killer)
            {
                for (uint8 i=0; i<5; ++i)
                {
                    Creature* channeler = Unit::GetCreature(*me, Channelers[i]);
                    if (channeler && channeler->isAlive())
                        return;
                }

                if (killer)
                    me->AI()->AttackStart(killer);
            }

            uint64 GetChanneled(Creature* channeler1)
            {
                SummonChannelers();
                if (!channeler1) return 0;
                uint8 i;
                for (i=0; i<5; ++i)
                {
                    Creature* channeler = Unit::GetCreature(*me, Channelers[i]);
                    if (channeler && channeler->GetGUID() == channeler1->GetGUID())
                        break;
                }
                return Channelers[(i+2)%5];
            }

            void SummonChannelers()
            {
                for (uint8 i=0; i<5; ++i)
                {
                    Creature* channeler = Unit::GetCreature(*me, Channelers[i]);
                    if (!channeler || channeler->isDead())
                        channeler = me->SummonCreature(ENTRY_CHANNELER, ShadowmoonChannelers[i][0], ShadowmoonChannelers[i][1], ShadowmoonChannelers[i][2], ShadowmoonChannelers[i][3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                    if (channeler)
                        Channelers[i] = channeler->GetGUID();
                    else
                        Channelers[i] = 0;
                }
            }

            void JustDied(Unit* /*Killer*/)
            {
                DoScriptText(SAY_DIE, me);

                if (!pInstance)
                    return;

                pInstance->SetData(TYPE_KELIDAN_THE_BREAKER_EVENT, DONE);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR1), true);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR6), true);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                {
                    if (check_Timer <= diff)
                    {
                        if (!me->IsNonMeleeSpellCasted(false))
                            DoCast(me, SPELL_EVOCATION);
                        check_Timer = 5000;
                    }
                    else
                        check_Timer -= diff;
                    return;
                }

                if (Firenova)
                {
                    if (Firenova_Timer <= diff)
                    {
                        DoCast(me, SPELL_FIRE_NOVA, true);
                        Firenova = false;
                        ShadowVolley_Timer = 2000;
                    }
                    else
                        Firenova_Timer -=diff;

                    return;
                }

                if (ShadowVolley_Timer <= diff)
                {
                    DoCast(me, SPELL_SHADOW_BOLT_VOLLEY);
                    ShadowVolley_Timer = 5000+rand()%8000;
                }
                else
                    ShadowVolley_Timer -=diff;

                if (Corruption_Timer <= diff)
                {
                    DoCast(me, SPELL_CORRUPTION);
                    Corruption_Timer = 30000+rand()%20000;
                }
                else
                    Corruption_Timer -=diff;

                if (BurningNova_Timer <= diff)
                {
                    if (me->IsNonMeleeSpellCasted(false))
                        me->InterruptNonMeleeSpells(true);

                    DoScriptText(SAY_NOVA, me);

                    if (SpellEntry *nova = GET_SPELL(SPELL_BURNING_NOVA))
                    {
                        if (Aura * aura = Aura::TryRefreshStackOrCreate(nova, MAX_EFFECT_MASK, me, me))
                            aura->ApplyForTargets();
                    }

                    if (IsHeroic())
                        DoTeleportAll(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());

                    BurningNova_Timer = 20000+rand()%8000;
                    Firenova_Timer= 5000;
                    Firenova = true;
                }
                else
                    BurningNova_Timer -=diff;

                DoMeleeAttackIfReady();
            }

        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new boss_kelidan_the_breakerAI (Creature);
        }
};

/*######
## mob_shadowmoon_channeler
######*/

enum eShadowmoon
{
    SPELL_SHADOW_BOLT       = 12739,
    H_SPELL_SHADOW_BOLT     = 15472,

    SPELL_MARK_OF_SHADOW    = 30937,
    SPELL_CHANNELING        = 39123
};

class mob_shadowmoon_channeler : public CreatureScript
{
    public:

        mob_shadowmoon_channeler()
            : CreatureScript("mob_shadowmoon_channeler")
        {
        }

        struct mob_shadowmoon_channelerAI : public ScriptedAI
        {
            mob_shadowmoon_channelerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
            }

            uint32 ShadowBolt_Timer;
            uint32 MarkOfShadow_Timer;
            uint32 check_Timer;

            void Reset()
            {
                ShadowBolt_Timer = 1000+rand()%1000;
                MarkOfShadow_Timer = 5000+rand()%2000;
                check_Timer = 0;
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(true);
            }

            void EnterCombat(Unit* who)
            {
                if (Creature* Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
                    CAST_AI(boss_kelidan_the_breaker::boss_kelidan_the_breakerAI, Kelidan->AI())->ChannelerEngaged(who);
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(true);
                DoStartMovement(who);
            }

            void JustDied(Unit* Killer)
            {
               if (Creature* Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
                   CAST_AI(boss_kelidan_the_breaker::boss_kelidan_the_breakerAI, Kelidan->AI())->ChannelerDied(Killer);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                {
                    if (check_Timer <= diff)
                    {
                        if (!me->IsNonMeleeSpellCasted(false))
                            if (Creature* Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
                            {
                                uint64 channeler = CAST_AI(boss_kelidan_the_breaker::boss_kelidan_the_breakerAI, Kelidan->AI())->GetChanneled(me);
                                if (Unit* channeled = Unit::GetUnit(*me, channeler))
                                    DoCast(channeled, SPELL_CHANNELING);
                            }
                        check_Timer = 5000;
                    }
                    else
                        check_Timer -= diff;
                    return;
                }

                if (MarkOfShadow_Timer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_MARK_OF_SHADOW);
                    MarkOfShadow_Timer = 15000+rand()%5000;
                }
                else
                    MarkOfShadow_Timer -=diff;

                if (ShadowBolt_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                    ShadowBolt_Timer = 5000+rand()%1000;
                }
                else
                    ShadowBolt_Timer -=diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new mob_shadowmoon_channelerAI (Creature);
        }
};

void AddSC_boss_kelidan_the_breaker()
{
    new boss_kelidan_the_breaker();
    new mob_shadowmoon_channeler();
}

