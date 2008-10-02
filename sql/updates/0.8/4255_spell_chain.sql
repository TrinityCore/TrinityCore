/* dependent from 14752 */
DELETE FROM `spell_chain` WHERE `spell_id` IN (27681,32999);

INSERT INTO `spell_chain` VALUES
(27681,14752,14752,2),
(32999,27681,14752,3);
