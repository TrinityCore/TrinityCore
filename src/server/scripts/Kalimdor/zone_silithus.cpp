/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
SDName: Silithus
SD%Complete: 100
SDComment: Quest support: 8348,8352,8361,8519
SDCategory: Silithus
EndScriptData */

/* ContentData
A Pawn on the Eternal Board - creatures, gameobjects and defines
quest_a_pawn_on_the_eternal_board
npc_qiraj_war_spawn : Adds that are summoned in the Qiraj gates battle.
npc_anachronos_the_ancient : Creature that controls the event.
npc_anachronos_quest_trigger: controls the spawning of the BG War mobs.
go_crystalline_tear : GameObject that begins the event and hands out quest
TO DO: get correct spell IDs and timings for spells cast upon dragon transformations
TO DO: Dragons should use the HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF) after transformation,
       but for some unknown reason it doesn't work.
EndContentData */

#include "ScriptMgr.h"
#include "CreatureAIImpl.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

/*#####
# Quest: A Pawn on the Eternal Board
#####*/

enum EternalBoard
{
    QUEST_A_PAWN_ON_THE_ETERNAL_BOARD = 8519,

    EVENT_AREA_RADIUS                 = 65,     // 65yds
    EVENT_COOLDOWN                    = 500000, // in ms. appears after event completed or failed (should be = Adds despawn time)

    NPC_ANACHRONOS                    = 15381,
    NPC_FANDRAL_STAGHELM              = 15382,
    NPC_ARYGOS                        = 15380,
    NPC_MERITHRA_OF_THE_DREAM         = 15378,
    NPC_CAELESTRASZ                   = 15379,

    ANACHRONOS_SAY_1                  = 0,
    ANACHRONOS_SAY_2                  = 1,
    ANACHRONOS_SAY_3                  = 2,
    ANACHRONOS_SAY_4                  = 3,
    ANACHRONOS_SAY_5                  = 4,
    ANACHRONOS_SAY_6                  = 5,
    ANACHRONOS_SAY_7                  = 6,
    ANACHRONOS_SAY_8                  = 7,
    ANACHRONOS_SAY_9                  = 8,
    ANACHRONOS_SAY_10                 = 9,
    ANACHRONOS_EMOTE_1                = 10,
    ANACHRONOS_EMOTE_2                = 11,
    ANACHRONOS_EMOTE_3                = 12,

    FANDRAL_SAY_1                     = 0,
    FANDRAL_SAY_2                     = 1,
    FANDRAL_SAY_3                     = 2,
    FANDRAL_SAY_4                     = 3,
    FANDRAL_SAY_5                     = 4,
    FANDRAL_SAY_6                     = 5,
    FANDRAL_EMOTE_1                   = 6,
    FANDRAL_EMOTE_2                   = 7,

    CAELESTRASZ_SAY_1                 = 0,
    CAELESTRASZ_SAY_2                 = 1,
    CAELESTRASZ_YELL_1                = 2,

    ARYGOS_SAY_1                      = 0,
    ARYGOS_YELL_1                     = 1,
    ARYGOS_EMOTE_1                    = 2,

    MERITHRA_SAY_1                    = 0,
    MERITHRA_SAY_2                    = 1,
    MERITHRA_YELL_1                   = 2,
    MERITHRA_EMOTE_1                  = 3,

    GO_GATE_OF_AHN_QIRAJ              = 176146,
    GO_GLYPH_OF_AHN_QIRAJ             = 176148,
    GO_ROOTS_OF_AHN_QIRAJ             = 176147
};

struct QuestCinematic
{
    int32 TextId;
    uint32 Creature, Timer;
};

// Creature 0 - Anachronos, 1 - Fandral, 2 - Arygos, 3 - Merithra, 4 - Caelestrasz
static QuestCinematic EventAnim[]=
{
    {ANACHRONOS_SAY_1,  0, 2000},
    {FANDRAL_SAY_1,     1, 4000},
    {MERITHRA_EMOTE_1,  3, 500},
    {MERITHRA_SAY_1,    3, 500},
    {ARYGOS_EMOTE_1,    2, 2000},
    {CAELESTRASZ_SAY_1, 4, 8000},
    {MERITHRA_SAY_2,    3, 6000},
    {0, 3, 2000},
    {MERITHRA_YELL_1,   3, 2500},
    {0, 3, 3000},                   //Morph
    {0, 3, 4000},                   //EmoteLiftoff
    {0, 3, 4000},                   // spell
    {0, 3, 1250},                   //fly
    {0, 3, 250},                    //remove flags
    {ARYGOS_SAY_1, 2, 3000},
    {0, 3, 2000},
    {ARYGOS_YELL_1, 2, 3000},
    {0, 3, 3000},                   //Morph
    {0, 3, 4000},                   //EmoteLiftoff
    {0, 3, 4000},                   // spell
    {0, 3, 1000},                   //fly
    {0, 3, 1000},                   //remove flags
    {CAELESTRASZ_SAY_2, 4, 5000},
    {0, 3, 3000},
    {CAELESTRASZ_YELL_1, 4, 3000},
    {0, 3, 3000},                   //Morph
    {0, 3, 4000},                   //EmoteLiftoff
    {0, 3, 2500},                   // spell
    {ANACHRONOS_SAY_2, 0, 2000},
    {0, 3, 250},                    //fly
    {0, 3, 25},                     //remove flags
    {FANDRAL_SAY_2, 1, 3000},
    {ANACHRONOS_SAY_3, 0, 10000},   //Both run through the armies
    {0, 3, 2000},                   // Sands will stop
    {0, 3, 8000},                   // Summon Gate
    {ANACHRONOS_SAY_4, 0, 4000},
    {0, 0, 2000},                   //spell 1-> Arcane cosmetic (Mobs freeze)
    {0, 0, 5000},                   //Spell 2-> Arcane long cosmetic (barrier appears) (Barrier -> Glyphs)
    {0, 0, 7000},                   //BarrieR
    {0, 0, 4000},                   //Glyphs
    {ANACHRONOS_SAY_5, 0, 2000},
    {0, 0, 4000},                   // Roots
    {FANDRAL_SAY_3, 1, 3000},       //Root Text
    {FANDRAL_EMOTE_1, 1, 3000},     //falls knee
    {ANACHRONOS_SAY_6, 0, 3000},
    {ANACHRONOS_SAY_7, 0, 3000},
    {ANACHRONOS_SAY_8, 0, 8000},
    {ANACHRONOS_EMOTE_1, 0, 1000},  //Give Scepter
    {FANDRAL_SAY_4, 1, 3000},
    {FANDRAL_SAY_5, 1, 3000},       //->Equip hammer~Scepter, throw it at door
    {FANDRAL_EMOTE_2, 1, 3000},     //Throw hammer at door.
    {ANACHRONOS_SAY_9, 0, 3000},
    {FANDRAL_SAY_6, 1, 3000},       //fandral goes away
    {ANACHRONOS_EMOTE_2, 0, 3000},
    {ANACHRONOS_EMOTE_3, 0, 3000},
    {0, 0, 2000},
    {0, 0, 2000},
    {0, 0, 4000},
    {ANACHRONOS_SAY_10, 0, 3000},
    {0, 0, 2000},
    {0, 0, 3000},
    {0, 0, 15000},
    {0, 0, 5000},
    {0, 0, 3500},
    {0, 0, 5000},
    {0, 0, 3500},
    {0, 0, 5000},
    {0, 0, 0}
};

