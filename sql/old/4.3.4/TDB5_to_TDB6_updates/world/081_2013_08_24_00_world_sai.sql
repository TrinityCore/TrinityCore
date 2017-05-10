-- Sleeping Giants A:11432 H:11433
SET @ENTRY    := 24669; -- Dormant Vrykul
SET @ITEM     := 34083; -- Awakening Rod

DELETE FROM `conditions` WHERE `SourceEntry`=@ITEM;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,@ITEM,0,24,1,@ENTRY,0,0,'','Awakening Rod target only Dormant Vrykul');

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Interference with the wakening ritual causes the vrykul to die.',16,0,100,0,0,0,'Dormant Vrykul emote text'),
(@ENTRY,0,1,'The vrykul dies from being awakened improperly.',16,0,100,0,0,0,'Dormant Vrykul emote text'),
(@ENTRY,0,2,'The incorrect application of the awakening rod causes the dormant vrykul to expire.',16,0,100,0,0,0,'Dormant Vrykul emote text');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100) AND `source_type` IN (0,9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,44261,0,0,0,5,53,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Dormant Vrykul - On Spellhit - Emote visual - Self'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,' Dormant Vrykul - On Link - Start Action Script'),
--
(@ENTRY*100,9,0,0,0,0,100,0,300,300,300,300,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,' Dormant Vrykul - On Script - Emote text  Invoker'),
(@ENTRY*100,9,1,0,0,0,100,0,2000,2000,2000,2000,33,24669,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,' Dormant Vrykul - On Script - Kill credit Invoker'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,' Dormant Vrykul - On Script - Die'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,41,4500,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Dormant Vrykul - On Script  Despawn');
