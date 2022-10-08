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

#include "ScriptMgr.h"
#include "CreatureTextMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    SPELL_BANISHMENT            = 116272,
    SPELL_SOUL_CUT_SUICIDE      = 116278,
    SPELL_SOUL_CUT_DAMAGE       = 117337,

    SPELL_TAP_THE_SPIRIT_WORLD  = 117002, // Only cosmetic
    SPELL_CHANNEL_SPIRIT_TOTEM  = 116833, // Only cosmetic
    SPELL_STRONG_MOJO           = 115964, // Only cosmetic
    SPELL_VOODOO_DOLL_VISUAL    = 122151,
    SPELL_VOODOO_DOLL_SHARE     = 116000,
    SPELL_SUMMON_SPIRIT_TOTEM   = 116174,
    SPELL_COSMETIC_SUMMON       = 118086, // Only cosmetic - Tiki mask
    SPELL_SOUL_CUTTER_COSMETIC  = 120677, // Only cosmetic - Tiki mask too
    SPELL_SUMMON_MINION         = 118087,

    // attaques ombreuses
    SPELL_RIGHT_CROSS           = 117215,
    SPELL_LEFT_HOOK             = 117218,
    SPELL_HAMMER_FIST           = 117219,
    SPELL_SWEEPING_KICK         = 117222,

    SPELL_FRENESIE              = 117752,

    // Shadowy Minion
    SPELL_SHADOW_BOLT           = 122118,
    SPELL_SPIRITUAL_GRASP       = 118421,

    // Misc
    SPELL_CLONE                 = 119051,
    SPELL_CLONE_VISUAL          = 119053,
    SPELL_LIFE_FRAGILE_THREAD   = 116227,
    SPELL_CROSSED_OVER          = 116161, // Todo : virer le summon
    SPELL_ANIM_VISUAL           = 121475,

    SPELL_FRAIL_SOUL            = 117723, // Heroic
    SPELL_SOUL_EXPLOSION        = 120639,
    SPELL_ROOT_FOR_EVER         = 31366,

    // Death Event
    SPELL_RELEASE_SPIRIT        = 118580, // Summon Gara'jal Ghost
    SPELL_SPIRIT_HOVER          = 75333,
    SPELL_GHOST_VISUAL          = 91218,
    SPELL_SPIRITUAL_PORTAL      = 118581, // Summon Spiritual Portal
    SPELL_VISUAL_PORTAL         = 118661, // Portal Visual

    // Enrage
    SPELL_FINAL_DESTINATION     = 118469,
    SPELL_INSTANTLY_DEATH       = 118443,

    SPELL_GARAJAL_BONUS         = 132190
};

enum eEvents
{
    EVENT_SECONDARY_ATTACK      = 1,
    EVENT_SUMMON_TOTEM          = 2,
    EVENT_SUMMON_SHADOWY_MINION = 3,
    EVENT_VOODOO_DOLL           = 4,
    EVENT_BANISHMENT            = 5,

    // Shadowy Minion
    EVENT_SHADOW_BOLT           = 6,
    EVENT_SPIRITUAL_GRASP       = 7,
    EVENT_CHECK_PLAYER          = 8,
    EVENT_CLONE_TAKEOFF         = 9,


    // Gara'Jal Ghost
    EVENT_GROWTH                = 10,
    EVENT_TALK_DEATH            = 11,
    EVENT_SUMMON_PORTAL         = 12,
    EVENT_DISAPPEAR             = 13,

    // Enrage
    EVENT_FINAL_DESTINATION     = 14,
    EVENT_SOUL_EXPLOSION        = 15,
    EVENT_CHECK_POSITION        = 16
};

enum GarajalTalk
{
    TALK_AGGRO  = 0,
    TALK_SLAY   = 1,
    TALK_FRENZY = 2
};

enum GarajalGhostTalk
{
    TALK_DEATH  = 0
};

// 60143 - Gara'jal the Spiritbinder
class boss_garajal : public CreatureScript
{
    public:
        boss_garajal() : CreatureScript("boss_garajal") {}

        struct boss_garajalAI : public BossAI
        {
            boss_garajalAI(Creature* creature) : BossAI(creature, DATA_GARAJAL)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;
            ObjectGuid voodooTargets[3];

