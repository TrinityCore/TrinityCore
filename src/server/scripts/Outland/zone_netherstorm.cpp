/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* ScriptData
SDName: Netherstorm
SD%Complete: 80
SDComment: Quest support: 10337, 10652 (special flight paths), 10198, 10191
SDCategory: Netherstorm
EndScriptData */

/* ContentData
npc_commander_dawnforge
EndContentData */

#include "ScriptMgr.h"
#include "Containers.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "EventMap.h"
#include "MotionMaster.h"
#include "WorldSession.h"
#include "Group.h"

/*######
## npc_commander_dawnforge
######*/

// The Speech of Dawnforge, Ardonis & Pathaleon
enum CommanderDawnforgeData
{
    SAY_COMMANDER_DAWNFORGE_1       = 0,
    SAY_COMMANDER_DAWNFORGE_2       = 1,
    SAY_COMMANDER_DAWNFORGE_3       = 2,
    SAY_COMMANDER_DAWNFORGE_4       = 3,
    SAY_COMMANDER_DAWNFORGE_5       = 4,

    SAY_ARCANIST_ARDONIS_1          = 0,
    SAY_ARCANIST_ARDONIS_2          = 1,

    SAY_PATHALEON_CULATOR_IMAGE_1   = 0,
    SAY_PATHALEON_CULATOR_IMAGE_2   = 1,
    SAY_PATHALEON_CULATOR_IMAGE_2_1 = 2,
    SAY_PATHALEON_CULATOR_IMAGE_2_2 = 3,

    QUEST_INFO_GATHERING            = 10198,
    SPELL_SUNFURY_DISGUISE          = 34603,
};

// Entries of Arcanist Ardonis, Commander Dawnforge, Pathaleon the Curators Image
const uint32 CreatureEntry[3] =
{
    19830,                                                // Ardonis
    19831,                                                // Dawnforge
    21504                                                 // Pathaleon
};

