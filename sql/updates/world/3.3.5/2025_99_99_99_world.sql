UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_servant_of_drakuru' WHERE `entry` = 28802;

 -- Servant of Drakuru smart ai
SET @ENTRY := 28802;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;

-- Servant of Drakuru Text
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ENTRY, 0, 0, "Darmuk must die, mon!", 12, 0, 100, 0, 0, 0, 28884, 0, 'Servant of Drakuru - Say on Charm');