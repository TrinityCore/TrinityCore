/*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"
#include "PhasingHandler.h"

enum MardumBroadcastTexts
{
    CREATURE_TEXT_ZERO,
    CREATURE_TEXT_ONE,
    CREATURE_TEXT_TWO,
};

enum MardumQuests
{
    QUEST_ENTER_THE_ILLIDARI_ASHTONGUE = 40378,
    QUEST_ENTER_THE_ILLIDARI_COILSKAR  = 40379,
    QUEST_ENTER_THE_ILLIDARI_SHIVARRA  = 38765,
    QUEST_EYE_ON_THE_PRIZE             = 39049,
    QUEST_BEFORE_WE_RE_OVERRUN         = 38766,
    QUEST_GIVE_ME_SIGHT_BEYOND_SIGHT   = 39262,
    QUEST_HIDDEN_NO_MORE               = 39495,
    QUEST_THE_INVASION_BEGINS          = 40077,
    QUEST_SET_THEM_FREE                = 38759
};

enum MardumQuestObjectives
{
    OBJECTIVE_FIRST_SUMMONED_GUARDIAN_ASHTONGUE = 280769,
    OBJECTIVE_FIRST_SUMMONED_GUARDIAN_COILSKAR  = 280773,
    OBJECTIVE_FIRST_SUMMONED_GUARDIAN_SHIVARRA  = 280115,
    OBJECTIVE_FIND_ALLARI                       = 281030,
    OBJECTIVE_BELATH_DAWNBLADE_GREET            = 280164,
    OBJECTIVE_CYANA_FREED                       = 280293,
    OBJECTIVE_BELATH_FREED                      = 278928,
    OBJECTIVE_IZAL_FREED                        = 278929,
    OBJECTIVE_MANNETHREL_FREED                  = 280293,
};

enum MardumCreatures
{
    CREATURE_FIRST_SUMMONED_GUARDIAN     = 97831,
    CREATURE_ALLARI_THE_SOULEATER        = 94410,
    CREATURE_ASHTONGUE_MYSTIC            = 99914,
    CREATURE_COLOSSAL_ELEMENTAL          = 96159,
    CREATURE_EYE_ON_THE_PRIZE_CREDIT     = 105946,
    CREATURE_BEFORE_WE_RE_OVERRUN_CREDIT = 106003,
    CREATURE_SEVIS_BRIGHTFLAME           = 99915,
    CREATURE_BELATH_DAWNBLADE            = 96654,
    CREATURE_LADY_STHENO                 = 93693,
    CREATURE_MATRON_MOTHER_MALEVOLENCE   = 94435,
    CREATURE_BATTLELORD_GAARDOUN         = 90247,
    CREATURE_JACE_DARKWEAVER             = 96436,
    CREATURE_SPECTRAL_SIGHT_KILL_CREDIT  = 96437
};

enum MardumSpells
{
    SPELL_SACRIFICING_MYSTICS_SOUL       = 196724,
    SPELL_EYE_BEAM                       = 198013,
    SPELL_LEARN_EYE_BEAM                 = 195447,
    SPELL_CONSUME_MAGIC                  = 183752,
    SPELL_LEARN_CONSUME_MAGIC            = 195439,
    SPELL_SEVIS_SACRIFICE_ME             = 196735,
    SPELL_SACRIFICING_SEVIS              = 196731,
    SPELL_COILSKAR_SCENE                 = 191400,
    SPELL_SHIVARRA_SCENE                 = 191402,
    SPELL_ASHTONGUE_SCENE                = 191315,
    SPELL_SPECTRAL_SIGHT                 = 188501,
    SPELL_SPECTRAL_SIGHT_PERIODIC        = 191095,
    SPELL_SPECTRAL_SIGHT_PERIODIC_CANCEL = 191096

};

enum MardumPaths
{
    SEVIS_ASHTONGUE_PATH = 999160,
    SEVIS_COILSKAR_PATH  = 1009820,
};

enum Events
{
    EVENT_TALK = 1,
    EVENT_MOUNT_UP,
    EVENT_START_MOVE,
    EVENT_ERASE
};

enum Mounts
{
    SEVIS_MOUNT = 64385,
};

class npc_sevis_brightflame_1 : public CreatureScript
{
public:
    npc_sevis_brightflame_1() : CreatureScript("npc_sevis_brightflame_1") { }

    struct npc_sevis_brightflame_1AI : public ScriptedAI
    {
        npc_sevis_brightflame_1AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (me->IsWithinDistInMap(who, 15.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) == QUEST_STATUS_INCOMPLETE)
                {
                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_FIRST_SUMMONED_GUARDIAN_ASHTONGUE);
                    if (!obj)
                        return;
                    
                    if (!player->IsQuestObjectiveComplete(*obj))
                    {
                        Talk(CREATURE_TEXT_ZERO, who);
                        player->KilledMonsterCredit(CREATURE_FIRST_SUMMONED_GUARDIAN);                        
                    }
                }
        }

        void IsSummonedBy(Unit* who) override
        {
            _events.ScheduleEvent(EVENT_TALK, 700);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TALK:
                    Talk(CREATURE_TEXT_ONE, me->GetOwner());
                    _events.ScheduleEvent(EVENT_MOUNT_UP, 1500);
                    break;
                case EVENT_MOUNT_UP:
                    me->SendPlaySpellVisualKit(36264, 0, 0);
                    me->Mount(SEVIS_MOUNT);
                    me->SetSpeed(MOVE_RUN, 7);                    
                    _events.ScheduleEvent(EVENT_START_MOVE, 1000);
                    break;
                case EVENT_START_MOVE:
                    me->GetMotionMaster()->MovePath(SEVIS_ASHTONGUE_PATH, false);
                default:
                    break;
                }
            }

            // no melee attacks
        }
    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sevis_brightflame_1AI(creature);
    }
};

class npc_sevis_brightflame_2 : public CreatureScript
{
public:
    npc_sevis_brightflame_2() : CreatureScript("npc_sevis_brightflame_2") { }

    struct npc_sevis_brightflame_2AI : public ScriptedAI
    {
        npc_sevis_brightflame_2AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (me->IsWithinDistInMap(who, 15.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_COILSKAR) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_COILSKAR) == QUEST_STATUS_INCOMPLETE)
                {
                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_FIRST_SUMMONED_GUARDIAN_COILSKAR);
                    if (!obj)
                        return;
                    
                    if (!player->IsQuestObjectiveComplete(*obj))
                    {
                        Talk(CREATURE_TEXT_ZERO, who);
                        Talk(CREATURE_TEXT_ONE, who);
                        player->KilledMonsterCredit(CREATURE_FIRST_SUMMONED_GUARDIAN);
                    }
                }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sevis_brightflame_2AI(creature);
    }
};

class npc_sevis_brightflame_3 : public CreatureScript
{
public:
    npc_sevis_brightflame_3() : CreatureScript("npc_sevis_brightflame_3") { }

    struct npc_sevis_brightflame_3AI : public ScriptedAI
    {
        npc_sevis_brightflame_3AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (me->IsWithinDistInMap(who, 15.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_SHIVARRA) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_SHIVARRA) == QUEST_STATUS_INCOMPLETE)
                {
                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_FIRST_SUMMONED_GUARDIAN_SHIVARRA);
                    if (!obj)
                        return;

                    if (!player->IsQuestObjectiveComplete(*obj))
                    {
                        Talk(CREATURE_TEXT_ZERO, who);
                        player->KilledMonsterCredit(CREATURE_FIRST_SUMMONED_GUARDIAN);
                    }

                }
        }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == 19133 && gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                // Personal Spawn Part Missing
                player->CastSpell(me->ToCreature(), SPELL_SACRIFICING_SEVIS);
            }

            if (menuId == 19132 && gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                // Personal Spawn Part Missing
                player->CastSpell(player, SPELL_SEVIS_SACRIFICE_ME);
            }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sevis_brightflame_3AI(creature);
    }
};

class npc_sevis_brightflame_4 : public CreatureScript
{
public:
    npc_sevis_brightflame_4() : CreatureScript("npc_sevis_brightflame_4") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_ENTER_THE_ILLIDARI_COILSKAR)
        {
            if (creature == nullptr)
                return false;

            player->SummonCreature(100982, creature->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 13000);
            PhasingHandler::OnConditionChange(player);
        }

        return true;
    }

    struct npc_sevis_brightflame_4AI : public ScriptedAI
    {
        npc_sevis_brightflame_4AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void IsSummonedBy(Unit* who) override
        {
            _events.ScheduleEvent(EVENT_TALK, 1000);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TALK:
                    Talk(CREATURE_TEXT_ZERO, me->GetOwner());
                    _events.ScheduleEvent(EVENT_MOUNT_UP, 1500);
                    break;
                case EVENT_MOUNT_UP:
                    me->SendPlaySpellVisualKit(36264, 0, 0);
                    me->Mount(SEVIS_MOUNT);
                    me->SetSpeedRate(MOVE_RUN, 2);
                    _events.ScheduleEvent(EVENT_START_MOVE, 1000);
                    break;
                case EVENT_START_MOVE:
                    me->GetMotionMaster()->MovePath(SEVIS_COILSKAR_PATH, false);
                default:
                    break;
                }
            }

            // no melee attacks
        }
    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sevis_brightflame_4AI(creature);
    }
};

class npc_kayn_sunfury1 : public CreatureScript
{
public:
    npc_kayn_sunfury1() : CreatureScript("npc_kayn_sunfury1") { }

    bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*item*/) override
    {
        if (quest->GetQuestId() == QUEST_THE_INVASION_BEGINS)
        {
            player->AddQuest(sObjectMgr->GetQuestTemplate(39279), nullptr);
        }

        return true;
    }

    struct npc_kayn_sunfury1AI : public ScriptedAI
    {
        npc_kayn_sunfury1AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kayn_sunfury1AI(creature);
    }
};

