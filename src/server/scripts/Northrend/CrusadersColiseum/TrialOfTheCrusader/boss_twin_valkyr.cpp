/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

// Known bugs:
//    - They should be floating but they aren't respecting the floor =(
//    - Hardcoded bullets spawner

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"
#include "CellImpl.h"
#include "trial_of_the_crusader.h"

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_NIGHT               = 1,
    SAY_LIGHT               = 2,
    EMOTE_VORTEX            = 3,
    EMOTE_TWINK_PACT        = 4,
    SAY_TWINK_PACT          = 5,
    SAY_KILL_PLAYER         = 6,
    SAY_BERSERK             = 7,
    SAY_DEATH               = 8
};

enum Equipment
{
    EQUIP_MAIN_1         = 9423,
    EQUIP_MAIN_2         = 37377
};

enum Summons
{
    NPC_BULLET_CONTROLLER        = 34743,

    NPC_BULLET_DARK              = 34628,
    NPC_BULLET_LIGHT             = 34630
};

enum BossSpells
{
    SPELL_LIGHT_TWIN_SPIKE      = 66075,
    SPELL_LIGHT_SURGE           = 65766,
    SPELL_LIGHT_SHIELD          = 65858,
    SPELL_LIGHT_TWIN_PACT       = 65876,
    SPELL_LIGHT_VORTEX          = 66046,
    SPELL_LIGHT_VORTEX_DAMAGE   = 66048,
    SPELL_LIGHT_TOUCH           = 67297,
    SPELL_LIGHT_ESSENCE         = 65686,
    SPELL_EMPOWERED_LIGHT       = 65748,
    SPELL_TWIN_EMPATHY_LIGHT    = 66133,
    SPELL_UNLEASHED_LIGHT       = 65795,

    SPELL_DARK_TWIN_SPIKE       = 66069,
    SPELL_DARK_SURGE            = 65768,
    SPELL_DARK_SHIELD           = 65874,
    SPELL_DARK_TWIN_PACT        = 65875,
    SPELL_DARK_VORTEX           = 66058,
    SPELL_DARK_VORTEX_DAMAGE    = 66059,
    SPELL_DARK_TOUCH            = 67282,
    SPELL_DARK_ESSENCE          = 65684,
    SPELL_EMPOWERED_DARK        = 65724,
    SPELL_TWIN_EMPATHY_DARK     = 66132,
    SPELL_UNLEASHED_DARK        = 65808,

    SPELL_CONTROLLER_PERIODIC   = 66149,
    SPELL_POWER_TWINS           = 65879,
    SPELL_BERSERK               = 64238,
    SPELL_POWERING_UP           = 67590,
    SPELL_SURGE_OF_SPEED        = 65828
};

#define SPELL_DARK_ESSENCE_HELPER RAID_MODE<uint32>(65684, 67176, 67177, 67178)
#define SPELL_LIGHT_ESSENCE_HELPER RAID_MODE<uint32>(65686, 67222, 67223, 67224)

#define SPELL_POWERING_UP_HELPER RAID_MODE<uint32>(67590, 67602, 67603, 67604)

#define SPELL_UNLEASHED_DARK_HELPER RAID_MODE<uint32>(65808, 67172, 67173, 67174)
#define SPELL_UNLEASHED_LIGHT_HELPER RAID_MODE<uint32>(65795, 67238, 67239, 67240)

enum Actions
{
    ACTION_VORTEX   = 0,
    ACTION_PACT     = 1
};

#define ESSENCE_REMOVE 0
#define ESSENCE_APPLY 1

class OrbsDespawner : public BasicEvent
{
    public:
        explicit OrbsDespawner(Creature* creature) : _creature(creature)
        {
        }

        bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
        {
            Trinity::CreatureWorker<OrbsDespawner> worker(_creature, *this);
            _creature->VisitNearbyGridObject(5000.0f, worker);
            return true;
        }

