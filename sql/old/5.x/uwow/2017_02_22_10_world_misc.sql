UPDATE `creature_template` SET `faction`='35' WHERE (`entry`='64297');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('114168', 'spell_warl_dark_apotheosis');

DELETE FROM `spell_trigger` WHERE (`spell_id`='144841') AND (`spell_trigger`='146874') AND (`option`='0') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');
DELETE FROM `spell_trigger` WHERE (`spell_id`='144841') AND (`spell_trigger`='146874') AND (`option`='20') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');
DELETE FROM `spell_trigger` WHERE (`spell_id`='146874') AND (`spell_trigger`='144859') AND (`option`='35') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `comment`) VALUES ('5217', '146874', '144841', 'Item - Druid T16 Feral 4P Bonus');

DELETE FROM `spell_proc_event` WHERE `entry` IN (146874);
INSERT INTO `spell_proc_event` VALUES (146874, 0, 0, 0, 268435456, 2097152, 4096, 0, 0, 0, 100, 0, 7);

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `aura`, `comment`) VALUES ('146874', '144859', '20', '10', '144841', 'Item - Druid T16 Feral 4P Bonus');

UPDATE `pet_stats` SET `spd`='-0.7' WHERE (`entry`='27829');