class npc_allari_the_souleater_1 : public CreatureScript
{
public:
    npc_allari_the_souleater_1() : CreatureScript("npc_allari_the_souleater_1") { }

    struct npc_allari_the_souleater_1AI : public ScriptedAI
    {
        npc_allari_the_souleater_1AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            _talkedTo.clear();
        }

        void EraseFromTalkedToMap(int32 diff) // diff = time after it's removed
        {
            for (std::map<ObjectGuid, time_t>::iterator itr = _talkedTo.begin(); itr != _talkedTo.end(); ++itr)
            {
                if (sWorld->GetGameTime() - itr->second > diff)
                    _talkedTo.erase(itr->first);
            }
        }

        void Initialize()
        {
            _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
        }

        void Reset() override
        {
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (me->IsWithinDistInMap(who, 50.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) && !player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) == QUEST_STATUS_NONE)
                {
                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_FIND_ALLARI);
                    if (!obj)
                        return;
                    
                    if (!player->IsQuestObjectiveComplete(*obj))
                        player->KilledMonsterCredit(CREATURE_ALLARI_THE_SOULEATER);

                    if (me->IsWithinDistInMap(who, 25.0f))
                    {
                        if (!_talkedTo[player->GetGUID()] || sWorld->GetGameTime() - _talkedTo[player->GetGUID()] > 1 * HOUR)
                        {
                            _talkedTo[player->GetGUID()] = sWorld->GetGameTime();
                            Talk(CREATURE_TEXT_ZERO, who);
                        }
                    }
                }
            }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ERASE:
                    EraseFromTalkedToMap(1 * HOUR);
                    _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        std::map<ObjectGuid, time_t> _talkedTo;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_allari_the_souleater_1AI(creature);
    }
};

