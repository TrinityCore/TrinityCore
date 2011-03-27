-- Conversation between Sabetta Ward & Gavin Ward, Fort Wildervar "Sabetta Ward Envoker"
SET @ENTRY := 24532;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,30000,150000,150000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Load script every 2.5 min ooc'),
(@ENTRY*100,9,0,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sabetta Ward Say text 0'),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,9,24531,0,10,0,0,0,0,'Gavin Ward Say text 0'),
(@ENTRY*100,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sabetta Ward Say text 1'),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,9,24531,0,10,0,0,0,0,'Gavin Ward Say text 1'),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sabetta Ward Say text 2'),
(@ENTRY*100,9,5,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,9,24531,0,10,0,0,0,0,'Gavin Ward Say text 2');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (24531,24532);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24532,0,0, 'And I don''t want our land to have any of those horrible wolves, or giants, or ugly rams!',0,7,100,1,0,0, 'Sabetta Ward'),
(24531,0,0, 'Yes, darling. You realize you''ll be eating dire ram mutton for dinner until the crops are planted...',0,7,100,1,0,0, 'Gavin Ward'),
(24532,1,0, 'I''d sooner butcher that mule of yours! Why did you bring that beast in here, anyway?',0,7,100,5,0,0, 'Sabetta Ward'),
(24531,1,0, 'I''d rather listen to his braying than yours, dear.',0,7,100,0,0,0, 'Gavin Ward'),
(24532,2,0, 'Remember, honey, we need to get a plot of land with a nice hot spring.',0,7,100,1,0,0, 'Sabetta Ward'),
(24531,2,0, 'Of course, darling.',0,7,100,1,0,0, 'Gavin Ward');

-- Conversation between Brune Grayblade & Eldrim Mounder <Blacksmith>, Fort Wildervar "Brune Grayblade Envoker"
SET @ENTRY := 24528;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,60000,150000,150000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Load script every 2.5 min ooc'),
(@ENTRY*100,9,0,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Brune Grayblade Say text 0'),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,9,24052,0,10,0,0,0,0,'Eldrim Mounder Say text 0'),
(@ENTRY*100,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Brune Grayblade Say text 1'),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,9,24052,0,10,0,0,0,0,'Eldrim Mounder Say text 1'),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,9,24052,0,10,0,0,0,0,'Eldrim Mounder Say text 2'),
(@ENTRY*100,9,5,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Brune Grayblade Say text 2');
-- NPC talk text insert from sniff "5 sec between text 2 min between restart"
DELETE FROM `creature_text` WHERE `entry` IN (24528,24052);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24528,0,0, 'How much''ll it cost me to get my mules shod?',0,7,100,6,0,0, 'Brune Grayblade'),
(24052,0,0, 'We don''t shoe no mules here. ''Sides, it''s strictly expedition business right now.',0,7,100,1,0,0, 'Eldrim Mounder'),
(24528,1,0, 'You don''t understand! If I''m not ready to go soon, all the good homesteading land will be taken!',0,7,100,1,0,0, 'Brune Grayblade'),
(24052,1,0, 'Not my problem! If yer so antsy to get yerself a house built, do it ''ere in the fort and quit yer whinin''!',0,7,100,274,0,0, 'Eldrim Mounder'),
(24052,2,0, 'Now, if you''d be so kind as to get your ass away from my forge...',0,7,100,25,0,0, 'Eldrim Mounder'),
(24528,2,0, 'That, sir, is a mule!',0,7,100,25,0,0, 'Brune Grayblade');
-- Creature Template Addon info
DELETE FROM `creature_template_addon` WHERE `entry` IN (24528,24052);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(24528,0,0,256,0, ''),
(24052,0,0,257,0, '');
