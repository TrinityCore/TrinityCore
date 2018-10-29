DELETE FROM `spell_script_names` WHERE `spell_id` IN (16336, 51966, 51971, 52010, 54089);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(16336, 'spell_stratholme_haunting_phantoms'),
(51966, 'spell_scourge_disguise'),
(51971, 'spell_scourge_disguise_instability'),
(52010, 'spell_scourge_disguise_expiring'),
(54089, 'spell_drop_disguise');


DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 54089;

