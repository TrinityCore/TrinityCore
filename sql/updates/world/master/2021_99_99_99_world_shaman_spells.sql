-- Update various shaman spells
UPDATE `creature_template` SET `spell1` = 192226 WHERE `entry` = 97369; -- Liquid Magma Totem
UPDATE `creature_template` SET `spell1` = 8145 WHERE `entry` = 5913; -- Tremor Totem
UPDATE `creature_template` SET `spell1` = 118905 WHERE `entry` = 61245; -- Capacitator
UPDATE `creature_template` SET `spell1` = 118905 WHERE `entry` = 73400; -- Healing Rain

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_liquid_magma_totem');
INSERT INTO spell_script (`spell_id`, `ScriptName`) VALUES (, 'spell_sha_liquid_magma_totem');

