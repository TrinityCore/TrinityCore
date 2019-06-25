/*
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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

#include "culling_of_stratholme.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "Random.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "ScriptSystem.h"
#include "SpellScript.h"
#include "SplineChainMovementGenerator.h"
#include "TemporarySummon.h"
#include <array>
#include <unordered_map>
#include <vector>

enum Entries
{
    NPC_MALGANIS_BUNNY = 20562,
    NPC_UTHER = 26528,
    NPC_JAINA = 26497,
    NPC_CITIZEN = 28167,
    NPC_RESIDENT = 28169,
    NPC_FOOTMAN = 27745,
    NPC_KNIGHT = 27746,
    NPC_PRIEST = 27747,
    NPC_SORCERESS = 27752,
    NPC_RISEN_ZOMBIE = 27737,
    NPC_CITIZEN_INFINITE = 28340,
    NPC_RESIDENT_INFINITE = 28341,
    NPC_TIME_RIFT = 28409,
    NPC_TIME_RIFT_LARGE = 28439,
    NPC_INFINITE_ADVERSARY = 27742,
    NPC_INFINITE_HUNTER = 27743,
    NPC_INFINITE_AGENT = 27744,
    NPC_EPOCH = 26532,
    NPC_MALGANIS = 26533,
    NPC_CHROMIE_3 = 30997,

    SPELL_HOLY_LIGHT = 52444,
    SPELL_EXORCISM = 52445,
    SPELL_DEVOTION_AURA = 52442,
    SPELL_CRUSADER_STRIKE = 50773,
    SPELL_SHADOWSTEP_VISUAL = 51908,
    SPELL_TRANSFORM_VISUAL = 33133,
    SPELL_MALGANIS_QUEST_CREDIT = 58124,
    SPELL_MALGANIS_KILL_CREDIT = 58630,
    SPELL_CHROMIE_3_TRANSFORM = 58986,
    GO_CHEST_NORMAL = 190663,
    GO_CHEST_HEROIC = 193597
};

enum SplineChains
{
    // RP1: Arthas/Jaina/Uther, outside Stratholme gates
    RP1_CHAIN_ARTHAS1   = 1, // Initial movement
    RP1_CHAIN_UTHER1    = 1, // Initial movement
    RP1_CHAIN_JAINA1    = 1, // Initial movement
    RP1_CHAIN_ARTHAS2   = 2, // Arthas moves up the hill to look out over Stratholme
    RP1_CHAIN_UTHER2    = 2, // Uther follows
    RP1_CHAIN_JAINA2    = 2, // Jaina follows
    RP1_CHAIN_UTHER3    = 3, // Uther leaves
    RP1_CHAIN_JAINA3    = 3, // Jaina turns to leave, but is stopped by Arthas
    RP1_CHAIN_JAINA4    = 4, // Jaina leaves for real
    RP1_CHAIN_ARTHAS3   = 3, // Arthas moves down the hill to the bridge
    RP1_CHAIN_ARTHAS4   = 4, // Arthas moves to the Stratholme entrance

    // RP2: Arthas/Mal'ganis, at Stratholme gates
    RP2_CHAIN_ARTHAS1   = 5, // Arthas enters Stratholme proper
    RP2_CHAIN_CITIZEN1  = 1, // A Stratholme citizen greets Arthas
    RP2_CHAIN_ARTHAS2   = 6, // Arthas advances towards the approaching citizen
    RP2_CHAIN_ARTHAS3   = 7, // Arthas moves on to a nearby resident

    // RP3: Arthas/Infinites, in Stratholme Town Hall
    RP3_CHAIN_ARTHAS1   = 91, // Arthas enters Stratholme Town Hall
    RP3_CHAIN_ARTHAS2   = 92, // Arthas approaches one of the disguised Infinites
    RP3_CHAIN_ARTHAS3   = 95, // Arthas proceeds up the stairs
    RP3_CHAIN_ARTHAS3_2 = 96, // Arthas encounters more Infinite resistance
    RP3_CHAIN_ARTHAS4   = 97, // Arthas presses onward into a hallway
    RP3_CHAIN_ARTHAS5   = 98, // Arthas advances into the boss room
    RP3_CHAIN_EPOCH     = 1,  // Chrono-Lord Epoch advances out of the portal

    // Spawn motions (all on 27742, infinite adversary)
    RP3_CHAIN_SPAWN1_LOC1 = 4,
    RP3_CHAIN_SPAWN1_LOC2 = 2,
    RP3_CHAIN_SPAWN1_LOC3 = 1,
    RP3_CHAIN_SPAWN1_LOC4 = 3,
    RP3_CHAIN_SPAWN2_LOC1 = 5,
    RP3_CHAIN_SPAWN2_LOC2 = 6,
    RP3_CHAIN_SPAWN2_LOC3 = 7,
    RP3_CHAIN_SPAWN2_LOC4 = 8,
    RP3_CHAIN_SPAWN3_LOC1 = 9,
    RP3_CHAIN_SPAWN3_LOC2 = 10,
    RP3_CHAIN_SPAWN3_LOC3 = 11,
    RP3_CHAIN_SPAWN3_LOC4 = 12,

    // RP4: Arthas moving towards Gauntlet
    RP4_CHAIN_ARTHAS1   = 101, // Arthas moves up to the bookcase
    RP4_CHAIN_ARTHAS2   = 128, // Arthas advances to the start of the Gauntlet section
    RP4_CHAIN_GAUNTLET1 = 1024, // Arthas charges to the halfway point of the Gauntlet
    RP4_CHAIN_GAUNTLET2 = 1025, // Arthas continues to Market Row

    // RP5: Arthas advances on Crusader Square and faces off against Mal'ganis
    RP5_CHAIN_ARTHAS1   = 121, // Arthas moves into Crusader Square
    RP5_CHAIN_ARTHAS2   = 124, // After Mal'ganis' defeat, Arthas attempts to chase him down
    RP5_CHAIN_ARTHAS3   = 125, // Arthas departs...
    RP5_CHAIN_ARTHAS4   = 127  // ...and then finally despawns
};

enum PointIDs
{
    RP1_POINTID_UTHER1 = 1,
    RP1_POINTID_ARTHAS2,
    RP1_POINTID_UTHER2,
    RP1_POINTID_JAINA2,
    RP1_POINTID_UTHER3,
    RP1_POINTID_JAINA4,
    RP1_POINTID_ARTHAS3,
    RP1_POINTID_ARTHAS4,

    RP2_POINTID_ARTHAS1,
    RP2_POINTID_ARTHAS2,
    RP2_POINTID_ARTHAS3,

    RP3_POINTID_TOWN_HALL,
    RP3_POINTID_ARTHAS1,
    RP3_POINTID_ARTHAS2,
    RP3_POINTID_ARTHAS3,
    RP3_POINTID_ARTHAS4,
    RP3_POINTID_ARTHAS5,

    RP4_POINTID_ARTHAS1,
    RP4_POINTID_ARTHAS2,
    RP4_POINTID_GAUNTLET1,
    RP4_POINTID_GAUNTLET2,

    RP5_POINTID_ARTHAS1,
    RP5_POINTID_ARTHAS3,
    RP5_POINTID_ARTHAS4
};

enum Actions
{
    ACTION_NONE = 0,
    RP3_ACTION_AFTER_INITIAL,
    RP3_ACTION_AFTER_SPAWN1,
    RP3_ACTION_AFTER_SPAWN2,
    RP3_ACTION_AFTER_SPAWN3,
    RP3_ACTION_AFTER_EPOCH,
    RP5_ACTION_AFTER_MALGANIS
};

enum Data
{
    DATA_RP_DUMMY_MOVED
};

enum RPEvents
{
    RP1_EVENT_START1 = 1,
    RP1_EVENT_START2,
    RP1_EVENT_ARTHAS1,
    RP1_EVENT_UTHER1,
    RP1_EVENT_ARTHAS2,
    RP1_EVENT_ARTHAS3,
    RP1_EVENT_UTHER_FACE,
    RP1_EVENT_JAINA_FACE,
    RP1_EVENT_UTHER2,
    RP1_EVENT_ARTHAS4,
    RP1_EVENT_UTHER3,
    RP1_EVENT_ARTHAS_TURN,
    RP1_EVENT_ARTHAS5,
    RP1_EVENT_UTHER4,
    RP1_EVENT_ARTHAS6,
    RP1_EVENT_UTHER5,
    RP1_EVENT_ARTHAS7,
    RP1_EVENT_JAINA1,
    RP1_EVENT_ARTHAS8,
    RP1_EVENT_ARTHAS8_2,
    RP1_EVENT_UTHER6,
    RP1_EVENT_UTHER_LEAVE,
    RP1_EVENT_JAINA_LEAVE,
    RP1_EVENT_ARTHAS9,
    RP1_EVENT_JAINA2,
    RP1_EVENT_JAINA_LEAVE2,
    RP1_EVENT_ARTHAS_LEAVE,
    RP1_EVENT_ARTHAS10,
    RP1_EVENT_ARTHAS_LEAVE2,
    RP1_EVENT_FINISHED,

    RP2_EVENT_ARTHAS_MOVE_1,
    RP2_EVENT_CITIZEN1,
    RP2_EVENT_ARTHAS2,
    RP2_EVENT_ARTHAS_MOVE_2,
    RP2_EVENT_CITIZEN2,
    RP2_EVENT_KILL1,
    RP2_EVENT_ARTHAS_MOVE_3,
    RP2_EVENT_KILL2,
    RP2_EVENT_REACT1,
    RP2_EVENT_REACT2,
    RP2_EVENT_REACT3,
    RP2_EVENT_REACT4,
    RP2_EVENT_REACT5,
    RP2_EVENT_ARTHAS_MOVE_4,
    RP2_EVENT_ARTHAS3,
    RP2_EVENT_MALGANIS1,
    RP2_EVENT_TROOPS_FACE,
    RP2_EVENT_ARTHAS_FACE,
    RP2_EVENT_MALGANIS2,
    RP2_EVENT_MALGANIS_LEAVE1,
    RP2_EVENT_MALGANIS_LEAVE2,
    RP2_EVENT_ARTHAS4,
    RP2_EVENT_ARTHAS4_2,
    RP2_EVENT_ARTHAS_MOVE_5,
    RP2_EVENT_ARTHAS5,
    RP2_EVENT_ARTHAS5_2,
    RP2_EVENT_ARTHAS5_3,
    RP2_EVENT_WAVE_START,

    EVENT_TOWN_HALL_REACHED,

    RP3_EVENT_RESIDENT_FACE,
    RP3_EVENT_ARTHAS_FACE,
    RP3_EVENT_CITIZEN1,
    RP3_EVENT_ARTHAS2,
    RP3_EVENT_ARTHAS_KILL,
    RP3_EVENT_INFINITE_LAUGH,
    RP3_EVENT_ARTHAS3,
    RP3_EVENT_CITIZEN2,
    RP3_EVENT_TRANSFORM1,
    RP3_EVENT_TRANSFORM2,
    RP3_EVENT_TRANSFORM3,
    RP3_EVENT_AGGRO,
    RP3_EVENT_ARTHAS4,
    RP3_EVENT_ARTHAS_MOVE_1,
    RP3_EVENT_ARTHAS_MOVE_1_2,
    RP3_EVENT_SPAWN1,
    RP3_EVENT_SPAWN1_FACE,
    RP3_EVENT_SPAWN1_AGGRO,
    RP3_EVENT_ARTHAS11,
    RP3_EVENT_ARTHAS_MOVE_2,
    RP3_EVENT_ARTHAS20,
    RP3_EVENT_SPAWN2,
    RP3_EVENT_ARTHAS_FACE2,
    RP3_EVENT_SPAWN2_FACE,
    RP3_EVENT_SPAWN2_AGGRO,
    RP3_EVENT_ARTHAS21,
    RP3_EVENT_ARTHAS_MOVE_3,
    RP3_EVENT_SPAWN3,
    RP3_EVENT_ARTHAS30,
    RP3_EVENT_SPAWN3_FACE,
    RP3_EVENT_SPAWN3_AGGRO,
    RP3_EVENT_EPOCH_SPAWN,
    RP3_EVENT_ARTHAS31,
    RP3_EVENT_EPOCH_FACE,
    RP3_EVENT_EPOCH1,
    RP3_EVENT_ARTHAS32,
    RP3_EVENT_ARTHAS32_2,
    RP3_EVENT_EPOCH_AGGRO,

    RP4_EVENT_ARTHAS2,
    RP4_EVENT_HIDDEN_PASSAGE,
    RP4_EVENT_ARTHAS3,
    RP4_EVENT_GAUNTLET_REACHED,

    RP4_EVENT_ARTHAS_MOVE,
    RP4_EVENT_ARTHAS11,
    RP4_EVENT_ARTHAS_FACE,
    RP4_EVENT_ARTHAS12,
    RP4_EVENT_GAUNTLET_RESUME,
    RP4_EVENT_ARTHAS13,
    RP4_EVENT_GAUNTLET_DONE,

    RP5_EVENT_ARTHAS2,
    RP5_EVENT_MALGANIS1,
    RP5_EVENT_MALGANIS_DONE,
    RP5_EVENT_MALGANIS12,
    RP5_EVENT_MALGANIS_LEAVE,
    RP5_EVENT_ARTHAS10,
    RP5_EVENT_ARTHAS10_2,
    RP5_EVENT_ARTHAS11,
    RP5_EVENT_ARTHAS11_2,
    RP5_EVENT_ARTHAS_LEAVE,
    RP5_EVENT_ARTHAS_LEAVE2,
    RP5_EVENT_CHROMIE_SPAWN,
    RP5_EVENT_CHROMIE_LAND,
    RP5_EVENT_CHROMIE_TRANSFORM
};

enum RPEventLines1
{
    RP1_LINE_ARTHAS1    =  0, // Glad you could make it, Uther.
    RP1_LINE_UTHER1     =  0, // Watch your tone with me, boy. You may be the prince, but I'm still your superior as a paladin!
    RP1_LINE_ARTHAS2    =  1, // As if I could forget. Listen, Uther, there's something about the plague you should know...
    RP1_LINE_ARTHAS3    =  2, // Oh, no. We're too late. These people have all been infected! They may look fine now, but it's just a matter of time before they turn into the undead!
    RP1_LINE_UTHER2     =  1, // What?
    RP1_LINE_ARTHAS4    =  3, // This entire city must be purged.
    RP1_LINE_UTHER3     =  2, // How can you even consider that? There's got to be some other way.
    RP1_LINE_ARTHAS5    =  4, // Damn it, Uther! As your future king, I order you to purge this city!
    RP1_LINE_UTHER4     =  3, // You are not my king yet, boy! Nor would I obey that command even if you were!
    RP1_LINE_ARTHAS6    =  5, // Then I must consider this an act of treason.
    RP1_LINE_UTHER5     =  4, // Treason? Have you lost your mind, Arthas?
    RP1_LINE_ARTHAS7    =  6, // Have I? Lord Uther, by my right of succession and the sovereignty of my crown, I hereby relieve you of your command and suspend your paladins from service.
    RP1_LINE_JAINA1     =  0, // Arthas! You can't just--
    RP1_LINE_ARTHAS8    =  7, // It's done! Those of you who have the will to save this land, follow me! The rest of you... get out of my sight!
    RP1_LINE_UTHER6     =  5, // You've just crossed a terrible threshold, Arthas.
    RP1_LINE_ARTHAS9    =  8, // Jaina?
    RP1_LINE_JAINA2     =  1, // I'm sorry, Arthas. I can't watch you do this.
    RP1_LINE_ARTHAS10   =  9, // Take position here, and I will lead a small force inside Stratholme to begin the culling. We must contain and purge the infected for the sake of all of Lordaeron!
    RP1_LINE_ARTHAS11   = 40  // All officers should check in with me when their squads are ready. We'll enter Stratholme on my order.
};

enum RPEventLines2
{
    RP2_LINE_ARTHAS1    = 10, // Everyone looks ready. Remember, these people are all infected with the plague and will die soon. We must purge Stratholme to protect the remainder of Lordaeron from the Scourge. Let's go.
    RP2_LINE_CITIZEN1   =  0, // Prince Arthas, may the light be praised! Many people in the town have begun to fall seriously ill, can you help us?
    RP2_LINE_ARTHAS2    = 11, // I can only help you with a clean death.
    RP2_LINE_CITIZEN2   =  1, // What? This can't be!
    RP2_LINE_RESIDENT1  =  0, // Oh, no...
    RP2_LINE_ARTHAS3    = 12, // That was just the beginning.
    RP2_LINE_MALGANIS1  =  0, // Yes, this is the beginning. I've been waiting for you, young prince. I am Mal'Ganis.
    RP2_LINE_MALGANIS2  =  1, // As you can see, your people are now mine. I will now turn this city household by household, until the flame of life has been snuffed out... forever.
    RP2_LINE_ARTHAS4    = 13, // I won't allow it, Mal'Ganis! Better that these people die by my hand than serve as your slaves in death!
    RP2_LINE_ARTHAS5    = 14  // Mal'Ganis will send out some of his Scourge minions to interfere with us. Those of you with the strongest steel and magic shall go forth and destroy them. I will lead the rest of my forces in purging Stratholme of the infected.
};

enum RPEventLines3
{
    RP3_LINE_ARTHAS1    = 16, // Follow me, I know the way through.
    RP3_LINE_CITIZEN1   =  0, // Ah, you've finally arrived Prince Arthas. You're here just in the nick of time.
    RP3_LINE_ARTHAS2    = 17, // Yes, I'm glad I could get to you before the plague.
    RP3_LINE_ARTHAS3    = 18, // What is this sorcery?
    RP3_LINE_CITIZEN2   =  1, // There's no need for you to understand, Arthas. All you need to do is die.
    RP3_LINE_ARTHAS4    = 19, // Mal'Ganis appears to have more than Scourge in his arsenal. We should make haste.

    RP3_LINE_ARTHAS10   = 20, // More vile sorcery! Be ready for anything!
    RP3_LINE_ARTHAS11   = 21, // Let's move on.

    RP3_LINE_ARTHAS20   = 22, // Watch your backs: they have us surrounded in this hall.
    RP3_LINE_ARTHAS21   = 24, // Mal'ganis is not making this easy.

    RP3_LINE_ARTHAS30   = 25, // They're very persistent.
    RP3_LINE_ARTHAS31   = 26, // What else can he put in my way?
    RP3_LINE_EPOCH1     =  0, // Prince Arthas Menethil, on this day, a powerful darkness has taken hold of your soul. The death you are destined to visit upon others will this day be your own.
    RP3_LINE_ARTHAS32   = 27, // I do what I must for Lordaeron, and neither your words nor your actions will stop me.
    RP3_LINE_EPOCH2     =  1  // We'll see about that, young prince.
};

enum RPEventLines4
{
    RP4_LINE_ARTHAS1    = 28, // The quickest path to Mal'Ganis lies behind that bookshelf ahead.
    RP4_LINE_ARTHAS2    = 29, // This will only take a moment.
    RP4_LINE_ARTHAS3    = 30, // I'm relieved this secret passage still works.

    RP4_LINE_ARTHAS10   = 31, // Let's move through here as quickly as possible. If the undead don't kill us, the fires might.
    RP4_LINE_ARTHAS11   = 32, // Rest a moment and clear your lungs, but we must move again soon.
    RP4_LINE_ARTHAS12   = 33, // That's enough; we must move again. Mal'Ganis awaits.
    RP4_LINE_ARTHAS13   = 34  // At last some good luck. Market Row has not caught fire yet. Mal'Ganis is supposed to be in Crusaders' Square, which is just ahead. Tell me when you're ready to move forward.
};

enum RPEventLines5
{
    RP5_LINE_ARTHAS1    = 35, // Justice will be done.
    RP5_LINE_ARTHAS2    = 36, // We're going to finish this right now, Mal'Ganis. Just you... and me.
    RP5_LINE_MALGANIS1  =  2, // This will be a fine test, Prince Arthas.
    RP5_LINE_MALGANIS12 = 10, // Your journey has just begun, young prince. Gather your forces and meet me in the arctic land of Northrend. It is there that we shall settle the score between us. It is there that your true destiny will unfold.
    RP5_LINE_ARTHAS10   = 37, // I'll hunt you to the ends of the earth if I have to! Do you hear me? To the ends of the earth!
    RP5_LINE_ARTHAS11   = 38, // You performed well this day. Anything that Mal'Ganis has left behind is yours. Take it as your reward. I must now begin plans for an expedition to Northrend.
    RP5_LINE_CHROMIE0   =  0  // Why, hello again!
};

enum PositionIndices : uint32
{
    // Arthas/Uther RP
    RP1_ARTHAS_INITIAL = 0,
    RP1_UTHER_SPAWN,
    RP1_JAINA_SPAWN,

    // Arthas/Mal'ganis RP
    ARTHAS_PURGE_PENDING_POS,
    ARTHAS_WAVES_POS,
    RP2_PRIEST1_POS,
    RP2_PRIEST2_POS,
    RP2_FOOT1_POS,
    RP2_FOOT2_POS,
    RP2_FOOT3_POS,
    RP2_FOOT4_POS,
    RP2_MALGANIS_POS,

    // Town Hall
    ARTHAS_TOWN_HALL_POS,
    RP3_SPAWN1_LOC1,
    RP3_SPAWN1_LOC2,
    RP3_SPAWN1_LOC3,
    RP3_SPAWN1_LOC4,
    RP3_SPAWN1_RIFT,
    RP3_SPAWN2_LOC1,
    RP3_SPAWN2_LOC2,
    RP3_SPAWN2_LOC3,
    RP3_SPAWN2_LOC4,
    RP3_SPAWN2_RIFT1,
    RP3_SPAWN2_RIFT2,
    RP3_SPAWN3_LOC1,
    RP3_SPAWN3_LOC2,
    RP3_SPAWN3_LOC3,
    RP3_SPAWN3_LOC4,
    RP3_SPAWN3_RIFT1,
    RP3_SPAWN3_RIFT2,
    RP3_EPOCH_SPAWN,
    RP3_EPOCH_RIFT,
    ARTHAS_TOWN_HALL_END_POS,

    ARTHAS_GAUNTLET_POS,
    ARTHAS_GAUNTLET_END_POS,

    RP5_MALGANIS_POS,
    ARTHAS_FINAL_POS,
    RP5_CHROMIE_SPAWN,

    // Array element count
    NUM_POSITIONS,
};

enum OtherLines
{
    LINE_TOWN_HALL_PENDING = 15,
    LINE_SLAY_ZOMBIE       = 39
};

// @todo sniff
// All kinds of positions Arthas needs for RP events (there are a lot of these)
static std::array<Position, NUM_POSITIONS> const ArthasPositions =
{
    {
        { 1983.857f, 1287.043f, 145.5596f, 3.0892330f }, // RP1_ARTHAS_INITIAL
        { 1783.843f, 1267.481f, 139.7800f, 0.2698664f }, // RP1_UTHER_SPAWN
        { 1876.788f, 1305.723f, 146.2474f, 6.0737460f }, // RP1_JAINA_SPAWN

        { 2047.948f, 1287.598f, 142.8568f, 3.176499f }, // ARTHAS_PURGE_PENDING_POS
        { 2091.994f, 1277.257f, 140.4707f, 1.134464f }, // ARTHAS_WAVES_POS // @todo
        { 2074.624f, 1282.958f, 141.6344f }, // RP2_PRIEST1_POS
        { 2074.805f, 1292.172f, 141.6728f }, // RP2_PRIEST2_POS
        { 2077.590f, 1284.609f, 141.5710f }, // RP2_FOOT1_POS
        { 2078.365f, 1281.254f, 141.5182f }, // RP2_FOOT2_POS
        { 2077.737f, 1290.441f, 141.5698f }, // RP2_FOOT3_POS
        { 2078.055f, 1293.624f, 141.5544f }, // RP2_FOOT4_POS
        { 2113.454f, 1287.986f, 136.3829f, 3.071779f }, // RP2_MALGANIS_POS

        { 2366.240f, 1195.253f, 132.0441f, 3.159046f }, // ARTHAS_TOWN_HALL_POS
        { 2433.154f, 1192.572f, 148.1547f, 5.542059f }, // RP3_SPAWN1_LOC1
        { 2432.990f, 1192.760f, 148.1474f, 1.026526f }, // RP3_SPAWN1_LOC2
        { 2432.824f, 1191.816f, 148.1556f, 4.927707f }, // RP3_SPAWN1_LOC3
        { 2432.711f, 1192.857f, 148.1550f, 6.257423f }, // RP3_SPAWN1_LOC4
        { 2433.357f, 1192.168f, 148.1593f, 3.001966f }, // RP3_SPAWN1_RIFT_SPAWN
        { 2414.349f, 1136.075f, 148.1592f, 1.345922f }, // RP3_SPAWN2_LOC1
        { 2403.961f, 1180.299f, 148.1587f, 5.139339f }, // RP3_SPAWN2_LOC2
        { 2414.671f, 1136.262f, 148.1592f, 2.305776f }, // RP3_SPAWN2_LOC3
        { 2403.908f, 1179.994f, 148.1586f, 4.654133f }, // RP3_SPAWN2_LOC4
        { 2404.311f, 1178.306f, 148.1585f, 1.605703f }, // RP3_SPAWN2_RIFT1
        { 2414.041f, 1136.068f, 148.1593f, 2.234021f }, // RP3_SPAWN2_RIFT2
        { 2429.026f, 1102.693f, 148.1499f, 1.952652f }, // RP3_SPAWN3_LOC1
        { 2441.173f, 1115.225f, 148.1264f, 2.302970f }, // RP3_SPAWN3_LOC2
        { 2430.645f, 1104.685f, 148.1306f, 1.135255f }, // RP3_SPAWN3_LOC3
        { 2439.649f, 1113.719f, 148.1298f, 3.111888f }, // RP3_SPAWN3_LOC4
        { 2429.296f, 1102.007f, 148.1593f, 6.213372f }, // RP3_SPAWN3_RIFT1
        { 2440.057f, 1114.226f, 148.1593f, 6.108652f }, // RP3_SPAWN3_RIFT2
        { 2457.008f, 1113.929f, 150.0776f, 3.272437f }, // RP3_EPOCH_SPAWN
        { 2456.058f, 1113.838f, 150.0917f, 1.745329f }, // RP3_EPOCH_RIFT
        { 2425.898f, 1118.842f, 148.0759f, 6.073746f }, // ARTHAS_TOWN_HALL_END_POS

        { 2534.988f, 1126.163f, 130.8621f, 2.844887f }, // ARTHAS_GAUNTLET_POS
        { 2363.440f, 1404.906f, 128.7869f, 2.775074f }, // ARTHAS_GAUNTLET_END_POS

        { 2296.862f, 1501.015f, 128.4456f, 5.131268f }, // RP5_MALGANIS_POS
        { 2301.055f, 1478.977f, 128.1299f, 1.758816f }, // ARTHAS_FINAL_POS
        { 2319.560f, 1506.408f, 152.0474f }, // RP5_CHROMIE_SPAWN
    }
};

uint32 const chromiePathSize = 3;
G3D::Vector3 const ChromieSplinePos[chromiePathSize] =
{
    { 2320.632f, 1507.193f, 152.5081f },
    { 2319.823f, 1506.605f, 152.5081f },
    { 2306.770f, 1496.780f, 128.3620f }
};

static float const ArthasSnapbackDistanceThreshold = 5.0f; // how far we can be from where we're supposed at start of phase to be before we snap back

struct SnapbackInfo
{
    ReactStates const ReactState;
    bool const HasGossip;
    Position const* const SnapbackPosition;
};

// Positions Arthas should be at when starting a given phase
static std::unordered_map<uint32, SnapbackInfo> const ArthasSnapbackPositions =
{
    { JUST_STARTED,         { REACT_PASSIVE,    false, &ArthasPositions[RP1_ARTHAS_INITIAL] } },
    { CRATES_IN_PROGRESS,   { REACT_PASSIVE,    false, &ArthasPositions[RP1_ARTHAS_INITIAL] } },
    { CRATES_DONE,          { REACT_PASSIVE,    false, &ArthasPositions[RP1_ARTHAS_INITIAL] } },
    { UTHER_TALK,           { REACT_PASSIVE,    false, &ArthasPositions[RP1_ARTHAS_INITIAL] } },
    { PURGE_PENDING,        { REACT_PASSIVE,    true,  &ArthasPositions[ARTHAS_PURGE_PENDING_POS] } },
    { PURGE_STARTING,       { REACT_PASSIVE,    false, &ArthasPositions[ARTHAS_PURGE_PENDING_POS] } },
    { WAVES_IN_PROGRESS,    { REACT_AGGRESSIVE, false, &ArthasPositions[ARTHAS_WAVES_POS] } },
    { WAVES_DONE,           { REACT_DEFENSIVE,  false, &ArthasPositions[ARTHAS_WAVES_POS] } },
    { TOWN_HALL_PENDING,    { REACT_DEFENSIVE,  true,  &ArthasPositions[ARTHAS_TOWN_HALL_POS] } },
    { TOWN_HALL,            { REACT_DEFENSIVE,  false, &ArthasPositions[ARTHAS_TOWN_HALL_POS] } },
    { TOWN_HALL_COMPLETE,   { REACT_PASSIVE,    true,  &ArthasPositions[ARTHAS_TOWN_HALL_END_POS] } },
    { GAUNTLET_TRANSITION,  { REACT_PASSIVE,    false, &ArthasPositions[ARTHAS_TOWN_HALL_END_POS] } },
    { GAUNTLET_PENDING,     { REACT_PASSIVE,    true,  &ArthasPositions[ARTHAS_GAUNTLET_POS] } },
    { GAUNTLET_IN_PROGRESS, { REACT_DEFENSIVE,  false, &ArthasPositions[ARTHAS_GAUNTLET_POS] } },
    { GAUNTLET_COMPLETE,    { REACT_PASSIVE,    true,  &ArthasPositions[ARTHAS_GAUNTLET_END_POS] } },
    { MALGANIS_IN_PROGRESS, { REACT_DEFENSIVE,  false, &ArthasPositions[ARTHAS_GAUNTLET_END_POS] } },
    { COMPLETE,             { REACT_PASSIVE,    false, &ArthasPositions[ARTHAS_FINAL_POS] } }
};

class npc_arthas_stratholme : public CreatureScript
{
public:
    npc_arthas_stratholme() : CreatureScript("npc_arthas_stratholme") { }

    struct npc_arthas_stratholmeAI : public ScriptedAI
    {
        npc_arthas_stratholmeAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()), _exorcismCooldown(urandms(7, 14)), _progressRP(true), _afterCombat(ACTION_NONE) { }

        inline COSProgressStates GetCurrentProgress()
        {
            return COSProgressStates(instance->GetData(DATA_INSTANCE_PROGRESS));
        }

        void AdvanceToState(COSProgressStates newState)
        {
            if (!_progressRP)
                _progressRP = true;

            auto itr = ArthasSnapbackPositions.find(newState);
            if (itr != ArthasSnapbackPositions.end())
            {
                SnapbackInfo const& target = itr->second;

                // Adjust react state and npc flags based on current state
                me->SetReactState(target.ReactState);
                if (target.ReactState == REACT_PASSIVE)
                    me->SetImmuneToAll(true, false);
                else
                    me->SetImmuneToAll(false);

                // Adjust gossip flag based on whether we have a gossip menu or not
                if (target.HasGossip)
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                else
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                // Snapback handling - if we're too far from where we're supposed to be, teleport there
                if (target.SnapbackPosition->GetExactDist(me) > ArthasSnapbackDistanceThreshold)
                    me->NearTeleportTo(*target.SnapbackPosition);
            }

            switch (newState)
            {
                case WAVES_DONE:
                    events.ScheduleEvent(EVENT_TOWN_HALL_REACHED, 3s);
                    break;
                case UTHER_TALK:
                    if (Creature* uther = me->SummonCreature(NPC_UTHER, ArthasPositions[RP1_UTHER_SPAWN], TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        uther->setActive(true);
                        uther->GetMotionMaster()->MoveAlongSplineChain(RP1_POINTID_UTHER1, RP1_CHAIN_UTHER1, false);
                    }
                    if (Creature* jaina = me->SummonCreature(NPC_JAINA, ArthasPositions[RP1_JAINA_SPAWN], TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        jaina->setActive(true);
                        jaina->GetMotionMaster()->MoveAlongSplineChain(0, RP1_CHAIN_JAINA1, true);
                    }
                    me->GetMotionMaster()->MoveAlongSplineChain(0, RP1_CHAIN_ARTHAS1, false);
                    break;
                case TOWN_HALL_PENDING:
                    Talk(LINE_TOWN_HALL_PENDING);
                    break;
                case COMPLETE:
                    if (events.Empty())
                    {
                        // This must be instance loading into COMPLETE state, spawn chromie
                        events.ScheduleEvent(RP5_EVENT_CHROMIE_SPAWN, 1s);
                        events.ScheduleEvent(RP5_EVENT_CHROMIE_LAND, 12s + 668ms);
                        events.ScheduleEvent(RP5_EVENT_CHROMIE_TRANSFORM, 15s + 491ms);
                        me->SetVisible(false);
                    }
                    break;
                default:
                    break;
            }
        }

        // Will happen immediately (if OOC) or on reached home (if IC)
        void ScheduleActionOOC(Actions action)
        {
            if (_progressRP)
                DoAction(action);
            else
                _afterCombat = action;
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case -ACTION_PROGRESS_UPDATE:
                    AdvanceToState(GetCurrentProgress());
                    break;
                case RP3_ACTION_AFTER_INITIAL:
                    events.ScheduleEvent(RP3_EVENT_ARTHAS4, 1s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS_MOVE_1, 7s);
                    break;
                case RP3_ACTION_AFTER_SPAWN1:
                    events.ScheduleEvent(RP3_EVENT_ARTHAS11, 1s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS_MOVE_2, 3s);
                    break;
                case RP3_ACTION_AFTER_SPAWN2:
                    events.ScheduleEvent(RP3_EVENT_ARTHAS21, 1s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS_MOVE_3, 4s);
                    break;
                case RP3_ACTION_AFTER_SPAWN3:
                    events.ScheduleEvent(RP3_EVENT_EPOCH_SPAWN, 3s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS31, 4s);
                    events.ScheduleEvent(RP3_EVENT_EPOCH_FACE, 6s);
                    events.ScheduleEvent(RP3_EVENT_EPOCH1, 9s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS32, 22s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS32_2, 27s);
                    events.ScheduleEvent(RP3_EVENT_EPOCH_AGGRO, 30s);
                    break;
                case RP3_ACTION_AFTER_EPOCH:
                    instance->SetData(DATA_TOWN_HALL_DONE, 1);
                    break;
                case RP5_ACTION_AFTER_MALGANIS:
                    events.ScheduleEvent(RP5_EVENT_MALGANIS_DONE, 3s);
                    break;
                default:
                    break;
            }
        }

        void SetGUID(ObjectGuid const& guid, int32 type) override
        {
            _eventStarterGuid = guid;

            Unit* talkTarget = ObjectAccessor::GetUnit(*me, _eventStarterGuid);
            switch (type)
            {
                case -ACTION_START_RP_EVENT2:
                    Talk(RP2_LINE_ARTHAS1, talkTarget);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS_MOVE_1, Seconds(9));
                    break;
                case -ACTION_START_RP_EVENT3:
                    Talk(RP3_LINE_ARTHAS1, talkTarget);
                    me->GetMotionMaster()->MoveAlongSplineChain(RP3_POINTID_ARTHAS1, RP3_CHAIN_ARTHAS1, false);
                    break;
                case -ACTION_START_RP_EVENT4_1:
                    Talk(RP4_LINE_ARTHAS1, talkTarget);
                    me->GetMotionMaster()->MoveAlongSplineChain(RP4_POINTID_ARTHAS1, RP4_CHAIN_ARTHAS1, true);
                    break;
                case -ACTION_START_RP_EVENT4_2:
                    Talk(RP4_LINE_ARTHAS10, talkTarget);
                    events.ScheduleEvent(RP4_EVENT_ARTHAS_MOVE, Seconds(5));
                    break;
                case -ACTION_START_RP_EVENT5:
                    Talk(RP5_LINE_ARTHAS1, talkTarget);
                    instance->instance->SummonCreature(NPC_MALGANIS, ArthasPositions[RP5_MALGANIS_POS]);
                    me->GetMotionMaster()->MoveAlongSplineChain(RP5_POINTID_ARTHAS1, RP5_CHAIN_ARTHAS1, false);
                    break;
                default:
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (!_progressRP)
                return;
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE && type != SPLINE_CHAIN_MOTION_TYPE)
                return;
            switch (id)
            {
                case RP1_POINTID_UTHER1:
                    events.ScheduleEvent(RP1_EVENT_START1, 0s);
                    events.ScheduleEvent(RP1_EVENT_START2, 1s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS1, 4s);
                    events.ScheduleEvent(RP1_EVENT_UTHER1, 8s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS2, 15s);
                    break;
                case RP1_POINTID_UTHER2:
                    events.ScheduleEvent(RP1_EVENT_UTHER_FACE, 0s);
                    break;
                case RP1_POINTID_JAINA2:
                    events.ScheduleEvent(RP1_EVENT_JAINA_FACE, 0s);
                    break;
                case RP1_POINTID_ARTHAS2:
                    events.ScheduleEvent(RP1_EVENT_ARTHAS3, 1s);
                    events.ScheduleEvent(RP1_EVENT_UTHER2, 12s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS_TURN, 13s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS4, 14s);
                    events.ScheduleEvent(RP1_EVENT_UTHER3, 18s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS5, 24s);
                    events.ScheduleEvent(RP1_EVENT_UTHER4, 30s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS6, 36s);
                    events.ScheduleEvent(RP1_EVENT_UTHER5, 39s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS7, 44s);
                    events.ScheduleEvent(RP1_EVENT_JAINA1, 57s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS8, 59s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS8_2, 65s);
                    events.ScheduleEvent(RP1_EVENT_UTHER6, 71s);
                    events.ScheduleEvent(RP1_EVENT_UTHER_LEAVE, 74s);
                    events.ScheduleEvent(RP1_EVENT_JAINA_LEAVE, 75s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS9, 76s);
                    events.ScheduleEvent(RP1_EVENT_JAINA2, 78s);
                    events.ScheduleEvent(RP1_EVENT_JAINA_LEAVE2, 82s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS_LEAVE, 88s);
                    break;
                case RP1_POINTID_UTHER3:
                    if (Creature* uther = me->FindNearestCreature(NPC_UTHER, 500.0f, true))
                        uther->DespawnOrUnsummon();
                    break;
                case RP1_POINTID_JAINA4:
                    if (Creature* jaina = me->FindNearestCreature(NPC_JAINA, 500.0f, true))
                        jaina->DespawnOrUnsummon();
                    break;
                case RP1_POINTID_ARTHAS3:
                    events.ScheduleEvent(RP1_EVENT_ARTHAS10, 0s);
                    events.ScheduleEvent(RP1_EVENT_ARTHAS_LEAVE2, 12s);
                    break;
                case RP1_POINTID_ARTHAS4:
                    events.ScheduleEvent(RP1_EVENT_FINISHED, 0s);
                    break;
                case RP2_POINTID_ARTHAS1:
                    if (Creature* citizen = me->FindNearestCreature(NPC_CITIZEN, 100.0f, true))
                        citizen->SetFacingToObject(me);
                    if (Creature* resident = me->FindNearestCreature(NPC_RESIDENT, 100.0f, true))
                        resident->SetFacingToObject(me);
                    events.ScheduleEvent(RP2_EVENT_CITIZEN1, 2s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS2, 10s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS_MOVE_2, 11s);
                    break;
                case RP2_POINTID_ARTHAS2:
                    events.ScheduleEvent(RP2_EVENT_CITIZEN2, 0s);
                    events.ScheduleEvent(RP2_EVENT_KILL1, 1s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS_MOVE_3, 3s);
                    break;
                case RP2_POINTID_ARTHAS3:
                    events.ScheduleEvent(RP2_EVENT_KILL2, 1s);
                    events.ScheduleEvent(RP2_EVENT_REACT1, 2s);
                    events.ScheduleEvent(RP2_EVENT_REACT2, 3s);
                    events.ScheduleEvent(RP2_EVENT_REACT3, 4s);
                    events.ScheduleEvent(RP2_EVENT_REACT4, 6s);
                    events.ScheduleEvent(RP2_EVENT_REACT5, 6s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS_MOVE_4, 4s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS3, 6s);
                    events.ScheduleEvent(RP2_EVENT_MALGANIS1, 10s);
                    events.ScheduleEvent(RP2_EVENT_TROOPS_FACE, 11s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS_FACE, 13s);
                    events.ScheduleEvent(RP2_EVENT_MALGANIS2, 22s);
                    events.ScheduleEvent(RP2_EVENT_MALGANIS_LEAVE1, 34s);
                    events.ScheduleEvent(RP2_EVENT_MALGANIS_LEAVE2, 35s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS4, 35s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS4_2, 39s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS_MOVE_5, 45s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS5, 45s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS5_2, 51s);
                    events.ScheduleEvent(RP2_EVENT_ARTHAS5_3, 57s);
                    events.ScheduleEvent(RP2_EVENT_WAVE_START, 64s);
                    break;
                case RP3_POINTID_ARTHAS1:
                {
                    std::list<Creature*> infinites;
                    me->GetCreatureListWithEntryInGrid(infinites, NPC_CITIZEN_INFINITE, 100.0f);
                    for (Creature* infinite : infinites)
                        infinite->SetFacingToObject(me);
                    events.ScheduleEvent(RP3_EVENT_RESIDENT_FACE, 1s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS_FACE, 2s);
                    events.ScheduleEvent(RP3_EVENT_CITIZEN1, 3s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS2, 12s);
                    break;
                }
                case RP3_POINTID_ARTHAS2:
                    events.ScheduleEvent(RP3_EVENT_ARTHAS_KILL, 1s);
                    events.ScheduleEvent(RP3_EVENT_INFINITE_LAUGH, 2s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS3, 6s);
                    events.ScheduleEvent(RP3_EVENT_CITIZEN2, 8s);
                    events.ScheduleEvent(RP3_EVENT_TRANSFORM1, 10s);
                    events.ScheduleEvent(RP3_EVENT_TRANSFORM2, 12s);
                    events.ScheduleEvent(RP3_EVENT_TRANSFORM3, 14s);
                    events.ScheduleEvent(RP3_EVENT_AGGRO, 15s);
                    break;
                case RP3_POINTID_ARTHAS3:
                    events.ScheduleEvent(RP3_EVENT_ARTHAS_MOVE_1_2, 1s);
                    events.ScheduleEvent(RP3_EVENT_SPAWN1, 2s);
                    events.ScheduleEvent(RP3_EVENT_SPAWN1_FACE, 5s);
                    events.ScheduleEvent(RP3_EVENT_SPAWN1_AGGRO, 7s);
                    break;
                case RP3_POINTID_ARTHAS4:
                    events.ScheduleEvent(RP3_EVENT_ARTHAS20, 1s);
                    events.ScheduleEvent(RP3_EVENT_SPAWN2, 2s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS_FACE2, 3s);
                    events.ScheduleEvent(RP3_EVENT_SPAWN2_FACE, 4s);
                    events.ScheduleEvent(RP3_EVENT_SPAWN2_AGGRO, 6s);
                    break;
                case RP3_POINTID_ARTHAS5:
                    events.ScheduleEvent(RP3_EVENT_SPAWN3, 2s);
                    events.ScheduleEvent(RP3_EVENT_ARTHAS30, 4s);
                    events.ScheduleEvent(RP3_EVENT_SPAWN3_FACE, 5s);
                    events.ScheduleEvent(RP3_EVENT_SPAWN3_AGGRO, 6s);
                    break;
                case RP4_POINTID_ARTHAS1:
                    events.ScheduleEvent(RP4_EVENT_ARTHAS2, 1s);
                    events.ScheduleEvent(RP4_EVENT_HIDDEN_PASSAGE, 4s); // @todo sniff timer
                    events.ScheduleEvent(RP4_EVENT_ARTHAS3, 5s);
                    break;
                case RP4_POINTID_ARTHAS2:
                    events.ScheduleEvent(RP4_EVENT_GAUNTLET_REACHED, 1s);
                    break;
                case RP4_POINTID_GAUNTLET1:
                    events.ScheduleEvent(RP4_EVENT_ARTHAS11, 1s);
                    events.ScheduleEvent(RP4_EVENT_ARTHAS_FACE, 5s);
                    events.ScheduleEvent(RP4_EVENT_ARTHAS12, 21s);
                    events.ScheduleEvent(RP4_EVENT_GAUNTLET_RESUME, 25s);
                    break;
                case RP4_POINTID_GAUNTLET2:
                    events.ScheduleEvent(RP4_EVENT_ARTHAS13, 1s);
                    events.ScheduleEvent(RP4_EVENT_GAUNTLET_DONE, 7s);
                    break;
                case RP5_POINTID_ARTHAS1:
                    events.ScheduleEvent(RP5_EVENT_ARTHAS2, 1s);
                    events.ScheduleEvent(RP5_EVENT_MALGANIS1, 6s);
                    break;
                case RP5_POINTID_ARTHAS3:
                    events.ScheduleEvent(RP5_EVENT_ARTHAS_LEAVE2, 0s);
                    break;
                case RP5_POINTID_ARTHAS4:
                    me->NearTeleportTo(ArthasPositions[ARTHAS_FINAL_POS]);
                    break;
                default:
                    break;
            }
        }

        bool CanAIAttack(Unit const* who) const override
        {
            if (me->HasReactState(REACT_AGGRESSIVE))
            {
                Position const& relativePos = me->IsEngaged() ? me->GetHomePosition() : me->GetPosition();
                // Don't let us chase too far from home
                if (relativePos.GetExactDist2d(who) > 30.0f)
                    return false;
            }
            return ScriptedAI::CanAIAttack(who);
        }

        void UpdateAICombat(uint32 diff)
        {
            if (me->HasReactState(REACT_PASSIVE))
                return;

            if (!UpdateVictim())
                return;

            if (HealthBelowPct(40))
                DoCastSelf(SPELL_HOLY_LIGHT);
            if (_exorcismCooldown <= diff)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    _exorcismCooldown = 0;
                else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(target, SPELL_EXORCISM);
                    _exorcismCooldown = urandms(7, 14);
                }
            }
            else
                _exorcismCooldown -= diff;

            DoMeleeAttackIfReady();
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->IsEngaged())
            {
                UpdateAICombat(diff);
                return;
            }

            // EventMap is only used for RP handling. RP events are paused while in combat or leashing back to resume pos
            if (!_progressRP)
                return;

            events.Update(diff);
            while (uint32 event = events.ExecuteEvent())
            {
                uint32 talkerEntry = UINT_MAX, talkerLine = 0;
                switch (event)
                {
                    case RP1_EVENT_START1:
                        if (Creature* jaina = me->FindNearestCreature(NPC_JAINA, 100.0f, true))
                            jaina->SetFacingToObject(me);
                        break;
                    case RP1_EVENT_START2:
                        if (Creature* uther = me->FindNearestCreature(NPC_UTHER, 100.0f, true))
                        {
                            uther->SetFacingToObject(me);
                            me->SetFacingToObject(uther);
                        }
                        break;
                    case RP1_EVENT_ARTHAS1:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS1;
                        break;
                    case RP1_EVENT_UTHER1:
                        talkerEntry = NPC_UTHER, talkerLine = RP1_LINE_UTHER1;
                        break;
                    case RP1_EVENT_ARTHAS2:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS2;
                        me->GetMotionMaster()->MoveAlongSplineChain(RP1_POINTID_ARTHAS2, RP1_CHAIN_ARTHAS2, true);
                        if (Creature* uther = me->FindNearestCreature(NPC_UTHER, 100.0f, true))
                            uther->GetMotionMaster()->MoveAlongSplineChain(RP1_POINTID_UTHER2, RP1_CHAIN_UTHER2, true);
                        if (Creature* jaina = me->FindNearestCreature(NPC_JAINA, 100.0f, true))
                            jaina->GetMotionMaster()->MoveAlongSplineChain(RP1_POINTID_JAINA2, RP1_CHAIN_JAINA2, true);
                        break;
                    case RP1_EVENT_UTHER_FACE:
                        if (Creature* uther = me->FindNearestCreature(NPC_UTHER, 100.0f, true))
                            uther->SetFacingToObject(me);
                        break;
                    case RP1_EVENT_JAINA_FACE:
                        if (Creature* jaina = me->FindNearestCreature(NPC_JAINA, 100.0f, true))
                            jaina->SetFacingToObject(me);
                        break;
                    case RP1_EVENT_ARTHAS3:
                    {
                        me->SetFacingTo(6.248279f); // @todo migrate
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS3;
                        std::list<Creature*> troops;
                        me->GetCreatureListWithEntryInGrid(troops, NPC_FOOTMAN, 100.0f);
                        me->GetCreatureListWithEntryInGrid(troops, NPC_SORCERESS, 100.0f);
                        me->GetCreatureListWithEntryInGrid(troops, NPC_KNIGHT, 100.0f);
                        me->GetCreatureListWithEntryInGrid(troops, NPC_PRIEST, 100.0f);
                        for (Creature* unit : troops)
                            if (unit->IsAlive())
                                unit->SetFacingToObject(me);
                        break;
                    }
                    case RP1_EVENT_UTHER2:
                        talkerEntry = NPC_UTHER, talkerLine = RP1_LINE_UTHER2;
                        break;
                    case RP1_EVENT_ARTHAS4:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS4;
                        break;
                    case RP1_EVENT_UTHER3:
                        talkerEntry = NPC_UTHER, talkerLine = RP1_LINE_UTHER3;
                        break;
                    case RP1_EVENT_ARTHAS_TURN:
                        if (Creature* uther = me->FindNearestCreature(NPC_UTHER, 100.0f, true))
                            me->SetFacingToObject(uther);
                        break;
                    case RP1_EVENT_ARTHAS5:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS5;
                        break;
                    case RP1_EVENT_UTHER4:
                        talkerEntry = NPC_UTHER, talkerLine = RP1_LINE_UTHER4;
                        break;
                    case RP1_EVENT_ARTHAS6:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS6;
                        break;
                    case RP1_EVENT_UTHER5:
                        talkerEntry = NPC_UTHER, talkerLine = RP1_LINE_UTHER5;
                        break;
                    case RP1_EVENT_ARTHAS7:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS7;
                        break;
                    case RP1_EVENT_JAINA1:
                        talkerEntry = NPC_JAINA, talkerLine = RP1_LINE_JAINA1;
                        break;
                    case RP1_EVENT_ARTHAS8:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS8;
                        break;
                    case RP1_EVENT_ARTHAS8_2:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                        break;
                    case RP1_EVENT_UTHER6:
                        talkerEntry = NPC_UTHER, talkerLine = RP1_LINE_UTHER6;
                        break;
                    case RP1_EVENT_UTHER_LEAVE:
                        if (Creature* uther = me->FindNearestCreature(NPC_UTHER, 100.0f, true))
                            uther->GetMotionMaster()->MoveAlongSplineChain(RP1_POINTID_UTHER3, RP1_CHAIN_UTHER3, true);
                        break;
                    case RP1_EVENT_JAINA_LEAVE:
                        if (Creature* jaina = me->FindNearestCreature(NPC_JAINA, 100.0f, true))
                            jaina->GetMotionMaster()->MoveAlongSplineChain(0, RP1_CHAIN_JAINA3, true);
                        break;
                    case RP1_EVENT_ARTHAS9:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS9;
                        if (Creature* jaina = me->FindNearestCreature(NPC_JAINA, 100.0f, true))
                            me->SetFacingToObject(jaina);
                        break;
                    case RP1_EVENT_JAINA2:
                        talkerEntry = NPC_JAINA, talkerLine = RP1_LINE_JAINA2;
                        break;
                    case RP1_EVENT_JAINA_LEAVE2:
                        if (Creature* jaina = me->FindNearestCreature(NPC_JAINA, 100.0f, true))
                            jaina->GetMotionMaster()->MoveAlongSplineChain(RP1_POINTID_JAINA4, RP1_CHAIN_JAINA4, true);
                        break;
                    case RP1_EVENT_ARTHAS_LEAVE:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP1_POINTID_ARTHAS3, RP1_CHAIN_ARTHAS3, true);
                        break;
                    case RP1_EVENT_ARTHAS10:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS10;
                        me->SetFacingTo(3.141593f); // @todo migrate
                        break;
                    case RP1_EVENT_ARTHAS_LEAVE2:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP1_POINTID_ARTHAS4, RP1_CHAIN_ARTHAS4, false);
                        break;
                    case RP1_EVENT_FINISHED:
                        talkerEntry = 0, talkerLine = RP1_LINE_ARTHAS11;
                        me->SetFacingTo(ArthasPositions[ARTHAS_PURGE_PENDING_POS].GetOrientation());
                        instance->SetData(DATA_UTHER_FINISHED, 1);
                        break;
                    case RP2_EVENT_ARTHAS_MOVE_1:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP2_POINTID_ARTHAS1, RP2_CHAIN_ARTHAS1, true);
                        break;
                    case RP2_EVENT_CITIZEN1:
                        if (Creature* citizen = me->FindNearestCreature(NPC_CITIZEN, 100.0f, true))
                        {
                            citizen->GetMotionMaster()->MoveAlongSplineChain(0, RP2_CHAIN_CITIZEN1, true);
                            citizen->AI()->Talk(RP2_LINE_CITIZEN1, ObjectAccessor::GetUnit(*me, _eventStarterGuid));
                        }
                        break;
                    case RP2_EVENT_ARTHAS2:
                        talkerEntry = 0, talkerLine = RP2_LINE_ARTHAS2;
                        break;
                    case RP2_EVENT_ARTHAS_MOVE_2:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP2_POINTID_ARTHAS2, RP2_CHAIN_ARTHAS2, true);
                        break;
                    case RP2_EVENT_CITIZEN2:
                        talkerEntry = NPC_CITIZEN, talkerLine = RP2_LINE_CITIZEN2;
                        break;
                    case RP2_EVENT_KILL1:
                        if (Creature* citizen = me->FindNearestCreature(NPC_CITIZEN, 100.0f, true))
                            DoCast(citizen, SPELL_CRUSADER_STRIKE);
                        if (Creature* resident = me->FindNearestCreature(NPC_RESIDENT, 100.0f, true))
                        {
                            resident->SetFlag(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                            resident->AI()->Talk(RP2_LINE_RESIDENT1, ObjectAccessor::GetUnit(*me, _eventStarterGuid));
                        }
                        break;
                    case RP2_EVENT_ARTHAS_MOVE_3:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP2_POINTID_ARTHAS3, RP2_CHAIN_ARTHAS3, true);
                        break;
                    case RP2_EVENT_KILL2:
                        if (Creature* resident = me->FindNearestCreature(NPC_RESIDENT, 100.0f, true))
                            DoCast(resident, SPELL_CRUSADER_STRIKE);
                        break;
                    case RP2_EVENT_REACT1:
                    case RP2_EVENT_REACT2:
                    case RP2_EVENT_REACT3:
                    case RP2_EVENT_REACT4:
                    case RP2_EVENT_REACT5:
                    {
                        std::list<Creature*> nearbyVictims;
                        me->GetCreatureListWithEntryInGrid(nearbyVictims, urand(0, 1) ? NPC_CITIZEN : NPC_RESIDENT, 60.0f);
                        if (!nearbyVictims.empty())
                        {
                            std::list<Creature*>::iterator it = nearbyVictims.begin();
                            std::advance(it, urand(0, nearbyVictims.size()-1));
                            Emote emote;
                            switch (urand(0, 3))
                            {
                                case 0:
                                    emote = EMOTE_ONESHOT_TALK;
                                    break;
                                case 1:
                                    emote = EMOTE_ONESHOT_EXCLAMATION;
                                    break;
                                case 2:
                                    emote = EMOTE_ONESHOT_RUDE;
                                    break;
                                case 3:
                                    emote = EMOTE_ONESHOT_ROAR;
                                    break;
                                default:
                                    break;
                            }
                            if ((*it)->IsAlive())
                                (*it)->HandleEmoteCommand(emote);
                        }
                        break;
                    }
                    case RP2_EVENT_ARTHAS_MOVE_4:
                        me->SetFacingTo(2.234021f); // @todo
                        break;
                    case RP2_EVENT_ARTHAS3:
                        talkerEntry = 0, talkerLine = RP2_LINE_ARTHAS3;
                        break;
                    case RP2_EVENT_MALGANIS1:
                        if (Creature* bunny = me->FindNearestCreature(NPC_MALGANIS_BUNNY, 80.0f, true))
                            bunny->CastSpell(bunny, SPELL_SHADOWSTEP_VISUAL);

                        if (Creature* malganis = instance->instance->SummonCreature(NPC_MALGANIS, ArthasPositions[RP2_MALGANIS_POS]))
                        {
                            malganis->CastSpell(malganis, SPELL_SHADOWSTEP_VISUAL);
                            malganis->AI()->Talk(RP2_LINE_MALGANIS1);
                        }
                        break;
                    case RP2_EVENT_TROOPS_FACE:
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 80.0f, true))
                        {
                            std::list<Creature*> troops;
                            me->GetCreatureListWithEntryInGrid(troops, NPC_FOOTMAN, 50.0f);
                            me->GetCreatureListWithEntryInGrid(troops, NPC_PRIEST, 50.0f);
                            for (Creature* unit : troops)
                                if (unit->IsAlive())
                                    unit->SetFacingToObject(malganis);
                        }
                        break;
                    case RP2_EVENT_ARTHAS_FACE:
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 80.0f, true))
                            me->SetFacingToObject(malganis);
                        break;
                    case RP2_EVENT_MALGANIS2:
                        talkerEntry = NPC_MALGANIS, talkerLine = RP2_LINE_MALGANIS2;
                        break;
                    case RP2_EVENT_MALGANIS_LEAVE1:
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 80.0f, true))
                            malganis->CastSpell(malganis, SPELL_SHADOWSTEP_VISUAL);
                        break;
                    case RP2_EVENT_MALGANIS_LEAVE2:
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 80.0f, true))
                            malganis->DespawnOrUnsummon(0);
                        if (Creature* bunny = me->FindNearestCreature(NPC_MALGANIS_BUNNY, 80.0f, true))
                            bunny->CastSpell(bunny, SPELL_SHADOWSTEP_VISUAL);
                        break;
                    case RP2_EVENT_ARTHAS4:
                        talkerEntry = 0, talkerLine = RP2_LINE_ARTHAS4;
                        break;
                    case RP2_EVENT_ARTHAS4_2:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                        break;
                    case RP2_EVENT_ARTHAS5:
                        talkerEntry = 0, talkerLine = RP2_LINE_ARTHAS5;
                        break;
                    case RP2_EVENT_ARTHAS5_2:
                    case RP2_EVENT_ARTHAS5_3:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                        break;
                    case RP2_EVENT_WAVE_START:
                        instance->SetData(DATA_START_WAVES, 1);
                        break;
                    case EVENT_TOWN_HALL_REACHED:
                        me->DespawnOrUnsummon();
                        instance->SetData(DATA_REACH_TOWN_HALL, 1);
                        break;
                    case RP3_EVENT_RESIDENT_FACE:
                        if (Creature* infinite = me->FindNearestCreature(NPC_RESIDENT_INFINITE, 100.0f, true))
                            infinite->SetFacingToObject(me);
                        break;
                    case RP3_EVENT_ARTHAS_FACE:
                        me->SetFacingTo(0.541052f); // @todo
                        break;
                    case RP3_EVENT_CITIZEN1:
                        talkerEntry = NPC_CITIZEN_INFINITE, talkerLine = RP3_LINE_CITIZEN1;
                        break;
                    case RP3_EVENT_ARTHAS2:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS2;
                        me->GetMotionMaster()->MoveAlongSplineChain(RP3_POINTID_ARTHAS2, RP3_CHAIN_ARTHAS2, true);
                        break;
                    case RP3_EVENT_ARTHAS_KILL:
                        if (Creature* citizen = me->FindNearestCreature(NPC_CITIZEN_INFINITE, 100.0f, true))
                            DoCast(citizen, SPELL_CRUSADER_STRIKE);
                        break;
                    case RP3_EVENT_INFINITE_LAUGH:
                        if (Creature* citizen = me->FindNearestCreature(NPC_CITIZEN_INFINITE, 100.0f, true))
                            citizen->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                        break;
                    case RP3_EVENT_ARTHAS3:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS3;
                        break;
                    case RP3_EVENT_CITIZEN2:
                        talkerEntry = NPC_CITIZEN_INFINITE, talkerLine = RP3_LINE_CITIZEN2;
                        break;
                    case RP3_EVENT_TRANSFORM1:
                    case RP3_EVENT_TRANSFORM3:
                        if (Creature* citizen = me->FindNearestCreature(NPC_CITIZEN_INFINITE, 100.0f, true))
                        {
                            citizen->CastSpell(citizen, SPELL_TRANSFORM_VISUAL);
                            citizen->UpdateEntry(NPC_INFINITE_HUNTER);
                        }
                        break;
                    case RP3_EVENT_TRANSFORM2:
                        if (Creature* resident = me->FindNearestCreature(NPC_RESIDENT_INFINITE, 100.0f, true))
                        {
                            resident->CastSpell(resident, SPELL_TRANSFORM_VISUAL);
                            resident->UpdateEntry(NPC_INFINITE_AGENT);
                        }
                        break;
                    case RP3_EVENT_AGGRO:
                        EngageInfinites();
                        ScheduleActionOOC(RP3_ACTION_AFTER_INITIAL);
                        break;
                    case RP3_EVENT_ARTHAS4:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS4;
                        break;
                    case RP3_EVENT_ARTHAS_MOVE_1:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP3_POINTID_ARTHAS3, RP3_CHAIN_ARTHAS3, false);
                        break;
                    case RP3_EVENT_ARTHAS_MOVE_1_2:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS10;
                        me->GetMotionMaster()->MoveAlongSplineChain(0, RP3_CHAIN_ARTHAS3_2, true);
                        break;
                    case RP3_EVENT_SPAWN1:
                    {
                        uint8 extra = urand(0, 2); // 0 = extra adversary, 1 = extra hunter, 2 = extra agent
                        if (Creature* spawn1 = instance->instance->SummonCreature(NPC_INFINITE_ADVERSARY, ArthasPositions[RP3_SPAWN1_LOC1]))
                            MoveInfiniteOnSpawn(spawn1, RP3_CHAIN_SPAWN1_LOC1);
                        if (Creature* spawn2 = instance->instance->SummonCreature(extra ? NPC_INFINITE_HUNTER : NPC_INFINITE_ADVERSARY, ArthasPositions[RP3_SPAWN1_LOC2]))
                            MoveInfiniteOnSpawn(spawn2, RP3_CHAIN_SPAWN1_LOC2);
                        if (Creature* spawn3 = instance->instance->SummonCreature(extra < 2 ? NPC_INFINITE_HUNTER : NPC_INFINITE_AGENT, ArthasPositions[RP3_SPAWN1_LOC3]))
                            MoveInfiniteOnSpawn(spawn3, RP3_CHAIN_SPAWN1_LOC3);
                        if (Creature* spawn4 = instance->instance->SummonCreature(NPC_INFINITE_AGENT, ArthasPositions[RP3_SPAWN1_LOC4]))
                            MoveInfiniteOnSpawn(spawn4, RP3_CHAIN_SPAWN1_LOC4);
                        if (Creature* rift = instance->instance->SummonCreature(NPC_TIME_RIFT, ArthasPositions[RP3_SPAWN1_RIFT]))
                            rift->DespawnOrUnsummon(Seconds(4));
                        break;
                    }
                    case RP3_EVENT_SPAWN1_FACE:
                    case RP3_EVENT_SPAWN2_FACE:
                    case RP3_EVENT_SPAWN3_FACE:
                    {
                        std::list<Creature*> infinites;
                        me->GetCreatureListWithEntryInGrid(infinites, NPC_INFINITE_ADVERSARY, 100.0f);
                        me->GetCreatureListWithEntryInGrid(infinites, NPC_INFINITE_AGENT, 100.0f);
                        me->GetCreatureListWithEntryInGrid(infinites, NPC_INFINITE_HUNTER, 100.0f);
                        for (Creature* target : infinites)
                            if (target->IsAlive())
                                target->SetFacingToObject(me);
                        break;
                    }
                    case RP3_EVENT_SPAWN1_AGGRO:
                        EngageInfinites();
                        ScheduleActionOOC(RP3_ACTION_AFTER_SPAWN1);
                        break;
                    case RP3_EVENT_ARTHAS11:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS11;
                        break;
                    case RP3_EVENT_ARTHAS_MOVE_2:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP3_POINTID_ARTHAS4, RP3_CHAIN_ARTHAS4, false);
                        break;
                    case RP3_EVENT_ARTHAS20:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS20;
                        break;
                    case RP3_EVENT_SPAWN2:
                    {
                        uint8 extra = urand(0, 2); // 0 = extra adversary, 1 = extra hunter, 2 = extra agent
                        if (Creature* SPAWN2 = instance->instance->SummonCreature(NPC_INFINITE_ADVERSARY, ArthasPositions[RP3_SPAWN2_LOC1]))
                            MoveInfiniteOnSpawn(SPAWN2, RP3_CHAIN_SPAWN2_LOC1);
                        if (Creature* spawn2 = instance->instance->SummonCreature(extra ? NPC_INFINITE_HUNTER : NPC_INFINITE_ADVERSARY, ArthasPositions[RP3_SPAWN2_LOC2]))
                            MoveInfiniteOnSpawn(spawn2, RP3_CHAIN_SPAWN2_LOC2);
                        if (Creature* spawn3 = instance->instance->SummonCreature(extra < 2 ? NPC_INFINITE_HUNTER : NPC_INFINITE_AGENT, ArthasPositions[RP3_SPAWN2_LOC3]))
                            MoveInfiniteOnSpawn(spawn3, RP3_CHAIN_SPAWN2_LOC3);
                        if (Creature* spawn4 = instance->instance->SummonCreature(NPC_INFINITE_AGENT, ArthasPositions[RP3_SPAWN2_LOC4]))
                            MoveInfiniteOnSpawn(spawn4, RP3_CHAIN_SPAWN2_LOC4);
                        if (Creature* rift1 = instance->instance->SummonCreature(NPC_TIME_RIFT, ArthasPositions[RP3_SPAWN2_RIFT1]))
                            rift1->DespawnOrUnsummon(Seconds(5));
                        if (Creature* rift2 = instance->instance->SummonCreature(NPC_TIME_RIFT, ArthasPositions[RP3_SPAWN2_RIFT2]))
                            rift2->DespawnOrUnsummon(Seconds(5));
                        break;
                    }
                    case RP3_EVENT_ARTHAS_FACE2:
                        me->SetFacingTo(1.762783f); // @todo
                        break;
                    case RP3_EVENT_SPAWN2_AGGRO:
                        EngageInfinites();
                        ScheduleActionOOC(RP3_ACTION_AFTER_SPAWN2);
                        break;
                    case RP3_EVENT_ARTHAS21:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS21;
                        break;
                    case RP3_EVENT_ARTHAS_MOVE_3:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP3_POINTID_ARTHAS5, RP3_CHAIN_ARTHAS5, false);
                        break;
                    case RP3_EVENT_SPAWN3:
                    {
                        uint8 extra = urand(0, 2); // 0 = extra adversary, 1 = extra hunter, 2 = extra agent
                        if (Creature* SPAWN3 = instance->instance->SummonCreature(NPC_INFINITE_ADVERSARY, ArthasPositions[RP3_SPAWN3_LOC1]))
                            MoveInfiniteOnSpawn(SPAWN3, RP3_CHAIN_SPAWN3_LOC1);
                        if (Creature* SPAWN3 = instance->instance->SummonCreature(extra ? NPC_INFINITE_HUNTER : NPC_INFINITE_ADVERSARY, ArthasPositions[RP3_SPAWN3_LOC2]))
                            MoveInfiniteOnSpawn(SPAWN3, RP3_CHAIN_SPAWN3_LOC2);
                        if (Creature* spawn3 = instance->instance->SummonCreature(extra < 2 ? NPC_INFINITE_HUNTER : NPC_INFINITE_AGENT, ArthasPositions[RP3_SPAWN3_LOC3]))
                            MoveInfiniteOnSpawn(spawn3, RP3_CHAIN_SPAWN3_LOC3);
                        if (Creature* spawn4 = instance->instance->SummonCreature(NPC_INFINITE_AGENT, ArthasPositions[RP3_SPAWN3_LOC4]))
                            MoveInfiniteOnSpawn(spawn4, RP3_CHAIN_SPAWN3_LOC4);
                        if (Creature* rift1 = instance->instance->SummonCreature(NPC_TIME_RIFT, ArthasPositions[RP3_SPAWN3_RIFT1]))
                            rift1->DespawnOrUnsummon(Seconds(5));
                        if (Creature* rift2 = instance->instance->SummonCreature(NPC_TIME_RIFT, ArthasPositions[RP3_SPAWN3_RIFT2]))
                            rift2->DespawnOrUnsummon(Seconds(5));
                        break;
                    }
                    case RP3_EVENT_ARTHAS30:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS30;
                        break;
                    case RP3_EVENT_SPAWN3_AGGRO:
                        EngageInfinites();
                        ScheduleActionOOC(RP3_ACTION_AFTER_SPAWN3);
                        break;
                    case RP3_EVENT_EPOCH_SPAWN:
                        if (Creature* epoch = instance->instance->SummonCreature(NPC_EPOCH, ArthasPositions[RP3_EPOCH_SPAWN]))
                            epoch->GetMotionMaster()->MoveAlongSplineChain(0, RP3_CHAIN_EPOCH, false);
                        if (Creature* rift = instance->instance->SummonCreature(NPC_TIME_RIFT_LARGE, ArthasPositions[RP3_EPOCH_RIFT]))
                            rift->DespawnOrUnsummon(Seconds(27));
                        break;
                    case RP3_EVENT_ARTHAS31:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS31;
                        me->SetFacingTo(6.073746f); // @todo
                        break;
                    case RP3_EVENT_EPOCH_FACE:
                        if (Creature* epoch = me->FindNearestCreature(NPC_EPOCH, 100.0f, true))
                            epoch->SetFacingToObject(me);
                        break;
                    case RP3_EVENT_EPOCH1:
                        talkerEntry = NPC_EPOCH, talkerLine = RP3_LINE_EPOCH1;
                        break;
                    case RP3_EVENT_ARTHAS32:
                        talkerEntry = 0, talkerLine = RP3_LINE_ARTHAS32;
                        break;
                    case RP3_EVENT_ARTHAS32_2:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_POINT_NO_SHEATHE);
                        break;
                    case RP3_EVENT_EPOCH_AGGRO:
                        talkerEntry = NPC_EPOCH, talkerLine = RP3_LINE_EPOCH2;
                        if (Creature* epoch = me->FindNearestCreature(NPC_EPOCH, 100.0f, true))
                        {
                            epoch->SetImmuneToAll(false);
                            me->EngageWithTarget(epoch);
                            epoch->EngageWithTarget(me);
                        }
                        ScheduleActionOOC(RP3_ACTION_AFTER_EPOCH);
                        break;
                    case RP4_EVENT_ARTHAS2:
                        me->SetFacingTo(0.226893f); // @todo
                        talkerEntry = 0, talkerLine = RP4_LINE_ARTHAS2;
                        break;
                    case RP4_EVENT_HIDDEN_PASSAGE:
                        if (GameObject* passage = me->FindNearestGameObject(GO_HIDDEN_PASSAGE, 100.0f))
                            passage->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case RP4_EVENT_ARTHAS3:
                        talkerEntry = 0, talkerLine = RP4_LINE_ARTHAS3;
                        me->GetMotionMaster()->MoveAlongSplineChain(RP4_POINTID_ARTHAS2, RP4_CHAIN_ARTHAS2, false);
                        break;
                    case RP4_EVENT_GAUNTLET_REACHED:
                        me->DespawnOrUnsummon();
                        instance->SetData(DATA_GAUNTLET_REACHED, 1);
                        break;
                    case RP4_EVENT_ARTHAS_MOVE:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP4_POINTID_GAUNTLET1, RP4_CHAIN_GAUNTLET1, false);
                        break;
                    case RP4_EVENT_ARTHAS11:
                        talkerEntry = 0, talkerLine = RP4_LINE_ARTHAS11;
                        break;
                    case RP4_EVENT_ARTHAS_FACE:
                        me->SetFacingTo(1.780236f); // @todo
                        break;
                    case RP4_EVENT_ARTHAS12:
                        talkerEntry = 0, talkerLine = RP4_LINE_ARTHAS12;
                        break;
                    case RP4_EVENT_GAUNTLET_RESUME:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP4_POINTID_GAUNTLET2, RP4_CHAIN_GAUNTLET2, false);
                        break;
                    case RP4_EVENT_ARTHAS13:
                        talkerEntry = 0, talkerLine = RP4_LINE_ARTHAS13;
                        me->SetFacingTo(ArthasPositions[ARTHAS_GAUNTLET_END_POS].GetOrientation());
                        break;
                    case RP4_EVENT_GAUNTLET_DONE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_POINT_NO_SHEATHE);
                        instance->SetData(DATA_GAUNTLET_DONE, 1);
                        break;
                    case RP5_EVENT_ARTHAS2:
                        talkerEntry = 0, talkerLine = RP5_LINE_ARTHAS2;
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 100.0f, true))
                            me->SetFacingToObject(malganis);
                        break;
                    case RP5_EVENT_MALGANIS1:
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 100.0f, true))
                        {
                            malganis->AI()->Talk(RP5_LINE_MALGANIS1, ObjectAccessor::GetUnit(*malganis, _eventStarterGuid));
                            malganis->SetImmuneToAll(false);
                            me->EngageWithTarget(malganis);
                            malganis->EngageWithTarget(me);
                        }
                        ScheduleActionOOC(RP5_ACTION_AFTER_MALGANIS);
                        break;
                    case RP5_EVENT_MALGANIS_DONE:
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 100.0f, true))
                        {
                            malganis->SetFacingToObject(me);
                            malganis->CastSpell(malganis, SPELL_MALGANIS_QUEST_CREDIT, true);
                            malganis->CastSpell(malganis, SPELL_MALGANIS_KILL_CREDIT, true);
                            if (GameObject* chest = malganis->FindNearestGameObject(RAID_MODE(GO_CHEST_NORMAL, GO_CHEST_HEROIC), 100.0f))
                                chest->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        events.ScheduleEvent(RP5_EVENT_MALGANIS12, 3s);
                        events.ScheduleEvent(RP5_EVENT_MALGANIS_LEAVE, 19s);
                        events.ScheduleEvent(RP5_EVENT_ARTHAS10, 20s);
                        events.ScheduleEvent(RP5_EVENT_ARTHAS10_2, 27s);
                        events.ScheduleEvent(RP5_EVENT_ARTHAS11, 30s);
                        events.ScheduleEvent(RP5_EVENT_ARTHAS11_2, 35s);
                        events.ScheduleEvent(RP5_EVENT_ARTHAS_LEAVE, 45s);
                        events.ScheduleEvent(RP5_EVENT_CHROMIE_SPAWN, 65s);
                        events.ScheduleEvent(RP5_EVENT_CHROMIE_LAND, 76s + 668ms);
                        events.ScheduleEvent(RP5_EVENT_CHROMIE_TRANSFORM, 79s + 491ms);
                        instance->SetBossState(DATA_MAL_GANIS, DONE);
                        instance->SetData(DATA_MALGANIS_DONE, 1);
                        break;
                    case RP5_EVENT_MALGANIS12:
                        talkerEntry = NPC_MALGANIS, talkerLine = RP5_LINE_MALGANIS12;
                        break;
                    case RP5_EVENT_MALGANIS_LEAVE:
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 100.0f, true))
                            malganis->CastSpell(malganis, SPELL_SHADOWSTEP_VISUAL);
                        break;
                    case RP5_EVENT_ARTHAS10:
                        if (Creature* malganis = me->FindNearestCreature(NPC_MALGANIS, 100.0f, true))
                            malganis->DespawnOrUnsummon();
                        me->GetMotionMaster()->MoveAlongSplineChain(0, RP5_CHAIN_ARTHAS2, false);
                        talkerEntry = 0, talkerLine = RP5_LINE_ARTHAS10;
                        break;
                    case RP5_EVENT_ARTHAS10_2:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                        break;
                    case RP5_EVENT_ARTHAS11:
                        talkerEntry = 0, talkerLine = RP5_LINE_ARTHAS11;
                        break;
                    case RP5_EVENT_ARTHAS11_2:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                        break;
                    case RP5_EVENT_ARTHAS_LEAVE:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP5_POINTID_ARTHAS3, RP5_CHAIN_ARTHAS3, true);
                        break;
                    case RP5_EVENT_ARTHAS_LEAVE2:
                        me->GetMotionMaster()->MoveAlongSplineChain(RP5_POINTID_ARTHAS4, RP5_CHAIN_ARTHAS4, true);
                        break;
                    case RP5_EVENT_CHROMIE_SPAWN:
                        if (Creature* chromie = instance->instance->SummonCreature(NPC_CHROMIE_3, ArthasPositions[RP5_CHROMIE_SPAWN]))
                        {
                            chromie->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                            Movement::PointsArray path(ChromieSplinePos, ChromieSplinePos + chromiePathSize);
                            Movement::MoveSplineInit init(chromie);
                            init.SetFly();
                            init.SetWalk(true);
                            init.MovebyPath(path, 0);
                            me->GetMotionMaster()->LaunchMoveSpline(std::move(init), 0, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
                        }
                        break;
                    case RP5_EVENT_CHROMIE_LAND:
                        if (Creature* chromie = me->FindNearestCreature(NPC_CHROMIE_3, 100.0f, true))
                            chromie->SetByteValue(UNIT_FIELD_BYTES_1, 3, 0);
                        break;
                    case RP5_EVENT_CHROMIE_TRANSFORM:
                        if (Creature* chromie = me->FindNearestCreature(NPC_CHROMIE_3, 100.0f, true))
                        {
                            chromie->CastSpell(chromie, SPELL_CHROMIE_3_TRANSFORM);
                            chromie->AI()->Talk(RP5_LINE_CHROMIE0);
                            chromie->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        }
                    default:
                        break;
                }

                if (talkerEntry != UINT_MAX)
                {
                    Creature* talker;
                    if (talkerEntry)
                        talker = me->FindNearestCreature(talkerEntry, 100.0f, true);
                    else
                        talker = me;
                    if (talker)
                        talker->AI()->Talk(talkerLine, ObjectAccessor::GetUnit(*talker, _eventStarterGuid));
                }
            }
        }

        void EngageInfinites()
        {
            std::list<Creature*> infinites;
            me->GetCreatureListWithEntryInGrid(infinites, NPC_INFINITE_ADVERSARY, 100.0f);
            me->GetCreatureListWithEntryInGrid(infinites, NPC_INFINITE_AGENT, 100.0f);
            me->GetCreatureListWithEntryInGrid(infinites, NPC_INFINITE_HUNTER, 100.0f);
            for (Creature* target : infinites)
            {
                target->SetImmuneToAll(false);
                me->EngageWithTarget(target);
                target->EngageWithTarget(me);
            }
        }

        static void MoveInfiniteOnSpawn(Creature* infinite, SplineChains chainId)
        {
            if (std::vector<SplineChainLink> const* chain = sScriptSystemMgr->GetSplineChain(NPC_INFINITE_ADVERSARY, chainId))
                infinite->GetMotionMaster()->MoveAlongSplineChain(0, *chain, true);
        }

        void KilledUnit(Unit* who) override
        {
            if (who && who->GetEntry() == NPC_RISEN_ZOMBIE)
                Talk(LINE_SLAY_ZOMBIE, who);
        }

        void JustEngagedWith(Unit* who) override
        {
            if (_progressRP)
            {
                _progressRP = false;
                me->SetHomePosition(me->GetPosition());

                SplineChainMovementGenerator::GetResumeInfo(_resumeMovement, me);
            }
            ScriptedAI::JustEngagedWith(who);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            ScriptedAI::EnterEvadeMode(why);
        }

        void JustReachedHome() override
        {
            if (!me->HasAura(SPELL_DEVOTION_AURA))
                DoCastSelf(SPELL_DEVOTION_AURA);

            _progressRP = true;

            if (!_resumeMovement.Empty()) // WP motion was interrupted, resume
            {
                me->GetMotionMaster()->ResumeSplineChain(_resumeMovement);
                _resumeMovement.Clear();
            }

            if (_afterCombat)
            {
                DoAction(_afterCombat);
                _afterCombat = ACTION_NONE;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            // Instance failure: regress back to last stable state
            instance->SetData(DATA_ARTHAS_DIED, 1);
            me->DespawnOrUnsummon(5s);
        }

        void JustAppeared() override
        {
            _progressRP = true;
            AdvanceToState(GetCurrentProgress());
            DoCastSelf(SPELL_DEVOTION_AURA);
        }

        void AdvanceDungeon(Player* cause, COSProgressStates from, COSInstanceData command)
        {
            if (instance->GetData(DATA_INSTANCE_PROGRESS) == from)
                instance->SetGuidData(command, cause->GetGUID());
        }

        bool GossipSelect(Player* player, uint32 /*sender*/, uint32 /*listId*/) override
        {
            AdvanceDungeon(player, PURGE_PENDING, DATA_START_PURGE);
            AdvanceDungeon(player, TOWN_HALL_PENDING, DATA_START_TOWN_HALL);
            AdvanceDungeon(player, TOWN_HALL_COMPLETE, DATA_TO_GAUNTLET);
            AdvanceDungeon(player, GAUNTLET_PENDING, DATA_START_GAUNTLET);
            AdvanceDungeon(player, GAUNTLET_COMPLETE, DATA_START_MALGANIS);
            return true;
        }

        bool GossipHello(Player* /*player*/) override
        {
            return false;
        }

        private:
            InstanceScript* const instance;
            EventMap events;
            ObjectGuid _eventStarterGuid;
            uint32 _exorcismCooldown; // no EventMap entry for this, it's reserved for RP handling

            bool _progressRP;
            Actions _afterCombat;
            SplineChainResumeInfo _resumeMovement;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetCullingOfStratholmeAI<npc_arthas_stratholmeAI>(creature);
    }
};