class npc_ashtongue_mystic_sacrifice : public CreatureScript
{
public:
    npc_ashtongue_mystic_sacrifice() : CreatureScript("npc_ashtongue_mystic_sacrifice") { }

    struct npc_ashtongue_mystic_sacrificeAI : public ScriptedAI
    {
        npc_ashtongue_mystic_sacrificeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                // Personal Spawn Part Missing
                player->CastSpell(player, SPELL_SACRIFICING_MYSTICS_SOUL);
            }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ashtongue_mystic_sacrificeAI(creature);
    }
};

class npc_inquisitor_baleful : public CreatureScript
{
public:
    npc_inquisitor_baleful() : CreatureScript("npc_inquisitor_baleful") { }

    struct npc_inquisitor_balefulAI : public ScriptedAI
    {
        npc_inquisitor_balefulAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override 
        { 
            Talk(CREATURE_TEXT_ZERO);
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void JustDied(Unit* killer) override
        {
            Talk(CREATURE_TEXT_ONE);

            if (Player* player = killer->ToPlayer())
                if (!player->HasSpell(SPELL_EYE_BEAM) && !player->GetQuestRewardStatus(QUEST_EYE_ON_THE_PRIZE) && player->GetQuestStatus(QUEST_EYE_ON_THE_PRIZE) == QUEST_STATUS_INCOMPLETE)
                {
                    // must be different
                    player->CastSpell(player, SPELL_LEARN_EYE_BEAM);
                    player->KilledMonsterCredit(CREATURE_COLOSSAL_ELEMENTAL);
                    player->KilledMonsterCredit(CREATURE_EYE_ON_THE_PRIZE_CREDIT);
                }
        }

        void UpdateAI(uint32 diff) override
        {
            // Totaly missing yet
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_inquisitor_balefulAI(creature);
    }
};

class npc_doom_commander_beliash : public CreatureScript
{
public:
    npc_doom_commander_beliash() : CreatureScript("npc_doom_commander_beliash") { }

