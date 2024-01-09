/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "CreatureAIImpl.h"
#include "ScriptMgr.h"
#include "CombatAI.h"
#include "CreatureTextMgr.h"
#include "G3DPosition.hpp"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

/*######
##Quest 12848
######*/

#define GCD_CAST    1

enum UnworthyInitiate
{
    SPELL_SOUL_PRISON_CHAIN         = 54612,
    SPELL_DK_INITIATE_VISUAL        = 51519,

    SPELL_ICY_TOUCH                 = 52372,
    SPELL_PLAGUE_STRIKE             = 52373,
    SPELL_BLOOD_STRIKE              = 52374,
    SPELL_DEATH_COIL                = 52375,

    SAY_EVENT_START                 = 0,
    SAY_EVENT_ATTACK                = 1,

    EVENT_ICY_TOUCH                 = 1,
    EVENT_PLAGUE_STRIKE             = 2,
    EVENT_BLOOD_STRIKE              = 3,
    EVENT_DEATH_COIL                = 4
};

enum UnworthyInitiatePhase
{
    PHASE_CHAINED,
    PHASE_TO_EQUIP,
    PHASE_EQUIPING,
    PHASE_TO_ATTACK,
    PHASE_ATTACKING,
};

uint32 acherus_soul_prison[12] =
{
    191577,
    191580,
    191581,
    191582,
    191583,
    191584,
    191585,
    191586,
    191587,
    191588,
    191589,
    191590
};

uint32 acherus_unworthy_initiate[5] =
{
    29519,
    29520,
    29565,
    29566,
    29567
};

class npc_unworthy_initiate : public CreatureScript
{
public:
    npc_unworthy_initiate() : CreatureScript("npc_unworthy_initiate") { }

    struct npc_unworthy_initiateAI : public ScriptedAI
    {
        npc_unworthy_initiateAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            me->SetReactState(REACT_PASSIVE);
            if (!me->GetCurrentEquipmentId())
                me->SetCurrentEquipmentId(me->GetOriginalEquipmentId());

            wait_timer = 0;
            anchorX = 0.f;
            anchorY = 0.f;
        }

        void Initialize()
        {
            anchorGUID.Clear();
            phase = PHASE_CHAINED;
        }

        ObjectGuid playerGUID;
        UnworthyInitiatePhase phase;
        uint32 wait_timer;
        float anchorX, anchorY;
        ObjectGuid anchorGUID;

        EventMap events;

