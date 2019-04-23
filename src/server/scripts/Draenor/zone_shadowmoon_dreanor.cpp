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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Garrison.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "WodGarrison.h"

enum
{
    QUEST_FINDING_A_FOOTHOLD                = 34582,
    QUEST_FOR_THE_ALLIANCE                  = 34583,

    QUEST_ESTABLISH_YOUR_GARRISON           = 34586,
};

enum
{
    NPC_VELEN_FOLLOWER_MARAAD               = 79218,
    NPC_VELEN_FOLLOWER_YREL                 = 79219,

    NPC_FINDING_A_FOOTHOLD_KILL_CREDIT      = 79697,
    NPC_FOR_THE_ALLIANCE_PORTAL_KILL_CREDIT = 79433,
    NPC_ESTABLISH_YOUR_GARRISON_KILL_CREDIT = 79757,
};

// 79206 - Prophète Velen - Shadowmoon start
class npc_velen_shadowmoon_begin : public CreatureScript
{
public:
    npc_velen_shadowmoon_begin() : CreatureScript("npc_velen_shadowmoon_begin") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_FINDING_A_FOOTHOLD)
        {
            if (TempSummon* waypointVelen = player->SummonCreature(creature->GetEntry(), creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
            {
                waypointVelen->AI()->SetGUID(player->GetGUID());
            }

            if (Creature* normalMaraad = creature->FindNearestCreature(NPC_VELEN_FOLLOWER_MARAAD, 50.0f))
            {
                if (TempSummon* waypointMaraad = player->SummonCreature(NPC_VELEN_FOLLOWER_MARAAD, normalMaraad->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
                {
                    waypointMaraad->AI()->SetGUID(player->GetGUID());
                }
            }

            if (Creature* normalYrel = creature->FindNearestCreature(NPC_VELEN_FOLLOWER_YREL, 50.0f))
            {
                if (TempSummon* waypointYrel = player->SummonCreature(NPC_VELEN_FOLLOWER_YREL, normalYrel->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
                {
                    waypointYrel->AI()->SetGUID(player->GetGUID());
                }
            }
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_velen_shadowmoon_beginAI(creature);
    }

    struct npc_velen_shadowmoon_beginAI : public npc_escortAI
    {
        npc_velen_shadowmoon_beginAI(Creature* creature) : npc_escortAI(creature) { }

        ObjectGuid playerGuid;

        void Reset() override
        {
            playerGuid = ObjectGuid::Empty;
        }

        void SetGUID(ObjectGuid guid, int32 /*id*/) override
        {
            playerGuid = guid;
            Start(false, true, guid);
            SetDespawnAtFar(false);
        }

        void LastWaypointReached() override
        {
            me->DespawnOrUnsummon();
            me->SetFacingTo(5.631830f);

            if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                player->ForceCompleteQuest(QUEST_FINDING_A_FOOTHOLD);
        }
    };
};

// 79206 - Prophète Velen - Shadowmoon start
class npc_velen_shadowmoon_follower : public CreatureScript
{
public:
    npc_velen_shadowmoon_follower() : CreatureScript("npc_velen_shadowmoon_follower") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_velen_shadowmoon_followerAI(creature);
    }

    struct npc_velen_shadowmoon_followerAI : public npc_escortAI
    {
        npc_velen_shadowmoon_followerAI(Creature* creature) : npc_escortAI(creature) { }

        void SetGUID(ObjectGuid guid, int32 /*id*/) override
        {
            Start(true, true, guid);
        }

        void WaypointReached(uint32 pointId) override
        {
            switch (pointId)
            {
                case 12:
                {
                    if (me->GetEntry() == NPC_VELEN_FOLLOWER_MARAAD)
                    {
                        me->SetFacingTo(4.966650f);
                        me->DespawnOrUnsummon();
                    }
                    break;
                }
                case 13:
                {
                    if (me->GetEntry() == NPC_VELEN_FOLLOWER_YREL)
                    {
                        me->SetFacingTo(6.268840f);
                        me->DespawnOrUnsummon();
                    }
                    break;
                }
            }
        }
    };
};

class npc_baros_pre_garrison : public CreatureScript
{
public:
    npc_baros_pre_garrison() : CreatureScript("npc_baros_pre_garrison") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_ESTABLISH_YOUR_GARRISON) == QUEST_STATUS_INCOMPLETE)
            AddGossipItemFor(player, 60002, 1, 0, 0);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
    {
        Garrison* garrison = player->GetGarrison(GARRISON_TYPE_GARRISON);
        if (!garrison)
        {
            CloseGossipMenuFor(player);
            player->CreateGarrison(player->IsInAlliance() ? GARRISON_SITE_WOD_ALLIANCE : GARRISON_SITE_WOD_HORDE);
            player->GetGarrison(GARRISON_TYPE_GARRISON)->ToWodGarrison()->TeleportOwnerAndPlayMovie();
            player->KilledMonsterCredit(NPC_ESTABLISH_YOUR_GARRISON_KILL_CREDIT);
        }

        return true;
    }
};

// Revendication 169455
class spell_shadowmoon_claiming : public SpellScriptLoader
{
public:
    spell_shadowmoon_claiming() : SpellScriptLoader("spell_shadowmoon_claiming") { }

    class spell_shadowmoon_claiming_spellscript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_claiming_spellscript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster())
                return;

            Player* player = GetCaster()->ToPlayer();

            if (!player)
                return;

            player->KilledMonsterCredit(NPC_FOR_THE_ALLIANCE_PORTAL_KILL_CREDIT);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shadowmoon_claiming_spellscript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_claiming_spellscript();
    }
};

