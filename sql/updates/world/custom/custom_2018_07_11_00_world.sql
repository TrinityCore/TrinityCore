UPDATE `creature_template` SET `mechanic_immune_mask`= 617299839, `ScriptName`= 'npc_lct_augh' WHERE `entry`= 45377;

DELETE FROM `creature_text` WHERE `CreatureID`= 45377;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(45377, 0, 0, 'Bwaaaah! You no take da treasure!!!', 12, 0, 100, 0, 0, 0, 45529, 'Augh'),
(45377, 1, 0, 'Bwagauugh!!! Augh feed you to da crocs!!!', 12, 0, 100, 0, 0, 0, 45544, 'Augh');
