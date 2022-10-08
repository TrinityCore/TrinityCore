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

#include "Creature.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"
#include "WorldSession.h"
#include "PhasingHandler.h"
#include "Conversation.h"
#include "GameObjectAI.h"

enum MardumQuests
{
    QUEST_INVASION_BEGIN = 40077,
    QUEST_ASHTONGUE_FORCES = 40378,
    QUEST_COILSKAR_FORCES = 40379,
    QUEST_EYE_ON_THE_PRIZE = 39049,
    QUEST_MEETING_WITH_QUEEN = 39050,
    QUEST_SHIVARRA_FORCES = 38765,
    QUEST_BEFORE_OVERRUN = 38766,
    QUEST_HIDDEN_NO_MORE = 39495,
    QUEST_ON_FELBAT_WINGS = 39663,
    QUEST_THE_KEYSTONE = 38728,
    QUEST_CRY_HAVOC = 39516,
    QUEST_VENGEANCE = 39515,
    QUEST_THEIR_NUMBERS_ARE_LEGION = 38819
};

enum MardumSpells
{
    // Inquisitor Baleful
    SPELL_INCITE_MADNESS = 194529,
    SPELL_INFERNAL_SMASH = 192709,
    SPELL_LEGION_AEGIS = 192665,
    SPELL_LEARN_EYE_BEAM = 195447,

    // Doom Commander Beliash
    SPELL_SHADOW_BLAZE = 195401,
    SPELL_SHADOW_BOLT_VOLLEY = 196403,
    SPELL_SHADOW_RETREAT = 196625
};

enum MardumEvents
{
    // Doom Commander Beliash
    EVENT_SHADOW_BLAZE = 0,
    EVENT_SHADOW_BOLT_VOLLEY = 1,
    EVENT_SHADOW_RETREAT = 2
};

enum MardumTexts
{
    // Inquisitor Baleful
    SAY_AGGRO_INQUISITOR_BALEFUL = 0,
    SAY_DEATH_INQUISITOR_BALEFUL = 1,
    SAY_60_HP_PCT_INQUISITOR_BALEFUL = 2,

    // Doom Commander Beliash
    SAY_AGGRO_DOOM_COMMANDER_BELIASH = 0,
    SAY_AGGRO_QUEEN_TYRANNA = 0,

    // Kayn Sunfury
    SAY_KAYN_SUNFURY_TEXT_1 = 0,
    SAY_KAYN_SUNFURY_TEXT_2 = 1,
    SAY_KAYN_SUNFURY_TEXT_3 = 2
};

enum MardumCreatures
{
    NPC_POWER_QUEST_KILL_CREDIT = 105946,
    NPC_COLOSSAL_INFERNAL = 96159,
    NPC_LEGION_GATEWAY_KILL_CREDIT = 94406,
    NPC_FIRST_SUMMONED_GUARDIAN_QUEST_KILL_CREDIT = 97831,
    NPC_QUEEN_TYRANNA = 95048,
    NPC_BELIASH_CREDIT = 106003,
    NPC_ASHTONGUE_CAPTAIN = 90247,
    NPC_COILSKAR_CAPTAIN = 93693,
    NPC_SHIVARRA_CAPTAIN = 94435
};

enum MardumScenes
{
    SPELL_SCENE_MARDUM_WELCOME = 193525,
    SPELL_SCENE_MARDUM_LEGION_BANNER = 191677,
    SPELL_SCENE_MARDUM_ASHTONGUE_FORCES = 189261,
    SPELL_SCENE_MARDUM_COILSKAR_FORCES = 190793,
    SPELL_SCENE_MEETING_WITH_QUEEN = 188539,
    SPELL_SCENE_MARDUM_SHIVARRA_FORCES = 190851,

    SCENE_ASHTONGUE = 191315,
    SCENE_COILSKAR = 191400,
    SCENE_SHIVARRA = 191402
};

enum MardumPhases
{
    PHASE_1_BEGINING  = 169,    // begining phase
    PHASE_2_WELCOMING = 170,    // welcoming phase
    PHASE_3_BANNER    = 171,    // legion banner phase
    PHASE_4_FELSABER  = 172,    // felsaber phase
    PHASE_5_ASHTONGUE = 175,    // illidari outpost ashtongue phase
    PHASE_6_COILSKAR  = 176,    // illidari outpost coilskar phase
    PHASE_7_SHIVARRA  = 177     // illidari outpost shivarra phase
};

enum MardumMisc
{
    PLAYER_CHOICE_DH_SPEC_SELECTION = 231,
    PLAYER_CHOICE_DH_SPEC_SELECTION_DEVASTATION = 478,
    PLAYER_CHOICE_DH_SPEC_SELECTION_VENGEANCE = 479
};

Position const NPCsPos[2] =
{
    { 523.404f,    2428.41f,     -117.087f,   0.108873f }, /// Summmon position for Colossal Infernal
    { 586.843323f, 2433.053955f, -62.977276f, 6.143252f }  /// Fly position when Legion Aegis Event (Inquisitor Baleful)
};

class PlayerScript_mardum_welcome_scene_trigger : public PlayerScript
{
public:
    PlayerScript_mardum_welcome_scene_trigger() : PlayerScript("PlayerScript_mardum_welcome_scene_trigger") { }

    uint32 checkTimer = 1000;

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (checkTimer <= diff)
        {
            if (player->getClass() == CLASS_DEMON_HUNTER && player->GetZoneId() == 7705 && player->GetQuestStatus(QUEST_INVASION_BEGIN) == QUEST_STATUS_NONE &&
                player->GetPositionY() < 3280.f && !player->HasAura(SPELL_SCENE_MARDUM_WELCOME) &&
                !player->Variables.GetValue<bool>("PHASE_2_WELCOMING_ACTIVE"))
            {
                player->CastSpell(player, SPELL_SCENE_MARDUM_WELCOME, true);
                Conversation::CreateConversation(705, player, player->GetPosition(), { player->GetGUID() });
            }

            checkTimer = 1000;
        }
        else checkTimer -= diff;
    }
};

class scene_mardum_welcome : public SceneScript
{
public:
    scene_mardum_welcome() : SceneScript("scene_mardum_welcome") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->Variables.Set("PHASE_2_WELCOMING_ACTIVE", true);
    }
};

