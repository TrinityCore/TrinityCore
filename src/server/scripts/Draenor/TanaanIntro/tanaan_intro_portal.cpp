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

#include "tanaan_intro.h"
#include "GameObject.h"

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

    CreatureAI* GetAI(Creature* creature) const
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

        void Reset()
        {
            if (me->GetAreaId() != TanaanZones::AreaTheDarkPortal)
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

            me->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
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

            if (Creature* ennemy = me->SummonCreature(ennemyId, ennemySpawnPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
            {
                if (ennemyId == NPC_SHADOWMOON_RITUALIST)
                    ennemy->CastSpell(ennemy, SPELL_RITUALIST_SPAWN, true);

                //ennemy->SetPlayerDamageReq(ennemy->GetHealth() / 10);
                ennemy->Attack(me, ennemyId != NPC_SHADOWMOON_RITUALIST);
            }
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            summons.Despawn(summon);
            events.ScheduleEvent(EVENT_CHECK_ENNEMY, urand(2000, 10000));
        }

        void DamageTaken(Unit* p_DoneBy, uint32& p_Damage)
        {
            if (p_DoneBy->ToCreature())
            {
                if (me->GetHealth() <= p_Damage || me->GetHealthPct() <= 80.0f)
                    p_Damage = 0;
            }
        }

        void UpdateAI(uint32 const p_Diff)
        {
            events.Update(p_Diff);

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
                            uint32 spellId = me->GetCreatureTemplate()->spells[randomSpellIndex];
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_iron_gronnlingAI(creature);
    }

    struct npc_iron_gronnlingAI : public ScriptedAI
    {
        npc_iron_gronnlingAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL ||
                !me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE)))
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
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

    bool OnGossipHello(Player* p_Player, GameObject* p_Gameobject) override
    {
        if (p_Player->GetQuestStatus(TanaanQuests::QuestOnslaughtEnd) == QUEST_STATUS_INCOMPLETE)
        {
            /// Shadowmoon Gob (Cho'Gall)
            if (p_Gameobject->GetEntry() == TanaanGameObjects::GobMarkOfShadowmoon)
            {
                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseChoGallSpell);

                if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjNorthernSpireDisabled) >= 1)
                    return true;

                p_Player->KilledMonsterCredit(TanaanKillCredits::CreditNorthernSpireDisabled);
                p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneChoGallsFreedom);
            }
            /// Bleeding Hollow Gob (Teron'Gor)
            else if (p_Gameobject->GetEntry() == TanaanGameObjects::GobMarkOfBleedingHollow)
            {
                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseTeronGorSpell);

                if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjSouthernSpireDisabled) >= 1)
                    return true;

                p_Player->KilledMonsterCredit(TanaanKillCredits::CreditSouthernSpireDisabled);
                p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneTeronGorsFreedom);
            }
        }
        return true;
    }
};

/// 300003 - Gul'Dan Trigger (Friendly)
class npc_gul_dan_trigger : public CreatureScript
{
public:
    npc_gul_dan_trigger() : CreatureScript("npc_gul_dan_trigger") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_gul_dan_triggerAI(creature);
    }

    struct npc_gul_dan_triggerAI : public ScriptedAI
    {
        npc_gul_dan_triggerAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* p_Unit) override
        {
            if (p_Unit->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* l_Player = p_Unit->ToPlayer();

            if (!l_Player || l_Player->GetPositionZ() > me->GetPositionZ() || !l_Player->isInFront(me))
                return;

            if (l_Player->GetQuestStatus(TanaanQuests::QuestThePortalPower) == QUEST_STATUS_INCOMPLETE && l_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjEnterGulDanPrison) < 1)
                l_Player->KilledMonsterCredit(TanaanKillCredits::CreditEnterGuldanPrison);
        }
    };
};

/// 233104 - Statis Rune
class gob_static_rune : public GameObjectScript
{
public:
    gob_static_rune() : GameObjectScript("gob_static_rune") { }

    bool OnGossipHello(Player* p_Player, GameObject* p_Gameobject) override
    {
        if (p_Player->GetQuestStatus(TanaanQuests::QuestThePortalPower) == QUEST_STATUS_INCOMPLETE && p_Player->GetQuestObjectiveCounter(273936) < 1)
        {
            if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBurningBladeDestroyed) == 0 ||
                p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjShatteredHandDestroyed) == 0 ||
                p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBlackrockMarkDestroyed) == 0)
                return true;

            p_Player->KilledMonsterCredit(TanaanKillCredits::CreditStatisRuneDestroyed);
            p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneGulDanFreedom);
        }
        return true;
    }
};

void AddSC_tanaan_intro_portal()
{
    new npc_generic_tanaan_guardian();
    new npc_iron_gronnling();
    new npc_gul_dan_trigger();

    new gob_intact_portal();
    new gob_static_rune();
    new gob_mark_of_tanaan();
}
