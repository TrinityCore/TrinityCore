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

#include "ScriptMgr.h"
#include "deadmines.h"
#include "InstanceScript.h"
#include "GridNotifiers.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "SpellScript.h"

enum Texts
{
    // Vanessa VanCleef
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_SUMMON_DEFIAS_REINFORCEMENT = 2,
    SAY_DETONATION_1                = 3,
    SAY_ANNOUNCE_DETONATION_1       = 4,
    SAY_DETONATION_2                = 5,
    SAY_ANNOUNCE_DETONATION_2       = 6,
    SAY_SUICIDE_1                   = 7,
    SAY_SUICIDE_2                   = 8,
    SAY_ANNOUNCE_POWDER_EXPLOSION   = 9,
    SAY_DEATH                       = 10,

    // Vanessa VanCleef Intro
    SAY_ANNOUNCE_NOISE_FROM_ABOVE   = 0,
    SAY_INTRO_1                     = 1,
    SAY_INTRO_2                     = 2,
    SAY_INTRO_3                     = 3,
    SAY_INTRO_4                     = 4,
    SAY_INTRO_5                     = 5,
    SAY_ANNOUNCE_NIGHTMARE_ELIXIR   = 6,

    // A Note from Vanessa VanCleef
    SAY_ANNOUNCE_NOTE_ON_THE_GROUND = 0,
};

enum Spells
{
    // Vanessa VanCleef
    SPELL_VANESSA_ACHIEVEMENT_SPELL     = 95654,
    SPELL_CLEAR_ALL_DEBUFFS             = 34098,
    SPELL_DEFLECTION                    = 92614,
    SPELL_DEADLY_BLADES                 = 92622,
    SPELL_BACKSLASH                     = 92619,
    SPELL_SUMMON_ENFORCER               = 92616,
    SPELL_SUMMON_SHADOWGUARD            = 92618,
    SPELL_SUMMON_BLOOD_WIZARD           = 92617,
    SPELL_VENGEANCE_OF_VANCLEEF         = 95542,
    SPELL_VANESSA_COSMETIC_BOMB_STATE   = 96280,
    SPELL_POWDER_EXPLOSION              = 96283,

    // General Purpose Bunny JMF
    SPELL_FIERY_BLAZE                   = 93484,

    // Vanessa VanCleef Nightmare
    SPELL_SITTING                       = 89279,
    SPELL_NOXIOUS_CONCOCTION            = 92100,
    SPELL_NIGHTMARE_ELIXIR              = 92113,
    SPELL_VANESSAS_BLACKOUT_AURA        = 92120
};

enum Events
{
    // Vanessa VanCleef
    EVENT_DEFLECTION = 1,
    EVENT_DEADLY_BLADES,
    EVENT_SUMMON_DEFIAS_REINFORCEMENT,
    EVENT_TALK_SUMMON_REINFORCEMENT,
    EVENT_SUMMON_ENTRANCE_FIRE,
    EVENT_FACE_TO_DECK,
    EVENT_TALK_DETONATION,
    EVENT_ANNOUNCE_DETONATION,
    EVENT_SUMMON_DETONATION_FIRE,
    EVENT_CAST_FIERY_BLAZE,
    EVENT_SUMMON_ROPES,
    EVENT_EXTINGUISH_FIRES,
    EVENT_FACE_TO_ROPES,
    EVENT_VENGEANCE_OF_VANCLEEF,
    EVENT_TALK_SUICIDE_1,
    EVENT_COSMETIC_BOMB_STATE,
    EVENT_TALK_SUICIDE_2,
    EVENT_ANNOUNCE_POWDER_EXPLSION,
    EVENT_TALK_LAST_WORDS,
    EVENT_POWDER_EXPLOSION,

    // Vanessa VanCleef Intro
    EVENT_ANNOUNCE_NOISE_FROM_ABOVE,
    EVENT_TALK_INTRO_1,
    EVENT_JUMP_ON_DECK,
    EVENT_MOVE_TO_INTRO_POS,
    EVENT_TALK_INTRO_2,
    EVENT_TALK_INTRO_3,
    EVENT_FACE_TO_PLAYERS,
    EVENT_TALK_INTRO_4,
    EVENT_NOXIOUS_CONCOCTION,
    EVENT_TALK_INTRO_5,
    EVENT_NIGHTMARE_ELIXIR,
    EVENT_ANNOUNCE_NIGHTMARE_ELIXIR,
    EVENT_LAUGH,
    EVENT_SETUP_NIGHTMARE,
    EVENT_MAGMA_TRAP,

