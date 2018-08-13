/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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
#include "SpellMgr.h"
#include "shadowmoon_burial_grounds.h"

/*######
## at_shadow_rune
######*/

enum RuneATEnums
{
    SPELL_SHADOW_RUNE            = 152690,
    
    SPELL_LUNAR_RUNE_1           = 164693,
    SPELL_SHADOW_RUNE_1          = 152684,
    SPELL_LUNAR_RUNE_2           = 164695,
    SPELL_SHADOW_RUNE_2          = 152691,
    SPELL_LUNAR_RUNE_3           = 164696,
    SPELL_SHADOW_RUNE_3          = 170038,
    
    NPC_SHADOW_RUNE              = 75778,
};

class at_shadow_rune1 : public AreaTriggerAI
{
public:
    at_shadow_rune1(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Creature* rune = GetClosestCreatureWithEntry(unit, NPC_SHADOW_RUNE, 5.0f))
        {
            if (unit->IsPlayer() && rune->HasAura(SPELL_SHADOW_RUNE_1))
            {
                rune->RemoveAurasDueToSpell(SPELL_SHADOW_RUNE_1);
                rune->CastSpell(rune, SPELL_SHADOW_RUNE, true);
            }
        }
    }
};

class at_shadow_rune2 : public AreaTriggerAI
{
public:
    at_shadow_rune2(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Creature* rune = GetClosestCreatureWithEntry(unit, NPC_SHADOW_RUNE, 5.0f))
        {
            if (unit->IsPlayer() && rune->HasAura(SPELL_SHADOW_RUNE_2))
            {
                rune->RemoveAurasDueToSpell(SPELL_SHADOW_RUNE_2);
                rune->CastSpell(rune, SPELL_SHADOW_RUNE, true);
            }
        }
    }
};

class at_shadow_rune3 : public AreaTriggerAI
{
public:
    at_shadow_rune3(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Creature* rune = GetClosestCreatureWithEntry(unit, NPC_SHADOW_RUNE, 5.0f))
        {
            if (unit->IsPlayer() && rune->HasAura(SPELL_SHADOW_RUNE_3))
            {
                rune->RemoveAurasDueToSpell(SPELL_SHADOW_RUNE_3);
                rune->CastSpell(rune, SPELL_SHADOW_RUNE, true);
            }
        }
    }
};

/*######
## Defiiled Burial Site
######*/

enum DefiledEnums
{
    SPELL_BOUND_REVENANT            = 153238,

    DEFILED_BURIAL_SITE             = 75977,
};

class defiled_burial_site : public CreatureScript
{
    public:
        defiled_burial_site() : CreatureScript("defiled_burial_site") { }

        struct defiled_burial_siteAI : public ScriptedAI
        {
            defiled_burial_siteAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                checkTimer = 100;
                spellTrig = false;
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (spellTrig)
                    return;

                if (checkTimer <= uiDiff)
                {
                    std::list<Player*> list;
                    GetPlayerListInGrid(list, me, 1.0f);
                    if (!list.empty())
                    {
                        DoCast(me, SPELL_BOUND_REVENANT);
                        me->DespawnOrUnsummon(4000);
                        spellTrig = true;
                    }
                    checkTimer = 100;
                }
                else
                    checkTimer -= uiDiff;
            }

        private:
            bool spellTrig;
            uint32 checkTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new defiled_burial_siteAI(creature);
        }
};

/*######
## Shadowmoon Exhumer
######*/

enum ExhumerEnums
{
    SPELL_EXHUME_THE_CRYPTS_1 = 153268,
    SPELL_EXHUME_THE_CRYPTS_2 = 153276,
    SPELL_VOID_BOLT = 156722,
};

class npc_shadowmoon_exhumer : public CreatureScript
{
public:
    npc_shadowmoon_exhumer() : CreatureScript("npc_shadowmoon_exhumer") { }

    struct npc_shadowmoon_exhumerAI : public ScriptedAI
    {
        npc_shadowmoon_exhumerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            voidBoltTimer = urand(2000, 3000);
        }

