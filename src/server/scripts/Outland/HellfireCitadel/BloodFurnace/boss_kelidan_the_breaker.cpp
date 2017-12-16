/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "blood_furnace.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"

enum Kelidan
{
    SAY_WAKE                    = 0,
    SAY_ADD_AGGRO               = 1,
    SAY_KILL                    = 2,
    SAY_NOVA                    = 3,
    SAY_DIE                     = 4,

    SPELL_CORRUPTION            = 30938,
    SPELL_EVOCATION             = 30935,

    SPELL_FIRE_NOVA             = 33132,
    H_SPELL_FIRE_NOVA           = 37371,

    SPELL_SHADOW_BOLT_VOLLEY    = 28599,
    H_SPELL_SHADOW_BOLT_VOLLEY  = 40070,

    SPELL_BURNING_NOVA          = 30940,
    SPELL_VORTEX                = 37370,

    ENTRY_KELIDAN               = 17377,
    ENTRY_CHANNELER             = 17653,

    ACTION_ACTIVATE_ADDS        = 92
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
        boss_kelidan_the_breaker() : CreatureScript("boss_kelidan_the_breaker") { }

        struct boss_kelidan_the_breakerAI : public BossAI
        {
            boss_kelidan_the_breakerAI(Creature* creature) : BossAI(creature, DATA_KELIDAN_THE_BREAKER)
            {
                Initialize();
                Firenova_Timer = 0;
            }

            void Initialize()
            {
                ShadowVolley_Timer = 1000;
                BurningNova_Timer = 15000;
                Corruption_Timer = 5000;
                check_Timer = 0;
                Firenova = false;
                addYell = false;
            }

            uint32 ShadowVolley_Timer;
            uint32 BurningNova_Timer;
            uint32 Firenova_Timer;
            uint32 Corruption_Timer;
            uint32 check_Timer;
            bool Firenova;
            bool addYell;
            ObjectGuid Channelers[5];

            void Reset() override
            {
                _Reset();
                Initialize();
                SummonChannelers();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetImmuneToAll(true);
            }

            void EnterCombat(Unit* who) override
            {
                _EnterCombat();
                Talk(SAY_WAKE);
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(true);
                DoStartMovement(who);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                if (rand32() % 2)
                    return;

                Talk(SAY_KILL);
            }

            void ChannelerEngaged(Unit* who)
            {
                if (who && !addYell)
                {
                    addYell = true;
                    Talk(SAY_ADD_AGGRO);
                }
                for (uint8 i = 0; i<5; ++i)
                {
                    Creature* channeler = ObjectAccessor::GetCreature(*me, Channelers[i]);
                    if (who && channeler && !channeler->IsInCombat())
                        channeler->AI()->AttackStart(who);
                }
            }

