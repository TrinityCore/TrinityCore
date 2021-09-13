UPDATE `creature` SET `modelid`= 0 WHERE `id` IN (10424, 10419, 10418, 10420, 11043, 10422, 10425, 10426, 10421, 10423, 10997, 10544);
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry`= 10812;
UPDATE `creature` SET `Id`= 10813, `modelid`= 0 WHERE `guid`= 52149;

UPDATE `creature_template` SET `ScriptName`= 'boss_balnazzar' WHERE `entry`= 10813;

DELETE FROM `creature_text`  WHERE `CreatureID`= 10813;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(10813, 0, 0, 'You fools think you can defeat me so easily? Face the true might of the Nathrezim!', 14, 0, 100, 0, 0, 0, 6447, 'Balnazzar - Aggro'),
(10813, 1, 0, 'Damn you mortals! All my plans of revenge, all my hate...I will be avenged...', 12, 0, 100, 0, 0, 0, 6442, 'Balnazzar - Death');
