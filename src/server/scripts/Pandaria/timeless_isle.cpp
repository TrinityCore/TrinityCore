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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "timeless_isle.h"

// Anduin Wrynn - 73061
class npc_prince_anduin : public CreatureScript
{
    public:
        npc_prince_anduin() : CreatureScript("npc_prince_anduin") {}

        struct npc_prince_anduinAI : public ScriptedAI
        {
            npc_prince_anduinAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_PRINCE_TALK_1:
                        Talk(0);
                        break;
                    case ACTION_PRINCE_TALK_2:
                        Talk(1);
                        break;
                    case ACTION_PRINCE_TALK_3:
                        Talk(2);
                        break;
                    case ACTION_PRINCE_TALK_4:
                        Talk(3);
                        break;
                    case ACTION_PRINCE_TALK_5:
                        Talk(4);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_prince_anduinAI(creature);
        }
};

// Kairoz - 72870
class npc_kairoz : public CreatureScript
{
    public:
        npc_kairoz() : CreatureScript("npc_kairoz") {}

        bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/) override
        {
            if (quest->GetQuestId() == QUEST_TIME_KEEPER_KAIROZ_H || quest->GetQuestId() == QUEST_TIME_KEEPER_KAIROZ_A)
            {
                if (creature->IsQuestGiver() && creature->AI())
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->AI()->DoAction(ACTION_CONVERSATION);
                }
            }
            return true;
        }

        struct npc_kairozAI : public ScriptedAI
        {
            npc_kairozAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;
            ObjectGuid playerGUID;
            bool conversationEngaged;

            void Reset() override
            {
                playerGUID = ObjectGuid::Empty;
                conversationEngaged = false;
            }

            void SetGUID(ObjectGuid guid, int32 /*id*/ /*= 0*/) override
            {
                playerGUID = guid;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_KAIROZ_TALK_1:
                        Talk(0);
                        break;
                    case ACTION_KAIROZ_TALK_2:
                        Talk(1);
                        break;
                    case ACTION_KAIROZ_TALK_3:
                        Talk(2);
                        break;
                    case ACTION_KAIROZ_TALK_4:
                        Talk(3);
                        break;
                    case ACTION_KAIROZ_TALK_5:
                        Talk(4);
                        break;
                    case ACTION_CONVERSATION:
                        if (!conversationEngaged)
                        {
                            conversationEngaged = true;
                            events.ScheduleEvent(EVENT_PRINCE_TALK_1, 3000);
                            events.ScheduleEvent(EVENT_KAIROZ_TALK_1, 6000);
                            events.ScheduleEvent(EVENT_PRINCE_TALK_2, 11000);
                            events.ScheduleEvent(EVENT_KAIROZ_TALK_2, 18000);
                            events.ScheduleEvent(EVENT_PRINCE_TALK_3, 25000);
                            events.ScheduleEvent(EVENT_KAIROZ_TALK_3, 32000);
                            events.ScheduleEvent(EVENT_PRINCE_TALK_4, 39000);
                            events.ScheduleEvent(EVENT_KAIROZ_TALK_4, 46000);
                            events.ScheduleEvent(EVENT_KAIROZ_TALK_5, 54000);
                            events.ScheduleEvent(EVENT_PRINCE_TALK_5, 60000);
                        }
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                std::list<Creature*> princeAnduinList;
                GetCreatureListWithEntryInGrid(princeAnduinList, me, NPC_PRINCE_ANDUIN, 7.0f);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PRINCE_TALK_1:
                            if (!princeAnduinList.empty())
                                for (auto princeAnduin : princeAnduinList)
                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_1);
                            break;
                        case EVENT_KAIROZ_TALK_1:
                            DoAction(ACTION_KAIROZ_TALK_1);
                            break;
                        case EVENT_PRINCE_TALK_2:
                            if (!princeAnduinList.empty())
                                for (auto princeAnduin : princeAnduinList)
                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_2);
                            break;
                        case EVENT_KAIROZ_TALK_2:
                            DoAction(ACTION_KAIROZ_TALK_2);
                            break;
                        case EVENT_PRINCE_TALK_3:
                            if (!princeAnduinList.empty())
                                for (auto princeAnduin : princeAnduinList)
                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_3);
                            break;
                        case EVENT_KAIROZ_TALK_3:
                            DoAction(ACTION_KAIROZ_TALK_3);
                            break;
                        case EVENT_PRINCE_TALK_4:
                            if (!princeAnduinList.empty())
                                for (auto princeAnduin : princeAnduinList)
                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_4);
                            break;
                        case EVENT_KAIROZ_TALK_4:
                            DoAction(ACTION_KAIROZ_TALK_4);
                            break;
                        case EVENT_KAIROZ_TALK_5:
                            DoAction(ACTION_KAIROZ_TALK_5);
                            break;
                        case EVENT_PRINCE_TALK_5:
                            if (!princeAnduinList.empty())
                                for (auto princeAnduin : princeAnduinList)
                                {
                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_5);
                                    conversationEngaged = false;
                                }
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kairozAI(creature);
        }
};

