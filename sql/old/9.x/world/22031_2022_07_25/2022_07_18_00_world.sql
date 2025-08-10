SET @CGUID := 460621;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 76411, 1116, 6720, 7765, '0', 3194, 0, 0, 0, 5540.1015625, 5012.24462890625, 12.96455001831054687, 5.017282962799072265, 7200, 0, 0, 24630, 0, 0, 0, 0, 0, 44325), -- Farseer Drek'Thar (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 78288, 1116, 6720, 7765, '0', 3194, 0, 0, 1, 5536.28564453125, 5009.91162109375, 12.91583633422851562, 5.380505561828613281, 7200, 0, 0, 19710, 9573, 0, 0, 0, 0, 44325), -- Archmage Khadgar (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 70859, 1116, 6720, 7765, '0', 3194, 0, 0, 1, 5537.3671875, 5011.87841796875, 12.85560894012451171, 5.223853111267089843, 7200, 0, 0, 2955600, 320750, 0, 0, 0, 0, 44325), -- Thrall (Area: -Unknown- - Difficulty: 0
(@CGUID+3, 78272, 1116, 6720, 7765, '0', 2406, 0, 0, 1, 5435.1630859375, 4949.3974609375, 64.76441192626953125, 1.229404687881469726, 7200, 0, 0, 738900, 0, 0, 0, 0, 0, 44325), -- Durotan (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 80415, 1116, 6720, 7765, '0', 3441, 0, 0, 1, 5524.65283203125, 5030.6396484375, 15.1562957763671875, 1.210091352462768554, 7200, 0, 0, 24630, 0, 0, 0, 0, 0, 44325), -- Lady Liadrin (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 79451, 1116, 6720, 7765, '0', 3441, 0, 0, 1, 5522.2724609375, 5028.8291015625, 15.26221656799316406, 1.528014183044433593, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44325); -- Olin Umberhide (Area: -Unknown- - Difficulty: 0)

-- Creature Template
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `unit_flags3`=1048576 WHERE `entry`=78272; -- Durotan
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=70859; -- Thrall
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `gossip_menu_id`=16344 WHERE `entry`=78288; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=76411; -- Farseer Drek'Thar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `gossip_menu_id`=16488 WHERE `entry`=80415; -- Lady Liadrin
UPDATE `creature_template` SET `gossip_menu_id`=16489 WHERE `entry`=79451; -- Olin Umberhide

-- Phase
DELETE FROM `phase_area` WHERE (`AreaId` = 7765 AND `PhaseId` = 3194) OR (`AreaId` = 7765 AND `PhaseId` = 2406) OR (`AreaId` = 7765 AND `PhaseId` = 3441);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7765, 3194, 'Cosmetic - Iconics at Garrison Landing'),
(7765, 2406, 'Cosmetic - See Durotan near Garrison Landing'),
(7765, 3441, 'Cosmetic - Less-Iconics at Garrison Landing');

UPDATE `phase_name` SET `Name`='Cosmetic - See Durotan near Garrison Landing' WHERE `ID`=2406; -- yes its not coliseum, blizz trolled

-- conditon
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3194 AND `SourceEntry` = 7765) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 2406 AND `SourceEntry` = 7765) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3441 AND `SourceEntry` = 7765);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3194, 7765, 0, 0, 9, 0, 33815, 0, 0, 1, 'Apply Phase 3194 If Quest 33815 IS NOT taken'),
(26, 3194, 7765, 0, 0, 47, 0, 33815, 66, 0, 1, 'Apply Phase 3194 If Quest 33815 IS NOT complete/rewarded'),
(26, 2406, 7765, 0, 0, 9, 0, 34402, 0, 0, 1, 'Apply Phase 2406 If Quest 34402 IS NOT taken'),
(26, 2406, 7765, 0, 0, 47, 0, 34402, 66, 0, 1, 'Apply Phase 2406 If Quest 34402 IS NOT complete/rewarded'),
(26, 3441, 7765, 0, 0, 47, 0, 33815, 64, 0, 1, 'Apply Phase 3441 If Quest 33815 IS NOT rewarded');

DELETE FROM `gossip_menu` WHERE (`MenuID`=16344 AND `TextID`=23663) OR (`MenuID`=16488 AND `TextID`=23938) OR (`MenuID`=16489 AND `TextID`=23939);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(16344, 23663, 44325), -- 78288 (Archmage Khadgar)
(16488, 23938, 44325), -- 80415 (Lady Liadrin)
(16489, 23939, 44325); -- 79451 (Olin Umberhide)

DELETE FROM `npc_text` WHERE `ID` IN (23938 /*23938*/, 23939 /*23939*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(23938, 1, 0, 0, 0, 0, 0, 0, 0, 82565, 0, 0, 0, 0, 0, 0, 0, 44325), -- 23938
(23939, 1, 0, 0, 0, 0, 0, 0, 0, 82566, 0, 0, 0, 0, 0, 0, 0, 44325); -- 23939

UPDATE `npc_text` SET `VerifiedBuild`=44325 WHERE `ID`=23663;
