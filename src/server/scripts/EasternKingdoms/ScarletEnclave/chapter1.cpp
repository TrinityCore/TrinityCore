/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "CombatAI.h"
#include "CreatureTextMgr.h"
#include "G3DPosition.hpp"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Log.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

/*######
##Quest 12848
######*/

#define GCD_CAST    1

enum UnworthyInitiate
{
    SPELL_SOUL_PRISON_CHAIN_SELF    = 54612,
    SPELL_SOUL_PRISON_CHAIN         = 54613,
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
            me->RemoveAurasDueToSpell(SPELL_SOUL_PRISON_CHAIN_SELF);
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
                        //TC_LOG_DEBUG("scripts", "npc_unworthy_initiateAI: move to %f %f %f", anchorX, anchorY, me->GetPositionZ());
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
                        events.DelayEvents(1000, GCD_CAST);
                        events.ScheduleEvent(EVENT_ICY_TOUCH, 5s, GCD_CAST);
                        break;
                    case EVENT_PLAGUE_STRIKE:
                        DoCastVictim(SPELL_PLAGUE_STRIKE);
                        events.DelayEvents(1000, GCD_CAST);
                        events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 5s, GCD_CAST);
                        break;
                    case EVENT_BLOOD_STRIKE:
                        DoCastVictim(SPELL_BLOOD_STRIKE);
                        events.DelayEvents(1000, GCD_CAST);
                        events.ScheduleEvent(EVENT_BLOOD_STRIKE, 5s, GCD_CAST);
                        break;
                    case EVENT_DEATH_COIL:
                        DoCastVictim(SPELL_DEATH_COIL);
                        events.DelayEvents(1000, GCD_CAST);
                        events.ScheduleEvent(EVENT_DEATH_COIL, 5s, GCD_CAST);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
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

            bool GossipHello(Player* player) override
            {
                if (Creature* anchor = me->FindNearestCreature(29521, 15))
                    if (ObjectGuid prisonerGUID = anchor->AI()->GetGUID())
                        if (Creature* prisoner = ObjectAccessor::GetCreature(*player, prisonerGUID))
                            ENSURE_AI(npc_unworthy_initiate::npc_unworthy_initiateAI, prisoner->AI())->EventStart(anchor, player);

                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_acherus_soul_prisonAI(go);
        }
};

class spell_death_knight_initiate_visual : public SpellScript
{
    PrepareSpellScript(spell_death_knight_initiate_visual);

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

        target->CastSpell(target, spellId, true);
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
    SPELL_THE_EYE_OF_ACHERUS = 51852,
    SPELL_EYE_VISUAL = 51892,
    SPELL_EYE_FLIGHT_BOOST = 51923,
    SPELL_EYE_FLIGHT = 51890,

    EVENT_MOVE_START = 1,

    TALK_MOVE_START = 0,
    TALK_CONTROL = 1,

    POINT_EYE_FALL = 1,
    POINT_EYE_MOVE_END = 3
};

Position const EyeOFAcherusFallPoint = { 2361.21f, -5660.45f, 496.7444f, 0.0f };

G3D::Vector3 const EyeOfAcherusPath[] =
{
    { 2361.21f, -5660.45f, 496.744f },
    { 2341.57f, -5672.8f,  538.394f },
    { 1957.4f,  -5844.1f,  273.867f },
    { 1758.01f, -5876.79f, 166.867f }
};
std::size_t constexpr EyeOfAcherusPathSize = std::extent<decltype(EyeOfAcherusPath)>::value;

class npc_eye_of_acherus : public CreatureScript
{
    public:
        npc_eye_of_acherus() : CreatureScript("npc_eye_of_acherus") { }

        struct npc_eye_of_acherusAI : public ScriptedAI
        {
            npc_eye_of_acherusAI(Creature* creature) : ScriptedAI(creature)
            {
                creature->SetDisplayId(creature->GetCreatureTemplate()->Modelid1);
                creature->SetReactState(REACT_PASSIVE);
                creature->SetDisableGravity(true);
                creature->SetControlled(true, UNIT_STATE_ROOT);
            }

