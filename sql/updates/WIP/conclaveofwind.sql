/*
0x243CC85E402CCB8000434F0000195AB6 -- anshal guid

-- Anshal
20:19:42.125 -- rohash aggro
20:19:43.207 -- winds pre effect warning cast
20:19:45.207 -- "you think you can outrun the wind?
20:19:45.208 -- withering winds start
20:19:45.641 -- winds pre effect warning start
20:19:48.074 -- winds pre effect warning
20:19:50.508 -- winds pre effect warning
20:19:52.941 -- winds pre effect warning
20:19:42.125

20:19:42.125 -- anshal aggro (not engaged)
20:19:57.808 -- soothing breeze (casted on self because there is nothing else


20:20:09.540
20:20:09.824 -- nurture

20:20:57.708 -- the conclive is nearning full strength
20:21:11.892 -- zephyr


20:25:39.343 -- jet stream cast
20:25:41.376 -- wind pre effect warning

20:25:43.394
20:25:43.493 -- you think you outrun the wind???
20:26:44.509 -- teleport to center west



20:23:53.994 -- creeper trigger cassts dummy visual
20:24:02.258 -- 85429

*/

-- Template Updates
UPDATE `creature_template` SET `ScriptName`= 'boss_anshal', `difficulty_entry_1`= 50103, `difficulty_entry_2`= 50113, `difficulty_entry_3`= 50123 WHERE `entry`= 45870;
UPDATE `creature_template` SET `ScriptName`= 'boss_nezir', `difficulty_entry_1`= 50098, `difficulty_entry_2`= 50108, `difficulty_entry_3`= 50118 WHERE `entry`= 45871;
UPDATE `creature_template` SET `ScriptName`= 'boss_rohash', `difficulty_entry_1`= 50095, `difficulty_entry_2`= 50105, `difficulty_entry_3`= 50115 WHERE `entry`= 45872;
-- Anshal
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `unit_flags2`= 1075838976, `vehicleId`= 1321, `InhabitType`= 1 WHERE `entry` IN (45872, 50103, 50113, 50123);
-- Nezir
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `unit_flags2`= 1075838976, `vehicleId`= 1319, `InhabitType`= 1 WHERE `entry` IN (45872, 50098, 50108, 50118);
-- Rohash
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `unit_flags2`= 1075838976, `vehicleId`= 1318, `InhabitType`= 9 WHERE `entry` IN (45872, 50095, 50105, 50115);
-- Ravenous Creeper Trigger
UPDATE `creature_template` SET `unit_flags`= 33555200, `flags_extra`= 128, `ScriptName`= 'npc_conclave_of_wind_ravenous_creeper_trigger' WHERE `entry`= 45813;
-- Soothing Breeze
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 46246;
-- North Wind
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 47926;

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (21252, 45870, 45871, 45872);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- World Trigger
(21252, 0, 0, 'The Conclave of Wind is nearing full strength!', 41, 0, 100, 0, 0, 0, 48590, 3, 'World Trigger - Announce Special Ability Warning'),
-- Anshal
(45870, 0, 0, 'It shall be I that earns the favor of our lord by casting out the intruders. My calmest wind shall still prove too much for them!', 14, 0, 100, 0, 0, 0, 50596, 3, 'Anshal - Aggro'),
(45870, 1, 0, 'You think to outrun the wind? A fatal mistake.', 14, 0, 100, 0, 0, 0, 50599, 3, 'Anshal - Out of Range'),
(45870, 2, 0, 'My power grows feeble, brothers. I shamefully must rely on you for a time.', 14, 0, 100, 0, 0, 0, 50601, 3, 'Anshal - Gather Strength'),
(45870, 3, 0, '%s begins to gather strength from the remaining Wind Lords!', 41, 0, 100, 0, 0, 0, 48593, 3, 'Anshal - Announce Gather Strength'),
(45870, 4, 0, 'The power of our winds, UNLEASHED!', 14, 0, 100, 0, 0, 0, 50594, 3, 'Anshal - Special Ability'),
(45870, 5, 0, 'Begone, outsider!', 14, 0, 100, 0, 0, 0, 50597, 3, 'Anshal - Slay 1'),
(45870, 5, 1, 'Your presence shall no longer defile our home!', 14, 0, 100, 0, 0, 0, 50598, 3, 'Anshal - Slay 2'),
-- Nezir
(45871, 0, 0, 'The honor of slaying the interlopers shall be mine, brothers! Their feeble bodies will freeze solid from my wind''s icy chill!', 14, 0, 100, 0, 0, 0, 50589, 3, 'Nezir - Aggro'),
(45871, 1, 0, 'You throw away your honor and flee as cowards? Then die!', 14, 0, 100, 0, 0, 0, 50592, 3, 'Nezir - Out of Range'),
(45871, 2, 0, 'Brothers, beware! These mortals are dangerous. I must pause and gather my strength.', 14, 0, 100, 0, 0, 0, 50595, 3, 'Nezir - Gather Strength'),
(45871, 3, 0, '%s begins to gather strength from the remaining Wind Lords!', 41, 0, 100, 0, 0, 0, 48593, 3, 'Nezir - Announce Gather Strength'),
(45871, 4, 0, 'The power of our winds, UNLEASHED!', 14, 0, 100, 0, 0, 0, 50594, 3, 'Nezir - Special Ability'),
(45871, 5, 0, 'Frozen solid.', 14, 0, 100, 0, 0, 0, 50590, 3, 'Nezir - Slay 1'),
(45871, 5, 1, 'Another mortal has taken their last breath!', 14, 0, 100, 0, 0, 0, 50591, 3, 'Nezir - Slay 2'),
-- Rohash
(45872, 0, 0, 'As I am the strongest wind, it shall be I that tears the invaders apart!', 14, 0, 100, 0, 0, 0, 50602, 3, 'Rohash - Aggro'),
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
DELETE FROM `creature_template_addon` WHERE `entry` IN (46246);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(46246, '86206 86207 86208');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_conclave_of_wind_winds_pre_effect_warning',
'spell_conclave_of_wind_winds_distance_checker',
'spell_conclave_of_winds_teleport_to_center');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96508, 'spell_conclave_of_wind_winds_pre_effect_warning'),
(85763, 'spell_conclave_of_wind_winds_distance_checker'),
(89843, 'spell_conclave_of_winds_teleport_to_center'),
(89844, 'spell_conclave_of_winds_teleport_to_center');

DELETE FROM `conditions` WHERE `SourceEntry` IN (89844, 89843) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89844, 0, 0, 31, 0, 3, 47925, 0, 0, 0, '', 'Teleport to Center (West) - Target West Wind'),
(13, 1, 89843, 0, 0, 31, 0, 3, 47926, 0, 0, 0, '', 'Teleport to Center (North) - Target North Wind');





