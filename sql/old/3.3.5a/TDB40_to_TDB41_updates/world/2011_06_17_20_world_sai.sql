-- Defines
SET @WHITEBARK_SPIRIT_ENTRY := 19456;
SET @SPELL_ENTANGLING_ROOTS := 31287;
SET @SPELL_WITHERED_TOUCH := 11442;
-- Template
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@WHITEBARK_SPIRIT_ENTRY;
-- Delete old data
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@WHITEBARK_SPIRIT_ENTRY;
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-1051,-1052);
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@WHITEBARK_SPIRIT_ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@WHITEBARK_SPIRIT_ENTRY,0,0,'What good does this violence serve?  What is done is done.  I have failed my people.',12,0,50,0,0,0,'Whitebark''s Spirit - 19456'),
(@WHITEBARK_SPIRIT_ENTRY,0,1,'Haven''t you done enough harm?  Must you also disturb my slumber?',12,0,50,0,0,0,'Whitebark''s Spirit - 19456');
-- Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=@WHITEBARK_SPIRIT_ENTRY;
INSERT INTO `smart_scripts`
(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WHITEBARK_SPIRIT_ENTRY,0,0,0,0,0,100,0,2500,5500,12000,14500,11,@SPELL_ENTANGLING_ROOTS,0,0,0,0,0,2,0,0,0,0,0,0,0,'Whitebark''s Spirit - Casts Entangling Roots'),
(@WHITEBARK_SPIRIT_ENTRY,0,1,0,0,0,100,0,7500,7500,9500,16000,11,@SPELL_WITHERED_TOUCH,0,0,0,0,0,2,0,0,0,0,0,0,0,'Whitebark''s Spirit - Casts Withered Touch'),
(@WHITEBARK_SPIRIT_ENTRY,0,2,0,2,0,100,1,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark''s Spirit - Say At 25% HP'),
(@WHITEBARK_SPIRIT_ENTRY,0,3,4,2,0,100,1,0,20,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark''s Spirit - At 20% HP change faction to friendly'),
(@WHITEBARK_SPIRIT_ENTRY,0,4,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark''s Spirit - At 20% HP - evade'),
(@WHITEBARK_SPIRIT_ENTRY,0,5,0,1,0,100,0,15000,15000,15000,15000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whitebark''s Spirit - after 15sec OOC  - despawn');
