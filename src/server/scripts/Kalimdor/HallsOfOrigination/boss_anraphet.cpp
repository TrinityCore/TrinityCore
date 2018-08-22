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

#include "ScriptMgr.h"
#include "GridNotifiers.h"
#include "halls_of_origination.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Texts
{
    ANRAPHET_SAY_INTRO              = 0,
    ANRAPHET_SAY_AGGRO              = 1,
    ANRAPHET_SAY_OMEGA_STANCE       = 2,
    ANRAPHET_SAY_KILL               = 3,
    ANRAPHET_SAY_DEATH              = 4,

    BRANN_SAY_DOOR_INTRO            = 0,  // Right, let's go! Just need to input the final entry sequence into the door mechanism... and...
    BRANN_SAY_UNLOCK_DOOR           = 1,  // That did the trick! The control room should be right behind this... oh... wow...
    BRANN_SAY_TROGGS                = 2,  // What? This isn't the control room! There's another entire defense mechanism in place, and the blasted Rock Troggs broke into here somehow. Troggs. Why did it have to be Troggs!
    BRANN_SAY_THINK                 = 3,  // Ok, let me think a moment.
    BRANN_SAY_MIRRORS               = 4,  // Mirrors pointing all over the place.
    BRANN_SAY_ELEMENTALS            = 5,  // Four platforms with huge elementals.
    BRANN_SAY_GET_IT                = 6,  // I got it! I saw a tablet that mentioned this chamber. This is the Vault of Lights! Ok, simple enough. I need you adventurers to take out each of the four elementals to trigger the opening sequence for the far door!
    BRANN_1_ELEMENTAL_DEAD          = 7,  // One down!
    BRANN_2_ELEMENTAL_DEAD          = 8,  // Another one down! Just look at those light beams! They seem to be connecting to the far door!
    BRANN_3_ELEMENTAL_DEAD          = 9,  // One more elemental to go! The door is almost open!
    BRANN_4_ELEMENTAL_DEAD          = 10, // That''s it, you''ve done it! The vault door is opening! Now we can... oh, no!
    BRANN_SAY_ANRAPHET_DIED         = 11, // We''ve done it! The control room is breached!
    BRANN_SAY_MOMENT                = 12, // Here we go! Now this should only take a moment...
    BRANN_SAY_BLASTED_TITANS        = 13, // Blasted titans... Why do they use a different set of mechanisms at each of their installations?
    BRANN_SAY_THIS_SYMBOL           = 14  // This symbol, I think I've seen this before...
};

enum Gossip
{
    GOSSIP_MENU_NO_TIME_TO_WASTE    = 11339, // Great, ye found yer way here!$b$bNo time to waste. Ye ready?
    GOSSIP_OPTION_WE_ARE_READY      = 0,     //   We're ready! Go, Brann!
    GOSSIP_MENU_DESTROY_ELEMENTAL   = 11348, // Yep, destroy the four elementals, then the door will open. I'm sure of it. Just watch out for the Troggs. Nasty tempered, filthy creatures, even if they have not succumbed to the Curse of Flesh.
    GOSSIP_MENU_OCH_ITS_NOT_EASY    = 12512  // Och!$b$bWhy can''t it just be easy fer once?!
};

