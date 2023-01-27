/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2014-2018 RoG_WoW Source <http://wow.rog.snet>
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
#include "ObjectMgr.h"
#include "dragon_soul.h"
#include "SpellMgr.h"
#include "GameObject.h"
#include "SpellAuraEffects.h"

enum ScriptedTexts
{
    SAY_AGGRO       = 0,
    SAY_DEATH       = 1,
    SAY_GROUND1     = 6,
    SAY_GROUND2     = 7,
    SAY_CRYSTAL     = 9,
    SAY_KILL        = 10,
    SAY_KOHCROM     = 11,
};

enum Spells
{
    SPELL_BERSERK                           = 47008,
    SPELL_STOMP                             = 103414,
    SPELL_CRUSH_ARMOR                       = 103687,
    SPELL_RESONATING_CRYSTAL                = 103640,
    SPELL_RESONATING_CRYSTAL_SUMMON         = 103639,
    SPELL_RESONATING_CRYSTAL_DMG            = 103545,
    SPELL_RESONATING_CRYSTAL_AURA           = 103494,
    SPELL_TARGET_SELECTION                  = 103528,
    SPELL_DANGER                            = 103534,
    SPELL_WARNING                           = 103536,
    SPELL_SAFE                              = 103541,
    SPELL_FURIOUS                           = 103846,
    SPELL_SUMMON                            = 22951,
    SPELL_BLACK_BLOOD_OF_THE_EARTH_DUMMY    = 103180,
    SPELL_BLACK_BLOOD_OF_THE_EARTH          = 103851,
    SPELL_BLACK_BLOOD_OF_THE_EARTH_DMG      = 103785,

    SPELL_EARTHEN_VORTEX                    = 103821,
    SPELL_EARTHEN_VORTEX_SUMMON             = 104512,
    SPELL_EARTHEN_VORTEX_VEHICLE            = 109615,

    SPELL_SUMMON_KOHCROM                    = 109017,
    SPELL_MORCHOK_JUMP                      = 109070,

    SPELL_EARTHS_VENGEANCE                  = 103176,
    SPELL_EARTHS_VENGEANCE_MISSILE          = 103177,
    SPELL_EARTHS_VENGEANCE_DMG              = 103178,
};

enum Events
{
    EVENT_EARTHS_VENGEANCE      = 1,
    EVENT_BLACK_BLOOD           = 2,
    EVENT_RESONATING_CRYSTAL    = 3,
    EVENT_BERSERK               = 4,
    EVENT_EARTHEN_VORTEX        = 5,
    EVENT_CONTINUE              = 6,
    EVENT_STOMP                 = 7,
    EVENT_CRUSH_ARMOR           = 8,
    EVENT_EXPLODE               = 9,
    EVENT_CHECK_PLAYERS         = 10,
    EVENT_UPDATE_HEALTH         = 11,
    EVENT_TROWN_ROCK            = 12,
};

enum Adds
{
    NPC_EARTHEN_VORTEX           = 55723,
    NPC_RESONATING_CRYSTAL       = 55346,
};

enum Actions
{
    ACTION_KOHCROM_STOMP                = 1,
    ACTION_KOHCROM_RESONATING_CRYSTAL   = 2,
    ACTION_KOHCROM_EARTHEN_VORTEX       = 3,
};

enum MiscData
{
    DATA_GUID_1         = 1,
    DATA_GUID_2         = 2,
    DATA_KOHCROM_DONE   = 3,
};

enum Auras
{
    AURA_BLACK_BLOOD_OF_THE_EARTH = 103180
};

enum Achievement
{
    ACHI_HEROIC_MORCHOK = 6109,
};