        void Reset() override
        {
            Initialize();
            events.Reset();
            me->SetFaction(FACTION_CREATURE);
            me->SetImmuneToPC(true);
            me->SetStandState(UNIT_STAND_STATE_KNEEL);
            me->LoadEquipment(0, true);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ICY_TOUCH, 1s, GCD_CAST);
            events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 3s, GCD_CAST);
            events.ScheduleEvent(EVENT_BLOOD_STRIKE, 2s, GCD_CAST);
            events.ScheduleEvent(EVENT_DEATH_COIL, 5s, GCD_CAST);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                wait_timer = 5000;
                me->LoadEquipment(1);
                me->CastSpell(me, SPELL_DK_INITIATE_VISUAL, true);

                if (Player* starter = ObjectAccessor::GetPlayer(*me, playerGUID))
                    Talk(SAY_EVENT_ATTACK, starter);

                phase = PHASE_TO_ATTACK;
            }
        }

        void EventStart(Creature* anchor, Player* target)
        {
            wait_timer = 5000;
            phase = PHASE_TO_EQUIP;

            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->RemoveAurasDueToSpell(SPELL_SOUL_PRISON_CHAIN);

            float z;
            anchor->GetContactPoint(me, anchorX, anchorY, z, 1.0f);

            playerGUID = target->GetGUID();
            Talk(SAY_EVENT_START, target);
        }

        void UpdateAI(uint32 diff) override
        {
            switch (phase)
            {
            case PHASE_CHAINED:
                if (!anchorGUID)
                {
                    if (Creature* anchor = me->FindNearestCreature(29521, 30))
                    {
                        anchor->AI()->SetGUID(me->GetGUID());
                        anchor->CastSpell(me, SPELL_SOUL_PRISON_CHAIN, true);
                        anchorGUID = anchor->GetGUID();
                    }
                    else
                        TC_LOG_ERROR("scripts", "npc_unworthy_initiateAI: unable to find anchor!");

                    float dist = 99.0f;
                    GameObject* prison = nullptr;

                    for (uint8 i = 0; i < 12; ++i)
                    {
                        if (GameObject* temp_prison = me->FindNearestGameObject(acherus_soul_prison[i], 30))
                        {
                            if (me->IsWithinDist(temp_prison, dist, false))
                            {
                                dist = me->GetDistance2d(temp_prison);
                                prison = temp_prison;
                            }
                        }
                    }

                    if (prison)
                        prison->ResetDoorOrButton();
                    else
                        TC_LOG_ERROR("scripts", "npc_unworthy_initiateAI: unable to find prison!");
                }
                break;
            case PHASE_TO_EQUIP:
                if (wait_timer)
                {
                    if (wait_timer > diff)
                        wait_timer -= diff;
                    else
                    {
                        me->GetMotionMaster()->MovePoint(1, anchorX, anchorY, me->GetPositionZ());
                        //TC_LOG_DEBUG("scripts", "npc_unworthy_initiateAI: move to {} {} {}", anchorX, anchorY, me->GetPositionZ());
                        phase = PHASE_EQUIPING;
                        wait_timer = 0;
                    }
                }
                break;
            case PHASE_TO_ATTACK:
                if (wait_timer)
                {
                    if (wait_timer > diff)
                        wait_timer -= diff;
                    else
                    {
                        me->SetFaction(FACTION_MONSTER);
                        me->SetImmuneToPC(false);
                        me->SetReactState(REACT_AGGRESSIVE);
                        phase = PHASE_ATTACKING;

                        if (Player* target = ObjectAccessor::GetPlayer(*me, playerGUID))
                            AttackStart(target);
                        wait_timer = 0;
                    }
                }
                break;
            case PHASE_ATTACKING:
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_ICY_TOUCH:
                        DoCastVictim(SPELL_ICY_TOUCH);
                        events.DelayEvents(1s, GCD_CAST);
                        events.ScheduleEvent(EVENT_ICY_TOUCH, 5s, GCD_CAST);
                        break;
                    case EVENT_PLAGUE_STRIKE:
                        DoCastVictim(SPELL_PLAGUE_STRIKE);
                        events.DelayEvents(1s, GCD_CAST);
                        events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 5s, GCD_CAST);
                        break;
                    case EVENT_BLOOD_STRIKE:
                        DoCastVictim(SPELL_BLOOD_STRIKE);
                        events.DelayEvents(1s, GCD_CAST);
                        events.ScheduleEvent(EVENT_BLOOD_STRIKE, 5s, GCD_CAST);
                        break;
                    case EVENT_DEATH_COIL:
                        DoCastVictim(SPELL_DEATH_COIL);
                        events.DelayEvents(1s, GCD_CAST);
                        events.ScheduleEvent(EVENT_DEATH_COIL, 5s, GCD_CAST);
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_unworthy_initiateAI(creature);
    }
};

class npc_unworthy_initiate_anchor : public CreatureScript
{
public:
    npc_unworthy_initiate_anchor() : CreatureScript("npc_unworthy_initiate_anchor") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_unworthy_initiate_anchorAI(creature);
    }

    struct npc_unworthy_initiate_anchorAI : public PassiveAI
    {
        npc_unworthy_initiate_anchorAI(Creature* creature) : PassiveAI(creature) { }

        ObjectGuid prisonerGUID;

        void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
        {
            prisonerGUID = guid;
        }

        ObjectGuid GetGUID(int32 /*id*/) const override
        {
            return prisonerGUID;
        }
    };
};

class go_acherus_soul_prison : public GameObjectScript
{
    public:
        go_acherus_soul_prison() : GameObjectScript("go_acherus_soul_prison") { }

        struct go_acherus_soul_prisonAI : public GameObjectAI
        {
            go_acherus_soul_prisonAI(GameObject* go) : GameObjectAI(go) { }

