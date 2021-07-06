DELETE FROM `spell_area` WHERE `spell` IN (92285, 92293, 92287, 92289, 92291, 92263);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(92285, 4926, 28735, 28737, 0, 0, 2, 3, 64, 1), -- See Question Mark at Corla
(92287, 4926, 28737, 28738, 0, 0, 2, 3, 64, 1), -- See Question Mark at Karsh
(92289, 4926, 28738, 28740, 0, 0, 2, 3, 64, 1), -- See Question Mark at Beauty
(92291, 4926, 28738, 28741, 0, 0, 2, 3, 64, 1), -- See Question Mark at Obsidius
(92263, 4926, 28735, 28741, 0, 0, 2, 3, 2 | 8 | 64, 1 | 2 | 8), -- Helm Visual
(92293, 4926, 0, 0, 0, 0, 2, 3, 0, 0); -- See Finkle Einhorn at the Entrance

DELETE FROM `areatrigger_scripts` WHERE `ScriptName` IN 
('at_brc_corla_quest',
 'at_brc_karsh_quest',
 'at_brc_beauty_quest',
 'at_brc_obsidius_quest');
 
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6593, 'at_brc_corla_quest'),
(6594, 'at_brc_karsh_quest'),
(6597, 'at_brc_beauty_quest'),
(6601, 'at_brc_obsidius_quest');

SET @CGUID := 396569;
DELETE FROM `creature` WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 49476, 645, 4926, 0, 1, 169, 0, 0, 0, 292.60275, 557.54285, 67.62, 0.014667154, 7200, 0, 0, 92853, 0, 0, 0, 0, 0, 15595);

DELETE FROM `creature_text` WHERE `CreatureID`= 49476;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(49476, 0, 0, 'RAZ, NOOOOOOOOOOO!!!!', 14, 0, 100, 0, 0, 18902, 49597, 'Finkle Einhorn');

-- Creature Finkle Einhorn 49476 SAI
SET @ENTRY := 49476;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -@CGUID;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4947600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4947600 // ");

-- TimedActionList 4947600 SAI
SET @ENTRY := 4947600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 305.7049, 557.6805, 66.17286, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Move to position (305.7049, 557.6805, 66.17286, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Talk 0 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 3500 min and 3500 max ms (repeat 0 min 0 max ms) - Self: Play emote 18 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 3600, 3600, 0, 0, 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 3600 min and 3600 max ms (repeat 0 min 0 max ms) - Self: Set UNIT_FIELD_BYTES_1 to 1 // ");

DELETE FROM `spawn_group_template` WHERE `groupId`= 452;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(452, 'Blackrock Caverns - Finkle Einhorn', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 452;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(452, 0, @CGUID);

DELETE FROM `instance_spawn_groups` WHERE `instanceMapId`= 645 AND `spawnGroupId`= 452;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(645, 4, 8, 452, 1);