    struct npc_doom_commander_beliashAI : public ScriptedAI
    {
        npc_doom_commander_beliashAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(CREATURE_TEXT_ZERO);
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void JustDied(Unit* killer) override
        {
            Talk(CREATURE_TEXT_ONE);

            if (Player* player = killer->ToPlayer())
                if (!player->HasSpell(SPELL_CONSUME_MAGIC) && !player->GetQuestRewardStatus(QUEST_BEFORE_WE_RE_OVERRUN) && player->GetQuestStatus(QUEST_BEFORE_WE_RE_OVERRUN) == QUEST_STATUS_INCOMPLETE)
                {
                    // must be different
                    player->CastSpell(player, SPELL_LEARN_CONSUME_MAGIC);
                    player->KilledMonsterCredit(CREATURE_BEFORE_WE_RE_OVERRUN_CREDIT);
                }
        }

        void UpdateAI(uint32 diff) override
        {
            // Totaly missing yet
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_doom_commander_beliashAI(creature);
    }
};

class npc_belath_dawnblade : public CreatureScript
{
public:
    npc_belath_dawnblade() : CreatureScript("npc_belath_dawnblade") { }

    struct npc_belath_dawnbladeAI : public ScriptedAI
    {
        npc_belath_dawnbladeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (me->IsWithinDistInMap(who, 15.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_SHIVARRA) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_SHIVARRA) == QUEST_STATUS_INCOMPLETE)
                {

                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_BELATH_DAWNBLADE_GREET);
                    if (!obj)
                        return;
                    
                    if (!player->IsQuestObjectiveComplete(*obj))
                    {
                        Talk(CREATURE_TEXT_ZERO, who);
                        player->KilledMonsterCredit(CREATURE_BELATH_DAWNBLADE);
                    }
                    
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_belath_dawnbladeAI(creature);
    }
};


class npc_lady_stheno : public CreatureScript
{
public:
    npc_lady_stheno() : CreatureScript("npc_lady_stheno") { }

    struct npc_lady_sthenoAI : public ScriptedAI
    {
        npc_lady_sthenoAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                // Personal Spawn Part Missing
                player->KilledMonsterCredit(CREATURE_LADY_STHENO);
                PhasingHandler::OnConditionChange(player);
                player->CastSpell(player, SPELL_COILSKAR_SCENE, true);
            }
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            // PersonalSpawn Part here
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lady_sthenoAI(creature);
    }
};

class npc_matron_mother_malevolence : public CreatureScript
{
public:
    npc_matron_mother_malevolence() : CreatureScript("npc_matron_mother_malevolence") { }

    struct npc_matron_mother_malevolenceAI : public ScriptedAI
    {
        npc_matron_mother_malevolenceAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                // Personal Spawn Part Missing
                player->KilledMonsterCredit(CREATURE_MATRON_MOTHER_MALEVOLENCE);
                PhasingHandler::OnConditionChange(player);
                player->CastSpell(player, SPELL_SHIVARRA_SCENE, true);
            }
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            // PersonalSpawn Part here
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_matron_mother_malevolenceAI(creature);
    }
};

class npc_battlelord_gaardoun : public CreatureScript
{
public:
    npc_battlelord_gaardoun() : CreatureScript("npc_battlelord_gaardoun") { }