            bool OnGossipHello(Player* player) override
            {
                if (Creature* anchor = me->FindNearestCreature(29521, 15))
                {
                    ObjectGuid prisonerGUID = anchor->AI()->GetGUID();
                    if (!prisonerGUID.IsEmpty())
                        if (Creature* prisoner = ObjectAccessor::GetCreature(*player, prisonerGUID))
                            ENSURE_AI(npc_unworthy_initiate::npc_unworthy_initiateAI, prisoner->AI())->EventStart(anchor, player);
                }

                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_acherus_soul_prisonAI(go);
        }
};

// 51519 - Death Knight Initiate Visual
class spell_death_knight_initiate_visual : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        uint32 spellId;
        switch (target->GetDisplayId())
        {
            case 25369: spellId = 51552; break; // bloodelf female
            case 25373: spellId = 51551; break; // bloodelf male
            case 25363: spellId = 51542; break; // draenei female
            case 25357: spellId = 51541; break; // draenei male
            case 25361: spellId = 51537; break; // dwarf female
            case 25356: spellId = 51538; break; // dwarf male
            case 25372: spellId = 51550; break; // forsaken female
            case 25367: spellId = 51549; break; // forsaken male
            case 25362: spellId = 51540; break; // gnome female
            case 25359: spellId = 51539; break; // gnome male
            case 25355: spellId = 51534; break; // human female
            case 25354: spellId = 51520; break; // human male
            case 25360: spellId = 51536; break; // nightelf female
            case 25358: spellId = 51535; break; // nightelf male
            case 25368: spellId = 51544; break; // orc female
            case 25364: spellId = 51543; break; // orc male
            case 25371: spellId = 51548; break; // tauren female
            case 25366: spellId = 51547; break; // tauren male
            case 25370: spellId = 51545; break; // troll female
            case 25365: spellId = 51546; break; // troll male
            default: return;
        }

        target->CastSpell(target, spellId, GetSpell());
        target->LoadEquipment();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_death_knight_initiate_visual::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## npc_eye_of_acherus
######*/

enum EyeOfAcherusMisc
{
    SPELL_THE_EYE_OF_ACHERUS                = 51852,
    SPELL_EYE_OF_ACHERUS_VISUAL             = 51892,
    SPELL_EYE_OF_ACHERUS_FLIGHT_BOOST       = 51923,
    SPELL_EYE_OF_ACHERUS_FLIGHT             = 51890,
    SPELL_ROOT_SELF                         = 51860,

    EVENT_ANNOUNCE_LAUNCH_TO_DESTINATION    = 1,
    EVENT_UNROOT                            = 2,
    EVENT_LAUNCH_TOWARDS_DESTINATION        = 3,
    EVENT_GRANT_CONTROL                     = 4,

    SAY_LAUNCH_TOWARDS_DESTINATION          = 0,
    SAY_EYE_UNDER_CONTROL                   = 1,

    POINT_NEW_AVALON                        = 1
};

static constexpr uint8 const EyeOfAcherusPathSize = 4;
G3D::Vector3 const EyeOfAcherusPath[EyeOfAcherusPathSize] =
{
    { 2361.21f,  -5660.45f,  496.744f  },
    { 2341.571f, -5672.797f, 538.3942f },
    { 1957.4f,   -5844.1f,   273.867f  },
    { 1758.01f,  -5876.79f,  166.867f  }
};

struct npc_eye_of_acherus : public ScriptedAI
{
    npc_eye_of_acherus(Creature* creature) : ScriptedAI(creature)
    {
        creature->SetDisplayFromModel(0);
        creature->SetReactState(REACT_PASSIVE);
        if (creature->GetCharmInfo())
            creature->GetCharmInfo()->InitPossessCreateSpells();
    }

    void InitializeAI() override
    {
        DoCastSelf(SPELL_ROOT_SELF);
        DoCastSelf(SPELL_EYE_OF_ACHERUS_VISUAL);
        _events.ScheduleEvent(EVENT_ANNOUNCE_LAUNCH_TO_DESTINATION, 7s);
    }

