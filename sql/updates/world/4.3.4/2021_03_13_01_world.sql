UPDATE `creature_template` SET `unit_flags`= 0x40 | 0x8000, `unit_flags2`= 0x800 |  0x400000, `VehicleId`= 1543, `mechanic_immune_mask`= 650854271, `flags_extra`= 0x40000000, `ScriptName`= 'npc_deepholm_xariona' WHERE `entry`= 50061;
UPDATE `creature_addon` SET `auras`= '', `bytes1`= 50331648 WHERE `guid`= 396407;
UPDATE `creature_template` SET `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 50431;

UPDATE `creature_template_movement` SET `Ground`= 2 WHERE `CreatureId`= 50061;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_deepholm_twilight_buffet_targeting');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(95385, 'spell_deepholm_twilight_buffet_targeting');