class npc_kayn_sunfury_welcome : public CreatureScript
{
public:
    npc_kayn_sunfury_welcome() : CreatureScript("npc_kayn_sunfury_welcome") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_INVASION_BEGIN)
        {
            creature->AI()->Talk(0);
            creature->GetScheduler().Schedule(Milliseconds(5000), [creature](TaskContext context)
            {
                creature->AI()->Talk(1);
            });

            player->GetScheduler().Schedule(Milliseconds(30000), [player](TaskContext context)
            {
                player->Variables.Set("PHASE_2_WELCOMING_ACTIVE", false);
            });

            creature->GetScheduler().Schedule(Milliseconds(11000), [creature](TaskContext context)
            {
                if (Creature* npc = creature->FindNearestCreature(98228, 100.0f, true))
                {
                    npc->ForcedDespawn(15000, Seconds(1));
                    npc->GetMotionMaster()->MovePath(10267108, false);
                }

                if (Creature* npc = creature->FindNearestCreature(98227, 100.0f, true))
                {
                    npc->DespawnOrUnsummon(16000, Seconds(1));
                    npc->GetMotionMaster()->MovePath(10267109, false);
                }

                if (Creature* npc = creature->FindNearestCreature(99918, 100.0f, true))
                {
                    npc->DespawnOrUnsummon(16000, Seconds(1));
                    npc->GetMotionMaster()->MovePath(10267110, false);
                }

                if (Creature* npc = creature->FindNearestCreature(98292, 100.0f, true))
                {
                    npc->DespawnOrUnsummon(16000, Seconds(1));
                    npc->GetMotionMaster()->MovePath(10267111, false);
                }

                if (Creature* npc = creature->FindNearestCreature(98290, 100.0f, true))
                {
                    npc->DespawnOrUnsummon(16000, Seconds(1));
                    npc->GetMotionMaster()->MovePath(10267112, false);
                }

                creature->DespawnOrUnsummon(16000, Seconds(1));
                creature->GetMotionMaster()->MovePath(10267107, false);
            });
        }
        return true;
    }
};

class go_mardum_legion_banner_1 : public GameObjectScript
{
public:
    go_mardum_legion_banner_1() : GameObjectScript("go_mardum_legion_banner_1") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->IsActiveQuest(QUEST_INVASION_BEGIN))
        {
            player->CastSpell(player, SPELL_SCENE_MARDUM_LEGION_BANNER, true);
            player->Variables.Set("PHASE_3_BANNER_ACTIVE", true);
            go->DestroyForPlayer(player);
        }
        return false;
    }
};

//Quest 39279- Gameobject 244439, 244440
class go_q39279 : public GameObjectScript
{
public:
    go_q39279() : GameObjectScript("go_q39279") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->IsActiveQuest(39279))
        {
            switch (go->GetEntry())
            {
                case 244439:
                    Conversation::CreateConversation(558, player, player->GetPosition(), { player->GetGUID() });
                    break;

                case 244440:
                    Conversation::CreateConversation(583, player, player->GetPosition(), { player->GetGUID() });
                    break;
            }

            go->DestroyForPlayer(player);
        }
        return false;
    }
};

class go_mardum_portal_ashtongue : public GameObjectScript
{
public:
    go_mardum_portal_ashtongue() : GameObjectScript("go_mardum_portal_ashtongue") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_ASHTONGUE_FORCES, 0))
        {
            player->KilledMonsterCredit(88872); // QUEST_ASHTONGUE_FORCES storageIndex 0 KillCredit
            player->KilledMonsterCredit(97831); // QUEST_ASHTONGUE_FORCES storageIndex 1 KillCredit
            player->CastSpell(player, SPELL_SCENE_MARDUM_ASHTONGUE_FORCES, true);
            player->Variables.Set("PHASE_5_ASHTONGUE_ACTIVE", true);
        }

        return false;
    }
};

class scene_mardum_welcome_ashtongue : public SceneScript
{
public:
    scene_mardum_welcome_ashtongue() : SceneScript("scene_mardum_welcome_ashtongue") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName)
    {
        if (triggerName == "SEEFELSABERCREDIT")
        {
            player->KilledMonsterCredit(101534); // QUEST_ASHTONGUE_FORCES storageIndex 1 KillCredit
        }
        else if (triggerName == "UPDATEPHASE")
        {
            player->Variables.Set("PHASE_4_FELSABER_ACTIVE", true);
        }
    }
};

// 200176 - Learn felsaber
class spell_learn_felsaber : public SpellScript
{
    PrepareSpellScript(spell_learn_felsaber);

    void HandleMountOnHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->Variables.Set("PHASE_4_FELSABER_ACTIVE", false);

        // We schedule this to let hover animation pass
        GetCaster()->GetScheduler().Schedule(Milliseconds(900), [](TaskContext context)
        {
            GetContextUnit()->CastSpell(GetContextUnit(), 200175, true); // Felsaber mount
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_learn_felsaber::HandleMountOnHit, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
    }
};

// 94410 - Allari the Souleater
struct npc_mardum_allari : public ScriptedAI
{
    npc_mardum_allari(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetDistance(me) < 5.0f)
                if (!player->GetQuestObjectiveData(QUEST_ASHTONGUE_FORCES, 2))
                    player->KilledMonsterCredit(me->GetEntry());
    }
};

class go_mardum_cage : public GameObjectScript
{
public:
    go_mardum_cage(const char* name, uint32 insideNpc, uint32 killCredit = 0) : GameObjectScript(name), _insideNpc(insideNpc), _killCredit(killCredit)
    {
        if (_killCredit == 0)
            _killCredit = insideNpc;
    }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (Creature* creature = go->FindNearestCreature(_insideNpc, 10.0f))
        {
            // TODO : Remove this line when phasing is done properly
            creature->DestroyForPlayer(player);

            if (TempSummon* personalCreature = player->SummonCreature(_insideNpc, creature->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 4000, 0, true))
            {
                float x, y, z;
                personalCreature->GetClosePoint(x, y, z, personalCreature->GetObjectSize() / 3, 50.0f);
                personalCreature->GetMotionMaster()->MovePoint(0, x, y, z);

                // TODO : personalCreature->Talk(0);
            }

            player->KilledMonsterCredit(_killCredit);
        }

        return false;
    }

    uint32 _insideNpc;
    uint32 _killCredit;
};

// 93105 - Inquisitor Baleful
struct npc_inquisitor_baleful : public ScriptedAI
{
    npc_inquisitor_baleful(Creature* creature) : ScriptedAI(creature) { }

    ObjectGuid colossalInfernalGuid;
    bool aegisDone;
    bool doingAegis;
    uint8 elementalCast;

    void Reset() override
    {
        me->SetCanFly(false);
        me->SetDisableGravity(false);

        if (!me->FindNearestCreature(NPC_COLOSSAL_INFERNAL, 150.0f))
        {
            if (Creature* infernal = me->SummonCreature(NPC_COLOSSAL_INFERNAL, NPCsPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000))
                colossalInfernalGuid = infernal->GetGUID();
        }

        aegisDone = false;
        doingAegis = false;
        elementalCast = 1;
    }

    Creature* GetInfernal() const
    {
        return ObjectAccessor::GetCreature(*me, colossalInfernalGuid);
    }

    void EnterCombat(Unit*) override
    {
        Talk(SAY_AGGRO_INQUISITOR_BALEFUL);

        me->GetScheduler().Schedule(Seconds(urand(8, 10)), [this](TaskContext context) /// Incite Madness
        {
            if (!doingAegis)
            {
                if (Unit* target = me->GetVictim())
                    me->CastSpell(target, SPELL_INCITE_MADNESS);
            }

            context.Repeat(15s);
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(60, damage) && !aegisDone)
        {
            aegisDone = true;
            doingAegis = true;

            Talk(SAY_60_HP_PCT_INQUISITOR_BALEFUL);

            if (Unit* target = me->GetVictim())
                me->CastSpell(me, SPELL_LEGION_AEGIS, true);

            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);

            me->SetCanFly(true);
            me->SetDisableGravity(true);

            me->GetMotionMaster()->MoveTakeoff(0, NPCsPos[1]);

            me->GetScheduler().Schedule(1s, [this](TaskContext context)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    if (Creature* infernal = GetInfernal())
                        infernal->CastSpell(target, SPELL_INFERNAL_SMASH);
                }

                elementalCast++;

                if (elementalCast <= 3) /// Only 3 cast of Infernal Smash
                    context.Repeat(5s);
            });

