/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

    // Spirit of the Shield ( Heroic )
    SPELL_SHADOWBURN                    = 131792,
    SPELL_SIPHONING_SHIELD              = 117203,
    SPELL_CHAINS_OF_SHADOW              = 118783,

    // Stolen Essences of Stone
    SPELL_NULLIFICATION_BARRIER         = 115817,
    SPELL_SHROUD_OF_REVERSAL            = 115911,

    // Siphoning Shield
    SPELL_SHIELD_VISUAL                 = 117763,
    SPELL_SHIELD_GROUND_VISUAL          = 117240,
    SPELL_SUMMON_SOUL                   = 117717,
    SPELL_SHIELD_HEAL                   = 118071,
    SPELL_HIDE_OFF_HAND_SHIELD          = 121296,

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
    // Inversion bouclier siphon        = 118471,
    SPELL_SHADOWBURN_INVERSION          = 132296,
    SPELL_LIGHTNING_LASH_INVERSION      = 132297,
    SPELL_ARCANE_SHOCK_INVERSION        = 132298
};

enum eEvents
{
    EVENT_DOT_ATTACK                    = 1,
    EVENT_RE_ATTACK                     = 2,

    EVENT_LIGHTNING_FISTS               = 3,
    EVENT_EPICENTER                     = 4,

    EVENT_WILDFIRE_SPARK                = 5,
    EVENT_DRAW_FLAME                    = 6,

    EVENT_ARCANE_VELOCITY               = 7,
    EVENT_ARCANE_VELOCITY_END           = 8,
    EVENT_ARCANE_RESONANCE              = 9,
    
    EVENT_SIPHONING_SHIELD              = 10,
    EVENT_SIPHONING_SHIELD_END          = 11,
    EVENT_CHAINS_OF_SHADOW              = 12
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
    TALK_INTRO        = 0,
    TALK_AGGRO        = 1,
    TALK_DEATH        = 2,
    TALK_SLAY         = 3,
    TALK_PHASE_FIST   = 4,
    TALK_PHASE_SHIELD = 5,
    TALK_PHASE_SPEAR  = 6,
    TALK_PHASE_STAFF  = 7,
};

enum EquipId
{
    EQUIP_ID_FISTS  = 82769,
    EQUIP_ID_SPEAR  = 82770,
    EQUIP_ID_STAFF  = 82771,
    EQUIP_ID_SHIELD = 82772, // ????
};

enum MovementId
{
    POINT_SHIELD    = 1,
};

Position modPhasePositions[4] =
{
    {4063.26f, 1320.50f, 466.30f, 5.5014f}, // Phase Fist
    {4021.17f, 1320.50f, 466.30f, 3.9306f}, // Phase Spear
    {4021.17f, 1362.80f, 466.30f, 2.0378f}, // Phase Staff
    {4063.26f, 1362.80f, 466.30f, 0.7772f}, // Phase Shield
};

uint32 statueEntryInOrder[4] = { GOB_FIST_STATUE,   GOB_SPEAR_STATUE,   GOB_STAFF_STATUE,   GOB_SHIELD_STATUE   };
uint32 controlerVisualId[4]  = { SPELL_VISUAL_FIST, SPELL_VISUAL_SPEAR, SPELL_VISUAL_STAFF, SPELL_VISUAL_SHIELD };
uint32 fengVisualId[4]       = { SPELL_SPIRIT_FIST, SPELL_SPIRIT_SPEAR, SPELL_SPIRIT_STAFF, SPELL_SPIRIT_SHIELD };