    // A Note from Vanessa VanCleef
    EVENT_TALK_NOTE_FALLS_TO_THE_GROUND,

    // Rope
    EVENT_START_SWING,
    EVENT_DESPAWN
};

enum ModelIds
{
    MODEL_ID_INVISIBLE = 11686
};

enum DefiasReinforcements
{
    REINFORCEMENT_ENFORCER      = 0,
    REINFORCEMENT_SHADOWGUARD   = 1,
    REINFORCEMENT_BLOOD_WIZARD  = 2
};

uint32 defiasReinforcementSpells[] =
{
    SPELL_SUMMON_ENFORCER,
    SPELL_SUMMON_SHADOWGUARD,
    SPELL_SUMMON_BLOOD_WIZARD
};

Position const defiasReinforcementPositions[] =
{
    { -79.9097f, -824.49f, 39.7954f },
    { -79.8455f, -815.483f, 39.7768f },
    { -87.2257f, -819.66f, 39.2205f }
};

Position const vanessaIntroJumpPos = { -64.5677f,  -820.161f,  41.123f   };
Position const vanessaIntroWalkPos = { -65.30209f, -838.0382f, 41.11562f };
Position const vanessaDetonationJumpPos = { -53.09028f, -819.5538f, 51.42455f };
Position const vanessaAfterDetonationJumpPos = { -66.64063f, -815.1962f, 40.94127f };


class boss_vanessa_van_cleef : public CreatureScript
{
    public:
        boss_vanessa_van_cleef() : CreatureScript("boss_vanessa_van_cleef") { }

        struct boss_vanessa_van_cleefAI : public BossAI
        {
            boss_vanessa_van_cleefAI(Creature* creature) : BossAI(creature, DATA_VANESSA_VAN_CLEEF)
            {
                Initialize();
            }

            void Initialize()
            {
                _currentReinforcement = REINFORCEMENT_ENFORCER;
                _detonationCounter = 0;
                _talkReinforcement = false;
                _prepareForReEngage = false;
                _allowDeath = false;
            }