            me->GetScheduler().Schedule(15s, [this](TaskContext context) /// End Legion Aegis event
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetDisableGravity(true);

                if (Creature* infernal = GetInfernal())
                {
                    infernal->AttackStop();
                    infernal->SetReactState(REACT_PASSIVE);
                }

                doingAegis = false;
            });
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH_INQUISITOR_BALEFUL);

        if (Creature* infernal = GetInfernal())
            infernal->KillSelf();

        std::list<Player*> players;
        me->GetPlayerListInGrid(players, 50.0f);

        for (Player* player : players)
        {
            if (player->HasQuest(QUEST_EYE_ON_THE_PRIZE) && !player->GetQuestObjectiveData(QUEST_EYE_ON_THE_PRIZE, 0))
            {
                player->KilledMonsterCredit(NPC_POWER_QUEST_KILL_CREDIT);
                player->KilledMonsterCredit(NPC_COLOSSAL_INFERNAL);

                if (!player->HasSpell(SPELL_LEARN_EYE_BEAM))
                    player->CastSpell(player, SPELL_LEARN_EYE_BEAM);
            }
        }
    }
};

// 192709 - Infernal Smash
class spell_mardum_infernal_smash : public SpellScript
{
    PrepareSpellScript(spell_mardum_infernal_smash);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster() || !GetHitUnit() || !(GetHitUnit()->GetTypeId() == TypeID::TYPEID_PLAYER))
            return;

        GetCaster()->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mardum_infernal_smash::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class npc_mardum_ashtongue_mystic : public CreatureScript
{
public:
    npc_mardum_ashtongue_mystic() : CreatureScript("npc_mardum_ashtongue_mystic") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->KilledMonsterCredit(creature->GetEntry());

        // TODO : Remove this line when phasing is done properly
        creature->DestroyForPlayer(player);

        if (TempSummon* personalCreature = player->SummonCreature(creature->GetEntry(), creature->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 4000, 0, true))
            personalCreature->KillSelf();
        return true;
    }
};

class go_mardum_portal_coilskar : public GameObjectScript
{
public:
    go_mardum_portal_coilskar() : GameObjectScript("go_mardum_portal_coilskar") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_COILSKAR_FORCES, 1))
        {
            player->KilledMonsterCredit(NPC_LEGION_GATEWAY_KILL_CREDIT); // QUEST_COILSKAR_FORCES storageIndex 0 KillCredit
            player->KilledMonsterCredit(NPC_FIRST_SUMMONED_GUARDIAN_QUEST_KILL_CREDIT); // QUEST_COILSKAR_FORCES storageIndex 1 KillCredit
            player->CastSpell(player, SPELL_SCENE_MARDUM_COILSKAR_FORCES, true);
            player->Variables.Set("PHASE_6_COILSKAR_ACTIVE", true);
        }

        return false;
    }
};

class go_meeting_with_queen_ritual : public GameObjectScript
{
public:
    go_meeting_with_queen_ritual() : GameObjectScript("go_meeting_with_queen_ritual") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (player->HasQuest(QUEST_MEETING_WITH_QUEEN) &&
            !player->GetQuestObjectiveData(QUEST_MEETING_WITH_QUEEN, 0))
        {
            player->CastSpell(player, SPELL_SCENE_MEETING_WITH_QUEEN, true);
        }

        return false;
    }
};

class scene_mardum_meeting_with_queen : public SceneScript
{
public:
    scene_mardum_meeting_with_queen() : SceneScript("scene_mardum_meeting_with_queen") { }

    void OnSceneEnd(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->KilledMonsterCredit(100722);
    }
};

// 93221 - Doom Commander Beliash
struct npc_doom_commander_beliash : public ScriptedAI
{
    npc_doom_commander_beliash(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        events.Reset();
    }

    void JustDied(Unit* killer) override
    {
        if (killer->IsPlayer())
            killer->ToPlayer()->KilledMonsterCredit(NPC_BELIASH_CREDIT, ObjectGuid::Empty);
                me->ForcedDespawn(15000, 15s);
    }

    void EnterCombat(Unit* who) override
    {
        Talk(SAY_AGGRO_DOOM_COMMANDER_BELIASH);

        events.ScheduleEvent(EVENT_SHADOW_BLAZE, 10s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 8s);
        events.ScheduleEvent(EVENT_SHADOW_RETREAT, 12s);

        if (Creature* tyranna = me->FindNearestCreature(NPC_QUEEN_TYRANNA, 100.0f))
            tyranna->AI()->Talk(SAY_AGGRO_QUEEN_TYRANNA, tyranna);

        if (Player* player = who->ToPlayer())
            Conversation::CreateConversation(531, player, player->GetPosition(), { player->GetGUID() });
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_SHADOW_BLAZE:
             DoCast(SPELL_SHADOW_BLAZE);
             events.ScheduleEvent(EVENT_SHADOW_BLAZE, 10s);
             break;
        case EVENT_SHADOW_BOLT_VOLLEY:
             DoCast(SPELL_SHADOW_BOLT_VOLLEY);
             events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 8s);
             break;
        case EVENT_SHADOW_RETREAT:
             DoCast(SPELL_SHADOW_RETREAT);
             events.ScheduleEvent(EVENT_SHADOW_RETREAT, 12s);
             break;
        }
    }
};

// 99915 - Sevis Brightflame
struct npc_mardum_sevis_brightflame_shivarra : public ScriptedAI
{
    npc_mardum_sevis_brightflame_shivarra(Creature* creature) : ScriptedAI(creature) { }

    // TEMP FIX, will need gossip
    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetDistance(me) < 5.0f)
                if (!player->GetQuestObjectiveData(QUEST_SHIVARRA_FORCES, 0))
                    player->KilledMonsterCredit(me->GetEntry());
    }
};

class go_mardum_portal_shivarra : public GameObjectScript
{
public:
    go_mardum_portal_shivarra() : GameObjectScript("go_mardum_portal_shivarra") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (player->GetQuestObjectiveData(QUEST_SHIVARRA_FORCES, 0))
        {
            player->ForceCompleteQuest(QUEST_SHIVARRA_FORCES);
            player->CastSpell(player, SPELL_SCENE_MARDUM_SHIVARRA_FORCES, true);
            player->Variables.Set("PHASE_7_SHIVARRA_ACTIVE", true);
        }

        return false;
    }
};

// 90247, 93693, 94435
class npc_mardum_captain : public CreatureScript
{
public:
    npc_mardum_captain() : CreatureScript("npc_mardum_captain") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->KilledMonsterCredit(creature->GetEntry());

