SET @CGUID := 10006931;
SET @OGUID := 10001978;

SET @NPCTEXTID := 600172;

-- Delete old spawns
DELETE FROM `gameobject` WHERE `guid` IN (500393,500400,500397,9000011,500392,500396,500398,500391,500395,500394,10000994,9003863);
DELETE FROM `gameobject_addon` WHERE `guid` IN (500393,500400,500397,9000011,500392,500396,500398,500391,500395,500394,10000994,9003863);

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 256078, 0, 1519, 10523, '0', 0, 0, 0, 0, -9078.16015625, 902.7742919921875, 67.5875244140625, 0.013109676539897918, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Lyssabel Dawnpetal (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@CGUID+1, 148233, 0, 1519, 10523, '0', 0, 0, 0, 1, -9073.890625, 908.2117919921875, 68.3509979248046875, 2.75807499885559082, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Kirin Tor Magus (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1 (Auras: 174827 - Garrison Magus)
(@CGUID+2, 148233, 0, 1519, 10523, '0', 0, 0, 0, 1, -9078.6787109375, 904.76214599609375, 68.3509979248046875, 1.45102548599243164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727); -- Kirin Tor Magus (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1 (Auras: 174827 - Garrison Magus)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 620467, 0, 1519, 10523, '0', 0, 0, -9005.2138671875, 928.8992919921875, 68.04378509521484375, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Jade Forest (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+1, 620477, 0, 1519, 10523, '0', 0, 0, -9054.064453125, 992.01043701171875, 73.59244537353515625, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Azsuna (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+2, 620458, 0, 1519, 10523, '0', 0, 0, -9078.0244140625, 873.42535400390625, 68.18328857421875, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Valdrakken (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+3, 620473, 0, 1519, 10523, '0', 0, 0, -9006.1611328125, 965.46356201171875, 68.221527099609375, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to the Exodar (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+4, 620475, 0, 1519, 10523, '0', 0, 0, -9023.3662109375, 952.546875, 68.33603668212890625, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Dalaran, Crystalsong Forest (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+5, 620455, 0, 1519, 10523, '0', 0, 0, -8984.5205078125, 963.31597900390625, 68.6964263916015625, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Caverns of Time (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+6, 620463, 0, 1519, 10523, '0', 24506, 0, -9060.7900390625, 886.8194580078125, 68.43552398681640625, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Dornogal (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+7, 620465, 0, 1519, 10523, '0', 0, 0, -9070.328125, 1012.99127197265625, 73.59220123291015625, 0, 0, 0, 0, 1, 120, 255, 1, 65727), -- Portal to Boralus (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+8, 543407, 0, 1519, 10523, '0', 0, 0, -9077.4951171875, 907.84375, 68.11911773681640625, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Founder's Point (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+9, 620479, 0, 1519, 10523, '0', 0, 0, -9036.296875, 1004.3870849609375, 73.93766021728515625, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Stormshield, Ashran (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+10, 620464, 0, 1519, 10523, '0', 0, 0, -9095.6611328125, 896.310791015625, 68.6197357177734375, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Oribos (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+11, 620472, 0, 1519, 10523, '0', 0, 0, -8988.794921875, 942.81427001953125, 68.04367828369140625, 0, 0, 0, 0, 1, 120, 255, 1, 65299), -- Portal to Shattrath (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@OGUID+12, 620476, 0, 1519, 10523, '0', 0, 0, -9126.455078125, 971.2899169921875, 73.6618804931640625, 0, 0, 0, 0, 1, 120, 255, 1, 65299); -- Portal to Bel'ameth (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 3503), -- Portal to Jade Forest
(@OGUID+1, 0, 0, 0, 1, 0, 3503), -- Portal to Azsuna
(@OGUID+2, 0, 0, 0, 1, 0, 3503), -- Portal to Valdrakken
(@OGUID+3, 0, 0, 0, 1, 0, 3503), -- Portal to the Exodar
(@OGUID+4, 0, 0, 0, 1, 0, 3503), -- Portal to Dalaran, Crystalsong Forest
(@OGUID+5, 0, 0, 0, 1, 0, 3503), -- Portal to Caverns of Time
(@OGUID+6, 0, 0, 0, 1, 0, 3503), -- Portal to Dornogal
(@OGUID+7, 0, 0, 0, 1, 0, 3503), -- Portal to Boralus
(@OGUID+8, 0, 0, 0, 1, 0, 24311), -- Portal to Founder's Point
(@OGUID+9, 0, 0, 0, 1, 0, 3503), -- Portal to Stormshield, Ashran
(@OGUID+10, 0, 0, 0, 1, 0, 3503), -- Portal to Oribos
(@OGUID+11, 0, 0, 0, 1, 0, 3503), -- Portal to Shattrath
(@OGUID+12, 0, 0, 0, 1, 0, 3906); -- Portal to Bel'ameth

-- Template
DELETE FROM `gameobject_template` WHERE `entry` IN (620463 /*Portal to Dornogal*/, 543407 /*Portal to Founder's Point*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(620463, 22, 92603, 'Portal to Dornogal', '', '', '', 1, 446540, -1, 0, 0, 0, 124420, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 864, 65299), -- Portal to Dornogal
(543407, 22, 117089, 'Portal to Founder\'s Point', '', '', '', 1.299999952316284179, 1235595, 0, 0, 1, 0, 23503, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65299); -- Portal to Founder's Point

UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=256078; -- Lyssabel Dawnpetal

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (620476,620472,617539,620464,620479,543407,620465,620463,620455,620475,620473,620458,620477,620467);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(620476, 1732, 0x0, 0, 3906), -- Portal to Bel'ameth
(620472, 1732, 0x0, 0, 3503), -- Portal to Shattrath
(620464, 1732, 0x0, 0, 3503), -- Portal to Oribos
(620479, 1732, 0x0, 0, 3503), -- Portal to Stormshield, Ashran
(543407, 0, 0x0, 0, 24311), -- Portal to Founder's Point
(620465, 1732, 0x0, 0, 3503), -- Portal to Boralus
(620463, 1732, 0x0, 0, 3503), -- Portal to Dornogal
(620455, 1732, 0x0, 0, 3503), -- Portal to Caverns of Time
(620475, 1732, 0x0, 0, 3503), -- Portal to Dalaran, Crystalsong Forest
(620473, 1732, 0x0, 0, 3503), -- Portal to the Exodar
(620458, 1732, 0x0, 0, 3503), -- Portal to Valdrakken
(620477, 1732, 0x0, 0, 3503), -- Portal to Azsuna
(620467, 1732, 0x0, 0, 3503); -- Portal to Jade Forest

-- Update positions
UPDATE `creature` SET `position_x` = -9060.607421875, `position_y` = 891.1336669921875, `position_z` = 68.12595367431640625, `orientation` = 4.558198451995849609 WHERE `guid` = 10003717;
UPDATE `creature` SET `position_x` = -9065.404296875, `position_y` = 887.38543701171875, `position_z` = 68.1258544921875, `orientation` = 6.194331169128417968 WHERE `guid` = 10003718;
UPDATE `creature` SET `position_x` = -9126.298828125, `position_y` = 967.092041015625, `position_z` = 73.67510986328125, `orientation` = 1.449335932731628417 WHERE `guid` = 9004107;
UPDATE `creature` SET `position_x` = -9121.7255859375, `position_y` = 970.5867919921875, `position_z` = 73.675079345703125, `orientation` = 2.988720893859863281 WHERE `guid` = 9004106;
UPDATE `creature` SET `position_x` = -9057.5732421875, `position_y` = 992.109375, `position_z` = 73.6747894287109375, `orientation` = 6.017000198364257812 WHERE `guid` = 850209;
UPDATE `creature` SET `position_x` = -9052.970703125, `position_y` = 995.51739501953125, `position_z` = 73.6749267578125, `orientation` = 4.576399803161621093 WHERE `guid` = 850210;
UPDATE `creature` SET `position_x` = -9066.716796875, `position_y` = 1014.06951904296875, `position_z` = 73.674560546875, `orientation` = 2.982812881469726562 WHERE `guid` = 850205;
UPDATE `creature` SET `position_x` = -9072.109375, `position_y` = 1009.95489501953125, `position_z` = 73.67443084716796875, `orientation` = 1.478312134742736816 WHERE `guid` = 850206;
UPDATE `creature` SET `position_x` = -9085.0400390625, `position_y` = 876.16143798828125, `position_z` = 67.58022308349609375, `orientation` = 5.854034900665283203 WHERE `guid` = 9000038;
UPDATE `creature` SET `position_x` = -9078.732421875, `position_y` = 880.6649169921875, `position_z` = 67.58486175537109375, `orientation` = 4.83990335464477539 WHERE `guid` = 9000039;
UPDATE `creature` SET `position_x` = -9040.44140625, `position_y` = 1004.9271240234375, `position_z` = 73.6748046875, `orientation` = 6.061535835266113281 WHERE `guid` = 850203;
UPDATE `creature` SET `position_x` = -9035.7255859375, `position_y` = 1008.45831298828125, `position_z` = 73.67487335205078125, `orientation` = 4.597506523132324218 WHERE `guid` = 850204;

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=256078 AND `MenuID`=41191);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(256078, 41191, 65727); -- Lyssabel Dawnpetal

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 297053, 0, 0, 0, 0, 0, 0, 0, 65727), -- 256078 (Lyssabel Dawnpetal)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 297060, 0, 0, 0, 0, 0, 0, 0, 65727), -- 256078 (Lyssabel Dawnpetal)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 303291, 0, 0, 0, 0, 0, 0, 0, 65727); -- 256078 (Lyssabel Dawnpetal)

DELETE FROM `gossip_menu` WHERE (`MenuID`=41191 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=41196 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=41201 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(41191, @NPCTEXTID+0, 65727), -- 256078 (Lyssabel Dawnpetal)
(41196, @NPCTEXTID+1, 65727), -- 256078 (Lyssabel Dawnpetal)
(41201, @NPCTEXTID+2, 65727); -- 256078 (Lyssabel Dawnpetal)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=41191 AND `OptionID`=2) OR (`MenuID`=41196 AND `OptionID` IN (1,2)) OR (`MenuID`=41201 AND `OptionID` IN (1,0));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(41191, 136950, 2, 0, 'I\'m interested in founding my own neighborhood.', 0, 0, 0, 41196, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727),
(41196, 136962, 1, 0, 'Tell me about charter neighborhoods.', 0, 0, 0, 41201, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727),
(41196, 136961, 2, 0, 'I\'d like to talk about something else.', 0, 0, 0, 41191, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727),
(41201, 136972, 1, 0, 'I\'d like to talk about something else.', 0, 0, 0, 41191, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727),
(41201, 136973, 0, 61, '<Buy a charter.>', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=4285, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=256078 AND `DifficultyID`=0); -- 256078 (Lyssabel Dawnpetal) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (136694, 131660, 141439);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(136694, 0.382999986410140991, 1.5, 0, 65727),
(131660, 0.305999994277954101, 1.5, 0, 65727),
(141439, 0.305999994277954101, 1.5, 0, 65727);