    void OnCharmed(bool apply) override
    {
        if (!apply)
        {
            me->GetCharmerOrOwner()->RemoveAurasDueToSpell(SPELL_THE_EYE_OF_ACHERUS);
            me->GetCharmerOrOwner()->RemoveAurasDueToSpell(SPELL_EYE_OF_ACHERUS_FLIGHT_BOOST);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ANNOUNCE_LAUNCH_TO_DESTINATION:
                    if (Unit* owner = me->GetCharmerOrOwner())
                        Talk(SAY_LAUNCH_TOWARDS_DESTINATION, owner);
                    _events.ScheduleEvent(EVENT_UNROOT, 1s + 200ms);
                    break;
                case EVENT_UNROOT:
                    me->RemoveAurasDueToSpell(SPELL_ROOT_SELF);
                    DoCastSelf(SPELL_EYE_OF_ACHERUS_FLIGHT_BOOST);
                    _events.ScheduleEvent(EVENT_LAUNCH_TOWARDS_DESTINATION, 1s + 200ms);
                    break;
                case EVENT_LAUNCH_TOWARDS_DESTINATION:
                {
                    std::function<void(Movement::MoveSplineInit&)> initializer = [=, me = me](Movement::MoveSplineInit& init)
                    {
                        Movement::PointsArray path(EyeOfAcherusPath, EyeOfAcherusPath + EyeOfAcherusPathSize);
                        init.MovebyPath(path);
                        init.SetFly();
                        if (Unit* owner = me->GetCharmerOrOwner())
                            init.SetVelocity(owner->GetSpeed(MOVE_RUN));
                    };

                    me->GetMotionMaster()->LaunchMoveSpline(std::move(initializer), POINT_NEW_AVALON, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
                    break;
                }
                case EVENT_GRANT_CONTROL:
                    me->RemoveAurasDueToSpell(SPELL_ROOT_SELF);
                    DoCastSelf(SPELL_EYE_OF_ACHERUS_FLIGHT);
                    me->RemoveAurasDueToSpell(SPELL_EYE_OF_ACHERUS_FLIGHT_BOOST);
                    if (Unit* owner = me->GetCharmerOrOwner())
                        Talk(SAY_EYE_UNDER_CONTROL, owner);
                    break;
                default:
                    break;
            }
        }
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_NEW_AVALON:
                DoCastSelf(SPELL_ROOT_SELF);
                _events.ScheduleEvent(EVENT_GRANT_CONTROL, 2s + 500ms);
                break;
            default:
                break;
        }
    }

private:
    EventMap _events;
};

/*######
## npc_death_knight_initiate
######*/

enum Spells_DKI
{
    SPELL_DUEL                  = 52996,
    //SPELL_DUEL_TRIGGERED        = 52990,
    SPELL_DUEL_VICTORY          = 52994,
    SPELL_DUEL_FLAG             = 52991,
    SPELL_GROVEL                = 7267,
};

enum Says_VBM
{
    SAY_DUEL                    = 0,
};

enum Misc_VBN
{
    QUEST_DEATH_CHALLENGE = 12733
};

enum Paths_VBN
{
    PATH_DEATH_KNIGHT_INITIATE      = 10361360,
    PATH_DEATH_KNIGHT_INITIATE2     = 10361440,
    PATH_DEATH_KNIGHT_INITIATE3     = 10362320,
    PATH_DEATH_KNIGHT_INITIATE4     = 10362400,
    PATH_DEATH_KNIGHT_INITIATE5     = 10362480,
    PATH_DEATH_KNIGHT_INITIATE6     = 10363520,
    PATH_DEATH_KNIGHT_INITIATE7     = 10363680,
    PATH_DEATH_KNIGHT_INITIATE8     = 10363760,
};

class npc_death_knight_initiate : public CreatureScript
{
public:
    npc_death_knight_initiate() : CreatureScript("npc_death_knight_initiate") { }

    struct npc_death_knight_initiateAI : public CombatAI
    {
        npc_death_knight_initiateAI(Creature* creature) : CombatAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            m_uiDuelerGUID.Clear();
            m_uiDuelTimer = 5000;
            m_bIsDuelInProgress = false;
            lose = false;
        }

        bool lose;
        ObjectGuid m_uiDuelerGUID;
        uint32 m_uiDuelTimer;
        bool m_bIsDuelInProgress;

        void Reset() override
        {
            Initialize();

            me->RestoreFaction();
            CombatAI::Reset();
            me->SetUnitFlag(UNIT_FLAG_CAN_SWIM);
        }

        void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
        {
            if (!m_bIsDuelInProgress && spellInfo->Id == SPELL_DUEL)
            {
                m_uiDuelerGUID = caster->GetGUID();
                Talk(SAY_DUEL, caster);
                m_bIsDuelInProgress = true;
            }
        }