            void Reset() override
            {
                _Reset();

                if (m_Instance->GetBossState(DATA_GARAJAL) != DONE)
                    m_Instance->SetBossState(DATA_GARAJAL, NOT_STARTED);

                m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOODOO_DOLL_VISUAL);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOODOO_DOLL_SHARE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLONE_VISUAL);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CROSSED_OVER);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LIFE_FRAGILE_THREAD);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUL_CUT_DAMAGE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUL_CUT_SUICIDE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BANISHMENT);

                me->AddAura(SPELL_STRONG_MOJO, me);
                me->CastSpell(me, SPELL_TAP_THE_SPIRIT_WORLD, true);
                me->SetReactState(REACT_PASSIVE);
            }

            void JustDied(Unit* /*p_Attacker*/) override
            {
                m_Instance->SetBossState(DATA_GARAJAL, DONE);
                _JustDied();
                me->CastSpell(me, SPELL_RELEASE_SPIRIT, false);

                events.Reset();
                m_Instance->SetBossState(DATA_GARAJAL, DONE);
                m_Instance->SaveToDB();

                m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOODOO_DOLL_VISUAL);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOODOO_DOLL_SHARE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLONE_VISUAL);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CROSSED_OVER);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LIFE_FRAGILE_THREAD);

                if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 200.0f, true))
                {
                    if (lorewalkerCho->AI())
                    {
                        lorewalkerCho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                        lorewalkerCho->AI()->DoAction(ACTION_RUN);
                    }
                }

                Map::PlayerList const& l_PlrList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
                {
                    if (Player* l_Player = l_Itr->GetSource())
                        me->CastSpell(l_Player, SPELL_GARAJAL_BONUS, true);
                }

                /*if (IsLFR())
                {
                    me->SetLootRecipient(nullptr);

                    bool l_Assigned = false;
                    for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
                    {
                        if (Player* l_Player = l_Itr->GetSource())
                        {
                            uint32 l_DungeonID = l_Player->GetGroup() ? sLFGMgr->GetDungeon(l_Player->GetGroup()->GetGUID()) : 0;
                            if (!me || l_Player->IsAtGroupRewardDistance(me))
                                sLFGMgr->RewardDungeonDoneFor(l_DungeonID, l_Player);

                            if (l_Assigned)
                                continue;

                            if (Group* l_Group = l_Player->GetGroup())
                            {
                                l_Assigned = true;
                                sLFGMgr->AutomaticLootAssignation(me, l_Group);
                            }
                        }
                    }
                }*/
            }

            void EnterCombat(Unit* attacker) override
            {
                // Can't be pulled if previous bosses hasn't been done, or if attacker isn't in the battle area
                if (!m_Instance->CheckRequiredBosses(DATA_GARAJAL) || attacker->GetPositionX() < 4240.0f || attacker->GetPositionY() > 1380.0f)
                {
                    me->AddAura(SPELL_STRONG_MOJO, me);
                    me->CastSpell(me, SPELL_TAP_THE_SPIRIT_WORLD, true);

                    EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }

                me->SetReactState(REACT_AGGRESSIVE);
                m_Instance->SetBossState(DATA_GARAJAL, IN_PROGRESS);
                m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                Talk(TALK_AGGRO);

                events.ScheduleEvent(EVENT_SECONDARY_ATTACK,        urand(5000, 10000));
                events.ScheduleEvent(EVENT_SUMMON_TOTEM,            urand(27500, 32500));
                events.ScheduleEvent(EVENT_SUMMON_SHADOWY_MINION,   urand(10000, 15000));
                events.ScheduleEvent(EVENT_BANISHMENT,              90000);
                events.ScheduleEvent(EVENT_VOODOO_DOLL,             2500);
                events.ScheduleEvent(EVENT_FINAL_DESTINATION,       361000); // 6 min & 10s

                me->RemoveAura(SPELL_STRONG_MOJO);
                me->RemoveAura(SPELL_TAP_THE_SPIRIT_WORLD);

                me->InterruptNonMeleeSpells(false);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->IsPlayer())
                    Talk(TALK_SLAY);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (!m_Instance)
                    return;

                // Can't be pulled if previous bosses hasn't been done, or if attacker isn't in the battle area
                if (!m_Instance->CheckRequiredBosses(DATA_GARAJAL) || attacker->GetPositionX() < 4240.0f || attacker->GetPositionY() > 1380.0f)
                {
                    me->AddAura(SPELL_STRONG_MOJO, me);
                    me->CastSpell(me, SPELL_TAP_THE_SPIRIT_WORLD, true);
                    me->SetFullHealth();

                    EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }

                if (!me->HasAura(SPELL_FRENESIE))
                {
                    if (me->HealthBelowPctDamaged(20, damage))
                    {
                        me->CastSpell(me, SPELL_FRENESIE, true);
                        me->TextEmote("Gara'jal casts |cffba2200|Hspell:117752|h[Frenzy]|h|r !", 0, true);
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SECONDARY_ATTACK:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            {
                                uint32 spellId = RAND(SPELL_RIGHT_CROSS, SPELL_LEFT_HOOK, SPELL_HAMMER_FIST, SPELL_SWEEPING_KICK);
                                me->CastSpell(target, spellId, true);
                            }
                            events.ScheduleEvent(EVENT_SECONDARY_ATTACK, urand(5000, 10000));
                            break;
                        }
                        case EVENT_SUMMON_TOTEM:
                        {
                            me->TextEmote("Gara'jal summons a Spirit Totem. Use it to Cross Over to the Spirit World !", 0, true);
                            float x = 0.0f, y = 0.0f;
                            GetRandPosFromCenterInDist(4277.08f, 1341.35f, frand(0.0f, 30.0f), x, y);
                            me->SummonCreature(NPC_SPIRIT_TOTEM, x, y, 454.55f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                            events.ScheduleEvent(EVENT_SUMMON_TOTEM,     urand(47500, 52500));
                            break;
                        }
                        case EVENT_SUMMON_SHADOWY_MINION:
                        {
                            float x = 0.0f, y = 0.0f;
                            GetRandPosFromCenterInDist(4277.08f, 1341.35f, frand(0.0f, 30.0f), x, y);
                            me->SummonCreature(NPC_SHADOWY_MINION_REAL, x, y, 454.55f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                            events.ScheduleEvent(EVENT_SUMMON_SHADOWY_MINION,     urand(10000, 15000));
                            break;
                        }
                        case EVENT_VOODOO_DOLL:
                        {
                            m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOODOO_DOLL_VISUAL);
                            m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOODOO_DOLL_SHARE);
                            me->TextEmote("Gara'jal selects random players to become |cffba2200|Hspell:116000|h[Voodoo Dolls]|h|r !", 0, true);

                            int32 mobCount = Is25ManRaid() ? 4 : 3;

                            for (int32 i = 0; i < mobCount; ++i)
                            {
                                if (Unit* target = SelectTarget(i == 0 ? SELECT_TARGET_TOPAGGRO : SELECT_TARGET_RANDOM, 0, 0, true, -SPELL_VOODOO_DOLL_VISUAL))
                                {
                                    voodooTargets[i] = target->GetGUID();
                                    me->TextEmote("You are a |cffba2200|Hspell:116000|h[Voodoo Doll]|h|r ! Damage you take is copied to the other Voodoo Dolls in your raid !", target, true);
                                    target->AddAura(SPELL_VOODOO_DOLL_VISUAL, target);
                                }
                            }

                            if (Player* target = ObjectAccessor::GetPlayer(*me, voodooTargets[0]))
                                me->CastSpell(target, SPELL_VOODOO_DOLL_SHARE, true);

                            break;
                        }
                        case EVENT_BANISHMENT:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            {
                                me->AddAura(SPELL_BANISHMENT,       target);
                                me->AddAura(SPELL_SOUL_CUT_SUICIDE, target);
                                me->AddAura(SPELL_SOUL_CUT_DAMAGE,  target);

                                uint8  mobCount   = IsHeroic() ? 3: 1;

                                for (uint8 i = 0; i < mobCount; ++i)
                                    if (Creature* soulCutter = me->SummonCreature(NPC_SOUL_CUTTER, target->GetPositionX() + 2.0f, target->GetPositionY() + 2.0f, target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 30000, i == 0))
                                    {
                                        soulCutter->GetPhaseShift().AddPhase(170, PhaseFlags::None, nullptr);
                                        soulCutter->AI()->AttackStart(target);
                                        soulCutter->SetInCombatWith(target);
                                        soulCutter->getThreatManager().addThreat(target, 10000.0f);
                                    }

                                me->getThreatManager().resetAllAggro();
                            }

                            m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOODOO_DOLL_VISUAL);
                            m_Instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOODOO_DOLL_SHARE);

                            events.ScheduleEvent(EVENT_VOODOO_DOLL, 5000);
                            events.ScheduleEvent(EVENT_BANISHMENT, 90000);
                            break;
                        }
                        case EVENT_FINAL_DESTINATION:
                        {
                            me->CastSpell(me, SPELL_FINAL_DESTINATION, false);
                            Talk(TALK_FRENZY);
                            break;
                        }
                        default:
                            break;
                    }
                }
                if (me->GetReactState() == REACT_AGGRESSIVE)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_garajalAI(creature);
        }
};

