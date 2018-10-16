-- Template Updates
UPDATE `creature_template` SET `ScriptName`= 'boss_anshal', `difficulty_entry_1`= 50103, `difficulty_entry_2`= 50113, `difficulty_entry_3`= 50123 WHERE `entry`= 45870;
UPDATE `creature_template` SET `ScriptName`= 'boss_nezir', `difficulty_entry_1`= 50098, `difficulty_entry_2`= 50108, `difficulty_entry_3`= 50118 WHERE `entry`= 45871;
UPDATE `creature_template` SET `ScriptName`= 'boss_rohash', `difficulty_entry_1`= 50095, `difficulty_entry_2`= 50105, `difficulty_entry_3`= 50115 WHERE `entry`= 45872;
-- Anshal
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `unit_flags2`= 1075838976, `vehicleId`= 1321, `InhabitType`= 1, `DamageModifier`= 60, `BaseVariance`= 0.5, `unit_class`= 2, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (45870, 50103, 50113, 50123);
-- Nezir
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `unit_flags2`= 1075838976, `vehicleId`= 1319, `InhabitType`= 1,
`DamageModifier`= 60, `BaseVariance`= 0.5, `unit_class`= 2, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (45871, 50098, 50108, 50118);
-- Rohash
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `unit_flags2`= 1075838976, `vehicleId`= 1318, `InhabitType`= 9, `unit_class`= 2, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (45872, 50095, 50105, 50115);
-- Ravenous Creeper Trigger
UPDATE `creature_template` SET `unit_flags`= 33555200, `flags_extra`= 128,  `ScriptName`= 'npc_conclave_of_wind_ravenous_creeper_trigger' WHERE `entry`= 45813;
-- Soothing Breeze
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 46246;
-- North Wind, East Wind and West Wind
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `InhabitType`= 4 WHERE `entry` IN (47926, 47924, 47925);
-- Ravenous Creeper
UPDATE `creature_template` SET `difficulty_entry_1`= 50100, `difficulty_entry_2`= 50110, `difficulty_entry_3`= 50120, `ScriptName`= 'npc_conclave_of_wind_ravenous_creeper' WHERE `entry`= 45812;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `InhabitType`= 1, `DamageModifier`= 10, `BaseVariance`= 0.5, `unit_class`= 2 WHERE `entry` IN (45812, 50110, 50110, 50120);
-- Tornado
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 46207;
-- World Trigger World Trigger (Not Immune NPC)
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1 WHERE `entry`= 19871;
-- Ice Patch
UPDATE `creature_template` SET `InhabitType`= 4, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 46186;
-- Hurricane
UPDATE `creature_template` SET `VehicleId`= 1185, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 46419;

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (21252, 45870, 45871, 45872);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- World Trigger
(21252, 0, 0, 'The Conclave of Wind is nearing full strength!', 41, 0, 100, 0, 0, 0, 48590, 3, 'World Trigger - Announce Special Ability Warning'),
-- Anshal
(45870, 0, 0, 'It shall be I that earns the favor of our lord by casting out the intruders. My calmest wind shall still prove too much for them!', 14, 0, 100, 0, 0, 0, 50596, 0, 'Anshal - Aggro'),
(45870, 1, 0, 'You think to outrun the wind? A fatal mistake.', 14, 0, 100, 0, 0, 0, 50599, 3, 'Anshal - Out of Range'),
(45870, 2, 0, 'My power grows feeble, brothers. I shamefully must rely on you for a time.', 14, 0, 100, 0, 0, 0, 50601, 3, 'Anshal - Gather Strength'),
(45870, 3, 0, '%s begins to gather strength from the remaining Wind Lords!', 41, 0, 100, 0, 0, 0, 48593, 3, 'Anshal - Announce Gather Strength'),
(45870, 4, 0, 'The power of our winds, UNLEASHED!', 14, 0, 100, 0, 0, 0, 50594, 3, 'Anshal - Special Ability'),
(45870, 5, 0, 'Begone, outsider!', 14, 0, 100, 0, 0, 0, 50597, 3, 'Anshal - Slay 1'),
(45870, 5, 1, 'Your presence shall no longer defile our home!', 14, 0, 100, 0, 0, 0, 50598, 3, 'Anshal - Slay 2'),
-- Nezir
(45871, 0, 0, 'The honor of slaying the interlopers shall be mine, brothers! Their feeble bodies will freeze solid from my wind''s icy chill!', 14, 0, 100, 0, 0, 0, 50589, 0, 'Nezir - Aggro'),
(45871, 1, 0, 'You throw away your honor and flee as cowards? Then die!', 14, 0, 100, 0, 0, 0, 50592, 3, 'Nezir - Out of Range'),
(45871, 2, 0, 'Brothers, beware! These mortals are dangerous. I must pause and gather my strength.', 14, 0, 100, 0, 0, 0, 50595, 3, 'Nezir - Gather Strength'),
(45871, 3, 0, '%s begins to gather strength from the remaining Wind Lords!', 41, 0, 100, 0, 0, 0, 48593, 3, 'Nezir - Announce Gather Strength'),
(45871, 4, 0, 'The power of our winds, UNLEASHED!', 14, 0, 100, 0, 0, 0, 50594, 3, 'Nezir - Special Ability'),
(45871, 5, 0, 'Frozen solid.', 14, 0, 100, 0, 0, 0, 50590, 3, 'Nezir - Slay 1'),
(45871, 5, 1, 'Another mortal has taken their last breath!', 14, 0, 100, 0, 0, 0, 50591, 3, 'Nezir - Slay 2'),
-- Rohash
(45872, 0, 0, 'As I am the strongest wind, it shall be I that tears the invaders apart!', 14, 0, 100, 0, 0, 0, 50602, 0, 'Rohash - Aggro'),
(45872, 1, 0, 'Why do you flee, mortals? There is nowhere you can run or hide here!', 14, 0, 100, 0, 0, 0, 50606, 3, 'Rohash - Out of Range'),
(45872, 2, 0, 'The intruders stand fast, brothers, I cannot break them. Allow me a brief respite to strengthen my winds.', 14, 0, 100, 0, 0, 0, 50607, 3, 'Rohash - Gather Strength'),
(45872, 3, 0, '%s begins to gather strength from the remaining Wind Lords!', 41, 0, 100, 0, 0, 0, 48593, 3, 'Rohash - Announce Gather Strength'),
(45872, 4, 0, 'The power of our winds, UNLEASHED!', 14, 0, 100, 0, 0, 0, 50594, 3, 'Roash - Special Ability'),
(45872, 5, 0, 'Blown away!', 14, 0, 100, 0, 0, 0, 50603, 3, 'Rohash - Slay 1'),
(45872, 5, 1, 'Mere dust...', 14, 0, 100, 0, 0, 0, 50604, 3, 'Roash - Slay 2'),
(45872, 6, 0, '|TInterface\\Icons\\spell_nature_cyclone.blp:20|t%s begins to cast|cFFFF9A20|Hspell:86193|h [Wind Blast]!|r', 41, 0, 100, 0, 0, 0, 50875, 0, 'Rohash - Announce Wind Blast');

