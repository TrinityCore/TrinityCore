-- Random comment ™
-- Corrupted Scarlet Onslaught
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29400;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29400;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29400,0,0,0,0,0,100,0,2000,15000,30000,45000,11,38056,2,0,0,0,0,2,0,0,0,0,0,0,0,'Corrupted Scarlet Onslaught - IC - Flesh Rip');

-- Onslaught Raven Bishop
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29338;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=29338;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29338,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - Set Phase 1 - On Aggro'),
(29338,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - Stop Moving - On Aggro'),
(29338,0,2,0,4,1,100,1,0,0,0,0,11,50740,0,0,0,0,0,2,0,0,0,0,0,0,0,'Raven Bishop - Cast bolt on Aggro'),
(29338,0,3,0,9,1,100,0,0,40,3400,4700,11,50740,0,0,0,0,0,2,0,0,0,0,0,0,0,'Raven Bishop -  Cast Raven Flock'),
(29338,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - Start Moving - When not in flock Range'),
(29338,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - Stop Moving - 15 Yards'),
(29338,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - Stop Moving - When in flock Range'),
(29338,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - Set Phase 2 - 15% Mana'),
(29338,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - Start Moving - 15% Mana'),
(29338,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - Set Phase 1 - When Mana is above 30%'),
(29338,0,10,0,2,1,100,0,10,50,2000,8000,11,50750,0,0,0,0,0,2,0,0,0,0,0,0,0,'Raven Bishop - Health Pct - Cast Raven Heal');

-- Onslaught Paladin
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29329;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29329;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29329,0,0,0,4,0,100,0,0,0,0,0,11,19131,2,0,0,0,0,2,0,0,0,0,0,0,0,'Onslaught Paladin - On Aggro - Cast Charge'),
(29329,0,1,0,0,0,100,0,2000,9000,17000,30000,11,32774,2,0,0,0,0,2,0,0,0,0,0,0,0,'Onslaught Paladin  - IC - Avenger''s Shield');

-- Onslaught Harbor Guard
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29330;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=29330;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29330,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbor Guard - Set Phase 1 - On Aggro'),
(29330,0,1,0,4,1,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,'Harbor Guard - Cast Shoot - On Aggro'),
(29330,0,2,0,9,1,100,0,0,40,3400,4700,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,'Harbor Guard -  Cast Shoot'),
(29330,0,3,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbor Guard - Start Moving - When not in Shoot range'),
(29330,0,4,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbor Guard - Stop Moving - 15 Yards'),
(29330,0,5,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbor Guard - Stop Moving - When in bolt Range'),
(29330,0,6,0,0,1,100,0,8000,8000,12000,14000,11,50750,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbor Guard - IC - Cast Frost Shot');
