DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_frostfire_bolt','spell_mage_ice_block','spell_pal_immunities');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-44614, 'spell_mage_frostfire_bolt'),
( 45438, 'spell_mage_ice_block'),
(   498, 'spell_pal_immunities'),
(   642, 'spell_pal_immunities'),
( -1022, 'spell_pal_immunities');