        switch (creature->GetEntry())
        {
            case NPC_ASHTONGUE_CAPTAIN:
                player->CastSpell(player, SCENE_ASHTONGUE, true);
                player->Variables.Set("PHASE_5_ASHTONGUE_ACTIVE", false);
                break;

            case NPC_COILSKAR_CAPTAIN:
                player->CastSpell(player, SCENE_COILSKAR, true);
                player->Variables.Set("PHASE_6_COILSKAR_ACTIVE", false);
                break;

            case NPC_SHIVARRA_CAPTAIN:
                player->CastSpell(player, SCENE_SHIVARRA, true);
                player->Variables.Set("PHASE_7_SHIVARRA_ACTIVE", false);
                break;

            default:
                break;
        }

        player->GetScheduler().Schedule(Seconds(15), [player, creature](TaskContext /*context*/)
        {
            creature->DestroyForPlayer(player);
        });
        return true;
    }
};

// 96436 - Jace Darkweaver
class npc_mardum_jace_darkweaver : public CreatureScript
{
public:
    npc_mardum_jace_darkweaver() : CreatureScript("npc_mardum_jace_darkweaver") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->KilledMonsterCredit(creature->GetEntry());
        return true;
    }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_HIDDEN_NO_MORE)
        {
            if (Creature* demonHunter1 = creature->FindNearestCreature(101790, 50.0f))
                demonHunter1->CastSpell(demonHunter1, 194326, true);
            if (Creature* demonHunter2 = creature->FindNearestCreature(101787, 50.0f))
                demonHunter2->CastSpell(demonHunter2, 194326, true);
            if (Creature* demonHunter3 = creature->FindNearestCreature(101788, 50.0f))
                demonHunter3->CastSpell(demonHunter3, 194326, true);
            if (Creature* demonHunter4 = creature->FindNearestCreature(101789, 50.0f))
                demonHunter4->CastSpell(demonHunter4, 194326, true);

            /* rockslide "animation" */
            if (GameObject* rockslide = player->SummonGameObject(245045, 1237.150024f, 1642.619995f, 103.152f, 5.80559f, QuaternionData(0, 0, 20372944, 20372944), 0, true))
            {
                rockslide->GetScheduler()
                    .Schedule(2s, [](TaskContext context)
                    {
                        GetContextGameObject()->SetLootState(GO_READY);
                        GetContextGameObject()->UseDoorOrButton(10000);
                    })
                        .Schedule(10s, [](TaskContext context)
                    {
                        GetContextGameObject()->Delete();
                    });
            }

            player->KilledMonsterCredit(98755, ObjectGuid::Empty);
        }

        return true;
    }
};

// gob 245045
class go_q39495 : public GameObjectScript
{
public:
    go_q39495() : GameObjectScript("go_q39495") { }

    struct go_q39495AI : public GameObjectAI
    {
        go_q39495AI(GameObject* go) : GameObjectAI(go){}

        void UpdateAI(uint32 diff) override
        {
            std::list<Player*> list;
            list.clear();
            go->GetPlayerListInGrid(list, 15.0f);
            if (!list.empty())
            {
                for (std::list<Player*>::const_iterator itr = list.begin(); itr != list.end(); ++itr)
                {
                    if ((*itr)->HasQuest(39495))
                        go->DestroyForPlayer(*itr);
                }
            }
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_q39495AI(go);
    }
};

// 188501 spectral sight
class spell_mardum_spectral_sight : public SpellScript
{
    PrepareSpellScript(spell_mardum_spectral_sight);

    void HandleOnCast()
    {
        if (GetCaster()->IsPlayer() && GetCaster()->GetAreaId() == 7754)
            GetCaster()->ToPlayer()->KilledMonsterCredit(96437);
        if (GetCaster()->IsPlayer() && GetCaster()->GetAreaId() == 4982)
            GetCaster()->ToPlayer()->KilledMonsterCredit(102563);
        // TO STROWIND PART AND PLAY SCENE
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_mardum_spectral_sight::HandleOnCast);
    }
};

enum FelLordCaza
{
    EVENT_SWEEPING_SLASH = 0,
    EVENT_FEL_INFUSION = 1,
    SPELL_SWEEPING_SLASH = 197002,
    SPELL_FEL_INFUSION = 197180,
    NPC_FEL_LORD_CAZA_CREDIT = 106014,
};

class npc_fel_lord_caza : public CreatureScript
{
public:
    npc_fel_lord_caza() : CreatureScript("npc_fel_lord_caza") { }

    struct npc_fel_lord_cazaAI : public ScriptedAI
    {
        npc_fel_lord_cazaAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            events.ScheduleEvent(EVENT_SWEEPING_SLASH, 10000);
            events.ScheduleEvent(EVENT_FEL_INFUSION, 8000);
        }

        void Reset() override
        {
            Initialize();
            events.Reset();
        }

        void JustDied(Unit* killer) override
        {
            if (killer->GetTypeId() == TYPEID_PLAYER)
                killer->ToPlayer()->KilledMonsterCredit(NPC_FEL_LORD_CAZA_CREDIT, ObjectGuid::Empty);
        }

        void EnterCombat(Unit* who) override
        {
            Talk(0);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SWEEPING_SLASH:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_SWEEPING_SLASH, true);

                    events.ScheduleEvent(EVENT_SWEEPING_SLASH, 10s);
                    break;
                case EVENT_FEL_INFUSION:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_FEL_INFUSION, true);

                    events.ScheduleEvent(EVENT_FEL_INFUSION, 8s);
                    break;
                }
            }

            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fel_lord_cazaAI(creature);
    }
};

// 243968 - Banner near 96732 - Destroyed by Ashtongue - KillCredit 96734
// 243967 - Banner near 96731 - Destroyed by Shivarra - KillCredit 96733
// 243965 - Banner near 93762 - Destroyed by Coilskar - KillCredit 96692
class go_mardum_illidari_banner : public GameObjectScript
{
public:
    go_mardum_illidari_banner() : GameObjectScript("go_mardum_illidari_banner") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        uint32 devastatorEntry = 0;
        uint32 killCreditEntry = 0;

        switch (go->GetEntry())
        {
        case 243968:
            devastatorEntry = 96732;
            killCreditEntry = 96734;
            break;
        case 243967:
            devastatorEntry = 96731;
            killCreditEntry = 96733;
            break;
        case 243965:
            devastatorEntry = 93762;
            killCreditEntry = 96692;
            break;
        default:
            break;
        }

        if (Creature* devastator = player->FindNearestCreature(devastatorEntry, 50.0f))
        {
            if (Creature* personnalCreature = player->SummonCreature(devastatorEntry, devastator->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN, 5000, 0, true))
            {
                player->KilledMonsterCredit(devastatorEntry);
                player->KilledMonsterCredit(killCreditEntry);
                devastator->DestroyForPlayer(player);

                //TODO : Script destruction event
                personnalCreature->GetScheduler().Schedule(Seconds(2), [](TaskContext context)
                {
                    GetContextUnit()->KillSelf();
                });
            }
        }

        return false;
    }
};

class go_mardum_tome_of_fel_secrets : public GameObjectScript
{
public:
    go_mardum_tome_of_fel_secrets() : GameObjectScript("go_mardum_tome_of_fel_secrets") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        player->CastSpell(player, 194938, true); // Display player spec choice
        return false;
    }
};

class PlayerScript_mardum_spec_choice : public PlayerScript
{
public:
    PlayerScript_mardum_spec_choice() : PlayerScript("PlayerScript_mardum_spec_choice") {}

