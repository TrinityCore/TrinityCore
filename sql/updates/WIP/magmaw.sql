-- Magmaw
UPDATE `creature_template` SET `InhabitType`= 12, `ScriptName`= 'boss_magmaw' WHERE `entry`= 41570;
UPDATE `creature_template` SET `InhabitType`= 12 WHERE `entry` IN (51101, 51102, 51103);
-- Magmaw's Pincer
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (41620, 41789);
-- Pillar of Flame
UPDATE `creature_template` SET `unit_flags`= 33587264, `unit_flags2`= 34816, `flags_extra`= 2 WHERE `entry`= 41843;
-- Lava Parasite
UPDATE `creature_template` SET `speed_run`= 0.3571, `speed_walk`= 1 WHERE `entry`= 41806;

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (41806);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(41806, '78019');

-- Vehicle accessory
DELETE FROM `vehicle_template_accessory` WHERE `entry`= 41570;

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 41570;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(41570, 77901, 1, 1);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_magmaw_magma_spit',
'spell_magmaw_mangle',
'spell_magmaw_pillar_of_flame_dummy',
'spell_magmaw_pillar_of_flame_forcecast');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(95280, 'spell_magmaw_magma_spit'),
(92047, 'spell_magmaw_mangle'),
(78017, 'spell_magmaw_pillar_of_flame_dummy'),
(77998, 'spell_magmaw_pillar_of_flame_forcecast');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (89743, 78360, 78017, 78010);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89743, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Ride Vehicle - Target Magmaw'),
(13, 1, 78360, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Ride Vehicle - Target Magmaw'),
(13, 2, 78017, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Pillar of Flame - Target Magmaw'),
(13, 1, 78010, 0, 0, 31, 0, 3, 41843, 0, 0, 0, '', 'Pillar of Flame - Target Pillar of Flame');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (41570);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(41570, 0, 0, '%s begins to erupt, spewing Lava Parasites onto the ground!', 41, 0, 100, 0, 0, 8717, 51464, 'Magmaw - Announce Lava Parasites'),
(41570, 1, 0, '%s slumps forward, exposing his pincers!', 41, 0, 100, 0, 0, 8717, 47603, 'Magmaw - Announce Exposing Pincers'),
(41570, 2, 0, '%s becomes impaled on the spike, exposing his head!', 41, 0, 100, 0, 0, 8717, 41614, 'Magmaw - Announce Exposed Head');

-- Delete encounter related creatures
DELETE FROM `creature` WHERE `guid` IN (250054, 250053, 250052);
DELETE FROM `creature_addon` WHERE `guid` IN (250054, 250053, 250052);
