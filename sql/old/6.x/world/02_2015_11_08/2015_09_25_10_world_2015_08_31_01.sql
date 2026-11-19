--
-- Kvaldir Raider SAI
SET @ENTRY := 25760;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,2000,2000,4000,4000,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Raider - OOC - React passif"),
(@ENTRY,0,1,0,1,0,100,1,3000,5000,4000,4000,17,375,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Raider - OOC - Emote"),
(@ENTRY,0,2,0,1,0,100,1,3000,3000,4000,4000,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Raider - OOC - React Aggressif");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (1,2,3) AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`,`NegativeCondition`) VALUES
(22,1,@ENTRY,0,0,1,1,43671,1,0,0,"","Only Run script if the npc has the aura 43671",0),
(22,2,@ENTRY,0,0,1,1,43671,1,0,0,"","Only Run script if the npc hasn't the aura 43671",1),
(22,3,@ENTRY,0,0,1,1,43671,1,0,0,"","Only Run script if the npc hasn't the aura 43671",1);

UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=@ENTRY;
