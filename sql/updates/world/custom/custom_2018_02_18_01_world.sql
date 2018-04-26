UPDATE `gameobject_template` SET `ScriptName`= 'go_deadmines_defias_cannon' WHERE `entry`= 16398;

DELETE FROM `creature_text` WHERE `CreatureID`= 45979 AND `GroupID`= 2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(45979, 2, 0, 'The cannon was rigged with an explosive trap!', 41, 0, 100, 0, 0, 0, 48790, 'General Purpose Bunny JMF to Player');