// 86213 - Aqualir - Mob rare
class npc_aqualir : public CreatureScript
{
public:
    npc_aqualir() : CreatureScript("npc_aqualir") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aqualirAI(creature);
    }

    struct npc_aqualirAI : public ScriptedAI
    {
        npc_aqualirAI(Creature* creature) :ScriptedAI(creature), summons(creature) {}

        uint8 binderCount;
        EventMap events;
        SummonList summons;

        enum spells
        {
            SPELL_AQUATIC_BALL      = 172182,
            SPELL_SHADOW_BINDING    = 172181,

            SPELL_JETTISON          = 172195,
            SPELL_SUBMERGE          = 172187,
            SPELL_WATER_BLAST       = 172186

        };

        enum Events
        {
            EVENT_JETTISON      = 1,
            EVENT_SUBMERGE      = 2,
            EVENT_WATER_BLAST   = 3
        };


        enum DisplayID
        {
            DISPLAYID_AQUATIC_BALL  = 59421,
            DISPLAYID_ELEMENTARY    = 58879
        };

        void Reset() override
        {
            binderCount = 3;

            summons.DespawnAll();

            me->CastSpell(me, SPELL_AQUATIC_BALL, true);
            me->SetDisplayId(DISPLAYID_AQUATIC_BALL);

            me->SummonCreature(81542, -870.97f, -1109.27f, 83.38f, 4.824920f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000);
            me->SummonCreature(81542, -861.96f, -1108.41f, 83.72f, 4.475420f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000);
            me->SummonCreature(81542, -880.42f, -1110.95f, 83.63f, 5.366850f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000);

            events.ScheduleEvent(EVENT_WATER_BLAST, 5000);
            events.ScheduleEvent(EVENT_SUBMERGE, urand(13000, 30000));
            events.ScheduleEvent(EVENT_JETTISON, urand(8000, 18000));

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void JustSummoned(Creature* summon) override
        {
            summon->CastSpell(me, SPELL_SHADOW_BINDING, true);
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            --binderCount;

            if (binderCount != 0)
                return;

            summons.Despawn(summon);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveAurasDueToSpell(SPELL_AQUATIC_BALL);
            me->SetDisplayId(DISPLAYID_ELEMENTARY);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_JETTISON:
                {
                    if (Unit* victim = me->GetVictim())
                        me->CastSpell(victim, SPELL_JETTISON, false);
                    events.ScheduleEvent(EVENT_JETTISON, urand(8000, 18000));
                    break;
                }

                case EVENT_SUBMERGE:
                {

                    me->CastSpell(me, SPELL_SUBMERGE, false);
                    events.ScheduleEvent(EVENT_SUBMERGE, urand(13000, 30000));
                    break;
                }

                case EVENT_WATER_BLAST:
                {
                    if (Unit* victim = me->GetVictim())
                        me->CastSpell(victim, SPELL_WATER_BLAST, false);
                    events.ScheduleEvent(EVENT_WATER_BLAST, 5000);
                    break;
                }
                }
            }

            DoMeleeAttackIfReady();
        }

    };
};