enum Events
{
    EVENT_BRANN_IDLE_EMOTE_COOLDOWN    = 1,
    EVENT_BRANN_START_INTRO            = 2,
    EVENT_BRANN_UNLOCK_DOOR            = 3,
    EVENT_BRANN_MOVE_INTRO             = 4,
    EVENT_BRANN_THINK                  = 5,
    EVENT_BRANN_LOOK_RIGHT             = 6,
    EVENT_BRANN_LOOK_LEFT              = 7,
    EVENT_BRANN_SAY_ELEMENTALS         = 8,
    EVENT_BRANN_SAY_GET_IT             = 9,
    EVENT_BRANN_SET_FLAG_GOSSIP        = 10,
    EVENT_BRANN_ACTIVATE_LASERBEAMS    = 11,
    EVENT_BRANN_SAY_ALL_ELEMENTAL_DEAD = 12,
    EVENT_BRANN_MOVE_OUTRO             = 13,
    EVENT_BRANN_MOVE_FINAL             = 14,
    EVENT_BRANN_TURN_BACK              = 15,
    EVENT_ANRAPHET_APPEAR              = 16,
    EVENT_ANRAPHET_ACTIVATE            = 17,
    EVENT_ANRAPHET_DESTRUCTION         = 18,
    EVENT_ANRAPHET_READY               = 19,
    EVENT_ANRAPHET_NEMESIS_STRIKE      = 20,
    EVENT_ANRAPHET_ALPHA_BEAMS         = 21,
    EVENT_ANRAPHET_OMEGA_STANCE        = 22,
    EVENT_ANRAPHET_CRUMBLING_RUIN      = 23,
    EVENT_ANRAPHET_ACTIVATE_OMEGA      = 24
};

enum Spells
{
    // Anraphet
    SPELL_DESTRUCTION_PROTOCOL          = 77437,
    SPELL_ALPHA_BEAMS                   = 76184,
    SPELL_ALPHA_BEAMS_BACK_CAST         = 76912,
    SPELL_CRUMBLING_RUIN                = 75609,
    SPELL_NEMESIS_STRIKE                = 75604,

    // Omega Stance
    SPELL_OMEGA_STANCE_SUMMON           = 77106,
    SPELL_OMEGA_STANCE                  = 75622,
    SPELL_OMEGA_STANCE_SPIDER_TRIGGER   = 77121,

    // Flame Warden
    SPELL_LAVA_ERUPTION_VISUAL          = 97317
};

enum Actions
{
    ACTION_BRANN_IDLE_EMOTE
};

enum Phases
{
    PHASE_INTRO         = 1,
    PHASE_COMBAT        = 2
};

enum Points
{
    POINT_ANRAPHET_ACTIVATE,
    POINT_BRANN_SAY_TROGGS, 
    POINT_BRANN_SAY_MOMENT,
    POINT_BRANN_TURN_BACK
};

uint32 const AnraphetPathSize = 6;
Position const AnraphetPath[AnraphetPathSize] =
{
    { -125.4643f, 366.5138f, 89.88697f },
    { -132.7143f, 366.5138f, 89.88697f },
    { -143.9643f, 366.5138f, 89.88697f },
    { -159.2143f, 366.5138f, 85.38697f },
    { -188.2143f, 366.7638f, 76.38697f },
    { -193.656f,  366.689f,  75.91001f }
};

// Brann's intro
Position const BrannBossHomePos = { -429.583f, 367.019f, 89.79282f, 0.01745329f };

// Brann's outro
uint32 const BrannOutroPathSize = 13;
Position const BrannOutroPath[BrannOutroPathSize] =
{
    { -409.9531f, 367.0469f, 89.81111f, 0.0f },
    { -397.8246f, 366.967f,  86.37722f, 0.0f },
    { -383.7813f, 366.8229f, 82.07919f, 0.0f },
    { -368.2604f, 366.7448f, 77.0984f,  0.0f },
    { -353.6458f, 366.4896f, 75.92504f, 0.0f },
    { -309.0608f, 366.7205f, 75.91345f, 0.0f },
    { -276.3303f, 367.0f,    75.92413f, 0.0f },
    { -246.5104f, 366.6389f, 75.87791f, 0.0f },
    { -202.0417f, 366.7517f, 75.92508f, 0.0f },
    { -187.6024f, 366.7656f, 76.23077f, 0.0f },
    { -155.0938f, 366.783f,  86.45834f, 0.0f },
    { -143.5694f, 366.8177f, 89.73354f, 0.0f },
    { -128.5608f, 366.8629f, 89.74199f, 0.0f }
};

Position const BrannFinalHomePos = { -35.04861f, 366.6563f, 89.77447f, 3.141593f };

