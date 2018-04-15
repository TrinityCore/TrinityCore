UPDATE `creature_template` SET `AIName`='SmartAI',`InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=38557;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=38558;

SET @GUID := 137784;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID+0 AND @GUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,38558,631,15,1,0,0,4637.27,2786.25,424.639,3.57357,604800,0,0,0,0,0,0,0,0,0), -- Infiltrator Minchar
(@GUID+1,38557,631,15,1,0,0,4642.60,2771.61,412.227,0.00000,604800,0,0,0,0,0,0,0,0,0), -- left leg
(@GUID+2,38557,631,15,1,0,0,4630.34,2799.74,412.512,0.00000,604800,0,0,0,0,0,0,0,0,0), -- right leg
(@GUID+3,38557,631,15,1,0,0,4630.73,2802.02,437.672,0.00000,604800,0,0,0,0,0,0,0,0,0), -- right arm
(@GUID+4,38557,631,15,1,0,0,4645.42,2771.67,436.146,0.00000,604800,0,0,0,0,0,0,0,0,0); -- left arm

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN -(@GUID+4) AND -(@GUID+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-(@GUID+1),0,0,0,25,0,100,0,0,0,0,0,11,72302,3,0,0,0,0,10,@GUID,0,0,0,0,0,0, 'Minchar Beam Stalker - Channel beam'),
(-(@GUID+2),0,0,0,25,0,100,0,0,0,0,0,11,72301,3,0,0,0,0,10,@GUID,0,0,0,0,0,0, 'Minchar Beam Stalker - Channel beam'),
(-(@GUID+3),0,0,0,25,0,100,0,0,0,0,0,11,72304,3,0,0,0,0,10,@GUID,0,0,0,0,0,0, 'Minchar Beam Stalker - Channel beam'),
(-(@GUID+4),0,0,0,25,0,100,0,0,0,0,0,11,72303,3,0,0,0,0,10,@GUID,0,0,0,0,0,0, 'Minchar Beam Stalker - Channel beam');

DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID,0,0x03000000,1,427, ''); -- Infiltrator Minchar

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=71322;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,71322,0,18,1,38558,0,0, '', 'Blood-Queen Lana''thel - Annihilate Minchar');
