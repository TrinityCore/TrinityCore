-- Malefic Necromancer 31155
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31155;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31155;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31155, 0, 0, 0, 0,  0, 100, 0, 0, 3000, 30000, 45000, 11, 50324, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malefic Necromancer - IC - Cast Bone Armor'),
(31155, 0, 1, 0, 0,  0, 100, 0, 2000, 3000, 5000, 7000, 11, 34344, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Malefic Necromancer - IC - Cast Shadow Bolt');

-- Undying Minion 31152
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31152;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31152;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31152, 0, 0, 0, 0,  0, 100, 0, 0, 5000, 15000, 25000, 11, 60626, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Undying Minion - IC - Cast Necrotic Strike');

-- Citadel Watcher 31787
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31787;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31787;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31787, 0, 0, 0, 0,  0, 100, 0, 0, 5000, 5000, 7000, 11, 16564, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Citadel Watcher - IC - Cast Gargoyle Strike');

-- Cultist Shard Watcher <Cult of the Damned> 32349
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32349;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32349;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32349, 0, 0, 0, 0,  0, 100, 0, 0, 3000, 3000, 4000, 11, 39175, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cultist Shard Watcher - IC - Cast Shadow Bolt Volley'),
(32349, 0, 1, 0, 0,  0, 100, 0, 0, 1000, 17000, 18000, 11, 34441, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cultist Shard Watcher - IC - Cast Shadow Word: Pain'),
(32349, 0, 2, 0, 0,  0, 100, 0, 0, 1000, 13000, 14000, 11, 34439, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cultist Shard Watcher - IC - Cast Unstable Affliction');


-- Bitter Initiate <Cult of the Damned> 32238
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32238;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32238;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32238, 0, 0, 0, 0,  0, 100, 0, 0, 2000, 3000, 4000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bitter Initiate - IC - Cast Shadow Bolt'),
(32238, 0, 1, 0, 0,  0, 100, 0, 0, 0, 14000, 15000, 11, 32063, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bitter Initiate - IC - Cast Corruption');

-- Cult Blackguard <Cult of the Damned> 32276
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32276;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32276;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32276, 0, 0, 0, 0,  0, 100, 0, 0, 0, 45000, 45000, 11, 60842, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cult Blackguard - IC - Cast Expose Armor'),
(32276, 0, 1, 0, 0,  0, 100, 0, 0, 2000, 2000, 3000, 11, 14873, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cult Blackguard - IC - Cast Sinister Strike');

-- Cult Conspirator <Cult of the Damned> 33537
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=33537;

DELETE FROM `smart_scripts` WHERE `entryorguid` =33537;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(33537, 0, 0, 0, 0,  0, 100, 0, 0, 0, 45000, 45000, 11, 60842, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cult Conspirator - IC - Cast Expose Armor'),
(33537, 0, 1, 0, 0,  0, 100, 0, 0, 2000, 2000, 3000, 11, 14873, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cult Conspirator - IC - Cast Sinister Strike');

-- Cult Researcher <Cult of the Damned> 32297
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32297;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32297;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32297, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 4000, 5000, 11, 15587, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cult Researcher - IC - Cast Mind Blast'),
(32297, 0, 1, 0, 0,  0, 100, 0, 5000, 9000, 13000, 18000, 11, 62129, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cult Researcher - IC - Cast Wail of Souls');

-- Cult Taskmaster <Cult of the Damned> 32268
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32268;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32268;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32268, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 4000, 5000, 11, 16583, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cult Taskmaster - IC - Cast Shadow Shock'),
(32268, 0, 1, 0, 0,  0, 100, 0, 3000, 4000, 5000, 7000, 11, 3551, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cult Taskmaster - IC - Cast Skull Crack');

-- Cultist Corrupter <Cult of the Damned> 31738
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31738;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31738;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31738, 0, 0, 0, 0,  0, 100, 0, 0, 0, 60000, 60000, 11, 50324, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cultist Corrupter - IC - Cast Bone Armour (Self)'),
(31738, 0, 1, 0, 0,  0, 100, 0, 2000, 3000, 2000, 4000, 11, 50323, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cultist Corrupter - IC - Cast Sharpened Bone');

-- Shadow Channeler <Cult of the Damned> 32262
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32262;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32262;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32262, 0, 0, 0, 4,  0, 100, 0, 0, 0, 0, 0, 11, 13787, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Channeler - On Agro - Cast Demon Armour (Self)'),
(32262, 0, 1, 0, 0,  0, 100, 0, 0, 1000, 14000, 15000, 11, 11962, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow Channeler - IC - Cast Immolate'),
(32262, 0, 2, 0, 0,  0, 100, 0, 0, 1000, 3000, 4000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow Channeler - IC - Cast Shadow Bolt');

-- Shadow Cultist <Cult of the Damned> 29717
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=29717;

DELETE FROM `smart_scripts` WHERE `entryorguid` =29717;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29717, 0, 0, 0, 11,  0, 100, 0, 0, 0, 0, 0, 11, 16592, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist - On Spawn - Cast Shadowform (Self)'),
(29717, 0, 1, 0, 0,  0, 100, 0, 0, 1000, 3000, 4000, 11, 32000, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist - IC - Cast Mind Sear');

-- Void Summoner <Cult of the Damned> 32259

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32259;
DELETE FROM `smart_scripts` WHERE `entryorguid` =32259;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32259, 0, 0, 0, 0,  0, 100, 0, 0, 2000, 3000, 4000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Void Summoner - IC - Cast Shadowbolt');

-- Wyrm Reanimator <Cult of the Damned> 31731
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31731;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31731;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31731, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 15000, 15000, 11, 32063, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - IC - Cast Corruption'),
(31731, 0, 1, 0, 0,  0, 100, 0, 0, 1000, 3000, 4000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - IC - Cast Shadowbolt'),
(31731, 0, 2, 0, 0,  0, 100, 0, 0, 1000, 7000, 8000, 11, 11443, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - IC - Cast Cripple');

-- Deathspeaker Kharos <Cult of the Damned> 34808
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=34808;

DELETE FROM `smart_scripts` WHERE `entryorguid` =34808;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34808, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 3000, 4000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Deathspeaker Kharos - IC - Cast Shadow Bolt'),
(34808, 0, 1, 0, 0,  0, 100, 0, 0, 3000, 14000, 15000, 11, 11962, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Deathspeaker Kharos - IC - Cast Immolate'),
(34808, 0, 2, 0, 0,  0, 100, 0, 0, 3000, 15000, 15000, 11, 67005, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Deathspeaker Kharos - IC - Summon Shade');

-- Vile Torturer <Cult of the Damned> 32279
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32279;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32279;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32279, 0, 0, 0, 0,  0, 100, 0, 0, 0, 14000, 15000, 11, 14032, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile Torturer - IC - Cast Shadow Word: Pain'),
(32279, 0, 1, 0, 0,  0, 100, 0, 0, 3000, 5000, 8000, 11, 16427, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile Torturer - IC - Cast Virulent Poison');

-- Overseer Faedris <Cult of the Damned> 32250
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32250;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32250;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32250, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 2000, 3000, 11, 51797, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Faedris - IC - Cast Arcane Blast'),
(32250, 0, 1, 0, 2,  0, 100, 0, 1, 50, 5000, 6000, 11, 17173, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Faedris - On Less Than 50% HP - Cast Drain Life');

-- Overseer Jhaeqon <Cult of the Damned> 32285
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32285;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32285;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32285, 0, 0, 0, 0,  0, 100, 0, 0, 2000, 3000, 4000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Jhaeqon - IC - Cast Shadowbolt');

-- Overseer Savryn <Cult of the Damned> 32291
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32291;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32291;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32291, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 2000, 3000, 11, 60850, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Savryn - IC - Cast Mutilate'),
(32291, 0, 1, 0, 0,  0, 100, 0, 2000, 5000, 60000, 60000, 11, 60847, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Savryn - IC - Cast Slice and Dice (Self)');

-- Overseer Veraj <Cult of the Damned>
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32263;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32263;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32263, 0, 0, 0, 0,  0, 100, 0, 0, 3000, 3000, 4000, 11, 20825, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Veraj - IC - Cast Shadow Bolt'),
(32263, 0, 1, 0, 0,  0, 100, 0, 0, 1000, 14000, 15000, 11, 20787, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Veraj - IC - Cast Immolate'),
(32263, 0, 2, 0, 0,  0, 100, 0, 0, 0, 15000, 15000, 11, 11980, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Veraj - IC - Cast Curse of Weakness'),
(32263, 0, 3, 0, 11,  0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Veraj - On Spawn - Set Faction Hostile');

-- Cultist Acolyte 32507
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32507;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32507;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32507, 0, 0, 0, 4,  0, 100, 0, 0, 0, 0, 0, 11, 13864, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cultist Acolyte - On Agro - Cast Power Word: Fortitude (Self)'),
(32507, 0, 1, 0, 0,  0, 100, 0, 0, 500, 3000, 3500, 11, 16568, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cultist Acolyte - IC - Cast Mind Flay'),
(32507, 0, 2, 0, 2,  0, 100, 0, 1, 30, 3000, 5000, 11, 11642, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cultist Acolyte - Between 1 and 30% Hp - Cast Heal (Self)');

-- Vrykul Necrolord 31783
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31783;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31783;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31783, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 12000, 12000, 11, 50027, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vrykul Necrolord - IC - Cast Tug Soul'),
(31783, 0, 1, 0, 0,  0, 100, 0, 0, 1000, 3000, 4000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vrykul Necrolord - IC - Cast Shadow Bolt'),
(31783, 0, 2, 0, 0,  0, 100, 0, 0, 1000, 7000, 10000, 11, 32712, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vrykul Necrolord - IC - Cast Shadow Nova');

-- Frostbrood Whelp 31718
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31718;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31718;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31718, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 2500, 3000, 11, 60814, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Frostbrood Whelp - IC - Cast Corrosive Vial');

-- Ymirheim Defender 31746
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31746;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31746;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Throw Harpoon Does not work (31746, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 1500, 2500, 11, 59633, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ymirheim Defender - IC - Cast Throw Harpoon'),
(31746, 0, 0, 0, 0,  0, 100, 0, 2000, 5000, 14000, 15000, 11, 60988, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ymirheim Defender - IC - Cast Poisoned Spear');

-- Ymirheim Chosen Warrior 31258
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31258;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31258;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31258, 0, 0, 0, 0,  0, 100, 0, 0, 3000, 10000, 10000, 11, 35949, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ymirheim Chosen Warrior - IC - Cast Bloodthirst (Self)'),
(31258, 0, 1, 0, 0,  0, 100, 0, 0, 1000, 2000, 4000, 11, 15496, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ymirheim Chosen Warrior - IC - Cast Cleave'),
(31258, 0, 2, 0, 0,  0, 100, 0, 9000, 11000, 13000, 14000, 11, 61227, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ymirheim Chosen Warrior - IC - Cast Jump Attack'),
(31258, 0, 3, 0, 4,  0, 100, 0, 0, 0, 0, 0, 11, 61227, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ymirheim Chosen Warrior - On Agro - Cast Jump Attack');

-- Ymirjar Element Shaper 31267
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31267;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31267;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31267, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 6000, 8000, 11, 55216, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ymirjar Element Shaper - IC - Cast Avalanche'),
(31267, 0, 1, 0, 0,  0, 100, 0, 2000, 5000, 14000, 15000, 11, 61897, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ymirjar Element Shaper - IC - Cast Torn Earth');

-- Blight Falconer 31262
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31262;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31262;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31262, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 1000, 2000, 11, 50092, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blight Falconer - IC - Cast Shoot');

-- Scourge Converter 32257
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32257;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32257;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32257, 0, 0, 0, 0,  0, 100, 0, 5000, 7000, 9000, 11000, 11, 20828, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scourge Converter - IC - Cast Cone of Cold'),
(32257, 0, 1, 0, 0,  0, 100, 0, 3000, 5000, 7000, 9000, 11, 11831, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Converter - IC - Cast Frost Nova'),
(32257, 0, 2, 0, 0,  0, 100, 0, 0, 0, 3000, 4000, 11, 20822, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scourge Converter - IC - Cast Frostbolt');

-- Converted Hero 32255
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32255;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32255;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32255, 0, 0, 0, 0,  0, 100, 0, 0, 5000, 8000, 24000, 11, 61578, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Converted Hero - IC - Cast Incapacitating Shout (Self)'),
(32255, 0, 1, 0, 0,  0, 100, 0, 2000, 15000, 45000, 7000, 11, 19643, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Converted Hero - IC - Cast Mortal Strike');

-- Scourge Banner-Bearer 31900
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31900;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31900;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31900, 0, 0, 1, 11,  0, 100, 0, 0, 0, 0, 0, 11, 60023, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Banner-Bearer - On Spawn - Cast Scourge Banner Aura (Self)'),
(31900, 0, 1, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 59942, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Banner-Bearer - Linked with Previous Event - Cast Scourge Banner-Bearer (Self)'),
(31900, 0, 2, 0, 0,  0, 100, 0, 5000, 5000, 7000, 14000, 11, 16583, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scourge Banner-Bearer - IC - Shadow Shock'),
(31900, 0, 3, 0, 0,  0, 100, 0, 3000, 3000, 7000, 9000, 11, 32712, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scourge Banner-Bearer - IC - Cast Shadow Nova');

-- Skeletal Constructor 30687
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=30687;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30687;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30687, 0, 0, 0, 0,  0, 100, 0, 0, 0, 60000, 60000, 11, 50324, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Constructor - IC - Cast Bone Armour (Self)'),
(30687, 0, 1, 0, 0,  0, 100, 0, 2000, 3000, 3500, 7000, 11, 9613, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Constructor - IC - Cast Shadow Bolt');

-- Spiked Ghoul 30597
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=30597;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30597;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30597, 0, 0, 0, 0,  0, 100, 0, 0, 0, 5000, 9000, 11, 60876, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Spiked Ghoul - IC - Cast Jagged Spike'),
(30597, 0, 1, 0, 0,  0, 100, 0, 2000, 3000, 5000, 7000, 11, 54185, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Spiked Ghoul - IC - Cast Claw Slash');

-- Mjordin Water Magus 30632
-- Kirkhammet already commited the script I writ for these when he scripted the art of been a water terror but never deleted the static spawns of npcs which are summoned as minions
DELETE FROM `creature` WHERE `id`=30633;  -- Delete static spawns of Water Terror as these are meant to be summoned by Mjordin Water Magus not static spawns (summon works and these despawn when summoner killed)


-- Sentry Worg 30430
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=30430;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30430;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30430, 0, 0, 0, 0,  0, 100, 0, 2000, 3000, 20000, 20000, 11, 3604, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sentry Worg - IC - Cast Tendon Rip');

-- Glacial Bonelord 31754
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31754;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31754;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31754, 0, 0, 0, 0,  0, 100, 0, 3000, 5000, 3000, 7000, 11, 58460, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Glacial Bonelord - IC - Cast Brutal Strike'),
(31754, 0, 1, 0, 0,  0, 100, 0, 4000, 6000, 10000, 12000, 11, 51878, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glacial Bonelord - IC - Cast Ice Slash');

-- Skeletal Archmage 31779
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31779;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31779;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31779, 0, 0, 0, 4,  0, 100, 0, 0, 0, 0, 0, 11, 18100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Archmage - On Agro - Cast Frost Armor (Self)'),
(31779, 0, 1, 0, 0,  0, 100, 0, 0, 3000, 3000, 4000, 11, 15242, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Archmage - IC - Cast Fireball'),
(31779, 0, 2, 0, 0,  0, 100, 0, 3000, 5000, 8000, 12000, 11, 15244, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Archmage - IC - Cone of Cold'),
(31779, 0, 3, 0, 13,  0, 100, 0, 10000, 15000, 0, 0, 11, 15122, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Archmage - On Target Casting - Cast Counterspell');

-- Thexal Deathchill 31775
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31775;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31775;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31775, 0, 0, 0, 4,  0, 100, 0, 0, 0, 0, 0, 11, 18100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thexal Deathchill - On Agro - Cast Frost Armor (Self)'),
(31775, 0, 1, 0, 0,  0, 100, 0, 0, 3000, 3000, 5000, 11, 61747, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thexal Deathchill - IC - Cast Frostbolt'),
(31775, 0, 2, 0, 0,  0, 100, 0, 3000, 5000, 8000, 12000, 11, 18099, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thexal Deathchill - IC - Chill Nova'),
(31775, 0, 3, 0, 0,  0, 100, 0, 0, 0, 60000, 60000, 11, 59663, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thexal Deathchill - IC - Cast Deathchill Empowerment'),
(31775, 0, 4, 0, 0,  0, 100, 0, 5000, 10000, 10000, 20000, 11, 12096, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thexal Deathchill - IC - Cast Fear'),
(31775, 0, 5, 0, 9,  0, 100, 0, 0, 4, 6000, 9000, 11, 60924, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thexal Deathchill - On Range - Cast Lich Slap');

-- Pustulent Horror 31139
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31139;

DELETE FROM `smart_scripts` WHERE `entryorguid` =31139;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31139, 0, 0, 0, 0,  0, 100, 0, 3000, 5000, 3000, 7000, 11, 28405, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Pustulent Horror - IC - Cast Knock Back'),
(31139, 0, 1, 0, 0,  0, 100, 0, 4000, 6000, 5000, 9000, 11, 63546, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pustulent Horror - IC - Cast Stomp');

-- Skeletal Runesmith 30921
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=30921;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30921;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30921, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 45000, 45000, 11, 46202, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Runesmith - IC - Cast Pierce Armor');

-- Umbral Brute 30922
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=30922;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30922;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30922, 0, 0, 0, 0,  0, 100, 0, 0, 0, 60000, 60000, 11, 50420, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Umbral Brute - IC - Cast Enrage (Self)'),
(30922, 0, 1, 0, 0,  0, 100, 0, 3000, 5000, 7000, 9000, 11, 13446, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Umbral Brute - IC - Cast Strike'),
(30922, 0, 2, 0, 0,  0, 100, 0, 4000, 5000, 9000, 13000, 11, 34439, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Umbral Brute - IC - Cast Uppercut');

-- Lumbering Atrocity 30920
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=30920;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30920;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30920, 0, 0, 0, 0,  0, 100, 0, 0, 1000, 3000, 4000, 11, 40504, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - IC - Cast Cleave');
