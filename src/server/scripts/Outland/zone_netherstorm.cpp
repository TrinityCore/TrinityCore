/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Netherstorm
SD%Complete: 80
SDComment: Quest support: 10337, 10438, 10652 (special flight paths), 10299, 10321, 10322, 10323, 10329, 10330, 10338, 10365(Shutting Down Manaforge), 10198, 10191
SDCategory: Netherstorm
EndScriptData */

/* ContentData
npc_manaforge_control_console
go_manaforge_control_console
npc_commander_dawnforge
npc_bessy
npc_maxx_a_million
go_captain_tyralius_prison
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

/*######
## npc_manaforge_control_console
######*/

//used by 20209, 20417, 20418, 20440, signed for 20209
enum ManaforgeConsoleData
{
    EMOTE_START                 = 0,
    EMOTE_60                    = 1,
    EMOTE_30                    = 2,
    EMOTE_10                    = 3,
    EMOTE_COMPLETE              = 4,
    EMOTE_ABORT                 = 5,

    ENTRY_BNAAR_C_CONSOLE       = 20209,
    ENTRY_CORUU_C_CONSOLE       = 20417,
    ENTRY_DURO_C_CONSOLE        = 20418,
    ENTRY_ARA_C_CONSOLE         = 20440,

    ENTRY_SUNFURY_TECH          = 20218,
    ENTRY_SUNFURY_PROT          = 20436,

    ENTRY_ARA_TECH              = 20438,
    ENTRY_ARA_ENGI              = 20439,
    ENTRY_ARA_GORKLONN          = 20460,

    SPELL_DISABLE_VISUAL        = 35031,
    SPELL_INTERRUPT_1           = 35016,                       //ACID mobs should cast this
    SPELL_INTERRUPT_2           = 35176,                       //ACID mobs should cast this (Manaforge Ara-version)
};

