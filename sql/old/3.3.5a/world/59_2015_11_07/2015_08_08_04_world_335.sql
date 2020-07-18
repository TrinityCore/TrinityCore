-- 
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='', `Flags_Extra`=0 WHERE `entry` IN (3568);
DELETE FROM `creature_text` WHERE `entry` IN (3519, 3568);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(3519,0,0,"Mist! I feared I would never see you again! Yes, I am well, do not worry for me. You must rest and recover your health.",12,7,100,0,0,0, 'Sentinel Arynia Cloudsbreak', 1330),
(3568,0,0,"%s growls in acknowledgement before straightening and making her way off into the forest.",16,0,100,0,0,0, 'Mist', 1340);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3568) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (356800, 356801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3568,0,0,0,19,0,100,0,938,0,0,0,80,356800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - On Quest Accepted- Action list"),
(356800,9,0,0,0,0,100,0,0,0,0,0,64,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mist - Actionlist - Store target"),
(356800,9,1,0,0,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Remove  unit flag"),
(356800,9,2,0,0,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - React def"),
(356800,9,3,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - remove npcflag"),
(356800,9,4,0,0,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mist - Actionlist - Start follow"),
(356800,9,5,0,0,0,100,0,540000,540000,0,0,6,928,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mist - Actionlist - Quest fail"),
(356800,9,6,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Despawn"),
(3568,0,1,0,75,0,100,1,0,3519,4,0,80,356801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Creature distance- Action list"),
(356801,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Root"),
(356801,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,3519,20,0,0,0,0,0,"Mist - Actionlist - Say text1"),
(356801,9,2,0,0,0,100,0,2000,2000,0,0,15,938,0,0,0,0,0,12,0,0,0,0,0,0,0,"Mist - Actionlist - CALL_AREAEXPLOREDOREVENTHAPPENS"),
(356801,9,3,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Say text1"),
(356801,9,4,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Despawn"),
(3568,0,2,0,6,0,100,0,0,0,0,0,6,938,0,0,0,0,0,12,0,0,0,0,0,0,0,'Mist - On Death - Fail Quest'),
(3568,0,3,4,11,0,100,0,0,0,0,0,2,80,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mist - On Respawn - Set faction'),
(3568,0,4,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mist - On Respawn - React passif');
