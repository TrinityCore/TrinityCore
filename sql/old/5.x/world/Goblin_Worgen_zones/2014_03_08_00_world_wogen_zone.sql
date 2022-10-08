DELETE FROM `creature` WHERE (`guid`='1390044');

DELETE FROM `gameobject` WHERE (`guid`='173896');
DELETE FROM `gameobject` WHERE (`guid`='173895');

DELETE FROM `spell_area` WHERE (`spell`='59073') AND (`area`='4756') AND (`quest_start`='14091') AND (`aura_spell`='0') AND (`racemask`='0') AND (`gender`='2');
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) 
VALUES 
('59073', '4756', '14091', '14093', '0', '0', '2', '1', '64', '11');

DELETE FROM `spell_area` WHERE (`spell`='59073') AND (`area`='4757') AND (`quest_start`='14099') AND (`aura_spell`='0') AND (`racemask`='0') AND (`gender`='2');
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `autocast`, `quest_start_status`) 
VALUES 
('59073', '4757', '14099', '1', '66');

DELETE FROM `spell_area` WHERE (`spell`='59073') AND (`area`='4755') AND (`quest_start`='14099') AND (`aura_spell`='0') AND (`racemask`='0') AND (`gender`='2');
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES ('59073', '4755', '14099', '0', '0', '0', '2', '1', '66', '11');

DELETE FROM `spell_area` WHERE `spell`='59074' AND `area`='4757' 
AND `quest_start` in (14280, 14275, 14277, 14278, 14269, 14273, 14265); 
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `autocast`, `quest_start_status`) 
VALUES 
('59074', '4757', '14280', '1', '66'),
('59074', '4757', '14275', '1', '66'),
('59074', '4757', '14277', '1', '66'),
('59074', '4757', '14278', '1', '66'),
('59074', '4757', '14269', '1', '66'),
('59074', '4757', '14273', '1', '66'),
('59074', '4757', '14265', '1', '66');

DELETE FROM `spell_area` WHERE `spell`='59074' AND `area`='4714' AND `quest_start` in (14280, 14275, 14277, 14278, 14269, 14273, 14265); 
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `autocast`, `quest_start_status`) 
VALUES 
('59074', '4714', '14280', '1', '66'),
('59074', '4714', '14275', '1', '66'),
('59074', '4714', '14277', '1', '66'),
('59074', '4714', '14278', '1', '66'),
('59074', '4714', '14269', '1', '66'),
('59074', '4714', '14273', '1', '66'),
('59074', '4714', '14265', '1', '66');

UPDATE `quest_template` SET `RewardSpell`='0' WHERE (`Id`='14078');
UPDATE `quest_template` SET `RewardSpell`='0' WHERE (`Id`='14099');
UPDATE `quest_template` SET `PrevQuestId`='14091' WHERE (`Id`='14091');
UPDATE `quest_template` SET `RequiredSpellCast1`='172' WHERE (`Id`='14274');
UPDATE `quest_template` SET `ZoneOrSort`='4755', `RequiredRaces`='0' WHERE (`Id`='14281');

UPDATE `quest_template` SET `PrevQuestId`='24930' WHERE (`Id`='14157');
UPDATE `quest_template` SET `RewardSpell` = 0 WHERE `Id` = 14221;
UPDATE `quest_template` SET `RewardSpell` = 0 WHERE `Id` = 14375;

DELETE FROM `spell_area` WHERE (`spell`='59074') AND (`area`='4762') AND (`quest_start`='14157') AND (`aura_spell`='0') AND (`racemask`='0') AND (`gender`='2');
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES ('59074', '4762', '14157', '0', '0', '0', '2', '0', '66', '11');

UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 44468;
UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 44465;
UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 44461;
UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 44469;
UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 44455;

UPDATE `gameobject` SET `spawnMask` = 1, `phaseMask` = 4 WHERE `guid` = 522372;


UPDATE `creature` SET `phaseMask` = 4 WHERE `guid` = 1367920;
UPDATE `quest_template` SET `RewardSpell` = 0 WHERE `Id` = 14321;
UPDATE `gameobject` SET `phaseMask` = 14 WHERE `guid` = 522342;

