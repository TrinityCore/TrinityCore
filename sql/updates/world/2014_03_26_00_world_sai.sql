DELETE FROM `smart_scripts` WHERE `entryorguid`=24601 AND `source_type`=0 AND `id`=2;

DELETE FROM `spell_script_names` WHERE `spell_id`=46374;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUE
(46374,'spell_windsoul_totem_aura');