class spell_jadefire_bolt : public SpellScriptLoader
{
public:
    spell_jadefire_bolt() : SpellScriptLoader("spell_jadefire_bolt") { }

    class spell_jadefire_bolt_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jadefire_bolt_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 4);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_jadefire_bolt_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
           // OnHit += SpellHitFn(spell_jadefire_bolt_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_jadefire_bolt_SpellScript();
    }
};

class spell_crackling_lightning : public SpellScriptLoader
{
public:
    spell_crackling_lightning() : SpellScriptLoader("spell_crackling_lightning") { }

    class spell_crackling_lightning_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_crackling_lightning_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_crackling_lightning_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
          //  OnHit += SpellHitFn(spell_crackling_lightning_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_crackling_lightning_SpellScript();
    }
};

class spell_chi_barrage : public SpellScriptLoader
{
public:
    spell_chi_barrage() : SpellScriptLoader("spell_chi_barrage") { }

    class spell_chi_barrage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chi_barrage_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 6);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chi_barrage_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
           // OnHit += SpellHitFn(spell_chi_barrage_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_chi_barrage_SpellScript();
    }
};

enum eZarimEvents
{
    QUEST_BONE_APART_INTRO = 33348,
    NPC_ZARIM = 71876,
    SPELL_BONE_APART_INTRO = 149122,
};
// AT - 9211
class at_tom_bone_apart : public AreaTriggerScript
{
public:
    at_tom_bone_apart() : AreaTriggerScript("at_tom_bone_apart") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*enter*/)
    {
        if (Creature* Zarim = GetClosestCreatureWithEntry(player, NPC_ZARIM, 30.0f))
        {
            if (player->GetQuestStatus(QUEST_BONE_APART_INTRO) != QUEST_STATUS_REWARDED)
            {
                player->CastSpell(player, SPELL_BONE_APART_INTRO, true);
                Zarim->AI()->Talk(0);
            }
        }
        return false;
    }
};

class at_ordos_entrance : public AreaTriggerScript
{
public:
    at_ordos_entrance() : AreaTriggerScript("at_ordos_entrance") { }

    bool OnTrigger(Player* pPlayer, const AreaTriggerEntry* /*pAt*/, bool /*enter*/)
    {
        if (pPlayer->IsGameMaster())
            return false;

        // A Pandaren Legend
        if (pPlayer->GetQuestStatus(33104) != QUEST_STATUS_REWARDED && !pPlayer->HasAchieved(8325))
            pPlayer->CastSpell(pPlayer, SPELL_BANISHMENT, true);

        return false;
    }
};

class npc_timeless_spirit : public CreatureScript
{
public:
    npc_timeless_spirit() : CreatureScript("npc_timeless_spirit") {}

    struct npc_timeless_spiritAI : public ScriptedAI
    {
        npc_timeless_spiritAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 SpiritStrangle_timer;