DELETE FROM `creature` WHERE `guid`=329292 AND id=36451;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`) 
VALUES 
('329292', '36451', '655', '1', '4', '-1894.86', '2524.09', '1.66469', '4.4528', '300', '293405');


DELETE FROM `quest_start_scripts` WHERE (`id`=14396 AND `command`=6);
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('14396', '10', '6', '655', '-1875.83', '2529.92', '-6.46165', '3.99403');
UPDATE `quest_template` SET `RewardSpellCast`='0', `SourceSpellId`='69027' ,`StartScript`='14396' WHERE (`Id`='14396');

-- Quest hack Fix Gasping for Breath
UPDATE `quest_template` SET `RequiredSpellCast1` = 68735 WHERE `Id` = 14395;
UPDATE `creature_template` SET `npcflag` = 16777216, `KillCredit1`='36450' WHERE `entry` = 36440;
DELETE FROM `creature_template_addon` WHERE (`entry`=36440);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (36440, 0, 0, 0, 0, 0, 68730);

DELETE FROM `npc_spellclick_spells` WHERE (`npc_entry`='36440') AND (`spell_id`='68735');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('36440', '68735', '1', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) 
VALUES 
(NULL, '36440', '655', '4714', '4714', '1', '14', '0', '0', '-1927.14', '2539.81', '-2.94776', '5.04014', '300', '0', '0', '1020', '0', '0', '0', '0', '0', '0');

DELETE FROM `creature_template_addon` WHERE (`entry`=36452);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (36452, '', 238, 0, 0, 0, '');


DELETE FROM `creature` WHERE `id` IN (36452,36458,36457);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) 
VALUES 
(NULL, '36452', '655', '4714', '4786', '1', '14', '0', '0', '-1862.44', '2293.23', '42.2586', '1.16874', '300', '0', '0', '198', '0', '0', '0', '0', '0', '0'),
(NULL, '36458', '655', '4714', '4806', '1', '14', '0', '0', '-2116.55', '2416.75', '12.1852', '3.64903', '300', '0', '0', '102', '0', '0', '0', '0', '0', '0'),
(NULL, '36457', '655', '4714', '4807', '1', '14', '0', '0', '-2059.97', '2254.66', '22.4735', '1.43575', '300', '0', '0', '102', '0', '0', '0', '0', '0', '0'),
(NULL, '36456', '655', '4714', '4808', '1', '12', '0', '0', '-2300.19', '2277.61', '0.406684', '3.60804', '300', '0', '0', '685', '0', '0', '0', '0', '0', '0');

DELETE FROM `creature` WHERE `id` IN (36488,36492,36491,36455,36454);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) 
VALUES
('334750', '36488', '655', '0', '0', '1', '14', '0', '0', '-2359.59', '2266.58', '1.63185', '1.20598', '300', '0', '0', '137', '0', '0', '0', '0', '0', '0'),
('334804', '36488', '655', '0', '0', '1', '14', '0', '0', '-2329.34', '2260.61', '0.518103', '0.489907', '300', '0', '0', '120', '0', '0', '0', '0', '0', '0'),
('334805', '36488', '655', '0', '0', '1', '14', '0', '0', '-2361.02', '2287.46', '0.914321', '0.1137', '300', '0', '0', '137', '0', '0', '0', '0', '0', '0'),
('334806', '36488', '655', '0', '0', '1', '14', '0', '0', '-2322.82', '2329.23', '4.74896', '5.7073', '300', '0', '0', '137', '0', '0', '0', '0', '0', '0'),
('334807', '36488', '655', '0', '0', '1', '14', '0', '0', '-2337.45', '2321.53', '1.56221', '5.42456', '300', '0', '0', '137', '0', '0', '0', '0', '0', '0'),
('334869', '36488', '655', '0', '0', '1', '14', '0', '0', '-2329.46', '2280.88', '0.276829', '6.02128', '300', '0', '0', '42', '0', '0', '0', '0', '0', '0'),
('334870', '36488', '655', '0', '0', '1', '14', '0', '0', '-2339.7', '2266.34', '0.494633', '0.957033', '300', '0', '0', '42', '0', '0', '0', '0', '0', '0'),
('334871', '36488', '655', '0', '0', '1', '14', '0', '0', '-2336.8', '2304.52', '0.414039', '5.17933', '300', '0', '0', '42', '0', '0', '0', '0', '0', '0'),
('334872', '36488', '655', '0', '0', '1', '14', '0', '0', '-2345.14', '2285.62', '0.346056', '5.9718', '300', '0', '0', '42', '0', '0', '0', '0', '0', '0'),
('335942', '36488', '655', '0', '0', '1', '14', '0', '36488', '-2241.53', '2286.31', '6.88909', '2.17829', '300', '0', '0', '120', '0', '0', '0', '0', '0', '0'),
('335943', '36488', '655', '0', '0', '1', '14', '0', '36488', '-2228.45', '2293.07', '7.12025', '0.173955', '300', '0', '0', '102', '0', '0', '0', '0', '0', '0'),
('335944', '36488', '655', '0', '0', '1', '14', '0', '36488', '-2256.67', '2281.21', '5.71715', '3.2213', '300', '0', '0', '137', '0', '0', '0', '0', '0', '0'),
('335945', '36488', '655', '0', '0', '1', '14', '0', '36488', '-2255.01', '2307.21', '5.38462', '2.66288', '300', '0', '0', '120', '0', '0', '0', '0', '0', '0'),

('334802', '36492', '655', '0', '0', '1', '14', '0', '0', '-2295.28', '2306.42', '-0.0831081', '0.364238', '300', '0', '0', '210', '0', '0', '0', '0', '0', '0'),
('335949', '36492', '655', '0', '0', '1', '14', '0', '36456', '-2327.06', '2302.9', '0.343745', '0.717009', '300', '0', '0', '685', '0', '0', '0', '0', '0', '0'),

('334803', '36491', '655', '0', '0', '1', '14', '0', '0', '-2299.64', '2298.04', '1.6697', '5.80312', '300', '0', '0', '210', '0', '0', '0', '0', '0', '0'),
('335948', '36491', '655', '0', '0', '1', '14', '0', '36456', '-2341.56', '2267.61', '0.44775', '0.916939', '300', '0', '0', '685', '0', '0', '0', '0', '0', '0'),

('334815', '36455', '655', '0', '0', '1', '14', '0', '0', '-2298.91', '2283.66', '1.53899', '4.65959', '300', '0', '0', '210', '0', '0', '0', '0', '0', '0'),
('335947', '36455', '655', '0', '0', '1', '14', '0', '0', '-2299.36', '2279.52', '0.905739', '2.37263', '300', '0', '0', '685', '0', '0', '0', '0', '0', '0'),

('334814', '36454', '655', '0', '0', '1', '14', '0', '0', '-2297.66', '2266.06', '-0.28204', '1.83608', '300', '0', '0', '210', '0', '0', '0', '0', '0', '0'),
('335946', '36454', '655', '0', '0', '1', '14', '0', '36456', '-2318.14', '2294.66', '0.512429', '1.15649', '300', '0', '0', '685', '0', '0', '0', '0', '0', '0');

UPDATE `gameobject` SET `map`='655', `phaseMask`='14' WHERE `id`='196473';
UPDATE `gameobject` SET `map`='655', `phaseMask`='14' WHERE `id`='196472';

UPDATE `creature` SET `map`='655', `phaseMask`='14' WHERE (`id`='36461');

UPDATE `creature` SET `phaseMask`='2' WHERE `id`='36540' AND zoneId=4714 AND areaId=4714;
UPDATE `creature` SET `map`='655', `phaseMask`='14' WHERE `id`='36540' AND zoneId=4714 AND areaId=4818;

-- Koroth the Hillbreaker
UPDATE `creature` SET `map`='655', `phaseMask`='14', `modelid`='33949' WHERE `id`='36294';
UPDATE `creature_template` SET `movementId` = 104 WHERE `entry` = 36294;
UPDATE `creature` SET `map`='655', `phaseMask`='14', `modelid`='33949' WHERE `id`='37808';

-- Mountain Horse
UPDATE `creature_template` SET `VehicleId` = 349 WHERE `entry` = 36540; 

UPDATE `quest_template` SET `NextQuestId` = 14412, `PrevQuestId` = 0 WHERE `Id` = 14404;
UPDATE `quest_template` SET `PrevQuestId` = 14404, `NextQuestId` = 14405, `NextQuestIdChain` = 0 WHERE `Id` = 14412;
UPDATE `quest_template` SET `PrevQuestId` = 14412 WHERE `Id` = 14405;

UPDATE `gameobject` SET `map`='655', `phaseMask`='14' WHERE `id`='196808' AND `areaId`= '4808';
UPDATE `gameobject` SET `map`='655', `phaseMask`='14' WHERE `id`='196809' AND `areaId`= '4808';
UPDATE `gameobject` SET `map`='655', `phaseMask`='14' WHERE `id`='196810' AND `areaId`= '4808';

-- Teleport Gate
DELETE FROM `gameobject_scripts` WHERE `id`=522292;
INSERT INTO `gameobject_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) 
VALUES 
('522293', '0', '6', '654', '0', '0', '-1680.62', '2508.8125', '97.8599', '0.911083');

