-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=17984;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (180916,180919,180920);
DELETE FROM `smart_scripts` WHERE `entryorguid`=17984 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (180916,180919,180920) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17984,0,0,0,1,0,100,0,1000,2000,1000,2000,0,11,31628 ,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Power Source Invisible Bunny - ooc - Cast Green Beam"),
(180916,1,0,0,70,0,100,0,2,0,0,0,0,51,0 ,0,0,0,0,0,19,17984,2,0,0,0,0,0,0,"Duskwither Spire Power Source - Goc activatd - Kill target"),
(180919,1,0,0,70,0,100,0,2,0,0,0,0,51,0 ,0,0,0,0,0,19,17984,2,0,0,0,0,0,0,"Duskwither Spire Power Source - Goc activatd - Kill target"),
(180920,1,0,0,70,0,100,0,2,0,0,0,0,51,0 ,0,0,0,0,0,19,17984,2,0,0,0,0,0,0,"Duskwither Spire Power Source - Goc activatd - Kill target");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=31628;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`, `ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`,`NegativeCondition`) VALUES
(13,1,31628,0,31,0,3,17984,63692,0, '', 'Green Beam',0),
(13,1,31628,0,31,1,3,17984,63692,0, '', 'Green Beam',1),
(13,1,31628,1,31,0,3,17984,63696,0, '', 'Green Beam',0),
(13,1,31628,1,31,1,3,17984,63696,0, '', 'Green Beam',1),
(13,1,31628,2,31,0,3,17984,96572,0, '', 'Green Beam',0),
(13,1,31628,2,31,1,3,17984,96572,0, '', 'Green Beam',1);

DELETE FROM `creature` WHERE `guid` IN (96572,96573,96579);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(96572, 17984, 530, 1, 1, 0, 0, 9336.03, -7884.33, 161.585, 6.03884, 30, 0, 0, 4120, 0, 0),
(96573, 17984, 530, 1, 1, 0, 0, 9347.22, -7892.33, 161.811, 2.52099, 30, 0, 0, 4120, 0, 0),
(96579, 17984, 530, 1, 1, 0, 0, 9326.99, -7894.44, 161.651, 0.84171, 30, 0, 0, 4120, 0, 0);
  
DELETE FROM `gameobject` WHERE `guid` IN (7076,7077);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(7076, 182092, 530, 1, 1, 9326.8, -7894.62, 161.72, 5.86431, 0, 0, -0.207912, 0.978148, 300, 100, 1),
(7077, 182092, 530, 1, 1, 9347.3, -7892.57, 161.727, 0.174532, 0, 0, 0.0871553, 0.996195, 300, 100, 1);

UPDATE `creature` SET `spawntimesecs`=30 WHERE `id`=17984;
UPDATE `spell_dbc` SET `effectimplicittargeta1`=25, `rangeindex`=12 WHERE `Id` IN (34448, 34452);
UPDATE `spell_scripts` SET `datalong2`=2 WHERE `Id` IN (34448, 34452);
