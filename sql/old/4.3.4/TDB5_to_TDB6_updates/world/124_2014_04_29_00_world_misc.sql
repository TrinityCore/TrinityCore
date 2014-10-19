--
DELETE FROM `battlemaster_entry` WHERE `entry` IN (31979,37413,37298,32092);
INSERT INTO `battlemaster_entry` (`entry`, `bg_template`) VALUES
(31979, 1),
(37413, 1),
(37298, 1),
(32092, 1);

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80 WHERE `entry`=35410;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=35410;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
(35410, 43671, 1);