Position const& GetArthasSnapbackFor(COSProgressStates state)
{
    auto itr = ArthasSnapbackPositions.find(state);
    if (itr == ArthasSnapbackPositions.end())
        itr = ArthasSnapbackPositions.begin();
    return *(itr->second.SnapbackPosition);
}

// Arthas' AI is the one controlling everything, all this AI does is report any movementinforms back to Arthas AI
struct npc_stratholme_rp_dummy : NullCreatureAI
{
    npc_stratholme_rp_dummy(Creature* creature) : NullCreatureAI(creature) { }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE || type == EFFECT_MOTION_TYPE || type == SPLINE_CHAIN_MOTION_TYPE)
            if (TempSummon* self = me->ToTempSummon())
                self->GetSummonerCreatureBase()->AI()->MovementInform(type, id);
    }
};

class spell_stratholme_crusader_strike : public SpellScript
{
    PrepareSpellScript(spell_stratholme_crusader_strike);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (target->GetEntry() == NPC_CITIZEN || target->GetEntry() == NPC_RESIDENT)
                Unit::Kill(GetCaster(), target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_stratholme_crusader_strike::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_npc_arthas_stratholme()
{
    new npc_arthas_stratholme();
    RegisterCreatureAI(npc_stratholme_rp_dummy);
    RegisterSpellScript(spell_stratholme_crusader_strike);
}
