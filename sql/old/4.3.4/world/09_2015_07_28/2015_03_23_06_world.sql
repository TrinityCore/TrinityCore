--
SET @CGUID := 45834; -- 1 free guid set by TC
SET @Triggger:=21321;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 21321, 530, 1, 1, 1316.625854, 6689.878418, -18.672377, 0.160565, 0, 0, 0);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (36587);
INSERT INTO `spell_linked_spell` VALUES 
(36587, 36573, 0, 'Vision Guide');

UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`= 2 WHERE `entry` IN (@Triggger);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Triggger AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Triggger,0,0,1,10,0,100,0,1,10,5000,5000,15,10525,0,0,0,0,0,7,0,0,0,0,0,0,0,'Triggger - LOS - AREAEXPLOREDOREVENTHAPPENS'),
(@Triggger,0,1,0,61,0,100,0,0,0,0,0,28,36573,0,0,0,0,0,7,0,0,0,0,0,0,0,'Triggger - LOS - remove aura'),
(@Triggger,0,2,0,63,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Triggger - Just created - Set invisible');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@Triggger;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Triggger,0,1,36573,1,0,0,'','event require Aura 36573');
