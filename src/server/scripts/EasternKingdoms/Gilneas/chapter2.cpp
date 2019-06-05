/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "gilneas.h"
#include "ScriptMgr.h"
#include "CombatAI.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "GameObjectAI.h"
#include "GameObject.h"

enum GilneasInvasionCamera
{
    CINEMATIC_FORSAKEN_INVASION = 168
};

class go_gilneas_invasion_camera : public GameObjectScript
{
    public:
        go_gilneas_invasion_camera() : GameObjectScript("go_gilneas_invasion_camera") { }

        struct go_gilneas_invasion_cameraAI : public GameObjectAI
        {
            go_gilneas_invasion_cameraAI(GameObject* go) : GameObjectAI(go) { }

            bool OnReportUse(Player* player) override
            {
                player->SendCinematicStart(CINEMATIC_FORSAKEN_INVASION);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_gilneas_invasion_cameraAI(go);
        }
};

enum HorridAbomination
{
    // Horrid Abomination
    SPELL_KEG_PLACED                    = 68555,
    SPELL_ABOMINATION_KILL_ME           = 68558,
    SPELL_RANDOM_CIRCUMFERENCE_POISON   = 42266,
    SPELL_RANDOM_CIRCUMFERENCE_BONE     = 42267,
    SPELL_RANDOM_CIRCUMFERENCE_BONE_2   = 42274,
    SPELL_HORRID_ABOMINATION_EXPLOSION  = 68560,
    SPELL_RESTITCHING                   = 68864,

    QUEST_HORRID_ABOMINATION_CREDIT     = 36233,

    SAY_KEG_PLACED                      = 0,
    EVENT_ABOMINATION_KILL_ME           = 1,

    // Prince Liam Greymane
    SPELL_SHOOT                         = 68559
};

class npc_gilneas_horrid_abomination : public CreatureScript
{
    public:
        npc_gilneas_horrid_abomination() : CreatureScript("npc_gilneas_horrid_abomination") { }

        struct npc_gilneas_horrid_abominationAI : public ScriptedAI
        {
            npc_gilneas_horrid_abominationAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _playerGUID = ObjectGuid::Empty;
                _allowEvents = false;
            }

            void Reset() override
            {
                Initialize();
                me->GetMotionMaster()->MoveRandom(6.0f);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_KEG_PLACED:
                        Talk(SAY_KEG_PLACED);
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->InitDefault();
                        me->StopMoving();
                        _playerGUID = caster->GetGUID();
                        _allowEvents = true;
                        _events.ScheduleEvent(EVENT_ABOMINATION_KILL_ME, Seconds(2));
                        break;
                    case SPELL_SHOOT:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            player->KilledMonsterCredit(QUEST_HORRID_ABOMINATION_CREDIT);

                        me->RemoveAurasDueToSpell(SPELL_KEG_PLACED);

                        for (uint8 i = 0; i < 11; i++)
                            DoCastSelf(SPELL_RANDOM_CIRCUMFERENCE_POISON, true);

                        for (uint8 i = 0; i < 6; i++)
                            DoCastSelf(SPELL_RANDOM_CIRCUMFERENCE_BONE, true);

                        for (uint8 i = 0; i < 4; i++)
                            DoCastSelf(SPELL_RANDOM_CIRCUMFERENCE_BONE_2, true);

                        DoCastSelf(SPELL_HORRID_ABOMINATION_EXPLOSION, true);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->DespawnOrUnsummon(Seconds(5));
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    if (!me->HasUnitState(UNIT_STATE_CASTING) && !me->HasAura(SPELL_RESTITCHING))
                        DoCastSelf(SPELL_RESTITCHING);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_allowEvents)
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_ABOMINATION_KILL_ME:
                            DoCastAOE(SPELL_ABOMINATION_KILL_ME, true);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            ObjectGuid _playerGUID;
            bool _allowEvents;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_gilneas_horrid_abominationAI (creature);
        }
};