        void operator()(Creature* creature) const
        {
            switch (creature->GetEntry())
            {
                case NPC_BULLET_DARK:
                case NPC_BULLET_LIGHT:
                    creature->DespawnOrUnsummon();
                    return;
                default:
                    return;
            }
        }

    private:
        Creature* _creature;
};

struct boss_twin_baseAI : public BossAI
{
    boss_twin_baseAI(Creature* creature) : BossAI(creature, BOSS_VALKIRIES)
    {
    }

    void Reset() override
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_PASSIVE);
        me->ModifyAuraState(AuraState, true);
        /* Uncomment this once that they are floating above the ground
        me->SetLevitate(true);
        me->SetFlying(true); */
        IsBerserk = false;

        SpecialAbilityTimer = 1*MINUTE*IN_MILLISECONDS;
        SpikeTimer = 20*IN_MILLISECONDS;
        TouchTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
        BerserkTimer = IsHeroic() ? 6*MINUTE*IN_MILLISECONDS : 10*MINUTE*IN_MILLISECONDS;

        summons.DespawnAll();
    }

    void JustReachedHome() override
    {
        instance->SetBossState(BOSS_VALKIRIES, FAIL);

        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiId)
        {
            case 1:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            Talk(SAY_KILL_PLAYER);
            instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELIGIBLE, 0);
        }
    }

    void JustSummoned(Creature* summoned) override
    {
        summons.Summon(summoned);
    }

    void SummonedCreatureDespawn(Creature* summoned) override
    {
        switch (summoned->GetEntry())
        {
            case NPC_LIGHT_ESSENCE:
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LIGHT_ESSENCE_HELPER);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_POWERING_UP_HELPER);
                break;
            case NPC_DARK_ESSENCE:
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DARK_ESSENCE_HELPER);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_POWERING_UP_HELPER);
                break;
            case NPC_BULLET_CONTROLLER:
                me->m_Events.AddEvent(new OrbsDespawner(me), me->m_Events.CalculateTime(100));
                break;
            default:
                break;
        }
        summons.Despawn(summoned);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        if (Creature* pSister = GetSister())
        {
            if (!pSister->IsAlive())
            {
                me->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                pSister->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                _JustDied();
            }
            else
            {
                me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                instance->SetBossState(BOSS_VALKIRIES, SPECIAL);
            }
        }
        summons.DespawnAll();
    }

    // Called when sister pointer needed
    Creature* GetSister()
    {
        return Unit::GetCreature((*me), instance->GetData64(SisterNpcId));
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->SetInCombatWithZone();
        if (Creature* pSister = GetSister())
        {
            me->AddAura(MyEmphatySpellId, pSister);
            pSister->SetInCombatWithZone();
        }
        instance->SetBossState(BOSS_VALKIRIES, IN_PROGRESS);

        Talk(SAY_AGGRO);
        DoCast(me, SurgeSpellId);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_VORTEX:
                Stage = me->GetEntry() == NPC_LIGHTBANE ? 2 : 1;
                break;
            case ACTION_PACT:
                Stage = me->GetEntry() == NPC_LIGHTBANE ? 1 : 2;
                break;
            default:
                break;
        }
    }

    void EnableDualWield(bool mode = true)
    {
        SetEquipmentSlots(false, Weapon, mode ? Weapon : int32(EQUIP_UNEQUIP), EQUIP_UNEQUIP);
        me->SetCanDualWield(mode);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!instance || !UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (Stage)
        {
            case 0:
                break;
            case 1: // Vortex
                if (SpecialAbilityTimer <= diff)
                {
                    if (Creature* pSister = GetSister())
                        pSister->AI()->DoAction(ACTION_VORTEX);
                    Talk(VortexEmote);
                    DoCastAOE(VortexSpellId);
                    Stage = 0;
                    SpecialAbilityTimer = 1*MINUTE*IN_MILLISECONDS;
                }
                else
                    SpecialAbilityTimer -= diff;
                break;
            case 2: // Shield + Pact
                if (SpecialAbilityTimer <= diff)
                {
                    Talk(EMOTE_TWINK_PACT);
                    Talk(SAY_TWINK_PACT);
                    if (Creature* pSister = GetSister())
                    {
                        pSister->AI()->DoAction(ACTION_PACT);
                        pSister->CastSpell(pSister, SPELL_POWER_TWINS, false);
                    }
                    DoCast(me, ShieldSpellId);
                    DoCast(me, TwinPactSpellId);
                    Stage = 0;
                    SpecialAbilityTimer = 1*MINUTE*IN_MILLISECONDS;
                }
                else
                    SpecialAbilityTimer -= diff;
                break;
            default:
                break;
        }

        if (SpikeTimer <= diff)
        {
            DoCastVictim(SpikeSpellId);
            SpikeTimer = 20*IN_MILLISECONDS;
        }
        else
            SpikeTimer -= diff;

        if (IsHeroic() && TouchTimer <= diff)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true, OtherEssenceSpellId))
                me->CastCustomSpell(TouchSpellId, SPELLVALUE_MAX_TARGETS, 1, target, false);
            TouchTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
        }
        else
            TouchTimer -= diff;

        if (!IsBerserk && BerserkTimer <= diff)
        {
            DoCast(me, SPELL_BERSERK);
            Talk(SAY_BERSERK);
            IsBerserk = true;
        }
        else
            BerserkTimer -= diff;

        DoMeleeAttackIfReady();
    }

    protected:
        AuraStateType AuraState;

        uint8  Stage;
        bool   IsBerserk;

        uint32 Weapon;
        uint32 SpecialAbilityTimer;
        uint32 SpikeTimer;
        uint32 TouchTimer;
        uint32 BerserkTimer;

        int32 VortexEmote;
        uint32 SisterNpcId;
        uint32 MyEmphatySpellId;
        uint32 OtherEssenceSpellId;
        uint32 SurgeSpellId;
        uint32 VortexSpellId;
        uint32 ShieldSpellId;
        uint32 TwinPactSpellId;
        uint32 SpikeSpellId;
        uint32 TouchSpellId;
};

