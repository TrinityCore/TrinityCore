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
#include "ScriptMgr.h"
#include "ScriptedEscortAI.h"
#include "GameObject.h"
#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "SpellMgr.h"
#include "ScriptMgr.h"
#include "Vehicle.h"
#include "World.h"

#define RACER_ENTRY         27664
#define RACER_BLUE_ENTRY    40281
#define SPELL_HF            49444
#define SPELL_EXPLOSION     40162

#define EVENT_WINTER_VEIL   2

class npc_racer_slam_bunny : public CreatureScript
{
    public:
        npc_racer_slam_bunny() : CreatureScript("npc_racer_slam_bunny") { }

        struct npc_racer_slam_bunnyAI : public ScriptedAI
        {
            npc_racer_slam_bunnyAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetVisible(false);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner->GetCharmer() || !summoner->GetCharmer()->ToPlayer())
                    return;

                Player * SummonerPlayer = summoner->GetCharmer()->ToPlayer();

                float x = me->GetPositionX();
                float y = me->GetPositionY();
                float z = me->GetPositionZ();

                std::list<Player*> OtherRacers;

                summoner->GetPlayerListInGrid(OtherRacers, 250.0f);

                if (!OtherRacers.empty())
                {
                    if (sGameEventMgr->IsActiveEvent(EVENT_WINTER_VEIL))
                    {
                        for (std::list<Player*>::iterator Itr = OtherRacers.begin(); Itr != OtherRacers.end(); ++Itr)
                        {
                            Player * EnnemyPlayer = (*Itr);
                            if (EnnemyPlayer != SummonerPlayer)
                            {
                                if (Unit * pUnit = EnnemyPlayer->GetCharm())
                                {
                                    if (pUnit->GetEntry() == RACER_ENTRY || pUnit->GetEntry() == RACER_BLUE_ENTRY)
                                    {
                                        if (pUnit->IsInBetween(me, summoner))
                                        {
                                            Creature * Trigger = me->SummonCreature(13876, pUnit->GetPositionX(), pUnit->GetPositionY(), pUnit->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 2000);

                                            Trigger->CastSpell(Trigger, SPELL_EXPLOSION);

                                            EnnemyPlayer->StopCastingCharm();
                                            EnnemyPlayer->CastStop();

                                            summoner->AddAura(SPELL_HF, summoner);

                                            //SummonerPlayer->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_HF);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }


                summoner->GetMotionMaster()->MoveCharge(x, y, z);

                me->DisappearAndDie();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_racer_slam_bunnyAI(creature);
        }
};

class npc_abominable_grinch : public CreatureScript
{
public:
    npc_abominable_grinch() : CreatureScript("npc_abominable_grinch") { }

    struct npc_abominable_grinchAI : public ScriptedAI
    {
        npc_abominable_grinchAI(Creature* creature) : ScriptedAI(creature) { }

        enum eSpells
        {
            SPELL_CLEAVE            = 40504,
            SPELL_THROW_TREE        = 101938,
            SPELL_THROW_SNOWMAN     = 101910,
            SPELL_ABOMINABLE_CRUSH  = 101885,
            SPELL_SHRINK_HEART      = 101873
        };

        enum eEvents
        {
            EVENT_CLEAVE            = 1,
            EVENT_THROW_TREE        = 2,
            EVENT_THROW_SNOWMAN     = 3,
            EVENT_ABOMINABLE_CRUSH  = 4,
            EVENT_SHRINK_HEART      = 5
        };

        enum eCreature
        {
            NPC_WINTER_VEIL_TREE        = 54519,
            NPC_STRANGE_SNOWMAN         = 54523,
            NPC_WICKED_LITTLE_HELPER    = 54524
        };

        ObjectGuid winterVeilTreeGuid;

        void Reset() override
        {
            winterVeilTreeGuid = ObjectGuid::Empty;

            events.Reset();
            events.ScheduleEvent(EVENT_CLEAVE,          urand(1000,  3000));
            events.ScheduleEvent(EVENT_THROW_TREE,      urand(5000,  10000));
            events.ScheduleEvent(SPELL_THROW_SNOWMAN,   urand(5000,  10000));
            events.ScheduleEvent(EVENT_SHRINK_HEART,    urand(10000, 20000));

            //me->GetVehicleKit()->AddPassenger(NPC_WICKED_LITTLE_HELPER, 0);
            //me->GetVehicleKit()->AddPassenger(NPC_WICKED_LITTLE_HELPER, 1);
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_WINTER_VEIL_TREE:
                    winterVeilTreeGuid = summon->GetGUID();
                    break;
            }

            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_WINTER_VEIL_TREE:
                    winterVeilTreeGuid = ObjectGuid::Empty;
                    break;
            }

            summons.Despawn(summon);
        }

        void MovementInform(uint32 /*p_Type*/, uint32 p_ID) override
        {
            if (p_ID == EVENT_ABOMINABLE_CRUSH)
            {
                if (Creature* winterVeilTree = ObjectAccessor::GetCreature(*me, winterVeilTreeGuid))
                {
                    me->CastSpell(winterVeilTree, SPELL_ABOMINABLE_CRUSH, false);
                    winterVeilTree->DespawnOrUnsummon(5000);
                }

                events.ScheduleEvent(EVENT_THROW_TREE, urand(10000, 20000));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CLEAVE:
                {
                    DoCastVictim(SPELL_CLEAVE, false);
                    events.ScheduleEvent(EVENT_CLEAVE, urand(3000, 5000));
                    break;
                }
                case EVENT_THROW_TREE:
                {
                    //DoCastRandom(SPELL_THROW_TREE, false);
                    events.ScheduleEvent(EVENT_ABOMINABLE_CRUSH, urand(2000, 4000));
                    break;
                }
                case EVENT_ABOMINABLE_CRUSH:
                {
                    if (!winterVeilTreeGuid.IsEmpty())
                    {
                        if (Creature* winterVeilTree = ObjectAccessor::GetCreature(*me, winterVeilTreeGuid))
                        {
                            float x = 0.0f, y = 0.0f, z = 0.0f;
                            me->GetContactPoint(winterVeilTree, x, y, z);
                            me->GetMotionMaster()->MoveCharge(x, y, z, 42.0f, EVENT_ABOMINABLE_CRUSH);
                        }
                    }
                    break;
                }
                case EVENT_SHRINK_HEART:
                {
                    DoCastAOE(SPELL_SHRINK_HEART);
                    events.ScheduleEvent(EVENT_SHRINK_HEART, urand(5000, 20000));
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_abominable_grinchAI(creature);
    }
};

class npc_winter_veil_strange_snowman : public CreatureScript
{
public:
    npc_winter_veil_strange_snowman() : CreatureScript("npc_winter_veil_strange_snowman") { }

    struct npc_winter_veil_strange_snowmanAI : public ScriptedAI
    {
        npc_winter_veil_strange_snowmanAI(Creature* creature) : ScriptedAI(creature) { }

        enum eSpells
        {
            SPELL_SNOW_CRASH = 101907
        };

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            DoCastAOE(SPELL_SNOW_CRASH);
            me->DespawnOrUnsummon(10000);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_winter_veil_strange_snowmanAI(creature);
    }
};

enum eCannibalizeSpells
{
    NPC_BOMBE_TRIGGER       = 23118,
    GOB_BOULES_DE_CANONS    = 185861,
};

class spell_throw_bomb : public SpellScriptLoader
{
    public:
        spell_throw_bomb() : SpellScriptLoader("spell_throw_bomb") { }

        class spell_throw_bomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_throw_bomb_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/) override
            {
                return true;
            }

            SpellCastResult CheckIfIsMounted()
            {
                if (!GetCaster()->IsMounted() || !GetCaster()->IsFlying())
                    return SPELL_FAILED_ONLY_MOUNTED;

                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit * pTrigger = GetHitUnit();

                if (!pTrigger->ToCreature() || !GetCaster()->ToPlayer() || !(pTrigger->GetEntry() == NPC_BOMBE_TRIGGER))
                    return;

                Player * pCaster = GetCaster()->ToPlayer();
                Creature * cTrigger = pTrigger->ToCreature();

                if (GameObject * pGobject = pTrigger->FindNearestGameObject(GOB_BOULES_DE_CANONS, 50.0f))
                {
                    if (pGobject->GetPhaseShift().HasPhase(50)) // Gob en attente de respawn
                    {
                        return;
                    }
                    else
                    {
                        cTrigger->AI()->DoAction(0);

                        pCaster->KilledMonsterCredit(NPC_BOMBE_TRIGGER);

                        PhasingHandler::AddPhase(pGobject, 50);
                        PhasingHandler::AddPhase(cTrigger, 50);
                    }
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_throw_bomb_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_throw_bomb_SpellScript::CheckIfIsMounted);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throw_bomb_SpellScript();
        }
};

enum VisibleDisplayId
{
    DISPLAYID_INVISIBLE                     = 11686,
};

class npc_throw_bomb_bunny : public CreatureScript
{
    public:
        npc_throw_bomb_bunny() : CreatureScript("npc_throw_bomb_bunny") { }

        struct npc_throw_bomb_bunnyAI : public ScriptedAI
        {
            npc_throw_bomb_bunnyAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetDisplayId(DISPLAYID_INVISIBLE);
                me->SetReactState(REACT_PASSIVE);

                CheckTimer = 20000;
                StartRespawnTimer = false;
            }

            void DoAction(int32 const /*action*/) override
            {
                StartRespawnTimer = true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (StartRespawnTimer)
                {
                    if (CheckTimer <= diff)
                    {
                        if (GameObject * pGobject = me->FindNearestGameObject(GOB_BOULES_DE_CANONS, 50.0f))
                        {
                            PhasingHandler::ResetPhaseShift(pGobject);
                            PhasingHandler::ResetPhaseShift(me);
                        }

                        StartRespawnTimer = false;
                        CheckTimer = 20000;
                    }
                    else
                        CheckTimer -= diff;
                }
            }

            uint32 CheckTimer;
            bool StartRespawnTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_throw_bomb_bunnyAI(creature);
        }
};

enum eSergentQuest
{
    QUEST_BOMBARDEZ_LES_ENCORE  = 11023,
    ACHIEVEMENT_LALALALA_OGRILA = 1282,
};

class npc_sergent_vanderlip : public CreatureScript
{
    public:
        npc_sergent_vanderlip() : CreatureScript("npc_sergent_vanderlip") {}

        bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*opt*/) override
        {
            if (quest->GetQuestId() == QUEST_BOMBARDEZ_LES_ENCORE)
            {
                if (player->HasAura(44655) || player->HasAura(44824)
                    || player->HasAura(44825) || player->HasAura(44827))
                {
                    AchievementEntry const* AchievLalalalaOgrila = sAchievementStore.LookupEntry(ACHIEVEMENT_LALALALA_OGRILA);
                    if (AchievLalalalaOgrila)
                        player->GetAchievementMgr()->CompletedAchievement(AchievLalalalaOgrila, player);
                }
            }

            return true;
        }
};

enum Mistletoe
{
    SPELL_CREATE_MISTLETOE  = 26206,
    SPELL_CREATE_HOLLY      = 26207,
    SPELL_CREATE_SNOWFLAKES = 45036
};

class spell_winter_veil_mistletoe: public SpellScriptLoader
{
    public:
        spell_winter_veil_mistletoe() : SpellScriptLoader("spell_winter_veil_mistletoe") { }

        class spell_winter_veil_mistletoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_winter_veil_mistletoe_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CREATE_MISTLETOE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_CREATE_HOLLY) ||
                    !sSpellMgr->GetSpellInfo(SPELL_CREATE_SNOWFLAKES))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                if (Player* target = GetHitPlayer())
                {
                    uint32 spellId = 0;
                    switch (urand(0, 2))
                    {
                        case 0:
                            spellId = SPELL_CREATE_MISTLETOE;
                            break;
                        case 1:
                            spellId = SPELL_CREATE_HOLLY;
                            break;
                        case 2:
                            spellId = SPELL_CREATE_SNOWFLAKES;
                            break;
                        default:
                            return;
                    }

                    caster->CastSpell(target, spellId, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_winter_veil_mistletoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_winter_veil_mistletoe_SpellScript();
        }
};

class spell_winter_veil_snowball : public SpellScriptLoader
{
public:
    spell_winter_veil_snowball() : SpellScriptLoader("spell_winter_veil_snowball") { }

    class spell_winter_veil_snowball_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_winter_veil_snowball_SpellScript);

        enum Achievements
        {
            ACHIEVEMENT_SCROOGE_A = 1255,
            ACHIEVEMENT_SCROOGE_H = 259
        };

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !caster->ToPlayer())
                return;

            if (caster->ToPlayer()->GetTeamId() == TEAM_ALLIANCE && target->GetEntry() == 42928) // Muradin
            {
                caster->ToPlayer()->CompletedAchievement(ACHIEVEMENT_SCROOGE_A);
            }
            else if (caster->ToPlayer()->GetTeamId() == TEAM_HORDE && target->GetEntry() == 36648) // Baine
            {
                caster->ToPlayer()->CompletedAchievement(ACHIEVEMENT_SCROOGE_H);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_winter_veil_snowball_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_winter_veil_snowball_SpellScript();
    }
};

/// Passive Scene Object
class playerScript_winter_veil_quest_reward : public PlayerScript
{
public:
    playerScript_winter_veil_quest_reward() : PlayerScript("playerScript_winter_veil_quest_reward") { }