enum SaveTheChildren
{
    BROADCAST_TEXT_ID_JAMES             = 36328,
    BROADCAST_TEXT_ID_CYNTHIA           = 36329,
    BROADCAST_TEXT_ID_ASHLEY            = 36331,

    SPELL_GILNEAS_QUEST_SAVE_JAMES      = 68596,
    SPELL_GILNEAS_QUEST_SAVE_CYNTHIA    = 68597,
    SPELL_GILNEAS_QUEST_SAVE_ASHLEY     = 68598,

    NPC_CYNTHIA                         = 36287,
    NPC_ASHLEY                          = 36288,
    NPC_JAMES                           = 36289,

    SAY_CHILD_RESCUED                   = 0,
    EVENT_TALK_RESCUED                  = 1,
    EVENT_RUN_TO_BASEMENT               = 2,
    EVENT_CRY                           = 3,

    POINT_BASEMENT_1                    = 1,
    POINT_BASEMENT_2                    = 2,
};

Position const JamesEscapePos = { -1913.021f, 2558.333f, 1.511007f };

Position const AshleyEscapePos[] =
{
    { -1923.283f, 2552.308f, 12.73581f }, // Ashley Point 1
    { -1920.023f, 2558.055f, 7.076692f }  // Ashley Point 2
};

Position const CynthiaEscapePos[] =
{
    { -1969.23f,  2517.465f, 2.580818f }, // Cynthia Point 1
    { -1947.472f, 2515.521f, 2.318746f }, // Cynthia Point 2
    { -1926.536f, 2519.312f, 2.246772f }  // Cynthia Point 3
};

class spell_gilneas_quest_save_james : public SpellScriptLoader
{
    public:
        spell_gilneas_quest_save_james() : SpellScriptLoader("spell_gilneas_quest_save_james") { }

        class spell_gilneas_quest_save_james_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gilneas_quest_save_james_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (Player* player = caster->ToPlayer())
                    {
                        Unit* target = GetHitUnit();
                        player->Talk(BROADCAST_TEXT_ID_JAMES, CHAT_MSG_SAY, 0.0f, target);
                        player->KilledMonsterCredit(target->GetEntry());
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_gilneas_quest_save_james_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gilneas_quest_save_james_SpellScript();
        }
};

class spell_gilneas_quest_save_the_children : public SpellScriptLoader
{
    public:
        spell_gilneas_quest_save_the_children() : SpellScriptLoader("spell_gilneas_quest_save_the_children") { }

        class spell_gilneas_quest_save_the_children_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gilneas_quest_save_the_children_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_GILNEAS_QUEST_SAVE_JAMES,
                        SPELL_GILNEAS_QUEST_SAVE_CYNTHIA,
                        SPELL_GILNEAS_QUEST_SAVE_ASHLEY
                    });
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (Player* player = caster->ToPlayer())
                    {
                        Unit* target = GetHitUnit();

                        switch (GetSpellInfo()->Id)
                        {
                            case SPELL_GILNEAS_QUEST_SAVE_CYNTHIA:
                                player->Talk(BROADCAST_TEXT_ID_CYNTHIA, CHAT_MSG_SAY, 0.0f, target);
                                break;
                            case SPELL_GILNEAS_QUEST_SAVE_ASHLEY:
                                player->Talk(BROADCAST_TEXT_ID_ASHLEY, CHAT_MSG_SAY, 0.0f, target);
                                break;
                            default:
                                break;
                        }

                        player->KilledMonsterCredit(target->GetEntry());
                    }
            }

            void Register() override
            {
                    OnEffectHitTarget += SpellEffectFn(spell_gilneas_quest_save_the_children_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gilneas_quest_save_the_children_SpellScript();
        }
};

class npc_gilneas_save_the_children : public CreatureScript
{
    public:
        npc_gilneas_save_the_children() : CreatureScript("npc_gilneas_save_the_children") { }

