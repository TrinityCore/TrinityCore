-- 
DELETE FROM `event_scripts` WHERE `id` IN (16243);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(16243, 0, 10, 23519, 180000, 0, -385.3869, -5649.8955, 0, 5.175775);

UPDATE  `creature_template` SET `AIName`='SmartAI', `unit_flags`=33024, `speed_walk`=4, `speed_run`=3  WHERE `entry` IN (23519);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23519) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23519,0,0,0,54,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Big Shirl - Just summoned - Set run ON"),
(23519,0,1,0,54,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,-83.86965, -5956.43017, 0 ,0,"Big Shirl - Just summoned - Movee to pos"),
(23519,0,2,0,34,0,100,0,0,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Big Shirl - On movement informer - Despawn"),
(23519,0,3,0,54,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Big Shirl - Just summoned - despawn");
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (23519);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,4,23519,0,0,29,1,23519,100,0,0,0,'','Execute sai if there''s already a spawned Big Shirl');