            void Reset() override
            {
                Initialize();
                _extinguishableFlamesGuidSet.clear();
                _nightmareFlamesGuidSet.clear();
                _Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(SAY_AGGRO);
                DoCastAOE(SPELL_VANESSA_ACHIEVEMENT_SPELL, true);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_DEFLECTION, Seconds(11));
                events.ScheduleEvent(EVENT_DEADLY_BLADES, Seconds(12));
                events.ScheduleEvent(EVENT_SUMMON_ENTRANCE_FIRE, Seconds(12) + Milliseconds(500));
                events.ScheduleEvent(EVENT_SUMMON_DEFIAS_REINFORCEMENT, Seconds(14) + Milliseconds(500));

            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_VANESSA_VAN_CLEEF, FAIL);
                _DespawnAtEvade();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth() && !_allowDeath)
                    damage = me->GetHealth() - 1;

                if ((me->HealthBelowPct(50) && _detonationCounter == 0)
                    || (me->HealthBelowPct(25) && _detonationCounter == 1))
                {
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAurasDueToSpell(SPELL_DEADLY_BLADES);
                    events.Reset();
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS, true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    float distance = me->GetDistance(vanessaDetonationJumpPos);
                    me->GetMotionMaster()->MoveJump(vanessaDetonationJumpPos, distance, 27.96389f);
                    events.ScheduleEvent(EVENT_FACE_TO_DECK, Seconds(1) + Milliseconds(200));
                    _detonationCounter++;
                }
                else if (me->GetHealthPct() <= 1.0f && _detonationCounter == 2)
                {
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAurasDueToSpell(SPELL_DEADLY_BLADES);
                    events.Reset();
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS, true);
                    events.ScheduleEvent(EVENT_TALK_SUICIDE_1, Milliseconds(200));
                    _detonationCounter++;
                }

                if (_prepareForReEngage)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    _prepareForReEngage = false;
                    if (_detonationCounter == 1)
                        events.CancelEvent(EVENT_VENGEANCE_OF_VANCLEEF);

                    events.ScheduleEvent(EVENT_DEFLECTION, Milliseconds(400));
                    events.ScheduleEvent(EVENT_DEADLY_BLADES, Seconds(5) + Milliseconds(200));
                }
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() != NPC_ROPE
                    && summon->GetEntry() != NPC_GENERAL_PURPOSE_DUMMY_JMF
                    && summon->GetEntry() != NPC_GLUBTOK_NIGHTMARE_FIRE_BUNNY)
                    BossAI::JustSummoned(summon);
                else
                    summons.Summon(summon);

                switch (summon->GetEntry())
                {
                    case NPC_GENERAL_PURPOSE_DUMMY_JMF:
                        summon->CastSpell(summon, SPELL_FIERY_BLAZE, true);
                        break;
                    case NPC_GLUBTOK_NIGHTMARE_FIRE_BUNNY:
                        _nightmareFlamesGuidSet.insert(summon->GetGUID());
                        break;
                    default:
                        break;
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
                        case EVENT_DEFLECTION:
                            if (me->HealthAbovePct(25))
                                DoCastSelf(SPELL_DEFLECTION);
                            break;
                        case EVENT_DEADLY_BLADES:
                            DoCastSelf(SPELL_DEADLY_BLADES);
                            break;
                        case EVENT_SUMMON_DEFIAS_REINFORCEMENT:
                        {
                            if (me->HealthAbovePct(50))
                            {
                                if (!_talkReinforcement)
                                {
                                    events.ScheduleEvent(EVENT_TALK_SUMMON_REINFORCEMENT, Milliseconds(200));
                                    _talkReinforcement = true;
                                }

                                float x = defiasReinforcementPositions[_currentReinforcement].m_positionX;
                                float y = defiasReinforcementPositions[_currentReinforcement].m_positionY;
                                float z = defiasReinforcementPositions[_currentReinforcement].m_positionZ;

                                me->CastSpell({ x, y, z }, defiasReinforcementSpells[_currentReinforcement], true);
                                _currentReinforcement++;

                                if (_currentReinforcement == REINFORCEMENT_BLOOD_WIZARD)
                                    _currentReinforcement = REINFORCEMENT_ENFORCER;

                                events.Repeat(Seconds(10));
                            }
                            break;
                        }
                        case EVENT_TALK_SUMMON_REINFORCEMENT:
                            Talk(SAY_SUMMON_DEFIAS_REINFORCEMENT);
                            break;
                        case EVENT_SUMMON_ENTRANCE_FIRE:
                            for (uint8 i = 0; i < 6; i++)
                                DoSummon(NPC_GENERAL_PURPOSE_DUMMY_JMF, VanessaEntranceFirePos[i], 0, TEMPSUMMON_MANUAL_DESPAWN);
                            break;
                        case EVENT_FACE_TO_DECK:
                            me->SetFacingTo(2.932153f);
                            events.ScheduleEvent(EVENT_TALK_DETONATION, Milliseconds(200));
                            break;
                        case EVENT_TALK_DETONATION:
                            if (_detonationCounter == 1)
                                Talk(SAY_DETONATION_1);
                            else if (_detonationCounter == 2)
                                Talk(SAY_DETONATION_2);

                            events.ScheduleEvent(EVENT_ANNOUNCE_DETONATION, Seconds(3) + Milliseconds(600));
                            break;
                        case EVENT_ANNOUNCE_DETONATION:
                            if (_detonationCounter == 1)
                                Talk(SAY_ANNOUNCE_DETONATION_1);
                            else if (_detonationCounter == 2)
                                Talk(SAY_ANNOUNCE_DETONATION_2);

                            events.ScheduleEvent(EVENT_SUMMON_DETONATION_FIRE, Milliseconds(600));
                            events.ScheduleEvent(EVENT_SUMMON_ROPES, Milliseconds(700));
                            break;
                        case EVENT_SUMMON_DETONATION_FIRE:
                            for (uint8 i = 0; i < 65; i++)
                            {
                                if (Creature* dummy = DoSummon(NPC_GLUBTOK_NIGHTMARE_FIRE_BUNNY, VanessaNightmareFirePos[i], 0, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    // Remove the default aura that has been set in creature_template_addon as it is not used here
                                    dummy->RemoveAllAuras();

                                    // Blizzard uses some specific orientations to decide which fires may get extinguished
                                    if (VanessaNightmareFirePos[i].GetOrientation() == 2.75762f || VanessaNightmareFirePos[i].GetOrientation() == 3.193953f)
                                    _extinguishableFlamesGuidSet.insert(dummy->GetGUID());
                                }
                            }
                            events.ScheduleEvent(EVENT_CAST_FIERY_BLAZE, Seconds(4) + Milliseconds(800));
                            events.ScheduleEvent(EVENT_EXTINGUISH_FIRES, Seconds(11));
                            break;
                        case EVENT_SUMMON_ROPES:
                            instance->SetData(DATA_SUMMON_ROPES, 0);
                            break;
                        case EVENT_CAST_FIERY_BLAZE:
                            if (_detonationCounter == 1)
                            {
                                for (auto itr = _nightmareFlamesGuidSet.begin(); itr != _nightmareFlamesGuidSet.end(); itr++)
                                    if (Creature* dummy = ObjectAccessor::GetCreature(*me, (*itr)))
                                        dummy->CastSpell(dummy, SPELL_FIERY_BLAZE);
                            }
                            else
                            {
                                for (auto itr = _extinguishableFlamesGuidSet.begin(); itr != _extinguishableFlamesGuidSet.end(); itr++)
                                    if (Creature* dummy = ObjectAccessor::GetCreature(*me, (*itr)))
                                        dummy->CastSpell(dummy, SPELL_FIERY_BLAZE);
                            }
                            break;
                        case EVENT_EXTINGUISH_FIRES:
                            for (auto itr = _extinguishableFlamesGuidSet.begin(); itr != _extinguishableFlamesGuidSet.end(); itr++)
                                if (Creature* dummy = ObjectAccessor::GetCreature(*me, (*itr)))
                                    dummy->RemoveAllAuras();
                            events.ScheduleEvent(EVENT_JUMP_ON_DECK, Seconds(3) + Milliseconds(200));
                            break;
                        case EVENT_JUMP_ON_DECK:
                            me->GetMotionMaster()->MoveJump(vanessaAfterDetonationJumpPos, me->GetDistance(vanessaAfterDetonationJumpPos), 32.75936f);
                            events.ScheduleEvent(EVENT_FACE_TO_ROPES, Seconds(1) + Milliseconds(200));
                            break;
                        case EVENT_FACE_TO_ROPES:
                            me->SetFacingTo(4.642576f);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            _prepareForReEngage = true;
                            events.ScheduleEvent(EVENT_VENGEANCE_OF_VANCLEEF, Seconds(1) + Milliseconds(200));
                            break;
                        case EVENT_VENGEANCE_OF_VANCLEEF:
                            DoCastSelf(SPELL_VENGEANCE_OF_VANCLEEF);
                            events.Repeat(Seconds(2) + Milliseconds(400));
                            break;
                        case EVENT_TALK_SUICIDE_1:
                            Talk(SAY_SUICIDE_1);
                            events.ScheduleEvent(EVENT_COSMETIC_BOMB_STATE, Seconds(4) + Milliseconds(600));
                            break;
                        case EVENT_COSMETIC_BOMB_STATE:
                            DoCastSelf(SPELL_VANESSA_COSMETIC_BOMB_STATE);
                            events.ScheduleEvent(EVENT_TALK_SUICIDE_2, Milliseconds(200));
                            break;
                        case EVENT_TALK_SUICIDE_2:
                            Talk(SAY_SUICIDE_2);
                            events.ScheduleEvent(EVENT_ANNOUNCE_POWDER_EXPLSION, Seconds(2) + Milliseconds(400));
                            break;
                        case EVENT_ANNOUNCE_POWDER_EXPLSION:
                            Talk(SAY_ANNOUNCE_POWDER_EXPLOSION);
                            events.ScheduleEvent(EVENT_TALK_LAST_WORDS, Seconds(3) + Milliseconds(500));
                            break;
                        case EVENT_TALK_LAST_WORDS:
                            Talk(SAY_DEATH);
                            events.ScheduleEvent(EVENT_POWDER_EXPLOSION, Seconds(1) + Milliseconds(100));
                            break;
                        case EVENT_POWDER_EXPLOSION:
                            _allowDeath = true;
                            DoCastAOE(SPELL_POWDER_EXPLOSION);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            uint8 _currentReinforcement;
            uint8 _detonationCounter;
            GuidSet _nightmareFlamesGuidSet;
            GuidSet _extinguishableFlamesGuidSet;
            bool _talkReinforcement;
            bool _prepareForReEngage;
            bool _allowDeath;
        };

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetDeadminesAI<boss_vanessa_van_cleefAI>(creature);
        }
};

