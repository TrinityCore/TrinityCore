UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` IN (1660,1665,13158,39097,66185);

DELETE FROM `smart_scripts` WHERE `entryorguid`=1660;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1660, 0, 0, 0, 4, 0, 30, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Bodyguard - On Aggro - Say Text'),
(1660, 0, 1, 0, 0, 0, 100, 0, 1000, 7000, 8000, 28000, '', 11, 12169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Bodyguard - Cast Shield Block'),
(1660, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Bodyguard - Say Text at 15% HP'),
(1660, 0, 3, 0, 75, 0, 100, 1, 0, 66185, 30, 0, '', 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Bodyguard - On creature distance - Set React Passive'),
(1660, 0, 4, 0, 75, 0, 100, 1, 0, 66185, 30, 0, '', 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Bodyguard - On creature distance - Set Immune to PC');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1665;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1665, 0, 0, 0, 1, 0, 100, 0, 500, 1000, 240000, 240000, '', 11, 8258, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Melrache - Cast Devotion Aura on Spawn'),
(1665, 0, 1, 0, 9, 0, 100, 0, 0, 5, 11000, 13000, '', 11, 11976, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Captain Melrache - Cast Strike on Close'),
(1665, 0, 2, 0, 75, 0, 100, 1, 0, 66185, 30, 0, '', 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Melrache - On creature distance - Set React Passive'),
(1665, 0, 3, 0, 75, 0, 100, 1, 0, 66185, 30, 0, '', 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Melrache - On creature distance - Set Immune to PC');

DELETE FROM `smart_scripts` WHERE `entryorguid`=13158;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(13158, 0, 0, 0, 19, 0, 100, 0, 25046, 0, 0, 0, '', 85, 73306, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lieutenant Sanders - On Quest 25046 Accept - Cast Lilian Voss (Guardian)');

DELETE FROM `smart_scripts` WHERE `entryorguid`=39097;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(39097, 0, 0, 0, 75, 0, 100, 1, 0, 66185, 30, 0, '', 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Priest Benedictus Voss - On creature distance - Set React Passive'),
(39097, 0, 1, 0, 75, 0, 100, 1, 0, 66185, 30, 0, '', 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Priest Benedictus Voss - On creature distance - Set Immune to PC');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (66185,6618500);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(66185, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, '', 11, 73305, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - On Spawn - Cast Shadowy Aura - Uber'),
(66185, 0, 1, 0, 0, 0, 100, 0, 0, 0, 4000, 4000, '', 11, 32711, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Cast Shadow Nova'),
(66185, 0, 2, 0, 0, 0, 100, 0, 0, 0, 5000, 5000, '', 11, 73309, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Cast Lilian\'s Death Grip'),
(66185, 0, 3, 0, 75, 0, 100, 1, 0, 39097, 20, 0, '', 80, 6618500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - On creature distance - Action list'),
(6618500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.61, -563.24, 126.718, 0.647956, 'Vengeful Forsaken (Lilian Voss) - Go to position'),
(6618500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Talk1'),
(6618500, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 19, 39097, 20, 0, 0, 0, 0, 0, 'High Priest Benedictus Voss - Talk1'),
(6618500, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Talk2'),
(6618500, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 11, 73308, 2, 0, 0, 0, 0, 19, 1660, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Cast Lilian\'s Shadow Hop'),
(6618500, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 11, 32711, 2, 0, 0, 0, 0, 19, 1660, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Cast Shadow Nova'),
(6618500, 9, 6, 0, 0, 0, 100, 0, 500, 500, 0, 0, '', 51, 0, 0, 0, 0, 0, 0, 19, 1660, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Kill Scarlet Bodyguard'),
(6618500, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 11, 73308, 2, 0, 0, 0, 0, 19, 1665, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Cast Lilian\'s Shadow Hop'),
(6618500, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 11, 32711, 2, 0, 0, 0, 0, 19, 1665, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Cast Shadow Nova'),
(6618500, 9, 9, 0, 0, 0, 100, 0, 500, 500, 0, 0, '', 51, 0, 0, 0, 0, 0, 0, 19, 1665, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Kill Captain Melrache'),
(6618500, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.61, -563.24, 126.718, 0.647956, 'Vengeful Forsaken (Lilian Voss) - Go to position'),
(6618500, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.61, -563.24, 126.718, 0.647956, 'Vengeful Forsaken (Lilian Voss) - SetOrientation'),
(6618500, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Talk3'),
(6618500, 9, 13, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 19, 39097, 20, 0, 0, 0, 0, 0, 'High Priest Benedictus Voss - Talk2'),
(6618500, 9, 14, 0, 0, 0, 100, 0, 3000, 5000, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Talk4'),
(6618500, 9, 15, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Talk5'),
(6618500, 9, 16, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 19, 39097, 20, 0, 0, 0, 0, 0, 'High Priest Benedictus Voss - Talk3'),
(6618500, 9, 17, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 11, 73308, 2, 0, 0, 0, 0, 19, 39097, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Cast Lilian\'s Shadow Hop'),
(6618500, 9, 18, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 11, 32711, 2, 0, 0, 0, 0, 19, 39097, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Cast Shadow Nova'),
(6618500, 9, 19, 0, 0, 0, 100, 0, 500, 500, 0, 0, '', 51, 0, 0, 0, 0, 0, 0, 19, 39097, 20, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Kill High Priest Benedictus Voss'),
(6618500, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 33, 39098, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Credit quest'),
(6618500, 9, 21, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, '', 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Talk6'),
(6618500, 9, 22, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vengeful Forsaken (Lilian Voss) - Despawn');

DELETE FROM `creature_text` WHERE `CreatureID`=66185;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(66185, 0, 0, 'Father!', 12, 0, 100, 0, 0, 0, 39138, 0, 'Vengeful Forsaken (Lilian Voss)'),
(66185, 1, 0, 'Shut up.', 12, 0, 100, 0, 0, 0, 39140, 0, 'Vengeful Forsaken (Lilian Voss)'),
(66185, 2, 0, 'You raised me to be a killer.  How am I doing, daddy?', 12, 0, 100, 0, 0, 0, 39141, 0, 'Vengeful Forsaken (Lilian Voss)'),
(66185, 3, 0, 'But wait... I remember now. You taught me to only kill the undead. So you do want me to kill myself, daddy?', 12, 0, 100, 0, 0, 0, 39143, 0, 'Vengeful Forsaken (Lilian Voss)'),
(66185, 4, 0, 'Then again, why kill myself... when I can kill YOU instead!', 12, 0, 100, 0, 0, 0, 39145, 0, 'Vengeful Forsaken (Lilian Voss)'),
(66185, 5, 0, 'Thanks for everything... father.', 12, 0, 100, 0, 0, 0, 39146, 0, 'Vengeful Forsaken (Lilian Voss)');

DELETE FROM `creature_text` WHERE `CreatureID`=39097;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(39097, 0, 0, 'Lilian... you\'re... it\'s so nice to see you well.', 12, 0, 100, 0, 0, 0, 39139, 0, 'High Priest Benedictus Voss'),
(39097, 1, 0, 'I, ah...', 12, 0, 100, 0, 0, 0, 39142, 0, 'High Priest Benedictus Voss'),
(39097, 2, 0, 'Lilian, I...', 12, 0, 100, 0, 0, 0, 39144, 0, 'High Priest Benedictus Voss');