    void OnPlayerChoiceResponse(Player* player, uint32 choiceID, uint32 responseID)
    {
        if (choiceID != PLAYER_CHOICE_DH_SPEC_SELECTION)
            return;

        player->LearnSpell(200749, false); // Allow to choose specialization

        switch (responseID)
        {
        case PLAYER_CHOICE_DH_SPEC_SELECTION_DEVASTATION:
            player->CastSpell(player, 194940, true);
            break;
        case PLAYER_CHOICE_DH_SPEC_SELECTION_VENGEANCE:
            player->CastSpell(player, 194939, true);

            if (ChrSpecializationEntry const* spec = sChrSpecializationStore.AssertEntry(581))
                player->ActivateTalentGroup(spec);

            break;
        default:
            break;
        }
    }
};

// 93127 - Kayn Sunfury
class npc_kayn_sunfury : public CreatureScript
{
public:
    npc_kayn_sunfury() : CreatureScript("npc_kayn_sunfury") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_CRY_HAVOC)
            creature->AI()->Talk(SAY_KAYN_SUNFURY_TEXT_1);

        if (quest->GetQuestId() == QUEST_ON_FELBAT_WINGS)
            creature->AI()->Talk(SAY_KAYN_SUNFURY_TEXT_2);

        if (quest->GetQuestId() == QUEST_INVASION_BEGIN)
            creature->AI()->Talk(SAY_KAYN_SUNFURY_TEXT_3);

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_VENGEANCE) == QUEST_STATUS_INCOMPLETE)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Kayn, I'll show you what I've learned about demonic mysteries.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());

            return true;
        }
        else
            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF:
            player->CastSpell(creature, 195020, true);
            creature->AI()->Talk(0);
            CloseGossipMenuFor(player);
            break;
        }

        return true;
    }
};

// 96655
struct npc_allari : public ScriptedAI
{
    npc_allari(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(QUEST_VENGEANCE))
        {
            if (gossipListId == 0)
            {
                player->CastSpell(player, 194996, true);
                Talk(0);
                CloseGossipMenuFor(player);
            }
        }
    }
};

// 96420
struct npc_cyana : public ScriptedAI
{
    npc_cyana(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(QUEST_VENGEANCE))
        {
            if (gossipListId == 0)
            {
                player->CastSpell(player, 195019, true);
                Talk(0);
                CloseGossipMenuFor(player);
            }
        }
    }
};

// 99045
struct npc_korvas : public ScriptedAI
{
    npc_korvas(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(QUEST_VENGEANCE))
        {
            if (gossipListId == 0)
            {
                player->CastSpell(player, 195021, true);
                Talk(0);
                CloseGossipMenuFor(player);
            }
        }
    }
};

// 96652
class npc_mannethrel : public CreatureScript
{
public:
    npc_mannethrel() : CreatureScript("npc_mannethrel") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_VENGEANCE) == QUEST_STATUS_INCOMPLETE)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Get Ready, Mannethrel. I'm going to fill you with the power of the Legion's secrets.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        }

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF:
            player->CastSpell(creature, 195022, true);
            creature->AI()->Talk(0);
            creature->AI()->Talk(1);
            creature->KillSelf();
            CloseGossipMenuFor(player);
            break;
        }

        return true;
    }
};

// 96653
class npc_mardum_izal_whitemoon : public CreatureScript
{
public:
    npc_mardum_izal_whitemoon() : CreatureScript("npc_mardum_izal_whitemoon") { }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
    {
        if (player->HasQuest(QUEST_ON_FELBAT_WINGS) || player->GetQuestStatus(QUEST_ON_FELBAT_WINGS) == QUEST_STATUS_REWARDED)
            player->CastSpell(player, 192136, true); // KillCredit & SendTaxi

        return true;
    }
};

enum TyrannaFightData
{
    DATA_TYRANNA_DEATH = 1,
};

enum TyrannaFightTexts
{
    TEXT_DEATH = 0,
};

enum TyrannaFightMisc
{
    BROOD_QUEEN_TYRANNA = 93802,
};

// Kayn: 20542609 (Entry: 97244)
class npc_kayn_tyranna_fight : public CreatureScript
{
public:
    npc_kayn_tyranna_fight() : CreatureScript("npc_kayn_tyranna_fight") { }

    struct npc_kayn_tyranna_fightAI : public ScriptedAI
    {
        npc_kayn_tyranna_fightAI(Creature* creature) : ScriptedAI(creature) {
            me->SetReactState(REACT_DEFENSIVE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->IsPlayer())
                if (Creature* creature = me->FindNearestCreature(BROOD_QUEEN_TYRANNA, me->GetVisibilityRange(), true))
                    AttackStart(creature);
        }

        void EnterCombat(Unit* who) override
        {
            who->GetAI()->AttackStart(me);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (HealthAbovePct(75))
                damage = urand(1, 2);
            else
                me->SetHealth(me->GetMaxHealth() * 0.85f);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override {}

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
            case DATA_TYRANNA_DEATH:
                Talk(TEXT_DEATH);
                EnterEvadeMode(EVADE_REASON_OTHER);
                break;
            }
        }

        void JustReachedHome() override {}

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            // while loop goes here

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kayn_tyranna_fightAI(creature);
    }
};

// Allari: 20542497 (Entry: 97962)
class npc_allari_tyranna_fight : public CreatureScript
{
public:
    npc_allari_tyranna_fight() : CreatureScript("npc_allari_tyranna_fight") { }

    struct npc_allari_tyranna_fightAI : public ScriptedAI
    {
        npc_allari_tyranna_fightAI(Creature* creature) : ScriptedAI(creature) {
            me->SetReactState(REACT_DEFENSIVE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->IsPlayer())
                if (Creature* creature = me->FindNearestCreature(BROOD_QUEEN_TYRANNA, me->GetVisibilityRange(), true))
                    AttackStart(creature);
        }

        void EnterCombat(Unit* who) override
        {
            who->GetAI()->AttackStart(me);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (HealthAbovePct(75))
                damage = urand(1, 2);
            else
                me->SetHealth(me->GetMaxHealth() * 0.85f);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override {}

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
            case DATA_TYRANNA_DEATH:
                EnterEvadeMode(EVADE_REASON_OTHER);
                break;
            }
        }

        void JustReachedHome() override {}

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            // while loop goes here

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_allari_tyranna_fightAI(creature);
    }
};

// Jace: 20542610 (Entry: 97959)
class npc_jace_tyranna_fight : public CreatureScript
{
public:
    npc_jace_tyranna_fight() : CreatureScript("npc_jace_tyranna_fight") { }

    struct npc_jace_tyranna_fightAI : public ScriptedAI
    {
        npc_jace_tyranna_fightAI(Creature* creature) : ScriptedAI(creature) {
            me->SetReactState(REACT_DEFENSIVE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->IsPlayer())
                if (Creature* creature = me->FindNearestCreature(BROOD_QUEEN_TYRANNA, me->GetVisibilityRange(), true))
                    AttackStart(creature);
        }

