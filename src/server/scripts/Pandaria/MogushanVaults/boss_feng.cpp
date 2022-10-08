/*
 * Copyright 2021 FuzionCore Project
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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    // Shared
    SPELL_SPIRIT_BOLT                   = 118530,
    SPELL_STRENGHT_OF_SPIRIT            = 116363,
    SPELL_DRAW_ESSENCE                  = 121631,
    SPELL_NULLIFICATION_BARRIER_PLAYERS = 115811,
    SPELL_FENG_THE_ACCURSED_BONUS       = 132189,

    // Visuals
    SPELL_SPIRIT_FIST                   = 115743,
    SPELL_SPIRIT_SPEAR                  = 115740,
    SPELL_SPIRIT_STAFF                  = 115742,
    SPELL_SPIRIT_SHIELD                 = 115741,

    // Spirit of the Fist
    SPELL_LIGHTNING_LASH                = 131788,
    SPELL_LIGHTNING_FISTS               = 116157,
    SPELL_EPICENTER                     = 116018,

    // Spirit of the Spear
    SPELL_FLAMING_SPEAR                 = 116942,
    SPELL_WILDFIRE_SPARK                = 116784,
    SPELL_DRAW_FLAME                    = 116711,
    SPELL_WILDFIRE_INFUSION_STACK       = 116821,
    SPELL_WILDFIRE_INFUSION             = 116817,
    SPELL_ARCHIMONDES_FIRE              = 116787,

    // Spirit of the Staff
    SPELL_ARCANE_SHOCK                  = 131790,
    SPELL_ARCANE_VELOCITY               = 116364,
    SPELL_ARCANE_RESONANCE              = 116417,

    // Spirit of the Shield (Heroic)
    SPELL_SHADOWBURN                    = 131792,
    SPELL_SIPHONING_SHIELD              = 118071,
    SPELL_CHAINS_OF_SHADOW              = 118783,

    // Stolen Essences of Stone
    SPELL_NULLIFICATION_BARRIER         = 115817,
    SPELL_SHROUD_OF_REVERSAL            = 115911,

    // Controler Visual
    SPELL_VISUAL_FIST                   = 105032,
    SPELL_VISUAL_SPEAR                  = 118485,
    SPELL_VISUAL_STAFF                  = 118486,
    SPELL_VISUAL_SHIELD                 = 117303,

    // Inversions Spell
    SPELL_INVERSION                     = 115972,

    SPELL_EPICENTER_INVERSION           = 118300,
    SPELL_LIGHTNING_FISTS_INVERSION     = 118302,
    SPELL_ARCANE_RESONANCE_INVERSION    = 118304,
    SPELL_ARCANE_VELOCITY_INVERSION     = 118305,
    SPELL_WILDFIRE_SPARK_INVERSION      = 118307,
    SPELL_FLAMING_SPEAR_INVERSION       = 118308,
    SPELL_SIPHONING_SHIELD_INVERSION    = 118471,
    SPELL_SHADOWBURN_INVERSION          = 132296,
    SPELL_LIGHTNING_LASH_INVERSION      = 132297,
    SPELL_ARCANE_SHOCK_INVERSION        = 132298,

    // Siphon Shield
    SPELL_SUMMON_SHIELD                 = 117203,
    SPELL_TOGGLE_SHIELD                 = 121296,
    SPELL_SHIELD_DISPLAYED              = 117763,
    SPELL_SHIELD_VISUAL                 = 117240,
    SPELL_SOUL_FRAGMENT                 = 45537,
    SPELL_SUMMON_SOUL_FRAGMENT          = 117717,
    SPELL_BACK_TO_FENG                  = 117781,
    SPELL_LINKED_SHIELD                 = 45537,

    // Soul Fragment
    SPELL_SOUL_DISPLAY                  = 32395,
    SPELL_ICE_TRAP                      = 135382
};

enum eEvents
{
    EVENT_DOT_ATTACK            = 1,
    EVENT_RE_ATTACK             = 2,

    EVENT_LIGHTNING_FISTS       = 3,
    EVENT_EPICENTER             = 4,

    EVENT_WILDFIRE_SPARK        = 5,
    EVENT_DRAW_FLAME            = 6,

    EVENT_ARCANE_VELOCITY       = 7,
    EVENT_ARCANE_VELOCITY_END   = 8,
    EVENT_ARCANE_RESONANCE      = 9,
    EVENT_SPIRIT_BOLTS          = 10,

    EVENT_SIPHONING_SHIELD      = 11,
    EVENT_CHAINS_OF_SHADOW      = 12,

    EVENT_SHIELD_CASTSOULS      = 13,
    EVENT_SHIELD_CHECKSOULS     = 14,
    EVENT_SHIELD_BACK           = 15,
    EVENT_SHIELD_DESTROY        = 16,
    EVENT_SOUL_WALK             = 17,
    EVENT_SOUL_GROW             = 18,
    EVENT_SHIELD_BARRIER        = 19
};

enum eFengPhases
{
    PHASE_NONE                  = 0,
    PHASE_FIST                  = 1,
    PHASE_SPEAR                 = 2,
    PHASE_STAFF                 = 3,
    PHASE_SHIELD                = 4
};

enum eTalk
{
    TALK_AGGRO      = 0,
    TALK_PHASE_1    = 1,
    TALK_PHASE_2    = 2,
    TALK_PHASE_3    = 3,
    TALK_PHASE_4    = 4,
    TALK_DEATH      = 5,
    TALK_SLAY       = 6
};

enum EquipId
{
    EQUIP_ID_FISTS      = 82769,
    EQUIP_ID_SPEAR      = 82770,
    EQUIP_ID_STAFF      = 82771,
    EQUIP_ID_HAXE       = 61887, // Not exactly the right weapon... - not found in [82760, 82780]
    EQUIP_ID_SHIELD     = 82767, // Shield
};

enum eShieldPhases
{
    PHASE_INACTIVE      = 0, // Feng isn't using Siphoning Shield
    PHASE_THROWN        = 1, // Feng has just thrown the shield, but it's not on the floor yet
    PHASE_LANDED        = 2, // Shield on the ground, casting
    PHASE_INTERRUPTED   = 3, // Shield has been recalled by Feng, stop casting on the ground
    PHASE_BACK          = 4, // Shield is flying back to Feng
};

enum eSoulActions
{
    ACTION_SOUL_HOME    = 20,
    ACTION_SOUL_KILLED  = 21,
    ACTION_SOUL_REMOVE  = 22
};

#define SHIELD_ON_FENG 5
#define DISPLAYID_SHIELD 11686

Position modPhasePositions[4] =
{
    {4063.26f, 1320.50f, 466.30f, 5.5014f}, // Phase Fist
    {4021.17f, 1320.50f, 466.30f, 3.9306f}, // Phase Spear
    {4021.17f, 1362.80f, 466.30f, 2.0378f}, // Phase Staff
    {4063.26f, 1362.80f, 466.30f, 0.7772f}, // Phase Shield
};


uint32 statueEntryInOrder[4] = {GOB_FIST_STATUE,   GOB_SPEAR_STATUE,   GOB_STAFF_STATUE,   GOB_SHIELD_STATUE};
uint32 controlerVisualId[4]  = {SPELL_VISUAL_FIST, SPELL_VISUAL_SPEAR, SPELL_VISUAL_STAFF, SPELL_VISUAL_SHIELD};
uint32 fengVisualId[4]       = {SPELL_SPIRIT_FIST, SPELL_SPIRIT_SPEAR, SPELL_SPIRIT_STAFF, SPELL_SPIRIT_SHIELD};

#define MAX_INVERSION_SPELLS    10
uint32 inversionMatching[MAX_INVERSION_SPELLS][2] =
{
    {SPELL_EPICENTER,        SPELL_EPICENTER_INVERSION},
    {SPELL_LIGHTNING_FISTS,  SPELL_LIGHTNING_FISTS_INVERSION},
    {SPELL_ARCANE_RESONANCE, SPELL_ARCANE_RESONANCE_INVERSION},
    {SPELL_ARCANE_VELOCITY,  SPELL_ARCANE_VELOCITY_INVERSION},
    {SPELL_WILDFIRE_SPARK,   SPELL_WILDFIRE_SPARK_INVERSION},
    {SPELL_FLAMING_SPEAR,    SPELL_FLAMING_SPEAR_INVERSION},
    {SPELL_SHADOWBURN,       SPELL_SHADOWBURN_INVERSION},
    {SPELL_LIGHTNING_LASH,   SPELL_LIGHTNING_LASH_INVERSION},
    {SPELL_ARCANE_SHOCK,     SPELL_ARCANE_SHOCK_INVERSION},
    {SPELL_SIPHONING_SHIELD, SPELL_SIPHONING_SHIELD_INVERSION}
};

#define MAX_DIST    60.0f
Position fengCenterPos = {4041.979980f, 1341.859985f, 466.388000f, 3.140160f};

// Positions for Siphoning Shield
Position shieldPositions[3] =
{
    {4067.59f, 1326.71f, 466.30f, 2.579275f},
    {4020.77f, 1363.22f, 466.30f, 5.500957f},
    {4036.06f, 1362.29f, 466.30f, 4.253744f}
};

#define SHIELD_POSITIONS_COUNT 3;

// Feng The Accursed - 60009
class boss_feng : public CreatureScript
{
    public:
        boss_feng() : CreatureScript("boss_feng") {}

        struct boss_fengAI : public BossAI
        {
            boss_fengAI(Creature* creature) : BossAI(creature, DATA_FENG)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            bool isWaitingForPhase;

            uint8 actualPhase;

            uint32 nextPhasePct;
            uint32 dotSpellId;
            std::list<uint32> phaseList;

            std::list<ObjectGuid> sparkList;
            uint8 availablePos[4];

            void Reset() override
            {
                _Reset();

                for (auto visualSpellId: fengVisualId)
                    me->RemoveAurasDueToSpell(visualSpellId);

                SetEquipmentSlots(false, 0, 0, EQUIP_NO_CHANGE);

                if (pInstance->GetBossState(DATA_FENG) != DONE)
                    pInstance->SetBossState(DATA_FENG, NOT_STARTED);

                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->SetReactState(REACT_PASSIVE);

                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FLAMING_SPEAR);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NULLIFICATION_BARRIER_PLAYERS);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INVERSION);

                isWaitingForPhase = false;
                actualPhase  = PHASE_NONE;
                nextPhasePct = 95;
                dotSpellId = 0;

                for(uint8 i = 1; i < 5; i++)
                    availablePos[i - 1] = i;

                // Desactivate old statue
                if (GameObject* oldStatue = pInstance->GetGameObject(statueEntryInOrder[actualPhase]))
                {
                    oldStatue->SetLootState(GO_READY);
                    oldStatue->UseDoorOrButton();
                }

                if (GameObject* inversionGob = pInstance->GetGameObject(GOB_INVERSION))
                    inversionGob->Respawn();

                if (GameObject* cancelGob = pInstance->GetGameObject(GOB_CANCEL))
                    cancelGob->Respawn();
            }

            void JustDied(Unit* /*p_Attacker*/) override
            {
                _JustDied();
                Talk(TALK_DEATH);
                pInstance->SetBossState(DATA_FENG, DONE);

                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FLAMING_SPEAR);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NULLIFICATION_BARRIER_PLAYERS);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INVERSION);

                if (GameObject* inversionGob = pInstance->GetGameObject(GOB_INVERSION))
                    inversionGob->Delete();

                if (GameObject* cancelGob = pInstance->GetGameObject(GOB_CANCEL))
                    cancelGob->Delete();

                if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 100.0f, true))
                {
                    if (lorewalkerCho->AI())
                    {
                        if (lorewalkerCho->GetPositionX() >= 3994.0f && lorewalkerCho->GetPositionX() <= 3996.0f &&
                            lorewalkerCho->GetPositionY() >= 1339.0f && lorewalkerCho->GetPositionY() <= 1341.0f &&
                            lorewalkerCho->GetPositionZ() >= 460.0f && lorewalkerCho->GetPositionZ() <= 463.0f)
                        {
                            lorewalkerCho->AI()->Talk(9);
                            lorewalkerCho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                        }
                    }
                }

                Map::PlayerList const& l_PlrList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
                {
                    if (Player* l_Player = l_Itr->GetSource())
                        me->CastSpell(l_Player, SPELL_FENG_THE_ACCURSED_BONUS, true);
                }

                /*if (me->GetMap()->IsLFR())
                {
                    me->ResetLootRecipients();
                    Player* l_Player = me->GetMap()->GetPlayers().begin()->GetSource();
                    if (l_Player && l_Player->GetGroup())
                        sLFGMgr->AutomaticLootAssignation(me, l_Player->GetGroup());
                }*/
            }

            void JustReachedHome() override
            {
                summons.DespawnAll();
                events.Reset();
                SetEquipmentSlots(false, 0, 0, EQUIP_NO_CHANGE);
                me->SetFullHealth();
                _JustReachedHome();
            }

            void EnterCombat(Unit* attacker) override
            {
                if (!pInstance->CheckRequiredBosses(DATA_FENG) || attacker->GetPositionX() < 4009.0f || attacker->GetPositionX() > 4076.0f)
                {
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }

                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                pInstance->SetBossState(DATA_FENG, IN_PROGRESS);
                Talk(TALK_AGGRO);
                events.ScheduleEvent(EVENT_SPIRIT_BOLTS, urand(25000, 35000));
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetInCombatWith(attacker);
                AttackStart(attacker);
            }

            void MovementInform (uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id >= 1 && id <= 4)
                    PrepareNewPhase(id);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_SPARK)
                    me->AddAura(SPELL_WILDFIRE_INFUSION_STACK, me);

                if (action == ACTION_SCHEDULE_SHIELD)
                    events.ScheduleEvent(EVENT_SIPHONING_SHIELD, 30000);
            }

            void PrepareNewPhase(uint8 newPhase)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DOT_ATTACK, 15000);
                events.ScheduleEvent(EVENT_RE_ATTACK,  500);
                events.ScheduleEvent(EVENT_SPIRIT_BOLTS, urand(25000, 35000));

                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->Clear();

                if (IsHeroic())
                    me->CastSpell(me, SPELL_STRENGHT_OF_SPIRIT, false);

                if (Creature* controler = GetClosestCreatureWithEntry(me, NPC_PHASE_CONTROLER, 20.0f))
                    controler->DespawnOrUnsummon();

                if (actualPhase != PHASE_NONE)
                {
                    // Desactivate old statue and enable the new one
                    if (GameObject* oldStatue = pInstance->GetGameObject(statueEntryInOrder[actualPhase - 1]))
                    {
                        oldStatue->SetLootState(GO_READY);
                        oldStatue->UseDoorOrButton();
                    }
                }

                if (GameObject* newStatue = pInstance->GetGameObject(statueEntryInOrder[newPhase - 1]))
                {
                    newStatue->SetLootState(GO_READY);
                    newStatue->UseDoorOrButton();
                }

                for (auto visualSpellId: fengVisualId)
                    me->RemoveAurasDueToSpell(visualSpellId);

                me->AddAura(fengVisualId[newPhase - 1], me);
                me->CastSpell(me, SPELL_DRAW_ESSENCE, true);

                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);

                switch (newPhase)
                {
                    case PHASE_FIST:
                    {
                        dotSpellId = SPELL_LIGHTNING_LASH;
                        events.ScheduleEvent(EVENT_LIGHTNING_FISTS,  20000, PHASE_FIST);
                        events.ScheduleEvent(EVENT_EPICENTER,        35000, PHASE_FIST);
                        SetEquipmentSlots(false, EQUIP_ID_FISTS, EQUIP_ID_FISTS, EQUIP_NO_CHANGE);
                        Talk(TALK_PHASE_1);
                        break;
                    }
                    case PHASE_SPEAR:
                    {
                        dotSpellId = SPELL_FLAMING_SPEAR;
                        events.ScheduleEvent(EVENT_WILDFIRE_SPARK,   30000, PHASE_SPEAR);
                        events.ScheduleEvent(EVENT_DRAW_FLAME,       40000, PHASE_SPEAR);
                        SetEquipmentSlots(false, EQUIP_ID_SPEAR, 0, EQUIP_NO_CHANGE);
                        Talk(TALK_PHASE_2);
                        break;
                    }
                    case PHASE_STAFF:
                    {
                        summons.DespawnAll();

                        me->RemoveAura(SPELL_WILDFIRE_INFUSION);
                        dotSpellId = SPELL_ARCANE_SHOCK;
                        events.ScheduleEvent(EVENT_ARCANE_VELOCITY,  25000, PHASE_STAFF);
                        events.ScheduleEvent(EVENT_ARCANE_RESONANCE, 40000, PHASE_STAFF);
                        SetEquipmentSlots(false, EQUIP_ID_STAFF, 0, EQUIP_NO_CHANGE);
                        Talk(TALK_PHASE_3);
                        break;
                    }
                    case PHASE_SHIELD:
                    {
                        dotSpellId = SPELL_SHADOWBURN;
                        SetEquipmentSlots(false, EQUIP_ID_HAXE, EQUIP_ID_SHIELD, EQUIP_NO_CHANGE);
                        events.ScheduleEvent(EVENT_SIPHONING_SHIELD, 5000, PHASE_SHIELD);
                        events.ScheduleEvent(EVENT_CHAINS_OF_SHADOW, 45000, PHASE_SHIELD);
                        Talk(TALK_PHASE_4);
                        break;
                    }
                    default:
                        break;
                }

                isWaitingForPhase = false;
                actualPhase = newPhase;
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                sparkList.push_back(summon->GetGUID());
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);

                sparkList.remove(summon->GetGUID());
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (Aura* inversion = target->GetAura(115911))
                {
                    if (Unit* caster = inversion->GetCaster())
                    {
                        for (uint8 i = 0; i < MAX_INVERSION_SPELLS; ++i)
                        {
                            if (spell->Id == inversionMatching[i][0])
                            {
                                bool alreadyHaveAnInversion = false;

                                for (uint8 j = 0; j < MAX_INVERSION_SPELLS; ++j)
                                    if (caster->HasAura(inversionMatching[j][1]))
                                    {
                                        alreadyHaveAnInversion = true;
                                        break;
                                    }

                                if (!alreadyHaveAnInversion)
                                    caster->CastSpell(caster, inversionMatching[i][1], true);

                                break;
                            }
                        }
                    }
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->IsPlayer())
                    Talk(TALK_SLAY);
            }

            void OnAddThreat(Unit* /*victim*/, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/) /*override*/
            {
                if (isWaitingForPhase)
                    fThreat = 0;
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (!pInstance->CheckRequiredBosses(DATA_FENG) || attacker->GetPositionX() < 4009.0f || attacker->GetPositionX() > 4076.0f)
                {
                    me->SetFullHealth();
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }

                if (!pInstance)
                    return;

                if (attacker->GetEntry() == NPC_WILDFIRE_SPARK)
                {
                    damage = 0;
                    return;
                }

                if (nextPhasePct)
                {
                    if (me->HealthBelowPctDamaged(nextPhasePct, damage))
                    {
                        events.Reset();

                        uint8 newPhase = 9;
                        isWaitingForPhase = true;

                        me->InterruptNonMeleeSpells(true);

                        // In normal mode, Feng reaches the statue in predetermined order
                        if (!IsHeroic())
                        {
                            newPhase = actualPhase + 1;
                            me->GetMotionMaster()->MovePoint(newPhase, modPhasePositions[newPhase - 1].GetPositionX(), modPhasePositions[newPhase - 1].GetPositionY(), modPhasePositions[newPhase - 1].GetPositionZ());
                        }
                        // In Heroic mode, Feng reaches the nearest statue he hasn't siphonned yet
                        else
                        {
                            float dist = 300.0f;
                            uint32 statue = 0;

                            // Looking for the closest available statue
                            for (uint8 i = 0; i < 4; i++)
                            {
                                if (availablePos[i])
                                {
                                    if (me->GetDistance(modPhasePositions[i]) < dist)
                                    {
                                        dist = me->GetDistance(modPhasePositions[i]);
                                        statue = i;
                                    }
                                }
                            }
                            // Statue selected
                            newPhase = statue + 1;
                            availablePos[statue] = 0;
                            me->GetMotionMaster()->MovePoint(newPhase, modPhasePositions[statue]);
                        }

                        if (Creature* controler = me->SummonCreature(NPC_PHASE_CONTROLER, modPhasePositions[newPhase - 1].GetPositionX(), modPhasePositions[newPhase - 1].GetPositionY(), modPhasePositions[newPhase - 1].GetPositionZ()))
                            controler->AddAura(controlerVisualId[newPhase - 1], controler);

                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

                        uint32 reduction = IsHeroic() ? 25: 32;
                        nextPhasePct >= reduction ? nextPhasePct-= reduction: nextPhasePct = 0;
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (pInstance)
                {
                    if (pInstance->IsWipe())
                    {
                        me->SetFullHealth();
                        me->GetMotionMaster()->MoveTargetedHome();
                        pInstance->SetBossState(DATA_FENG, FAIL);
                    }
                }

                CheckPlatform();

                if (isWaitingForPhase)
                    return;

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    // All Phases
                    case EVENT_DOT_ATTACK:
                    {
                        // if (dotSpellId == SPELL_SHADOWBURN)
                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, dotSpellId, false);

                        /*else if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, dotSpellId, false);*/

                        events.ScheduleEvent(EVENT_DOT_ATTACK, 12500);
                        break;
                    }
                    case EVENT_RE_ATTACK:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->GetMotionMaster()->MoveChase(target);
                            me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    }
                    // Fist Phase
                    case EVENT_LIGHTNING_FISTS:
                    {
                        me->CastSpell(me, SPELL_LIGHTNING_FISTS, false);
                        events.ScheduleEvent(EVENT_LIGHTNING_FISTS, 20000);
                        break;
                    }
                    case EVENT_EPICENTER:
                    {
                        me->TextEmote("Feng the Accursed begins to channel a violent |cffba2200|Hspell:116018|h[Epicenter]|h|r !", 0, true);
                        me->CastSpell(me, SPELL_EPICENTER, false);
                        events.ScheduleEvent(EVENT_EPICENTER, 35000);
                        break;
                    }
                    // Spear Phase
                    case EVENT_WILDFIRE_SPARK:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->TextEmote("You have been affected by |cffba2200|Hspell:116784|h[Wildfire Spark]|h|r !", target, true);
                            me->CastSpell(target, SPELL_WILDFIRE_SPARK, false);
                        }
                        events.ScheduleEvent(EVENT_WILDFIRE_SPARK, urand(25000, 35000));
                        break;
                    }
                    case EVENT_DRAW_FLAME:
                    {
                        me->TextEmote("Feng the Accursed begins to |cffba2200|Hspell:116711|h[Draw Flame]|h|r to his weapon !", 0, true);
                        me->CastSpell(me, SPELL_DRAW_FLAME, false);

                        events.ScheduleEvent(EVENT_DRAW_FLAME, 60000);
                        break;
                    }
                    // Staff Phase
                    case EVENT_ARCANE_VELOCITY:
                    {
                        me->SetSpeed(MOVE_RUN, 0.0f);
                        me->CastSpell(me, SPELL_ARCANE_VELOCITY, false);
                        events.ScheduleEvent(EVENT_ARCANE_VELOCITY_END, 100);   // The eventmap don't update while the creature is casting
                        events.ScheduleEvent(EVENT_ARCANE_VELOCITY,     15000);
                        break;
                    }
                    case EVENT_ARCANE_VELOCITY_END:
                    {
                        me->SetSpeed(MOVE_RUN, 1.14f);
                        break;
                    }
                    case EVENT_ARCANE_RESONANCE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                            target->AddAura(SPELL_ARCANE_RESONANCE, target);
                        events.ScheduleEvent(EVENT_ARCANE_RESONANCE, 40000);
                        break;
                    }
                    case EVENT_SPIRIT_BOLTS:
                    {
                        me->CastSpell(me, SPELL_SPIRIT_BOLT, true);
                        events.ScheduleEvent(EVENT_SPIRIT_BOLTS, urand(25000, 35000));
                        break;
                    }
                    // Shield Phase
                    case EVENT_SIPHONING_SHIELD:
                    {
                        me->CastSpell(me, SPELL_SUMMON_SHIELD, true);
                        break;
                    }
                    case EVENT_CHAINS_OF_SHADOW:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_CHAINS_OF_SHADOW, true);
                        events.ScheduleEvent(EVENT_CHAINS_OF_SHADOW, urand(30000, 40000));
                        break;
                    }
                    default:
                        break;
                }
                if (me->GetReactState() == REACT_AGGRESSIVE)
                    DoMeleeAttackIfReady();
            }

            private:
                void CheckPlatform()
                {
                    if (!me->IsInCombat())
                        return;

                    if ((me->GetPositionX() - fengCenterPos.GetPositionX()) > 37.0f ||
                        (me->GetPositionX() - fengCenterPos.GetPositionX()) < -37.0f ||
                        (me->GetPositionY() - fengCenterPos.GetPositionY()) > 37.0f ||
                        (me->GetPositionY() - fengCenterPos.GetPositionY()) < -37.0f)
                        me->AI()->EnterEvadeMode(EVADE_REASON_OTHER);
                }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_fengAI(creature);
        }
};

