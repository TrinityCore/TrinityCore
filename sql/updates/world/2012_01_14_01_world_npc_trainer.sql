-- fix summon charger for horde
UPDATE `npc_trainer` SET `spell` = 34767 WHERE `spell` = 34766;
DELETE FROM `spell_required` WHERE `spell_id` = 34767 AND `req_spell` = 33391;
INSERT INTO `spell_required` (`spell_id`, `req_spell`) VALUES (34767, 33391);

-- fix summon charger for alliance
UPDATE `npc_trainer` SET `spell` = 23214 WHERE `spell` = 23215;
DELETE FROM `spell_required` WHERE `spell_id` = 23214 AND `req_spell` = 33391;
INSERT INTO `spell_required` (`spell_id`, `req_spell`) VALUES (23214, 33391);

-- fix dreadsteed for warlocks
UPDATE `npc_trainer` SET `spell` = 23161, `reqskill` = 0, `reqskillvalue` = 0 WHERE `spell` = 23160;
DELETE FROM `spell_required` WHERE `spell_id` = 23161 AND `req_spell` = 33391;
INSERT INTO `spell_required` (`spell_id`, `req_spell`) VALUES (23161, 33391);
