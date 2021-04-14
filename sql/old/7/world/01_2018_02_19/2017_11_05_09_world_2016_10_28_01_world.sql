--
DELETE FROM `creature_text` WHERE `CreatureID`=26649;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26649, 0, 0, "Pssst... Over here, by the mailbox. Come quickly and make sure you aren't followed.", 15, 0, 100, 0, 0, 0, 25823, 0, "Borus Ironbender");

DELETE FROM `areatrigger_scripts` WHERE `entry`=4960;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4960, "at_nearby_messenger_torvus");
