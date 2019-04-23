/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "AchievementMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedEscortAI.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "World.h"

/*######
## npc_dancing_flames
######*/

#define SPELL_BRAZIER       45423
#define SPELL_SEDUCTION     47057
#define SPELL_FIERY_AURA    45427

class npc_dancing_flames : public CreatureScript
{
public:
    npc_dancing_flames() : CreatureScript("npc_dancing_flames") { }

    struct npc_dancing_flamesAI : public ScriptedAI
    {
        npc_dancing_flamesAI(Creature* c) : ScriptedAI(c) {}

        bool Active;
        uint32 CanIteract;

        void Reset() override
        {
            Active = true;
            CanIteract = 3500;
            DoCast(me, SPELL_BRAZIER, true);
            DoCast(me, SPELL_FIERY_AURA, false);
            float x, y, z;
            me->GetPosition(x, y, z);
            me->Relocate(x, y, z + 0.94f);
            me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
            //WorldPacket data;                       //send update position to client
            //me->BuildHeartBeatMsg(&data);
            //me->SendMessageToSet(&data, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!Active)
            {
                if (CanIteract <= diff)
                {
                    Active = true;
                    CanIteract = 3500;
                    me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
                }
                else
                    CanIteract -= diff;
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void ReceiveEmote(Player* player, uint32 emote) override
        {
            if (me->IsWithinLOS(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ()) && me->IsWithinDistInMap(player, 30.0f))
            {
                me->SetInFront(player);
                Active = false;

                //WorldPacket data;
                //me->BuildHeartBeatMsg(&data);
                //me->SendMessageToSet(&data, true);
                switch(emote)
                {
                    case TEXT_EMOTE_KISS:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_SHY);
                        break;
                    case TEXT_EMOTE_WAVE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                        break;
                    case TEXT_EMOTE_BOW:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                        break;
                    case TEXT_EMOTE_JOKE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                        break;
                    case TEXT_EMOTE_DANCE:
                        if (!player->HasAura(SPELL_SEDUCTION))
                            DoCast(player, SPELL_SEDUCTION, true);
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dancing_flamesAI(creature);
    }
};

enum midsummerDefines
{
    SPELL_BRASERO_TARGET_AURA   = 64328,
    SPELL_TORCH                 = 45732,

    NPC_BRASERO                 = 25515,

    QUEST_TORCHS_1              = 11731,
    QUEST_TORCHS_2              = 11921,
    QUEST_TORCHS_3              = 11922,
    QUEST_TORCHS_4              = 11926,
};

class npc_midsummer_quest_torch : public CreatureScript
{
public:
    npc_midsummer_quest_torch() : CreatureScript("npc_midsummer_quest_torch") { }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* quest) override
    {
        switch (quest->GetQuestId())
        {
            case QUEST_TORCHS_1:
            case QUEST_TORCHS_2:
            case QUEST_TORCHS_3:
            case QUEST_TORCHS_4:
            {
                std::list<Creature*> braseroList;
                std::list<Creature*>::iterator Itr;

                GetCreatureListWithEntryInGrid(braseroList, creature, NPC_BRASERO, 100.0f);

                for (Itr = braseroList.begin(); Itr != braseroList.end(); Itr++)
                    if (Creature * pBrasero = *Itr)
                        pBrasero->AI()->DoAction(0);


                Trinity::Containers::RandomResize(braseroList, 1);

                if (Creature * pBrasero = *braseroList.begin())
                    if (pBrasero->AI())
                        pBrasero->AI()->DoAction(1);
            }
            default:
                break;
        }

        return true;
    }
};

class npc_midsummer_brasero : public CreatureScript
{
public:
    npc_midsummer_brasero() : CreatureScript("npc_midsummer_brasero") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_midsummer_braseroAI(creature);
    }

    struct npc_midsummer_braseroAI : public ScriptedAI
    {
        npc_midsummer_braseroAI(Creature* c) : ScriptedAI(c) { }

        uint32 targetTimer;
        bool HasAura;

        void Reset() override
        {
            targetTimer = 0;
            HasAura = false;
        }

        void DoAction(int32 const param) override
        {
            if (param == 1)
            {
                me->AddAura(SPELL_BRASERO_TARGET_AURA, me);
                targetTimer = urand(3000, 5000);
                HasAura = true;
            }
            else
            {
                me->RemoveAurasDueToSpell(SPELL_BRASERO_TARGET_AURA);
                HasAura = false;
                targetTimer = 0;
            }
        }

        void SelectNextTarget()
        {
            me->RemoveAurasDueToSpell(SPELL_BRASERO_TARGET_AURA);
            HasAura = false;
            targetTimer = 0;

            std::list<Creature*> braseroList;

            GetCreatureListWithEntryInGrid(braseroList, me, me->GetEntry(), 100.0f);

            braseroList.remove(me);
            Trinity::Containers::RandomResize(braseroList, 1);

            if (Creature * pBrasero = *braseroList.begin())
                if (pBrasero->AI())
                    pBrasero->AI()->DoAction(1);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (HasAura)
            {
                if (spell->Id == SPELL_TORCH)
                {
                    if (Player * pPlayer = caster->ToPlayer())
                    {
                        pPlayer->KilledMonsterCredit(me->GetEntry(), me->GetGUID());

                        if (pPlayer->GetQuestStatus(QUEST_TORCHS_1) != QUEST_STATUS_COMPLETE &&
                            pPlayer->GetQuestStatus(QUEST_TORCHS_2) != QUEST_STATUS_COMPLETE &&
                            pPlayer->GetQuestStatus(QUEST_TORCHS_3) != QUEST_STATUS_COMPLETE &&
                            pPlayer->GetQuestStatus(QUEST_TORCHS_4) != QUEST_STATUS_COMPLETE)
                            SelectNextTarget();
                        else
                            DoAction(0);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (HasAura)
            {
                if (targetTimer <= diff)
                {

                    if (me->SelectNearestPlayer(100.0f))
                        SelectNextTarget();
                    else
                        DoAction(0);

                } else targetTimer -= diff;
            }
        }
    };
};

class spell_gen_torch_launch : public SpellScriptLoader
{
    public:
        spell_gen_torch_launch() : SpellScriptLoader("spell_gen_torch_launch") { }

        class spell_gen_torch_launch_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gen_torch_launch_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                std::list<Creature*> braseroList;
                std::list<Creature*>::iterator Itr;

                GetCreatureListWithEntryInGrid(braseroList, caster, 25515, 100.0f);

                for (Itr = braseroList.begin(); Itr != braseroList.end(); Itr++)
                    if (Creature * pBrasero = *Itr)
                        if (GetExplTargetDest()->IsInDist2d(pBrasero->GetPositionX(), pBrasero->GetPositionY(), 1.0f))
                            pBrasero->AI()->SpellHit(caster, GetSpellInfo());
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_gen_torch_launch_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gen_torch_launch_SpellScript();
        }
};

enum RibbonPoleData
{
    SPELL_HAS_FULL_MIDSUMMER_SET        = 58933,   // Full set aura
    SPELL_BURNING_HOT_POLE_DANCE        = 45390,   // Checker
    SPELL_RIBBON_DANCE_XP               = 29175,   // + Xp
    SPELL_DANCE                         = 45418,   // Dance aura
    GO_RIBBON_POLE                      = 181605,
    HF_FIRE_DANCE                       = 271,
};

class spell_gen_ribbon_pole_dancer_check : public SpellScriptLoader
{
    public:
        spell_gen_ribbon_pole_dancer_check() : SpellScriptLoader("spell_gen_ribbon_pole_dancer_check") { }

        class spell_gen_ribbon_pole_dancer_check_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_ribbon_pole_dancer_check_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HAS_FULL_MIDSUMMER_SET,
                    SPELL_BURNING_HOT_POLE_DANCE,
                    SPELL_RIBBON_DANCE_XP
                });
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();

                if (!target)
                    return;

                // check if aura needs to be removed
                if (!target->FindNearestGameObject(GO_RIBBON_POLE, 20.0f) || !target->HasAura(SPELL_DANCE))
                {
                    target->InterruptNonMeleeSpells(false);
                    target->RemoveAurasDueToSpell(GetId());
                    return;
                }

                // set xp buff duration
                if (Aura* aur = target->GetAura(SPELL_RIBBON_DANCE_XP))
                {
                    const int32 Hour         = 1 * HOUR * IN_MILLISECONDS;
                    const int32 ThreeMinutes = 3 * MINUTE * IN_MILLISECONDS;

                    aur->SetMaxDuration(aur->GetMaxDuration() >= Hour ? Hour : aur->GetMaxDuration() + ThreeMinutes);
                    aur->RefreshDuration();

                    // reward achievement criteria
                    if (aur->GetMaxDuration() == Hour && target->HasAura(SPELL_HAS_FULL_MIDSUMMER_SET))
                        if (Player * pPlayer = target->ToPlayer())
                            if (!pPlayer->GetAchievementMgr()->HasAchieved(HF_FIRE_DANCE))
                                pPlayer->CompletedAchievement(sAchievementStore.LookupEntry(HF_FIRE_DANCE));
                }
                else
                    target->AddAura(SPELL_RIBBON_DANCE_XP, target);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_ribbon_pole_dancer_check_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gen_ribbon_pole_dancer_check_AuraScript();
        }
};

#define QUEST_TORCHS_1  11731
#define QUEST_TORCHS_2  11921
#define QUEST_TORCHS_3  11922
#define QUEST_TORCHS_4  11926

#define SPELL_TORCH     45276

class spell_hol_torch_launch_achievement : public SpellScriptLoader
{
    public:
        spell_hol_torch_launch_achievement() : SpellScriptLoader("spell_hol_torch_launch_achievement") { }

