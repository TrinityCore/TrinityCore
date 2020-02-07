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

#include "scarlet_monastery.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "InstanceScript.h"
#include "LFGMgr.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "Timer.h"

// this texts are already used by 3975 and 3976
enum HeadlessHorsemanSays
{
    SAY_LOST_HEAD          = 0,
    SAY_PLAYER_DEATH       = 1,

    SAY_ENTRANCE           = 0,
    SAY_REJOINED           = 1,
    SAY_CONFLAGRATION      = 2,
    SAY_SPROUTING_PUMPKINS = 3,
    SAY_DEATH              = 4,
};

std::vector<uint32> HeadlessHorsemanRandomLaughSound = { 11965u, 11975u, 11976u };

enum HeadlessHorsemanEntry
{
    NPC_HEADLESS_HORSEMAN_MOUNTED    = 23682,
    NPC_HEADLESS_HORSEMAN_DISMOUNTED = 23800,
    NPC_HEADLESS_HORSEMAN_HEAD       = 23775,
    NPC_PULSING_PUMPKIN              = 23694,
    NPC_PUMPKIN_FIEND                = 23545,
    NPC_HELPER                       = 23686,
    NPC_WISP_INVIS                   = 24034
};

enum HeadlessHorsemanSpells
{
    SPELL_CONFLAGRATION                                                       = 42380,
    SPELL_HORSEMANS_CONFLAGRATION                                             = 42381, // Triggered from SPELL_CONFLAGRATION
    SPELL_HORSEMANS_SUMMON                                                    = 42394,
    SPELL_HEADLESS_HORSEMAN_CLIMAX___HORSEMANS_WHIRLWIND                      = 43116,
    SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN_REMOVED_ON_DEATH              = 42556,
    SPELL_HORSEMANS_CLEAVE                                                    = 42587, // Triggered from SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN_REMOVED_ON_DEATH
    SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN                               = 42403,
    SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN_CONFUSE_ONLY_REMOVED_ON_DEATH = 43105,
    SPELL_HEADLESS_HORSEMAN_CLIMAX___SEND_HEAD                                = 42399, // Visual flying head
    SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_VISUAL                              = 42413, // Visual buff, "head"
    SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_IS_DEAD                             = 42428, // At killing head, Phase 3
    SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_IS_DEAD_TRIGGERED                   = 42566, // Triggered from SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_IS_DEAD
    SPELL_PUMPKIN_LIFE_CYCLE                                                  = 42280,
    SPELL_HEADLESS_HORSEMAN___PUMPKIN_AURA                                    = 42294,
    SPELL_SQUASH_SOUL                                                         = 42514,
    SPELL_SPROUTING                                                           = 42281,
    SPELL_SPROUT_BODY                                                         = 42285,
    SPELL_HEADLESS_HORSEMAN_CLIMAX___SUMMONING_RHYME_SHAKE_MEDIUM             = 42909,
    SPELL_HEADLESS_HORSEMAN_CLIMAX___SUMMONING_RHYME_SHAKE_SMALL              = 42910,
    SPELL_HEADLESS_HORSEMAN___SPEAKS                                          = 43129,
    SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_LANDS                               = 42400,
    SPELL_HEADLESS_HORSEMAN___FIRE                                            = 42074,
    SPELL_HEADLESS_HORSEMAN___BURNING_COSMETIC                                = 42971,
    SPELL_HEADLESS_HORSEMAN_CLIMAX___ENRAGED_VISUAL                           = 42438, // Is this used?
    SPELL_HEADLESS_HORSEMAN___WISP_FLIGHT_MISSILE                             = 42821,
    SPELL_HEADLESS_HORSEMAN___WISP_FLIGHT_PORT                                = 42818, // Triggered from SPELL_HEADLESS_HORSEMAN___WISP_FLIGHT_MISSILE
    SPELL_HEADLESS_HORSEMAN___WISP_INVIS                                      = 42823,
    SPELL_HEADLESS_HORSEMAN___SMOKE                                           = 42355,
};