class npc_vanessa_vanessa_van_cleef : public CreatureScript
{
    public:
        npc_vanessa_vanessa_van_cleef() : CreatureScript("npc_vanessa_vanessa_van_cleef") { }

        struct npc_vanessa_vanessa_van_cleefAI : public ScriptedAI
        {
            npc_vanessa_vanessa_van_cleefAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                _instance->SetBossState(DATA_VANESSA_VAN_CLEEF, IN_PROGRESS);
                _events.ScheduleEvent(EVENT_ANNOUNCE_NOISE_FROM_ABOVE, Seconds(2) + Milliseconds(500));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ANNOUNCE_NOISE_FROM_ABOVE:
                            Talk(SAY_ANNOUNCE_NOISE_FROM_ABOVE);
                            _events.ScheduleEvent(EVENT_TALK_INTRO_1, Seconds(3) + Milliseconds(500));
                            break;
                        case EVENT_TALK_INTRO_1:
                            Talk(SAY_INTRO_1);
                            _events.ScheduleEvent(EVENT_JUMP_ON_DECK, Seconds(2));
                            break;
                        case EVENT_JUMP_ON_DECK:
                            me->RemoveAurasDueToSpell(SPELL_SITTING);
                            me->GetMotionMaster()->MoveJump(vanessaIntroJumpPos, 10.0f, 16.31084f);
                            _events.ScheduleEvent(EVENT_MOVE_TO_INTRO_POS, Seconds(8) + Milliseconds(400));
                            break;
                        case EVENT_MOVE_TO_INTRO_POS:
                        {
                            Movement::MoveSplineInit init(me);
                            init.SetWalk(true);
                            init.MoveTo(vanessaIntroWalkPos.GetPositionX(), vanessaIntroWalkPos.GetPositionY(), vanessaIntroWalkPos.GetPositionZ(), true);
                            init.Launch();
                            _events.ScheduleEvent(EVENT_TALK_INTRO_2, Milliseconds(200));
                            break;
                        }
                        case EVENT_TALK_INTRO_2:
                            Talk(SAY_INTRO_2);
                            _events.ScheduleEvent(EVENT_TALK_INTRO_3, Seconds(9) + Milliseconds(700));
                            break;
                        case EVENT_TALK_INTRO_3:
                            Talk(SAY_INTRO_3);
                            _events.ScheduleEvent(EVENT_FACE_TO_PLAYERS, Seconds(7) + Milliseconds(900));
                            break;
                        case EVENT_FACE_TO_PLAYERS:
                            me->SetFacingTo(1.53589f);
                            _events.ScheduleEvent(EVENT_TALK_INTRO_4, Milliseconds(200));
                            break;
                        case EVENT_TALK_INTRO_4:
                            Talk(SAY_INTRO_4);
                            _events.ScheduleEvent(EVENT_NOXIOUS_CONCOCTION, Seconds(2) + Milliseconds(200));
                            break;
                        case EVENT_NOXIOUS_CONCOCTION:
                            DoCastAOE(SPELL_NOXIOUS_CONCOCTION);
                            _events.ScheduleEvent(EVENT_TALK_INTRO_5, Seconds(2) + Milliseconds(600));
                            break;
                        case EVENT_TALK_INTRO_5:
                            Talk(SAY_INTRO_5);
                            _events.ScheduleEvent(EVENT_NIGHTMARE_ELIXIR, Seconds(4) + Milliseconds(600));
                            break;
                        case EVENT_NIGHTMARE_ELIXIR:
                            DoCastAOE(SPELL_NIGHTMARE_ELIXIR);
                            DoCastAOE(SPELL_VANESSAS_BLACKOUT_AURA, true);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_NIGHTMARE_ELIXIR, Milliseconds(200));
                            break;
                        case EVENT_ANNOUNCE_NIGHTMARE_ELIXIR:
                            Talk(SAY_ANNOUNCE_NIGHTMARE_ELIXIR);
                            _events.ScheduleEvent(EVENT_LAUGH, Seconds(2) + Milliseconds(100));
                            break;
                        case EVENT_LAUGH:
                            me->HandleEmoteCommand(EMOTE_STATE_LAUGH);
                            _events.ScheduleEvent(EVENT_SETUP_NIGHTMARE, Milliseconds(700));
                            me->DespawnOrUnsummon(Seconds(5));
                            break;
                        case EVENT_SETUP_NIGHTMARE:
                            _instance->SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STATE_PREPARE_TRAP);
                            _events.ScheduleEvent(EVENT_MAGMA_TRAP, Milliseconds(800));
                            break;
                        case EVENT_MAGMA_TRAP:
                            _instance->SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STAGE_MAGMA_TRAP);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_vanessa_vanessa_van_cleefAI>(creature);
        }
};

