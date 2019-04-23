/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "GridNotifiers.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "dragon_soul.h"
#include "MoveSplineInit.h"
#include "boss_warmaster_blackhorn.h"
#include <G3D/Vector3.h>
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ScriptedGossip.h"

enum ScriptedTextBlackhorn
{
    SAY_AGGRO       = 0,
    SAY_DEATH       = 1,
    SAY_EVENT_1     = 2,
    SAY_EVENT_2     = 3,
    SAY_INTRO       = 4,
    SAY_KILL        = 5,
    SAY_GORIONA     = 6,
    SAY_ROAR        = 7,
    SAY_SHOCKWAVE   = 8,
    SAY_SAPPER_YELL = 9,
};

enum ScriptedTextSwayze
{
    SAY_SWAYZE_VICTORY = 0,
    SAY_SWAYZE_BACK_1  = 1,
    SAY_SWAYZE_BACK_2  = 2,
    SAY_SWAYZE_EVENT_1 = 3,
    SAY_SWAYZE_EVENT_2 = 4,
    SAY_SWAYZE_EVENT_3 = 5,
    SAY_SWAYZE_EVENT_4 = 6,
    SAY_SWAYZE_EVENT_5 = 7,
    SAY_SWAYZE_EVENT_6 = 8,
    SAY_SWAYZE_PRE_1   = 9,
    SAY_SWAYZE_PRE_2   = 10,
};

enum Spells
{
    // Warmaster Blackhorn
    SPELL_BERSERK                       = 26662,
    SPELL_VENGEANCE                     = 108045,
    SPELL_DEVASTATE                     = 108042,
    SPELL_DISRUPTING_ROAR               = 108044,
    SPELL_SHOCKWAVE_AOE                 = 110137,
    SPELL_SHOCKWAVE                     = 108046,
    SPELL_SIPHON_VITALITY               = 110312,

    // Goriona
    SPELL_TWILIGHT_ONSLAUGHT_DUMMY_1    = 107927,
    SPELL_TWILIGHT_ONSLAUGHT_DUMMY_2    = 107586,
    SPELL_TWILIGHT_ONSLAUGHT            = 107588,
    SPELL_TWILIGHT_ONSLAUGHT_DMG_1      = 106401,
    SPELL_TWILIGHT_ONSLAUGHT_DMG_2      = 107589,
    SPELL_BROADSIDE_AOE                 = 110153,
    SPELL_BROADSIDE_DMG                 = 110157,
    SPELL_TWILIGHT_BREATH               = 110212,
    SPELL_CONSUMING_SHROUD              = 110214,
    SPELL_CONSUMING_SHROUD_DMG          = 110215,
    SPELL_TWILIGHT_MISSILE              = 108050,
    SPELL_TWILIGHT_FLAMES               = 108051,
    SPELL_TWILIGHT_FLAMES_AURA          = 108053,

    // Twilight Assault Drake
    SPELL_TWILIGHT_BARRAGE              = 107286,
    SPELL_TWILIGHT_BARRAGE_DMG_1        = 107439,
    SPELL_TWILIGHT_BARRAGE_DUMMY        = 107287,
    SPELL_TWILIGHT_BARRAGE_DMG_2        = 107501,

    // Twilight Elite Dreadblade & Slayer
    SPELL_BLADE_RUSH                    = 107594,
    SPELL_BLADE_RUSH_DMG                = 107595,
    SPELL_BRUTAL_STRIKE                 = 107567,
    SPELL_DEGENERATION                  = 107558,

    // Twilight Sapper
    SPELL_EVADE                         = 107761,
    SPELL_DETONATE                      = 107518,
    SPELL_SMOKE_BOMB                    = 107752,

    // Skifire
    SPELL_ENGINE_FIRE                   = 107799,
    SPELL_DECK_FIRE                     = 109445, // 109245
    SPELL_DECK_FIRE_DMG                 = 110095,
    SPELL_DECK_FIRE_PERIODIC            = 110092,
    SPELL_DECK_FIRE_SPAWN               = 109470,
    SPELL_MASSIVE_EXPLOSION             = 108132,
    SPELL_HEAVY_SLUG                    = 108010,
    SPELL_ARTILLERY_BARRAGE             = 108040,
    SPELL_ARTILLERY_BARRAGE_DMG         = 108041,
    SPELL_HARPOON                       = 108038,
    SPELL_RELOADING                     = 108039,
    SPELL_RIDE_VEHICLE                  = 43671, // commandos on harpoon guns and cannons
};

enum Adds
{
    NPC_TWILIGHT_ASSAULT_DRAKE_1    = 56855,
    NPC_TWILIGHT_ASSAULT_DRAKE_2    = 56587,
    NPC_TWILIGHT_ELITE_DREADBLADE   = 56854,
    NPC_TWILIGHT_ELITE_SLAYER       = 56848,
    NPC_TWILIGHT_INFILTRATOR        = 56922,
    NPC_TWILIGHT_SAPPER             = 56923,
    NPC_SKYFIRE                     = 56598,
    NPC_TWILIGHT_FLAMES             = 57268,
    NPC_MASSIVE_EXPLOSION           = 57297,
    NPC_GUNSHIP_PURSUIT_CONTROLLER  = 56599,
    NPC_ONSLAUGHT_TARGET            = 57238,

    NPC_ENGINE_STALKER              = 57190,
    NPC_FIRE_STALKER                = 57852,
    NPC_SKYFIRE_HARPOON_GUN         = 56681,
    NPC_SKYFIRE_CANNON              = 57260,
    NPC_SKYFIRE_COMMANDO            = 57264,
};

enum Events
{
    EVENT_INTRO_1               = 1,
    EVENT_INTRO_2               = 2,
    EVENT_INTRO_3               = 3,
    EVENT_INTRO_4               = 4,
    EVENT_INTRO_5               = 5,
    EVENT_CHECK_PLAYERS         = 6,
    EVENT_SUMMON_DRAKE          = 7,
    EVENT_TWILIGHT_BARRAGE      = 8,
    EVENT_TWILIGHT_ONSLAUGHT    = 9,
    EVENT_BLADE_RUSH            = 10,
    EVENT_DEGENERATION          = 11,
    EVENT_BRUTAL_STRIKE         = 12,
    EVENT_SUMMON_ADDS           = 13,
    EVENT_CONTINUE              = 14,
    EVENT_HARPOON               = 15,
    EVENT_BROADSIDE             = 16,
    EVENT_HARPOON_END           = 17,
    EVENT_SUMMON_INFILTRATOR    = 18,
    EVENT_SUMMON_SAPPER         = 19,
    EVENT_DESPAWN_INFILTRATOR   = 20,
    EVENT_SMOKE_BOMB            = 21,
    EVENT_SMOKE_BOMB_REMOVE     = 22,
    EVENT_KILL                  = 23,
    EVENT_END_BATTLE            = 24,
    EVENT_SHOCKWAVE             = 25,
    EVENT_DISRUPTING_ROAR       = 26,
    EVENT_DEVASTATE             = 27,
    EVENT_CONSUMING_SHROUD      = 28,
    EVENT_TWILIGHT_FLAMES       = 29,
    EVENT_TWILIGHT_BREATH       = 30,
    EVENT_SECOND_PHASE_1        = 31, // Swayze talk
    EVENT_SECOND_PHASE_2        = 32, // Canons fire
    EVENT_SECOND_PHASE_3        = 33, // Blackhorn talks, Goriona falls
    EVENT_SECOND_PHASE_4        = 34, // Blackhorn appears
    EVENT_BERSERK               = 35,
    EVENT_SIPHON_VITALITY       = 36,
};