    enum Quests
    {
        QUEST_A_SMOKYWOOD_PASTURES_THANK_YOU_A = 7045, // ACHIEVEMENT_SIMPLY_ABOMINABLE
        QUEST_A_SMOKYWOOD_PASTURES_THANK_YOU_H = 6984, // ACHIEVEMENT_SIMPLY_ABOMINABLE

        QUEST_YOU_RE_A_MEAN_ONE_A   = 7043, // ACHIEVEMENT_ON_METZEN
        QUEST_YOU_RE_A_MEAN_ONE_H   = 6983, // ACHIEVEMENT_ON_METZEN

        QUEST_CHRISTMAS_GIFT_1  = 8744,  // ACHIEVEMENT_HE_KNOW_BEEN_NAUGHTY
        QUEST_CHRISTMAS_GIFT_2  = 8769,  // ACHIEVEMENT_HE_KNOW_BEEN_NAUGHTY
        QUEST_CHRISTMAS_GIFT_3  = 8803,  // ACHIEVEMENT_HE_KNOW_BEEN_NAUGHTY
        QUEST_CHRISTMAS_GIFT_4  = 36617, // ACHIEVEMENT_HE_KNOW_BEEN_NAUGHTY
        QUEST_CHRISTMAS_GIFT_5  = 8788,  // ACHIEVEMENT_HE_KNOW_BEEN_NAUGHTY
        QUEST_CHRISTMAS_GIFT_6  = 8768,  // ACHIEVEMENT_HE_KNOW_BEEN_NAUGHTY
    };

