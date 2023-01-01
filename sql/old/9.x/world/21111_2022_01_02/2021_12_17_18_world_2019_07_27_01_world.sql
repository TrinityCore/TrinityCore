-- 

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (22465);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22465) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22465, 0, 0, 0, 1, 0, 100, 0, 60000, 120000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Natasha - OOC - Say text');

DELETE FROM `creature_text` WHERE `CreatureId` IN (22465);
INSERT INTO `creature_text` (`CreatureId`, `GroupId`, `ID`, `Text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(22465, 0, 0, "I'm only 4 years old.", 12, 0, 100, 0, 0, 0, 'Natasha', 20353),
(22465, 0, 1, "Have you seen my mommy and daddy?", 12, 0, 100, 0, 0, 0, 'Natasha', 20355),
(22465, 0, 2, "Antelarion, is it safe to play in the forest yet?", 12, 0, 100, 6, 0, 0, 'Natasha', 20357),
(22465, 0, 3, "I think I came from Eng-land, do you know where that is?", 12, 0, 100, 5, 0, 0, 'Natasha', 20358),
(22465, 0, 4, "Antelarion says I fell off a big bird, as I fell he caught me... He is so pretty!", 12, 0, 100, 0, 0, 0, 'Natasha', 20360);