enum Actions
{
    ACTION_START            = 1,
    ACTION_START_BATTLE     = 2,
    ACTION_END_BATTLE       = 3,
    ACTION_GORIONA_MOVE     = 4,
    ACTION_HARPOON          = 5,
    ACTION_HARPOON_END      = 6,
    ACTION_SAPPER           = 7,
    ACTION_SECOND_PHASE     = 8,
    ACTION_DECK             = 9,
    ACTION_BLACKHORN_DIED   = 10,
};

class boss_warmaster_blackhorn: public CreatureScript
{
    public:
        boss_warmaster_blackhorn() : CreatureScript("boss_warmaster_blackhorn") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_warmaster_blackhornAI(pCreature);
        }

        struct boss_warmaster_blackhornAI : public BossAI
        {
            boss_warmaster_blackhornAI(Creature* pCreature) : BossAI(pCreature, DATA_BLACKHORN)
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
                uiWave = 0;
                drakeDied = 0;
                phase = 0;
                deck = true;
            }

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptId(DSScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset() override
            {
                _Reset();

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                me->SetVisible(false);

                me->setActive(true);

                uiWave = 0;
                drakeDied = 0;
                phase = 0;
                deck = true;
                ShockWave = false;
                orientation = 0;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                uiWave = 0;
                drakeDied = 0;
                phase = 0;
                deck = true;
                ShockWave = false;
                orientation = 0;

                DoZoneInCombat();
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_START_BATTLE)
                {
                    Talk(SAY_AGGRO);
                    DoZoneInCombat();
                    instance->SetBossState(DATA_BLACKHORN, IN_PROGRESS);

                    if (Creature* pGoriona = me->FindNearestCreature(NPC_GORIONA, 300.0f))
                    {
                        DoZoneInCombat(pGoriona);
                        pGoriona->AI()->DoAction(ACTION_GORIONA_MOVE);
                    }
                    if (Creature* pShip = me->FindNearestCreature(NPC_SKYFIRE, 300.0f))
                    {
                        pShip->SetInCombatWith(me);
                        pShip->AddThreat(me, 0.0f);
                        me->AddThreat(pShip, 0.0f);
                    }

                    events.ScheduleEvent(EVENT_SUMMON_DRAKE, 10000);
                    events.ScheduleEvent(EVENT_HARPOON, 40000);
                    events.ScheduleEvent(EVENT_SUMMON_INFILTRATOR, 58000);
                }
                else if (action == ACTION_END_BATTLE)
                {
                    summons.DespawnAll();
                    DespawnCreatures(NPC_TWILIGHT_FLAMES);


                    events.Reset();
                    if (Creature* pShip = me->FindNearestCreature(NPC_SKYFIRE, 300.0f))
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pShip);
                        pShip->DespawnOrUnsummon();
                    }
                    if (Creature* pGoriona = me->FindNearestCreature(NPC_GORIONA, 300.0f))
                        pGoriona->DespawnOrUnsummon();

                    std::list<Creature*> creatures;
                    me->GetCreatureListWithEntryInGrid(creatures, NPC_SKYFIRE_HARPOON_GUN, 200.0f);
                    if (creatures.size() == 2)
                        for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                            (*itr)->AI()->DoAction(ACTION_END_BATTLE);

                    creatures.clear();
                    me->GetCreatureListWithEntryInGrid(creatures, NPC_SKYFIRE_CANNON, 200.0f);
                    if (!creatures.empty())
                        for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                            {
                                (*itr)->InterruptNonMeleeSpells(false);
                                (*itr)->AI()->EnterEvadeMode();
                        }

                    me->DespawnOrUnsummon(2000);
                    instance->SetBossState(DATA_BLACKHORN, NOT_STARTED);
                }
                else if (action == ACTION_DECK)
                    deck = false;
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                if (summon->GetEntry() == NPC_TWILIGHT_ASSAULT_DRAKE_1 ||
                    summon->GetEntry() == NPC_TWILIGHT_ASSAULT_DRAKE_2)
                    drakeDied++;

                if (drakeDied >= 6 && phase == 0)
                {
                    phase = 1;

                    events.CancelEvent(EVENT_HARPOON);
                    events.CancelEvent(EVENT_SUMMON_DRAKE);
                    events.CancelEvent(EVENT_SUMMON_INFILTRATOR);

                    std::list<Creature*> creatures;
                    me->GetCreatureListWithEntryInGrid(creatures, NPC_SKYFIRE_HARPOON_GUN, 200.0f);
                    if (creatures.size() == 2)
                        for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                            (*itr)->AI()->DoAction(ACTION_END_BATTLE);


                    DoCast(me, SPELL_VENGEANCE, true);

                    events.ScheduleEvent(EVENT_SECOND_PHASE_1, 5000);
                }
            }

            bool AllowAchieve()
            {
                return deck;
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);

                _JustDied();

                //75 Justices Points for players level 85
                //instance->DoModifyPlayerCurrenciesIfLevel(395, 7500, 85);
                if (!IsHeroic())
                {
                    instance->DoModifyPlayerCurrencies(614, 1);
                    instance->DoModifyPlayerCurrencies(615, 1);
                }
                else
                {
                    instance->DoModifyPlayerCurrencies(614, 2);
                    instance->DoModifyPlayerCurrencies(615, 2);
                }

                DespawnCreatures(NPC_TWILIGHT_FLAMES);
                instance->SetBossState(DATA_BLACKHORN, DONE);

                if (Creature* pShip = me->FindNearestCreature(NPC_SKYFIRE, 300.0f))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pShip);
                    pShip->DespawnOrUnsummon();
                }

                std::list<Creature*> creatures;
                me->GetCreatureListWithEntryInGrid(creatures, NPC_SKYFIRE_CANNON, 200.0f);
                if (!creatures.empty())
                    for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                        {
                            (*itr)->InterruptNonMeleeSpells(false);
                            (*itr)->AI()->EnterEvadeMode();
                        }

                if (Creature* pSwayze = me->FindNearestCreature(NPC_SKY_CAPTAIN_SWAYZE, 200.0f))
                    pSwayze->AI()->DoAction(ACTION_BLACKHORN_DIED);

            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (ShockWave && orientation)
                {
                    me->SetOrientation(orientation);
                    me->SetFacingTo(orientation);
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_DRAKE:
                            if (uiWave < 3)
                            {
                                uiWave++;
                                CallAssaultDrakes(uiWave);
                                events.ScheduleEvent(EVENT_SUMMON_DRAKE, 60000);
                            }
                            break;
                        case EVENT_HARPOON:
                        {
                            std::list<Creature*> creatures;
                            me->GetCreatureListWithEntryInGrid(creatures, NPC_SKYFIRE_HARPOON_GUN, 200.0f);
                            if (creatures.size() == 2)
                                for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                                    (*itr)->AI()->DoAction(ACTION_HARPOON);

                            events.ScheduleEvent(EVENT_HARPOON, 35000);
                            break;
                        }
                        case EVENT_SUMMON_INFILTRATOR:
                            me->SummonCreature(NPC_TWILIGHT_INFILTRATOR, infiltratorPos[0]);
                            events.ScheduleEvent(EVENT_SUMMON_INFILTRATOR, 40000);
                            break;
                        case EVENT_SECOND_PHASE_1:
                            if (Creature* pSwayze = me->FindNearestCreature(NPC_SKY_CAPTAIN_SWAYZE, 200.0f))
                                pSwayze->AI()->Talk(SAY_SWAYZE_EVENT_3);
                            events.ScheduleEvent(EVENT_SECOND_PHASE_2, 3000);
                            break;
                        case EVENT_SECOND_PHASE_2:
                        {
                            if (Creature* pGoriona = me->FindNearestCreature(NPC_GORIONA, 200.0f))
                            {
                                std::list<Creature*> creatures;
                                me->GetCreatureListWithEntryInGrid(creatures, NPC_SKYFIRE_CANNON, 200.0f);
                                if (!creatures.empty())
                                    for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                                    {
                                        (*itr)->SetFacingToObject(pGoriona);
                                        (*itr)->CastSpell(pGoriona, SPELL_ARTILLERY_BARRAGE);
                                    }
                            }
                            events.ScheduleEvent(EVENT_SECOND_PHASE_3, 5000);
                            break;
                        }
                        case EVENT_SECOND_PHASE_3:
                            Talk(SAY_EVENT_1);
                            if (Creature* pGoriona = me->FindNearestCreature(NPC_GORIONA, 300.0f))
                                pGoriona->AI()->DoAction(ACTION_SECOND_PHASE);
                            events.ScheduleEvent(EVENT_SECOND_PHASE_4, 3000);
                            break;
                        case EVENT_SECOND_PHASE_4:
                        {
                            me->SetVisible(true);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->SetReactState(REACT_AGGRESSIVE);

                            std::list<Creature*> creatures;
                            me->GetCreatureListWithEntryInGrid(creatures, NPC_SKYFIRE_CANNON, 200.0f);
                            if (!creatures.empty())
                                for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                                {
                                    (*itr)->InterruptNonMeleeSpells(false);
                                    (*itr)->AI()->EnterEvadeMode();
                                }

                            events.ScheduleEvent(EVENT_BERSERK, 4 * MINUTE * IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_DISRUPTING_ROAR, 10000);
                            events.ScheduleEvent(EVENT_SHOCKWAVE, urand(13000, 16000));
                            events.ScheduleEvent(EVENT_DEVASTATE, urand(6000, 8500));
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_SIPHON_VITALITY, 5000);
                            break;
                        }
                        case EVENT_BERSERK:
                            Talk(SAY_EVENT_2);
                            DoCast(me, SPELL_BERSERK);
                            break;
                        case EVENT_DISRUPTING_ROAR:
                            Talk(SAY_ROAR);
                            DoCastAOE(SPELL_DISRUPTING_ROAR);
                            events.ScheduleEvent(EVENT_DISRUPTING_ROAR, urand(18500, 23000));
                            break;
                        case EVENT_SHOCKWAVE:
                            Talk(SAY_SHOCKWAVE);

                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            ShockWave = true;
                            orientation = me->GetOrientation();
                            DoCastAOE(SPELL_SHOCKWAVE_AOE);
                            events.ScheduleEvent(EVENT_CONTINUE, 3000);
                            events.ScheduleEvent(EVENT_SHOCKWAVE, 23000);
                            break;
                        case EVENT_CONTINUE:
                            ShockWave = false;
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_DEVASTATE:
                            DoCastVictim(SPELL_DEVASTATE);
                            events.ScheduleEvent(EVENT_DEVASTATE, 8500);
                            break;
                        case EVENT_SIPHON_VITALITY:
                            if (me->HealthBelowPct(60))
                            {
                                if (Creature* pGoriona = me->FindNearestCreature(NPC_GORIONA, 200.0f))
                                    if (pGoriona->GetHealthPct() >= 30.0f)
                                        DoCast(pGoriona, SPELL_SIPHON_VITALITY);
                            }
                            events.ScheduleEvent(EVENT_SIPHON_VITALITY, 10000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 uiWave;
            uint8 drakeDied;
            uint8 phase;
            bool deck;
            float orientation;
            bool ShockWave;

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                   return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                     (*iter)->DespawnOrUnsummon();
            }

            void CallAssaultDrakes(uint8 wave)
            {
                if (Creature* pCreature = me->SummonCreature(NPC_TWILIGHT_ASSAULT_DRAKE_1, assaultdrakePos[0][0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000))
                    pCreature->AI()->SetData(DATA_WAVE, wave);
                if (Creature* pCreature = me->SummonCreature(NPC_TWILIGHT_ASSAULT_DRAKE_2, assaultdrakePos[1][0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000))
                    pCreature->AI()->SetData(DATA_WAVE, wave);
            }
        };
};