class boss_morchok: public CreatureScript
{
    public:
        boss_morchok() : CreatureScript("boss_morchok") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_morchokAI(pCreature);
        }

        struct boss_morchokAI : public BossAI
        {
            boss_morchokAI(Creature* pCreature) : BossAI(pCreature, DATA_MORCHOK)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
            }

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptIdOrAdd(DSScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset() override
            {
                _Reset();

                me->SetObjectScale(1);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DANGER);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WARNING);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SAFE);
                instance->SetBossState(BOSS_MORCHOK, NOT_STARTED);
                instance->SetData(DATA_MORCHOK, NOT_STARTED);
                me->SetReactState(REACT_AGGRESSIVE);
                DespawnGameobjects(GO_INNER_WALL, 100.0f);
                me->LowerPlayerDamageReq(me->GetHealth());

                _stompguid1 = ObjectGuid::Empty;
                _stompguid2 = ObjectGuid::Empty;
                bEnrage = false;
                bKohcrom = false;
                bAchieve = true;
                CheckCristal = 2000;

            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_STOMP, urand(12000, 14000));
                events.ScheduleEvent(EVENT_EARTHEN_VORTEX, urand(56000, 60000));
                events.ScheduleEvent(EVENT_RESONATING_CRYSTAL, urand(19000, 20000));
                events.ScheduleEvent(EVENT_BERSERK, 7 * MINUTE * IN_MILLISECONDS);
                if (!IsHeroic())
                    events.ScheduleEvent(EVENT_CRUSH_ARMOR, urand(6000, 12000));

                _stompguid1 = ObjectGuid::Empty;
                _stompguid2 = ObjectGuid::Empty;
                bEnrage = false;
                bKohcrom = false;
                bAchieve = true;

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DANGER);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WARNING);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SAFE);

                DoZoneInCombat();
                instance->SetBossState(BOSS_MORCHOK, IN_PROGRESS);
                instance->SetData(DATA_MORCHOK, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);

                if (instance)
                {
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DANGER);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WARNING);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SAFE);
                    instance->SetBossState(BOSS_MORCHOK, DONE);
                    instance->SetData(DATA_MORCHOK, DONE);
                    instance->DoModifyPlayerCurrencies(395, 7500);
                    if (!IsHeroic())
                    {
                        instance->DoModifyPlayerCurrencies(614, 1);
                        instance->DoModifyPlayerCurrencies(615, 1);
                    }
                    else
                    {
                        instance->DoModifyPlayerCurrencies(614, 2);
                        instance->DoModifyPlayerCurrencies(615, 2);
                        instance->DoCompleteAchievement(ACHI_HEROIC_MORCHOK);
                    }
                    DespawnGameobjects(GO_INNER_WALL, 100.0f);
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                events.Reset();
                summons.DespawnAll();
                DespawnGameobjects(GO_INNER_WALL, 100.0f);
                me->GetMotionMaster()->MoveTargetedHome();
                me->SetObjectScale(1);
                instance->SetBossState(BOSS_MORCHOK, FAIL);
                instance->SetData(DATA_MORCHOK, FAIL);
                _Reset();
                _EnterEvadeMode();
                Reset();
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                if (type == DATA_GUID_1)
                    _stompguid1 = guid;
                else if (type == DATA_GUID_2)
                    _stompguid2 = guid;
            }

            ObjectGuid GetGUID(int32 type) const override
            {
                if (type == DATA_GUID_1)
                    return _stompguid1;
                else if (type == DATA_GUID_2)
                    return _stompguid2;

                return ObjectGuid::Empty;
            }

            void JustSummoned(Creature* summon) override
            {
                BossAI::JustSummoned(summon);
                if (summon->GetEntry() == NPC_KOHCROM)
                {
                    summon->SetMaxHealth(me->GetMaxHealth());
                    summon->SetHealth(me->GetHealth());
                    summon->setActive(true);
                    summon->SetFaction(14);
                    summon->AI()->AttackStart(me->GetVictim());
                    DoZoneInCombat(summon);
                }
            }
            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            bool AllowAchieve()
            {
                return bAchieve;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_KOHCROM_DONE)
                    return uint32(bKohcrom);

                return 0;
            }

            void DespawnGameobjects(uint32 entry, float distance)
            {
                std::list<GameObject*> gameobjects;
                GetGameObjectListWithEntryInGrid(gameobjects, me, entry, distance);

                if (gameobjects.empty())
                    return;

                for (std::list<GameObject*>::iterator iter = gameobjects.begin(); iter != gameobjects.end(); ++iter)
                    (*iter)->RemoveFromWorld();
            }


            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (me->HealthBelowPct(95) && me->HealthAbovePct(91))
                    me->SetObjectScale(0.95f);
                if (me->HealthBelowPct(90) && me->HealthAbovePct(86))
                    me->SetObjectScale(0.90f);
                if (me->HealthBelowPct(85) && me->HealthAbovePct(81))
                    me->SetObjectScale(0.85f);
                if (me->HealthBelowPct(80) && me->HealthAbovePct(76))
                    me->SetObjectScale(0.80f);
                if (me->HealthBelowPct(75) && me->HealthAbovePct(71))
                    me->SetObjectScale(0.75f);
                if (me->HealthBelowPct(70) && me->HealthAbovePct(66))
                    me->SetObjectScale(0.70f);
                if (me->HealthBelowPct(65) && me->HealthAbovePct(61))
                    me->SetObjectScale(0.65f);
                if (me->HealthBelowPct(60) && me->HealthAbovePct(56))
                    me->SetObjectScale(0.60f);
                if (me->HealthBelowPct(55) && me->HealthAbovePct(51))
                    me->SetObjectScale(0.55f);
                if (me->HealthBelowPct(50) && me->HealthAbovePct(46))
                    me->SetObjectScale(0.50f);
                if (IsHeroic())
                {
                    if (Creature* ppKohcrom = me->FindNearestCreature(NPC_KOHCROM, 500.0f))
                    {
                        if (me->HealthBelowPct(95) && me->HealthAbovePct(91))
                            ppKohcrom->SetObjectScale(0.95f);
                        if (me->HealthBelowPct(90) && me->HealthAbovePct(86))
                            ppKohcrom->SetObjectScale(0.90f);
                        if (me->HealthBelowPct(85) && me->HealthAbovePct(81))
                            ppKohcrom->SetObjectScale(0.85f);
                        if (me->HealthBelowPct(80) && me->HealthAbovePct(76))
                            ppKohcrom->SetObjectScale(0.80f);
                        if (me->HealthBelowPct(75) && me->HealthAbovePct(71))
                            ppKohcrom->SetObjectScale(0.75f);
                        if (me->HealthBelowPct(70) && me->HealthAbovePct(66))
                            ppKohcrom->SetObjectScale(0.70f);
                        if (me->HealthBelowPct(65) && me->HealthAbovePct(61))
                            ppKohcrom->SetObjectScale(0.65f);
                        if (me->HealthBelowPct(60) && me->HealthAbovePct(56))
                            ppKohcrom->SetObjectScale(0.60f);
                        if (me->HealthBelowPct(55) && me->HealthAbovePct(51))
                            ppKohcrom->SetObjectScale(0.55f);
                        if (me->HealthBelowPct(50) && me->HealthAbovePct(46))
                            ppKohcrom->SetObjectScale(0.50f);
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                        return;

                if (me->GetDistance(me->GetHomePosition()) > 500.0f)
                {
                    EnterEvadeMode(EVADE_REASON_BOUNDARY);
                    return;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (IsHeroic() && me->HealthBelowPct(90) && !bKohcrom)
                {
                    events.Reset();
                    bKohcrom = true;
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();

                    Talk(SAY_KOHCROM);

                    DoCast(me, SPELL_MORCHOK_JUMP);
                    DoCast(me, SPELL_SUMMON_KOHCROM, true);

                    events.ScheduleEvent(EVENT_EARTHEN_VORTEX, urand(56000, 60000));
                    events.ScheduleEvent(EVENT_CONTINUE, 5000);
                    events.ScheduleEvent(EVENT_UPDATE_HEALTH, 8000);
                    return;
                }

                if (me->HealthBelowPct(20) && !bEnrage)
                {
                    bEnrage = true;
                    DoCast(me, SPELL_FURIOUS);
                    return;
                }

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPDATE_HEALTH:
                            if (me->IsAlive())
                            {
                                if (Creature* pKohcrom = instance->GetCreature(DATA_KOHCROM))
                                {
                                    if (!pKohcrom->IsAlive())
                                        break;

                                    if (me->GetHealth() < 500000 || pKohcrom->GetHealth() < 500000)
                                        break;

                                    uint64 new_health = (me->GetHealth() + pKohcrom->GetHealth()) / 2;
                                    new_health = std::min(new_health, me->GetMaxHealth());
                                    me->SetHealth(new_health);
                                    pKohcrom->SetHealth(new_health);
                                }
                                events.ScheduleEvent(EVENT_UPDATE_HEALTH, 3000);
                            }

                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        case EVENT_CRUSH_ARMOR:
                            DoCastVictim(SPELL_CRUSH_ARMOR);
                            events.ScheduleEvent(EVENT_CRUSH_ARMOR, urand(12000, 15000));
                            break;
                        case EVENT_STOMP:
                        {
                            _stompguid1 = ObjectGuid::Empty;
                            _stompguid2 = ObjectGuid::Empty;

                            int32 tim = int32(events.GetNextEventTime(EVENT_EARTHEN_VORTEX)) - int32(events.GetTimer());
                            if (tim <= 7000)
                                break;

                            DoCast(me, SPELL_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, urand(12000, 14000));
                            if (bKohcrom)
                            {
                                if (Creature* pKohcrom = instance->GetCreature(DATA_KOHCROM))
                                    pKohcrom->AI()->DoAction(ACTION_KOHCROM_STOMP);
                            }
                            break;
                        }
                        case EVENT_RESONATING_CRYSTAL:
                        {
                            int32 tim = int32(events.GetNextEventTime(EVENT_EARTHEN_VORTEX)) - int32(events.GetTimer());
                            if (tim <= 17000)
                                break;

                            Talk(SAY_CRYSTAL);
                            Position pos;
                            pos = me->GetNearPosition(frand(25.0f, 45.0f), frand(0.0f, float(2 * M_PI)));
                            me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_RESONATING_CRYSTAL, true);
                            events.ScheduleEvent(EVENT_RESONATING_CRYSTAL, urand(20000, 25000));
                            if (bKohcrom)
                            {
                                if (Creature* pKohcrom = instance->GetCreature(DATA_KOHCROM))
                                    pKohcrom->AI()->DoAction(ACTION_KOHCROM_RESONATING_CRYSTAL);
                            }
                            break;
                        }
                        case EVENT_EARTHEN_VORTEX:
                            Talk(SAY_GROUND1);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();

                            events.CancelEvent(EVENT_RESONATING_CRYSTAL);
                            events.CancelEvent(EVENT_STOMP);
                            events.CancelEvent(EVENT_CRUSH_ARMOR);
                            DoCastAOE(SPELL_SUMMON);
                            DoCastAOE(SPELL_EARTHEN_VORTEX, true);
                            DoCast(me, SPELL_EARTHS_VENGEANCE);
                            if (bKohcrom)
                                if (Creature* pKohcrom = instance->GetCreature(DATA_KOHCROM))
                                    pKohcrom->AI()->DoAction(ACTION_KOHCROM_EARTHEN_VORTEX);

                            events.ScheduleEvent(EVENT_BLACK_BLOOD, 5000);
                            events.ScheduleEvent(EVENT_EARTHEN_VORTEX, urand(94000, 97000));
                            break;
                        case EVENT_BLACK_BLOOD:
                            Talk(SAY_GROUND2);
                            if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->GetSource()->IsAlive())
                            if (me->GetExactDist(i->GetSource()) < 50.0f)
                                i->GetSource()->TeleportTo(967, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.0f);
                            DoCast(me, SPELL_BLACK_BLOOD_OF_THE_EARTH);
                            events.ScheduleEvent(EVENT_CONTINUE, 18000);
                            break;
                        case EVENT_CONTINUE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            AttackStart(me->GetVictim());
                            events.ScheduleEvent(EVENT_STOMP, 18000);
                            events.ScheduleEvent(EVENT_RESONATING_CRYSTAL, 25000);
                            if (!IsHeroic())
                                events.ScheduleEvent(EVENT_CRUSH_ARMOR, urand(6000, 12000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            uint32 CheckCristal;
            ObjectGuid _stompguid1;
            ObjectGuid _stompguid2;
            bool bEnrage;
            bool bKohcrom;
            bool bAchieve;

            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
        };
};

class npc_morchok_kohcrom: public CreatureScript
{
    public:
        npc_morchok_kohcrom() : CreatureScript("npc_morchok_kohcrom") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_morchok_kohcromAI(pCreature);
        }

        struct npc_morchok_kohcromAI : public ScriptedAI
        {
            npc_morchok_kohcromAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                pInstance = me->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();

                _stompguid1 = ObjectGuid::Empty;
                _stompguid2 = ObjectGuid::Empty;
                bEnrage = false;
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                if (type == DATA_GUID_1)
                    _stompguid1 = guid;
                else if (type == DATA_GUID_2)
                    _stompguid2 = guid;
            }

            ObjectGuid GetGUID(int32 type) const override
            {
                if (type == DATA_GUID_1)
                    return _stompguid1;
                else if (type == DATA_GUID_2)
                    return _stompguid2;

                return ObjectGuid::Empty;
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                DoCast(me, SPELL_MORCHOK_JUMP, true);
                events.ScheduleEvent(EVENT_CONTINUE, 5000);
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_KOHCROM_STOMP:
                        events.ScheduleEvent(EVENT_STOMP, urand(4000, 6000));
                        break;
                    case ACTION_KOHCROM_RESONATING_CRYSTAL:
                        events.ScheduleEvent(EVENT_RESONATING_CRYSTAL, urand(4000, 6000));
                        break;
                    case ACTION_KOHCROM_EARTHEN_VORTEX:
                        events.ScheduleEvent(EVENT_EARTHEN_VORTEX, 1);
                        break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (me->HealthBelowPct(20) && !bEnrage)
                {
                    bEnrage = true;
                    DoCast(me, SPELL_FURIOUS);
                    return;
                }

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STOMP:
                            _stompguid1 = ObjectGuid::Empty;
                            _stompguid2 = ObjectGuid::Empty;
                            DoCast(me, SPELL_STOMP);
                            break;
                        case EVENT_RESONATING_CRYSTAL:
                        {
                            Position pos;
                            pos = me->GetNearPosition(frand(25.0f, 45.0f), frand(0.0f, float(2 * M_PI)));
                            me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_RESONATING_CRYSTAL, true);
                            break;
                        }
                        case EVENT_EARTHEN_VORTEX:
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            DoCastAOE(SPELL_EARTHEN_VORTEX, true);
                            DoCast(me, SPELL_EARTHS_VENGEANCE);
                            events.ScheduleEvent(EVENT_BLACK_BLOOD, 5000);
                            break;
                        case EVENT_BLACK_BLOOD:
                            if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->GetSource()->IsAlive())
                            if (me->GetExactDist(i->GetSource()) < 50.0f)
                                i->GetSource()->TeleportTo(967, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.0f);
                            DoCast(me, SPELL_BLACK_BLOOD_OF_THE_EARTH);
                            events.ScheduleEvent(EVENT_CONTINUE, 18000);
                            break;
                        case EVENT_CONTINUE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            AttackStart(me->GetVictim());
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:

            EventMap events;
            SummonList summons;
            InstanceScript* pInstance;
            ObjectGuid _stompguid1;
            ObjectGuid _stompguid2;
            bool bEnrage;
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
        };
};

