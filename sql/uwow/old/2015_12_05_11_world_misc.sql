INSERT INTO `spell_proc_check` (`entry`, `checkspell`, `comment`) VALUES ('145091', '112092', 'Item - Warlock T16 4P Bonus');

DELETE FROM `spell_script_names` WHERE (`spell_id`='115422') AND (`ScriptName`='spell_warl_void_ray');

UPDATE `spell_dummy_trigger` SET `option`='8' WHERE (`spell_id`='143381') AND (`spell_trigger`='86040') AND (`option`='4') AND (`aura`='0');