-- Goblin Assasins in Northshire
DELETE FROM `creature_text` WHERE `CreatureID` = 50039;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(50039, 0, 0, 'We\'ll kill anybody for the right price!', 12, 0, 100, 0, 0, 0, 0, 49837, 0, 'Goblin Assassin on Aggro'),
(50039, 0, 1, 'Time to join your friends, kissin\' the dirt!', 12, 0, 100, 0, 0, 0, 0, 49838, 0, 'Goblin Assassin on Aggro'),
(50039, 0, 2, 'DIE!!!', 12, 0, 100, 0, 0, 0, 0, 49839, 0, 'Goblin Assassin on Aggro');

-- Update chance as its higher on retail
UPDATE `smart_scripts` SET `event_chance`= 35 WHERE `entryorguid`= 50039 AND `event_type`= 4;
