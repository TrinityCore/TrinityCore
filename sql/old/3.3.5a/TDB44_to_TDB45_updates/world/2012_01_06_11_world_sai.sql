-- Quest "Torgos!" 10035 (A) - 10036 (H)
-- Converted to SAI
SET @TRACHELA := 21515;
SET @TORGOS := 18707;
DELETE FROM `creature` WHERE `id`=@TORGOS; -- Torgos must to appear only by quest
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~256 WHERE `entry`=@TORGOS; -- removing OOC
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@TORGOS,@TRACHELA);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@TORGOS,@TRACHELA);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@TORGOS,@TRACHELA);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRACHELA,0,0,0,0,0,100,0,5000,8000,10000,14000,11,32903,1,0,0,0,0,5,0,0,0,0,0,0,0, 'Trachela - On combat - Cast Fevered Disease'),
(@TORGOS,0,0,0,0,0,100,0,2000,5000,12000,20000,11,32022,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Torgos - On combat - Cast Gut Rip'),
(@TORGOS,0,1,0,0,0,100,0,8000,10000,20000,25000,11,13579,1,0,0,0,0,3,0,0,0,0,0,0,0, 'Torgos - On combat - Cast Gouge'),
(@TORGOS,0,2,0,0,0,100,0,5000,8000,10000,14000,11,32903,1,0,0,0,0,5,0,0,0,0,0,0,0, 'Torgos - On combat - Cast Fevered Disease');