class npc_commander_dawnforge : public CreatureScript
{
public:
    npc_commander_dawnforge() : CreatureScript("npc_commander_dawnforge") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_commander_dawnforgeAI(creature);
    }

    struct npc_commander_dawnforgeAI : public ScriptedAI
    {
        npc_commander_dawnforgeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            PlayerGUID.Clear();
            ardonisGUID.Clear();
            pathaleonGUID.Clear();

            Phase = 1;
            PhaseSubphase = 0;
            Phase_Timer = 4000;
            isEvent = false;
        }

        ObjectGuid PlayerGUID;
        ObjectGuid ardonisGUID;
        ObjectGuid pathaleonGUID;

        uint32 Phase;
        uint32 PhaseSubphase;
        uint32 Phase_Timer;
        bool isEvent;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void JustSummoned(Creature* summoned) override
        {
            pathaleonGUID = summoned->GetGUID();
        }

        // Emote Ardonis and Pathaleon
        void Turn_to_Pathaleons_Image()
        {
            Creature* ardonis = ObjectAccessor::GetCreature(*me, ardonisGUID);
            Creature* pathaleon = ObjectAccessor::GetCreature(*me, pathaleonGUID);

            if (!ardonis || !pathaleon)
                return;

            // Turn Dawnforge
            me->SetFacingToObject(pathaleon);

            // Turn Ardonis
            ardonis->SetFacingToObject(pathaleon);

            //Set them to kneel
            me->SetStandState(UNIT_STAND_STATE_KNEEL);
            ardonis->SetStandState(UNIT_STAND_STATE_KNEEL);
        }

        //Set them back to each other
        void Turn_to_eachother()
        {
            if (Unit* ardonis = ObjectAccessor::GetUnit(*me, ardonisGUID))
            {
                // Turn Dawnforge
                me->SetFacingToObject(ardonis);

                // Turn Ardonis
                ardonis->SetFacingToObject(me);

                //Set state
                me->SetStandState(UNIT_STAND_STATE_STAND);
                ardonis->SetStandState(UNIT_STAND_STATE_STAND);
            }
        }

        bool CanStartEvent(Player* player)
        {
            if (!isEvent)
            {
                Creature* ardonis = me->FindNearestCreature(CreatureEntry[0], 10.0f);
                if (!ardonis)
                    return false;

                ardonisGUID = ardonis->GetGUID();
                PlayerGUID = player->GetGUID();

                isEvent = true;

                Turn_to_eachother();
                return true;
            }

            TC_LOG_DEBUG("scripts", "npc_commander_dawnforge event already in progress, need to wait.");
            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            //Is event even running?
            if (!isEvent)
                return;

            //Phase timing
            if (Phase_Timer >= diff)
            {
                Phase_Timer -= diff;
                return;
            }

            Creature* ardonis = ObjectAccessor::GetCreature(*me, ardonisGUID);
            Creature* pathaleon = ObjectAccessor::GetCreature(*me, pathaleonGUID);
            Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);

            if (!ardonis || !player)
            {
                Reset();
                return;
            }

            if (Phase > 4 && !pathaleon)
            {
                Reset();
                return;
            }

            //Phase 1 Dawnforge say
            switch (Phase)
            {
            case 1:
                Talk(SAY_COMMANDER_DAWNFORGE_1);
                ++Phase;
                Phase_Timer = 16000;
                break;
                //Phase 2 Ardonis say
            case 2:
                ardonis->AI()->Talk(SAY_ARCANIST_ARDONIS_1);
                ++Phase;
                Phase_Timer = 16000;
                break;
                //Phase 3 Dawnforge say
            case 3:
                Talk(SAY_COMMANDER_DAWNFORGE_2);
                ++Phase;
                Phase_Timer = 16000;
                break;
                //Phase 4 Pathaleon spawns up to phase 9
            case 4:
                //spawn pathaleon's image
                me->SummonCreature(CreatureEntry[2], 2325.851563f, 2799.534668f, 133.084229f, 6.038996f, TEMPSUMMON_TIMED_DESPAWN, 90s);
                ++Phase;
                Phase_Timer = 500;
                break;
                //Phase 5 Pathaleon say
            case 5:
                pathaleon->AI()->Talk(SAY_PATHALEON_CULATOR_IMAGE_1);
                ++Phase;
                Phase_Timer = 6000;
                break;
                //Phase 6
            case 6:
                switch (PhaseSubphase)
                {
                    //Subphase 1: Turn Dawnforge and Ardonis
                case 0:
                    Turn_to_Pathaleons_Image();
                    ++PhaseSubphase;
                    Phase_Timer = 8000;
                    break;
                    //Subphase 2 Dawnforge say
                case 1:
                    Talk(SAY_COMMANDER_DAWNFORGE_3);
                    PhaseSubphase = 0;
                    ++Phase;
                    Phase_Timer = 8000;
                    break;
                }
                break;
                //Phase 7 Pathaleons say 3 Sentence, every sentence need a subphase
            case 7:
                switch (PhaseSubphase)
                {
                    //Subphase 1
                case 0:
                    pathaleon->AI()->Talk(SAY_PATHALEON_CULATOR_IMAGE_2);
                    ++PhaseSubphase;
                    Phase_Timer = 12000;
                    break;
                    //Subphase 2
                case 1:
                    pathaleon->AI()->Talk(SAY_PATHALEON_CULATOR_IMAGE_2_1);
                    ++PhaseSubphase;
                    Phase_Timer = 16000;
                    break;
                    //Subphase 3
                case 2:
                    pathaleon->AI()->Talk(SAY_PATHALEON_CULATOR_IMAGE_2_2);
                    PhaseSubphase = 0;
                    ++Phase;
                    Phase_Timer = 10000;
                    break;
                }
                break;
                //Phase 8 Dawnforge & Ardonis say
            case 8:
                Talk(SAY_COMMANDER_DAWNFORGE_4);
                ardonis->AI()->Talk(SAY_ARCANIST_ARDONIS_2);
                ++Phase;
                Phase_Timer = 4000;
                break;
                //Phase 9 Pathaleons Despawn, Reset Dawnforge & Ardonis angle
            case 9:
                Turn_to_eachother();
                //hide pathaleon, unit will despawn shortly
                pathaleon->SetVisible(false);
                PhaseSubphase = 0;
                ++Phase;
                Phase_Timer = 3000;
                break;
                //Phase 10 Dawnforge say
            case 10:
                Talk(SAY_COMMANDER_DAWNFORGE_5);
                player->AreaExploredOrEventHappens(QUEST_INFO_GATHERING);
                Reset();
                break;
            }
         }
    };
};

