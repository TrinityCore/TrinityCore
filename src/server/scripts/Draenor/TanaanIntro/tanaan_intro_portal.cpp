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
#include "GameObject.h"
#include "Player.h"
#include "tanaan_intro.h"
#include "TemporarySummon.h"

enum eCreatures
{
    // Company
    NPC_KHADGAR                 = 78558,
    NPC_OLIN                    = 79315,
    NPC_THAELIN                 = 78568,
    NPC_HANSEL                  = 78569,

    // Ennemy
    NPC_IRON_GRUNT              = 78883,
    NPC_SHADOWMOON_RITUALIST    = 81711,

    // Ally
    NPC_VANGUARD_MUMPER         = 82188, // Escalier
    NPC_VANGUARD_MORICCALAS     = 81990, // Escalier

    NPC_VANGUARD_ARNOLD         = 79062,
    NPC_VANGUARD_RACY           = 82082,
    NPC_VANGUARD_ASTRYLIAN      = 81993,
    NPC_VANGUARD_CORSELLE       = 81994,
    NPC_VANGUARD_MAELGWYN       = 81995,
    NPC_VANGUARD_TURKINA        = 81996,
    NPC_VANGUARD_ROAGUE         = 81997,
    NPC_VANGUARD_ANRUIN         = 81998,
    NPC_VANGUARD_NEVO           = 81999,
    NPC_VANGUARD_ELAYNEA        = 82000,
    NPC_VANGUARD_MONISHOT       = 82001,
    NPC_VANGUARD_ALYA           = 82002, // Enemy : Shadowmoon Ritualist
    NPC_VANGUARD_ED             = 82003,
    NPC_VANGUARD_SALTY          = 82004,
    NPC_VANGUARD_CHALLE         = 82005,
    NPC_VANGUARD_PAZO           = 82006,
    NPC_VANGUARD_TORE           = 82007,
    NPC_VANGUARD_MALOTHAS       = 82008,
    NPC_VANGUARD_BARBERY        = 82009,
    NPC_VANGUARD_BONESAW        = 82010,
    NPC_VANGUARD_NORTHPAUL      = 82011,
    NPC_VANGUARD_KENGTUS        = 82012,
    NPC_VANGUARD_DARRAGH        = 82013,
    NPC_VANGUARD_ARCHON         = 82014, // Enemy : Shadowmoon Ritualist
    NPC_VANGUARD_MOONALLI       = 82015,
    NPC_VANGUARD_DURPHORN       = 82016,
    NPC_VANGUARD_MISERAIN       = 82017,
    NPC_VANGUARD_YOORI          = 82025,
    NPC_VANGUARD_RYII           = 82075,
    NPC_VANGUARD_ETUBRUTE       = 82187,
    NPC_VANGUARD_LUPAS          = 82189,
    NPC_VANGUARD_SHOJU          = 82191,
    NPC_VANGUARD_RAINIARA       = 82260,
    NPC_VANGUARD_AGIOS          = 82263,
    NPC_VANGUARD_JOHNNY         = 82264
};

enum eEvents
{
    EVENT_AGGRO     = 1
};

enum eKillCredits
{
    CREDIT_DARK_PORTAL_KILL      = 78419,
    CREDIT_STATIS_RUNE_DESTROYED = 78333,
    CREDIT_ENTER_GULDAN_PRISON   = 82573
};

