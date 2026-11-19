UPDATE `smart_scripts` SET `event_type`=75, `event_param1`=0, `event_param2`=16878, `event_param3`=4000, `event_param4`=4000, `action_param2`=1, `target_type`=1, `target_param1`=0, `target_param2`=0, `comment`='Anchorite Relic Bunny - On Shattered Hand Berserker in range  - Cast \'Anchorite Contrition\' (No Repeat)' WHERE  `entryorguid`=22444 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `gameobject_template` SET `AIName`='' WHERE  `entry`=185298;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(22454);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(22454) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=185298 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22454, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, 'Fel Spirit - On Just Summoned - Attack'),
(22454, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fel Spirit - On Agro - Attack');

DELETE FROM `creature_text` WHERE `entry`=22454;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(22454, 0, 0, 'Vengeance will not be yours, $n!', 12, 0, 100, 15, 0, 0, 20301, 'Fel Spirit to Player');

UPDATE `gameobject_template` SET `flags` = 16 WHERE `entry` = 185298;
