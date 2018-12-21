-- Gilneas fixups
-- Make Northgate Rebel rooted
UPDATE `creature_template` SET `InhabitType`= 9 WHERE `entry`= 36057;

-- Reduce spawntime for Frightened Citizen
UPDATE `creature` SET `spawntimesecs`= 10 WHERE `guid`= 376345;

-- Add Pathing to Frightened Citizen
DELETE FROM `waypoints` WHERE `entry`= 3763450;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(3763450, 1, -1400.989, 1430.045, 35.71169),
(3763450, 2, -1403.989, 1423.545, 35.71169),
(3763450, 3, -1404.239, 1395.545, 35.71169),
(3763450, 4, -1406.989, 1376.545, 35.71169),
(3763450, 5, -1412.989, 1366.295, 35.71169),
(3763450, 6, -1446.989, 1358.545, 35.71169),
(3763450, 7, -1479.739, 1349.795, 35.71169),
(3763450, 8, -1512.489, 1341.295, 35.71169),
(3763450, 9, -1545.489, 1331.795, 35.71169),
(3763450, 10, -1578.739, 1317.045, 35.71169),
(3763450, 11, -1603.239, 1312.795, 18.71169),
(3763450, 12, -1627.739, 1308.795, 20.71169),
(3763450, 13, -1649.739, 1307.545, 20.21169),
(3763450, 14, -1682.239, 1306.045, 20.21169),
(3763450, 15, -1689.239, 1304.795, 20.21169),
(3763450, 16, -1692.365, 1297.531, 20.28411);

-- Creature Panicked Citizen 34851 SAI
SET @ENTRY := 34851;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;

SET @ENTRY := -376345;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Set active (are you sure?) // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 3763450, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Start path #3763450, run, do not repeat, Passive // ");

-- Kezan fixups
-- Correct movement types
UPDATE `creature` SET `MovementType`= 0, `spawndist`= 0 WHERE `guid` IN (251716, 251611, 251602, 251726, 251603);
-- Quest chaining
UPDATE `quest_template_addon` SET `PrevQuestID`= 14138, `ExclusiveGroup`= -14069 WHERE `ID` IN (14075, 14069);
-- Creature template addon corrections
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`= 34830;