class npc_warmaster_blackhorn_goriona: public CreatureScript
{
    public:
        npc_warmaster_blackhorn_goriona() : CreatureScript("npc_warmaster_blackhorn_goriona") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_warmaster_blackhorn_gorionaAI(pCreature);
        }

        struct npc_warmaster_blackhorn_gorionaAI : public ScriptedAI
        {
            npc_warmaster_blackhorn_gorionaAI(Creature* pCreature) : ScriptedAI(pCreature)
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
                phase = 0;
            }

            void Reset() override
            {
                events.Reset();
                me->SetReactState(REACT_PASSIVE);
                me->setActive(true);
                phase = 0;
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }

            void MovementInform(uint32 type, uint32 data) override
            {
                if (type == POINT_MOTION_TYPE)
                    if (data == POINT_LAND)
                    {
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                        events.ScheduleEvent(EVENT_CONTINUE, 1000);
                        events.ScheduleEvent(EVENT_TWILIGHT_BREATH, urand(10000, 20000));
                    }
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.Reset();
                me->SetReactState(REACT_PASSIVE);
                me->setActive(true);
                phase = 0;
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }

            void JustSummoned(Creature* summon) override
            {
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_GORIONA_MOVE)
                {
                    me->SetSpeed(MOVE_RUN, 2.0f);
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    Movement::MoveSplineInit init(me);
                    for (uint8 i = 1; i < 6; ++i)
                    {
                        G3D::Vector3 point;
                        point.x = gorionaPos[i].GetPositionX();
                        point.y = gorionaPos[i].GetPositionY();
                        point.z = gorionaPos[i].GetPositionZ();
                        init.Path().push_back(point);
                    }
                    init.SetWalk(false);
                    init.Launch();

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    events.ScheduleEvent(EVENT_TWILIGHT_ONSLAUGHT, 46000);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_BROADSIDE, 57000);
                }
                else if (action == ACTION_SECOND_PHASE)
                {
                    phase = 1;

                    me->InterruptNonMeleeSpells(false);

                    events.CancelEvent(EVENT_TWILIGHT_ONSLAUGHT);
                    events.CancelEvent(EVENT_BROADSIDE);

                    Movement::MoveSplineInit init(me);
                    init.MoveTo(gorionaPos[6].GetPositionX(), gorionaPos[6].GetPositionY(), gorionaPos[6].GetPositionZ());
                    init.SetWalk(false);
                    init.Launch();

                    events.ScheduleEvent(EVENT_TWILIGHT_FLAMES, 15000);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_CONSUMING_SHROUD, 45000);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (IsHeroic() && me->HealthBelowPct(90) && phase == 1)
                {
                    phase = 2;

                    me->GetMotionMaster()->MovePoint(POINT_LAND, gorionaPos[7].GetPositionX(), gorionaPos[7].GetPositionY(), gorionaPos[7].GetPositionZ());

                    return;
                }
                else if (me->HealthBelowPct(20) && phase != 3)
                {
                    phase = 3;

                    events.CancelEvent(EVENT_TWILIGHT_ONSLAUGHT);
                    events.CancelEvent(EVENT_BROADSIDE);
                    events.CancelEvent(EVENT_CONTINUE);
                    events.CancelEvent(EVENT_TWILIGHT_FLAMES);
                    events.CancelEvent(EVENT_TWILIGHT_BREATH);
                    events.CancelEvent(EVENT_CONSUMING_SHROUD);

                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveAllAuras();

                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);

                    Movement::MoveSplineInit init(me);
                    init.MoveTo(gorionaPos[4].GetPositionX(), gorionaPos[4].GetPositionY(), gorionaPos[4].GetPositionZ());
                    init.SetWalk(false);
                    init.Launch();

                    me->DespawnOrUnsummon(4000);
                    return;
                }

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TWILIGHT_ONSLAUGHT:
                        {
                            std::list<Creature*> creatures;
                            me->GetCreatureListWithEntryInGrid(creatures, NPC_ONSLAUGHT_TARGET, 300.0f);
                            if (!creatures.empty())
                                if (Unit* pTarget = Trinity::Containers::SelectRandomContainerElement(creatures))
                                {
                                    pTarget->CastSpell(pTarget, SPELL_TWILIGHT_ONSLAUGHT_DUMMY_1, true);
                                    me->CastSpell(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), SPELL_TWILIGHT_ONSLAUGHT, false);
                                }

                            events.ScheduleEvent(EVENT_TWILIGHT_ONSLAUGHT, 35000);
                            break;
                        }
                        case EVENT_BROADSIDE:
                            DoCastAOE(SPELL_BROADSIDE_AOE);
                            events.ScheduleEvent(EVENT_BROADSIDE, 90000);
                            break;
                        case EVENT_CONTINUE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_TWILIGHT_BREATH:
                            DoCastVictim(SPELL_TWILIGHT_BREATH);
                            events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 20500);
                            break;
                        case EVENT_TWILIGHT_FLAMES:
                        {
                            Unit* pTarget = NULL;
                            pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, TwilightFlamesSelector());
                            if (!pTarget)
                                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                            if (pTarget)
                                me->CastSpell(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), SPELL_TWILIGHT_MISSILE, true);
                            events.ScheduleEvent(EVENT_TWILIGHT_FLAMES, 9000);
                            break;
                        }
                        case EVENT_CONSUMING_SHROUD:
                            DoCastAOE(SPELL_CONSUMING_SHROUD);
                            events.ScheduleEvent(EVENT_CONSUMING_SHROUD, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
            uint8 phase;

            struct TwilightFlamesSelector : public std::unary_function<Unit*, bool>
            {
                public:

                    TwilightFlamesSelector() {}

                    bool operator()(Unit const* target) const
                    {
                        if (target->GetTypeId() != TYPEID_PLAYER)
                            return false;
                        if (target->FindNearestCreature(NPC_BLACKHORN, 14.0f))
                            return false;
                        return true;
                    }
            };
        };
};

