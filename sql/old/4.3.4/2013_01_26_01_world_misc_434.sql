DELETE FROM `spell_script_names` WHERE `spell_id` IN (82676, 82691);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(82676, 'spell_mage_ring_of_frost'),
(82691, 'spell_mage_ring_of_frost_freeze');

-- Set flags UNIT_FLAG_DISABLE_MOVE| UNIT_FLAG_STUNNED|UNIT_FLAG_NOT_SELECTABLE on Ring of Frost
UPDATE `creature_template` SET `unit_flags` = 0x4|0x40000|0x2000000 WHERE `entry` = 44199;
