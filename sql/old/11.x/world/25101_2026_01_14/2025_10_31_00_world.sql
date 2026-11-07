SET @CGUID := 6005889;
SET @OGUID := 6002968;
SET @SPAWN_GROUP := 1278;

DELETE FROM `battleground_scripts` WHERE `MapId` = 1505 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(1505, 0, 'arena_nagrand_arena_legion');

DELETE FROM `battleground_template` WHERE `ID` = 809;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(809, 5126, 5127, 0, 1, 'Nagrand Arena (Legion)');

DELETE FROM `creature_template_addon` WHERE `entry` IN (115069 /*115069 (Frostwolf Leader) - Mod Scale Increase*/, 115070 /*115070 (Frostwolf Grunt) - Mod Scale Increase*/, 117079 /*117079 (Warsong Grunt) - Mod Scale Increase*/, 115077 /*115077 (Warsong Leader) - Mod Scale Increase*/, 117078 /*117078 (Frostwolf Grunt) - Mod Scale Increase*/, 115076 /*115076 (Warsong Grunt) - Mod Scale Increase*/, 115107 /*115107 (Warsong Rider)*/, 115068 /*115068 (Frostwolf Warrior) - Mod Scale Increase*/, 114925 /*114925 (Warsong Warrior) - Mod Scale Increase*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(115069, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '228832'), -- 115069 (Frostwolf Leader) - Mod Scale Increase
(115070, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '228832'), -- 115070 (Frostwolf Grunt) - Mod Scale Increase
(117079, 0, 0, 0, 0, 0, 1, 0, 0, 12265, 0, 0, 0, '228832'), -- 117079 (Warsong Grunt) - Mod Scale Increase
(115077, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '228832'), -- 115077 (Warsong Leader) - Mod Scale Increase
(117078, 0, 0, 0, 0, 0, 1, 0, 0, 12265, 0, 0, 0, '228832'), -- 117078 (Frostwolf Grunt) - Mod Scale Increase
(115076, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '228832'), -- 115076 (Warsong Grunt) - Mod Scale Increase
(115107, 0, 58437, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 115107 (Warsong Rider)
(115068, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '228832'), -- 115068 (Frostwolf Warrior) - Mod Scale Increase
(114925, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '228832'); -- 114925 (Warsong Warrior) - Mod Scale Increase

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+79;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 115109, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1983.7882080078125, 6555.86376953125, 11.92982959747314453, 5.646188259124755859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frost Wolf (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+1, 114925, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2090.203125, 6684.30029296875, 36.39992141723632812, 5.586688518524169921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+2, 114925, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2083.15283203125, 6693.14599609375, 36.459747314453125, 5.482541084289550781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+3, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2033.7535400390625, 6593.68212890625, 37.32933807373046875, 2.020286321640014648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+4, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2036.298583984375, 6598.7587890625, 36.37642288208007812, 1.606918931007385253, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+5, 115107, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2085.64111328125, 6724.33349609375, 5.642350673675537109, 2.475842714309692382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Rider (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+6, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2080.58154296875, 6707.41650390625, 37.98035812377929687, 5.29676055908203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+7, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2048.584716796875, 6713.5810546875, 36.671661376953125, 3.84355783462524414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+8, 115083, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2074.132080078125, 6701.21337890625, 36.65122222900390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Orc Drum (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+9, 117078, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2019.890625, 6601.92529296875, 36.59801864624023437, 1.97403717041015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+10, 115109, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1974.673583984375, 6563.82275390625, 10.41519355773925781, 5.470674514770507812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frost Wolf (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+11, 115086, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2040.5035400390625, 6699.978515625, 12.70759105682373046, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Adder (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+12, 115087, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2101.041015625, 6620.8330078125, 12.81133079528808593, 1.945276856422424316, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Rat (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+13, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2124.87841796875, 6806.29052734375, -3.57203102111816406, 1.430661678314208984, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+14, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2190.349609375, 6705.7587890625, -2.50267410278320312, 2.206266164779663085, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+15, 115107, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2092.30908203125, 6741.259765625, -0.30584883689880371, 2.307210445404052734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Rider (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+16, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2061.663330078125, 6719.10400390625, 38.593536376953125, 4.878993034362792968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+17, 115093, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2172.850830078125, 6872.93212890625, -7.75903129577636718, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Clefthoof (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+18, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2011.4014892578125, 6699.53466796875, 41.89958953857421875, 0.238513410091400146, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+19, 115083, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2020.18408203125, 6603.134765625, 36.60158538818359375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Orc Drum (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+20, 115097, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2160.632568359375, 6762.97119140625, -3.51956677436828613, 5.644862174987792968, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Tortured Earth Spirit (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+21, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2013.4989013671875, 6499.1220703125, 15.67569828033447265, 3.763102293014526367, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+22, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1952.0186767578125, 6482.5771484375, 19.22262191772460937, 0.890564322471618652, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+23, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2060.736083984375, 6716.12939453125, 38.04050827026367187, 4.83701944351196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+24, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2087.7900390625, 6704.9912109375, 38.69394683837890625, 5.445136070251464843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+25, 115093, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2152.86279296875, 6785.4462890625, -3.96072316169738769, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Clefthoof (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+26, 115077, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2071.114501953125, 6704.0380859375, 36.58251953125, 5.143953323364257812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Leader (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+27, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2086.132080078125, 6694.68994140625, 36.76923370361328125, 0.681179642677307128, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+28, 115093, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1976.4752197265625, 6475.72265625, 22.50014686584472656, 1.997747063636779785, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Clefthoof (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+29, 117078, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2014.5, 6604.8212890625, 36.60653305053710937, 2.044155120849609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+30, 117079, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2068.241455078125, 6706.48291015625, 36.60012435913085937, 5.132005214691162109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+31, 115083, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2067.71875, 6705.06103515625, 36.59103012084960937, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Orc Drum (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+32, 115087, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1998.9381103515625, 6679.89697265625, 13.0044870376586914, 4.302520751953125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Rat (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+33, 117079, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2074.857666015625, 6702.384765625, 36.62760162353515625, 5.293087005615234375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+34, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2240.287353515625, 6706.859375, -1.82799863815307617, 2.036637306213378906, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+35, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1840.8455810546875, 6481.48388671875, 23.22997283935546875, 4.051688671112060546, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+36, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1904.4376220703125, 6460.05712890625, 29.12241554260253906, 3.937356948852539062, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+37, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2093.68359375, 6662.87841796875, 41.90743637084960937, 2.240368366241455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+38, 115093, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1928.5123291015625, 6489.83349609375, 19.37971305847167968, 6.153987884521484375, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Clefthoof (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+39, 115093, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2243.385498046875, 6737.5146484375, -5.29166126251220703, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Clefthoof (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+40, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2053.3056640625, 6714.94287109375, 37.32355499267578125, 4.961896419525146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+41, 115093, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1935.7216796875, 6450.81201171875, 26.82182884216308593, 5.976571083068847656, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Clefthoof (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+42, 115097, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2145.372314453125, 6816.552734375, -6.32551097869873046, 2.934223651885986328, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Tortured Earth Spirit (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+43, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2006.8836669921875, 6602.23291015625, 37.8780364990234375, 2.231958627700805664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+44, 115097, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2155.890380859375, 6736.73046875, -5.67094278335571289, 2.03881072998046875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Tortured Earth Spirit (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+45, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 1, -1982.3367919921875, 6556.9912109375, 11.66410064697265625, 5.717782020568847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+46, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2194.1025390625, 6726.0283203125, -6.64905738830566406, 4.893116474151611328, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+47, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1925.601318359375, 6409.798828125, 39.44009780883789062, 0.471566617488861083, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+48, 115093, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2267.90625, 6718.73779296875, -2.2794501781463623, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Clefthoof (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+49, 115076, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2066.01904296875, 6711.17724609375, 37.22791290283203125, 4.956846237182617187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+50, 115093, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2169.9462890625, 6703.43603515625, -2.01279377937316894, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Clefthoof (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+51, 114925, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2055.350830078125, 6721.10400390625, 38.74813461303710937, 5.124923229217529296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+52, 115070, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2070.052734375, 6611.05615234375, 41.89958953857421875, 2.905430793762207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+53, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2001.8697509765625, 6617.38720703125, 36.54923248291015625, 2.112817764282226562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+54, 115083, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2015.0660400390625, 6605.73095703125, 36.59558868408203125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Orc Drum (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+55, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1996.125, 6611.376953125, 38.0279388427734375, 2.205353975296020507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+56, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1999.2708740234375, 6604.03466796875, 38.675506591796875, 2.205353975296020507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+57, 115086, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2017.111572265625, 6599.4423828125, 12.32046890258789062, 0.916941821575164794, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Adder (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+58, 115087, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2067.678466796875, 6707.74169921875, 11.95703125, 1.383979082107543945, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Rat (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+59, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2001.2847900390625, 6588.96435546875, 11.84334468841552734, 3.580499649047851562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+60, 115091, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1912.360595703125, 6485.26708984375, 21.90256881713867187, 3.82457280158996582, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elekk (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+61, 114925, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2084.1494140625, 6700.19775390625, 37.39508819580078125, 5.482541084289550781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+62, 114925, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2079.6806640625, 6703.87939453125, 37.3070220947265625, 5.427005290985107421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+63, 115070, 1505, 7822, 7822, '0', '0', 0, 0, 1, -1990.857421875, 6646.03515625, 42.10271453857421875, 5.413291454315185546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+64, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2031.6927490234375, 6587.75, 38.73274993896484375, 1.89630281925201416, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+65, 114925, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2057.56591796875, 6707.642578125, 36.4822540283203125, 5.03397989273071289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+66, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2003.7882080078125, 6609.2646484375, 37.32154464721679687, 2.205353975296020507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+67, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2004.1910400390625, 6588.15625, 11.97482681274414062, 0.253675132989883422, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+68, 115070, 1505, 7822, 7822, '0', '0', 0, 0, 1, -1995.7498779296875, 6618.0712890625, 36.80854415893554687, 2.520666837692260742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+69, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -1997.63720703125, 6622.24755859375, 36.61750411987304687, 2.737583637237548828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+70, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2019.8125, 6591.63037109375, 38.4921722412109375, 1.839002370834350585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+71, 115069, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2017.87158203125, 6604.109375, 36.56983184814453125, 1.938249707221984863, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Leader (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+72, 115107, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2099.25341796875, 6731.22900390625, -0.28424787521362304, 2.701325178146362304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Rider (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@CGUID+73, 114925, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2091.2431640625, 6698.6865234375, 38.03900146484375, 5.482541084289550781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+74, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2026.626708984375, 6592.4755859375, 38.04468536376953125, 1.998313069343566894, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+75, 114925, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2052.267333984375, 6709.453125, 36.46075057983398437, 4.662768840789794921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Warsong Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+76, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 1, -1976.8992919921875, 6562.61181640625, 10.78506660461425781, 5.490165233612060546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+77, 115070, 1505, 7822, 7822, '0', '0', 0, 0, 1, -2036.46435546875, 6595.59033203125, 36.6315155029296875, 0.324676960706710815, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Grunt (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+78, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2009.857666015625, 6610.12744140625, 36.55633163452148437, 2.205384016036987304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)
(@CGUID+79, 115068, 1505, 7822, 7822, '0', '0', 0, 0, 0, -2040.2882080078125, 6598.5087890625, 36.28379058837890625, 1.425915002822875976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Frostwolf Warrior (Area: Nagrand Arena - Difficulty: 0) CreateObject1 (Auras: 228832 - Mod Scale Increase)

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115069 AND `DifficultyID`=0); -- 115069 (Frostwolf Leader) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115070 AND `DifficultyID`=0); -- 115070 (Frostwolf Grunt) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=117079 AND `DifficultyID`=0); -- 117079 (Warsong Grunt) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115077 AND `DifficultyID`=0); -- 115077 (Warsong Leader) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115097 AND `DifficultyID`=0); -- 115097 (Tortured Earth Spirit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115093 AND `DifficultyID`=0); -- 115093 (Clefthoof) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115091 AND `DifficultyID`=0); -- 115091 (Elekk) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115086 AND `DifficultyID`=0); -- 115086 (Adder) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=117078 AND `DifficultyID`=0); -- 117078 (Frostwolf Grunt) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=63305 WHERE (`Entry`=115083 AND `DifficultyID`=0); -- 115083 (Orc Drum) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115076 AND `DifficultyID`=0); -- 115076 (Warsong Grunt) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115107 AND `DifficultyID`=0); -- 115107 (Warsong Rider) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115068 AND `DifficultyID`=0); -- 115068 (Frostwolf Warrior) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=114925 AND `DifficultyID`=0); -- 114925 (Warsong Warrior) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=115109 AND `DifficultyID`=0); -- 115109 (Frost Wolf) - CanSwim

UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=115069; -- Frostwolf Leader
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry` IN (115070, 117078); -- Frostwolf Grunt
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry` IN (117079, 115076); -- Warsong Grunt
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=115077; -- Warsong Leader
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x8000000 WHERE `entry`=115097; -- Tortured Earth Spirit
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x8000000 WHERE `entry`=115093; -- Clefthoof
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x4000000 WHERE `entry`=115091; -- Elekk
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=115086; -- Adder
UPDATE `creature_template` SET `unit_flags`=0x2000300, `unit_flags3`=0x40000000 WHERE `entry`=115083; -- Orc Drum
UPDATE `creature_template` SET `unit_flags`=0x2000040 WHERE `entry`=115107; -- Warsong Rider
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=115068; -- Frostwolf Warrior
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114925; -- Warsong Warrior
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=115109; -- Frost Wolf

UPDATE `gameobject_template_addon` SET `flags`=0x20 WHERE `entry` IN (260528, 260527); -- Gate

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+79;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 3920, 1505, 7822, 7822, '0', '0', 0, -2972.7275390625, 6395.17333984375, 96.247467041015625, 0.445056945085525512, 0, 0, 0.220696449279785156, 0.975342512130737304, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+1, 3921, 1505, 7822, 7822, '0', '0', 0, -2977.84375, 6399.0615234375, 96.247467041015625, 2.897245407104492187, 0, 0, 0.99254608154296875, 0.121869951486587524, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+2, 3926, 1505, 7822, 7822, '0', '0', 0, -2966.902587890625, 6372.12841796875, 96.25653076171875, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+3, 3927, 1505, 7822, 7822, '0', '0', 0, -2971.53564453125, 6381.42626953125, 96.25653076171875, 2.434729337692260742, 0, 0, 0.938190460205078125, 0.346119433641433715, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+4, 3925, 1505, 7822, 7822, '0', '0', 0, -2976.98876953125, 6359.88818359375, 96.3812255859375, 2.452184438705444335, 0, 0, 0.941175460815429687, 0.337918221950531005, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+5, 182155, 1505, 7822, 7822, '0', '0', 0, -2803.076904296875, 6466.1484375, 64.8544158935546875, 5.811948776245117187, 0, 0, -0.2334442138671875, 0.9723702073097229, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+6, 182158, 1505, 7822, 7822, '0', '0', 0, -2788.743408203125, 6456.1123046875, 64.8544158935546875, 5.811948776245117187, 0, 0, -0.2334442138671875, 0.9723702073097229, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+7, 182159, 1505, 7822, 7822, '0', '0', 0, -2799.961181640625, 6455.41455078125, 78.30356597900390625, 0.549776852130889892, 0, 0, 0.271439552307128906, 0.962455451488494873, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+8, 182156, 1505, 7822, 7822, '0', '0', 0, -2786.304443359375, 6469.669921875, 113.1583709716796875, 5.672322273254394531, 0, 0, -0.3007049560546875, 0.953717231750488281, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+9, 182157, 1505, 7822, 7822, '0', '0', 0, -2787.479248046875, 6472.81689453125, 64.8544158935546875, 5.811948776245117187, 0, 0, -0.2334442138671875, 0.9723702073097229, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+10, 182162, 1505, 7822, 7822, '0', '0', 0, -2795.437744140625, 6456.62646484375, 113.1583709716796875, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+11, 182160, 1505, 7822, 7822, '0', '0', 0, -2798.31689453125, 6475.41748046875, 78.30356597900390625, 0.6370430588722229, 0, 0, 0.313162803649902343, 0.949699461460113525, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+12, 182161, 1505, 7822, 7822, '0', '0', 0, -2781.51171875, 6463.513671875, 78.30356597900390625, 0.479964137077331542, 0, 0, 0.237685203552246093, 0.971342265605926513, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+13, 260450, 1505, 7822, 7822, '0', '0', 0, -2102.302490234375, 6636.31689453125, 36.524444580078125, 0.318290919065475463, -0.00754261016845703, -0.00261402130126953, 0.158458709716796875, 0.987333357334136962, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench014 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+14, 260451, 1505, 7822, 7822, '0', '0', 0, -2103.8095703125, 6640.89111328125, 36.441436767578125, 0.318289607763290405, -0.00714921951293945, -0.00247764587402343, 0.158459663391113281, 0.987336456775665283, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench015 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+15, 260448, 1505, 7822, 7822, '0', '0', 0, -2099.73095703125, 6628.4404296875, 36.5721282958984375, 0.318270504474639892, 0, 0, 0.158464431762695312, 0.987364709377288818, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool037 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+16, 260449, 1505, 7822, 7822, '0', '0', 0, -2100.788330078125, 6631.720703125, 36.55778121948242187, 0.318271011114120483, 0.002106189727783203, 0.000729560852050781, 0.158463478088378906, 0.987362325191497802, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench013 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+17, 260454, 1505, 7822, 7822, '0', '0', 0, -2106.9091796875, 6639.86962890625, 37.15923309326171875, 0.318270504474639892, 0, 0, 0.158464431762695312, 0.987364709377288818, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench009 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+18, 260455, 1505, 7822, 7822, '0', '0', 0, -2105.402099609375, 6635.29541015625, 37.14840316772460937, 0.318272054195404052, -0.0016646385192871, -0.00057697296142578, 0.158464431762695312, 0.987363100051879882, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench008 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+19, 260452, 1505, 7822, 7822, '0', '0', 0, -2104.8642578125, 6644.021484375, 36.38921356201171875, 0.318270504474639892, 0, 0, 0.158464431762695312, 0.987364709377288818, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool040 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+20, 260453, 1505, 7822, 7822, '0', '0', 0, -2107.96630859375, 6642.9990234375, 37.15330123901367187, 0.318270504474639892, 0, 0, 0.158464431762695312, 0.987364709377288818, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool041 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+21, 260458, 1505, 7822, 7822, '0', '0', 0, -2105.610595703125, 6626.50341796875, 37.92354583740234375, 0.318270504474639892, 0, 0, 0.158464431762695312, 0.987364709377288818, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool039 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+22, 260459, 1505, 7822, 7822, '0', '0', 0, -2106.65478515625, 6629.7822265625, 37.877166748046875, 0.318310946226119995, -0.01030635833740234, -0.00357246398925781, 0.15845489501953125, 0.987305939197540283, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench010 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+23, 260456, 1505, 7822, 7822, '0', '0', 0, -2103.887939453125, 6630.69970703125, 37.17110443115234375, 0.318280011415481567, 0.005214691162109375, 0.001807212829589843, 0.158461570739746093, 0.987349748611450195, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench007 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+24, 260457, 1505, 7822, 7822, '0', '0', 0, -2102.8330078125, 6627.41845703125, 37.18374252319335937, 0.318270504474639892, 0, 0, 0.158464431762695312, 0.987364709377288818, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool038 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+25, 260462, 1505, 7822, 7822, '0', '0', 0, -2110.744140625, 6642.083984375, 37.62420654296875, 0.318270504474639892, 0, 0, 0.158464431762695312, 0.987364709377288818, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool042 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+26, 260463, 1505, 7822, 7822, '0', '0', 0, -2093.8212890625, 6618.39306640625, 36.22134017944335937, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool001 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+27, 260460, 1505, 7822, 7822, '0', '0', 0, -2108.16845703125, 6634.37744140625, 37.77321243286132812, 0.318310946226119995, -0.01030635833740234, -0.00357246398925781, 0.15845489501953125, 0.987305939197540283, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench011 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+28, 260461, 1505, 7822, 7822, '0', '0', 0, -2109.675048828125, 6638.95068359375, 37.66974639892578125, 0.318310946226119995, -0.01030635833740234, -0.00357246398925781, 0.15845489501953125, 0.987305939197540283, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench012 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+29, 260466, 1505, 7822, 7822, '0', '0', 0, -2096.29345703125, 6611.82080078125, 38.01398468017578125, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench006 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+30, 260467, 1505, 7822, 7822, '0', '0', 0, -2094.088134765625, 6613.72021484375, 37.16115570068359375, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench001 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+31, 260464, 1505, 7822, 7822, '0', '0', 0, -2096.296142578125, 6616.26171875, 37.18374252319335937, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool012 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+32, 260465, 1505, 7822, 7822, '0', '0', 0, -2098.51220703125, 6614.35302734375, 38.08810043334960937, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool018 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+33, 260470, 1505, 7822, 7822, '0', '0', 0, -2090.742919921875, 6609.8359375, 37.16115570068359375, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench002 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+34, 3842, 1505, 7822, 7822, '0', '0', 0, -2892.668701171875, 6478.32861328125, 87.28089141845703125, 6.204647541046142578, 0, 0, -0.03925895690917968, 0.999229073524475097, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+35, 260471, 1505, 7822, 7822, '0', '0', 0, -2092.9482421875, 6607.9365234375, 38.01398468017578125, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench005 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+36, 3843, 1505, 7822, 7822, '0', '0', 0, -2888.712890625, 6467.3125, 101.672637939453125, 5.122544288635253906, 0, 0, -0.54829216003417968, 0.836286902427673339, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+37, 260468, 1505, 7822, 7822, '0', '0', 0, -2091.654052734375, 6615.81640625, 36.31757354736328125, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench004 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+38, 3840, 1505, 7822, 7822, '0', '0', 0, -2897.861572265625, 6466.7685546875, 82.77323150634765625, 6.204647541046142578, 0, 0, -0.03925895690917968, 0.999229073524475097, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+39, 260469, 1505, 7822, 7822, '0', '0', 0, -2088.308837890625, 6611.93212890625, 36.31757354736328125, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Bench003 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+40, 3841, 1505, 7822, 7822, '0', '0', 0, -2889.394775390625, 6466.1396484375, 82.77323150634765625, 4.668757438659667968, 0, 0, -0.72236347198486328, 0.691513597965240478, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+41, 260474, 1505, 7822, 7822, '0', '0', 0, -2086.165283203125, 6609.5029296875, 36.22134017944335937, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool006 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+42, 260472, 1505, 7822, 7822, '0', '0', 0, -2090.856201171875, 6605.46337890625, 38.08810043334960937, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool015 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+43, 3844, 1505, 7822, 7822, '0', '0', 0, -2898.41552734375, 6468.00390625, 101.636993408203125, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+44, 260473, 1505, 7822, 7822, '0', '0', 0, -2088.64013671875, 6607.37158203125, 37.18374252319335937, 0.710968554019927978, 0, 0, 0.348044395446777343, 0.937478065490722656, 7200, 255, 1, 63305), -- Doodad_6OC_OrcClans_Stool009 (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+45, 3845, 1505, 7822, 7822, '0', '0', 0, -2884.7822265625, 6453.44091796875, 82.77323150634765625, 0.593411982059478759, 0, 0, 0.292371749877929687, 0.956304728984832763, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+46, 174953, 1505, 7822, 7822, '0', '0', 0, -2958.7744140625, 6349.568359375, 96.247467041015625, 1.614428043365478515, 0, 0, 0.722363471984863281, 0.691513597965240478, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+47, 184303, 1505, 7822, 7822, '0', '0', 0, -2518.51025390625, 7360.1025390625, 10.62232398986816406, 4.057007312774658203, 0, 0, -0.89706802368164062, 0.441892504692077636, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+48, 260527, 1505, 7822, 7822, '0', '0', 0, -2067.72216796875, 6699.3857421875, 11.90679931640625, 2.0635986328125, 0, 0, 0.858223915100097656, 0.513275444507598876, 7200, 255, 1, 63305), -- Gate (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+49, 260528, 1505, 7822, 7822, '0', '0', 0, -2019.23779296875, 6609.09765625, 11.90679931640625, 5.205194473266601562, 0, 0, -0.51327419281005859, 0.858224689960479736, 7200, 255, 1, 63305), -- Gate (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+50, 182155, 1505, 7822, 7822, '0', '0', 0, -2999.412109375, 6515.7041015625, 99.32613372802734375, 2.468022584915161132, 0, 0, 0.943821907043457031, 0.330454498529434204, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+51, 3839, 1505, 7822, 7822, '0', '0', 0, -2903.89111328125, 6454.92626953125, 82.77323150634765625, 0.593411982059478759, 0, 0, 0.292371749877929687, 0.956304728984832763, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+52, 182159, 1505, 7822, 7822, '0', '0', 0, -3000.30712890625, 6526.84521484375, 112.7752761840820312, 3.489048957824707031, 0, 0, -0.98494720458984375, 0.172855526208877563, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+53, 3915, 1505, 7822, 7822, '0', '0', 0, -2982.453125, 6376.74755859375, 96.3812255859375, 1.474801421165466308, 0, 0, 0.672366142272949218, 0.740218758583068847, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+54, 3913, 1505, 7822, 7822, '0', '0', 0, -2965.822021484375, 6361.5126953125, 96.25653076171875, 1.631881952285766601, 0, 0, 0.72837066650390625, 0.685183286666870117, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+55, 3919, 1505, 7822, 7822, '0', '0', 0, -2960.926513671875, 6343.6005859375, 96.247467041015625, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+56, 3934, 1505, 7822, 7822, '0', '0', 0, -2974.97802734375, 6340.20166015625, 96.25653076171875, 0.863936781883239746, 0, 0, 0.418659210205078125, 0.908143401145935058, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+57, 3932, 1505, 7822, 7822, '0', '0', 0, -2991.244384765625, 6394.19677734375, 96.247833251953125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+58, 185136, 1505, 7822, 7822, '0', '0', 0, -2739.054443359375, 7339.7470703125, 43.42174530029296875, 2.67023324966430664, 0, 0, 0.972355842590332031, 0.23350401222705841, 7200, 255, 1, 63305), -- Cookpot (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+59, 182158, 1505, 7822, 7822, '0', '0', 0, -3011.43603515625, 6528.416015625, 99.32613372802734375, 2.468022584915161132, 0, 0, 0.943821907043457031, 0.330454498529434204, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+60, 182162, 1505, 7822, 7822, '0', '0', 0, -3004.98193359375, 6526.5673828125, 147.630096435546875, 3.131257534027099609, 0, 0, 0.999986648559570312, 0.005167482886463403, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+61, 182160, 1505, 7822, 7822, '0', '0', 0, -3005.937255859375, 6507.58056640625, 112.7752761840820312, 3.576314449310302734, 0, 0, -0.97646999359130859, 0.215653300285339355, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+62, 182161, 1505, 7822, 7822, '0', '0', 0, -3020.007568359375, 6522.619140625, 112.7752761840820312, 3.419228076934814453, 0, 0, -0.99038028717041015, 0.138372182846069335, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+63, 182156, 1505, 7822, 7822, '0', '0', 0, -3016.550048828125, 6515.625, 147.630096435546875, 2.328395366668701171, 0, 0, 0.918471336364746093, 0.395487546920776367, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+64, 3912, 1505, 7822, 7822, '0', '0', 0, -2984.95361328125, 6366.64013671875, 96.4288330078125, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+65, 182157, 1505, 7822, 7822, '0', '0', 0, -3016.03125, 6512.30615234375, 99.32613372802734375, 2.468022584915161132, 0, 0, 0.943821907043457031, 0.330454498529434204, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+66, 3922, 1505, 7822, 7822, '0', '0', 0, -3007.69287109375, 6368.62060546875, 96.3812255859375, 1.474801421165466308, 0, 0, 0.672366142272949218, 0.740218758583068847, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+67, 3923, 1505, 7822, 7822, '0', '0', 0, -3010.153564453125, 6388.41552734375, 96.25653076171875, 4.092801570892333984, 0, 0, -0.88901615142822265, 0.457875818014144897, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+68, 3924, 1505, 7822, 7822, '0', '0', 0, -3002.31103515625, 6351.923828125, 96.3812255859375, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+69, 3931, 1505, 7822, 7822, '0', '0', 0, -2993.4560546875, 6334.37255859375, 96.25653076171875, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+70, 3929, 1505, 7822, 7822, '0', '0', 0, -3000.080810546875, 6362.01513671875, 96.4288330078125, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+71, 3917, 1505, 7822, 7822, '0', '0', 0, -3012.218994140625, 6333.49853515625, 96.247467041015625, 3.874636650085449218, 0, 0, -0.9335794448852539, 0.358370482921600341, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+72, 3930, 1505, 7822, 7822, '0', '0', 0, -3018.06005859375, 6356.88427734375, 96.25653076171875, 5.12254190444946289, 0, 0, -0.54829311370849609, 0.83628624677658081, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+73, 3928, 1505, 7822, 7822, '0', '0', 0, -3013.137939453125, 6347.3759765625, 96.25653076171875, 5.506513595581054687, 0, 0, -0.37864875793457031, 0.925540447235107421, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+74, 3933, 1505, 7822, 7822, '0', '0', 0, -3018.6201171875, 6369.68017578125, 96.25653076171875, 4.651303291320800781, 0, 0, -0.72837066650390625, 0.685183286666870117, 7200, 255, 1, 63305), -- Blazing Fire (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+75, 3914, 1505, 7822, 7822, '0', '0', 0, -3026.064208984375, 6378.92041015625, 96.247467041015625, 4.756022453308105468, 0, 0, -0.6915130615234375, 0.722363948822021484, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+76, 3918, 1505, 7822, 7822, '0', '0', 0, -3007.2529296875, 6329.82958984375, 96.247467041015625, 0.043632153421640396, 0, 0, 0.021814346313476562, 0.99976205825805664, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+77, 3916, 1505, 7822, 7822, '0', '0', 0, -3023.7890625, 6384.9306640625, 96.247467041015625, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 7200, 255, 1, 63305), -- Burning Embers (Area: Nagrand Arena - Difficulty: 0) CreateObject1
(@OGUID+78, 184663, 1505, 7822, 7822, '0', '0', 0, -2092.829833984375, 6628.21630859375, 12.82109546661376953, 0, 0, 0, 0, 1, 360, 255, 1, 63305), -- Shadow Sight (Area: Nagrand Arena - Difficulty: 0) CreateObject2
(@OGUID+79, 184663, 1505, 7822, 7822, '0', '0', 0, -1994.892333984375, 6680.19775390625, 13.06343936920166015, 0, 0, 0, 0, 1, 360, 255, 1, 63305); -- Shadow Sight (Area: Nagrand Arena - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+79;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Burning Embers
(@OGUID+1, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Burning Embers
(@OGUID+2, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+3, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+4, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+5, 0, 0, 0.887010812759399414, -0.4617486298084259, 0, 0), -- Blazing Fire
(@OGUID+6, 0, 0, 0.887010812759399414, -0.4617486298084259, 0, 0), -- Blazing Fire
(@OGUID+7, 0, 0, 0.887010812759399414, -0.4617486298084259, 0, 0), -- Blazing Fire
(@OGUID+8, 0, 0, 0.887010812759399414, -0.4617486298084259, 0, 0), -- Blazing Fire
(@OGUID+9, 0, 0, 0.887010812759399414, -0.4617486298084259, 0, 0), -- Blazing Fire
(@OGUID+10, 0, 0, 0.887010812759399414, -0.4617486298084259, 0, 0), -- Blazing Fire
(@OGUID+11, 0, 0, 0.887010812759399414, -0.4617486298084259, 0, 0), -- Blazing Fire
(@OGUID+12, 0, 0, 0.887010812759399414, -0.4617486298084259, 0, 0), -- Blazing Fire
(@OGUID+13, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench014
(@OGUID+14, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench015
(@OGUID+15, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool037
(@OGUID+16, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench013
(@OGUID+17, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench009
(@OGUID+18, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench008
(@OGUID+19, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool040
(@OGUID+20, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool041
(@OGUID+21, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool039
(@OGUID+22, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench010
(@OGUID+23, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench007
(@OGUID+24, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool038
(@OGUID+25, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool042
(@OGUID+26, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool001
(@OGUID+27, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench011
(@OGUID+28, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench012
(@OGUID+29, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench006
(@OGUID+30, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench001
(@OGUID+31, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool012
(@OGUID+32, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool018
(@OGUID+33, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench002
(@OGUID+34, 0, 0, -0.73432236909866333, 0.678800940513610839, 0, 0), -- Burning Embers
(@OGUID+35, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench005
(@OGUID+36, 0, 0, -0.73432236909866333, 0.678800940513610839, 0, 0), -- Burning Embers
(@OGUID+37, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench004
(@OGUID+38, 0, 0, -0.73432236909866333, 0.678800940513610839, 0, 0), -- Burning Embers
(@OGUID+39, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Bench003
(@OGUID+40, 0, 0, -0.73432236909866333, 0.678800940513610839, 0, 0), -- Burning Embers
(@OGUID+41, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool006
(@OGUID+42, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool015
(@OGUID+43, 0, 0, -0.73432236909866333, 0.678800940513610839, 0, 0), -- Burning Embers
(@OGUID+44, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Doodad_6OC_OrcClans_Stool009
(@OGUID+45, 0, 0, -0.73432236909866333, 0.678800940513610839, 0, 0), -- Burning Embers
(@OGUID+46, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Burning Embers
(@OGUID+47, 0, 0, 0.441892117261886596, 0.897068262100219726, 0, 0), -- Blazing Fire
(@OGUID+48, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Gate
(@OGUID+49, 0, 0, 0.969796299934387207, -0.24391628801822662, 0, 0), -- Gate
(@OGUID+50, 0, 0, 0.36980605125427246, 0.929108977317810058, 0, 0), -- Blazing Fire
(@OGUID+51, 0, 0, -0.73432236909866333, 0.678800940513610839, 0, 0), -- Burning Embers
(@OGUID+52, 0, 0, 0.36980605125427246, 0.929108977317810058, 0, 0), -- Blazing Fire
(@OGUID+53, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+54, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+55, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Burning Embers
(@OGUID+56, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+57, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+58, 0, 0, 0.97813570499420166, 0.207967907190322875, 0, 0), -- Cookpot
(@OGUID+59, 0, 0, 0.36980605125427246, 0.929108977317810058, 0, 0), -- Blazing Fire
(@OGUID+60, 0, 0, 0.36980605125427246, 0.929108977317810058, 0, 0), -- Blazing Fire
(@OGUID+61, 0, 0, 0.36980605125427246, 0.929108977317810058, 0, 0), -- Blazing Fire
(@OGUID+62, 0, 0, 0.36980605125427246, 0.929108977317810058, 0, 0), -- Blazing Fire
(@OGUID+63, 0, 0, 0.36980605125427246, 0.929108977317810058, 0, 0), -- Blazing Fire
(@OGUID+64, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+65, 0, 0, 0.36980605125427246, 0.929108977317810058, 0, 0), -- Blazing Fire
(@OGUID+66, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+67, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+68, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+69, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+70, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+71, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Burning Embers
(@OGUID+72, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+73, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+74, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Blazing Fire
(@OGUID+75, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Burning Embers
(@OGUID+76, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0), -- Burning Embers
(@OGUID+77, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0); -- Burning Embers

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Nagrand Arena (Legion) - Shadow sight', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+78),
(@SPAWN_GROUP, 1, @OGUID+79);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

SET @MOVERGUID := @CGUID+72;
SET @ENTRY := 115107;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x01, NULL, 'Warsong Rider - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2081.4766, 6721.0654, 9.035518, NULL, 0),
(@PATH, 1, -2086.2012, 6724.7734, 5.3653135, NULL, 0),
(@PATH, 2, -2086.9883, 6725.3916, 4.613757, NULL, 0),
(@PATH, 3, -2087.7754, 6726.01, 4.243466, NULL, 0),
(@PATH, 4, -2092.165, 6729.9985, 1.7703848, NULL, 0),
(@PATH, 5, -2098.8665, 6737.863, -1.403483, NULL, 3215);

UPDATE `creature` SET `position_x`=-2081.4766, `position_y`=6721.0654, `position_z`=9.035518, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '228832');

SET @MOVERGUID := @CGUID+52;
SET @ENTRY := 115070;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Frostwolf Grunt - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2067.4285, 6610.425, 41.89959, NULL, 0),
(@PATH, 1, -2070.0527, 6611.056, 41.89959, NULL, 0),
(@PATH, 2, -2072.677, 6611.6875, 41.89959, NULL, 0),
(@PATH, 3, -2077.4722, 6608.053, 41.89959, NULL, 0),
(@PATH, 4, -2077.4722, 6608.053, 41.89959, NULL, 0),
(@PATH, 5, -2079.8196, 6603.165, 41.89959, NULL, 0),
(@PATH, 6, -2077.0764, 6597.303, 41.89959, NULL, 0),
(@PATH, 7, -2069.5364, 6593.737, 41.89959, NULL, 0),
(@PATH, 8, -2062.9097, 6597.0957, 41.89959, NULL, 0),
(@PATH, 9, -2061.4045, 6603.692, 41.89959, NULL, 0),
(@PATH, 10, -2063.3906, 6608.8447, 41.89959, NULL, 0);

UPDATE `creature` SET `position_x`=-2067.4285, `position_y`=6610.425, `position_z`=41.89959, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '228832');

SET @MOVERGUID := @CGUID+68;
SET @ENTRY := 115070;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Frostwolf Grunt - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1995.9948, 6618.2466, 36.79883, NULL, 0),
(@PATH, 1, -2012.0278, 6605.0625, 36.72482, NULL, 0),
(@PATH, 2, -1995.9948, 6618.2466, 36.79883, NULL, 0),
(@PATH, 3, -1991.4288, 6614.7734, 37.87625, NULL, 0);

UPDATE `creature` SET `position_x`=-1995.9948, `position_y`=6618.2466, `position_z`=36.79883, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '228832');

SET @MOVERGUID := @CGUID+77;
SET @ENTRY := 115070;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Frostwolf Grunt - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2038.1216, 6595.1084, 36.649426, NULL, 37),
(@PATH, 1, -2021.0486, 6600.7812, 36.77132, NULL, 37);

UPDATE `creature` SET `position_x`=-2038.1216, `position_y`=6595.1084, `position_z`=36.649426, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '228832');

SET @MOVERGUID := @CGUID+7;
SET @ENTRY := 115076;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Warsong Grunt - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2049.2917, 6712.983, 36.64339, NULL, 0),
(@PATH, 1, -2060.0815, 6709.8457, 36.61309, NULL, 0),
(@PATH, 2, -2067.5676, 6707.783, 36.69522, NULL, 0),
(@PATH, 3, -2060.1816, 6709.8184, 36.597572, NULL, 0),
(@PATH, 4, -2049.2917, 6712.983, 36.64339, NULL, 0),
(@PATH, 5, -2046.9774, 6714.94, 36.832428, NULL, 0),
(@PATH, 6, -2046.9497, 6718.0166, 37.529026, NULL, 0);

UPDATE `creature` SET `position_x`=-2049.2917, `position_y`=6712.983, `position_z`=36.64339, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '228832');

SET @MOVERGUID := @CGUID+37;
SET @ENTRY := 115076;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Warsong Grunt - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2098.0989, 6668.4565, 41.95938, NULL, 0),
(@PATH, 1, -2102.7622, 6670.21, 41.97126, NULL, 0),
(@PATH, 2, -2108.0347, 6665.598, 42.29292, NULL, 0),
(@PATH, 3, -2110.4705, 6655.403, 41.89959, NULL, 0),
(@PATH, 4, -2103.073, 6650.6694, 41.91811, NULL, 0),
(@PATH, 5, -2098.0208, 6651.752, 41.948643, NULL, 0),
(@PATH, 6, -2092.816, 6656.836, 41.9653, NULL, 0),
(@PATH, 7, -2093.0696, 6664.4854, 41.89959, NULL, 0);

UPDATE `creature` SET `position_x`=-2098.0989, `position_y`=6668.4565, `position_z`=41.95938, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '228832');

SET @MOVERGUID := @CGUID+18;
SET @ENTRY := 115076;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Warsong Grunt - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2098.0989, 6668.4565, 41.95938, NULL, 0),
(@PATH, 1, -2102.7622, 6670.21, 41.97126, NULL, 0),
(@PATH, 2, -2108.0347, 6665.598, 42.29292, NULL, 0),
(@PATH, 3, -2110.4705, 6655.403, 41.89959, NULL, 0),
(@PATH, 4, -2103.073, 6650.6694, 41.91811, NULL, 0),
(@PATH, 5, -2098.0208, 6651.752, 41.948643, NULL, 0),
(@PATH, 6, -2092.816, 6656.836, 41.9653, NULL, 0),
(@PATH, 7, -2093.0696, 6664.4854, 41.89959, NULL, 0);

UPDATE `creature` SET `position_x`=-2098.0989, `position_y`=6668.4565, `position_z`=41.95938, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '228832');

SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 115076;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Warsong Grunt - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2071.4185, 6706.617, 36.64514, NULL, 0),
(@PATH, 1, -2090.5764, 6690.8594, 36.74643, NULL, 170);

UPDATE `creature` SET `position_x`=-2071.4185, `position_y`=6706.617, `position_z`=36.64514, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '228832');
