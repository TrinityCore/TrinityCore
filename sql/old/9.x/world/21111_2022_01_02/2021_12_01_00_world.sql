-- 
SET @CGUID := 1050147;

-- creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+34;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Dwarf Hunter Bear
(@CGUID+0, 167375, 2261, 10424, 10639, '0', 15404, 0, 0, 0, -1.7841954231262207, 8.35608673095703125, 5.183962821960449218, 2.553898811340332031, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Bear (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 167375, 2261, 10424, 10639, '0', 15418, 0, 0, 0, 31.47201919555664062, -2.22218537330627441, 4.928502082824707031, 2.19466257095336914, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Bear (Area: -Unknown- - Difficulty: 0)
-- Nightelf Hunter Tiger
(@CGUID+2, 167347, 2261, 10424, 10639, '0', 15403, 0, 0, 0, -1.7841954231262207, 8.35608673095703125, 5.183962821960449218, 2.553898811340332031, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- -Unknown- (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 167347, 2261, 10424, 10639, '0', 15317, 0, 0, 0, 31.47201919555664062, -2.22218537330627441, 4.928502082824707031, 2.19466257095336914, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- -Unknown- (Area: -Unknown- - Difficulty: 0)
-- Human Hunter Wolf
(@CGUID+4, 167345, 2261, 10424, 10639, '0', 15405, 0, 0, 0, -1.7841954231262207, 8.35608673095703125, 5.183962821960449218, 2.553898811340332031, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Wolf (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 167345, 2261, 10424, 10639, '0', 15419, 0, 0, 0, 31.47201919555664062, -2.22218537330627441, 4.928502082824707031, 2.19466257095336914, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Wolf (Area: -Unknown- - Difficulty: 0)
-- Gnome Hunter Mechanical Buny
(@CGUID+6, 167337, 2261, 10424, 10639, '0', 15402, 0, 0, 0, -1.7841954231262207, 8.35608673095703125, 5.183962821960449218, 2.553898811340332031, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Mechanical Bunny (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 167337, 2261, 10424, 10639, '0', 15416, 0, 0, 0, 31.47201919555664062, -2.22218537330627441, 4.928502082824707031, 2.19466257095336914, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Mechanical Bunny (Area: -Unknown- - Difficulty: 0)
-- Draenei Hunter Moth
(@CGUID+8, 167342, 2261, 10424, 10639, '0', 15401, 0, 0, 0, -1.7841954231262207, 8.35608673095703125, 5.183962821960449218, 2.553898811340332031, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Moth (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 167342, 2261, 10424, 10639, '0', 15415, 0, 0, 0, 31.47201919555664062, -2.22218537330627441, 4.928502082824707031, 2.19466257095336914, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Moth (Area: -Unknown- - Difficulty: 0)
-- Worgen Hunter Dog
(@CGUID+10, 167352, 2261, 10424, 10639, '0', 15400, 0, 0, 0, -1.7841954231262207, 8.35608673095703125, 5.183962821960449218, 2.553898811340332031, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Dog (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 167352, 2261, 10424, 10639, '0', 15414, 0, 0, 0, 31.47201919555664062, -2.22218537330627441, 4.928502082824707031, 2.19466257095336914, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Dog (Area: -Unknown- - Difficulty: 0)
-- Pandaren Hunter Turtle
(@CGUID+12, 167348, 2261, 10424, 10639, '0', 15399, 0, 0, 0, -1.7841954231262207, 8.35608673095703125, 5.183962821960449218, 2.553898811340332031, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Turtle (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 167348, 2261, 10424, 10639, '0', 15413, 0, 0, 0, 31.47201919555664062, -2.22218537330627441, 4.928502082824707031, 2.19466257095336914, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Turtle (Area: -Unknown- - Difficulty: 0)
-- Gryphons
(@CGUID+14, 156345, 2261, 10424, 10639, '0', 15286, 0, 0, 0, 14.20531082153320312, -26.5884475708007812, 6.417416095733642578, 3.128648757934570312, 7200, 0, 0, 124, 191, 0, 0, 0, 0, 41079), -- Wildhammer Gryphon (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+15, 156345, 2261, 10424, 10639, '0', 15286, 0, 0, 0, 2.541015625, 28.23583984375, 5.165633201599121093, 3.019754409790039062, 7200, 0, 0, 124, 191, 0, 0, 0, 0, 41079), -- Wildhammer Gryphon (Area: -Unknown- - Difficulty: 0) (Auras: )
-- Helmsman
(@CGUID+16, 157049, 2261, 10424, 10639, '0', 15284, 0, 0, 0, 35.08272171020507812, 0.047190301120281219, 12.1281280517578125, 3.144292116165161132, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Helmsman Lenard (Area: -Unknown- - Difficulty: 0)
-- Dummies
(@CGUID+17, 160737, 2261, 10424, 10639, '0', 0, 0, 0, 0, -11.1897535324096679, -7.82821083068847656, 5.428291797637939453, 0.674162268638610839, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
(@CGUID+18, 160737, 2261, 10424, 10639, '0', 0, 0, 0, 0, -14.015899658203125, 4.469318389892578125, 5.589790821075439453, 0, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
(@CGUID+19, 160737, 2261, 10424, 10639, '0', 0, 0, 0, 0, -7.63469696044921875, 9.629475593566894531, 5.227081298828125, 5.175071239471435546, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
(@CGUID+20, 160737, 2261, 10424, 10639, '0', 0, 0, 0, 0, -13.8276653289794921, -4.42006683349609375, 5.58518218994140625, 0, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
(@CGUID+21, 160737, 2261, 10424, 10639, '0', 0, 0, 0, 0, -7.8249969482421875, -9.21034431457519531, 5.289811134338378906, 0.997226417064666748, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
(@CGUID+22, 160737, 2261, 10424, 10639, '0', 0, 0, 0, 0, -11.2698230743408203, 8.094544410705566406, 5.423777103424072265, 5.367025375366210937, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
-- some trigger npc
(@CGUID+23, 155125, 2261, 10424, 10639, '0', 0, 0, 0, 0, 8, 0, 5.083333492279052734, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- -Unknown- (Area: -Unknown- - Difficulty: 0) (Auras: 305351 - -Unknown-)
-- decoration npcs stage 1
(@CGUID+24, 167886, 2261, 10424, 10639, '0', 14355, 0, 0, 0, 12.81454181671142578, -0.49229940772056579, 5.25865936279296875, 5.498137950897216796, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Alliance Sailor (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 157042, 2261, 10424, 10639, '0', 14355, 0, 0, 0, -1.84916245937347412, -8.44075584411621093, 5.126376152038574218, 1.615344762802124023, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Quartermaster Richter (Area: -Unknown- - Difficulty: 0)
(@CGUID+26, 157046, 2261, 10424, 10639, '0', 14355, 0, 0, 0, -4.48603677749633789, 9.742008209228515625, 5.148960590362548828, 6.073061466217041015, 7200, 0, 0, 99, 382, 0, 0, 0, 0, 41079), -- Austin Huxworth (Area: -Unknown- - Difficulty: 0)
(@CGUID+27, 157043, 2261, 10424, 10639, '0', 14355, 0, 0, 0, -15.4333686828613281, 6.548393726348876953, 5.587193012237548828, 3.309375524520874023, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Kee-La (Area: -Unknown- - Difficulty: 0)
(@CGUID+28, 157044, 2261, 10424, 10639, '0', 14355, 0, 0, 0, 12.87485980987548828, -8.51634407043457031, 5.083402633666992187, 5.096017837524414062, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Bjorn Stouthands (Area: -Unknown- - Difficulty: 0)
-- decoration npcs stage 2
(@CGUID+29, 156280, 2261, 10424, 10639, '0', 13861, 0, 0, 0, 26.98125267028808593, 5.439176559448242187, 4.957939624786376953, 3.31911778450012207, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Captain Garrick (Area: -Unknown- - Difficulty: 0)
(@CGUID+30, 157042, 2261, 10424, 10639, '0', 13861, 0, 0, 0, 29.86839103698730468, 0.785679280757904052, 4.963192462921142578, 1.306632757186889648, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Quartermaster Richter (Area: -Unknown- - Difficulty: 0)
(@CGUID+31, 157046, 2261, 10424, 10639, '0', 13861, 0, 0, 0, 30.04240226745605468, 2.580899238586425781, 4.972657680511474609, 4.732944488525390625, 7200, 0, 0, 99, 382, 0, 0, 0, 0, 41079), -- Austin Huxworth (Area: -Unknown- - Difficulty: 0)
(@CGUID+32, 157044, 2261, 10424, 10639, '0', 13861, 0, 0, 0, 29.2059326171875, 4.201228141784667968, 4.96921539306640625, 3.282791376113891601, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Bjorn Stouthands (Area: -Unknown- - Difficulty: 0)
(@CGUID+33, 157043, 2261, 10424, 10639, '0', 13861, 0, 0, 0, 27.51091957092285156, -1.03362488746643066, 4.952632904052734375, 3.295278787612915039, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Kee-La (Area: -Unknown- - Difficulty: 0)
(@CGUID+34, 160664, 2261, 10424, 10639, '0', 13861, 0, 0, 0, 30.93886756896972656, 6.37119150161743164, 4.900855541229248046, 4.120803356170654296, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079); -- Private Cole (Area: -Unknown- - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` IN(@CGUID+23, @CGUID+25, @CGUID+26, @CGUID+27);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, '305351'), -- -Unknown- - 305351 - -Unknown-
(@CGUID+25, 0, 0, 0, 1, 720, 0, 0, 0, ''), -- Quartermaster Richter
(@CGUID+26, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 157046 (Austin Huxworth)
(@CGUID+27, 0, 0, 8, 1, 0, 0, 0, 0, ''); -- 157043 (Kee-La)

DELETE FROM `creature_template_addon` WHERE `entry` IN (157049, 154867, 160737, 156345, 167886);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(157049, 0, 0, 0, 1, 0, 16390, 0, 0, ''), -- 157049 (Helmsman Lenard)
(154867, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 154867 (Wildhammer Gryphon Rider) - Ride Vehicle Hardcoded
(160737, 0, 0, 0, 1, 0, 0, 0, 0, '344178'), -- 160737 (Combat Dummy) - -Unknown-
(156345, 0, 0, 50331648, 1, 0, 18518, 0, 0, ''), -- 156345 (Wildhammer Gryphon)
(167886, 0, 0, 8, 1, 0, 0, 0, 0, ''); -- 167886 (Alliance Sailor)

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=154867 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(154867, 1, 122385, 0, 0, 0, 0, 0, 0, 0, 0); -- Wildhammer Gryphon Rider

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (91997, 91995, 92804);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(91997, 0.347222000360488891, 1.5, 0, 41079),
(91995, 0.347000002861022949, 1.5, 0, 41079),
(92804, 0.347222000360488891, 1.5, 0, 41079);

UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=157049; -- Helmsman Lenard
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=534, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048 WHERE `entry`=154867; -- Wildhammer Gryphon Rider
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=534, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048, `VehicleId`=6835 WHERE `entry`=156345; -- Wildhammer Gryphon
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=17 WHERE `entry`=160737; -- Combat Dummy
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=155125; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2618, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167886; -- Alliance Sailor
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=1732, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=157043; -- Kee-La
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2618, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=157044; -- Bjorn Stouthands
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=1732, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=157046; -- Austin Huxworth
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=1732, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=157042; -- Quartermaster Richter

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (156345, 160737);
INSERT INTO `creature_template_movement`(`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(156345, 1, 1, 1, 0),
(160737, 1, 1, 0, 1);

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (167375, 167347, 167337, 167342, 167352, 167348) AND `DifficultyID`=0;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(167375, 0, 0, 0, 482, 41079),
(167347, 0, 0, 0, 482, 41079),
(167337, 0, 0, 0, 482, 41079),
(167342, 0, 0, 0, 482, 41079),
(167352, 0, 0, 0, 482, 41079),
(167348, 0, 0, 0, 482, 41079);

DELETE FROM `vehicle_template_accessory` WHERE `entry` = 156345 AND `accessory_entry` = 154867;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(156345, 154867, 0, 0, 'Wildhammer Gryphon - Wildhammer Gryphon Rider', 6, 30000); -- Wildhammer Gryphon - Wildhammer Gryphon Rider

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 156345;
INSERT INTO `npc_spellclick_spells`(`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(156345, 46598, 1, 0);

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 10639 AND `PhaseId` IN (15404, 15418, 15403, 15417, 15405, 15419, 15402, 15416, 15401, 15415, 15400, 15414, 15399, 15413, 15286, 15284, 14355, 13861);
INSERT INTO `phase_area`(`AreaId`, `PhaseId`, `Comment`) VALUES
(10639, 15404, 'NPE Alliance Ship - Dwarf Hunter only: Bear (quest 58208 incomplete)'),
(10639, 15418, 'NPE Alliance Ship - Dwarf Hunter only: Bear during storm (quest 58208 complete)'),
(10639, 15403, 'NPE Alliance Ship - Nightelf Hunter only: Tiger (quest 58208 incomplete)'),
(10639, 15417, 'NPE Alliance Ship - Nightelf Hunter only: Tiger during storm (quest 58208 complete)'),
(10639, 15405, 'NPE Alliance Ship - Human Hunter only: Wolf (quest 58208 incomplete)'),
(10639, 15419, 'NPE Alliance Ship - Human Hunter only: Wolf during storm (quest 58208 complete)'),
(10639, 15402, 'NPE Alliance Ship - Gnome Hunter only: Mechanical Bunny (quest 58208 incomplete)'),
(10639, 15416, 'NPE Alliance Ship - Gnome Hunter only: Mechanical Bunny during storm (quest 58208 complete)'),
(10639, 15401, 'NPE Alliance Ship - Draenei Hunter only: Moth (quest 58208 incomplete)'),
(10639, 15415, 'NPE Alliance Ship - Draenei Hunter only: Moth during storm (quest 58208 complete)'),
(10639, 15400, 'NPE Alliance Ship - Worgen Hunter only: Dog (quest 58208 incomplete)'),
(10639, 15414, 'NPE Alliance Ship - Worgen Hunter only: Dog during storm (quest 58208 complete)'),
(10639, 15399, 'NPE Alliance Ship - Pandaren Hunter only: Turtle (quest 58208 incomplete)'),
(10639, 15413, 'NPE Alliance Ship - Pandaren Hunter only: Turtle during storm (quest 58208 complete)'),
(10639, 15286, 'NPE Alliance Ship - Gryphon Riders'),
(10639, 15284, 'NPE Alliance Ship - Helmsman Lenard'),
(10639, 14355, 'NPE Alliance Ship - Decoration NPCs initial (quest 58209 incomplete)'),
(10639, 13861, 'NPE Alliance Ship - Decoration NPCs during storm (quest 58209 complete)');

DELETE FROM `spell_area` WHERE `spell` IN (305420, 305422) AND `area` = 10639;
INSERT INTO `spell_area`(`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(305420, 10639, 56775, 58208, 0, 0, 2, 3, 2 | 64, 1), -- Medium Fog + Rain
(305422, 10639, 58208, 58208, 0, 0, 2, 3, 2, 2); -- Heavy Fog + Rain

-- Condition
DELETE FROM `conditions` WHERE `SourceEntry` = 10639 AND `SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (15404, 15418, 15403, 15417, 15405, 15419, 15402, 15416, 15401, 15415, 15400, 15414, 15399, 15413, 13753, 14355, 13861);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Dwarf
(26, 15404, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15404 if Player is Hunter'),
(26, 15404, 10639, 0, 0, 16, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15404 if Player is Dwarf'),
(26, 15404, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 15404 if Quest 58208 is NOT Complete'),
(26, 15418, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15418 if Player is Hunter'),
(26, 15418, 10639, 0, 0, 16, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15418 if Player is Dwarf'),
(26, 15418, 10639, 0, 0, 28, 0, 58208, 0, 0, 0, 0, 0, '', 'Allow Phase 15418 if Quest 58208 is complete'),
-- Nightelf
(26, 15403, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15403 if Player is Hunter'),
(26, 15403, 10639, 0, 0, 16, 0, 8, 0, 0, 0, 0, 0, '', 'Allow Phase 15403 if Player is Nightelf'),
(26, 15403, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 15403 if Quest 58208 is NOT Complete'),
(26, 15417, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15417 if Player is Hunter'),
(26, 15417, 10639, 0, 0, 16, 0, 8, 0, 0, 0, 0, 0, '', 'Allow Phase 15417 if Player is Nightelf'),
(26, 15417, 10639, 0, 0, 28, 0, 58208, 0, 0, 0, 0, 0, '', 'Allow Phase 15417 if Quest 58208 is complete'),
-- Human
(26, 15405, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15405 if Player is Hunter'),
(26, 15405, 10639, 0, 0, 16, 0, 1, 0, 0, 0, 0, 0, '', 'Allow Phase 15405 if Player is Human'),
(26, 15405, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 15405 if Quest 58208 is NOT Complete'),
(26, 15419, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15419 if Player is Hunter'),
(26, 15419, 10639, 0, 0, 16, 0, 1, 0, 0, 0, 0, 0, '', 'Allow Phase 15419 if Player is Human'),
(26, 15419, 10639, 0, 0, 28, 0, 58208, 0, 0, 0, 0, 0, '', 'Allow Phase 15419 if Quest 58208 is complete'),
-- Gnome
(26, 15402, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15402 if Player is Hunter'),
(26, 15402, 10639, 0, 0, 16, 0, 64, 0, 0, 0, 0, 0, '', 'Allow Phase 15402 if Player is Gnome'),
(26, 15402, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 15402 if Quest 58208 is NOT Complete'),
(26, 15416, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15416 if Player is Hunter'),
(26, 15416, 10639, 0, 0, 16, 0, 64, 0, 0, 0, 0, 0, '', 'Allow Phase 15416 if Player is Gnome'),
(26, 15416, 10639, 0, 0, 28, 0, 58208, 0, 0, 0, 0, 0, '', 'Allow Phase 15416 if Quest 58208 is complete'),
-- Draenei
(26, 15401, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15401 if Player is Hunter'),
(26, 15401, 10639, 0, 0, 16, 0, 1024, 0, 0, 0, 0, 0, '', 'Allow Phase 15401 if Player is Draenei'),
(26, 15401, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 15401 if Quest 58208 is NOT Complete'),
(26, 15415, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15415 if Player is Hunter'),
(26, 15415, 10639, 0, 0, 16, 0, 1024, 0, 0, 0, 0, 0, '', 'Allow Phase 15415 if Player is Draenei'),
(26, 15415, 10639, 0, 0, 28, 0, 58208, 0, 0, 0, 0, 0, '', 'Allow Phase 15415 if Quest 58208 is complete'),
-- Worgen
(26, 15400, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15400 if Player is Hunter'),
(26, 15400, 10639, 0, 0, 16, 0, 2097152, 0, 0, 0, 0, 0, '', 'Allow Phase 15400 if Player is Worgen'),
(26, 15400, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 15400 if Quest 58208 is NOT Complete'),
(26, 15414, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15414 if Player is Hunter'),
(26, 15414, 10639, 0, 0, 16, 0, 2097152, 0, 0, 0, 0, 0, '', 'Allow 15414 Phase if Player is Worgen'),
(26, 15414, 10639, 0, 0, 28, 0, 58208, 0, 0, 0, 0, 0, '', 'Allow Phase 15414 if Quest 58208 is complete'),
-- Pandaren
(26, 15399, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15399 if Player is Hunter'),
(26, 15399, 10639, 0, 0, 16, 0, 16777216, 0, 0, 0, 0, 0, '', 'Allow Phase 15399 if Player is Pandaren (A)'),
(26, 15399, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 15399 if Quest 58208 is NOT Complete'),
(26, 15413, 10639, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15413 if Player is Hunter'),
(26, 15413, 10639, 0, 0, 16, 0, 16777216, 0, 0, 0, 0, 0, '', 'Allow Phase 15413 if Player is Pandaren (A)'),
(26, 15413, 10639, 0, 0, 28, 0, 58208, 0, 0, 0, 0, 0, '', 'Allow Phase 15413 if Quest 58208 is complete'),
-- Private Cole fix
(26, 13753, 10639, 0, 0, 9, 0, 58209, 0, 0, 1, 0, 0, '', 'Allow Phase 13753 if Quest 58209 IS NOT taken'),
(26, 13753, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 13753 if Quest 58208 IS NOT complete'),
-- decoration npcs stage 1
(26, 14355, 10639, 0, 0, 28, 0, 58208, 0, 0, 1, 0, 0, '', 'Allow Phase 14355 if Quest 58208 is NOT Complete'),
-- decoration npcs stage 2
(26, 13861, 10639, 0, 0, 28, 0, 58208, 0, 0, 0, 0, 0, '', 'Allow Phase 13861 if Quest 58208 IS Complete');
