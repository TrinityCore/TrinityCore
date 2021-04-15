DELETE FROM `spell_script_names` WHERE `spell_id`=-19572;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-19572,'spell_hun_improved_mend_pet');

UPDATE `spell_proc_event` SET `procFlags`=0x40000 WHERE `entry` = -19572;
