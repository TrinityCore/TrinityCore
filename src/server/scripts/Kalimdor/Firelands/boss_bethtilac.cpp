/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "firelands.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"

enum Spells
{
    SPELL_EMBER_FLARE_1             = 98934, // 1 phase
    SPELL_EMBER_FLARE_2             = 99859, // 2 phase
    SPELL_METEOR_BURN_DUMMY         = 98534,
    SPELL_VENOM_RAIN                = 99333,
    SPELL_SPIDERWEB_FILAMENT_UP     = 97196,
    SPELL_SPIDERWEB_FILAMENT_DOWN   = 98149,
    SPELL_SPIDERWEB_FILAMENT_PET    = 97182,
    SPELL_SPIDERWEB_FILAMENT_SUMMON = 98148,
    SPELL_SPIDERWEB_FILAMENT_ANY    = 98623,
    SPELL_CREEPER                   = 98858,
    SPELL_TEMPERAMENT               = 98958,
    SPELL_SMOLDERING_DEVASTATION    = 99052,
    SPELL_BURNING_ACID              = 98471,
    SPELL_FIERY_WEB_SPIN            = 97202,
    SPELL_BOILING_SPATTER           = 99463,
    SPELL_FIXATE                    = 99526,
    SPELL_FIXATE_SELF               = 99599,
    SPELL_FIXATE_BROODLING          = 99999,
    SPELL_LEECH_VENOM               = 99411,
    SPELL_VOLATILE_BURST            = 99990,
    SPELL_THE_WIDOW_KISS            = 99476,
    SPELL_FRENZY                    = 99497,
    SPELL_ZERO_POWER                = 96301,
    SPELL_CONSUME_DRONE             = 99304,
    SPELL_ENERGIZE                  = 99211, // Drone
    SPELL_VOLATILE_POISON           = 99276,
};

enum Adds
{
    NPC_WEB_RIP                 = 53450, // 99071
    NPC_WEB_RIP_1               = 53474, // 99591
    NPC_CINDERWEB_SPINNER       = 52524, // 98858, 98958
    NPC_CINDERWEB_DRONE         = 52581, // 99211
    NPC_CINDERWEB_SPIDERLING    = 52447,
    NPC_ENGORGED_BROODLING      = 53745, // 99982
    NPC_SPIDERWEB_FILAMENT      = 53082, // 98149
    NPC_CRACKLING_FLAME         = 53433, // 98570
    NPC_SPIDERLING_STALKER      = 53178,
    NPC_STICKY_WEBBING          = 53492,
    NPC_STICKY_WEBBING_1        = 53490, // 99219
};

enum Events
{
    EVENT_CHECK_HIGH            = 1,
    EVENT_EMBER_FLARE           = 2,
    EVENT_FILAMENT              = 3,
    EVENT_ENERGY                = 4,
    EVENT_BURNING_ACID          = 5,
    EVENT_FIERY_WEB_SPIN        = 6,
    EVENT_THE_WIDOW_KISS        = 7,
    EVENT_FRENZY                = 8,
    EVENT_GO_DOWN               = 9,
    EVENT_ENERGY_2              = 10,
    EVENT_BOILING_SPATTER       = 11,
    EVENT_SUMMON_DRONE          = 12,
    EVENT_SUMMON_SPIDERLING     = 13,
    EVENT_SUMMON_BROODLING_1    = 14,
    EVENT_SUMMON_SPIDERLING_1   = 15,
    EVENT_CHECK_DRONE           = 16,
    EVENT_CHECK_SPIDERLING      = 17,
    EVENT_CHECK_TARGET          = 18,
    EVENT_FIXATE                = 19,
    EVENT_FIXATE_OFF            = 20,
};

enum Other
{
    POINT_HIGH  = 1,
    DATA_PHASE  = 2, // don't change that! Related with TargetedMovementGenerator
    POINT_DOWN  = 3,
};

enum ePhases
{
    PHASE_HIGH = 0,
    PHASE_LOW  = 1
};

#define LEVEL_HEIGHT 100.0f
#define GROUND_HEIGHT 74.05f

