DELETE FROM `spell_affect` WHERE `entry` IN (20216) AND `effectId`=0;
INSERT INTO `spell_affect` VALUES 
(20216,0,0,0,0,0,0,3223322624,0);

DELETE FROM `spell_affect` WHERE `entry` IN (31842) AND `effectId`=0;
INSERT INTO `spell_affect` VALUES 
(31842,0,0,126,0,0,0,0,0);

DELETE FROM `spell_affect` WHERE `entry` IN (31834) AND `effectId`=0;
INSERT INTO `spell_affect` VALUES 
(31834,0,0,0,0,0,0,2147483648,0);

DELETE FROM `spell_affect` WHERE `entry` IN (20224,20225,20330,20331,20332) AND `effectId`=0;
INSERT INTO `spell_affect` VALUES 
(20224,0,0,0,0,0,0,134218752,0),
(20225,0,0,0,0,0,0,134218752,0),
(20330,0,0,0,0,0,0,134218752,0),
(20331,0,0,0,0,0,0,134218752,0),
(20332,0,0,0,0,0,0,134218752,0);

DELETE FROM `spell_affect` WHERE `entry` IN (20244,20245) AND `effectId`=0;
INSERT INTO `spell_affect` VALUES 
(20244,0,0,0,0,0,0,65536,0),
(20245,0,0,0,0,0,0,65536,0);