uint32 const BrannFinalPathSize = 3;
Position const BrannFinalPath[BrannFinalPathSize] =
{
    { -103.559f,  366.5938f, 89.79725f, 0.0f },
    { -71.58507f, 367.0278f, 89.77069f, 0.0f },
    { -35.04861f, 366.6563f, 89.77447f, 0.0f }
};

struct boss_anraphet : public BossAI
{
    boss_anraphet(Creature* creature) : BossAI(creature, DATA_ANRAPHET) { }

    void Reset() override
    {
        _Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(ANRAPHET_SAY_AGGRO);
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.SetPhase(PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ANRAPHET_NEMESIS_STRIKE, Seconds(8), 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ANRAPHET_ALPHA_BEAMS, Seconds(10), 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ANRAPHET_OMEGA_STANCE, Seconds(35), 0, PHASE_COMBAT);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_ANRAPHET, FAIL);
        summons.DespawnAll();
        _EnterEvadeMode();
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(ANRAPHET_SAY_DEATH);
        _JustDied();

        if (Creature* brann = instance->GetCreature(DATA_BRANN_0))
            brann->AI()->DoAction(ACTION_ANRAPHET_DIED);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(ANRAPHET_SAY_KILL);
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_ANRAPHET_INTRO)
            return;

        // Intro
        events.SetPhase(PHASE_INTRO);
        events.ScheduleEvent(EVENT_ANRAPHET_APPEAR, Seconds(6), 0, PHASE_INTRO);
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != EFFECT_MOTION_TYPE || point != POINT_ANRAPHET_ACTIVATE)
            return;

        events.ScheduleEvent(EVENT_ANRAPHET_ACTIVATE, Seconds(1), 0, PHASE_INTRO);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ANRAPHET_APPEAR:
                    me->GetMotionMaster()->MoveSmoothPath(POINT_ANRAPHET_ACTIVATE, AnraphetPath, AnraphetPathSize);
                    break;
                case EVENT_ANRAPHET_ACTIVATE:
                    Talk(ANRAPHET_SAY_INTRO);
                    events.ScheduleEvent(EVENT_ANRAPHET_DESTRUCTION, Seconds(10), 0, PHASE_INTRO);
                    break;
                case EVENT_ANRAPHET_DESTRUCTION:
                    DoCastAOE(SPELL_DESTRUCTION_PROTOCOL);
                    events.ScheduleEvent(EVENT_ANRAPHET_READY, Seconds(6), 0, PHASE_INTRO);
                    break;
                case EVENT_ANRAPHET_READY:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_ANRAPHET_NEMESIS_STRIKE:
                    DoCastVictim(SPELL_NEMESIS_STRIKE);
                    events.ScheduleEvent(EVENT_ANRAPHET_NEMESIS_STRIKE, Seconds(21), 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_ALPHA_BEAMS:
                    DoCastSelf(SPELL_ALPHA_BEAMS);
                    events.ScheduleEvent(EVENT_ANRAPHET_CRUMBLING_RUIN, Seconds(12), 0, PHASE_COMBAT);
                    events.ScheduleEvent(EVENT_ANRAPHET_ALPHA_BEAMS, Seconds(40), Seconds(45), 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_OMEGA_STANCE:
                    DoCastSelf(SPELL_OMEGA_STANCE);
                    Talk(ANRAPHET_SAY_OMEGA_STANCE);
                    events.ScheduleEvent(EVENT_ANRAPHET_OMEGA_STANCE, Seconds(45), Seconds(50), 0, PHASE_COMBAT);
                    events.ScheduleEvent(EVENT_ANRAPHET_CRUMBLING_RUIN, Seconds(13), 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_CRUMBLING_RUIN:
                    DoCastSelf(SPELL_CRUMBLING_RUIN);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 39908 Brann Bronzebeard
struct npc_brann_bronzebeard_anraphet : public CreatureAI
{
    npc_brann_bronzebeard_anraphet(Creature* creature) : CreatureAI(creature), _instance(creature->GetInstanceScript()) { }

    bool GossipHello(Player* player) override
    {
        if (!_instance)
            return true;

        uint32 gossipMenuId = GOSSIP_MENU_NO_TIME_TO_WASTE;

        if (_instance->GetData(DATA_VAULT_OF_LIGHTS) == NOT_STARTED)
            AddGossipItemFor(player, gossipMenuId, GOSSIP_OPTION_WE_ARE_READY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        else if (_instance->GetData(DATA_VAULT_OF_LIGHTS) != DONE)
            gossipMenuId = GOSSIP_MENU_DESTROY_ELEMENTAL;
        else
            gossipMenuId = GOSSIP_MENU_OCH_ITS_NOT_EASY;

        SendGossipMenuFor(player, player->GetGossipTextId(gossipMenuId, me), me->GetGUID());
        return true;
    }

    void Reset() override
    {
        canSayIdleEmote = _instance->GetData(DATA_VAULT_OF_LIGHTS) == NOT_STARTED;

        if (_instance->GetBossState(DATA_ANRAPHET) == DONE)
            me->SetHomePosition(BrannFinalHomePos);
        else if (_instance->GetData(DATA_VAULT_OF_LIGHTS) != NOT_STARTED)
            me->SetHomePosition(BrannBossHomePos);

        me->GetMotionMaster()->MoveTargetedHome();
    }

    bool GossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (_instance->GetData(DATA_VAULT_OF_LIGHTS) != NOT_STARTED)
            return false;

        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        events.Reset();
        events.RescheduleEvent(EVENT_BRANN_START_INTRO, Seconds(1));

        return true;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_BRANN_IDLE_EMOTE:
                if (canSayIdleEmote)
                {
                    canSayIdleEmote = false;
                    Talk(urand(0, 1) ? BRANN_SAY_BLASTED_TITANS : BRANN_SAY_THIS_SYMBOL);
                    events.ScheduleEvent(EVENT_BRANN_IDLE_EMOTE_COOLDOWN, Seconds(45)); // Cooldown for AreaTrigger
                }
                break;
            case ACTION_ELEMENTAL_DIED:
            {

                uint32 deadElementals = _instance->GetData(DATA_DEAD_ELEMENTALS);
                if (deadElementals < 4)
                    Talk(BRANN_1_ELEMENTAL_DEAD + deadElementals - 1);
                else
                    _instance->SetData(DATA_VAULT_OF_LIGHTS, DONE);
                events.RescheduleEvent(EVENT_BRANN_ACTIVATE_LASERBEAMS, Seconds(9));
                break;
            }
            case ACTION_ANRAPHET_DIED:
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                events.ScheduleEvent(EVENT_BRANN_MOVE_OUTRO, Seconds(5));
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BRANN_IDLE_EMOTE_COOLDOWN:
                    canSayIdleEmote = true;
                    break;
                case EVENT_BRANN_START_INTRO:
                    Talk(BRANN_SAY_DOOR_INTRO);
                    events.ScheduleEvent(EVENT_BRANN_UNLOCK_DOOR, Seconds(7));
                    break;
                case EVENT_BRANN_UNLOCK_DOOR:
                    Talk(BRANN_SAY_UNLOCK_DOOR);
                    _instance->SetData(DATA_VAULT_OF_LIGHTS, IN_PROGRESS);
                    events.ScheduleEvent(EVENT_BRANN_MOVE_INTRO, Seconds(3));
                    break;
                case EVENT_BRANN_MOVE_INTRO:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_BRANN_SAY_TROGGS, BrannBossHomePos, true);
                    break;
                case EVENT_BRANN_THINK:
                    Talk(BRANN_SAY_THINK);
                    events.ScheduleEvent(EVENT_BRANN_LOOK_RIGHT, Seconds(6));
                    break;
                case EVENT_BRANN_LOOK_RIGHT:
                    me->SetFacingTo(DegToRad(312.0f)); // Sniff: o = 5.445427f
                    Talk(BRANN_SAY_MIRRORS);
                    events.ScheduleEvent(EVENT_BRANN_LOOK_LEFT, Seconds(1));
                    break;
                case EVENT_BRANN_LOOK_LEFT:
                    me->SetFacingTo(DegToRad(36.0f)); // Sniff: o = 0.6283185f
                    events.ScheduleEvent(EVENT_BRANN_SAY_ELEMENTALS, Seconds(3));
                    break;
                case EVENT_BRANN_SAY_ELEMENTALS:
                    me->SetFacingTo(DegToRad(1.0f)); // Sniff: o = 0.01745329f
                    Talk(BRANN_SAY_ELEMENTALS);
                    events.ScheduleEvent(EVENT_BRANN_SAY_GET_IT, Seconds(4));
                    break;
                case EVENT_BRANN_SAY_GET_IT:
                    Talk(BRANN_SAY_GET_IT);
                    events.ScheduleEvent(EVENT_BRANN_SET_FLAG_GOSSIP, Seconds(16));
                    break;
                case EVENT_BRANN_SET_FLAG_GOSSIP:
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case EVENT_BRANN_ACTIVATE_LASERBEAMS:
                {
                    _instance->SetData(DATA_UPDATE_LASERBEAMS, 0);

                    if (_instance->GetData(DATA_VAULT_OF_LIGHTS) == DONE)
                    {
                        if (GameObject* mirror = _instance->GetGameObject(DATA_ANRAPHET_SUN_MIRROR))
                            mirror->SetGoState(GO_STATE_ACTIVE);
                        if (GameObject* door = _instance->GetGameObject(DATA_ANRAPHET_DOOR))
                            door->SetGoState(GO_STATE_ACTIVE);
                        events.ScheduleEvent(EVENT_BRANN_SAY_ALL_ELEMENTAL_DEAD, Seconds(4));
                    }
                    break;
                }
                case EVENT_BRANN_SAY_ALL_ELEMENTAL_DEAD:
                    Talk(BRANN_4_ELEMENTAL_DEAD);
                    if (Creature* anraphet = _instance->GetCreature(DATA_ANRAPHET))
                        anraphet->AI()->DoAction(ACTION_ANRAPHET_INTRO);
                    break;
                case EVENT_BRANN_MOVE_OUTRO:
                    Talk(BRANN_SAY_ANRAPHET_DIED);
                    me->GetMotionMaster()->MoveSmoothPath(POINT_BRANN_SAY_MOMENT, BrannOutroPath, BrannOutroPathSize, false);
                    break;
                case EVENT_BRANN_MOVE_FINAL:
                    me->GetMotionMaster()->MoveSmoothPath(POINT_BRANN_TURN_BACK, BrannFinalPath, BrannFinalPathSize, false);
                    break;
                case EVENT_BRANN_TURN_BACK:
                    me->SetFacingTo(DegToRad(180.0f)); // Sniff: 3.141593f
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
            }
        }
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE && movementType != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_BRANN_SAY_TROGGS:
                me->SetWalk(false);
                Talk(BRANN_SAY_TROGGS);
                events.ScheduleEvent(EVENT_BRANN_THINK, Seconds(15));
                break;
            case POINT_BRANN_SAY_MOMENT:
                Talk(BRANN_SAY_MOMENT);
                events.ScheduleEvent(EVENT_BRANN_MOVE_FINAL, Seconds(2));
                break;
            case POINT_BRANN_TURN_BACK:
                events.ScheduleEvent(EVENT_BRANN_TURN_BACK, Seconds(6));
                break;
            default:
                break;
        }
    }
