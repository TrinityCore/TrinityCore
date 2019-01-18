-- Template Updates
-- Berserker Boulder Roller
UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 0.5, `flags_extra`= 0x40000000, `mechanic_immune_mask`= 634338303, `ScriptName`= 'npc_zulgurub_berserking_boulder_roller' WHERE `entry`= 52348;
-- Boulder
UPDATE `creature_template` SET `speed_run`= 2.1428, `unit_flags`= 33554432, `unit_flags2`= 2099200, `VehicleId`= 1594, `flags_extra`= 2 WHERE `entry` IN (52353, 52351, 52354);
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 2099200, `flags_extra`= 2, `ScriptName`= '' WHERE `entry`= 52350;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_zulgurub_rolling_boulders');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96826, 'spell_zulgurub_rolling_boulders'),
(96837, 'spell_zulgurub_rolling_boulders');

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (52353, 52351, 52354, 52350);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(52353, 0, 1, '96831'),
(52351, 0, 1, '96831'),
(52354, 0, 1, '96831');

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (52353, 52351, 52354);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(52353, 46598, 1, 1),
(52351, 46598, 1, 1),
(52354, 46598, 1, 1);

-- Vehicle accessories
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (52353, 52351, 52354);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(52353, 52350, 0, 1, 'Boulder - Boulder', 8, 0),
(52351, 52350, 0, 1, 'Boulder - Boulder', 8, 0),
(52354, 52350, 0, 1, 'Boulder - Boulder', 8, 0);