enum eLightningFistSpell
{
    SPELL_FIST_BARRIER      = 115856,
    SPELL_FIST_CHARGE       = 116374,
    SPELL_FIST_VISUAL       = 116225
};

// Lightning Charge - 60241
class mob_lightning_fist : public CreatureScript
{
    public:
        mob_lightning_fist() : CreatureScript("mob_lightning_fist") {}

        struct mob_lightning_fistAI : public ScriptedAI
        {
            mob_lightning_fistAI(Creature* creature) : ScriptedAI(creature)
            {}

            uint32 checkNearPlayerTimer;

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_FIST_BARRIER, me);
                me->AddAura(SPELL_FIST_VISUAL, me);

                float x = 0, y = 0;
                GetPositionWithDistInOrientation(me, 100.0f, me->GetOrientation(), x, y);

                me->GetMotionMaster()->MoveCharge(x, y, me->GetPositionZ(), 24.0f, 1);

                checkNearPlayerTimer = 500;
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                    me->DespawnOrUnsummon();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (checkNearPlayerTimer)
                {
                    if (checkNearPlayerTimer <= diff)
                    {
                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, me, 5.0f);

                        for (auto player: playerList)
                            me->CastSpell(player, SPELL_FIST_CHARGE, true);

                        checkNearPlayerTimer = 500;
                    }
                    else
                        checkNearPlayerTimer -= diff;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_lightning_fistAI(creature);
        }
};