        class spell_hol_torch_launch_achievement_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hol_torch_launch_achievement_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return true;
            }

            SpellCastResult CheckCast()
            {
                if (!GetExplTargetDest() || GetCaster())
                    return SPELL_FAILED_DONT_REPORT;

                std::list<WorldObject*> objectList;
                GetSpell()->SearchAreaTargets(objectList, 5, GetExplTargetDest(), GetCaster(), TARGET_OBJECT_TYPE_UNIT, TARGET_CHECK_ALLY, nullptr);

                for (std::list<WorldObject*>::iterator itr = objectList.begin(); itr != objectList.end(); ++itr)
                {
                    if (Player * pPlayer = (*itr)->ToPlayer())
                    {
                        if (pPlayer->GetQuestRewardStatus(QUEST_TORCHS_1) ||
                            pPlayer->GetQuestRewardStatus(QUEST_TORCHS_2) ||
                            pPlayer->GetQuestRewardStatus(QUEST_TORCHS_3) ||
                            pPlayer->GetQuestRewardStatus(QUEST_TORCHS_4))
                        {
                            GetCaster()->CastSpell(pPlayer, SPELL_TORCH, true);
                        }
                    }
                }

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_hol_torch_launch_achievement_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hol_torch_launch_achievement_SpellScript();
        }
};

void AddSC_event_midsummer()
{
    new npc_dancing_flames();
    new npc_midsummer_quest_torch();
    new npc_midsummer_brasero();
    new spell_gen_torch_launch();
    new spell_gen_ribbon_pole_dancer_check();
    new spell_hol_torch_launch_achievement();
}

