-- 
-- Hand of Iruxos Crystal SAI
SET @ENTRY := 176581;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI", `scriptname`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,64,0,100,0,0,0,0,0,12,11876,4,10000,0,0,0,1,0,0,0,0,0,0,0,"Hand of Iruxos Crystal - On Gossip Hello - Summon Creature 'Demon Spirit' for 10000 milliseconds ");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=176581;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,176581,1,0,29,1,11876,25,0,1,0,0,"","Do not run Hand of Iruxos Crystal SAI near 25 yards range to 'Demon Spirit'");
