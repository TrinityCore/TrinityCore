/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
    SAY_LOST_HEAD                    = 0,
    SAY_PLAYER_DEATH                 = 1,

    SAY_ENTRANCE                     = 0,
    SAY_REJOINED                     = 1,
    SAY_CONFLAGRATION                = 2,
    SAY_SPROUTING_PUMPKINS           = 3,
    SAY_DEATH                        = 4,
};

std::vector<uint32> HeadlessHorsemanRandomLaughSound = { 11965u, 11975u, 11976u };

enum HeadlessHorsemanEntry
{
    NPC_HEADLESS_HORSEMAN_MOUNTED    = 23682,
    NPC_HEADLESS_HORSEMAN_DISMOUNTED = 23800,
    NPC_HEAD                         = 23775,
    NPC_PULSING_PUMPKIN              = 23694,
    NPC_PUMPKIN_FIEND                = 23545,
    NPC_HELPER                       = 23686,
    NPC_WISP_INVIS                   = 24034
};

enum HeadlessHorsemanSpells
{
    SPELL_CLEAVE                     = 42587,
    SPELL_CONFLAGRATION              = 42380, // Phase 2, can't find real spell (Dim Fire?)
 // SPELL_CONFL_SPEED                = 22587, // 8% increase speed, value 22587 from SPELL_CONFLAGRATION mains that spell?
    SPELL_SUMMON_PUMPKIN             = 42394,
    SPELL_WHIRLWIND                  = 43116,
    SPELL_IMMUNE                     = 42556,
    SPELL_BODY_REGEN                 = 42403,
    SPELL_CONFUSE                    = 43105,
    SPELL_FLYING_HEAD                = 42399, // visual flying head
    SPELL_HEAD                       = 42413, // visual buff, "head"
    SPELL_HEAD_IS_DEAD               = 42428, // at killing head, Phase 3
    SPELL_PUMPKIN_AURA               = 42280,
    SPELL_PUMPKIN_AURA_GREEN         = 42294,
    SPELL_SQUASH_SOUL                = 42514,
    SPELL_SPROUTING                  = 42281,
    SPELL_SPROUT_BODY                = 42285,
    SPELL_RHYME_BIG                  = 42909,
 // SPELL_RHYME_SMALL                = 42910,
    SPELL_HEAD_SPEAKS                = 43129,
    SPELL_HEAD_LANDS                 = 42400,
    SPELL_BODY_FLAME                 = 42074,
    SPELL_HEAD_FLAME                 = 42971,
 // SPELL_ENRAGE_VISUAL              = 42438, // he uses this spell?
    SPELL_WISP_BLUE                  = 42821,
    SPELL_WISP_FLIGHT_PORT           = 42818,
 // SPELL_WISP_INVIS                 = 42823,
    SPELL_SMOKE                      = 42355,
    SPELL_DEATH                      = 42566  // not correct spell
};

enum HeadlessHorsemanMisc
{
    DISPLAYID_INVIS_WISP = 2027,

    DATA_INVIS_WISP_CREATURE_TYPE = 0,
    DATA_HEAD_TALK,

    INVIS_WISP_CREATURE_TYPE_PUMPKIN = 1,
    INVIS_WISP_CREATURE_TYPE_FLAME,
    INVIS_WISP_CREATURE_TYPE_SMOKE,
    INVIS_WISP_CREATURE_TYPE_BLUE,

    ACTION_HEAD_DISAPPEAR = 0,
    ACTION_HORSEMAN_EVENT_START,

    PHASE_HEAD_1 = 0,
    PHASE_HEAD_2,
    PHASE_HEAD_3,

    POINT_HORSEMAN_0 = 0,
    POINT_HORSEMAN_1 = 1,
    POINT_HORSEMAN_6 = 6,
    POINT_HORSEMAN_19 = 19,
    POINT_HORSEMAN_20 = 20,
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
static char const* Text[] =
{
    "Horseman rise...",
    "Your time is nigh...",
    "You felt death once...",
    "Now, know demise!"
};

struct npc_wisp_invis : public ScriptedAI
{
    npc_wisp_invis(Creature* creature) : ScriptedAI(creature), _creatureType(0), _timer(0), _firstSpell(0), _secondSpell(0) { }

