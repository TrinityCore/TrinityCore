-- Territorial Trespass (13051)

SET @NPC_VERANUS := 30461;
SET @QUEST := 13051;
SET @EVENT := 19714;
SET @NPC_THORIM := 30462;
SET @SPELL_MOUNT := 43671;

UPDATE `creature_template` SET `HoverHeight`=10.8,`speed_walk`=3.2,`speed_run`=1.42857146263123,`VehicleId`=237,`minlevel`=80,`faction_A`=14,`faction_H`=14,`unit_flags`=0x8140,`InhabitType`=5 WHERE `entry`=@NPC_VERANUS;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_VERANUS;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_VERANUS,0,0x3000000,0x1,'');

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_VERANUS,@NPC_THORIM);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_VERANUS,0,0,'%s lets out a bellowing roar as she descends upon the nest.',16,0,100,15,0,0,'Veranus'),
(@NPC_THORIM,0,0,'Look out below!',14,0,100,0,0,0,'Thorim'),
(@NPC_THORIM,1,0,'Easy there, girl!  Don''t you recognize your old master?',12,0,100,0,0,0,'Thorim'),
(@NPC_THORIM,2,0,'I will see you at the Temple of Storms. Looks like I''m going to have to break her in again.',12,0,100,0,0,0,'Thorim');

-- Veranus SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_VERANUS,@NPC_THORIM);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_VERANUS,@NPC_THORIM) AND `source_type`=0) OR (`entryorguid`=@NPC_THORIM*100 AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_VERANUS,0,0,0,54,0,100,0,0,0,0,0,53,1,@NPC_VERANUS,0,@QUEST,0,0,1,0,0,0,0,0,0,0,'Veranus - On Summoned - Start WP-Movement'),
(@NPC_VERANUS,0,1,2,58,0,100,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Veranus - On WP-End - Talk(emote)'),
(@NPC_VERANUS,0,2,3,61,0,100,0,1,0,0,0,33,@NPC_VERANUS,0,0,0,0,0,7,0,0,0,0,0,0,0,'Veranus - On WP-End - Give quest credit'),
(@NPC_VERANUS,0,3,0,61,0,100,0,0,0,0,0,12,@NPC_THORIM,8,0,0,0,0,8,0,0,0,7096.863,-904.658,1119.904,2.338741,'Veranus - On WP-End - Summon Thorim'),
(@NPC_VERANUS,0,4,5,38,0,100,0,1,1,0,0,46,100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Veranus - On data - Move forward'),
(@NPC_VERANUS,0,5,0,61,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Veranus - On data - despawn'),
--
(@NPC_THORIM,0,0,0,54,0,100,0,0,0,0,0,80,@NPC_THORIM*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Thorim - On Summoned - Start script'),
(@NPC_THORIM,0,1,0,38,0,100,0,1,1,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thorim - On data - despawn'),
(@NPC_THORIM*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thorim - On Script - Talk(yell)'),
(@NPC_THORIM*100,9,1,0,0,0,100,0,0,0,0,0,11,@SPELL_MOUNT,0,0,0,0,0,7,0,0,0,0,0,0,0,'Thorim - On Script - Cast spell mount'),
(@NPC_THORIM*100,9,2,0,0,0,100,0,10000,10000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thorim - On Script - Talk(say)'),
(@NPC_THORIM*100,9,3,0,0,0,100,0,5000,5000,0,0,1,2,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Thorim - On Script - Talk(say)'),
(@NPC_THORIM*100,9,4,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,7,0,0,0,0,0,0,0,'Thorim - On Script - Set data'),
(@NPC_THORIM*100,9,5,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,1,0,0,0,0,0,0,0,'Thorim - On Script - Set data');

DELETE FROM `waypoints` WHERE `entry`=@NPC_VERANUS;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@NPC_VERANUS,1,7083.224,-912.2372,1090.213,'Veranus - WP1');

DELETE FROM `event_scripts` WHERE `id`=@EVENT;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@EVENT,0,10,@NPC_VERANUS,600000,0,6947.481,-859.5176,1147.604,5.674867);
