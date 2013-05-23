SET @NARVIR := 30299;
SET @HEART := 192181;

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@HEART;
UPDATE `creature_template` SET `speed_run`=0.99206, `faction_H`=1954, `faction_A`=1954, `unit_flags`=768, `AIName`='SmartAI' WHERE `entry`=@NARVIR;

DELETE FROM `creature_equip_template` WHERE `entry`=@NARVIR;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@NARVIR,1,35727,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NARVIR AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@HEART AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NARVIR*100,@HEART*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NARVIR,0,0,0,11,0,100,0,0,0,0,0,80,@NARVIR*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir - On spawn - Run script'),
(@NARVIR,0,1,2,8,0,100,0,40163,0,0,0,33,@NARVIR,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Overseer Narvir - On spellhit Teleport - Quest credit'),
(@NARVIR,0,2,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir - On spellhit Teleport - Despawn'),

(@HEART,1,0,0,70,0,100,0,2,0,0,0,80,@HEART*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'The Heart of the Storm - On state changed - Run script'),

(@NARVIR*100,9,0,0,0,0,100,0,20,20,0,0,11,56485,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Overseer Narvir script - Spellcast The Storm''s Fury'),
(@NARVIR*100,9,1,0,0,0,100,0,500,500,0,0,69,0,0,0,0,0,0,8,0,0,0,7312.406,-726.3165,791.6095,0, 'Overseer Narvir script - Move to position'),
(@NARVIR*100,9,1,0,0,0,100,0,6500,6500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.919862, 'Overseer Narvir script - Turn to'),
(@NARVIR*100,9,3,0,0,0,100,0,1500,1500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir script - Say line'),
(@NARVIR*100,9,4,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir script - Say line'),
(@NARVIR*100,9,5,0,0,0,100,0,3000,3000,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir script - Play emote'),
(@NARVIR*100,9,6,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.385939, 'Overseer Narvir script - Turn to'),
(@NARVIR*100,9,7,0,0,0,100,0,500,500,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir script - Play emotestate'),
(@NARVIR*100,9,8,0,0,0,100,0,3500,3500,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir script - Stop emotestate'),
(@NARVIR*100,9,9,0,0,0,100,0,1500,1500,0,0,11,40163,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir script - Spellcast Teleport'),

(@HEART*100,9,0,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Heart of the Storm script - Store targetlist'),
(@HEART*100,9,1,0,0,0,100,0,0,0,0,0,12,@NARVIR,8,0,0,0,0,8,0,0,0,7313.231,-711.5209,791.6917,5.61996, 'The Heart of the Storm script - Summon Overseer Narvir'),
(@HEART*100,9,2,0,0,0,100,0,10,10,0,0,100,1,0,0,0,0,0,19,@NARVIR,50,0,0,0,0,0, 'The Heart of the Storm script - Send targetlist to Overseer Narvir');

DELETE FROM `creature_text` WHERE `entry`=@NARVIR;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NARVIR,0,0,'You didn''t think that I was going to let you walk in here and take the Heart of the Storm, did you?',12,0,100,6,0,0,'Overseer Narvir'),
(@NARVIR,1,0,'You may have killed Valduran, but that will not stop me from completing the colossus.',12,0,100,1,0,0,'Overseer Narvir');
