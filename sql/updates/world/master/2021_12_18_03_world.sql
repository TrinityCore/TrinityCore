SET @CGUID := 1050216;
SET @OGUID := 600018;

-- Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 179470, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5927.04541015625, 4881.32470703125, 4790.078125, 2.147932052612304687, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Dock Enforcer (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 179469, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5937.64599609375, 4859.5146484375, 4790.078125, 0.539287984371185302, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Market Specialist (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 179515, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5929.267578125, 4883.37939453125, 4790.078125, 5.291161060333251953, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Shipping Facilitator (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 179470, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5933.171875, 4860.12158203125, 4790.078125, 3.580482721328735351, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Dock Enforcer (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 179469, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5899.71337890625, 4829.6943359375, 4790.00830078125, 1.257099866867065429, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Market Specialist (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 179515, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5908.53125, 4850.4912109375, 4790.078125, 5.748018741607666015, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Shipping Facilitator (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 179470, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5922.205078125, 4829.95068359375, 4790.078125, 0.613434672355651855, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Dock Enforcer (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 179515, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5903.52099609375, 4843.408203125, 4792.59375, 2.868761301040649414, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Shipping Facilitator (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 178796, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5887.6962890625, 4815.2490234375, 4790.078125, 2.952180147171020507, 7200, 0, 0, 23256, 0, 0, 0, 0, 0, 41359), -- Ta'resarra (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 179515, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5905.236328125, 4834.8349609375, 4791.408203125, 2.851178169250488281, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Shipping Facilitator (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 179515, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5937.10400390625, 4831.4287109375, 4790.078125, 5.093245506286621093, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Shipping Facilitator (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 179515, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5899.2587890625, 4832.11279296875, 4790.00830078125, 4.535107135772705078, 7200, 0, 0, 46512, 0, 0, 0, 0, 0, 41359), -- Shipping Facilitator (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 179144, 2222, 13672, 13672, '0', 0, 0, 0, 0, -5940.81591796875, 4927.71630859375, 4803.5361328125, 4.730221271514892578, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41359); -- Zo'mezal (Area: -Unknown- - Difficulty: 0)

-- Creature Addons
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 1, 415, 0, 0, 0, ''), -- Dock Enforcer
(@CGUID+5, 0, 0, 0, 1, 69, 0, 0, 0, ''), -- Shipping Facilitator
(@CGUID+6, 0, 0, 0, 1, 720, 0, 0, 0, ''), -- Dock Enforcer
(@CGUID+7, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Shipping Facilitator
(@CGUID+9, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Shipping Facilitator
(@CGUID+10, 0, 0, 0, 1, 69, 0, 0, 0, ''); -- Shipping Facilitator

-- GameObject Data
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 365352, 2222, 13672, 13672, '0', 0, 0, -5940.79345703125, 4931.865234375, 4803.60888671875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 41359), -- Customs Enforcement Door (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 365353, 2222, 13672, 13672, '0', 0, 0, -5881.4833984375, 5492.73486328125, 4771.3330078125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 41359), -- Mailroom Entrance (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 368248, 2222, 13672, 13672, '0', 0, 0, -6119.28759765625, 5407.59765625, 4771.1640625, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 7200, 255, 0, 41359), -- Menagerie Door (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 368250, 2222, 13672, 13672, '0', 0, 0, -6068.7900390625, 5436.7109375, 4771.162109375, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 7200, 255, 0, 41359), -- Door (Area: -Unknown- - Difficulty: 0)
(@OGUID+4, 367994, 2222, 13672, 13672, '0', 0, 0, -5926.392578125, 4843.74560546875, 4789.93408203125, 0.532324969768524169, 0, 0, 0.263031005859375, 0.96478736400604248, 7200, 255, 1, 41359), -- Meeting Stone (Area: -Unknown- - Difficulty: 0)
(@OGUID+5, 369260, 2222, 13672, 13672, '0', 0, 0, -5894.755859375, 5451.96337890625, 4771.2998046875, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 41359), -- Portal to Customs (Area: -Unknown- - Difficulty: 0)
(@OGUID+6, 365351, 2222, 13672, 13672, '0', 0, 0, -5940.79345703125, 5098.94384765625, 4803.60888671875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 41359), -- Door (Area: -Unknown- - Difficulty: 0)
(@OGUID+7, 368246, 2222, 13672, 13672, '0', 0, 0, -5748.1767578125, 5472.26416015625, 4773.46630859375, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 7200, 255, 1, 41359), -- Door (Area: -Unknown- - Difficulty: 0)
(@OGUID+8, 369258, 2222, 13672, 13672, '0', 0, 0, -6047.43408203125, 5354.9423828125, 4771.2998046875, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 7200, 255, 1, 41359), -- Portal to Customs (Area: -Unknown- - Difficulty: 0)
(@OGUID+9, 369317, 2222, 13672, 13672, '0', 0, 0, -5962.04833984375, 5754.7548828125, 4811.75732421875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 41359), -- Portal to Customs (Area: -Unknown- - Difficulty: 0)
(@OGUID+10, 368938, 2222, 13672, 13672, '0', 0, 0, -5803.7900390625, 5492.28271484375, 4771.634765625, 3.130894899368286132, 0, 0, 0.999985694885253906, 0.005348853301256895, 7200, 255, 1, 41359), -- Portal to Customs (Area: -Unknown- - Difficulty: 0)
(@OGUID+11, 369744, 2222, 13672, 13672, '0', 0, 0, -5984.462890625, 5834.9130859375, 4805.92236328125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 0, 41359), -- Energy Barrier (Area: -Unknown- - Difficulty: 0)
(@OGUID+12, 368580, 2222, 13672, 13672, '0', 0, 0, -5888.92578125, 4984.26171875, 4804.1162109375, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 7200, 255, 1, 41359), -- Portal to Myza's Oasis (Area: -Unknown- - Difficulty: 0)
(@OGUID+13, 368579, 2222, 13672, 13672, '0', 0, 0, -5876.72412109375, 4987.4111328125, 4804.1162109375, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 7200, 255, 1, 41359); -- Portal to The P.O.S.T. (Area: -Unknown- - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Customs Enforcement Door
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Mailroom Entrance
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Menagerie Door
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal to Customs
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+8, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal to Customs
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal to Customs
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal to Customs
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- Energy Barrier
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 0, 8414), -- Portal to Myza's Oasis
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 8414); -- Portal to The P.O.S.T.

-- GameObject Template Data
DELETE FROM `gameobject_template` WHERE `entry` IN (368579 /*Portal to The P.O.S.T.*/, 368580 /*Portal to Myza's Oasis*/, 369744 /*Energy Barrier*/, 369317 /*Portal to Customs*/, 368938 /*Portal to Customs*/, 365353 /*Mailroom Entrance*/, 368246 /*Door*/, 368250 /*Door*/, 369260 /*Portal to Customs*/, 368248 /*Menagerie Door*/, 369258 /*Portal to Customs*/, 365351 /*Door*/, 365352 /*Customs Enforcement Door*/, 367994 /*Meeting Stone*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(368579, 10, 69590, 'Portal to The P.O.S.T.', 'point', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Portal to The P.O.S.T.
(368580, 10, 69590, 'Portal to Myza\'s Oasis', 'point', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Portal to Myza's Oasis
(369744, 0, 70566, 'Energy Barrier', '', '', '', 3.599999189376831054, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Energy Barrier
(369317, 0, 61271, 'Portal to Customs', '', '', '', 0.999999582767486572, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Portal to Customs
(368938, 0, 61271, 'Portal to Customs', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Portal to Customs
(365353, 0, 68410, 'Mailroom Entrance', '', '', '', 0.999999880790710449, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Mailroom Entrance
(368246, 0, 68410, 'Door', '', '', '', 0.999999523162841796, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Door
(368250, 0, 68410, 'Door', '', '', '', 0.999999523162841796, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Door
(369260, 0, 61271, 'Portal to Customs', '', '', '', 0.999999582767486572, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Portal to Customs
(368248, 0, 68410, 'Menagerie Door', '', '', '', 0.999999523162841796, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Menagerie Door
(369258, 0, 61271, 'Portal to Customs', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Portal to Customs
(365351, 0, 68410, 'Door', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Door
(365352, 0, 68410, 'Customs Enforcement Door', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Customs Enforcement Door
(367994, 23, 46089, 'Meeting Stone', '', '', '', 0.879999935626983642, 1, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 748, 41359); -- Meeting Stone

-- Creature Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (179144,178796,179515,179469,179470));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(179144, 0, 0, 0, 783, 41359),
(178796, 0, 0, 0, 2043, 41359),
(179515, 0, 0, 0, 2043, 41359),
(179469, 0, 0, 0, 2043, 41359),
(179470, 0, 0, 0, 2043, 41359);

-- Creature ModelInfo
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (101262, 101154, 100888, 100880, 100869);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(101262, 2.455555438995361328, 2.599999904632568359, 0, 41359),
(101154, 1.888888955116271972, 2, 0, 41359),
(100888, 1.888888955116271972, 2, 0, 41359),
(100880, 2.266666889190673828, 2.40000009536743164, 0, 41359),
(100869, 1.888888955116271972, 2, 0, 41359);

-- Gossip
DELETE FROM `gossip_menu` WHERE (`MenuId`=26961 AND `TextId`=42978);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(26961, 42978, 41359); -- 179144 (Zo'mezal)

-- Creature Text
DELETE FROM `npc_text` WHERE `ID`=42978;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(42978, 0, 0, 0, 0, 0, 0, 0, 0, 210729, 0, 0, 0, 0, 0, 0, 0, 41359); -- 42978

UPDATE `creature_template` SET `gossip_menu_id`=26961, `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=179144; -- Zo'mezal
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=8192, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=178796; -- Ta'resarra
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=179515; -- Shipping Facilitator
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=179469; -- Market Specialist
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=179470; -- Dock Enforcer

-- SAI & Scripts
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (179515, 179470, 179469);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@CGUID+4), -(@CGUID+11), -(@CGUID+1), -(@CGUID+0), -(@CGUID+2)) AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+4), 0, 0, 0, 1, 0, 100, 0, 5000, 10000, 10000, 15000, 0, '', 10, 6, 396, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5s - 10s and Repeat every 10s - 15s - use Rnd Emote - to self'),
(-(@CGUID+11), 0, 0, 0, 1, 0, 100, 0, 5000, 10000, 10000, 15000, 0, '', 10, 6, 396, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5s - 10s and Repeat every 10s - 15s - use Rnd Emote - to self'),
(-(@CGUID+1), 0, 0, 0, 1, 0, 100, 0, 5000, 15000, 15000, 30000, 0, '', 10, 6, 396, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5s - 15s and Repeat every 15s - 30s - use Rnd Emote - to self'),
(-(@CGUID+0), 0, 0, 0, 1, 0, 100, 0, 5000, 10000, 10000, 15000, 0, '', 10, 6, 396, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5s - 10s and Repeat every 10s - 15s - use Rnd Emote - to self'),
(-(@CGUID+2), 0, 0, 0, 1, 0, 100, 0, 5000, 10000, 10000, 15000, 0, '', 10, 6, 396, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5s - 10s and Repeat every 10s - 15s - use Rnd Emote - to self');
