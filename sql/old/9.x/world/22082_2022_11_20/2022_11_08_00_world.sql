SET @CGUID := 1051887;
SET @OGUID := 600243;

SET @NPCTEXTID := 580004;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 156803, 2175, 10424, 10529, '0', 13833, 0, 0, 0, 191.1006927490234375, -2308.31591796875, 80.72725677490234375, 2.998941898345947265, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Alaria (Area: Ogre Ruins - Difficulty: 0)
(@CGUID+1, 154300, 2175, 10424, 10529, '0', 13833, 0, 0, 1, 192.1805572509765625, -2311.40283203125, 80.7794189453125, 3.370757579803466796, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Bjorn Stouthands (Area: Ogre Ruins - Difficulty: 0)
(@CGUID+2, 156803, 2175, 10424, 10527, '0', 13816, 0, 0, 0, 91.98264312744140625, -2246.829833984375, 94.48230743408203125, 2.024514675140380859, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Alaria (Area: Hrun's Barrow - Difficulty: 0)
(@CGUID+3, 156891, 2175, 10424, 10527, '0', 13816, 0, 0, 1, 89.68402862548828125, -2249.263916015625, 94.77820587158203125, 1.939347267150878906, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Bjorn Stouthands (Area: Hrun's Barrow - Difficulty: 0)
(@CGUID+4, 156932, 2175, 10424, 10527, '0', 13831, 0, 0, 0, 183.7430572509765625, -2288.057373046875, 81.900390625, 0.905255854129791259, 120, 0, 0, 97, 382, 0, 0, 0, 0, 46455), -- Ralia Dreamchaser (Area: Hrun's Barrow - Difficulty: 0)
(@CGUID+5, 156803, 2175, 10424, 10527, '0', 13832, 0, 0, 0, 182.12847900390625, -2291.24658203125, 81.90361785888671875, 0.353680580854415893, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Alaria (Area: Hrun's Barrow - Difficulty: 0)
(@CGUID+6, 154300, 2175, 10424, 10527, '0', 13832, 0, 0, 1, 184.97222900390625, -2292.1337890625, 81.7708892822265625, 1.902909159660339355, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Bjorn Stouthands (Area: Hrun's Barrow - Difficulty: 0)
(@CGUID+7, 156833, 2175, 10424, 10529, '0', 13809, 0, 0, 0, 254.1805572509765625, -2328.013916015625, 80.76143646240234375, 5.244953632354736328, 120, 0, 0, 97, 382, 0, 0, 0, 0, 46455), -- Henry Garrick (Area: Ogre Ruins - Difficulty: 0)
(@CGUID+8, 156804, 2175, 10424, 10529, '0', 13809, 0, 0, 0, 251.142364501953125, -2329.72216796875, 81.06636810302734375, 5.188352584838867187, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Kee-La (Area: Ogre Ruins - Difficulty: 0)
(@CGUID+9, 156859, 2175, 10424, 10528, '0', 13811, 0, 0, 0, 392.494781494140625, -2440.421875, 125.4952392578125, 5.31956338882446289, 120, 0, 0, 97, 382, 0, 0, 0, 0, 46455), -- Henry Garrick (Area: Harpy Roost - Difficulty: 0)
(@CGUID+10, 156860, 2175, 10424, 10588, '0', 13811, 0, 0, 0, 390.868072509765625, -2443.600830078125, 125.0643386840820312, 0.44841080904006958, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Kee-La (Area: Darkmaul Plains - Difficulty: 0)
(@CGUID+11, 156886, 2175, 10424, 10529, '0', 13836, 0, 0, 0, 182.998260498046875, -2286.68408203125, 81.9317626953125, 0, 120, 0, 0, 97, 382, 0, 0, 0, 0, 46455), -- Meredy Huntswell (Area: Ogre Ruins - Difficulty: 0)
(@CGUID+12, 156887, 2175, 10424, 10529, '0', 13318, 0, 0, 0, 187.3802032470703125, -2286.43408203125, 81.8004302978515625, 3.478890180587768554, 120, 0, 0, 97, 382, 0, 0, 0, 0, 46455), -- Henry Garrick (Area: Ogre Ruins - Difficulty: 0)
(@CGUID+13, 156885, 2175, 10424, 10529, '0', 13318, 0, 0, 0, 178.4965362548828125, -2281.757080078125, 81.9315948486328125, 2.704557180404663085, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455), -- Kee-La (Area: Ogre Ruins - Difficulty: 0)
(@CGUID+14, 156801, 2175, 10424, 10529, '0', 15011, 0, 0, 0, 187.064239501953125, -2279.7275390625, 81.93114471435546875, 1.83221590518951416, 120, 0, 0, 121, 0, 0, 0, 0, 0, 46455); -- Private Cole (Area: Ogre Ruins - Difficulty: 0)

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 342365, 2175, 10424, 10529, '0', 0, 0, 180.3663177490234375, -2284.223876953125, 82.02576446533203125, 0, 0, 0, 0, 1, 120, 255, 1, 46455); -- Campfire (Area: Ogre Ruins - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+13, 0, 0, 0, 1, 533, 0, 0, 0, 0, ''); -- Kee-La

DELETE FROM `creature_template_addon` WHERE `entry` IN (154300, 153211);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(154300, 0, 0, 0, 1, 0, 0, 0, 0, 4, ''), -- 154300 (Bjorn Stouthands)
(153211, 0, 0, 0, 1, 0, 0, 0, 0, 0, '305513'); -- 153211 (Meredy Huntswell) - Necrotic Ritual (DNT)

UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156891; -- Bjorn Stouthands
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156803; -- Alaria
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=4196352 WHERE `entry`=154300; -- Bjorn Stouthands
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=156932; -- Ralia Dreamchaser
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156833; -- Henry Garrick
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156804; -- Kee-La
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156860; -- Kee-La
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `gossip_menu_id`=24543, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156859; -- Henry Garrick
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `gossip_menu_id`=24887, `faction`=1732, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=153211; -- Meredy Huntswell
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156885; -- Kee-La
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156887; -- Henry Garrick
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `gossip_menu_id`=25321, `faction`=1732, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=156886; -- Meredy Huntswell

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 46455); -- 153211 (Meredy Huntswell)

DELETE FROM `gossip_menu` WHERE (`MenuID`=24887 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(24887, @NPCTEXTID+0, 46455); -- 153211 (Meredy Huntswell)

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (13794, 13833, 13816, 13831, 13832, 13809, 13811, 13318, 13836, 15011);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(13794, 'Cosmetic - 9.0 NPE - Alliance Populated Camp'),
(13833, 'Cosmetic - See Bjorn and Alaria at Alliance Populated Camp'),
(13816, 'Cosmetic - See Bjorn and Alaria at Hruns Barrows'),
(13832, 'Cosmetic - See Bjorn and Alaria back at Alliance Populated Camp'),
(13831, 'Cosmetic - See Ralia at Alliance Populated Camp'),
(13809, 'Cosmetic - See Henry and Kee-La at Alliance Populated Camp'),
(13811, 'Cosmetic - See Henry and Kee-La at Harpy Roost'),
(13318, 'Cosmetic - See Henry and Kee-La back at Alliance Populated Camp'),
(13836, 'Cosmetic - See Meredy back at Alliance Populated Camp'),
(15011, 'Cosmetic - See Private Cole at Alliance Populated Camp');

DELETE FROM `phase_area` WHERE (`AreaId` IN (10529, 10588, 10527) AND `PhaseId` = 13794) OR (`AreaId` IN (10529, 10588, 10527) AND `PhaseId` = 13833) OR (`AreaId` IN (10529, 10588, 10527) AND `PhaseId` = 13816) OR (`AreaId` IN (10529, 10588, 10527) AND `PhaseId` = 13831) OR (`AreaId` IN (10529, 10588, 10527) AND `PhaseId` = 13832) OR (`AreaId` IN (10529, 10588, 10528) AND `PhaseId` = 13809) OR (`AreaId` IN (10529, 10588, 10528) AND `PhaseId` = 13811) OR (`AreaId` IN (10529, 10588, 10528, 10527) AND `PhaseId` = 13318) OR (`AreaId` IN (10588, 10529, 10527) AND `PhaseId` = 13836) OR (`AreaId` IN (10529, 10588, 10527) AND `PhaseId` = 15011);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
-- Clientside GameObjects
(10529, 13794, 'Cosmetic - 9.0 NPE - Alliance Populated Camp'), -- Ogre Ruins
(10588, 13794, 'Cosmetic - 9.0 NPE - Alliance Populated Camp'), -- Darkmaul Plains
(10527, 13794, 'Cosmetic - 9.0 NPE - Alliance Populated Camp'), -- Hruns Barrows
-- Alaria & Bjorn
(10529, 13833, 'See Bjorn and Alaria at Alliance Populated Camp'), -- Ogre Ruins
(10588, 13833, 'See Bjorn and Alaria at Alliance Populated Camp'), -- Darkmaul Plains
(10527, 13833, 'See Bjorn and Alaria at Alliance Populated Camp'), -- Hruns Barrows
-- Alaria & Bjorn at Hruns Barrows
(10529, 13816, 'See Bjorn and Alaria at Hruns Barrows'), -- Ogre Ruins
(10588, 13816, 'See Bjorn and Alaria at Hruns Barrows'), -- Darkmaul Plains
(10527, 13816, 'See Bjorn and Alaria at Hruns Barrows'), -- Hruns Barrows
-- Alaria & Bjorn back at Camp
(10529, 13832, 'See Bjorn and Alaria back at Alliance Populated Camp'), -- Ogre Ruins
(10588, 13832, 'See Bjorn and Alaria back at Alliance Populated Camp'), -- Darkmaul Plains
(10527, 13832, 'See Bjorn and Alaria back at Alliance Populated Camp'), -- Hruns Barrows
-- Ralia Dreamchaser
(10529, 13831, 'See Ralia at Alliance Populated Camp'), -- Ogre Ruins
(10588, 13831, 'See Ralia at Alliance Populated Camp'), -- Darkmaul Plains
(10527, 13831, 'See Ralia at Alliance Populated Camp'), -- Hruns Barrows
-- Henry Garricks & Kee-La
(10529, 13809, 'See Henry and Kee-La at Alliance Populated Camp'), -- Ogre Ruins
(10588, 13809, 'See Henry and Kee-La at Alliance Populated Camp'), -- Darkmaul Plains
(10528, 13809, 'See Henry and Kee-La at Alliance Populated Camp'), -- Harpy Roost
-- Henry Garricks & Kee-La at Harpy Roost
(10529, 13811, 'See Henry and Kee-La at Harpy Roost'), -- Ogre Ruins
(10588, 13811, 'See Henry and Kee-La at Harpy Roost'), -- Darkmaul Plains
(10528, 13811, 'See Henry and Kee-La at Harpy Roost'), -- Harpy Roost
-- Henry Garricks & Kee-La back at Camp
(10529, 13318, 'See Henry and Kee-La back at Alliance Populated Camp'), -- Ogre Ruins
(10588, 13318, 'See Henry and Kee-La back at Alliance Populated Camp'), -- Darkmaul Plains
(10528, 13318, 'See Henry and Kee-La back at Alliance Populated Camp'), -- Harpy Roost
(10527, 13318, 'See Henry and Kee-La back at Alliance Populated Camp'), -- Hruns Barrows
-- Meredy back at Camp
(10588, 13836, 'See Meredy back at Alliance Populated Camp'), -- Darkmaul Plains
(10529, 13836, 'See Meredy back at Alliance Populated Camp'), -- Ogre Ruins
(10527, 13836, 'See Meredy back at Alliance Populated Camp'), -- Hruns Barrows
-- Private Cole at Camp
(10529, 15011, 'Cosmetic - See Private Cole at Alliance Populated Camp'), -- Ogre Ruins
(10588, 15011, 'Cosmetic - See Private Cole at Alliance Populated Camp'), -- Darkmaul Plains
(10527, 15011, 'Cosmetic - See Private Cole at Alliance Populated Camp'); -- Hruns Barrows

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13794 AND `SourceEntry` IN (10529, 10588, 10527)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13833 AND `SourceEntry` IN (10529, 10588, 10527)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13816 AND `SourceEntry` IN (10529, 10588, 10527)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13831 AND `SourceEntry` IN (10529, 10588, 10527)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13832 AND `SourceEntry` IN (10529, 10588, 10527)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13809 AND `SourceEntry` IN (10529, 10588, 10528)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13811 AND `SourceEntry` IN (10529, 10588, 10528)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13318 AND `SourceEntry` IN (10529, 10588, 10527, 10528)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13836 AND `SourceEntry` IN (10529, 10588, 10527)) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 15011 AND `SourceEntry` IN (10529, 10588, 10527));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 13794, 10529, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13794 if Quest 55879 is rewarded'), -- Ogre Ruins
(26, 13794, 10588, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13794 if Quest 55879 is rewarded'), -- Darkmaul Plains
(26, 13794, 10527, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13794 if Quest 55879 is rewarded'), -- Hruns Barrows
-- Alaria & Bjorn
(26, 13833, 10529, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13833 if Quest 55879 is rewarded'), -- Ogre Ruins
(26, 13833, 10529, 0, 0, 47, 0, 55965, 2 | 8 | 64, 0, 1, 'Apply Phase 13833 if Quest 55965 is not in progress | complete | rewarded'), -- Ogre Ruins
(26, 13833, 10588, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13833 if Quest 55879 is rewarded'), -- Darkmaul Plains
(26, 13833, 10588, 0, 0, 47, 0, 55965, 2 | 8 | 64, 0, 1, 'Apply Phase 13833 if Quest 55965 is not in progress | complete | rewarded'), -- Darkmaul Plains
(26, 13833, 10527, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13833 if Quest 55879 is rewarded'), -- Hruns Barrows
(26, 13833, 10527, 0, 0, 47, 0, 55965, 2 | 8 | 64, 0, 1, 'Apply Phase 13833 if Quest 55965 is not in progress | complete | rewarded'), -- Hruns Barrows
-- Alaria & Bjorn at Hruns Barrows
(26, 13816, 10529, 0, 0, 47, 0, 55965, 2 | 8 | 64, 0, 0, 'Apply Phase 13833 if Quest 55965 is in progress | complete | rewarded'), -- Ogre Ruins
(26, 13816, 10529, 0, 0, 47, 0, 55639, 2 | 64, 0, 1, 'Apply Phase 13833 if Quest 55639 is not complete | rewarded'), -- Ogre Ruins
(26, 13816, 10588, 0, 0, 47, 0, 55965, 2 | 8 | 64, 0, 0, 'Apply Phase 13833 if Quest 55965 is in progress | complete | rewarded'), -- Darkmaul Plains
(26, 13816, 10588, 0, 0, 47, 0, 55639, 2 | 64, 0, 1, 'Apply Phase 13833 if Quest 55639 is not complete | rewarded'), -- Darkmaul Plains
(26, 13816, 10527, 0, 0, 47, 0, 55965, 2 | 8 | 64, 0, 0, 'Apply Phase 13833 if Quest 55965 is in progress | complete | rewarded'), -- Hruns Barrows
(26, 13816, 10527, 0, 0, 47, 0, 55639, 2 | 64, 0, 1, 'Apply Phase 13833 if Quest 55639 is not complete | rewarded'), -- Darkmaul Plains
-- Alaria & Bjorn back at Camp
(26, 13832, 10529, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13832 if Quest 55639 is complete | rewarded'), -- Ogre Ruins
(26, 13832, 10588, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13832 if Quest 55639 is complete | rewarded'), -- Darkmaul Plains
(26, 13832, 10527, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13832 if Quest 55639 is complete | rewarded'), -- Hruns Barrows
-- Ralia Dreamchaser
(26, 13831, 10529, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13831 if Quest 55639 is complete | rewarded'), -- Ogre Ruins
(26, 13831, 10588, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13831 if Quest 55639 is complete | rewarded'), -- Darkmaul Plains
(26, 13831, 10527, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13831 if Quest 55639 is complete | rewarded'), -- Hruns Barrows
-- Henry Garricks & Kee-La
(26, 13809, 10529, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13809 if Quest 55879 is rewarded'), -- Ogre Ruins
(26, 13809, 10529, 0, 0, 47, 0, 55196, 2 | 8 | 64, 0, 1, 'Apply Phase 13809 if Quest 55196 is not in progress | complete | rewarded'), -- Ogre Ruins
(26, 13809, 10588, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13809 if Quest 55879 is rewarded'), -- Darkmaul Plains
(26, 13809, 10588, 0, 0, 47, 0, 55196, 2 | 8 | 64, 0, 1, 'Apply Phase 13809 if Quest 55196 is not in progress | complete | rewarded'), -- Darkmaul Plains
(26, 13809, 10528, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 13809 if Quest 55879 is rewarded'), -- Harpy Roost
(26, 13809, 10528, 0, 0, 47, 0, 55196, 2 | 8 | 64, 0, 1, 'Apply Phase 13809 if Quest 55196 is not in progress | complete | rewarded'), -- Harpy Roost
-- Henry Garricks & Kee-La at Harpy Roost
(26, 13811, 10529, 0, 0, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is in progress | complete | rewarded'), -- Ogre Ruins
(26, 13811, 10529, 0, 0, 47, 0, 55763, 1, 0, 0, 'Apply Phase 13811 if Quest 55763 is not taken'), -- Ogre Ruins
(26, 13811, 10529, 0, 1, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is in progress | complete | rewarded'), -- Ogre Ruins
(26, 13811, 10529, 0, 1, 47, 0, 55764, 1, 0, 0, 'Apply Phase 13811 if Quest 55764 is not taken'), -- Ogre Ruins
(26, 13811, 10529, 0, 2, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is progress | complete | rewarded'), -- Ogre Ruins
(26, 13811, 10529, 0, 2, 47, 0, 55881, 1, 0, 0, 'Apply Phase 13811 if Quest 55881 is not taken'), -- Ogre Ruins
(26, 13811, 10529, 0, 3, 47, 0, 55763, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55763 is complete | rewarded'), -- Ogre Ruins
(26, 13811, 10529, 0, 3, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not taken'), -- Ogre Ruins
(26, 13811, 10529, 0, 4, 47, 0, 55764, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55764 is complete | rewarded'), -- Ogre Ruins
(26, 13811, 10529, 0, 4, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not taken'), -- Ogre Ruins
(26, 13811, 10529, 0, 5, 47, 0, 55881, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55881 is complete | rewarded'), -- Ogre Ruins
(26, 13811, 10529, 0, 5, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not taken'), -- Ogre Ruins
(26, 13811, 10588, 0, 0, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is in progress | complete | rewarded'), -- Darkmaul Plains
(26, 13811, 10588, 0, 0, 47, 0, 55763, 1, 0, 0, 'Apply Phase 13811 if Quest 55763 is not taken'), -- Darkmaul Plains
(26, 13811, 10588, 0, 1, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is in progress | complete | rewarded'), -- Darkmaul Plains
(26, 13811, 10588, 0, 1, 47, 0, 55764, 1, 0, 0, 'Apply Phase 13811 if Quest 55764 is not taken'), -- Darkmaul Plains
(26, 13811, 10588, 0, 2, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is progress | complete | rewarded'), -- Darkmaul Plains
(26, 13811, 10588, 0, 2, 47, 0, 55881, 1, 0, 0, 'Apply Phase 13811 if Quest 55881 is not taken'), -- Darkmaul Plains
(26, 13811, 10588, 0, 3, 47, 0, 55763, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55763 is complete | rewarded'), -- Darkmaul Plains
(26, 13811, 10588, 0, 3, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not takend'), -- Darkmaul Plains
(26, 13811, 10588, 0, 4, 47, 0, 55764, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55764 is complete | rewarded'), -- Darkmaul Plains
(26, 13811, 10588, 0, 4, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not taken'), -- Darkmaul Plains
(26, 13811, 10588, 0, 5, 47, 0, 55881, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55881 is complete | rewarded'), -- Darkmaul Plains
(26, 13811, 10588, 0, 5, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not taken'), -- Darkmaul Plains
(26, 13811, 10528, 0, 0, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is in progress | complete | rewarded'), -- Harpy Roost
(26, 13811, 10528, 0, 0, 47, 0, 55763, 1, 0, 0, 'Apply Phase 13811 if Quest 55763 is not taken'), -- Harpy Roost
(26, 13811, 10528, 0, 1, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is in progress | complete | rewarded'), -- Harpy Roost
(26, 13811, 10528, 0, 1, 47, 0, 55764, 1, 0, 0, 'Apply Phase 13811 if Quest 55764 is not taken'), -- Harpy Roost
(26, 13811, 10528, 0, 2, 47, 0, 55196, 2 | 8 | 64, 0, 0, 'Apply Phase 13811 if Quest 55196 is progress | complete | rewarded'), -- Harpy Roost
(26, 13811, 10528, 0, 2, 47, 0, 55881, 1, 0, 0, 'Apply Phase 13811 if Quest 55881 is not taken'), -- Harpy Roost
(26, 13811, 10528, 0, 3, 47, 0, 55763, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55763 is complete | rewarded'), -- Harpy Roost
(26, 13811, 10528, 0, 3, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not taken'), -- Harpy Roost
(26, 13811, 10528, 0, 4, 47, 0, 55764, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55764 is complete | rewarded'), -- Harpy Roost
(26, 13811, 10528, 0, 4, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not taken'), -- Harpy Roost
(26, 13811, 10528, 0, 5, 47, 0, 55881, 2 | 64, 0, 0, 'Apply Phase 13811 if Quest 55881 is complete | rewarded'), -- Harpy Roost
(26, 13811, 10528, 0, 5, 47, 0, 55882, 1, 0, 0, 'Apply Phase 13811 if Quest 55882 is not taken'), -- Harpy Roost
-- Henry and Kee-La back at Camp
(26, 13318, 10529, 0, 0, 47, 0, 55882, 2 | 64, 0, 0, 'Apply Phase 13318 if Quest 55882 is complete | rewarded'), -- Ogre Ruins
(26, 13318, 10588, 0, 0, 47, 0, 55882, 2 | 64, 0, 0, 'Apply Phase 13318 if Quest 55882 is complete | rewarded'), -- Darkmaul Plains
(26, 13318, 10527, 0, 0, 47, 0, 55882, 2 | 64, 0, 0, 'Apply Phase 13318 if Quest 55882 is complete | rewarded'), -- Hruns Barrows
(26, 13318, 10528, 0, 0, 47, 0, 55882, 2 | 64, 0, 0, 'Apply Phase 13318 if Quest 55882 is complete | rewarded'), -- Harpy Roost
-- Meredy back at Camp
(26, 13836, 10529, 0, 0, 47, 0, 55882, 2 | 64, 0, 0, 'Apply Phase 13836 if Quest 55882 is complete | rewarded'), -- Ogre Ruins
(26, 13836, 10588, 0, 0, 47, 0, 55882, 2 | 64, 0, 0, 'Apply Phase 13836 if Quest 55882 is complete | rewarded'), -- Darkmaul Plains
(26, 13836, 10527, 0, 0, 47, 0, 55882, 2 | 64, 0, 0, 'Apply Phase 13836 if Quest 55882 is complete | rewarded'), -- Hruns Barrows
-- Private Cole at Camp
(26, 15011, 10529, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 15011 if Quest 55879 is rewarded'), -- Ogre Ruins
(26, 15011, 10588, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 15011 if Quest 55879 is rewarded'), -- Darkmaul Plains
(26, 15011, 10527, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 15011 if Quest 55879 is rewarded'); -- Hruns Barrows
