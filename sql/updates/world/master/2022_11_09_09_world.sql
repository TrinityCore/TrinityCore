SET @CGUID := 651510;
SET @OGUID := 400421;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 98019, 1220, 7334, 7361, '0', 5260, 0, 0, 0, 1136.03125, 6283.56005859375, 110.32708740234375, 3.752716779708862304, 120, 0, 0, 156920, 0, 0, 0, 0, 0, 46455), -- Baric Metamorphosis
(@CGUID+1, 97736, 1220, 7334, 7361, '0', 5260, 0, 0, 1, 1136.125, 6283.4619140625, 110.3270339965820312, 3.723321914672851562, 120, 0, 0, 19615, 100, 0, 0, 0, 0, 46455), -- Baric Stormrunner
(@CGUID+2, 98026, 1220, 7334, 7361, '0', 5267, 0, 0, 1, 1133.7708740234375, 6272.1953125, 109.9552230834960937, 4.251774311065673828, 120, 0, 0, 19615, 100, 0, 0, 0, 0, 46455); -- Baric Stormrunner (Area: Ley-Ruins of Zarkhenar - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '69676 193288'), -- Baric Metamorphosis - 69676 - Cosmetic - Alpha State 50%, 193288 - Cosmetic - Alpha State 10%
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '177766'), -- Baric Stormrunner - 177766 - Levitate
(@CGUID+2, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''); -- Baric Stormrunner

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=98026 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(98026, 1, 128361, 0, 0, 128369, 0, 0, 0, 0, 0, 46455); -- Baric Stormrunner

UPDATE `creature_questender` SET `VerifiedBuild`=46455 WHERE (`id`=98026 AND `quest`=39938);

UPDATE `creature_template` SET `gossip_menu_id`=18836, `minlevel`=45, `maxlevel`=45, `faction`=2839, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `VerifiedBuild`=46455 WHERE `entry`=98026; -- Baric Stormrunner
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=2838, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048, `unit_flags3`=16777216, `VerifiedBuild`=46455 WHERE `entry`=98019; -- Baric Metamorphosis

UPDATE `creature_equip_template` SET `VerifiedBuild`=46455 WHERE (`CreatureID`=97736 AND `ID`=1);

DELETE FROM `quest_offer_reward` WHERE `ID`=39938;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(39938, 1, 1, 0, 0, 0, 0, 0, 0, 'It is done. I fear that if I had waited any longer to improve my wards, the demon in me may have taken over.$b$bThank you again, $n.', 46455); -- Containing the Demon Within

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 244738, 1220, 7334, 7361, '0', 5259, 0, 1136.0191650390625, 6283.50439453125, 110.2437362670898437, 0.61010754108428955, 0, 0, 0.300344467163085937, 0.9538307785987854, 120, 255, 1, 46455), -- Baric's Runic Circle 01
(@OGUID+1, 244739, 1220, 7334, 7361, '0', 5259, 0, 1134.0416259765625, 6278.08935546875, 110.2199325561523437, 0.61010754108428955, 0, 0, 0.300344467163085937, 0.9538307785987854, 120, 255, 1, 46455), -- Baric's Runic Circle 02
(@OGUID+2, 244739, 1220, 7334, 7361, '0', 5259, 0, 1132.560791015625, 6288.462890625, 110.269561767578125, 0.61010754108428955, 0, 0, 0.300344467163085937, 0.9538307785987854, 120, 255, 1, 46455), -- Baric's Runic Circle 02
(@OGUID+3, 244739, 1220, 7334, 7361, '0', 5259, 0, 1142, 6283.6953125, 110.232818603515625, 0.61010754108428955, 0, 0, 0.300344467163085937, 0.9538307785987854, 120, 255, 1, 46455), -- Baric's Runic Circle 02
(@OGUID+4, 244742, 1220, 7334, 7361, '0', 5260, 0, 1142.076416015625, 6283.673828125, 110.2322006225585937, 3.054414033889770507, 0, 0, 0.999050140380859375, 0.043575510382652282, 120, 255, 1, 46455), -- Baric's Ritual Essence (Area: -Unknown- - Difficulty: 0)
(@OGUID+5, 244740, 1220, 7334, 7361, '0', 5260, 0, 1132.5833740234375, 6288.4287109375, 110.2689971923828125, 0, 0, 0, 0, 1, 120, 255, 1, 46455), -- Baric's Ritual Essence (Area: -Unknown- - Difficulty: 0)
(@OGUID+6, 244741, 1220, 7334, 7361, '0', 5260, 0, 1134.0572509765625, 6278.12841796875, 110.2212066650390625, 2.252085208892822265, 0, 0, 0.902716636657714843, 0.430235624313354492, 120, 255, 1, 46455); -- Baric's Ritual Essence

DELETE FROM `gameobject_template` WHERE `entry` IN (244742, 244741, 244740, 244739, 244738);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(244742, 10, 14918, 'Baric\'s Ritual Essence', 'questinteract', '', '', 0.70999997854232788, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 193282, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 36167, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 348, 46455), -- Baric's Ritual Essence
(244741, 10, 14918, 'Baric\'s Ritual Essence', 'questinteract', '', '', 0.70999997854232788, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 193281, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 36165, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 348, 46455), -- Baric's Ritual Essence
(244740, 10, 14918, 'Baric\'s Ritual Essence', 'questinteract', '', '', 0.70999997854232788, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 193280, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 36168, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 348, 46455), -- Baric's Ritual Essence
(244739, 5, 17800, 'Baric\'s Runic Circle 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 348, 46455), -- Baric's Runic Circle 02
(244738, 5, 7034, 'Baric\'s Runic Circle 01', '', '', '', 3.170000076293945312, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 348, 46455); -- Baric's Runic Circle 01

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (5259, 5260, 5267);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5259, 'Cosmetic - See Baric Stormrunner Runic Circles'),
(5260, 'Cosmetic - See Baric Stormrunner Ritual'),
(5267, 'Cosmetic - See Baric Stormrunner after Ritual');

DELETE FROM `phase_area` WHERE `AreaId` IN (7334,7361) AND `PhaseId` IN (5259, 5260,5267);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7334, 5259, 'See Baric Stormrunner Runic Circles in Ley-Ruins of Zarkhenar'),
(7334, 5260, 'See Baric Stormrunner Runic Ritual in Ley-Ruins of Zarkhenar'),
(7361, 5267, 'See Baric Stormrunner Runic after Ritual in Ley-Ruins of Zarkhenar');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (5259, 5260, 5267) AND `SourceEntry`  IN (7334, 7361));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5259, 7334, 0, 0, 47, 0, 39938, 8, 0, 0, 'Apply Phase 5259 if Quest 39938 is in progress'),
(26, 5259, 7334, 0, 0, 48, 0, 280166, 0, 1, 0, 'Apply Phase 5259 if player has quest objective done: Start the Ritual'),
(26, 5260, 7334, 0, 0, 47, 0, 39938, 8, 0, 0, 'Apply Phase 5260 if Quest 39938 is in progress'),
(26, 5260, 7334, 0, 0, 48, 0, 280166, 0, 1, 0, 'Apply Phase 5260 if player has quest objective done: Start the Ritual'),
(26, 5267, 7361, 0, 0, 47, 0, 39938, 2 | 64, 0, 0, 'Apply Phase 5267 if Quest 39938 is completed | rewarded');
