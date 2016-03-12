SET @Oguid=5638;  -- 2 free Gob guid set by TC
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (3746, 3766);
INSERT INTO `areatrigger_scripts` VALUES (3746,'SmartTrigger'), (3766,'SmartTrigger');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3746, 3766) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3746, 2, 0, 0, 46, 0, 100, 0, 3746, 0, 0, 0, 70, 7200, 0, 0, 0, 0, 0, 14, @Oguid+1, 180024, 0, 0, 0, 0, 0, 'Area Trigger 3746 - On Trigger - Respawn Mysterious Deadmines Chest'),
(3766, 2, 0, 0, 46, 0, 100, 0, 3766, 0, 0, 0, 70, 7200, 0, 0, 0, 0, 0, 14, @Oguid, 180055, 0, 0, 0, 0, 0, 'Area Trigger 3746 - On Trigger - Respawn Mysterious Wailing Caverns');
DELETE FROM `gameobject` WHERE `id` IN (180055, 180024);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@Oguid,180055,43,1,1,-97.6,173.8,-79,2.08,0,0,0.862404,0.50622,-1,100,1),
(@Oguid+1,180024,36,1,1,-32.1232,-374.64,59.06,3.0820,0,0,0.879275,-0.476315,-1,100,1); 
DELETE FROM `gameobject_questender` WHERE `id`=180055 AND `quest`=7944;
INSERT INTO `gameobject_questender` (`id`,`quest`) VALUES (180055,7944);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (3766,3746) AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,3746,2,0,28,0,7938,0,0,0,0,'','SAI areatrigger 3746 triggers only if player has the quest 7938'),
(22,1,3766,2,0,28,0,7944,0,0,0,0,'','SAI areatrigger 3766 triggers only if player has the quest 7944');
