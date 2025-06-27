-- A Friendly Chat... (24576, 24657)
-- Snivel Rustrocket set gossip flag
UPDATE `creature_template` SET `npcflag` = 1, `AIName`='SmartAI' WHERE `entry` = 37715;

-- Quest credit SAI
DELETE FROM `smart_scripts` WHERE (`entryorguid`=37715 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37715,0,0,0,62,0,100,0,10946,0,0,0,11,70646,2,0,0,0,0,7,0,0,0,0,0,0,0, "Snivel Rustrocket - on gosip 10947 - cast Love - Create Snivel's Ledger");

-- Gossip option conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=10929);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10929,0,0,9,24576,0,0,0,'','Show gossip only if plaer have A Friendly Chat... Horde quest'),
(15,10929,0,1,9,24657,0,0,0,'','Show gossip only if plaer have A Friendly Chat... Alliance quest');
