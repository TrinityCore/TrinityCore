DELETE FROM `spell_script_names` WHERE `spell_id` IN (-46951,23780,33896,37594,37705,23551,23552,23572);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-46951,'spell_warr_sword_and_board'),
(23780,'spell_item_aegis_of_preservation'),
(33896,'spell_item_desperate_defense'),
(37594,'spell_pri_item_greater_heal_refund'),
(37705,'spell_pal_item_healing_discount'),
(23551,'spell_sha_item_lightning_shield'),
(23552,'spell_sha_item_lightning_shield_trigger'),
(23572,'spell_sha_item_mana_surge');

DELETE FROM `spell_ranks` WHERE `first_spell_id` IN (46951);
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(46951, 46951, 1),
(46951, 46952, 2),
(46951, 46953, 3);