UPDATE `gameobject` SET `phaseMask` = 15, `map`='655' WHERE `guid` = 522290;
UPDATE `gameobject` SET `phaseMask` = 15, `map`='655', `phaseMask`='14' WHERE `guid`='522293';
UPDATE `gameobject_template` SET `flags` = 16 WHERE `entry` = 196401;


UPDATE `quest_template` SET `RewardSpell` = 0 WHERE `Id` = 14466;

UPDATE `quest_template` SET `StartScript`='24438' WHERE (`Id`='24438');

DELETE FROM `quest_start_scripts` WHERE `id` = 24438 AND `command`=6; 
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('24438', '2', '6', '654', '-2173.178955', '1809.8', '13.143705', '3.197577');

UPDATE `gameobject` SET `phaseMask` = 15 WHERE `guid` = 522610;

UPDATE `gameobject` SET `phaseMask` = 14 WHERE `id` = 201607 AND `map`=654;
UPDATE `creature` SET `phaseMask` = 14 WHERE `id` = 44119 AND map=654;
UPDATE `gameobject` SET `phaseMask` = 14 WHERE `id` = 201914 AND `map`=654;
UPDATE `gameobject` SET `phaseMask` = 14 WHERE `id` = 201939 AND `map`=654;


UPDATE `quest_template` SET `NextQuestId` = 24495 WHERE `Id` = 24484;
UPDATE `quest_template` SET `PrevQuestId` = 24501, `NextQuestId` = 24501 WHERE `Id` = 24495;
UPDATE `quest_template` SET `PrevQuestId` = 24495, `NextQuestId` = 24578 WHERE `Id` = 24501;
UPDATE `quest_template` SET `PrevQuestId` = 24501 WHERE `Id` = 24578;
UPDATE `quest_template` SET `PrevQuestId` = 24578 WHERE `Id` = 24616;

