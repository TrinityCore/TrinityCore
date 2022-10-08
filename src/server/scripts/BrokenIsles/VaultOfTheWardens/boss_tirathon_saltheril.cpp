/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "vault_of_the_wardens.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_DARKSTRIKES = 1,
    SAY_FURIOUS = 2,
    SAY_METAMORPH = 3,
    SAY_EVADE = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_DARKSTRIKES = 191941,
    SPELL_DARKSTRIKES_DMG = 191948,
    SPELL_DARK_ENERGIES_ABSORB = 191999,
    SPELL_SWOOP = 191765,
    SPELL_SWOOP_JUMP = 191766,
    SPELL_FURIOUS_BLAST = 191823,
    SPELL_FEL_MORTAR = 202913,

    //Second Phase 50% HP
    SPELL_METAMORPHOSIS_HAVOC = 192504,
    SPELL_METAMORPHOSIS_VENGEANCE = 202740,
    //Havoc
    SPELL_SUMMON_LASER_BEAM = 202780,
    SPELL_LASER_BEAM_AT = 190830, //Hatred. Dmg 190836
    SPELL_LASER_BEAM_VISUAL = 190833,
    SPELL_LASER_BEAM_BETWEEN_DMG = 202862,

    //Other
    SPELL_JUMP_DOWN = 199132,
    SPELL_DUAL_WIELD = 42459,
};

//to-do: 191641 spell on trash

enum eEvents
{
    EVENT_DARKSTRIKES = 1,
    EVENT_SWOOP = 2,
    EVENT_METAMORPHOSIS = 3,
    EVENT_FEL_MORTAR = 4,
    EVENT_LASER_BEAM = 5,
};

//95885
class boss_tirathon_saltheril : public CreatureScript
{
public:
    boss_tirathon_saltheril() : CreatureScript("boss_tirathon_saltheril") {}

    struct boss_tirathon_saltherilAI : public BossAI
    {
        boss_tirathon_saltherilAI(Creature* creature) : BossAI(creature, DATA_SALTHERIL), phaseSecond(false)
        {
            introScene = false;
            introDone = false;
            randMetamorph = urand(0, 1);
            timer = 0;
            phase = 0;
        }

        bool introScene;
        bool introDone;
        bool phaseSecond;
        uint8 randMetamorph;
        uint32 timer, phase;

