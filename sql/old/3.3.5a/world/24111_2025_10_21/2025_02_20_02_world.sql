UPDATE `playercreateinfo_action` SET `action`=20154 WHERE `action`=21084;

DELETE FROM `spell_ranks` WHERE `first_spell_id`=20154;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(20154,20154,1),
(20154,21084,2);

UPDATE `trainer_spell` SET `SpellId`=10321 WHERE `SpellId`=20271;