class at_commander_dawnforge : public AreaTriggerScript
{
public:
    at_commander_dawnforge() : AreaTriggerScript("at_commander_dawnforge") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        //if player lost aura or not have at all, we should not try start event.
        if (!player->HasAura(SPELL_SUNFURY_DISGUISE))
            return false;

        if (player->IsAlive() && player->GetQuestStatus(QUEST_INFO_GATHERING) == QUEST_STATUS_INCOMPLETE)
        {
            Creature* Dawnforge = player->FindNearestCreature(CreatureEntry[1], 30.0f);
            if (!Dawnforge)
                return false;

            if (ENSURE_AI(npc_commander_dawnforge::npc_commander_dawnforgeAI, Dawnforge->AI())->CanStartEvent(player))
                return true;
        }
        return false;
    }
};

/*######
## npc_phase_hunter
######*/

enum PhaseHunterData
{
    QUEST_RECHARGING_THE_BATTERIES  = 10190,

    NPC_PHASE_HUNTER_ENTRY          = 18879,
    NPC_DRAINED_PHASE_HUNTER_ENTRY  = 19595,

    EMOTE_WEAK                      = 0,

    // Spells
    SPELL_RECHARGING_BATTERY        = 34219,
    SPELL_PHASE_SLIP                = 36574,
    SPELL_MANA_BURN                 = 13321,
    SPELL_MATERIALIZE               = 34804,
    SPELL_DE_MATERIALIZE            = 34814,
};

class npc_phase_hunter : public CreatureScript
{
public:
    npc_phase_hunter() : CreatureScript("npc_phase_hunter") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_phase_hunterAI(creature);
    }

    struct npc_phase_hunterAI : public ScriptedAI
    {
        npc_phase_hunterAI(Creature* creature) : ScriptedAI(creature)
        {
            Weak = false;
            Materialize = false;
            Drained = false;
            WeakPercent = 25;
            ManaBurnTimer = 5000;
        }

        bool Weak;
        bool Materialize;
        bool Drained;
        uint8 WeakPercent;

        ObjectGuid PlayerGUID;

        uint32 ManaBurnTimer;

        void Reset() override
        {
            Weak = false;
            Materialize = false;
            Drained = false;
            WeakPercent = 25 + (rand32() % 16); // 25-40

            PlayerGUID.Clear();

            ManaBurnTimer = 5000 + (rand32() % 3 * 1000); // 5-8 sec cd

            if (me->GetEntry() == NPC_DRAINED_PHASE_HUNTER_ENTRY)
                me->UpdateEntry(NPC_PHASE_HUNTER_ENTRY);
        }

        void JustEngagedWith(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                PlayerGUID = who->GetGUID();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!Materialize)
            {
                DoCast(me, SPELL_MATERIALIZE);
                Materialize = true;
            }

            if (me->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED) || me->HasUnitState(UNIT_STATE_ROOT)) // if the mob is rooted/slowed by spells eg.: Entangling Roots, Frost Nova, Hamstring, Crippling Poison, etc. => remove it
                DoCast(me, SPELL_PHASE_SLIP);

            if (!UpdateVictim())
                return;

            // some code to cast spell Mana Burn on random target which has mana
            if (ManaBurnTimer <= diff)
            {
                std::list<Unit*> UnitsWithMana;
                for (auto* ref : me->GetThreatManager().GetUnsortedThreatList())
                    if (ref->GetVictim()->GetPower(POWER_MANA))
                        UnitsWithMana.push_back(ref->GetVictim());
                if (!UnitsWithMana.empty())
                {
                    DoCast(Trinity::Containers::SelectRandomContainerElement(UnitsWithMana), SPELL_MANA_BURN);
                    ManaBurnTimer = urand(8000, 18000); // 8-18 sec cd
                }
                else
                    ManaBurnTimer = 3500;
            } else ManaBurnTimer -= diff;

            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID)) // start: support for quest 10190
            {
                if (!Weak && HealthBelowPct(WeakPercent)
                    && player->GetQuestStatus(QUEST_RECHARGING_THE_BATTERIES) == QUEST_STATUS_INCOMPLETE)
                {
                    Talk(EMOTE_WEAK);
                    Weak = true;
                }
                if (Weak && !Drained && me->HasAura(SPELL_RECHARGING_BATTERY))
                {
                    Drained = true;
                    int32 uHpPct = int32(me->GetHealthPct());

                    me->UpdateEntry(NPC_DRAINED_PHASE_HUNTER_ENTRY);

                    me->SetHealth(me->CountPctFromMaxHealth(uHpPct));
                    me->LowerPlayerDamageReq(me->GetMaxHealth() - me->GetHealth());
                    me->SetInCombatWith(player);
                }
            } // end: support for quest 10190

            DoMeleeAttackIfReady();
        }
    };
};

