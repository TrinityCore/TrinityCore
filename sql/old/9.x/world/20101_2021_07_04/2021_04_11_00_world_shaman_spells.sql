-- Update various shaman spells
UPDATE `creature_template` SET `spell1` = 192226 WHERE `entry` = 97369; -- Liquid Magma Totem
UPDATE `creature_template` SET `spell1` = 8145 WHERE `entry` = 5913; -- Tremor Totem
UPDATE `creature_template` SET `spell1` = 118905 WHERE `entry` = 61245; -- Capacitator

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_healing_rain', 'spell_sha_liquid_magma_totem', 'spell_sha_flametongue_weapon', 'spell_sha_flametongue_weapon_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(73920, 'spell_sha_healing_rain'),
(192223, 'spell_sha_liquid_magma_totem'),
(318038, 'spell_sha_flametongue_weapon'),
(319778, 'spell_sha_flametongue_weapon_aura');
