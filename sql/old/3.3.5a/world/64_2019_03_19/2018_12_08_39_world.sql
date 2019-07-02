DELETE FROM `creature_text` WHERE `creatureID` IN (24051, 23658, 23660, 23651, 24635);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24051,0,0,"Suffer, insect!",12,0,100,0,0,0,22701,0,"Dragonflayer Invader"),
(24051,0,1,"My life for Ymiron!",12,0,100,0,0,0,22702,0,"Dragonflayer Invader"),
(24051,0,2,"For Ymiron!",12,0,100,0,0,0,22697,0,"Dragonflayer Invader"),
(24051,0,3,"Beg for your life...",12,0,100,0,0,0,22698,0,"Dragonflayer Invader"),
(24051,0,4,"Your end draws closer!",12,0,100,0,0,0,22699,0,"Dragonflayer Invader"),
(24051,0,5,"YAAARRRGH!",12,0,100,0,0,0,22700,0,"Dragonflayer Invader"),
(23658,0,0,"Suffer, insect!",12,0,100,0,0,0,22701,0,"Dragonflayer Death Weaver"),
(23658,0,1,"My life for Ymiron!",12,0,100,0,0,0,22702,0,"Dragonflayer Death Weaver"),
(23658,0,2,"For Ymiron!",12,0,100,0,0,0,22697,0,"Dragonflayer Death Weaver"),
(23658,0,3,"Beg for your life...",12,0,100,0,0,0,22698,0,"Dragonflayer Death Weaver"),
(23658,0,4,"Your end draws closer!",12,0,100,0,0,0,22699,0,"Dragonflayer Death Weaver"),
(23658,0,5,"YAAARRRGH!",12,0,100,0,0,0,22700,0,"Dragonflayer Death Weaver"),
(23660,0,0,"Suffer, insect!",12,0,100,0,0,0,22701,0,"Dragonflayer Thane"),
(23660,0,1,"My life for Ymiron!",12,0,100,0,0,0,22702,0,"Dragonflayer Thane"),
(23660,0,2,"For Ymiron!",12,0,100,0,0,0,22697,0,"Dragonflayer Thane"),
(23660,0,3,"Beg for your life...",12,0,100,0,0,0,22698,0,"Dragonflayer Thane"),
(23660,0,4,"Your end draws closer!",12,0,100,0,0,0,22699,0,"Dragonflayer Thane"),
(23660,0,5,"YAAARRRGH!",12,0,100,0,0,0,22700,0,"Dragonflayer Thane"),
(23651,0,0,"Suffer, insect!",12,0,100,0,0,0,22701,0,"Dragonflayer Tribesman"),
(23651,0,1,"My life for Ymiron!",12,0,100,0,0,0,22702,0,"Dragonflayer Tribesman"),
(23651,0,2,"For Ymiron!",12,0,100,0,0,0,22697,0,"Dragonflayer Tribesman"),
(23651,0,3,"Beg for your life...",12,0,100,0,0,0,22698,0,"Dragonflayer Tribesman"),
(23651,0,4,"Your end draws closer!",12,0,100,0,0,0,22699,0,"Dragonflayer Tribesman"),
(23651,0,5,"YAAARRRGH!",12,0,100,0,0,0,22700,0,"Dragonflayer Tribesman"),
(24635,0,0,"Suffer, insect!",12,0,100,0,0,0,22701,0,"Dragonflayer Harpooner"),
(24635,0,1,"My life for Ymiron!",12,0,100,0,0,0,22702,0,"Dragonflayer Harpooner"),
(24635,0,2,"For Ymiron!",12,0,100,0,0,0,22697,0,"Dragonflayer Harpooner"),
(24635,0,3,"Beg for your life...",12,0,100,0,0,0,22698,0,"Dragonflayer Harpooner"),
(24635,0,4,"Your end draws closer!",12,0,100,0,0,0,22699,0,"Dragonflayer Harpooner"),
(24635,0,5,"YAAARRRGH!",12,0,100,0,0,0,22700,0,"Dragonflayer Harpooner");

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (23658, 23660, 23651, 24635);

-- Table smart_scripts Dragonflayer Death Weaver
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 23658);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23658, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 11, 43159, 0, 0, 0, 0, 0, 19, 24158, 30, 0, 0, 0, 0, 0, 'Dragonflayer Death Weaver - Out of Combat - Cast \'Soul Siphon\''),
(23658, 0, 1, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Death Weaver - On Aggro - Say Line 0'),
(23658, 0, 2, 0, 2, 0, 100, 0, 0, 30, 10000, 60000, 11, 43417, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Death Weaver - Between 0-30% Health - Cast \'Drain Life\''),
(23658, 0, 3, 0, 0, 0, 100, 0, 1000, 10000, 10000, 10000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Death Weaver - In Combat - Cast \'Shadow Bolt\'');

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24635;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 24635);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24635, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Harpooner - On Aggro - Say Line 0'),
(24635, 0, 1, 0, 0, 0, 100, 0, 1000, 20000, 15000, 15000, 11, 43325, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Harpooner - In Combat - Cast \'Oluf\'s Harpoon\''),
(24635, 0, 2, 0, 2, 0, 100, 0, 0, 50, 1000, 30000, 11, 48193, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Harpooner - Between 0-50% Health - Cast \'Enrage\'');

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24051;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 24051);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24051, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Invader - On Aggro - Say Line 0'),
(24051, 0, 1, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 58747, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Invader - On Aggro - Cast \'Intercept\''),
(24051, 0, 2, 0, 0, 0, 100, 0, 3000, 15000, 15000, 15000, 11, 42870, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Invader - In Combat - Cast \'Throw Dragonflayer Harpoon\'');

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23660;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 23660);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23660, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Thane - On Aggro - Say Line 0'),
(23660, 0, 1, 0, 0, 0, 100, 0, 10000, 20000, 10000, 10000, 11, 9080, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Thane - In Combat - Cast \'Hamstring\''),
(23660, 0, 2, 0, 0, 0, 100, 0, 1000, 30000, 25000, 25000, 11, 11971, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonflayer Thane - In Combat - Cast \'Sunder Armor\'');
