DELETE FROM `spell_proc_event` WHERE `entry` IN (79134);
INSERT INTO `spell_proc_event` VALUES (79134, 0, 0, 256+1048576, 0, 0, 0, 0, 1, 0, 0, 0, 7);

DELETE FROM `spell_trigger` WHERE `spell_id` IN (79134);
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '3409', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '3409', 'Venomous Wounds');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '44289', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '44289', 'Venomous Wounds');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '8680', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '8680', 'Venomous Wounds');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '2818', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '2818', 'Venomous Wounds');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '5760', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '5760', 'Venomous Wounds');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '115194', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '115194', 'Venomous Wounds');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '113952', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '113952', 'Venomous Wounds');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '112961', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '112961', 'Venomous Wounds');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '51637', '2', '2', '115197', 'Venomous Wounds');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `effectmask`, `aura`, `comment`) VALUES ('79134', '79136', '20', '2', '2', '115197', 'Venomous Wounds');

INSERT INTO `spell_proc_check` (`entry`, `checkspell`, `hastalent`, `target`, `effectmask`, `comment`) VALUES ('79134', '-703', '1943', '1', '2', 'Venomous Wounds');

DELETE FROM `spell_script_names` WHERE (`spell_id`='703') AND (`ScriptName`='spell_rog_venomous_wounds');