DELETE FROM `creature_text` WHERE `CreatureID`=166782 AND `GroupID`=0 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(166782, 0, 0, 'Thank the elements you survived.', 12, 0, 100, 3, 0, 297937, 0, 0, 'Trall to Player');

DELETE FROM `creature_text_locale` WHERE `CreatureID`=166782 AND `GroupID`=0 AND `ID`=0 AND `Locale`='ruRU';
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(166782, 0, 0, 'ruRU', 'Хвала стихиям, ты в порядке!');

DELETE FROM `creature_text` WHERE `CreatureID`=156626 AND `GroupID`=0 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(156626, 0, 0, '$n! The sea was kind to you today.', 12, 0, 100, 3, 0, 297962, 0, 0, 'Леди Джайна Праудмур to Player');

DELETE FROM `creature_text_locale` WHERE `CreatureID`=156626 AND `GroupID`=0 AND `ID`=0 AND `Locale`='ruRU';
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(156626, 0, 0, 'ruRU', 'Тебе повезло! Море тебя пощадило.');
