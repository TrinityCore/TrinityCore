-- Forest Moss Creeper SAI fix
SET @ENTRY := 2350;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,6,7800,15700,48300,66300,11,3396,32,0,0,0,0,2,0,0,0,0,0,0,0,"Forest Moss Creeper - In Combat - Cast 3396 (Dungeon Only)");
-- Scarshield Grunt SAI fix
UPDATE `smart_scripts` SET `event_flags`=2 WHERE `entryorguid`=9043;
-- Mana Bomb Explosion Trigger SAI fix
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=20767 AND `id`=1;
-- Serpent Statue SAI fix
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=177673;
-- Warlord Tartek SAI fix
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=28105 AND `id`=4;
-- Razormane Hunter SAI fix
UPDATE `smart_scripts` SET `link`=5 WHERE `entryorguid`=3265 AND `id`=4;
-- Father Kamaros SAI fix
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=31279 AND `id`=14;

-- Thrym SAI fix
SET @ENTRY := 29895;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thrym - On spawn - Yell 0'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,97,40,30,0,0,0,0,1,0,0,0,5555.583, -2223.97, 235.967,0,'Thrym - On Script - Jump to pos'),
(@ENTRY,0,2,0,1,0,100,1,3000,3000,3000,3000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thrym - OOC - Set home position'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thrym - On Aggro - Yell 1'),
(@ENTRY,0,4,0,0,0,100,0,8000,16000,15000,21000,11,28167,0,0,0,0,0,5,0,0,0,0,0,0,0,'Thrym - IC - Cast Chain Lightning'),
(@ENTRY,0,5,0,6,0,100,0,0,0,0,0,11,55662,2,0,0,0,0,7,0,0,0,0,0,0,0,'Thrym - On Death - Cast criteria credit');
