/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CreatureAIImpl.h"
#include "GameTime.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "Player.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Vehicle.h"
#include "GridNotifiers.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "Creature.h"
#include "TemporarySummon.h"
#include "GameObject.h"
#include "G3D/Vector3.h"
#include <list>
#include <vector>

#include "Custom_Instance_Deadmines.h"

namespace Scripts::EasternKingdoms::Deadmines
{
    // 49552 - Rope Anchor
    struct npc_rope_ship : public ScriptedAI
    {
        npc_rope_ship(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
        }

        void Reset() override
        {
            if (TempSummon* summon = me->ToTempSummon())
                if (Creature* summoner = summon->GetSummonerCreatureBase())
                    DoCast(summoner, Spells::VanessaVanCleef::RopeBeam);
        }
    };

    // 49481 - Collapsing Icicle
    struct npc_icycle_dm : public PassiveAI
    {
        npc_icycle_dm(Creature* creature) : PassiveAI(creature) { }

        void Reset() override
        {
            _events.ScheduleEvent(Events::VanessaVanCleef::IcicleAOE, 10s);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case Events::VanessaVanCleef::IcicleAOE:
                        DoCastSelf(Spells::VanessaVanCleef::IcicleVisual);
                        if (Player* player = me->SelectNearestPlayer(20.0f))
                            DoCast(player, Spells::VanessaVanCleef::IcicleDamage);
                        _events.ScheduleEvent(Events::VanessaVanCleef::IcicleAOE, 10s);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
    };

    // 49564 - A Note From Vanessa
    struct npc_note : public ScriptedAI
    {
        npc_note(Creature* creature) : ScriptedAI(creature)
        {
            me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }

        void Reset() override
        {
            _events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::NoteSummon:
                        me->SummonCreature(Creatures::VanessaIntro, Positions::VanessaIntroSpawn, TEMPSUMMON_MANUAL_DESPAWN);
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            if (gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                _events.ScheduleEvent(Events::VanessaVanCleef::NoteSummon, 5s);
            }
            return true;
        }

    private:
        EventMap _events;
    };

    // 49454 - Vanessa's Trap Bunny
    struct npc_magma_pull : public ScriptedAI
    {
        npc_magma_pull(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            Talk(Texts::VanessaVanCleef::VanessaTrapBunnyWarning);
        }

        void SetData(uint32 id, uint32 value) override
        {
            if (id == 1 && value == 1)
                _triggered = true;
        }

        uint32 GetData(uint32 id) const override
        {
            if (id == 1)
                return _triggered ? 1 : 0;
            return 0;
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE || pointId != 0)
                return;

            _step++;
            if (_step < 5)
                _events.ScheduleEvent(Events::VanessaVanCleef::TrapDescent, 0s);
            else
                me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override
        {
            if (_triggered)
            {
                _triggered = false;
                _events.ScheduleEvent(Events::VanessaVanCleef::TrapPullPlayers, 0s);
            }

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::TrapPullPlayers:
                    {
                        std::list<Player*> players;
                        me->GetPlayerListInGrid(players, 50.0f);
                        for (Player* player : players)
                            if (player->IsAlive())
                                player->CastSpell(me, Spells::VanessaVanCleef::GenericRideVehicle);

                        me->NearTeleportTo(Positions::MagmaPullPlayers);
                        if (Creature* ropeAnchor = me->SummonCreature(Creatures::RopeAnchor, Positions::MagmaRopeCeiling, TEMPSUMMON_TIMED_DESPAWN, 30s))
                            ropeAnchor->SetDisableGravity(true);

                        me->SummonCreature(Creatures::VanessaNightmare, Positions::VanessaNightmare1, TEMPSUMMON_MANUAL_DESPAWN);

                        if(Creature* glubtok = me->SummonCreature(Creatures::NightmareGlubtok, Positions::GlubtokNightmare1, TEMPSUMMON_CORPSE_DESPAWN))
                            glubtok->SetReactState(REACT_PASSIVE);

                        _step = 0;
                        _events.ScheduleEvent(Events::VanessaVanCleef::TrapDescent, 1s);
                        break;
                    }
                    case Events::VanessaVanCleef::TrapDescent:
                    {
                        if (_step == 0)
                        {
                            Talk(Texts::VanessaVanCleef::VanessaTrapBunnyValves);

                            std::list<Creature*> valves;
                            me->GetCreatureListWithEntryInGrid(valves, Creatures::SteamValve, 30.f);
                            for (Creature* valve : valves)
                                valve->CastSpell(valve, Spells::VanessaVanCleef::GreenMarker);
                        }

                        float targetZ = Positions::MagmaPullPlayers.GetPositionZ() - ((_step + 1) * 2.0f);
                        Position dest(Positions::MagmaPullPlayers.GetPositionX(), Positions::MagmaPullPlayers.GetPositionY(), targetZ);
                        me->GetMotionMaster()->MovePoint(0, dest, false, {}, 0.2f);
                        break;
                    }
                    default:
                        break;
                }
            }
        }