enum HeadlessHorsemanMisc
{
    DISPLAYID_INVIS_WISP_MAN = 2027,
    DISPLAYID_INVIS_WISP_INVISIBLE = 21908,

    DATA_INVIS_WISP_CREATURE_TYPE = 0,
    DATA_HEAD_TALK,
    DATA_HEAD_PHASE,

    INVIS_WISP_CREATURE_TYPE_PUMPKIN = 1,
    INVIS_WISP_CREATURE_TYPE_FLAME,
    INVIS_WISP_CREATURE_TYPE_SMOKE,
    INVIS_WISP_CREATURE_TYPE_BLUE,

    ACTION_HEAD_RETURN_TO_BODY = 0,
    ACTION_HEAD_KILLED,
    ACTION_HORSEMAN_EVENT_START,

    PHASE_HEAD_1 = 1,
    PHASE_HEAD_2,
    PHASE_HEAD_3,

    PHASE_BODY_0 = 0,
    PHASE_BODY_1,
    PHASE_BODY_2,
    PHASE_BODY_3,

    TASK_GROUP_COMBAT = 1,
    TASK_GROUP_WITHOUT_HEAD,

    POINT_HORSEMAN_0 = 0,
    POINT_HORSEMAN_1 = 1,
    POINT_HORSEMAN_6 = 6,
    POINT_HORSEMAN_19 = 19,
    POINT_HORSEMAN_20 = 20,

    LFG_DUNGEONID_THE_HEADLESS_HORSEMAN = 285,
};

std::vector<Position> const HeadlessHorsemanFlightPoints =
{
    { 1754.00f, 1346.00f, 17.50f },
    { 1765.00f, 1347.00f, 19.00f },
    { 1784.00f, 1346.80f, 25.40f },
    { 1803.30f, 1347.60f, 33.00f },
    { 1824.00f, 1350.00f, 42.60f },
    { 1838.80f, 1353.20f, 49.80f },
    { 1852.00f, 1357.60f, 55.70f },
    { 1861.30f, 1364.00f, 59.40f },
    { 1866.30f, 1374.80f, 61.70f },
    { 1864.00f, 1387.30f, 63.20f },
    { 1854.80f, 1399.40f, 64.10f },
    { 1844.00f, 1406.90f, 64.10f },
    { 1824.30f, 1411.40f, 63.30f },
    { 1801.00f, 1412.30f, 60.40f },
    { 1782.00f, 1410.10f, 55.50f },
    { 1770.50f, 1405.20f, 50.30f },
    { 1765.20f, 1400.70f, 46.60f },
    { 1761.40f, 1393.40f, 41.70f },
    { 1759.10f, 1386.70f, 36.60f },
    { 1757.80f, 1378.20f, 29.00f },
    { 1758.00f, 1367.00f, 19.51f }
};

std::vector<Position> const HeadlessHorsemanSpawnPoints =
{
    { 1776.27f, 1348.74f, 19.20f }, // spawn point for pumpkin shrine mob
    { 1765.28f, 1347.46f, 17.55f }  // spawn point for smoke
};

//@todo Dear Lord, please someone have mercy and let this die soon
static char const* HeadlessHorsemanInitialPlayerTexts[] =
{
    "Horseman rise...",
    "Your time is nigh...",
    "You felt death once...",
    "Now, know demise!"
};

struct npc_wisp_invis : public ScriptedAI
{
    npc_wisp_invis(Creature* creature) : ScriptedAI(creature), _timer(0), _creatureType(0), _firstSpell(0), _secondSpell(0)
    {
        creature->SetDisplayId(DISPLAYID_INVIS_WISP_INVISIBLE);
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type != DATA_INVIS_WISP_CREATURE_TYPE)
            return;

