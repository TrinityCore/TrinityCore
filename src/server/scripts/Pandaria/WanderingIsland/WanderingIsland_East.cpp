/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "Creature.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "Vehicle.h"

#define QUEST_SPIRIT_OF_WATER 29678
#define QUEST_A_NEW_FRIEND    29679

class AreaTrigger_at_bassin_curse : public AreaTriggerScript
{
    public:
        AreaTrigger_at_bassin_curse() : AreaTriggerScript("AreaTrigger_at_bassin_curse")
        {}

        enum eTriggers
        {
            AREA_CRANE              = 6991,
            AREA_SKUNK              = 6988,
            AREA_FROG               = 6987,
            AREA_FROG_EXIT          = 6986,
            AREA_TURTLE             = 7012,
            AREA_CROCODILE          = 6990
        };

        enum eSpells
        {
            SPELL_FROG              = 102938,
            SPELL_SKUNK             = 102939,
            SPELL_TURTLE            = 102940,
            SPELL_CRANE             = 102941,
            SPELL_CROCODILE         = 102942
        };

        void AddOrRemoveSpell(Player* player, uint32 spellId, bool add)
        {
            RemoveAllSpellsExcept(player, spellId);

            if (add)
            {
                if (!player->IsOnVehicle())
                    player->AddAura(spellId, player);
            }
            else
                player->RemoveAurasDueToSpell(spellId);
        }

        void RemoveAllSpellsExcept(Player* player, uint32 spellId)
        {
            uint32 spellTable[5] = {SPELL_FROG, SPELL_SKUNK, SPELL_TURTLE, SPELL_CRANE, SPELL_CROCODILE};

            for (uint8 i = 0; i < 5; ++i)
                if (spellId != spellTable[i])
                    player->RemoveAurasDueToSpell(spellTable[i]);
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool entered) override
        {
            switch (trigger->ID)
            {
                case AREA_CRANE:     AddOrRemoveSpell(player, SPELL_CRANE, entered);     break;
                case AREA_SKUNK:     AddOrRemoveSpell(player, SPELL_SKUNK, entered);     break;
                case AREA_FROG:      AddOrRemoveSpell(player, SPELL_FROG, entered);      break;
                case AREA_FROG_EXIT: RemoveAllSpellsExcept(player, 0);                   break;
                case AREA_TURTLE:    AddOrRemoveSpell(player, SPELL_TURTLE, entered);    break;
                case AREA_CROCODILE: AddOrRemoveSpell(player, SPELL_CROCODILE, entered); break;
            }
            return true;
        }
};

// Npc's : 54993 - 55083 - 57431
class vehicle_balance_pole : public VehicleScript
{
    public:
        vehicle_balance_pole() : VehicleScript("vehicle_balance_pole") {}

        void OnAddPassenger(Vehicle* /*veh*/, Unit* passenger, int8 /*seatId*/) override
        {
            if (passenger->HasAura(102938))
                passenger->ExitVehicle();
        }

        void OnRemovePassenger(Vehicle* veh, Unit* passenger) override
        {
            if (veh->GetBase()->GetPositionZ() == 116.521004f) // Hack
                if (passenger->IsOnVehicle()) // Maybe the player
                    passenger->AddAura(102938, passenger);
        }
};

class mob_tushui_monk : public CreatureScript
{
public:
    mob_tushui_monk() : CreatureScript("mob_tushui_monk") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_tushui_monkAI(creature);
    }

    struct mob_tushui_monkAI : public ScriptedAI
    {
        mob_tushui_monkAI(Creature* creature) : ScriptedAI(creature)
        {}

        void Reset() override
        {
            std::list<Creature*> poleList;
            GetCreatureListWithEntryInGrid(poleList, me, 54993, 25.0f);

            if (poleList.empty())
            {
                me->DespawnOrUnsummon(1000);
                return;
            }

            Trinity::Containers::RandomResize(poleList, 1);

            for (auto creature: poleList)
                me->EnterVehicle(creature);

            me->setFaction(2357);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->ExitVehicle();
            me->DespawnOrUnsummon(1000);
        }
    };
};

// Rock Jump - 103069 / 103070 / 103077
class spell_rock_jump: public SpellScriptLoader
{
    public:
        spell_rock_jump() : SpellScriptLoader("spell_rock_jump") { }

