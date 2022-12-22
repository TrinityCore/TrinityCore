 --
 --
 -- Silverpine Forest
 
SET @CGUID := 395673;

--
-- Ivar Patch

-- Detect: Quest Invis Zone 2
DELETE FROM `spell_area` WHERE `spell`=83739 AND `area`=239 AND `quest_start`=27045 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83739, 239, 27045, 0, 0, 0, 2, 3, 66, 0);

-- Abandoned Outhouse
UPDATE `gameobject_template` SET `ScriptName` = 'go_silverpine_abandoned_outhouse' WHERE `entry` = 205143;

DELETE FROM `gossip_menu` WHERE `MenuID`=11897 AND `TextID`=16689;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES 
(11897, 16689, 45338);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=11897 AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(11897, 0, 0, 'Yorick, you in there? I\'m ready to do this! Let\'s go!', 44940, 0, 0, 0, 0, 0, NULL, 0, 45338);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11897 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=1 AND `ConditionTarget`=0 AND `ConditionValue1`=83751 AND `ConditionValue2`=1 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 11897, 0, 0, 1, 1, 0, 83751, 1, 0, 1, 0, 0, '', 'Show gossip option if player doesn\'t have aura 83751');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11897 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=27045 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 11897, 0, 0, 1, 9, 0, 27045, 0, 0, 0, 0, 0, '', 'Show gossip option if player has taken quest 27045');

-- Deathstalker Rane Yorick
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_deathstalker_rane_yorick' WHERE `entry` = 44882;

DELETE FROM `creature_text` WHERE `CreatureID` = 44882;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44882, 0, 0, 'We haven\'t got much time. Crowly will be arriving shortly.', 12, 0, 100, 5, 0, 0,  44951, 5, ''),
(44882, 1, 0, 'THERE! Hide in the armoire! I\'ll hide in the shadow next to you.', 12, 0, 100, 25, 0, 0, 44955, 5, ''),
(44882, 2, 0, 'I live... and die... for the Banshee Queen.', 12, 0, 100, 0, 0, 0, 44971, 5, '');

DELETE FROM `waypoint_data` WHERE `id` = 448820;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448820, 1, 1300.27, 1190.11, 52.600067, NULL, 0, 0, 0, 0, 0),
(448820, 2, 1288.52, 1196.86, 52.850067, NULL, 0, 0, 0, 0, 0),
(448820, 3, 1287.52, 1205.11, 53.100067, NULL, 0, 0, 0, 0, 0),
(448820, 4, 1294.27, 1207.36, 54.100067, NULL, 0, 0, 0, 0, 0),
(448820, 5, 1299.27, 1207.86, 54.100067, NULL, 0, 0, 0, 0, 0),
(448820, 6, 1304.27, 1210.36, 54.100067, NULL, 0, 0, 0, 0, 0),
(448820, 7, 1304.77, 1217.86, 54.100067, NULL, 0, 0, 0, 0, 0),
(448820, 8, 1298.52, 1221.36, 54.100067, NULL, 0, 0, 0, 0, 0),
(448820, 9, 1298.27, 1218.86, 55.100067, NULL, 0, 0, 0, 0, 0),
(448820, 10, 1298.02, 1216.61, 56.350067, NULL, 0, 0, 0, 0, 0),
(448820, 11, 1297.27, 1212.86, 58.600067, NULL, 0, 0, 0, 0, 0),
(448820, 12, 1298.27, 1206.86, 58.600067, NULL, 0, 0, 0, 0, 0),
(448820, 13, 1307.27, 1206.11, 58.600067, NULL, 0, 0, 0, 0, 0),
(448820, 14, 1311.27, 1205.86, 58.600067, NULL, 0, 0, 0, 0, 0),
(448820, 15, 1312.67, 1208.86, 58.5123, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 448821;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448821, 1, 1313.435, 1210.425, 58.7561, NULL, 0, 0, 0, 0, 0),
(448821, 2, 1313.7, 1211.99, 58.4999, 4.564474, 0, 0, 0, 0, 0);

-- Armoire
UPDATE `creature_template` SET `unit_flags` = 33554440, `VehicleId` = 1055, `ScriptName` = 'npc_silverpine_armoire' WHERE `entry` = 44893;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83763 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44883 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 83763, 0, 1, 31, 0, 3, 44883, 0, 0, 0, 0, '', 'Armoire Camera - Target Lord Darius Crowley');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83764 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44884 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 83764, 0, 0, 31, 0, 3, 44884, 0, 0, 0, 0, '', 'Armoire Camera - Target Packleader Ivar Bloodfang');

-- Armoire
UPDATE `creature_template` SET `npcflag` = 16777216 WHERE `entry` = 44894;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 44894 AND `spell_id` = 83756;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(44894, 83756, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=44894 AND `SourceEntry`=83756 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=47 AND `ConditionTarget`=0 AND `ConditionValue1`=27045 AND `ConditionValue2`=8 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 44894, 83756, 0, 0, 47, 0, 27045, 8, 0, 0, 0, 0, '', 'Allow spellclick if quest 27045 is active');

-- Lord Darius Crowley
UPDATE `creature_template` SET `unit_flags` = 2, `unit_flags2` = 16384, `ScriptName` = 'npc_silverpine_lord_darius_crowley_exsanguinate' WHERE `entry` = 44883;