//Cordinates for Spawns
Position const SpawnLocation[] =
{
    {-8085.0f, 1528.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8080.0f, 1526.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8085.0f, 1524.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8080.0f, 1522.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8085.0f, 1520.0f, 2.61f, 3.141592f}, //Kaldorei Infantry

    {-8085.0f, 1524.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8080.0f, 1522.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8085.0f, 1520.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8080.0f, 1518.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8085.0f, 1516.0f, 2.61f, 3.141592f}, //Kaldorei Infantry

    {-8085.0f, 1518.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8080.0f, 1516.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8080.0f, 1520.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8080.0f, 1424.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8085.0f, 1422.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    // 2 waves of warriors
    {-8082.0f, 1528.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8078.0f, 1525.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8082.0f, 1524.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8078.0f, 1526.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8082.0f, 1527.0f, 2.61f, 3.141592f}, //Kaldorei Infantry

    {-8082.0f, 1524.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8078.0f, 1522.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8082.0f, 1520.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8078.0f, 1518.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8082.0f, 1516.0f, 2.61f, 3.141592f}, //Kaldorei Infantry

    {-8082.0f, 1523.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8078.0f, 1521.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8082.0f, 1528.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8078.0f, 1519.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8082.0f, 1526.0f, 2.61f, 3.141592f}, //Kaldorei Infantry

    {-8082.0f, 1524.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8078.0f, 1522.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8082.0f, 1520.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8078.0f, 1518.0f, 2.61f, 3.141592f}, //Kaldorei Infantry
    {-8082.0f, 1516.0f, 2.61f, 3.141592f}, //Kaldorei Infantry

    {-8088.0f, 1510.0f, 2.61f, 0.0f},      //Anubisath Conqueror
    {-8084.0f, 1520.0f, 2.61f, 0.0f},      //Anubisath Conqueror
    {-8088.0f, 1530.0f, 2.61f, 0.0f},      //Anubisath Conqueror

    {-8080.0f, 1513.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8082.0f, 1523.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8085.0f, 1518.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8082.0f, 1516.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8085.0f, 1520.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8080.0f, 1528.0f, 2.61f, 0.0f},      //Qiraj Wasp

    {-8082.0f, 1513.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8079.0f, 1523.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8080.0f, 1531.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8079.0f, 1516.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8082.0f, 1520.0f, 2.61f, 0.0f},      //Qiraj Wasp
    {-8080.0f, 1518.0f, 2.61f, 0.0f},      //Qiraj Wasp

    {-8081.0f, 1514.0f, 2.61f, 0.0f},      //Qiraj Tank
    {-8081.0f, 1520.0f, 2.61f, 0.0f},      //Qiraj Tank
    {-8081.0f, 1526.0f, 2.61f, 0.0f},      //Qiraj Tank
    {-8081.0f, 1512.0f, 2.61f, 0.0f},      //Qiraj Tank
    {-8082.0f, 1520.0f, 2.61f, 0.0f},      //Qiraj Tank
    {-8081.0f, 1528.0f, 2.61f, 0.0f},      //Qiraj Tank

    {-8082.0f, 1513.0f, 2.61f, 3.141592f}, //Anubisath Conqueror
    {-8082.0f, 1520.0f, 2.61f, 3.141592f}, //Anubisath Conqueror
    {-8082.0f, 1527.0f, 2.61f, 3.141592f}, //Anubisath Conqueror
};

struct WaveData
{
    uint8 SpawnCount, UsedSpawnPoint;
    uint32 CreatureId, SpawnTimer, YellTimer, DespTimer;
    int32 WaveTextId;
};

static WaveData WavesInfo[5] =
{
    {30,  0, 15423, 0, 0, 24000, 0},    // Kaldorei Soldier
    { 3, 35, 15424, 0, 0, 24000, 0},    // Anubisath Conqueror
    {12, 38, 15414, 0, 0, 24000, 0},    // Qiraji Wasps
    { 6, 50, 15422, 0, 0, 24000, 0},    // Qiraji Tanks
    {15, 15, 15423, 0, 0, 24000, 0}     // Kaldorei Soldier

};

struct SpawnSpells
{
    uint32 Timer1, Timer2, SpellId;
};

static SpawnSpells SpawnCast[4] =
{
    {100000, 2000, 33652},   // Stoned
    {38500, 300000, 28528},  // Poison Cloud
    {58000, 300000, 35871},  // Frost Debuff (need correct spell)
    {80950, 300000, 42075},  // Fire Explosion (need correct spell however this one looks cool)
};

/*#####
# npc_anachronos_the_ancient
######*/

enum AnachronosTheAncient
{
    NPC_QIRAJI_WASP                  = 15414,
    NPC_QIRAJI_TANK                  = 15422,
    NPC_KALDOREI_INFANTRY            = 15423,
    NPC_ANUBISATH_CONQUEROR          = 15424,
    SPELL_ARCANE_CHANNELING          = 23017,
    SPELL_NOXIOUS_BREATH             = 24818,
    SPELL_GREEN_DRAGON_TRANSFORM_DND = 25105,
    SPELL_RED_DRAGON_TRANSFORM_DND   = 25106,
    SPELL_BLUE_DRAGON_TRANSFORM_DND  = 25107,
    SPELL_TIME_STOP                  = 25158,
    SPELL_CALL_PRISMATIC_BARRIER     = 25159,
    SPELL_CALL_GLYPHS_OF_WARDING     = 25166,
    SPELL_CALL_ANCIENTS              = 25167,
    SPELL_THROW_HAMMER               = 33806,
    SPELL_FROST_BREATH               = 50505,
    SPELL_FLAME_BREATH               = 54293
};

class npc_anachronos_the_ancient : public CreatureScript
{
public:
    npc_anachronos_the_ancient() : CreatureScript("npc_anachronos_the_ancient") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_anachronos_the_ancientAI(creature);
    }

    struct npc_anachronos_the_ancientAI : public ScriptedAI
    {
        npc_anachronos_the_ancientAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            AnimationTimer = 1500;
            AnimationCount = 0;
            AnachronosQuestTriggerGUID.Clear();
            MerithraGUID.Clear();
            ArygosGUID.Clear();
            CaelestraszGUID.Clear();
            FandralGUID.Clear();
            PlayerGUID.Clear();
            eventEnd = false;
        }

        uint32 AnimationTimer;
        uint8 AnimationCount;

        ObjectGuid AnachronosQuestTriggerGUID;
        ObjectGuid MerithraGUID;
        ObjectGuid ArygosGUID;
        ObjectGuid CaelestraszGUID;
        ObjectGuid FandralGUID;
        ObjectGuid PlayerGUID;
        bool eventEnd;

        void Reset() override
        {
            Initialize();

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void HandleAnimation()
        {
            Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);
            if (!player)
                return;

            Creature* Fandral = player->FindNearestCreature(NPC_FANDRAL_STAGHELM, 100.0f);
            Creature* Arygos = player->FindNearestCreature(NPC_ARYGOS, 100.0f);
            Creature* Caelestrasz = player->FindNearestCreature(NPC_CAELESTRASZ, 100.0f);
            Creature* Merithra = player->FindNearestCreature(NPC_MERITHRA_OF_THE_DREAM, 100.0f);

            if (!Fandral || !Arygos || !Caelestrasz || !Merithra)
                return;

            AnimationTimer = EventAnim[AnimationCount].Timer;
            if (eventEnd == false)
            {
                switch (AnimationCount)
                {
                    case 0:
                        Talk(ANACHRONOS_SAY_1, Fandral);
                        break;
                    case 1:
                        Fandral->SetTarget(me->GetGUID());
                        Fandral->AI()->Talk(FANDRAL_SAY_1, me);
                        break;
                    case 2:
                        Fandral->SetTarget(ObjectGuid::Empty);
                        Merithra->AI()->Talk(MERITHRA_EMOTE_1);
                        break;
                    case 3:
                        Merithra->AI()->Talk(MERITHRA_SAY_1);
                        break;
                    case 4:
                        Arygos->AI()->Talk(ARYGOS_EMOTE_1);
                        break;
                    case 5:
                        Caelestrasz->SetTarget(Fandral->GetGUID());
                        Caelestrasz->AI()->Talk(CAELESTRASZ_SAY_1);
                        break;
                    case 6:
                        Merithra->AI()->Talk(MERITHRA_SAY_2);
                        break;
                    case 7:
                        Caelestrasz->SetTarget(ObjectGuid::Empty);
                        Merithra->GetMotionMaster()->MoveCharge(-8065, 1530, 2.61f, 10);
                        break;
                    case 8:
                        Merithra->AI()->Talk(MERITHRA_YELL_1);
                        break;
                    case 9:
                        Merithra->CastSpell(Merithra, SPELL_GREEN_DRAGON_TRANSFORM_DND, true);
                        break;
                    case 10:
                        Merithra->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        Merithra->SetDisableGravity(true);
                        Merithra->GetMotionMaster()->MoveCharge(-8065, 1530, 6.61f, 3);
                        break;
                    case 11:
                        Merithra->CastSpell(Merithra, SPELL_NOXIOUS_BREATH, false);
                        break;
                    case 12:
                        Merithra->GetMotionMaster()->MoveCharge(-8100, 1530, 50, 42);
                        break;
                    case 13:
                        break;
                    case 14:
                        Arygos->AI()->Talk(ARYGOS_SAY_1);
                        Merithra->SetVisible(false);
                        break;
                    case 15:
                        Arygos->GetMotionMaster()->MoveCharge(-8065, 1530, 2.61f, 10);
                        Merithra->GetMotionMaster()->MoveCharge(-8034.535f, 1535.14f, 2.61f, 42);
                        break;
                    case 16:
                        Arygos->AI()->Talk(ARYGOS_YELL_1);
                        break;
                    case 17:
                        Arygos->CastSpell(Arygos, SPELL_BLUE_DRAGON_TRANSFORM_DND, true);
                        break;
                    case 18:
                        Arygos->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        Arygos->SetDisableGravity(true);
                        Arygos->GetMotionMaster()->MoveCharge(-8065, 1530, 6.61f, 42);
                        break;
                    case 19:
                        Arygos->CastSpell(Arygos, SPELL_FROST_BREATH, false);
                        break;
                    case 20:
                        Arygos->GetMotionMaster()->MoveCharge(-8095, 1530, 50, 42);
                        break;
                    case 21:
                        break;
                    case 22:
                        Caelestrasz->AI()->Talk(CAELESTRASZ_SAY_2, Fandral);
                        break;
                    case 23:
                        Caelestrasz->GetMotionMaster()->MoveCharge(-8065, 1530, 2.61f, 10);
                        Arygos->SetVisible(false);
                        Arygos->GetMotionMaster()->MoveCharge(-8034.535f, 1535.14f, 2.61f, 10);
                        break;
                    case 24:
                        Caelestrasz->AI()->Talk(CAELESTRASZ_YELL_1);
                        break;
                    case 25:
                        Caelestrasz->CastSpell(Caelestrasz, SPELL_RED_DRAGON_TRANSFORM_DND, true);
                        break;
                    case 26:
                        Caelestrasz->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        Caelestrasz->SetDisableGravity(true);
                        Caelestrasz->GetMotionMaster()->MoveCharge(-8065, 1530, 7.61f, 4);
                        break;
                    case 27:
                        Caelestrasz->CastSpell(Caelestrasz, SPELL_FLAME_BREATH, false);
                        break;
                    case 28:
                        Talk(ANACHRONOS_SAY_2, Fandral);
                        break;
                    case 29:
                        Caelestrasz->GetMotionMaster()->MoveCharge(-8095, 1530, 50, 42);
                        Fandral->AI()->Talk(FANDRAL_SAY_2);
                        break;
                    case 30:
                        break;
                    case 31:
                        Talk(ANACHRONOS_SAY_3, Fandral);
                        break;
                    case 32:
                        Caelestrasz->SetVisible(false);
                        Caelestrasz->GetMotionMaster()->MoveCharge(-8034.535f, 1535.14f, 2.61f, 42);
                        Fandral->GetMotionMaster()->MoveCharge(-8108, 1529, 2.77f, 8);
                        me->GetMotionMaster()->MoveCharge(-8113, 1525, 2.77f, 8);
                        break;//both run to the gate
                    case 33:
                        Talk(ANACHRONOS_SAY_4);
                        Caelestrasz->GetMotionMaster()->MoveCharge(-8050, 1473, 65, 15);
                        break; //Text: sands will stop
                    case 34:
                        DoCast(player, SPELL_ARCANE_CHANNELING, true);//Arcane Channeling
                        break;
                    case 35:
                        me->CastSpell({ -8088, 1520.43f, 2.67f }, SPELL_TIME_STOP, true);
                        break;
                    case 36:
                        DoCast(player, SPELL_CALL_PRISMATIC_BARRIER, true);
                        break;
                    case 37:
                        me->SummonGameObject(GO_GATE_OF_AHN_QIRAJ, Position(-8130.f, 1525.f, 17.5f, 0.f), QuaternionData(), 0);
                        break;
                    case 38:
                        DoCast(player, SPELL_CALL_GLYPHS_OF_WARDING, true);
                        me->SummonGameObject(GO_GLYPH_OF_AHN_QIRAJ, Position(-8130.f, 1525.f, 17.5f, 0.f), QuaternionData(), 0);
                        break;
                    case 39:
                        Talk(ANACHRONOS_SAY_5, Fandral);
                        break;
                    case 40:
                        Fandral->CastSpell(me, SPELL_CALL_ANCIENTS, true);
                        break;
                    case 41:
                        Fandral->SummonGameObject(GO_ROOTS_OF_AHN_QIRAJ, Position(-8130.f, 1525.f, 17.5f, 0.f), QuaternionData(), 0);
                        Fandral->AI()->Talk(FANDRAL_SAY_3);
                        break;
                    case 42:
                        me->CastStop();
                        Fandral->AI()->Talk(FANDRAL_EMOTE_1);
                        break;
                    case 43:
                        Fandral->CastStop();
                        break;
                    case 44:
                        Talk(ANACHRONOS_SAY_6);
                        break;
                    case 45:
                        Talk(ANACHRONOS_SAY_7);
                        break;
                    case 46:
                        Talk(ANACHRONOS_SAY_8);
                        me->GetMotionMaster()->MoveCharge(-8110, 1527, 2.77f, 4);
                        break;
                    case 47:
                        Talk(ANACHRONOS_EMOTE_1);
                        break;
                    case 48:
                        Fandral->AI()->Talk(FANDRAL_SAY_4, me);
                        break;
                    case 49:
                        Fandral->AI()->Talk(FANDRAL_SAY_5, me);
                        break;
                    case 50:
                        Fandral->AI()->Talk(FANDRAL_EMOTE_2);
                        Fandral->CastSpell({ -8127, 1525, 17.5f }, SPELL_THROW_HAMMER, true);
                        break;
                    case 51:
                    {
                        uint32 entries[4] = { NPC_KALDOREI_INFANTRY, NPC_ANUBISATH_CONQUEROR, NPC_QIRAJI_WASP, NPC_QIRAJI_TANK };
                        Unit* mob = nullptr;
                        for (uint8 i = 0; i < 4; ++i)
                        {
                            mob = player->FindNearestCreature(entries[i], 50);
                            while (mob)
                            {
                                mob->RemoveFromWorld();
                                mob = player->FindNearestCreature(NPC_KALDOREI_INFANTRY, 50);
                            }
                        }
                        break;
                    }
                    case 52:
                        Fandral->GetMotionMaster()->MoveCharge(-8028.75f, 1538.795f, 2.61f, 4);
                        Fandral->AI()->Talk(ANACHRONOS_SAY_9, me);
                        break;
                    case 53:
                        Fandral->AI()->Talk(FANDRAL_SAY_6);
                        break;
                    case 54:
                        Talk(ANACHRONOS_EMOTE_2);
                        break;
                    case 55:
                        Fandral->SetVisible(false);
                        break;
                    case 56:
                        Talk(ANACHRONOS_EMOTE_3);
                        me->GetMotionMaster()->MoveCharge(-8116, 1522, 3.65f, 4);
                        break;
                    case 57:
                        me->GetMotionMaster()->MoveCharge(-8116.7f, 1527, 3.7f, 4);
                        break;
                    case 58:
                        me->GetMotionMaster()->MoveCharge(-8112.67f, 1529.9f, 2.86f, 4);
                        break;
                    case 59:
                        me->GetMotionMaster()->MoveCharge(-8117.99f, 1532.24f, 3.94f, 4);
                        break;
                    case 60:
                        Talk(ANACHRONOS_SAY_10, player);
                        me->GetMotionMaster()->MoveCharge(-8113.46f, 1524.16f, 2.89f, 4);
                        break;
                    case 61:
                        me->GetMotionMaster()->MoveCharge(-8057.1f, 1470.32f, 2.61f, 6);
                        if (player->IsInRange(me, 0, 15))
                            player->GroupEventHappens(QUEST_A_PAWN_ON_THE_ETERNAL_BOARD, me);
                        break;
                    case 62:
                        me->SetDisplayId(15500);
                        break;
                    case 63:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        me->SetDisableGravity(true);
                        break;
                    case 64:
                        me->GetMotionMaster()->MoveCharge(-8000, 1400, 150, 9);
                        break;
                    case 65:
                        me->SetVisible(false);
                        if (Creature* AnachronosQuestTrigger = (ObjectAccessor::GetCreature(*me, AnachronosQuestTriggerGUID)))
                        {
                            Talk(ARYGOS_YELL_1);
                            AnachronosQuestTrigger->AI()->EnterEvadeMode();
                            eventEnd = true;
                        }
                        break;
                }
            }
            ++AnimationCount;
        }
        void UpdateAI(uint32 diff) override
        {
            if (AnimationTimer)
            {
                if (AnimationTimer <= diff)
                    HandleAnimation();
                else AnimationTimer -= diff;
            }
            if (AnimationCount < 65)
                me->CombatStop();
            if (AnimationCount == 65 || eventEnd)
                EnterEvadeMode();
        }
    };

};