const Position highPos = {58.05f, 379.35f, 111.0f, 3.91f};
const Position addsPos[9] =
{
    {24.691f, 298.297f, 81.54f, 0.0f}, // spiderling
    {134.570f, 360.037f, 85.420f, 0.0f}, // spiderling
    {86.338f, 442.826f, 76.72f, 0.0f}, // spiderling
    {11.773f, 479.865f, 78.51f, 0.0f}, // Drone
    {48.428f, 376.85f, 106.8785f, 0.0f}, // Spiderweb Filament
    {41.594f, 378.043f, 74.05f, 0.0f}, // center of the room
    {55.301f, 375.729f, 111.0f, 0.94f},
    {75.372f, 374.039f, 111.0f, 2.18f},
    {59.665f, 406.437f, 111.0f, 5.02f}
};

struct PositionSelector : public std::unary_function<Unit*, bool>
{
    public:

        PositionSelector(bool b, uint32 spellId) : _b(b), _spellId(spellId) {}

        bool operator()(Unit const* target) const
        {
            if (_spellId && target->HasAura(_spellId))
                return false;

            return _b? (target->GetPositionZ() < 100.0f): (target->GetPositionZ() > 100.0f);
        }

    private:
        bool _b;
        uint32 _spellId;

};

class boss_bethtilac : public CreatureScript
{
    public:
        boss_bethtilac() : CreatureScript("boss_bethtilac") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_bethtilacAI(pCreature);
        }

        struct boss_bethtilacAI : public BossAI
        {
            boss_bethtilacAI(Creature* pCreature) : BossAI(pCreature, DATA_BETHTILAC)
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

            uint8 uiPhase;
            uint8 uiCount;
            uint8 uiSide;

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptIdOrAdd(FLScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            bool AllowAchieve()
            {
                return false;
            }

            void Reset() override
            {
                DoCast(me, SPELL_ZERO_POWER, true);
                me->SetReactState(REACT_PASSIVE);
                //me->SetUInt32Value(UNIT_FIELD_ANIM_TIER, 50331648);
                //me->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
                uiPhase = PHASE_HIGH;
                uiCount = 0;
                uiSide = 0;
                me->SetMaxPower(POWER_MANA, 9000);
                me->SetPower(POWER_MANA, 9000);
                _Reset();
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                me->SetCanFly(true);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                if (!_EnterEvadeMode())
                    return;

                Position home = me->GetHomePosition();
                me->GetMotionMaster()->MoveJump(home, 40.0f, 40.0f);
                Reset();
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                uiPhase = PHASE_HIGH;
                uiCount = 0;
                uiSide = 0;
                me->RemoveAurasByType(SPELL_AURA_MOD_TAUNT);
                instance->SetBossState(DATA_BETHTILAC, IN_PROGRESS);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->GetMotionMaster()->MovePoint(POINT_HIGH, highPos);
                DoZoneInCombat();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE)
                {
                    if (id == POINT_HIGH)
                    {
                        me->RemoveAurasByType(SPELL_AURA_MOD_TAUNT);
                        //me->SetUInt32Value(UNIT_FIELD_ANIM_TIER, 0);
                        //me->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_CHECK_HIGH, 5000);
                        events.ScheduleEvent(EVENT_FILAMENT, 6000);
                        events.ScheduleEvent(EVENT_SUMMON_DRONE, 60000);
                        events.ScheduleEvent(EVENT_SUMMON_SPIDERLING, 30000);
                        events.ScheduleEvent(EVENT_EMBER_FLARE, urand(7000, 8000));
                        events.ScheduleEvent(EVENT_ENERGY, 1000);
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                    }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_PHASE)
                    return uiPhase;

                return 0;
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void CheckVictim()
            {
               UpdateVictim();

               Unit* victim = me->GetVictim();
                if (!victim)
                    return;

                if (uiPhase == PHASE_HIGH)
                {
                    if (victim->GetPositionZ() < 100.0f)
                        DoModifyThreatPercent(victim, -100);
                }
                else
                {
                    if (victim->GetPositionZ() > 100.0f)
                        DoModifyThreatPercent(victim, -100);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_HIGH:
                        {
                            if (me->GetVictim())
                                if (me->GetVictim()->GetPositionZ() >= 100.0f)
                                    break;

                            std::list<Player*> PlayerList;
                            me->GetPlayerListInGrid(PlayerList, 300.0f);
                            if (PlayerList.size() == 0)
                                DoCastAOE(SPELL_VENOM_RAIN);
                            events.ScheduleEvent(EVENT_CHECK_HIGH, 5000);
                            break;
                        }
                        case EVENT_EMBER_FLARE:
                            if (uiPhase == PHASE_HIGH)
                            {
                                std::list<Player*> PlayerList;
                                me->GetPlayerListInGrid(PlayerList, 300.0f);
                                if (PlayerList.size() > 0)
                                    DoCastAOE(SPELL_EMBER_FLARE_1);
                            }
                            else
                            {
                                DoCastAOE(SPELL_EMBER_FLARE_2);
                            }

                            events.ScheduleEvent(EVENT_EMBER_FLARE, urand(6000, 7000));
                            break;
                        case EVENT_FILAMENT:
                            for (uint8 i = 0; i < RAID_MODE(2, 4, 2, 4); i++)
                                if (Creature* pFilament = me->SummonCreature(NPC_SPIDERWEB_FILAMENT, addsPos[4].GetPositionX() + irand(-8, 8), addsPos[4].GetPositionY() + irand(-8, 8), addsPos[4].GetPositionZ(), 0.0f))
                                    pFilament->SetCanFly(true);
                            events.ScheduleEvent(EVENT_FILAMENT, urand(20000, 25000));
                            break;
                        case EVENT_SUMMON_DRONE:
                            if (Creature* pDrone = me->SummonCreature(NPC_CINDERWEB_DRONE, addsPos[3]))
                                //pDrone->GetMotionMaster()->MovePoint(0, addsPos[5]);
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, PositionSelector(true, 0)))
                                    pDrone->GetMotionMaster()->MoveChase(pTarget);
                            events.ScheduleEvent(EVENT_SUMMON_DRONE, 60000);
                            break;
                        case EVENT_SUMMON_SPIDERLING:
                            uiSide = urand(0, 2);
                            for (uint8 i = 0; i < 8; i++)
                                events.ScheduleEvent(EVENT_SUMMON_SPIDERLING_1, i * 500);
                            if (IsHeroic())
                                for (uint8 i = 0; i < RAID_MODE(1, 2, 1, 2); ++i)
                                    events.ScheduleEvent(EVENT_SUMMON_BROODLING_1, i * 1000);
                            events.ScheduleEvent(EVENT_SUMMON_SPIDERLING, 30000);
                            break;
                        case EVENT_SUMMON_SPIDERLING_1:
                            if (Creature* pSpiderling = me->SummonCreature(NPC_CINDERWEB_SPIDERLING, addsPos[uiSide]))
                                pSpiderling->GetMotionMaster()->MovePoint(0, addsPos[5]);
                            break;
                        case EVENT_SUMMON_BROODLING_1:
                            if (Creature* pBroodling = me->SummonCreature(NPC_ENGORGED_BROODLING, addsPos[uiSide]))
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, PositionSelector(true, 0)))
                                {
                                    pBroodling->CastSpell(pTarget, SPELL_FIXATE_BROODLING, true);
                                    pBroodling->ClearUnitState(UNIT_STATE_CASTING);
                                    pBroodling->GetMotionMaster()->MoveFollow(pTarget, 0.0f, 0.0f);
                                }
                            break;
                        case EVENT_ENERGY_2:
                            //me->SetPower(POWER_MANA, 9000);
                            break;
                        case EVENT_ENERGY:
                        {
                            uint32 energy = me->GetPower(POWER_MANA);
                            if (energy > 0)
                                me->SetPower(POWER_MANA, energy - 100);
                            if ((energy - 100) == 0)
                            {
                                uiCount++;
                                if (uiCount < 3)
                                {
                                    events.RescheduleEvent(EVENT_FILAMENT, 23000);
                                    events.RescheduleEvent(EVENT_CHECK_HIGH, 12000);
                                    events.RescheduleEvent(EVENT_EMBER_FLARE, 14000);
                                    events.ScheduleEvent(EVENT_ENERGY, 10000);
                                    events.ScheduleEvent(EVENT_ENERGY_2, 8000);
                                }
                                else
                                {
                                    events.CancelEvent(EVENT_ENERGY);
                                    events.CancelEvent(EVENT_FILAMENT);
                                    events.CancelEvent(EVENT_CHECK_HIGH);
                                    events.CancelEvent(EVENT_SUMMON_DRONE);
                                    events.CancelEvent(EVENT_SUMMON_SPIDERLING);
                                    events.RescheduleEvent(EVENT_EMBER_FLARE, 15000);
                                    events.ScheduleEvent(EVENT_GO_DOWN, 10000);
                                }

                                DoCastAOE(SPELL_SMOLDERING_DEVASTATION);
                            }
                            else
                                events.ScheduleEvent(EVENT_ENERGY, 1000);
                            break;
                        }
                        case EVENT_GO_DOWN:
                        {
                            uiPhase = PHASE_LOW;
                            me->GetMotionMaster()->MoveJump(addsPos[5], 40.0f, 40.0f);
                            events.ScheduleEvent(EVENT_FRENZY, 10000);
                            events.ScheduleEvent(EVENT_THE_WIDOW_KISS, 32000);
                            Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                            if (!PlayerList.isEmpty())
                            {
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                    if (Player* player = i->GetSource())
                                        if (player->GetPositionZ() > 100.0f)
                                            player->NearTeleportTo(addsPos[5].GetPositionX(), addsPos[5].GetPositionY(), addsPos[5].GetPositionZ(), 0.0f);
                            }
                            break;
                        }
                        case EVENT_FRENZY:
                            DoCast(me, SPELL_FRENZY);
                            events.ScheduleEvent(EVENT_FRENZY, 7000);
                            break;
                        case EVENT_THE_WIDOW_KISS:
                            DoCastVictim(SPELL_THE_WIDOW_KISS);
                            events.ScheduleEvent(EVENT_THE_WIDOW_KISS, 34000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            class PlayerPositionCheck
            {
                public:
                    PlayerPositionCheck(bool bRev): _bRev(bRev) {}
                    bool operator()(Player* u)
                    {
                        return _bRev? (u->GetPositionZ() > 100.0f): (u->GetPositionZ() < 100.0f);
                    }

                private:
                    bool _bRev;
            };

        };
};

