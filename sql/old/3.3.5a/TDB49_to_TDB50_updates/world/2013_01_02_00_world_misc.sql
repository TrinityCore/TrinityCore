DELETE FROM `creature_template_addon` WHERE `entry`=32535;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(32535, 0, 0, 0x3020400, 0x1, 0, '60534');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=32535;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUE
(32535, 61245, 1, 0);