/*######
## Quest 10857: Teleport This!
######*/

enum TeleportThis
{
    SPELL_TELEPORTER_KILL_CREDIT_1   = 38982,    // 22348
    SPELL_TELEPORTER_KILL_CREDIT_2   = 38983,    // 22351
    SPELL_TELEPORTER_KILL_CREDIT_3   = 38984,    // 22350
    NPC_WESTERN_TELEPORTER_CREDIT    = 22348,
    NPC_EASTERN_TELEPORTER_CREDIT    = 22351,
    NPC_CENTRAL_TELEPORTER_CREDIT    = 22350
};

// 38920 - Detonate Teleporter
class spell_netherstorm_detonate_teleporter : public SpellScript
{
    PrepareSpellScript(spell_netherstorm_detonate_teleporter);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_TELEPORTER_KILL_CREDIT_1,
            SPELL_TELEPORTER_KILL_CREDIT_2,
            SPELL_TELEPORTER_KILL_CREDIT_3
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
        {
            if (Unit* charmer = GetCaster()->GetCharmerOrOwner())
            {
                if (Player* player = charmer->ToPlayer())
                {
                    uint32 spellId = 0;

                    switch (creature->GetEntry())
                    {
                        case NPC_WESTERN_TELEPORTER_CREDIT:
                            spellId = SPELL_TELEPORTER_KILL_CREDIT_1;
                            break;
                        case NPC_EASTERN_TELEPORTER_CREDIT:
                            spellId = SPELL_TELEPORTER_KILL_CREDIT_2;
                            break;
                        case NPC_CENTRAL_TELEPORTER_CREDIT:
                            spellId = SPELL_TELEPORTER_KILL_CREDIT_3;
                            break;
                        default:
                            return;
                    }

                    player->CastSpell(player, spellId);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_netherstorm_detonate_teleporter::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 10409: Deathblow to the Legion
######*/

enum DeathblowToTheLegion
{
    SPELL_SOCRETHAR_TO_SEAT          = 35743,
    SPELL_SOCRETHAR_FROM_SEAT        = 35744,

    AREA_INVASION_POINT_OVERLORD     = 3900,
    AREA_SOCRETHARS_SEAT             = 3742
};

// 35745 - Socrethar's Stone
class spell_netherstorm_socrethars_stone : public SpellScript
{
    PrepareSpellScript(spell_netherstorm_socrethars_stone);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SOCRETHAR_TO_SEAT, SPELL_SOCRETHAR_FROM_SEAT });
    }

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        Unit* caster = GetCaster();
        switch (caster->GetAreaId())
        {
            case AREA_INVASION_POINT_OVERLORD:
                caster->CastSpell(caster, SPELL_SOCRETHAR_TO_SEAT);
                break;
            case AREA_SOCRETHARS_SEAT:
                caster->CastSpell(caster, SPELL_SOCRETHAR_FROM_SEAT);
                break;
            default:
                return;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_netherstorm_socrethars_stone::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/*
Support the Escort Quest Dimensius the All-Devouring
*/

enum Dimensius_the_All_Devouring
{
    NPC_SAEED_SAY_1                         = 0,
    NPC_SAEED_SAY_2                         = 1,
    NPC_SAEED_SAY_3                         = 2,
    NPC_SAEED_SAY_4                         = 3,
    NPC_FOLLOWER_SAY                        = 0,            /*Protectorate Regenerator SAY after reached WP19*/

    EVENT_ATTACK_DIMENSIONS                 = 1,            /*Starts the Final Escort Waypoint to the BOSS*/
    EVENT_DESPAWN_WP19                      = 2,            /*Delays despawn to cast spell*/
    EVENT_START_EMOTE_FOLLOW                = 3,            /*Handle Emote Command bevor starts follow (Blizzlike)*/
    EVENT_CAST_VISUAL_TELEPORT_SPELL        = 51347,        /*Cast Saeed and follor bevore despawn (Blizzlike)*/

    QUEST_DIMENSIONS_THE_ALL_DEVOURING      = 10439,        /*QUEST ID*/

    SPELL_DIMENSIONS_TRANSFORM              = 35939,        /*comes from Triniticore spell_dbc and used in the SAI Script from Dimensions and remove the Aura from the Boss*/
    SPELL_DIMENSIONS_SHADOW_RAIN_1          = 37396,
    SPELL_DIMENSIONS_SHADOW_RAIN_2          = 37397,
    SPELL_DIMENSIONS_SHADOW_RAIN_3          = 37399,
    SPELL_DIMENSIONS_SHADOW_RAIN_4          = 37405,
    SPELL_DIMENSIONS_SHADOW_RAIN_5          = 37409,

    NPC_SAEED_KILLCREDIT                    = 20985,        /*Give The Killcredit after Speaking with SAEED*/
    NPC_SAEED_FOLLOWER_1                    = 21783,
    NPC_SAEED_FOLLOWER_2                    = 20984,
    NPC_SAEED_FOLLOWER_3                    = 21805,
    NPC_DIMENSIONS                          = 19554,        /*Final Boss Entry ID*/

    TRINITY_STRING_TEXT_1                   = 30000,        /*Escort Start Button Text*/
    TRINITY_STRING_TEXT_2                   = 30001,        /*Escort Final Stage Button Text*/

    DATA_GOSSIP_STATE                       = 1,            /*Switch between NPC GOSSIP TEXT*/
    TEXT_NPC_SAEED_START_FIGHT              = 10232,        /*GOSSIP NPC TEXT Waypoint 16*/
    TEXT_NPC_SAEED_DEFAULT                  = 10229,        /*GOSSIP NPC TEXT FIRST SPEEKING WITH SAEED*/

    WAYPOINT_16                             = 16,
    WAYPOINT_18                             = 18,
    WAYPOINT_19                             = 19,

    ACTION_FOLLOW_LEADER                    = 1
};

struct npc_saeed_follower : public ScriptedAI
{
    npc_saeed_follower(Creature* creature) : ScriptedAI(creature), _leaderGuid(), _index(0), _total(0), _followLeaderCalled(false)  { }

public:
    static ObjectGuid talkingFollowerGuid;

    void Reset() override
    {
        _followLeaderCalled = false;
        me->setActive(true);
        me->SetFaction(me->GetCreatureTemplate()->faction);
        me->SetReactState(REACT_PASSIVE);
    }

    void SetLeaderGuid(ObjectGuid guid, uint32 i, uint32 t)
    {
        _leaderGuid = guid;
        _index = i;
        _total = t;

        if (Creature* leader = ObjectAccessor::GetCreature(*me, _leaderGuid))
            me->SetHomePosition(leader->GetPosition());

        if (me->GetEntry() == NPC_SAEED_FOLLOWER_1 && talkingFollowerGuid.IsEmpty())
            talkingFollowerGuid = me->GetGUID();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_FOLLOW_LEADER)
        {
            me->SetFaction(250);
            me->SetReactState(REACT_AGGRESSIVE);
            FollowLeader();
        }
    }

    void FollowLeader(Unit* who = nullptr)
    {
        if (Creature* leader = ObjectAccessor::GetCreature(*me, _leaderGuid))
        {
            if (!who)
            {
                float radius = 3.0f;
                float leaderOri = leader->GetOrientation();
                float angle = 2.0f * M_PI * float(_index) / float(_total);
                float finalAngle = leaderOri + angle;
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveFollow(leader, radius, finalAngle);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            }
            else
            {
                me->AI()->AttackStart(who);
            }
        }
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (_leaderGuid.IsEmpty())
            return;

        Creature* leader = ObjectAccessor::GetCreature(*me, _leaderGuid);
        if (!leader || !leader->IsAlive())
        {
            me->DespawnOrUnsummon(1s, 5s);
            return;
        }

        me->SetHomePosition(leader->GetHomePosition());

        if (leader->GetVictim())
        {
            if (!UpdateVictim())
                AttackStart(leader->GetVictim());

            DoMeleeAttackIfReady();
            _followLeaderCalled = false;
        }
        else
        {
            if (!_followLeaderCalled)
            {
                FollowLeader();
                _followLeaderCalled = true;
            }
        }
    }

private:
    ObjectGuid _leaderGuid;
    uint32 _index;
    uint32 _total;
    bool _followLeaderCalled;
};

ObjectGuid npc_saeed_follower::talkingFollowerGuid;

CreatureAI* GetAI_npc_saeed_follower(Creature* creature)
{
    return new npc_saeed_follower(creature);
}

struct npc_captain_saeed : public EscortAI
{
    npc_captain_saeed(Creature* creature)
        : EscortAI(creature),
        _lastReachedWaypoint(0),
        _playersWithKillCredit(),
        _questStarterGUID(),
        _playerAwayTime(0),
        _currentGossipState(0),
        _escortPaused(false),
        _pausedByPlayer(false),
        _pausedByEvent(false),
        _attackScheduled(false)
    {}

public:
    bool OnGossipHello(Player* player) override
    {
        uint32 gossipText = GetData(DATA_GOSSIP_STATE) == 1 ? TEXT_NPC_SAEED_START_FIGHT : TEXT_NPC_SAEED_DEFAULT;

        if (_questStarterGUID.IsEmpty() && player->GetQuestStatus(QUEST_DIMENSIONS_THE_ALL_DEVOURING) == QUEST_STATUS_INCOMPLETE)
            _questStarterGUID = player->GetGUID();

        ClearGossipMenuFor(player);

        if (player->GetGUID() != _questStarterGUID)
        {
            SendGossipMenuFor(player, gossipText, me->GetGUID());
            return true;
        }

        if (_pausedByPlayer)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(TRINITY_STRING_TEXT_2), 0, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, gossipText, me->GetGUID());
            return true;
        }

        if (player->GetQuestStatus(QUEST_DIMENSIONS_THE_ALL_DEVOURING) != QUEST_STATUS_INCOMPLETE)
        {
            SendGossipMenuFor(player, gossipText, me->GetGUID());
            return true;
        }

        if (!_playersWithKillCredit.contains(player->GetGUID()))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(TRINITY_STRING_TEXT_1), 0, GOSSIP_ACTION_INFO_DEF);
        SendGossipMenuFor(player, gossipText, me->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
        CloseGossipMenuFor(player);

        if (player->GetGUID() != _questStarterGUID)
            return true;

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF:
        {
            _playersWithKillCredit.clear();

            if (Group* group = player->GetGroup())
            {
                for (GroupReference* ref = group->GetFirstMember(); ref; ref = ref->next())
                {
                    if (Player* member = ref->GetSource())
                    {
                        if (member->GetQuestStatus(QUEST_DIMENSIONS_THE_ALL_DEVOURING) == QUEST_STATUS_INCOMPLETE)
                        {
                            member->KilledMonsterCredit(NPC_SAEED_KILLCREDIT);
                            _playersWithKillCredit.insert(member->GetGUID());
                        }
                    }
                }
            }
            else
            {
                player->KilledMonsterCredit(NPC_SAEED_KILLCREDIT);
                _playersWithKillCredit.insert(player->GetGUID());
            }
            Talk(NPC_SAEED_SAY_1);
            Start(true, true, player->GetGUID());
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetFaction(250);
            me->SetReactState(REACT_AGGRESSIVE);
            StartEscortFollowers();
            break;
        }

        case GOSSIP_ACTION_INFO_DEF + 1:
        {
            if (_pausedByPlayer)
            {
                _pausedByPlayer = false;
                _escortPaused = false;
                SetEscortPaused(false);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
            break;
        }

        default:
            break;
        }

        return true;
    }

