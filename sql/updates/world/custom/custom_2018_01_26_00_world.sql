DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_mage_flame_orb',
'spell_mage_flame_orb_aoe_dummy');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82731, 'spell_mage_flame_orb'), -- Flame Orb
(92283, 'spell_mage_flame_orb'), -- Frostfire Orb
(82734, 'spell_mage_flame_orb_aoe_dummy'),
(84718, 'spell_mage_flame_orb_aoe_dummy');

UPDATE `creature_template` SET `minlevel`= 74, `maxlevel`= 74, `faction`= 5, `unit_flags`= 33556552, `unit_flags2`= 32768, `HoverHeight`= 2, `flags_extra`= 2, `speed_walk`= 1, `ScriptName`= 'npc_mage_orb' WHERE `entry` IN (44214, 45322);
DELETE FROM `creature_template_addon` WHERE `entry` IN (44214, 45322);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`) VALUES
(44214, 33554432),
(45322, 33554432);