/*######
# npc_qiraj_war_spawn
######*/

enum QirajWarSpawn
{
    SPELL_STONED_CHANNEL_CAST_VISUAL = 15533,
    SPELL_SUMMON_POISON_CLOUD        = 24319,
    SPELL_STONED                     = 33652
};

class npc_qiraj_war_spawn : public CreatureScript
{
public:
    npc_qiraj_war_spawn() : CreatureScript("npc_qiraj_war_spawn") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_qiraj_war_spawnAI(creature);
    }

    struct npc_qiraj_war_spawnAI : public ScriptedAI
    {
        npc_qiraj_war_spawnAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            SpellTimer1 = 0;
            SpellTimer2 = 0;
            SpellTimer3 = 0;
            SpellTimer4 = 0;
        }

        void Initialize()
        {
            MobGUID.Clear();
            PlayerGUID.Clear();
            Timers = false;
            hasTarget = false;
        }

        ObjectGuid MobGUID;
        ObjectGuid PlayerGUID;
        uint32 SpellTimer1, SpellTimer2, SpellTimer3, SpellTimer4;
        bool Timers;
        bool hasTarget;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override { }
        void JustDied(Unit* /*killer*/) override;

        void UpdateAI(uint32 diff) override
        {
            if (!Timers)
            {
                if (me->GetEntry() == NPC_ANUBISATH_CONQUEROR || me->GetEntry() == NPC_QIRAJI_TANK || me->GetEntry() == NPC_QIRAJI_WASP) //all but Kaldorei Soldiers
                {
                    SpellTimer1 = SpawnCast[1].Timer1;
                    SpellTimer2 = SpawnCast[2].Timer1;
                    SpellTimer3 = SpawnCast[3].Timer1;
                }
                if (me->GetEntry() == NPC_KALDOREI_INFANTRY || me->GetEntry() == NPC_ANUBISATH_CONQUEROR || me->GetEntry() == NPC_QIRAJI_TANK || me->GetEntry() == NPC_QIRAJI_WASP)
                    SpellTimer4 = SpawnCast[0].Timer1;
                Timers = true;
            }
            if (me->GetEntry() == NPC_ANUBISATH_CONQUEROR || me->GetEntry() == NPC_QIRAJI_TANK || me->GetEntry() == NPC_QIRAJI_WASP)
            {
                if (SpellTimer1 <= diff)
                {
                    DoCast(me, SpawnCast[1].SpellId);
                    DoCast(me, SPELL_SUMMON_POISON_CLOUD);
                    SpellTimer1 = SpawnCast[1].Timer2;
                } else SpellTimer1 -= diff;
                if (SpellTimer2 <= diff)
                {
                    DoCast(me, SpawnCast[2].SpellId);
                    SpellTimer2 = SpawnCast[2].Timer2;
                } else SpellTimer2 -= diff;
                if (SpellTimer3 <= diff)
                {
                    DoCast(me, SpawnCast[3].SpellId);
                    SpellTimer3 = SpawnCast[3].Timer2;
                } else SpellTimer3 -= diff;
            }
            if (me->GetEntry() == NPC_KALDOREI_INFANTRY || me->GetEntry() == NPC_ANUBISATH_CONQUEROR || me->GetEntry() == NPC_QIRAJI_TANK || me->GetEntry() == NPC_QIRAJI_WASP)
            {
                if (SpellTimer4 <= diff)
                {
                    me->RemoveAllAttackers();
                    me->AttackStop();
                    DoCast(me, SPELL_STONED_CHANNEL_CAST_VISUAL);
                    SpellTimer4 = SpawnCast[0].Timer2;
                } else SpellTimer4 -= diff;
            }
            if (!hasTarget)
            {
                Unit* target = nullptr;
                if (me->GetEntry() == NPC_ANUBISATH_CONQUEROR || me->GetEntry() == NPC_QIRAJI_TANK || me->GetEntry() == NPC_QIRAJI_WASP)
                    target = me->FindNearestCreature(NPC_KALDOREI_INFANTRY, 20, true);
                if (me->GetEntry() == NPC_KALDOREI_INFANTRY)
                {
                    uint8 tar = urand(0, 2);

                    if (tar == 0)
                        target = me->FindNearestCreature(NPC_QIRAJI_TANK, 20, true);
                    else if (tar == 1)
                        target = me->FindNearestCreature(NPC_ANUBISATH_CONQUEROR, 20, true);
                    else if (tar == 2)
                        target = me->FindNearestCreature(NPC_QIRAJI_WASP, 20, true);
                }
                hasTarget = true;
                if (target)
                    AttackStart(target);
            }
            if (!(me->FindNearestCreature(NPC_CAELESTRASZ, 60)))
                DoCast(me, SPELL_STONED);

            if (!UpdateVictim())
            {
                hasTarget = false;
                return;
            }

            DoMeleeAttackIfReady();
        }
    };

};