class boss_fjola : public CreatureScript
{
    public:
        boss_fjola() : CreatureScript("boss_fjola") { }

        struct boss_fjolaAI : public boss_twin_baseAI
        {
            boss_fjolaAI(Creature* creature) : boss_twin_baseAI(creature)
            {
            }

            void Reset() override
            {
                SetEquipmentSlots(false, EQUIP_MAIN_1, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                Stage = 0;
                Weapon = EQUIP_MAIN_1;
                AuraState = AURA_STATE_UNKNOWN22;
                VortexEmote = EMOTE_VORTEX;
                SisterNpcId = NPC_DARKBANE;
                MyEmphatySpellId = SPELL_TWIN_EMPATHY_DARK;
                OtherEssenceSpellId = SPELL_DARK_ESSENCE_HELPER;
                SurgeSpellId = SPELL_LIGHT_SURGE;
                VortexSpellId = SPELL_LIGHT_VORTEX;
                ShieldSpellId = SPELL_LIGHT_SHIELD;
                TwinPactSpellId = SPELL_LIGHT_TWIN_PACT;
                TouchSpellId = SPELL_LIGHT_TOUCH;
                SpikeSpellId = SPELL_LIGHT_TWIN_SPIKE;

                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT,  EVENT_START_TWINS_FIGHT);
                boss_twin_baseAI::Reset();
            }

            void EnterCombat(Unit* who) override
            {
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT,  EVENT_START_TWINS_FIGHT);

                me->SummonCreature(NPC_BULLET_CONTROLLER, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 0.0f, TEMPSUMMON_MANUAL_DESPAWN);
                boss_twin_baseAI::EnterCombat(who);
            }