UPDATE `gameobject` SET `phaseMask` = 14 WHERE `map`=654 AND `id` = 201950;
UPDATE `gameobject` SET `phaseMask` = 14 WHERE `map`=654 AND `id` = 201951;
UPDATE `gameobject` SET `phaseMask` = 14 WHERE `map`=654 AND `id` = 201952;

UPDATE `creature` SET `phaseMask` = 14 WHERE `map`= 654 AND `id` = 37735;
UPDATE `creature` SET `phaseMask` = 14 WHERE `map`= 654 AND `id` = 37733;

UPDATE `gameobject` SET `phaseMask` = 14 WHERE `map`=654 AND `id` = 201775;
UPDATE `gameobject_template` SET `flags` = 2, `data5` = 1 WHERE `entry` = 201775;

UPDATE `creature_template` SET `spell1` = 6660, `spell2` = 15496 WHERE `entry` = 37784;

DELETE FROM `quest_start_scripts` WHERE `id` = 24904 AND `command`=6;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES 
('24904', '10', '6', '654', '-1659', '1600.16', '23.1314', '4.1205');

UPDATE `quest_template` SET `StartScript`='24904' WHERE (`Id`='24904');
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 0, `RequiredNpcOrGoCount1` = 0 WHERE `Id` = 24904;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`='-15' WHERE (`entry`='37884') AND (`item`='49921');

UPDATE `gameobject` SET `phaseMask` = 2 WHERE `guid` = 522356;
UPDATE `gameobject` SET `phaseMask` = 2 WHERE `guid` = 522357;
UPDATE `gameobject` SET `phaseMask` = 2 WHERE `guid` = 522355;

-- quest 24681 
UPDATE `creature_template` SET `VehicleId` = 337, `npcflag` = 16777216 WHERE `entry` = 38150;
-- Spell Ride Vehicle
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= '38150' AND `spell_id`='68503';
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES ('38150', '68503', '1');

UPDATE `creature_template` SET `VehicleId` = 337, `minlevel` = 12, `maxlevel` = 12 WHERE `entry` = 37927;
UPDATE `creature_template` SET `spell1` = 66456, `spell3` = 67195, `spell4` = 0, `spell5` = 59737 WHERE `entry` = 37927;
UPDATE `creature_template` SET `npcflag` = 16777216, `unit_flags` = 16384 WHERE `entry` = 37927;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= '37927' AND `spell_id`='68503';
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES ('37927', '68503', '1');


-- Conditions for Ride Vehicle if Quest 24681 - QUESTTAKEN 
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`='18') AND (`SourceGroup`='38150') AND (`SourceEntry`='68503') AND (`SourceId`='0') AND (`ElseGroup`='0') AND (`ConditionTypeOrReference`='9') AND (`ConditionTarget`='0') AND (`ConditionValue1`='24681') AND (`ConditionValue2`='0') AND (`ConditionValue3`='0');
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `Comment`) VALUES ('18', '38150', '68503', '9', '24681', 'Quest 24681 - QUESTTAKEN');

