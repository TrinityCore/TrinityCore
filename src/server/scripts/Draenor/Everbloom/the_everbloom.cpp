/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "the_everbloom.h"

class spell_barrage_of_leaves : public SpellScriptLoader
{
public:
    spell_barrage_of_leaves() : SpellScriptLoader("spell_barrage_of_leaves") { }

    class spell_barrage_of_leaves_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_barrage_of_leaves_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex], true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_barrage_of_leaves_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
     
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_barrage_of_leaves_SpellScript();
    }
};

enum EverbloomNaturalistEnums
{
    SPELL_REVITALIZING_GROWTH   = 169287,
    SPELL_MOD_SCALE             = 123978,
    SPELL_BARRAGE_OF_LEAVES     = 165113,
    SPELL_COSMETIC_CHANNEL      = 164714,

    NPC_STALKER                 = 84677,
    NPC_AQUEOUS                 = 81821,
};

/// Everbloom Naturalist - 81819
class mob_everbloom_naturalist : public CreatureScript
{
public:
    mob_everbloom_naturalist() : CreatureScript("mob_everbloom_naturalist") { }

    struct mob_everbloom_naturalistAI : public ScriptedAI
    {
        mob_everbloom_naturalistAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            DoCast(me, SPELL_MOD_SCALE);
        }

        void Reset() override
        {
            BarrageOfLeavesTimer = 4000;
            CheckTimer = 1000;
            stalker = false;
            aqueous = false;
        }

        void JustReachedHome() override
        {
            DoCast(me, SPELL_MOD_SCALE);
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            me->RemoveAurasDueToSpell(SPELL_REVITALIZING_GROWTH);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!me->IsInCombat())
            {
                if (CheckTimer <= diff)
                {
                    if (!stalker)
                    {
                        if (Creature* mob_stalker = me->FindNearestCreature(NPC_STALKER, 45.0f))
                        {
                            stalker = true;
                            DoCast(mob_stalker, SPELL_REVITALIZING_GROWTH);
                        }
                    }

                    if (!aqueous)
                    {
                        if (me->FindNearestCreature(NPC_AQUEOUS, 10.0f))
                        {
                            aqueous = true;
                            DoCast(me, SPELL_COSMETIC_CHANNEL);
                        }
                    }
                    CheckTimer = 1000;
                }
                else
                    CheckTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (BarrageOfLeavesTimer <= diff)
            {
                BarrageOfLeavesTimer = urand(10000, 11000);
                DoCast(me, SPELL_BARRAGE_OF_LEAVES);
            }
            else
                BarrageOfLeavesTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:

        uint32 BarrageOfLeavesTimer;
        uint32 CheckTimer;
        bool stalker;
        bool aqueous;
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new mob_everbloom_naturalistAI(pCreature);
    }
};

enum EverbloomMenderEnums
{
    SPELL_HEALING_WATERS = 164887,
    SPELL_CHOKING_VINES = 164967,
};

/// Everbloom Mender - 81820
class mob_everbloom_mender : public CreatureScript
{
public:
    mob_everbloom_mender() : CreatureScript("mob_everbloom_mender") { }

    struct mob_everbloom_menderAI : public ScriptedAI
    {
        mob_everbloom_menderAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            DoCast(me, SPELL_MOD_SCALE);
        }

        void Reset() override
        {
            HealingWatersTimer = 0;
            ChokingVinesTimer = urand(7000, 8000);
            CheckTimer = 1000;
            aqueous = false;
        }

        void JustReachedHome() override
        {
            DoCast(me, SPELL_MOD_SCALE);
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            me->RemoveAurasDueToSpell(SPELL_REVITALIZING_GROWTH);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!me->IsInCombat())
            {
                if (CheckTimer <= diff)
                {
                    if (!aqueous)
                    {
                        if (me->FindNearestCreature(NPC_AQUEOUS, 10.0f))
                        {
                            aqueous = true;
                            DoCast(me, SPELL_COSMETIC_CHANNEL);
                        }
                    }
                    CheckTimer = 1000;
                }
                else
                    CheckTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (HealingWatersTimer <= diff)
            {
                HealingWatersTimer = urand(9000, 10000);
                DoCast(me, SPELL_HEALING_WATERS);
            }
            else
                HealingWatersTimer -= diff;

            if (ChokingVinesTimer <= diff)
            {
                ChokingVinesTimer = urand(25000, 30000);
                DoCast(me, SPELL_CHOKING_VINES);
            }
            else
                ChokingVinesTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:

        uint32 HealingWatersTimer;
        uint32 ChokingVinesTimer;
        uint32 CheckTimer;
        bool aqueous;
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new mob_everbloom_menderAI(pCreature);
    }
};

