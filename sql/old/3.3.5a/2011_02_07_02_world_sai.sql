-- SAI for quest 10345 "The Flesh Lies..."
-- Spell script target for Protectorate Igniter (quest The Flesh Lies...) 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=35372;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,35372,1,18,1,20561,0,0,'', 'Protectorate Igniter');
-- Withered Corpse SAI.
SET @ENTRY:=20561;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~2 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|256 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'On spawn set phase 1'),
(@ENTRY,0,1,0,8,1,100,0,35372,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'set phase 0'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,0,0,33,20561,0,0,0,0,0,7,0,0,0,0,0,0,0,'give quest credit'),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'despawn');

-- SAI for quest 11607 "The Lost Spirits"
-- Kaskala Craftman SAI.
SET @ENTRY:=25321;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'On spawn set phase 1'),
(@ENTRY,0,1,0,8,1,100,0,45504,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'set phase 0'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say Text 0 random'),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,0,0,33,25321,0,0,0,0,0,7,0,0,0,0,0,0,0,'give quest credit'),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'despawn');
-- Add texts for this NPC.
DELETE FROM `creature_text` WHERE `entry`=25321;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(25321,0,0, 'Thank you for freeing me! May the tides always favor you.',0,0,100,1,0,0, 'Kaskala Craftman'),
(25321,0,1, 'Do not allow Kaskala to forget what has happened here.',0,0,100,1,0,0, 'Kaskala Craftman');
-- Kaskala Shaman SAI.
SET @ENTRY:=25322;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0, 'On spawn set phase 1'),
(@ENTRY,0,1,0,8,1,100,0,45504,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'set phase 0'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say Text 0 random'),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,0,0,33,25322,0,0,0,0,0,7,0,0,0,0,0,0,0, 'give quest credit'),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'despawn');
-- Add texts for this NPC.
DELETE FROM `creature_text` WHERE `entry`=25322;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(25322,0,0, 'May the ancestors always aid you, $n, as you have aided me.',0,0,100,1,0,0, 'Kaskala Shaman'),
(25322,0,1, 'Thank you, $n. May the winds and seas always deliver you safely.',0,0,100,1,0,0, 'Kaskala Shaman');
-- Delete the old EAI script.
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (25321,25322);
-- Delete the EAI texts.
DELETE FROM `creature_ai_texts` WHERE entry IN (-899,-898,-900,-901);
