-- 
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_ioc_seaforium_blast_credit' AND `spell_id` IN (67813,67814);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(67813, 'spell_ioc_seaforium_blast_credit'),
(67814, 'spell_ioc_seaforium_blast_credit');
