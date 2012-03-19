-- [Q] The Dreghood Elder
SET @ENTRY_AYLAAN := 20679;
SET @ENTRY_AKORU := 20678;
SET @ENTRY_MOROD := 20677;

-- Aylaan the Waterwalker - Akoru the Firecaller - Morod the Windstirrer SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY_AKORU,@ENTRY_AYLAAN,@ENTRY_MOROD);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_AKORU,@ENTRY_AYLAAN,@ENTRY_MOROD);
INSERT INTO `smart_scripts`  (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)  VALUES
(@ENTRY_AYLAAN,0,0,0,62,0,100,0,8161,0,0,0,33,@ENTRY_AYLAAN,0,0,0,0,0,7,0,0,0,0,0,0,0,"Aylaan the Waterwalker - On Gossip Select - Quest Credit The Dreghood Elders"),
(@ENTRY_AYLAAN,0,1,0,62,0,100,0,8161,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Aylaan the Waterwalker - On gossip option select - Close gossip"),
(@ENTRY_AKORU,0,0,0,62,0,100,0,8163,0,0,0,33,@ENTRY_AKORU,0,0,0,0,0,7,0,0,0,0,0,0,0,"Akoru the Firecaller - On Gossip Select - Quest Credit The Dreghood Elders"),
(@ENTRY_AKORU,0,1,0,62,0,100,0,8163,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Akoru the Firecaller - On gossip option select - Close gossip"),
(@ENTRY_MOROD,0,0,0,62,0,100,0,8162,0,0,0,33,@ENTRY_MOROD,0,0,0,0,0,7,0,0,0,0,0,0,0,"Morod the Windstirrer - On Gossip Select - Quest Credit The Dreghood Elders"),
(@ENTRY_MOROD,0,1,0,62,0,100,0,8162,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Morod the Windstirrer - On gossip option select - Close gossip");

-- Only show first gossip if player is on quest The Dreghood Elders
DELETE FROM `conditions` WHERE `SourceGroup` IN (8161,8163,8162) AND `ConditionValue1` IN (10368);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8161,0,0,9,10368,0,0,0,'',"Only show gossip if player is on quest The Dreghood Elders"),
(15,8163,0,0,9,10368,0,0,0,'',"Only show gossip if player is on quest The Dreghood Elders"),
(15,8162,0,0,9,10368,0,0,0,'',"Only show gossip if player is on quest The Dreghood Elders");
