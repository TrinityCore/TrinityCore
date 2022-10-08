/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "court_of_stars.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "court_of_stars.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_ARCANE_LOCKDOWN = 1,
    SAY_SIGNAL = 2,
    SAY_FLASK = 3,
    SAY_DEATH = 4,
};

enum Spells
{
    SPELL_RESONANT_SLASH = 207261,
    SPELL_RESONANT_SLASH_FRONT = 206574,
    SPELL_RESONANT_SLASH_BACK = 206580,
    SPELL_ARCANE_LOCKDOWN = 207278,
    SPELL_SIGNAL_BEACON = 207806,
    SPELL_SUM_VIGILANT_NIGHTWATCH = 210435,
    SPELL_FLASK_SOLEMN_NIGHT = 207815,
    SPELL_STREETSWEEPER = 219488,

    //Guards
    SPELL_HINDER = 215204,

    //Streetsweeper
    SPELL_STREETSWEEPER_VISUAL = 219475,
    SPELL_STREETSWEEPER_VISUAL_BEAM = 219483,
    SPELL_STREETSWEEPER_AT = 219477,

    //Beacon
    SPELL_WATCHPOST_VICINITY = 212479, //?
    SPELL_WATCHPOST_VICINITY_AT = 212480, //?
    SPELL_CAST_DISABLE_BEACON = 210253,
    SPELL_BEACON_DISABLED = 210257,
};

enum eEvents
{
    EVENT_RESONANT_SLASH = 1,
    EVENT_ARCANE_LOCKDOWN = 2,
    EVENT_SIGNAL_BEACON = 3,
    EVENT_FLASK_SOLEMN_NIGHT = 4,
    EVENT_FLASK_SOLEMN_NIGHT_END = 5,
    EVENT_STREETSWEEPER = 6
};

Position const flaskPos = { 1308.29f, 3537.42f, 20.76f };

//104215
class boss_patrol_captain_gerdo : public CreatureScript
{
public:
    boss_patrol_captain_gerdo() : CreatureScript("boss_patrol_captain_gerdo") {}

    struct boss_patrol_captain_gerdoAI : public BossAI
    {
        boss_patrol_captain_gerdoAI(Creature* creature) : BossAI(creature, DATA_CAPTAIN_GERDO) {}

        bool flaskEvent;