// Siphoning Shield - 60627
class mob_siphon_shield : public CreatureScript
{
    public :
        mob_siphon_shield() : CreatureScript("mob_siphon_shield") { }

        struct mob_siphon_shieldAI : public ScriptedAI
        {
            mob_siphon_shieldAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                // Set invisible
                me->SetDisplayId(DISPLAYID_SHIELD);
                if (Creature* feng = pInstance->GetCreature(NPC_FENG))
                    me->SetFacingToObject(feng);
            }

            InstanceScript* pInstance;
            uint8 soulsCount;
            std::map<uint32, uint32> soulsMap;

            void Reset() override
            {
                events.Reset();
                soulsCount = 0;
                // Display shield
                me->AddAura(SPELL_SHIELD_DISPLAYED, me);
                // Activate Visual
                me->AddAura(SPELL_SHIELD_VISUAL, me);
                me->CastSpell(me, SPELL_FIST_BARRIER, false);
                events.ScheduleEvent(EVENT_SHIELD_BARRIER,   6000);
                events.ScheduleEvent(EVENT_SHIELD_CASTSOULS, 2000);
                // me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC));
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_SOUL_HOME:
                    {
                        if (Creature* feng = pInstance->GetCreature(NPC_FENG))
                            feng->SetHealth(feng->GetHealth() + feng->GetMaxHealth() / (Is25ManRaid() ? 20 : 10));
                        soulsCount--;
                        break;
                    }
                    case ACTION_SOUL_KILLED:
                    {
                        soulsCount--;
                        break;
                    }
                    case ACTION_SOUL_REMOVE:
                    {
                        std::list<Creature*> soulList;
                        GetCreatureListWithEntryInGrid(soulList, me, NPC_SOUL_FRAGMENT, 200.0f);

                        for (auto soul : soulList)
                            soul->DespawnOrUnsummon(1000);

                        soulsCount = 0;
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventID = events.ExecuteEvent())
                {
                    switch (eventID)
                    {
                        case EVENT_SHIELD_CASTSOULS:
                        {
                            // Retrieving targets
                            std::list<Player*> potenTargets;
                            GetPlayerListInGrid(potenTargets, me, 150.0f);

                            if (potenTargets.empty())
                            {
                                events.ScheduleEvent(EVENT_SHIELD_CHECKSOULS, 10000);
                                break;
                            }

                            uint8 maxTargets = Is25ManRaid() ? 10 : 5;

                            std::list<Player*>::iterator itr, next;
                            itr = potenTargets.begin();
                            // Selecting targets
                            while (potenTargets.size() > maxTargets)
                            {
                                next = itr;

                                if (urand(0, 1))
                                    potenTargets.remove(*itr);

                                itr = ++next;
                                if (itr == potenTargets.end())
                                    itr = potenTargets.begin();
                            }

                            soulsCount = potenTargets.size();

                            // Attacking targets -- Souls are summoned by player
                            for (auto target : potenTargets)
                                target->CastSpell(target, SPELL_SUMMON_SOUL_FRAGMENT, false);

                            // Check if there are souls remainings
                            events.ScheduleEvent(EVENT_SHIELD_CHECKSOULS, 10000);
                            break;
                        }
                        case EVENT_SHIELD_CHECKSOULS:
                        {
                            if (!soulsCount)
                            {
                                // Remove visual effect
                                me->RemoveAura(SPELL_SHIELD_VISUAL);
                                // Scheduling end of action
                                events.ScheduleEvent(EVENT_SHIELD_BACK, 2000);
                            }
                            else
                                events.ScheduleEvent(EVENT_SHIELD_CHECKSOULS, 1000);
                            break;
                        }
                        case EVENT_SHIELD_BACK:
                        {
                            if (!pInstance)
                            {
                                events.ScheduleEvent(EVENT_SHIELD_DESTROY, 200);
                                break;
                            }

                            if (Creature* feng = pInstance->GetCreature(NPC_FENG))
                            {
                                // Making Feng moves his arm
                                feng->CastSpell(me, SPELL_BACK_TO_FENG, true);
                                // Making shield returning to feng
                                me->CastSpell(feng, SPELL_BACK_TO_FENG, false);
                                // Visual effect
                                me->CastSpell(feng, SPELL_LINKED_SHIELD, false);
                            }
                            events.ScheduleEvent(EVENT_SHIELD_DESTROY, 200);
                            break;
                        }
                        case EVENT_SHIELD_DESTROY:
                        {
                            if (!pInstance)
                                break;

                            if (Creature* feng = pInstance->GetCreature(NPC_FENG))
                            {
                                // Become invisible
                                me->RemoveAura(SPELL_SHIELD_DISPLAYED);
                                // Make the shield on Feng's arm
                                feng->RemoveAura(SPELL_TOGGLE_SHIELD);
                                // No more visual link between Feng & shield, as shield is on Feng
                                feng->RemoveAura(SPELL_LINKED_SHIELD);
                                // Scheduling next siphoning shield in 30 secs
                                feng->AI()->DoAction(ACTION_SCHEDULE_SHIELD);
                                // Bye !
                                me->DespawnOrUnsummon();
                            }
                            break;
                        }
                        case EVENT_SHIELD_BARRIER:
                        {
                            me->AddAura(SPELL_FIST_BARRIER, me);
                            events.ScheduleEvent(EVENT_SHIELD_BARRIER, 6000);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_siphon_shieldAI(creature);
        }
};

// Soul Fragment - 60781
class mob_soul_fragment : public CreatureScript
{
    public:
        mob_soul_fragment() : CreatureScript("mob_soul_fragment") { }

        struct mob_soul_fragmentAI : public ScriptedAI
        {
            mob_soul_fragmentAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            float scale;

            void Reset() override
            {
                // Set dark aspect
                me->AddAura(SPELL_SOUL_DISPLAY, me);
                if (Player* bound = me->SelectNearestPlayer(10.0f))
                {
                    // Display with display of player
                    me->SetDisplayId(bound->GetDisplayId());
                }
                scale = 0.1f;
                me->SetObjectScale(scale);
                if (Creature* shield = pInstance->GetCreature(NPC_SIPHONING_SHIELD))
                    shield->CastSpell(me, SPELL_SOUL_FRAGMENT, false);
                me->AddAura(SPELL_FIST_BARRIER, me);
                events.ScheduleEvent(EVENT_SOUL_WALK, 2000);
                events.ScheduleEvent(EVENT_SOUL_GROW, 100);
            }

            void JustDied(Unit* /*killer*/) override
            {
                // We send negative guid to tell shield the soul has been killed
                if (Creature* shield = pInstance->GetCreature(NPC_SIPHONING_SHIELD))
                    shield->AI()->DoAction(ACTION_SOUL_KILLED);
            }

            // Prevent the NPC to chase after the players
            void MoveInLineOfSight(Unit* /*who*/) override
            {
                return;
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                {
                    // We send positive GUID to tell shield the soul has reached it, and the player should be killed
                    if (Creature* shield = pInstance->GetCreature(NPC_SIPHONING_SHIELD))
                        if (me->GetDistance(shield) < 1.0f)
                            shield->AI()->DoAction(ACTION_SOUL_HOME);

                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventID = events.ExecuteEvent())
                {
                    switch (eventID)
                    {
                        case EVENT_SOUL_WALK:
                        {
                            me->CastSpell(me, SPELL_ICE_TRAP, false);
                            if (Creature* shield = pInstance->GetCreature(NPC_SIPHONING_SHIELD))
                            {
                                me->SetSpeed(MOVE_RUN, 0.1f);
                                me->GetMotionMaster()->MovePoint(1, shield->GetPositionX(), shield->GetPositionY(), shield->GetPositionZ());
                                me->SetWalk(true);
                            }
                            break;
                        }
                        case EVENT_SOUL_GROW:
                        {
                            if (scale < 1.5f)
                            {
                                scale += 0.1f;
                                me->SetObjectScale(scale);
                                events.ScheduleEvent(EVENT_SOUL_GROW, 100);
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_soul_fragmentAI(creature);
        }
};

// Wildfire Spark - 60438
class mob_wild_spark : public CreatureScript
{
    public:
        mob_wild_spark() : CreatureScript("mob_wild_spark") {}

        struct mob_wild_sparkAI : public ScriptedAI
        {
            mob_wild_sparkAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            uint32 checkNearPlayerTimer;
            InstanceScript* pInstance;

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, 116717, true); // Fire aura
                me->CastSpell(me, SPELL_ARCHIMONDES_FIRE, true); // Fire visual
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveRandom(5.0f);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_DRAW_FLAME)
                {
                    me->GetMotionMaster()->Clear();
                    me->SetSpeed(MOVE_RUN, 5.0f);
                    me->SetSpeed(MOVE_WALK, 5.0f);
                    me->GetMotionMaster()->MovePoint(1, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                    if (InstanceScript* pInstance = me->GetInstanceScript())
                        if (Creature* feng = pInstance->GetCreature(NPC_FENG))
                        {
                            feng->AI()->DoAction(ACTION_SPARK);
                            me->DespawnOrUnsummon(500);
                        }
            }

            void UpdateAI(const uint32 /*p_Diff*/) override
            {
                if (pInstance)
                    if (pInstance->GetBossState(DATA_FENG) != IN_PROGRESS)
                        me->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_wild_sparkAI(creature);
        }
};

// Mogu Epicenter - 116040
class spell_mogu_epicenter : public SpellScriptLoader
{
    public:
        spell_mogu_epicenter() : SpellScriptLoader("spell_mogu_epicenter") { }

        class spell_mogu_epicenter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mogu_epicenter_SpellScript);

            void DealDamage()
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                if (!caster || !target)
                    return;

                float distance = caster->GetExactDist2d(target);

                if (distance >= 0.0f && distance <= 100.0f)
                    SetHitDamage(int32(GetHitDamage() * (1.0f - (distance / 100.0f))));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_mogu_epicenter_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mogu_epicenter_SpellScript();
        }
};

// Wildfire Spark - 116583
class spell_mogu_wildfire_spark : public SpellScriptLoader
{
    public:
        spell_mogu_wildfire_spark() : SpellScriptLoader("spell_mogu_wildfire_spark") { }

        class spell_mogu_wildfire_spark_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mogu_wildfire_spark_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                const uint8 maxSpark = 4;

                Unit* caster = GetCaster();

                if (!caster)
                    return;

                for (uint8 i = 0; i < maxSpark; ++i)
                {
                    float position_x = caster->GetPositionX() + frand(-3.0f, 3.0f);
                    float position_y = caster->GetPositionY() + frand(-3.0f, 3.0f);
                    caster->CastSpell(position_x, position_y, caster->GetPositionZ(), 116586, true);
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_mogu_wildfire_spark_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mogu_wildfire_spark_SpellScript();
        }
};

/// Wildfire spark - 116784
class spell_wildfire_spark : public SpellScriptLoader
{
    public:
        spell_wildfire_spark() : SpellScriptLoader("spell_wildfire_spark") { }

        class spell_wildfire_spark_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_wildfire_spark_AuraScript);

            void Cast(AuraEffect const* /*AurEff*/)
            {
                if (Unit* caster = GetCaster())
                    if (Unit* target = GetTarget())
                        caster->CastSpell(target, 116583, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_wildfire_spark_AuraScript::Cast, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        class spell_wildfire_spark_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_wildfire_spark_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    caster->AddAura(SPELL_WILDFIRE_SPARK, caster);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_wildfire_spark_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_wildfire_spark_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_wildfire_spark_AuraScript();
        }
};

// Wildfire Infusion (stacks) - 116821
class spell_wildfire_infusion_stacks : public SpellScriptLoader
{
    public:
        spell_wildfire_infusion_stacks() : SpellScriptLoader("spell_wildfire_infusion_stacks") { }

        class spell_wildfire_infusion_stacks_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_wildfire_infusion_stacks_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget())
                    GetTarget()->AddAura(SPELL_WILDFIRE_INFUSION, GetTarget());
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget())
                    GetTarget()->RemoveAura(SPELL_WILDFIRE_INFUSION);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_wildfire_infusion_stacks_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_wildfire_infusion_stacks_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_wildfire_infusion_stacks_AuraScript();
        }
};

// Wildfire Infusion - 116816
class spell_mogu_wildfire_infusion : public SpellScriptLoader
{
    public:
        spell_mogu_wildfire_infusion() : SpellScriptLoader("spell_mogu_wildfire_infusion") { }

        class spell_mogu_wildfire_infusion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mogu_wildfire_infusion_SpellScript);

            void HandleAfterCast()
            {
                if (Unit* caster = GetCaster())
                    if (Aura* aura = caster->GetAura(SPELL_WILDFIRE_INFUSION_STACK))
                        aura->ModStackAmount(-1);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_mogu_wildfire_infusion_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mogu_wildfire_infusion_SpellScript();
        }
};

// Draw Flame - 116711
class spell_draw_flame : public SpellScriptLoader
{
    public:
        spell_draw_flame() : SpellScriptLoader("spell_draw_flame") { }

        class spell_draw_flame_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_draw_flame_SpellScript);

            void ReplaceTarget(std::list<WorldObject*>& targets)
            {
                targets.clear();

                if (Unit* feng = GetCaster())
                {
                    std::list<Creature*> wildfireSpark;
                    feng->GetCreatureListWithEntryInGrid(wildfireSpark, NPC_WILDFIRE_SPARK, 65.0f);

                    for (auto itr : wildfireSpark)
                        targets.push_back(itr);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_draw_flame_SpellScript::ReplaceTarget, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_draw_flame_SpellScript();
        }
};

// Arcane Velocity - 116365
class spell_mogu_arcane_velocity : public SpellScriptLoader
{
    public:
        spell_mogu_arcane_velocity() : SpellScriptLoader("spell_mogu_arcane_velocity") { }

        class spell_mogu_arcane_velocity_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mogu_arcane_velocity_SpellScript);

            void DealDamage()
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                if (!caster || !target)
                    return;

                float distance = caster->GetExactDist2d(target);

                Difficulty difficulty = GetCaster()->GetInstanceScript()->instance->GetDifficultyID();
                int32 mindmg  = (difficulty == DIFFICULTY_10_N ? 39000 : (difficulty == DIFFICULTY_25_N ? 44850 : (difficulty == DIFFICULTY_10_HC ? 58500 : (difficulty == DIFFICULTY_25_HC ? 67275 : 16770))));
                int32 range   = (difficulty == DIFFICULTY_10_N ?  2000 : (difficulty == DIFFICULTY_25_N ?  2300 : (difficulty == DIFFICULTY_10_HC ?  3000 : (difficulty == DIFFICULTY_25_HC ?  3450 :   860))));

                if (distance >= 0.0f && distance <= 60.0f)
                    SetHitDamage(mindmg + int32(range * (distance / MAX_DIST)));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_mogu_arcane_velocity_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mogu_arcane_velocity_SpellScript();
        }
};

