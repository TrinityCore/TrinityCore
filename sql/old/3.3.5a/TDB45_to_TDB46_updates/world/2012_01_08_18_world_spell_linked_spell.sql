-- add spell link for Temporary Electrical Charge
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='-52098' AND `spell_effect`='52092';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
('-52098', '52092', '0', 'Charge Up - Temporary Electrical Charge');