            void JustAppeared() override
            {
                ScriptedAI::JustAppeared();

                DoCastSelf(SPELL_EYE_VISUAL);
                DoCastSelf(SPELL_EYE_FLIGHT);

                Movement::MoveSplineInit init(me);
                init.MoveTo(PositionToVector3(EyeOFAcherusFallPoint), false);
                init.SetFall();
                me->GetMotionMaster()->LaunchMoveSpline(std::move(init), POINT_EYE_FALL, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
            }

            void OnCharmed(bool /*isNew*/) override
            {
                if (!me->IsCharmed())
                {
                    me->GetCharmerOrOwner()->RemoveAurasDueToSpell(SPELL_THE_EYE_OF_ACHERUS);
                    me->GetCharmerOrOwner()->RemoveAurasDueToSpell(SPELL_EYE_FLIGHT_BOOST);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_START:
                        {
                            me->SetControlled(false, UNIT_STATE_ROOT);

                            DoCastSelf(SPELL_EYE_FLIGHT_BOOST);

                            if (Unit* owner = me->GetCharmerOrOwner())
                                Talk(TALK_MOVE_START, owner);

                            Movement::PointsArray path(EyeOfAcherusPath, EyeOfAcherusPath + EyeOfAcherusPathSize);
                            Movement::MoveSplineInit init(me);
                            init.MovebyPath(path);
                            me->GetMotionMaster()->LaunchMoveSpline(std::move(init), POINT_EYE_MOVE_END, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
                            break;
                        }
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
                    case POINT_EYE_FALL:
                        _events.ScheduleEvent(EVENT_MOVE_START, 2s);
                        break;
                    case POINT_EYE_MOVE_END:
                        me->RemoveAurasDueToSpell(SPELL_EYE_FLIGHT_BOOST);
                        if (Unit* owner = me->GetCharmerOrOwner())
                            Talk(TALK_CONTROL, owner);
                        break;
                    default:
                        break;
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_eye_of_acherusAI(creature);
        }
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
    QUEST_DEATH_CHALLENGE       = 12733
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
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_15);
        }

        void SpellHit(Unit* pCaster, SpellInfo const* pSpell) override
        {
            if (!m_bIsDuelInProgress && pSpell->Id == SPELL_DUEL)
            {
                m_uiDuelerGUID = pCaster->GetGUID();
                Talk(SAY_DUEL, pCaster);
                m_bIsDuelInProgress = true;
            }
        }

       void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
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

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
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
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_15);

