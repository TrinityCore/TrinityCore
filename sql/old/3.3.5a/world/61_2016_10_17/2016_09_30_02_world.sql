--
SET @GUID := 94777;
DELETE FROM `creature` WHERE `id` IN (25090, 25091, 25092);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@GUID   , 25090, 530, 0, 0, 1, 1, 0, 0, 13199.25, -7050.695, 14.45722, 3.700098, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+1 , 25090, 530, 0, 0, 1, 1, 0, 0, 13196.12, -7049.336, 16.22812, 0.8552113, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+2 , 25090, 530, 0, 0, 1, 1, 0, 0, 13274.6, -7057.694, 24.88402, 0.2443461, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+3 , 25090, 530, 0, 0, 1, 1, 0, 0, 13207.01, -7053.201, 15.47437, 2.740167, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+4 , 25090, 530, 0, 0, 1, 1, 0, 0, 13202.56, -7051.397, 16.39847, 4.18879, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+5 , 25090, 530, 0, 0, 1, 1, 0, 0, 13235.61, -7053.926, 15.1975, 5.934119, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+6 , 25090, 530, 0, 0, 1, 1, 0, 0, 13240.7, -7053.23, 14.11119, 4.974188, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+7 , 25090, 530, 0, 0, 1, 1, 0, 0, 13242.16, -7054.788, 17.20347, 4.764749, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+8 , 25091, 530, 0, 0, 1, 1, 0, 0, 13321.43, -6992.023, 15.16358, 1.850049, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+9 , 25091, 530, 0, 0, 1, 1, 0, 0, 13330.63, -6993.74, 18.55262, 0.4537856, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+10, 25091, 530, 0, 0, 1, 1, 0, 0, 13312.74, -6989.042, 16.80069, 3.036873, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+11, 25092, 530, 0, 0, 1, 1, 0, 0, 13332.46, -7149.989, 25.6237, 3.455752, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+12, 25092, 530, 0, 0, 1, 1, 0, 0, 13308.78, -7147.535, 14.74447, 2.6529, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+13, 25092, 530, 0, 0, 1, 1, 0, 0, 13276.29, -7148.312, 18.78717, 5.253441, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+14, 25092, 530, 0, 0, 1, 1, 0, 0, 13323.89, -7149.331, 23.59076, 0.3316126, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+15, 25092, 530, 0, 0, 1, 1, 0, 0, 13315.08, -7149.389, 15.7673, 4.066617, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+16, 25092, 530, 0, 0, 1, 1, 0, 0, 13306.4, -7148.456, 19.44827, 6.126106, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+17, 25092, 530, 0, 0, 1, 1, 0, 0, 13273.84, -7146.333, 11.37591, 0.3141593, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+18, 25092, 530, 0, 0, 1, 1, 0, 0, 13285.6, -7150.727, 20.10993, 5.113815, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007),
(@GUID+19, 25092, 530, 0, 0, 1, 1, 0, 0, 13323.48, -7150.049, 19.51648, 2.251475, 300, 0, 0, 42, 0, 0, 0, 0, 0, 14007);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (25090, 25091, 25092);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25090, 25091, 25092);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25090, 0, 0, 1, 8, 0, 100, 0, 45115, 0, 0, 0, 33, 25090, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Sin'Loren Credit - On Spellhit 'Quest - Sunwell Daily - Ship Bombing Run Bomb' - Give Kill Credit"),
(25090, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 9, 25090, 0, 200, 0, 0, 0, 0, "Sin'Loren Credit - On Spellhit 'Quest - Sunwell Daily - Ship Bombing Run Bomb' - Set Data to nearby creatures"),
(25090, 0, 2, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 73119, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sin'Loren Credit - On Data Set - Cast spell '[DND] Fire Visual'"),
(25091, 0, 0, 1, 8, 0, 100, 0, 45115, 0, 0, 0, 33, 25091, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodoath Credit - On Spellhit 'Quest - Sunwell Daily - Ship Bombing Run Bomb' - Give Kill Credit"),
(25091, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 9, 25091, 0, 200, 0, 0, 0, 0, "Bloodoath Credit - On Spellhit 'Quest - Sunwell Daily - Ship Bombing Run Bomb' - Set Data to nearby creatures"),
(25091, 0, 2, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 73119, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodoath Credit - On Data Set - Cast spell '[DND] Fire Visual'"),
(25092, 0, 0, 1, 8, 0, 100, 0, 45115, 0, 0, 0, 33, 25092, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Dawnchaser Credit - On Spellhit 'Quest - Sunwell Daily - Ship Bombing Run Bomb' - Give Kill Credit"),
(25092, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 9, 25092, 0, 200, 0, 0, 0, 0, "Dawnchaser Credit - On Spellhit 'Quest - Sunwell Daily - Ship Bombing Run Bomb' - Set Data to nearby creatures"),
(25092, 0, 2, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 73119, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dawnchaser Credit - On Data Set - Cast spell '[DND] Fire Visual'");

UPDATE `conditions` SET `ConditionTypeOrReference`=28 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9143;
UPDATE `conditions` SET `Comment`="Show gossip option if player has quest 11542 complete OR" WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9143 AND `ElseGroup`=0;
UPDATE `conditions` SET `Comment`="Show gossip option if player has quest 11543 complete" WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9143 AND `ElseGroup`=1;
