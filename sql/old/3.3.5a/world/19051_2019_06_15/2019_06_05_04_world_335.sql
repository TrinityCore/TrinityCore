UPDATE `creature_text` SET `TextRange`=3 WHERE `CreatureID`=14834 AND `GroupId` IN (2, 3);
DELETE FROM `creature_text` WHERE `CreatureID`=14834 AND `GroupId`=4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14834, 4, 0, "Your callous disregard for the sovereign might of the Gurubashi Empire has been noted. The inhabitants of Zul'Gurub have been alerted to your presence.", 16, 0, 100, 0, 0, 0, 10550, 3, "hakkar SAY_ENTRANCE");

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (3957, 3958, 3960);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(3957, 'at_zulgurub_entrance'),
(3958, 'at_zulgurub_entrance'),
(3960, 'at_zulgurub_entrance');