#define MAX_INVERSION_SPELLS    9
uint32 inversionMatching[MAX_INVERSION_SPELLS][2] =
{
    {SPELL_EPICENTER,        SPELL_EPICENTER_INVERSION          },
    {SPELL_LIGHTNING_FISTS,  SPELL_LIGHTNING_FISTS_INVERSION    },
    {SPELL_ARCANE_RESONANCE, SPELL_ARCANE_RESONANCE_INVERSION   },
    {SPELL_ARCANE_VELOCITY,  SPELL_ARCANE_VELOCITY_INVERSION    },
    {SPELL_WILDFIRE_SPARK,   SPELL_WILDFIRE_SPARK_INVERSION     },
    {SPELL_FLAMING_SPEAR,    SPELL_FLAMING_SPEAR_INVERSION      },
    {SPELL_SHADOWBURN,       SPELL_SHADOWBURN_INVERSION         },
    {SPELL_LIGHTNING_LASH,   SPELL_LIGHTNING_LASH_INVERSION     },
    {SPELL_ARCANE_SHOCK,     SPELL_ARCANE_SHOCK_INVERSION       }
};

#define MAX_DIST    60
Position centerPos = {4041.979980f, 1341.859985f, 466.388000f, 3.140160f};

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

            uint64 phaseControllerList[4];
            uint64 shieldGUID;

            std::list<uint32> phaseList;

            void Reset()
            {
                _Reset();

                for (auto visualSpellId: fengVisualId)
                    me->RemoveAurasDueToSpell(visualSpellId);

                SetEquipmentSlots(false, 0, 0, EQUIP_NO_CHANGE);

                if (pInstance)
                {
                    if (pInstance->GetBossState(DATA_FENG) != DONE)
                        pInstance->SetBossState(DATA_FENG, NOT_STARTED);

                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FLAMING_SPEAR);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NULLIFICATION_BARRIER_PLAYERS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INVERSION);

                    // Desactivate old statue
                    if (GameObject* oldStatue = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(pInstance->GetData64(statueEntryInOrder[actualPhase - 1]))))
                    {
                        oldStatue->SetLootState(GO_READY);
                        oldStatue->UseDoorOrButton();
                    }

                    if (GameObject* inversionGob = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(pInstance->GetData64(GOB_INVERSION))))
                        inversionGob->Respawn();

                    if (GameObject* cancelGob = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(pInstance->GetData64(GOB_CANCEL))))
                        cancelGob->Respawn();
                }

                for (uint8 i = 0; i < 4; ++i)
                {
                    if (pInstance)
                        if (Creature* phaseController = pInstance->instance->GetCreature(pInstance->GetObjectGuid(phaseControllerList[i])))
                            phaseController->DespawnOrUnsummon();

                    phaseControllerList[i] = 0;

                    if (Creature* phaseController = me->SummonCreature(NPC_PHASE_CONTROLLER, modPhasePositions[i].GetPositionX(), modPhasePositions[i].GetPositionY(), modPhasePositions[i].GetPositionZ(), modPhasePositions[i].GetOrientation()))
                        phaseControllerList[i] = phaseController->GetGUID().GetEntry();
                }

                isWaitingForPhase = false;
                actualPhase  = PHASE_NONE;
                nextPhasePct = 95;
                dotSpellId = 0;
                shieldGUID = 0;
            }

            void JustDied(Unit* attacker)
            {
                Talk(TALK_DEATH);
                _JustDied();

                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FLAMING_SPEAR);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NULLIFICATION_BARRIER_PLAYERS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INVERSION);

                    if (GameObject* inversionGob = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(pInstance->GetData64(GOB_INVERSION))))
                        inversionGob->Delete();

                    if (GameObject* cancelGob = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(pInstance->GetData64(GOB_CANCEL))))
                        cancelGob->Delete();
                }

                if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, 61348, 100.0f, true))
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
            }

            void EnterCombat(Unit* attacker)
            {
                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    pInstance->SetBossState(DATA_FENG, IN_PROGRESS);
                }
                Talk(TALK_AGGRO);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id >= 1 && id <= 4)
                    PrepareNewPhase(id);
            }

            void DoAction(int32 action)
            {
                if (action == ACTION_SPARK)
                    me->AddAura(SPELL_WILDFIRE_INFUSION_STACK, me);
                
                if (action == ACTION_SHIELD_END)
                    events.RescheduleEvent(EVENT_SIPHONING_SHIELD_END, 500);
            }

            void PrepareNewPhase(uint8 newPhase)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DOT_ATTACK, 15000);
                events.ScheduleEvent(EVENT_RE_ATTACK,  500);

                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->Clear();

                if (Creature* controler = GetClosestCreatureWithEntry(me, NPC_PHASE_CONTROLLER, 20.0f))
                    controler->DespawnOrUnsummon();

                if (pInstance)
                {
                    if (GameObject* newStatue = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(pInstance->GetData64(statueEntryInOrder[newPhase - 1]))))
                    {
                        newStatue->SetLootState(GO_READY);
                        newStatue->UseDoorOrButton();
                    }
                }

                for (auto visualSpellId: fengVisualId)
                    me->RemoveAurasDueToSpell(visualSpellId);

                me->AddAura(fengVisualId[newPhase - 1], me);
                me->CastSpell(me, SPELL_DRAW_ESSENCE, true);

                if (instance->instance->IsHeroic())
                    me->CastSpell(me, SPELL_STRENGHT_OF_SPIRIT, true);

                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                
                if (actualPhase == PHASE_SPEAR)
                {
                    summons.DespawnAll();
                    me->RemoveAura(SPELL_WILDFIRE_INFUSION);
                }

                switch (newPhase)
                {
                    case PHASE_FIST:
                    {
                        dotSpellId = SPELL_LIGHTNING_LASH;
                        events.ScheduleEvent(EVENT_LIGHTNING_FISTS,  20000, PHASE_FIST);
                        events.ScheduleEvent(EVENT_EPICENTER,        35000, PHASE_FIST);
                        SetEquipmentSlots(false, EQUIP_ID_FISTS, EQUIP_ID_FISTS, EQUIP_NO_CHANGE);
                        Talk(TALK_PHASE_FIST);
                        break;
                    }
                    case PHASE_SPEAR:
                    {
                        dotSpellId = SPELL_FLAMING_SPEAR;
                        events.ScheduleEvent(EVENT_WILDFIRE_SPARK,   30000, PHASE_SPEAR);
                        events.ScheduleEvent(EVENT_DRAW_FLAME,       40000, PHASE_SPEAR);
                        SetEquipmentSlots(false, EQUIP_ID_SPEAR, 0, EQUIP_NO_CHANGE);
                        Talk(TALK_PHASE_SPEAR);
                        break;
                    }
                    case PHASE_STAFF:
                    {
                        dotSpellId = SPELL_ARCANE_SHOCK;
                        events.ScheduleEvent(EVENT_ARCANE_VELOCITY,  25000, PHASE_STAFF);
                        events.ScheduleEvent(EVENT_ARCANE_RESONANCE, 40000, PHASE_STAFF);
                        SetEquipmentSlots(false, EQUIP_ID_STAFF, 0, EQUIP_NO_CHANGE);
                        Talk(TALK_PHASE_STAFF);
                        break;
                    }
                    case PHASE_SHIELD:
                    {
                        dotSpellId = SPELL_SHADOWBURN;
                        events.ScheduleEvent(EVENT_CHAINS_OF_SHADOW, urand(10000, 20000));
                        events.ScheduleEvent(EVENT_SIPHONING_SHIELD, 30000, PHASE_SHIELD);
                        SetEquipmentSlots(false, 0, EQUIP_ID_SHIELD, EQUIP_NO_CHANGE);
                        Talk(TALK_PHASE_SHIELD);
                        break;
                    }
                    default:
                        break;
                }

                isWaitingForPhase = false;
                actualPhase = newPhase;
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_SHIELD)
                    shieldGUID = summon->GetGUID().GetEntry();
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);

                if (summon->GetEntry() == NPC_SHIELD)
                    shieldGUID = 0;
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
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

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    if (urand(0, 2))
                        Talk(TALK_SLAY);
            }

            void OnAddThreat(Unit* /*victim*/, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
            {
                if (isWaitingForPhase)
                    fThreat = 0;
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
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
                        uint8 newPhase = 255;

                        if (pInstance->instance->IsHeroic())
                        {
                            if (Creature* nearestController = GetClosestCreatureWithEntry(me, NPC_PHASE_CONTROLLER, 200.0f))
                            {
                                for (uint8 i = 0; i < 4; ++i)
                                {
                                    if (nearestController->GetGUID().GetEntry() == phaseControllerList[i])
                                    {
                                        newPhase = i + 1;
                                        break;
                                    }
                                }
                            }
                            else
                                newPhase = actualPhase + 1;
                        }
                        else // NM / LFR
                        {
                            newPhase = actualPhase + 1;
                        }

                        if (newPhase > 4)
                            return;

                        isWaitingForPhase = true;
                        me->InterruptNonMeleeSpells(true);

                        if (Creature* phaseController = instance->instance->GetCreature(pInstance->GetObjectGuid(phaseControllerList[newPhase - 1])))
                            phaseController->AddAura(controlerVisualId[newPhase - 1], phaseController);

                        me->GetMotionMaster()->MovePoint(newPhase, modPhasePositions[newPhase - 1].GetPositionX(), modPhasePositions[newPhase - 1].GetPositionY(), modPhasePositions[newPhase - 1].GetPositionZ());

                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

                        uint32 reduction = IsHeroic() ? 25: 32;
                        nextPhasePct >= reduction ? nextPhasePct-= reduction: nextPhasePct = 0;
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
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
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, dotSpellId, false);

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
                        //me->MonsterTextEmote("Feng le Maudit commence a incanter un violent Epicentre !", 0, true);
                        me->CastSpell(me, SPELL_EPICENTER, false);
                        events.ScheduleEvent(EVENT_EPICENTER, 35000);
                        break;
                    }
                    // Spear Phase
                    case EVENT_WILDFIRE_SPARK:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            //me->MonsterTextEmote("Vous avez ete affecte par une Etincelle !", target, true);
                            me->CastSpell(target, SPELL_WILDFIRE_SPARK, false);
                        }
                        events.ScheduleEvent(EVENT_WILDFIRE_SPARK, urand(25000, 35000));
                        break;
                    }
                    case EVENT_DRAW_FLAME: 
                    {
                        //me->MonsterTextEmote("Feng le Maudit commence a attirer les flammes a son arme !", 0, true);
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
                    // Shield Phase
                    case EVENT_CHAINS_OF_SHADOW:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                            me->CastSpell(target, SPELL_CHAINS_OF_SHADOW, false);
                        events.ScheduleEvent(EVENT_CHAINS_OF_SHADOW, urand(10000, 20000));
                        break;
                    }
                    case EVENT_SIPHONING_SHIELD:
                    {
                        me->CastSpell(me, SPELL_SIPHONING_SHIELD, me);
                        me->AddAura(SPELL_HIDE_OFF_HAND_SHIELD, me);
                        events.ScheduleEvent(EVENT_SIPHONING_SHIELD_END, 30000);
                        break;
                    }
                    case EVENT_SIPHONING_SHIELD_END:
                    {
                        if (pInstance)
                        {
                            if (Creature* shield = pInstance->instance->GetCreature(pInstance->GetObjectGuid(shieldGUID)))
                            {
                                shield->AI()->DoAction(ACTION_SHIELD_END);
                                shield->DespawnOrUnsummon();
                            }
                        }
                        me->RemoveAurasDueToSpell(SPELL_HIDE_OFF_HAND_SHIELD);
                        events.ScheduleEvent(EVENT_SIPHONING_SHIELD, urand(30000, 40000));
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            private:
                void CheckPlatform()
                {
                    if (!me->IsInCombat())
                        return;

                    if ((me->GetPositionX() - centerPos.GetPositionX()) > 37.0f ||
                        (me->GetPositionX() - centerPos.GetPositionX()) < -37.0f ||
                        (me->GetPositionY() - centerPos.GetPositionY()) > 37.0f ||
                        (me->GetPositionY() - centerPos.GetPositionY()) < -37.0f)
                        me->AI()->EnterEvadeMode();
                }
        };

        CreatureAI* GetAI(Creature* creature) const
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

