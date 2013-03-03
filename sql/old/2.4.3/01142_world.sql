DELETE from `spell_affect` where entry=16999 and effectId=0;
DELETE from `spell_affect` where entry=16999 and effectId=2;
INSERT INTO `spell_affect` VALUES (16999, 0, 0x1000001000);
INSERT INTO `spell_affect` VALUES (16999, 2, 0x1000001000);
DELETE from `spell_affect` where entry=16998 and effectId=0;
DELETE from `spell_affect` where entry=16998 and effectId=2;
INSERT INTO `spell_affect` VALUES (16998, 0, 0x1000001000);
INSERT INTO `spell_affect` VALUES (16998, 2, 0x1000001000);