class npc_morchok_resonating_crystal : public CreatureScript
{
    public:
        npc_morchok_resonating_crystal() : CreatureScript("npc_morchok_resonating_crystal") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_morchok_resonating_crystalAI(pCreature);
        }

        struct npc_morchok_resonating_crystalAI : public Scripted_NoMovementAI
        {
            npc_morchok_resonating_crystalAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
            }

            EventMap events;

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.ScheduleEvent(EVENT_EXPLODE, 10000);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_EXPLODE)
                    {
                        me->RemoveAura(SPELL_RESONATING_CRYSTAL);
                        DoCastAOE(SPELL_RESONATING_CRYSTAL_DMG);
                        Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                Player *player = i->GetSource();
                                if (player->HasAura(SPELL_DANGER) || player->HasAura(SPELL_WARNING) || player->HasAura(SPELL_SAFE))
                                {
                                    player->RemoveAura(SPELL_DANGER);
                                    player->RemoveAura(SPELL_WARNING);
                                    player->RemoveAura(SPELL_SAFE);
                                }
                            }
                        }
                        me->DespawnOrUnsummon(500);
                    }
                }
            }
        };
};


class spell_morchok_target_selected : public SpellScriptLoader
{
    public:
        spell_morchok_target_selected() : SpellScriptLoader("spell_morchok_target_selected") { }