-- Model Updates
UPDATE `creature_model_info` SET `BoundingRadius`= 6.987639, `CombatReach`= 12.5, `Gender`= 0 WHERE `DisplayID`= 35234;
UPDATE `creature_model_info` SET `BoundingRadius`= 6.987639, `CombatReach`= 12.5, `Gender`= 0 WHERE `DisplayID`= 35233;
UPDATE `creature_model_info` SET `BoundingRadius`= 6.987639 WHERE `DisplayID`= 35232;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (46246, 46207, 46186, 45870, 45871, 45872);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(46246, '86206 86207 86208'),
(46207, '86134'),
(46186, '86107');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_conclave_of_wind_winds_pre_effect_warning',
'spell_conclave_of_wind_teleport_to_center',
'spell_conclave_of_wind_winds',
'spell_conclave_of_wind_wind_blast',
'spell_conclave_of_wind_wind_blast_triggered',
'spell_conclave_of_wind_hurricane',
'spell_conclave_of_wind_hurricane_ride_vehicle',
'spell_conclave_of_wind_toxic_spores',
'spell_conclave_of_wind_sleet_storm');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96508, 'spell_conclave_of_wind_winds_pre_effect_warning'),
(89843, 'spell_conclave_of_wind_teleport_to_center'),
(89844, 'spell_conclave_of_wind_teleport_to_center'),
(85573, 'spell_conclave_of_wind_winds'),
(85578, 'spell_conclave_of_wind_winds'),
(85576, 'spell_conclave_of_wind_winds'),
(93190, 'spell_conclave_of_wind_winds'),
(93191, 'spell_conclave_of_wind_winds'),
(93192, 'spell_conclave_of_wind_winds'),
(93147, 'spell_conclave_of_wind_winds'),
(93148, 'spell_conclave_of_wind_winds'),
(93149, 'spell_conclave_of_wind_winds'),
(93181, 'spell_conclave_of_wind_winds'),
(93182, 'spell_conclave_of_wind_winds'),
(93183, 'spell_conclave_of_wind_winds'),
(86193, 'spell_conclave_of_wind_wind_blast'),
(85480, 'spell_conclave_of_wind_wind_blast_triggered'),
(86498, 'spell_conclave_of_wind_hurricane'),
(86481, 'spell_conclave_of_wind_hurricane_ride_vehicle'),
(86290, 'spell_conclave_of_wind_toxic_spores'),
(86367, 'spell_conclave_of_wind_sleet_storm'),
(93135, 'spell_conclave_of_wind_sleet_storm'),
(93136, 'spell_conclave_of_wind_sleet_storm'),
(93137, 'spell_conclave_of_wind_sleet_storm');