        void Reset() override
        {
            _Reset();
            phaseSecond = false;
            DoCast(me, SPELL_DUAL_WIELD, true);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();

            events.RescheduleEvent(EVENT_DARKSTRIKES, 16000);
            events.RescheduleEvent(EVENT_SWOOP, 22000);
            events.RescheduleEvent(EVENT_FEL_MORTAR, 10000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            if (auto drelanim = me->FindNearestCreature(99013, 100.0f))
                drelanim->AI()->DoAction(2);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            BossAI::EnterEvadeMode();
            Talk(SAY_EVADE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!introDone && me->IsWithinDistInMap(who, 118.0f))
            {
              //  Conversation* conversation = new Conversation;
             //   if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 873, who, NULL, *who))
             //       delete conversation;
                introDone = true;
                timer = 5000;
                phase = 0;
                introScene = true;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == EFFECT_MOTION_TYPE)
            {
                if (id == SPELL_SWOOP_JUMP)
                {
                    DoCast(SPELL_FURIOUS_BLAST);
                    Talk(SAY_FURIOUS);
                }
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPct(51) && !phaseSecond)
            {
                phaseSecond = true;
                events.RescheduleEvent(EVENT_METAMORPHOSIS, 0);
                Talk(SAY_METAMORPH);
            }
        }

        void DoAction(int32 const action) override
        {
            if (action == 1)
            {
                me->InterruptNonMeleeSpells(false);
                me->SetReactState(REACT_AGGRESSIVE);
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_FEL_MORTAR:
            {
                Position pos;
                target->GetRandomNearPosition(5.0f);
                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 202920, true); //Fel Mortar
                break;
            }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (introScene)
            {
                switch (phase)
                {
                case 0:
                {
                    if (timer < diff)
                    {
                        DoCast(199132);
                        phase++;
                        timer = 2000;
                    }
                    else timer -= diff;
                    break;
                }
                case 1:
                {
                    if (timer < diff)
                    {
                        me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                        phase++;
                        introScene = false;
                        if (auto drelanim = me->FindNearestCreature(99013, 100.0f, true))
                            drelanim->AI()->DoAction(1);
                    }
                    else timer -= diff;
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DARKSTRIKES:
                    DoCast(SPELL_DARKSTRIKES);
                    Talk(SAY_DARKSTRIKES);
                    events.RescheduleEvent(EVENT_DARKSTRIKES, 60000);
                    break;
                case EVENT_SWOOP:
                    DoCast(SPELL_SWOOP);
                    events.RescheduleEvent(EVENT_SWOOP, 30000);
                    break;
                case EVENT_METAMORPHOSIS:
                    if (!randMetamorph)
                    {
                        DoCast(SPELL_METAMORPHOSIS_HAVOC);
                        events.RescheduleEvent(EVENT_LASER_BEAM, 24000);
                    }
                    else
                    {
                        events.CancelEvent(EVENT_SWOOP);
                        DoCast(SPELL_METAMORPHOSIS_VENGEANCE);
                    }
                    break;
                case EVENT_FEL_MORTAR:
                    DoCast(SPELL_FEL_MORTAR);
                    events.RescheduleEvent(EVENT_FEL_MORTAR, 16000);
                    break;
                case EVENT_LASER_BEAM:
                    me->SetReactState(REACT_PASSIVE);
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        DoCast(target, SPELL_SUMMON_LASER_BEAM, true);
                    events.RescheduleEvent(EVENT_LASER_BEAM, 30000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_tirathon_saltherilAI(creature);
    }
};

//96241
class npc_tirathon_beam_target : public CreatureScript
{
public:
    npc_tirathon_beam_target() : CreatureScript("npc_tirathon_beam_target") {}

    struct npc_tirathon_beam_targetAI : public ScriptedAI
    {
        npc_tirathon_beam_targetAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_RUN, 0.5f);
            me->SetSpeed(MOVE_WALK, 0.5f);
        }

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            summoner->CastSpell(me, SPELL_LASER_BEAM_VISUAL, true);
            summoner->CastSpell(me, SPELL_LASER_BEAM_AT, true);

            events.RescheduleEvent(1, 2000);
            events.RescheduleEvent(2, 9000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                {
                    Position pos;
                    me->GetNearPosition(40.0f, frand(0, 6.28f));
                    me->GetMotionMaster()->MovePoint(1, pos);
                    break;
                }
                case 2:
                    if (Unit* owner = me->GetOwner())
                        owner->GetAI()->DoAction(1);
                    me->DespawnOrUnsummon(100);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tirathon_beam_targetAI(creature);
    }
};

//98177
class npc_glayvianna_soulrender : public CreatureScript
{
public:
    npc_glayvianna_soulrender() : CreatureScript("npc_glayvianna_soulrender") {}

    struct npc_glayvianna_soulrenderAI : public ScriptedAI
    {
        npc_glayvianna_soulrenderAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            DoCast(42459);
            DoCast(200888);
            DoCast(204879);
            introDone = false;
        }

        EventMap events;
        bool introDone;
        bool phaseSecond;
        bool phaseThree;

        void EnterCombat(Unit* /*who*/) override
        {
            me->RemoveAurasDueToSpell(200888);
            me->RemoveAurasDueToSpell(204879);
            me->SetDisableGravity(false);
            events.RescheduleEvent(1, 12000);
            events.RescheduleEvent(5, 14000);
            phaseSecond = false;
            phaseThree = false;
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (me->HealthBelowPct(60) && !phaseSecond)
            {
                phaseSecond = true;
                events.RescheduleEvent(2, 0);
                if (Creature* conv = me->SummonCreature(950003, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - 10.0f, me->GetOrientation()))
                {
                  //  Conversation* conversation = new Conversation;
                  //  if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 866, attacker, NULL, *attacker))
                   //     delete conversation;
                    conv->DespawnOrUnsummon();
                }
            }
            if (me->HealthBelowPct(50) && !phaseThree)
            {
                phaseThree = true;
                events.RescheduleEvent(3, 0);
            }
        }

        void JustDied(Unit* killer) override
        {
            if (Creature* conv = me->SummonCreature(950002, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - 10.0f, me->GetOrientation()))
            {
              //  Conversation* conversation = new Conversation;
               // if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 867, killer, NULL, *killer))
               //     delete conversation;
                conv->DespawnOrUnsummon();
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!introDone && me->IsWithinDistInMap(who, 75.0f))
            {
                if (Creature* conv = me->SummonCreature(950002, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - 10.0f, me->GetOrientation()))
                {
                    //Conversation* conversation = new Conversation;
                   // if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 559, who, NULL, *who))
                   //     delete conversation;
                    introDone = true;
                    conv->DespawnOrUnsummon();
                }
            }

            if (!me->IsInCombat() && me->IsWithinDistInMap(who, 35.0f))
                me->AI()->AttackStart(who);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(193607);
                    events.RescheduleEvent(1, 12000);
                    break;
                case 2:
                    DoCast(193502);
                    break;
                case 3:
                    DoCast(193609);
                    events.RescheduleEvent(4, 12000);
                    break;
                case 4:
                    DoCast(193615);
                    events.RescheduleEvent(4, 12000);
                    break;
                case 5:
                    DoCast(193559);
                    DoCast(193578);
                    events.RescheduleEvent(5, 14000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_glayvianna_soulrenderAI(creature);
    }
};

//
class npc_drelanim : public CreatureScript
{
public:
    npc_drelanim() : CreatureScript("npc_drelanim") {}

    struct npc_drelanimAI : public ScriptedAI
    {
        npc_drelanimAI(Creature* creature) : ScriptedAI(creature), timer(0)
        {
            outroScene = false;
        }

        bool outroScene;
        uint32 timer;

        void DoAction(int32 const action) override
        {
            switch (action)
            {
            case 1:
                me->GetMotionMaster()->MoveJump(Position(4244.69f, -428.03f, 259.35f), 20, 25);
                DoCast(194836);
                break;
            case 2:
                Talk(0);
                timer = 5000;
                outroScene = true;
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (outroScene)
            {
                if (timer < diff)
                {
                    Talk(1);
                    outroScene = false;
                }
                else timer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_drelanimAI(creature);
    }
};

//190833
class spell_tirathon_beam_dmg : public SpellScriptLoader
{
public:
    spell_tirathon_beam_dmg() : SpellScriptLoader("spell_tirathon_beam_dmg") { }

    class spell_tirathon_beam_dmg_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_tirathon_beam_dmg_AuraScript);

        uint16 castTimer = 500;

        void OnUpdate(uint32 diff, AuraEffect* /*aurEff*/)
        {
            if (castTimer <= diff)
            {
                castTimer = 500;

                if (GetCaster() && GetTarget())
                    GetCaster()->CastSpell(GetTarget(), SPELL_LASER_BEAM_BETWEEN_DMG, true);
            }
            else
                castTimer -= diff;
        }

        void Register() override
        {
          //  OnEffectUpdate += AuraEffectUpdateFn(spell_tirathon_beam_dmg_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_tirathon_beam_dmg_AuraScript();
    }
};

//191941
class spell_tirathon_darkstrikes : public AuraScript
{
    PrepareAuraScript(spell_tirathon_darkstrikes);

    uint32 procDelay = 0;

    void OnProc(AuraEffect const* /*auraEffect*/, ProcEventInfo& eventInfo)
    {
        if (procDelay)
            PreventDefaultAction();
        else
            procDelay = 1000;
    }

    void OnUpdate(uint32 diff, AuraEffect* /*aurEff*/)
    {
        if (procDelay)
        {
            if (procDelay <= diff)
                procDelay = 0;
            else
                procDelay -= diff;
        }
    }

    void Register() override
    {
       // OnEffectProc += AuraEffectProcFn(spell_tirathon_darkstrikes::OnProc, EFFECT_0, SPELL_AURA_PROC_MELEE_TRIGGER_SPELL);
        //OnEffectUpdate += AuraEffectUpdateFn(spell_tirathon_darkstrikes::OnUpdate, EFFECT_0, SPELL_AURA_PROC_MELEE_TRIGGER_SPELL);
    }
};

//191948
class spell_tirathon_darkstrike : public SpellScript
{
    PrepareSpellScript(spell_tirathon_darkstrike);

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
     //   if (!GetCaster() || !GetHitUnit() || GetHitUnit()->IsActiveMitigation())
        //    return;

        float damage = GetHitDamage();

        if (auto auraEff = GetCaster()->GetAuraEffect(SPELL_DARK_ENERGIES_ABSORB, EFFECT_0))
        {
        //    auraEff->ChangeAmount(auraEff->GetAmount() + damage);
        //    auraEff->GetBase()->SetDuration(auraEff->GetBase()->GetMaxDuration());
        }
        //else
         //   GetCaster()->CastCustomSpell(GetCaster(), SPELL_DARK_ENERGIES_ABSORB, &damage, NULL, NULL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tirathon_darkstrike::HandleDamage, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
    }
};

void AddSC_boss_tirathon_saltheril()
{
    new boss_tirathon_saltheril();
    new npc_tirathon_beam_target();
    new npc_glayvianna_soulrender();
    new npc_drelanim();
    new spell_tirathon_beam_dmg();
    RegisterAuraScript(spell_tirathon_darkstrikes);
    RegisterSpellScript(spell_tirathon_darkstrike);
}