       void DamageTaken(Unit* pDoneBy, uint32 &uiDamage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (m_bIsDuelInProgress && pDoneBy && pDoneBy->IsControlledByPlayer())
            {
                if (pDoneBy->GetGUID() != m_uiDuelerGUID && pDoneBy->GetOwnerGUID() != m_uiDuelerGUID) // other players cannot help
                    uiDamage = 0;
                else if (uiDamage >= me->GetHealth())
                {
                    uiDamage = 0;

                    if (!lose)
                    {
                        pDoneBy->RemoveGameObject(SPELL_DUEL_FLAG, true);
                        pDoneBy->AttackStop();
                        me->CastSpell(pDoneBy, SPELL_DUEL_VICTORY, true);
                        lose = true;
                        me->CastSpell(me, SPELL_GROVEL, true);
                        me->RestoreFaction();
                    }
                }
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
            {
                if (m_bIsDuelInProgress)
                {
                    if (m_uiDuelTimer <= uiDiff)
                    {
                        me->SetFaction(FACTION_UNDEAD_SCOURGE_2);

                        if (Unit* unit = ObjectAccessor::GetUnit(*me, m_uiDuelerGUID))
                            AttackStart(unit);
                    }
                    else
                        m_uiDuelTimer -= uiDiff;
                }
                return;
            }

            if (m_bIsDuelInProgress)
            {
                if (lose)
                {
                    if (!me->HasAura(SPELL_GROVEL))
                        EnterEvadeMode();
                    return;
                }
                else if (me->GetVictim() && me->EnsureVictim()->GetTypeId() == TYPEID_PLAYER && me->EnsureVictim()->HealthBelowPct(10))
                {
                    me->EnsureVictim()->CastSpell(me->GetVictim(), SPELL_GROVEL, true); // beg
                    me->EnsureVictim()->RemoveGameObject(SPELL_DUEL_FLAG, true);
                    EnterEvadeMode();
                    return;
                }
            }

            /// @todo spells

            CombatAI::UpdateAI(uiDiff);
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF)
            {
                CloseGossipMenuFor(player);

                if (player->IsInCombat() || me->IsInCombat())
                    return true;

                if (m_bIsDuelInProgress)
                    return true;

                me->SetImmuneToPC(false);
                me->RemoveUnitFlag(UNIT_FLAG_CAN_SWIM);

                player->CastSpell(me, SPELL_DUEL, false);
                player->CastSpell(player, SPELL_DUEL_FLAG, true);
            }
            return true;
        }

        bool OnGossipHello(Player* player) override
        {
            uint32 gossipMenuId = player->GetGossipMenuForSource(me);
            InitGossipMenuFor(player, gossipMenuId);
            if (player->GetQuestStatus(QUEST_DEATH_CHALLENGE) == QUEST_STATUS_INCOMPLETE && me->IsFullHealth())
            {
                if (player->HealthBelowPct(10))
                    return true;

                if (player->IsInCombat() || me->IsInCombat())
                    return true;

                AddGossipItemFor(player, player->GetGossipMenuForSource(me), 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            }
            return true;
        }

        void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
        {
            switch (pathId)
            {
                case PATH_DEATH_KNIGHT_INITIATE:
                case PATH_DEATH_KNIGHT_INITIATE2:
                case PATH_DEATH_KNIGHT_INITIATE3:
                case PATH_DEATH_KNIGHT_INITIATE4:
                case PATH_DEATH_KNIGHT_INITIATE5:
                case PATH_DEATH_KNIGHT_INITIATE6:
                case PATH_DEATH_KNIGHT_INITIATE7:
                case PATH_DEATH_KNIGHT_INITIATE8:
                    me->DespawnOrUnsummon(1s);
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_death_knight_initiateAI(creature);
    }
};

/*######
## npc_dark_rider_of_acherus
######*/

enum DarkRiderOfAcherus
{
    SAY_DARK_RIDER              = 0,

    EVENT_START_MOVING          = 1,
    EVENT_DESPAWN_HORSE         = 2,
    EVENT_END_SCRIPT            = 3,

    SPELL_DESPAWN_HORSE         = 52267
};

struct npc_dark_rider_of_acherus : public ScriptedAI
{
    npc_dark_rider_of_acherus(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (TempSummon* summon = me->ToTempSummon())
            _horseGUID = summon->GetSummonerGUID();

        _events.ScheduleEvent(EVENT_START_MOVING, 1s);
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
                case EVENT_START_MOVING:
                    me->SetTarget(_horseGUID);
                    if (Creature* horse = ObjectAccessor::GetCreature(*me, _horseGUID))
                        me->GetMotionMaster()->MoveChase(horse);
                    _events.ScheduleEvent(EVENT_DESPAWN_HORSE, 5s);
                    break;
                case EVENT_DESPAWN_HORSE:
                    Talk(SAY_DARK_RIDER);
                    if (Creature* horse = ObjectAccessor::GetCreature(*me, _horseGUID))
                        DoCast(horse, SPELL_DESPAWN_HORSE, true);
                    _events.ScheduleEvent(EVENT_END_SCRIPT, 2s);
                    break;
                case EVENT_END_SCRIPT:
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DESPAWN_HORSE && target->GetGUID() == _horseGUID)
            if (Creature* creature = target->ToCreature())
                creature->DespawnOrUnsummon(2s);
    }

private:
    ObjectGuid _horseGUID;
    EventMap _events;
};

/*######
## npc_salanar_the_horseman
######*/

enum SalanarTheHorseman
{
    SALANAR_SAY                       = 0,
    QUEST_INTO_REALM_OF_SHADOWS       = 12687,
    SPELL_EFFECT_STOLEN_HORSE         = 52263,
    SPELL_DELIVER_STOLEN_HORSE        = 52264,
    SPELL_CALL_DARK_RIDER             = 52266,
    SPELL_EFFECT_OVERTAKE             = 52349,
    SPELL_REALM_OF_SHADOWS            = 52693
};

class npc_salanar_the_horseman : public CreatureScript
{
public:
    npc_salanar_the_horseman() : CreatureScript("npc_salanar_the_horseman") { }