class mob_lightning_fist : public CreatureScript
{
    public:
        mob_lightning_fist() : CreatureScript("mob_lightning_fist") {}

        struct mob_lightning_fistAI : public ScriptedAI
        {
            mob_lightning_fistAI(Creature* creature) : ScriptedAI(creature)
            {}

            uint32 checkNearPlayerTimer;

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_FIST_BARRIER, me);
                me->AddAura(SPELL_FIST_VISUAL, me);

                float x = 0, y = 0;
                //GetPositionWithDistInOrientation(me, 100.0f, me->GetOrientation(), x, y);

                me->GetMotionMaster()->MoveCharge(x, y, me->GetPositionZ(), 24.0f, 1, false);

                checkNearPlayerTimer = 500;
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                    me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 diff)
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_lightning_fistAI(creature);
        }
};

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

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, 116717, true); // Fire aura
                me->CastSpell(me, SPELL_ARCHIMONDES_FIRE, true); // Fire visual
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveRandom(5.0f);
            }
    
            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_DRAW_FLAME)
                {
                    me->GetMotionMaster()->Clear();
                    me->SetSpeed(MOVE_RUN, 5.0f);
                    me->SetSpeed(MOVE_WALK, 5.0f);
                    me->GetMotionMaster()->MovePoint(1, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                    if (InstanceScript* pInstance = me->GetInstanceScript())
                        if (Creature* feng = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_FENG))))
                        {
                            feng->AI()->DoAction(ACTION_SPARK);
                            me->DespawnOrUnsummon(500);
                        }
            }

            void UpdateAI(uint32 diff)
            {
                if (pInstance)
                    if (pInstance->GetBossState(DATA_FENG) != IN_PROGRESS)
                        me->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_wild_sparkAI(creature);
        }
};