/*#####
# npc_anachronos_quest_trigger
#####*/

class npc_anachronos_quest_trigger : public CreatureScript
{
public:
    npc_anachronos_quest_trigger() : CreatureScript("npc_anachronos_quest_trigger") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_anachronos_quest_triggerAI(creature);
    }

    struct npc_anachronos_quest_triggerAI : public ScriptedAI
    {
        npc_anachronos_quest_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            PlayerGUID.Clear();

            WaveTimer = 2000;
            AnnounceTimer = 1000;
            LiveCount = 0;
            WaveCount = 0;

            EventStarted = false;
            Announced = false;
            Failed = false;
        }

        ObjectGuid PlayerGUID;

        uint32 WaveTimer;
        uint32 AnnounceTimer;

        int8 LiveCount;
        uint8 WaveCount;

        bool EventStarted;
        bool Announced;
        bool Failed;

        void Reset() override
        {
            Initialize();

            me->SetVisible(false);
        }

        void SummonNextWave()
        {
            uint8 locIndex = WavesInfo[WaveCount].UsedSpawnPoint;
            uint8 count = locIndex + WavesInfo[WaveCount].SpawnCount;

            for (uint8 i = locIndex; i <= count; ++i)
            {
                uint32 desptimer = WavesInfo[WaveCount].DespTimer;

                if (Creature* spawn = me->SummonCreature(WavesInfo[WaveCount].CreatureId, SpawnLocation[i], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, desptimer))
                {
                    if (spawn->GetEntry() == NPC_KALDOREI_INFANTRY)
                        spawn->SetUInt32Value(UNIT_FIELD_DISPLAYID, 15427 + rand32() % 4);
                    if (i >= 30) WaveCount = 1;
                    if (i >= 33) WaveCount = 2;
                    if (i >= 45) WaveCount = 3;
                    if (i >= 51) WaveCount = 4;

                    if (WaveCount < 5) //1-4 Wave
                    {
                        if (npc_qiraj_war_spawn::npc_qiraj_war_spawnAI* spawnAI = CAST_AI(npc_qiraj_war_spawn::npc_qiraj_war_spawnAI, spawn->AI()))
                        {
                            spawnAI->MobGUID = me->GetGUID();
                            spawnAI->PlayerGUID = PlayerGUID;
                        }
                    }
                }
            }

            WaveTimer = WavesInfo[WaveCount].SpawnTimer;
            AnnounceTimer = WavesInfo[WaveCount].YellTimer;
        }

        void CheckEventFail()
        {
            Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);
            if (!player)
                return;

            if (Group* EventGroup = player->GetGroup())
            {
                Player* groupMember = nullptr;

                uint8 GroupMemberCount = 0;
                uint8 DeadMemberCount = 0;
                uint8 FailedMemberCount = 0;

                Group::MemberSlotList const& members = EventGroup->GetMemberSlots();

                for (Group::member_citerator itr = members.begin(); itr!= members.end(); ++itr)
                {
                    groupMember = ObjectAccessor::GetPlayer(*me, itr->guid);
                    if (!groupMember)
                        continue;
                    if (!groupMember->IsWithinDistInMap(me, EVENT_AREA_RADIUS) && groupMember->GetQuestStatus(QUEST_A_PAWN_ON_THE_ETERNAL_BOARD) == QUEST_STATUS_INCOMPLETE)
                    {
                         groupMember->FailQuest(QUEST_A_PAWN_ON_THE_ETERNAL_BOARD);
                        ++FailedMemberCount;
                    }
                    ++GroupMemberCount;

                    if (groupMember->isDead())
                        ++DeadMemberCount;
                }

                if (GroupMemberCount == FailedMemberCount || !player->IsWithinDistInMap(me, EVENT_AREA_RADIUS))
                    Failed = true; //only so event can restart
            }
        }

        void LiveCounter()
        {
            --LiveCount;
            if (!LiveCount)
                Announced = false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!PlayerGUID || !EventStarted)
                return;

            if (WaveCount < 4)
            {
                if (!Announced && AnnounceTimer <= diff)
                {
                    Talk(WavesInfo[WaveCount].WaveTextId);
                    Announced = true;
                } else AnnounceTimer -= diff;

                if (WaveTimer <= diff)
                    SummonNextWave();
                else WaveTimer -= diff;
            }
            CheckEventFail();
            if (WaveCount == 4 || Failed)
                EnterEvadeMode();
        };
    };

};

