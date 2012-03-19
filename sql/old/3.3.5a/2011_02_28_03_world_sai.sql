-- SAI for Thoralius the Wise
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23975;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23975;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (2397500,2397501,2397502,2397503);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- AI Section
(23975,0,0,1,1,0,100,0,60000,120000,300000,300000,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - every 5 min Stand'),
(23975,0,1,0,61,0,100,0,0,0,0,0,53,0,23975,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Start WP'),
(23975,0,2,0,40,0,100,0,2,23975,0,0,80,2397500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Load script 1 at WP 2'),
(23975,0,3,0,40,0,100,0,4,23975,0,0,80,2397501,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Load script 2 at WP 4'),
(23975,0,4,0,40,0,100,0,7,23975,0,0,80,2397502,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Load script 3 at WP 7'),
(23975,0,5,0,40,0,100,0,8,23975,0,0,80,2397503,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Load script 4 at WP 8'),
-- Script 1
(2397500,9,0,0,0,0,100,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Pause at WP 2'),
(2397500,9,1,0,0,0,100,0,0,0,0,0,11,42837,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Cast 42837'),
(2397500,9,2,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,24046,0,0,0,0,0,0, 'Thoralius the Wise - Turn to face spirit Totem (Fire)'),
(2397500,9,3,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - say text 0'),
-- Script 2
(2397501,9,0,0,0,0,100,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Pause at WP 4'),
(2397501,9,1,0,0,0,100,0,0,0,0,0,11,42838,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Cast 42838'),
(2397501,9,2,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,24045,0,0,0,0,0,0, 'Thoralius the Wise - Turn to face spirit Totem (Water)'),
(2397501,9,3,0,0,0,100,0,500,500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Say text 1'),
-- Script 3
(2397502,9,0,0,0,0,100,0,0,0,0,0,54,53000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Pause at WP 7'),
(2397502,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Do text 2'),
(2397502,9,2,0,0,0,100,0,1000,1000,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - do emote state STATE_STUN'),
(2397502,9,3,0,0,0,100,0,45000,45000,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - do emote state STATE_STAND'),
(2397502,9,4,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Do text 3'),
-- Script 4
(2397503,9,0,0,0,0,100,0,8,23975,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Stop at WP 8'),
(2397503,9,1,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - Reset heading at WP 8'),
(2397503,9,2,0,0,0,100,0,500,500,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thoralius the Wise - sit at WP 8');

-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry`=23975;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(23975,0,0, 'Fire grant me vision...',0,7,100,20,0,0, 'Thoralius the Wise'),
(23975,1,0, 'Water grant me serenity...',0,7,100,20,0,0, 'Thoralius the Wise'),
(23975,2,0, '%s inhales the wispy smoke tendrils emanating from the burner.',2,7,100,0,0,0, 'Thoralius the Wise'),
(23975,3,0, 'Thank you, spirits.',0,7,100,2,0,0, 'Thoralius the Wise');

-- Waypoints for Thoralius the Wise from sniff
DELETE FROM `waypoints` WHERE `entry`=23975;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(23975,1,637.177,-5011.109,4.653919,'Thoralius the Wise WP 1'),
(23975,2,634.8372,-5010.296,4.528919,'Thoralius the Wise WP 2'),
(23975,3,637.9232,-5015.031,4.528919,'Thoralius the Wise WP 3'),
(23975,4,636.0419,-5016.675,4.153919,'Thoralius the Wise WP 4'),
(23975,5,638.2552,-5013.186,4.653919,'Thoralius the Wise WP 5'),
(23975,6,637.7585,-5013.268,4.653919,'Thoralius the Wise WP 6'),
(23975,7,636.8245,-5013.386,4.528919,'Thoralius the Wise WP 7'),
(23975,8,638.2552,-5013.186,4.653919,'Thoralius the Wise WP 8');

-- Add spell target positions
DELETE FROM `spell_target_position` WHERE `id` IN (42837,42838);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(42837,571,634.094,-5010.67,4.419494,2.807002),
(42838,571,635.081,-5016.87,4.138474,3.859472);

-- Ascented Mage Hunter SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25724;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25724);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25724,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ascented Mage Hunter - On reset - Set react state passive'),
(25724,0,1,0,1,0,100,1,1000,1000,1000,1000,11,45940,0,0,0,0,0,9,25594,0,10,0,0,0,0,'Ascented Mage Hunter - On reset - Cast Evanor''s Prison Chains');