class npc_bethtilac_spiderweb_filament : public CreatureScript
{
    public:
        npc_bethtilac_spiderweb_filament() : CreatureScript("npc_bethtilac_spiderweb_filament") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_bethtilac_spiderweb_filamentAI(pCreature);
        }

        struct npc_bethtilac_spiderweb_filamentAI : public Scripted_NoMovementAI
        {
            npc_bethtilac_spiderweb_filamentAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                pInstance = me->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            }

            InstanceScript* pInstance;

            void JustSummoned(Creature* summon) override
            {
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void OnSpellClick(Unit* who, bool& /*result*/) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    uint32 i = urand(6, 8);
                    who->NearTeleportTo(addsPos[i].GetPositionX(), addsPos[i].GetPositionY(), addsPos[i].GetPositionZ(), addsPos[i].GetOrientation());
                }
                if (me->GetOwner() && (me->GetOwner()->GetEntry() == NPC_SPIDERWEB_FILAMENT || me->GetOwner()->GetEntry() == NPC_BETHTILAC))
                    me->GetOwner()->ToCreature()->DespawnOrUnsummon();
                me->DespawnOrUnsummon();
            }

            void IsSummonedBy(Unit* owner) override
            {
                if (!owner)
                    me->DespawnOrUnsummon();

                if (owner->GetEntry() == NPC_BETHTILAC)
                {
                    if (Creature* pSpinner = owner->SummonCreature(NPC_CINDERWEB_SPINNER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                    {
                        pSpinner->SetCanFly(true);
                        DoCast(pSpinner, SPELL_SPIDERWEB_FILAMENT_ANY, true);
                        //pSpinner->CastSpell(pSpinner, SPELL_CREEPER, true);
                        pSpinner->CastSpell(pSpinner, SPELL_TEMPERAMENT, true);
                        //float z = pSpinner->GetMap()->GetHeight(pSpinner->GetPositionX(), pSpinner->GetPositionY(), pSpinner->GetPositionZ(), true);
                        float z = GROUND_HEIGHT;
                        pSpinner->GetMotionMaster()->MovePoint(0, pSpinner->GetPositionX(), pSpinner->GetPositionY(), z + 5.0f);
                    }
                }
                else if (owner->GetEntry() == NPC_CINDERWEB_SPINNER)
                {
                    DoCast(me, SPELL_SPIDERWEB_FILAMENT_DOWN, true);
                    //float z = me->GetMap()->GetHeight(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), true, 100.0f);
                    float z = GROUND_HEIGHT;
                    me->GetMotionMaster()->MovePoint(POINT_DOWN, me->GetPositionX(), me->GetPositionY(), z);
                }
            }

            void MovementInform(uint32 type, uint32 data) override
            {
                if (type == POINT_MOTION_TYPE)
                    if (data == POINT_DOWN)
                    {
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (pInstance->GetBossState(DATA_BETHTILAC) != IN_PROGRESS)
                    me->DespawnOrUnsummon();
            }
        };
};

class npc_bethtilac_cinderweb_spinner : public CreatureScript
{
    public:
        npc_bethtilac_cinderweb_spinner() : CreatureScript("npc_bethtilac_cinderweb_spinner") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_bethtilac_cinderweb_spinnerAI(pCreature);
        }

        struct npc_bethtilac_cinderweb_spinnerAI : public ScriptedAI
        {
            npc_bethtilac_cinderweb_spinnerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                bTaunted = false;
                owner = NULL;
                pInstance = me->GetInstanceScript();
            }

            bool bTaunted;
            Unit* owner;
            InstanceScript* pInstance;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_BURNING_ACID, urand(7000, 15000));
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_FIERY_WEB_SPIN, urand(5000, 15000));
            }

            void IsSummonedBy(Unit* who) override
            {
                if (who)
                    owner = who;
            }

            void JustDied(Unit* /*who*/) override
            {
                me->SetCanFly(false);
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                if (bTaunted)
                    return;

                if (spellInfo->HasEffect(SPELL_EFFECT_ATTACK_ME) || spellInfo->HasAura(DIFFICULTY_NONE, SPELL_AURA_MOD_TAUNT))
                {
                    bTaunted = true;
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (owner && owner->GetEntry() == NPC_BETHTILAC)
                        if (Creature* pFilament = me->SummonCreature(NPC_SPIDERWEB_FILAMENT, owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 15000))
                        {
                            pFilament->SetCanFly(true);
                            owner->CastSpell(pFilament, SPELL_SPIDERWEB_FILAMENT_ANY, true);
                        }

                    events.CancelEvent(EVENT_FIERY_WEB_SPIN);
                    me->InterruptNonMeleeSpells(false);
                    me->RemoveAura(SPELL_SPIDERWEB_FILAMENT_ANY);
                    //me->RemoveAura(SPELL_CREEPER);
                    me->RemoveAura(SPELL_TEMPERAMENT);
                    me->SetCanFly(false);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (pInstance->GetBossState(DATA_BETHTILAC) != IN_PROGRESS)
                    me->DespawnOrUnsummon();

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BURNING_ACID:
                            DoCastAOE(SPELL_BURNING_ACID);
                            events.ScheduleEvent(EVENT_BURNING_ACID, urand(7000, 15000));
                            break;
                        case EVENT_FIERY_WEB_SPIN:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, PositionSelector(true, SPELL_FIERY_WEB_SPIN)))
                                DoCast(pTarget, SPELL_FIERY_WEB_SPIN);
                            events.ScheduleEvent(EVENT_FIERY_WEB_SPIN, urand(25000, 30000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_bethtilac_cinderweb_drone : public CreatureScript
{
    public:
        npc_bethtilac_cinderweb_drone() : CreatureScript("npc_bethtilac_cinderweb_drone") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_bethtilac_cinderweb_droneAI(pCreature);
        }

        struct npc_bethtilac_cinderweb_droneAI : public ScriptedAI
        {
            npc_bethtilac_cinderweb_droneAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            }

            EventMap events;

            void Reset() override
            {
                DoCast(me, SPELL_ZERO_POWER, true);
                me->SetMaxPower(POWER_MANA, 90);
                me->SetPower(POWER_MANA, 90);
                DoCast(me, SPELL_ENERGIZE, true);
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_BURNING_ACID, urand(7000, 15000));
                events.ScheduleEvent(EVENT_BOILING_SPATTER, urand(14000, 20000));
                events.ScheduleEvent(EVENT_CHECK_TARGET, 2000);
                events.ScheduleEvent(EVENT_CHECK_SPIDERLING, 3000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_FIXATE, urand(12000, 15000));
            }

            void JustDied(Unit* /*who*/) override
            {
                for (uint8 i = 0; i < 3; ++i)
                    DoCast(me, SPELL_CREATE_CHITINOUS_FRAGMENT, true);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIXATE:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, PositionSelector(true, 0)))
                            {
                                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                                DoResetThreat();
                                DoCast(me, SPELL_FIXATE_SELF, true);
                                DoCast(pTarget, SPELL_FIXATE, true);
                                me->AddThreat(pTarget, 1000000.0f);
                                AttackStart(pTarget);
                                events.ScheduleEvent(EVENT_FIXATE_OFF, 10000);
                            }
                            break;
                        case EVENT_FIXATE_OFF:
                            DoResetThreat();
                            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                            break;
                        case EVENT_BOILING_SPATTER:
                            DoCast(me, SPELL_BOILING_SPATTER);
                            events.ScheduleEvent(EVENT_BOILING_SPATTER, urand(15000, 20000));
                            break;
                        case EVENT_BURNING_ACID:
                            DoCastAOE(SPELL_BURNING_ACID);
                            events.ScheduleEvent(EVENT_BURNING_ACID, urand(10000, 15000));
                            break;
                        case EVENT_CHECK_TARGET:
                            if (me->GetVictim())
                                if (me->GetVictim()->GetPositionZ() > 100.0f)
                                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, PositionSelector(true, 0)))
                                        AttackStart(pTarget);

                            events.ScheduleEvent(EVENT_CHECK_TARGET, 2000);
                            break;
                        case EVENT_CHECK_SPIDERLING:
                            if (Creature* pSpiderling = me->FindNearestCreature(NPC_CINDERWEB_SPIDERLING, 8.0f))
                                DoCast(pSpiderling, SPELL_CONSUME_DRONE, true);
                            events.ScheduleEvent(EVENT_CHECK_SPIDERLING, 3000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_bethtilac_cinderweb_spiderling : public CreatureScript
{
    public:
        npc_bethtilac_cinderweb_spiderling() : CreatureScript("npc_bethtilac_cinderweb_spiderling") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_bethtilac_cinderweb_spiderlingAI(pCreature);
        }

        struct npc_bethtilac_cinderweb_spiderlingAI : public ScriptedAI
        {
            npc_bethtilac_cinderweb_spiderlingAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pDrone = NULL;
                me->SetReactState(REACT_PASSIVE);
            }

            Unit* pDrone;
            EventMap events;

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_CHECK_DRONE, 2000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_DRONE:
                            if (!pDrone || !pDrone->IsAlive())
                            {
                                if (Creature* pTarget = me->FindNearestCreature(NPC_CINDERWEB_DRONE, 500.0f))
                                {
                                    pDrone = pTarget;
                                    me->GetMotionMaster()->MovementExpired(false);
                                    me->GetMotionMaster()->MoveFollow(pDrone, 0.0f, 0.0f);
                                }
                                else
                                {
                                    if (!me->isMoving())
                                    {
                                        me->GetMotionMaster()->MovementExpired(false);
                                        me->GetMotionMaster()->MovePoint(0, addsPos[5]);
                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_CHECK_DRONE, 2000);
                            break;
                    }
                }
            }
        };
};

