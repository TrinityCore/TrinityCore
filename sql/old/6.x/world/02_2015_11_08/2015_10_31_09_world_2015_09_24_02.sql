-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `Entry` IN (29698, 26043);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29698, 26043) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29698,0,0,0,4,0,100,0,0,0,0,0,11,54487,0,0,0,0,0,2,0,0,0,0,0,0,0,'Drakuru Raptor - On aggro - Cast Jump Attack'),
(26043,0,0,0,1,0,100,0,2000,8000,8000,15000,11,46400,0,0,0,0,0,1,0,0,0,0,0,0,0,'Steam Burst - OOC - Cast Steam Weapon');

UPDATE `creature_equip_template` SET `ItemID1`=21573, `ItemID2`=143 WHERE `creatureid`=27160;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `Entry`=27375;

DELETE FROM `creature_template_addon` WHERE `entry`= 27268;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES (27268,0,0,1,48553);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13) AND `SourceEntry`=48551;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(13, 1, 48551, 0, 31, 3, 27375, 0, 0, '', 'Vengeful Stormhammer only on Risen Gryphon Rider Target', 0);

DELETE FROM `creature_addon` WHERE `guid`= 86097;
DELETE FROM `waypoint_data` WHERE `id`= 860970;
