-- [Q] The Might of the Horde

-- Warsong Battle Standard SAI
SET @ENTRY := 26678;
SET @QUEST := 12053;
UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=70,`maxlevel`=71,`exp`=1 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - On Spawn - Set React State Passive"), -- We shouldn't EVER attack back or move
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,6,@QUEST,0,0,0,0,0,23,0,0,0,0,0,0,0,"Warsong Battle Standard - On Death - Fail Quest"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - Just Summoned - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,5000,15000,0,0,12,26676,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Summon Anub'ar Invader"),
(@ENTRY*100,9,1,0,0,0,100,0,8000,15000,0,0,12,26676,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Summon Anub'ar Invader"),
(@ENTRY*100,9,2,0,0,0,100,0,8000,15000,0,0,12,26676,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Summon Anub'ar Invader"),
(@ENTRY*100,9,3,0,0,0,100,0,8000,15000,0,0,12,26676,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Summon Anub'ar Invader"),
(@ENTRY*100,9,4,0,0,0,100,0,8000,15000,0,0,12,26676,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Summon Anub'ar Invader"),
(@ENTRY*100,9,5,0,0,0,100,0,4000,4000,0,0,15,@QUEST,0,0,0,0,0,23,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Quest Credit");

-- Anub'ar Invader SAI
SET @ENTRY := 26676;
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=2018,`faction_H`=2018 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Anub'ar Invader - Just Summoned - Attack Summoner");