        struct npc_gilneas_save_the_childrenAI : public ScriptedAI
        {
            npc_gilneas_save_the_childrenAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _playerGUID = ObjectGuid::Empty;
            }

            void Reset() override
            {
                Initialize();
                if (me->GetEntry() == NPC_CYNTHIA)
                    _events.ScheduleEvent(EVENT_CRY, Seconds(1));
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_GILNEAS_QUEST_SAVE_JAMES:
                    case SPELL_GILNEAS_QUEST_SAVE_CYNTHIA:
                    case SPELL_GILNEAS_QUEST_SAVE_ASHLEY:
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        _playerGUID = caster->GetGUID();
                        _events.ScheduleEvent(EVENT_TALK_RESCUED, Seconds(2) + Milliseconds(500));
                        _events.CancelEvent(EVENT_CRY);
                        break;
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_BASEMENT_1:
                        if (me->GetEntry() == NPC_ASHLEY)
                            me->GetMotionMaster()->MovePoint(0, AshleyEscapePos[1], true);
                        else
                            me->GetMotionMaster()->MovePoint(POINT_BASEMENT_2, CynthiaEscapePos[1], true);
                        break;
                    case POINT_BASEMENT_2:
                        me->GetMotionMaster()->MovePoint(0, CynthiaEscapePos[2], true);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_TALK_RESCUED:
                            Talk(SAY_CHILD_RESCUED, ObjectAccessor::GetPlayer(*me, _playerGUID));
                            _events.ScheduleEvent(EVENT_RUN_TO_BASEMENT, me->GetEntry() == NPC_JAMES ? Seconds(3) + Milliseconds(600) : Seconds(2) + Milliseconds(300));
                            break;
                        case EVENT_RUN_TO_BASEMENT:
                            switch (me->GetEntry())
                            {
                                case NPC_JAMES:
                                    me->GetMotionMaster()->MovePoint(0, JamesEscapePos, true);
                                    me->DespawnOrUnsummon(Seconds(5) + Milliseconds(200));
                                    break;
                                case NPC_ASHLEY:
                                    me->GetMotionMaster()->MovePoint(POINT_BASEMENT_1, AshleyEscapePos[0], true);
                                    me->DespawnOrUnsummon(Seconds(3) + Milliseconds(800));
                                    break;
                                case NPC_CYNTHIA:
                                    me->GetMotionMaster()->MovePoint(POINT_BASEMENT_1, CynthiaEscapePos[0], true);
                                    me->DespawnOrUnsummon(Seconds(8) + Milliseconds(500));
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case EVENT_CRY:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
                            _events.Repeat(Seconds(1), Seconds(1) + Milliseconds(500));
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            ObjectGuid _playerGUID;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_gilneas_save_the_childrenAI (creature);
        }
};

enum ForsakenCatapult
{
    NPC_FORSAKEN_MACHINIST  = 36292,

    SPELL_FIERY_BOULDER     = 68591,
    SPELL_LAUNCH_INTERNAL   = 96114,
    SPELL_LAUNCH_INTERNAL_2 = 96185,
    SPELL_LAUNCH            = 66251,

    EVENT_FIERY_BOULDER     = 1,
    EVENT_CHECK_AREA        = 2,

    SEAT_0                  = 0,

    SAY_WARN_OUT_OF_AREA    = 0,

    AREA_ID_DUSKMIST_SHORE  = 5720
};

class npc_gilneas_forsaken_catapult : public CreatureScript
{
    public:
        npc_gilneas_forsaken_catapult() : CreatureScript("npc_gilneas_forsaken_catapult") { }

        struct npc_gilneas_forsaken_catapultAI : public VehicleAI
        {
            npc_gilneas_forsaken_catapultAI(Creature* creature) : VehicleAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _preparedDespawn = false;
            }