        void Reset()
        {
            SpiritStrangle_timer = 0;
            //me->GetMotionMaster()->MoveRandom(10.0f);
            DoCast(SPELL_GHOSTLY_VOID);
            DoCast(SPELL_DESATURATE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (Unit* pTarget = me->GetVictim())
            {
                if (me->GetDistance(pTarget) >= 15.0f)
                    EnterEvadeMode();

                if (SpiritStrangle_timer <= diff)
                {
                    DoCast(pTarget, SPELL_SPIRIT_STRANGLE);

                    SpiritStrangle_timer = 7000;
                }
                else SpiritStrangle_timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_timeless_spiritAI(creature);
    }
};

class npc_emperor_shaohao : public CreatureScript
{
public:
    npc_emperor_shaohao() : CreatureScript("npc_emperor_shaohao") {}

    struct npc_emperor_shaohaoAI : public ScriptedAI
    {
        npc_emperor_shaohaoAI(Creature* creature) : ScriptedAI(creature), summons(me) {}

        EventMap events;
        SummonList summons;

        void Reset()
        {
            me->SummonCreature(NPC_CHIJI, summonPos[0]);
            me->SummonCreature(NPC_XUEN, summonPos[1]);
            me->SummonCreature(NPC_YULON, summonPos[2]);
            me->SummonCreature(NPC_NIUZAO, summonPos[3]);

            events.RescheduleEvent(urand(EVENT_CHIJI_START, EVENT_NIUZAO_START), 60000);
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
            case ACTION_CHIJI_END:
                events.RescheduleEvent(EVENT_CHIJI_END, 10000);
                break;
            case ACTION_CHIJI_FAIL:
                events.RescheduleEvent(EVENT_CHIJI_START, 30000);
                break;
            case ACTION_XUEN_END:
                events.RescheduleEvent(EVENT_XUEN_END, 10000);
                break;
            case ACTION_XUEN_FAIL:
                events.RescheduleEvent(EVENT_XUEN_START, 30000);
                break;
            case ACTION_YULON_END:
                events.RescheduleEvent(EVENT_YULON_END, 10000);
                break;
            case ACTION_YULON_FAIL:
                events.RescheduleEvent(EVENT_YULON_START, 30000);
                break;
            case ACTION_NIUZAO_END:
                events.RescheduleEvent(EVENT_NIUZAO_END, 10000);
                break;
            case ACTION_NIUZAO_FAIL:
                events.RescheduleEvent(EVENT_NIUZAO_START, 30000);
                break;
            }
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHIJI_START:
                {
                    Talk(SAY_CHIJI_START);
                    EntryCheckPredicate pred1(NPC_CHIJI);
                    summons.DoAction(ACTION_MOVE_CENTR_POSS, pred1);
                    break;
                }
                case EVENT_CHIJI_END:
                    Talk(SAY_CHIJI_FINISH);
                    events.RescheduleEvent(EVENT_XUEN_START, 60000);
                    break;
                case EVENT_XUEN_START:
                {
                    Talk(SAY_XUEN_START);
                    EntryCheckPredicate pred1(NPC_XUEN);
                    summons.DoAction(ACTION_MOVE_CENTR_POSS, pred1);
                    break;
                }
                case EVENT_XUEN_END:
                    Talk(SAY_XUEN_FINISH);
                    events.RescheduleEvent(EVENT_YULON_START, 60000);
                    break;
                case EVENT_YULON_START:
                {
                    Talk(SAY_YULON_START);
                    EntryCheckPredicate pred1(NPC_YULON);
                    summons.DoAction(ACTION_MOVE_CENTR_POSS, pred1);
                    break;
                }
                case EVENT_YULON_END:
                {
                    Talk(SAY_YULON_FINISH);
                    events.RescheduleEvent(EVENT_NIUZAO_START, 60000);
                    break;
                }
                case EVENT_NIUZAO_START:
                {
                    Talk(SAY_NIUZAO_START);
                    EntryCheckPredicate pred1(NPC_NIUZAO);
                    summons.DoAction(ACTION_MOVE_CENTR_POSS, pred1);
                    break;
                }
                case EVENT_NIUZAO_END:
                {
                    Talk(SAY_NIUZAO_FINISH);
                    events.RescheduleEvent(EVENT_CHIJI_START, 60000);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_emperor_shaohaoAI(creature);
    }
};

void AddSC_timeless_isle()
{
    new npc_prince_anduin();
    new npc_kairoz();
    new npc_timeless_spirit();
    new npc_emperor_shaohao();

    //areatrigger
    new at_tom_bone_apart();
    new at_ordos_entrance();
}