/// Submerge - 172189
struct areatrigger_aqualir_submerge : AreaTriggerAI
{
    areatrigger_aqualir_submerge(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    Position bottom = { -867.21f, -1133.19f, 81.22f, 1.75f };

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
            unit->ApplyMovementForce(at->GetGUID(), 7.0f, bottom);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsPlayer())
            unit->RemoveMovementForce(at->GetGUID());
    }
};

//## Gara - suite de quêtes cachées chasseur

enum GaraQuestLineEnum
{
    //Spells in questline
    SPELL_TRACKING_QUEST_1  = 177294,   ///> Complete quest 37423
    SPELL_TRACKING_QUEST_2  = 177295,   ///> Complete quest 37424
    SPELL_TRACKING_QUEST_3  = 177296 ,  ///> Complete quest 37427

    SPELL_VOID_LANTERN      = 177305,
    SPELsummon_GARA       = 177298, ///> Summon 88707

    //Creatures
    NPC_MOTHER_OMRA_BURIAL  = 88709,

    NPC_GARA_BURIAL         = 85645,
    NPC_GARA_VOID_PET       = 88707,
    NPC_GARA_TAMABLE_PET    = 88708,

    NPC_XAN                 = 88713,

    NPC_ELDER_VOIDCALLER    = 88711,
    NPC_ELDER_VOID_LORD     = 88712,

    //Items
    ITEM_SHADOWBERRY        = 119449,

    //GameObjects
    GOB_VOIDBLADE = 238853,

    //Gossips
    TEXT_ID_GARA_GRAVE      = 856451,
    TEXT_ID_GARA_BERRY      = 856452,

    //Cosmetic Spells
    SPELL_SOULSTONE_VISUAL  = 95750,
    SPELL_VOID_EFFECT       = 177303,

    //Soul Effigy events
    EVENT_SOUL_EFFIGY_01    = 1,
    EVENT_SOUL_EFFIGY_02,
    EVENT_SOUL_EFFIGY_03,
    EVENT_SOUL_EFFIGY_04,
    EVENT_SOUL_EFFIGY_05,
    EVENT_SOUL_EFFIGY_06,
    EVENT_SOUL_EFFIGY_07,
    EVENT_SOUL_EFFIGY_08,
    EVENT_SOUL_EFFIGY_END,

    //Gara events
    EVENT_CHECK_PLAYER      = 1,
    EVENT_GARA_01,
    EVENT_GARA_02,
    EVENT_GARA_03,
    EVENT_GARA_04,
    EVENT_GARA_05,
    EVENT_GARA_06,
    EVENT_GARA_END,


    //Void creatures + Xan events/actions
    ACTION_SUMMON_XAN       = 2,
    ACTION_XAN_DEATH        = 3,
    EVENT_CONSUMING_VOID,
    EVENT_GRIP_OF_THE_VOID,
    EVENT_NEGATE,
    EVENT_SINGULARITY,
    EVENT_TWIST_REALITY,
    EVENT_VOID_BOLT,

    //Void creatures + Xan Spells
    SPELL_VOID_BOLT         = 177639,
    SPELL_NEGATE            = 171343,
    SPELL_GRIP_OF_THE_VOID  = 157176,
    SPELL_TWIST_REALITY     = 171342,
    SPELL_CONSUMING_VOID    = 177307,
    SPELL_SINGULARITY       = 171346,
    SPELL_SINGULARITY_PULL  = 171350,
};