DELETE FROM `conditions` WHERE `SourceEntry` IN (89844, 89843, 89898, 86481, 90262, 86290) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89844, 0, 0, 31, 0, 3, 47925, 0, 0, 0, '', 'Teleport to Center (West) - Target West Wind'),
(13, 1, 89843, 0, 0, 31, 0, 3, 47926, 0, 0, 0, '', 'Teleport to Center (North) - Target North Wind'),
(13, 1, 89898, 0, 0, 31, 0, 3, 45870, 0, 0, 0, '', 'Power Gain - Target Anshal'),
(13, 1, 89898, 0, 1, 31, 0, 3, 45871, 0, 0, 0, '', 'Power Gain - Target Nezir'),
(13, 1, 89898, 0, 2, 31, 0, 3, 45872, 0, 0, 0, '', 'Power Gain - Target Roash'),
(13, 1, 86481, 0, 0, 31, 0, 3, 46419, 0, 0, 0, '', 'Hurricane - Target Hurricane'),
(13, 1, 90262, 0, 0, 31, 0, 3, 46419, 0, 0, 0, '', 'Hurricane - Target Hurricane'),
(13, 1, 86290, 0, 0, 31, 0, 3, 45812, 0, 0, 0, '', 'Toxic Spores - Target Ravenous Creeper');

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` IN (45870, 45871, 45872, 50103, 50113, 50123, 50098, 50108, 50118, 50095, 50105, 50115);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (45870, 45871, 45872, 50103, 50113, 50123, 50098, 50108, 50118, 50095, 50105, 50115);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (458700, 458701);

INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal Mode
(458700, 63497, 0, 1, 1, 1, 1),
(458700, 63496, 0, 1, 1, 1, 1),
(458700, 63490, 0, 1, 1, 1, 1),
(458700, 63498, 0, 1, 1, 1, 1),
(458700, 63492, 0, 1, 1, 1, 1),
(458700, 63495, 0, 1, 1, 1, 1),
(458700, 63491, 0, 1, 1, 1, 1),
(458700, 63493, 0, 1, 1, 1, 1),
(458700, 63488, 0, 1, 1, 1, 1),
(458700, 63489, 0, 1, 1, 1, 1),
(458700, 63494, 0, 1, 1, 1, 1),
-- Heroic Mode
(458701, 65374, 0, 1, 1, 1, 1),
(458701, 65377, 0, 1, 1, 1, 1),
(458701, 65369, 0, 1, 1, 1, 1),
(458701, 65376, 0, 1, 1, 1, 1),
(458701, 65368, 0, 1, 1, 1, 1),
(458701, 65375, 0, 1, 1, 1, 1),
(458701, 65370, 0, 1, 1, 1, 1),
(458701, 65371, 0, 1, 1, 1, 1),
(458701, 65367, 0, 1, 1, 1, 1),
(458701, 65372, 0, 1, 1, 1, 1),
(458701, 65373, 0, 1, 1, 1, 1);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
-- 10 Player Normal
(45870, 458700, 100, 1, 458700, 1),
(45871, 458700, 100, 1, 458700, 1),
(45872, 458700, 100, 1, 458700, 1),
-- 25 Player Normal
(50103, 458700, 100, 1, 458700, 2),
(50098, 458700, 100, 1, 458700, 2),
(50095, 458700, 100, 1, 458700, 2),
-- 10 Player Heroic
(50113, 458701, 100, 1, 458701, 1),
(50108, 458701, 100, 1, 458701, 1),
(50105, 458701, 100, 1, 458701, 1),
-- 25 Player Heroic
(50123, 458701, 100, 1, 458701, 2),
(50118, 458701, 100, 1, 458701, 2),
(50115, 458701, 100, 1, 458701, 2);

-- Gold loot
UPDATE `creature_template` SET `mingold`= 740000, `maxgold`= 800000 WHERE `entry` IN (45870, 45871, 45872, 50113, 50108, 50105);
UPDATE `creature_template` SET `mingold`= 1500000, `maxgold`= 1700000 WHERE `entry` IN (50103, 50098, 50095, 50123, 50118, 50115);

-- Currency loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (45871, 50098, 50108, 50118);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(45871, 396, 11500),
(50098, 396, 13500),
(50108, 396, 11500),
(50118, 396, 13500);