    struct npc_salanar_the_horsemanAI : public ScriptedAI
    {
        npc_salanar_the_horsemanAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who) override
        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetTypeId() == TYPEID_UNIT && who->IsVehicle() && me->IsWithinDistInMap(who, 5.0f))
            {
                if (Unit* charmer = who->GetCharmer())
                {
                    if (Player* player = charmer->ToPlayer())
                    {
                        if (player->GetQuestStatus(QUEST_INTO_REALM_OF_SHADOWS) == QUEST_STATUS_INCOMPLETE)
                        {
                            player->GroupEventHappens(QUEST_INTO_REALM_OF_SHADOWS, me);
                            Talk(SALANAR_SAY);
                            charmer->RemoveAurasDueToSpell(SPELL_EFFECT_OVERTAKE);
                            if (Creature* creature = who->ToCreature())
                            {
                                creature->DespawnOrUnsummon();
                                //creature->Respawn(true);
                            }
                        }

                        player->RemoveAurasDueToSpell(SPELL_REALM_OF_SHADOWS);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_salanar_the_horsemanAI(creature);
    }
};

enum HorseSeats
{
    SEAT_ID_0   = 0
};

// 52265 - Repo
class spell_stable_master_repo : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* creature = GetTarget()->ToCreature();
        if (!creature)
            return;

        if (Vehicle* vehicleKit = creature->GetVehicleKit())
            if (Unit* passenger = vehicleKit->GetPassenger(SEAT_ID_0))
                GetCaster()->EngageWithTarget(passenger);

        creature->DespawnOrUnsummon(1s);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_stable_master_repo::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 52264 - Deliver Stolen Horse
class spell_deliver_stolen_horse : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DELIVER_STOLEN_HORSE, SPELL_EFFECT_STOLEN_HORSE });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->RemoveAurasDueToSpell(SPELL_EFFECT_STOLEN_HORSE);

        Unit* caster = GetCaster();
        caster->RemoveAurasDueToSpell(SPELL_EFFECT_STOLEN_HORSE);
        caster->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        caster->SetFaction(FACTION_FRIENDLY);

        caster->CastSpell(caster, SPELL_CALL_DARK_RIDER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_deliver_stolen_horse::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_KILL_CREDIT2);
    }
};

/*######
## npc_ros_dark_rider
######*/

class npc_ros_dark_rider : public CreatureScript
{
public:
    npc_ros_dark_rider() : CreatureScript("npc_ros_dark_rider") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ros_dark_riderAI(creature);
    }

    struct npc_ros_dark_riderAI : public ScriptedAI
    {
        npc_ros_dark_riderAI(Creature* creature) : ScriptedAI(creature) { }

        void JustEngagedWith(Unit* /*who*/) override
        {
            me->ExitVehicle();
        }

        void Reset() override
        {
            Creature* deathcharger = me->FindNearestCreature(28782, 30);
            if (!deathcharger)
                return;

            deathcharger->RestoreFaction();
            deathcharger->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            deathcharger->SetUninteractible(true);
            if (!me->GetVehicle() && deathcharger->IsVehicle() && deathcharger->GetVehicleKit()->HasEmptySeat(0))
                me->EnterVehicle(deathcharger);
        }

        void JustDied(Unit* killer) override
        {
            Creature* deathcharger = me->FindNearestCreature(28782, 30);
            if (!deathcharger || !killer)
                return;

            if (killer->GetTypeId() == TYPEID_PLAYER && deathcharger->GetTypeId() == TYPEID_UNIT && deathcharger->IsVehicle())
            {
                deathcharger->SetNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                deathcharger->SetUninteractible(false);
                deathcharger->SetFaction(FACTION_SCARLET_CRUSADE_2);
            }
        }
    };

};