        switch (_creatureType = value)
        {
            case INVIS_WISP_CREATURE_TYPE_PUMPKIN:
                _firstSpell = SPELL_HEADLESS_HORSEMAN___PUMPKIN_AURA;
                break;
            case INVIS_WISP_CREATURE_TYPE_FLAME:
                _timer.Reset(15 * IN_MILLISECONDS);
                _firstSpell = SPELL_HEADLESS_HORSEMAN___FIRE;
                _secondSpell = SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_IS_DEAD;
                break;
            case INVIS_WISP_CREATURE_TYPE_SMOKE:
                _timer.Reset(15 * IN_MILLISECONDS);
                _firstSpell = SPELL_HEADLESS_HORSEMAN___SMOKE;
                break;
            case INVIS_WISP_CREATURE_TYPE_BLUE:
                _timer.Reset(7 * IN_MILLISECONDS);
                _secondSpell = SPELL_HEADLESS_HORSEMAN___WISP_FLIGHT_MISSILE;
                break;
            default:
                break;
        }
        if (_firstSpell)
            DoCastSelf(_firstSpell);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_HEADLESS_HORSEMAN___WISP_FLIGHT_PORT && _creatureType == 4)
            me->SetDisplayId(DISPLAYID_INVIS_WISP_MAN);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || _creatureType != INVIS_WISP_CREATURE_TYPE_PUMPKIN || !who->isTargetableForAttack())
            return;

        if (me->IsWithinDist(who, 0.1f, false) && !who->HasAura(SPELL_SQUASH_SOUL))
            DoCast(who, SPELL_SQUASH_SOUL);
    }

    void UpdateAI(uint32 diff) override
    {
        if (_timer.Passed())
            return;

        _timer.Update(diff);
        if (_timer.Passed())
        {
            me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN___SMOKE);
            if (_secondSpell)
                DoCast(me, _secondSpell);
            _timer.Reset(0);
        }
    }

private:
    TimeTrackerSmall _timer;
    uint32 _creatureType;
    uint32 _firstSpell;
    uint32 _secondSpell;
};

struct npc_head : public ScriptedAI
{
    npc_head(Creature* creature) : ScriptedAI(creature), _laughTimer(urand(15 * IN_MILLISECONDS, 30 * IN_MILLISECONDS))
    {
        creature->SetReactState(REACT_PASSIVE);
        Initialize();
    }

    void Initialize()
    {
        _bodyGUID = ObjectGuid::Empty;
        _phase = 0;
        _withBody = true;
        _die = false;
    }

    void Reset() override
    {
        Initialize();
        _laughTimer.Reset(urand(15 * IN_MILLISECONDS, 30 * IN_MILLISECONDS));
        _scheduler.CancelAll();

        // Just to be sure it's MOTION_SLOT_DEFAULT is static
        me->GetMotionMaster()->MoveIdle();
    }