        void EnterCombat(Unit* who) override
        {
            who->GetAI()->AttackStart(me);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (HealthAbovePct(75))
                damage = urand(1, 2);
            else
                me->SetHealth(me->GetMaxHealth() * 0.85f);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override {}

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
            case DATA_TYRANNA_DEATH:
                EnterEvadeMode(EVADE_REASON_OTHER);
                break;
            }
        }

        void JustReachedHome() override {}

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_jace_tyranna_fightAI(creature);
    }
};

// Korvas: 20542498 (Entry: 98712)
class npc_korvas_tyranna_fight : public CreatureScript
{
public:
    npc_korvas_tyranna_fight() : CreatureScript("npc_korvas_tyranna_fight") { }

    struct npc_korvas_tyranna_fightAI : public ScriptedAI
    {
        npc_korvas_tyranna_fightAI(Creature* creature) : ScriptedAI(creature) {
            me->SetReactState(REACT_DEFENSIVE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->IsPlayer())
                if (Creature* creature = me->FindNearestCreature(BROOD_QUEEN_TYRANNA, me->GetVisibilityRange(), true))
                    AttackStart(creature);
        }

        void EnterCombat(Unit* who) override
        {
            who->GetAI()->AttackStart(me);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (HealthAbovePct(75))
                damage = urand(1, 2);
            else
                me->SetHealth(me->GetMaxHealth() * 0.85f);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override {}

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
            case DATA_TYRANNA_DEATH:
                EnterEvadeMode(EVADE_REASON_OTHER);
                break;
            }
        }

        void JustReachedHome() override {}

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_korvas_tyranna_fightAI(creature);
    }
};

enum TyrannaTexts
{
    TEXT_START_COMBAT = 0,
    TEXT_KEYSTONE = 1,
    TEXT_KISS = 2,
    TEXT_CHILDREN = 3,
    TEXT_TYRANNA_DEATH = 4,
};

enum TyrannaEvents
{
    EVENT_BROOD_SWARM = 1,
    EVENT_INTO_THE_SHADOWS = 2,
    EVENT_QUEENS_BITE = 3,
    EVENT_SAY_TEXT_2 = 4,
    EVENT_SAY_TEXT_1 = 5,
    EVENT_TYRANNA_DIED = 6,
};

enum TyrannaSpells
{
    SPELL_BROOD_SWARM = 197627,
    SPELL_INTO_THE_SHADOWS = 197414,
    SPELL_QUEENS_BITE = 197486,
};

enum TyrannaMisc
{
    NPC_KORVAS_TYRANNA = 98712,
    NPC_JACE_TYRANNA = 97959,
    NPC_KAYN_TYRANNA = 97244,
    NPC_ALLARI_TYRANNA = 97962,
    NPC_TYRANNA_SPAWN = 100334,
    NPC_SKITTERING_BROODLING = 100333,
};

class npc_brood_queen_tyranna : public CreatureScript
{
public:
    npc_brood_queen_tyranna() : CreatureScript("npc_brood_queen_tyranna") { }

    struct npc_brood_queen_tyrannaAI : public ScriptedAI
    {
        npc_brood_queen_tyrannaAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _playerParticipating = false;
            _combatStarted = false;
            _swarmSummoned = 0;
        }

        void Reset() override
        {
            _events.Reset();
            Initialize();
            me->setActive(true);
            me->SetReactState(REACT_PASSIVE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (player->GetDistance(me) < 10.0f)
                    if (!_combatStarted)
                    {
                        _combatStarted = true;
                        // Enter Combat
                        _events.ScheduleEvent(EVENT_SAY_TEXT_1, 0);
                        _events.ScheduleEvent(EVENT_BROOD_SWARM, 19000);
                        _events.ScheduleEvent(EVENT_INTO_THE_SHADOWS, 22000);
                        _events.ScheduleEvent(EVENT_QUEENS_BITE, urand(16000, 18000));
                    }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            // We will schedule the npc abilities when player move near the npc
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (HealthAbovePct(65) && attacker->IsCreature())
                if (attacker->GetEntry() == NPC_KAYN_TYRANNA)
                    damage = urand(1, 2);

            if (HealthBelowPct(65) && attacker->IsCreature())
                if (attacker->GetEntry() == NPC_KAYN_TYRANNA)
                    me->SetHealth(me->GetHealth() + damage);

            if (!_playerParticipating && attacker->ToPlayer())
            {
                if (Creature* creature = me->FindNearestCreature(NPC_KAYN_TYRANNA, me->GetVisibilityRange(), true))
                {
                    _playerParticipating = true;
                }
            }

            if (damage >= me->GetHealth())
            {
                _events.ScheduleEvent(EVENT_TYRANNA_DIED, 0);

                std::list<HostileReference*> threatList;
                threatList = me->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
                    if (Player* target = (*itr)->getTarget()->ToPlayer())
                        if (target->GetQuestStatus(38728) == QUEST_STATUS_INCOMPLETE)
                            target->KilledMonsterCredit(101760);
            }
        }

        void JustDied(Unit* killer) override
        {
            std::list<Creature*> summonedSwarm;
            me->GetCreatureListWithEntryInGrid(summonedSwarm, NPC_TYRANNA_SPAWN, me->GetVisibilityRange());
            for (std::list<Creature*>::const_iterator itr = summonedSwarm.begin(); itr != summonedSwarm.end(); ++itr)
                (*itr)->ToCreature()->DespawnOrUnsummon(0);

            if (Creature* creature = me->FindNearestCreature(NPC_KAYN_TYRANNA, me->GetVisibilityRange(), true))
                creature->AI()->SetData(DATA_TYRANNA_DEATH, DATA_TYRANNA_DEATH);
            if (Creature* creature = me->FindNearestCreature(NPC_KORVAS_TYRANNA, me->GetVisibilityRange(), true))
                creature->AI()->SetData(DATA_TYRANNA_DEATH, DATA_TYRANNA_DEATH);
            if (Creature* creature = me->FindNearestCreature(NPC_JACE_TYRANNA, me->GetVisibilityRange(), true))
                creature->AI()->SetData(DATA_TYRANNA_DEATH, DATA_TYRANNA_DEATH);
            if (Creature* creature = me->FindNearestCreature(NPC_ALLARI_TYRANNA, me->GetVisibilityRange(), true))
                creature->AI()->SetData(DATA_TYRANNA_DEATH, DATA_TYRANNA_DEATH);

            me->ForcedDespawn(15000, 3s);
        }

        void SummomNearTarget(uint8 count, uint32 entry, Position targetPos, uint32 duration)
        {
            for (uint8 i = 0; i < count; i++)
            {
                uint8 rand = urand(1, 2);
                float angle = frand(0.0f, 2.0f * float(M_PI));
                float x = targetPos.GetPositionX() + (5.0f * std::cos(angle));
                float y = targetPos.GetPositionY() + (5.0f * std::sin(angle));
                Position randomPosition = {
                    x, y, targetPos.GetPositionZ(), targetPos.GetOrientation()
                };
                me->SummonCreature(entry, randomPosition, TEMPSUMMON_CORPSE_DESPAWN, duration);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BROOD_SWARM:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    {
                        Talk(TEXT_CHILDREN, me->GetOwner());
                        // commented out cast of the brood swarm spell because I've failed with the implementation
                        // leave here a workaround with the regular summon
                        // DoCast(target, SPELL_BROOD_SWARM);
                        SummomNearTarget(2, NPC_TYRANNA_SPAWN, target->GetPosition(), 20 * TimeConstants::IN_MILLISECONDS); // 2 bigger spiders
                        SummomNearTarget(3, NPC_SKITTERING_BROODLING, target->GetPosition(), 15 * TimeConstants::IN_MILLISECONDS); // 3 small spiders
                    }

                    _events.ScheduleEvent(EVENT_BROOD_SWARM, 16s);
                    _swarmSummoned++;
                    break;
                case EVENT_QUEENS_BITE:
                    Talk(TEXT_KISS, me->GetOwner());
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1), SPELL_QUEENS_BITE, true);
                    _events.ScheduleEvent(EVENT_QUEENS_BITE, 18s, 24s);
                    break;
                case EVENT_INTO_THE_SHADOWS:
                    DoCast(me, SPELL_INTO_THE_SHADOWS, true);
                    _events.RescheduleEvent(EVENT_QUEENS_BITE, 34s, 44s);
                    _events.RescheduleEvent(EVENT_BROOD_SWARM, 40s, 46s);
                    _events.ScheduleEvent(EVENT_INTO_THE_SHADOWS, 20s + 20s);
                    break;
                case EVENT_SAY_TEXT_2:
                    Talk(TEXT_KEYSTONE, me->GetOwner());
                    break;
                case EVENT_SAY_TEXT_1:
                    Talk(TEXT_START_COMBAT, me->GetOwner());
                    _events.ScheduleEvent(EVENT_SAY_TEXT_2, 3s);
                    break;
                case EVENT_TYRANNA_DIED:
                    Talk(TEXT_TYRANNA_DEATH, me->GetOwner());
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        bool _playerParticipating;
        bool _combatStarted;
        uint8 _swarmSummoned;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brood_queen_tyrannaAI(creature);
    }
};

