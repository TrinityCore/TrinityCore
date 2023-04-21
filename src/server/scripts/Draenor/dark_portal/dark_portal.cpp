/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedEscortAI.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"
#include "GossipDef.h"
//#include "QuestData.h"

enum misc
{
    SPELL_UPDATE_PHASE_SHIFT = 82238,
};

enum __data
{
    SPELL_CHAIN_LIGHT = 15305,    //Chain Lightning
    SPELL_COMMAND_EARTH = 167470,   //Command Earth
    SPELL_COMMAND_LIGHT = 167014,   //Command Lightning
    SPELL_SAVAGERY = 167432,   //Savagery
    SPELL_PROTECTOR = 166114,
};

const uint32 spells[3] = { SPELL_CHAIN_LIGHT, SPELL_COMMAND_EARTH, SPELL_COMMAND_LIGHT };

struct arena_friendly_classAI : public ScriptedAI
{
    EventMap events;

    arena_friendly_classAI(Creature* creature) : ScriptedAI(creature)
    {
    }

    enum data
    {
        EVENT_COMBAT_SPELL_1 = 1,
        EVENT_COMBAT_SAVAGERY = 2,
        EVENT_BEGIN_1,
    };

    void Reset() override
    {

    }

    void JustRespawned() 
    {
        //ScriptedAI::JustRespawned();
        switch (me->GetAreaId())//GetCurrentAreaID
        {
            case 7037:
                events.RescheduleEvent(EVENT_BEGIN_1, Milliseconds(1000));
            case 7040:  //arena
                me->SetFaction(2580);
                break;
        }
    }

    //void EnterEvadeMode() 
    //{
    //    events.CancelEvent(EVENT_COMBAT_SPELL_1);
    //    events.CancelEvent(EVENT_COMBAT_SAVAGERY);
    //    ScriptedAI::EnterEvadeMode();
    //}

    void JustEnteredCombat(Unit* /*victim*/) override
    {
        events.RescheduleEvent(EVENT_COMBAT_SPELL_1,Milliseconds (5000));
        events.RescheduleEvent(EVENT_COMBAT_SAVAGERY, Milliseconds(1000));
    }
};