    void SetData(uint32 type, uint32 value) override
    {
        switch (type)
        {
            case DATA_HEAD_TALK:
                DoTalk(value);
                break;
            case DATA_HEAD_PHASE:
                _phase = value;
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (_withBody)
            return;

        if (_die)
        {
            damage = 0;
            return;
        }

        switch (_phase)
        {
            case PHASE_HEAD_1:
                if (me->HealthBelowPctDamaged(67, damage))
                    ReturnToBody(true);
                break;
            case PHASE_HEAD_2:
                if (me->HealthBelowPctDamaged(34, damage))
                    ReturnToBody(true);
                break;
            case PHASE_HEAD_3:
                if (!_die && damage >= me->GetHealth())
                {
                    _die = true;
                    damage = 0;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->GetMotionMaster()->Clear();

                    DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_IS_DEAD);

                    _scheduler.Schedule(3s, [this](TaskContext /*context*/)
                    {
                        if (Unit* body = ObjectAccessor::GetUnit(*me, _bodyGUID))
                            body->KillSelf();
                        me->KillSelf();
                    });
                }
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (!_withBody)
            return;

        if (spell->Id == SPELL_HEADLESS_HORSEMAN_CLIMAX___SEND_HEAD)
        {
            _withBody = false;

            if (!_bodyGUID)
                _bodyGUID = caster->GetGUID();

            me->RemoveAllAuras();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->GetMotionMaster()->Clear();

            DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_LANDS, true);
            DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_VISUAL);

            DoTalk(SAY_LOST_HEAD);

            _scheduler.Schedule(2s, [caster, this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MoveFleeing(caster);
            });
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_HEAD_RETURN_TO_BODY:
                ReturnToBody(false);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (_withBody)
            return;

        if (!_laughTimer.Passed())
            _laughTimer.Update(diff);

        if (_laughTimer.Passed())
        {
            _laughTimer.Reset(urand(15 * IN_MILLISECONDS, 30 * IN_MILLISECONDS));

            DoPlaySoundToSet(me, Trinity::Containers::SelectRandomContainerElement(HeadlessHorsemanRandomLaughSound));

            if (Creature* speaker = DoSpawnCreature(NPC_HELPER, 0.f, 0.f, 0.f, 0.f, TEMPSUMMON_TIMED_DESPAWN, 1 * IN_MILLISECONDS))
                speaker->CastSpell(speaker, SPELL_HEADLESS_HORSEMAN___SPEAKS, false);
        }
    }

private:
    void ReturnToBody(bool advance)
    {
        if (_withBody || _bodyGUID.IsEmpty())
            return;

        Creature* body = ObjectAccessor::GetCreature(*me, _bodyGUID);
        if (!body || !body->IsAlive())
        {
            me->DespawnOrUnsummon();
            return;
        }

        _withBody = true;
        me->RemoveAllAuras();
        me->SetFullHealth();
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->GetMotionMaster()->MoveIdle();

        if (advance)
            body->AI()->DoAction(ACTION_HEAD_KILLED);

        body->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN_REMOVED_ON_DEATH); // hack, SpellHit doesn't calls if body has immune aura
        DoCast(body, SPELL_HEADLESS_HORSEMAN_CLIMAX___SEND_HEAD);
    }

    void DoTalk(uint32 entry)
    {
        Talk(entry);
        _laughTimer.Reset(3 * IN_MILLISECONDS);

        if (Creature* speaker = DoSpawnCreature(NPC_HELPER, 0.f, 0.f, 0.f, 0.f, TEMPSUMMON_TIMED_DESPAWN, 1 * IN_MILLISECONDS))
            speaker->CastSpell(speaker, SPELL_HEADLESS_HORSEMAN___SPEAKS, false);
    }

    TaskScheduler _scheduler;
    TimeTrackerSmall _laughTimer;
    ObjectGuid _bodyGUID;
    uint32 _phase;
    bool _withBody;
    bool _die;
};