// 85645 - Gara
class npc_gara : public CreatureScript
{
public:
    npc_gara() : CreatureScript("npc_gara") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if(player->GetQuestStatus(37423) != QUEST_STATUS_INCOMPLETE && player->GetQuestStatus(37423) != QUEST_STATUS_COMPLETE && player->GetQuestStatus(37423) != QUEST_STATUS_REWARDED)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "(Beast Mastery) Lean down and scratch the wolf behind its ears.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (player->GetQuestStatus(37423) == QUEST_STATUS_REWARDED && player->GetQuestStatus(37424) != QUEST_STATUS_REWARDED && player->HasItemCount(ITEM_SHADOWBERRY, 1))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "(Beast Mastery) Show Gara the Shadowberries.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        player->PlayerTalkClass->SendGossipMenu(85645, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player * player, Creature * creature, uint32 /*p_Sender*/, uint32 action) override
    {
        if (player->getClass() != CLASS_HUNTER || player->GetSpecializationId() != TALENT_SPEC_HUNTER_BEASTMASTER)
            return false;

        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            SendGossipMenuFor(player, TEXT_ID_GARA_GRAVE, creature->GetGUID());
            player->CastSpell(player, SPELL_TRACKING_QUEST_1);
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 2)
        {
            SendGossipMenuFor(player, TEXT_ID_GARA_BERRY, creature->GetGUID());
            player->CastSpell(player, SPELL_TRACKING_QUEST_2);
        }
        return true;
    }

};

// 177301 - Use Effigy
class spell_use_effigy : public SpellScriptLoader
{
public:
    spell_use_effigy() : SpellScriptLoader("spell_use_effigy") { }

    class spell_use_effigy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_use_effigy_SpellScript);

        SpellCastResult CheckCast()
        {
            if (Unit *unt = GetCaster())
                if (Player *player = unt->ToPlayer())
                    if (player->GetQuestStatus(37426) != QUEST_STATUS_REWARDED || player->IsGameMaster())
                        if (player->GetQuestStatus(37425) == QUEST_STATUS_REWARDED || player->IsGameMaster())
                    return SPELL_CAST_OK;

            return SPELL_FAILED_SPELL_UNAVAILABLE;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_use_effigy_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_use_effigy_SpellScript();
    }
};

Position BurialEventPos[] =
{
    { -300.479309f, -754.269653f, 16.830910f, 0.251439f }, //Om'ra summon
    { -287.301636f, -751.508606f, 16.896639f, 0.223946f }, //Om'ra WP
    { -285.411957f, -753.524963f, 16.823908f, 5.360457f }, //Om'ra kneel
    { -280.977783f, -763.287170f, 16.710634f, 1.995033f }  //Xan summon
};

#define SAY_OMRA_01 "My soul... rest in peace... thanks."
#define SAY_OMRA_02 "Gara was my wolf, back before we forsook shamanism for these... dark magics. She wouldn't even look at me, not after I was tainted by the Void."
#define SAY_OMRA_03 "The Lord of Glass, a void god who calls himself Xan, had taken my soul captive in the void realm. Fragments of it were... torn away... for use by the Shadowmoon here in the burial grounds."
#define SAY_OMRA_04 "But Gara didn't wanted to leave me. Not until the right effigy has been burnt, and my soul appeased."
#define SAY_OMRA_05 "Thank you to deliver us."
#define SAY_XAN_01  "How dare you set her soul at rest. Om'ra's soul belongs to the VOID!"
#define SAY_XAN_02  "I shall take this one as compensation!"

// 237944 - Spirit Effigy
class go_spirit_effigy : public GameObjectScript
{
public:
    go_spirit_effigy() : GameObjectScript("go_spirit_effigy") { }

    struct go_spirit_effigyAI : public GameObjectAI
    {
        go_spirit_effigyAI(GameObject* go) : GameObjectAI(go)
        {
            events.ScheduleEvent(EVENT_SOUL_EFFIGY_01, 0);
        }

        ObjectGuid omraGuid;
        ObjectGuid xanGuid;

        TempSummon* GetOmra()
        {
            if (Creature* omra = ObjectAccessor::GetCreature(*go, omraGuid))
                return omra->ToTempSummon();

            return nullptr;
        }

