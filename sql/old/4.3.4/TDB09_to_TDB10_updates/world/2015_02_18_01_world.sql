--
SET @ENTRY := 178905;
SET @Scion:= 13696;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@Scion);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Scion AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,64,0,100,0,0,0,0,0,12,13696,2,60000,0,0,0,1,0,0,0,0,0,0,0,"Vylestem Vine - On Gossip Hello - Summon Creature 'Noxxious Scion'"),
(@Scion,0,0,0,4,0,100,1,0,0,0,0,11,21883,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noxxious Scion - On Aggro -Cast 21883"),
(@Scion,0,1,0,63,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Noxxious Scion - On Just created - Attack");
