-- quest 29611 The Art of War
DELETE FROM `areatrigger_scripts` WHERE `entry` = 8463;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (8463, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 8463 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(8463, 2, 0, 0, 46, 0, 100, 0, 8463, 0, 0, 0, '', 85, 130409, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Areatrigger Art of War - Cast Kill Credit and Movie Spell');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 8463 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 8463, 2, 0, 9, 0, 29611, 0, 0, 0, 0, 0, '', 'Execute SAI only if The Art of War is incomplete');

-- remove quest start Nothing Left for You Here from Furien
DELETE FROM `creature_queststarter` WHERE `id` = 35286 AND `quest` = 26134;

-- add Generic Quest Invisibility Detection 1 for quest Warchief's Command: Desolace!
DELETE FROM `spell_area` WHERE `spell` = 49416 AND `area` = 2404;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `teamId`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES (49416, 2404, 28548, 14184, 0, -1, 0, 2, 3, 74, 64);

-- spawns High Road Scout for quest Clear the High Road
DELETE FROM `creature` WHERE `guid` IN (273514, 273515, 273516);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(273514, 37159, 1, 4709, 4985, 1, 0, 0, 0, -1, 30548, 0, -419.407, -1118.09, 152.512, 4.90635, 300, 3, 0, 2583, 0, 1, 0, 0, 0, 0, 0, '', 0),
(273515, 37159, 1, 4709, 4985, 1, 0, 0, 0, -1, 30548, 0, -567.878, -1310.87, 163.189, 3.64186, 300, 3, 0, 2583, 0, 1, 0, 0, 0, 0, 0, '', 0),
(273516, 37159, 1, 4709, 4985, 1, 0, 0, 0, -1, 30548, 0, -533.305, -1289.96, 156.906, 4.17593, 300, 3, 0, 2583, 0, 1, 0, 0, 0, 0, 0, '', 0);

-- fix flight path for quest To the Summit
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40358 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(40358, 0, 0, 1, 62, 0, 100, 0, 11372, 1, 0, 0, '', 52, 718, 0, 0, 0, 0, 0, 7, 0, 0, 0, -4464, -535, 7, 0, 'On Menu Click - Start Taxi'),
(40358, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 33, 39897, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Menu Click - Add Kill Credit');

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 40362 WHERE `MenuId` = 11372 AND `OptionIndex` = 1;

-- only show gossip option if quest is active
DELETE FROM`conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 11372 AND `SourceEntry` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (15, 11372, 1, 0, 0, 47, 0, 25478, 10, 0, 0, 0, 0, '', NULL);