        TempSummon* GetXan()
        {
            if (Creature* xan = ObjectAccessor::GetCreature(*go, xanGuid))
                return xan->ToTempSummon();

            return nullptr;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SOUL_EFFIGY_01:
                    {
                        if (Creature* gara = go->FindNearestCreature(NPC_GARA_BURIAL, 15, false))
                            gara->Respawn();

                        if (TempSummon* Omra = go->SummonCreature(NPC_MOTHER_OMRA_BURIAL, BurialEventPos[0], TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            omraGuid = Omra->GetGUID();
                            Omra->CastSpell(Omra, SPELL_SOULSTONE_VISUAL);
                            Omra->SetSpeed(MOVE_WALK, 0.4f);
                            Omra->SetSpeed(MOVE_RUN, 0.4f);
                            Omra->GetMotionMaster()->MovePoint(1, BurialEventPos[1], true);
                        }
                        events.ScheduleEvent(EVENT_SOUL_EFFIGY_02, 4.5 * IN_MILLISECONDS);

                        break;
                    }
                    case EVENT_SOUL_EFFIGY_02:
                    {
                        if (TempSummon* Omra = GetOmra())
                        {
                            Omra->Say(SAY_OMRA_01, LANG_UNIVERSAL, Omra);
                            Omra->GetMotionMaster()->MovePoint(1, BurialEventPos[2], true);
                        }
                        events.ScheduleEvent(EVENT_SOUL_EFFIGY_03, 4 * IN_MILLISECONDS);

                        break;
                    }
                    case EVENT_SOUL_EFFIGY_03:
                    {
                        if (TempSummon* Omra = GetOmra())
                        {
                            Omra->Say(SAY_OMRA_02, LANG_UNIVERSAL, Omra);
                            Omra->HandleEmoteCommand(16 /*EMOTE_ONESHOT_KNEEL*/);
                        }

                        events.ScheduleEvent(EVENT_SOUL_EFFIGY_04, 8 * IN_MILLISECONDS);

                        break;
                    }
                    case EVENT_SOUL_EFFIGY_04:
                    {
                        if (TempSummon* Omra = GetOmra())
                            Omra->Say(SAY_OMRA_03, LANG_UNIVERSAL, Omra);

                        events.ScheduleEvent(EVENT_SOUL_EFFIGY_05, 11 * IN_MILLISECONDS);

                        break;
                    }
                    case EVENT_SOUL_EFFIGY_05:
                    {
                        if (TempSummon* Omra = GetOmra())
                            Omra->Say(SAY_OMRA_04, LANG_UNIVERSAL, Omra);

                        events.ScheduleEvent(EVENT_SOUL_EFFIGY_06, 7.5 * IN_MILLISECONDS);

                        break;
                    }
                    case EVENT_SOUL_EFFIGY_06:
                    {
                        if (TempSummon* Omra = GetOmra())
                        {
                            Omra->Say(SAY_OMRA_05, LANG_UNIVERSAL, Omra);
                            Omra->CastSpell(Omra, SPELL_SOULSTONE_VISUAL);
                        }
                        events.ScheduleEvent(EVENT_SOUL_EFFIGY_07, 2 * IN_MILLISECONDS);
                        if (TempSummon* Xan = go->SummonCreature(NPC_XAN, BurialEventPos[3], TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            xanGuid = Xan->GetGUID();
                            Xan->SetReactState(REACT_PASSIVE);
                            Xan->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        }

                        break;
                    }
                    case EVENT_SOUL_EFFIGY_07:
                    {
                        if (TempSummon* Omra = GetOmra())
                            Omra->DisappearAndDie();

                        if (TempSummon* Xan = GetXan())
                            Xan->Say(SAY_XAN_01, LANG_UNIVERSAL, Xan);

                        events.ScheduleEvent(EVENT_SOUL_EFFIGY_08, 6 * IN_MILLISECONDS);

                        break;
                    }
                    case EVENT_SOUL_EFFIGY_08:
                    {
                        if (TempSummon* Xan = GetXan())
                            Xan->Say(SAY_XAN_02, LANG_UNIVERSAL, Xan);

                        if (Creature* gara = go->FindNearestCreature(NPC_GARA_BURIAL, 15, true))
                            gara->CastSpell(gara, SPELL_VOID_EFFECT);
                        events.ScheduleEvent(EVENT_SOUL_EFFIGY_END, 4 * IN_MILLISECONDS);

                        break;
                    }
                    case EVENT_SOUL_EFFIGY_END:
                    {
                        if (Creature* gara = go->FindNearestCreature(NPC_GARA_BURIAL, 15))
                        {
                            gara->TextEmote("Gara slowly disappear into the void.", gara);
                            gara->RemoveAllAuras();
                            gara->DisappearAndDie();
                        }

                        if (TempSummon* Xan = GetXan())
                            Xan->DisappearAndDie();

                        break;
                    }
                }
            }
        }
        EventMap events;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_spirit_effigyAI(go);
    }
};

