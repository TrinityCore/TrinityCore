--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (12479, 12480, -12480)  AND `spell_effect` IN (12480, 530, -530);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`)  VALUES 
(12479, 12480, 0, 'Hex of Jammal''an'),
(12480, 530, 0, 'Hex of Jammal''an'),
(-12480, -530, 0, 'Hex of Jammal''an');

UPDATE `smart_scripts` SET `event_type`=0, `Comment`= "Jammal'an the Prophet - In combat - Cast 'Hex of Jammal'an' (Phase 1)" WHERE `entryorguid`=5710 AND `source_Type`=0 AND `id`=5;