void npc_qiraj_war_spawn::npc_qiraj_war_spawnAI::JustDied(Unit* /*killer*/)
{
    me->DespawnOrUnsummon();

    if (!MobGUID)
        return;

    if (Creature* mob = ObjectAccessor::GetCreature(*me, MobGUID))
        if (npc_anachronos_quest_trigger::npc_anachronos_quest_triggerAI* triggerAI = CAST_AI(npc_anachronos_quest_trigger::npc_anachronos_quest_triggerAI, mob->AI()))
            triggerAI->LiveCounter();

}

/*#####
# go_crystalline_tear
######*/

enum CrystallineTear
{
    ARYGOS_GNOME_FORM                  = 15418,
    CAELESTRASZ_NIGHT_ELF_FORM         = 15419,
    MERITHRA_NIGHT_ELF_FORM            = 15420,
    ANACHRONOS_QUEST_TRIGGER_INVISIBLE = 15454
};

class go_crystalline_tear : public GameObjectScript
{
public:
    go_crystalline_tear() : GameObjectScript("go_crystalline_tear") { }

    struct go_crystalline_tearAI : GameObjectAI
    {
        go_crystalline_tearAI(GameObject* go) : GameObjectAI(go) { }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_A_PAWN_ON_THE_ETERNAL_BOARD)
            {
                if (Creature* trigger = me->FindNearestCreature(ANACHRONOS_QUEST_TRIGGER_INVISIBLE, 100))
                {
                    Unit* Merithra = trigger->SummonCreature(NPC_MERITHRA_OF_THE_DREAM, -8034.535f, 1535.14f, 2.61f, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 220000);
                    Unit* Caelestrasz = trigger->SummonCreature(NPC_CAELESTRASZ, -8032.767f, 1533.148f, 2.61f, 1.5f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 220000);
                    Unit* Arygos = trigger->SummonCreature(NPC_ARYGOS, -8034.52f, 1537.843f, 2.61f, 5.7f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 220000);
                    /* Unit* Fandral = */ trigger->SummonCreature(NPC_FANDRAL_STAGHELM, -8028.462f, 1535.843f, 2.61f, 3.141592f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 220000);
                    Creature* Anachronos = trigger->SummonCreature(NPC_ANACHRONOS, -8028.75f, 1538.795f, 2.61f, 4, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 220000);

                    if (Merithra)
                    {
                        Merithra->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                        Merithra->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                        Merithra->SetUInt32Value(UNIT_FIELD_DISPLAYID, MERITHRA_NIGHT_ELF_FORM);
                        Merithra->SetFaction(FACTION_FRIENDLY);
                    }

                    if (Caelestrasz)
                    {
                        Caelestrasz->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                        Caelestrasz->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                        Caelestrasz->SetUInt32Value(UNIT_FIELD_DISPLAYID, CAELESTRASZ_NIGHT_ELF_FORM);
                        Caelestrasz->SetFaction(FACTION_FRIENDLY);
                    }

                    if (Arygos)
                    {
                        Arygos->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                        Arygos->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                        Arygos->SetUInt32Value(UNIT_FIELD_DISPLAYID, ARYGOS_GNOME_FORM);
                        Arygos->SetFaction(FACTION_FRIENDLY);
                    }

                    if (Anachronos)
                    {
                        if (npc_anachronos_the_ancient::npc_anachronos_the_ancientAI* anachronosAI = CAST_AI(npc_anachronos_the_ancient::npc_anachronos_the_ancientAI, Anachronos->AI()))
                            anachronosAI->PlayerGUID = player->GetGUID();

                        if (npc_anachronos_quest_trigger::npc_anachronos_quest_triggerAI* triggerAI = CAST_AI(npc_anachronos_quest_trigger::npc_anachronos_quest_triggerAI, trigger->AI()))
                        {
                            triggerAI->Failed = false;
                            triggerAI->PlayerGUID = player->GetGUID();
                            triggerAI->EventStarted = true;
                            triggerAI->Announced = true;
                        }
                    }
                }
            }
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_crystalline_tearAI(go);
    }
};