// 238853 - Shadowmoon Voidblade
class go_shadowmoon_voidblade : public GameObjectScript
{
public:
    go_shadowmoon_voidblade() : GameObjectScript("go_shadowmoon_voidblade") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if ((player->HasAura(SPELL_VOID_LANTERN) && player->GetQuestStatus(37426) == QUEST_STATUS_REWARDED) || player->GetQuestStatus(37427) == QUEST_STATUS_REWARDED)
            if(player->getClass() == CLASS_HUNTER && player->GetSpecializationId() == TALENT_SPEC_HUNTER_BEASTMASTER)
            player->CastSpell(player, SPELL_TRACKING_QUEST_3);

        CloseGossipMenuFor(player);
        return true;
    }
};

// 177297 - Void Realm
class spell_aura_void_realm : public SpellScriptLoader
{
public:
    spell_aura_void_realm() : SpellScriptLoader("spell_aura_void_realm") { }

    class spell_aura_void_realm_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_aura_void_realm_AuraScript);

        void HandlePhasing(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster()->IsPlayer())
                return;

            PhasingHandler::AddPhase(GetCaster(), 8);
            GetCaster()->SummonCreature(NPC_GARA_VOID_PET, GetCaster()->GetPosition());
        }

        void HandlePhasingRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster()->IsPlayer())
                return;
            PhasingHandler::RemovePhase(GetCaster(), 8);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_aura_void_realm_AuraScript::HandlePhasing, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_aura_void_realm_AuraScript::HandlePhasingRemove, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_aura_void_realm_AuraScript();
    }
};

Position VoidRealmEventPos[] =
{
    { 932.043701f, -1835.089600f,  0.966880f, 1.500073f }, //Xan Summon
    { 930.837952f, -1810.070801f, -0.442225f, 1.683415f }, //Gara end of path
    { 942.078857f, -1802.449097f,  0.316170f, 3.808706f }, //Om'ra summon
    { 934.591187f, -1808.346069f, -0.136876f, 3.808706f }, //Om'ra way
};

#define SAY_OMRA_11 "She is being swallowed by the void! You must help her! There is only one way, tame her, now! Maybe you can find a way to reverse the process, and put her soul at rest, as you have done mine !"
#define SAY_OMRA_12 "You've done it... thank you. Goodbye, Gara, my soul is at peace now. I hope... that you find this peace some day, too. I am so sorry, my dearest Gara."

// 88707 - Gara invoquée dans le vide
class npc_void_gara : public CreatureScript
{
public:
    npc_void_gara() : CreatureScript("npc_void_gara") { }

    struct npc_void_garaAI : public ScriptedAI
    {
        npc_void_garaAI(Creature* creature) : ScriptedAI(creature)
        {
            owner           = creature->SelectNearestPlayer(10);
            Omra            = nullptr;
            gara_teamable   = nullptr;

            if (owner != nullptr)
                events.ScheduleEvent(EVENT_CHECK_PLAYER, 0);
            else
                creature->DisappearAndDie();
        }

        EventMap events;
        Player* owner;
        TempSummon* Omra;
        TempSummon* gara_teamable;

