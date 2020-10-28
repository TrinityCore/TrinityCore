-- Template Updates
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512 WHERE `entry` IN (32857, 33694);
UPDATE `creature_template` SET `speed_run`= 1.42857 WHERE `entry`= 33694;
UPDATE `creature_template` SET `speed_run`= 1.28571 WHERE `entry`= 33692;
UPDATE `creature_template` SET `speed_walk`= 0.888888,  `speed_run`= 1.58731 WHERE `entry`= 33693;
UPDATE `creature_template` SET `ScriptName`= 'npc_assembly_lightning_elemental' WHERE `entry`= 32958;
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry` IN (32866, 33690);

DELETE FROM `creature_template_addon` WHERE `entry` IN (32866, 33690);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(32866, '61877'),
(33690, '61877');

-- Spawn Groups
DELETE FROM `spawn_group_template` WHERE `groupId`= 67;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(67, 'Ulduar - Assembly of Iron', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 67;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(67, 0, 136421), -- Steelbreaker
(67, 0, 136760), -- Runemaster Molgeim
(67, 0, 136316); -- Stormcaller Brundir

-- Correct spawn positions
UPDATE `creature` SET `position_x`= 1575.9601, `position_y`= 120.35938, `position_z`= 427.4189, `orientation`= 0.122173048555850982 WHERE `guid`= 136421;
UPDATE `creature` SET `position_x`= 1589.5435, `position_y`= 106.98612, `position_z`= 427.4189, `orientation`= 2.338741064071655273 WHERE `guid`= 136760;
UPDATE `creature` SET `position_x`= 1592.9392, `position_y`= 120.38715, `position_z`= 427.4189, `orientation`= 3.141592741012573242 WHERE `guid`= 136316;

-- Correct Model Info Data
UPDATE `creature_model_info` SET `BoundingRadius`= 6.22840118408203125 WHERE `DisplayID`= 28344; -- Steelbreaker
UPDATE `creature_model_info` SET `CombatReach`= 0, `BoundingRadius`= 1.330477356910705566 WHERE `DisplayID`= 28324; -- Stormcaller Brundir

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (61942, 61975, 61920, 64320) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 61942, 0, 0, 31, 0, 3, 32867, 0, 0, 0, '', 'Lightning Channel Pre-fight Visual - Target Steelbreaker'),
(13, 1, 61975, 0, 0, 31, 0, 3, 32867, 0, 0, 0, '', 'Rune of Power - Target Steelbreaker'),
(13, 7, 61920, 0, 0, 31, 0, 3, 32867, 0, 0, 0, '', 'Supercharge - Target Steelbreaker'),
(13, 7, 61920, 0, 1, 31, 0, 3, 32927, 0, 0, 0, '', 'Supercharge - Target Runemaster Molgeim'),
(13, 7, 61920, 0, 2, 31, 0, 3, 32857, 0, 0, 0, '', 'Supercharge - Target Stormcaller Brundir'),
(13, 1, 64320, 0, 0, 31, 0, 3, 32867, 0, 0, 0, '', 'Rune of Power - Target Steelbreaker'),
(13, 1, 64320, 0, 1, 31, 0, 3, 32927, 0, 0, 0, '', 'Rune of Power - Target Runemaster Molgeim'),
(13, 1, 64320, 0, 2, 31, 0, 3, 32857, 0, 0, 0, '', 'Rune of Power - Target Stormcaller Brundir');

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_assembly_supercharge',
'spell_assembly_berserk',
'spell_assembly_random_aggro_periodic',
'spell_assembly_lightning_tendrils_visual');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61920, 'spell_assembly_supercharge'),
(62535, 'spell_assembly_berserk'),
(61906, 'spell_assembly_random_aggro_periodic'),
(61884, 'spell_assembly_lightning_tendrils_visual');
