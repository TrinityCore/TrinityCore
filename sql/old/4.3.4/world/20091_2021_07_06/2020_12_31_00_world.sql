DELETE FROM `areatrigger_scripts` WHERE `ScriptName`= 'at_halfus_wyrmbreaker_intro';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6437, 'at_halfus_wyrmbreaker_intro');

UPDATE `creature_template` SET `ScriptName`= 'npc_bot_chogall' WHERE `entry`= 46965;

DELETE FROM `creature_text` WHERE `CreatureID`= 46965;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(46965, 0, 0, 'Halfus! Hear me! (The Master calls, the Master wants.) Protect our secrets, Halfus. Destroy the intruders. (Murder for His glory. Murder for His hunger.)', 14, 0, 100, 0, 0, 22055, 47478, 'Cho\'gall'),
(46965, 1, 0, ' Flesh and sinew, weak but proud. Dare they part the Master\'s shroud? They stumble fumble groping blind. Finding fate and chaos intertwined.', 14, 0, 100, 0, 0, 22056, 47481, 'Cho\'gall'),
(46965, 2, 0, 'Brothers in chaos, the Twilight has come! (Shadows lengthen, endless night.) Deathwing has sundered this world. (Doors once opened never close.) So that its true Lords may return. (The Master comes, He comes He comes.)', 14, 0, 100, 0, 0, 22057, 47485, 'Cho\'gall'),
(46965, 3, 0, 'Brothers of the Hammer, to me! (Their will is still their own.) The unbelievers still stand. Destroy them! (Crush their bodies, crush their will.)', 14, 0, 100, 0, 0, 22060, 47497, 'Cho\'gall'),
(46965, 4, 0, 'Mortals, you merely separate the wheat from the chaff. (Unworthy, unworthy).', 14, 0, 100, 0, 0, 22062, 47488, 'Cho\'gall');

UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID`= 46965;