        void Reset() override
        {
            owner = nullptr;
            Omra = nullptr;
            gara_teamable = nullptr;
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_SUMMON_XAN)
                events.ScheduleEvent(EVENT_GARA_01, 0);
            else if (action == ACTION_XAN_DEATH)
                events.ScheduleEvent(EVENT_GARA_02, 0);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_PLAYER:
                    {
                        if (owner && owner->IsInWorld())
                        {
                            if (owner->HasAura(177297))
                                me->GetMotionMaster()->MoveFollow(owner, 2, (float)M_PI);
                            else me->DisappearAndDie();
                        }
                        else me->DisappearAndDie();

                        events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                    }
                    break;
                    case EVENT_GARA_01:
                    {
                        if (TempSummon* Xan = me->SummonCreature(NPC_XAN, VoidRealmEventPos[0], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60 * 60 * IN_MILLISECONDS))
                        {
                            Xan->setFaction(14);
                            Xan->SetReactState(REACT_AGGRESSIVE);
                        }
                    }
                        break;
                    case EVENT_GARA_02:
                    {
                        events.CancelEvent(EVENT_CHECK_PLAYER);
                        me->GetMotionMaster()->MovePoint(2, VoidRealmEventPos[1], true);
                        me->CastSpell(me, SPELL_VOID_EFFECT);
                        events.ScheduleEvent(EVENT_GARA_03, 10 * IN_MILLISECONDS);
                    }
                        break;
                    case EVENT_GARA_03:
                    {
                        Omra = me->SummonCreature(NPC_MOTHER_OMRA_BURIAL, VoidRealmEventPos[2], TEMPSUMMON_MANUAL_DESPAWN);
                        if (Omra)
                        {
                            Omra->CastSpell(Omra, SPELL_SOULSTONE_VISUAL);
                            Omra->SetSpeed(MOVE_WALK, 0.4f);
                            Omra->SetSpeed(MOVE_RUN, 0.4f);
                            Omra->GetMotionMaster()->MovePoint(1, VoidRealmEventPos[3], true);
                            Omra->Say(SAY_OMRA_11, LANG_UNIVERSAL, Omra);
                        }
                        me->RemoveAllAuras();
                        me->SetVisible(false);
                        gara_teamable = me->SummonCreature(NPC_GARA_TAMABLE_PET, me->GetPosition(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 30000);

                        if(gara_teamable)
                            gara_teamable->SetHealth(gara_teamable->GetHealth() * 60000);

                        events.ScheduleEvent(EVENT_GARA_04, 0);
                    }
                        break;
                    case EVENT_GARA_04:
                    {
                        if (!gara_teamable)
                            return;

                        if (gara_teamable->IsInCombat())
                            events.ScheduleEvent(EVENT_GARA_05, 2 * IN_MILLISECONDS);
                        else events.ScheduleEvent(EVENT_GARA_04, 300);
                    }
                        break;
                    case EVENT_GARA_05:
                    {
                        if (Omra)
                            Omra->Say(SAY_OMRA_12, LANG_UNIVERSAL, Omra);

                        events.ScheduleEvent(EVENT_GARA_06, 11 * IN_MILLISECONDS);
                    }
                        break;
                    case EVENT_GARA_06:
                    {
                        if (Omra)
                            Omra->CastSpell(Omra, SPELL_SOULSTONE_VISUAL);

                        events.ScheduleEvent(EVENT_GARA_END, 1 * IN_MILLISECONDS);
                    }
                        break;
                    case EVENT_GARA_END:
                    {
                        me->DisappearAndDie();

                        if (Omra)
                            Omra->DisappearAndDie();
                    }
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_void_garaAI(creature);
    }
};

// Void Creatures: 88711 - Elder Voidcaller // 88712 - Elder Void Lord
class npc_gara_void_creature : public CreatureScript
{
public:
    npc_gara_void_creature() : CreatureScript("npc_gara_void_creature") { }