class mob_wod_thrall : public CreatureScript
{
public:
    mob_wod_thrall() : CreatureScript("mob_wod_thrall") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_thrallAI(creature);
    }

    struct mob_wod_thrallAI : public arena_friendly_classAI
    {
        mob_wod_thrallAI(Creature* creature) : arena_friendly_classAI(creature)
        {
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_COMBAT_SPELL_1:
                    {
                        if (Unit* victim = me->GetVictim())
                            me->CastSpell(victim, spells[urand(0, 2)], false);
                        events.RescheduleEvent(EVENT_COMBAT_SPELL_1, Milliseconds(5000));
                        break;
                    }
                    case EVENT_COMBAT_SAVAGERY:
                        me->CastSpell(me, SPELL_SAVAGERY, false);
                        events.RescheduleEvent(EVENT_COMBAT_SAVAGERY, Milliseconds(30000));
                        break;
                    case EVENT_BEGIN_1:
                        events.RescheduleEvent(EVENT_BEGIN_1, Milliseconds(60000));
                        //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_1, ObjectGuid::Empty);
                        me->CastSpell(me, SPELL_PROTECTOR, false);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class mob_wod_cordona_welsong : public CreatureScript
{
public:
    mob_wod_cordona_welsong() : CreatureScript("mob_wod_cordona_welsong") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_cordona_welsongAI(creature);
    }

    struct mob_wod_cordona_welsongAI : public arena_friendly_classAI
    {
        mob_wod_cordona_welsongAI(Creature* creature) : arena_friendly_classAI(creature)
        {
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_COMBAT_SPELL_1:
                {
                    if (Unit* victim = me->GetVictim())
                        me->CastSpell(victim, 166911, false);
                    events.RescheduleEvent(EVENT_COMBAT_SPELL_1, Milliseconds(5000));
                    break;
                }
                case EVENT_COMBAT_SAVAGERY:
                    me->CastSpell(me, SPELL_SAVAGERY, false);
                    events.RescheduleEvent(EVENT_COMBAT_SAVAGERY, Milliseconds(30000));
                    break;

                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class mob_wod_archimage_khadgar : public CreatureScript
{
public:
    mob_wod_archimage_khadgar() : CreatureScript("mob_wod_archimage_khadgar") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_archimage_khadgarAI(creature);
    }

    struct mob_wod_archimage_khadgarAI : public arena_friendly_classAI
    {
        mob_wod_archimage_khadgarAI(Creature* creature) : arena_friendly_classAI(creature)
        {
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_wod_olin_oberhind : public CreatureScript
{
public:
    mob_wod_olin_oberhind() : CreatureScript("mob_wod_olin_oberhind") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_olin_oberhindAI(creature);
    }

    struct mob_wod_olin_oberhindAI : public arena_friendly_classAI
    {
        mob_wod_olin_oberhindAI(Creature* creature) : arena_friendly_classAI(creature)
        {
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_COMBAT_SPELL_1:
                {
                    if (Unit* victim = me->GetVictim())
                        me->CastSpell(victim, 166969, false);
                    events.RescheduleEvent(EVENT_COMBAT_SPELL_1, Milliseconds(5000));
                    break;
                }
                case EVENT_COMBAT_SAVAGERY:
                    me->CastSpell(me, SPELL_SAVAGERY, false);
                    events.RescheduleEvent(EVENT_COMBAT_SAVAGERY, Milliseconds(30000));
                    break;

                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class mob_wod_intro_enemy_at_portal : public CreatureScript
{
public:
    mob_wod_intro_enemy_at_portal() : CreatureScript("mob_wod_intro_enemy_at_portal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_intro_enemy_at_portalAI(creature);
    }

    struct mob_wod_intro_enemy_at_portalAI : public ScriptedAI
    {
        mob_wod_intro_enemy_at_portalAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset()
        {
            if (me->GetVictim() || me->IsInEvadeMode())
                return;

            std::list<Unit*> list;
            me->GetAttackableUnitListInRange(list, 70.0f);
            for (auto enemy : list)
            {
                if (enemy->ToPlayer())
                    continue;
                me->AI()->AttackStart(enemy);
                break;
            }
        }

        void MoveInLineOfSight(Unit* /*who*/) override {};
        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/) override
        {
            if (victim->ToPlayer())
                damage /= 10;
            else
                damage = 0;
        }

        //void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        virtual void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (attacker->ToPlayer())
            {
                damage *= 2;
                return;
            }
            damage /= 2;
        }
    };
};

class mob_wod_intro_guldan : public CreatureScript
{
public:
    mob_wod_intro_guldan() : CreatureScript("mob_wod_intro_guldan") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_intro_guldanAI(creature);
    }

    struct mob_wod_intro_guldanAI : public ScriptedAI
    {

        enum data
        {
            SPELL_SCENE_INTRO       = 163807,
            SPELL_PORTAL_CREDIT     = 166319,
            QUEST_PORTAL_ENERGY     = 34393,
            OBJECTIVE_PORTAL_CREDIT = 82573,
        };

        mob_wod_intro_guldanAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset()
        {
        }

        void MoveInLineOfSight(Unit* who)
        {
            Player *player = who->ToPlayer();
            if (!player || !me->IsWithinDistInMap(who, 51.0f) || who->GetPositionZ() > 79.0f)
                return;

            if (player->GetQuestStatus(QUEST_PORTAL_ENERGY) != QUEST_STATUS_INCOMPLETE)
                return;

            /*if (player->HasAura(SPELL_SCENE_INTRO) || player->GetQuestObjectiveData(QUEST_PORTAL_ENERGY, OBJECTIVE_PORTAL_CREDIT))
                return;*/

            player->CastSpell(player, SPELL_PORTAL_CREDIT, true);
            player->CastSpell(player, SPELL_SCENE_INTRO, false);
            return;
        }
    };
};

class mob_wod_frostwolf_slave : public CreatureScript
{
public:
    mob_wod_frostwolf_slave() : CreatureScript("mob_wod_frostwolf_slave") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_frostwolf_slaveAI(creature);
    }

    struct mob_wod_frostwolf_slaveAI : public ScriptedAI
    {

        mob_wod_frostwolf_slaveAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        enum data
        {
            QUEST1 = 34421,
            QUEST2 = 35240,
        };

        GuidSet players;

        void Reset()
        {
        }

        void SetGUID(ObjectGuid const& guid, int32 /*id*/ = 0)
        {
            players.insert(guid);
        }

        void MoveInLineOfSight(Unit* who)
        {
            Player *player = who->ToPlayer();
            if (!player || !me->IsWithinDistInMap(who, 51.0f) || who->GetPositionZ() > 79.0f)
                return;

            if (player->GetQuestStatus(QUEST1) != QUEST_STATUS_INCOMPLETE && player->GetQuestStatus(QUEST2) != QUEST_STATUS_INCOMPLETE)
                return;

            auto data = players.find(who->GetGUID());
            if (data != players.end())
                return;

            players.insert(who->GetGUID());
            //sCreatureTextMgr->SendChat(me, 0, who->GetGUID());
            sCreatureTextMgr->SendChat(me, 0, who);

            // already trigered player for nearest
            std::list<Creature*> creatureList;
            me->GetCreatureListWithEntryInGrid(creatureList, me->GetEntry(), 50);
            for (auto c : creatureList)
                c->AI()->SetGUID(who->GetGUID(), 0);
        }
    };
};

// 159126 - eastern
class go_wod_slaves_cage : public GameObjectScript
{
public:
    go_wod_slaves_cage() : GameObjectScript("go_wod_slaves_cage") { }

    struct go_wod_slaves_cageAI : public GameObjectAI
    {
        go_wod_slaves_cageAI(GameObject* go) : GameObjectAI(go)
        {

        }
        
        enum data
        {
            SOUTH_SCENE = 159127,
            EASTERN_SCENE = 159126
        };

        //bool GossipHello(Player* player) override
        bool OnGossipHello(Player* player)override        
        {
            /*if (go->GetEntry() == 229353)
            {
                player->CastSpell(player, EASTERN_SCENE, true);
                player->KilledMonsterCredit(85142, ObjectGuid::Empty);
                player->KilledMonsterCredit(78529, ObjectGuid::Empty);
            }
            else*/
            {
                player->CastSpell(player, SOUTH_SCENE, true);
                player->KilledMonsterCredit(82871, ObjectGuid::Empty);
                player->KilledMonsterCredit(85141, ObjectGuid::Empty);
            }

            return true;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const
    {
        return new go_wod_slaves_cageAI(go);
    }
};

class mob_wod_ariok : public CreatureScript
{
public:
    mob_wod_ariok() : CreatureScript("mob_wod_ariok") { }

    enum data
    {
        QUEST = 34423,
        SPELL_CREDIT = 159278,
        SPELL_SUMMON = 161625,
        PHASE_ARIOK_DB = 3394,
    };
    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == 1)
        {
            //player->CLOSE_GOSSIP_MENU();
            if (player->GetQuestStatus(QUEST) == QUEST_STATUS_INCOMPLETE)
            {
                player->CastSpell(player, SPELL_CREDIT, true);
                player->CastSpell(player, SPELL_SUMMON, true);
                std::set<uint32> phase = player->GetPhases();
                phase.erase(PHASE_ARIOK_DB);
                //player->SetPhaseId(phase, true);
            }
        }

        return true;
    }
};

// phase spell - 165052
// end quest - 165053
class mob_wod_ariok_mover : public CreatureScript
{
public:
    mob_wod_ariok_mover() : CreatureScript("mob_wod_ariok_mover") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_ariok_moverAI(creature);
    }

    struct mob_wod_ariok_moverAI : public ScriptedAI
    {
        EventMap events;
        ObjectGuid playerGuid;

        mob_wod_ariok_moverAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        enum data
        {
            SPELL_ON_ALTAR_CREDIT = 161637,
            SPELL_SCENE_EYE_CILLROG = 164877,
            SPELL_SCENE = 165061,

            NPC_ORB = 83670,

            EVENT_1 = 1,
            EVENT_2,
            EVENT_3,
            EVENT_4,
            EVENT_5,
            EVENT_6,
            EVENT_CHECK_PHASE_1
        };

        void OnCharmed(bool /*apply*/)
        {
        }

        void IsSummonedBy(Unit* summoner)
        {
            Player *player = summoner->ToPlayer();
            if (!player)
            {
                /*me->MonsterSay("SCRIPT::mob_wod_ariok_moverAI summoner is not player", LANG_UNIVERSAL, ObjectGuid::Empty);*/  //org
                me->Say("SCRIPT::mob_wod_ariok_moverAI summoner is not player", LANG_UNIVERSAL, nullptr);
                return;
            }

            playerGuid = summoner->GetGUID();
            //me->AddPlayerInPersonnalVisibilityList(summoner->GetGUID());

            uint32 t = 0;                                                       //
            events.RescheduleEvent(EVENT_1,Milliseconds (t += 2000));               //09:14:54.000
            events.RescheduleEvent(EVENT_2, Milliseconds(t += 6000));               //09:15:00.000
            events.RescheduleEvent(EVENT_3, Milliseconds(t += 7000));               //09:15:07.000

            events.RescheduleEvent(EVENT_CHECK_PHASE_1, Milliseconds(t += 1000));
        }

        void DoAction(int32 const /*param*/)
        {
            //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_5, playerGuid);
            me->DespawnOrUnsummon(Milliseconds(1000));
        }

        void UpdateAI(uint32 diff)
        {
            UpdateVictim();

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_4:
                    //if (Player* player = sObjectAccessor->FindPlayer(playerGuid))
                    //{
                    //    player->CastSpell(player, SPELL_ON_ALTAR_CREDIT, true);
                    //    player->CastSpell(player, SPELL_SCENE_EYE_CILLROG, true);
                    //}
                    //break;    no break;
                case EVENT_5:
                case EVENT_1:
                case EVENT_2:
                case EVENT_3:
                    //sCreatureTextMgr->SendChat(me, /*TEXT_GENERIC_0*/eventId-1, playerGuid);
                    break;
                case EVENT_6:
                    /*if (Player* player = sObjectAccessor->FindPlayer(playerGuid))
                        player->CastSpell(player, SPELL_SCENE, true);*/
                    break;
                case EVENT_CHECK_PHASE_1:

                    if (me->GetDistance(3979.26f, -2918.31f, 60.8725f) < 80.0f)
                    {
                        uint32 t = 0;
                        events.RescheduleEvent(EVENT_4, Milliseconds(t += 1000));               //09:16:18.000
                        events.RescheduleEvent(EVENT_5, Milliseconds(t += 5000));               //09:16:23.000
                        events.RescheduleEvent(EVENT_6, Milliseconds(t += 60000));              //09:17:27.000
                    }else
                        events.RescheduleEvent(EVENT_CHECK_PHASE_1, Milliseconds(5000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

// Destroy - 167955
class spell_wod_destroying : public SpellScriptLoader
{
public:
    spell_wod_destroying() : SpellScriptLoader("spell_wod_destroying") { }

    class spell_wod_destroying_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_wod_destroying_SpellScript);

        enum data
        {
            SPELL_GUARD_SUMMON_SPELL = 161618,
            NPC_SUMMON_ID = 80087,
            QUEST = 34423,
            OBJECTIVE_CREDIT = 78966,
        };

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            PreventHitDefaultEffect(EFFECT_1);

            if (Unit* caster = GetCaster())
            {
                Player *player = caster->ToPlayer();
                if (!player)
                    return;

                if (Unit * target = GetHitUnit())
                {
                    //target->AddToHideList(caster->GetGUID());
                    target->DestroyForPlayer(player);
                }

                //if (player->GetQuestObjectiveData(QUEST, OBJECTIVE_CREDIT) >= 3)
                //{
                //    if (Creature *c = player->GetMinionByEntry(NPC_SUMMON_ID))
                //        c->AI()->DoAction(0);
                //}
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_wod_destroying_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_wod_destroying_SpellScript();
    }
};

class mob_khadgar_q34425 : public CreatureScript
{
public:
    mob_khadgar_q34425() : CreatureScript("mob_khadgar_q34425") { }

    //CreatureAI* GetAI(Creature* creature) const
    //{
    //    return new mob_khadgar_q34425AI(creature);
    //}

    struct mob_khadgar_q34425AI : public EscortAI
    {
        mob_khadgar_q34425AI(Creature* creature) : EscortAI(creature)
        {}

        ObjectGuid playerGuid;
        EventMap events;

        enum events
        {
            SPELL_SHOWER = 165864,
            NPC_CREDIT = 80244,

            EVENT_1 = 1,
            EVENT_2 = 2,
            EVENT_JECK_DEAD = 3,
        };

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void SetGUID(ObjectGuid const& guid, int32)
        {
            playerGuid = guid;
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->CastSpell(me, SPELL_SHOWER, false); //09:20:28.000
            //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_0, playerGuid);

            //me->AddPlayerInPersonnalVisibilityList(summoner->GetGUID());
            playerGuid = summoner->GetGUID();
            events.RescheduleEvent(EVENT_1, Milliseconds(8000));    //09:20:36.000
        }

        //void WaypointReached(uint32 waypointId)
        //{
        //    if (waypointId == 3)
        //    {
        //        if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
        //            player->KilledMonsterCredit(NPC_CREDIT);
        //        me->DespawnOrUnsummon(Milliseconds(1000));
        //    }
        //}

        void UpdateAI(uint32 diff)
        {
            EscortAI::UpdateAI(diff);
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_1, playerGuid);
                        //Start(false, true);
                        Start(false,ObjectGuid::Empty);
                        break;
                    default:
                        break;
                }
            }
        }
    };
};

//! enable phase_definitions for zone 7025 ID 18 phases - 3266 3394 3395 3396 3481 3693 3694 3712 3824 3833 3834 4006 4017 4150 4151 4200
//! was done by spell 165867 withch prock with trigger and witch prock - 82238 with change phase. and by using condition CONDITION_SCENE_TRIGER_EVENT i did it.
//! so. this script just like example for future possible scripting. But. I think. Blizz all has done by spell prock at triger scene.
//class sceneTrigger_q34425 : public SceneTriggerScript
//{
//public:
//    sceneTrigger_q34425() : SceneTriggerScript("sceneTrigger_q34425")
//    {}
//
//    bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
//    {
//        return false;
//    }
//};

class mob_arena_combatant_q34429 : public CreatureScript
{
public:
    mob_arena_combatant_q34429() : CreatureScript("mob_arena_combatant_q34429") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_arena_combatant_q34429AI(creature);
    }

    struct mob_arena_combatant_q34429AI : public ScriptedAI
    {

        mob_arena_combatant_q34429AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        enum data
        {
            QUEST = 34429,
            NPC_CREDIT = 82066,
            SPELL_SUMMON = 167314,
            SPELL_CREDIT = 168182,
        };

        void Reset()
        {
            if (me->GetVictim() || me->IsInEvadeMode())
                return;

            std::list<Unit*> list;
            me->GetAttackableUnitListInRange(list, 70.0f);
            for (auto enemy : list)
            {
                if (enemy->ToPlayer())
                    continue;
                me->AI()->AttackStart(enemy);
                break;
            }
        }

        void MoveInLineOfSight(Unit* /*who*/) override {};
        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/) override
        {
            if (victim->ToPlayer())
                damage /= 10;
            else
                damage = 0;
        }

        //void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) {
            if (attacker->ToPlayer())
            {
                damage *= 2;
                return;
            }
            damage /= 2;
        }

        void JustDied(Unit* /*killer*/)
        {
            std::list<Player*> lList;
            me->GetPlayerListInGrid(lList, 200.0f);
            for (auto player : lList)
            {
                /*if (player->GetQuestStatus(QUEST) == QUEST_STATUS_INCOMPLETE && player->GetQuestObjectiveData(QUEST, NPC_CREDIT) < 99)*/
                    player->CastSpell(player, SPELL_CREDIT, true);
            }

            std::list<Creature*> creatureList;
            //me->GetAliveCreatureListWithEntryInGrid(creatureList, me->GetEntry(), 20.0f);
            if (creatureList.size() < 20)
                me->CastSpell(me, SPELL_SUMMON, false);

        }
    };
};

//class sceneTrigger_q34429 : public SceneTriggerScript
//{
//public:
//    sceneTrigger_q34429() : SceneTriggerScript("sceneTrigger_q34429")
//    {}
//
//    enum data
//    {
//        SPELL_CREDIT_100 = 168182,
//        SPELL_PHASE = 167960,
//        SPELL_CREDIT_ESCAPE = 165265,
//    };
//
//    //bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
//    //{
//    //    if (type == "Update")
//    //    {
//    //        player->CastSpell(player, SPELL_PHASE, false);
//    //    }
//    //    else if (type == "Hundred")
//    //    {
//    //        player->CastSpell(player, SPELL_CREDIT_100, true);
//    //    }
//    //    else if (type == "Credit")
//    //    {
//    //        player->CastSpell(player, SPELL_CREDIT_ESCAPE, false);
//
//    //        if (Quest const* qInfo = sQuestDataStore->GetQuestTemplate(34429))
//    //        {
//    //            for (QuestObjective const& obj : qInfo->GetObjectives())
//    //            {
//    //                if (obj.ObjectID != 82142)
//    //                    continue;
//    //                player->SetQuestObjectiveData(qInfo, &obj, 99);
//    //                if (player->CanCompleteQuest(34429))
//    //                    player->CompleteQuest(34429);
//    //                break;
//    //            }
//    //        }
//    //    }
//    //    return true;
//    //}
//};

//- NPC 78994
class mob_wod_irel : public CreatureScript
{
public:
    mob_wod_irel() : CreatureScript("mob_wod_irel") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_irelAI(creature);
    }

    enum data
    {
        SPELL_CREDIT = 160774,
        OBJECTIVE_CREDIT = 79593,
        Q_H = 34737,
        Q_A = 34431,
    };

    struct mob_wod_irelAI : public ScriptedAI
    {
        mob_wod_irelAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset()
        {
        }

        void MoveInLineOfSight(Unit* who)
        {
            Player *player = who->ToPlayer();
            if (!player || !me->IsWithinDistInMap(who, 25.0f))
                return;
            
            if (player->GetQuestStatus(player->GetTeam() == ALLIANCE ? Q_A : Q_H) != QUEST_STATUS_INCOMPLETE)
                return;

            /*if (player->GetQuestObjectiveData(player->GetTeam() == ALLIANCE ? Q_A : Q_H, OBJECTIVE_CREDIT))
                return;*/

            player->CastSpell(player, SPELL_CREDIT, true);
            //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_0, player->GetGUID());
            return;
        }
    };
};