            void Reset()
            {
                Initialize();
                _events.ScheduleEvent(EVENT_FIERY_BOULDER, Milliseconds(1), Seconds(7));
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (!passenger)
                    return;

                if (passenger->GetEntry() == NPC_FORSAKEN_MACHINIST)
                {
                    if (apply)
                    {
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        passenger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        if (Creature* creature = passenger->ToCreature())
                            creature->SetReactState(REACT_PASSIVE);
                    }
                    else
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->SetFaction(FACTION_FRIENDLY);
                        _events.CancelEvent(EVENT_FIERY_BOULDER);
                    }
                }
                else if (passenger->GetTypeId() == TYPEID_PLAYER && !apply)
                    me->DespawnOrUnsummon(Seconds(9));
                else if (passenger->GetTypeId() == TYPEID_PLAYER && apply)
                    _events.ScheduleEvent(EVENT_CHECK_AREA, Milliseconds(1));
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_LAUNCH_INTERNAL:
                        DoCastSelf(SPELL_LAUNCH_INTERNAL_2, true);
                        break;
                    default:
                        break;
                }
            }

            void SetTargetDestination(Position pos)
            {
                _targetPos = pos;
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_LAUNCH:
                        if (target->GetVehicleCreatureBase())
                        {
                            Position pos = target->GetPosition();
                            pos.m_positionZ += 6.0f;
                            target->ExitVehicle(&pos);
                            target->GetMotionMaster()->MoveJump(_targetPos, 58.62504f, 12.75955f);
                        }
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIERY_BOULDER:
                            DoCastAOE(SPELL_FIERY_BOULDER);
                            _events.Repeat(Seconds(7), Seconds(8));
                            break;
                        case EVENT_CHECK_AREA:
                            if (me->GetAreaId() != AREA_ID_DUSKMIST_SHORE)
                            {
                                if (!_preparedDespawn)
                                {
                                    if (Vehicle* vehicle = me->GetVehicleKit())
                                        if (Unit* passenger = vehicle->GetPassenger(SEAT_0))
                                            Talk(SAY_WARN_OUT_OF_AREA, passenger);

                                    _preparedDespawn = true;

                                }
                                else
                                    me->DespawnOrUnsummon();

                                _events.Repeat(Seconds(10));
                            }
                            else
                            {
                                if (_preparedDespawn)
                                {
                                    _preparedDespawn = false;
                                    _events.Repeat(Seconds(2));
                                }
                                else
                                    _events.Repeat(Seconds(2));
                            }
                            break;
                        default:
                            break;
                    }
                }

            }
        private:
            EventMap _events;
            Position _targetPos;
            bool _preparedDespawn;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_gilneas_forsaken_catapultAI(creature);
        }
};

class spell_gilneas_launch : public SpellScriptLoader
{
    public:
        spell_gilneas_launch() : SpellScriptLoader("spell_gilneas_launch") { }

        class spell_gilneas_launch_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gilneas_launch_SpellScript);

            void TransferDestination(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* creature = caster->ToCreature())
                        if (creature->IsAIEnabled)
                            CAST_AI(npc_gilneas_forsaken_catapult::npc_gilneas_forsaken_catapultAI,
                                creature->AI())->SetTargetDestination(GetExplTargetDest()->GetPosition());
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_gilneas_launch_SpellScript::TransferDestination, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gilneas_launch_SpellScript();
    }
};

class FireBoulderInFrontCheck
{
    public:
        FireBoulderInFrontCheck(Unit* _caster) : caster(_caster) { }

        bool operator()(WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
                return (!caster->isInFront(target, float(M_PI * 0.3f)));

            return false;
        }
    private:
        Unit* caster;

};

class spell_gilneas_fiery_boulder : public SpellScriptLoader
{
    public:
        spell_gilneas_fiery_boulder() : SpellScriptLoader("spell_gilneas_fiery_boulder") { }

