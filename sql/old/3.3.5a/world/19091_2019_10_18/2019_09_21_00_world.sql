-- 
DELETE FROM `creature` WHERE `id`= 21925;
DELETE FROM `spawn_group` WHERE `spawnId`=85978 AND `spawnType`=0;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (21925);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21925) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21925, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Avatar of Sathal - On Just summoned - Say text'),
(21925, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Avatar of Sathal - On Just summoned - Start attack'),
(21925, 0, 2, 0, 0, 0, 100, 0, 2000, 3000, 5000, 8000, 11, 12471, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Avatar of Sathal - IC - Cast Shadow Bolt');

DELETE FROM `creature_text` WHERE `CreatureId` IN (21925);
INSERT INTO `creature_text` (`CreatureId`, `GroupId`, `ID`, `Text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(21925, 0, 0, "Feel my wrath, $r scum!  You will not get away with this!", 14, 0, 100, 0, 0, 0, 'Avatar of Sathal', 19598);