class npc_dreadpetal : public CreatureScript
{
public:
    npc_dreadpetal() : CreatureScript("npc_dreadpetal") { }

    struct npc_dreadpetalAI : public ScriptedAI
    {
        npc_dreadpetalAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetEmoteState(EMOTE_STATE_SUBMERGED);
        }

        void Reset() override
        {
            if (!me->HasAura(151051))
                DoCast(me, 151051);

            if (!me->HasAura(164885))
                DoCast(me, 164885);
        }

        void JustReachedHome() override
        {
            me->SetEmoteState(EMOTE_STATE_SUBMERGED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            me->HandleEmoteCommand(449);
        }

        void UpdateAI(uint32 /*uiDiff*/) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dreadpetalAI(creature);
    }
};

/*######
## Everbloom Tender
######*/

enum TenderEnums
{
    SPELL_GROWTH_1 = 169563,
    SPELL_GROWTH_2 = 169568,
    SPELL_GROWTH_3 = 169518,
    SPELL_GROWTH_4 = 169520,
    SPELL_GROWTH_5 = 169521,

    SPELL_ENRAGED_GROWTH = 169486,
    SPELL_DANCING_THORNS = 164973,
};

class npc_everbloom_tender : public CreatureScript
{
public:
    npc_everbloom_tender() : CreatureScript("npc_everbloom_tender") { }

    struct npc_everbloom_tenderAI : public ScriptedAI
    {
        npc_everbloom_tenderAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCast(me, SPELL_MOD_SCALE);
            DoCast(me, SPELL_GROWTH_1);
        }

        void Reset() override
        {
            GrowthTimer = 2000;
            EnragedGrowthTimer = 4000;
            DancingThornsTimer = 9000;
        }

        void JustReachedHome() override
        {
            DoCast(me, SPELL_GROWTH_1);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me->IsInCombat())
            {
                if (GrowthTimer <= uiDiff)
                {
                    uint8 spells = urand(0, 2);
                    uint32 spellRand = 0;
                    switch (spells)
                    {
                        case 0:
                            spellRand = SPELL_GROWTH_3;
                            break;
                        case 1:
                            spellRand = SPELL_GROWTH_4;
                            break;
                        case 2:
                            spellRand = SPELL_GROWTH_5;
                            break;
                        default:
                            break;
                    }
                    DoCast(me, spellRand, true);

                    GrowthTimer = 2000;
                }
                else
                    GrowthTimer -= uiDiff;
            }

            if (!UpdateVictim())
                return;

            if (EnragedGrowthTimer)
            {
                if (EnragedGrowthTimer <= uiDiff)
                {
                    EnragedGrowthTimer = 0;
                    DoCast(me, SPELL_ENRAGED_GROWTH, true);
                }
                else
                    EnragedGrowthTimer -= uiDiff;
            }

            if (DancingThornsTimer <= uiDiff)
            {
                DancingThornsTimer = 5000;
                DoCast(me->GetVictim(), SPELL_DANCING_THORNS);
            }
            else
                DancingThornsTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

    private:

        uint32 GrowthTimer;
        uint32 EnragedGrowthTimer;
        uint32 DancingThornsTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_everbloom_tenderAI(creature);
    }
};

class spell_growth : public SpellScriptLoader
{
public:
    spell_growth() : SpellScriptLoader("spell_growth") { }

    class spell_growth_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_growth_SpellScript);

        void HandleEffect(SpellEffIndex /*effIndex*/)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_GROWTH_2);
            if (!spellInfo)
                return;

            WorldLocation* dest = GetHitDest();
            SpellCastTargets targets;
            targets.SetDst(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), GetCaster()->GetOrientation());
            GetCaster()->CastSpell(targets, spellInfo, NULL);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_growth_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_CREATE_AREATRIGGER);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_growth_SpellScript();
    }
};

class spell_enraged_growth : public SpellScriptLoader
{
public:
    spell_enraged_growth() : SpellScriptLoader("spell_enraged_growth") { }

    class spell_enraged_growth_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_enraged_growth_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex]);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_enraged_growth_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_enraged_growth_SpellScript;
    }
};

/*######
## Melded Berserker
######*/

enum MeldedEnums
{
    SPELL_VILE_BREATH = 172588,
    SPELL_ENRAGE      = 38166,

    SPELL_BOUNDING_WHIRL_1 = 172576,
    SPELL_BOUNDING_WHIRL_2 = 172577,
    SPELL_BOUNDING_WHIRL_3 = 172578,
};

class npc_melded_berserker : public CreatureScript
{
public:
    npc_melded_berserker() : CreatureScript("npc_melded_berserker") { }

    struct npc_melded_berserkerAI : public ScriptedAI
    {
        npc_melded_berserkerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            VileBreathTimer = 15000;
            EnrageTimer = 21000;
            BoundingWhirlTimer = 8000;
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != EFFECT_MOTION_TYPE)
                return;

