UPDATE `creature_template` SET `spell2`='0' WHERE (`entry`='5925');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('8178', 'spell_sha_grounding_totem');
UPDATE `spell_proc_event` SET `procFlags`='139264' WHERE (`entry`='8178') AND (`effectmask`='7');

DELETE FROM `spell_proc_event` WHERE (`entry`='974') AND (`effectmask`='7');
INSERT INTO `spell_proc_event` (`entry`, `procFlags`) VALUES ('974', '1048576');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('34026', '34720', '109306', '30', '1', 'Thrill of the Hunt');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('117050', '34720', '109306', '30', '1', 'Thrill of the Hunt');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('131894', '34720', '109306', '30', '1', 'Thrill of the Hunt');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('109259', '34720', '109306', '30', '1', 'Thrill of the Hunt');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('3674', '34720', '109306', '30', '1', 'Thrill of the Hunt');

DELETE FROM `spell_proc_event` WHERE `entry` IN (109306);
INSERT INTO `spell_proc_event` VALUES (109306, 0, 0, 2048+4096+131072, 2147483648, 16777216+256+1, 4+8192, 0, 0, 0, 0, 0, 7);


INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('13004', 'id: %d %s duration: %d caster: %s guid: %d');

UPDATE `spell_bonus_data` SET `ap_dot_bonus`='0.391' WHERE (`entry`='53301');

UPDATE `spell_group_stack_rules` SET `stack_rule`='3' WHERE (`group_id`='1118');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('1118', '117666');
UPDATE `spell_group_stack_rules` SET `stack_rule`='3' WHERE (`group_id`='1250');
UPDATE `spell_group` SET `id`='1250' WHERE (`id`='1024') AND (`spell_id`='109773');