class npc_manaforge_control_console : public CreatureScript
{
public:
    npc_manaforge_control_console() : CreatureScript("npc_manaforge_control_console") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_manaforge_control_consoleAI(creature);
    }

    struct npc_manaforge_control_consoleAI : public ScriptedAI
    {
        npc_manaforge_control_consoleAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 Event_Timer;
        uint32 Wave_Timer;
        uint32 Phase;
        bool Wave;
        uint64 someplayer;
        uint64 goConsole;
        Creature* add;

        void Reset() override
        {
            Event_Timer = 3000;
            Wave_Timer = 0;
            Phase = 1;
            Wave = false;
            someplayer = 0;
            goConsole = 0;
            add = NULL;
        }

        void EnterCombat(Unit* /*who*/) override { }

        /*void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            //we have no way of telling the Creature was hit by spell -> got aura applied after 10-12 seconds
            //then no way for the mobs to actually stop the shutdown as intended.
            if (spell->Id == SPELL_INTERRUPT_1)
                DoSay("Silence! I kill you!", LANG_UNIVERSAL, NULL);
        }*/

        void JustDied(Unit* /*killer*/) override
        {
            Talk(EMOTE_ABORT);

            if (someplayer)
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, someplayer))
                {
                    switch (me->GetEntry())
                    {
                        case ENTRY_BNAAR_C_CONSOLE:
                            player->FailQuest(10299);
                            player->FailQuest(10329);
                            break;
                        case ENTRY_CORUU_C_CONSOLE:
                            player->FailQuest(10321);
                            player->FailQuest(10330);
                            break;
                        case ENTRY_DURO_C_CONSOLE:
                            player->FailQuest(10322);
                            player->FailQuest(10338);
                            break;
                        case ENTRY_ARA_C_CONSOLE:
                            player->FailQuest(10323);
                            player->FailQuest(10365);
                            break;
                    }
                }
            }

            if (goConsole)
                if (GameObject* go = GameObject::GetGameObject(*me, goConsole))
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        }

        void DoWaveSpawnForCreature(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case ENTRY_BNAAR_C_CONSOLE:
                    if (rand()%2)
                    {
                        add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2933.68f, 4162.55f, 164.00f, 1.60f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (add) add->GetMotionMaster()->MovePoint(0, 2927.36f, 4212.97f, 164.00f);
                    }
                    else
                    {
                        add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2927.36f, 4212.97f, 164.00f, 4.94f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (add) add->GetMotionMaster()->MovePoint(0, 2933.68f, 4162.55f, 164.00f);
                    }
                    Wave_Timer = 30000;
                    break;
                case ENTRY_CORUU_C_CONSOLE:
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2445.21f, 2765.26f, 134.49f, 3.93f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2424.21f, 2740.15f, 133.81f);
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2429.86f, 2731.85f, 134.53f, 1.31f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2435.37f, 2766.04f, 133.81f);
                    Wave_Timer = 20000;
                    break;
                case ENTRY_DURO_C_CONSOLE:
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2986.80f, 2205.36f, 165.37f, 3.74f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2985.15f, 2197.32f, 164.79f);
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2952.91f, 2191.20f, 165.32f, 0.22f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2060.01f, 2185.27f, 164.67f);
                    Wave_Timer = 15000;
                    break;
                case ENTRY_ARA_C_CONSOLE:
                    if (rand()%2)
                    {
                        add = me->SummonCreature(ENTRY_ARA_TECH, 4035.11f, 4038.97f, 194.27f, 2.57f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (add) add->GetMotionMaster()->MovePoint(0, 4003.42f, 4040.19f, 193.49f);
                        add = me->SummonCreature(ENTRY_ARA_TECH, 4033.66f, 4036.79f, 194.28f, 2.57f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (add) add->GetMotionMaster()->MovePoint(0, 4003.42f, 4040.19f, 193.49f);
                        add = me->SummonCreature(ENTRY_ARA_TECH, 4037.13f, 4037.30f, 194.23f, 2.57f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (add) add->GetMotionMaster()->MovePoint(0, 4003.42f, 4040.19f, 193.49f);
                    }
                    else
                    {
                        add = me->SummonCreature(ENTRY_ARA_TECH, 3099.59f, 4049.30f, 194.22f, 0.05f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (add) add->GetMotionMaster()->MovePoint(0, 4028.01f, 4035.17f, 193.59f);
                        add = me->SummonCreature(ENTRY_ARA_TECH, 3999.72f, 4046.75f, 194.22f, 0.05f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (add) add->GetMotionMaster()->MovePoint(0, 4028.01f, 4035.17f, 193.59f);
                        add = me->SummonCreature(ENTRY_ARA_TECH, 3996.81f, 4048.26f, 194.22f, 0.05f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (add) add->GetMotionMaster()->MovePoint(0, 4028.01f, 4035.17f, 193.59f);
                    }
                    Wave_Timer = 15000;
                    break;
            }
        }
        void DoFinalSpawnForCreature(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case ENTRY_BNAAR_C_CONSOLE:
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2946.52f, 4201.42f, 163.47f, 3.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2927.49f, 4192.81f, 163.00f);
                    break;
                case ENTRY_CORUU_C_CONSOLE:
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2453.88f, 2737.85f, 133.27f, 2.59f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2433.96f, 2751.53f, 133.85f);
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2441.62f, 2735.32f, 134.49f, 1.97f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2433.96f, 2751.53f, 133.85f);
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2450.73f, 2754.50f, 134.49f, 3.29f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2433.96f, 2751.53f, 133.85f);
                    break;
                case ENTRY_DURO_C_CONSOLE:
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2956.18f, 2202.85f, 165.32f, 5.45f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2972.27f, 2193.22f, 164.48f);
                    add = me->SummonCreature(ENTRY_SUNFURY_TECH, 2975.30f, 2211.50f, 165.32f, 4.55f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2972.27f, 2193.22f, 164.48f);
                    add = me->SummonCreature(ENTRY_SUNFURY_PROT, 2965.02f, 2217.45f, 164.16f, 4.96f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 2972.27f, 2193.22f, 164.48f);
                    break;
                case ENTRY_ARA_C_CONSOLE:
                    add = me->SummonCreature(ENTRY_ARA_ENGI, 3994.51f, 4020.46f, 192.18f, 0.91f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 4008.35f, 4035.04f, 192.70f);
                    add = me->SummonCreature(ENTRY_ARA_GORKLONN, 4021.56f, 4059.35f, 193.59f, 4.44f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if (add) add->GetMotionMaster()->MovePoint(0, 4016.62f, 4039.89f, 193.46f);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (Event_Timer <= diff)
            {
                switch (Phase)
                {
                    case 1:
                        if (someplayer)
                        {
                            Unit* u = ObjectAccessor::GetUnit(*me, someplayer);
                            if (u && u->GetTypeId() == TYPEID_PLAYER)
                                Talk(EMOTE_START, u);
                        }
                        Event_Timer = 60000;
                        Wave = true;
                        ++Phase;
                        break;
                    case 2:
                        Talk(EMOTE_60);
                        Event_Timer = 30000;
                        ++Phase;
                        break;
                    case 3:
                        Talk(EMOTE_30);
                        Event_Timer = 20000;
                        DoFinalSpawnForCreature(me);
                        ++Phase;
                        break;
                    case 4:
                        Talk(EMOTE_10);
                        Event_Timer = 10000;
                        Wave = false;
                        ++Phase;
                        break;
                    case 5:
                        Talk(EMOTE_COMPLETE);
                        if (someplayer)
                        {
                            if (Player* player = ObjectAccessor::GetPlayer(*me, someplayer))
                                player->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
                            DoCast(me, SPELL_DISABLE_VISUAL);
                        }

                        if (goConsole)
                            if (GameObject* go = GameObject::GetGameObject(*me, goConsole))
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);

                        ++Phase;
                        break;
                }
            }
            else
                Event_Timer -= diff;

            if (Wave)
            {
                if (Wave_Timer <= diff)
                {
                    DoWaveSpawnForCreature(me);
                }
                else
                    Wave_Timer -= diff;
            }
        }
    };
};