class mob_feng_shield : public CreatureScript
{
    public:
        mob_feng_shield() : CreatureScript("mob_feng_shield") {}

        struct mob_feng_shieldAI : public ScriptedAI
        {
            mob_feng_shieldAI(Creature* creature) : ScriptedAI(creature), summons(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            SummonList summons;
            uint32 checkSoulTimer;

            void Reset()
            {
                if (!pInstance)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                summons.empty();

                checkSoulTimer = 1000;
                me->CastSpell(me, SPELL_SHIELD_VISUAL, true);
                me->CastSpell(me, SPELL_SHIELD_GROUND_VISUAL, true);
                
                uint8 maxSoulFragment = pInstance->instance->Is25ManRaid() ? 10: 5;
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 200.0f);
                Trinity::Containers::RandomResizeList(playerList, maxSoulFragment);
                
                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    if (Player* player = (*itr))
                        me->CastSpell(player, SPELL_SUMMON_SOUL, true);
            }

            Creature* GetFeng()
            {
                return (pInstance) ? pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_FENG))) : NULL;
            }

            void JustDied(Unit* attacker)
            {
                if (Creature* feng = GetFeng())
                    feng->AI()->DoAction(ACTION_SHIELD_END);
            }

            void DoAction(int32 action)
            {
                if (action == ACTION_SHIELD_END)
                {
                    uint8 remainingSoul = summons.size();
                    
                    if (Creature* feng = GetFeng())
                        for (uint8 i = 0; i < remainingSoul; ++i)
                            feng->CastSpell(feng, SPELL_SHIELD_HEAL, true);
                    
                    summons.DespawnEntry(NPC_SOUL_FRAGMENT);
                }
            }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == NPC_SOUL_FRAGMENT)
                    summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                if (summon->GetEntry() == NPC_SOUL_FRAGMENT)
                    summons.Despawn(summon);
            }

            void UpdateAI(uint32 diff)
            {
                if (checkSoulTimer <= diff)
                {
                    if (Creature* soulFragment = GetClosestCreatureWithEntry(me, NPC_SOUL_FRAGMENT, 2.0f))
                    {
                        soulFragment->DespawnOrUnsummon();

                        if (Creature* feng = GetFeng())
                            feng->CastSpell(feng, SPELL_SHIELD_HEAL, true);
                    }
                    checkSoulTimer = 1000;
                }
                else
                    checkSoulTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_feng_shieldAI(creature);
        }
};

