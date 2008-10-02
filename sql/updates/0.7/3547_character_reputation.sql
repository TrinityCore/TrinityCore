/* alliance */
UPDATE `character_reputation`,`character` SET `character_reputation`.`flags` = 17 
WHERE `character_reputation`.`guid` = `character`.`guid`  
  AND (`character_reputation`.`faction` = 47 or `character_reputation`.`faction` = 54 or `character_reputation`.`faction` = 69 or `character_reputation`.`faction` = 72 or `character_reputation`.`faction` = 930 )
  AND (`character`.`race` = 1 OR `character`.`race` = 3 OR `character`.`race` = 4 OR `character`.`race` = 7 OR `character`.`race` = 11 );

/* horde */
UPDATE `character_reputation`,`character` SET `character_reputation`.`flags` = 17 
WHERE `character_reputation`.`guid` = `character`.`guid`  
  AND (`character_reputation`.`faction` = 68 or `character_reputation`.`faction` = 76 or `character_reputation`.`faction` = 81 or `character_reputation`.`faction` = 530 or `character_reputation`.`faction` = 911 )
  AND (`character`.`race` = 2 OR `character`.`race` = 5 OR `character`.`race` = 6 OR `character`.`race` = 8 OR `character`.`race` = 10 );

/* faction 47 */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 47 , 20, '0', '17' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 47 , 20, '0',  '2' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 54 */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 54 , 18, '0', '17' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 54 , 18, '0',  '2' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 68 */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 68 , 17, '0',  '2' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 68 , 17, '0', '17' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 69 */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 69 , 21, '0', '17' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 69 , 21, '0',  '2' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 72 */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 72 , 19, '0', '17' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 72 , 19, '0',  '2' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 76 */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 76 , 14, '0',  '2' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 76 , 14, '0', '17' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 81 */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 81 , 16, '0',  '2' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 81 , 16, '0', '17' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 530 */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 530, 15, '0',  '2' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 530, 15, '0', '17' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 911 (B.Elf) */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 911, 15, '0',  '2' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 911, 15, '0', '17' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

/* faction 930 (Dra) */
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 930 , 19, '0', '17' 
FROM `character` WHERE `race` = 1 OR `race` = 3 OR `race` = 4 OR `race` = 7 OR `race` = 11;
INSERT IGNORE INTO `character_reputation` SELECT `character`.`guid`, 930 , 19, '0',  '2' 
FROM `character` WHERE `race` = 2 OR `race` = 5 OR `race` = 6 OR `race` = 8 OR `race` = 10;