            void EnterEvadeMode() override
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                boss_twin_baseAI::EnterEvadeMode();
            }

            void JustReachedHome() override
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));

                boss_twin_baseAI::JustReachedHome();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_fjolaAI>(creature);
        }
};

class boss_eydis : public CreatureScript
{
    public:
        boss_eydis() : CreatureScript("boss_eydis") { }

        struct boss_eydisAI : public boss_twin_baseAI
        {
            boss_eydisAI(Creature* creature) : boss_twin_baseAI(creature) { }

            void Reset() override
            {
                SetEquipmentSlots(false, EQUIP_MAIN_2, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                Stage = 1;
                Weapon = EQUIP_MAIN_2;
                AuraState = AURA_STATE_UNKNOWN19;
                VortexEmote = EMOTE_VORTEX;
                SisterNpcId = NPC_LIGHTBANE;
                MyEmphatySpellId = SPELL_TWIN_EMPATHY_LIGHT;
                OtherEssenceSpellId = SPELL_LIGHT_ESSENCE_HELPER;
                SurgeSpellId = SPELL_DARK_SURGE;
                VortexSpellId = SPELL_DARK_VORTEX;
                ShieldSpellId = SPELL_DARK_SHIELD;
                TwinPactSpellId = SPELL_DARK_TWIN_PACT;
                TouchSpellId = SPELL_DARK_TOUCH;
                SpikeSpellId = SPELL_DARK_TWIN_SPIKE;
                boss_twin_baseAI::Reset();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_eydisAI>(creature);
        }
};

class npc_essence_of_twin : public CreatureScript
{
    public:
        npc_essence_of_twin() : CreatureScript("npc_essence_of_twin") { }

        struct npc_essence_of_twinAI : public ScriptedAI
        {
            npc_essence_of_twinAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 GetData(uint32 data) const override
            {
                uint32 spellReturned = 0;
                switch (me->GetEntry())
                {
                    case NPC_LIGHT_ESSENCE:
                        spellReturned = (data == ESSENCE_REMOVE) ? SPELL_DARK_ESSENCE_HELPER : SPELL_LIGHT_ESSENCE_HELPER;
                        break;
                    case NPC_DARK_ESSENCE:
                        spellReturned = (data == ESSENCE_REMOVE) ? SPELL_LIGHT_ESSENCE_HELPER : SPELL_DARK_ESSENCE_HELPER;
                        break;
                    default:
                        break;
                }

                return spellReturned;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_essence_of_twinAI(creature);
        };

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            player->RemoveAurasDueToSpell(creature->GetAI()->GetData(ESSENCE_REMOVE));
            player->CastSpell(player, creature->GetAI()->GetData(ESSENCE_APPLY), true);
            player->CLOSE_GOSSIP_MENU();
            return true;
        }
};

struct npc_unleashed_ballAI : public ScriptedAI
{
    npc_unleashed_ballAI(Creature* creature) : ScriptedAI(creature)
    {
    }

    void MoveToNextPoint()
    {
        float x0 = ToCCommonLoc[1].GetPositionX(), y0 = ToCCommonLoc[1].GetPositionY(), r = 47.0f;
        float y = y0;
        float x = frand(x0 - r, x0 + r);
        float sq = pow(r, 2) - pow(x - x0, 2);
        float rt = sqrtf(fabs(sq));
        if (urand(0, 1))
            y = y0 + rt;
        else
            y = y0 - rt;
        me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());
    }

    void Reset() override
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_PASSIVE);
        me->SetDisableGravity(true);
        me->SetCanFly(true);
        SetCombatMovement(false);
        MoveToNextPoint();
        RangeCheckTimer = 0.5*IN_MILLISECONDS;
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiId)
        {
            case 0:
                if (urand(0, 3) == 0)
                    MoveToNextPoint();
                else
                    me->DisappearAndDie();
                break;
            default:
                break;
        }
    }

    protected:
        uint32 RangeCheckTimer;
};

class npc_unleashed_dark : public CreatureScript
{
    public:
        npc_unleashed_dark() : CreatureScript("npc_unleashed_dark") { }