/*######
## go_manaforge_control_console
######*/

/// @todo clean up this workaround when Trinity adds support to do it properly (with gossip selections instead of instant summon)
class go_manaforge_control_console : public GameObjectScript
{
public:
    go_manaforge_control_console() : GameObjectScript("go_manaforge_control_console") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
        {
            player->PrepareQuestMenu(go->GetGUID());
            player->SendPreparedQuest(go->GetGUID());
        }

        Creature* manaforge = NULL;

        switch (go->GetAreaId())
        {
            case 3726:                                          //b'naar
                if ((player->GetQuestStatus(10299) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10329) == QUEST_STATUS_INCOMPLETE) &&
                    player->HasItemCount(29366))
                    manaforge = player->SummonCreature(ENTRY_BNAAR_C_CONSOLE, 2918.95f, 4189.98f, 161.88f, 0.34f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 125000);
                break;
            case 3730:                                          //coruu
                if ((player->GetQuestStatus(10321) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10330) == QUEST_STATUS_INCOMPLETE) &&
                    player->HasItemCount(29396))
                    manaforge = player->SummonCreature(ENTRY_CORUU_C_CONSOLE, 2426.77f, 2750.38f, 133.24f, 2.14f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 125000);
                break;
            case 3734:                                          //duro
                if ((player->GetQuestStatus(10322) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10338) == QUEST_STATUS_INCOMPLETE) &&
                    player->HasItemCount(29397))
                    manaforge = player->SummonCreature(ENTRY_DURO_C_CONSOLE, 2976.48f, 2183.29f, 163.20f, 1.85f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 125000);
                break;
            case 3722:                                          //ara
                if ((player->GetQuestStatus(10323) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10365) == QUEST_STATUS_INCOMPLETE) &&
                    player->HasItemCount(29411))
                    manaforge = player->SummonCreature(ENTRY_ARA_C_CONSOLE, 4013.71f, 4028.76f, 192.10f, 1.25f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 125000);
                break;
        }

        if (manaforge)
        {
            CAST_AI(npc_manaforge_control_console::npc_manaforge_control_consoleAI, manaforge->AI())->someplayer = player->GetGUID();
            CAST_AI(npc_manaforge_control_console::npc_manaforge_control_consoleAI, manaforge->AI())->goConsole = go->GetGUID();
            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        }
        return true;
    }
};

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
        npc_commander_dawnforgeAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 PlayerGUID;
        uint64 ardonisGUID;
        uint64 pathaleonGUID;

        uint32 Phase;
        uint32 PhaseSubphase;
        uint32 Phase_Timer;
        bool isEvent;

        void Reset() override
        {
            PlayerGUID = 0;
            ardonisGUID = 0;
            pathaleonGUID = 0;

            Phase = 1;
            PhaseSubphase = 0;
            Phase_Timer = 4000;
            isEvent = false;
        }

        void EnterCombat(Unit* /*who*/) override { }

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
                me->SummonCreature(CreatureEntry[2], 2325.851563f, 2799.534668f, 133.084229f, 6.038996f, TEMPSUMMON_TIMED_DESPAWN, 90000);
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

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) override
    {
        //if player lost aura or not have at all, we should not try start event.
        if (!player->HasAura(SPELL_SUNFURY_DISGUISE))
            return false;

        if (player->IsAlive() && player->GetQuestStatus(QUEST_INFO_GATHERING) == QUEST_STATUS_INCOMPLETE)
        {
            Creature* Dawnforge = player->FindNearestCreature(CreatureEntry[1], 30.0f);
            if (!Dawnforge)
                return false;

            if (CAST_AI(npc_commander_dawnforge::npc_commander_dawnforgeAI, Dawnforge->AI())->CanStartEvent(player))
                return true;
        }
        return false;
    }
};