class npc_bethtilac_engorged_broodling : public CreatureScript
{
    public:
        npc_bethtilac_engorged_broodling() : CreatureScript("npc_bethtilac_engorged_broodling") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_bethtilac_engorged_broodlingAI(pCreature);
        }

        struct npc_bethtilac_engorged_broodlingAI : public ScriptedAI
        {
            npc_bethtilac_engorged_broodlingAI(Creature* pCreature) : ScriptedAI(pCreature)
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
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                me->SetReactState(REACT_PASSIVE);
                me->SetSpeed(MOVE_RUN, 2.0f);
            }

            bool bBurst;

            void EnterCombat(Unit* /*who*/) override
            {
                bBurst = false;
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!bBurst && me->SelectNearestPlayer(3.0f))
                {
                    bBurst = true;
                    DoCastAOE(SPELL_VOLATILE_BURST);
                    DoCast(me, SPELL_VOLATILE_POISON, true);
                    me->DespawnOrUnsummon(30000);
                }
            }
        };
};

class achievement_death_from_above : public AchievementCriteriaScript
{
    public:
        achievement_death_from_above() : AchievementCriteriaScript("achievement_death_from_above") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (boss_bethtilac::boss_bethtilacAI* BethtilacAI = CAST_AI(boss_bethtilac::boss_bethtilacAI, target->GetAI()))
                return BethtilacAI->AllowAchieve();

