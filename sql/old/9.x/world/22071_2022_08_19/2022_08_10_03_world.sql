-- accept quest 40644
--     remove phase 5935 
--         despawns 101064
--     add phase 5626
--         spawns 103276 103277 103302 103293 103291 103281
--     add phase 5931
--         spawns 101065, 103372, 103373, 103875
-- objective 1 done (hamuul reaching his location)
--     add phase 5936
--         spawns 103420
-- objective 2 done (serverside at/inrange of malfurion)
--     remove phase 5931
--         all iconic druids move
--         
-- objective 3 done (channel) / quest complete
--     add phase 5628
--     add phase 5950
-- 
--         spawns 103373, 103372, 103276, 103299, 101065, 103875, 103476
--         spawns portal effect
-- turnin
--     remove phase 5626
--         despawns all helpers

SET @CGUID := 650136;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 101064, 1, 493, 2361, '0', 5935, 0, 0, 1, 8001.759765625, -2680.265625, 512.16680908203125, 3.177409172058105468, 120, 0, 0, 647200, 76700, 0, 0, 0, 0, 44908), -- Archdruid Hamuul Runetotem (Area: Nighthaven - Difficulty: 0)
(@CGUID+1, 103276, 1, 493, 656, '0', 5626, 0, 0, 1, 7587.28466796875, -2932.100830078125, 465.0479736328125, 3.896954298019409179, 120, 0, 0, 2588, 3801, 0, 0, 0, 0, 44908), -- Druid of the Talon (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+2, 103276, 1, 493, 656, '0', 5626, 0, 0, 1, 7544.8349609375, -2929.286376953125, 465.0479736328125, 5.486056327819824218, 120, 0, 0, 2588, 3801, 0, 0, 0, 0, 44908), -- Druid of the Talon (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+3, 103276, 1, 493, 2363, '0', 5626, 0, 0, 1, 7541.3837890625, -2971.263916015625, 465.0479736328125, 0.743347406387329101, 120, 0, 0, 2588, 3801, 0, 0, 0, 0, 44908), -- Druid of the Talon (Area: Stormrage Barrow Dens - Difficulty: 0)
(@CGUID+4, 103277, 1, 493, 656, '0', 5626, 0, 0, 1, 7594.39404296875, -2954.5244140625, 465.0479736328125, 3.17354440689086914, 120, 0, 0, 2588, 3801, 0, 0, 0, 0, 44908), -- Druid of the Talon (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+5, 103277, 1, 493, 2363, '0', 5626, 0, 0, 1, 7534.33056640625, -2951.142333984375, 465.0479736328125, 0.001882322249002754, 120, 0, 0, 2588, 3801, 0, 0, 0, 0, 44908), -- Druid of the Talon (Area: Stormrage Barrow Dens - Difficulty: 0)
(@CGUID+6, 103302, 1, 493, 2363, '0', 5626, 0, 0, 1, 7562.12060546875, -2981.486083984375, 465.0479736328125, 1.56773531436920166, 120, 0, 0, 2588, 3801, 0, 0, 0, 0, 44908), -- Druid of the Talon (Area: Stormrage Barrow Dens - Difficulty: 0)
(@CGUID+7, 103293, 1, 493, 2363, '0', 5626, 0, 0, 0, 7563.91748046875, -2960.282958984375, 468.0592041015625, 1.565186619758605957, 120, 0, 0, 3236, 0, 0, 0, 0, 0, 44908), -- Druid of the Claw (Area: Stormrage Barrow Dens - Difficulty: 0)
(@CGUID+8, 103291, 1, 493, 656, '0', 5626, 0, 0, 0, 7573.02685546875, -2952.032958984375, 468.0592041015625, 3.089622735977172851, 120, 0, 0, 3236, 0, 0, 0, 0, 0, 44908), -- Druid of the Claw (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+9, 103281, 1, 493, 656, '0', 5626, 0, 0, 0, 7555.1181640625, -2950.666748046875, 468.0592041015625, 6.213886260986328125, 120, 0, 0, 3236, 0, 0, 0, 0, 0, 44908), -- Druid of the Claw (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+10, 103875, 1, 493, 656, '0', 5931, 0, 0, 0, 7559.45068359375, -2897.03466796875, 460.7935791015625, 0.879814684391021728, 120, 0, 0, 4045000, 345150, 0, 0, 0, 0, 44908), -- Malfurion Stormrage (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+11, 101065, 1, 493, 656, '0', 5931, 0, 0, 0, 7572.61572265625, -2899.97216796875, 460.22271728515625, 1.588140368461608886, 120, 0, 0, 64720, 1534, 0, 0, 0, 0, 44908), -- Keeper Remulos (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+12, 103372, 1, 493, 656, '0', 5931, 0, 0, 1, 7565.8349609375, -2901.1181640625, 460.07147216796875, 1.821961641311645507, 120, 0, 0, 3236, 1534, 0, 0, 0, 0, 44908), -- Zen'tabra (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+13, 103373, 1, 493, 656, '0', 5931, 0, 0, 0, 7563.17724609375, -2899.8994140625, 460.043426513671875, 1.510910868644714355, 120, 0, 0, 9708, 0, 0, 0, 0, 0, 44908), -- Naralex (Area: Lake Elune'ara - Difficulty: 0)
(@CGUID+14, 103420, 1, 493, 2363, '0', 5936, 0, 0, 1, 7575.74462890625, -2883.22216796875, 462.478912353515625, 4.946101188659667968, 120, 0, 0, 647200, 76700, 0, 0, 0, 0, 44908), -- Archdruid Hamuul Runetotem (Area: Stormrage Barrow Dens - Difficulty: 0)
(@CGUID+15, 103421, 1, 493, 656, '0', 0, 0, 0, 0, 7565.48095703125, -2926.314208984375, 465.432891845703125, 0, 120, 0, 0, 324, 0, 0, 0, 0, 0, 44908); -- Ritual Bunny (Area: Lake Elune'ara - Difficulty: 0)

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=103420 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(103420, 1, 63052, 0, 0, 0, 0, 0, 0, 0, 0, 44908); -- Archdruid Hamuul Runetotem

DELETE FROM `creature_template_addon` WHERE `entry` IN (103421 /*103421 (Ritual Bunny)*/, 101064 /*101064 (Archdruid Hamuul Runetotem)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(103421, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 103421 (Ritual Bunny)
(101064, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''); -- 101064 (Archdruid Hamuul Runetotem)

DELETE FROM `phase_area` WHERE `PhaseId` IN(5935, 5626, 5931);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(493, 5935, 'See Hamuul Runetotem in Nighthaven (Legion Druid Campaign)'), 
(493, 5626, 'See Druid helper NPCs for creating Dreamway portal (Legion Druid Campaign)'),
(493, 5931, 'See iconic druids waiting before creating Dreamway portal (Legion Druid Campaign)'),
(493, 5936, 'See Hamuul Runetotem waiting before creating Dreamway portal (Legion Druid Campaign)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (5935, 5626, 5936, 5931, 5628, 5950));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5935, 493, 0, 0, 14, 0, 40644, 1, 0, 0, 'Player has never finished nor has active quest The Dreamway (40644)'),
(26, 5626, 493, 0, 0, 47, 0, 40644, 10, 0, 0, 'Player has The Dreamway (40644) in state complete, incomplete'),
(26, 5936, 493, 0, 0, 48, 0, 281070, 0, 1, 0, 'Player has completed objective 281070 (but hasn\'t rewarded quest yet)'),
(26, 5931, 493, 0, 0, 9, 0, 40644, 0, 0, 0, 'Player has quest The Dreamway (40644) active'),
(26, 5931, 493, 0, 0, 48, 0, 281958, 0, 1, 1, 'Player hasn\'t completed objective 281958 or has rewarded the quest'),
(26, 5628, 493, 0, 0, 48, 0, 281071, 0, 1, 0, 'Player has completed objective 281071 (but hasn\'t rewarded quest yet)'),
(26, 5628, 493, 0, 1, 8, 0, 40644, 0, 0, 0, 'Player has quest The Dreamway (40644) rewarded'),
(26, 5950, 493, 0, 0, 48, 0, 281071, 0, 1, 0, 'Player has completed objective 281071 (but hasn\'t rewarded quest yet)'),
(26, 5950, 493, 0, 1, 8, 0, 40644, 0, 0, 0, 'Player has quest The Dreamway (40644) rewarded');

DELETE FROM `phase_name` WHERE `ID` IN(5935, 5626, 5931, 5936);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5935, 'See Hamuul Runetotem in Nighthaven (Legion Druid Campaign)'),
(5626, 'See Druid helper NPCs for creating Dreamway portal (Legion Druid Campaign)'),
(5931, 'See iconic druids waiting before creating Dreamway portal (Legion Druid Campaign)'),
(5936, 'See Hamuul Runetotem waiting before creating Dreamway portal (Legion Druid Campaign)');

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (22889,101064,101065,103276,103277,103281,103291,103293,103299,103302,103372,103373,103420,103476,103875));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(22889, 0, 0, 0, 884, 44908),
(101064, 0, 0, 0, 642, 44908),
(101065, 0, 0, 0, 642, 44908),
(103276, 0, 0, 0, 642, 44908),
(103277, 0, 0, 0, 642, 44908),
(103281, 0, 0, 0, 642, 44908),
(103291, 0, 0, 0, 642, 44908),
(103293, 0, 0, 0, 642, 44908),
(103299, 0, 0, 0, 642, 44908),
(103302, 0, 0, 0, 642, 44908),
(103372, 0, 0, 0, 642, 44908),
(103373, 0, 0, 0, 642, 44908),
(103420, 0, 0, 0, 642, 44908),
(103476, 0, 0, 0, 642, 44908),
(103875, 0, 0, 0, 642, 44908);

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=103299; -- Moonglade Warden
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags3`=1048576 WHERE `entry` IN (103476, 101064); -- Archdruid Hamuul Runetotem
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=22889; -- Manifest Nightmare
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=22837; -- Dreamwarden Lurosa
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=22902; -- Phantasmal Lash
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=994, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=1048576 WHERE `entry`=103420; -- Archdruid Hamuul Runetotem
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry` IN (103302, 103277, 103276); -- Druid of the Talon
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry` IN (103293, 103291, 103281); -- Druid of the Claw
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=103373; -- Naralex
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=103372; -- Zen'tabra
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags3`=1048576 WHERE `entry`=101065; -- Keeper Remulos
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags3`=1048576 WHERE `entry`=103875; -- Malfurion Stormrage

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry` IN(103421);