    enum Achievements
    {
        ACHIEVEMENT_SIMPLY_ABOMINABLE       = 279,
        ACHIEVEMENT_ON_METZEN               = 273,
        ACHIEVEMENT_HE_KNOW_BEEN_NAUGHTY    = 1689
    };

    void OnQuestStatusChange(Player* player, uint32 questId) override
    {
        if (!player->IsQuestRewarded(questId))
            return;

        if (questId == QUEST_A_SMOKYWOOD_PASTURES_THANK_YOU_A ||
            questId == QUEST_A_SMOKYWOOD_PASTURES_THANK_YOU_H)
        {
            player->CompletedAchievement(ACHIEVEMENT_SIMPLY_ABOMINABLE);
        }
        else if (questId == QUEST_YOU_RE_A_MEAN_ONE_A ||
                 questId == QUEST_YOU_RE_A_MEAN_ONE_H)
        {
            player->CompletedAchievement(ACHIEVEMENT_ON_METZEN);
        }
        else if (questId == QUEST_CHRISTMAS_GIFT_1 ||
                 questId == QUEST_CHRISTMAS_GIFT_2 ||
                 questId == QUEST_CHRISTMAS_GIFT_3 ||
                 questId == QUEST_CHRISTMAS_GIFT_4 ||
                 questId == QUEST_CHRISTMAS_GIFT_5 ||
                 questId == QUEST_CHRISTMAS_GIFT_6)
        {
            player->CompletedAchievement(ACHIEVEMENT_HE_KNOW_BEEN_NAUGHTY);
        }
    }
};

void AddSC_event_winter_veil()
{
    new npc_racer_slam_bunny();
    new npc_abominable_grinch();
    new npc_winter_veil_strange_snowman();
    new spell_throw_bomb();
    new npc_throw_bomb_bunny();
    new npc_sergent_vanderlip();
    new spell_winter_veil_mistletoe();
    new spell_winter_veil_snowball();

    new playerScript_winter_veil_quest_reward();
}