    struct npc_gara_void_creatureAI : public ScriptedAI
    {
        npc_gara_void_creatureAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void JustDied(Unit* killer) override
        {
            //roll the chance to trigger the final Xan event
            if (Creature* gara = killer->FindNearestCreature(NPC_GARA_VOID_PET, 50, true))
                if (roll_chance_i(33))
                    gara->GetAI()->DoAction(ACTION_SUMMON_XAN);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.Reset();

            if (me->GetEntry() == NPC_ELDER_VOIDCALLER)
            {
                events.ScheduleEvent(EVENT_NEGATE, urand(30, 40) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_TWIST_REALITY, urand(2, 10) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_VOID_BOLT, urand(2, 5) * IN_MILLISECONDS);
            }
            else
            {
                events.ScheduleEvent(EVENT_CONSUMING_VOID, urand(40, 60) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_GRIP_OF_THE_VOID, urand(10, 20) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SINGULARITY, urand(5, 15) * IN_MILLISECONDS);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CONSUMING_VOID:
                    {
                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                            me->CastSpell(victim, SPELL_CONSUMING_VOID);

                        events.ScheduleEvent(EVENT_CONSUMING_VOID, urand(40, 60) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_GRIP_OF_THE_VOID:
                    {
                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 50.0f, true))
                            me->CastSpell(victim, SPELL_GRIP_OF_THE_VOID);

                        events.ScheduleEvent(EVENT_GRIP_OF_THE_VOID, urand(20, 30) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_NEGATE:
                    {
                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 10.0f, true))
                            me->CastSpell(victim, SPELL_NEGATE);

                        events.ScheduleEvent(EVENT_NEGATE, urand(10, 25) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_SINGULARITY:
                    {
                        DoCast(SPELL_SINGULARITY);

                        std::list<Player *> players; me->GetPlayerListInGrid(players, 45);

                        for (auto player : players)
                            player->CastSpell(me, SPELL_SINGULARITY_PULL);

                        events.ScheduleEvent(EVENT_SINGULARITY, urand(5, 15) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_TWIST_REALITY:
                    {
                        DoCast(SPELL_TWIST_REALITY);
                        events.ScheduleEvent(EVENT_TWIST_REALITY, urand(2, 6) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_VOID_BOLT:
                    {
                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 40.0f))
                            me->CastSpell(victim, SPELL_VOID_BOLT);

                        events.ScheduleEvent(EVENT_VOID_BOLT, urand(2, 6) * IN_MILLISECONDS);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gara_void_creatureAI(creature);
    }
};

// 88713 - Xan
class npc_xan_void_realm : public CreatureScript
{
public:
    npc_xan_void_realm() : CreatureScript("npc_xan_void_realm") { }

    struct npc_xan_void_realmAI : public ScriptedAI
    {
        npc_xan_void_realmAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void JustDied(Unit* killer) override
        {
            if (Creature* gara = killer->FindNearestCreature(NPC_GARA_VOID_PET, 50, true))
                gara->GetAI()->DoAction(ACTION_XAN_DEATH);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_CONSUMING_VOID, urand(40, 60) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_GRIP_OF_THE_VOID, urand(10, 20) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_NEGATE, urand(5, 10) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SINGULARITY, urand(15, 30) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_TWIST_REALITY, urand(5, 10) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_VOID_BOLT, urand(2, 5) * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CONSUMING_VOID:
                    {
                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                            me->CastSpell(victim, SPELL_CONSUMING_VOID);

                        events.ScheduleEvent(EVENT_CONSUMING_VOID, urand(40, 60) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_GRIP_OF_THE_VOID:
                    {
                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 50.0f, true))
                            me->CastSpell(victim, SPELL_GRIP_OF_THE_VOID);

                        events.ScheduleEvent(EVENT_GRIP_OF_THE_VOID, urand(30, 35) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_NEGATE:
                    {
                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 10.0f, true))
                            me->CastSpell(victim, SPELL_NEGATE);

                        events.ScheduleEvent(EVENT_NEGATE, urand(20, 25) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_SINGULARITY:
                    {
                        DoCast(SPELL_SINGULARITY);

                        std::list<Player *> players; me->GetPlayerListInGrid(players, 45);

                        for (auto player : players)
                            player->CastSpell(me, SPELL_SINGULARITY_PULL);

                        events.ScheduleEvent(EVENT_SINGULARITY, urand(15, 40) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_TWIST_REALITY:
                    {
                        DoCast(SPELL_TWIST_REALITY);
                        events.ScheduleEvent(EVENT_TWIST_REALITY, urand(2, 9) * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_VOID_BOLT:
                    {
                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 40.0f))
                            me->CastSpell(victim, SPELL_VOID_BOLT);

                        events.ScheduleEvent(EVENT_VOID_BOLT, urand(2, 5) * IN_MILLISECONDS);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xan_void_realmAI(creature);
    }
};

void AddSC_shadowmoon_draenor()
{
    new npc_velen_shadowmoon_begin();
    new npc_velen_shadowmoon_follower();
    new npc_baros_pre_garrison();
    new npc_aqualir();

    new spell_shadowmoon_claiming();

    RegisterAreaTriggerAI(areatrigger_aqualir_submerge);

    new npc_gara();
    new spell_use_effigy();
    new go_spirit_effigy();
    new go_shadowmoon_voidblade();
    new spell_aura_void_realm();
    new npc_void_gara();
    new npc_gara_void_creature();
    new npc_xan_void_realm();
}