/*######
## npc_professor_dabiri
######*/
enum ProfessorDabiriData
{
    SPELL_PHASE_DISTRUPTOR  = 35780,

  //WHISPER_DABIRI          = 0, not existing in database

    QUEST_DIMENSIUS         = 10439,
    QUEST_ON_NETHERY_WINGS  = 10438,
};

#define GOSSIP_ITEM "I need a new phase distruptor, Professor"

class npc_professor_dabiri : public CreatureScript
{
public:
    npc_professor_dabiri() : CreatureScript("npc_professor_dabiri") { }

    //OnQuestAccept:
    //if (quest->GetQuestId() == QUEST_DIMENSIUS)
        //creature->AI()->Talk(WHISPER_DABIRI, player);

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            creature->CastSpell(player, SPELL_PHASE_DISTRUPTOR, false);
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_ON_NETHERY_WINGS) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(29778))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
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
            PlayerGUID = 0;
            ManaBurnTimer = 5000;
        }

        bool Weak;
        bool Materialize;
        bool Drained;
        uint8 WeakPercent;

        uint64 PlayerGUID;

        uint32 ManaBurnTimer;

        void Reset() override
        {
            Weak = false;
            Materialize = false;
            Drained = false;
            WeakPercent = 25 + (rand() % 16); // 25-40

            PlayerGUID = 0;

            ManaBurnTimer = 5000 + (rand() % 3 * 1000); // 5-8 sec cd

            if (me->GetEntry() == NPC_DRAINED_PHASE_HUNTER_ENTRY)
                me->UpdateEntry(NPC_PHASE_HUNTER_ENTRY);
        }

        void EnterCombat(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                PlayerGUID = who->GetGUID();
        }

        //void SpellHit(Unit* /*caster*/, const SpellInfo* /*spell*/) override
        //{
        //    DoCast(me, SPELL_DE_MATERIALIZE);
        //}

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
                std::list<HostileReference*> AggroList = me->getThreatManager().getThreatList();
                std::list<Unit*> UnitsWithMana;

                for (std::list<HostileReference*>::const_iterator itr = AggroList.begin(); itr != AggroList.end(); ++itr)
                {
                    if (Unit* unit = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid()))
                    {
                        if (unit->GetCreateMana() > 0)
                            UnitsWithMana.push_back(unit);
                    }
                }
                if (!UnitsWithMana.empty())
                {
                    DoCast(Trinity::Containers::SelectRandomContainerElement(UnitsWithMana), SPELL_MANA_BURN);
                    ManaBurnTimer = 8000 + (rand() % 10 * 1000); // 8-18 sec cd
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
## npc_bessy
######*/
enum BessyData
{
    Q_ALMABTRIEB    = 10337,
    N_THADELL       = 20464,
    SPAWN_FIRST     = 20512,
    SPAWN_SECOND    = 19881,
    SAY_THADELL_1   = 0,
    SAY_THADELL_2   = 1,
};

class npc_bessy : public CreatureScript
{
public:
    npc_bessy() : CreatureScript("npc_bessy") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == Q_ALMABTRIEB)
        {
            creature->setFaction(113);
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            CAST_AI(npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bessyAI(creature);
    }

    struct npc_bessyAI : public npc_escortAI
    {
        npc_bessyAI(Creature* creature) : npc_escortAI(creature) { }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(Q_ALMABTRIEB);
        }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 3: //first spawn
                    me->SummonCreature(SPAWN_FIRST, 2449.67f, 2183.11f, 96.85f, 6.20f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(SPAWN_FIRST, 2449.53f, 2184.43f, 96.36f, 6.27f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(SPAWN_FIRST, 2449.85f, 2186.34f, 97.57f, 6.08f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 7:
                    me->SummonCreature(SPAWN_SECOND, 2309.64f, 2186.24f, 92.25f, 6.06f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(SPAWN_SECOND, 2309.25f, 2183.46f, 91.75f, 6.22f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 12:
                    player->GroupEventHappens(Q_ALMABTRIEB, me);
                    if (me->FindNearestCreature(N_THADELL, 30))
                        Talk(SAY_THADELL_1);
                    break;
                case 13:
                    if (me->FindNearestCreature(N_THADELL, 30))
                        Talk(SAY_THADELL_2, player);
                    break;
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void Reset() override
        {
            me->RestoreFaction();
        }
    };
};

/*######
## npc_maxx_a_million
######*/

enum MaxxAMillion
{
    QUEST_MARK_V_IS_ALIVE   = 10191,
    GO_DRAENEI_MACHINE      = 183771
};

class npc_maxx_a_million_escort : public CreatureScript
{
public:
    npc_maxx_a_million_escort() : CreatureScript("npc_maxx_a_million_escort") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_maxx_a_million_escortAI(creature);
    }

    struct npc_maxx_a_million_escortAI : public npc_escortAI
    {
        npc_maxx_a_million_escortAI(Creature* creature) : npc_escortAI(creature) { }

        bool bTake;
        uint32 uiTakeTimer;

        void Reset() override
        {
            bTake=false;
            uiTakeTimer=3000;
        }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 7:
                case 17:
                case 29:
                    //Find Object and "work"
                    if (GetClosestGameObjectWithEntry(me, GO_DRAENEI_MACHINE, INTERACTION_DISTANCE))
                    {
                        // take the GO -> animation
                        me->HandleEmoteCommand(EMOTE_STATE_LOOT);
                        SetEscortPaused(true);
                        bTake=true;
                    }
                    break;
                case 36: //return and quest_complete
                    player->CompleteQuest(QUEST_MARK_V_IS_ALIVE);
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_MARK_V_IS_ALIVE);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (bTake)
            {
                if (uiTakeTimer < uiDiff)
                {
                    me->HandleEmoteCommand(EMOTE_STATE_NONE);
                    if (GameObject* go = GetClosestGameObjectWithEntry(me, GO_DRAENEI_MACHINE, INTERACTION_DISTANCE))
                    {
                        SetEscortPaused(false);
                        bTake=false;
                        uiTakeTimer = 3000;
                        go->Delete();
                    }
                }
                else
                    uiTakeTimer -= uiDiff;
            }
            DoMeleeAttackIfReady();
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_MARK_V_IS_ALIVE)
        {
            if (npc_maxx_a_million_escortAI* pEscortAI = CAST_AI(npc_maxx_a_million_escort::npc_maxx_a_million_escortAI, creature->AI()))
            {
                creature->setFaction(113);
                pEscortAI->Start(false, false, player->GetGUID());
            }
        }
        return true;
    }
};

/*######
## go_captain_tyralius_prison
######*/

enum CaptainTyralius
{
    NPC_CAPTAIN_TYRALIUS    = 20787,
    SAY_FREE                = 0,
};

class go_captain_tyralius_prison : public GameObjectScript
{
    public:
        go_captain_tyralius_prison() : GameObjectScript("go_captain_tyralius_prison") { }

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            go->UseDoorOrButton();
            if (Creature* tyralius = go->FindNearestCreature(NPC_CAPTAIN_TYRALIUS, 1.0f))
            {
                player->KilledMonsterCredit(NPC_CAPTAIN_TYRALIUS, 0);
                tyralius->AI()->Talk(SAY_FREE);
                tyralius->DespawnOrUnsummon(8000);
            }
            return true;
        }
};

void AddSC_netherstorm()
{
    new go_manaforge_control_console();
    new npc_manaforge_control_console();
    new npc_commander_dawnforge();
    new at_commander_dawnforge();
    new npc_professor_dabiri();
    new npc_phase_hunter();
    new npc_bessy();
    new npc_maxx_a_million_escort();
    new go_captain_tyralius_prison();
}
