///*
// * Copyright 2023 AzgathCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "new_karazhan.h"
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_HOLY_BOLT = 1,
//    SAY_SACRED_GROUND = 2,
//    SAY_HOLY_SHOCK = 3,
//    SAY_MASS_REPENTANCE = 4,
//    SAY_MASS_REPENTANCE_WARN = 5,
//    SAY_HOLY_BULWARK = 6,
//    SAY_HOLY_WRATH = 7,
//    SAY_DEATH = 8,
//};
//
//enum Spells
//{
//    SPELL_HOLY_BOLT = 227809,
//    SPELL_SACRED_GROUND = 227789,
//    SPELL_HOLY_SHOCK = 227800,
//    SPELL_MASS_REPENTANCE = 227508,
//    SPELL_HOLY_BULWARK = 227817,
//    SPELL_HOLY_WRATH = 227823,
//};
//
//enum eEvents
//{
//    EVENT_HOLY_BOLT = 1,
//    EVENT_SACRED_GROUND = 2,
//    EVENT_HOLY_SHOCK = 3,
//    EVENT_MASS_REPENTANCE = 4,
//    EVENT_HOLY_BULWARK = 5,
//    EVENT_HOLY_WRATH = 6,
//};
//
////113971
//class boss_maiden_of_virtue_legion : public CreatureScript
//{
//public:
//    boss_maiden_of_virtue_legion() : CreatureScript("boss_maiden_of_virtue_legion") {}
//
//    struct boss_maiden_of_virtue_legionAI : public BossAI
//    {
//        boss_maiden_of_virtue_legionAI(Creature* creature) : BossAI(creature, DATA_MAIDEN_VIRTUE) {}
//
//        void Reset() override
//        {
//            _Reset();
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//            //52:10
//        {
//            Talk(SAY_AGGRO);
//            _JustEngagedWith();
//
//            DefaultEvents();
//        }
//
//        void DefaultEvents()
//        {
//            events.RescheduleEvent(EVENT_HOLY_BOLT, 9000);
//            events.RescheduleEvent(EVENT_SACRED_GROUND, 11000);
//            events.RescheduleEvent(EVENT_HOLY_SHOCK, 16000);
//            events.RescheduleEvent(EVENT_MASS_REPENTANCE, 50000);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            Talk(SAY_DEATH);
//            _JustDied();
//            if (Creature* lotar = me->SummonCreature(115489, -10908.68f, -2063.87f, 92.17f, 5.67f))
//            {
//                lotar->CastSpell(lotar, 229485);
//                lotar->CastSpell(lotar, 231195);
//                lotar->CastSpell(lotar, 231496);
//
//                lotar->GetMotionMaster()->MovePoint(0, -10850.92f, -2106.76f, 92.16f);
//            }
//
//            if (Creature* lleyn = me->SummonCreature(115490, -10907.58f, -2063.87f, 92.17f, 5.67f))
//            {
//                lleyn->CastSpell(lleyn, 229485);
//                lleyn->GetMotionMaster()->MovePoint(0, -10853.09f, -2106.32f, 92.16f);
//            }
//
//            if (Creature* mediv = me->SummonCreature(115487, -10849.59f, -2104.29f, 93.18f, 2.51f))
//            {
//                mediv->CastSpell(mediv, 229594);
//                mediv->CastSpell(mediv, 229596);
//                mediv->CastSpell(mediv, 107674);
//            }
//            Map::PlayerList const& players = me->GetMap()->GetPlayers();
//            if (!players.isEmpty())
//            {
//                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//                {
//                    if (Player* pPlayer = itr->GetSource())
//                        pPlayer->CastSpell(pPlayer, 232516);
//                }
//            }
//        }
//
//
//        void OnSpellFinished(SpellInfo const* spell) override
//        {
//            if (spell->Id == SPELL_MASS_REPENTANCE)
//                events.RescheduleEvent(EVENT_HOLY_BULWARK, 100);
//
//            if (spell->Id == SPELL_HOLY_BULWARK)
//                events.RescheduleEvent(EVENT_HOLY_WRATH, 1000);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_HOLY_BOLT:
//                    if (urand(0, 1))
//                        Talk(SAY_HOLY_BOLT);
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                        DoCast(target, SPELL_HOLY_BOLT, false);
//                    events.RescheduleEvent(EVENT_HOLY_BOLT, 14000);
//                    break;
//                case EVENT_SACRED_GROUND:
//                    if (urand(0, 1))
//                        Talk(SAY_SACRED_GROUND);
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                        DoCast(target, SPELL_SACRED_GROUND, false);
//                    events.RescheduleEvent(EVENT_SACRED_GROUND, 23000);
//                    break;
//                case EVENT_HOLY_SHOCK:
//                    if (urand(0, 1))
//                        Talk(SAY_HOLY_SHOCK);
//                    DoCastVictim(SPELL_HOLY_SHOCK);
//                    events.RescheduleEvent(EVENT_HOLY_SHOCK, 13000);
//                    break;
//                case EVENT_MASS_REPENTANCE:
//                    Talk(SAY_MASS_REPENTANCE);
//                    Talk(SAY_MASS_REPENTANCE_WARN);
//                    events.DelayEvents(6000);
//                    DoCast(SPELL_MASS_REPENTANCE);
//                    events.RescheduleEvent(EVENT_MASS_REPENTANCE, 50000);
//                    break;
//                case EVENT_HOLY_BULWARK:
//                    Talk(SAY_HOLY_BULWARK);
//                    DoCast(SPELL_HOLY_BULWARK);
//                    break;
//                case EVENT_HOLY_WRATH:
//                    Talk(SAY_HOLY_WRATH);
//                    DoCast(SPELL_HOLY_WRATH);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_maiden_of_virtue_legionAI(creature);
//    }
//};
//
//void AddSC_boss_maiden_of_virtue_new()
//{
//    new boss_maiden_of_virtue_legion();
//}
