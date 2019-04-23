/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "SceneMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum eQuests
{
    QUEST_INVASION_BEGIN        = 40077,
    QUEST_ASHTONGUE_FORCES      = 40378,
    QUEST_COILSKAR_FORCES       = 40379,
    QUEST_MEETING_WITH_QUEEN    = 39050,
    QUEST_SHIVARRA_FORCES       = 38765,
    QUEST_BEFORE_OVERRUN        = 38766,
    QUEST_HIDDEN_NO_MORE        = 39495,
    QUEST_ON_FELBAT_WINGS       = 39663,
    QUEST_THE_KEYSTONE          = 38728,
};

enum eScenes
{
    SPELL_SCENE_MARDUM_WELCOME          = 193525,
    SPELL_SCENE_MARDUM_LEGION_BANNER    = 191677,
    SPELL_SCENE_MARDUM_ASHTONGUE_FORCES = 189261,
    SPELL_SCENE_MARDUM_COILSKAR_FORCES  = 190793,
    SPELL_SCENE_MEETING_WITH_QUEEN      = 188539,
    SPELL_SCENE_MARDUM_SHIVARRA_FORCES  = 190851,
};

enum ePhaseSpells
{
    SPELL_PHASE_170 = 59073,
    SPELL_PHASE_171 = 59074,
    SPELL_PHASE_172 = 59087,
    SPELL_PHASE_173 = 54341,

    SPELL_PHASE_175 = 57569,
    SPELL_PHASE_176 = 74789,
    SPELL_PHASE_177 = 69819,

    SPELL_PHASE_179 = 67789,
    SPELL_PHASE_180 = 68480,
    SPELL_PHASE_181 = 68481
};

enum ePhases
{
    SPELL_PHASE_MARDUM_WELCOME              = SPELL_PHASE_170,
    SPELL_PHASE_MARDUM_FELSABBER            = SPELL_PHASE_172,

    SPELL_PHASE_ILLIDARI_OUTPOST_ASHTONGUE  = SPELL_PHASE_175,
    SPELL_PHASE_ILLIDARI_OUTPOST_COILSKAR   = SPELL_PHASE_176,
    SPELL_PHASE_ILLIDARI_OUTPOST_SHIVARRA   = SPELL_PHASE_177
};

enum eMisc
{
    PLAYER_CHOICE_DH_SPEC_SELECTION             = 231,
    PLAYER_CHOICE_DH_SPEC_SELECTION_DEVASTATION = 478,
    PLAYER_CHOICE_DH_SPEC_SELECTION_VENGEANCE   = 479,
};

class PlayerScript_mardum_welcome_scene_trigger : public PlayerScript
{
public:
    PlayerScript_mardum_welcome_scene_trigger() : PlayerScript("PlayerScript_mardum_welcome_scene_trigger") {}

    uint32 checkTimer = 1000;

    void OnLogin(Player* player, bool firstLogin) override
    {
        if (player->getClass() == CLASS_DEMON_HUNTER && player->GetZoneId() == 7705 && firstLogin)
        {
            player->RemoveAurasDueToSpell(SPELL_PHASE_MARDUM_WELCOME);
        }
    }

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (checkTimer <= diff)
        {
            if (player->getClass() == CLASS_DEMON_HUNTER && player->GetZoneId() == 7705 && player->GetQuestStatus(QUEST_INVASION_BEGIN) == QUEST_STATUS_NONE &&
                player->GetPositionY() < 3280 && !player->HasAura(SPELL_SCENE_MARDUM_WELCOME) &&
                !player->HasAura(SPELL_PHASE_MARDUM_WELCOME))
            {
                player->CastSpell(player, SPELL_SCENE_MARDUM_WELCOME, true);
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
        player->AddAura(SPELL_PHASE_MARDUM_WELCOME);
    }
};

class npc_kayn_sunfury_welcome : public CreatureScript
{
public:
    npc_kayn_sunfury_welcome() : CreatureScript("npc_kayn_sunfury_welcome") { }

    bool OnQuestAccept(Player* /*player*/, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_INVASION_BEGIN)
        {
            // Todo : Make creatures wing out
        }
        return true;
    }
};

class go_mardum_legion_banner_1 : public GameObjectScript
{
public:
    go_mardum_legion_banner_1() : GameObjectScript("go_mardum_legion_banner_1") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_INVASION_BEGIN, 1))
            player->CastSpell(player, SPELL_SCENE_MARDUM_LEGION_BANNER, true);

        if (!player->GetQuestObjectiveData(QUEST_INVASION_BEGIN, 1))
            player->CastSpell(player, SPELL_PHASE_171, true);

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
            player->AddAura(SPELL_PHASE_MARDUM_FELSABBER);
        }
    }
};