// 97303
class npc_mardum_kayn_sunfury_end : public CreatureScript
{
public:
    npc_mardum_kayn_sunfury_end() : CreatureScript("npc_mardum_kayn_sunfury_end") { }

    bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* /*quest*/, uint32 /*opt*/) override
    {
        // This Scene make the mobs disappear ATM
        //if (quest->GetQuestId() == QUEST_THE_KEYSTONE)
        //    player->CastSpell(player, 193387, true); // Scene

        PhasingHandler::OnConditionChange(player);

        return true;
    }
};

// 245728
class go_mardum_the_keystone : public GameObjectScript
{
public:
    go_mardum_the_keystone() : GameObjectScript("go_mardum_the_keystone") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        player->KilledMonsterCredit(100651);
        return false;
    }
};

// 192140 - Back to black temple
class spell_mardum_back_to_black_temple : public SpellScript
{
    PrepareSpellScript(spell_mardum_back_to_black_temple);

    void HandleOnCast()
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            player->AddMovieDelayedAction(471, [player]
            {
                WorldLocation location(1468, 4325.46f, -620.53f, -281.40f, 1.517563f);
                player->SetHomebind(location, 7873);
                player->SendBindPointUpdate();
                player->TeleportTo(location);
            });

            player->GetScheduler().Schedule(Seconds(2), [](TaskContext context)
            {
                GetContextUnit()->RemoveAurasDueToSpell(192140); // Remove black screen
            });
            
            if (player->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC)
                player->LearnSpell(188499, false);
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_mardum_back_to_black_temple::HandleOnCast);
    }
};