            switch (point)
            {
                case SPELL_BOUNDING_WHIRL_2:
                    DoCast(me, SPELL_BOUNDING_WHIRL_3, true);
                    break;
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
                return;

            if (EnrageTimer <= uiDiff)
            {
                EnrageTimer = 60000;
                DoCast(me, SPELL_ENRAGE);
            }
            else
                EnrageTimer -= uiDiff;

            if (VileBreathTimer <= uiDiff)
            {
                VileBreathTimer = 15000;
                DoCast(me, SPELL_VILE_BREATH);
            }
            else
                VileBreathTimer -= uiDiff;

            if (BoundingWhirlTimer <= uiDiff)
            {
                BoundingWhirlTimer = 20000;
                DoCast(me, SPELL_BOUNDING_WHIRL_1, true);
            }
            else
                BoundingWhirlTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

    private:

        uint32 VileBreathTimer;
        uint32 EnrageTimer;
        uint32 BoundingWhirlTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_melded_berserkerAI(creature);
    }
};

class spell_bounding_whirl : public SpellScriptLoader
{
public:
    spell_bounding_whirl() : SpellScriptLoader("spell_bounding_whirl") { }

    class spell_bounding_whirl_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_bounding_whirl_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex]);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_bounding_whirl_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_bounding_whirl_SpellScript;
    }
};

enum GnarlrootEnums
{
    SPELL_GROWTH_GNARLROOT  = 169572,
    SPELL_LIVING_LEAVES     = 169495,
    SPELL_GASP              = 169714,
};

class npc_gnarlroot : public CreatureScript
{
public:
    npc_gnarlroot() : CreatureScript("npc_gnarlroot") { }

    struct npc_gnarlrootAI : public ScriptedAI
    {
        npc_gnarlrootAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCast(me, SPELL_MOD_SCALE);
        }

        void Reset() override
        {
            GrowthTimer = 1000;
            LivingLeavesTimer = 8000;
            GaspTimer = 16000;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me->IsInCombat())
            {
                if (GrowthTimer <= uiDiff)
                {
                    uint8 spells = urand(0, 2);
                    uint32 spellRand = 0;
                    switch (spells)
                    {
                        case 0:
                            spellRand = SPELL_GROWTH_3;
                            break;
                        case 1:
                            spellRand = SPELL_GROWTH_4;
                            break;
                        case 2:
                            spellRand = SPELL_GROWTH_5;
                            break;
                        default:
                            break;
                    }
                    DoCast(me, spellRand, true);

                    GrowthTimer = 1000;
                }
                else
                    GrowthTimer -= uiDiff;
            }

            if (!UpdateVictim())
                return;

            if (LivingLeavesTimer <= uiDiff)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                            DoCast(player, SPELL_LIVING_LEAVES);
                    }
                }
                LivingLeavesTimer = urand(23000, 25000);
            }
            else
                LivingLeavesTimer -= uiDiff;

            if (GaspTimer <= uiDiff)
            {
                DoCast(me, SPELL_GASP);
                GaspTimer = urand(30000, 35000);
            }
            else
                GaspTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

    private:

        uint32 GrowthTimer;
        uint32 LivingLeavesTimer;
        uint32 GaspTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gnarlrootAI(creature);
    }
};

class spell_choking_vines : public SpellScriptLoader
{
public:
    spell_choking_vines() : SpellScriptLoader("spell_choking_vines") { }

    class spell_choking_vines_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_choking_vines_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex]);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_choking_vines_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_choking_vines_SpellScript;
    }
};

class spell_spore_breath : public SpellScriptLoader
{
public:
    spell_spore_breath() : SpellScriptLoader("spell_spore_breath") { }

    class spell_spore_breath_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_spore_breath_SpellScript);

        void Handle(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), 169854, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_spore_breath_SpellScript::Handle, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_spore_breath_SpellScript;
    }
};

class spell_black_hole : public SpellScriptLoader
{
public:
    spell_black_hole() : SpellScriptLoader("spell_black_hole") { }

    class spell_black_hole_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_black_hole_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex], true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_black_hole_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_black_hole_SpellScript;
    }
};

class areatrigger_black_hole : public AreaTriggerAI
{
public:
    areatrigger_black_hole(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        //at->SetCustomRadius(1.0f);
        directionForce = { at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), at->GetOrientation() };
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            player->ApplyMovementForce(at->GetGUID(), directionForce, 3.0f, 0);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            player->RemoveMovementForce(at->GetGUID());
    }

private:
    Position directionForce;
};


class spell_frozen_snap : public SpellScriptLoader
{
public:
    spell_frozen_snap() : SpellScriptLoader("spell_frozen_snap") { }