    struct npc_battlelord_gaardounAI : public ScriptedAI
    {
        npc_battlelord_gaardounAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                // Personal Spawn Part Missing
                player->KilledMonsterCredit(CREATURE_BATTLELORD_GAARDOUN);
                PhasingHandler::OnConditionChange(player);
                player->CastSpell(player, SPELL_ASHTONGUE_SCENE, true);
            }
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            // PersonalSpawn Part here
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_battlelord_gaardounAI(creature);
    }
};

class npc_jace_darkweaver : public CreatureScript
{
public:
    npc_jace_darkweaver() : CreatureScript("npc_jace_darkweaver") { }

    struct npc_jace_darkweaverAI : public ScriptedAI
    {
        npc_jace_darkweaverAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                Talk(CREATURE_TEXT_ZERO, player);
                player->KilledMonsterCredit(CREATURE_JACE_DARKWEAVER);

                if (player->GetSpellHistory()->HasCooldown(SPELL_SPECTRAL_SIGHT))
                    player->GetSpellHistory()->ResetCooldown(SPELL_SPECTRAL_SIGHT, true);

                if (!player->HasAura(SPELL_SPECTRAL_SIGHT_PERIODIC))
                    player->AddAura(SPELL_SPECTRAL_SIGHT_PERIODIC, player);
            }
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            // PersonalSpawn Part here
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_HIDDEN_NO_MORE)
        {
            PhasingHandler::OnConditionChange(player);
            //Personal Spawn Start
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_jace_darkweaverAI(creature);
    }
};

class npc_cyana_nightglaive_cage : public CreatureScript
{
public:
    npc_cyana_nightglaive_cage() : CreatureScript("npc_cyana_nightglaive_cage") { }

    struct npc_cyana_nightglaive_cageAI : public ScriptedAI
    {
        npc_cyana_nightglaive_cageAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            _talkedTo.clear();
        }

        void EraseFromTalkedToMap(int32 diff) // diff = time after it's removed
        {
            for (std::map<ObjectGuid, time_t>::iterator itr = _talkedTo.begin(); itr != _talkedTo.end(); ++itr)
            {
                if (sWorld->GetGameTime() - itr->second > diff)
                    _talkedTo.erase(itr->first);
            }
        }

        void Initialize()
        {
            _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (me->IsWithinDistInMap(who, 10.0f) && !player->GetQuestRewardStatus(QUEST_SET_THEM_FREE) && !player->GetQuestStatus(QUEST_SET_THEM_FREE) == QUEST_STATUS_NONE)
                {
                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_CYANA_FREED);
                    if (!obj)
                        return;

                    if (!player->IsQuestObjectiveComplete(*obj))
                    {
                        if (!_talkedTo[player->GetGUID()] || sWorld->GetGameTime() - _talkedTo[player->GetGUID()] > 1 * HOUR)
                        {
                            _talkedTo[player->GetGUID()] = sWorld->GetGameTime();
                            Talk(CREATURE_TEXT_ZERO, who);
                        }
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ERASE:
                    EraseFromTalkedToMap(1 * HOUR);
                    _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        std::map<ObjectGuid, time_t> _talkedTo;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cyana_nightglaive_cageAI(creature);
    }
};

class npc_belath_dawnblade_cage : public CreatureScript
{
public:
    npc_belath_dawnblade_cage() : CreatureScript("npc_belath_dawnblade_cage") { }

    struct npc_belath_dawnblade_cageAI : public ScriptedAI
    {
        npc_belath_dawnblade_cageAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            _talkedTo.clear();
        }

        void EraseFromTalkedToMap(int32 diff) // diff = time after it's removed
        {
            for (std::map<ObjectGuid, time_t>::iterator itr = _talkedTo.begin(); itr != _talkedTo.end(); ++itr)
            {
                if (sWorld->GetGameTime() - itr->second > diff)
                    _talkedTo.erase(itr->first);
            }
        }