// 61140 - Gara'jal the Spiritbinder
class mob_garajal_ghost : public CreatureScript
{
    public:
        mob_garajal_ghost() : CreatureScript("mob_garajal_ghost") {}

        struct mob_garajal_ghostAI : public ScriptedAI
        {
            mob_garajal_ghostAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;
            float ghostScale;

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                me->AddAura(SPELL_GHOST_VISUAL, me);
                me->AddAura(SPELL_STRONG_MOJO, me);
                me->AddAura(SPELL_SPIRIT_HOVER, me);
                ghostScale = me->GetObjectScale();
                me->SetObjectScale(ghostScale / 10.0f);

                events.ScheduleEvent(EVENT_GROWTH,          200);
                events.ScheduleEvent(EVENT_TALK_DEATH,      4000);
                events.ScheduleEvent(EVENT_SUMMON_PORTAL,   8000);
                events.ScheduleEvent(EVENT_DISAPPEAR,       13000);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_SPIRITUAL_PORTAL)
                {
                    summon->CastSpell(summon, SPELL_VISUAL_PORTAL, true);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (pInstance->GetBossState(DATA_GARAJAL) != DONE)
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GROWTH:
                            if (me->GetObjectScale() < ghostScale)
                            {
                                me->SetObjectScale(me->GetObjectScale() + (ghostScale / 10.0f));
                                events.ScheduleEvent(EVENT_GROWTH, 200);
                            }
                            break;
                        case EVENT_TALK_DEATH:
                            Talk(TALK_DEATH);
                            break;
                        case EVENT_SUMMON_PORTAL:
                            me->CastSpell(me, SPELL_SPIRITUAL_PORTAL, true);
                            break;
                        case EVENT_DISAPPEAR:
                            if (Creature* spiritualPortal = me->FindNearestCreature(NPC_SPIRITUAL_PORTAL, 50.0f))
                                spiritualPortal->DespawnOrUnsummon(5000);
                            me->DespawnOrUnsummon(500);
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_garajal_ghostAI(creature);
        }
};

