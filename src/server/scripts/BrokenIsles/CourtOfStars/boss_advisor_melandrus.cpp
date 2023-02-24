/*
 * Copyright 2023 AzgathCore
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
#include "court_of_stars.h"
#include "ScriptedGossip.h"
#include "Conversation.h"

enum Says
{
    SAY_AGGRO = 2,
    SAY_MAELSTROM = 3,
    SAY_BLADE = 4,
    SAY_KILL = 5,
    SAY_EVADE = 6,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_PIERCING_GALE = 209628,
    SPELL_SLICING_MAELSTROM = 209676,
    SPELL_BLADE_SURGE = 209602,
    SPELL_WIND_IMAGE = 209614,
    SPELL_SLICING_MAELSTROM_2 = 209741, //Image Melandrus cast
    SPELL_ENVELOPING_WINDS_FILTER = 224327,
    SPELL_ENVELOPING_WINDS_AT = 224330,
    SPELL_ENVELOPING_WINDS_STUN = 224333,
};

enum eEvents
{
    EVENT_PIERCING_GALE = 1,
    EVENT_SLICING_MAELSTROM = 2,
    EVENT_BLADE_SURGE = 3,
    EVENT_ENVELOPING_WINDS = 4,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

Position const groupCheckPos[4] =
{
    {938.15f, 3147.17f, 52.24f},  //???? ????
    {931.61f, 3171.08f, 49.57f},  //???? ?????
    {947.74f, 3202.11f, 22.57f},  //??? ?????
    {973.10f, 3166.68f, 22.57f},  //??? ???? 
};

uint32 const pathId[4] =
{
    9100408,
    9100407,
    9100406,
    9100405
};

class boss_advisor_melandrus : public CreatureScript
{
public:
    boss_advisor_melandrus() : CreatureScript("boss_advisor_melandrus") {}

    struct boss_advisor_melandrusAI : public BossAI
    {
        boss_advisor_melandrusAI(Creature* creature) : BossAI(creature, DATA_MELANDRUS)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            elisanda = me->SummonCreature(110443, 871.28f, 3111.11f, 54.93f, 5.87f);
            introDone = false;
            event = false;
            checkrange = true;
            checkrangetimer = 1000;
        }

        Creature* elisanda;
        bool introDone;
        bool event;
        bool queue;
        bool checkrange;
        uint32 checkrangetimer;
        uint32 timer;
        uint8 text;

        void Reset() override
        {
            _Reset();
        }

        void JustEngagedWith(Unit* /*who*/) override
            //48:11
        {
            Talk(SAY_AGGRO);
            _JustEngagedWith();

            events.RescheduleEvent(EVENT_PIERCING_GALE, 6000); //48:17, 48:37, 48:56
            events.RescheduleEvent(EVENT_SLICING_MAELSTROM, 11000); //48:22, 48:43, 49:01
            events.RescheduleEvent(EVENT_BLADE_SURGE, 19000); //48:31, 48:50, 49:09
            events.RescheduleEvent(EVENT_ENVELOPING_WINDS, 10000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) override
        {
            if (event)
                if (elisanda)
                    if (timer <= diff)
                    {
                        if (queue)
                            Talk(text);
                        else
                        {
                            elisanda->AI()->Talk(text);
                            text++;
                        }

                        queue = (queue == true ? false : true);

                        if (text < 2)
                            timer = 5000;
                        else
                        {
                            event = false;
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                            elisanda->DespawnOrUnsummon(100);
                            if (Unit* target = me->SelectNearestPlayer(30.0f))
                                me->AI()->AttackStart(target);
                        }
                    }
                    else timer -= diff;


            if (checkrange)
                if (checkrangetimer <= diff)
                {
                    if (Unit* target = me->SelectNearestPlayer(50.0f))
                        if (me->IsWithinMeleeRange(target))
                        {
                            introDone = true;
                            timer = 1000;
                            text = 0;
                            event = true;
                            queue = true;
                            checkrange = false;
                        }
                    checkrangetimer = 1000;
                }
                else checkrangetimer -= diff;

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PIERCING_GALE:
                {
                    DoCastVictim(SPELL_PIERCING_GALE);
                    EntryCheckPredicate pred(NPC_IMAGE_MELANDRUS);
                    summons.DoAction(EVENT_PIERCING_GALE, pred);
                    events.RescheduleEvent(EVENT_PIERCING_GALE, 20000);
                    break;
                }
                case EVENT_SLICING_MAELSTROM:
                {
                    DoCast(SPELL_SLICING_MAELSTROM);
                    EntryCheckPredicate pred(NPC_IMAGE_MELANDRUS);
                    summons.DoAction(EVENT_SLICING_MAELSTROM, pred);
                    Talk(SAY_MAELSTROM);
                    events.RescheduleEvent(EVENT_SLICING_MAELSTROM, 18000);
                    break;
                }
                case EVENT_BLADE_SURGE:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                        DoCast(pTarget, SPELL_BLADE_SURGE);
                    Talk(SAY_BLADE);
                    events.RescheduleEvent(EVENT_BLADE_SURGE, 19000);
                    break;
                case EVENT_ENVELOPING_WINDS:
                    DoCast(me, SPELL_ENVELOPING_WINDS_FILTER, true);
                    events.RescheduleEvent(EVENT_ENVELOPING_WINDS, 20000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_advisor_melandrusAI(creature);
    }
};

//105754
class npc_image_of_advisor_melandrus : public CreatureScript
{
public:
    npc_image_of_advisor_melandrus() : CreatureScript("npc_image_of_advisor_melandrus") {}

    struct npc_image_of_advisor_melandrusAI : public ScriptedAI
    {
        npc_image_of_advisor_melandrusAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            DoCast(me, SPELL_WIND_IMAGE, true);
        }

        void DoAction(int32 const action) override
        {
            if (action == EVENT_PIERCING_GALE)
                DoCast(SPELL_PIERCING_GALE);

            if (action == EVENT_SLICING_MAELSTROM)
                DoCast(SPELL_SLICING_MAELSTROM_2);
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_image_of_advisor_melandrusAI(creature);
    }
};

// 107435
class npc_suspicious_noble : public CreatureScript
{
public:
    npc_suspicious_noble() : CreatureScript("npc_suspicious_noble") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->HasAura(213213) && !player->HasAura(213304))
        {
            AddGossipItemFor(player, 0, "We are here to help you!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        if (action != GOSSIP_ACTION_INFO_DEF + 1)
            return false;

        if (creature->GetGUID() == creature->GetInstanceScript()->GetGuidData(107435))
        {
            creature->AI()->Talk(1, player);
            CAST_AI(npc_suspicious_noble::npc_suspicious_nobleAI, (creature->AI()))->start = true;
            creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }
        else
        {
            creature->AI()->Talk(0, player);
            player->AddAura(213304, player);
        }
        return true;
    }

    struct npc_suspicious_nobleAI : public ScriptedAI
    {
        npc_suspicious_nobleAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_WALK, 2.0f);
            instance = me->GetInstanceScript();
            if (me->GetGUID() == instance->GetGuidData(107435) && instance->GetBossState(DATA_MELANDRUS_EVENT) != DONE)
                instance->SetBossState(DATA_MELANDRUS_EVENT, NOT_STARTED);
        }

        InstanceScript* instance;
        EventMap events;
        uint32 Path;
        uint32 pointchek;

        bool start = false;
        uint32 starttimer = 1000;

        void Reset() override {}

        void JustEngagedWith(Unit* who) override
        {
            Talk(2);
            me->SetDisplayId(66917);
            events.RescheduleEvent(EVENT_1, 3000); // 214688 25
            events.RescheduleEvent(EVENT_2, 9000); // 214690
            events.RescheduleEvent(EVENT_3, 16000); // 214692
        }

        void JustDied(Unit* who) override
        {
            instance->SetBossState(DATA_MELANDRUS_EVENT, DONE);
            instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 219722);
        }

        void UpdateAI(uint32 diff) override
        {
            if (start)
            {
                if (starttimer <= diff)
                {
                    if (me->GetPositionZ() > 48.0f)
                    {
                        if (me->GetPositionY() > 3160.80f)
                            Path = 9100407;
                        else
                            Path = 9100408;
                    }
                    else
                    {
                        if (me->GetPositionY() > 3189.18f)
                            Path = 9100406;
                        else
                            Path = 9100405;
                    }

                    me->GetMotionMaster()->MovePath(Path, false);

                    switch (Path)
                    {
                    case 9100405:
                        pointchek = 19;
                        break;
                    case 9100406:
                        pointchek = 18;
                        break;
                    case 9100407:
                    case 9100408:
                        pointchek = 9;
                        break;
                    default:
                        break;
                    }
                    start = false;

                }
                else starttimer -= diff;
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
                case EVENT_1:
                    DoCast(214688);
                    events.RescheduleEvent(EVENT_1, 25000); // 214688 25
                    break;
                case EVENT_2:
                    DoCast(214690);
                    events.RescheduleEvent(EVENT_2, 25000); // 214690
                    break;
                case EVENT_3:
                    DoCast(214692);
                    events.RescheduleEvent(EVENT_3, 25000); // 214692
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_suspicious_nobleAI(creature);
    }
};