        class spell_morchok_target_selected_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_morchok_target_selected_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                uint32 max_size = (GetCaster()->GetMap()->Is25ManRaid() ? 7 : 3);

                if (targets.size() > max_size)
                {
                    targets.sort(DistanceOrderPred(GetCaster()));
                }

                max_size = std::min((uint32)targets.size(), max_size);

                uint32 count = 0;
                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    temp_targets.push_back((*itr));
                    count++;
                    if (count >= max_size)
                        break;
                }
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                bool bFound = false;
                for (std::vector<WorldObject*>::const_iterator itr = temp_targets.begin(); itr != temp_targets.end(); ++itr)
                    if ((*itr)->GetGUID() == GetHitUnit()->GetGUID())
                    {
                        bFound = true;
                        break;
                    }

                if (!bFound)
                {
                    GetHitUnit()->RemoveAura(SPELL_DANGER);
                    GetHitUnit()->RemoveAura(SPELL_WARNING);
                    GetHitUnit()->RemoveAura(SPELL_SAFE);
                }
                else
                {
                    float dist = GetCaster()->GetDistance(GetHitUnit());
                    if (dist > 30.0f)
                        GetCaster()->CastSpell(GetHitUnit(), SPELL_DANGER, true);
                    else if (dist > 15.0f)
                        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARNING, true);
                    else
                        GetCaster()->CastSpell(GetHitUnit(), SPELL_SAFE, true);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morchok_target_selected_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_morchok_target_selected_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_DUMMY);
            }

        private:

            std::vector<WorldObject*> temp_targets;

            class DistanceOrderPred
            {
                public:
                    DistanceOrderPred(WorldObject* searcher) : _searcher(searcher) { }
                    bool operator() (WorldObject* a, WorldObject* b) const
                    {
                        float rA = _searcher->GetDistance(a);
                        float rB = _searcher->GetDistance(b);
                        return rA < rB;
                    }
                private:
                    WorldObject* _searcher;
            };
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_morchok_target_selected_SpellScript();
        }

};