struct boss_headless_horseman : public ScriptedAI
{
    boss_headless_horseman(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _laughTimer(0), _phase(0), _id(0)
    {
        Initialize();

        _scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void Initialize()
    {
        _withHead = true;
    }

    void InitializeAI() override
    {
        me->SetImmuneToPC(false);
        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        _laughTimer.Reset(0);
        Initialize();

        DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_VISUAL);
        if (_headGUID)
        {
            if (Creature* head = ObjectAccessor::GetCreature(*me, _headGUID))
                head->DespawnOrUnsummon();

            _headGUID.Clear();
        }

        me->SetImmuneToPC(false);

        // Just to be sure it's MOTION_SLOT_DEFAULT is static
        me->GetMotionMaster()->MoveIdle();

        _instance->SetBossState(DATA_HORSEMAN_EVENT, NOT_STARTED);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _phase = PHASE_BODY_1;
        ScriptedAI::EnterEvadeMode(why);
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_HORSEMAN_EVENT_START:
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetCanFly(true);
                me->SetWalk(false);

                _id = 0;
                _phase = PHASE_BODY_0;

                _scheduler.Schedule(3s, [this](TaskContext talkContext)
                {
                    if (talkContext.GetRepeatCounter() < 3)
                    {
                        if (me->GetMap()->HavePlayers())
                        {
                            RefManager<Map, Player> const& players = me->GetMap()->GetPlayers();
                            LinkedListHead::Iterator<Reference<Map, Player> const> it = players.RefManager<Map, Player>::begin();
                            std::advance(it, urand(0, uint32(me->GetMap()->GetPlayers().getSize()) - 1));
                            if (Player* player = it->GetSource())
                                player->Say(HeadlessHorsemanInitialPlayerTexts[talkContext.GetRepeatCounter()], LANG_UNIVERSAL);
                        }
                        talkContext.Repeat(3s);
                    }
                    else
                    {
                        DoCast(SPELL_HEADLESS_HORSEMAN_CLIMAX___SUMMONING_RHYME_SHAKE_MEDIUM);
                        if (me->GetMap()->HavePlayers())
                        {
                            RefManager<Map, Player> const& players = me->GetMap()->GetPlayers();
                            LinkedListHead::Iterator<Reference<Map, Player> const> it = players.RefManager<Map, Player>::begin();
                            std::advance(it, urand(0, uint32(me->GetMap()->GetPlayers().getSize()) - 1));
                            if (Player* player = it->GetSource())
                            {
                                player->Say(HeadlessHorsemanInitialPlayerTexts[talkContext.GetRepeatCounter()], LANG_UNIVERSAL);
                                player->HandleEmoteCommand(ANIM_EMOTE_SHOUT);
                            }
                        }

                        me->GetMotionMaster()->MovePoint(_id, HeadlessHorsemanFlightPoints[_id]);
                    }
                });
                break;
            case ACTION_HEAD_KILLED:
                if (_phase < 3)
                    ++_phase;
                else
                    _phase = 3;
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE || _phase != PHASE_BODY_0 || id != _id)
            return;

        switch (id)
        {
            case POINT_HORSEMAN_0:
                me->SetVisible(true);
                break;
            case POINT_HORSEMAN_1:
                if (Creature* smoke = me->SummonCreature(NPC_HELPER, HeadlessHorsemanSpawnPoints[1], TEMPSUMMON_TIMED_DESPAWN, 20 * IN_MILLISECONDS))
                    smoke->AI()->SetData(DATA_INVIS_WISP_CREATURE_TYPE, INVIS_WISP_CREATURE_TYPE_SMOKE);
                DoCast(SPELL_HEADLESS_HORSEMAN_CLIMAX___SUMMONING_RHYME_SHAKE_MEDIUM);
                break;
            case POINT_HORSEMAN_6:
                _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_PUMPKIN_SHRINE));
                break;
            case POINT_HORSEMAN_19:
                me->SetCanFly(false);
                break;
            case POINT_HORSEMAN_20:
                _phase = PHASE_BODY_1;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetHomePosition(me->GetPosition());
                DoTalk(SAY_ENTRANCE);
                DoZoneInCombat();
                break;
            default:
                break;
        }

        ++_id;
        if (_id <= POINT_HORSEMAN_20)
            me->GetMotionMaster()->MovePoint(_id, HeadlessHorsemanFlightPoints[_id]);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _instance->SetBossState(DATA_HORSEMAN_EVENT, IN_PROGRESS);
        DoZoneInCombat();

        _scheduler.Schedule(2s, uint32(TASK_GROUP_COMBAT), [this](TaskContext cleaveContext)
        {
            DoCastVictim(SPELL_HORSEMANS_CLEAVE);
            cleaveContext.Repeat(2s, 6s);
        }).Schedule(6s, uint32(TASK_GROUP_COMBAT), [this](TaskContext /*burnContext*/)
        {
            if (Creature* flame = me->SummonCreature(NPC_HELPER, HeadlessHorsemanSpawnPoints[0], TEMPSUMMON_TIMED_DESPAWN, 17 * IN_MILLISECONDS))
                flame->AI()->SetData(DATA_INVIS_WISP_CREATURE_TYPE, INVIS_WISP_CREATURE_TYPE_FLAME);
        });
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (_withHead && _phase != PHASE_BODY_0)
            ScriptedAI::MoveInLineOfSight(who);
    }

    void KilledUnit(Unit* player) override
    {
        if (player->GetTypeId() != TYPEID_PLAYER)
            return;

        if (_withHead)
            DoTalk(SAY_PLAYER_DEATH);
        else if (Creature* head = ObjectAccessor::GetCreature(*me, _headGUID))
            head->AI()->SetData(DATA_HEAD_TALK, SAY_PLAYER_DEATH);
    }

    void SpellHitTarget(Unit* unit, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_CONFLAGRATION && unit->HasAura(SPELL_CONFLAGRATION))
            DoTalk(SAY_CONFLAGRATION, unit);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoTalk(SAY_DEATH);
        if (Creature* flame = DoSpawnCreature(NPC_HELPER, 0.f, 0.f, 0.f, 0.f, TEMPSUMMON_TIMED_DESPAWN, 60 * IN_MILLISECONDS))
            flame->CastSpell(flame, SPELL_HEADLESS_HORSEMAN___FIRE);
        if (Creature* wisp = DoSpawnCreature(NPC_WISP_INVIS, 0.f, 0.f, 0.f, 0.f, TEMPSUMMON_TIMED_DESPAWN, 60 * IN_MILLISECONDS))
            wisp->AI()->SetData(DATA_INVIS_WISP_CREATURE_TYPE, INVIS_WISP_CREATURE_TYPE_BLUE);

        _instance->SetBossState(DATA_HORSEMAN_EVENT, DONE);

        if (me->GetMap()->HavePlayers())
        {
            if (Group* group = me->GetMap()->GetPlayers().begin()->GetSource()->GetGroup())
                if (group->isLFGGroup())
                    sLFGMgr->FinishDungeon(group->GetGUID(), LFG_DUNGEONID_THE_HEADLESS_HORSEMAN, me->GetMap());
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
    {
        if (_withHead)
            return;

        if (spellInfo->Id != SPELL_HEADLESS_HORSEMAN_CLIMAX___SEND_HEAD)
            return;

        _laughTimer.Reset(urand(2 * IN_MILLISECONDS, 5 * IN_MILLISECONDS));
        _withHead = true;
        _scheduler.CancelGroup(TASK_GROUP_WITHOUT_HEAD);

        me->InterruptNonMeleeSpells(true);
        me->RemoveAllAuras();
        me->SetName("Headless Horseman"); //@todo THIS can't be serious
        me->SetFullHealth();

        DoTalk(SAY_REJOINED);
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___HEAD_VISUAL);
        caster->GetMotionMaster()->Clear();
        caster->GetMotionMaster()->MoveFollow(me, 6.f, 0.f);

        switch (_phase)
        {
            case PHASE_BODY_1:
                _scheduler.Schedule(2s, uint32(TASK_GROUP_COMBAT), [this](TaskContext cleaveContext)
                {
                    DoCastVictim(SPELL_HORSEMANS_CLEAVE);
                    cleaveContext.Repeat(2s, 6s);
                }).Schedule(6s, uint32(TASK_GROUP_COMBAT), [this](TaskContext /*burnContext*/)
                {
                    if (Creature* flame = me->SummonCreature(NPC_HELPER, HeadlessHorsemanSpawnPoints[0], TEMPSUMMON_TIMED_DESPAWN, 17 * IN_MILLISECONDS))
                        flame->AI()->SetData(DATA_INVIS_WISP_CREATURE_TYPE, INVIS_WISP_CREATURE_TYPE_FLAME);
                });
                break;
            case PHASE_BODY_2:
                _scheduler.Schedule(2s, uint32(TASK_GROUP_COMBAT), [this](TaskContext cleaveContext)
                {
                    DoCastVictim(SPELL_HORSEMANS_CLEAVE);
                    cleaveContext.Repeat(2s, 6s);
                }).Schedule(15s, uint32(TASK_GROUP_COMBAT), [this](TaskContext clonfragateContext)
                {
                    if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true, false, -SPELL_CONFLAGRATION))
                        DoCast(player, SPELL_CONFLAGRATION, false);
                    clonfragateContext.Repeat(10s, 16s);
                });
                break;
            case PHASE_BODY_3:
                _scheduler.Schedule(2s, uint32(TASK_GROUP_COMBAT), [this](TaskContext cleaveContext)
                {
                    DoCastVictim(SPELL_HORSEMANS_CLEAVE);
                    cleaveContext.Repeat(2s, 6s);
                }).Schedule(15s, uint32(TASK_GROUP_COMBAT), [this](TaskContext summonAddsContext)
                {
                    me->InterruptNonMeleeSpells(false);
                    DoCastSelf(SPELL_HORSEMANS_SUMMON);
                    DoTalk(SAY_SPROUTING_PUMPKINS);
                    summonAddsContext.Repeat(25s, 35s);
                });
                break;
            default:
                break;
        }

    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (damage < me->GetHealth() || !_withHead)
        {
            if (damage >= me->GetHealth() && !_withHead)
                damage = 0;
            return;
        }

        damage = 0;
        _withHead = false;
        _scheduler.CancelGroup(TASK_GROUP_COMBAT);
        me->InterruptNonMeleeSpells(true);
        me->RemoveAllAuras();
        me->SetName("Headless Horseman, Unhorsed"); //@todo THIS can't be serious
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN_REMOVED_ON_DEATH, true);
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN, true);
        DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN_CONFUSE_ONLY_REMOVED_ON_DEATH, false); // test

        Creature* head = nullptr;
        if (!_headGUID)
        {
            if (Creature* newHead = DoSpawnCreature(NPC_HEADLESS_HORSEMAN_HEAD, frand(0.f, 5.f), frand(0.f, 5.f), 0, 0, TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                _headGUID = newHead->GetGUID();
                head = newHead;
            }
        }

        if (!head)
            head = ObjectAccessor::GetCreature(*me, _headGUID);
        if (head && head->IsAlive())
        {
            head->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            head->AI()->SetData(DATA_HEAD_PHASE, _phase);
            DoCast(head, SPELL_HEADLESS_HORSEMAN_CLIMAX___SEND_HEAD, true);
        }

        _scheduler.Schedule(2s, uint32(TASK_GROUP_WITHOUT_HEAD), [this](TaskContext whirlwindContext)
        {
            if (roll_chance_i(50))
            {
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN_CONFUSE_ONLY_REMOVED_ON_DEATH);
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___HORSEMANS_WHIRLWIND, true);
                DoCastSelf(SPELL_HEADLESS_HORSEMAN_CLIMAX___BODY_REGEN_CONFUSE_ONLY_REMOVED_ON_DEATH);
            }
            else
                me->RemoveAurasDueToSpell(SPELL_HEADLESS_HORSEMAN_CLIMAX___HORSEMANS_WHIRLWIND);

            if (!_withHead)
                whirlwindContext.Repeat(4s, 8s);
        }).Schedule(1s, uint32(TASK_GROUP_WITHOUT_HEAD), [this](TaskContext regenerateContext)
        {
            if (me->IsFullHealth() && !_withHead)
            {
                Creature* head = ObjectAccessor::GetCreature(*me, _headGUID);
                if (head && head->IsAlive())
                    head->AI()->DoAction(ACTION_HEAD_RETURN_TO_BODY);
            }
            else
                regenerateContext.Repeat(1s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_laughTimer.Passed())
            _laughTimer.Update(diff);

        if (_withHead && _laughTimer.Passed())
        {
            _laughTimer.Reset(urand(11 * IN_MILLISECONDS, 22 * IN_MILLISECONDS));
            DoPlaySoundToSet(me, Trinity::Containers::SelectRandomContainerElement(HeadlessHorsemanRandomLaughSound));
        }

        if (UpdateVictim())
        {
            _scheduler.Update(diff, [this]
            {
                if (_withHead)
                    DoMeleeAttackIfReady();
            });
        }
        else
            _scheduler.Update(diff);
    }

private:
    void DoTalk(uint8 textEntry, Unit* target = nullptr)
    {
        Talk(textEntry, target);
        _laughTimer.Reset(std::min<uint32>(10 * IN_MILLISECONDS, _laughTimer.GetExpiry() + 4 * IN_MILLISECONDS));
    }

    InstanceScript* _instance;
    TaskScheduler _scheduler;
    TimeTrackerSmall _laughTimer;
    ObjectGuid _headGUID;
    uint32 _phase;
    uint32 _id;
    bool _withHead;
};