-- Conditions for Ride Vehicle if Quest 24681 - QUESTTAKEN 
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`='18') AND (`SourceGroup`='37927') AND (`SourceEntry`='68503') AND (`SourceId`='0') AND (`ElseGroup`='0') AND (`ConditionTypeOrReference`='9') AND (`ConditionTarget`='0') AND (`ConditionValue1`='24681') AND (`ConditionValue2`='0') AND (`ConditionValue3`='0');
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `Comment`) VALUES ('18', '37927', '68503', '9', '24681', 'Quest 24681 - QUESTTAKEN');

DELETE FROM `creature` WHERE `id`=36616;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(NULL, '36616', '654', '4714', '4726', '1', '14', '0', '0', '-1294.43', '2105.86', '5.54645', '2.62738', '300', '0', '0', '2080', '205', '0', '0', '0', '0', '0');

UPDATE `creature` SET `phaseMask` = 15 WHERE `guid` = 1440274;

DELETE FROM `spell_area` WHERE `area`='4726' AND `spell`='59073';
DELETE FROM `spell_area` WHERE `area`='4726' AND `spell`='59074';
DELETE FROM `spell_area` WHERE `area`='4726' AND `spell`='72872';
DELETE FROM `spell_area` WHERE `area`='4726' AND `spell`='116855';
DELETE FROM `spell_area` WHERE `area`='4726' AND `spell`='95840';

INSERT INTO `spell_area` (`spell`, `area`, `quest_end`, `autocast`, `quest_end_status`) VALUES ('59073', '4726', '14434', '1', '66');
INSERT INTO `spell_area` (`spell`, `area`, `quest_end`, `autocast`, `quest_end_status`) VALUES ('59074', '4726', '14434', '1', '66');
INSERT INTO `spell_area` (`spell`, `area`, `quest_end`, `autocast`, `quest_end_status`) VALUES ('72872', '4726', '14434', '1', '66');
INSERT INTO `spell_area` (`spell`, `area`, `quest_end`, `autocast`, `quest_end_status`) VALUES ('116855', '4726', '14434', '1', '66');
INSERT INTO `spell_area` (`spell`, `area`, `quest_end`, `autocast`, `quest_end_status`) VALUES ('95840', '4726', '14434', '1', '66');

DELETE FROM `quest_end_scripts` WHERE (`id`='14434') AND (`command`='6');
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14434', '6', '6', '1', '0', '0', '8179.79', '1004.28', '6.95961', '6.01877');