class mob_wod_q34434_q34740 : public CreatureScript
{
public:
    mob_wod_q34434_q34740() : CreatureScript("mob_wod_q34434_q34740") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_q34434_q34740AI(creature);
    }

    struct mob_wod_q34434_q34740AI : public ScriptedAI
    {
        EventMap events;
        ObjectGuid playerGuid;

        mob_wod_q34434_q34740AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        enum data
        {
            EVENT_1 = 1,
            EVENT_2,
            EVENT_3,

            EVENT_CHECK_PHASE_1
        };

        void OnCharmed(bool /*apply*/)
        {
        }

        void IsSummonedBy(Unit* summoner)
        {
            Player *player = summoner->ToPlayer();
            if (!player)
            {
                //me->MonsterSay("SCRIPT::mob_wod_q34434_q34740AI summoner is not player", LANG_UNIVERSAL, ObjectGuid::Empty);
                me->Say("SCRIPT::mob_wod_q34434_q34740AI summoner is not player", LANG_UNIVERSAL,nullptr);
                return;
            }

            playerGuid = summoner->GetGUID();
            //me->AddPlayerInPersonnalVisibilityList(summoner->GetGUID());

            uint32 t = 0;                                                       //
            events.RescheduleEvent(EVENT_1, Milliseconds(t += 2000));               //09:34:23.000 
            events.RescheduleEvent(EVENT_2, Milliseconds(t += 6000));               //09:34:28.000

            events.RescheduleEvent(EVENT_CHECK_PHASE_1, Milliseconds(t += 1000));
        }

        void DoAction(int32 const /*param*/)
        {

        }

        void UpdateAI(uint32 diff)
        {
            UpdateVictim();

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                case EVENT_2:
                case EVENT_3:
                    //sCreatureTextMgr->SendChat(me, /*TEXT_GENERIC_0*/eventId - 1, playerGuid);
                    break;
                case EVENT_CHECK_PHASE_1:
                    if (me->GetDistance(4516.582f, -2495.618f, 25.87184f) < 40.0f && !me->GetVictim())
                    {
                        //if (Player* player = sObjectAccessor->FindPlayer(playerGuid))
                            //player->KilledMonsterCredit(79794, ObjectGuid::Empty);

                        me->GetMotionMaster()->MovePoint(1, 4516.582f, -2495.618f, 25.87184f);
                        //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_2, playerGuid);
                        me->DespawnOrUnsummon(Milliseconds(15000));
                    }
                    else
                        events.RescheduleEvent(EVENT_CHECK_PHASE_1, Milliseconds(5000));
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};
//go - 233197 Q: 34741, 34436
class go_wod_gate_q34741_34436 : public GameObjectScript
{
public:
    go_wod_gate_q34741_34436() : GameObjectScript("go_wod_gate_q34741_34436") { }

    struct go_wod_gate_q34741_34436_AI : public GameObjectAI
    {
        go_wod_gate_q34741_34436_AI(GameObject* go) : GameObjectAI(go)
        {
            events.RescheduleEvent(1, Milliseconds(5000));
        }

        enum data
        {
            Q_H = 34741,
            Q_A = 34436,
        };

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                events.RescheduleEvent(1, Milliseconds(1000));

                std::list<Player*> playerList;
                //go->GetPlayerListInGrid(playerList, 10.0f);
                for (std::list<Player*>::iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    if ((*itr)->GetQuestStatus((*itr)->GetTeam() == ALLIANCE ? Q_A : Q_H) == QUEST_STATUS_NONE)
                        continue;
                    /*if (go->GetGoState() != GO_STATE_ACTIVE_ALTERNATIVE)
                        go->EnableOrDisableGo(true, true);*/
                    return;
                }
                /*if (go->GetGoState() == GO_STATE_ACTIVE_ALTERNATIVE)
                    go->EnableOrDisableGo(false, false);*/                
            }
        }

    private:
        EventMap events;
    };

    GameObjectAI* GetAI(GameObject* go) const
    {
        return new go_wod_gate_q34741_34436_AI(go);
    }
};

