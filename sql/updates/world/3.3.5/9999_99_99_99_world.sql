DELETE FROM `spell_script_names` WHERE `spell_id` IN (16336, 51971, 52010);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(16336, 'spell_stratholme_haunting_phantoms'),
(51971, 'spell_scourge_disguise_instability'),
(52010, 'spell_scourge_disguise_expiring');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 51966;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(51966, 51971, 1, 'Scourge Disguise applies Scourge Disguise Instability');