class npc_warmaster_blackhorn_twilight_assault_drake: public CreatureScript
{
    public:
        npc_warmaster_blackhorn_twilight_assault_drake() : CreatureScript("npc_warmaster_blackhorn_twilight_assault_drake") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_warmaster_blackhorn_twilight_assault_drakeAI(pCreature);
        }

        struct npc_warmaster_blackhorn_twilight_assault_drakeAI : public ScriptedAI
        {
            npc_warmaster_blackhorn_twilight_assault_drakeAI(Creature* pCreature) : ScriptedAI(pCreature)
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
                side = 0;
                wave = 0;
                bReady = false;
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->setActive(true);
                side = ((me->GetEntry() == NPC_TWILIGHT_ASSAULT_DRAKE_2) ? 1 : 0);
                wave = 0;
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.ScheduleEvent(EVENT_SUMMON_ADDS, 9000);
                events.ScheduleEvent(EVENT_TWILIGHT_BARRAGE, urand(23000, 28000));
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_HARPOON_END)
                {
                    me->InterruptNonMeleeSpells(false);
                    me->RemoveAura(SPELL_HARPOON);
                    Movement::MoveSplineInit init(me);
                    G3D::Vector3 point;
                    switch (wave)
                    {
                        case 2:
                            point.x = assaultdrakePos[side][8].GetPositionX();
                            point.y = assaultdrakePos[side][8].GetPositionY();
                            point.z = assaultdrakePos[side][8].GetPositionZ();
                            break;
                        case 3:
                            point.x = assaultdrakePos[side][9].GetPositionX();
                            point.y = assaultdrakePos[side][9].GetPositionY();
                            point.z = assaultdrakePos[side][9].GetPositionZ();
                            break;
                        default:
                            point.x = assaultdrakePos[side][7].GetPositionX();
                            point.y = assaultdrakePos[side][7].GetPositionY();
                            point.z = assaultdrakePos[side][7].GetPositionZ();
                            break;
                    }
                    init.MoveTo(point);
                    init.SetWalk(false);
                    init.Launch();
                }
            }

            bool IsReady()
            {
                return bReady;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                if (spellInfo->Id == SPELL_HARPOON)
                {
                    me->InterruptNonMeleeSpells(false);
                    Movement::MoveSplineInit init(me);
                    init.MoveTo(harpoonPos[side].GetPositionX(), harpoonPos[side].GetPositionY(), harpoonPos[side].GetPositionZ());
                    init.SetWalk(false);
                    init.Launch();
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_WAVE)
                {
                    wave = data;
                    me->SetSpeed(MOVE_RUN, 2.0f);
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    Movement::MoveSplineInit init(me);
                    for (uint8 i = 1; i < 8; ++i)
                    {
                        G3D::Vector3 point;
                        if (i == 7)
                        {
                            switch (wave)
                            {
                                case 2:
                                    point.x = assaultdrakePos[side][8].GetPositionX();
                                    point.y = assaultdrakePos[side][8].GetPositionY();
                                    point.z = assaultdrakePos[side][8].GetPositionZ();
                                    break;
                                case 3:
                                    point.x = assaultdrakePos[side][9].GetPositionX();
                                    point.y = assaultdrakePos[side][9].GetPositionY();
                                    point.z = assaultdrakePos[side][9].GetPositionZ();
                                    break;
                                default:
                                    point.x = assaultdrakePos[side][i].GetPositionX();
                                    point.y = assaultdrakePos[side][i].GetPositionY();
                                    point.z = assaultdrakePos[side][i].GetPositionZ();
                                    break;
                            }
                        }
                        else
                        {
                            point.x = assaultdrakePos[side][i].GetPositionX();
                            point.y = assaultdrakePos[side][i].GetPositionY();
                            point.z = assaultdrakePos[side][i].GetPositionZ();
                        }
                        init.Path().push_back(point);
                    }
                    init.SetWalk(false);
                    init.Launch();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (!me->HasFlag(UNIT_FIELD_BYTES_1, 0x02)){
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                }

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_ADDS:
                            if (Creature* pBlackhorn = me->FindNearestCreature(NPC_BLACKHORN, 200.0f))
                                pBlackhorn->SummonCreature(((side == 1) ? NPC_TWILIGHT_ELITE_DREADBLADE : NPC_TWILIGHT_ELITE_SLAYER), addsPos[side], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60000);
                            break;
                        case EVENT_TWILIGHT_BARRAGE:
                        {
                            bReady = true;
                            if (!me->isMoving())
                            {
                                uint8 i = (uint8)urand(0, 24);
                                me->CastSpell(damagePos[i].GetPositionX(), damagePos[i].GetPositionY(), damagePos[i].GetPositionZ(), SPELL_TWILIGHT_BARRAGE, false);
                            }
                            events.ScheduleEvent(EVENT_TWILIGHT_BARRAGE, urand(10000, 15000));
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap events;
            uint8 side;
            uint8 wave;
            bool bReady;
        };
};

class npc_warmaster_blackhorn_twilight_elite_dreadblade_slayer: public CreatureScript
{
    public:
        npc_warmaster_blackhorn_twilight_elite_dreadblade_slayer() : CreatureScript("npc_warmaster_blackhorn_twilight_elite_dreadblade_slayer") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_warmaster_blackhorn_twilight_elite_dreadblade_slayerAI(pCreature);
        }

        struct npc_warmaster_blackhorn_twilight_elite_dreadblade_slayerAI : public ScriptedAI
        {
            npc_warmaster_blackhorn_twilight_elite_dreadblade_slayerAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.ScheduleEvent(EVENT_CONTINUE, 1500);
                events.ScheduleEvent(((me->GetEntry() == NPC_TWILIGHT_ELITE_DREADBLADE) ? EVENT_DEGENERATION : EVENT_BRUTAL_STRIKE), urand(8500, 9500));
                events.ScheduleEvent(EVENT_BLADE_RUSH, 20000);
            }

            bool IsBladeRushAffected(WorldObject* pTarget)
            {
                float dist = pTarget->GetExactDist2d(startPos.GetPositionX(), startPos.GetPositionY());
                if ((dist * dist) >= startPos.GetExactDist2dSq(endPos.GetPositionX(), endPos.GetPositionY()))
                    return false;

                float size = pTarget->GetObjectSize() / 2;
                float angle = startPos.GetAngle(&endPos);
                return (size * size) >= pTarget->GetExactDist2dSq(startPos.GetPositionX() + std::cos(angle) * dist, startPos.GetPositionY() + std::sin(angle) * dist);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLADE_RUSH:
                            startPos = me->GetPosition();
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_FARTHEST, 0, 30.0f, true))
                            {
                                endPos = pTarget->GetPosition();
                                DoCast(pTarget, SPELL_BLADE_RUSH);
                            }
                            events.ScheduleEvent(EVENT_BLADE_RUSH, 20000);
                            break;
                        case EVENT_CONTINUE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_DEGENERATION:
                            if (Unit* pTarget = me->GetVictim())
                            {
                                if (Aura* aur = pTarget->GetAura(SPELL_DEGENERATION))
                                    aur->ModStackAmount(1);
                                else
                                    DoCast(pTarget, SPELL_DEGENERATION);
                            }
                            events.ScheduleEvent(EVENT_DEGENERATION, urand(8500, 9500));
                            break;
                        case EVENT_BRUTAL_STRIKE:
                            if (Unit* pTarget = me->GetVictim())
                            {
                                if (Aura* aur = pTarget->GetAura(SPELL_BRUTAL_STRIKE))
                                    aur->ModStackAmount(1);
                                else
                                    DoCast(pTarget, SPELL_BRUTAL_STRIKE);
                            }
                            events.ScheduleEvent(EVENT_BRUTAL_STRIKE, urand(8500, 9500));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
            Position startPos, endPos;

            Unit* SelectAreaTargetRandom(float area)
            {
                int _count = 1;
                int _rand = 1;
                int max = me->GetInstanceScript()->instance->GetPlayers().getSize();
                _rand = irand(1, max);
                std::list<Unit*> _targets;
                me->GetAttackableUnitListInRange(_targets, area);

                for (auto itr : _targets)
                {
                    if (!itr)
                        continue;

                    if (itr->ToPlayer())
                    {
                        if (_rand == _count){
                            return itr;
                        }
                        _count++;
                    }
                }
                return me->SelectNearestPlayer(40.0f);
            }
        };
};

