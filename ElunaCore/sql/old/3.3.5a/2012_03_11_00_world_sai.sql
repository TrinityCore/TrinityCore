-- Coilfang Guardian

DELETE FROM `smart_scripts` WHERE `entryorguid`=21873 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21873, 0, 0, 0, 0, 0, 0, 0, 5000, 5000, 15000, 15000, 11, 28168, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilfang Guardian - IC - Cast Arcing Smash'),
(21873, 0, 1, 0, 0, 0, 0, 0, 2000, 2000, 10000, 10000, 11, 9080, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilfang Guardian - IC - Cast Harmstring'),
(21873, 0, 2, 0, 0, 0, 50, 0, 3000, 4000, 10000, 20000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Coilfang Guardian - IC - Say 0'); -- randomly guessed timers

DELETE FROM `creature_text` WHERE `entry`=21873;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(21873, 0, 0, 'By Nazjatar''s Depths!', 12, 0, 0, 0, 0, 0, 'Coilfang Guardian'),
(21873, 0, 1, 'Die, warmblood!', 12, 0, 0, 0, 0, 0, 'Coilfang Guardian'),
(21873, 0, 2, 'For the Master!', 12, 0, 0, 0, 0, 0, 'Coilfang Guardian'),
(21873, 0, 3, 'Illidan reigns!', 12, 0, 0, 0, 0, 0, 'Coilfang Guardian'),
(21873, 0, 4, 'My blood is like venom!', 12, 0, 0, 0, 0, 0, 'Coilfang Guardian');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=21873;

-- Coilfang Strider

DELETE FROM `smart_scripts` WHERE `entryorguid`=22056 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22056, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 11, 38257, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Coilfang Strider - On Reset - Cast Panic Periodic'),
(22056, 0, 1, 0, 0, 0, 0, 0, 8000, 8000, 30000, 40000, 11, 38259, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilfang Strider - IC - Cast Mind Blast');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=22056;

-- Coilfang Elite

DELETE FROM `smart_scripts` WHERE `entryorguid`=22055 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22055, 0, 0, 0, 0, 0, 0, 0, 5000, 5000, 15000, 20000, 11, 38260, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Coilfang Elite - IC - Cast Cleave'),
(22055, 0, 1, 0, 0, 0, 0, 0, 2000, 2000, 10000, 10000, 11, 38262, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilfang Elite - IC - Cast Harmstring');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=22055;

-- Core Hound

DELETE FROM `smart_scripts` WHERE `entryorguid`=11673 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 11673*100+0 AND 11673*100+5 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11673, 0, 0, 0, 0, 0, 0, 0, 10000, 10000, 7000, 7000, 11, 19272, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - IC - Cast Lava Breath'),
(11673, 0, 1, 0, 0, 0, 0, 0, 4000, 4000, 6000, 6000, 11, 19319, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - IC - Cast Vicious Bite'),
(11673, 0, 2, 0, 0, 0, 0, 0, 15000, 15000, 24000, 24000, 88, 11673*100+0, 11673*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - IC - Call random script'),
(11673*100+0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 19364, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - Random 0 - Cast Ground Stomp'),
(11673*100+1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 19366, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - Random 1 - Cast Cauterizing Flames'),
(11673*100+2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 19367, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - Random 2 - Cast Withering Heat'),
(11673*100+3, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 19369, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - Random 3 - Cast Ancient Despair'),
(11673*100+4, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 19372, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - Random 4 - Cast Ancient Hysteria'),
(11673*100+5, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 19365, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Core Hound - Random 5 - Cast Ancient Dread');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=11673;

-- Shadow of Aran

DELETE FROM `smart_scripts` WHERE `entryorguid`=18254 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18254, 0, 0, 0, 0, 0, 0, 0, 1000, 1000, 5000, 5000, 11, 29978, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow of Aran - IC - Cast Pyro Blast');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=18254;