        void Reset() override
        {
            _Reset();
            flaskEvent = false;
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
            //06:03
        {
            Talk(SAY_AGGRO);
            _EnterCombat();

            events.RescheduleEvent(EVENT_RESONANT_SLASH, 7000);   //06:10, 06:32, 06:44
            events.RescheduleEvent(EVENT_ARCANE_LOCKDOWN, 15000); //06:18, 06:52, 07:20
            events.RescheduleEvent(EVENT_SIGNAL_BEACON, 23000);   //06:26
            events.RescheduleEvent(EVENT_STREETSWEEPER, 18000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            if (Creature* sayer = me->FindNearestCreature(104694, 250.0f, true))
                sayer->AI()->Talk(0);
        }

        void SpellHit(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_SIGNAL_BEACON)
                instance->SetData(DATA_BEACON_ACTIVATE, IN_PROGRESS);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPct(26) && !flaskEvent)
            {
                flaskEvent = true;
                Talk(SAY_FLASK);
                events.RescheduleEvent(EVENT_FLASK_SOLEMN_NIGHT, 500);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
                events.RescheduleEvent(EVENT_FLASK_SOLEMN_NIGHT_END, 500);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RESONANT_SLASH:
                {
                    DoCast(SPELL_RESONANT_SLASH);
                    float angle = 0.0f;
                    Position pos;
                    me->GetNearPosition(4.0f, angle);
                    if (Creature* frontTrig = me->SummonCreature(NPC_GERDO_TRIG_FRONT, pos))
                    {
                        angle += 3.14f;
                        frontTrig->CastSpell(frontTrig, SPELL_RESONANT_SLASH_FRONT);
                    }
                    me->GetNearPosition(4.0f, angle);
                    if (Creature* backTrig = me->SummonCreature(NPC_GERDO_TRIG_BACK, pos))
                        backTrig->CastSpell(backTrig, SPELL_RESONANT_SLASH_BACK);
                    events.RescheduleEvent(EVENT_RESONANT_SLASH, 12000);
                    break;
                }
                case EVENT_ARCANE_LOCKDOWN:
                    DoCast(SPELL_ARCANE_LOCKDOWN);
                    Talk(SAY_ARCANE_LOCKDOWN);
                    events.RescheduleEvent(EVENT_ARCANE_LOCKDOWN, 28000);
                    break;
                case EVENT_SIGNAL_BEACON:
                    DoCast(SPELL_SIGNAL_BEACON);
                    Talk(SAY_SIGNAL);
                    break;
                case EVENT_FLASK_SOLEMN_NIGHT:
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(1, flaskPos);
                    break;
                case EVENT_FLASK_SOLEMN_NIGHT_END:
                    DoCast(SPELL_FLASK_SOLEMN_NIGHT);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_STREETSWEEPER:
                    DoCast(SPELL_STREETSWEEPER);
                    events.RescheduleEvent(EVENT_STREETSWEEPER, 18000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_patrol_captain_gerdoAI(creature);
    }
};

//104918
class npc_captain_gerdo_vigilant_duskwatch : public CreatureScript
{
public:
    npc_captain_gerdo_vigilant_duskwatch() : CreatureScript("npc_captain_gerdo_vigilant_duskwatch") {}

    struct npc_captain_gerdo_vigilant_duskwatchAI : public ScriptedAI
    {
        npc_captain_gerdo_vigilant_duskwatchAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner) override
        {
            DoZoneInCombat(me, 100.0f);
            events.RescheduleEvent(1, 5000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCastVictim(SPELL_HINDER);
                    events.RescheduleEvent(1, 10000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_captain_gerdo_vigilant_duskwatchAI(creature);
    }
};

//105729
class npc_signal_lantern : public CreatureScript
{
public:
    npc_signal_lantern() : CreatureScript("npc_signal_lantern") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (!player->HasAura(210295))
        {
            //player->ADD_GOSSIP_ITEM_DB(19515, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
           // player->SEND_GOSSIP_MENU(28836, creature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
      //  if (action != GOSSIP_ACTION_INFO_DEF + 1)
            return false;
        player->AddAura(210295, player);
        player->CastSpell(player, 209524);    //213505
       // player->CLOSE_GOSSIP_MENU();

        return true;
    }
};

//
class npc_nightborne_boat : public CreatureScript
{
public:
    npc_nightborne_boat() : CreatureScript("npc_nightborne_boat") {}

    struct npc_nightborne_boatAI : public ScriptedAI
    {
        npc_nightborne_boatAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 timer;
        bool event;

        void IsSummonedBy(Unit* summoner) override
        {
            me->GetMotionMaster()->MovePath(9100402, false);  //213505
            timer = 13000;
            event = false;
        }

        void PassengerBoarded(Unit* player, int8 /* */, bool /* */) override
        {
            if (player->GetTypeId() != TYPEID_PLAYER)
                return;
            me->GetMotionMaster()->MovePath(9100403, false);
            timer = 48000;
            event = true;
            // player->CastSpell(player, 215170, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (timer <= diff)
            {
                if (!event)
                {
                    if (Unit* owner = me->ToTempSummon()->GetSummoner())
                        owner->CastSpell(me, 213507, true);
                }
                else
                {
                    if (Unit* owner = me->ToTempSummon()->GetSummoner())
                        owner->CastSpell(owner, 208703, true);
                    me->DespawnOrUnsummon(3000);
                }
            }
            else timer -= diff;
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nightborne_boatAI(creature);
    }
};

//
class npc_lilet_lunarh : public CreatureScript
{
public:
    npc_lilet_lunarh() : CreatureScript("npc_lilet_lunarh") {}

    struct npc_lilet_lunarhAI : public ScriptedAI
    {
        npc_lilet_lunarhAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 timer;
        uint8 talk;
        bool event;
        Player* owner = nullptr;

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->GetTypeId() == TYPEID_PLAYER)
                owner = summoner->ToPlayer();
            timer = 13000;
            event = true;
            talk = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (event)
                if (talk < 4)
                    if (timer <= diff)
                    {
                        if (owner)
                         //   Talk(talk, owner->GetGUID());
                        talk++;
                        timer = 16000;
                    }
                    else timer -= diff;
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lilet_lunarhAI(creature);
    }
};

//104251
class npc_duskwatch_sentry : public CreatureScript
{
public:
    npc_duskwatch_sentry() : CreatureScript("npc_duskwatch_sentry") {}

    struct npc_duskwatch_sentryAI : public ScriptedAI
    {
        npc_duskwatch_sentryAI(Creature* creature) : ScriptedAI(creature) {}

        void EnterCombat(Unit* who) override
        {
            me->SetReactState(REACT_PASSIVE);
            DoCast(who, 209036);
            Talk(0);
            if (Creature* target = me->FindNearestCreature(104245, 100.0f))
            {
                me->GetMotionMaster()->MovePoint(1, target->GetPositionX() + irand(-7, 7), target->GetPositionY() + irand(-7, 7), target->GetPositionZ());
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
                DoCast(me, 210261); //Alarm TO-DO: Sniff for npc
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_duskwatch_sentryAI(creature);
    }
};

//104245
class npc_gerdo_arcane_beacon : public CreatureScript
{
public:
    npc_gerdo_arcane_beacon() : CreatureScript("npc_gerdo_arcane_beacon") {}

    struct npc_gerdo_arcane_beaconAI : public ScriptedAI
    {
        npc_gerdo_arcane_beaconAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
        }

        void Reset() override {}

        void OnSpellClick(Unit* clicker, bool& result) override
        {
            if (!me->HasAura(SPELL_BEACON_DISABLED))
                clicker->CastSpell(me, SPELL_CAST_DISABLE_BEACON);
        }

        void SpellHit(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_CAST_DISABLE_BEACON)
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                DoCast(me, SPELL_BEACON_DISABLED, true);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gerdo_arcane_beaconAI(creature);
    }
};

//110403
class npc_gerdo_streetsweeper : public CreatureScript
{
public:
    npc_gerdo_streetsweeper() : CreatureScript("npc_gerdo_streetsweeper") {}

    struct npc_gerdo_streetsweeperAI : public ScriptedAI
    {
        npc_gerdo_streetsweeperAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;

        void Reset() override {}

        void EnterCombat(Unit* who) override {}

        void IsSummonedBy(Unit* summoner) override
        {
            DoCast(me, SPELL_STREETSWEEPER_VISUAL, true);
            events.RescheduleEvent(1, 500);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (Unit* owner = me->GetOwner())
                        if (Creature* summoner = owner->ToCreature())
                            if (Unit* target = summoner->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                                me->SetFacingToObject(target);
                    events.RescheduleEvent(2, 500);
                    break;
                case 2:
                    DoCast(me, SPELL_STREETSWEEPER_AT, true);
                    events.RescheduleEvent(3, 2000);
                    break;
                case 3:
                    DoCast(me, SPELL_STREETSWEEPER_VISUAL_BEAM, true);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gerdo_streetsweeperAI(creature);
    }
};

//207278
class spell_patrol_arcane_lockdown : public SpellScriptLoader
{
public:
    spell_patrol_arcane_lockdown() : SpellScriptLoader("spell_patrol_arcane_lockdown") { }

    class spell_patrol_arcane_lockdown_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_patrol_arcane_lockdown_AuraScript);

        uint8 stack = 0;

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (!GetTarget())
                return;

           // if (Aura* aura = GetTarget()->GetAura(GetId()))
                //ura->SetStackAmount(aura->GetStackAmount() + 2);
        }

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            if (Aura* aura = GetTarget()->GetAura(GetId()))
            {
                //stack = aura->GetStackAmount();

              //  if (stack > 1)
                 //   aura->SetStackAmount(stack - 1);
               // else
               //     aurEff->GetBase()->Remove();
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_patrol_arcane_lockdown_AuraScript::OnApply, EFFECT_1, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
            OnEffectProc += AuraEffectProcFn(spell_patrol_arcane_lockdown_AuraScript::OnProc, EFFECT_1, SPELL_AURA_MOD_DECREASE_SPEED);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_patrol_arcane_lockdown_AuraScript();
    }
};

void AddSC_boss_patrol_captain_gerdo()
{
    new boss_patrol_captain_gerdo();
    new npc_captain_gerdo_vigilant_duskwatch();
    new npc_signal_lantern();
    new npc_nightborne_boat();
    new npc_lilet_lunarh();
    new npc_duskwatch_sentry();
    new npc_gerdo_arcane_beacon();
    new npc_gerdo_streetsweeper();
    new spell_patrol_arcane_lockdown();
}