                player->CastSpell(me, SPELL_DUEL, false);
                player->CastSpell(player, SPELL_DUEL_FLAG, true);
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (player->GetQuestStatus(QUEST_DEATH_CHALLENGE) == QUEST_STATUS_INCOMPLETE && me->IsFullHealth())
            {
                if (player->HealthBelowPct(10))
                    return true;

                if (player->IsInCombat() || me->IsInCombat())
                    return true;

                AddGossipItemFor(player, Player::GetDefaultGossipMenuForSource(me), 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            }
            return true;
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

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_DESPAWN_HORSE && target->GetGUID() == _horseGUID)
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
    GOSSIP_SALANAR_MENU               = 9739,
    GOSSIP_SALANAR_OPTION             = 0,
    SALANAR_SAY                       = 0,
    QUEST_INTO_REALM_OF_SHADOWS       = 12687,
    NPC_SALANAR_IN_REALM_OF_SHADOWS   = 28788,
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

        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == GOSSIP_SALANAR_MENU && gossipListId == GOSSIP_SALANAR_OPTION)
            {
                player->CastSpell(player, SPELL_REALM_OF_SHADOWS, true);
                player->PlayerTalkClass->SendCloseGossip();
            }
            return false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetTypeId() == TYPEID_UNIT && who->IsVehicle() && me->IsWithinDistInMap(who, 5.0f))
            {
                if (Unit* charmer = who->GetCharmer())
                {
                    if (Player* player = charmer->ToPlayer())
                    {
                        // for quest Into the Realm of Shadows(QUEST_INTO_REALM_OF_SHADOWS)
                        if (me->GetEntry() == NPC_SALANAR_IN_REALM_OF_SHADOWS && player->GetQuestStatus(QUEST_INTO_REALM_OF_SHADOWS) == QUEST_STATUS_INCOMPLETE)
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

class spell_stable_master_repo : public AuraScript
{
    PrepareAuraScript(spell_stable_master_repo);

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

class spell_deliver_stolen_horse : public SpellScript
{
    PrepareSpellScript(spell_deliver_stolen_horse);

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
        caster->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
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
            deathcharger->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            deathcharger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
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
                deathcharger->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                deathcharger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                deathcharger->SetFaction(FACTION_SCARLET_CRUSADE_2);
            }
        }
    };

};

// correct way: 52312 52314 52555 ...
enum Creatures_SG
{
    NPC_GHOULS = 28845,
    NPC_GHOSTS = 28846,
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

class npc_scarlet_ghoul : public CreatureScript
{
public:
    npc_scarlet_ghoul() : CreatureScript("npc_scarlet_ghoul") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_scarlet_ghoulAI(creature);
    }

    struct npc_scarlet_ghoulAI : public ScriptedAI
    {
        npc_scarlet_ghoulAI(Creature* creature) : ScriptedAI(creature)
        {
            // Ghouls should display their Birth Animation
            // Crawling out of the ground
            //DoCast(me, 35177, true);
            //me->MonsterSay("Mommy?", LANG_UNIVERSAL, 0);
            me->SetReactState(REACT_DEFENSIVE);
        }

        void FindMinions(Unit* owner)
        {
            std::list<Creature*> MinionList;
            owner->GetAllMinionsByEntry(MinionList, NPC_GHOULS);

            if (!MinionList.empty())
            {
                for (std::list<Creature*>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                {
                    if ((*itr)->GetOwner()->GetGUID() == me->GetOwner()->GetGUID())
                    {
                        if ((*itr)->IsInCombat() && (*itr)->getAttackerForHelper())
                        {
                            AttackStart((*itr)->getAttackerForHelper());
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
                        if (plrOwner->getAttackerForHelper() && plrOwner->getAttackerForHelper()->GetEntry() == NPC_GHOSTS)
                            AttackStart(plrOwner->getAttackerForHelper());
                        else
                            FindMinions(owner);
                    }
                }
            }

            if (!UpdateVictim() || !me->GetVictim())
                return;

            //ScriptedAI::UpdateAI(diff);
            //Check if we have a current target
            if (me->EnsureVictim()->GetEntry() == NPC_GHOSTS)
            {
                if (me->isAttackReady())
                {
                    //If we are within range melee the target
                    if (me->IsWithinMeleeRange(me->GetVictim()))
                    {
                        me->AttackerStateUpdate(me->GetVictim());
                        me->resetAttackTimer();
                    }
                }
            }
        }
    };

};

/*####
## npc_scarlet_miner_cart
####*/

enum ScarletMinerCart
{
    SPELL_CART_CHECK        = 54173,
    SPELL_SUMMON_CART       = 52463,
    SPELL_SUMMON_MINER      = 52464,
    SPELL_CART_DRAG         = 52465,

    NPC_MINER               = 28841
};

class npc_scarlet_miner_cart : public CreatureScript
{
    public:
        npc_scarlet_miner_cart() : CreatureScript("npc_scarlet_miner_cart") { }

        struct npc_scarlet_miner_cartAI : public PassiveAI
        {
            npc_scarlet_miner_cartAI(Creature* creature) : PassiveAI(creature)
            {
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid1); // Modelid2 is a horse.
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_MINER)
                {
                    _minerGUID = summon->GetGUID();
                    summon->AI()->SetGUID(_playerGUID);
                }
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_MINER)
                    _minerGUID.Clear();
            }

            void DoAction(int32 /*param*/) override
            {
                if (Creature* miner = ObjectAccessor::GetCreature(*me, _minerGUID))
                {
                    me->SetWalk(false);

                    // Not 100% correct, but movement is smooth. Sometimes miner walks faster
                    // than normal, this speed is fast enough to keep up at those times.
                    me->SetSpeedRate(MOVE_RUN, 1.25f);

                    me->GetMotionMaster()->MoveFollow(miner, 1.0f, 0);
                }
            }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
            {
                if (apply)
                {
                    _playerGUID = who->GetGUID();
                    me->CastSpell(nullptr, SPELL_SUMMON_MINER, true);
                }
                else
                {
                    _playerGUID.Clear();
                    if (Creature* miner = ObjectAccessor::GetCreature(*me, _minerGUID))
                        miner->DespawnOrUnsummon();
                }
            }

        private:
            ObjectGuid _minerGUID;
            ObjectGuid _playerGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_scarlet_miner_cartAI(creature);
        }
};

/*####
## npc_scarlet_miner
####*/

enum Says_SM
{
    SAY_SCARLET_MINER_0         = 0,
    SAY_SCARLET_MINER_1         = 1
};

class npc_scarlet_miner : public CreatureScript
{
    public:
        npc_scarlet_miner() : CreatureScript("npc_scarlet_miner") { }

        struct npc_scarlet_minerAI : public EscortAI
        {
            npc_scarlet_minerAI(Creature* creature) : EscortAI(creature)
            {
                Initialize();
                me->SetReactState(REACT_PASSIVE);
            }

            void Initialize()
            {
                carGUID.Clear();
                IntroTimer = 0;
                IntroPhase = 0;
            }

            uint32 IntroTimer;
            uint32 IntroPhase;
            ObjectGuid carGUID;