// correct way: 52312 52314 52555 ...
enum TheGiftThatKeepsOnGiving
{
    SAY_LINE_0  = 0,

    NPC_GHOULS  = 28845,
    NPC_GHOSTS  = 28846,
};

class npc_dkc1_gothik : public CreatureScript
{
public:
    npc_dkc1_gothik() : CreatureScript("npc_dkc1_gothik") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dkc1_gothikAI(creature);
    }

    struct npc_dkc1_gothikAI : public ScriptedAI
    {
        npc_dkc1_gothikAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who) override

        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetEntry() == NPC_GHOULS && me->IsWithinDistInMap(who, 10.0f))
            {
                if (Unit* owner = who->GetOwner())
                {
                    if (Player* player = owner->ToPlayer())
                    {
                        Creature* creature = who->ToCreature();
                        if (player->GetQuestStatus(12698) == QUEST_STATUS_INCOMPLETE)
                            creature->CastSpell(owner, 52517, true);

                        /// @todo Creatures must not be removed, but, must instead
                        //      stand next to Gothik and be commanded into the pit
                        //      and dig into the ground.
                        creature->DespawnOrUnsummon();

                        if (player->GetQuestStatus(12698) == QUEST_STATUS_COMPLETE)
                            owner->RemoveAllMinionsByEntry(NPC_GHOSTS);
                    }
                }
            }
        }
    };

};

struct npc_scarlet_ghoul : public ScriptedAI
{
    npc_scarlet_ghoul(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_DEFENSIVE);
    }

    void JustAppeared() override
    {
        CreatureAI::JustAppeared();

        if (urand(0, 1))
            if (Unit* owner = me->GetOwner())
                Talk(SAY_LINE_0, owner);
    }

    void FindMinions(Unit* owner)
    {
        std::list<TempSummon*> MinionList;
        owner->GetAllMinionsByEntry(MinionList, NPC_GHOULS);

        if (!MinionList.empty())
        {
            for (Creature* creature : MinionList)
            {
                if (creature->GetOwner()->GetGUID() == me->GetOwner()->GetGUID())
                {
                    if (creature->IsInCombat() && creature->getAttackerForHelper())
                    {
                        AttackStart(creature->getAttackerForHelper());
                    }
                }
            }
        }
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!me->IsInCombat())
        {
            if (Unit* owner = me->GetOwner())
            {
                Player* plrOwner = owner->ToPlayer();
                if (plrOwner && plrOwner->IsInCombat())
                {
                    Unit* newTarget = plrOwner->getAttackerForHelper();
                    if (newTarget && newTarget->GetEntry() == NPC_GHOSTS)
                        AttackStart(newTarget);
                    else
                        FindMinions(owner);
                }
            }
        }

        if (!UpdateVictim())
            return;
    }

    bool CanAIAttack(Unit const* target) const override
    {
        return target->GetEntry() == NPC_GHOSTS;
    }
};

enum GiftOfTheHarvester
{
    SPELL_GHOUL_TRANFORM    = 52490,
    SPELL_GHOST_TRANSFORM   = 52505
};

// 52479 - Gift of the Harvester
class spell_gift_of_the_harvester : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_GHOUL_TRANFORM,
            SPELL_GHOST_TRANSFORM
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* originalCaster = GetOriginalCaster();
        Unit* target = GetHitUnit();

        if (originalCaster && target)
            originalCaster->CastSpell(target, RAND(SPELL_GHOUL_TRANFORM, SPELL_GHOST_TRANSFORM), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gift_of_the_harvester::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 12842: Runeforging: Preparation For Battle
######*/

enum Runeforging
{
    SPELL_RUNEFORGING_CREDIT     = 54586,
    QUEST_RUNEFORGING            = 12842
};

/* 53343 - Rune of Razorice
   53344 - Rune of the Fallen Crusader
   62158 - Rune of the Stoneskin Gargoyle
   326805 - Rune of Sanguination
   326855 - Rune of Spellwarding
   326911 - Rune of Hysteria
   326977 - Rune of Unending Thirst
   327082 - Rune of the Apocalypse */
class spell_chapter1_runeforging_credit : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RUNEFORGING_CREDIT }) &&
            sObjectMgr->GetQuestTemplate(QUEST_RUNEFORGING);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
            if (caster->GetQuestStatus(QUEST_RUNEFORGING) == QUEST_STATUS_INCOMPLETE)
                caster->CastSpell(caster, SPELL_RUNEFORGING_CREDIT);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_chapter1_runeforging_credit::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

