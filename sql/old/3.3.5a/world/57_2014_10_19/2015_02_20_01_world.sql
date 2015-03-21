--
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=17587;
SET @ENTRY := 17587;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` IN (11, 12, 13, 14, 15, 16);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 11, 0, 26, 0, 100, 0, 1, 15, 60000, 60000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - IC_LOS - TALK'),
(@ENTRY, 0, 12, 0, 53, 0, 100, 0, 1, 200000, 20000, 20000, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - RECEIVE_HEAL - TALK'),
(@ENTRY, 0, 13, 0, 5, 0, 100, 0, 30000, 30000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - KILL - TALK'),
(@ENTRY, 0, 14, 0, 1, 0, 100, 0, 60000, 60000, 60000, 60000, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - OOC - TALK'),
(@ENTRY, 0, 15, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 25, 15, 0, 0, 0, 0, 0, 0, 'Draenei Youngling - AGGRO - TALK'),
(@ENTRY,0,16,0,11,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Respawn ' Remove npcflag");
DELETE FROM  smart_scripts  WHERE `entryorguid`=24178 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24178,0,3,0,8,0,0,0,43209,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shatterhorn - On Place Meat spellhit remove unit flags');
