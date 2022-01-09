ALTER TABLE `spell_dbc` 
CHANGE COLUMN `Comment` `SpellName` varchar(128) NOT NULL AFTER `SpellTargetRestrictionsId`;