class mob_wod_q34741_34436 : public CreatureScript
{
public:
    mob_wod_q34741_34436() : CreatureScript("mob_wod_q34741_34436") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_q34741_34436_AI(creature);
    }

    struct mob_wod_q34741_34436_AI : public ScriptedAI
    {
        EventMap events;
        bool _event;
        mob_wod_q34741_34436_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        enum data
        {
            SPELL_VOID_SHELL = 165880, //Void Shell
            SPELL_VOID_BOLT_VOLLEY = 165875, //Void Bolt Volley
            SPELL_VOID_VACUUM = 165871, //Void Vacuum

            SPELL_VOID_COSMETIC_MISLE = 165316,

            EVENT_COMBAT_SPELL_1 = 1,
            EVENT_SHELL,
            EVENT_3,
            EVENT_4,
            EVENT_5,
            EVENT_6,

        };

        void Reset() override
        {
            
        }

        //void JustDied(Unit* killer)
        //{
        //    sCreatureTextMgr->SendChat(me, TEXT_GENERIC_3, ObjectGuid::Empty);
        //}

        //void EnterEvadeMode() override
        void EnterEvadeMode(EvadeReason /*why = EvadeReason::Other*/)
        {
            events.CancelEvent(EVENT_COMBAT_SPELL_1);
            events.CancelEvent(EVENT_SHELL);
            ScriptedAI::EnterEvadeMode();
        }

        void JustEnteredCombat(Unit* /*victim*/) override
        {
            //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_0, ObjectGuid::Empty);
            events.RescheduleEvent(EVENT_COMBAT_SPELL_1, Milliseconds(5000));
            events.RescheduleEvent(EVENT_SHELL, Milliseconds(8000));
        }

        void UpdateAI(uint32 diff)
        {
            UpdateVictim();

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_COMBAT_SPELL_1:
                    {
                        if (Unit* victim = me->GetVictim())
                            me->CastSpell(victim, 166911, false);
                        events.RescheduleEvent(EVENT_COMBAT_SPELL_1, Milliseconds(5000));
                        break;
                    }
                    case EVENT_SHELL:
                        //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_2, ObjectGuid::Empty);
                        me->CastSpell(me, SPELL_VOID_VACUUM, false);
                        events.RescheduleEvent(EVENT_SHELL, Milliseconds(20000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

//class sceneTrigger_q34741_34436 : public SceneTriggerScript
//{
//public:
//    sceneTrigger_q34741_34436() : SceneTriggerScript("sceneTrigger_q34741_34436")
//    {}
//
//    enum data
//    {
//        SPELL_CREDIT_100 = 168182,
//        SPELL_PHASE = 167960,
//        SPELL_CREDIT_ESCAPE = 165265,
//    };
//
//    bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
//    {
//        if (type == "Teleport")
//        {
//            player->TeleportTo(1265, 4519.2f, -2294.0f, 33.8118f, 1.343904f);
//        }
//        return true;
//    }
//};

//class sceneTrigger_q34439 : public SceneTriggerScript
//{
//public:
//    sceneTrigger_q34439() : SceneTriggerScript("sceneTrigger_q34439")
//    {}
//
//    enum data
//    {
//        SPELL_BIG = 167891,
//        SPELL_SMALL = 167890,
//    };
//
//    bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
//    {
//        if (type == "Big")
//        {
//            player->CastSpell(player, SPELL_BIG, false);
//        }
//        else if (type == "Small")
//        {
//            player->CastSpell(player, SPELL_SMALL, false);
//        }
//        return true;
//    }
//};
//
//class sceneTrigger_q34987 : public SceneTriggerScript
//{
//public:
//    sceneTrigger_q34987() : SceneTriggerScript("sceneTrigger_q34987")
//    {}
//
//    enum data
//    {
//        NPC__ = 78569,
//        SPELL_TALKA = 163678,
//        SPELL_SMALL = 167890,
//    };
//
//    bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
//    {
//        if (type == "TalkA")
//        {
//            if (Creature *c = player->FindNearestCreature(NPC__, 100.0f))
//                sCreatureTextMgr->SendChat(c, TEXT_GENERIC_1, player->GetGUID());
//        }
//        else if (type == "TalkB")
//        {
//            if (Creature *c = player->FindNearestCreature(NPC__, 100.0f))
//                sCreatureTextMgr->SendChat(c, TEXT_GENERIC_2, player->GetGUID());
//            player->CastSpell(player, SPELL_SMALL, false);
//        }
//        else if (type == "TalkC")
//        {
//            if (Creature *c = player->FindNearestCreature(NPC__, 100.0f))
//                sCreatureTextMgr->SendChat(c, TEXT_GENERIC_3, player->GetGUID());
//        }
//        else if (type == "TalkD")
//        {
//            if (Creature *c = player->FindNearestCreature(NPC__, 100.0f))
//                sCreatureTextMgr->SendChat(c, TEXT_GENERIC_4, player->GetGUID());
//        }
//        return true;
//    }
//};

class mob_wod_thaelin_darkanvil : public CreatureScript
{
public:
    mob_wod_thaelin_darkanvil() : CreatureScript("mob_wod_thaelin_darkanvil") { }

    enum data
    {
        QUEST = 35747,
        CREDIT = 80880,
    };

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/)
    {
        player->PlayerTalkClass->ClearMenus();
        //if (action == 1)
        //{
        //    player->CLOSE_GOSSIP_MENU();
        //    if (player->GetQuestStatus(QUEST) == QUEST_STATUS_INCOMPLETE)
        //    {
        //        player->KilledMonsterCredit(CREDIT, ObjectGuid::Empty);
        //        player->GetPhaseMgr().RemoveUpdateFlag(PHASE_UPDATE_FLAG_ZONE_UPDATE);
        //        return true;
        //    }
        //}
        return false;        
    }
};

class mob_wod_q35747 : public CreatureScript
{
public:
    mob_wod_q35747() : CreatureScript("mob_wod_q35747") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wod_q35747AI(creature);
    }

    struct mob_wod_q35747AI : public ScriptedAI
    {
        EventMap events;
        ObjectGuid playerGuid;
        uint8 state;

        mob_wod_q35747AI(Creature* creature) : ScriptedAI(creature)
        {
            state = 0;
        }

        enum data
        {
            EVENT_1 = 1,
            EVENT_2,
            EVENT_3,

            EVENT_CHECK_PHASE_1
        };

        void OnCharmed(bool /*apply*/)
        {
        }

        void IsSummonedBy(Unit* summoner)
        {
            Player *player = summoner->ToPlayer();
            if (!player)
            {
                //me->MonsterSay("SCRIPT::mob_wod_q35747 summoner is not player", LANG_UNIVERSAL, ObjectGuid::Empty);
                me->Say("SCRIPT::mob_wod_q35747 summoner is not player", LANG_UNIVERSAL, nullptr);
                return;
            }

            playerGuid = summoner->GetGUID();
            //me->AddPlayerInPersonnalVisibilityList(summoner->GetGUID());

            me->SetEntry(78568);
            me->SetDisplayId(52540);
            me->SetDisplayId(54576);//SetNativeDisplayId

            //! after entry set.
            //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_0, playerGuid);

            events.RescheduleEvent(EVENT_CHECK_PHASE_1, Milliseconds(5000));
        }

        void UpdateAI(uint32 diff)
        {
            UpdateVictim();

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PHASE_1:
                    if (me->GetDistance(4065.0f, -1955.0f, 27.0f) < 40.0f && !state)
                    {
                        state = 1;
                        //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_1, playerGuid);      
                    }

                    if (state == 1 && me->GetDistance(4063.77f, -2020.122f, 75.47333f) < 10.0f)
                    {
                        //sCreatureTextMgr->SendChat(me, TEXT_GENERIC_2, playerGuid);
                        me->GetMotionMaster()->MovePoint(1, 4063.77f, -2020.122f, 75.47333f);
                        me->DespawnOrUnsummon(Milliseconds(1000));
                        /*if (Player* player = sObjectAccessor->FindPlayer(playerGuid))
                            player->KilledMonsterCredit(80887, ObjectGuid::Empty);*/
                        return;
                    }
                    events.RescheduleEvent(EVENT_CHECK_PHASE_1, Milliseconds(5000));
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

//class sceneTrigger_q34445 : public SceneTriggerScript
//{
//public:
//    sceneTrigger_q34445() : SceneTriggerScript("sceneTrigger_q34445")
//    {}
//
//    enum data
//    {
//        NPC__ = 80521,
//        CREDIT_ = 80016,
//        SPEL_INST = 176104,
//        SPELL_BLOOD = 161527,
//        SPELL_GO = 164043,
//        //167976 
//    };
//
//    //bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
//    //{
//    //    if (type == "Instructions")
//    //    {
//    //        player->CastSpell(player, SPEL_INST, false);
//    //        //if (Creature *c = player->FindNearestCreature(NPC__, 100.0f))
//    //            //sCreatureTextMgr->SendChat(c, TEXT_GENERIC_1, player->GetGUID());
//    //    }
//    //    else if (type == "Credit")
//    //    {
//    //        player->KilledMonsterCredit(CREDIT_, ObjectGuid::Empty);
//    //    }
//    //    else if (type == "Bloodlust")
//    //    {
//    //        player->CastSpell(player, SPELL_BLOOD, false);
//    //    }
//    //    else if (type == "CancelGame")
//    //    {
//    //        player->CastSpell(player, SPELL_GO, false);
//    //    }
//    //    return true;
//    //}
//};

class go_wod_q34445 : public GameObjectScript
{
public:
    go_wod_q34445() : GameObjectScript("go_wod_q34445") { }

    struct go_wod_q34445AI : public GameObjectAI
    {
        go_wod_q34445AI(GameObject* go) : GameObjectAI(go)
        {

        }

        enum data
        {
            SPELL_CINEMA = 176159,

        };
        bool OnGossipHello(Player* player) override
        {
            if (player->GetQuestStatus(34445) == QUEST_STATUS_INCOMPLETE)
                player->CastSpell(player, SPELL_CINEMA, true);
            return false;
        }

    };

    GameObjectAI* GetAI(GameObject* go) const
    {
        return new go_wod_q34445AI(go);
    }
};

//! 167421 Khadgar's Watch
//! Q: 34446 35884
class spell_wod_khadgar_watch : public SpellScriptLoader
{
public:
    spell_wod_khadgar_watch() : SpellScriptLoader("spell_wod_khadgar_watch") { }

    class spell_wod_khadgar_watch_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_wod_khadgar_watch_AuraScript);

        enum data
        {
            SPELL_A = 163524,
            SPELL_B = 163525,
            SPELL_C = 163526,
            SPELL_D = 163527,
            SPELL_E = 163528,
            SPELL_F = 163529,
            SPELL_G = 163530,

            QUEST_A = 34446,
            QUEST_B = 35884,

            CREDIT_ = 81024,
        };

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (!GetCaster())
                return;

            if (Player* player = GetCaster()->ToPlayer())
            {
                if (player->GetQuestStatus(QUEST_A) == QUEST_STATUS_INCOMPLETE ||
                    player->GetQuestStatus(QUEST_B) == QUEST_STATUS_INCOMPLETE)
                {
                    if (!player->IsInWorld())
                        return;

                    if (player->GetDistance(4021.0f, -2000.0f, 30.0f) < 20.0f && !player->HasAura(SPELL_A))
                        player->CastSpell(player, SPELL_A, true);

                    if (player->GetDistance(3970.787f, -2010.345f, 28.65494f) < 20.0f && !player->HasAura(SPELL_B))
                        player->CastSpell(player, SPELL_B, true);

                    if (player->GetDistance(3888.591f, -2025.13f, 19.50598f) < 20.0f && !player->HasAura(SPELL_C))
                        player->CastSpell(player, SPELL_C, true);

                    if (player->GetDistance(3888.591f, -2025.13f, 19.50598f) < 20.0f && !player->HasAura(SPELL_D))
                        player->CastSpell(player, SPELL_D, true);

                    if (player->GetDistance(3792.147f, -2065.47f, 14.06284f) < 20.0f && !player->HasAura(SPELL_E))
                        player->CastSpell(player, SPELL_E, true);

                    if (player->GetDistance(3792.147f, -2065.47f, 14.06284f) < 20.0f && !player->HasAura(SPELL_F))
                        player->CastSpell(player, SPELL_F, true);

                    if (player->GetDistance(3704.125f, -2049.134f, 9.72922f) < 20.0f && !player->HasAura(SPELL_G))
                        player->CastSpell(player, SPELL_G, true);

                    if (player->GetDistance(3554.205f, -2120.661f, 19.31005f) < 20.0f)
                        player->KilledMonsterCredit(CREDIT_, ObjectGuid::Empty);
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_wod_khadgar_watch_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_wod_khadgar_watch_AuraScript();
    }
};

void AddSC_wod_dark_portal()
{
    new mob_wod_thrall();
    new mob_wod_cordona_welsong();
    new mob_wod_archimage_khadgar();
    new mob_wod_olin_oberhind();
    new mob_wod_intro_enemy_at_portal();
    new mob_wod_intro_guldan();
    new mob_wod_frostwolf_slave();
    new go_wod_slaves_cage();
    new mob_wod_ariok();
    new mob_wod_ariok_mover();
    new spell_wod_destroying();
    new mob_khadgar_q34425();
    //new sceneTrigger_q34425();
    new mob_arena_combatant_q34429();
    //new sceneTrigger_q34429();
    new mob_wod_irel();
    new mob_wod_q34434_q34740();
    new go_wod_gate_q34741_34436();
    new mob_wod_q34741_34436();
    /*new sceneTrigger_q34741_34436();
    new sceneTrigger_q34439();
    new sceneTrigger_q34987();*/
    new mob_wod_thaelin_darkanvil();
    new mob_wod_q35747();
    //new sceneTrigger_q34445();
    new go_wod_q34445();
    new spell_wod_khadgar_watch();
}