        void EnterCombat(Unit* /*victim*/) override
        {
            DoCast(me, SPELL_EXHUME_THE_CRYPTS_1);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
                return;

            if (voidBoltTimer <= uiDiff)
            {
                DoCast(me->GetVictim(), SPELL_VOID_BOLT);
                voidBoltTimer = urand(2000, 3000);
            }
            else
                voidBoltTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

    private:

        uint32 voidBoltTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shadowmoon_exhumerAI(creature);
    }
};

class ExhumeTargetSelector
{
public:
    ExhumeTargetSelector() { }

    bool operator()(WorldObject* object)
    {
        if (object->GetEntry() != DEFILED_BURIAL_SITE)
            return true;

        return false;
    }
};

class spell_exhume_the_crypts : public SpellScriptLoader
{
public:
    spell_exhume_the_crypts() : SpellScriptLoader("spell_exhume_the_crypts") { }

    class spell_exhume_the_crypts_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_exhume_the_crypts_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_EXHUME_THE_CRYPTS_1))
                return false;

            if (!sSpellMgr->GetSpellInfo(SPELL_EXHUME_THE_CRYPTS_2))
                return false;
            return true;
        }

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            targets.remove_if(ExhumeTargetSelector());
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_EXHUME_THE_CRYPTS_2);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_exhume_the_crypts_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_exhume_the_crypts_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_exhume_the_crypts_SpellScript();
    }
};

enum CarrionWormEnums
{
    SPELL_BODY_SLAM                 = 153395,
    SPELL_FETID_SPIT                = 153496,
    SPELL_ROCKWORM_SUBMERGE         = 177694,
};

class npc_carrion_worm : public CreatureScript
{
public:
    npc_carrion_worm() : CreatureScript("npc_carrion_worm") { }

    struct npc_carrion_wormAI : public Scripted_NoMovementAI
    {
        npc_carrion_wormAI(Creature* creature) : Scripted_NoMovementAI(creature){ }

        void Reset() override
        {
            bodySlamTimer = 2000;
            fetidSpitTimer = 5000;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetVictim())
                return;

            if (Player* player = who->ToPlayer())
                if (player->IsGameMaster())
                    return;

            if (me->GetDistance2d(who) <= 15.0f)
            {
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 20.0f);
                AttackStart(who);
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                DoCast(me, SPELL_ROCKWORM_SUBMERGE);
            }
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_ROCKWORM_SUBMERGE)
                me->DespawnOrUnsummon(3000);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (bodySlamTimer <= uiDiff)
            {
                DoCast(me, SPELL_BODY_SLAM);
                bodySlamTimer = 15000;
            }
            else
                bodySlamTimer -= uiDiff;

            if (fetidSpitTimer <= uiDiff)
            {
                DoCast(me->GetVictim(), SPELL_FETID_SPIT);
                fetidSpitTimer = urand(2000, 3000);
            }
            else
                fetidSpitTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

    private:

        uint32 bodySlamTimer;
        uint32 fetidSpitTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_carrion_wormAI(creature);
    }
};

class spell_water_burst_targeting : public SpellScriptLoader
{
    public:
        spell_water_burst_targeting() : SpellScriptLoader("spell_water_burst_targeting") { }

        class spell_water_burst_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_water_burst_targeting_SpellScript);

            void SelectTargets(std::list<WorldObject*>& targets)
            {
                targets.clear();

                std::list<Player*> list;
                GetPlayerListInGrid(list, GetCaster(), 5.0f);

                if (!list.empty())
                    targets.push_back(list.front());
            }

            void HandleForceCast(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), uint32(GetEffectValue()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_water_burst_targeting_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_water_burst_targeting_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_water_burst_targeting_SpellScript();
        }
};

enum NerzhulFlyEnums
{
    SPELL_FLOATING_DEAD           = 160467,
    CLIENT_SCENE_TELEPORT         = 178093,
    SPELL_SAFEFALL                = 158032,

    SCENE_NERZHUL                 = 849,

    NPC_NERZHUL_FLY               = 79497,
};

class npc_nerzhul_fly : public CreatureScript
{
public:
    npc_nerzhul_fly() : CreatureScript("npc_nerzhul_fly") { }

