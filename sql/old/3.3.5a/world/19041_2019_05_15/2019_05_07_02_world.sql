-- 
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (23888,24038);
DELETE FROM `smart_scripts`   WHERE `entryorguid` IN (23749) AND `source_type`=0 AND `id` IN (2,3,4);
DELETE FROM `smart_scripts`   WHERE `entryorguid` IN (23888,24038) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23749, 0, 2, 3, 20, 0, 100, 0, 11250, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Mage-Captain Adams - On quest rewarded - Store target"),
(23749, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24038, 0, 0, 0, 0, 0, 0, "Mage-Captain Adams - On quest rewarded - Send target"),
(23749, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24038, 0, 0, 0, 0, 0, 0, "Mage-Captain Adams - On quest rewarded - Set data"),
(24038, 0, 0, 0, 38, 0, 100, 0, 1, 1, 1000, 1000, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Father Levariol - On data set - Say text"),
(24038, 0, 1, 2, 20, 0, 100, 0, 11231, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Father Levariol - On quest rewarded - Store target"),
(24038, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 23888, 0, 0, 0, 0, 0, 0, "Father Levariol - On quest rewarded - Send target"),
(24038, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 23888, 0, 0, 0, 0, 0, 0, "Father Levariol - On quest rewarded - Set data"),
(23888, 0, 0, 0, 38, 0, 100, 0, 1, 1, 1000, 1000, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Mage-Lieutenant Malister - On data set - Say text");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23888,24038);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23888,0,0,"$n, I would have words with you.",15,0,100,0,0,0,23634,0,"Mage-Lieutenant Malister"),
(24038,0,0,"$n my child, come here, I have something to ask of you.",15,0,100,0,0,0,22685,0,"Father Levariol");