DELETE FROM `creature_text` WHERE `CreatureID` = 44883;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44883, 0, 0, 'Have you given any more thought to my proposal, Ivar?', 12, 0, 100, 6, 0, 0,  44957, 5, ''),
(44883, 1, 0, 'If we\'re to win this war we will need your help. Our packs must unite! The Forsaken will destroy us otherwise.', 12, 0, 100, 396, 0, 0, 44960, 5, ''),
(44883, 2, 0, 'You are the alpha male, Ivar. The rest of the ferals in Silverpine will do as you command.', 12, 0, 100, 397, 0, 0, 44961, 5, ''),
(44883, 3, 0, 'So will you help?', 12, 0, 100, 6, 0, 0, 44965, 5, '');

DELETE FROM `waypoint_data` WHERE `id` = 448830;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448830, 0, 1299.36, 1206.64, 58.5706, NULL, 0, 0, 0, 0, 0),
(448830, 1, 1300.36, 1206.64, 58.5706, NULL, 0, 0, 0, 0, 0),
(448830, 2, 1302.33, 1206.44, 58.499, NULL, 0, 0, 0, 0, 0),
(448830, 3, 1305.32, 1206.43, 58.5126, NULL, 0, 0, 0, 0, 0),
(448830, 4, 1313.48, 1206.09, 58.5119, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 448831;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448831, 0, 1310.28, 1206.0249, 58.76205, NULL, 0, 0, 0, 0, 0),
(448831, 1, 1305.58, 1206.46, 58.5122, NULL, 0, 0, 0, 0, 0);

 -- Packleader Ivar Bloodfang
UPDATE `creature_template` SET `unit_flags` = 2, `unit_flags2` = 16384, `VehicleId` = 1059, `ScriptName` = 'npc_silverpine_packleader_ivar_bloodfang_exsanguinate' WHERE `entry` = 44884;

DELETE FROM `creature_text` WHERE `CreatureID` = 44884;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44884, 0, 0, 'Why trust you now, Crowley? You abandoned us. Left us to die.', 12, 0, 100, 6, 0, 0, 44959, 5, ''),
(44884, 1, 0, 'I don\'t care about your war, Crowley.', 12, 0, 100, 274, 0, 0, 44962, 5, ''),
(44884, 2, 0, 'But...', 12, 0, 100, 1, 0, 0, 44963, 5, ''),
(44884, 3, 0, 'I have seen firsthand what the Forsaken are capable of doing. It is true. They hunt us... slaughter the defenseless.', 12, 0, 100, 1, 0, 0, 44964, 5, ''),
(44884, 4, 0, 'Aye, I will gather my pack... we...', 12, 0, 100, 1, 0, 0, 44966, 5, ''),
(44884, 5, 0, 'Packleader Ivar Bloodfang sniffs the air.', 16, 0, 100, 479, 0, 0, 44967, 5, ''),
(44884, 6, 0, 'It would appear that we are being watched, Crowley. You have grown soft... Likely Greymane\'s fault.', 12, 0, 100, 1, 0, 0, 44968, 5, ''),
(44884, 7, 0, 'Treacherous little pup!', 12, 0, 100, 15, 0, 0, 44969, 5, ''),
(44884, 8, 0, 'What say you now, spy?', 12, 0, 100, 0, 0, 0, 44970, 5, ''),
(44884, 9, 0, 'I was hoping you\'d say that...', 12, 0, 100, 0, 0, 0, 44972, 5, ''),
(44884, 10, 0, 'I will prepare the pack. It will take some time to gather them all, but we will join... for now.', 12, 0, 100, 1, 0, 0, 44973, 5, '');

DELETE FROM `spell_script_names` WHERE `spell_id` = 83781 AND `ScriptName` = 'spell_gen_reverse_cast_target_to_caster_triggered';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83781, 'spell_gen_reverse_cast_target_to_caster_triggered');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83781 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44882 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 83781, 0, 0, 31, 0, 3, 44882, 0, 0, 0, 0, '', 'Reverse Cast Ride Vehicle - Target Deathstalker Rane Yorick');

DELETE FROM `spell_script_names` WHERE `spell_id` = 80743 AND `ScriptName` = 'spell_gen_eject_passenger_1';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80743, 'spell_gen_eject_passenger_1');

DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry`=8420;
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES 
(8420, 1, 1311.91, 1207.39, 58.477764, 1.5707, 2);

DELETE FROM `waypoint_data` WHERE `id`= 448840;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448840, 0, 1296.2, 1210.54, 58.5533, NULL, 0, 0, 0, 0, 0),
(448840, 1, 1297.2, 1210.54, 58.5533, NULL, 0, 0, 0, 0, 0),
(448840, 2, 1302.31, 1206.61, 58.4984, NULL, 0, 0, 0, 0, 0),
(448840, 3, 1308.4, 1206.28, 58.5109, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id`= 448841;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448841, 0, 1312.585, 1209.135, 58.7603, NULL, 0, 0, 0, 0, 0),
(448841, 1, 1313.18, 1210.32, 58.5093, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id`= 448842;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448842, 0, 1311.25, 1208.875, 58.7602, NULL, 0, 0, 0, 0, 0),
(448842, 1, 1309.32, 1206.43, 58.5111, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id`= 448843;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448843, 0, 1304.2949, 1207.105, 58.760803, NULL, 0, 0, 0, 0, 0),
(448843, 1, 1299.0449, 1209.605, 58.760803, NULL, 0, 0, 0, 0, 0),
(448843, 2, 1297.27, 1212.28, 58.5105, NULL, 0, 0, 0, 0, 0);

-- Deathstalker Rane Yorick (44848)
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+0, 44899, 0, 130, 239, '0', 0, 169, 0, -1, 0, 1, 1295.52, 1206.65, 58.5013, 0.023232, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45338);

DELETE FROM `creature_template_addon` WHERE `entry`=44899;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(44899, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83738 29266');
