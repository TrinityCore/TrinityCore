SET @CGUID := 396712;
SET @OGUID := 253212;
SET @SGROUP := 342;
SET @EVENT := 2;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=13636; -- Strange Snowman
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=15664; -- Metzen the Reindeer
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=54499; -- The Abominable Greench
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=54509; -- Nasty Little Helper
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `speed_run`=1, `unit_flags`=33554432, `unit_flags3`=524289 WHERE `entry`=54519; -- Winter Veil Tree
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags`=33554432, `unit_flags2`=32768, `unit_flags3`=524289 WHERE `entry`=54523; -- Strange Snowman
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=54524; -- Wicked Little Helper
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=55003; -- Rotten Little Helper

DELETE FROM `creature_template_addon` WHERE `entry` IN (13636, 54499, 54509, 54519, 54523, 54524, 55003);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(13636, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 13636 (Strange Snowman)
(54499, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 54499 (The Abominable Greench)
(54509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 54509 (Nasty Little Helper)
(54519, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 54519 (Winter Veil Tree)
(54523, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 54523 (Strange Snowman)
(54524, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 54524 (Wicked Little Helper)
(55003, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '102754'); -- 55003 (Rotten Little Helper)

UPDATE `creature_template_addon` SET `PvpFlags`=0 WHERE `entry`=15664; -- 15664 (Metzen the Reindeer)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (54519, 54523);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(54519, 0, 0, 1, 1, 0, 0, NULL),
(54523, 0, 0, 1, 1, 0, 0, NULL);

-- Vehicle data
DELETE FROM `vehicle_template_accessory` WHERE `entry`=54499;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(54499, 54524, 1, 1, 'The Abominable Greench - Wicked Little Helper', 8, 0), -- The Abominable Greench - Wicked Little Helper
(54499, 54509, 0, 1, 'The Abominable Greench - Nasty Little Helper', 8, 0); -- The Abominable Greench - Nasty Little Helper

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=54499 AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(54499, 46598, 0, 0);

-- Gossips
UPDATE `gossip_menu` SET `VerifiedBuild`=47187 WHERE (`MenuID`=6761 AND `TextID`=8077) OR (`MenuID`=6763 AND `TextID`=8076);

UPDATE `gossip_menu_option` SET `GossipOptionID`=32641, `VerifiedBuild`=47187 WHERE (`MenuID`=6763 AND `OptionID`=0);

-- Models
UPDATE `creature_model_info` SET `BoundingRadius`=0.168299987912178039, `CombatReach`=0.824999928474426269, `VerifiedBuild`=47187 WHERE `DisplayID`=38827;
UPDATE `creature_model_info` SET `VerifiedBuild`=47187 WHERE `DisplayID` IN (38830, 38837, 38845, 38842, 38834, 39021, 15903, 14327, 14326, 13383, 13730, 7031, 32547, 11552, 3724);

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (55003,54524,54523,54519,54509,54499,15664,14221,13636,2453));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(55003, 0, 0, 0, 296, 47187),
(54524, 0, 0, 0, 296, 47187),
(54523, 0, 0, 0, 296, 47187),
(54519, 0, 0, 0, 296, 47187),
(54509, 0, 0, 0, 296, 47187),
(54499, 0, 0, 0, 296, 47187),
(15664, 0, 0, 0, 417, 47187),
(13636, 0, 0, 0, 11, 47187);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=47187 WHERE (`DifficultyID`=0 AND `Entry` IN (121200,49111,47484,43499,26614,24207,19907,14284,13777,2480,2422,2421,2420,2417,2416,2350,2318,2287,2257,2256,2255,2254,2253,2252,2098,89));

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=417, `VerifiedBuild`=47187 WHERE `entry` IN (209497, 209506); -- Stolen Treats

UPDATE `gameobject_template_addon` SET `flags`=262148 WHERE `entry` IN (209506, 209497); -- Stolen Treats
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=209474; -- Metzen Cage Post
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=209473; -- Metzen Cage Segment

-- Quests
DELETE FROM `creature_queststarter` WHERE (`id`=13636 AND `quest`=7043);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(13636, 7043, 47187); -- You're a Mean One... offered Strange Snowman

DELETE FROM `game_event_creature_quest` WHERE (`id`=13636 AND `quest`=7043);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 13636, 0, 267, 1683, '0', 0, 0, 0, 0, 147.423004150390625, -208.91400146484375, 153.490325927734375, 0.157079637050628662, 120, 0, 0, 2239, 0, 0, 0, 0, 0, 47187), -- Strange Snowman (Area: Growless Cave - Difficulty: 0)
(@CGUID+1, 15664, 0, 267, 1683, '0', 0, 0, 0, 0, 230.6215362548828125, -295.328125, 151.4381103515625, 3.31612563133239746, 900, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Metzen the Reindeer (Area: Growless Cave - Difficulty: 0)
(@CGUID+2, 54499, 0, 267, 1683, '0', 0, 0, 0, 0, 213.4479217529296875, -267.296875, 145.215362548828125, 3.176499128341674804, 600, 0, 0, 5781440, 0, 0, 0, 0, 0, 47187), -- The Abominable Greench (Area: Growless Cave - Difficulty: 0) (Auras: )
(@CGUID+3, 55003, 0, 267, 1683, '0', 0, 0, 0, 0, 227.420135498046875, -294.529510498046875, 151.5233612060546875, 6.056292533874511718, 900, 0, 0, 56460, 0, 0, 0, 0, 0, 47187), -- Rotten Little Helper (Area: Growless Cave - Difficulty: 0)
(@CGUID+4, 55003, 0, 267, 1683, '0', 0, 0, 0, 0, 227.5850677490234375, -296.625, 151.517486572265625, 0.610865235328674316, 900, 0, 0, 56460, 0, 0, 0, 0, 0, 47187); -- Rotten Little Helper (Area: Growless Cave - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+3, @CGUID+4);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, '102754'), -- 55003 (Rotten Little Helper)
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, '102754'); -- 55003 (Rotten Little Helper)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+48;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 178609, 0, 267, 282, '0', 0, 0, 661.1920166015625, -740.14898681640625, 168.425994873046875, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 47187), -- Holiday Snow (Area: Crushridge Hold - Difficulty: 0)
(@OGUID+1, 178609, 0, 267, 282, '0', 0, 0, 754.52801513671875, -648.6099853515625, 149.5579986572265625, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 47187), -- Holiday Snow (Area: Crushridge Hold - Difficulty: 0)
(@OGUID+2, 178609, 0, 267, 282, '0', 0, 0, 719.85601806640625, -560.28399658203125, 163.8679962158203125, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 47187), -- Holiday Snow (Area: Crushridge Hold - Difficulty: 0)
(@OGUID+3, 178609, 0, 267, 282, '0', 0, 0, 658.65802001953125, -557.697998046875, 171.2209930419921875, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 47187), -- Holiday Snow (Area: Crushridge Hold - Difficulty: 0)
(@OGUID+4, 178609, 0, 267, 282, '0', 0, 0, 603.46600341796875, -510.64300537109375, 175.660003662109375, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 47187), -- Holiday Snow (Area: Crushridge Hold - Difficulty: 0)
(@OGUID+5, 178609, 0, 267, 281, '0', 0, 0, 580.65997314453125, -448.03399658203125, 161.6909942626953125, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+6, 178609, 0, 267, 283, '0', 0, 0, 822.364990234375, -508.822998046875, 141.376007080078125, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 47187), -- Holiday Snow (Area: Slaughter Hollow - Difficulty: 0)
(@OGUID+7, 178609, 0, 267, 283, '0', 0, 0, 815.21002197265625, -450.8380126953125, 133.9409942626953125, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 47187), -- Holiday Snow (Area: Slaughter Hollow - Difficulty: 0)
(@OGUID+8, 178609, 0, 267, 283, '0', 0, 0, 881.53399658203125, -507.152008056640625, 134.9069976806640625, 1.256635904312133789, 0, 0, 0.587784767150878906, 0.809017360210418701, 120, 255, 1, 47187), -- Holiday Snow (Area: Slaughter Hollow - Difficulty: 0)
(@OGUID+9, 178609, 0, 267, 283, '0', 0, 0, 773.85498046875, -398.191009521484375, 139.625, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 47187), -- Holiday Snow (Area: Slaughter Hollow - Difficulty: 0)
(@OGUID+10, 178609, 0, 267, 281, '0', 0, 0, 755.2969970703125, -337.7239990234375, 139.3350067138671875, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+11, 178609, 0, 267, 281, '0', 0, 0, 728.20697021484375, -302.97601318359375, 139.7859954833984375, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+12, 178609, 0, 267, 281, '0', 0, 0, 819.06597900390625, -272.72198486328125, 151.0789947509765625, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+13, 178609, 0, 267, 281, '0', 0, 0, 773.52301025390625, -230.858001708984375, 135.7449951171875, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+14, 178609, 0, 267, 281, '0', 0, 0, 652.9580078125, -361.62200927734375, 152.858001708984375, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+15, 178609, 0, 267, 281, '0', 0, 0, 562.8079833984375, -362.746002197265625, 155.5659942626953125, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+16, 178609, 0, 267, 281, '0', 0, 0, 533.49200439453125, -354.657989501953125, 160.8939971923828125, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+17, 178609, 0, 267, 281, '0', 0, 0, 482.37799072265625, -338.248992919921875, 166.936004638671875, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+18, 178609, 0, 267, 281, '0', 0, 0, 591.573974609375, -207.003005981445312, 143.2649993896484375, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+19, 178609, 0, 267, 281, '0', 0, 0, 543.74200439453125, -210.843994140625, 146.8699951171875, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+20, 178609, 0, 267, 281, '0', 0, 0, 457.061004638671875, -268.042999267578125, 157.3430023193359375, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+21, 178609, 0, 267, 281, '0', 0, 0, 551.26397705078125, -149.820999145507812, 144.6439971923828125, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+22, 178609, 0, 267, 281, '0', 0, 0, 512.14501953125, -92.2017974853515625, 144.55999755859375, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+23, 178609, 0, 267, 281, '0', 0, 0, 608.17401123046875, -126.985000610351562, 136.968994140625, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+24, 178609, 0, 267, 281, '0', 0, 0, 405.5, -255.171005249023437, 159.5469970703125, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+25, 178609, 0, 267, 281, '0', 0, 0, 385.209991455078125, -308.447998046875, 164.001007080078125, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+26, 178609, 0, 267, 281, '0', 0, 0, 445.084991455078125, -323.740997314453125, 163.66400146484375, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+27, 178609, 0, 267, 281, '0', 0, 0, 486.985992431640625, -575.4429931640625, 179.7570037841796875, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 47187), -- Holiday Snow (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+28, 178609, 0, 267, 1357, '0', 0, 0, 392.243988037109375, -513.64801025390625, 170.53399658203125, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 47187), -- Holiday Snow (Area: Gallows' Corner - Difficulty: 0)
(@OGUID+29, 178609, 0, 267, 1357, '0', 0, 0, 325.881011962890625, -449.009002685546875, 163.906005859375, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 47187), -- Holiday Snow (Area: Gallows' Corner - Difficulty: 0)
(@OGUID+30, 178609, 0, 267, 1357, '0', 0, 0, 244.0989990234375, -413.516998291015625, 151.8860015869140625, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 47187), -- Holiday Snow (Area: Gallows' Corner - Difficulty: 0)
(@OGUID+31, 178609, 0, 267, 1683, '0', 0, 0, 339.39599609375, -345.503997802734375, 168.6150054931640625, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 120, 255, 1, 47187), -- Holiday Snow (Area: Growless Cave - Difficulty: 0)
(@OGUID+32, 178924, 0, 267, 1683, '0', 0, 0, 232.58160400390625, -297.75, 152.2213592529296875, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 47187), -- Lights (Area: Growless Cave - Difficulty: 0)
(@OGUID+33, 178924, 0, 267, 1683, '0', 0, 0, 233.923614501953125, -296.196197509765625, 151.9201812744140625, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 47187), -- Lights (Area: Growless Cave - Difficulty: 0)
(@OGUID+34, 178924, 0, 267, 1683, '0', 0, 0, 233.5208282470703125, -293.685760498046875, 151.8355255126953125, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 47187), -- Lights (Area: Growless Cave - Difficulty: 0)
(@OGUID+35, 178924, 0, 267, 1683, '0', 0, 0, 229.248260498046875, -292.73089599609375, 152.2802886962890625, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 47187), -- Lights (Area: Growless Cave - Difficulty: 0)
(@OGUID+36, 178924, 0, 267, 1683, '0', 0, 0, 230.1840362548828125, -297.989593505859375, 152.126922607421875, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 47187), -- Lights (Area: Growless Cave - Difficulty: 0)
(@OGUID+37, 178924, 0, 267, 1683, '0', 0, 0, 231.7100677490234375, -292.435760498046875, 152.02587890625, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 47187), -- Lights (Area: Growless Cave - Difficulty: 0)
(@OGUID+38, 209465, 0, 267, 1683, '0', 0, 0, 227.9114532470703125, -265.5625, 147.2050018310546875, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 120, 255, 1, 47187), -- Greench Stash (Area: Growless Cave - Difficulty: 0)
(@OGUID+39, 209473, 0, 267, 281, '0', 0, 0, 233.0069427490234375, -292.3975830078125, 150.9533843994140625, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 47187), -- Metzen Cage Segment (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+40, 209473, 0, 267, 281, '0', 0, 0, 234.03125, -297.420135498046875, 151.1999359130859375, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 47187), -- Metzen Cage Segment (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+41, 209473, 0, 267, 281, '0', 0, 0, 227.8489532470703125, -293.265625, 151.1623992919921875, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 47187), -- Metzen Cage Segment (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+42, 209474, 0, 267, 281, '0', 0, 0, 228.845489501953125, -297.946197509765625, 151.23883056640625, 0, 0, 0, 0, 1, 120, 255, 1, 47187), -- Metzen Cage Post (Area: Ruins of Alterac - Difficulty: 0)
(@OGUID+43, 209497, 0, 267, 1683, '0', 0, 0, 232.154510498046875, -266.673614501953125, 145.9286346435546875, 0, 0, 0, 0, 1, 300, 255, 1, 47187), -- Stolen Treats (Area: Growless Cave - Difficulty: 0)
(@OGUID+44, 209497, 0, 267, 1683, '0', 0, 0, 225.609375, -259.333343505859375, 145.006103515625, 0, 0, 0, 0, 1, 300, 255, 1, 47187), -- Stolen Treats (Area: Growless Cave - Difficulty: 0)
(@OGUID+45, 209497, 0, 267, 1683, '0', 0, 0, 224.170135498046875, -278.482635498046875, 146.6750030517578125, 0, 0, 0, 0, 1, 300, 255, 1, 47187), -- Stolen Treats (Area: Growless Cave - Difficulty: 0)
(@OGUID+46, 209506, 0, 267, 1683, '0', 0, 0, 228.6006927490234375, -270.086822509765625, 146.3180389404296875, 0, 0, 0, 0, 1, 300, 255, 1, 47187), -- Stolen Treats (Area: Growless Cave - Difficulty: 0)
(@OGUID+47, 209506, 0, 267, 1683, '0', 0, 0, 226.44097900390625, -280.302093505859375, 146.9281768798828125, 0, 0, 0, 0, 1, 300, 255, 1, 47187), -- Stolen Treats (Area: Growless Cave - Difficulty: 0)
(@OGUID+48, 209506, 0, 267, 1683, '0', 0, 0, 226.8333282470703125, -263.111114501953125, 145.775787353515625, 0, 0, 0, 0, 1, 300, 255, 1, 47187); -- Stolen Treats (Area: Growless Cave - Difficulty: 0)

-- Spawn Group
DELETE FROM `spawn_group` WHERE `groupId`=@SGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SGROUP, 1, @OGUID+43),
(@SGROUP, 1, @OGUID+44),
(@SGROUP, 1, @OGUID+45),
(@SGROUP, 1, @OGUID+46),
(@SGROUP, 1, @OGUID+47),
(@SGROUP, 1, @OGUID+48);

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+4;
DELETE FROM `game_event_creature` WHERE `eventEntry`=-@EVENT AND `guid` IN (323869, 323870, 323873, 323874, 324137, 324139, 324141, 324144, 324146, 324353, 324354, 324478, 324480, 324547, 324575, 324576, 324639, 323866, 323867, 323868, 323871, 323872, 324100, 324135, 324136, 324138, 324142, 324143, 324145, 324577, 324638, 324695, 324697, 324698, 324699, 324701, 324702, 324720, 324721, 324722, 324723, 324724, 324725, 324773, 324774, 324140);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3),
(@EVENT, @CGUID+4),
(-@EVENT, 323869), -- Mountain Yeti
(-@EVENT, 323870),
(-@EVENT, 323873),
(-@EVENT, 323874),
(-@EVENT, 324137),
(-@EVENT, 324139),
(-@EVENT, 324141),
(-@EVENT, 324144),
(-@EVENT, 324146),
(-@EVENT, 324353),
(-@EVENT, 324354),
(-@EVENT, 324478),
(-@EVENT, 324480),
(-@EVENT, 324547),
(-@EVENT, 324575),
(-@EVENT, 324576),
(-@EVENT, 324639),
(-@EVENT, 323866), -- Giant Yeti
(-@EVENT, 323867),
(-@EVENT, 323868),
(-@EVENT, 323871),
(-@EVENT, 323872),
(-@EVENT, 324100),
(-@EVENT, 324135),
(-@EVENT, 324136),
(-@EVENT, 324138),
(-@EVENT, 324142),
(-@EVENT, 324143),
(-@EVENT, 324145),
(-@EVENT, 324577),
(-@EVENT, 324638),
(-@EVENT, 324695),
(-@EVENT, 324697),
(-@EVENT, 324698),
(-@EVENT, 324699),
(-@EVENT, 324701),
(-@EVENT, 324702),
(-@EVENT, 324720),
(-@EVENT, 324721),
(-@EVENT, 324722),
(-@EVENT, 324723),
(-@EVENT, 324724),
(-@EVENT, 324725),
(-@EVENT, 324773),
(-@EVENT, 324774),
(-@EVENT, 324140); -- Skhowl

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+48;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25),
(@EVENT, @OGUID+26),
(@EVENT, @OGUID+27),
(@EVENT, @OGUID+28),
(@EVENT, @OGUID+29),
(@EVENT, @OGUID+30),
(@EVENT, @OGUID+31),
(@EVENT, @OGUID+32),
(@EVENT, @OGUID+33),
(@EVENT, @OGUID+34),
(@EVENT, @OGUID+35),
(@EVENT, @OGUID+36),
(@EVENT, @OGUID+37),
(@EVENT, @OGUID+38),
(@EVENT, @OGUID+39),
(@EVENT, @OGUID+40),
(@EVENT, @OGUID+41),
(@EVENT, @OGUID+42);