/*###
## go_wind_stone
###*/

enum WSSpells
{
    AURA_TWILIGHT_SET      = 24746,
    AURA_MEDALLION         = 24748,
    AURA_RING              = 24782,

    SPELL_TEMPLAR_RANDOM   = 24745,
    SPELL_TEMPLAR_FIRE     = 24747,
    SPELL_TEMPLAR_AIR      = 24757,
    SPELL_TEMPLAR_EARTH    = 24759,
    SPELL_TEMPLAR_WATER    = 24761,

    SPELL_DUKE_RANDOM      = 24762,
    SPELL_DUKE_FIRE        = 24766,
    SPELL_DUKE_AIR         = 24769,
    SPELL_DUKE_EARTH       = 24771,
    SPELL_DUKE_WATER       = 24773,

    SPELL_ROYAL_RANDOM     = 24785,
    SPELL_ROYAL_FIRE       = 24787,
    SPELL_ROYAL_AIR        = 24791,
    SPELL_ROYAL_EARTH      = 24792,
    SPELL_ROYAL_WATER      = 24793,

    SPELL_PUNISHMENT       = 24803,
    SPELL_SPAWN_IN         = 25035
};

enum WSGossip
{
    OPTION_ID_WS_RANDOM    = 0,
    OPTION_ID_1_CRIMSON    = 1,
    OPTION_ID_2_AZURE      = 2,
    OPTION_ID_3_EARTHEN    = 3,
    OPTION_ID_4_HOARY      = 4,
    OPTION_ID_1_CYNDERS    = 1,
    OPTION_ID_2_FATHOMS    = 2,
    OPTION_ID_3_SHARDS     = 3,
    OPTION_ID_4_ZEPHYRS    = 4,
    OPTION_ID_1_SKALDRENOX = 1,
    OPTION_ID_2_SKWOL      = 2,
    OPTION_ID_3_KAZUM      = 3,
    OPTION_ID_4_WHIRLAXIS  = 4,
    GOSSIP_ID_LESSER_WS    = 6540,
    GOSSIP_ID_WIND_STONE   = 6542,
    GOSSIP_ID_GREATER_WS   = 6543
};