enum HearthglenCrusaderPaths : uint32
{
    PATH_HEARTHGLEN_CRUSADER_DESPAWN    = 10445360,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN2   = 10445600,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN3   = 10448640,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN4   = 10449200,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN5   = 10452240,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN6   = 10452880,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN7   = 10452960,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN8   = 10453040,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN9   = 10453520,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN10  = 10453680,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN11  = 10454000,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN12  = 10454080,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN13  = 10454160,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN14  = 10454320,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN15  = 10454560,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN16  = 10459440,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN17  = 10460320,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN18  = 10463040,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN19  = 10463120,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN20  = 10463280,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN21  = 10463360,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN22  = 10463520,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN23  = 10463680,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN24  = 10463840,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN25  = 10464080,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN26  = 10464160,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN27  = 10464240,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN28  = 10464320,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN29  = 10464400,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN30  = 10464480,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN31  = 10464720,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN32  = 10464800,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN33  = 10464880,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN34  = 10464960,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN35  = 10465040,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN36  = 10465520,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN37  = 10465600,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN38  = 10466000,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN39  = 10466160,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN40  = 10466320,
    PATH_HEARTHGLEN_CRUSADER_DESPAWN41  = 10466400,
};

// 29102 - Hearthglen Crusader
// 29103 - Tirisfal Crusader
struct npc_hearthglen_crusader : public ScriptedAI
{
    npc_hearthglen_crusader(Creature* creature) : ScriptedAI(creature), _minimumRange(0)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(creature->m_spells[0], creature->GetMap()->GetDifficultyID());
        if (!spellInfo)
            return;

        _minimumRange = spellInfo->GetMinRange(false);

        if (!_minimumRange)
            _minimumRange = MELEE_RANGE;
        creature->m_CombatDistance = spellInfo->GetMaxRange(false);
        creature->m_SightDistance = creature->m_CombatDistance;
    }

    void AttackStart(Unit* who) override
    {
        if (!who)
            return;

        if (me->IsWithinCombatRange(who, _minimumRange))
        {
            if (me->Attack(who, true) && !who->IsFlying())
                me->GetMotionMaster()->MoveChase(who);
        }
        else
        {
            if (me->Attack(who, false) && !who->IsFlying())
                me->GetMotionMaster()->MoveChase(who, me->m_CombatDistance);
        }

        if (who->IsFlying())
            me->GetMotionMaster()->MoveIdle();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        if (!me->IsWithinCombatRange(me->GetVictim(), _minimumRange))
            DoSpellAttackIfReady(me->m_spells[0]);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN2:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN3:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN4:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN5:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN6:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN7:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN8:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN9:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN10:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN11:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN12:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN13:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN14:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN15:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN16:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN17:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN18:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN19:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN20:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN21:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN22:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN23:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN24:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN25:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN26:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN27:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN28:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN29:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN30:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN31:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN32:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN33:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN34:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN35:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN36:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN37:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN38:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN39:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN40:
            case PATH_HEARTHGLEN_CRUSADER_DESPAWN41:
                me->DespawnOrUnsummon(1s);
                break;
            default:
                break;
        }
    }

private:
    float _minimumRange;
};

void AddSC_the_scarlet_enclave_c1()
{
    new npc_unworthy_initiate();
    new npc_unworthy_initiate_anchor();
    new go_acherus_soul_prison();
    RegisterSpellScript(spell_death_knight_initiate_visual);
    RegisterCreatureAI(npc_eye_of_acherus);
    new npc_death_knight_initiate();
    RegisterCreatureAI(npc_dark_rider_of_acherus);
    new npc_salanar_the_horseman();
    RegisterSpellScript(spell_stable_master_repo);
    RegisterSpellScript(spell_deliver_stolen_horse);
    new npc_ros_dark_rider();
    new npc_dkc1_gothik();
    RegisterCreatureAI(npc_scarlet_ghoul);
    RegisterSpellScript(spell_gift_of_the_harvester);
    RegisterSpellScript(spell_chapter1_runeforging_credit);
    RegisterCreatureAI(npc_hearthglen_crusader);
}