    void SetData(uint32 type, uint32 value) override
    {
        if (type != DATA_INVIS_WISP_CREATURE_TYPE)
            return;

        switch (_creatureType = value)
        {
            case INVIS_WISP_CREATURE_TYPE_PUMPKIN:
                _firstSpell = SPELL_PUMPKIN_AURA_GREEN;
                break;
            case INVIS_WISP_CREATURE_TYPE_FLAME:
                _timer.Reset(15 * IN_MILLISECONDS);
                _firstSpell = SPELL_BODY_FLAME;
                _secondSpell = SPELL_DEATH;
                break;
            case INVIS_WISP_CREATURE_TYPE_SMOKE:
                _timer.Reset(15 * IN_MILLISECONDS);
                _firstSpell = SPELL_SMOKE;
                break;
            case INVIS_WISP_CREATURE_TYPE_BLUE:
                _timer.Reset(7 * IN_MILLISECONDS);
                _secondSpell = SPELL_WISP_BLUE;
                break;
            default:
                break;
        }
        if (_firstSpell)
            DoCastSelf(_firstSpell);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_WISP_FLIGHT_PORT && _creatureType == 4)
            me->SetDisplayId(DISPLAYID_INVIS_WISP);
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
            me->RemoveAurasDueToSpell(SPELL_SMOKE);
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
        if (type != DATA_HEAD_TALK)
            return;

        DoTalk(value);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (_withBody)
            return;

