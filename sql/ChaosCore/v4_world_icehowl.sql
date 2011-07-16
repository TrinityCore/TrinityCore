-- Icehowl Surge of Adrenaline
-- The DELETE with 4 ids is only to make sure there wont be anymore wrong ids with this trigger, there is no misstypo here.
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-66683,-67660,-67661,-67662);
INSERT INTO `spell_linked_spell` VALUES
(-66683,68667,2,'Icehowl - Surge Of Adrenaline'),
(-67660,68667,2,'Icehowl - Surge Of Adrenaline');