        struct npc_unleashed_darkAI : public npc_unleashed_ballAI
        {
            npc_unleashed_darkAI(Creature* creature) : npc_unleashed_ballAI(creature) { }

            void UpdateAI(uint32 diff) override
            {
                if (RangeCheckTimer < diff)
                {
                    if (me->SelectNearestPlayer(3.0f))
                    {
                        DoCastAOE(SPELL_UNLEASHED_DARK_HELPER);
                        me->GetMotionMaster()->MoveIdle();
                        me->DespawnOrUnsummon(1*IN_MILLISECONDS);
                    }
                    RangeCheckTimer = 0.5*IN_MILLISECONDS;
                }
                else
                    RangeCheckTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_unleashed_darkAI(creature);
        }
};

class npc_unleashed_light : public CreatureScript
{
    public:
        npc_unleashed_light() : CreatureScript("npc_unleashed_light") { }

        struct npc_unleashed_lightAI : public npc_unleashed_ballAI
        {
            npc_unleashed_lightAI(Creature* creature) : npc_unleashed_ballAI(creature) { }

            void UpdateAI(uint32 diff) override
            {
                if (RangeCheckTimer < diff)
                {
                    if (me->SelectNearestPlayer(3.0f))
                    {
                        DoCastAOE(SPELL_UNLEASHED_LIGHT_HELPER);
                        me->GetMotionMaster()->MoveIdle();
                        me->DespawnOrUnsummon(1*IN_MILLISECONDS);
                    }
                    RangeCheckTimer = 0.5*IN_MILLISECONDS;
                }
                else
                    RangeCheckTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_unleashed_lightAI(creature);
        }
};

class npc_bullet_controller : public CreatureScript
{
    public:
        npc_bullet_controller() : CreatureScript("npc_bullet_controller") { }

        struct npc_bullet_controllerAI : public ScriptedAI
        {
            npc_bullet_controllerAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
            }

            void Reset() override
            {
                DoCastAOE(SPELL_CONTROLLER_PERIODIC);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_bullet_controllerAI(creature);
        }
};

class spell_powering_up : public SpellScriptLoader
{
    public:
        spell_powering_up() : SpellScriptLoader("spell_powering_up") { }

        class spell_powering_up_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_powering_up_SpellScript)

            uint32 spellId;
            uint32 poweringUp;

