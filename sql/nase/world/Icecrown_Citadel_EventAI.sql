REPLACE INTO `creature_ai_scripts` VALUES (37571001, 37571, 2, 0, 100, 7, 20, 18, 0, 16000, 11, 72065, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (3757002, 37571, 0, 0, 100, 7, 16000, 12000, 16000, 12000, 11, 72057, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37595001, 37595, 2, 0, 100, 7, 50, 0, 15000, 15000, 11, 70451, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37595002, 37595, 0, 0, 100, 7, 10000, 10000, 10000, 10000, 11, 70437, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37663001, 37663, 0, 0, 100, 7, 10000, 10000, 10000, 10000, 11, 72960, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37663002, 37663, 0, 0, 100, 7, 12000, 12000, 12000, 12000, 11, 70645, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37664001, 37664, 0, 0, 100, 7, 10000, 10000, 10000, 10000, 11, 70409, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37664002, 37664, 2, 0, 100, 7, 80, 40, 12000, 12000, 11, 70410, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37664003, 37664, 0, 0, 100, 7, 9000, 15000, 7000, 16000, 11, 70407, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37662001, 37662, 0, 0, 100, 7, 11000, 11000, 11000, 11000, 11, 70449, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37134001, 37134, 0, 0, 100, 7, 3000, 15000, 15000, 15000, 11, 71249, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37134002, 37134, 2, 0, 100, 7, 100, 99, 0, 10000, 11, 71705, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37134003, 37134, 0, 0, 100, 7, 10000, 10000, 10000, 10000, 11, 71252, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37134004, 37134, 0, 0, 100, 7, 4000, 16000, 16000, 16000, 11, 71251, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37133, 37133, 0, 0, 100, 7, 8000, 8000, 8000, 8000, 11, 41056, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37132001, 37132, 0, 0, 100, 7, 8000, 8000, 8000, 8000, 11, 71257, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37023001, 37023, 0, 0, 100, 7, 9000, 9000, 9000, 9000, 11, 73079, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37022, 37022, 0, 0, 100, 7, 12000, 12000, 12000, 12000, 11, 71150, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (37022003, 37022, 0, 0, 100, 7, 9000, 9000, 9000, 9000, 11, 71140, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_ai_scripts` VALUES (36880001, 36880, 0, 0, 100, 7, 12000, 12000, 12000, 12000, 11, 71114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `creature_template` SET `dmg_multiplier`=15, `baseattacktime`=2000, `AIName`='EventAI', `mechanic_immune_mask`=617299803 WHERE  `entry` in (37571, 
37595, 37595, 37663, 37664, 37662, 37134, 37133, 37132, 37023, 37022, 10404, 36880);

UPDATE `creature` SET `spawntimesecs`=90 WHERE  `id`=37985;