            void ChannelerDied(Unit* killer)
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    Creature* channeler = ObjectAccessor::GetCreature(*me, Channelers[i]);
                    if (channeler && channeler->IsAlive())
                        return;
                }
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetImmuneToAll(false);
                if (killer)
                    AttackStart(killer);
            }

            ObjectGuid GetChanneled(Creature* channeler1)
            {
                SummonChannelers();
                if (!channeler1)
                    return ObjectGuid::Empty;

                uint8 i;
                for (i = 0; i < 5; ++i)
                {
                    Creature* channeler = ObjectAccessor::GetCreature(*me, Channelers[i]);
                    if (channeler && channeler->GetGUID() == channeler1->GetGUID())
                        break;
                }
                return Channelers[(i + 2) % 5];
            }

            void SummonChannelers()
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    Creature* channeler = ObjectAccessor::GetCreature(*me, Channelers[i]);
                    if (!channeler || channeler->isDead())
                        channeler = me->SummonCreature(ENTRY_CHANNELER, ShadowmoonChannelers[i][0], ShadowmoonChannelers[i][1], ShadowmoonChannelers[i][2], ShadowmoonChannelers[i][3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                    if (channeler)
                        Channelers[i] = channeler->GetGUID();
                    else
                        Channelers[i].Clear();
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DIE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                {
                    if (check_Timer <= diff)
                    {
                        if (!me->IsNonMeleeSpellCast(false))
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
                    ShadowVolley_Timer = 5000 + rand32() % 8000;
                }
                else
                    ShadowVolley_Timer -=diff;

                if (Corruption_Timer <= diff)
                {
                    DoCast(me, SPELL_CORRUPTION);
                    Corruption_Timer = 30000 + rand32() % 20000;
                }
                else
                    Corruption_Timer -=diff;

                if (BurningNova_Timer <= diff)
                {
                    if (me->IsNonMeleeSpellCast(false))
                        me->InterruptNonMeleeSpells(true);

                    Talk(SAY_NOVA);

                    me->AddAura(SPELL_BURNING_NOVA, me);

                    if (IsHeroic())
                        DoTeleportAll(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());

                    BurningNova_Timer = 20000 + rand32() % 8000;
                    Firenova_Timer= 5000;
                    Firenova = true;
                }
                else
                    BurningNova_Timer -=diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBloodFurnaceAI<boss_kelidan_the_breakerAI>(creature);
        }
};

/*######
## npc_shadowmoon_channeler
######*/

enum Shadowmoon
{
    SPELL_SHADOW_BOLT       = 12739,
    H_SPELL_SHADOW_BOLT     = 15472,

    SPELL_MARK_OF_SHADOW    = 30937,
    SPELL_CHANNELING        = 39123
};

class npc_shadowmoon_channeler : public CreatureScript
{
    public:

        npc_shadowmoon_channeler() : CreatureScript("npc_shadowmoon_channeler") { }

        struct npc_shadowmoon_channelerAI : public ScriptedAI
        {
            npc_shadowmoon_channelerAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                ShadowBolt_Timer = 1000 + rand32() % 1000;
                MarkOfShadow_Timer = 5000 + rand32() % 2000;
                check_Timer = 0;
            }

            uint32 ShadowBolt_Timer;
            uint32 MarkOfShadow_Timer;
            uint32 check_Timer;

            void Reset() override
            {
                Initialize();
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(true);
            }

            void EnterCombat(Unit* who) override
            {
                if (Creature* Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
                    ENSURE_AI(boss_kelidan_the_breaker::boss_kelidan_the_breakerAI, Kelidan->AI())->ChannelerEngaged(who);
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(true);
                DoStartMovement(who);
            }

            void JustDied(Unit* killer) override
            {
               if (Creature* Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
                   ENSURE_AI(boss_kelidan_the_breaker::boss_kelidan_the_breakerAI, Kelidan->AI())->ChannelerDied(killer);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                {
                    if (check_Timer <= diff)
                    {
                        if (!me->IsNonMeleeSpellCast(false))
                        {
                            if (Creature* Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
                            {
                                ObjectGuid channeler = ENSURE_AI(boss_kelidan_the_breaker::boss_kelidan_the_breakerAI, Kelidan->AI())->GetChanneled(me);
                                if (Unit* channeled = ObjectAccessor::GetUnit(*me, channeler))
                                    DoCast(channeled, SPELL_CHANNELING);
                            }
                        }
                        check_Timer = 5000;
                    }
                    else
                        check_Timer -= diff;

                    return;
                }

                if (MarkOfShadow_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_MARK_OF_SHADOW);
                    MarkOfShadow_Timer = 15000 + rand32() % 5000;
                }
                else
                    MarkOfShadow_Timer -=diff;

                if (ShadowBolt_Timer <= diff)
                {
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    ShadowBolt_Timer = 5000 + rand32() % 1000;
                }
                else
                    ShadowBolt_Timer -=diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBloodFurnaceAI<npc_shadowmoon_channelerAI>(creature);
        }
};

void AddSC_boss_kelidan_the_breaker()
{
    new boss_kelidan_the_breaker();
    new npc_shadowmoon_channeler();
}