class spell_morchok_resonating_crystal_dmg : public SpellScriptLoader
{

    public:
        spell_morchok_resonating_crystal_dmg() : SpellScriptLoader("spell_morchok_resonating_crystal_dmg") { }

        class spell_morchok_resonating_crystal_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_morchok_resonating_crystal_dmg_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(AurasCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morchok_resonating_crystal_dmg_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morchok_resonating_crystal_dmg_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morchok_resonating_crystal_dmg_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
            }

        private:

            class AurasCheck
            {
                public:
                    AurasCheck() {}

                    bool operator()(WorldObject* unit)
                    {
                        return (!unit->ToUnit() || !(unit->ToUnit()->HasAura(SPELL_DANGER) || unit->ToUnit()->HasAura(SPELL_WARNING) || unit->ToUnit()->HasAura(SPELL_SAFE)));
                    }
            };
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_morchok_resonating_crystal_dmg_SpellScript();
        }
};

class spell_morchok_black_blood_of_the_earth : public SpellScriptLoader
{
    public:
        spell_morchok_black_blood_of_the_earth() : SpellScriptLoader("spell_morchok_black_blood_of_the_earth") { }

        class spell_morchok_black_blood_of_the_earth_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_morchok_black_blood_of_the_earth_AuraScript);

            void HandlePeriodicTick(AuraEffect const* aurEff)
            {
                uint32 ticks = aurEff->GetTickNumber();

                for (uint32 j = 0; j < ticks; ++j)
                {
                    Position pos;
                    for (float i = 0.0f; i < 2 * M_PI; i += float (0.3f))
                    {
                        pos = GetCaster()->GetNearPosition(ticks * 3 , i);
                        GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_BLACK_BLOOD_OF_THE_EARTH_DUMMY, true);
                        if (j == 4)
                        {
                            pos = GetCaster()->GetNearPosition((ticks - 4) * 3, i);
                            GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_BLACK_BLOOD_OF_THE_EARTH_DUMMY, true);
                        }
                        if (j == 8)
                        {
                            pos = GetCaster()->GetNearPosition((ticks - 8) * 3, i);
                            GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_BLACK_BLOOD_OF_THE_EARTH_DUMMY, true);
                        }
                    }

                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_morchok_black_blood_of_the_earth_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_morchok_black_blood_of_the_earth_AuraScript();
        }
};

