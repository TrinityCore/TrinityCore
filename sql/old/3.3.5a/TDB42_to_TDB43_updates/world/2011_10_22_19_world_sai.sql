-- Quest 12860, 12927 "Data Mining"
SET @CREDIT := 29752;
SET @SPELL_CREDIT := 59728;
SET @SPELL := 55161;
SET @NPC := 29746;

UPDATE `creature_template` SET `AIName`='SmartAI', `InhabitType`=7 WHERE `entry`=@NPC;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,1,8,0,100,0,@SPELL_CREDIT,0,0,0,33,@CREDIT,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Databank Core - On spell Retrieve Data hit - Give kill credit for quest Data Mining'),
(@NPC,0,1,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Databank Core - On spell Retrieve Data hit - Despawn (Linked)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_CREDIT;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_CREDIT;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL,0,29,@NPC,20,0,0, '', 'Spell Retrieve Data will only be cast near Databank'),
(13,0,@SPELL,0,18,1,@NPC,0,0, '', 'Spell Retrieve Data does only target Databank');