// Todo : Soul Visual
class mob_soul_fragment : public CreatureScript
{
    public:
        mob_soul_fragment() : CreatureScript("mob_soul_fragment") {}

        struct mob_soul_fragmentAI : public ScriptedAI
        {
            mob_soul_fragmentAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint32 checkMovementTimer;
            uint64 shieldGUID;

            void Reset()
            {
                checkMovementTimer = 1000;
                shieldGUID = 0;
            }

            void IsSummonedBy(Unit* summoner)
            {
                shieldGUID = summoner->GetGUID();
                me->GetMotionMaster()->MovePoint(POINT_SHIELD, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
            }

            void UpdateAI(uint32 diff)
            {
                if (checkMovementTimer <= diff)
                {
                    if (!me->HasUnitMovementFlag(MOVEMENTFLAG_ROOT) && me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE)
                    {
                        if (Creature* shield = pInstance->instance->GetCreature(pInstance->GetObjectGuid(shieldGUID)))
                        {
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveIdle();
                            me->GetMotionMaster()->MovePoint(POINT_SHIELD, shield->GetPositionX(), shield->GetPositionY(), shield->GetPositionZ());
                        }
                    }
                    checkMovementTimer = 1000;
                }
                else
                    checkMovementTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_soul_fragmentAI(creature);
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

                if (distance >= 0 && distance <= 60)
                    SetHitDamage(GetHitDamage() * (1 - (distance / MAX_DIST)));
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_mogu_epicenter_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const
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

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_mogu_wildfire_spark_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mogu_wildfire_spark_SpellScript();
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

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_wildfire_infusion_stacks_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_wildfire_infusion_stacks_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
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

            void Register()
            {
                AfterCast += SpellCastFn(spell_mogu_wildfire_infusion_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
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

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_draw_flame_SpellScript::ReplaceTarget, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
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

                if (distance >= 0 && distance <= 60)
                    SetHitDamage(GetHitDamage() * (distance / MAX_DIST));
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_mogu_arcane_velocity_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const
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

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mogu_arcane_resonance_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnHit                    += SpellHitFn(spell_mogu_arcane_resonance_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const
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

            void Register()
            {
                OnEffectApply     += AuraEffectApplyFn(spell_mogu_inversion_AuraScript::OnApply,   EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_mogu_inversion_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mogu_inversion_AuraScript();
        }
};

// GameObject - 211628
class go_inversion : public GameObjectScript
{
    public:
        go_inversion() : GameObjectScript("go_inversion") { }

        struct go_inversionAI : public GameObjectAI
        {
            go_inversionAI(GameObject* go) : GameObjectAI(go) { }

            bool GossipHello(Player* player)
            {
                if (!player->IsInCombat())
                    return true;

                //if (player->GetRoleForGroup(player->GetSpecializationId(player->GetActiveSpec())) != ROLES_TANK)
                //    return true;

                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const
        {
            return new go_inversionAI(go);
        }
};

// GameObject - 211626
class go_cancel : public GameObjectScript
{
    public:
        go_cancel() : GameObjectScript("go_cancel") { }

        struct go_cancelAI : public GameObjectAI
        {
            go_cancelAI(GameObject* go) : GameObjectAI(go) { }

            bool GossipHello(Player* player)
            {
                if (!player->IsInCombat())
                    return true;

                //if (player->GetRoleForGroup(player->GetSpecializationId(player->GetActiveSpec())) != ROLES_TANK)
                //    return true;

                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const
        {
            return new go_cancelAI(go);
        }
};

void AddSC_boss_feng()
{
    new boss_feng();
    new mob_lightning_fist();
    new mob_wild_spark();
    new mob_feng_shield();
    new mob_soul_fragment();
    new spell_mogu_epicenter();
    new spell_mogu_wildfire_spark();
    new spell_wildfire_infusion_stacks();
    new spell_mogu_wildfire_infusion();
    new spell_draw_flame();
    new spell_mogu_arcane_velocity();
    new spell_mogu_arcane_resonance();
    new spell_mogu_inversion();
    new go_inversion();
    new go_cancel();
}