        class spell_rock_jump_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rock_jump_SpellScript);

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (!caster->ToPlayer() || caster->ToPlayer()->GetQuestStatus(29678) != QUEST_STATUS_INCOMPLETE)
                        return;

                    if (caster->GetPositionZ() < 90.0f)
                        caster->GetMotionMaster()->MoveJump(1045.36f, 2848.47f, 91.38f, 20.0f, 10.0f, 10.0f);
                    else if (caster->GetPositionZ() < 92.0f)
                        caster->GetMotionMaster()->MoveJump(1054.42f, 2842.65f, 92.96f, 20.0f, 10.0f, 10.0f);
                    else if (caster->GetPositionZ() < 94.0f)
                        caster->GetMotionMaster()->MoveJump(1063.66f, 2843.49f, 95.50f, 20.0f, 10.0f, 10.0f);
                    else
                    {
                        caster->GetMotionMaster()->MoveJump(1078.42f, 2845.07f, 95.16f, 20.0f, 10.0f, 10.0f);

                        if (caster->ToPlayer())
                            caster->ToPlayer()->KilledMonsterCredit(57476);
                    }
                }
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_rock_jump_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rock_jump_SpellScript();
        }
};

Position rocksPos[4] =
{
    {1102.05f, 2882.11f, 94.32f, 0.11f},
    {1120.01f, 2883.20f, 96.44f, 4.17f},
    {1128.09f, 2859.44f, 97.64f, 2.51f},
    {1111.52f, 2849.84f, 94.84f, 1.94f}
};

class mob_shu_water_spirit : public CreatureScript
{
public:
    mob_shu_water_spirit() : CreatureScript("mob_shu_water_spirit") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_shu_water_spiritAI(creature);
    }

    struct mob_shu_water_spiritAI : public ScriptedAI
    {
        mob_shu_water_spiritAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap _events;
        uint8 actualPlace;

        ObjectGuid waterSpoutGUID;

        enum eShuSpells
        {
            SPELL_WATER_SPOUT_SUMMON    = 116810,
            SPELL_WATER_SPOUT_WARNING   = 116695,
            SPELL_WATER_SPOUT_EJECT     = 116696,
            SPELL_WATER_SPOUT_VISUAL    = 117057
        };

        enum eEvents
        {
            EVENT_CHANGE_PLACE          = 1,
            EVENT_SUMMON_WATER_SPOUT    = 2,
            EVENT_WATER_SPOUT_VISUAL    = 3,
            EVENT_WATER_SPOUT_EJECT     = 4,
            EVENT_WATER_SPOUT_DESPAWN   = 5
        };

        void Reset() override
        {
            _events.Reset();
            actualPlace = 0;
            waterSpoutGUID = ObjectGuid::Empty;

            _events.ScheduleEvent(EVENT_CHANGE_PLACE, 5000);
        }

        void MovementInform(uint32 typeId, uint32 pointId) override
        {
            if (typeId != EFFECT_MOTION_TYPE)
                return;

            if (pointId == 1)
            {
                me->RemoveAurasDueToSpell(SPELL_WATER_SPOUT_WARNING);
                if (Player* player = me->SelectNearestPlayer(50.0f))
                {
                    me->SetOrientation(me->GetAngle(player));
                    me->SetFacingToObject(player);
                    _events.ScheduleEvent(EVENT_SUMMON_WATER_SPOUT, 2000);
                }
                else
                    _events.ScheduleEvent(EVENT_CHANGE_PLACE, 5000);
            }
        }

        Creature* getWaterSpout()
        {
            return me->GetMap()->GetCreature(waterSpoutGUID);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            switch (_events.ExecuteEvent())
            {
                case EVENT_CHANGE_PLACE:
                {
                    uint8 newPlace = 0;

                    do
                    {
                        newPlace = urand(0, 3);
                    }
                    while (newPlace == actualPlace);

                    me->GetMotionMaster()->MoveJump(rocksPos[newPlace].GetPositionX(), rocksPos[newPlace].GetPositionY(), rocksPos[newPlace].GetPositionZ(), 10.0f, 10.0f, 10.0f, 1);
                    me->AddAura(SPELL_WATER_SPOUT_WARNING, me); // Just visual
                    actualPlace = newPlace;
                    break;
                }
                case EVENT_SUMMON_WATER_SPOUT:
                {
                    float x = 0.0f, y = 0.0f;
                    GetPositionWithDistInOrientation(me, 5.0f, me->GetOrientation() + frand(-float(M_PI), float(M_PI)), x, y);
                    waterSpoutGUID = ObjectGuid::Empty;

                    if (Creature* waterSpout = me->SummonCreature(60488, x, y, 92.189629f))
                        waterSpoutGUID = waterSpout->GetGUID();

                    _events.ScheduleEvent(EVENT_WATER_SPOUT_VISUAL, 500);
                    _events.ScheduleEvent(EVENT_WATER_SPOUT_EJECT, 7500);
                    break;
                }
                case EVENT_WATER_SPOUT_VISUAL:
                {
                    if (Creature* waterSpout = getWaterSpout())
                        waterSpout->CastSpell(waterSpout, SPELL_WATER_SPOUT_WARNING, true);
                    break;
                }
                case EVENT_WATER_SPOUT_EJECT:
                {
                    if (Creature* waterSpout = getWaterSpout())
                    {
                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, waterSpout, 1.0f);

                        for (auto player: playerList)
                            player->CastSpell(player, SPELL_WATER_SPOUT_EJECT, true);

                        waterSpout->CastSpell(waterSpout, SPELL_WATER_SPOUT_VISUAL, true);
                    }
                    _events.ScheduleEvent(EVENT_WATER_SPOUT_DESPAWN, 3000);
                    break;
                }
                case EVENT_WATER_SPOUT_DESPAWN:
                {
                    if (Creature* waterSpout = getWaterSpout())
                        waterSpout->DespawnOrUnsummon();

                    waterSpoutGUID = ObjectGuid::Empty;

                    _events.ScheduleEvent(EVENT_CHANGE_PLACE, 2000);
                    break;
                }
            }
        }
    };
};

