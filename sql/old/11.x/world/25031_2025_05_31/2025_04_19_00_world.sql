SET @CGUID := 7002288;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 144336, 1643, 8721, 9130, '0', 0, 0, 0, 0, -381.376739501953125, 1285.482666015625, 18.01809883117675781, 5.197472572326660156, 120, 0, 0, 0, 1, NULL, NULL, NULL, 60257); -- Fletcher's Hollow Villager (Area: Hangman's Point - Difficulty: 0) CreateObject1

-- Update creature
UPDATE `creature` SET `npcflag` = 1 WHERE `guid` IN (7002081, 7002082, 7002083, 7002080);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=144335 AND `MenuID`=21397) OR (`CreatureID`=144336 AND `MenuID`=21399) OR (`CreatureID`=144337 AND `MenuID`=21401) OR (`CreatureID`=144338 AND `MenuID`=21403) OR (`CreatureID`=144339 AND `MenuID`=21405);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(144335, 21397, 60257), -- Fletcher's Hollow Villager
(144336, 21399, 60257), -- Fletcher's Hollow Villager
(144337, 21401, 60257), -- Fletcher's Hollow Villager
(144338, 21403, 60257), -- Fletcher's Hollow Villager
(144339, 21405, 60257); -- Fletcher's Hollow Villager

UPDATE `gossip_menu` SET `VerifiedBuild`=60257 WHERE (`MenuID`=21395 AND `TextID`=32591) OR (`MenuID`=21396 AND `TextID`=32594) OR (`MenuID`=21397 AND `TextID`=32593) OR (`MenuID`=21398 AND `TextID`=32596) OR (`MenuID`=21399 AND `TextID`=32595) OR (`MenuID`=21400 AND `TextID`=32598) OR (`MenuID`=21401 AND `TextID`=32597) OR (`MenuID`=21402 AND `TextID`=32600) OR (`MenuID`=21403 AND `TextID`=32599) OR (`MenuID`=21404 AND `TextID`=32602) OR (`MenuID`=21405 AND `TextID`=32601);

UPDATE `gossip_menu_option` SET `GossipOptionID`=47699, `ActionMenuID`=21396, `VerifiedBuild`=60257 WHERE (`MenuID`=21397 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=47704, `ActionMenuID`=21404, `VerifiedBuild`=60257 WHERE (`MenuID`=21405 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=47700, `ActionMenuID`=21398, `VerifiedBuild`=60257 WHERE (`MenuID`=21399 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=47703, `ActionMenuID`=21402, `VerifiedBuild`=60257 WHERE (`MenuID`=21403 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=47701, `ActionMenuID`=21400, `VerifiedBuild`=60257 WHERE (`MenuID`=21401 AND `OptionID`=0);

-- Gossip Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14) AND (`SourceGroup` IN (21397,21399,21401,21403,21405));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(14, 21397, 0, 0, 0, 47, 0, 48111, 10, 0, '', 0, 'Player for which gossip text is shown has Trial by Superstition (48111) in state complete, incomplete'),
(14, 21399, 0, 0, 0, 47, 0, 48111, 10, 0, '', 0, 'Player for which gossip text is shown has Trial by Superstition (48111) in state complete, incomplete'),
(14, 21401, 0, 0, 0, 47, 0, 48111, 10, 0, '', 0, 'Player for which gossip text is shown has Trial by Superstition (48111) in state complete, incomplete'),
(14, 21403, 0, 0, 0, 47, 0, 48111, 10, 0, '', 0, 'Player for which gossip text is shown has Trial by Superstition (48111) in state complete, incomplete'),
(14, 21405, 0, 0, 0, 47, 0, 48111, 10, 0, '', 0, 'Player for which gossip text is shown has Trial by Superstition (48111) in state complete, incomplete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (21405,21403,21401,21399,21397));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 21405, 0, 0, 0, 48, 0, 291957, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 291957 < 1 or has rewarded the quest'),
(15, 21403, 0, 0, 0, 48, 0, 291956, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 291956 < 1 or has rewarded the quest'),
(15, 21401, 0, 0, 0, 48, 0, 291955, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 291955 < 1 or has rewarded the quest'),
(15, 21399, 0, 0, 0, 48, 0, 291954, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 291954 < 1 or has rewarded the quest'),
(15, 21397, 0, 0, 0, 48, 0, 291953, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 291953 < 1 or has rewarded the quest');

-- Fletcher's Hollow Villager smart ai
SET @ENTRY := 144339;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 21405, 0, 0, 0, 0, 85, 250109, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21405 selected - Gossip player: Cast spell 250109 on self', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 250110, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21405 selected - Gossip player: Cast spell 250110 on self', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21405 selected - Gossip player: Close gossip', '');

-- Fletcher's Hollow Villager smart ai
SET @ENTRY := 144338;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 21403, 0, 0, 0, 0, 85, 250108, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21403 selected - Gossip player: Cast spell 250108 on self', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 250110, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21403 selected - Gossip player: Cast spell 250110 on self', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21403 selected - Gossip player: Close gossip', '');

-- Fletcher's Hollow Villager smart ai
SET @ENTRY := 144337;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 21401, 0, 0, 0, 0, 85, 250107, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21401 selected - Gossip player: Cast spell 250107 on self', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 250110, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21401 selected - Gossip player: Cast spell 250110 on self', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21401 selected - Gossip player: Close gossip', '');

-- Fletcher's Hollow Villager smart ai
SET @ENTRY := 144336;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 21399, 0, 0, 0, 0, 85, 250106, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21399 selected - Gossip player: Cast spell 250106 on self', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 250110, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21399 selected - Gossip player: Cast spell 250110 on self', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21399 selected - Gossip player: Close gossip', '');

-- Fletcher's Hollow Villager smart ai
SET @ENTRY := 144335;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 21397, 0, 0, 0, 0, 85, 250105, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21397 selected - Gossip player: Cast spell 250105 on self', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 250110, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21397 selected - Gossip player: Cast spell 250110 on self', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21397 selected - Gossip player: Close gossip', '');