enum WSCreatures
{
    NPC_TEMPLAR_FIRE       = 15209,
    NPC_TEMPLAR_WATER      = 15211,
    NPC_TEMPLAR_AIR        = 15212,
    NPC_TEMPLAR_EARTH      = 15307,

    NPC_DUKE_FIRE          = 15206,
    NPC_DUKE_WATER         = 15207,
    NPC_DUKE_EARTH         = 15208,
    NPC_DUKE_AIR           = 15220,

    NPC_ROYAL_FIRE         = 15203,
    NPC_ROYAL_AIR          = 15204,
    NPC_ROYAL_EARTH        = 15205,
    NPC_ROYAL_WATER        = 15305
};

enum WSItems
{
    ITEM_TEMPLAR_FIRE      = 20416,
    ITEM_TEMPLAR_AIR       = 20418,
    ITEM_TEMPLAR_EARTH     = 20419,
    ITEM_TEMPLAR_WATER     = 20420,

    ITEM_DUKE_FIRE         = 20432,
    ITEM_DUKE_AIR          = 20433,
    ITEM_DUKE_EARTH        = 20435,
    ITEM_DUKE_WATER        = 20436,

    ITEM_ROYAL_FIRE        = 20447,
    ITEM_ROYAL_AIR         = 20448,
    ITEM_ROYAL_EARTH       = 20449,
    ITEM_ROYAL_WATER       = 20450
};

enum WS
{
    TEMPLAR                = 0,
    DUKE                   = 1,
    ROYAL                  = 2,

    FIRE                   = 0x1,
    WATER                  = 0x2,
    EARTH                  = 0x4,
    AIR                    = 0x8
};

enum WSTexts
{
    SAY_TEMPLAR_AGGRO      = 0,
    SAY_DUKE_AGGRO         = 0,
    YELL_ROYAL_AGGRO       = 0
};

class go_wind_stone : public GameObjectScript
{
    public:
        go_wind_stone() : GameObjectScript("go_wind_stone") { }

        struct go_wind_stoneAI : public GameObjectAI
        {
            go_wind_stoneAI(GameObject* go) : GameObjectAI(go) { }

            private:
                uint8 GetPlayerRank(Player* player) // For random summoning
                {
                    bool setAura = player->HasAura(AURA_TWILIGHT_SET);
                    bool medallionAura = player->HasAura(AURA_MEDALLION);
                    bool ringAura = player->HasAura(AURA_RING);

                    if (setAura && medallionAura && ringAura)
                        return 3;
                    else if (setAura && medallionAura)
                        return 2;
                    else if (setAura)
                        return 1;
                    else
                        return 0;
                }

                uint8 GetItems(Player* player, WS type)
                {
                    uint8 result = 0x0;

                    switch (type)
                    {
                        case TEMPLAR:
                        {
                            if (player->HasItemCount(ITEM_TEMPLAR_FIRE))
                                result |= FIRE;
                            if (player->HasItemCount(ITEM_TEMPLAR_WATER))
                                result |= WATER;
                            if (player->HasItemCount(ITEM_TEMPLAR_EARTH))
                                result |= EARTH;
                            if (player->HasItemCount(ITEM_TEMPLAR_AIR))
                                result |= AIR;
                            break;
                        }
                        case DUKE:
                        {
                            if (player->HasItemCount(ITEM_DUKE_FIRE))
                                result |= FIRE;
                            if (player->HasItemCount(ITEM_DUKE_WATER))
                                result |= WATER;
                            if (player->HasItemCount(ITEM_DUKE_EARTH))
                                result |= EARTH;
                            if (player->HasItemCount(ITEM_DUKE_AIR))
                                result |= AIR;
                            break;
                        }
                        case ROYAL:
                        {
                            if (player->HasItemCount(ITEM_ROYAL_FIRE))
                                result |= FIRE;
                            if (player->HasItemCount(ITEM_ROYAL_WATER))
                                result |= WATER;
                            if (player->HasItemCount(ITEM_ROYAL_EARTH))
                                result |= EARTH;
                            if (player->HasItemCount(ITEM_ROYAL_AIR))
                                result |= AIR;
                            break;
                        }
                        default:
                            break;
                    }
                    return result;
                }

                void SummonNPC(GameObject* go, Player* player, uint32 npc, uint32 spell)
                {
                    go->CastSpell(player, spell);
                    TempSummon* summons = go->SummonCreature(npc, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), player->GetOrientation() - float(M_PI), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10 * 60 * 1000);
                    summons->CastSpell(summons, SPELL_SPAWN_IN, false);
                    switch (summons->GetEntry())
                    {
                        case NPC_TEMPLAR_FIRE:
                        case NPC_TEMPLAR_WATER:
                        case NPC_TEMPLAR_AIR:
                        case NPC_TEMPLAR_EARTH:
                            summons->AI()->Talk(SAY_TEMPLAR_AGGRO, player);
                            break;

                        case NPC_DUKE_FIRE:
                        case NPC_DUKE_WATER:
                        case NPC_DUKE_EARTH:
                        case NPC_DUKE_AIR:
                            summons->AI()->Talk(SAY_DUKE_AGGRO, player);
                            break;
                        case NPC_ROYAL_FIRE:
                        case NPC_ROYAL_AIR:
                        case NPC_ROYAL_EARTH:
                        case NPC_ROYAL_WATER:
                            summons->AI()->Talk(YELL_ROYAL_AGGRO, player);
                            break;
                    }
                    summons->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    summons->EngageWithTarget(player);
                }