            bool Load() override
            {
                spellId = sSpellMgr->GetSpellIdForDifficulty(SPELL_SURGE_OF_SPEED, GetCaster());
                if (!sSpellMgr->GetSpellInfo(spellId))
                    return false;

                poweringUp = sSpellMgr->GetSpellIdForDifficulty(SPELL_POWERING_UP, GetCaster());
                if (!sSpellMgr->GetSpellInfo(poweringUp))
                    return false;

                return true;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    if (Aura* pAura = target->GetAura(poweringUp))
                    {
                        if (pAura->GetStackAmount() >= 100)
                        {
                            if (target->GetDummyAuraEffect(SPELLFAMILY_GENERIC, 2206, EFFECT_1))
                                target->CastSpell(target, SPELL_EMPOWERED_DARK, true);

                            if (target->GetDummyAuraEffect(SPELLFAMILY_GENERIC, 2845, EFFECT_1))
                                target->CastSpell(target, SPELL_EMPOWERED_LIGHT, true);

                            target->RemoveAurasDueToSpell(poweringUp);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_powering_up_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_powering_up_SpellScript();
        }
};

class spell_valkyr_essences : public SpellScriptLoader
{
    public:
        spell_valkyr_essences() : SpellScriptLoader("spell_valkyr_essences") { }

        class spell_valkyr_essences_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_valkyr_essences_AuraScript);

            uint32 spellId;

            bool Load() override
            {
                spellId = sSpellMgr->GetSpellIdForDifficulty(SPELL_SURGE_OF_SPEED, GetCaster());
                if (!sSpellMgr->GetSpellInfo(spellId))
                    return false;
                return true;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & /*absorbAmount*/)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    if (dmgInfo.GetSpellInfo())
                    {
                        if (uint32 poweringUp = sSpellMgr->GetSpellIdForDifficulty(SPELL_POWERING_UP, owner))
                        {
                            if (urand(0, 99) < 5)
                                GetTarget()->CastSpell(GetTarget(), spellId, true);

                            // Twin Vortex part
                            uint32 lightVortex = sSpellMgr->GetSpellIdForDifficulty(SPELL_LIGHT_VORTEX_DAMAGE, owner);
                            uint32 darkVortex = sSpellMgr->GetSpellIdForDifficulty(SPELL_DARK_VORTEX_DAMAGE, owner);
                            int32 stacksCount = int32(dmgInfo.GetSpellInfo()->Effects[EFFECT_0].CalcValue()) * 0.001 - 1;

                            if (lightVortex && darkVortex && stacksCount)
                            {
                                if (dmgInfo.GetSpellInfo()->Id == darkVortex || dmgInfo.GetSpellInfo()->Id == lightVortex)
                                {
                                    Aura* pAura = owner->GetAura(poweringUp);
                                    if (pAura)
                                    {
                                        pAura->ModStackAmount(stacksCount);
                                        owner->CastSpell(owner, poweringUp, true);
                                    }
                                    else
                                    {
                                        owner->CastSpell(owner, poweringUp, true);
                                        if (Aura* pTemp = owner->GetAura(poweringUp))
                                            pTemp->ModStackAmount(stacksCount);
                                    }
                                }
                            }

                            // Picking floating balls
                            uint32 unleashedDark = sSpellMgr->GetSpellIdForDifficulty(SPELL_UNLEASHED_DARK, owner);
                            uint32 unleashedLight = sSpellMgr->GetSpellIdForDifficulty(SPELL_UNLEASHED_LIGHT, owner);

                            if (unleashedDark && unleashedLight)
                            {
                                if (dmgInfo.GetSpellInfo()->Id == unleashedDark || dmgInfo.GetSpellInfo()->Id == unleashedLight)
                                {
                                    // need to do the things in this order, else players might have 100 charges of Powering Up without anything happening
                                    Aura* pAura = owner->GetAura(poweringUp);
                                    if (pAura)
                                    {
                                        // 2 lines together add the correct amount of buff stacks
                                        pAura->ModStackAmount(stacksCount);
                                        owner->CastSpell(owner, poweringUp, true);
                                    }
                                    else
                                    {
                                        owner->CastSpell(owner, poweringUp, true);
                                        if (Aura* pTemp = owner->GetAura(poweringUp))
                                            pTemp->ModStackAmount(stacksCount);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_valkyr_essences_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_valkyr_essences_AuraScript();
        }
};

class spell_power_of_the_twins : public SpellScriptLoader
{
    public:
        spell_power_of_the_twins() : SpellScriptLoader("spell_power_of_the_twins") { }

        class spell_power_of_the_twins_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_power_of_the_twins_AuraScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                {
                    if (Creature* Valk = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(GetCaster()->GetEntry())))
                        CAST_AI(boss_twin_baseAI, Valk->AI())->EnableDualWield(true);
                }
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                {
                    if (Creature* Valk = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(GetCaster()->GetEntry())))
                        CAST_AI(boss_twin_baseAI, Valk->AI())->EnableDualWield(false);
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_power_of_the_twins_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_power_of_the_twins_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);

            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_power_of_the_twins_AuraScript();
        }
};

void AddSC_boss_twin_valkyr()
{
    new boss_fjola();
    new boss_eydis();
    new npc_unleashed_light();
    new npc_unleashed_dark();
    new npc_essence_of_twin();
    new npc_bullet_controller();

    new spell_powering_up();
    new spell_valkyr_essences();
    new spell_power_of_the_twins();
}