class npc_warmaster_blackhorn_skyfire_harpoon_gun: public CreatureScript
{
    public:
        npc_warmaster_blackhorn_skyfire_harpoon_gun() : CreatureScript("npc_warmaster_blackhorn_skyfire_harpoon_gun") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_warmaster_blackhorn_skyfire_harpoon_gunAI(pCreature);
        }

        struct npc_warmaster_blackhorn_skyfire_harpoon_gunAI : public  Scripted_NoMovementAI
        {
            npc_warmaster_blackhorn_skyfire_harpoon_gunAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                drakeEntry = 0;
            }

            void Reset() override
            {
                drakeEntry = ((me->GetPositionY() < -12130.f) ? NPC_TWILIGHT_ASSAULT_DRAKE_1 : NPC_TWILIGHT_ASSAULT_DRAKE_2);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_HARPOON)
                {
                    if (Creature* drake = FindAssaultDrake(drakeEntry))
                        DoCast(drake, SPELL_HARPOON);

                    events.ScheduleEvent(EVENT_HARPOON_END, (IsHeroic() ? 20000 : 25000));
                }
                else if (action == ACTION_END_BATTLE)
                {
                    me->InterruptNonMeleeSpells(true);
                    events.Reset();
                    EnterEvadeMode();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                switch (uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_HARPOON_END:
                    {
                        ReleaseAssaultDrake(drakeEntry);
                        //DoCast(me, SPELL_RELOADING);
                        break;
                    }
                    default:
                        break;
                }
            }

        private:
            EventMap events;
            uint32 drakeEntry;

            Creature* FindAssaultDrake(uint32 entry)
            {
                std::list<Creature*> creatures;
                me->GetCreatureListWithEntryInGrid(creatures, entry, 200.0f);
                if (!creatures.empty())
                    for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                        if (npc_warmaster_blackhorn_twilight_assault_drake::npc_warmaster_blackhorn_twilight_assault_drakeAI* drakeAI = CAST_AI(npc_warmaster_blackhorn_twilight_assault_drake::npc_warmaster_blackhorn_twilight_assault_drakeAI, (*itr)->GetAI()))
                            if (drakeAI->IsReady() && (*itr)->IsAlive())
                                return (*itr);

                return NULL;
            }

            void ReleaseAssaultDrake(uint32 entry)
            {
                std::list<Creature*> creatures;
                me->GetCreatureListWithEntryInGrid(creatures, entry, 200.0f);
                if (!creatures.empty())
                    for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                        if ((*itr)->HasAura(SPELL_HARPOON, me->GetGUID()))
                            (*itr)->AI()->DoAction(ACTION_HARPOON_END);
            }
        };
};

class npc_warmaster_blackhorn_twilight_infiltrator: public CreatureScript
{
    public:
        npc_warmaster_blackhorn_twilight_infiltrator() : CreatureScript("npc_warmaster_blackhorn_twilight_infiltrator") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_warmaster_blackhorn_twilight_infiltratorAI(pCreature);
        }

        struct npc_warmaster_blackhorn_twilight_infiltratorAI : public ScriptedAI
        {
            npc_warmaster_blackhorn_twilight_infiltratorAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                me->SetSpeed(MOVE_RUN, 2.0f);
                me->SetSpeed(MOVE_FLIGHT, 2.0f);
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                Movement::MoveSplineInit init(me);
                for (uint8 i = 1; i < 12; ++i)
                {
                    G3D::Vector3 point;
                    point.x = infiltratorPos[i].GetPositionX();
                    point.y = infiltratorPos[i].GetPositionY();
                    point.z = infiltratorPos[i].GetPositionZ();
                    init.Path().push_back(point);
                }

                init.SetWalk(false);
                init.Launch();

                events.ScheduleEvent(EVENT_SUMMON_SAPPER, 9000);
                events.ScheduleEvent(EVENT_DESPAWN_INFILTRATOR, 19000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_SAPPER:
                            if (Creature* pBlackhorn = me->FindNearestCreature(NPC_BLACKHORN, 200.0f))
                            {
                                pBlackhorn->AI()->Talk(SAY_SAPPER_YELL);
                                pBlackhorn->SummonCreature(NPC_TWILIGHT_SAPPER, sapperPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000);
                            }
                            break;
                        case EVENT_DESPAWN_INFILTRATOR:
                            me->DespawnOrUnsummon(1000);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap events;
        };
};