// Shu Benediction - 103245
class spell_shu_benediction: public SpellScriptLoader
{
    public:
        spell_shu_benediction() : SpellScriptLoader("spell_shu_benediction") { }

        class spell_shu_benediction_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shu_benediction_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (!target)
                    return;

                std::list<Creature*> shuList;
                GetCreatureListWithEntryInGrid(shuList, target, 55213, 20.0f);

                for (auto shu: shuList)
                    if (shu->ToTempSummon())
                        if (shu->ToTempSummon()->GetOwnerGUID() == target->GetGUID())
                            return;

                // A partir d'ici on sait que le joueur n'a pas encore de Huo
                if (TempSummon* tempShu = target->SummonCreature(55213, target->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, true))
                {
                    tempShu->SetOwnerGUID(target->GetGUID());
                    tempShu->GetMotionMaster()->MoveFollow(target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (!target)
                    return;

                std::list<Creature*> shuList;
                GetCreatureListWithEntryInGrid(shuList, target, 55213, 20.0f);

                for (auto shu: shuList)
                    if (shu->ToTempSummon())
                        if (shu->ToTempSummon()->GetOwnerGUID() == target->GetGUID())
                            shu->DespawnOrUnsummon();
            }

            void Register() override
            {
                OnEffectApply  += AuraEffectApplyFn (spell_shu_benediction_AuraScript::OnApply,  EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                OnEffectRemove += AuraEffectRemoveFn(spell_shu_benediction_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_shu_benediction_AuraScript();
        }
};

// Grab Carriage - 115904
class spell_grab_carriage: public SpellScriptLoader
{
    public:
        spell_grab_carriage() : SpellScriptLoader("spell_grab_carriage") { }

        class spell_grab_carriage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_grab_carriage_SpellScript);

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                if (!caster)
                    return;

                Creature* carriage = NULL;
                Creature* yak      = NULL;

                if (caster->GetAreaId() == 5826) // Bassins chantants
                {
                    carriage = caster->SummonCreature(57208, 979.06f, 2863.87f, 87.88f, 4.7822f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);
                    yak      = caster->SummonCreature(57207, 979.37f, 2860.29f, 88.22f, 4.4759f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);
                }
                else if (caster->GetAreaId() == 5881) // Ferme Dai-Lo
                {
                    carriage = caster->SummonCreature(57208, 588.70f, 3165.63f, 88.86f, 4.4156f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);
                    yak      = caster->SummonCreature(59499, 587.61f, 3161.91f, 89.31f, 4.3633f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);
                }
                else if (caster->GetAreaId() == 5833) // Epave du Chercheciel
                {
                    carriage = caster->SummonCreature(57208, 264.37f, 3867.60f, 73.56f, 0.9948f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);
                    yak      = caster->SummonCreature(57743, 268.38f, 3872.36f, 74.50f, 0.8245f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);
                }

                if (!carriage || !yak)
                    return;

                //carriage->CastSpell(yak, 108627, true);
                carriage->GetMotionMaster()->MoveFollow(yak, 0.0f, float(M_PI));
                caster->EnterVehicle(carriage, 0);
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_grab_carriage_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_grab_carriage_SpellScript();
        }
};

class npc_nourished_yak : public CreatureScript
{
public:
    npc_nourished_yak() : CreatureScript("npc_nourished_yak") { }

