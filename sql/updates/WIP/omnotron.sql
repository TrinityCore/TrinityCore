-- Template Updates
-- Omnotron
UPDATE `creature_template` SET `ScriptName`= 'boss_omnotron_defense_system' WHERE `entry`= 42186;
-- Golems
UPDATE `creature_template` SET `unit_flags2`= 0, `unit_flags`= 0x02000000 | 0x80000000, `ScriptName`= 'npc_omnotron_golem' WHERE `entry` IN (42166, 42178, 42179, 42180);


-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (42166, 42178, 42179, 42180, 42186);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Omnotron
(42186, 0, 0, 'Electron unit activated.', 14, 0, 100, 0, 0, 21865, 47924, 'Omnotron to Electron'),
(42186, 1, 0, 'Toxitron unit activated.', 14, 0, 100, 0, 0, 21867, 47926, 'Omnotron to Toxitron'),
(42186, 2, 0, 'Magmatron unit activated.', 14, 0, 100, 0, 0, 21866, 47925, 'Omnotron to Magmatron'),
(42186, 3, 0, 'Arcanotron unit activated.', 14, 0, 100, 0, 0, 23378, 47927, 'Omnotron to Arcanotron'),
(42186, 4, 0, 'Electron unit shield systems online.', 14, 0, 100, 0, 0, 21869, 47928, 'Omnotron to Electron'),
(42186, 5, 0, 'Toxitron unit shield systems online.', 14, 0, 100, 0, 0, 21871, 47956, 'Omnotron to Toxitron'),
(42186, 6, 0, 'Arcanotron unit shield systems online.', 14, 0, 100, 0, 0, 21872, 47930, 'Omnotron to Arcanotron'),
(42186, 7, 0, 'Magmatron unit shield systems online.', 14, 0, 100, 0, 0, 21870, 47929, 'Omnotron to Magmatron'),
(42186, 8, 0, 'Rerouting excess energy to Magmatron unit. Engage flamethrower device.', 14, 0, 100, 0, 0, 21873, 47931, 'Omnotron to Magmatron'),
(42186, 9, 0, 'Defense systems obliterated. Powering down...', 14, 0, 100, 0, 0, 21864, 47934, 'Omnotron to Player');

/*
(42166, @GROUP_ID+0, @ID+, '|TInterface\\Icons\\spell_arcane_arcaneresilience.blp:20|t%s begins to cast|cFFFE1CF7|Hspell:79729|h [Power Conversion]!|r', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Arcanotron'),
(42178, @GROUP_ID+0, @ID+, '|TInterface\\Icons\\ability_hunter_mastermarksman.blp:20|t%s sets his eye on |cFFFF0000$n|r and begins to cast|cFFFF0000|Hspell:79501|h [Acquiring Target]!|r', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Magmatron to Player'),
(42179, @GROUP_ID+0, @ID+, '|TInterface\\Icons\\spell_shaman_staticshock.blp:20|t%s casts|cFF1CF2FE|Hspell:79888|h [Lightning Conductor]|h|r at |cFF1CF2FE$n|r!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Electron to Player'),
(42179, @GROUP_ID+1, @ID+, '|TInterface\\Icons\\spell_nature_lightningshield.blp:20|t%s begins to cast|cFF1CF2FE|Hspell:79900|h [Unstable Shield]!|r', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Electron'),
(42180, @GROUP_ID+0, @ID+, '|TInterface\\Icons\\spell_nature_nullifydisease.blp:20|t%s begins to cast|cFF1CFE1C|Hspell:79835|h [Poison Soaked Shell]!|r', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Toxitron'),
*/

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_omnotron_controller_recharge',
'spell_omnotron_recharging',
'spell_omnotron_activated',
'spell_omnotron_inactive');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(78696, 'spell_omnotron_controller_recharge'),
(78697, 'spell_omnotron_recharging'),
(95019, 'spell_omnotron_recharging'),
(95020, 'spell_omnotron_recharging'),
(95021, 'spell_omnotron_recharging'),
(78698, 'spell_omnotron_recharging'),
(95025, 'spell_omnotron_recharging'),
(95026, 'spell_omnotron_recharging'),
(95027, 'spell_omnotron_recharging'),
(78700, 'spell_omnotron_recharging'),
(95022, 'spell_omnotron_recharging'),
(95023, 'spell_omnotron_recharging'),
(95024, 'spell_omnotron_recharging'),
(78699, 'spell_omnotron_recharging'),
(95028, 'spell_omnotron_recharging'),
(95029, 'spell_omnotron_recharging'),
(95030, 'spell_omnotron_recharging'),
(78740, 'spell_omnotron_activated'),
(95016, 'spell_omnotron_activated'),
(95017, 'spell_omnotron_activated'),
(95018, 'spell_omnotron_activated'),
(78726, 'spell_omnotron_inactive');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (79920, 78696, 78697, 95019, 95020, 95021, 78698, 95025, 95026, 95027, 78699, 78700, 95022, 95023, 95024, 95028, 95029, 95030) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 79920, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Shared Health - Target Electron'),
(13, 1, 79920, 0, 1, 31, 0, 3, 42178, 0, 0, 0, '', 'Shared Health - Target Magmatron'),
(13, 1, 79920, 0, 2, 31, 0, 3, 42180, 0, 0, 0, '', 'Shared Health - Target Toxitron'),

