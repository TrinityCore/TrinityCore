SET @CGUID := 213973;
SET @OGUID := 167095;
SET @EVENT := 61;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=11394 WHERE `entry`=40492;
UPDATE `creature_template` SET `gossip_menu_id`=11398 WHERE `entry`=39654;
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=41839; -- [DND] Controller
UPDATE `creature_template` SET `npcflag`=1, `unit_flags`=768 WHERE `entry`=40492; -- Zild'jian
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=40425; -- Voodoo Troll
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=40231; -- Hexed Troll
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=40199; -- Tiki Warrior

DELETE FROM `creature_template_addon` WHERE `entry` IN (41839 /*41839 ([DND] Controller)*/, 40492 /*40492 (Zild'jian)*/, 40425 /*40425 (Voodoo Troll)*/, 40241 /*40241 (Darkspear Warrior)*/, 40231 /*40231 (Hexed Troll)*/, 40199 /*40199 (Tiki Warrior) - Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 03, Freeze Anim*/);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(41839, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 41839 ([DND] Controller)
(40492, 0, 0, 0, 0, 1, 0, 173, 0, ''), -- 40492 (Zild'jian)
(40425, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 40425 (Voodoo Troll)
(40241, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 40241 (Darkspear Warrior)
(40231, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 40231 (Hexed Troll)
(40199, 0, 0, 0, 0, 1, 0, 0, 0, '75038'); -- 40199 (Tiki Warrior) - Freeze Anim

UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry`=40192; -- 40192 (Vanira)
UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry`=39654; -- 39654 (Vol'jin)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (41839);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(41839, 0, 0, 1, 1, 0, 0, NULL);

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuID`=11394 AND `TextID`=15871);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11394, 15871, 53788); -- 40492 (Zild'jian)

UPDATE `gossip_menu_option` SET `ActionMenuID`=11397 WHERE (`MenuID`=11398 AND `OptionID`=0);

DELETE FROM `npc_text` WHERE `ID`=15871;
INSERT INTO `npc_text` (`ID`, `text0_0`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(15871, 'Vol''jin be waitin for ya.  You should talk wit him now, my arms are gettin'' tired.$B$BDis echo isle attack betta be startin'' soon. ', 1, 0, 0, 0, 0, 0, 0, 0, 40472, 0, 0, 0, 0, 0, 0, 0, 53788); -- 15871

-- Misc
UPDATE `spell_area` SET `quest_start`=25480, `quest_start_status`=64 WHERE `spell`=74092;

-- Quests
DELETE FROM `quest_details` WHERE `ID`=25495;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25495, 1, 1, 0, 0, 0, 0, 0, 0, 53788); -- Preparin' For Battle

UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=53788 WHERE `ID`=25495; -- Preparin' For Battle

DELETE FROM `game_event_creature_quest` WHERE (`id`=40253 AND `quest`=25495);
DELETE FROM `creature_queststarter` WHERE (`id`=40253 AND `quest`=25495);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(40253, 25495); -- Preparin' For Battle offered by Champion Uru'zin

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (40199);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (40199) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4019900, 4019901, 4019902) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40199,0,0,0,11,0,100,0,0,0,0,0,0,88,4019900,4019902,0,0,0,0,1,0,0,0,0,0,0,0,0,'Tiki Warrior - On spawn - Call random range actionlist'),
(4019900,9,0,0,0,0,100,0,0,0,0,0,0,11,52614,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Tiki Warrior - Cast "Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 01"'),
(4019901,9,0,0,0,0,100,0,0,0,0,0,0,11,52617,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Tiki Warrior - Cast "Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 02"'),
(4019902,9,0,0,0,0,100,0,0,0,0,0,0,11,52618,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Tiki Warrior - Cast "Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 03"');

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `VerifiedBuild`) VALUES
(@CGUID+0, 39654, 1, 14, 368, 1, 256, 0, 1, -803.7569580078125, -5372.67529296875, 1.706597328186035156, 4.607669353485107421, 120, 0, 0, 5578000, 68128, 0, 53788), -- Vol'jin (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+1, 40192, 1, 14, 368, 1, 256, 0, 1, -806.6007080078125, -5372.3662109375, 1.740533351898193359, 4.607669353485107421, 120, 0, 0, 630000, 99850, 0, 53788), -- Vanira (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+2, 40199, 1, 14, 368, 1, 256, 0, 0, -1089.203125, -5534.72412109375, 8.209239959716796875, 3.176499128341674804, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 52618 - Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 03, 75038 - Freeze Anim)
(@CGUID+3, 40199, 1, 14, 368, 1, 256, 0, 0, -1103.0660400390625, -5601.11474609375, 8.610991477966308593, 2.216568231582641601, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+4, 40199, 1, 14, 368, 1, 256, 0, 0, -1116.671875, -5546.1787109375, 8.427076339721679687, 1.326450228691101074, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+5, 40199, 1, 14, 368, 1, 256, 0, 0, -1130.310791015625, -5561.09033203125, 10.66214179992675781, 3.665191411972045898, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+6, 40199, 1, 14, 368, 1, 256, 0, 0, -1125.625, -5578.8212890625, 9.991229057312011718, 2.809980154037475585, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+7, 40199, 1, 14, 368, 1, 256, 0, 0, -1141.717041015625, -5561.7880859375, 9.991229057312011718, 5.375614166259765625, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+8, 40199, 1, 14, 368, 1, 256, 0, 0, -1127.5625, -5604.67041015625, 8.571069717407226562, 1.326450228691101074, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+9, 40199, 1, 14, 368, 1, 256, 0, 0, -1144.564208984375, -5577.41650390625, 9.991169929504394531, 0.191986218094825744, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+10, 40199, 1, 14, 368, 1, 256, 0, 0, -1148.5555419921875, -5529.25, 6.521678447723388671, 0.05235987901687622, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 52618 - Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 03, 75038 - Freeze Anim)
(@CGUID+11, 40199, 1, 14, 368, 1, 256, 0, 0, -1137.2291259765625, -5507.49853515625, 7.451714515686035156, 4.642575740814208984, 120, 0, 0, 25200, 0, 0, 53788), -- Tiki Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: 52614 - Enchanted Tiki Warrior: Enchanted Tiki Warrior Visual 01, 75038 - Freeze Anim)
(@CGUID+12, 40222, 1, 14, 368, 1, 256, 0, 0, -854.15625, -5344.60595703125, 3.308190345764160156, 1.186823844909667968, 120, 0, 0, 12600, 0, 0, 53788), -- Scout Bat (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+13, 40231, 1, 14, 368, 1, 256, 0, 0, -1250.9305419921875, -5507.1162109375, 5.849954605102539062, 3.525565147399902343, 120, 0, 0, 151200, 139790, 0, 53788), -- Hexed Troll (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+14, 40231, 1, 14, 368, 1, 256, 0, 0, -1242.1492919921875, -5513.3505859375, 9.614050865173339843, 3.281219005584716796, 120, 0, 0, 151200, 139790, 0, 53788), -- Hexed Troll (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+15, 40231, 1, 14, 368, 1, 256, 0, 0, -1262.9635009765625, -5497.2587890625, 4.929576396942138671, 5.078907966613769531, 120, 0, 0, 151200, 139790, 0, 53788), -- Hexed Troll (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+16, 40231, 1, 14, 368, 1, 256, 0, 0, -1271.390625, -5517.07275390625, 5.070352554321289062, 0, 120, 0, 0, 151200, 139790, 0, 53788), -- Hexed Troll (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+17, 40231, 1, 14, 368, 1, 256, 0, 0, -1281.654541015625, -5508.578125, 8.472925186157226562, 0, 120, 0, 0, 151200, 139790, 0, 53788), -- Hexed Troll (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+18, 40231, 1, 14, 368, 1, 256, 0, 0, -1278.5972900390625, -5501.01904296875, 5.113239288330078125, 0, 120, 0, 0, 151200, 139790, 0, 53788), -- Hexed Troll (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+19, 40241, 1, 14, 368, 1, 256, 0, 1, -814.0694580078125, -5360.75, 2.521949291229248046, 4.747295379638671875, 120, 0, 0, 1008000, 0, 0, 53788), -- Darkspear Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+20, 40241, 1, 14, 368, 1, 256, 0, 1, -795.6961669921875, -5360.73095703125, 2.28309035301208496, 4.520402908325195312, 120, 0, 0, 1008000, 0, 0, 53788), -- Darkspear Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+21, 40241, 1, 14, 368, 1, 256, 0, 1, -807.34722900390625, -5360.52587890625, 2.302173137664794921, 4.747295379638671875, 120, 0, 0, 1008000, 0, 0, 53788), -- Darkspear Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+22, 40241, 1, 14, 368, 1, 256, 0, 1, -788.65802001953125, -5361.0869140625, 3.251736164093017578, 4.520402908325195312, 120, 0, 0, 1008000, 0, 0, 53788), -- Darkspear Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+23, 40241, 1, 14, 368, 1, 256, 0, 1, -810.217041015625, -5361.923828125, 2.541666269302368164, 4.747295379638671875, 120, 0, 0, 1008000, 0, 0, 53788), -- Darkspear Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+24, 40241, 1, 14, 368, 1, 256, 0, 1, -792.0850830078125, -5362.5224609375, 2.518892288208007812, 4.520402908325195312, 120, 0, 0, 1008000, 0, 0, 53788), -- Darkspear Warrior (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+25, 40425, 1, 14, 368, 1, 256, 0, 0, -1232.8021240234375, -5516.01025390625, 6.147329330444335937, 0, 120, 0, 0, 151200, 59910, 0, 53788), -- Voodoo Troll (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+26, 40425, 1, 14, 368, 1, 256, 0, 0, -1259.90283203125, -5544.4619140625, 10.13318634033203125, 1.378810048103332519, 120, 0, 0, 151200, 59910, 0, 53788), -- Voodoo Troll (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+27, 40425, 1, 14, 368, 1, 256, 0, 0, -1261.3958740234375, -5505.87353515625, 5.455820560455322265, 0, 120, 0, 0, 151200, 59910, 0, 53788), -- Voodoo Troll (Area: Echo Isles - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+28, 40492, 1, 14, 368, 1, 256, 0, 1, -802.140625, -5347.78466796875, 2.247483253479003906, 5.951572895050048828, 120, 0, 0, 12600, 0, 0, 53788), -- Zild'jian (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+29, 41839, 1, 14, 368, 1, 256, 0, 0, -1168.8004150390625, -5505.4150390625, 5.630413532257080078, 0, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Controller (Area: Echo Isles - Difficulty: 0) CreateObject1
(@CGUID+30, 41839, 1, 14, 368, 1, 256, 0, 0, -1168.9375, -5505.126953125, 5.627105712890625, 0, 120, 0, 0, 42, 0, 0, 53788); -- [DND] Controller (Area: Echo Isles - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 0, 1, 0, 333, 0, ''); -- Tiki Warrior

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` IN (12373,12398,12399,12400,12401,12402,12403);
DELETE FROM `gameobject_addon` WHERE `guid` IN (12373,12398,12399,12400,12401,12402,12403);
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+16;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(12373, 3237, 1, 14, 368, 1, 257, -1286.0894775390625, -5528.13037109375, 15.20782184600830078, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 53788), -- Imprisoned Darkspear (Area: Echo Isles - Difficulty: 0) CreateObject1
(12398, 3237, 1, 14, 368, 1, 257, -1287.270751953125, -5528.1318359375, 15.20782184600830078, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 53788), -- Imprisoned Darkspear (Area: Echo Isles - Difficulty: 0) CreateObject1
(12399, 3237, 1, 14, 368, 1, 257, -1287.2486572265625, -5530.0029296875, 15.20782184600830078, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 53788), -- Imprisoned Darkspear (Area: Echo Isles - Difficulty: 0) CreateObject1
(12400, 3237, 1, 14, 368, 1, 257, -1287.583984375, -5528.7802734375, 15.20782184600830078, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 53788), -- Imprisoned Darkspear (Area: Echo Isles - Difficulty: 0) CreateObject1
(12401, 3237, 1, 14, 368, 1, 257, -1287.740234375, -5527.71142578125, 15.20781993865966796, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 53788), -- Imprisoned Darkspear (Area: Echo Isles - Difficulty: 0) CreateObject1
(12402, 3237, 1, 14, 368, 1, 257, -1286.97314453125, -5529.0693359375, 15.20782184600830078, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 53788), -- Imprisoned Darkspear (Area: Echo Isles - Difficulty: 0) CreateObject1
(12403, 3237, 1, 14, 368, 1, 257, -1288.1153564453125, -5529.064453125, 15.20782279968261718, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 120, 255, 1, 53788), -- Imprisoned Darkspear (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+0, 188470, 1, 14, 368, 1, 256, -1282.2274169921875, -5532.27978515625, 15.03157901763916015, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 53788), -- Event Fog (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+1, 190214, 1, 14, 368, 1, 256, -789.91839599609375, -5355.3369140625, 3.387152910232543945, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 53788), -- Voodoo Pile Skulls (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+2, 190214, 1, 14, 368, 1, 256, -794.296875, -5354.46875, 3.019097089767456054, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 53788), -- Voodoo Pile Skulls (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+3, 190214, 1, 14, 368, 1, 256, -791.00518798828125, -5351.1650390625, 2.854166984558105468, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 53788), -- Voodoo Pile Skulls (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+4, 194501, 1, 14, 368, 1, 256, -811.0225830078125, -5343.18603515625, 0.917156994342803955, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+5, 194501, 1, 14, 368, 1, 256, -835.3507080078125, -5314.251953125, 1.883900046348571777, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+6, 194501, 1, 14, 368, 1, 256, -792.4600830078125, -5378.80029296875, 3.098958015441894531, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+7, 194501, 1, 14, 368, 1, 256, -784.0538330078125, -5352.375, 2.78125, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+8, 194501, 1, 14, 368, 1, 256, -819.33856201171875, -5369.609375, 2.072698116302490234, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+9, 194501, 1, 14, 368, 1, 256, -872.62152099609375, -5329.5244140625, 1.313696026802062988, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+10, 194501, 1, 14, 368, 1, 256, -868.357666015625, -5371.22216796875, 0.976329982280731201, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 53788), -- Sen'jin Banner (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+11, 202833, 1, 14, 368, 1, 256, -848.420166015625, -5348.6650390625, 3.214971065521240234, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 53788), -- Sen'jin Bat Totem (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+12, 202834, 1, 14, 368, 1, 256, -853.86456298828125, -5344.2587890625, 3.884398937225341796, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 53788), -- Sen'jin Bat Roost Straw (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+13, 202835, 1, 14, 368, 1, 256, -855.28643798828125, -5348.17041015625, 4.395833015441894531, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 53788), -- Sen'jin Bat Roost Fence (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+14, 202835, 1, 14, 368, 1, 256, -861.04339599609375, -5345.95166015625, 3.407985925674438476, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 53788), -- Sen'jin Bat Roost Fence (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+15, 202839, 1, 14, 368, 1, 256, -852.03643798828125, -5348.32666015625, 4.36799478530883789, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 53788), -- Sen'jin Bat Roost Fence Post (Area: Echo Isles - Difficulty: 0) CreateObject1
(@OGUID+16, 202845, 1, 14, 368, 1, 256, -698.029541015625, -5593.4462890625, 23.58217811584472656, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 53788); -- Voodoo Pile Skulls (Area: Echo Isles - Difficulty: 0) CreateObject1

UPDATE `gameobject` SET `phasemask`=257 WHERE `guid` IN (167093, 167094);
UPDATE `gameobject` SET `phasemask`=257 WHERE `id` IN (178444, 102986, 18084, 3240, 3089);

DELETE FROM `spawn_group` WHERE `spawnType`=1 AND `spawnId` IN (12373,12398,12399,12400,12401,12402,12403);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(2, 1, 12373),
(2, 1, 12398),
(2, 1, 12399),
(2, 1, 12400),
(2, 1, 12401),
(2, 1, 12402),
(2, 1, 12403);

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3),
(@EVENT, @CGUID+4),
(@EVENT, @CGUID+5),
(@EVENT, @CGUID+6),
(@EVENT, @CGUID+7),
(@EVENT, @CGUID+8),
(@EVENT, @CGUID+9),
(@EVENT, @CGUID+10),
(@EVENT, @CGUID+11),
(@EVENT, @CGUID+12),
(@EVENT, @CGUID+13),
(@EVENT, @CGUID+14),
(@EVENT, @CGUID+15),
(@EVENT, @CGUID+16),
(@EVENT, @CGUID+17),
(@EVENT, @CGUID+18),
(@EVENT, @CGUID+19),
(@EVENT, @CGUID+20),
(@EVENT, @CGUID+21),
(@EVENT, @CGUID+22),
(@EVENT, @CGUID+23),
(@EVENT, @CGUID+24),
(@EVENT, @CGUID+25),
(@EVENT, @CGUID+26),
(@EVENT, @CGUID+27),
(@EVENT, @CGUID+28),
(@EVENT, @CGUID+29),
(@EVENT, @CGUID+30);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+16;
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
(@EVENT, @OGUID+16);