    struct npc_nerzhul_flyAI : public ScriptedAI
    {
        npc_nerzhul_flyAI(Creature* creature) : ScriptedAI(creature)
        {
            teleport = false;
            checkTimer = 0;
            sceneTimer = 0;
            scenePhase = 0;
            checkTeleportTimer = 0;
        }

        void DoAction(int32 /*action*/) override
        {
            switch (scenePhase)
            {
                case 1:
                {
                    Map::PlayerList const &players = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                    {
                        Player* player = i->GetSource();
                        if (!player || !player->IsAlive() || player->IsGameMaster())
                            continue;

                        player->SetControlled(true, UNIT_STATE_ROOT);
                        player->GetSceneMgr().PlaySceneByPackageId(SCENE_NERZHUL);
                        player->CastSpell(player, SPELL_FLOATING_DEAD, true);
                    }

                    sceneTimer = 18000;
                    scenePhase = 2;
                    break;
                }
                case 2:
                {
                    Map::PlayerList const &players = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                    {
                        Player* player = i->GetSource();
                        if (!player || !player->IsAlive() || player->IsGameMaster())
                            continue;

                        player->GetSceneMgr().CancelSceneByPackageId(SCENE_NERZHUL);
                        player->SetControlled(false, UNIT_STATE_ROOT);
                        player->CastSpell(player, CLIENT_SCENE_TELEPORT);
                        player->CastSpell(player, SPELL_SAFEFALL, true);
                    }

                    sceneTimer = 7000;
                    scenePhase = 3;
                    break;
                }
                case 3:
                {
                    Map::PlayerList const &players = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                    {
                        Player* player = i->GetSource();
                        if (!player || !player->IsAlive() || player->IsGameMaster())
                            continue;

                        player->RemoveAurasDueToSpell(SPELL_FLOATING_DEAD);
                        player->RemoveAurasDueToSpell(SPELL_SAFEFALL);
                    }

                    sceneTimer = 0;
                    scenePhase = 0;
                    break;
                }
                default:
                    break;
            }
        }

        void SetData(uint32 /*id*/, uint32 /*value*/) override
        {
            sceneTimer = 0;
            scenePhase = 2;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (sceneTimer <= uiDiff)
                DoAction(0);
            else
                sceneTimer -= uiDiff;

            if (checkTimer <= uiDiff)
            {
                if (teleport)
                    return;

                std::list<Player*> list;
                GetPlayerListInGrid(list, me, 70.0f);
                if (!list.empty())
                {
                    sceneTimer = 0;
                    scenePhase = 1;
                    teleport = true;
                    
                    checkTeleportTimer = 60000;
                }
                checkTimer = 200;
            }
            else
                checkTimer -= uiDiff;

            if (teleport)
            {
                if (checkTeleportTimer <= uiDiff)
                    teleport = false;
                else
                    checkTeleportTimer -= uiDiff;
            }
        }

    private:

        uint32 checkTeleportTimer;
        uint32 checkTimer;
        uint32 sceneTimer;
        uint8 scenePhase;
        bool teleport;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nerzhul_flyAI(creature);
    }
};

class playerScript_nerzhul_scene : public PlayerScript
{
public:
    playerScript_nerzhul_scene() : PlayerScript("playerScript_nerzhul_scene") { }

    void OnSceneCancel(Player* player, uint32 p_SceneInstanceID) override
    {
        if (!player->GetSceneMgr().HasScene(p_SceneInstanceID, SCENE_NERZHUL))
            return;

        if (Creature* nerzhul = player->FindNearestCreature(NPC_NERZHUL_FLY, 100.0f))
            nerzhul->AI()->SetData(1, 1);
    }
};

void AddSC_shadowmoon_burial_grounds()
{
    RegisterAreaTriggerAI(at_shadow_rune1);
    RegisterAreaTriggerAI(at_shadow_rune2);
    RegisterAreaTriggerAI(at_shadow_rune3);
    new defiled_burial_site();
    new npc_shadowmoon_exhumer();
    new spell_exhume_the_crypts();
    new npc_carrion_worm();
    new spell_water_burst_targeting();
    new npc_nerzhul_fly();
    new playerScript_nerzhul_scene();
}