private:
    InstanceScript * _instance;
    EventMap events;
    bool canSayIdleEmote;
};

struct npc_alpha_beam : public ScriptedAI
{
    npc_alpha_beam(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* anraphet = _instance->GetCreature(DATA_ANRAPHET))
            anraphet->CastSpell(me, SPELL_ALPHA_BEAMS_BACK_CAST);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { } // Never evade

private:
    InstanceScript * _instance;
};

struct npc_omega_stance : public ScriptedAI
{
    npc_omega_stance(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_OMEGA_STANCE_SPIDER_TRIGGER, true);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }
};

class PlayerCheck
{
    public:
        PlayerCheck() { }

        bool operator()(WorldObject* object)
        {
            return (object->GetTypeId() != TYPEID_PLAYER);
        }
};

// 77437 - Destruction Protocol
class spell_anraphet_destruction_protocol : public SpellScript
{
    PrepareSpellScript(spell_anraphet_destruction_protocol);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(PlayerCheck());
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* trogg = GetHitUnit()->ToCreature())
            trogg->SetRespawnTime(DAY);
    }

    void HandlePlayerDamage(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitPlayer())
            SetHitDamage(CalculatePct(player->GetHealth(), 90));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anraphet_destruction_protocol::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_anraphet_destruction_protocol::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_anraphet_destruction_protocol::HandlePlayerDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_anraphet_alpha_beams : public SpellScript
{
    PrepareSpellScript(spell_anraphet_alpha_beams);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anraphet_alpha_beams::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_anraphet_omega_stance : public AuraScript
{
    PrepareAuraScript(spell_anraphet_omega_stance);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_OMEGA_STANCE_SUMMON, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* omegaStanceDummy = GetTarget()->FindNearestCreature(NPC_OMEGA_STANCE, 50.0f, true))
            omegaStanceDummy->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anraphet_omega_stance::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_anraphet_omega_stance::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 77106 - Omega Stance (Summon)
class spell_anraphet_omega_stance_summon : public SpellScript
{
    PrepareSpellScript(spell_anraphet_omega_stance_summon);

    void SetDestPosition(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            float x = caster->GetPositionX();
            float y = caster->GetPositionY();
            float z = caster->GetPositionZ() + 30.0f;

            const_cast<WorldLocation*>(GetExplTargetDest())->Relocate(x, y, z);
            GetHitDest()->Relocate(x, y, z);
        }
    }

    void Register()
    {
        OnEffectLaunch += SpellEffectFn(spell_anraphet_omega_stance_summon::SetDestPosition, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// 77127 Omega Stance Spider Effect
class spell_anraphet_omega_stance_spider_effect : public SpellScript
{
    PrepareSpellScript(spell_anraphet_omega_stance_spider_effect);

    void SetDestPosition(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        float angle = float(rand_norm()) * static_cast<float>(2 * M_PI);
        uint32 dist = caster->GetCombatReach() + GetSpellInfo()->Effects[EFFECT_0].CalcRadius(caster) * (float)rand_norm();

        float x = caster->GetPositionX() + dist * std::cos(angle);
        float y = caster->GetPositionY() + dist * std::sin(angle);
        float z = caster->GetMap()->GetHeight(caster->GetPhaseShift(), x, y, caster->GetPositionZ());
        float o = GetHitDest()->GetOrientation();

        GetHitDest()->Relocate({ x, y, z, o });
    }

    void Register()
    {
        OnEffectLaunch += SpellEffectFn(spell_anraphet_omega_stance_spider_effect::SetDestPosition, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 5811 Brann's AreaTrigger
class at_hoo_brann_idle_emote : public AreaTriggerScript
{
    public:
        at_hoo_brann_idle_emote() : AreaTriggerScript("at_hoo_brann_idle_emote") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* brann = instance->GetCreature(DATA_BRANN_0))
                    brann->AI()->DoAction(ACTION_BRANN_IDLE_EMOTE);
            return true;
        }
};

void AddSC_boss_anraphet()
{
    RegisterHallsOfOriginationCreatureAI(boss_anraphet);
    RegisterHallsOfOriginationCreatureAI(npc_brann_bronzebeard_anraphet);
    RegisterHallsOfOriginationCreatureAI(npc_alpha_beam);
    RegisterHallsOfOriginationCreatureAI(npc_omega_stance);
    RegisterSpellScript(spell_anraphet_destruction_protocol);
    RegisterSpellScript(spell_anraphet_alpha_beams);
    RegisterAuraScript(spell_anraphet_omega_stance);
    RegisterSpellScript(spell_anraphet_omega_stance_summon);
    RegisterSpellScript(spell_anraphet_omega_stance_spider_effect);
    new at_hoo_brann_idle_emote();
}
