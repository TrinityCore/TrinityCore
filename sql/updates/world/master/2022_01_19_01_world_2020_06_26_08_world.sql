--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4546 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4546,2,0,1,46,0,100,0,4546,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Sylvanaar) - On Trigger - Store Targetlist"),
(4546,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,21469,0,0,0,0,0,0,0,"Areatrigger (Sylvanaar) - On Link - Send Target 1 (Daranelle)"),
(4546,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,21469,0,0,0,0,0,0,0,"Areatrigger (Sylvanaar) - On Link - Set Data 0 1 (Daranelle)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4546;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4546,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4546 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4546,2,0,1,0,36904,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player does have aura 'Lashh'an Channeling'"),
-- Nothing will happen without the guardian https://youtu.be/ckevGJXt-sk?t=45
(22,1,4546,2,0,29,0,21468,20,0,0,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Kaliri Totem' is near");

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 21469;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21469 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21469,0,0,1,38,0,100,0,0,1,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Daranelle - On Data Set 0 1 - Say Line 0"),
(21469,0,1,2,61,0,100,0,0,0,0,0,0,11,37028,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Daranelle - On Link - Cast 'Dispelling Analysis'"),
(21469,0,2,0,61,0,100,0,0,0,0,0,0,11,37013,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daranelle - On Link - Cast 'Despawn Kaliri Totem'");

-- Spawned only by Effect 2 (Spell 36904)
DELETE FROM `event_scripts` WHERE `id` = 12890;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 37013;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,37013,0,0,31,0,3,21468,0,0,0,0,"","Group 0: Spell 'Despawn Kaliri Totem' targets creature 'Kaliri Totem'");

DELETE FROM `spell_scripts` WHERE `id` = 37013;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(37013,0,0,18,1000,0,0,0,0,0,0);
