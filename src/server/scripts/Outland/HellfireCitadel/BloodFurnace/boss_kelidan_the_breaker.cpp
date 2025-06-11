/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* Find a more elegant way to handle channelers */

#include "ScriptMgr.h"
#include "blood_furnace.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"

enum KelidanTexts
{
    SAY_WAKE                    = 0,
    SAY_NOVA                    = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3,

    SAY_AGGRO                   = 0
};

enum KelidanSpells
{
    SPELL_CORRUPTION            = 30938,
    SPELL_EVOCATION             = 30935,

    SPELL_FIRE_NOVA             = 33132,
    SPELL_FIRE_NOVA_H           = 37371,

    SPELL_SHADOW_BOLT_VOLLEY    = 28599,
    SPELL_SHADOW_BOLT_VOLLEY_H  = 40070,

    SPELL_BURNING_NOVA          = 30940,
    SPELL_VORTEX                = 37370,

    // Shadowmoon Channeler
    SPELL_SHADOW_BOLT           = 12739,
    SPELL_SHADOW_BOLT_H         = 15472,

    SPELL_MARK_OF_SHADOW        = 30937,
    SPELL_CHANNELING            = 39123
};

enum KelidanMisc
{
    NPC_KELIDAN                 = 17377,
    NPC_CHANNELER               = 17653
};

Position const ShadowmoonChannelers[5] =
{
    { 301.988f, -86.7465f, -24.4517f, 0.15708f },
    { 320.750f, -63.6121f, -24.6361f, 4.88692f },
    { 345.848f, -74.4559f, -24.6402f, 3.59538f },
    { 343.584f, -103.631f, -24.5688f, 2.35619f },
    { 316.274f, -108.877f, -24.6027f, 1.25664f }
};

// 17377 - Keli'dan the Breaker
struct boss_kelidan_the_breaker : public BossAI
{
    boss_kelidan_the_breaker(Creature* creature) : BossAI(creature, DATA_KELIDAN_THE_BREAKER)
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
    }

    uint32 ShadowVolley_Timer;
    uint32 BurningNova_Timer;
    uint32 Firenova_Timer;
    uint32 Corruption_Timer;
    uint32 check_Timer;
    bool Firenova;
    ObjectGuid Channelers[5];

    void Reset() override
    {
        _Reset();
        Initialize();
        SummonChannelers();
        me->SetImmuneToNPC(true);
        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_WAKE);
        if (me->IsNonMeleeSpellCast(false))
            me->InterruptNonMeleeSpells(true);
        DoStartMovement(who);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        if (rand32() % 2)
            return;

        Talk(SAY_SLAY);
    }

    void ChannelerEngaged(Unit* who)
    {
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
        me->SetImmuneToNPC(false);
        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
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
                channeler = me->SummonCreature(NPC_CHANNELER, ShadowmoonChannelers[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5min);
            if (channeler)
                Channelers[i] = channeler->GetGUID();
            else
                Channelers[i].Clear();
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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

// 17653 - Shadowmoon Channeler
struct npc_shadowmoon_channeler : public ScriptedAI
{
    npc_shadowmoon_channeler(Creature* creature) : ScriptedAI(creature)
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

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);

        if (Creature* Kelidan = me->FindNearestCreature(NPC_KELIDAN, 100))
            ENSURE_AI(boss_kelidan_the_breaker, Kelidan->AI())->ChannelerEngaged(who);
        if (me->IsNonMeleeSpellCast(false))
            me->InterruptNonMeleeSpells(true);
        DoStartMovement(who);
    }

    void JustDied(Unit* killer) override
    {
        if (!killer)
            return;

        if (Creature* Kelidan = me->FindNearestCreature(NPC_KELIDAN, 100))
            ENSURE_AI(boss_kelidan_the_breaker, Kelidan->AI())->ChannelerDied(killer);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            if (check_Timer <= diff)
            {
                if (!me->IsNonMeleeSpellCast(false))
                {
                    if (Creature* Kelidan = me->FindNearestCreature(NPC_KELIDAN, 100))
                    {
                        ObjectGuid channeler = ENSURE_AI(boss_kelidan_the_breaker, Kelidan->AI())->GetChanneled(me);
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
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
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

void AddSC_boss_kelidan_the_breaker()
{
    RegisterBloodFurnaceCreatureAI(boss_kelidan_the_breaker);
    RegisterBloodFurnaceCreatureAI(npc_shadowmoon_channeler);
}