    private:
        bool _triggered = false;
        uint8 _step = 0;
        EventMap _events;
    };

    // 49550 - Rope
    struct npc_rope_away : public ScriptedAI
    {
        npc_rope_away(Creature* creature) : ScriptedAI(creature)
        {
            me->SetNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            me->SetDisableGravity(true);
        }

        void Reset() override
        {
            me->SetSpeedRate(MOVE_RUN, 1.2f);

            me->SummonCreature(Creatures::RopeAnchor, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 40.f, 0, TEMPSUMMON_TIMED_DESPAWN, 40s);
        }

        void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
        {
            if (passenger->GetTypeId() == TYPEID_PLAYER)
                if (apply)
                    _events.ScheduleEvent(Events::VanessaVanCleef::RopeStartRide, 500ms);
        }

        void MovementInform(uint32 /*type*/, uint32 pointId) override
        {
            if (pointId == Points::VanessaVanCleef::RopeOut)
            {
                Position homePos = me->GetHomePosition();
                me->GetMotionMaster()->MovePoint(Points::VanessaVanCleef::RopeHome, homePos.GetPositionX(), homePos.GetPositionY(), homePos.GetPositionZ() + 5.f, false);
            }

            if (pointId == Points::VanessaVanCleef::RopeHome)
            {
                if (Vehicle* kit = me->GetVehicleKit())
                    kit->RemoveAllPassengers();

                me->RemoveAllAuras();
                me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::RopeStartRide:
                        me->GetMotionMaster()->MovePoint(Points::VanessaVanCleef::RopeOut, me->GetPositionX(), me->GetPositionY() - 80.f, me->GetPositionZ() + 10.f, false);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
    };

    // 49520 - Lightning Platter
    struct npc_lightning_orbs : public ScriptedAI
    {
        npc_lightning_orbs(Creature* creature) : ScriptedAI(creature), _summons(me)
        {
            me->SetUninteractible(true);
            me->SetDisableGravity(true);
            me->SetSessile(true);
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            _summons.Despawn(summon);
        }

        void OnDespawn() override
        {
            _summons.DespawnAll();
        }

        void Reset() override
        {
            _events.ScheduleEvent(1, 100ms);

            if (Vehicle* vehicle = me->GetVehicleKit())
                for (uint8 i = 0; i < 8; i++)
                    if (vehicle->HasEmptySeat(i))
                        if (Creature* pas = me->SummonCreature(Creatures::SparkPassenger, me->GetPosition()))
                        {
                            pas->SetSessile(true);
                            pas->EnterVehicle(me, i);
                        }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case 1:
                        me->SetOrientation(me->GetOrientation() + 0.05233f);
                        me->SetFacingTo(me->GetOrientation());
                        _events.ScheduleEvent(1, 100ms);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        SummonList _summons;
    };

    // 48445 - Oaf Lackey
    struct npc_oaf_lackey : public ScriptedAI
    {
        npc_oaf_lackey(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            _enrageCast = false;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _events.ScheduleEvent(Events::VanessaVanCleef::SummonAdd1, 4s);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (!_enrageCast && me->HealthBelowPct(35))
            {
                _enrageCast = true;
                DoCastSelf(Spells::VanessaVanCleef::Enrage);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::SummonAdd1:
                        DoCastVictim(Spells::VanessaVanCleef::AxeHead);
                        _events.ScheduleEvent(Events::VanessaVanCleef::SummonAdd1, 8s);
                        break;
                    default:
                        break;
                }
            }

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        bool _enrageCast = false;
    };

    // 48279 - Goblin Overseer
    struct npc_goblin_overseer : public ScriptedAI
    {
        npc_goblin_overseer(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            _threateningCast = false;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _events.ScheduleEvent(Events::VanessaVanCleef::SummonAdd1, 5s);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (!_threateningCast && me->HealthBelowPct(50))
            {
                _threateningCast = true;
                DoCastSelf(Spells::VanessaVanCleef::Threatening);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::SummonAdd1:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, true))
                            DoCast(target, Spells::VanessaVanCleef::Motivate);
                        _events.ScheduleEvent(Events::VanessaVanCleef::SummonAdd1, 10s);
                        break;
                    default:
                        break;
                }
            }

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        bool _threateningCast = false;
    };

    // 49532 - Enraged Worgen
    struct npc_enraged_worgen_dm : public ScriptedAI
    {
        npc_enraged_worgen_dm(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* vanessa = me->FindNearestCreature(Creatures::VanessaNightmare, 200.0f))
                vanessa->AI()->SetData(1, 1);
        }
    };

    // 49539 - James Harrington
    struct npc_james_dm : public ScriptedAI
    {
        npc_james_dm(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->m_Events.AddEventAtOffset([this]()
            {
                if (Vehicle* vehicle = me->GetVehicleKit())
                    if (vehicle->GetPassenger(0))
                        return;

                if (Creature* Calissa = me->FindNearestCreature(Creatures::CalissaHarrington, 20.f))
                {
                    Calissa->EnterVehicle(me, 0);
                    Calissa->Attack(me, true);
                }
            }, 500ms);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirEffect);
                instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirRipsnarl);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirRipsnarlRemove);
            if (Creature* vanessa = me->FindNearestCreature(Creatures::VanessaNightmare, 200.0f))
                vanessa->AI()->SetData(2, 2);

            Talk(Texts::VanessaVanCleef::JamesHarrington0);

            if (Creature* Calissa = me->FindNearestCreature(Creatures::CalissaHarrington, 20.f))
            {
                Calissa->SetStandState(UNIT_STAND_STATE_DEAD);
                Calissa->m_Events.AddEventAtOffset([Calissa]()
                    {
                        if (Calissa)
                            Calissa->ExitVehicle();
                    }, std::chrono::milliseconds(500));

                Calissa->m_Events.AddEventAtOffset([Calissa]()
                    {
                        if (Calissa)
                            Calissa->AI()->Talk(Texts::VanessaVanCleef::CalissaHarrington0);
                    }, std::chrono::seconds(4));

                Calissa->m_Events.AddEventAtOffset([Calissa]()
                    {
                        if (Calissa)
                            Calissa->AI()->Talk(Texts::VanessaVanCleef::CalissaHarrington1);
                    }, std::chrono::seconds(10));
            }
        }
    };

    // 49429 - Vanessa VanCleef (intro spawn)
    struct npc_vanessa_intro : public ScriptedAI
    {
        npc_vanessa_intro(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            me->AddAura(Spells::VanessaVanCleef::Sitting, me);
            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            Talk(Texts::VanessaVanCleef::VanessaIntroWarning);
            _events.ScheduleEvent(Events::VanessaVanCleef::IntroSay1, 3s);
            _events.ScheduleEvent(Events::VanessaVanCleef::IntroJump, 5s);
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type == EFFECT_MOTION_TYPE && pointId == EVENT_JUMP)
                _events.ScheduleEvent(Events::VanessaVanCleef::IntroLaugh, 2s);
            else if (type == POINT_MOTION_TYPE && pointId == 0)
            {
                Talk(Texts::VanessaVanCleef::VanessaSay3);
                _events.ScheduleEvent(Events::VanessaVanCleef::IntroSay4, 8s);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::IntroSay1:
                        Talk(Texts::VanessaVanCleef::VanessaSay1);
                        break;
                    case Events::VanessaVanCleef::IntroJump:
                    {
                        me->RemoveAura(Spells::VanessaVanCleef::Sitting);
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        if (Creature* bunny = me->GetMap()->GetCreatureBySpawnId(CreatureSpawns::CuldronSpawnBunny))
                        {
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveJump(EVENT_JUMP, bunny->GetPosition(), 10.0f, {}, 8.0f);
                        }
                        break;
                    }
                    case Events::VanessaVanCleef::IntroLaugh:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                        _events.ScheduleEvent(Events::VanessaVanCleef::IntroMove, 2s);
                        break;
                    case Events::VanessaVanCleef::IntroMove:
                        me->SetWalk(true);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(0, Positions::VanessaIntroMoveTo);
                        Talk(Texts::VanessaVanCleef::VanessaSay2);
                        break;
                    case Events::VanessaVanCleef::IntroSay4:
                    {
                        if (Creature* bunny = me->GetMap()->GetCreatureBySpawnId(CreatureSpawns::CuldronSpawnBunny))
                            me->SetFacingToObject(bunny);
                        Talk(Texts::VanessaVanCleef::VanessaSay4);
                        _events.ScheduleEvent(Events::VanessaVanCleef::IntroConcoction, 3s);
                        break;
                    }
                    case Events::VanessaVanCleef::IntroConcoction:
                        DoCastAOE(Spells::VanessaVanCleef::NoxiousConcoction);
                        _events.ScheduleEvent(Events::VanessaVanCleef::IntroElixir, 3s);
                        break;
                    case Events::VanessaVanCleef::IntroElixir:
                    {
                        DoCastAOE(Spells::VanessaVanCleef::NightmareElixir);
                        if (InstanceScript* instance = me->GetInstanceScript())
                            instance->SetData(Misc::VindicatorElixirTime, uint32(GameTime::GetGameTime()));
                        Talk(Texts::VanessaVanCleef::VanessaSay5);
                        _events.ScheduleEvent(Events::VanessaVanCleef::IntroSummonTrap, 0s);
                        _events.ScheduleEvent(Events::VanessaVanCleef::IntroBlackout1, 4s);
                        _events.ScheduleEvent(Events::VanessaVanCleef::IntroBlackout2, 6s);
                        me->DespawnOrUnsummon(10s);
                        break;
                    }
                    case Events::VanessaVanCleef::IntroSummonTrap:
                        me->SummonCreature(Creatures::TrapBunny, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
                        break;
                    case Events::VanessaVanCleef::IntroBlackout1:
                    case Events::VanessaVanCleef::IntroBlackout2:
                    {
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        for (MapReference const& ref : players)
                        {
                            if (Player* player = ref.GetSource())
                                player->CastSpell(player, Spells::VanessaVanCleef::Blackout, true);
                        }
                        if (eventId == Events::VanessaVanCleef::IntroBlackout2)
                        {
                            if (Creature* trapBunny = me->FindNearestCreature(Creatures::TrapBunny, 50.0f))
                                trapBunny->AI()->SetData(1, 1);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
    };

    // 49671 - Vanessa VanCleef (nightmare)
    struct npc_vanessa_nightmare : public ScriptedAI
    {
        npc_vanessa_nightmare(Creature* creature) : ScriptedAI(creature), _summons(me) { }

        void Reset() override
        {
            _events.Reset();
            _bossKilled = 0;
            _worgenKilled = 0;
            _jamesKilled = false;
            _finalTriggered = false;
            _summons.DespawnAll();
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetReactState(REACT_PASSIVE);
            SetActiveNightmare(0);
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            _summons.Despawn(summon);
        }

        void SummonAllFires()
        {
            for (uint8 i = 0; i < 43; ++i)
                me->SummonCreature(Creatures::FireBunny, Positions::FieryBlaze[i], TEMPSUMMON_MANUAL_DESPAWN);
        }

        void SummonAllSpiders()
        {
            if(Creature* bunny = me->GetMap()->GetCreatureBySpawnId(CreatureSpawns::HelixNightmareMainSpiderBunny))
                me->SummonCreature(Creatures::MainSpider, bunny->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN);

            uint32 spiderEntry = RAND(Creatures::NightmareSpider, Creatures::ChatteringHorror);

            for (uint8 i = 0; i < 3; ++i)
                me->SummonCreature(spiderEntry, Positions::NightmareSpidersSpawn[i], TEMPSUMMON_CORPSE_DESPAWN);
        }

        void SummonAllSparks()
        {
            for (uint8 i = 0; i < 7; ++i)
                me->SummonCreature(Creatures::Spark, Positions::ElectricSpark[i], TEMPSUMMON_MANUAL_DESPAWN);
        }

        uint8 GetActiveNightmare() const
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                return static_cast<uint8>(instance->GetData(Misc::ActiveNightmare));
            return 0;
        }

        void SetActiveNightmare(uint8 value)
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                instance->SetData(Misc::ActiveNightmare, value);
        }

        void TalkNightmareIntro(uint8 step)
        {
            uint8 nightmare = GetActiveNightmare();
            switch (step)
            {
                case 1:
                    switch (nightmare)
                    {
                        case 1: Talk(Texts::VanessaVanCleef::VanessaNightmareGlubtok1); break;
                        case 2: Talk(Texts::VanessaVanCleef::VanessaNightmareHelix1); break;
                        case 3: Talk(Texts::VanessaVanCleef::VanessaNightmareMechanical1); break;
                        case 4: Talk(Texts::VanessaVanCleef::VanessaNightmareRipsnarl1); break;
                    }
                    break;
                case 2:
                    switch (nightmare)
                    {
                        case 1: Talk(Texts::VanessaVanCleef::VanessaNightmareGlubtok2); break;
                        case 2: Talk(Texts::VanessaVanCleef::VanessaNightmareHelix2); break;
                        case 3: Talk(Texts::VanessaVanCleef::VanessaNightmareMechanical2); break;
                        case 4: Talk(Texts::VanessaVanCleef::VanessaNightmareRipsnarl2); break;
                    }
                    break;
            }
        }

        void SummonNightmareBoss()
        {
            uint8 nightmare = GetActiveNightmare();
            switch (nightmare)
            {
                case 1:
                {
                    Creature* glubtok = me->FindNearestCreature(Creatures::NightmareGlubtok, 20.0f, true);
                    if (glubtok)
                        glubtok->AI()->DoAction(Actions::GlubtokCharge);
                    break;
                }
                case 2:
                    SummonAllSpiders();
                    break;
                case 3:
                    if (Creature* mech = me->SummonCreature(Creatures::NightmareFoeReaper, Positions::FoeReaperNightmareSpawn, TEMPSUMMON_CORPSE_DESPAWN))
                        mech->AI()->DoAction(Actions::MechanicalEngage);
                    break;
                case 4:
                {
                    for (uint8 i = 0; i < 3; ++i)
                        me->SummonCreature(Creatures::EnragedWorgen, Positions::EnragedWorgen1[i], TEMPSUMMON_MANUAL_DESPAWN);
                    for (uint8 i = 0; i < 3; ++i)
                        me->SummonCreature(Creatures::EnragedWorgen, Positions::EnragedWorgen2[i], TEMPSUMMON_MANUAL_DESPAWN);
                    
                    me->SummonCreature(Creatures::EmmeHarrington, Positions::FamilySpawn[0], TEMPSUMMON_MANUAL_DESPAWN);
                    me->SummonCreature(Creatures::ErikHarrington, Positions::FamilySpawn[1], TEMPSUMMON_MANUAL_DESPAWN);
                    if (Creature* calissa = me->SummonCreature(Creatures::CalissaHarrington, Positions::FamilySpawn[3], TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        calissa->SetDisableGravity(false);
                        calissa->SetRegenerateHealth(false);
                    }
                    break;
                }
                case 5:
                {
                    if (InstanceScript* instance = me->GetInstanceScript())
                    {
                        instance->DoRemoveAurasDueToSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixir);
                        instance->DoRemoveAurasDueToSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirEffect);
                    }

                    me->SummonCreature(Creatures::VanessaVanCleef, Positions::VanessaBossSpawn, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10min);
                    me->DespawnOrUnsummon(3s);
                    break;
                }
            }
        }

        void HandleNightmareFade()
        {
            uint8 nightmare = GetActiveNightmare();
            switch (nightmare)
            {
                case 1:
                    Talk(Texts::VanessaVanCleef::VanessaNightmareGetBackToTheShip);
                    me->SetVisible(false);
                    me->NearTeleportTo(Positions::VanessaNightmare2);
                    break;
                case 2:
                    Talk(Texts::VanessaVanCleef::VanessaNightmare2Warning);
                    me->SetVisible(false);
                    //if(Creature* foe = me->SummonCreature(Creatures::NightmareFoeReaper, Positions::MechanicalNightmareSpawn, TEMPSUMMON_CORPSE_DESPAWN))
                    //    foe->SetReactState(REACT_PASSIVE);
                    me->NearTeleportTo(Positions::VanessaNightmare3);
                    break;
                case 3:
                    Talk(Texts::VanessaVanCleef::VanessaNightmare3Warning);
                    me->SetVisible(false);
                    me->NearTeleportTo(Positions::VanessaNightmare4);
                    break;
                case 4:
                    Talk(Texts::VanessaVanCleef::VanessaNightmare4Warning);
                    if (GameObject* IronDoor = me->FindNearestGameObject(Objects::IronCladDoor, 30.f))
                        IronDoor->SetGoState(GO_STATE_ACTIVE);
                    me->SetVisible(false);
                    me->NearTeleportTo(Positions::VanessaNightmare5);
                    break;
            }
        }

        void SetData(uint32 id, uint32 value) override
        {
            if (id == 4)
            {
                SummonAllFires();
                Talk(Texts::VanessaVanCleef::VanessaNightmareWarning);
                SetActiveNightmare(1);
                _events.ScheduleEvent(Events::VanessaVanCleef::NightmareSay1, 2s);
            }

            if (id == 1 && value == 1)
            {
                _worgenKilled++;

                if (GetActiveNightmare() == 4)
                {
                    if (_worgenKilled == 3)
                    {
                        Talk(Texts::VanessaVanCleef::VanessaNightmareSaveErik);
                        if (InstanceScript* instance = me->GetInstanceScript())
                            instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::Sprint);
                        me->NearTeleportTo(Positions::VanessaNightmare7);
                    }
                    else if (_worgenKilled == 6)
                    {
                        Talk(Texts::VanessaVanCleef::VanessaNightmareSaveCalissa);
                        if (InstanceScript* instance = me->GetInstanceScript())
                            instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::Sprint);

                        if (Creature* cannon = me->GetMap()->GetCreatureBySpawnId(CreatureSpawns::CannonFiring1))
                        {
                            cannon->SummonCreature(Creatures::JamesHarrington, cannon->GetPosition());
                            cannon->DespawnOrUnsummon(1s);
                        }
                        else
                            me->SummonCreature(Creatures::JamesHarrington, Positions::FamilySpawn[3], TEMPSUMMON_MANUAL_DESPAWN);
                    }
                }
            }

            if (id == 2 && value == 2)
            {
                Talk(Texts::VanessaVanCleef::VanessaNightmareElixirOff);
                _jamesKilled = true;
            }

            if (id == 3 && value == 3)
            {
                _bossKilled++;
                _events.ScheduleEvent(Events::VanessaVanCleef::NightmareShift, 0s);
                _events.ScheduleEvent(Events::VanessaVanCleef::NightmareElixirReapply, 3s);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::NightmareSay1:
                        TalkNightmareIntro(1);
                        _events.ScheduleEvent(Events::VanessaVanCleef::NightmareSay2, 7s);
                        break;
                    case Events::VanessaVanCleef::NightmareSay2:
                        TalkNightmareIntro(2);
                        _events.ScheduleEvent(Events::VanessaVanCleef::NightmareSummon, 2s);
                        if (GetActiveNightmare() == 4)
                            _events.ScheduleEvent(Events::VanessaVanCleef::NightmareSaveEmme, 5s);
                        break;
                    case Events::VanessaVanCleef::NightmareSummon:
                        SummonNightmareBoss();
                        if (GetActiveNightmare() < 5)
                            _events.ScheduleEvent(Events::VanessaVanCleef::NightmareFade, 2s);
                        break;
                    case Events::VanessaVanCleef::NightmareFade:
                        HandleNightmareFade();
                        break;
                    case Events::VanessaVanCleef::NightmareElixirReapply:
                        if (InstanceScript* instance = me->GetInstanceScript())
                            instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirEffect);
                        break;
                    case Events::VanessaVanCleef::NightmareSaveEmme:
                        if (InstanceScript* instance = me->GetInstanceScript())
                        {
                            Talk(Texts::VanessaVanCleef::VanessaNightmareSaveEmme);
                            instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::Sprint);
                            me->NearTeleportTo(Positions::VanessaNightmare6);
                        }
                        break;
                    case Events::VanessaVanCleef::NightmareShift:
                        Talk(Texts::VanessaVanCleef::VanessaNightmareShift);
                        _summons.DespawnAll();
                        me->SetVisible(true);
                        SetActiveNightmare(_bossKilled + 1);
                        if (GetActiveNightmare() == 2)
                            if (Creature* helix = me->SummonCreature(Creatures::NightmareHelix, Positions::HelixNightmareSpawn, TEMPSUMMON_CORPSE_DESPAWN))
                                helix->AI()->DoAction(Actions::HelixEngage);
                        if (GetActiveNightmare() == 3)
                        {
                            SummonAllSparks();
                            if (Creature* foe = me->SummonCreature(Creatures::NightmareFoeReaper, Positions::MechanicalNightmareSpawn))
                                foe->SetReactState(REACT_PASSIVE);
                        }
                        if (GetActiveNightmare() == 4)
                            me->SummonCreature(Creatures::JamesHarringtonHuman, Positions::FoeReaperNightmareSpawn);
                        if (GetActiveNightmare() < 5)
                            _events.ScheduleEvent(Events::VanessaVanCleef::NightmareSay1, 1s);
                        break;
                    default:
                        break;
                }
            }

            if (GetActiveNightmare() == 4 && _worgenKilled >= 6 && _jamesKilled && !_finalTriggered)
            {
                _finalTriggered = true;
                SetActiveNightmare(5);
                me->SetVisible(true);
                _events.ScheduleEvent(Events::VanessaVanCleef::NightmareSummon, 2s);
            }
        }

    private:
        EventMap _events;
        SummonList _summons;
        uint8 _bossKilled = 0;
        uint8 _worgenKilled = 0;
        bool _jamesKilled = false;
        bool _finalTriggered = false;
    };

    // 49670 - Nightmare Glubtok
    struct npc_glubtok_dm : public ScriptedAI
    {
        npc_glubtok_dm(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(Misc::ActiveNightmare) != 1)
                    _events.Reset();
            
        }

        void DoAction(int32 action) override
        {
            if (action == Actions::GlubtokCharge)
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                {
                    instance->SetData(Misc::ActiveNightmare, 1);
                    instance->HandleGameObject(instance->GetGuidData(Objects::FoundryDoor), false);
                    if (GameObject* ironCladDoor = me->GetMap()->GetGameObject(instance->GetGuidData(Objects::IronCladDoor)))
                        ironCladDoor->ResetDoorOrButton();
                }
                _events.ScheduleEvent(Events::VanessaVanCleef::GlubtokCharge, 5s);
            }
        }

        void EngageAfterTeleport()
        {
            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE_2);
            me->SetImmuneToPC(false);
            me->SetImmuneToNPC(false);
            me->SetReactState(REACT_AGGRESSIVE);
            _events.ScheduleEvent(Events::VanessaVanCleef::IcicleAOE, 11s, 15s);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirEffect);
                instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirGlubtok);
            }
            _events.ScheduleEvent(Events::VanessaVanCleef::IcicleAOE, 6s, 8s);
            _events.ScheduleEvent(Events::VanessaVanCleef::SpiritStrike, 6s);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirGlubtokRemove);
            if (Creature* vanessa = me->FindNearestCreature(Creatures::VanessaNightmare, 200.0f))
                vanessa->AI()->SetData(3, 3);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::GlubtokCharge:
                        me->NearTeleportTo(Positions::GlubtokNightmareCharge);
                        EngageAfterTeleport();
                        break;
                    case Events::VanessaVanCleef::IcicleAOE:
                        if (Unit* target = me->SelectNearestTarget(200.0f))
                        {
                            DoCast(target, Spells::VanessaVanCleef::Icicle);
                            me->SummonCreature(Creatures::CollapsingIcicle, target->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 17s);
                        }
                        _events.ScheduleEvent(Events::VanessaVanCleef::IcicleAOE, 8s);
                        break;
                    case Events::VanessaVanCleef::SpiritStrike:
                        if (Unit* target = me->SelectNearestTarget(200.0f))
                            DoCast(target, Spells::VanessaVanCleef::SpiritStrike);
                        _events.ScheduleEvent(Events::VanessaVanCleef::SpiritStrike, 10s);
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    // 49674 - Nightmare Helix
    struct npc_helix_dm : public ScriptedAI
    {
        npc_helix_dm(Creature* creature) : ScriptedAI(creature), _summons(me) { }

        void Reset() override
        {
            _events.Reset();
            _summons.DespawnAll();
            if (InstanceScript* instance = me->GetInstanceScript())
                if (instance->GetData(Misc::ActiveNightmare) > 0)
                    return;
            me->SetReactState(REACT_PASSIVE);
        }

        void DoAction(int32 action) override
        {
            if (action == Actions::HelixEngage)
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                    instance->SetData(Misc::ActiveNightmare, 2);
                _events.ScheduleEvent(Events::VanessaVanCleef::HelixEngage, 7s);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                
                case Creatures::MainSpider:
                    summon->SetObjectScale(0.1f);
                    summon->SetWalk(true);
                    summon->SetSpeed(MOVE_WALK, 0.1f);
                    break;
                case Creatures::NightmareSpider:
                case Creatures::ChatteringHorror:
                    if (Unit* victim = me->GetVictim())
                        summon->AI()->AttackStart(victim);
                    break;
            }
            _summons.Summon(summon);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirEffect);
                instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirHelix);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirHelixRemove);
                instance->HandleGameObject(instance->GetGuidData(Objects::FoundryDoor), true);
            }
            if (Creature* vanessa = me->FindNearestCreature(Creatures::VanessaNightmare, 200.0f))
                vanessa->AI()->SetData(3, 3);
            _summons.DespawnAll();
        }

        void SummonSpiders()
        {
            std::list<Creature*> bunnies;
            me->GetCreatureListWithEntryInGrid(bunnies, Creatures::GeneralPurposeBunny, 30.0f);
            for (Creature* bunny : bunnies)
            {
                if (!bunny)
                    continue;
                float x = bunny->GetPositionX() + frand(-3.0f, 3.0f);
                float y = bunny->GetPositionY() + frand(-3.0f, 3.0f);
                float z = bunny->GetPositionZ();
                me->SummonCreature(Creatures::NightmareSpider, Position(x, y, z), TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::HelixEngage:
                        me->SetEmoteState(EMOTE_ONESHOT_NONE);
                        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE_2);
                        me->SetImmuneToPC(false);
                        me->SetImmuneToNPC(false);
                        me->SetReactState(REACT_AGGRESSIVE);
                        _events.ScheduleEvent(Events::VanessaVanCleef::SpiritStrike, 6s, 8s);
                        _events.ScheduleEvent(Events::VanessaVanCleef::SummonSpiders, 5s);
                        break;
                    case Events::VanessaVanCleef::SpiritStrike:
                        DoCastVictim(Spells::VanessaVanCleef::SpiritStrike);
                        _events.ScheduleEvent(Events::VanessaVanCleef::SpiritStrike, 10s);
                        break;
                    case Events::VanessaVanCleef::SummonSpiders:
                        SummonSpiders();
                        _events.ScheduleEvent(Events::VanessaVanCleef::SummonSpiders, 10s, 15s);
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        SummonList _summons;
    };

    // 49681 - Nightmare Foe Reaper 5000
    struct npc_mechanical_dm : public ScriptedAI
    {
        npc_mechanical_dm(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
        }

        void JustReachedHome() override
        {
            DoAction(Actions::MechanicalEngage);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if(why == EvadeReason::NoHostiles)
                DoAction(Actions::MechanicalEngage);
        }

        void DoAction(int32 action) override
        {
            if (action == Actions::MechanicalEngage)
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                    instance->SetData(Misc::ActiveNightmare, 3);
                _events.ScheduleEvent(Events::VanessaVanCleef::MechanicalEngage, 5s);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirEffect);
                instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirMechanical);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                instance->DoCastSpellOnPlayers(Spells::VanessaVanCleef::NightmareElixirMechanicalRemove);
            if (Creature* vanessa = me->FindNearestCreature(Creatures::VanessaNightmare, 200.0f))
                vanessa->AI()->SetData(3, 3);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::MechanicalEngage:
                        me->SetEmoteState(EMOTE_ONESHOT_NONE);
                        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE_2);
                        me->SetImmuneToPC(false);
                        me->SetImmuneToNPC(false);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveAura(Spells::Offline);
                        _events.ScheduleEvent(Events::VanessaVanCleef::SpiritStrike, 6s, 8s);
                        break;
                    case Events::VanessaVanCleef::SpiritStrike:
                        DoCastVictim(Spells::VanessaVanCleef::SpiritStrike);
                        _events.ScheduleEvent(Events::VanessaVanCleef::SpiritStrike, 10s);
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    // 49541 - Vanessa VanCleef
    struct boss_vanessa_vancleef : public BossAI
    {
        boss_vanessa_vancleef(Creature* creature) : BossAI(creature, DataTypes::BOSS_VANESSA_VANCLEEF), ropeList(creature)
        {
            ApplyCrowdControlImmunities(me);
            me->setActive(true);
        }

        void Reset() override
        {
            _Reset();
            _disappearCount = 0;
            _disappearActive = false;
            _finalExplosion = false;
            _fireBunnyGuids.clear();
            me->SetVisible(true);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_PACIFIED);
            me->RemoveAura(Spells::VanessaVanCleef::AynashasRoot);
            me->SetReactState(REACT_AGGRESSIVE);
            ropeList.DespawnAll();
        }

        void JustEngagedWith(Unit* who) override
        {
            _JustEngagedWith(who);

            if (IsHeroic())
            {
                uint32 elixirTime = instance->GetData(Misc::VindicatorElixirTime);
                if (elixirTime && GameTime::GetGameTime() - elixirTime < 5 * MINUTE)
                {
                    if (AchievementEntry const* achievement = sAchievementStore.LookupEntry(Achievements::VigorousVanCleefVindicator))
                    {
                        instance->instance->DoOnPlayers([achievement](Player* player)
                        {
                            if (!player->HasAchieved(achievement->ID))
                                player->CompletedAchievement(achievement);
                        });
                    }
                }
            }

            Talk(Texts::VanessaVanCleef::Aggro);
            DoZoneInCombat();
            events.ScheduleEvent(Events::VanessaVanCleef::BossIntroMove, 2s);
            events.ScheduleEvent(Events::VanessaVanCleef::DeadlyBlades, 12s);
            events.ScheduleEvent(Events::VanessaVanCleef::Backslash, 15s);
            events.ScheduleEvent(Events::VanessaVanCleef::Deflection, 10s);
            events.ScheduleEvent(Events::VanessaVanCleef::SummonAdd1, 9s);
        }

        void JustDied(Unit* killer) override
        {
            Talk(Texts::VanessaVanCleef::VanessaDefeated3);
            DoCastSelf(Spells::VanessaVanCleef::PowderExplosion);

            BossAI::JustDied(killer);

            summons.DespawnAll();
            ropeList.DespawnAll();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim != me)
                Talk(Texts::VanessaVanCleef::KilledUnit);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            BossAI::SummonedCreatureDespawn(summon);

            if (summon->GetEntry() == Creatures::Rope)
                ropeList.Despawn(summon);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == EVENT_JUMP)
            {
                DoCastSelf(Spells::VanessaVanCleef::AynashasRoot);
            }
            else if (type == POINT_MOTION_TYPE && id == 1)
            {
                me->GetMotionMaster()->MoveJump(0, Position(-65.585f, -820.742f, 41.022f, 0.0f), 10.0f, {}, 5.0f);
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (!_disappearActive && !_finalExplosion)
            {
                if (_disappearCount == 0 && me->HealthBelowPctDamaged(50, damage))
                {
                    Talk(Texts::VanessaVanCleef::Bomb50pct);
                    _disappearCount = 1;
                    events.ScheduleEvent(Events::VanessaVanCleef::Disappear, 1s);
                }
                else if (_disappearCount == 1 && me->HealthBelowPctDamaged(25, damage))
                {
                    Talk(Texts::VanessaVanCleef::Bomb25pct);
                    _disappearCount = 2;
                    events.ScheduleEvent(Events::VanessaVanCleef::Disappear, 1s);
                }
            }

            if (!_finalExplosion && me->HealthBelowPctDamaged(1, damage))
            {
                _finalExplosion = true;
                damage = me->GetHealth() - 1;
                events.Reset();
                me->RemoveAllAuras();
                me->AttackStop();
                me->ClearAllReactives();
                me->SetReactState(REACT_PASSIVE);
                DoCastSelf(Spells::VanessaVanCleef::AynashasRoot);
                Talk(Texts::VanessaVanCleef::VanessaDefeated1);

                events.ScheduleEvent(Events::VanessaVanCleef::FinalTimer, 5s);
            }

            if (damage >= me->GetHealth())
            {
                damage = 0;
                me->SetHealth(1);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VanessaVanCleef::BossIntroMove:
                    {
                        Position pos = me->GetNearPosition(5.0f, me->GetOrientation());
                        me->GetMotionMaster()->MovePoint(1, pos);
                        break;
                    }
                    case Events::VanessaVanCleef::DeadlyBlades:
                        DoCastSelf(Spells::VanessaVanCleef::DeadlyBlades);
                        events.ScheduleEvent(Events::VanessaVanCleef::DeadlyBlades, 35s);
                        break;
                    case Events::VanessaVanCleef::Backslash:
                        DoCastVictim(Spells::VanessaVanCleef::Backslash);
                        events.ScheduleEvent(Events::VanessaVanCleef::Backslash, 17s);
                        break;
                    case Events::VanessaVanCleef::Deflection:
                        if (me->HealthAbovePct(25))
                            DoCastSelf(Spells::VanessaVanCleef::Deflection);
                        events.ScheduleEvent(Events::VanessaVanCleef::Deflection, 50s);
                        break;
                    case Events::VanessaVanCleef::SummonAdd1:
                        if (me->HealthAbovePct(50))
                        {
                            Talk(Texts::VanessaVanCleef::Summons);
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, false))
                                if (Creature* add = me->SummonCreature(Creatures::DefiasShadowguard, Positions::Shadowspawn[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5s))
                                    add->AI()->AttackStart(target);
                            events.ScheduleEvent(Events::VanessaVanCleef::SummonAdd2, 15s);
                        }
                        break;
                    case Events::VanessaVanCleef::SummonAdd2:
                        if (me->HealthAbovePct(50))
                        {
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, false))
                                if (Creature* add = me->SummonCreature(Creatures::DefiasEnforcer, Positions::Shadowspawn[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5s))
                                    add->AI()->AttackStart(target);
                            events.ScheduleEvent(Events::VanessaVanCleef::SummonAdd3, 15s);
                        }
                        break;
                    case Events::VanessaVanCleef::SummonAdd3:
                        if (me->HealthAbovePct(50))
                        {
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, false))
                                if (Creature* add = me->SummonCreature(Creatures::DefiasBloodWizzard, Positions::Shadowspawn[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5s))
                                    add->AI()->AttackStart(target);
                            events.ScheduleEvent(Events::VanessaVanCleef::SummonAdd1, 15s);
                        }
                        break;
                    case Events::VanessaVanCleef::Disappear:
                        DoDisappear();
                        events.ScheduleEvent(Events::VanessaVanCleef::SummonRope, 2s);
                        break;
                    case Events::VanessaVanCleef::SummonRope:
                        SummonRopes();
                        events.ScheduleEvent(Events::VanessaVanCleef::RopeReady, 1s);
                        break;
                    case Events::VanessaVanCleef::RopeReady:
                        RopeReady();
                        events.ScheduleEvent(Events::VanessaVanCleef::FireBoom, 10s);
                        break;
                    case Events::VanessaVanCleef::FireBoom:
                        FieryBoom();
                        events.ScheduleEvent(Events::VanessaVanCleef::ClearShip, 5s);
                        break;
                    case Events::VanessaVanCleef::ClearShip:
                        DoReappear();
                        break;
                    case Events::VanessaVanCleef::Shadowguard:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, false))
                            if (Creature* add = me->SummonCreature(Creatures::DefiasShadowguard, Positions::Shadowspawn[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5s))
                                add->AI()->AttackStart(target);
                        break;
                    case Events::VanessaVanCleef::Vengeance:
                        DoCastSelf(Spells::VanessaVanCleef::Vengeance);
                        break;
                    case Events::VanessaVanCleef::FinalTimer:
                        Talk(Texts::VanessaVanCleef::VanessaDefeated2);
                        events.ScheduleEvent(Events::VanessaVanCleef::FinalWarning, 3s);
                        break;
                    case Events::VanessaVanCleef::FinalWarning:
                        Talk(Texts::VanessaVanCleef::VanessaDetonation3);
                        DoCastSelf(Spells::VanessaVanCleef::VanessaCosmeticBombState);
                        events.ScheduleEvent(Events::VanessaVanCleef::FinalDetonation, 5s);
                        break;
                    case Events::VanessaVanCleef::FinalDetonation:
                    {
                        me->AttackStop();
                        me->ClearAllReactives();

                        Player* killer = nullptr;

                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        for (auto const& ref : players)
                        {
                            if (Player* p = ref.GetSource())
                            {
                                if (!killer)
                                    killer = p;
                                me->SetTappedBy(p);
                            }
                        }

                        if (killer)
                            killer->Kill(killer, me);

                        break;
                    }
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            if (!_disappearActive)
                me->DoMeleeAttackIfReady();
        }

    private:
        SummonList ropeList;
        std::vector<ObjectGuid> _fireBunnyGuids;
        uint8 _disappearCount = 0;
        bool _disappearActive = false;
        bool _finalExplosion = false;

        void DoDisappear()
        {
            me->RemoveAllAuras();
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_PACIFIED);
            //me->SetVisible(false);
            me->GetMotionMaster()->MoveJump(EVENT_JUMP, Positions::VanessaBossJumpAtopShip, 10.0f, {}, 5.0f);
            summons.DespawnAll();
            _disappearActive = true;
        }

        void DoReappear()
        {
            RemoveFiresFromShip();
            //me->SetVisible(true);
            me->RemoveAllAuras();
            me->GetMotionMaster()->MoveJump(0, Position(-65.93f, -820.33f, 40.98f, 0.0f), 10.0f, {}, 8.0f);
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_PACIFIED);
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, false))
                AttackStart(target);
            _disappearActive = false;
            if (_disappearCount == 1)
                events.ScheduleEvent(Events::VanessaVanCleef::Shadowguard, 27s);
            else if (_disappearCount == 2)
                events.ScheduleEvent(Events::VanessaVanCleef::Vengeance, 4s);
        }

        void SummonRopes()
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(Creatures::Rope, Positions::RopeSpawn[i], TEMPSUMMON_MANUAL_DESPAWN);
        }

        void RopeReady()
        {
            if(_disappearCount == 1)
                Talk(Texts::VanessaVanCleef::VanessaDetonation1);
            else if(_disappearCount == 2)
                Talk(Texts::VanessaVanCleef::VanessaDetonation2);

            for (ObjectGuid const& guid : ropeList)
            {
                if (Creature* rope = ObjectAccessor::GetCreature(*me, guid))
                    rope->CastSpell(rope, Spells::VanessaVanCleef::ClickMe, true);
            }

            SummonThreatController();
        }

        void SummonThreatController()
        {
            if (Creature* bunny = me->SummonCreature(Creatures::GeneralPurposeBunnyJMF, -52.31f, -820.18f, 51.91f, 3.32963f, TEMPSUMMON_MANUAL_DESPAWN))
            {
                bunny->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                bunny->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                bunny->SetUnitFlag(UNIT_FLAG_STUNNED);
                bunny->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                bunny->SetReactState(REACT_AGGRESSIVE);
                bunny->SetFaction(18);
                bunny->Attack(me, true);
                AddThreat(bunny, 200000.0f);
                me->SetInCombatWith(bunny);
            }
            DoZoneInCombat();
        }

        void FieryBoom()
        {
            std::list<Creature*> fiery;
            me->GetCreatureListWithEntryInGrid(fiery, Creatures::GeneralPurposeBunny, 150.0f);
            fiery.sort(Trinity::ObjectDistanceOrderPred(me));
            for (std::list<Creature*>::iterator itr = fiery.begin(); itr != fiery.end(); ++itr)
            {
                if ((*itr)->IsAlive() && (*itr)->GetTypeId() == TYPEID_UNIT)
                {
                    _fireBunnyGuids.push_back((*itr)->GetGUID());
                    (*itr)->CastSpell((*itr), Spells::VanessaVanCleef::FieryBlaze, true);
                }
            }
        }

        void RemoveFiresFromShip()
        {
            static const std::unordered_set<uint32> shipFireSpawnIds = {
                376125, 376110, 376126, 376109, 376139, 376138,
                376140, 376141, 376135, 376145, 376134, 376137,
                376127, 376129, 376133, 376144, 376128, 376142,
                376147, 376131, 376136, 376146
            };

            for (ObjectGuid const& guid : _fireBunnyGuids)
            {
                if (Creature* fire = ObjectAccessor::GetCreature(*me, guid))
                {
                    if (shipFireSpawnIds.count(fire->GetSpawnId()))
                        fire->RemoveAura(Spells::VanessaVanCleef::FieryBlaze);
                }
            }
            _fireBunnyGuids.clear();
        }
    };

    // 49457 - Steam Valve
    struct npc_steam_valve : public ScriptedAI
    {
        npc_steam_valve(Creature* creature) : ScriptedAI(creature)
        {
            me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }

        bool OnGossipHello(Player* player) override
        {
            InstanceScript* instance = me->GetInstanceScript();
            if (!instance)
                return false;

            me->RemoveAllAuras();
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

            uint8 count = instance->GetData(Misc::SteamValveCount);
            instance->SetData(Misc::SteamValveCount, count + 1);

            if (count + 1 >= 4)
            {
                for (MapReference const& ref : me->GetMap()->GetPlayers())
                {
                    Player* p = ref.GetSource();
                    if (!p || !p->IsInWorld())
                        continue;

                    if (p->GetVehicle())
                    {
                        Unit* vehicleBase = p->GetVehicle()->GetBase();
                        if (vehicleBase && vehicleBase->GetEntry() == Creatures::TrapBunny)
                        {
                            p->ExitVehicle(/*&Positions::MagmaPullPlayerExit*/);
                            p->GetMotionMaster()->Clear();
                            p->GetMotionMaster()->MoveJump(EVENT_JUMP, Positions::MagmaPullPlayerExit, 15.f, {}, 5.f);
                            p->m_Events.AddEventAtOffset([p]()
                            {
                                if (p && p->IsInWorld())
                                    p->CastSpell(p, Spells::VanessaVanCleef::NightmareElixirEffect, true);
                            }, 3s);
                        }
                    }
                }

                instance->SetData(Misc::SteamValveCount, 0);

                if (Creature* vanessaNightmare = me->FindNearestCreature(Creatures::VanessaNightmare, 50.f))
                    vanessaNightmare->AI()->SetData(4, 1);
            }

            player->PlayerTalkClass->SendCloseGossip();
            return true;
        }
    };
}

void AddSC_custom_deadmines_vanessa_vancleef()
{
    using namespace Scripts::EasternKingdoms::Deadmines;

    RegisterCreatureAI(npc_rope_ship);
    RegisterCreatureAI(npc_icycle_dm);
    RegisterCreatureAI(npc_note);
    RegisterCreatureAI(npc_steam_valve);
    RegisterCreatureAI(npc_magma_pull);
    RegisterCreatureAI(npc_rope_away);
    RegisterCreatureAI(npc_lightning_orbs);
    RegisterCreatureAI(npc_oaf_lackey);
    RegisterCreatureAI(npc_goblin_overseer);
    RegisterCreatureAI(npc_enraged_worgen_dm);
    RegisterCreatureAI(npc_james_dm);
    RegisterCreatureAI(npc_vanessa_intro);
    RegisterCreatureAI(npc_vanessa_nightmare);
    RegisterCreatureAI(npc_glubtok_dm);
    RegisterCreatureAI(npc_helix_dm);
    RegisterCreatureAI(npc_mechanical_dm);
    RegisterCreatureAI(boss_vanessa_vancleef);
}