// Arcane Resonance - 116434
class spell_mogu_arcane_resonance : public SpellScriptLoader
{
    public:
        spell_mogu_arcane_resonance() : SpellScriptLoader("spell_mogu_arcane_resonance") { }

        class spell_mogu_arcane_resonance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mogu_arcane_resonance_SpellScript);

            uint8 targetCount;

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targetCount = targets.size();
            }

            void DealDamage()
            {
                if (targetCount > 25)
                    targetCount = 0;

                SetHitDamage(GetHitDamage() * targetCount);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mogu_arcane_resonance_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnHit                    += SpellHitFn(spell_mogu_arcane_resonance_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mogu_arcane_resonance_SpellScript();
        }
};

// Mogu Inversion - 118300 / 118302 / 118304 / 118305 / 118307 / 118308 / 132296 / 132297 / 132298
class spell_mogu_inversion : public SpellScriptLoader
{
    public:
        spell_mogu_inversion() : SpellScriptLoader("spell_mogu_inversion") { }

        class spell_mogu_inversion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mogu_inversion_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget())
                    GetTarget()->RemoveAurasDueToSpell(SPELL_INVERSION);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget())
                    GetTarget()->CastSpell(GetTarget(), SPELL_INVERSION, true);
            }

            void Register() override
            {
                OnEffectApply     += AuraEffectApplyFn(spell_mogu_inversion_AuraScript::OnApply,   EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_mogu_inversion_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mogu_inversion_AuraScript();
        }
};

