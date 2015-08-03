UPDATE `creature_template` SET `baseattacktime`=1500,`unit_flags`=32832 WHERE `entry`=52157;

UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=52529;

UPDATE `creature_template_addon` SET `auras`=97122 WHERE `entry` =52529;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=52529;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(52529, 96328, 3, 0);

DELETE FROM `game_graveyard_zone` WHERE `ghost_zone`=1977;
INSERT INTO `game_graveyard_zone` (`id`, `ghost_zone`, `faction`) VALUES
(1969, 1977, 0); -- Stranglethorn Vale, Zul\'Gurub GY