        switch (_phase)
        {
            case PHASE_HEAD_1:
                if (me->HealthBelowPctDamaged(67, damage))
                    Disappear();
                break;
            case PHASE_HEAD_2:
                if (me->HealthBelowPctDamaged(34, damage))
                    Disappear();
                break;
            case PHASE_HEAD_3:
                if (!_die && damage >= me->GetHealth())
                {
                    _die = true;
                    damage = me->GetHealth() - me->CountPctFromMaxHealth(1);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->GetMotionMaster()->Clear();

                    DoCastSelf(SPELL_HEAD_IS_DEAD);

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

        if (spell->Id == SPELL_FLYING_HEAD)
        {
            if (_phase < PHASE_HEAD_3)
                ++_phase;
            else
                _phase = PHASE_HEAD_3;

            _withBody = false;

            if (!_bodyGUID)
                _bodyGUID = caster->GetGUID();

            me->RemoveAllAuras();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->GetMotionMaster()->Clear();

            DoCastSelf(SPELL_HEAD_LANDS, true);
            DoCastSelf(SPELL_HEAD);

            DoTalk(SAY_LOST_HEAD);

            _scheduler.Schedule(2s, [caster, this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MoveFleeing(caster->GetVictim());
            });
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_HEAD_DISAPPEAR:
                Disappear();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!_laughTimer.Passed())
            _laughTimer.Update(diff);

        if (!_withBody && _laughTimer.Passed())
        {
            _laughTimer.Reset(urand(15 * IN_MILLISECONDS, 30 * IN_MILLISECONDS));

            DoPlaySoundToSet(me, Trinity::Containers::SelectRandomContainerElement(HeadlessHorsemanRandomLaughSound));

            if (Creature* speaker = DoSpawnCreature(NPC_HELPER, 0.f, 0.f, 0.f, 0.f, TEMPSUMMON_TIMED_DESPAWN, 1 * IN_MILLISECONDS))
                speaker->CastSpell(speaker, SPELL_HEAD_SPEAKS, false);
        }
    }

private:
    void Disappear()
    {
        if (_withBody)
            return;

        if (_bodyGUID)
        {
            Creature* body = ObjectAccessor::GetCreature(*me, _bodyGUID);
            if (body && body->IsAlive())
            {
                _withBody = true;
                me->RemoveAllAuras();

                //-------------------------->>>>>>> body->RemoveAurasDueToSpell(SPELL_IMMUNE); // hack, SpellHit doesn't calls if body has immune aura

                DoCast(body, SPELL_FLYING_HEAD);
                me->SetFullHealth();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->GetMotionMaster()->MoveIdle();
                ENSURE_AI(boss_headless_horseman::boss_headless_horsemanAI, body->AI())->returned = true;
            }
        }
    }

    void DoTalk(uint32 entry)
    {
        Talk(entry);
        _laughTimer.Reset(3 * IN_MILLISECONDS);

        if (Creature* speaker = DoSpawnCreature(NPC_HELPER, 0.f, 0.f, 0.f, 0.f, TEMPSUMMON_TIMED_DESPAWN, 1 * IN_MILLISECONDS))
            speaker->CastSpell(speaker, SPELL_HEAD_SPEAKS, false);
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
    boss_headless_horseman(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
    {
        Initialize();
        _id = 0;
        _whirlwind = 0;
        _wpReached = false;
    }

    void Initialize()
    {
        _phase = 1;
        _count = 0;
        _sayTimer = 3000;
        _conflagrate = 15000;
        _summonAdds = 15000;
        _cleave = 2000;
        _regenerate = 1000;
        _laugh = urand(16000, 20000);
        _burn = 6000;
        _withHead = true;
        _returned = true;
        _isFlying = false;
        _burned = false;
    }

    void InitializeAI() override
    {
        me->SetImmuneToPC(false);
        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        Initialize();

        DoCastSelf(SPELL_HEAD);
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

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_HORSEMAN_EVENT_START:
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetDisableGravity(true);
                me->SetSpeedRate(MOVE_WALK, 5.0f);

                _wpReached = false;
                _count = 0;
                _sayTimer = 3000;
                _id = 0;
                _phase = 0;
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE || !_isFlying || id != _id)
            return;

        _wpReached = true;

        switch (id)
        {
            case POINT_HORSEMAN_0:
                me->SetVisible(true);
                break;
            case POINT_HORSEMAN_1:
                if (Creature* smoke = me->SummonCreature(NPC_HELPER, HeadlessHorsemanSpawnPoints[1], TEMPSUMMON_TIMED_DESPAWN, 20 * IN_MILLISECONDS))
                    smoke->AI()->SetData(DATA_INVIS_WISP_CREATURE_TYPE, INVIS_WISP_CREATURE_TYPE_SMOKE);
                DoCastSelf(SPELL_RHYME_BIG);
                break;
            case POINT_HORSEMAN_6:
                _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_PUMPKIN_SHRINE));
                break;
            case POINT_HORSEMAN_19:
                me->SetDisableGravity(false);
                break;
            case POINT_HORSEMAN_20:
                _phase = 1;
                _isFlying = false;
                _wpReached = false;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                DoTalk(SAY_ENTRANCE);
                if (Unit* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                    DoStartMovement(player);
                break;
            default:
                break;
        }
        ++_id;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _instance->SetBossState(DATA_HORSEMAN_EVENT, IN_PROGRESS);
        DoZoneInCombat();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (_withHead && _phase != 0)
            ScriptedAI::MoveInLineOfSight(who);
    }

    void KilledUnit(Unit* player) override
    {
        if (player->GetTypeId() == TYPEID_PLAYER)
        {
            if (_withHead)
                DoTalk(SAY_PLAYER_DEATH);
            else if (Creature* head = ObjectAccessor::GetCreature(*me, _headGUID))
                head->AI()->SetData(DATA_HEAD_TALK, SAY_PLAYER_DEATH);
        }
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
            flame->CastSpell(flame, SPELL_BODY_FLAME, false);
        if (Creature* wisp = DoSpawnCreature(NPC_WISP_INVIS, 0.f, 0.f, 0.f, 0.f, TEMPSUMMON_TIMED_DESPAWN, 60 * IN_MILLISECONDS))
            wisp->AI()->SetData(DATA_INVIS_WISP_CREATURE_TYPE, INVIS_WISP_CREATURE_TYPE_BLUE);

        _instance->SetBossState(DATA_HORSEMAN_EVENT, DONE);

        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        if (!players.isEmpty())
        {
            if (Group* group = players.begin()->GetSource()->GetGroup())
                if (group->isLFGGroup())
                    sLFGMgr->FinishDungeon(group->GetGUID(), 285, me->GetMap());
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
    {
        if (_withHead)
            return;

        if (spellInfo->Id == SPELL_FLYING_HEAD)
        {
            if (_phase < 3)
                ++_phase;
            else
                _phase = 3;

            _withHead = true;
            me->RemoveAllAuras();
            me->SetName("Headless Horseman"); //@todo THIS can't be serious
            me->SetFullHealth();
            DoTalk(SAY_REJOINED);
            DoCastSelf(SPELL_HEAD);
            caster->GetMotionMaster()->Clear();
            caster->GetMotionMaster()->MoveFollow(me, 6.f, 0.f);
        }
    }

    void DamageTaken(Unit* /*done_by*/, uint32& damage) override
    {
        if (damage >= me->GetHealth() && _withHead)
        {
            _withHead = false;
            _returned = false;
            damage = me->GetHealth() - me->CountPctFromMaxHealth(1);
            me->RemoveAllAuras();
            me->SetName("Headless Horseman, Unhorsed"); //@todo THIS can't be serious

            Creature* head;
            if (!_headGUID)
            {
                if (Creature* newHead = DoSpawnCreature(NPC_HEAD, frand(0.f, 5.f), frand(0.f, 5.f), 0, 0, TEMPSUMMON_DEAD_DESPAWN, 0))
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
                me->InterruptNonMeleeSpells(false);
                DoCastSelf(SPELL_IMMUNE, true);
                DoCastSelf(SPELL_BODY_REGEN, true);
                DoCast(head, SPELL_FLYING_HEAD, true);
                DoCastSelf(SPELL_CONFUSE, false); // test

                _whirlwind = urand(4000, 8000);
                _regenerate = 0;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (withhead)
        {
            switch (Phase)
            {
            case 0:
            {
                if (!IsFlying)
                {
                    if (say_timer <= diff)
                    {
                        say_timer = 3000;
                        Player* player = SelectRandomPlayer(100.0f, false);
                        if (count < 3)
                        {
                            if (player)
                                player->Say(Text[count], LANG_UNIVERSAL);
                        }
                        else
                        {
                            DoCast(me, SPELL_RHYME_BIG);
                            if (player)
                            {
                                player->Say(Text[count], LANG_UNIVERSAL);
                                player->HandleEmoteCommand(ANIM_EMOTE_SHOUT);
                            }
                            wp_reached = true;
                            IsFlying = true;
                            count = 0;
                            break;
                        }
                        ++count;
                    }
                    else say_timer -= diff;
                }
                else
                {
                    if (wp_reached)
                    {
                        wp_reached = false;
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(id, FlightPoint[id]);
                    }
                }
            }
            break;
            case 1:
                if (burned)
                    break;
                if (burn <= diff)
                {
                    if (Creature* flame = me->SummonCreature(HELPER, Spawn[0], TEMPSUMMON_TIMED_DESPAWN, 17000))
                        ENSURE_AI(npc_wisp_invis::npc_wisp_invisAI, flame->AI())->SetType(2);
                    burned = true;
                }
                else burn -= diff;
                break;
            case 2:
                if (conflagrate <= diff)
                {
                    if (Unit* player = SelectRandomPlayer(30.0f))
                        DoCast(player, SPELL_CONFLAGRATION, false);
                    conflagrate = urand(10000, 16000);
                }
                else conflagrate -= diff;
                break;
            case 3:
                if (summonadds <= diff)
                {
                    me->InterruptNonMeleeSpells(false);
                    DoCast(me, SPELL_SUMMON_PUMPKIN);
                    SaySound(SAY_SPROUTING_PUMPKINS);
                    summonadds = urand(25000, 35000);
                }
                else summonadds -= diff;
                break;
            }

            if (laugh <= diff)
            {
                laugh = urand(11000, 22000);
                DoPlaySoundToSet(me, RandomLaugh[rand32() % 3]);
            }
            else laugh -= diff;

            if (UpdateVictim())
            {
                DoMeleeAttackIfReady();
                if (cleave <= diff)
                {
                    DoCastVictim(SPELL_CLEAVE);
                    cleave = urand(2000, 6000);       //1 cleave per 2.0f-6.0fsec
                }
                else cleave -= diff;
            }
        }
        else
        {
            if (regen <= diff)
            {
                regen = 1000;                   //"body calls head"
                if (me->IsFullHealth() && !returned)
                {
                    if (Phase > 1)
                        --Phase;
                    else
                        Phase = 1;
                    Creature* Head = ObjectAccessor::GetCreature((*me), headGUID);
                    if (Head && Head->IsAlive())
                    {
                        ENSURE_AI(npc_head::npc_headAI, Head->AI())->Phase = Phase;
                        ENSURE_AI(npc_head::npc_headAI, Head->AI())->Disappear();
                    }
                    return;
                }
            }
            else regen -= diff;

            if (whirlwind <= diff)
            {
                whirlwind = urand(4000, 8000);
                if (urand(0, 1))
                {
                    me->RemoveAurasDueToSpell(SPELL_CONFUSE);
                    DoCast(me, SPELL_WHIRLWIND, true);
                    DoCast(me, SPELL_CONFUSE);
                }
                else
                    me->RemoveAurasDueToSpell(SPELL_WHIRLWIND);
            }
            else whirlwind -= diff;
        }
    }

private:

    void DoTalk(uint8 textEntry, Unit* target = nullptr)
    {
        Talk(textEntry, target);
        _laugh += 4000;
    }

    Player* SelectRandomPlayer(float range = 0.0f, bool checkLoS = true)
    {
        Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
        if (PlayerList.isEmpty())
            return nullptr;

        std::list<Player*> temp;
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if ((me->IsWithinLOSInMap(i->GetSource()) || !checkLoS) && me->GetVictim() != i->GetSource() &&
                me->IsWithinDistInMap(i->GetSource(), range) && i->GetSource()->IsAlive())
                temp.push_back(i->GetSource());

        if (!temp.empty())
        {
            std::list<Player*>::const_iterator j = temp.begin();
            advance(j, rand32() % temp.size());
            return (*j);
        }
        return nullptr;
    }

    InstanceScript* _instance;
    ObjectGuid _headGUID;
    ObjectGuid _playerGUID;
    uint32 _phase;
    uint32 _id;
    uint32 _count;
    uint32 _sayTimer;
    uint32 _conflagrate;
    uint32 _summonAdds;
    uint32 _cleave;
    uint32 _regenerate;
    uint32 _whirlwind;
    uint32 _laugh;
    uint32 _burn;
    bool _withHead;
    bool _returned;
    bool _isFlying;
    bool _wpReached;
    bool _burned;
};

class npc_pulsing_pumpkin : public CreatureScript
{
public:
    npc_pulsing_pumpkin() : CreatureScript("npc_pulsing_pumpkin") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScarletMonasteryAI<npc_pulsing_pumpkinAI>(creature);
    }

    struct npc_pulsing_pumpkinAI : public ScriptedAI
    {
        npc_pulsing_pumpkinAI(Creature* creature) : ScriptedAI(creature)
        {
            sprouted = false;
        }

        bool sprouted;
        ObjectGuid debuffGUID;

        void Reset() override
        {
            float x, y, z;
            me->GetPosition(x, y, z);   //this visual aura some under ground
            me->UpdatePosition(x, y, z + 0.35f, 0.0f);
            debuffGUID.Clear();
            Despawn();
            Creature* debuff = DoSpawnCreature(HELPER, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 14500);
            if (debuff)
            {
                debuff->SetDisplayId(me->GetDisplayId());
                debuff->CastSpell(debuff, SPELL_PUMPKIN_AURA_GREEN, false);
                ENSURE_AI(npc_wisp_invis::npc_wisp_invisAI, debuff->AI())->SetType(1);
                debuffGUID = debuff->GetGUID();
            }
            sprouted = false;
            DoCast(me, SPELL_PUMPKIN_AURA, true);
            DoCast(me, SPELL_SPROUTING);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_SPROUTING)
            {
                sprouted = true;
                me->RemoveAllAuras();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                DoCast(me, SPELL_SPROUT_BODY, true);
                me->UpdateEntry(PUMPKIN_FIEND);
                DoStartMovement(me->GetVictim());
            }
        }

        void Despawn()
        {
            if (!debuffGUID)
                return;

            Unit* debuff = ObjectAccessor::GetUnit(*me, debuffGUID);
            if (debuff)
            {
                debuff->SetVisible(false);
                debuffGUID.Clear();
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (!sprouted)
                Despawn();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !me->IsValidAttackTarget(who) || me->GetVictim())
                return;

            AddThreat(who, 0.0f);
            if (sprouted)
                DoStartMovement(who);
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (sprouted && UpdateVictim())
                DoMeleeAttackIfReady();
        }
    };
};

enum LooselyTurnedSoil
{
    QUEST_CALL_THE_HEADLESS_HORSEMAN = 11405
};

class go_loosely_turned_soil : public GameObjectScript
{
    public:
        go_loosely_turned_soil() : GameObjectScript("go_loosely_turned_soil") { }

        struct go_loosely_turned_soilAI : public GameObjectAI
        {
            go_loosely_turned_soilAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

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
                if (Creature* horseman = me->SummonCreature(HH_MOUNTED, FlightPoint[20], TEMPSUMMON_MANUAL_DESPAWN, 0))
                {
                    ENSURE_AI(boss_headless_horseman::boss_headless_horsemanAI, horseman->AI())->PlayerGUID = player->GetGUID();
                    ENSURE_AI(boss_headless_horseman::boss_headless_horsemanAI, horseman->AI())->FlyMode();
                }
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetScarletMonasteryAI<go_loosely_turned_soilAI>(go);
        }
};

void AddSC_boss_headless_horseman()
{
    new boss_headless_horseman();
    new npc_head();
    new npc_pulsing_pumpkin();
    new npc_wisp_invis();
    new go_loosely_turned_soil();
}