// 60240 - Spirit Totem
class mob_spirit_totem : public CreatureScript
{
    public:
        mob_spirit_totem() : CreatureScript("mob_spirit_totem") {}

        struct mob_spirit_totemAI : public ScriptedAI
        {
            mob_spirit_totemAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            void Reset() override
            {
                me->AddAura(116827, me);
                me->AddAura(SPELL_ROOT_FOR_EVER, me);
                me->SetReactState(REACT_PASSIVE);
            }

            void JustDied(Unit* /*p_Attacker*/) override
            {
                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 6.0f);

                uint8 count = 0;
                for (auto player: playerList)
                {
                    if (player->HasAura(SPELL_VOODOO_DOLL_VISUAL) || player->HasAura(SPELL_FRAIL_SOUL))
                        continue;

                    if (++count > 3)
                        break;

                    if (Creature* clone = me->SummonCreature(56405, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation()))
                    {
                        if (player->GetHealthPct() >= 10.0f)
                            player->SetHealth(player->GetMaxHealth() / 10);

                        player->CastSpell(player, SPELL_CLONE_VISUAL, true);
                        player->CastSpell(player, SPELL_CROSSED_OVER, true);

                        player->CastSpell(clone,  SPELL_CLONE, true);

                        clone->CastSpell(clone, SPELL_LIFE_FRAGILE_THREAD, true);
                        clone->GetMotionMaster()->MoveTakeoff(1, Position(clone->GetPositionX(), clone->GetPositionY(), clone->GetPositionZ() + 10.0f));

                        player->AddAura(SPELL_LIFE_FRAGILE_THREAD, player);
                    }
                }
            }

            void UpdateAI(const uint32 /*p_Diff*/) override
            {
                if (pInstance)
                    if (pInstance->GetBossState(DATA_GARAJAL) != IN_PROGRESS)
                        me->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_spirit_totemAI(creature);
        }
};

