UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '260718'; 
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '267528'; 
DELETE FROM `gameobject` WHERE `id`=207416;
UPDATE `spell_target_position` SET `MapID` = '730' , `PositionX` = '852.306' , `PositionY` = '1038.92' , `PositionZ` = '-5.3136' WHERE `ID` = '84464' AND `EffectIndex` = '0'; 
UPDATE `spell_target_position` SET `PositionX` = '854' , `PositionY` = '1075' , `PositionZ` = '-11.392230' WHERE `ID` = '84464' AND `EffectIndex` = '0'; 


DELETE FROM `creature` WHERE `id`=43818;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116797, 43818, 646, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1027.85, 516.63, -49.3336, 2.61803, 300, 0, 0, 38640, 8726, 0, 0, 0, 0, 0, 0, '', 0);










































