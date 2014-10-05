UPDATE `creature_template` SET `ScriptName`='boss_occuthar' WHERE `entry`=52363;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction_A`=14,`faction_H`=14,`ScriptName`='npc_eyestalk',`flags_extra`=128 WHERE `entry`=52369;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction_A`=14,`faction_H`=14,`ScriptName`='' WHERE `entry`=52389;
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=52368;

UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=52369;
UPDATE `creature_template` SET `unit_flags`=2048 WHERE `entry`=52389;

DELETE FROM `creature_template_addon` WHERE `entry`=52389;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(52389, 0, 0x0, 0x1, '96995');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (96872,96931,96932,96942,101009);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(96872 ,'spell_occuthar_focused_fire'),
(96931 ,'spell_occuthar_eyes_of_occuthar'),
(96932 ,'spell_occuthar_eyes_of_occuthar_vehicle'),
(96942 ,'spell_occuthar_occuthars_destruction'),
(101009 ,'spell_occuthar_occuthars_destruction');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=96931;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,96931,0,0,31,0,3,52368,0,0,0,'','');

DELETE FROM `creature` WHERE `id`=52368;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=52363;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(52363, 46598, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=52363;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(52363, 52368, 0, 1, 'Occu''thar - Eyestalk (Seat 1)', 8, 0),
(52363, 52368, 1, 1, 'Occu''thar - Eyestalk (Seat 2)', 8, 0),
(52363, 52368, 2, 1, 'Occu''thar - Eyestalk (Seat 3)', 8, 0),
(52363, 52368, 3, 1, 'Occu''thar - Eyestalk (Seat 4)', 8, 0),
(52363, 52368, 4, 1, 'Occu''thar - Eyestalk (Seat 5)', 8, 0),
(52363, 52368, 5, 1, 'Occu''thar - Eyestalk (Seat 6)', 8, 0),
(52363, 52368, 6, 1, 'Occu''thar - Eyestalk (Seat 7)', 8, 0);
