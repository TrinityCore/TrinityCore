DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=64799; -- Lightning Tether
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,64799,0,0,31,0,3,33293,0,0,0,0,'','Effect_0 hits XT002');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_xt002_exposed_heart',
'spell_xt002_energy_orb');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63849,'spell_xt002_exposed_heart'),
(62826,'spell_xt002_energy_orb');

DELETE FROM `spell_proc` WHERE `SpellId`=63849; -- Disable spell proc to effect_1
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(63849,0,0,0,0,0,0,0,0,0,32,0,0,0,0);

UPDATE `creature` SET `MovementType`=0, `Spawndist`=0 WHERE `id`=33337; -- XT-Toy Pile

UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=0.428571, `ScriptName`='npc_scrapbot' WHERE `entry`=33343;
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=0.428571 WHERE `entry`=33887; -- Scrapbot
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=0.428571, `modelid2`=0, `modelid3`=0 WHERE `entry` IN (33346,33886); -- Boombot
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry` IN (33293,33885); -- XT-002 Deconstructor (hi ariel, I stole from you xD)
UPDATE `creature_template` SET `mechanic_immune_mask`=617299839 WHERE `entry` IN (33329,33885); -- Heart mechanical immunities xD

DELETE FROM `waypoint_scripts` WHERE `id` IN(2,5);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(2,0,1,468,1,0,0,0,0,0,1360540),
(2,11,1,0,1,0,0,0,0,0,1360541),
(5,0,1,10,1,0,0,0,0,0,1360542),
(5,30,1,0,1,0,0,0,0,0,1360543);

DELETE FROM `waypoint_data` WHERE `id`=1360540;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1360540, 1, 862.5053, 7.207682, 409.8612, 0, 0, 0, 0, 100, 0),
(1360540, 2, 863.4635, 25.65489, 409.8612, 0, 0, 0, 0, 100, 0),
(1360540, 3, 872.6903, 39.44819, 409.8355, 0, 11000, 0, 2, 100, 0), -- emote 468 11s
(1360540, 4, 869.8901, 32.82189, 409.8509, 0, 0, 0, 0, 100, 0),
(1360540, 5, 854.8365, 9.631022, 409.8612, 0, 0, 0, 0, 100, 0),
(1360540, 6, 855.48, -19.90913, 409.8787, 0, 0, 0, 0, 100, 0),
(1360540, 7, 852.1145, -44.87088, 409.8869, 0, 0, 0, 0, 100, 0),
(1360540, 8, 864.5853, -62.56917, 409.6369, 0, 0, 0, 0, 100, 0),
(1360540, 9, 876.4196, -77.23026, 409.9155, 0, 11000, 0, 2, 100, 0), -- emote 468 11s
(1360540, 10, 878.3914, -79.4183, 409.9155, 0, 0, 0, 0, 100, 0),
(1360540, 11, 870.9197, -65.75331, 409.9155, 0, 0, 0, 0, 100, 0),
(1360540, 12, 880.2524, -33.8488, 409.9155, 0, 0, 0, 0, 100, 0),
(1360540, 13, 883.6281, -12.63596, 409.799, 3.159046, 30000, 0, 5, 100, 0); -- emote 10 30s