class npc_warmaster_blackhorn_twilight_sapper: public CreatureScript
{
    public:
        npc_warmaster_blackhorn_twilight_sapper() : CreatureScript("npc_warmaster_blackhorn_twilight_sapper") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_warmaster_blackhorn_twilight_sapperAI(pCreature);
        }

        struct npc_warmaster_blackhorn_twilight_sapperAI : public ScriptedAI
        {
            npc_warmaster_blackhorn_twilight_sapperAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
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
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.ScheduleEvent(EVENT_SMOKE_BOMB, 500);
                events.ScheduleEvent(EVENT_CONTINUE, 1500);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SMOKE_BOMB:
                            DoCast(me, SPELL_SMOKE_BOMB);
                            //DoCast(me, SPELL_EVADE, true);
                            events.ScheduleEvent(EVENT_SMOKE_BOMB_REMOVE, 2000);
                            break;
                        case EVENT_SMOKE_BOMB_REMOVE:
                            me->RemoveAura(SPELL_SMOKE_BOMB);
                            break;
                        case EVENT_CONTINUE:
                        {
                            if (Creature* pTrigger = me->SummonCreature(WORLD_TRIGGER, sapperPos[1], TEMPSUMMON_TIMED_DESPAWN, 30000))
                                me->GetMotionMaster()->MoveFollow(pTrigger, 0.0f, 0.0f);

                            events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1000);
                            break;
                        }
                        case EVENT_CHECK_PLAYERS:
                            if (me->GetDistance2d(sapperPos[1].GetPositionX(), sapperPos[1].GetPositionY()) <= 4.0f)
                            {
                                DoCastAOE(SPELL_DETONATE);
                                events.ScheduleEvent(EVENT_KILL, 1000);
                            }
                            else
                                events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1000);
                            break;
                        case EVENT_KILL:
                            if (Creature* pSwayze = me->FindNearestCreature(NPC_SKY_CAPTAIN_SWAYZE, 200.0f))
                                pSwayze->AI()->DoAction(ACTION_SAPPER);
                            me->Kill(me, false);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap events;
        };
};

class npc_warmaster_blackhorn_skyfire: public CreatureScript
{
    public:
        npc_warmaster_blackhorn_skyfire() : CreatureScript("npc_warmaster_blackhorn_skyfire") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_warmaster_blackhorn_skyfireAI(pCreature);
        }

        struct npc_warmaster_blackhorn_skyfireAI : public  Scripted_NoMovementAI
        {
            npc_warmaster_blackhorn_skyfireAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                pInstance = me->GetInstanceScript();
                bLowHealth = false;
                me->SetMaxHealth(RAID_MODE(4000000, 10000000, 6000000, 15000000));
                me->SetHealth(RAID_MODE(4000000, 10000000, 6000000, 15000000));
            }

            void DamageTaken(Unit* /*owner*/, uint32 &damage) override
            {
                if (!bLowHealth)
                    if (me->HealthBelowPctDamaged(30, damage))
                    {
                        bLowHealth = true;
                        if (Creature* pSwayze = me->FindNearestCreature(NPC_SKY_CAPTAIN_SWAYZE, 200.0f))
                            pSwayze->AI()->Talk(SAY_SWAYZE_EVENT_5);
                    }
            }

            void JustDied(Unit* /*owner*/) override
            {
                if (Creature* pSwayze = me->FindNearestCreature(NPC_SKY_CAPTAIN_SWAYZE, 200.0f))
                    pSwayze->AI()->DoAction(ACTION_END_BATTLE);

                if (pInstance)
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (pInstance)
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            }

        private:
            InstanceScript* pInstance;
            bool bLowHealth;
        };
};

