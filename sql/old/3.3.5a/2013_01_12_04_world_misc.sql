UPDATE `creature_template` SET `AIName` = '',`ScriptName` = 'boss_mechano_lord_capacitus' WHERE `entry` =19219;
UPDATE `creature_template` SET `unit_flags`=`unit_flags` |2 |33554432 WHERE `entry` IN (20405,21534); -- Nether Charge

DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (19219,20405);
DELETE FROM `creature_ai_texts` WHERE `entry` BETWEEN -92 AND -87;

DELETE FROM `creature_template_addon` WHERE `entry` IN (20405,21534);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(20405,0,0,0,0,0,'37670 35150'), -- Nether Charge
(21534,0,0,0,0,0,'37670 35150'); -- Nether Charge (1)

SET @ENTRY := 20405; -- Nether Charge

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,0,0,100,0,14000,14000,1000,1000,11,35151,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Nether Bomb - Nether Charge Pulse"),
(@ENTRY,0,1,0,0,0,100,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Nether Charge - No Melee"),
(@ENTRY,0,2,0,0,0,100,0,0,0,14000,14000,21,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Nether Charge - Prevent Combat Movement When Start...");

DELETE FROM `creature_text` WHERE `entry` = 19219;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(19219, 0, 0, 'You should split while you can.', 14, 0, 100, 0, 0, 11162, 'Mechano-Lord Capacitus - Aggro'),
(19219, 1, 0, 'Go ahead, gimme your best shot. I can take it!', 14, 0, 100, 0, 0, 11166, 'Mechano-Lord Capacitus - Yells'), -- Reflective Damage Shield
(19219, 2, 0, 'Think you can hurt me, huh? Think I''m afraid a'' you?', 14, 0, 100, 0, 0, 11165, 'Mechano-Lord Capacitus - Yells'), -- Reflective Magic Shield
(19219, 3, 0, 'Can''t say I didn''t warn you!', 14, 0, 100, 0, 0, 11163, 'Mechano-Lord Capacitus - Killing a player'),
(19219, 3, 1, 'Damn, I''m good!', 14, 0, 100, 0, 0, 11164, 'Mechano-Lord Capacitus - Killing a player'),
(19219, 4, 0, 'Bully!', 14, 0, 100, 0, 0, 11167, 'Mechano-Lord Capacitus - Death');
