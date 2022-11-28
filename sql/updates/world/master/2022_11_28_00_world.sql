SET @CGUID := 651819;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89032, 1220, 7334, 7344, '0', 4302, 0, 0, 0, -358.40277099609375, 6588.8994140625, 0.215799957513809204, 1.499445915222167968, 120, 0, 0, 7846, 0, 0, 0, 0, 0, 46549), -- Vrykul Harpooner (Area: Shipwreck Arena - Difficulty: 0)
(@CGUID+1, 89026, 1220, 7334, 7344, '0', 4304, 0, 0, 0, -357.618072509765625, 6590.0556640625, 0.215799957513809204, 1.663296461105346679, 120, 0, 0, 7846, 0, 0, 0, 0, 0, 46549), -- Kul Tiras Marine (Area: Shipwreck Arena - Difficulty: 0)
(@CGUID+2, 89029, 1220, 7334, 7344, '0', 4307, 0, 0, 0, -358.65625, 6590.8369140625, 0.215799957513809204, 1.451566576957702636, 120, 0, 0, 7846, 0, 0, 0, 0, 0, 46549), -- Kul Tiras Marine (Area: Shipwreck Arena - Difficulty: 0)
(@CGUID+3, 88908, 1220, 7334, 7344, '0', 4295, 0, 0, 1, -357.90277099609375, 6595.12255859375, 0.215799957513809204, 4.369774818420410156, 120, 0, 0, 15692, 0, 0, 0, 0, 0, 46549), -- Boss Whalebelly (Area: Shipwreck Arena - Difficulty: 0)
(@CGUID+4, 89036, 1220, 7334, 7344, '0', 4313, 0, 0, 0, -359.524322509765625, 6592.5380859375, 0.215799957513809204, 1.247439026832580566, 120, 0, 0, 7846, 0, 0, 0, 0, 0, 46549), -- Steamwheedle Rocketeer (Area: Shipwreck Arena - Difficulty: 0)
(@CGUID+5, 89034, 1220, 7334, 7344, '0', 4311, 0, 0, 0, -360.982635498046875, 6590.74853515625, 0.215799957513809204, 1.137022733688354492, 120, 0, 0, 7846, 0, 0, 0, 0, 0, 46549), -- Zandalari Striker (Area: Shipwreck Arena - Difficulty: 0)
(@CGUID+6, 89018, 1220, 7334, 7344, '0', 4309, 0, 0, 0, -355.44097900390625, 6590.95751953125, 0.215799957513809204, 1.912369132041931152, 120, 0, 0, 7846, 0, 0, 0, 0, 0, 46549), -- Brinesnout Raider (Area: Shipwreck Arena - Difficulty: 0)
(@CGUID+7, 88911, 1220, 7334, 7344, '0', 4296, 0, 0, 0, -371.664947509765625, 6659.41162109375, 1.416111946105957031, 0.02996908500790596, 120, 0, 0, 47076, 0, 0, 0, 0, 0, 46549), -- Bilgerudder (Area: Shipwreck Arena - Difficulty: 0)
(@CGUID+8, 89034, 1220, 7334, 7344, '0', 4312, 0, 0, 0, -370.604156494140625, 6646.38916015625, 1.460069537162780761, 0.282886296510696411, 120, 0, 0, 11294, 0, 0, 0, 0, 0, 46658), -- Zandalari Striker (Area: Shipwreck Arena - Difficulty: Normal)
(@CGUID+9, 89032, 1220, 7334, 7344, '0', 4303, 0, 0, 0, -368.192718505859375, 6664.83349609375, 1.512666940689086914, 5.999370098114013671, 120, 0, 0, 11294, 0, 0, 0, 0, 0, 46658), -- Vrykul Harpooner (Area: Shipwreck Arena - Difficulty: Normal)
(@CGUID+10, 89018, 1220, 7334, 7344, '0', 4310, 0, 0, 0, -367.09027099609375, 6643.1630859375, 1.181991219520568847, 0.412034690380096435, 120, 0, 0, 11294, 0, 0, 0, 0, 0, 46658), -- Brinesnout Raider (Area: Shipwreck Arena - Difficulty: Normal)
(@CGUID+11, 89026, 1220, 7334, 7344, '0', 4305, 0, 0, 0, -366.671875, 6664.77783203125, 1.221307754516601562, 5.984834671020507812, 120, 0, 0, 11294, 0, 0, 0, 0, 0, 46658), -- Kul Tiras Marine (Area: Shipwreck Arena - Difficulty: Normal)
(@CGUID+12, 89029, 1220, 7334, 7344, '0', 4308, 0, 0, 0, -366.734375, 6663.0234375, 1.055171132087707519, 6.043070316314697265, 120, 0, 0, 11294, 0, 0, 0, 0, 0, 46658), -- Kul Tiras Marine (Area: Shipwreck Arena - Difficulty: Normal)
(@CGUID+13, 89036, 1220, 7334, 7344, '0', 4314, 0, 0, 0, -367.40625, 6646.8818359375, 0.80381941795349121, 0.305847018957138061, 120, 0, 0, 11294, 0, 0, 0, 0, 0, 46658), -- Steamwheedle Rocketeer (Area: Shipwreck Arena - Difficulty: Normal)
(@CGUID+14, 88916, 1220, 7334, 7344, '0', 4297, 0, 0, 1, -370.618072509765625, 6649.99755859375, 0.886875748634338378, 0.085419289767742156, 120, 0, 0, 22588, 0, 0, 0, 0, 0, 46658); -- Boss Whalebelly (Area: Shipwreck Arena - Difficulty: Normal)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Boss Whalebelly
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- Brinesnout Raider
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, 4, ''), -- Bilgerudder
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''); -- Brinesnout Raider

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=46549 WHERE `entry`=89032; -- Vrykul Harpooner
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=46549 WHERE `entry` IN (89029, 89026); -- Kul Tiras Marine
UPDATE `creature_template` SET `gossip_menu_id`=17416, `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=46549 WHERE `entry`=88908; -- Boss Whalebelly
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=46549 WHERE `entry`=89036; -- Steamwheedle Rocketeer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=46549 WHERE `entry`=89034; -- Zandalari Striker
UPDATE `creature_template` SET `VerifiedBuild`=46549 WHERE `entry`=88911; -- Bilgerudder
UPDATE `creature_template` SET `gossip_menu_id`=17417, `minlevel`=45, `maxlevel`=45, `faction`=2136, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048, `VerifiedBuild`=46549 WHERE `entry`=88916; -- Boss Whalebelly

UPDATE `creature_template_model` SET `CreatureDisplayID`=714, `VerifiedBuild`=46549 WHERE (`CreatureID`=89018 AND `Idx`=0); -- Brinesnout Raider

UPDATE `gossip_menu` SET `VerifiedBuild`=46549 WHERE (`MenuID`=17416 AND `TextID`=25871);

UPDATE `quest_template` SET `VerifiedBuild`=46658 WHERE `ID`=37507; -- Boss Whalebelly's in Charge

UPDATE `quest_poi` SET `VerifiedBuild`=46658 WHERE (`QuestID`=37507 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37507 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37507 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46658 WHERE (`QuestID`=37507 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37507 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37507 AND `Idx1`=0 AND `Idx2`=0);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (4295, 4296, 4297, 4302, 4303, 4304, 4305, 4307, 4308, 4309, 4310, 4311, 4312, 4313, 4314);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4295, 'Cosmetic - See Boss Whalebelly at Shipwreck Arena (water)'),
(4297, 'Cosmetic - See Boss Whalebelly at Shipwreck Arena (ship)'),
(4296, 'Cosmetic - See Bilgerudder at Shipwreck Arena'),
(4302, 'Cosmetic - See Vrykul Arponeer at Shipwreck Arena (water)'),
(4303, 'Cosmetic - See Vrykul Arponeer at Shipwreck Arena (ship)'),
(4304, 'Cosmetic - See Kul Tiras Marine #1 at Shipwreck Arena (water)'),
(4305, 'Cosmetic - See Kul Tiras Marine #1 at Shipwreck Arena (ship)'),
(4307, 'Cosmetic - See Kul Tiras Marine #2 at Shipwreck Arena (water)'),
(4308, 'Cosmetic - See Kul Tiras Marine #2 at Shipwreck Arena (ship)'),
(4309, 'Cosmetic - See Brinesnout Raider at Shipwreck Arena (water)'),
(4310, 'Cosmetic - See Brinesnout Raider at Shipwreck Arena (ship)'),
(4311, 'Cosmetic - See Zandalari Striker at Shipwreck Arena (water)'),
(4312, 'Cosmetic - See Zandalari Striker at Shipwreck Arena (ship)'),
(4313, 'Cosmetic - See Steamwheedle Rocketeer at Shipwreck Arena (water)'),
(4314, 'Cosmetic - See Steamwheedle Rocketeer at Shipwreck Arena (ship)');

DELETE FROM `phase_area` WHERE `AreaId` = 7344 AND `PhaseId` IN (4295, 4296, 4297, 4302, 4303, 4304, 4305, 4307, 4308, 4309, 4310, 4311, 4312, 4313, 4314);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7344, 4295, 'See Boss Whalebelly at Shipwreck Arena (water)'),
(7344, 4296, 'See Bilgerudder at Shipwreck Arena (ship)'),
(7344, 4297, 'See Boss Whalebelly at Shipwreck Arena (ship)'),
(7344, 4302, 'See Vrykul Arponeer at Shipwreck Arena (water)'),
(7344, 4303, 'See Vrykul Arponeer at Shipwreck Arena (ship)'),
(7344, 4304, 'See Kul Tiras Marine #1 at Shipwreck Arena (water)'),
(7344, 4305, 'See Kul Tiras Marine #1 at Shipwreck Arena (ship)'),
(7344, 4307, 'See Kul Tiras Marine #2 at Shipwreck Arena (water)'),
(7344, 4308, 'See Kul Tiras Marine #2 at Shipwreck Arena (ship)'),
(7344, 4309, 'See Brinesnout Raider at Shipwreck Arena (water)'),
(7344, 4310, 'See Brinesnout Raider at Shipwreck Arena (ship)'),
(7344, 4311, 'See Zandalari Striker at Shipwreck Arena (water)'),
(7344, 4312, 'See Zandalari Striker at Shipwreck Arena (ship)'),
(7344, 4313, 'See Steamwheedle Rocketeer at Shipwreck Arena (water)'),
(7344, 4314, 'See Steamwheedle Rocketeer at Shipwreck Arena (ship)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4295, 4297, 4302, 4303, 4304, 4305, 4307, 4308, 4309, 4310, 4311, 4312, 4313, 4314) AND `SourceEntry` = 7344;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4295, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 1, 'Apply Phase 4295 if Quest 37507 is not completed | rewarded'),
(26, 4302, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 1, 'Apply Phase 4302 if Quest 37507 is not completed | rewarded'),
(26, 4304, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 1, 'Apply Phase 4304 if Quest 37507 is not completed | rewarded'),
(26, 4307, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 1, 'Apply Phase 4307 if Quest 37507 is not completed | rewarded'),
(26, 4309, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 1, 'Apply Phase 4309 if Quest 37507 is not completed | rewarded'),
(26, 4311, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 1, 'Apply Phase 4311 if Quest 37507 is not completed | rewarded'),
(26, 4313, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 1, 'Apply Phase 4313 if Quest 37507 is not completed | rewarded'),
(26, 4297, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 0, 'Apply Phase 4297 if Quest 37507 is completed | rewarded'),
(26, 4297, 7344, 0, 0, 47, 0, 37538, 8 | 2, 0, 1, 'Apply Phase 4297 if Quest 37538 is not in progress | completed'),
(26, 4303, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 0, 'Apply Phase 4303 if Quest 37507 is completed | rewarded'),
(26, 4303, 7344, 0, 0, 47, 0, 37538, 8 | 2, 0, 1, 'Apply Phase 4303 if Quest 37538 is not in progress | completed'),
(26, 4305, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 0, 'Apply Phase 4305 if Quest 37507 is completed | rewarded'),
(26, 4305, 7344, 0, 0, 47, 0, 37538, 8 | 2, 0, 1, 'Apply Phase 4305 if Quest 37538 is not in progress | completed'),
(26, 4308, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 0, 'Apply Phase 4308 if Quest 37507 is completed | rewarded'),
(26, 4308, 7344, 0, 0, 47, 0, 37538, 8 | 2, 0, 1, 'Apply Phase 4308 if Quest 37538 is not in progress | completed'),
(26, 4310, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 0, 'Apply Phase 4310 if Quest 37507 is completed | rewarded'),
(26, 4310, 7344, 0, 0, 47, 0, 37538, 8 | 2, 0, 1, 'Apply Phase 4310 if Quest 37538 is not in progress | completed'),
(26, 4312, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 0, 'Apply Phase 4312 if Quest 37507 is completed | rewarded'),
(26, 4312, 7344, 0, 0, 47, 0, 37538, 8 | 2, 0, 1, 'Apply Phase 4312 if Quest 37538 is not in progress | completed'),
(26, 4314, 7344, 0, 0, 47, 0, 37507, 2 | 64, 0, 0, 'Apply Phase 4314 if Quest 37507 is completed | rewarded'),
(26, 4314, 7344, 0, 0, 47, 0, 37538, 8 | 2, 0, 1, 'Apply Phase 4314 if Quest 37538 is not in progress | completed');
