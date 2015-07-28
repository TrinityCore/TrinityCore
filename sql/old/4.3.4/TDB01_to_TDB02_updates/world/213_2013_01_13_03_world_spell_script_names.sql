-- Zul'drak Rat spell: Script assignment
DELETE FROM `spell_script_names` WHERE `spell_id`=50894;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUE
(50894,'spell_q12527_zuldrak_rat');
