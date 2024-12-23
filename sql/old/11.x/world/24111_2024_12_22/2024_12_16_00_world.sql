SET @CGUID := 10004900;
SET @OGUID := 10001212;

SET @NPCTEXTID := 600068;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+75;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 3, 2973.7197265625, -2387.0400390625, 276.406982421875, 0.09345245361328125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+1, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2936.701904296875, -2457.659423828125, 295.078094482421875, 3.177837848663330078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+2, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2959.3916015625, -2378.6025390625, 266.328216552734375, 3.960079193115234375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+3, 230542, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2887.12841796875, -2388.9462890625, 266.6357421875, 5.433397769927978515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Archivist Mokrand (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 458385 - [DNT] Female Earthen/Dwarf Taking Notes)
(@CGUID+4, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2882.044189453125, -2414.513916015625, 266.6357421875, 0.798904657363891601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+5, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 5, 2937.36279296875, -2356.6181640625, 266.3717041015625, 3.87408757209777832, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+6, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2866.239501953125, -2458.596923828125, 259.390625, 3.914029598236083984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2949.907958984375, -2416.255126953125, 266.328216552734375, 5.430101394653320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+8, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2887.34033203125, -2440.83154296875, 266.844818115234375, 2.343483209609985351, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+9, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2821.760498046875, -2463.236083984375, 239.2051239013671875, 1.535251617431640625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+10, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2859.325439453125, -2472.697998046875, 250.199859619140625, 3.883814334869384765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+11, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2928.35498046875, -2419.994873046875, 266.3282470703125, 4.795296669006347656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+12, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2956.203125, -2414.741455078125, 287.1416015625, 2.844187736511230468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+13, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2862.924560546875, -2405.814208984375, 294.888427734375, 3.34917616844177246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+14, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2918.9775390625, -2340.0556640625, 276.40484619140625, 6.066197395324707031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+15, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 5, 2867.6416015625, -2307.397705078125, 258.393798828125, 3.931911706924438476, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+16, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2821.572021484375, -2466.3525390625, 239.2081451416015625, 2.461111307144165039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+17, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2907.42529296875, -2367.20654296875, 265.54248046875, 5.430101394653320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+18, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2863.625, -2436.748291015625, 266.844482421875, 3.998203992843627929, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+19, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2860.966064453125, -2405.8837890625, 294.888427734375, 0.039449937641620635, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+20, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 2, 2965.9775390625, -2411.66845703125, 265.54248046875, 2.33508157730102539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+21, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2823.517333984375, -2429.390625, 240.848876953125, 3.670683622360229492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+22, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2861.952392578125, -2404.392333984375, 294.888427734375, 4.660629749298095703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+23, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 6, 2901.588623046875, -2434.276123046875, 266.6357421875, 0.941063106060028076, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+24, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2954.72216796875, -2415.994873046875, 287.1416015625, 2.333097457885742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+25, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2901.272705078125, -2355.94970703125, 287.1416015625, 4.843334674835205078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+26, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2890.643310546875, -2402.845458984375, 266.03546142578125, 4.498662948608398437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+27, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2821.822021484375, -2461.86279296875, 239.205078125, 4.637385845184326171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+28, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2928.4384765625, -2421.694580078125, 266.3282470703125, 1.635419487953186035, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+29, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 2, 2929.55908203125, -2341.869873046875, 276.406982421875, 1.633610129356384277, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+30, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2890.209228515625, -2404.845458984375, 266.056610107421875, 1.357070207595825195, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+31, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2951.1806640625, -2417.98095703125, 266.220703125, 0.933941841125488281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 396209 - Conversation Aura: Talk Only - upper body [DNT])
(@CGUID+32, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2923.874267578125, -2432.69970703125, 266.6357421875, 2.33508157730102539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+33, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2908.439208984375, -2368.880126953125, 265.54248046875, 2.120377302169799804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+34, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 7, 2904.020751953125, -2350.43408203125, 265.54248046875, 5.97323465347290039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+35, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 2, 2843.125, -2456.5, 250.199462890625, 4.004134654998779296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+36, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2901.193603515625, -2357.90283203125, 287.1416015625, 1.533610105514526367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+37, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2874.74658203125, -2428.96875, 266.84478759765625, 5.64228057861328125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+38, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2879.21533203125, -2452.3681640625, 266.844482421875, 3.940617084503173828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+39, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2864.95068359375, -2457.059814453125, 259.48016357421875, 3.914558172225952148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+40, 222631, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2894.9150390625, -2385.994873046875, 266.3282470703125, 4.706026554107666015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Archmage Celindra (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+41, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 7, 2883.236083984375, -2391.616455078125, 266.6357421875, 5.466122627258300781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+42, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2920.9775390625, -2340.49658203125, 276.4052734375, 2.924604654312133789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+43, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2897.4462890625, -2321.366455078125, 260.625335693359375, 2.15447235107421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+44, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2962.950439453125, -2264.51220703125, 252.5333404541015625, 0.898440539836883544, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 436791 - Holding Mead Mug [DNT], 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+45, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2964.224853515625, -2262.911376953125, 252.517486572265625, 4.040033340454101562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 436791 - Holding Mead Mug [DNT])
(@CGUID+46, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 4, 2860.3515625, -2299.8056640625, 258.393402099609375, 3.931911706924438476, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+47, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2847.921875, -2299.335205078125, 259.50634765625, 0.549555003643035888, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+48, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2822.85595703125, -2472.23779296875, 239.2081146240234375, 3.785763263702392578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+49, 219014, 2552, 14771, 15044, '0', 0, 0, 0, 1, 2843.677001953125, -2493.04345703125, 239.2081146240234375, 3.785763263702392578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Peacekeeper (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+50, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2860.085205078125, -2523.90625, 238.86346435546875, 4.1927642822265625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+51, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2860.97216796875, -2525.630126953125, 239.208038330078125, 3.681674718856811523, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+52, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2789.72314453125, -2466.060791015625, 239.2081146240234375, 4.030816078186035156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+53, 229379, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2788.30810546875, -2464.73779296875, 239.2081146240234375, 4.541906356811523437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Unbound Villager (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+54, 224544, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2838.764892578125, -2515.3681640625, 239.2339630126953125, 2.353287935256958007, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Rannida (Area: Keepers Terrace - Difficulty: 0) CreateObject1
(@CGUID+55, 219346, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2773.631591796875, -2439.664306640625, 234.8574371337890625, 5.505495071411132812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Oathsworn Dignitary (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+56, 214772, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2899.83251953125, -2494.444580078125, 292.535888671875, 4.231603622436523437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+57, 214772, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2820.958251953125, -2416.342041015625, 292.535888671875, 3.219585895538330078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+58, 214772, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2877.049560546875, -2470.303955078125, 292.535888671875, 3.368112564086914062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+59, 214772, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2877.06689453125, -2467.486083984375, 292.535888671875, 3.380945920944213867, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+60, 214947, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2883.68408203125, -2498.182373046875, 241.5872039794921875, 5.060177803039550781, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+61, 214950, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2882.0087890625, -2492.53125, 240.2430267333984375, 3.511220216751098632, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Azure Peachick (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+62, 214772, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2821.294189453125, -2410.572998046875, 292.535888671875, 3.722562551498413085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+63, 214772, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2861.979248046875, -2472.359375, 257.138458251953125, 2.522553682327270507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+64, 214950, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2830.927978515625, -2503.067626953125, 239.2081146240234375, 3.842822074890136718, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Azure Peachick (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+65, 214772, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2871.82373046875, -2491.263916015625, 245.479766845703125, 3.34850311279296875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+66, 214947, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2838.459228515625, -2534.010498046875, 242.03338623046875, 4.218731880187988281, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+67, 214947, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2827.208251953125, -2458.407958984375, 242.76904296875, 4.897751808166503906, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+68, 214947, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2857.223876953125, -2515.46533203125, 241.880615234375, 2.923590660095214843, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+69, 214947, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2839.259521484375, -2535.904541015625, 242.399200439453125, 1.246740221977233886, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+70, 214950, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2835.609375, -2563.338623046875, 239.6295013427734375, 5.230384349822998046, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Azure Peachick (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+71, 214950, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2896.920166015625, -2569.7587890625, 239.208282470703125, 3.69503331184387207, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Azure Peachick (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+72, 214950, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2818.907958984375, -2431.447998046875, 239.8837890625, 5.814088344573974609, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Azure Peachick (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+73, 214947, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2825.885498046875, -2457.744873046875, 240.943328857421875, 5.482824325561523437, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+74, 214950, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2779.368896484375, -2463.763916015625, 239.9935150146484375, 0.412877112627029418, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Azure Peachick (Area: Keepers Terrace - Difficulty: 0) CreateObject2
(@CGUID+75, 214947, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2778.6259765625, -2464.772705078125, 241.9304962158203125, 4.872925758361816406, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57689); -- Eye of Topaz (Area: Keepers Terrace - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+75;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+4, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+8, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+10, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435518'), -- Unbound Villager - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+15, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 1023, 0, 0, 0, 0, ''), -- Oathsworn Dignitary
(@CGUID+18, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+20, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+21, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Unbound Villager
(@CGUID+23, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435518'), -- Unbound Villager - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+29, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435518'), -- Unbound Villager - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 0, 14533, 0, 0, 0, '396209'), -- Oathsworn Dignitary - 396209 - Conversation Aura: Talk Only - upper body [DNT]
(@CGUID+32, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+34, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+35, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+37, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+38, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+41, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+43, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Unbound Villager
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436791 435518'), -- Unbound Villager - 436791 - Holding Mead Mug [DNT], 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436791'), -- Unbound Villager - 436791 - Holding Mead Mug [DNT]
(@CGUID+46, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 0, 29098, 0, 0, 0, ''), -- Unbound Villager
(@CGUID+48, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+49, 0, 0, 0, 0, 0, 0, 1, 717, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 2085, 0, 0, 0, ''), -- Unbound Villager
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 0, 2085, 0, 0, 0, '435518'), -- Unbound Villager - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435518'), -- Unbound Villager - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+56, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+57, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+58, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+59, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+62, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+63, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+65, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Limestone Falcon

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+77;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 429072, 2552, 14771, 15044, '0', 0, 0, 2875.73095703125, -2502.244873046875, 239.1302642822265625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+1, 446172, 2552, 14771, 15044, '0', 0, 0, 2971.542236328125, -2527.78466796875, 248.3314056396484375, 2.337144851684570312, 0, 0, 0.920192718505859375, 0.391465693712234497, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+2, 428970, 2552, 14771, 15044, '0', 0, 0, 2759.802001953125, -2341.991455078125, 266.9361572265625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+3, 429073, 2552, 14771, 15044, '0', 0, 0, 2868.9072265625, -2502.4462890625, 239.1302642822265625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+4, 428864, 2552, 14771, 15044, '0', 0, 0, 2827.255126953125, -2243.132080078125, 266.83746337890625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+5, 466852, 2552, 14771, 15044, '0', 0, 0, 2863.93701171875, -2386.778076171875, 348.995269775390625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Fire (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+6, 446168, 2552, 14771, 15044, '0', 0, 0, 2986.580322265625, -2498.448974609375, 242.8477630615234375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+7, 428865, 2552, 14771, 15044, '0', 0, 0, 2833.447998046875, -2217.182373046875, 266.8370361328125, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+8, 428948, 2552, 14771, 15044, '0', 0, 0, 2778.671142578125, -2428.3125, 231.013885498046875, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+9, 466853, 2552, 14771, 15044, '0', 0, 0, 2926.971435546875, -2323.74365234375, 349.087432861328125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Fire (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+10, 446169, 2552, 14771, 15044, '0', 0, 0, 2975.1884765625, -2491.895263671875, 243.0958404541015625, 5.6985015869140625, 0, 0, -0.28819561004638671, 0.957571566104888916, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+11, 452653, 2552, 14771, 15044, '0', 0, 0, 2853.6826171875, -2576.00732421875, 220.1246795654296875, 3.900813102722167968, 0, 0, -0.92880916595458984, 0.370558410882949829, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+12, 446170, 2552, 14771, 15044, '0', 0, 0, 2958.9775390625, -2519.404296875, 248.9457550048828125, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+13, 428950, 2552, 14771, 15044, '0', 0, 0, 2778.75, -2414.65966796875, 231.015625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+14, 428976, 2552, 14771, 15044, '0', 0, 0, 2924.32470703125, -2593.47216796875, 239.3831939697265625, 0.741763234138488769, 0, 0, 0.362437248229980468, 0.932008147239685058, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+15, 446171, 2552, 14771, 15044, '0', 0, 0, 2960.7216796875, -2519.343505859375, 248.9654388427734375, 2.453489303588867187, 0, 0, 0.941395759582519531, 0.337304025888442993, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+16, 456777, 2552, 14771, 15044, '0', 0, 0, 1666.0677490234375, -1532.0504150390625, 0.853936076164245605, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 57689), -- Alliance Transport (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+17, 428877, 2552, 14771, 15044, '0', 0, 0, 2760.064208984375, -2382.34716796875, 231.0146484375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+18, 456778, 2552, 14771, 15044, '0', 0, 0, 1961.91845703125, -1314.8021240234375, -2.34244871139526367, 3.09791874885559082, 0, 0, 0.999761581420898437, 0.021835235878825187, 120, 255, 1, 57689), -- Horde Transport (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+19, 428878, 2552, 14771, 15044, '0', 0, 0, 2778.9296875, -2400.220458984375, 231.01513671875, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+20, 466850, 2552, 14771, 15044, '0', 0, 0, 2928.435302734375, -2451.2763671875, 346.825531005859375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Fire (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+21, 428852, 2552, 14771, 15044, '0', 0, 0, 2917.21533203125, -2589.35595703125, 239.1016693115234375, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+22, 466851, 2552, 14771, 15044, '0', 0, 0, 2992.27978515625, -2387.436279296875, 348.596710205078125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Fire (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+23, 433469, 2552, 14771, 15044, '0', 0, 0, 1866.0504150390625, -1305.8055419921875, -2.82093644142150878, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 57689), -- Horde Transport (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+24, 433470, 2552, 14771, 15044, '0', 0, 0, 1790.7586669921875, -1323.0416259765625, -2.18679475784301757, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 57689), -- Horde Transport (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+25, 429062, 2552, 14771, 15044, '0', 0, 0, 2885.296875, -2506.44091796875, 239.1302642822265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+26, 428990, 2552, 14771, 15044, '0', 0, 0, 2727.6796875, -2323.751708984375, 266.648681640625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Mailbox (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+27, 433471, 2552, 14771, 15044, '0', 0, 0, 1709.1788330078125, -1462.78125, -0.7358059287071228, 5.977754592895507812, 0, 0, -0.15212249755859375, 0.988361656665802001, 120, 255, 1, 57689), -- Alliance Transport (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+28, 452662, 2552, 14771, 15044, '0', 0, 0, 2967.564453125, -2278.76171875, 252.4530487060546875, 2.015851974487304687, 0, 0, 0.845726966857910156, 0.533615827560424804, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+29, 452663, 2552, 14771, 15044, '0', 0, 0, 2965.107421875, -2277.404296875, 252.4530487060546875, 0.32288438081741333, 0, 0, 0.160741806030273437, 0.98699653148651123, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+30, 428850, 2552, 14771, 15044, '0', 0, 0, 2922.09814453125, -2561.626708984375, 248.295135498046875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+31, 433467, 2552, 14771, 15044, '0', 0, 0, 1763.8507080078125, -1541.345458984375, 0.299024790525436401, 0.610865473747253417, 0, 0, 0.300705909729003906, 0.953716933727264404, 120, 255, 1, 57689), -- Alliance Transport (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+32, 428851, 2552, 14771, 15044, '0', 0, 0, 2916.882080078125, -2579.263916015625, 239.1249542236328125, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+33, 428953, 2552, 14771, 15044, '0', 0, 0, 2833.749267578125, -2351.54345703125, 258.19183349609375, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+34, 428860, 2552, 14771, 15044, '0', 0, 0, 2759.451416015625, -2290.083251953125, 266.95574951171875, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+35, 467460, 2552, 14771, 15044, '0', 0, 0, 2896.569580078125, -2386.203857421875, 266.31744384765625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+36, 428955, 2552, 14771, 15044, '0', 0, 0, 2840.264892578125, -2345.31591796875, 258.19183349609375, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+37, 428862, 2552, 14771, 15044, '0', 0, 0, 2818.298583984375, -2252.30908203125, 266.83746337890625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+38, 467461, 2552, 14771, 15044, '0', 0, 0, 2893.125732421875, -2386.2216796875, 266.332916259765625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+39, 452668, 2552, 14771, 15044, '0', 0, 0, 2973.1298828125, -2279.076171875, 252.4653472900390625, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+40, 428863, 2552, 14771, 15044, '0', 0, 0, 2759.447998046875, -2300.10595703125, 266.95574951171875, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+41, 467462, 2552, 14771, 15044, '0', 0, 0, 2884.08984375, -2400.25634765625, 266.447235107421875, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+42, 452669, 2552, 14771, 15044, '0', 0, 0, 2967.662109375, -2259.3359375, 252.4336700439453125, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+43, 467463, 2552, 14771, 15044, '0', 0, 0, 2883.58447265625, -2395.762939453125, 266.332916259765625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+44, 434125, 2552, 14771, 15044, '0', 0, 0, 2775.646728515625, -2291.6962890625, 266.836578369140625, 1.562069892883300781, 0, 0, 0.704014778137207031, 0.71018528938293457, 120, 255, 1, 57689), -- Meeting Stone (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+45, 428962, 2552, 14771, 15044, '0', 0, 0, 2867.475830078125, -2591.395751953125, 239.125, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+46, 428857, 2552, 14771, 15044, '0', 0, 0, 2833.260498046875, -2229.345458984375, 266.837249755859375, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+47, 467456, 2552, 14771, 15044, '0', 0, 0, 2929.498291015625, -2419.13232421875, 266.31744384765625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+48, 428858, 2552, 14771, 15044, '0', 0, 0, 2759.8046875, -2331.96875, 266.9361572265625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+49, 467457, 2552, 14771, 15044, '0', 0, 0, 2929.533203125, -2422.629150390625, 266.332916259765625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+50, 452664, 2552, 14771, 15044, '0', 0, 0, 2973.181640625, -2259.3984375, 252.39544677734375, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+51, 429066, 2552, 14771, 15044, '0', 0, 0, 2940.40283203125, -2518.255126953125, 248.314239501953125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+52, 446166, 2552, 14771, 15044, '0', 0, 0, 2986.828857421875, -2516.16552734375, 242.9175567626953125, 0.759216904640197753, 0, 0, 0.370556831359863281, 0.928809821605682373, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+53, 467458, 2552, 14771, 15044, '0', 0, 0, 2919.964111328125, -2431.871826171875, 266.33282470703125, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+54, 452665, 2552, 14771, 15044, '0', 0, 0, 2970.626953125, -2257.48046875, 252.5463104248046875, 4.773476600646972656, 0, 0, -0.68518257141113281, 0.728371381759643554, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+55, 446167, 2552, 14771, 15044, '0', 0, 0, 2977.994873046875, -2491.79296875, 243.1192626953125, 4.00553131103515625, 0, 0, -0.9081430435180664, 0.418660014867782592, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+56, 467459, 2552, 14771, 15044, '0', 0, 0, 2915.8876953125, -2432.05419921875, 266.447235107421875, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+57, 428992, 2552, 14771, 15044, '0', 0, 0, 2947.87158203125, -2551.447998046875, 248.2425079345703125, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 57689), -- Mailbox (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+58, 452666, 2552, 14771, 15044, '0', 0, 0, 2970.607421875, -2261.1328125, 252.5745086669921875, 1.544615507125854492, 0, 0, 0.697790145874023437, 0.716302275657653808, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+59, 452667, 2552, 14771, 15044, '0', 0, 0, 2975.6904296875, -2276.6171875, 252.4704132080078125, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+60, 415760, 2552, 14771, 15044, '0', 0, 0, 2987.4306640625, -2388.6806640625, 266.244873046875, 5.801862239837646484, 0, 0, -0.23834514617919921, 0.971180498600006103, 120, 255, 1, 57689), -- Earthen Teleporter (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+61, 429033, 2552, 14771, 15044, '0', 0, 0, 2943.505126953125, -2285.892333984375, 251.233642578125, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Earthen Cleanup Bucket (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+62, 429034, 2552, 14771, 15044, '0', 0, 0, 2943.505126953125, -2285.892333984375, 251.3336029052734375, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Fire Honey Puddle (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+63, 434486, 2552, 14771, 15044, '0', 0, 0, 2956.616455078125, -2206.092041015625, 251.574462890625, 5.905436038970947265, 0, 0, -0.18775367736816406, 0.982216119766235351, 120, 255, 1, 57689), -- Bottle of Infused Underclay (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+64, 429635, 2552, 14771, 15044, '0', 0, 0, 2956.256103515625, -2205.755126953125, 251.5742950439453125, 0.866819322109222412, 0, 0, 0.4199676513671875, 0.907539069652557373, 120, 255, 1, 57689), -- Bottle of Infused Underclay (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+65, 429636, 2552, 14771, 15044, '0', 0, 0, 2956.348876953125, -2205.991455078125, 251.3350982666015625, 0.822922587394714355, 0, 0, 0.399949073791503906, 0.916537344455718994, 120, 255, 1, 57689), -- Crate of Delivered Goods (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+66, 434486, 2552, 14771, 15044, '0', 0, 0, 2956.061767578125, -2205.895751953125, 251.5738677978515625, 4.684757232666015625, 0, 0, -0.71680831909179687, 0.69727027416229248, 120, 255, 1, 57689), -- Bottle of Infused Underclay (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+67, 429635, 2552, 14771, 15044, '0', 0, 0, 2956.4228515625, -2206.204833984375, 251.5740509033203125, 4.057512283325195312, 0, 0, -0.89695644378662109, 0.442118912935256958, 120, 255, 1, 57689), -- Bottle of Infused Underclay (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+68, 434486, 2552, 14771, 15044, '0', 0, 0, 2956.509521484375, -2205.913330078125, 251.57452392578125, 0.383199632167816162, 0, 0, 0.1904296875, 0.981700837612152099, 120, 255, 1, 57689), -- Bottle of Infused Underclay (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+69, 428961, 2552, 14771, 15044, '0', 0, 0, 2867.7431640625, -2603.20654296875, 239.125, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+70, 428963, 2552, 14771, 15044, '0', 0, 0, 2872.015625, -2614.5869140625, 239.126739501953125, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+71, 428965, 2552, 14771, 15044, '0', 0, 0, 2878.60498046875, -2621.083251953125, 239.126739501953125, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+72, 494551, 2552, 14771, 15044, '0', 0, 0, 2704.271484375, -2336.9287109375, 264.260467529296875, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 57689), -- Bench (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+73, 494545, 2552, 14771, 15044, '0', 0, 0, 2699.28173828125, -2342.437744140625, 264.46875, 1.579524636268615722, 0, 0, 0.710186004638671875, 0.704014122486114501, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+74, 494547, 2552, 14771, 15044, '0', 0, 0, 2701.024658203125, -2341.0908203125, 264.46875, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+75, 441897, 2552, 14771, 15044, '0', 0, 0, 2928.483642578125, -2387.423583984375, 493.9200439453125, 5.801862239837646484, 0, 0, -0.23834514617919921, 0.971180498600006103, 120, 255, 1, 57689), -- Earthen Teleporter (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+76, 494549, 2552, 14771, 15044, '0', 0, 0, 2696.9091796875, -2342.421142578125, 264.46875, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 57689), -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@OGUID+77, 494550, 2552, 14771, 15044, '0', 0, 0, 2699.19091796875, -2338.800048828125, 264.46875, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 57689); -- Chair (Area: Foundation Hall - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+77;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Chair
(@OGUID+5, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Fire
(@OGUID+6, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Chair
(@OGUID+9, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Fire
(@OGUID+10, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Chair
(@OGUID+11, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Chair
(@OGUID+12, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Chair
(@OGUID+15, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Chair
(@OGUID+20, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Fire
(@OGUID+22, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Fire
(@OGUID+28, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+29, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+35, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+38, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+39, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+41, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+42, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+43, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+47, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+49, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+50, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+52, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Chair
(@OGUID+53, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+54, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+55, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Chair
(@OGUID+56, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+58, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+59, 0, 0, 0.000000087422776573, 1, 0, 0), -- Chair
(@OGUID+60, 0, 0, 0, 1, 0, 5605), -- Earthen Teleporter
(@OGUID+72, 0, 0, 0.70710688829421997, 0.707106649875640869, 0, 0), -- Bench
(@OGUID+73, 0, 0, 0.70710688829421997, 0.707106649875640869, 0, 0), -- Chair
(@OGUID+74, 0, 0, 0.70710688829421997, 0.707106649875640869, 0, 0), -- Chair
(@OGUID+75, 0, 0, 0, 1, 0, 5605), -- Earthen Teleporter
(@OGUID+76, 0, 0, 0.70710688829421997, 0.707106649875640869, 0, 0), -- Chair
(@OGUID+77, 0, 0, 0.70710688829421997, 0.707106649875640869, 0, 0); -- Chair

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (441897 /*Earthen Teleporter*/, 421632 /*Letter*/, 415760 /*Earthen Teleporter*/, 441169 /*Dormant Rock Giant*/, 433470 /*Horde Transport*/, 433469 /*Horde Transport*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(441897, 0, 0x40000, 0, 5605), -- Earthen Teleporter
(421632, 190, 0x0, 0, 0), -- Letter
(415760, 0, 0x40000, 0, 5605), -- Earthen Teleporter
(441169, 0, 0x100020, 0, 0), -- Dormant Rock Giant
(433470, 0, 0x100020, 0, 0), -- Horde Transport
(433469, 0, 0x100020, 0, 0); -- Horde Transport

DELETE FROM `creature_template_addon` WHERE `entry` IN (222631 /*222631 (Archmage Celindra)*/, 230542 /*230542 (Archivist Mokrand) - [DNT] Female Earthen/Dwarf Taking Notes*/, 224544);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(222631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 222631 (Archmage Celindra)
(230542, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '458385'), -- 230542 (Archivist Mokrand) - [DNT] Female Earthen/Dwarf Taking Notes
(224544, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''); -- Rannida

-- Template
DELETE FROM `gameobject_template` WHERE `entry` IN (494550 /*Chair*/, 494549 /*Chair*/, 494547 /*Chair*/, 494545 /*Chair*/, 494551 /*Bench*/, 433470 /*Horde Transport*/, 456777 /*Alliance Transport*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(494550, 7, 87468, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Chair
(494549, 7, 87468, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Chair
(494547, 7, 87468, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Chair
(494545, 7, 87468, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Chair
(494551, 7, 88476, 'Bench', '', '', '', 0.999999403953552246, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Bench
(433470, 43, 88875, 'Horde Transport', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Horde Transport
(456777, 43, 48224, 'Alliance Transport', '', '', '', 1, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689); -- Alliance Transport

UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x800 WHERE `entry`=222631; -- Archmage Celindra
UPDATE `creature_template` SET `faction`=3438, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=230542; -- Archivist Mokrand
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=224544; -- Rannida
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=214950; -- Azure Peachick

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222631 AND `DifficultyID`=0); -- 222631 (Archmage Celindra) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=230542 AND `DifficultyID`=0); -- 230542 (Archivist Mokrand) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `StaticFlags3`=0x2000000, `VerifiedBuild`=57689 WHERE (`Entry`=224544 AND `DifficultyID`=0); -- 224544 (Rannida) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=214950 AND `DifficultyID`=0); -- 214950 (Azure Peachick) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=222631 AND `MenuID`=34720);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(222631, 34720, 57689); -- Archmage Celindra

DELETE FROM `gossip_menu` WHERE (`MenuID`=34720 AND `TextID`=30684);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34720, 30684, 57689); -- 222631 (Archmage Celindra)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34720 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34720, @NPCTEXTID+0, 57689); -- 222631 (Archmage Celindra)

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 123240, 0, 0, 0, 0, 0, 0, 0, 57689); -- 222631 (Archmage Celindra)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=34720 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(34720, 122165, 0, 3, 'Please teach me.', 8442, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 34720) OR (`SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 34720);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 34720, 0, 0, 0, 15, 0, 128, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a mage'),
(14, 34720, @NPCTEXTID+0, 0, 0, 15, 0, 128, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a mage');

-- Trainer
DELETE FROM `trainer` WHERE `Id`=1162;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(1162, 0, 'Welcome!', 57689);

DELETE FROM `creature_trainer` WHERE (`CreatureID`=222631 AND `MenuID`=34720 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(222631, 1162, 34720, 0);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=1162 AND `SpellId` IN (446534,446540));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(1162, 446534, 168000, 0, 0, 0, 0, 0, 78, 57689), -- No Faction found! MoneyCost not recalculated!
(1162, 446540, 168000, 0, 0, 0, 0, 0, 72, 57689); -- No Faction found! MoneyCost not recalculated!

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=224544 AND `quest`=82747);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(224544, 82747, 57689); -- Crossroads Plaza offered by Rannida

DELETE FROM `creature_questender` WHERE (`id`=224566 AND `quest`=82747);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(224566, 82747, 57689); -- Crossroads Plaza ended by Bondaz

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (116387, 92759, 123008, 115261);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(116387, 0.494568407535552978, 1.5, 0, 57689),
(92759, 0.738248705863952636, 1.5, 0, 57689),
(123008, 0.240027263760566711, 0, 0, 57689),
(115261, 0.221856966614723205, 0.300000011920928955, 0, 57689);

UPDATE `creature_model_info` SET `VerifiedBuild`=57689 WHERE `DisplayID` IN (121971, 117277, 117695, 117806, 117696, 117689, 121106, 110227, 121148, 120606, 122301, 115505, 108862, 117697, 120610, 115035, 117757, 118268, 120914, 117200, 117201, 120384, 117756, 121065, 120981, 117238, 115038, 118181, 118386, 57067, 120727, 117690, 118411, 24719, 118385, 60426, 118384, 120957, 118415, 120732, 120733, 117348, 118073, 75322, 92446, 77577, 120952, 118452, 117418, 120951, 120949, 120678, 117653, 120680, 121042, 121044, 118451, 117429, 120629, 120654, 120653, 120648, 120651, 117337, 117419, 120683, 120650, 120649, 117355, 117352, 120730, 120729, 117800, 120681, 117341, 120647, 120646, 104021, 120948, 120685, 122231, 120612, 120016, 120645, 120689, 120636, 5556, 122495, 122496, 65228, 120687, 120619, 120635, 120620, 120543, 120613, 120633, 122494, 120617, 120604, 119739, 120603, 120608, 120627, 117342, 120628, 107365, 117431, 117423, 120626, 120614, 117256, 117354, 118459, 117336, 119080, 116112, 117416, 117426, 117420, 117660, 118449, 117353, 114941, 117491, 117481, 119070, 114923, 117484, 114653, 104045, 117654, 83698, 117655, 117349, 72183, 117658, 120480, 118462, 118482, 119740, 117685, 120605, 65644, 118464, 117797, 109867, 118457, 117785, 117786, 120744, 120749, 117413, 120299, 117421, 99915, 120954, 120741, 120740, 120811, 30764, 120747, 120743, 102553, 117779, 104534, 120745, 114929, 117746, 36833, 120742, 64049, 117486, 118458, 120736, 120735, 120738, 120737, 36880, 36882, 36881, 117422, 120748, 114926, 117417, 118353, 120611, 59303, 120739, 36904, 65251, 117356, 117725, 108778, 120622, 112806, 117428, 117414, 118460, 108777, 108867, 111138, 27959, 111139, 88792, 104042, 121052, 117427, 28282, 28111, 108868, 120630, 120675, 120676, 118463, 117359, 117642, 117343, 117346, 120540, 121979, 121982, 120638, 121980, 121976, 120621, 117408, 61889, 120802, 120670, 121973, 121978, 121986, 120639, 120643, 22003, 117358, 27019, 117350, 120644, 120625, 121989, 121968, 117345, 117412, 117411, 117360, 121975, 121981, 117347, 118447, 120755, 117657, 118461, 121977, 117409, 121974, 117351, 114814);
UPDATE `creature_model_info` SET `BoundingRadius`=0.138684809207916259, `CombatReach`=0.5 WHERE `DisplayID`=63716;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=57689 WHERE `DisplayID`=85203;

-- Path for Oathsworn Dignitary
SET @MOVERGUID := @CGUID+1;
SET @ENTRY := 219346;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Oathsworn Dignitary - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2944.2126, -2440.8994, 292.05322, NULL, 0),
(@PATH, 1, 2944.1711, -2436.6875, 289.0332, NULL, 0),
(@PATH, 2, 2944.722, -2434.0034, 287.18466, NULL, 0),
(@PATH, 3, 2949.8247, -2427.7188, 287.1552, NULL, 0),
(@PATH, 4, 2952.9246, -2424.212, 287.15524, NULL, 0),
(@PATH, 5, 2956.5964, -2420.1562, 287.1552, NULL, 0),
(@PATH, 6, 2963.718, -2420.0295, 287.1552, NULL, 0),
(@PATH, 7, 2969.5886, -2420.7258, 287.1552, NULL, 0),
(@PATH, 8, 2972.0156, -2418.514, 285.54495, NULL, 0),
(@PATH, 9, 2976.8135, -2413.5034, 281.29346, NULL, 0),
(@PATH, 10, 2979.639, -2410.6355, 278.80215, NULL, 0),
(@PATH, 11, 2982.6685, -2404.5, 276.35834, NULL, 0),
(@PATH, 12, 2983.5452, -2398.2883, 276.35834, NULL, 0),
(@PATH, 13, 2983.8977, -2393.1545, 276.4282, NULL, 0),
(@PATH, 14, 2983.6606, -2389.606, 276.4382, NULL, 0),
(@PATH, 15, 2983.2883, -2387.264, 276.4144, NULL, 5063),
(@PATH, 16, 2983.8977, -2393.1545, 276.4282, NULL, 0),
(@PATH, 17, 2983.5452, -2398.2883, 276.35834, NULL, 0),
(@PATH, 18, 2982.6685, -2404.5, 276.35834, NULL, 0),
(@PATH, 19, 2979.639, -2410.6355, 278.80215, NULL, 0),
(@PATH, 20, 2976.8135, -2413.5034, 281.29346, NULL, 0),
(@PATH, 21, 2972.0156, -2418.514, 285.54495, NULL, 0),
(@PATH, 22, 2969.5886, -2420.7258, 287.1552, NULL, 0),
(@PATH, 23, 2963.718, -2420.0295, 287.1552, NULL, 0),
(@PATH, 24, 2956.5964, -2420.1562, 287.1552, NULL, 0),
(@PATH, 25, 2952.9246, -2424.212, 287.15524, NULL, 0),
(@PATH, 26, 2949.8247, -2427.7188, 287.1552, NULL, 0),
(@PATH, 27, 2944.7415, -2433.908, 287.26035, NULL, 0),
(@PATH, 28, 2944.1711, -2436.6875, 289.0332, NULL, 0),
(@PATH, 29, 2944.2126, -2440.8994, 292.05322, NULL, 0),
(@PATH, 30, 2944.1736, -2445.0156, 294.86304, NULL, 0),
(@PATH, 31, 2943.89, -2452.658, 294.96768, NULL, 0),
(@PATH, 32, 2937.5547, -2457.6284, 295.06195, NULL, 0),
(@PATH, 33, 2931.6172, -2457.8438, 295.1552, NULL, 0),
(@PATH, 34, 2925.4705, -2458.019, 295.1552, NULL, 0),
(@PATH, 35, 2919.6328, -2457.7847, 295.0604, NULL, 4992),
(@PATH, 36, 2925.4705, -2458.019, 295.1552, NULL, 0),
(@PATH, 37, 2931.6172, -2457.8438, 295.1552, NULL, 0),
(@PATH, 38, 2937.5479, -2457.6287, 295.07736, NULL, 0),
(@PATH, 39, 2943.89, -2452.658, 294.96768, NULL, 0),
(@PATH, 40, 2944.1736, -2445.0156, 294.86304, NULL, 0);

UPDATE `creature` SET `position_x`=2944.2126, `position_y`=-2440.8994, `position_z`=292.05322, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Dignitary
SET @MOVERGUID := @CGUID+55;
SET @ENTRY := 219346;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Oathsworn Dignitary - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2791.4878, -2458.316, 239.12479, NULL, 0),
(@PATH, 1, 2800.783, -2469.2136, 239.12479, NULL, 0),
(@PATH, 2, 2809.2683, -2478.0051, 239.12479, NULL, 0),
(@PATH, 3, 2818.6458, -2491.111, 239.12009, NULL, 0),
(@PATH, 4, 2827.2761, -2502.165, 239.12479, NULL, 0),
(@PATH, 5, 2833.6875, -2509.6477, 239.12479, NULL, 0),
(@PATH, 6, 2836.8489, -2513.4011, 239.15523, NULL, 4281),
(@PATH, 7, 2833.6875, -2509.6477, 239.12479, NULL, 0),
(@PATH, 8, 2827.2761, -2502.165, 239.12479, NULL, 0),
(@PATH, 9, 2818.6458, -2491.111, 239.12009, NULL, 0),
(@PATH, 10, 2809.2683, -2478.0051, 239.12479, NULL, 0),
(@PATH, 11, 2800.783, -2469.2136, 239.12479, NULL, 0),
(@PATH, 12, 2791.4878, -2458.316, 239.12479, NULL, 0),
(@PATH, 13, 2781.9297, -2447.6165, 239.15524, NULL, 0),
(@PATH, 14, 2779.9915, -2445.927, 239.15523, NULL, 0),
(@PATH, 15, 2772.659, -2438.7065, 234.03648, NULL, 0),
(@PATH, 16, 2766.1008, -2432.2432, 231.01503, NULL, 0),
(@PATH, 17, 2758.605, -2425.073, 231.01503, NULL, 6910),
(@PATH, 18, 2766.1008, -2432.2432, 231.01503, NULL, 0),
(@PATH, 19, 2772.659, -2438.7065, 234.03648, NULL, 0),
(@PATH, 20, 2779.9915, -2445.927, 239.15523, NULL, 0);

UPDATE `creature` SET `position_x`=2791.4878, `position_y`=-2458.316, `position_z`=239.12479, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Dignitary
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+6;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+6, @CGUID+6, 0, 0, 515, 0, 0),
(@CGUID+6, @CGUID+39, 2, 90, 515, 7, 23);

SET @MOVERGUID := @CGUID+6;
SET @ENTRY := 219346;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Oathsworn Dignitary - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2819.8247, -2502.309, 239.12479, NULL, 0),
(@PATH, 1, 2799.8047, -2518.4114, 239.12479, NULL, 0),
(@PATH, 2, 2782.179, -2532.9844, 239.35834, NULL, 0),
(@PATH, 3, 2774.1946, -2541.1423, 232.59349, NULL, 0),
(@PATH, 4, 2766.316, -2548.9133, 226.18872, NULL, 0),
(@PATH, 5, 2758.333, -2557.033, 219.6511, NULL, 0),
(@PATH, 6, 2754.486, -2561.0764, 219.6511, NULL, 0),
(@PATH, 7, 2751.0652, -2564.5696, 219.6511, NULL, 3702),
(@PATH, 8, 2754.486, -2561.0764, 219.6511, NULL, 0),
(@PATH, 9, 2758.333, -2557.033, 219.6511, NULL, 0),
(@PATH, 10, 2766.316, -2548.9133, 226.18872, NULL, 0),
(@PATH, 11, 2774.1946, -2541.1423, 232.59349, NULL, 0),
(@PATH, 12, 2782.151, -2533.013, 239.36151, NULL, 0),
(@PATH, 13, 2799.8047, -2518.4114, 239.12479, NULL, 0),
(@PATH, 14, 2819.8247, -2502.309, 239.12479, NULL, 0),
(@PATH, 15, 2837.5469, -2486.0051, 239.12479, NULL, 0),
(@PATH, 16, 2848.3525, -2475.837, 244.1171, NULL, 0),
(@PATH, 17, 2864.802, -2459.9983, 258.11346, NULL, 0),
(@PATH, 18, 2874.3604, -2450.6807, 266.3301, NULL, 0),
(@PATH, 19, 2881.033, -2441.6858, 266.35828, NULL, 0),
(@PATH, 20, 2886.7065, -2433.3594, 266.59995, NULL, 0),
(@PATH, 21, 2895.3594, -2425.5051, 266.56146, NULL, 0),
(@PATH, 22, 2905.8665, -2422.986, 266.00995, NULL, 0),
(@PATH, 23, 2925.7058, -2420.8994, 266.56146, NULL, 5049),
(@PATH, 24, 2905.8665, -2422.986, 266.00995, NULL, 0),
(@PATH, 25, 2895.3594, -2425.5051, 266.56146, NULL, 0),
(@PATH, 26, 2886.8, -2433.2744, 266.56146, NULL, 0),
(@PATH, 27, 2881.033, -2441.6858, 266.35828, NULL, 0),
(@PATH, 28, 2874.3604, -2450.6807, 266.3301, NULL, 0),
(@PATH, 29, 2864.802, -2459.9983, 258.11346, NULL, 0),
(@PATH, 30, 2848.3525, -2475.837, 244.1171, NULL, 0),
(@PATH, 31, 2837.5469, -2486.0051, 239.12479, NULL, 0);

UPDATE `creature` SET `position_x`=2819.8247, `position_y`=-2502.309, `position_z`=239.12479, `orientation`=0 WHERE `guid`=@CGUID+39;
UPDATE `creature` SET `position_x`=2819.8247, `position_y`=-2502.309, `position_z`=239.12479, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
