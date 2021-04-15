--
INSERT INTO `battlemaster_entry` (`entry`, `bg_template`) VALUES (31979, 1);
INSERT INTO `battlemaster_entry` (`entry`, `bg_template`) VALUES (37413, 1);
INSERT INTO `battlemaster_entry` (`entry`, `bg_template`) VALUES (37298, 1);
INSERT INTO `battlemaster_entry` (`entry`, `bg_template`) VALUES (32092, 1);
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80 WHERE `entry`=35410;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES (35410, 43671, 1);