    class spell_frozen_snap_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_frozen_snap_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex], true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_frozen_snap_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_frozen_snap_SpellScript;
    }
};

class aura_glowbulb_pollen : public SpellScriptLoader
{
public:
    aura_glowbulb_pollen() : SpellScriptLoader("aura_glowbulb_pollen") { }

    class aura_glowbulb_pollen_AuraScript : public AuraScript
    {
        PrepareAuraScript(aura_glowbulb_pollen_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            GetCaster()->CastSpell(GetCaster(), 170017);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(aura_glowbulb_pollen_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new aura_glowbulb_pollen_AuraScript();
    }
};

Position PositionBarrier[4] =
{
    { 611.9896f, 1482.075f, 116.5940f, 0.000000f },
    { 606.5781f, 1484.406f, 116.5923f, 0.000000f },
    { 607.3038f, 1483.655f, 121.8079f, 0.000000f },
    { 611.1250f, 1481.955f, 121.8079f, 0.000000f },
};

class aura_barrier : public SpellScriptLoader
{
public:
    aura_barrier() : SpellScriptLoader("aura_barrier") { }

    class aura_barrier_AuraScript : public AuraScript
    {
        PrepareAuraScript(aura_barrier_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            for (uint8 i = 0; i < 4; i++)
                GetCaster()->CastSpell(PositionBarrier[i].m_positionX, PositionBarrier[i].m_positionY, PositionBarrier[i].m_positionZ, 170663, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(aura_barrier_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new aura_barrier_AuraScript();
    }
};

class spell_vine_pull : public SpellScriptLoader
{
    public:
        spell_vine_pull() : SpellScriptLoader("spell_vine_pull") { }

        class spell_vine_pull_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_vine_pull_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_vine_pull_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_vine_pull_SpellScript();
        }
};

/*class areatrigger_spore_cloud : public AreaTriggerAI
{
    public:
        areatrigger_spore_cloud() : AreaTriggerAI("at_spore_cloud") { }

        void OnCreate() override
        {
            at->SetCustomRadius(3.0f);
        }

        AreaTriggerAI* GetAI() const
        {
            return new areatrigger_spore_cloud();
        }
};*/

/// 232552
class go_everbloom_entrance_portal : public GameObjectScript
{
public:
    go_everbloom_entrance_portal() : GameObjectScript("go_everbloom_entrance_portal")
    {
        checkTimer = 1000;
    }

    uint32 checkTimer;

    void OnUpdate(GameObject* p_Object, uint32 diff) override
    {
        if (checkTimer < diff)
        {
            checkTimer -= diff;
            return;
        }

        checkTimer = 1000;

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, p_Object, 2.0f);

        for (Player* player : playerList)
            player->TeleportTo(1116, 7108.66f, 195.72f, 144.65f, 0.307976f);
    }
};

/// 234025 / 234121
class go_everbloom_stormwind_portal : public GameObjectScript
{
public:
    go_everbloom_stormwind_portal() : GameObjectScript("go_everbloom_stormwind_portal")
    {
        checkTimer = 1000;
    }

    uint32 checkTimer;

    void OnUpdate(GameObject* p_Object, uint32 diff) override
    {
        if (checkTimer < diff)
        {
            checkTimer -= diff;
            return;
        }

        checkTimer = 1000;

        InstanceScript* pInstance = p_Object->GetInstanceScript();

        if (!pInstance)
            return;

        if (pInstance->GetBossState(DATA_ARCHMAGE_SOL) != DONE)
            return;

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, p_Object, 1.0f);

        for (Player* player : playerList)
        {
            if (p_Object->GetEntry() == 234025) // Everbloom to Sw
                player->TeleportTo(1279, 874.53f, -1221.81f, 197.20f, 0.0f);
            else // Sw to Everbloom
                player->TeleportTo(1279, 624.08f, 1725.75f, 143.02f, 4.768497f);
        }
    }
};

void AddSC_the_everbloom()
{
    new spell_barrage_of_leaves();
    new mob_everbloom_naturalist();
    new npc_dreadpetal();
    new npc_everbloom_tender();
    new mob_everbloom_mender();
    //new spell_growth();
    new spell_enraged_growth();
    new npc_melded_berserker();
    new spell_bounding_whirl();
    new npc_gnarlroot();
    //new spell_choking_vines();
    new spell_spore_breath();
    new spell_black_hole();
    RegisterAreaTriggerAI(areatrigger_black_hole);
    new spell_frozen_snap();
    new aura_glowbulb_pollen();
    new aura_barrier();
    //new spell_vine_pull();
    //new areatrigger_spore_cloud();
    new go_everbloom_entrance_portal();
    new go_everbloom_stormwind_portal();
}
