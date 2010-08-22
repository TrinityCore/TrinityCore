-- spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (66870,67621,67622,67623,-66683,-67661);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(66870,-66823,1, 'Remove Paralytic Toxin when hit by Burning Bite'),
(67621,-67618,1, 'Remove Paralytic Toxin when hit by Burning Bite'),
(67622,-67619,1, 'Remove Paralytic Toxin when hit by Burning Bite'),
(67623,-67620,1, 'Remove Paralytic Toxin when hit by Burning Bite');
(-66683,68667,0, 'Icehowl - Surge of Adrenaline'),
(-67661,68667,0, 'Icehowl - Surge of Adrenaline');