// Spirit Bolt - 118530
class spell_spirit_bolt : public SpellScriptLoader
{
    public:
        spell_spirit_bolt() : SpellScriptLoader("spell_spirit_bolt") { }

        class spell_spirit_bolt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spirit_bolt_SpellScript);

            void SelectTarget(std::list<WorldObject*>& targets)
            {
                if (Unit* caster = GetCaster())
                {
                    std::list<WorldObject*>::iterator itr, next;

                    // 8 targets in 25NM and 25HM, 3 targets else
                    uint8 maxTargets = 3;
                    if (InstanceScript* pInstance = caster->GetInstanceScript())
                        if (pInstance->instance->Is25ManRaid())
                            maxTargets = 8;

                    // Removing non player targets
                    for (itr = targets.begin(); itr != targets.end(); itr = next)
                    {
                        next = itr;
                        ++next;

                        if ((*itr)->GetTypeId() != TYPEID_PLAYER)
                            targets.remove(*itr);
                    }

                    // Removing random targets while they're too numerous
                    while (targets.size() > maxTargets)
                    {
                        for (itr = targets.begin(); itr != targets.end(); itr = next)
                        {
                            next = itr;
                            ++next;

                            if (targets.size() > maxTargets && urand(0, 1))
                                targets.remove(*itr);
                        }
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_spirit_bolt_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_spirit_bolt_SpellScript();
        }
};

// Nullification Barrier - for Shield action purpose
class spell_nullification_barrier : public SpellScriptLoader
{
    public:
        spell_nullification_barrier() : SpellScriptLoader("spell_nullification_barrier") { }

        class spell_nullification_barrierSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_nullification_barrierSpellScript);

            void RemoveSoulFragments()
            {
                if (Creature* shield = GetClosestCreatureWithEntry(GetCaster(), NPC_SIPHONING_SHIELD, 200.0f))
                    shield->AI()->DoAction(ACTION_SOUL_REMOVE);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_nullification_barrierSpellScript::RemoveSoulFragments);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_nullification_barrierSpellScript();
        }
};