// 200176 - Learn felsaber
    class spell_learn_felsaber : public SpellScript
    {
        PrepareSpellScript(spell_learn_felsaber);

        void HandleMountOnHit(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->RemoveAurasDueToSpell(SPELL_PHASE_MARDUM_FELSABBER);

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

struct npc_mardum_inquisitor_pernissius : public ScriptedAI
{
    npc_mardum_inquisitor_pernissius(Creature* creature) : ScriptedAI(creature) { }

    enum Spells
    {
        SPELL_INCITE_MADNESS    = 194529,
        SPELL_INFERNAL_SMASH    = 192709,

        SPELL_LEARN_EYE_BEAM    = 195447
    };

    enum Creatures
    {
        NPC_COLOSSAL_INFERNAL   = 96159
    };

    enum Text
    {
        SAY_ONDEATH = 0,
        SAY_ONCOMBAT = 1,
        SAY_60PCT = 2,
    };

    ObjectGuid colossalInfernalguid;

    void Reset() override
    {
        if (Creature* infernal = me->SummonCreature(NPC_COLOSSAL_INFERNAL, 523.404f, 2428.41f, -117.087f, 0.108873f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000))
            colossalInfernalguid = infernal->GetGUID();
    }

    Creature* GetInfernal() const
    {
        return ObjectAccessor::GetCreature(*me, colossalInfernalguid);
    }

    void EnterCombat(Unit*) override
    {
        Talk(SAY_ONCOMBAT);

        me->GetScheduler().Schedule(Seconds(15), [this](TaskContext context)
        {
            if (Unit* target = me->GetVictim())
                me->CastSpell(target, SPELL_INCITE_MADNESS);

            context.Repeat(Seconds(15));
        })
        .Schedule(Seconds(10), [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                if (Creature* infernal = GetInfernal())
                    infernal->CastSpell(target, SPELL_INFERNAL_SMASH);

            if (me->GetHealthPct() <= 60)
            {
                Talk(SAY_60PCT);
            }

            context.Repeat(Seconds(10));
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_ONDEATH);

        if (Creature* infernal = GetInfernal())
            infernal->KillSelf();

        std::list<Player*> players;
        me->GetPlayerListInGrid(players, 50.0f);

        for (Player* player : players)
        {
            player->KilledMonsterCredit(105946);
            player->KilledMonsterCredit(96159);

            if (!player->HasSpell(SPELL_LEARN_EYE_BEAM))
                player->CastSpell(player, SPELL_LEARN_EYE_BEAM);
        }
    }
};

// 192709 Infernal Smash
class spell_mardum_infernal_smash : public SpellScript
{
    PrepareSpellScript(spell_mardum_infernal_smash);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster() || !GetHitUnit())
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
            player->KilledMonsterCredit(94406); // QUEST_COILSKAR_FORCES storageIndex 0 KillCredit
            player->KilledMonsterCredit(97831); // QUEST_COILSKAR_FORCES storageIndex 1 KillCredit
            player->CastSpell(player, SPELL_SCENE_MARDUM_COILSKAR_FORCES, true);
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

//93221 Doom Commander Beliash
struct npc_mardum_doom_commander_beliash : public ScriptedAI
{
    npc_mardum_doom_commander_beliash(Creature* creature) : ScriptedAI(creature){ }

    enum Spells
    {
        SPELL_SHADOW_BOLT_VOLLEY    = 196403,
        SPELL_SHADOW_RETREAT        = 196625,
        SPELL_SHADOW_RETREAT_AT     = 195402,

        SPELL_LEARN_CONSUME_MAGIC   = 195439
    };

    enum texts
    {
        SAY_ONCOMBAT_BELIASH = 0,
        SAY_ONDEATH = 1,
    };

    void EnterCombat(Unit*) override
    {
        Talk(SAY_ONCOMBAT_BELIASH);

        me->GetScheduler().Schedule(Milliseconds(2500), [this](TaskContext context)
        {
            me->CastSpell(me, SPELL_SHADOW_BOLT_VOLLEY, true);
            context.Repeat(Milliseconds(2500));
        });

        me->GetScheduler().Schedule(Seconds(10), [this](TaskContext context)
        {
            me->CastSpell(me, SPELL_SHADOW_RETREAT);
            context.Repeat(Seconds(15));

            // During retreat commander make blaze appear
            me->GetScheduler().Schedule({ Milliseconds(500), Milliseconds(1000) }, [this](TaskContext /*context*/)
            {
                me->CastSpell(me, SPELL_SHADOW_RETREAT_AT, true);
            });
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_ONDEATH);

        std::list<Player*> players;
        me->GetPlayerListInGrid(players, 50.0f);

        for (Player* player : players)
        {
            player->ForceCompleteQuest(QUEST_BEFORE_OVERRUN);

            if (!player->HasSpell(SPELL_LEARN_CONSUME_MAGIC))
                player->CastSpell(player, SPELL_LEARN_CONSUME_MAGIC);
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
        }

        return false;
    }
};

// 90247, 93693, 94435
class npc_mardum_captain : public CreatureScript
{
public:
    npc_mardum_captain() : CreatureScript("npc_mardum_captain") { }

    enum
    {
        NPC_ASHTONGUE_CAPTAIN   = 90247,
        NPC_COILSKAR_CAPTAIN    = 93693,
        NPC_SHIVARRA_CAPTAIN    = 94435,

        SCENE_ASHTONGUE         = 191315,
        SCENE_COILSKAR          = 191400,
        SCENE_SHIVARRA          = 191402
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->KilledMonsterCredit(creature->GetEntry());

        uint32 sceneSpellId = 0;
        uint32 phaseSpellId = 0;
        switch (creature->GetEntry())
        {
            case NPC_ASHTONGUE_CAPTAIN: sceneSpellId = SCENE_ASHTONGUE; phaseSpellId = SPELL_PHASE_ILLIDARI_OUTPOST_ASHTONGUE;  break;
            case NPC_COILSKAR_CAPTAIN:  sceneSpellId = SCENE_COILSKAR;  phaseSpellId = SPELL_PHASE_ILLIDARI_OUTPOST_COILSKAR;   break;
            case NPC_SHIVARRA_CAPTAIN:  sceneSpellId = SCENE_SHIVARRA;  phaseSpellId = SPELL_PHASE_ILLIDARI_OUTPOST_SHIVARRA;   break;
            default: break;
        }

        if (sceneSpellId)
            player->CastSpell(player, sceneSpellId, true);

        if (phaseSpellId)
            player->RemoveAurasDueToSpell(phaseSpellId);

        player->GetScheduler().Schedule(Seconds(15), [player, creature](TaskContext /*context*/)
        {
            creature->DestroyForPlayer(player);
        });
        return true;
    }
};

// 96436
class npc_mardum_jace_darkweaver : public CreatureScript
{
public:
    npc_mardum_jace_darkweaver() : CreatureScript("npc_mardum_jace_darkweaver") { }

    enum
    {
        GOB_CAVERN_STONES = 245045
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->KilledMonsterCredit(creature->GetEntry());
        return true;
    }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == 39495)
        {
            if (Creature* demonHunter1 = creature->FindNearestCreature(101790, 50.0f))
                demonHunter1->CastSpell(demonHunter1, 194326, true);
            if (Creature* demonHunter2 = creature->FindNearestCreature(101787, 50.0f))
                demonHunter2->CastSpell(demonHunter2, 194326, true);
            if (Creature* demonHunter3 = creature->FindNearestCreature(101788, 50.0f))
                demonHunter3->CastSpell(demonHunter3, 194326, true);
            if (Creature* demonHunter4 = creature->FindNearestCreature(101789, 50.0f))
                demonHunter4->CastSpell(demonHunter4, 194326, true);

            if (GameObject* go = creature->FindNearestGameObject(245045, 50.0f))
                go->UseDoorOrButton();

            player->KilledMonsterCredit(98755, ObjectGuid::Empty);
        }

        if (GameObject* personnalCavernStone = player->SummonGameObject(GOB_CAVERN_STONES, 1237.150024f, 1642.619995f, 103.152f, 5.80559f, QuaternionData(0, 0, 20372944, 20372944), 0, true))
        {
            personnalCavernStone->GetScheduler().
            Schedule(2s, [](TaskContext context)
            {
                GetContextGameObject()->SetLootState(GO_READY);
                GetContextGameObject()->UseDoorOrButton(10000);
            }).Schedule(10s, [](TaskContext context)
            {
                GetContextGameObject()->Delete();
            });
        }

        return true;
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
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_mardum_spectral_sight::HandleOnCast);
    }
};

// 197180
struct npc_mardum_fel_lord_caza : public ScriptedAI
{
    npc_mardum_fel_lord_caza(Creature* creature) : ScriptedAI(creature) { }

    enum Spells
    {
        SPELL_FEL_INFUSION          = 197180,
        SPELL_LEARN_CONSUME_MAGIC   = 195441
    };

    void EnterCombat(Unit*) override
    {
        me->GetScheduler().Schedule(Seconds(10), [this](TaskContext context)
        {
            me->CastSpell(me->GetVictim(), SPELL_FEL_INFUSION, true);
            context.Repeat(Seconds(10));
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        std::list<Player*> players;
        me->GetPlayerListInGrid(players, 50.0f);

        for (Player* player : players)
        {
            player->ForceCompleteQuest(QUEST_HIDDEN_NO_MORE);

            if (!player->HasSpell(SPELL_LEARN_CONSUME_MAGIC))
                player->CastSpell(player, SPELL_LEARN_CONSUME_MAGIC);
        }
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
            case 243968: devastatorEntry = 96732; killCreditEntry = 96734; break;
            case 243967: devastatorEntry = 96731; killCreditEntry = 96733; break;
            case 243965: devastatorEntry = 93762; killCreditEntry = 96692; break;
            default: break;
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

    void OnPlayerChoiceResponse(Player* player, uint32 choiceID, uint32 responseID) override
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

// 96655, 93127, 99045, 96420, 96652
class npc_mardum_dh_learn_spec : public CreatureScript
{
public:
    npc_mardum_dh_learn_spec() : CreatureScript("npc_mardum_dh_learn_spec") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->KilledMonsterCredit(creature->GetEntry());

        if (creature->GetEntry() == 96652)
        {
            // TODO Animation power overwhel & kill creature
        }
        else
        {
            // TODO Animation
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

// 93802
struct npc_mardum_tyranna : public ScriptedAI
{
    npc_mardum_tyranna(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        std::list<Player*> players;
        me->GetPlayerListInGrid(players, 50.0f);

        for (Player* player : players)
            player->KilledMonsterCredit(101760);
    }
};

// 97303
class npc_mardum_kayn_sunfury_end : public CreatureScript
{
public:
    npc_mardum_kayn_sunfury_end() : CreatureScript("npc_mardum_kayn_sunfury_end") { }

    bool OnQuestReward(Player* /*player*/, Creature* /*creature*/, Quest const* /*quest*/, uint32 /*opt*/) override
    {
        // This Scene make the mobs disappear ATM
        //if (quest->GetQuestId() == QUEST_THE_KEYSTONE)
        //    player->CastSpell(player, 193387, true); // Scene

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

// 192140 back to black temple
class spell_mardum_back_to_black_temple : public SpellScript
{
    PrepareSpellScript(spell_mardum_back_to_black_temple);

    void HandleOnCast()
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            player->AddMovieDelayedAction(471, [player]
            {
                //player->CastSpell(nullptr, 192141, true);

                if (player->GetTeam() == ALLIANCE)
                    player->TeleportTo(0, -8838.72f, 616.29f, 93.06f, 0.779564f);
                else
                    player->TeleportTo(1, 1569.96f, -4397.41f, 16.05f, 0.527317f);
            });

            player->GetScheduler().Schedule(Seconds(2), [](TaskContext context)
            {
                GetContextUnit()->RemoveAurasDueToSpell(192140); // Remove black screen
            });

            // TEMPFIX - Spells learned in next zone
            if (player->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC)
            {
                player->LearnSpell(188499, false);
                player->LearnSpell(198793, false);
                player->LearnSpell(198589, false);
                player->LearnSpell(179057, false);
            }
            else
            {
                player->LearnSpell(204596, false);
                player->LearnSpell(203720, false);
                player->LearnSpell(204021, false);
                player->LearnSpell(185245, false);
            }
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_mardum_back_to_black_temple::HandleOnCast);
    }
};

void AddSC_zone_mardum()
{
    new PlayerScript_mardum_welcome_scene_trigger();
    new scene_mardum_welcome();
    new npc_kayn_sunfury_welcome();
    new go_mardum_legion_banner_1();
    new go_mardum_portal_ashtongue();
    new scene_mardum_welcome_ashtongue();
    RegisterSpellScript(spell_learn_felsaber);
    RegisterCreatureAI(npc_mardum_allari);
    new go_mardum_cage("go_mardum_cage_belath",     94400);
    new go_mardum_cage("go_mardum_cage_cyana",      94377);
    new go_mardum_cage("go_mardum_cage_izal",       93117);
    new go_mardum_cage("go_mardum_cage_mannethrel", 93230);
    RegisterCreatureAI(npc_mardum_inquisitor_pernissius);
    RegisterSpellScript(spell_mardum_infernal_smash);
    new npc_mardum_ashtongue_mystic();
    new go_mardum_portal_coilskar();
    new go_meeting_with_queen_ritual();
    new scene_mardum_meeting_with_queen();
    RegisterCreatureAI(npc_mardum_doom_commander_beliash);
    RegisterCreatureAI(npc_mardum_sevis_brightflame_shivarra);
    new go_mardum_portal_shivarra();
    new npc_mardum_captain();
    new npc_mardum_jace_darkweaver();
    RegisterSpellScript(spell_mardum_spectral_sight);
    RegisterCreatureAI(npc_mardum_fel_lord_caza);
    new go_mardum_illidari_banner();
    new go_mardum_tome_of_fel_secrets();
    new PlayerScript_mardum_spec_choice();
    new npc_mardum_dh_learn_spec();
    new npc_mardum_izal_whitemoon();
    RegisterCreatureAI(npc_mardum_tyranna);
    new npc_mardum_kayn_sunfury_end();
    new go_mardum_the_keystone();
    RegisterSpellScript(spell_mardum_back_to_black_temple);
}