            public:
                bool GossipHello(Player* player) override
                {
                    uint8 rank = GetPlayerRank(player);

                    uint32 gossipId = me->GetGOInfo()->GetGossipMenuId();
                    switch (gossipId)
                    {
                        case GOSSIP_ID_LESSER_WS:
                        {
                            if (rank >= 1) // 1 or 2 or 3
                                AddGossipItemFor(player, GOSSIP_ID_LESSER_WS, OPTION_ID_WS_RANDOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                            else
                            {
                                me->CastSpell(player, SPELL_PUNISHMENT);
                                break;
                            }

                            uint8 item = GetItems(player, TEMPLAR);
                            if (item & FIRE)
                                AddGossipItemFor(player, GOSSIP_ID_LESSER_WS, OPTION_ID_1_CRIMSON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                            if (item & WATER)
                                AddGossipItemFor(player, GOSSIP_ID_LESSER_WS, OPTION_ID_2_AZURE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                            if (item & EARTH)
                                AddGossipItemFor(player, GOSSIP_ID_LESSER_WS, OPTION_ID_3_EARTHEN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                            if (item & AIR)
                                AddGossipItemFor(player, GOSSIP_ID_LESSER_WS, OPTION_ID_4_HOARY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                            break;
                        }
                        case GOSSIP_ID_WIND_STONE:
                        {
                            if (rank >= 2) // 2 or 3
                                AddGossipItemFor(player, GOSSIP_ID_WIND_STONE, OPTION_ID_WS_RANDOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                            else
                            {
                                me->CastSpell(player, SPELL_PUNISHMENT);
                                break;
                            }

                            uint8 item = GetItems(player, DUKE);
                            if (item & FIRE)
                                AddGossipItemFor(player, GOSSIP_ID_WIND_STONE, OPTION_ID_1_CYNDERS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                            if (item & WATER)
                                AddGossipItemFor(player, GOSSIP_ID_WIND_STONE, OPTION_ID_2_FATHOMS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
                            if (item & EARTH)
                                AddGossipItemFor(player, GOSSIP_ID_WIND_STONE, OPTION_ID_3_SHARDS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
                            if (item & AIR)
                                AddGossipItemFor(player, GOSSIP_ID_WIND_STONE, OPTION_ID_4_ZEPHYRS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                            break;
                        }
                        case GOSSIP_ID_GREATER_WS:
                        {
                            if (rank == 3) // 3
                                AddGossipItemFor(player, GOSSIP_ID_GREATER_WS, OPTION_ID_WS_RANDOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                            else
                            {
                                me->CastSpell(player, SPELL_PUNISHMENT);
                                break;
                            }

                            uint8 item = GetItems(player, ROYAL);
                            if (item & FIRE)
                                AddGossipItemFor(player, GOSSIP_ID_GREATER_WS, OPTION_ID_1_SKALDRENOX, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                            if (item & WATER)
                                AddGossipItemFor(player, GOSSIP_ID_GREATER_WS, OPTION_ID_2_SKWOL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                            if (item & EARTH)
                                AddGossipItemFor(player, GOSSIP_ID_GREATER_WS, OPTION_ID_3_KAZUM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
                            if (item & AIR)
                                AddGossipItemFor(player, GOSSIP_ID_GREATER_WS, OPTION_ID_4_WHIRLAXIS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
                            break;
                        }
                        default:
                            break;
                    }

                    SendGossipMenuFor(player, player->GetGossipTextId(gossipId, me), me->GetGUID());
                    return true;
                }

                bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
                {
                    uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                    ClearGossipMenuFor(player);
                    player->PlayerTalkClass->SendCloseGossip();

                    switch (action)
                    {
                        case GOSSIP_ACTION_INFO_DEF + 1:
                            SummonNPC(me, player, RAND(NPC_TEMPLAR_WATER, NPC_TEMPLAR_FIRE, NPC_TEMPLAR_EARTH, NPC_TEMPLAR_AIR), SPELL_TEMPLAR_RANDOM);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 2:
                            SummonNPC(me, player, NPC_TEMPLAR_FIRE, SPELL_TEMPLAR_FIRE);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 3:
                            SummonNPC(me, player, NPC_TEMPLAR_WATER, SPELL_TEMPLAR_WATER);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 4:
                            SummonNPC(me, player, NPC_TEMPLAR_EARTH, SPELL_TEMPLAR_EARTH);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 5:
                            SummonNPC(me, player, NPC_TEMPLAR_AIR, SPELL_TEMPLAR_AIR);
                            break;

                        case GOSSIP_ACTION_INFO_DEF + 6:
                            SummonNPC(me, player, RAND(NPC_DUKE_FIRE, NPC_DUKE_WATER, NPC_DUKE_EARTH, NPC_DUKE_AIR), SPELL_DUKE_RANDOM);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 7:
                            SummonNPC(me, player, NPC_DUKE_FIRE, SPELL_DUKE_FIRE);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 8:
                            SummonNPC(me, player, NPC_DUKE_WATER, SPELL_DUKE_WATER);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 9:
                            SummonNPC(me, player, NPC_DUKE_EARTH, SPELL_DUKE_EARTH);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 10:
                            SummonNPC(me, player, NPC_DUKE_AIR, SPELL_DUKE_AIR);
                            break;

                        case GOSSIP_ACTION_INFO_DEF + 11:
                            SummonNPC(me, player, RAND(NPC_ROYAL_FIRE, NPC_ROYAL_AIR, NPC_ROYAL_EARTH, NPC_ROYAL_WATER), SPELL_ROYAL_RANDOM);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 12:
                            SummonNPC(me, player, NPC_ROYAL_FIRE, SPELL_ROYAL_FIRE);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 13:
                            SummonNPC(me, player, NPC_ROYAL_WATER, SPELL_ROYAL_WATER);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 14:
                            SummonNPC(me, player, NPC_ROYAL_EARTH, SPELL_ROYAL_EARTH);
                            break;
                        case GOSSIP_ACTION_INFO_DEF + 15:
                            SummonNPC(me, player, NPC_ROYAL_AIR, SPELL_ROYAL_AIR);
                            break;

                        default:
                            break;
                    }
                    return true;
                }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_wind_stoneAI(go);
        }
};

// 24745 - Summon Templar, Trigger
// 24747 - Summon Templar Fire, Trigger
// 24757 - Summon Templar Air, Trigger
// 24759 - Summon Templar Earth, Trigger
// 24761 - Summon Templar Water, Trigger
// 24762 - Summon Duke, Trigger
// 24766 - Summon Duke Fire, Trigger
// 24769 - Summon Duke Air, Trigger
// 24771 - Summon Duke Earth, Trigger
// 24773 - Summon Duke Water, Trigger
// 24785 - Summon Royal, Trigger
// 24787 - Summon Royal Fire, Trigger
// 24791 - Summon Royal Air, Trigger
// 24792 - Summon Royal Earth, Trigger
// 24793 - Summon Royal Water, Trigger
// 46595 - Summon Ice Stone Lieutenant, Trigger
class spell_silithus_summon_cultist_periodic : public AuraScript
{
    PrepareAuraScript(spell_silithus_summon_cultist_periodic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        // All these spells trigger a spell that requires reagents; if the
        // triggered spell is cast as "triggered", reagents are not consumed
        if (Unit* caster = GetCaster())
            caster->CastSpell(nullptr, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST)).SetTriggeringAura(aurEff));
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_silithus_summon_cultist_periodic::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_silithus()
{
    new go_crystalline_tear();
    new npc_anachronos_quest_trigger();
    new npc_anachronos_the_ancient();
    new npc_qiraj_war_spawn();
    new go_wind_stone();
    RegisterAuraScript(spell_silithus_summon_cultist_periodic);
}