            void Reset() override
            {
                Initialize();
            }

            void IsSummonedBy(WorldObject* summoner) override
            {
                carGUID = summoner->GetGUID();
            }

            void InitWaypoint()
            {
                AddWaypoint(1, 2389.03f,     -5902.74f,     109.014f, 0.f, 5000);
                AddWaypoint(2, 2341.812012f, -5900.484863f, 102.619743f);
                AddWaypoint(3, 2306.561279f, -5901.738281f, 91.792419f);
                AddWaypoint(4, 2300.098389f, -5912.618652f, 86.014885f);
                AddWaypoint(5, 2294.142090f, -5927.274414f, 75.316849f);
                AddWaypoint(6, 2286.984375f, -5944.955566f, 63.714966f);
                AddWaypoint(7, 2280.001709f, -5961.186035f, 54.228283f);
                AddWaypoint(8, 2259.389648f, -5974.197754f, 42.359348f);
                AddWaypoint(9, 2242.882812f, -5984.642578f, 32.827850f);
                AddWaypoint(10, 2217.265625f, -6028.959473f, 7.675705f);
                AddWaypoint(11, 2202.595947f, -6061.325684f, 5.882018f);
                AddWaypoint(12, 2188.974609f, -6080.866699f, 3.370027f);

                if (urand(0, 1))
                {
                    AddWaypoint(13, 2176.483887f, -6110.407227f, 1.855181f);
                    AddWaypoint(14, 2172.516602f, -6146.752441f, 1.074235f);
                    AddWaypoint(15, 2138.918457f, -6158.920898f, 1.342926f);
                    AddWaypoint(16, 2129.866699f, -6174.107910f, 4.380779f);
                    AddWaypoint(17, 2117.709473f, -6193.830078f, 13.3542f, 0.f, 10000);
                }
                else
                {
                    AddWaypoint(13, 2184.190186f, -6166.447266f, 0.968877f);
                    AddWaypoint(14, 2234.265625f, -6163.741211f, 0.916021f);
                    AddWaypoint(15, 2268.071777f, -6158.750977f, 1.822252f);
                    AddWaypoint(16, 2270.028320f, -6176.505859f, 6.340538f);
                    AddWaypoint(17, 2271.739014f, -6195.401855f, 13.3542f, 0.f, 10000);
                }
            }

            void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
            {
                InitWaypoint();
                Start(false, false, guid);
                SetDespawnAtFar(false);
            }

            void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
            {
                switch (waypointId)
                {
                    case 1:
                        if (Unit* car = ObjectAccessor::GetCreature(*me, carGUID))
                            me->SetFacingToObject(car);
                        Talk(SAY_SCARLET_MINER_0);
                        SetRun(true);
                        IntroTimer = 4000;
                        IntroPhase = 1;
                        break;
                    case 17:
                        if (Unit* car = ObjectAccessor::GetCreature(*me, carGUID))
                        {
                            me->SetFacingToObject(car);
                            car->RemoveAura(SPELL_CART_DRAG);
                        }
                        Talk(SAY_SCARLET_MINER_1);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (IntroPhase)
                {
                    if (IntroTimer <= diff)
                    {
                        if (IntroPhase == 1)
                        {
                            if (Creature* car = ObjectAccessor::GetCreature(*me, carGUID))
                                DoCast(car, SPELL_CART_DRAG);
                            IntroTimer = 800;
                            IntroPhase = 2;
                        }
                        else
                        {
                            if (Creature* car = ObjectAccessor::GetCreature(*me, carGUID))
                                car->AI()->DoAction(0);
                            IntroPhase = 0;
                        }
                    }
                    else
                        IntroTimer -= diff;
                }
                EscortAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_scarlet_minerAI(creature);
        }
};

// npc 28912 quest 17217 boss 29001 mob 29007 go 191092

void AddSC_the_scarlet_enclave_c1()
{
    new npc_unworthy_initiate();
    new npc_unworthy_initiate_anchor();
    new go_acherus_soul_prison();
    RegisterSpellScript(spell_death_knight_initiate_visual);
    new npc_eye_of_acherus();
    new npc_death_knight_initiate();
    RegisterCreatureAI(npc_dark_rider_of_acherus);
    new npc_salanar_the_horseman();
    RegisterAuraScript(spell_stable_master_repo);
    RegisterSpellScript(spell_deliver_stolen_horse);
    new npc_ros_dark_rider();
    new npc_dkc1_gothik();
    new npc_scarlet_ghoul();
    new npc_scarlet_miner();
    new npc_scarlet_miner_cart();
}
