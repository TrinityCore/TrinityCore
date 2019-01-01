/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "blackwing_lair.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Says
{
   SAY_LINE1                         = 0,
   SAY_LINE2                         = 1,
   SAY_LINE3                         = 2,
   SAY_HALFLIFE                      = 3,
   SAY_KILLTARGET                    = 4
};

enum Gossip
{
   GOSSIP_ID                         = 21334,
};

enum Spells
{
   SPELL_ESSENCEOFTHERED             = 23513,
   SPELL_FLAMEBREATH                 = 23461,
   SPELL_FIRENOVA                    = 23462,
   SPELL_TAILSWIPE                   = 15847,
   SPELL_BURNINGADRENALINE           = 18173,  //Cast this one. It's what 3.3.5 DBM expects.
   SPELL_BURNINGADRENALINE_EXPLOSION = 23478,
   SPELL_CLEAVE                      = 19983   //Chain cleave is most likely named something different and contains a dummy effect
};

enum Events
{
    EVENT_SPEECH_1                  = 1,
    EVENT_SPEECH_2                  = 2,
    EVENT_SPEECH_3                  = 3,
    EVENT_SPEECH_4                  = 4,
    EVENT_ESSENCEOFTHERED           = 5,
    EVENT_FLAMEBREATH               = 6,
    EVENT_FIRENOVA                  = 7,
    EVENT_TAILSWIPE                 = 8,
    EVENT_CLEAVE                    = 9,
    EVENT_BURNINGADRENALINE_CASTER  = 10,
    EVENT_BURNINGADRENALINE_TANK    = 11
};

class boss_vaelastrasz : public CreatureScript
{
public:
    boss_vaelastrasz() : CreatureScript("boss_vaelastrasz") { }

    struct boss_vaelAI : public BossAI
    {
        boss_vaelAI(Creature* creature) : BossAI(creature, DATA_VAELASTRAZ_THE_CORRUPT)
        {
            Initialize();
            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            creature->setFaction(35);
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void Initialize()
        {
            PlayerGUID.Clear();
            HasYelled = false;
        }

        void Reset() override
        {
            _Reset();

            me->SetStandState(UNIT_STAND_STATE_DEAD);
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            DoCast(me, SPELL_ESSENCEOFTHERED);
            me->SetHealth(me->CountPctFromMaxHealth(30));
            // now drop damage requirement to be able to take loot
            me->ResetPlayerDamageReq();

            events.ScheduleEvent(EVENT_CLEAVE, 10000);
            events.ScheduleEvent(EVENT_FLAMEBREATH, 15000);
            events.ScheduleEvent(EVENT_FIRENOVA, 20000);
            events.ScheduleEvent(EVENT_TAILSWIPE, 11000);
            events.ScheduleEvent(EVENT_BURNINGADRENALINE_CASTER, 15000);
            events.ScheduleEvent(EVENT_BURNINGADRENALINE_TANK, 45000);
        }

        void BeginSpeech(Unit* target)
        {
            PlayerGUID = target->GetGUID();
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            events.ScheduleEvent(EVENT_SPEECH_1, 1000);
        }

        void KilledUnit(Unit* victim) override
        {
            if (rand32() % 5)
                return;

            Talk(SAY_KILLTARGET, victim);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            // Speech
            if (!UpdateVictim())
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPEECH_1:
                            Talk(SAY_LINE1);
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            events.ScheduleEvent(EVENT_SPEECH_2, 12000);
                            break;
                        case EVENT_SPEECH_2:
                            Talk(SAY_LINE2);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            events.ScheduleEvent(EVENT_SPEECH_3, 12000);
                            break;
                        case EVENT_SPEECH_3:
                            Talk(SAY_LINE3);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            events.ScheduleEvent(EVENT_SPEECH_4, 16000);
                            break;
                        case EVENT_SPEECH_4:
                            me->setFaction(103);
                            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                                AttackStart(player);
                            break;
                    }
                }
                return;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE:
                        events.ScheduleEvent(EVENT_CLEAVE, 15000);
                        DoCastVictim(SPELL_CLEAVE);
                        break;
                    case EVENT_FLAMEBREATH:
                        DoCastVictim(SPELL_FLAMEBREATH);
                        events.ScheduleEvent(EVENT_FLAMEBREATH, urand(8000, 14000));
                        break;
                    case EVENT_FIRENOVA:
                        DoCastVictim(SPELL_FIRENOVA);
                        events.ScheduleEvent(EVENT_FIRENOVA, 15000);
                        break;
                    case EVENT_TAILSWIPE:
                        //Only cast if we are behind
                        /*if (!me->HasInArc(M_PI, me->GetVictim()))
                        {
                        DoCast(me->GetVictim(), SPELL_TAILSWIPE);
                        }*/
                        events.ScheduleEvent(EVENT_TAILSWIPE, 15000);
                        break;
                    case EVENT_BURNINGADRENALINE_CASTER:
                        {
                            //selects a random target that isn't the current victim and is a mana user (selects mana users) but not pets
                            //it also ignores targets who have the aura. We don't want to place the debuff on the same target twice.
                            if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 1, [&](Unit* u) { return u && !u->IsPet() && u->GetPowerType() == POWER_MANA && !u->HasAura(SPELL_BURNINGADRENALINE); }))
                            {
                                me->CastSpell(target, SPELL_BURNINGADRENALINE, true);
                            }
                        }
                        //reschedule the event
                        events.ScheduleEvent(EVENT_BURNINGADRENALINE_CASTER, 15000);
                        break;
                    case EVENT_BURNINGADRENALINE_TANK:
                        //Vael has to cast it himself; contrary to the previous commit's comment. Nothing happens otherwise.
                        me->CastSpell(me->GetVictim(), SPELL_BURNINGADRENALINE, true);
                        events.ScheduleEvent(EVENT_BURNINGADRENALINE_TANK, 45000);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            // Yell if hp lower than 15%
            if (HealthBelowPct(15) && !HasYelled)
            {
                Talk(SAY_HALFLIFE);
                HasYelled = true;
            }

            DoMeleeAttackIfReady();
        }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == GOSSIP_ID && gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                BeginSpeech(player);
            }
        }

        private:
            ObjectGuid PlayerGUID;
            bool HasYelled;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackwingLairAI<boss_vaelAI>(creature);
    }
};

//Need to define an aurascript for EVENT_BURNINGADRENALINE's death effect.
// 18173 - Burning Adrenaline
class spell_vael_burning_adrenaline : public SpellScriptLoader
{
public:
    spell_vael_burning_adrenaline() : SpellScriptLoader("spell_vael_burning_adrenaline") { }

    class spell_vael_burning_adrenaline_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_vael_burning_adrenaline_AuraScript);

        void OnAuraRemoveHandler(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            //The tooltip says the on death the AoE occurs. According to information: http://qaliaresponse.stage.lithium.com/t5/WoW-Mayhem/Surviving-Burning-Adrenaline-For-tanks/td-p/48609
            //Burning Adrenaline can be survived therefore Blizzard's implementation was an AoE bomb that went off if you were still alive and dealt
            //damage to the target. You don't have to die for it to go off. It can go off whether you live or die.
            GetTarget()->CastSpell(GetTarget(), SPELL_BURNINGADRENALINE_EXPLOSION, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_vael_burning_adrenaline_AuraScript::OnAuraRemoveHandler, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_vael_burning_adrenaline_AuraScript();
    }
};

void AddSC_boss_vaelastrasz()
{
    new boss_vaelastrasz();
    new spell_vael_burning_adrenaline();
}