//98986 Prolifica
class npc_q39495_prolifica : public CreatureScript
{
public:
    npc_q39495_prolifica() : CreatureScript("npc_q39495_prolifica") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_q39495_prolificaAI(creature);
    }

    struct npc_q39495_prolificaAI : public Scripted_NoMovementAI
    {
        EventMap events;
        ObjectGuid playerGuid;

        npc_q39495_prolificaAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            creature->SetCorpseDelay(30);
            creature->SetRespawnDelay(15);
            if (GameObject* gob = me->FindNearestGameObject(245169, 100.0f))
                gob->DestroyForNearbyPlayers();
        }

        void Reset() override
        {
            events.Reset();
            if (GameObject* gob = me->FindNearestGameObject(245169, 100.0f))
                gob->DestroyForNearbyPlayers();
        }

        void EnterCombat(Unit* victim) override
        {
            Talk(0);

            if (GameObject* gob = me->FindNearestGameObject(245169, 100.0f))
                gob->DestroyForNearbyPlayers();

            events.RescheduleEvent(1, 13000);
            events.RescheduleEvent(2, 5000);
        }

        void JustDied(Unit* killer) override
        {
            Player* pl = killer->ToPlayer();
            if (!pl)
                return;

            Talk(2);

            killer->GetScheduler().Schedule(Seconds(5), [](TaskContext context)
                {
                    Conversation::CreateConversation(585, GetContextUnit(), GetContextUnit()->GetPosition(), { GetContextUnit()->GetGUID() });
                });
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(197217);
                    events.RescheduleEvent(1, 13000);
                    break;
                case 2:
                    DoCast(197240);
                    events.RescheduleEvent(2, 20000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

// 101716
struct npc_the_keystone: public ScriptedAI
{
    npc_the_keystone(Creature* creature) : ScriptedAI(creature) { }
    
    void MoveInLineOfSight(Unit* u) override
    {
        Player* plr = u->ToPlayer();
        if (u->IsPlayer() && plr->GetQuestStatus(38728) == QUEST_STATUS_INCOMPLETE)
        {             
           if (plr->GetDistance(me) < 5.0f)
           {
                plr->KilledMonsterCredit(101760);
           }
        }
    }
};

/* Mardum phasehandler */
class phasehandler_mardum : public PlayerScript
{
public:
    phasehandler_mardum() : PlayerScript("phasehandler_mardum") { }


    uint32 MAP_MARDUM = 1481;
    uint32 ZONE_MARDUM_SHATTERED_ABYSS = 7705;

    void OnLogin(Player* player, bool firstLogin)
    {
        if (player->GetMapId() == MAP_MARDUM)
        {
            /* set default phases on login */
            player->Variables.Set("PHASE_1_BEGINING_ACTIVE",  true);     // is begining phase active (this is only active phase on begining)
            player->Variables.Set("PHASE_2_WELCOMING_ACTIVE", false);    // is welcoming phase active
            player->Variables.Set("PHASE_3_BANNER_ACTIVE",    false);    // is legion banner phase active
            player->Variables.Set("PHASE_4_FELSABER_ACTIVE",  false);    // is felsaber phase active
            player->Variables.Set("PHASE_5_ASHTONGUE_ACTIVE", false);    // is illidari outpost ashtongue phase active
            player->Variables.Set("PHASE_6_COILSKAR_ACTIVE",  false);    // is illidari outpost coilskar phase active
            player->Variables.Set("PHASE_7_SHIVARRA_ACTIVE",  false);    // is illidari outpost shivarra phase active


            /* modify phases according to player quest progress */
            //if (player->GetQuestStatus(QUEST_INVASION_BEGIN) == QUEST_STATUS_REWARDED)
            //    player->Variables.Set("PHASE_1_BEGINING_ACTIVE", false);

            if (player->GetQuestStatus(QUEST_INVASION_BEGIN) == QUEST_STATUS_COMPLETE)
                player->Variables.Set("PHASE_3_BANNER_ACTIVE", true);

            if (player->GetQuestStatus(QUEST_ASHTONGUE_FORCES) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_ASHTONGUE_FORCES) == QUEST_STATUS_REWARDED)
                player->Variables.Set("PHASE_5_ASHTONGUE_ACTIVE", true);

            if (player->GetQuestStatus(QUEST_COILSKAR_FORCES) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_COILSKAR_FORCES) == QUEST_STATUS_REWARDED)
                player->Variables.Set("PHASE_6_COILSKAR_ACTIVE", true);

            if (player->GetQuestStatus(QUEST_SHIVARRA_FORCES) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_SHIVARRA_FORCES) == QUEST_STATUS_REWARDED)
                player->Variables.Set("PHASE_7_SHIVARRA_ACTIVE", true);
        }
    }

    void OnUpdateZone(Player* player, uint32 /*newZone*/, uint32 /*oldZone*/, uint32 /*newArea*/) override
    {
        if (player->GetZoneId() == ZONE_MARDUM_SHATTERED_ABYSS)
        {
            /* modify phases according to player quest progress */
            if (player->GetQuestStatus(QUEST_INVASION_BEGIN) == QUEST_STATUS_NONE)
            {
                player->Variables.Set("PHASE_2_WELCOMING_ACTIVE", false);
            }
        }
    }

    void OnUpdate(Player* player, uint32) override
    {
        if (player->GetMapId() == MAP_MARDUM)
        {
            /* update player phases */
            if (player->Variables.GetValue<bool>("PHASE_1_BEGINING_ACTIVE")) { if (!player->GetPhaseShift().HasPhase(PHASE_1_BEGINING))  PhasingHandler::AddPhase(player, PHASE_1_BEGINING, true); }
                else { if (player->GetPhaseShift().HasPhase(PHASE_1_BEGINING)) PhasingHandler::RemovePhase(player, PHASE_1_BEGINING, true); }

            if (player->Variables.GetValue<bool>("PHASE_2_WELCOMING_ACTIVE")) { if (!player->GetPhaseShift().HasPhase(PHASE_2_WELCOMING))  PhasingHandler::AddPhase(player, PHASE_2_WELCOMING, true); }
                else { if (player->GetPhaseShift().HasPhase(PHASE_2_WELCOMING)) PhasingHandler::RemovePhase(player, PHASE_2_WELCOMING, true); }

            if (player->Variables.GetValue<bool>("PHASE_3_BANNER_ACTIVE")) { if (!player->GetPhaseShift().HasPhase(PHASE_3_BANNER))  PhasingHandler::AddPhase(player, PHASE_3_BANNER, true); }
                else { if (player->GetPhaseShift().HasPhase(PHASE_3_BANNER)) PhasingHandler::RemovePhase(player, PHASE_3_BANNER, true); }

            if (player->Variables.GetValue<bool>("PHASE_4_FELSABER_ACTIVE")) { if (!player->GetPhaseShift().HasPhase(PHASE_4_FELSABER))  PhasingHandler::AddPhase(player, PHASE_4_FELSABER, true); }
                else { if (player->GetPhaseShift().HasPhase(PHASE_4_FELSABER)) PhasingHandler::RemovePhase(player, PHASE_4_FELSABER, true); }

            if (player->Variables.GetValue<bool>("PHASE_5_ASHTONGUE_ACTIVE")) { if (!player->GetPhaseShift().HasPhase(PHASE_5_ASHTONGUE))  PhasingHandler::AddPhase(player, PHASE_5_ASHTONGUE, true); }
                else { if (player->GetPhaseShift().HasPhase(PHASE_5_ASHTONGUE)) PhasingHandler::RemovePhase(player, PHASE_5_ASHTONGUE, true); }

            if (player->Variables.GetValue<bool>("PHASE_6_COILSKAR_ACTIVE")) { if (!player->GetPhaseShift().HasPhase(PHASE_6_COILSKAR))  PhasingHandler::AddPhase(player, PHASE_6_COILSKAR, true); }
                else { if (player->GetPhaseShift().HasPhase(PHASE_6_COILSKAR)) PhasingHandler::RemovePhase(player, PHASE_6_COILSKAR, true); }

            if (player->Variables.GetValue<bool>("PHASE_7_SHIVARRA_ACTIVE")) { if (!player->GetPhaseShift().HasPhase(PHASE_7_SHIVARRA))  PhasingHandler::AddPhase(player, PHASE_7_SHIVARRA, true); }
                else { if (player->GetPhaseShift().HasPhase(PHASE_7_SHIVARRA)) PhasingHandler::RemovePhase(player, PHASE_7_SHIVARRA, true); }
        }
    }
};


void AddSC_zone_mardum()
{
    new npc_q39495_prolifica();
    new go_q39279();
    new go_q39495();
    new PlayerScript_mardum_welcome_scene_trigger();
    new scene_mardum_welcome();
    new npc_kayn_sunfury_welcome();
    new go_mardum_legion_banner_1();
    new go_mardum_portal_ashtongue();
    new scene_mardum_welcome_ashtongue();
    RegisterSpellScript(spell_learn_felsaber);
    RegisterCreatureAI(npc_mardum_allari);
    new go_mardum_cage("go_mardum_cage_belath", 94400);
    new go_mardum_cage("go_mardum_cage_cyana", 94377);
    new go_mardum_cage("go_mardum_cage_izal", 93117);
    new go_mardum_cage("go_mardum_cage_mannethrel", 93230);
    RegisterCreatureAI(npc_inquisitor_baleful);
    RegisterSpellScript(spell_mardum_infernal_smash);
    new npc_mardum_ashtongue_mystic();
    new go_mardum_portal_coilskar();
    new go_meeting_with_queen_ritual();
    new scene_mardum_meeting_with_queen();
    RegisterCreatureAI(npc_doom_commander_beliash);
    RegisterCreatureAI(npc_mardum_sevis_brightflame_shivarra);
    new go_mardum_portal_shivarra();
    new npc_mardum_captain();
    new npc_mardum_jace_darkweaver();
    RegisterSpellScript(spell_mardum_spectral_sight);
    new npc_fel_lord_caza();
    new go_mardum_illidari_banner();
    new go_mardum_tome_of_fel_secrets();
    new PlayerScript_mardum_spec_choice();
    new npc_mardum_izal_whitemoon();
    new npc_kayn_tyranna_fight();
    new npc_allari_tyranna_fight();
    new npc_jace_tyranna_fight();
    new npc_korvas_tyranna_fight();
    new npc_brood_queen_tyranna();
    new npc_mardum_kayn_sunfury_end();
    new go_mardum_the_keystone();
    new npc_kayn_sunfury();
    RegisterCreatureAI(npc_allari);
    RegisterCreatureAI(npc_cyana);
    RegisterCreatureAI(npc_korvas);
    new npc_mannethrel();
    RegisterSpellScript(spell_mardum_back_to_black_temple);
    RegisterCreatureAI(npc_the_keystone);
    new(phasehandler_mardum);
}