        void Initialize()
        {
            _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (me->IsWithinDistInMap(who, 20.0f) && !player->GetQuestRewardStatus(QUEST_SET_THEM_FREE) && !player->GetQuestStatus(QUEST_SET_THEM_FREE) == QUEST_STATUS_NONE)
                {
                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_BELATH_FREED);
                    if (!obj)
                        return;

                    if (!player->IsQuestObjectiveComplete(*obj))
                    {
                        if (!_talkedTo[player->GetGUID()] || sWorld->GetGameTime() - _talkedTo[player->GetGUID()] > 1 * HOUR)
                        {
                            _talkedTo[player->GetGUID()] = sWorld->GetGameTime();
                            Talk(CREATURE_TEXT_ZERO, who);
                        }
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ERASE:
                    EraseFromTalkedToMap(1 * HOUR);
                    _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        std::map<ObjectGuid, time_t> _talkedTo;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_belath_dawnblade_cageAI(creature);
    }
};

class npc_izal_whitemoon_cage : public CreatureScript
{
public:
    npc_izal_whitemoon_cage() : CreatureScript("npc_izal_whitemoon_cage") { }

    struct npc_izal_whitemoon_cageAI : public ScriptedAI
    {
        npc_izal_whitemoon_cageAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            _talkedTo.clear();
        }

        void EraseFromTalkedToMap(int32 diff) // diff = time after it's removed
        {
            for (std::map<ObjectGuid, time_t>::iterator itr = _talkedTo.begin(); itr != _talkedTo.end(); ++itr)
            {
                if (sWorld->GetGameTime() - itr->second > diff)
                    _talkedTo.erase(itr->first);
            }
        }

        void Initialize()
        {
            _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (me->IsWithinDistInMap(who, 35.0f) && !player->GetQuestRewardStatus(QUEST_SET_THEM_FREE) && !player->GetQuestStatus(QUEST_SET_THEM_FREE) == QUEST_STATUS_NONE)
                {
                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_IZAL_FREED);
                    if (!obj)
                        return;

                    if (!player->IsQuestObjectiveComplete(*obj))
                    {
                        if (!_talkedTo[player->GetGUID()] || sWorld->GetGameTime() - _talkedTo[player->GetGUID()] > 1 * HOUR)
                        {
                            _talkedTo[player->GetGUID()] = sWorld->GetGameTime();
                            Talk(CREATURE_TEXT_ZERO, who);
                        }
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ERASE:
                    EraseFromTalkedToMap(1 * HOUR);
                    _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        std::map<ObjectGuid, time_t> _talkedTo;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_izal_whitemoon_cageAI(creature);
    }
};

class npc_mannethrel_darkstar_cage : public CreatureScript
{
public:
    npc_mannethrel_darkstar_cage() : CreatureScript("npc_mannethrel_darkstar_cage") { }

    struct npc_mannethrel_darkstar_cageAI : public ScriptedAI
    {
        npc_mannethrel_darkstar_cageAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            _talkedTo.clear();
        }

        void EraseFromTalkedToMap(int32 diff) // diff = time after it's removed
        {
            for (std::map<ObjectGuid, time_t>::iterator itr = _talkedTo.begin(); itr != _talkedTo.end(); ++itr)
            {
                if (sWorld->GetGameTime() - itr->second > diff)
                    _talkedTo.erase(itr->first);
            }
        }

