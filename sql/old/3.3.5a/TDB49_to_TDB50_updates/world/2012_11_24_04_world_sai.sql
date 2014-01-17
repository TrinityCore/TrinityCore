-- Add creature_text entry for the shout
DELETE FROM `creature_text` WHERE `entry`=23905;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(23905,0,0,'Keep Moving!',14,7,100,0,0,0, 'Major Mills');
-- Add Smart AI for the quest.
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23905) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2390500) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23905,0,0,0,19,1,100,0,11198,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Major Mills - On Quest Accept - Say text'),
(23905,0,1,0,19,1,100,0,11198,0,0,0,80,2390500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Major Mills: On quest accept call main script'),
-- After 5 seconds: Summon Guards
(2390500,9,0,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3904.77,-4635.09,9.62735,5.49334, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,1,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3856.59,-4622.45,9.24753,3.87856, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,2,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3917.6,-4648.53,9.32604,5.56795, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,3,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3890.48,-4620.7,9.55527,4.99383, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,4,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3865.94,-4617.2,9.26262,4.16523, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,5,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3834.8,-4645.41,9.25827,3.61152, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,6,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3826.61,-4655.32,9.21484,3.13243, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,7,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3830.76,-4673.74,9.50962,2.70832, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,8,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3843.65,-4687.59,9.6436,2.43735, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,9,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3858.49,-4703.49,9.17411,2.33525, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,10,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3851.97,-4697.24,9.36834,2.33525, 'Take Down Tethyr: Summon Theramore Marksman'),
(2390500,9,11,0,1,0,100,0,5000,5000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3924.35,-4656.55,9.15409,5.80749, 'Take Down Tethyr: Summon Theramore Marksman'),
 -- After 8 seconds Summon Tethyr
(2390500,9,12,0,1,0,100,0,8000,8000,0,0,12,23900,1,900000,0,0,0,8,0,0,0,-3891.03,-4671.17,-1.52,0.74, 'Take Down Tethyr: Summon Tethyr');
