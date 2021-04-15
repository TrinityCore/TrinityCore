-- SAI for Zereketh The Unbound
SET @ENTRY := 20870;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zereketh The Unbound - On Aggro - Say text'),
(@ENTRY,0,1,0,5,0,100,6,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zereketh The Unbound - On Player Death - Say text'),
(@ENTRY,0,2,0,6,0,100,7,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zereketh The Unbound - On Death - Say text'),
(@ENTRY,0,3,0,0,0,80,6,32000,32000,32000,32000,11,36119,0,0,0,0,0,4,0,0,0,0,0,0,0, 'Zereketh The Unbound - Combat - Cast Void Zone'),
(@ENTRY,0,4,5,0,0,80,2,10000,10000,40000,40000,11,36127,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Zereketh The Unbound - Combat - Cast Shadow Nova'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zereketh The Unbound - Cast Shadow Nova - Say text'),
(@ENTRY,0,6,7,0,0,80,4,10000,10000,40000,40000,11,39005,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Zereketh The Unbound - Combat - Cast Shadow Nova'),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zereketh The Unbound - Cast Shadow Nova - Say text');

-- NPC talk text convert from creature_ai_text
DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -33 AND -29;
DELETE FROM `creature_text` WHERE `entry` IN (20870);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(20870,0,0, 'Life energy to... consume.',14,0,100,0,0,11250, 'Zereketh The Unbound - Aggro Say'),
(20870,1,0, 'This vessel... is empty.',14,0,100,0,0,11251, 'Zereketh The Unbound - Player Death Say'),
(20870,1,1, 'No...more...life.',14,0,100,0,0,11252, 'Zereketh The Unbound - Player Death Say'),
(20870,2,0, 'The shadow... will engulf you.',14,0,100,0,0,11253, 'Zereketh The Unbound - Cast Shadow Nova Say'),
(20870,2,1, 'Darkness...consumes...all.',14,0,100,0,0,11254, 'Zereketh The Unbound - Cast Shadow Nova Say'),
(20870,3,0, 'The void...beckons.',14,0,100,0,0,11255, 'Zereketh The Unbound - On Death Say');