    struct npc_nourished_yakAI : public npc_escortAI
    {
        npc_nourished_yakAI(Creature* creature) : npc_escortAI(creature)
        {}

        uint32 IntroTimer;
        uint8 waypointToEject;

        void Reset() override
        {
            uint8 waypointToEject = 100;

            if (me->IsSummon())
            {
                IntroTimer = 2500;

                // Bassins chantants -> Dai-Lo
                if (me->GetAreaId() == 5826)
                    waypointToEject = 24;
                // Dai-Lo -> Temple
                else if (me->GetAreaId() == 5881) // Ferme Dai-Lo
                    waypointToEject = 22;
                // Epave -> Temple
                else if (me->GetAreaId() == 5833) // Epave du Chercheciel
                    waypointToEject = 18;
            }
            else
                IntroTimer = 0;
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == waypointToEject)
            {
                if (Creature* vehicle = GetClosestCreatureWithEntry(me, 57208, 50.0f))
                    if (vehicle->GetVehicleKit())
                        vehicle->GetVehicleKit()->RemoveAllPassengers();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    Start(false, true);
                    IntroTimer = 0;
                }
                else
                    IntroTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nourished_yakAI(creature);
    }

};

class npc_water_spirit_dailo : public CreatureScript
{
public:
    npc_water_spirit_dailo() : CreatureScript("npc_water_spirit_dailo") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(29774) == QUEST_STATUS_INCOMPLETE)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Can you please help us to wake up Wugou ?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            CloseGossipMenuFor(player);
            player->KilledMonsterCredit(55548);
            player->RemoveAurasDueToSpell(59073); // Remove Phase 2, first water spirit disapear

            if (Creature* shu = player->SummonCreature(55558, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0, true))
            {
                if (shu->AI())
                {
                    shu->AI()->DoAction(0);
                    shu->AI()->SetGUID(player->GetGUID());
                }
            }
        }
        return true;
    }

    struct npc_water_spirit_dailoAI : public ScriptedAI
    {
        npc_water_spirit_dailoAI(Creature* creature) : ScriptedAI(creature) {}

        ObjectGuid playerGuid;
        uint16 eventTimer;
        uint8  eventProgress;

        void Reset() override
        {
            eventTimer      = 0;
            eventProgress   = 0;
            playerGuid      = ObjectGuid::Empty;
        }

        void DoAction(const int32 /*actionId*/) override
        {
            eventTimer = 2500;
        }

        void SetGUID(ObjectGuid guid, int32 /*type*/) override
        {
            playerGuid = guid;
        }

        void MovementInform(uint32 typeId, uint32 pointId) override
        {
            if (typeId != POINT_MOTION_TYPE)
                return;

            switch (pointId)
            {
                case 1:
                    eventTimer = 250;
                    ++eventProgress;
                    break;
                case 2:
                    eventTimer = 250;
                    ++eventProgress;
                    break;
                case 3:
                    if (Creature* wugou = GetClosestCreatureWithEntry(me, 60916, 20.0f))
                        me->SetFacingToObject(wugou);
                    eventTimer = 2000;
                    ++eventProgress;
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (eventTimer)
            {
                if (eventTimer <= diff)
                {
                    switch (eventProgress)
                    {
                        case 0:
                            me->GetMotionMaster()->MovePoint(1, 650.30f, 3127.16f, 89.62f);
                            eventTimer = 0;
                            break;
                        case 1:
                            me->GetMotionMaster()->MovePoint(2, 625.25f, 3127.88f, 87.95f);
                            eventTimer = 0;
                            break;
                        case 2:
                            me->GetMotionMaster()->MovePoint(3, 624.44f, 3142.94f, 87.75f);
                            eventTimer = 0;
                            break;
                        case 3:
                            if (Creature* wugou = GetClosestCreatureWithEntry(me, 60916, 20.0f))
                                wugou->CastSpell(wugou, 118027, false);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            eventTimer = 3000;
                            ++eventProgress;
                            break;
                        case 4:
                            eventTimer = 0;
                            if (Player* owner = ObjectAccessor::FindPlayer(playerGuid))
                            {
                                owner->KilledMonsterCredit(55547);
                                owner->RemoveAurasDueToSpell(59074); // Remove phase 4, asleep wugou disappear

                                if (Creature* wugou = GetClosestCreatureWithEntry(me, 60916, 20.0f))
                                    if (Creature* newWugou = owner->SummonCreature(60916, wugou->GetPositionX(), wugou->GetPositionY(), wugou->GetPositionZ(), wugou->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0))
                                        newWugou->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);

                                me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, -PET_FOLLOW_ANGLE);
                            }
                            break;
                        default:
                            break;
                    }
                }
                else
                    eventTimer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_water_spirit_dailoAI(creature);
    }
};