// 60184 - Shadowy Minion - Only visible in spirit world
// 60940 - Shadowy Minion - Visible for all players
class mob_shadowy_minion : public CreatureScript
{
    public:
        mob_shadowy_minion() : CreatureScript("mob_shadowy_minion") {}

        struct mob_shadowy_minionAI : public Scripted_NoMovementAI
        {
            mob_shadowy_minionAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            ObjectGuid spiritGuid;
            EventMap events;

            void Reset() override
            {
                events.Reset();
                spiritGuid = ObjectGuid::Empty;

                if (me->GetEntry() == NPC_SHADOWY_MINION_REAL)
                {
                    me->SetDisplayId(11686);

                    // Summoning 2 spirit minions
                    for (uint8 i = 0; i < 2; ++i)
                    {
                        if (Creature* spirit = me->SummonCreature(NPC_SHADOWY_MINION_SPIRIT, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN))
                        {
                            spiritGuid = spirit->GetGUID();
                            spirit->GetPhaseShift().AddPhase(170, PhaseFlags::None, nullptr);
                        }
                    }
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
                    events.ScheduleEvent(EVENT_SPIRITUAL_GRASP, urand(2000, 5000));
                }
                else
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(2000, 5000));

                me->AddAura(SPELL_COSMETIC_SUMMON, me);

                DoZoneInCombat();
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_SHADOWY_MINION_SPIRIT)
                    me->DespawnOrUnsummon();
            }

            void JustDied(Unit* /*p_Attacker*/) override
            {
                if (me->GetEntry() == NPC_SHADOWY_MINION_SPIRIT)
                    if (me->ToTempSummon())
                        if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                            if (summoner->ToCreature())
                                summoner->ToCreature()->DespawnOrUnsummon();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (pInstance)
                    if (pInstance->GetBossState(DATA_GARAJAL) != IN_PROGRESS)
                        me->DespawnOrUnsummon();

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Spirit World
                        case EVENT_SHADOW_BOLT:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, false, SPELL_CROSSED_OVER))
                                me->CastSpell(target, SPELL_SHADOW_BOLT, false);
                            else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, false, SPELL_SOUL_CUT_SUICIDE))
                                me->CastSpell(target, SPELL_SHADOW_BOLT, false);

                            events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(2000, 3000));
                            break;
                        }
                        // Real World
                        case EVENT_SPIRITUAL_GRASP:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, false, -SPELL_SOUL_CUT_SUICIDE))
                                me->CastSpell(target, SPELL_SPIRITUAL_GRASP, false);
                            else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, false, -SPELL_CROSSED_OVER))
                                me->CastSpell(target, SPELL_SPIRITUAL_GRASP, false);

                            events.ScheduleEvent(EVENT_SPIRITUAL_GRASP, urand(5000, 8000));
                            break;
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_shadowy_minionAI(creature);
        }
};

// 62003 - Severer of Souls
class mob_soul_cutter : public CreatureScript
{
    public:
        mob_soul_cutter() : CreatureScript("mob_soul_cutter") {}

        struct mob_soul_cutterAI : public ScriptedAI
        {
            mob_soul_cutterAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            void Reset() override
            {
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SOUL_EXPLOSION, 30000);
            }

            void JustDied(Unit* /*p_Attacker*/) override
            {
                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 100.f);

                for (auto player : playerList)
                {
                    player->RemoveAurasDueToSpell(SPELL_BANISHMENT);
                    player->RemoveAurasDueToSpell(SPELL_SOUL_CUT_SUICIDE);
                    player->RemoveAurasDueToSpell(SPELL_SOUL_CUT_DAMAGE);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (pInstance)
                    if (pInstance->GetBossState(DATA_GARAJAL) != IN_PROGRESS)
                        me->DespawnOrUnsummon();

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_SOUL_EXPLOSION:
                        {
                            std::list<Player*> playerList;
                            me->GetPlayerListInGrid(playerList, 300.0f);
                            bool hasCast = false;

                            if (playerList.empty())
                                break;

                            while (!hasCast)
                            {
                                if (playerList.empty())
                                    break;

                                for (auto player : playerList)
                                {
                                    if (urand(0, 1))
                                    {
                                        me->CastSpell(player, SPELL_SOUL_EXPLOSION, false);
                                        hasCast = true;
                                    }
                                }
                            }

                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_SOUL_EXPLOSION, 30000);

                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_soul_cutterAI(creature);
        }
};

