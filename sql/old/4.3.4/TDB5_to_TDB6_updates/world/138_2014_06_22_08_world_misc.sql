SET @GUID := 68282; -- Needs 3

-- Add Ahn'kahar Watcher's Corpse to heroic loot for Ahn'kahar Watcher
DELETE FROM `creature_loot_template` WHERE `entry`=31449 AND `item`=43494;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(31449, 43494, 100, 1, 0, 1, 1); -- Ahn'kahar Watcher's Corpse 

-- Condition to ensure item only drops if player on quest since we cant use negative chance here since item is not requirement to complete quest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=31449 AND `SourceEntry`=43494;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(1, 31449, 43494, 0, 1, 9, 0, 13190, 0, 0, 0, 0, 0, '', 'Ahn kahar Watchers Corpse drops if player has taken (13190) All Things in Good Time');

-- Add Ahn'kahet Brazier KC Bunny and Ahn'Kahar Watchers
DELETE FROM `creature` WHERE `guid`  BETWEEN @GUID AND @GUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID, 31105, 619, 3, 173, 520.7055, -352.9016, 47.92243, 2.234021, 7200, 0, 0), -- 31105 (Area: 4627)
(@GUID+1, 31104, 619, 3, 1, 454.1534, -1024.992, 30.43521, 5.218534, 7200, 5, 1), -- 31104 (Area: 4623) (possible waypoints or random movement)
(@GUID+2, 31104, 619, 3, 1, 460.0319, -1034.93, 30.33384, 1.972222, 7200, 5, 1); -- 31104 (Area: 4623) (possible waypoints or random movement)

UPDATE `creature_template` SET `flags_extra`=130 WHERE  `entry`=31105;
DELETE FROM `creature_template_addon` WHERE `entry` =31104;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(31104, 0, 0x0, 0x1, '18950'); -- 31104 - 18950

-- Condition for spellhit 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(58515);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 58515, 0, 0, 31, 0, 3, 31105, 0, 0, 0, 0, '', 'Burn Corpse hits Ahn kahet Brazier KC Bunny');

-- Script for Ahn'kahet Brazier KC Bunny
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` =31105;
DELETE FROM `smart_scripts` WHERE `entryorguid` =31105 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31105,0,0,1,8,0,100,4,58515,0,0,0,11,58518,2,0,0,0,0,16,0,0,0,0,0,0,0,'Ahn kahet Brazier KC Bunny - On Spell Hit (Burn Corpse) - Give Quest Credit (Heroic Only)'),
(31105,0,1,0,61,0,100,4,0,0,0,0,11,58522,2,0,0,0,0,1,0,0,0,0,0,0,0,'Ahn kahet Brazier KC Bunny - Linked with Previous Event - Cast Ahn kahet Brazier Effect');

-- Script for Ahn'Kahar Watcher 
DELETE FROM `smart_scripts` WHERE `entryorguid`=31104 AND `source_type`=0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry =31104;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31104, 0, 0, 0, 9, 0, 100, 0, 0, 5, 14000, 17000, 11, 42746, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ahn kahar Watcher - In Combat - Cast Cleave'),
(31104, 0, 1, 0, 0, 0, 100, 0, 9000, 12000, 15000, 18000, 11, 56643, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahn kahar Watcher - In Combat - Cast Triple Slash'),
(31104, 0, 2, 0, 2, 0, 100, 0, 0, 30, 8000, 10000, 11, 56646, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahn kahar Watcher - Between 0-30% Health - Cast Enrage');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`IN(58515,58518);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 58515, 64, '', '', 'Ignore LOS on Burn Corpse'),
(0, 58518, 64, '', '', 'Ignore LOS on Ahn kahet Brazier Kill Credit');