class AreaTrigger_at_middle_temple_from_east : public AreaTriggerScript
{
    public:
        AreaTrigger_at_middle_temple_from_east() : AreaTriggerScript("AreaTrigger_at_middle_temple_from_east") {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
        {
            if (Creature* shu = GetClosestCreatureWithEntry(player, 55558, 25.0f))
                shu->DespawnOrUnsummon();

            if (Creature* wugou = GetClosestCreatureWithEntry(player, 60916, 25.0f))
                wugou->DespawnOrUnsummon();

            return true;
        }
};

#define ACTION_TALK_1 1
#define ACTION_TALK_2 2

class mob_delivery_cart_tender : public CreatureScript
{
public:
    mob_delivery_cart_tender() : CreatureScript("mob_delivery_cart_tender") { }

    struct mob_delivery_cart_tenderAI : public ScriptedAI
    {
        mob_delivery_cart_tenderAI(Creature* creature) : ScriptedAI(creature)
        {
            hasSaidIntro  = false;
            hasSaidIntro2 = false;
        }

        bool hasSaidIntro;
        bool hasSaidIntro2;

        void DoAction(const int32 actionId) override
        {
            if (actionId == ACTION_TALK_1)
            {
                if (!hasSaidIntro)
                {
                    Talk(0);
                    hasSaidIntro = true;
                }
            }
            else if (actionId == ACTION_TALK_2)
                if (!hasSaidIntro2)
                {
                    Talk(1);
                    hasSaidIntro2 = true;
                }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 15.0f);

            for (auto player: playerList)
            {
                if (me->GetPositionX() == 974.718994f && me->GetPositionY() == 2863.25)
                    DoAction(ACTION_TALK_1);
                else if (player->GetQuestStatus(29775) == QUEST_STATUS_COMPLETE)
                    DoAction(ACTION_TALK_2);
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_delivery_cart_tenderAI(creature);
    }
};


class npc_ji_firepaw_killcredit : public CreatureScript
{
    public:
        npc_ji_firepaw_killcredit() : CreatureScript("npc_ji_firepaw_killcredit") { }

        struct npc_ji_firepaw_killcreditAI : public ScriptedAI
        {
            npc_ji_firepaw_killcreditAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            uint64 m_CheckTimer;

            void Reset() override
            {
                m_CheckTimer = 2000;
            }

            void UpdateAI(uint32 p_Diff) override
            {
                if (m_CheckTimer)
                {
                    if (m_CheckTimer <= p_Diff)
                    {
                        std::list<Player*> l_PlayerList;
                        GetPlayerListInGrid(l_PlayerList, me, 15.0f);

                        for (Player* l_Player : l_PlayerList)
                        {
                            if (l_Player->GetQuestStatus(29680) == QUEST_STATUS_INCOMPLETE && l_Player->GetQuestObjectiveCounter(276325) < 1)
                                l_Player->KilledMonsterCredit(57710);
                        }

                        m_CheckTimer = 1500;
                    }
                    else
                        m_CheckTimer -= p_Diff;
                }
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_ji_firepaw_killcreditAI(creature);
        }
};

class playerScript_AutoAcceptQuest: public PlayerScript
{
    public:
        playerScript_AutoAcceptQuest() : PlayerScript("playerScript_AutoAcceptQuest") { }

        void OnQuestReward(Player* p_Player, const Quest* p_Quest) override
        {
            if (p_Quest->GetQuestId() == QUEST_SPIRIT_OF_WATER)
            {
                if (const Quest* l_Quest = sObjectMgr->GetQuestTemplate(QUEST_A_NEW_FRIEND))
                    p_Player->AddQuest(l_Quest, nullptr);
            }
        }
};

void AddSC_WanderingIsland_East()
{
    new AreaTrigger_at_bassin_curse();
    new vehicle_balance_pole();
    new mob_tushui_monk();
    new spell_rock_jump();
    new mob_shu_water_spirit();
    new spell_shu_benediction();
    new spell_grab_carriage();
    new npc_nourished_yak();
    new npc_water_spirit_dailo();
    new mob_delivery_cart_tender();
    new npc_ji_firepaw_killcredit();
    new playerScript_AutoAcceptQuest();
}
