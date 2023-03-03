DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pvp_honor_adaptation',
'spell_pvp_honor_medallion');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(214027, 'spell_pvp_honor_adaptation'),
(42292,  'spell_pvp_honor_medallion'),
(195710, 'spell_pvp_honor_medallion'),
(208683, 'spell_pvp_honor_medallion');

-- 257537/257538 - Ebonbolt
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_ebonbolt', 'spell_mage_ebonbolt_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(257537, 'spell_mage_ebonbolt'),
(257538, 'spell_mage_ebonbolt_damage');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_icicle_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(148022, 'spell_mage_icicle_damage');