class npc_dragon_soul_sky_captain_swayze : public CreatureScript
{
    public:
        npc_dragon_soul_sky_captain_swayze() : CreatureScript("npc_dragon_soul_sky_captain_swayze") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
        {
            if (pPlayer->IsInCombat())
                return true;

            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {
                if (pInstance->IsEncounterInProgress())
                    return true;

                if (pInstance->GetBossState(DATA_ULTRAXION) != DONE)
                    return true;

                if (pInstance->instance->IsHeroic() && !pInstance->GetData(DATA_ALL_HEROIC))
                {
                    //pPlayer->GetSession()->SendNotification(LANG_DS_HEROIC_MODE);
                    return true;
                }

                if (pInstance->GetBossState(DATA_BLACKHORN) != DONE &&
                    !pInstance->GetData64(DATA_BLACKHORN))
                {
                    if (pCreature->GetPositionZ() > 200.0f)
                        AddGossipItemFor(pPlayer, 0, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    else
                        AddGossipItemFor(pPlayer, 0, GOSSIP_OPTION_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

                    SendGossipMenuFor(pPlayer, 1, pCreature->GetGUID());

                    return true;
                }
                else if (pInstance->GetBossState(DATA_BLACKHORN) == DONE &&
                    pInstance->GetBossState(DATA_SPINE) != DONE)
                {
                    if (pCreature->GetPositionZ() > 200.0f)
                        AddGossipItemFor(pPlayer, 0, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    else
                        AddGossipItemFor(pPlayer, 0, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

                    SendGossipMenuFor(pPlayer, 1, pCreature->GetGUID());

                    return true;
                }
                else if (pInstance->GetBossState(DATA_SPINE) == DONE)
                {
                    if (pCreature->GetPositionZ() > 200.0f)
                        AddGossipItemFor(pPlayer, 0, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    else
                        AddGossipItemFor(pPlayer, 0, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

                    SendGossipMenuFor(pPlayer, 1, pCreature->GetGUID());

                    return true;
                }
            }
            return false;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*sender*/, uint32 action) override
        {
            pPlayer->PlayerTalkClass->SendCloseGossip();

            if (pPlayer->IsInCombat())
                return true;

            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {

                if (pInstance->IsEncounterInProgress())
                    return true;

                if (pInstance->GetBossState(DATA_ULTRAXION) != DONE)
                    return true;

                if (pInstance->instance->IsHeroic() && !pInstance->GetData(DATA_ALL_HEROIC))
                {
                    //pPlayer->GetSession()->SendNotification(LANG_DS_HEROIC_MODE);
                    return true;
                }

                if (pInstance->GetBossState(DATA_BLACKHORN) != DONE &&
                    !pInstance->GetData64(DATA_BLACKHORN))
                {
                    if (action == GOSSIP_ACTION_INFO_DEF + 1)
                    {
                        Map::PlayerList const &plrList = pInstance->instance->GetPlayers();

                        if (!plrList.isEmpty())
                            for (Map::PlayerList::const_iterator i = plrList.begin(); i != plrList.end(); ++i)
                                if (Player* pPlayer = i->GetSource())
                                    if (pCreature->GetDistance(pPlayer) <= 100.0f)
                                        pPlayer->NearTeleportTo(skyfirePos.GetPositionX(), skyfirePos.GetPositionY(), skyfirePos.GetPositionZ(), skyfirePos.GetOrientation());

                    }
                    else if (action == GOSSIP_ACTION_INFO_DEF + 2)
                    {
                        pCreature->SummonCreature(NPC_GORIONA, gorionaPos[0]);
                        pCreature->SummonCreature(NPC_BLACKHORN, blackhornPos);
                        pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        pCreature->AI()->DoAction(ACTION_START);
                    }
                }
                else if (pInstance->GetBossState(DATA_BLACKHORN) == DONE &&
                    pInstance->GetBossState(DATA_SPINE) != DONE)
                {
                    if (action == GOSSIP_ACTION_INFO_DEF + 1)
                    {
                        Map::PlayerList const &plrList = pInstance->instance->GetPlayers();

                        if (!plrList.isEmpty())
                            for (Map::PlayerList::const_iterator i = plrList.begin(); i != plrList.end(); ++i)
                                if (Player* pPlayer = i->GetSource())
                                    if (pCreature->GetDistance(pPlayer) <= 100.0f)
                                        pPlayer->NearTeleportTo(skyfirePos.GetPositionX(), skyfirePos.GetPositionY(), skyfirePos.GetPositionZ(), skyfirePos.GetOrientation());

                    }
                    else if (action == GOSSIP_ACTION_INFO_DEF + 3)
                    {
                        pInstance->SetBossState(DATA_SPINE, IN_PROGRESS);

                        if (Creature* pDeathwing = pCreature->SummonCreature(NPC_SPINE_OF_DEATHWING, spinedeathwingPos))
                            pDeathwing->AI()->DoAction(1); // ACTION_START_BATTLE

                        Map::PlayerList const &plrList = pInstance->instance->GetPlayers();
                        if (!plrList.isEmpty())
                            for (Map::PlayerList::const_iterator i = plrList.begin(); i != plrList.end(); ++i)
                                if (Player* pPlayer = i->GetSource())
                                    if (pCreature->GetDistance(pPlayer) <= 100.0f)
                                    {
                                        pPlayer->SendMovieStart(74);
                                        pPlayer->CastSpell(pPlayer, SPELL_PARACHUTE, true);
                                        pPlayer->NearTeleportTo(teleportPos[5].GetPositionX() + frand(-2.f, 2.f), teleportPos[5].GetPositionY() + frand(-2.f, 2.f), teleportPos[5].GetPositionZ(), teleportPos[5].GetOrientation());
                                    }
                    }
                }
                else if (pInstance->GetBossState(DATA_SPINE) == DONE)
                {
                    if (action == GOSSIP_ACTION_INFO_DEF + 1)
                    {
                        Map::PlayerList const &plrList = pInstance->instance->GetPlayers();

                        if (!plrList.isEmpty())
                            for (Map::PlayerList::const_iterator i = plrList.begin(); i != plrList.end(); ++i)
                                if (Player* pPlayer = i->GetSource())
                                    if (pCreature->GetDistance(pPlayer) <= 100.0f)
                                        pPlayer->NearTeleportTo(skyfirePos.GetPositionX(), skyfirePos.GetPositionY(), skyfirePos.GetPositionZ(), skyfirePos.GetOrientation());

                    }
                    else if (action == GOSSIP_ACTION_INFO_DEF + 4)
                    {
                        pInstance->DoNearTeleportPlayers(madnessdeathwingPos);
                    }
                }
            }
            return true;
        }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_sky_captain_swayzeAI(pCreature);
        }

        struct npc_dragon_soul_sky_captain_swayzeAI : public ScriptedAI
        {
            npc_dragon_soul_sky_captain_swayzeAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                events.Reset();
                me->SetReactState(REACT_PASSIVE);
                me->setActive(true);
                bSapper = false;
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_START)
                {
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
                    events.ScheduleEvent(EVENT_INTRO_1, 3000);
                }
                else if (action == ACTION_END_BATTLE)
                {
                    Talk(SAY_SWAYZE_EVENT_6);
                    events.ScheduleEvent(EVENT_END_BATTLE, 5000);
                }
                else if (action == ACTION_SAPPER)
                {
                    if (!bSapper)
                    {
                        bSapper = true;
                        Talk(SAY_SWAYZE_EVENT_4);
                    }
                }
                else if (action == ACTION_BLACKHORN_DIED)
                {
                    events.Reset();
                    summons.DespawnEntry(NPC_ENGINE_STALKER);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_END_BATTLE:
                            if (Creature* pTrigger = me->SummonCreature(NPC_MASSIVE_EXPLOSION, skyfirePos, TEMPSUMMON_TIMED_DESPAWN, 5000))
                                pTrigger->CastSpell(pTrigger, SPELL_MASSIVE_EXPLOSION);
                            events.Reset();
                            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            if (Creature* pBlackhorn = me->FindNearestCreature(NPC_BLACKHORN, 300.0f))
                                pBlackhorn->AI()->DoAction(ACTION_END_BATTLE);
                            summons.DespawnEntry(NPC_ENGINE_STALKER);
                            summons.DespawnEntry(NPC_SKYFIRE);
                            bSapper = false;
                            break;
                        case EVENT_CHECK_PLAYERS:
                        {
                            if (!CheckPlayers())
                            {
                                events.Reset();
                                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                if (Creature* pBlackhorn = me->FindNearestCreature(NPC_BLACKHORN, 300.0f))
                                    pBlackhorn->AI()->DoAction(ACTION_END_BATTLE);
                                summons.DespawnEntry(NPC_ENGINE_STALKER);
                                summons.DespawnEntry(NPC_SKYFIRE);
                                bSapper = false;
                            }
                            else
                                events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
                            break;
                        }
                        case EVENT_INTRO_1:
                            me->SummonCreature(NPC_SKYFIRE, skyfirePos);
                            Talk(SAY_SWAYZE_EVENT_1);
                            events.ScheduleEvent(EVENT_INTRO_2, 7000);
                            break;
                        case EVENT_INTRO_2:
                            if (Creature* pBlackhorn = me->FindNearestCreature(NPC_BLACKHORN, 300.0f))
                                pBlackhorn->AI()->Talk(SAY_INTRO);
                            events.ScheduleEvent(EVENT_INTRO_3, 8000);
                            break;
                        case EVENT_INTRO_3:
                            Talk(SAY_SWAYZE_PRE_2);
                            for (uint8 i = 0; i < 8; ++i)
                                me->SummonCreature(NPC_ENGINE_STALKER, enginePos[i]);
                            events.ScheduleEvent(EVENT_INTRO_4, 5000);
                            break;
                        case EVENT_INTRO_4:
                            if (Creature* pBlackhorn = me->FindNearestCreature(NPC_BLACKHORN, 300.0f))
                                pBlackhorn->AI()->DoAction(ACTION_START_BATTLE);
                            events.ScheduleEvent(EVENT_INTRO_5, 7000);
                            break;
                        case EVENT_INTRO_5:
                            Talk(SAY_SWAYZE_EVENT_2);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap events;
            SummonList summons;
            bool bSapper;

            bool CheckPlayers()
            {
                Player* player = NULL;
                AnyLivePlayerNoGmCheck check(me, 200.0f);
                Trinity::PlayerSearcher<AnyLivePlayerNoGmCheck> searcher(me, player, check);
                Cell::VisitWorldObjects(me, searcher, 200.0f);
                return (player ? true : false);
            }

            class AnyLivePlayerNoGmCheck
            {
                public:
                    AnyLivePlayerNoGmCheck(WorldObject const* obj, float range) : _obj(obj), _range(range) {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (!_obj->IsWithinDistInMap(u, _range))
                            return false;

                        if (u->IsGameMaster())
                            return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _range;
            };
        };
};

class spell_warmaster_blackhorn_twilight_barrage_dmg : public SpellScriptLoader
{
    public:
        spell_warmaster_blackhorn_twilight_barrage_dmg() : SpellScriptLoader("spell_warmaster_blackhorn_twilight_barrage_dmg") { }

        class spell_warmaster_blackhorn_twilight_barrage_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warmaster_blackhorn_twilight_barrage_dmg_SpellScript);

            void FilterTargetsDamage(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                {
                    if (Creature* pBlackhorn = GetCaster()->FindNearestCreature(NPC_BLACKHORN, 300.0f))
                        pBlackhorn->AI()->DoAction(ACTION_DECK);

                    if (Creature* pShip = GetCaster()->FindNearestCreature(NPC_SKYFIRE, 300.0f))
                    {
                        int32 bp0 = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
                        bp0 *= 1.5f;
                        GetCaster()->CastCustomSpell(pShip, SPELL_TWILIGHT_BARRAGE_DMG_2, &bp0, NULL, NULL, true);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warmaster_blackhorn_twilight_barrage_dmg_SpellScript::FilterTargetsDamage, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warmaster_blackhorn_twilight_barrage_dmg_SpellScript();
        }
};

class spell_warmaster_blackhorn_twilight_onslaught_dmg : public SpellScriptLoader
{
    public:
        spell_warmaster_blackhorn_twilight_onslaught_dmg() : SpellScriptLoader("spell_warmaster_blackhorn_twilight_onslaught_dmg") { }

        class spell_warmaster_blackhorn_twilight_onslaught_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warmaster_blackhorn_twilight_onslaught_dmg_SpellScript);

            void FilterTargetsDamage(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (Creature* pShip = GetCaster()->FindNearestCreature(NPC_SKYFIRE, 300.0f))
                {
                    int32 bp0 = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
                    bp0 /= targets.size() + 1;
                    GetCaster()->CastCustomSpell(pShip, SPELL_TWILIGHT_ONSLAUGHT_DMG_2, &bp0, NULL, NULL, true);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warmaster_blackhorn_twilight_onslaught_dmg_SpellScript::FilterTargetsDamage, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warmaster_blackhorn_twilight_onslaught_dmg_SpellScript();
        }
};

class spell_warmaster_blackhorn_blade_rush_dmg : public SpellScriptLoader
{
    public:
        spell_warmaster_blackhorn_blade_rush_dmg() : SpellScriptLoader("spell_warmaster_blackhorn_blade_rush_dmg") { }

        class spell_warmaster_blackhorn_blade_rush_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warmaster_blackhorn_blade_rush_dmg_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (Creature* pDreadblade = GetCaster()->ToCreature())
                    targets.remove_if(TargetCheck(pDreadblade));

            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warmaster_blackhorn_blade_rush_dmg_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            class TargetCheck
            {
                public:
                    TargetCheck(Creature* owner) : _owner(owner) {}

                    bool operator()(WorldObject* unit)
                    {
                        if (unit->GetTypeId() != TYPEID_PLAYER)
                            return true;

                        if (npc_warmaster_blackhorn_twilight_elite_dreadblade_slayer::npc_warmaster_blackhorn_twilight_elite_dreadblade_slayerAI* dreadbladeAI = CAST_AI(npc_warmaster_blackhorn_twilight_elite_dreadblade_slayer::npc_warmaster_blackhorn_twilight_elite_dreadblade_slayerAI, _owner->GetAI()))
                            if (dreadbladeAI->IsBladeRushAffected(unit))
                                return false;

                        return true;
                    }

            private:
                Creature* _owner;
            };
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warmaster_blackhorn_blade_rush_dmg_SpellScript();
        }
};

class spell_warmaster_blackhorn_consuming_shroud : public SpellScriptLoader
{
    public:
        spell_warmaster_blackhorn_consuming_shroud() : SpellScriptLoader("spell_warmaster_blackhorn_consuming_shroud") { }

        class spell_warmaster_blackhorn_consuming_shroud_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warmaster_blackhorn_consuming_shroud_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.size() > 2)
                {
                    if (Creature* pBlackhorn = GetCaster()->FindNearestCreature(NPC_BLACKHORN, 300.0f))
                        if (Unit* victim = pBlackhorn->GetVictim())
                            targets.remove(victim);

                    if (Creature* pGoriona = GetCaster()->ToCreature())
                        if (Unit* victim = pGoriona->GetVictim())
                            targets.remove(victim);
                }

                if (targets.size() > 1)
                    Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warmaster_blackhorn_consuming_shroud_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        class spell_warmaster_blackhorn_consuming_shroud_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warmaster_blackhorn_consuming_shroud_AuraScript);

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                if (removeMode == AURA_REMOVE_BY_DEATH)
                    if (GetTarget())
                    {
                        int32 bp0 = aurEff->GetAmount();
                        GetTarget()->CastCustomSpell((Unit*)NULL, SPELL_CONSUMING_SHROUD_DMG, &bp0, NULL, NULL, true);
                    }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_warmaster_blackhorn_consuming_shroud_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warmaster_blackhorn_consuming_shroud_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_warmaster_blackhorn_consuming_shroud_AuraScript();
        }
};

class spell_warmaster_blackhorn_vengeance : public SpellScriptLoader
{
    public:
        spell_warmaster_blackhorn_vengeance() : SpellScriptLoader("spell_warmaster_blackhorn_vengeance") { }

        class spell_warmaster_blackhorn_vengeance_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warmaster_blackhorn_vengeance_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetUnitOwner())
                    return;

                uint32 val = int32(100.0f - GetUnitOwner()->GetHealthPct());

                if (AuraEffect* aurEff = GetAura()->GetEffect(EFFECT_0))
                    aurEff->SetAmount(val);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_warmaster_blackhorn_vengeance_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warmaster_blackhorn_vengeance_AuraScript();
        }
};

class spell_warmaster_blackhorn_shockwave_aoe : public SpellScriptLoader
{
    public:
        spell_warmaster_blackhorn_shockwave_aoe() : SpellScriptLoader("spell_warmaster_blackhorn_shockwave_aoe") { }

