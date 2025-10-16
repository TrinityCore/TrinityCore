--
UPDATE `gameobject_template` SET `ScriptName` = 'go_drakkari_canopic_jar_chest' WHERE `entry` = 188499;

-- Texts expanded by the NPC speaking their text when they attack a player.
DELETE FROM `creature_text` WHERE `CreatureID` = 26811;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26811, 0, 0, 'I could sleep forever, mon....', 12, 0, 100, 0, 0, 0, 26149, 0, 'Ancient Drakkari Warmonger'),
(26811, 0, 1, 'Finally, I can be restin\'...', 12, 0, 100, 0, 0, 0, 26151, 0, 'Ancient Drakkari Warmonger'),
(26811, 0, 2, 'Free at last, mon.', 12, 0, 100, 0, 0, 0, 26148, 0, 'Ancient Drakkari Warmonger'),
(26811, 0, 3, 'Where\'s mah mummy?', 12, 0, 100, 0, 0, 0, 26150, 0, 'Ancient Drakkari Warmonger'),
(26811, 1, 0, 'Dat me liver you be squeezin, mon!', 12, 0, 100, 0, 0, 0, 26087, 0, 'Ancient Drakkari Warmonger'),
(26811, 1, 1, 'You take my heart, now I take yours!', 12, 0, 100, 0, 0, 0, 26085, 0, 'Ancient Drakkari Warmonger'),
(26811, 1, 2, 'Why ya wanna mess wit me innards, mon?', 12, 0, 100, 0, 0, 0, 26086, 0, 'Ancient Drakkari Warmonger');

DELETE FROM `creature_text` WHERE `CreatureID` = 26812;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26812, 0, 0, 'I could sleep forever, mon....', 12, 0, 100, 0, 0, 0, 26149, 0, 'Ancient Drakkari Soothsayer'),
(26812, 0, 1, 'Finally, I can be restin\'...', 12, 0, 100, 0, 0, 0, 26151, 0, 'Ancient Drakkari Soothsayer'),
(26812, 0, 2, 'Free at last, mon.', 12, 0, 100, 0, 0, 0, 26148, 0, 'Ancient Drakkari Soothsayer'),
(26812, 0, 3, 'Where\'s mah mummy?', 12, 0, 100, 0, 0, 0, 26150, 0, 'Ancient Drakkari Soothsayer'),
(26812, 1, 0, 'Dat me liver you be squeezin, mon!', 12, 0, 100, 0, 0, 0, 26087, 0, 'Ancient Drakkari Soothsayer // Ancient Drakkari Warmonger'),
(26812, 1, 1, 'You take my heart, now I take yours!', 12, 0, 100, 0, 0, 0, 26085, 0, 'Ancient Drakkari Soothsayer // Ancient Drakkari Warmonger'),
(26812, 1, 2, 'Why ya wanna mess wit me innards, mon?', 12, 0, 100, 0, 0, 0, 26086, 0, 'Ancient Drakkari Soothsayer // Ancient Drakkari Warmonger');
