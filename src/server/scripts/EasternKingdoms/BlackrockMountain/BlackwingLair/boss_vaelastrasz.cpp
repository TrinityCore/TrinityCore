/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "blackwing_lair.h"
#include "ScriptedGossip.h"
#include "Player.h"

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
   SPELL_BURNINGADRENALINE           = 23620,
   SPELL_CLEAVE                      = 20684   //Chain cleave is most likely named something different and contains a dummy effect
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
        boss_vaelAI(Creature* creature) : BossAI(creature, BOSS_VAELASTRAZ)
        {
            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            creature->setFaction(35);
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void Reset() override
        {
            _Reset();

            me->SetStandState(UNIT_STAND_STATE_DEAD);
            PlayerGUID = 0;

            HasYelled = false;
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
            if (rand()%5)
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
                            Unit* target = NULL;

                            uint8 i = 0;
                            while (i < 3)   // max 3 tries to get a random target with power_mana
                            {
                                ++i;
                                target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true); // not aggro leader
                                if (target && target->getPowerType() == POWER_MANA)
                                    i = 3;
                            }
                            if (target)                                     // cast on self (see below)
                                target->CastSpell(target, SPELL_BURNINGADRENALINE, true);
                        }
                        events.ScheduleEvent(EVENT_BURNINGADRENALINE_CASTER, 15000);
                        break;
                    case EVENT_BURNINGADRENALINE_TANK:
                        // have the victim cast the spell on himself otherwise the third effect aura will be applied to Vael instead of the player
                        me->EnsureVictim()->CastSpell(me->GetVictim(), SPELL_BURNINGADRENALINE, true);
                        events.ScheduleEvent(EVENT_BURNINGADRENALINE_TANK, 45000);
                        break;
                }
            }

            // Yell if hp lower than 15%
            if (HealthBelowPct(15) && !HasYelled)
            {
                Talk(SAY_HALFLIFE);
                HasYelled = true;
            }

            DoMeleeAttackIfReady();
        }

        void sGossipSelect(Player* player, uint32 sender, uint32 action) override
        {
            if (sender == GOSSIP_ID && action == 0)
            {
                player->CLOSE_GOSSIP_MENU();
                BeginSpeech(player);
            }
        }

        private:
            uint64 PlayerGUID;
            bool HasYelled;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_vaelAI(creature);
    }
};

void AddSC_boss_vaelastrasz()
{
    new boss_vaelastrasz();
}
