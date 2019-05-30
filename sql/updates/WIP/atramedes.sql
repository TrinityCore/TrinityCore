-- Template Updates
-- Atramedes
UPDATE `creature_template` SET `ScriptName`= 'boss_atramedes' WHERE `entry`= 41442;
UPDATE `creature_template` SET `speed_run`= 1.429, `VehicleId`= 891, `flags_extra`= 1 | 512, `DamageModifier`= 120, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271 WHERE `entry` IN (41442, 49583, 49584, 49585);
-- Blind Dragon Tail
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130 WHERE `entry`= 42356;
-- Sonar Pulse
UPDATE `creature_template` SET `speed_run`= 1, `unit_flags`= 34080768, `flags_extra`= 130 WHERE `entry`= 41546;
-- Sonar Pulse Target
UPDATE `creature_template` SET `unit_flags`= 33554688, `flags_extra`= 128 WHERE `entry`= 49679;
-- Roaring Flame
UPDATE `creature_template` SET `unit_flags`= 33554688, `flags_extra`= 130 WHERE `entry`= 41807;
-- Tracking Flames
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130, `speed_run`= 0.714 WHERE `entry`= 41879;
-- Sonar Pulse
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130 WHERE `entry`= 49623;
-- Reverberating Flame
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130, `speed_run`= 0.714 WHERE `entry`= 41962;
-- Reverberating Flame (Fire)
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130, `speed_run`= 0.714 WHERE `entry`= 42001;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 41442;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(41442, 0, 0, 'I have no need for eyes to see my enemies. Your clumsy footsteps and foul stench give you away!', 14, 0, 100, 0, 0, 20820, 48030, 'Atramedes - Aggro'),
(41442, 1, 0, '|TInterface\\Icons\\spell_fire_selfdestruct.blp:20|t%s rears back and casts |cFFFF0000|Hspell:77982|h[Searing Flame]|h|r!\n', 41, 0, 100, 0, 0, 20826, 42180, 'Atramedes - Announce Searing Flame'),
(41442, 2, 0, 'You cannot hide from searing flame!', 14, 0, 100, 0, 0, 20826, 48036, 'Atramedes - Searing Flame'),
(41442, 3, 0, 'Yes, run! With every step your heart quickens. The beating, loud and thunderous... Almost deafening. You cannot escape!', 14, 0, 100, 0, 0, 20827, 48038, 'Atramedes'),
(41442, 4, 0, 'This miserable existence finally ends.', 14, 0, 100, 0, 0, 20823, 48034, 'Atramedes to Player');

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_atramedes_modulation',
'spell_atramedes_roaring_flame_breath_reverse_cast',
'spell_atramedes_roaring_flame_breath',
'spell_atramedes_roaring_flame_breath_fire_periodic',
'spell_atramedes_resonating_clash_ground',
'spell_atramedes_vertigo');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(92452, 'spell_atramedes_modulation'),
(92453, 'spell_atramedes_modulation'),
(78230, 'spell_atramedes_roaring_flame_breath_reverse_cast'),
(78221, 'spell_atramedes_roaring_flame_breath'),
(78431, 'spell_atramedes_roaring_flame_breath_fire_periodic'),
(77611, 'spell_atramedes_resonating_clash_ground'),
(77717, 'spell_atramedes_vertigo'),
(92389, 'spell_atramedes_vertigo'),
(92390, 'spell_atramedes_vertigo'),
(92391, 'spell_atramedes_vertigo');

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (41807, 42001, 41962);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(41807, 0, 1, '78024 78018'),
(42001, 0, 1, '78024 78018'),
(41962, 0, 1, '78217 78354');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (77673, 78098, 92403, 92404, 92405, 78230, 78431, 77611, 78168) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 77673, 0, 0, 31, 0, 3, 41442, 0, 0, 0, '', 'Sonar Pulse Summon - Target Atramedes'),
(13, 1, 78098, 0, 0, 31, 0, 3, 41879, 0, 0, 0, '', 'Sonic Breath - Target Tracking Flames'),
(13, 1, 92403, 0, 0, 31, 0, 3, 41879, 0, 0, 0, '', 'Sonic Breath - Target Tracking Flames'),
(13, 1, 92404, 0, 0, 31, 0, 3, 41879, 0, 0, 0, '', 'Sonic Breath - Target Tracking Flames'),
(13, 1, 92405, 0, 0, 31, 0, 3, 41879, 0, 0, 0, '', 'Sonic Breath - Target Tracking Flames'),
(13, 1, 78230, 0, 0, 31, 0, 3, 41442, 0, 0, 0, '', 'Roaring Flame Breath Reverse Cast - Target Atramedes'),
(13, 1, 78431, 0, 0, 31, 0, 3, 42001, 0, 0, 0, '', 'Roaring Flame Breath Fire Periodic - Target Reverberating Flame'),
(13, 3, 77611, 0, 0, 31, 0, 3, 41442, 0, 0, 0, '', 'Resonating Clash - Target Atramedes'),
(13, 1, 78168, 0, 0, 31, 0, 3, 41442, 0, 0, 0, '', 'Resonating Clash - Target Atramedes');

-- Vehicle Accessory
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (41442, 49583, 49584, 49585);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(41442, 42356, 0, 1, 'Atramedes - Blind Dragon Tail', 8, 0), -- Atramedes - Blind Dragon Tail
(49583, 42356, 0, 1, 'Atramedes - Blind Dragon Tail', 8, 0), -- Atramedes - Blind Dragon Tail
(49584, 42356, 0, 1, 'Atramedes - Blind Dragon Tail', 8, 0), -- Atramedes - Blind Dragon Tail
(49585, 42356, 0, 1, 'Atramedes - Blind Dragon Tail', 8, 0); -- Atramedes - Blind Dragon Tail

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (41442, 49583, 49584, 49585);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(41442, 46598, 1, 1),
(49583, 46598, 1, 1),
(49584, 46598, 1, 1),
(49585, 46598, 1, 1);

-- Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (41546, 41962);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`) VALUES
(41546, 0, 1, 1),
(41962, 0, 0, 2);

-- Correct Athenaeum Door Rotation
UPDATE `gameobject` SET `rotation2`= -1, `rotation3`= 0 WHERE `guid`= 235177;
UPDATE `gameobject_addon` SET `parent_rotation2`= 1, `parent_rotation3`= -0.00000004371139 WHERE `guid`= 235177;