        class spell_gilneas_fiery_boulder_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gilneas_fiery_boulder_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(FireBoulderInFrontCheck(GetCaster()));

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gilneas_fiery_boulder_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gilneas_fiery_boulder_SpellScript();
        }
};

enum LeaderOfThePack
{
    NPC_ATTACK_MASTIFF = 36405
};

Position const AttackMastiffSummonPositions[] =
{
    { -1944.483f, 2656.656f, 1.051441f,  1.691914f  },
    { -1956.602f, 2649.942f, 1.374257f,  1.441419f  },
    { -1973.627f, 2654.836f, -0.6995407f, 1.098437f },
    { -1983.201f, 2662.242f, -1.66652f,  0.8627869f },
    { -1994.557f, 2672.134f, -2.303949f, 0.5766099f },
    { -1949.314f, 2642.024f, 1.299083f,  1.580745f  },
    { -1972.606f, 2639.383f, 1.211673f,  1.217789f  },
    { -1997.009f, 2650.811f, -1.030188f, 0.8184887f },
    { -2006.259f, 2663.115f, -2.00431f,  0.5941383f },
    { -1945.504f, 2653.386f, 1.177739f,  1.675516f  }
};

class spell_gilneas_call_attack_mastiff : public SpellScriptLoader
{
    public:
        spell_gilneas_call_attack_mastiff() : SpellScriptLoader("spell_gilneas_call_attack_mastiff") { }

        class spell_gilneas_call_attack_mastiff_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gilneas_call_attack_mastiff_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                {
                    for (uint8 i = 0; i < 10; i++)
                        if (Creature* mastiff = caster->SummonCreature(NPC_ATTACK_MASTIFF, AttackMastiffSummonPositions[i], TEMPSUMMON_TIMED_DESPAWN, 60000))
                            mastiff->AI()->AttackStart(GetHitUnit());
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_gilneas_call_attack_mastiff_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gilneas_call_attack_mastiff_SpellScript();
        }
};

class spell_gilneas_forcecast_cataclysm_1 : public SpellScriptLoader
{
    public:
        spell_gilneas_forcecast_cataclysm_1() : SpellScriptLoader("spell_gilneas_forcecast_cataclysm_1") { }

        class spell_gilneas_forcecast_cataclysm_1_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gilneas_forcecast_cataclysm_1_SpellScript);

            void HandleForcecast(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, GetSpellInfo()->Effects[effIndex].TriggerSpell, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_gilneas_forcecast_cataclysm_1_SpellScript::HandleForcecast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_gilneas_forcecast_cataclysm_1_SpellScript();
        }
};

class SummonerTargetSelector
{
public:
    SummonerTargetSelector(Unit* caster) : _caster(caster) { }

    bool operator() (WorldObject* target)
    {
        if (target->GetTypeId() != TYPEID_UNIT)
            return true;

        if (TempSummon* summon = target->ToUnit()->ToTempSummon())
            if (summon->GetSummoner() == _caster)
                return false;

        return true;
    }

private:
    Unit* _caster;
};

class spell_gilneas_worgen_intro_completion : public SpellScript
{
    PrepareSpellScript(spell_gilneas_worgen_intro_completion);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(SummonerTargetSelector(GetCaster()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gilneas_worgen_intro_completion::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

void AddSC_gilneas_c2()
{
    new go_gilneas_invasion_camera();

    new npc_gilneas_horrid_abomination();
    new npc_gilneas_save_the_children();
    new npc_gilneas_forsaken_catapult();

    new spell_gilneas_quest_save_james();
    new spell_gilneas_quest_save_the_children();
    new spell_gilneas_launch();
    new spell_gilneas_fiery_boulder();
    new spell_gilneas_call_attack_mastiff();
    new spell_gilneas_forcecast_cataclysm_1();
    RegisterSpellScript(spell_gilneas_worgen_intro_completion);
}