//
class npc_advisor_hall_checker : public CreatureScript
{
public:
    npc_advisor_hall_checker() : CreatureScript("npc_advisor_hall_checker") {}

    struct npc_advisor_hall_checkerAI : public ScriptedAI
    {
        npc_advisor_hall_checkerAI(Creature* creature) : ScriptedAI(creature)
        {
            _conversation = false;
        }

        bool _conversation;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->IsWithinDistInMap(who, 20.0f))
            {
                if (!who->HasAura(213213))
                {
                    who->CastSpell(who, 213233, true);
                    return;
                }

                if (!_conversation)
                {
                    _conversation = true;
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_advisor_hall_checkerAI(creature);
    }
};

//112687
class npc_advisor_enveloping_winds : public CreatureScript
{
public:
    npc_advisor_enveloping_winds() : CreatureScript("npc_advisor_enveloping_winds") {}

    struct npc_advisor_enveloping_windsAI : public ScriptedAI
    {
        npc_advisor_enveloping_windsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_RUN, 0.15f);
            me->SetSpeed(MOVE_WALK, 0.15f);
        }

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            events.RescheduleEvent(EVENT_1, 500);
            events.RescheduleEvent(EVENT_2, 5000);
        }

        void OnSpellFinished(SpellInfo const* spellInfo) override
        {
            switch (spellInfo->Id)
            {
            case SPELL_ENVELOPING_WINDS_STUN:
                me->DespawnOrUnsummon(1000);
                break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
                events.RescheduleEvent(EVENT_2, 1000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    DoCast(me, SPELL_ENVELOPING_WINDS_AT, true);
                    break;
                case EVENT_2:
                    if (Unit* summoner = me->GetOwner())
                        if (Unit* target = summoner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                            me->GetMotionMaster()->MovePoint(1, target->GetPosition());
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_advisor_enveloping_windsAI(creature);
    }
};

// 213304
class spell_righteous_indignation : public SpellScriptLoader
{
public:
    spell_righteous_indignation() : SpellScriptLoader("spell_righteous_indignation") {}

    class spell_righteous_indignation_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_righteous_indignation_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            target->RemoveAura(213213);
            target->CastSpell(target, 213233, true);

        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_righteous_indignation_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_righteous_indignation_AuraScript();
    }
};


void AddSC_boss_advisor_melandrus()
{
    new boss_advisor_melandrus();
    new npc_image_of_advisor_melandrus();
    new npc_suspicious_noble();
    new npc_advisor_hall_checker();
    new npc_advisor_enveloping_winds();
    new spell_righteous_indignation();
}