// 60512 - Spirit Totem
// 60513 - Spirit Totem
class mob_spirit_totem_intro : public CreatureScript
{
    public:
        mob_spirit_totem_intro() : CreatureScript("mob_spirit_totem_intro") {}

        struct mob_spirit_totem_introAI : public ScriptedAI
        {
            mob_spirit_totem_introAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                creature->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            }

            InstanceScript* pInstance;

            void Reset() override
            {
                if (me->GetEntry() == NPC_SPIRIT_TOTEM_SKULL_INTRO)
                    me->SetDisplayId(11686);
            }

            void UpdateAI(const uint32 /*p_Diff*/) override
            {
                if (Unit* skull = me->FindNearestCreature(NPC_SPIRIT_TOTEM_SKULL_INTRO, 15))
                    if (!skull->HasAura(SPELL_CHANNEL_SPIRIT_TOTEM))
                        me->CastSpell(skull, SPELL_CHANNEL_SPIRIT_TOTEM, true);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_spirit_totem_introAI(creature);
        }
};

// Soul Back - 120715
class spell_soul_back : public SpellScriptLoader
{
    public:
        spell_soul_back() : SpellScriptLoader("spell_soul_back") { }

        class spell_soul_back_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_soul_back_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    // SPELL_LIFE_FRAGILE_THREAD removed by default effect
                    target->RemoveAurasDueToSpell(SPELL_CLONE_VISUAL);
                    target->RemoveAurasDueToSpell(SPELL_CROSSED_OVER);
                    if (target->GetMap()->IsHeroic())
                        target->AddAura(SPELL_FRAIL_SOUL, target);
                    target->SetHealth(target->CountPctFromCurHealth(30));

                    // Todo : Jump le joueur la ou etait son corps
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_soul_back_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_REMOVE_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_soul_back_SpellScript();
        }
};

// Final Destination - 118469
class spell_final_destination : public SpellScriptLoader
{
    public:
        spell_final_destination() : SpellScriptLoader("spell_final_destination") { }

        class spell_final_destination_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_final_destination_AuraScript);

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (Unit* Garajal = GetCaster())
                {
                    if (InstanceScript* pInstance = Garajal->GetInstanceScript())
                    {
                        Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();

                        if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                if (Player* player = i->GetSource())
                                    if (player->IsAlive())
                                        Garajal->CastSpell(player, SPELL_INSTANTLY_DEATH, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_final_destination_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_final_destination_AuraScript();
        }
};

// Voodoo Doll - 122151
class spell_voodoo_doll : public SpellScriptLoader
{
    public:
        spell_voodoo_doll() : SpellScriptLoader("spell_voodoo_doll") { }

        class spell_voodoo_doll_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_voodoo_doll_AuraScript);

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                    target->AddAura(65371, target);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_voodoo_doll_AuraScript::Apply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_voodoo_doll_AuraScript();
        }
};

// 60240 - Clone player
struct mob_clone_player : public ScriptedAI
{
    mob_clone_player(Creature* creature) : ScriptedAI(creature)
    {
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddAura(SPELL_ANIM_VISUAL, me);
        me->SetCanFly(true);
        me->SetDisableGravity(true);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
        events.ScheduleEvent(EVENT_CHECK_PLAYER, 5000);
        events.ScheduleEvent(EVENT_CLONE_TAKEOFF, 3000);
    }

    void UpdateAI(const uint32 diff) override
    {
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Spirit World
            case EVENT_CHECK_PLAYER:
                if (me->ToTempSummon())
                    if (Unit * Summoner = me->ToTempSummon()->GetSummoner())
                        if (!Summoner->HasAura(SPELL_CROSSED_OVER))
                            me->DespawnOrUnsummon();
                events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                break;
            case EVENT_CLONE_TAKEOFF:
                me->GetMotionMaster()->MoveTakeoff(1, me->GetPositionX());
                break;
            }
        }
    }
};

void AddSC_boss_garajal()
{
    new boss_garajal();
    new mob_garajal_ghost();
    new mob_spirit_totem();
    new mob_shadowy_minion();
    new mob_soul_cutter();
    new mob_spirit_totem_intro();
    new spell_soul_back();
    new spell_final_destination();
    new spell_voodoo_doll();
    RegisterCreatureAI(mob_clone_player);
}