        void Initialize()
        {
            _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (me->IsWithinDistInMap(who, 25.0f) && !player->GetQuestRewardStatus(QUEST_SET_THEM_FREE) && !player->GetQuestStatus(QUEST_SET_THEM_FREE) == QUEST_STATUS_NONE)
                {
                    QuestObjective const* obj = sObjectMgr->GetQuestObjective(OBJECTIVE_MANNETHREL_FREED);
                    if (!obj)
                        return;

                    if (!player->IsQuestObjectiveComplete(*obj))
                    {
                        if (!_talkedTo[player->GetGUID()] || sWorld->GetGameTime() - _talkedTo[player->GetGUID()] > 1 * HOUR)
                        {
                            _talkedTo[player->GetGUID()] = sWorld->GetGameTime();
                            Talk(CREATURE_TEXT_ZERO, who);
                        }
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ERASE:
                    EraseFromTalkedToMap(1 * HOUR);
                    _events.ScheduleEvent(EVENT_ERASE, 15 * MINUTE * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        std::map<ObjectGuid, time_t> _talkedTo;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mannethrel_darkstar_cageAI(creature);
    }
};

class spell_sacrificing_mystics_soul : public SpellScriptLoader
{
public:
    spell_sacrificing_mystics_soul() : SpellScriptLoader("spell_sacrificing_mystics_soul") { }

    class spell_sacrificing_mystics_soul_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sacrificing_mystics_soul_SpellScript);

        void HandleEvent(SpellEffIndex /* index */)
        {
            if (Player* player = GetCaster()->ToPlayer())
                player->KilledMonsterCredit(CREATURE_ASHTONGUE_MYSTIC);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_sacrificing_mystics_soul_SpellScript::HandleEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_sacrificing_mystics_soul_SpellScript();
    }

};

class spell_sevis_sacrifice_me : public SpellScriptLoader
{

public:
    spell_sevis_sacrifice_me() : SpellScriptLoader("spell_sevis_sacrifice_me") { }

    class spell_sevis_sacrifice_me_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sevis_sacrifice_me_SpellScript);

        void HandleEvent(SpellEffIndex /* index */)
        {
            if (Player* player = GetCaster()->ToPlayer())
                // probably shall be granted by Personal Spawn
                player->KilledMonsterCredit(CREATURE_SEVIS_BRIGHTFLAME);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_sevis_sacrifice_me_SpellScript::HandleEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_sevis_sacrifice_me_SpellScript();
    }

};

class spell_enter_the_illidari_shivarra_sacrificing_sevis : public SpellScriptLoader
{

public:
    spell_enter_the_illidari_shivarra_sacrificing_sevis() : SpellScriptLoader("spell_enter_the_illidari_shivarra_sacrificing_sevis") { }

    class spell_enter_the_illidari_shivarra_sacrificing_sevis_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_enter_the_illidari_shivarra_sacrificing_sevis_SpellScript);

        void HandleEvent(SpellEffIndex /* index */)
        {
            if (Player* player = GetCaster()->ToPlayer())
                // probably shall be granted by Personal Spawn
                player->KilledMonsterCredit(CREATURE_SEVIS_BRIGHTFLAME);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_enter_the_illidari_shivarra_sacrificing_sevis_SpellScript::HandleEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_enter_the_illidari_shivarra_sacrificing_sevis_SpellScript();
    }

};

class spell_give_me_sight_beyond_sight_periodic : public SpellScriptLoader
{
public:
    spell_give_me_sight_beyond_sight_periodic() : SpellScriptLoader("spell_give_me_sight_beyond_sight_periodic") { }

    class spell_give_me_sight_beyond_sight_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_give_me_sight_beyond_sight_periodic_AuraScript);

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (GetOwner()->ToPlayer()->HasAura(SPELL_SPECTRAL_SIGHT) && GetOwner()->ToPlayer()->GetQuestStatus(QUEST_GIVE_ME_SIGHT_BEYOND_SIGHT) == QUEST_STATUS_INCOMPLETE)
            {
                GetOwner()->ToPlayer()->KilledMonsterCredit(CREATURE_SPECTRAL_SIGHT_KILL_CREDIT);
                GetOwner()->ToPlayer()->CastSpell(GetTarget(), SPELL_SPECTRAL_SIGHT_PERIODIC_CANCEL);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_give_me_sight_beyond_sight_periodic_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_give_me_sight_beyond_sight_periodic_AuraScript();
    }
};

void AddSC_zone_mardum()
{
    new npc_sevis_brightflame_1();
    new npc_sevis_brightflame_2();
    new npc_sevis_brightflame_3();
    new npc_sevis_brightflame_4();
    new npc_kayn_sunfury1();
    new npc_allari_the_souleater_1();
    new npc_ashtongue_mystic_sacrifice();
    new npc_inquisitor_baleful();
    new npc_doom_commander_beliash();
    new npc_belath_dawnblade();
    new npc_lady_stheno();
    new npc_matron_mother_malevolence();
    new npc_battlelord_gaardoun();
    new npc_jace_darkweaver();
    new npc_cyana_nightglaive_cage();
    new npc_belath_dawnblade_cage();
    new npc_izal_whitemoon_cage();
    new npc_mannethrel_darkstar_cage();
    new spell_sacrificing_mystics_soul();
    new spell_sevis_sacrifice_me();
    new spell_enter_the_illidari_shivarra_sacrificing_sevis();
    new spell_give_me_sight_beyond_sight_periodic();
}
