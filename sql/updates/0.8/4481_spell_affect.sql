DELETE FROM `spell_affect` WHERE `entry` IN (16544,16086) AND `effectId`=2;
INSERT INTO `spell_affect` VALUES 
(16544,2,0,0,0,0,0,4,0),
(16086,2,0,0,0,0,0,4,0);