class npc_generic_tanaan_guardian : public CreatureScript
{
public:
    npc_generic_tanaan_guardian() : CreatureScript("npc_generic_tanaan_guardian") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_generic_tanaan_guardianAI(creature);
    }

    struct npc_generic_tanaan_guardianAI : public ScriptedAI
    {
        npc_generic_tanaan_guardianAI(Creature* creature) : ScriptedAI(creature), summons(creature) { }

        EventMap events;
        SummonList summons;

        uint32 ennemyId;
        uint8 ennemyNumber;
        uint8 randomSpellIndex;

        enum Events
        {
            EVENT_CHECK_ENNEMY      = 1,
            EVENT_RESTORE_HEALTH    = 2,
            EVENT_RANDOM_SPELL      = 3
        };

        enum Spells
        {
            SPELL_RITUALIST_SPAWN   = 158396
        };

        void Reset() override
        {
            if (me->GetAreaId() != AREA_TANAAN_DARK_PORTAL)
                return;

            switch (me->GetEntry())
            {
                case NPC_VANGUARD_ALYA:
                case NPC_VANGUARD_ARCHON:
                    ennemyId = NPC_SHADOWMOON_RITUALIST;
                    break;
                default:
                    ennemyId = NPC_IRON_GRUNT;
                    break;
            }

            ennemyNumber = urand(1, 3);
            randomSpellIndex = 0;

            events.ScheduleEvent(EVENT_CHECK_ENNEMY,    1000);
            events.ScheduleEvent(EVENT_RESTORE_HEALTH,  10000);
            events.ScheduleEvent(EVENT_RANDOM_SPELL,    urand(5000, 10000));

            me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }

        bool IsEscalierVangard()
        {
            return me->GetEntry() == NPC_VANGUARD_MUMPER || me->GetEntry() == NPC_VANGUARD_MORICCALAS;
        }

        void SpawnEnnemy()
        {
            Position ennemySpawnPos = me->GetPosition();

            if (IsEscalierVangard())
            {
                // TODO
                return;
            }

            if (ennemyId == NPC_SHADOWMOON_RITUALIST)
                GetRandPosFromCenterInDist(me, frand(3.0f, 7.0f), ennemySpawnPos);
            else
                GetPositionWithDistInOrientation(me, 2.0f, me->GetOrientation() + frand(-3.0f, 3.0f), ennemySpawnPos);

            if (TempSummon* ennemy = me->SummonCreature(ennemyId, ennemySpawnPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
            {
                if (ennemyId == NPC_SHADOWMOON_RITUALIST)
                    ennemy->CastSpell(ennemy, SPELL_RITUALIST_SPAWN, true);

                //ennemy->SetPlayerDamageReq(ennemy->GetHealth() / 10);
                ennemy->Attack(me, ennemyId != NPC_SHADOWMOON_RITUALIST);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
            events.ScheduleEvent(EVENT_CHECK_ENNEMY, urand(2000, 10000));
        }

        void DamageTaken(Unit* p_DoneBy, uint32& damage) override
        {
            if (p_DoneBy->ToCreature())
            {
                if (me->GetHealth() <= damage || me->GetHealthPct() <= 80.0f)
                    damage = 0;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_ENNEMY:
                    {
                        uint8 currentEnnemyNumber = summons.size();
                        while (currentEnnemyNumber++ < ennemyNumber)
                            SpawnEnnemy();

                        break;
                    }
                    case EVENT_RESTORE_HEALTH:
                    {
                        me->SetFullHealth();
                        events.ScheduleEvent(EVENT_RESTORE_HEALTH, 10000);
                        break;
                    }
                    case EVENT_RANDOM_SPELL:
                    {
                        uint32 spellId = me->GetCreatureTemplate()->spells[randomSpellIndex];

                        if (!spellId)
                        {
                            randomSpellIndex = 0;
                            spellId = me->GetCreatureTemplate()->spells[randomSpellIndex];
                        }

                        if (!spellId)
                            break;

                        if (++randomSpellIndex > 6)
                            randomSpellIndex = 0;

                        DoCastVictim(spellId);
                        events.ScheduleEvent(EVENT_RANDOM_SPELL, urand(5000, 10000));
                        break;
                    }
                }
            }

            if (me->HasUnitState(UNIT_STATE_CASTING) || !UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

/// 82484 - Iron Gronnling (ennemy)
class npc_iron_gronnling : public CreatureScript
{
public:
    npc_iron_gronnling() : CreatureScript("npc_iron_gronnling") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_iron_gronnlingAI(creature);
    }

    struct npc_iron_gronnlingAI : public ScriptedAI
    {
        npc_iron_gronnlingAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            if (!me->HasUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL) ||
                !me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
            {
                me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            }
        }
    };
};

/// 237670 - Fucking big intact portal
class gob_intact_portal : public GameObjectScript
{
public:
    gob_intact_portal() : GameObjectScript("gob_intact_portal") { }

    struct gob_intact_portalAI : public GameObjectAI
    {
        gob_intact_portalAI(GameObject* go) : GameObjectAI(go) { }

        void Reset() override
        {
            go->setShouldIntersectWithAllPhases(true);
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new gob_intact_portalAI(go);
    }
};

/// 233056/233057 - Mark of the Shadowmoon/Bleeding Hollow
class gob_mark_of_tanaan : public GameObjectScript
{
public:
    gob_mark_of_tanaan() : GameObjectScript("gob_mark_of_tanaan") { }

    bool OnGossipHello(Player* player, GameObject* gameObject) override
    {
        if (player->GetQuestStatus(TanaanQuests::QuestOnslaughtEnd) == QUEST_STATUS_INCOMPLETE)
        {
            /// Shadowmoon Gob (Cho'Gall)
            if (gameObject->GetEntry() == TanaanGameObjects::GobMarkOfShadowmoon)
            {
                player->RemoveAurasDueToSpell(TanaanPhases::PhaseChoGallSpell);

                if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjNorthernSpireDisabled) >= 1)
                    return true;

                player->KilledMonsterCredit(TanaanKillCredits::CreditNorthernSpireDisabled);
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneChoGallsFreedom);
            }
            /// Bleeding Hollow Gob (Teron'Gor)
            else if (gameObject->GetEntry() == TanaanGameObjects::GobMarkOfBleedingHollow)
            {
                player->RemoveAurasDueToSpell(TanaanPhases::PhaseTeronGorSpell);

                if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjSouthernSpireDisabled) >= 1)
                    return true;

                player->KilledMonsterCredit(TanaanKillCredits::CreditSouthernSpireDisabled);
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneTeronGorsFreedom);
            }
        }
        return true;
    }
};

