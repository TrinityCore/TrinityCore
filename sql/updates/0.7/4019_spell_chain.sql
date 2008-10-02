DELETE FROM `spell_chain` WHERE `spell_id` IN (33776,31785);

INSERT INTO `spell_chain` VALUES
(31785,     0, 31785, 1),
(33776, 31785, 31785, 2);
