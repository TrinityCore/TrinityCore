SET @GUID:=69717; -- 3 free Gob guid set by TC
SET @WESTERN_TP := 22348;
SET @EASTERN_TP := 22351;
SET @CENTRAL_TP := 22350;
SET @Teleporter := 185215;

DELETE FROM `gameobject` WHERE `guid` IN (@GUID+0, @GUID+1, @GUID+2);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID+0, @Teleporter, 530, 1, 1, 4697.5, 3298.68, 178.892, 2.02823, 0, 0, 0.849013, 0.528372, 120, 0, 1),
(@GUID+1, @Teleporter, 530, 1, 1, 4734.71, 3193.67, 161.48, 0.386745, 0, 0, 0.19217, 0.981362, 120, 0, 1),
(@GUID+2, @Teleporter, 530, 1, 1, 4673.28, 3126.67, 166.725, 5.42979, 0, 0, 0.413867, -0.910337, 120, 0, 1);

UPDATE `creature_template` SET `spell2`=36255,`spell3`=8599,`spell4`=38920 WHERE `entry`=16943;
UPDATE `creature_template` SET `spell2`=37179,`spell3`=36251,`spell4`=38920 WHERE `entry`=20928;
UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=33555200, `flags_extra`=130 WHERE `entry` IN (@CENTRAL_TP, @EASTERN_TP, @WESTERN_TP);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (20928);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-70125,-70122,-70124,-70126,-70123,-70116,-70115,-70117,-70118,-70119,-70128,-70127,-70121,-70120, -70131, -70130, -70129, -70112, -70113, -70114, -70132, -70133, -70135, -70134, -70138, -70136, -70139, -70137) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@WESTERN_TP, @EASTERN_TP, @CENTRAL_TP, 20928) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16943) AND `source_type`=0 AND id IN (3,4,5);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WESTERN_TP,0,0,0,8,0,100,0,38920,0,0,0,45,0,1,0,0,0,0,7,0,0,0,0,0,0,0,"WESTERN_TP - On spell hit - SET data"),
(@EASTERN_TP,0,1,0,8,0,100,0,38920,0,0,0,45,0,2,0,0,0,0,7,0,0,0,0,0,0,0,"EASTERN_TP - On spell hit - SET data"),
(@CENTRAL_TP,0,2,0,8,0,100,0,38920,0,0,0,45,0,3,0,0,0,0,7,0,0,0,0,0,0,0,"CENTRAL_TP - On spell hit - SET data"),
(16943,0,3,0,38,0,100,0,0,1,0,0,86,38982,0,23,0,0,0,1,0,0,0,0,0,0,0,"16943 - On data set - Cast Credit"),
(16943,0,4,0,38,0,100,0,0,2,0,0,86,38983,0,23,0,0,0,1,0,0,0,0,0,0,0,"16943 - On data set - Cast Credit"),
(16943,0,5,0,38,0,100,0,0,3,0,0,86,38984,0,23,0,0,0,1,0,0,0,0,0,0,0,"16943 - On data set - Cast Credit"),
(20928,0,0,0,0,0,100,0,1000,1000,7000,9000,11,37179,0,0,0,0,0,2,0,0,0,0,0,0,0,"20928 - IC- Cast"),
(20928,0,1,0,0,0,100,0,4000,4000,5000,5000,11,36251,0,0,0,0,0,2,0,0,0,0,0,0,0,"20928 - IC- Cast"),
(20928,0,2,0,4,0,100,0,0,0,0,0,11,33962,0,0,0,0,0,1,0,0,0,0,0,0,0,"20928 - On Aggro - Cast"),
(20928,0,3,0,38,0,100,0,0,1,0,0,86,38982,0,23,0,0,0,1,0,0,0,0,0,0,0,"20928 - On data set - Cast Credit"),
(20928,0,4,0,38,0,100,0,0,2,0,0,86,38983,0,23,0,0,0,1,0,0,0,0,0,0,0,"20928 - On data set - Cast Credit"),
(20928,0,5,0,38,0,100,0,0,3,0,0,86,38984,0,23,0,0,0,1,0,0,0,0,0,0,0,"20928 - On data set - Cast Credit"),
(-70115,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70116,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70118,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70116,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70117,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70116,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70119,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70120,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70128,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70120,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70121,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70120,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70127,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70126,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70123,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70122,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70123,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70124,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70123,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70125,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70114,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70132,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70133,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,1,0,0,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70129,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70131,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70130,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70129,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70131,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70130,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70113,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70112,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70112,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70113,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70135,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70137,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70134,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70137,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70138,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70137,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70136,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70137,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target'),
(-70139,0,0,0,1,0,100,1,0,0,0,0,11,33346,64,0,0,0,0,10,70137,19656,0,0,0,0,0,'Invisible Location Trigger - OOC no repeat - Cast Green Beam on target');

DELETE FROM `conditions` WHERE `SourceEntry`=38920 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(13,7,38920,0,1,31,0,3,@WESTERN_TP,0,0,0,'', 'Detonate all 3 implicit effects can hit western teleporter'),
(13,7,38920,0,2,31,0,3,@EASTERN_TP,0,0,0,'', 'Detonate all 3 implicit effects can hit eastern teleporter'),
(13,7,38920,0,3,31,0,3,@CENTRAL_TP,0,0,0,'', 'Detonate all 3 implicit effects can hit central teleporter');

DELETE FROM `conditions` WHERE `SourceEntry`=38915 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(17,0,38915,0,1,31,1,3,16943,0,0,0,'', 'Mental interference target can be Cyber-Rage Forgelord'),
(17,0,38915,0,2,31,1,3,20928,0,0,0,'', 'Mental interference target can be Ironspine Forgelord');
