-- 
DELETE FROM `creature` WHERE `id` IN (698, 756);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` IN (669,784,699);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (669,784,699) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(669, 0, 0, 0, 60, 0, 100, 0, 1000, 4000, 10000, 10000, 11, 3621, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skullsplitter Hunter - On Update - Cast Skullsplitter Pet'),
(669, 0, 1, 0, 0, 0, 100, 0, 4000, 6000, 8000, 10000, 11, 3148, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Skullsplitter Hunter - IC Update - Cast Head Crack'),
(669, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 3417, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skullsplitter Hunter - On reset - Cast Thrash '),
(784, 0, 0, 0, 60, 0, 100, 0, 1000, 4000, 10000, 10000, 11, 3621, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skullsplitter Beastmaster - On Update - Cast Skullsplitter Pet'),
(784, 0, 1, 0, 0, 0, 100, 0, 500, 1000, 1661, 2000, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Skullsplinter Beastmaster - IC - Cast \'Shoot\''),
(699,0, 0,0, 25, 0,100,0, 0,  0,   0,   0, 11, 3612, 0, 0,0,0,0,1,0,0,0,0,0,0,0,'Bloodscalp Beastmaster - On reset - Cast Bloodscalp Pet'),
(699,0, 1,0,  0, 0,100,0, 500, 1000,2000,2000, 11, 6660, 64, 0,0,0,0,2,0,0,0,0,0,0,0,'Bloodscalp Beastmaster - IC - Cast \'Shoot\''),
(699,0, 2,3,  2, 0,100,1, 1, 20,   0,   0, 11, 8599,  0, 0,0,0,0,1,0,0,0,0,0,0,0,'Bloodscalp Beastmaster - On 20% Health - Cast Enrage (No Repeat)'),
(699,0, 3,0, 61, 0,100,0, 0,  0,   0,   0,  1,    0,  0, 0,0,0,0,1,0,0,0,0,0,0,0,'Bloodscalp Beastmaster - On 20% Health - Say Line 0 (No Repeat)');
