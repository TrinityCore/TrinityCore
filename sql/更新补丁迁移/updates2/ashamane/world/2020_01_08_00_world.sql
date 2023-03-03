DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_create_healthstone';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('23517', 'spell_warl_create_healthstone');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=34130 AND `spell_effect`=23517 AND `type`=0;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (34130, 23517, 0, 'Create Healthstone');