            return false;
        }
};

class PositionCheck
{
    public:
        PositionCheck(bool b) : _b(b) {}

        bool operator()(WorldObject* unit)
        {
            return _b? (unit->GetPositionZ() > 100.0f): (unit->GetPositionZ() < 100.0f);
        }

        private:
            bool _b;
};

class spell_bethtilac_smoldering_devastation : public SpellScriptLoader
{
    public:
        spell_bethtilac_smoldering_devastation() : SpellScriptLoader("spell_bethtilac_smoldering_devastation") { }

        class spell_bethtilac_smoldering_devastation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_bethtilac_smoldering_devastation_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if(PositionCheck(false));
            }

            void HandleAfterCast()
            {
                if (!GetCaster())
                    return;

                std::list<Creature*> creatureList;
                GetCaster()->GetCreatureListWithEntryInGrid(creatureList, NPC_DULL_CHITINOUS_FOCUS, 100.0f);
                if (!creatureList.empty())
                {
                    for (std::list<Creature*>::const_iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
                    {
                        if (Creature* pFocus = (*itr)->ToCreature())
                        {
                            pFocus->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            pFocus->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                            pFocus->CastSpell(pFocus, SPELL_TRANSFORM_CHARGED_CHITINOUS_FOCUS, true);
                        }
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_bethtilac_smoldering_devastation_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                AfterCast += SpellCastFn(spell_bethtilac_smoldering_devastation_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_bethtilac_smoldering_devastation_SpellScript();
        }
};

class spell_bethtilac_ember_flare : public SpellScriptLoader
{
    public:
        spell_bethtilac_ember_flare() : SpellScriptLoader("spell_bethtilac_ember_flare") { }

        class spell_bethtilac_ember_flare_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_bethtilac_ember_flare_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if(PositionCheck(false));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_bethtilac_ember_flare_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            private:

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_bethtilac_ember_flare_SpellScript();
        }
};

class spell_bethtilac_burning_acid : public SpellScriptLoader
{
    public:
        spell_bethtilac_burning_acid() : SpellScriptLoader("spell_bethtilac_burning_acid") { }

        class spell_bethtilac_burning_acid_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_bethtilac_burning_acid_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if(PositionCheck(true));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_bethtilac_burning_acid_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            private:

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_bethtilac_burning_acid_SpellScript();
        }
};

void AddSC_boss_bethtilac()
{
    new boss_bethtilac();
    new npc_bethtilac_spiderweb_filament();
    new npc_bethtilac_cinderweb_spinner();
    new npc_bethtilac_cinderweb_drone();
    new npc_bethtilac_cinderweb_spiderling();
    new npc_bethtilac_engorged_broodling();
    new spell_bethtilac_smoldering_devastation();
    new spell_bethtilac_ember_flare();
    new spell_bethtilac_burning_acid();
    new achievement_death_from_above();
}
