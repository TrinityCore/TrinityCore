-- 
ALTER TABLE `creature_text` ADD `SoundPlayType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Sound`;
    
UPDATE `creature_text` SET `SoundPlayType`=1 WHERE `CreatureID`=130986;

DELETE FROM `creature_text` WHERE `CreatureID`=130986 AND ((`GroupID`=0 AND `ID` IN(1, 2)) OR (`GroupID`=2 AND `ID` IN(1, 2)) OR (`GroupID`=3 AND `ID`=1));
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(130986, 0, 1, 'Oh, you made it.', 12, 0, 100, 0, 0, 96040, 1, 146007, 5, 'Vigilant Quoram to Player'),
(130986, 0, 2, 'Wonderful.', 12, 0, 100, 0, 0, 96041, 1, 146008, 5, 'Vigilant Quoram to Player'),
(130986, 2, 1, 'I imagine it is quite painful.', 12, 0, 100, 0, 0, 96045, 1, 146012, 5, 'Vigilant Quoram to Player'),
(130986, 2, 2, 'It is designed to kill you.', 12, 0, 100, 0, 0, 96044, 1, 146011, 5, 'Vigilant Quoram to Player'),
(130986, 3, 1, 'Perhaps.', 12, 0, 100, 0, 0, 96048, 1, 146015, 5, 'Vigilant Quoram to Player'); -- BroadcastTextID: 133363 - 146015
