-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=30714;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30714, 3071400) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30714, 0, 0, 0, 1, 0, 100, 0, 10000, 40000, 120000, 240000, 80, 3071400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Crusade Engineer Spitzpatrick - Out Of Combat - Run Script"),
(3071400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Crusade Engineer Spitzpatrick - On Script - Talk 0"),
(3071400, 9, 1, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 30686, 0, 0, 0, 0, 0, 0, "Crusade Engineer Spitzpatrick - On Script - Talk 0 (Crusade Architect Silas)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (30714, 30686);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(30714, 0, 0, "Dying must have completely destroyed your ability to perform simple arithmetic. Can't you see that there is no way you're going to make that structure's layout work? It'll collapse!", 12, 0, 100, 1, 0, 0, 31404, 0, "Crusade Engineer Spitzpatrick"),
(30686, 0, 0, "How dare you! I am the chief architect here and I make the final call on layouts! If you have a problem with my plans, feel free to file a grievance with Highlord Fordring. Now if you don't mind, I have work to attend!", 12, 0, 100, 1, 0, 0, 31406, 0, "Crusade Architect Silas");