class spell_morchok_black_blood_of_the_earth_dmg : public SpellScriptLoader
{

    public:
        spell_morchok_black_blood_of_the_earth_dmg() : SpellScriptLoader("spell_morchok_black_blood_of_the_earth_dmg") { }

        class spell_morchok_black_blood_of_the_earth_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_morchok_black_blood_of_the_earth_dmg_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_BLACK_BLOOD_OF_THE_EARTH, EFFECT_0))
                {
                    uint32 ticks = aurEff->GetTickNumber() + 1;
                    targets.remove_if(DistanceCheck(GetCaster(), float(ticks * 4)));
                }

                std::list<GameObject*> goList;
                GetCaster()->GetGameObjectListWithEntryInGrid(goList, GO_INNER_WALL, 100.0f);
                if (!goList.empty())
                    for (std::list<GameObject*>::const_iterator itr = goList.begin(); itr != goList.end(); ++itr)
                        targets.remove_if(WallCheck(GetCaster(), (*itr)));

            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morchok_black_blood_of_the_earth_dmg_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morchok_black_blood_of_the_earth_dmg_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            }

        private:
            class DistanceCheck
            {
                public:
                    DistanceCheck(Unit* searcher, float distance) : _searcher(searcher), _distance(distance) {}

                    bool operator()(WorldObject* unit)
                    {
                        return (_searcher->GetDistance2d(unit) > _distance);
                    }

                private:
                    Unit* _searcher;
                    float _distance;
            };

            class WallCheck
            {
                public:
                    WallCheck(Unit* searcher, GameObject* go) : _searcher(searcher), _go(go) {}

                    bool operator()(WorldObject* unit)
                    {
                        return (_go->IsInBetween(_searcher, unit, 3.0f));
                    }

                private:
                    Unit* _searcher;
                    GameObject* _go;
            };
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_morchok_black_blood_of_the_earth_dmg_SpellScript();
        }
};