// Custom AT gul'dan trigger - 100000
struct at_tanaan_guldan_trigger : AreaTriggerAI
{
    at_tanaan_guldan_trigger(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    int32 timeInterval;

    void OnUnitEnter(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetQuestStatus(TanaanQuests::QuestThePortalPower) == QUEST_STATUS_INCOMPLETE)
                player->KilledMonsterCredit(TanaanKillCredits::CreditEnterGuldanPrison);
    }
};

/// 233104 - Statis Rune
class gob_static_rune : public GameObjectScript
{
public:
    gob_static_rune() : GameObjectScript("gob_static_rune") { }

    bool OnGossipHello(Player* player, GameObject* /*gameObject*/) override
    {
        if (player->GetQuestStatus(TanaanQuests::QuestThePortalPower) == QUEST_STATUS_INCOMPLETE && player->GetQuestObjectiveCounter(273936) < 1)
        {
            if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBurningBladeDestroyed) == 0 ||
                player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjShatteredHandDestroyed) == 0 ||
                player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBlackrockMarkDestroyed) == 0)
                return true;

            player->KilledMonsterCredit(TanaanKillCredits::CreditStatisRuneDestroyed);
            player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneGulDanFreedom);
        }
        return true;
    }
};

void AddSC_tanaan_intro_portal()
{
    new npc_generic_tanaan_guardian();
    new npc_iron_gronnling();

    RegisterAreaTriggerAI(at_tanaan_guldan_trigger);

    new gob_intact_portal();
    new gob_static_rune();
    new gob_mark_of_tanaan();
}
