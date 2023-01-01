-- view-source:http://web.archive.org/web/20100613150844/www.wowhead.com/npc=31691
UPDATE `creature_template` SET `mingold` = 1654, `maxgold` = 2756 WHERE `entry` = 31691;

-- https://youtu.be/H4Kx-sCWEic?t=69
DELETE FROM `smart_scripts` WHERE `entryorguid` = 31691 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(31691,0,0,0,4,0,20,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Faceless Lurker - On Aggro - Say Line 0"),
(31691,0,1,0,0,0,100,1,1000,2000,0,0,0,11,52342,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Faceless Lurker - In Combat - Cast 'Seething Evil' (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = 31691;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(31691,0,0,"Shur'nab... shur'nab... Yogg-Saron!",12,0,100,0,0,0,29709,0,"Faceless Lurker");