// GameObject - 211628 - Shroud of reversal
class go_inversion : public GameObjectScript
{
public:
    go_inversion() : GameObjectScript("go_inversion") { }

    struct go_inversionAI : public GameObjectAI
    {
        go_inversionAI(GameObject* go) : GameObjectAI(go) { }

        bool GossipHello(Player* /*player*/) override
        {
            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_inversionAI(go);
    }
};

// GameObject - 211626 - Nullification Barrier
class go_cancel : public GameObjectScript
{
public:
    go_cancel() : GameObjectScript("go_cancel") { }

    struct go_cancelAI : public GameObjectAI
    {
        go_cancelAI(GameObject* go) : GameObjectAI(go) { }

        bool GossipHello(Player* /*player*/) override
        {
            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_cancelAI(go);
    }
};

/// Created by spell 115817
class at_nullification_barrier : public AreaTriggerAI
{
public:
    at_nullification_barrier(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUpdate(uint32 /*p_Time*/) override
    {
        std::list<Unit*> l_TargetList;
        float l_Radius = 6.0f;
        Unit* l_Caster = at->GetCaster();

        if (!l_Caster)
            return;

        l_Caster->GetAttackableUnitListInRange(l_TargetList, l_Radius);

        if (!l_TargetList.empty())
        for (Unit* l_Target : l_TargetList)
            l_Target->CastSpell(l_Target, SPELL_NULLIFICATION_BARRIER, true);
    }

    void OnRemove() override
    {
        std::list<Unit*> l_TargetList;
        float l_Radius = 60.0f;
        Unit* l_Caster = at->GetCaster();

        if (!l_Caster)
            return;

        l_Caster->GetAttackableUnitListInRange(l_TargetList, l_Radius);

        for (Unit* l_Unit : l_TargetList)
        {
            if (l_Unit->HasAura(SPELL_NULLIFICATION_BARRIER))
                l_Unit->RemoveAura(SPELL_NULLIFICATION_BARRIER);
        }
    }
};

void AddSC_boss_feng()
{
    new boss_feng();                        ///< 60009
    new mob_lightning_fist();               ///< 60241
    new mob_wild_spark();                   ///< 60438
    new mob_siphon_shield();                ///< 60627
    new mob_soul_fragment();                ///< 60781
    new spell_mogu_epicenter();             ///< 116040
    new spell_mogu_wildfire_spark();        ///< 116583
    new spell_wildfire_spark();             ///< 116784
    new spell_wildfire_infusion_stacks();   ///< 116821
    new spell_mogu_wildfire_infusion();     ///< 116816
    new spell_draw_flame();                 ///< 116711
    new spell_mogu_arcane_velocity();       ///< 116365
    new spell_mogu_arcane_resonance();      ///< 116434
    new spell_mogu_inversion();             ///< 118300 - 118302 - 118304 - 118305 - 118307 - 118308 - 132296 - 132297 - 132298
    new spell_spirit_bolt();                ///< 118530
    new spell_nullification_barrier();      ///< 115817
    new go_inversion;                       ///< 211628
    new go_cancel;                          ///< 211626
    RegisterAreaTriggerAI(at_nullification_barrier);         ///< 115817
}