        class spell_warmaster_blackhorn_shockwave_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warmaster_blackhorn_shockwave_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                std::list<WorldObject*> new_targets;
                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if (GetCaster()->GetDistance((*itr)) >= 15.0f)
                        new_targets.push_back((*itr));

                if (new_targets.size() >=2)
                {
                    targets.clear();
                    targets.push_back(Trinity::Containers::SelectRandomContainerElement(new_targets));
                }
                else
                    Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleDummy (SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Unit* pTarget = GetHitUnit())
                GetCaster()->CastSpell(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), SPELL_SHOCKWAVE, false);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warmaster_blackhorn_shockwave_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_warmaster_blackhorn_shockwave_aoe_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warmaster_blackhorn_shockwave_aoe_SpellScript();
        }
};


class spell_warmaster_blackhorn_broadside : public SpellScriptLoader
{
    public:
        spell_warmaster_blackhorn_broadside() : SpellScriptLoader("spell_warmaster_blackhorn_broadside") { }

        class spell_warmaster_blackhorn_broadside_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warmaster_blackhorn_broadside_SpellScript);

            void HandleAfterCast()
            {
                if (!GetCaster())
                    return;

                if (Creature* pShip = GetCaster()->FindNearestCreature(NPC_SKYFIRE, 300.0f))
                {
                    int32 bp0 = pShip->CountPctFromCurHealth(20);
                    GetCaster()->CastCustomSpell(pShip, SPELL_BROADSIDE_DMG, &bp0, NULL, NULL, true);
                }
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_warmaster_blackhorn_broadside_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warmaster_blackhorn_broadside_SpellScript();
        }
};

typedef boss_warmaster_blackhorn::boss_warmaster_blackhornAI BlackhornAI;

class achievement_deck_defender : public AchievementCriteriaScript
{
    public:
        achievement_deck_defender() : AchievementCriteriaScript("achievement_deck_defender") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (BlackhornAI* blackhornAI = CAST_AI(BlackhornAI, target->GetAI()))
                return blackhornAI->AllowAchieve();

            return false;
        }
};

void AddSC_boss_warmaster_blackhorn()
{
    new boss_warmaster_blackhorn();
    new npc_warmaster_blackhorn_goriona();
    new npc_warmaster_blackhorn_twilight_assault_drake();
    new npc_warmaster_blackhorn_twilight_elite_dreadblade_slayer();
    new npc_warmaster_blackhorn_skyfire_harpoon_gun();
    new npc_warmaster_blackhorn_twilight_infiltrator();
    new npc_warmaster_blackhorn_twilight_sapper();
    new npc_warmaster_blackhorn_skyfire();
    new npc_dragon_soul_sky_captain_swayze();
    new spell_warmaster_blackhorn_twilight_barrage_dmg();
    new spell_warmaster_blackhorn_twilight_onslaught_dmg();
    new spell_warmaster_blackhorn_blade_rush_dmg();
    new spell_warmaster_blackhorn_consuming_shroud();
    new spell_warmaster_blackhorn_vengeance();
    new spell_warmaster_blackhorn_shockwave_aoe();
    new spell_warmaster_blackhorn_broadside();
    new achievement_deck_defender();
};