class spell_morchok_stomp : public SpellScriptLoader
{
    public:
        spell_morchok_stomp() : SpellScriptLoader("spell_morchok_stomp") { }

        class spell_morchok_stomp_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_morchok_stomp_SpellScript);

            bool Load() override
            {
                _targetCount = 0;

                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                if (Creature* pMorchok = GetCaster()->ToCreature())
                {
                    targets.sort(DistanceOrderPred(GetCaster()));
                    std::list<WorldObject*>::const_iterator itr = targets.begin();
                    pMorchok->AI()->SetGUID((*itr)->GetGUID(), DATA_GUID_1);
                    _targetCount = targets.size();
                    if (targets.size() > 1)
                    {
                        ++itr;
                        pMorchok->AI()->SetGUID((*itr)->GetGUID(), DATA_GUID_2);
                    }
                }
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                PreventHitDamage();

                if (!GetCaster())
                    return;

                if (!GetHitUnit()->IsAlive() || !_targetCount)
                    return;

                /*if (Creature* creature = GetCaster()->ToCreature())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_STOMP))
                        {
                            uint32 damage = (uint32(GetEffectValue() / _targetCount));
                            SpellNonMeleeDamage damageInfo(creature, target, SPELL_STOMP, spellInfo->SchoolMask);
                            damageInfo.damage = damage;
                            creature->SendSpellNonMeleeDamageLog(&damageInfo);
                            creature->DealSpellDamage(&damageInfo, false);
                            SetHitDamage(damage);
                        }
                    }
                }*/
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morchok_stomp_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_morchok_stomp_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }

        private:
            uint32 _targetCount;

            class DistanceOrderPred
            {
                public:
                    DistanceOrderPred(WorldObject* searcher) : _searcher(searcher) { }
                    bool operator() (WorldObject* a, WorldObject* b) const
                    {
                        float rA = _searcher->GetExactDist(a);
                        float rB = _searcher->GetExactDist(b);
                        return rA < rB;
                    }

                private:
                    WorldObject* _searcher;
            };
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_morchok_stomp_SpellScript();
        }
};

typedef boss_morchok::boss_morchokAI MorchokAI;

class achievement_dont_stay_so_close_to_me : public AchievementCriteriaScript
{
    public:
        achievement_dont_stay_so_close_to_me() : AchievementCriteriaScript("achievement_dont_stay_so_close_to_me") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (MorchokAI* morchokAI = CAST_AI(MorchokAI, target->GetAI()))
                return morchokAI->AllowAchieve();

            return false;
        }
};

void AddSC_boss_morchok()
{
    new boss_morchok();
    new npc_morchok_kohcrom();
    new npc_morchok_resonating_crystal();
    new spell_morchok_target_selected();
    new spell_morchok_resonating_crystal_dmg();
    new spell_morchok_black_blood_of_the_earth();
    new spell_morchok_black_blood_of_the_earth_dmg();
    new spell_morchok_stomp();
    new achievement_dont_stay_so_close_to_me();
}
