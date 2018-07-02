-- Slabhide
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512 WHERE `entry` IN (43214, 49538);
-- Stalactite Trigger
UPDATE `creature_template` SET `unit_flags`= 33554432 WHERE `entry`= 43357;
-- Stalactite Trigger
UPDATE `creature_template` SET `InhabitType`= 4, `ScriptName`= 'npc_slabhide_stalactite_trigger' WHERE `entry`= 43159;
-- Lava Fissure
UPDATE `creature_template` SET `ScriptName`= 'npc_slabhide_lava_fissure' WHERE `entry`= 43242;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_s81035_stalactite',
'spell_slabhide_stalactite',
'spell_s81028_s80650_stalactite',
'spell_slabhide_stalactite_summon',
'spell_slabhide_stalactite_dest_relocation',
'spell_stalactite_mod_dest_height',
'spell_s92306_crystal_storm',
'spell_slabhide_crystal_storm_periodic',
'spell_s92300_crystal_storm',
'spell_slabhide_crystal_storm');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81035, 'spell_slabhide_stalactite'),
(81028, 'spell_slabhide_stalactite_summon'),
(80650, 'spell_slabhide_stalactite_summon'),
(80654, 'spell_slabhide_stalactite_dest_relocation'),
(80643, 'spell_slabhide_stalactite_dest_relocation'),
(92653, 'spell_slabhide_stalactite_dest_relocation'),
(80647, 'spell_slabhide_stalactite_dest_relocation'),
(92309, 'spell_slabhide_stalactite_dest_relocation'),
(92306, 'spell_slabhide_crystal_storm_periodic');