class npc_vanessa_note_from_vanessa : public CreatureScript
{
    public:
        npc_vanessa_note_from_vanessa() : CreatureScript("npc_vanessa_note_from_vanessa") { }

        struct npc_vanessa_note_from_vanessaAI : public ScriptedAI
        {
            npc_vanessa_note_from_vanessaAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                _events.ScheduleEvent(EVENT_TALK_NOTE_FALLS_TO_THE_GROUND, Seconds(5));
            }

            bool GossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/) override
            {
                if (_instance->GetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER) != IN_PROGRESS)
                {
                    _instance->SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, IN_PROGRESS);
                    me->DespawnOrUnsummon(Seconds(7));
                }
                return false;
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_NOTE_FALLS_TO_THE_GROUND:
                            Talk(SAY_ANNOUNCE_NOTE_ON_THE_GROUND);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_vanessa_note_from_vanessaAI>(creature);
        }
};

class npc_vanessa_rope : public CreatureScript
{
    public:
        npc_vanessa_rope() : CreatureScript("npc_vanessa_rope") { }

        struct npc_vanessa_ropeAI : public ScriptedAI
        {
            npc_vanessa_ropeAI(Creature* creature) : ScriptedAI(creature) { }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (!passenger)
                    return;

                if (apply && passenger->GetTypeId() == TYPEID_PLAYER)
                {
                    me->RemoveAurasDueToSpell(SPELL_CLICK_ME);
                    _events.ScheduleEvent(EVENT_START_SWING, Milliseconds(800));
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
                        case EVENT_START_SWING:
                            for (uint8 i = 0; i < 5; i++)
                                if (RopePos[i].GetExactDist(me->GetPosition()) <= 1.0f)
                                {
                                    me->DespawnOrUnsummon(Seconds(8) + Milliseconds(900));
                                    me->SetSpeed(MOVE_RUN, 22.0f); // Don't ask me why but this is the correct speed to be synch with sniff behaivior
                                    me->SetDisplayId(MODEL_ID_INVISIBLE);
                                    switch (i)
                                    {
                                        case 0:
                                            me->GetMotionMaster()->MoveSmoothPath(0, RopePath1, 5, false, true);
                                            break;
                                        case 1:
                                            me->GetMotionMaster()->MoveSmoothPath(0, RopePath2, 5, false, true);
                                            break;
                                        case 2:
                                            me->GetMotionMaster()->MoveSmoothPath(0, RopePath3, 5, false, true);
                                            break;
                                        case 3:
                                            me->GetMotionMaster()->MoveSmoothPath(0, RopePath4, 5, false, true);
                                            break;
                                        case 4:
                                            me->GetMotionMaster()->MoveSmoothPath(0, RopePath5, 5, false, true);
                                            break;
                                    }
                                    break;
                                }
                            break;
                        default:
                            break;
                    }
                }

            }
        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_vanessa_ropeAI>(creature);
        }
};

class spell_vanessa_backslash_targeting : public SpellScriptLoader
{
    public:
        spell_vanessa_backslash_targeting() : SpellScriptLoader("spell_vanessa_backslash_targeting") { }

        class spell_vanessa_backslash_targeting_SpellScript : public SpellScript
        {
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_BACKSLASH });
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_BACKSLASH));

                if (!targets.empty())
                    Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnEffectHitTarget.Register(&spell_vanessa_backslash_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect.Register(&spell_vanessa_backslash_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_vanessa_backslash_targeting_SpellScript();
        }
};

void AddSC_boss_vanessa_van_cleef()
{
    new boss_vanessa_van_cleef();
    new npc_vanessa_vanessa_van_cleef();
    new npc_vanessa_note_from_vanessa();
    new npc_vanessa_rope();
    new spell_vanessa_backslash_targeting();
}