    void SetData(const uint32 id, uint32 value) override
    {
        if (id == DATA_GOSSIP_STATE)
            _currentGossipState = value;
    }

    uint32 GetData(uint32 id) const override
    {
        if (id == DATA_GOSSIP_STATE)
            return _currentGossipState;
        return 0;
    }

    void StartEscortFollowers()
    {
        uint32 const followerEntries[] = { NPC_SAEED_FOLLOWER_1, NPC_SAEED_FOLLOWER_2, NPC_SAEED_FOLLOWER_3 };

        _followers.clear();

        for (uint32 entry : followerEntries)
        {
            std::list<Creature*> tempList;
            me->GetCreatureListWithEntryInGrid(tempList, entry, 30.0f);

            for (Creature* cr : tempList)
            {
                if (cr && cr->IsAlive())
                    _followers.push_back(cr);
            }
        }
        /*This is required so that everyone performs the emote and only starts running 3 seconds later. Blizzlike behavior*/
        for (Creature* cr : _followers)
            if (cr)
                cr->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);

        _events.ScheduleEvent(EVENT_START_EMOTE_FOLLOW, 3s);
    }

    void EscortDespawn()
    {
        uint32 const followerEntries[] = { NPC_SAEED_FOLLOWER_1, NPC_SAEED_FOLLOWER_2, NPC_SAEED_FOLLOWER_3 };

        for (uint32 entry : followerEntries)
        {
            std::list<Creature*> tempList;
            me->GetCreatureListWithEntryInGrid(tempList, entry, 30.0f);
            for (Creature* follower : tempList)
            {
                if (follower && follower->IsAlive())
                    follower->CastSpell(follower, EVENT_CAST_VISUAL_TELEPORT_SPELL, false);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        EscortAI::UpdateAI(diff);

        _events.Update(diff);
        while (uint32 ev = _events.ExecuteEvent())
        {
            switch (ev)
            {
            case EVENT_START_EMOTE_FOLLOW:
            {
                size_t total = _followers.size();
                size_t i = 0;

                for (Creature* cr : _followers)
                {
                    if (cr && cr->IsAlive())
                    {
                        if (npc_saeed_follower* ai = dynamic_cast<npc_saeed_follower*>(cr->AI()))
                        {
                            ai->SetLeaderGuid(me->GetGUID(), i, total);
                            ai->DoAction(ACTION_FOLLOW_LEADER);
                            ++i;
                        }
                    }
                }
                break;
            }

            case EVENT_DESPAWN_WP19:
            {
                EscortDespawn();
                DoCastSelf(EVENT_CAST_VISUAL_TELEPORT_SPELL, false);

                for (Creature* follower : _followers)
                {
                    if (follower && follower->IsAlive())
                        follower->DespawnOrUnsummon(1s, 5s);
                }
                _followers.clear();

                me->DespawnOrUnsummon(1s, 5s);
                break;
            }

            case EVENT_ATTACK_DIMENSIONS:
            {
                _attackScheduled = false;
                _pausedByEvent = false;

                if (Creature* target = me->FindNearestCreature(NPC_DIMENSIONS, 100.0f, true))
                {
                    target->RemoveAurasDueToSpell(SPELL_DIMENSIONS_TRANSFORM);
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
                    Talk(NPC_SAEED_SAY_4);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->Attack(target, true);
                    me->GetMotionMaster()->MoveChase(target);
                }

                if (_escortPaused)
                {
                    SetEscortPaused(false);
                    _escortPaused = false;
                }
                break;
            }

            default:
                break;
            }
        }

        std::set<ObjectGuid>::iterator it = _playersWithKillCredit.begin();
        while (it != _playersWithKillCredit.end())
        {
            Player* p = ObjectAccessor::FindPlayer(*it);
            if (!p || p->GetQuestStatus(QUEST_DIMENSIONS_THE_ALL_DEVOURING) != QUEST_STATUS_INCOMPLETE)
                it = _playersWithKillCredit.erase(it);
            else
                ++it;
        }
        Player* player = GetPlayerForEscort();
        if (!player)
            return;

        if (_questStarterGUID.IsEmpty())
            _questStarterGUID = player->GetGUID();

        if (_lastReachedWaypoint < 18)
        {
            if (me->GetDistance(player) > 20.0f)
            {
                if (!_escortPaused)
                {
                    SetEscortPaused(true);
                    _escortPaused = true;
                    _playerAwayTime = 0;
                }
                else
                {
                    _playerAwayTime += diff;
                    if (_playerAwayTime >= 20000)
                        me->DespawnOrUnsummon(1s, 5s);
                }
            }
            else
            {
                if (_escortPaused && !_pausedByPlayer && !_pausedByEvent)
                {
                    SetEscortPaused(false);
                    _escortPaused = false;
                }
                _playerAwayTime = 0;
            }
        }
    }

    void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
    {
        me->SetHomePosition(me->GetPosition());
        _lastReachedWaypoint = waypointId;

        Player* player = GetPlayerForEscort();
        if (!player)
            return;

        if (_questStarterGUID.IsEmpty())
            _questStarterGUID = player->GetGUID();

        switch (waypointId)
        {
        case WAYPOINT_16:
        {
            if (Player* player = ObjectAccessor::GetPlayer(*me, _questStarterGUID))
                Talk(NPC_SAEED_SAY_2, player);
            else
            Talk(NPC_SAEED_SAY_2);
            _currentGossipState = 1;
            SetEscortPaused(true);
            _escortPaused = true;
            _pausedByPlayer = true;
            _pausedByEvent = false;
            _attackScheduled = false;
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            break;
        }

        case WAYPOINT_18:
        {
            Talk(NPC_SAEED_SAY_3);
            SetEscortPaused(true);
            _escortPaused = true;
            _pausedByPlayer = false;
            _pausedByEvent = true;
            _attackScheduled = true;
            _events.ScheduleEvent(EVENT_ATTACK_DIMENSIONS, 10s);
            break;
        }

        case WAYPOINT_19:
        {
            if (Creature* follower = ObjectAccessor::GetCreature(*me, npc_saeed_follower::talkingFollowerGuid))
                follower->AI()->Talk(NPC_FOLLOWER_SAY);

            SetEscortPaused(true);
            _escortPaused = true;
            _events.ScheduleEvent(EVENT_DESPAWN_WP19, 5s);
            break;
        }

        default:
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        for (auto guid : _playersWithKillCredit)
        {
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                player->FailQuest(QUEST_DIMENSIONS_THE_ALL_DEVOURING);
        }

        for (Creature* follower : _followers)
        {
            if (follower && follower->IsAlive())
                follower->DespawnOrUnsummon(1s, 5s);
        }
        _followers.clear();
        me->SetRespawnTime(5);
        me->Respawn();
    }

    void Reset() override
    {
        _lastReachedWaypoint = 0;
        _playerAwayTime = 0;
        _escortPaused = false;
        _pausedByPlayer = false;
        _pausedByEvent = false;
        _attackScheduled = false;
        _currentGossipState = 0;
        _playersWithKillCredit.clear();
        me->SetHomePosition(me->GetPosition());
        me->SetReactState(REACT_PASSIVE);
        me->SetFaction(me->GetCreatureTemplate()->faction);
        me->setActive(true);
    }
private:
    std::list<Creature*> _followers;
    std::vector<ObjectGuid> _followerGUIDs;
    uint32 _lastReachedWaypoint;
    std::set<ObjectGuid> _playersWithKillCredit;
    ObjectGuid _questStarterGUID;
    uint32 _playerAwayTime;
    uint32 _currentGossipState;
    bool _escortPaused;
    bool _pausedByPlayer;
    bool _pausedByEvent;
    bool _attackScheduled;

    EventMap _events;
};

CreatureAI* GetAI_npc_captain_saeed(Creature* creature)
{
    return new npc_captain_saeed(creature);
}

/*Controll the SCRIPT EFFECT Spell 37425 Logic Tick (Dimensius) and used in the SAI Script from Dimensions*/
class spell_37425_logic_tick : public SpellScript
{
    PrepareSpellScript(spell_37425_logic_tick);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        uint32 spells[5] = { SPELL_DIMENSIONS_SHADOW_RAIN_1, SPELL_DIMENSIONS_SHADOW_RAIN_2, SPELL_DIMENSIONS_SHADOW_RAIN_3, SPELL_DIMENSIONS_SHADOW_RAIN_4, SPELL_DIMENSIONS_SHADOW_RAIN_5 };
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, spells[urand(0, 4)], true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_37425_logic_tick::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_netherstorm()
{
    new npc_commander_dawnforge();
    new at_commander_dawnforge();
    new npc_phase_hunter();
    RegisterSpellScript(spell_netherstorm_detonate_teleporter);
    RegisterSpellScript(spell_netherstorm_socrethars_stone);
    RegisterCreatureAI(npc_captain_saeed);
    RegisterCreatureAI(npc_saeed_follower);
    RegisterSpellScript(spell_37425_logic_tick);
}