(13, 1, 79920, 0, 3, 31, 0, 3, 42166, 0, 0, 0, '', 'Shared Health - Target Arcanotron'),

(13, 1, 78696, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Controller Recharge - Target Electron'),
(13, 1, 78696, 0, 1, 31, 0, 3, 42178, 0, 0, 0, '', 'Controller Recharge - Target Magmatron'),
(13, 1, 78696, 0, 2, 31, 0, 3, 42180, 0, 0, 0, '', 'Controller Recharge - Target Toxitron'),
(13, 1, 78696, 0, 3, 31, 0, 3, 42166, 0, 0, 0, '', 'Controller Recharge - Target Arcanotron'),

(13, 1, 78697, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Recharging - Target Electron'),
(13, 1, 95019, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Recharging - Target Electron'),
(13, 1, 95020, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Recharging - Target Electron'),
(13, 1, 95021, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Recharging - Target Electron'),

(13, 1, 78698, 0, 0, 31, 0, 3, 42178, 0, 0, 0, '', 'Recharging - Target Magmatron'),
(13, 1, 95025, 0, 0, 31, 0, 3, 42178, 0, 0, 0, '', 'Recharging - Target Magmatron'),
(13, 1, 95026, 0, 0, 31, 0, 3, 42178, 0, 0, 0, '', 'Recharging - Target Magmatron'),
(13, 1, 95027, 0, 0, 31, 0, 3, 42178, 0, 0, 0, '', 'Recharging - Target Magmatron'),

(13, 1, 78700, 0, 0, 31, 0, 3, 42180, 0, 0, 0, '', 'Recharging - Target Toxitron'),
(13, 1, 95022, 0, 0, 31, 0, 3, 42180, 0, 0, 0, '', 'Recharging - Target Toxitron'),
(13, 1, 95023, 0, 0, 31, 0, 3, 42180, 0, 0, 0, '', 'Recharging - Target Toxitron'),
(13, 1, 95024, 0, 0, 31, 0, 3, 42180, 0, 0, 0, '', 'Recharging - Target Toxitron'),

(13, 1, 78699, 0, 0, 31, 0, 3, 42166, 0, 0, 0, '', 'Recharging - Target Arcanotron'),
(13, 1, 95028, 0, 0, 31, 0, 3, 42166, 0, 0, 0, '', 'Recharging - Target Arcanotron'),
(13, 1, 95029, 0, 0, 31, 0, 3, 42166, 0, 0, 0, '', 'Recharging - Target Arcanotron'),
(13, 1, 95030, 0, 0, 31, 0, 3, 42166, 0, 0, 0, '', 'Recharging - Target Arcanotron');

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 42186 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(42186, 0, 0, 42179, -342.519, -405.134, 214.0583, 0.9424778, 8, 0),
(42186, 0, 0, 42178, -308.807, -405.278, 214.0873, 2.111848, 8, 0),
(42186, 0, 0, 42180, -333.632, -411.866, 214.1353, 1.291544, 8, 0),
(42186, 0, 0, 42166, -315.415, -412.474, 214.0963, 1.832596, 8, 0);

-- Waypoints
DELETE FROM `waypoint_data` WHERE `id`= 4218600;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(4218600, 1, -309.7726, -392.9861, 213.9485),
(4218600, 2, -324.7795, -399.0781, 213.8248),
(4218600, 3, -342.2674, -392.6615, 213.9369),
(4218600, 4, -324.7795, -399.0781, 213.8248);

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (42179, 42178, 42180, 42166);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(42179, 0, 1, '78726 82265 78725 73059'),
(42178, 0, 1, '78726 82265 78725 73059'),
(42180, 0, 1, '78726 82265 78725 73059'),
(42166, 0, 1, '78726 82265 78725 73059');

-- Delete encounter related creature
DELETE FROM `creature` WHERE `guid` IN (250043, 250044, 250045, 250046);
DELETE FROM `creature_addon` WHERE `guid` IN (250043, 250044, 250045, 250046);