struct npc_pulsing_pumpkin : public ScriptedAI
{
    npc_pulsing_pumpkin(Creature* creature) : ScriptedAI(creature)
    {
        _sprouted = false;
    }

    void Reset() override
    {
        _debuffGUID.Clear();

        Despawn();

        Creature* debuff = DoSpawnCreature(NPC_HELPER, 0.f, 0.f, 0.f, 0.f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 14 * IN_MILLISECONDS + 500);
        if (debuff)
        {
            debuff->SetDisplayId(me->GetDisplayId());
            debuff->AI()->SetData(DATA_INVIS_WISP_CREATURE_TYPE, INVIS_WISP_CREATURE_TYPE_PUMPKIN);
            _debuffGUID = debuff->GetGUID();
        }

        _sprouted = false;

        DoCastSelf(SPELL_PUMPKIN_LIFE_CYCLE, true);
        DoCastSelf(SPELL_SPROUTING);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SPROUTING)
        {
            _sprouted = true;
            me->RemoveAllAuras();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            DoCastSelf(SPELL_SPROUT_BODY, true);
            DoZoneInCombat();
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (!_sprouted)
            Despawn();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (_sprouted)
            ScriptedAI::MoveInLineOfSight(who);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (_sprouted && UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    void Despawn()
    {
        if (!_debuffGUID)
            return;

        Creature* debuff = ObjectAccessor::GetCreature(*me, _debuffGUID);
        if (debuff)
            debuff->DespawnOrUnsummon();

        _debuffGUID.Clear();
    }

    ObjectGuid _debuffGUID;
    bool _sprouted;
};

enum LooselyTurnedSoil
{
    QUEST_CALL_THE_HEADLESS_HORSEMAN = 11405
};

struct go_loosely_turned_soil : public GameObjectAI
{
    go_loosely_turned_soil(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

    bool GossipHello(Player* player) override
    {
        if (instance->GetBossState(DATA_HORSEMAN_EVENT) == IN_PROGRESS || player->GetQuestStatus(QUEST_CALL_THE_HEADLESS_HORSEMAN) != QUEST_STATUS_COMPLETE)
            return true;

        return false;
    }

    void QuestReward(Player* player, Quest const* /*quest*/, uint32 /*opt*/) override
    {
        if (instance->GetBossState(DATA_HORSEMAN_EVENT) == IN_PROGRESS)
            return;

        player->AreaExploredOrEventHappens(11405);

        if (TempSummon* horseman = me->GetMap()->SummonCreature(NPC_HEADLESS_HORSEMAN_MOUNTED, HeadlessHorsemanFlightPoints[20]))
        {
            horseman->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
            horseman->AI()->DoAction(ACTION_HORSEMAN_EVENT_START);
        }
    }

private:
    InstanceScript* instance;
};

void AddSC_boss_headless_horseman()
{
    RegisterScarletMonasteryCreatureAI(boss_headless_horseman);
    RegisterScarletMonasteryCreatureAI(npc_head);
    RegisterScarletMonasteryCreatureAI(npc_pulsing_pumpkin);
    RegisterScarletMonasteryCreatureAI(npc_wisp_invis);
    RegisterScarletMonasteryGameObjectAI(go_loosely_turned_soil);
}
