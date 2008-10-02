UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 549755813888 WHERE `Category` = 631;
UPDATE `spell_affect` SET  `Category` = 0 WHERE `Category` = 631;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 549755813888 WHERE `Category` = 1175;
UPDATE `spell_affect` SET  `Category` = 0 WHERE `Category` = 1175;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 8589934592 WHERE `Category` = 1169;
UPDATE `spell_affect` SET  `Category` = 0 WHERE `Category` = 1169;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 8589934592 WHERE `Category` = 1179;
UPDATE `spell_affect` SET  `Category` = 0 WHERE `Category` = 1179;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 34359738368 WHERE `Category` = 634;
UPDATE `spell_affect` SET  `Category` = 0 WHERE `Category` = 634;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 274877906944 WHERE `Category` = 931;
UPDATE `spell_affect` SET  `Category` = 0 WHERE `Category` = 931;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 1099511627776 WHERE `Category` = 30;
UPDATE `spell_affect` SET  `Category` = 0 WHERE `Category` = 30;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 8589934592 WHERE `SpellId` = 5375;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 5375;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 68719476736 WHERE (entry=29836 OR entry=29859 OR entry=29860 OR entry=29861  OR entry=29862);

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 25769803776 WHERE (entry=14057 OR entry=14128 OR entry=14132 OR entry=14135  OR entry=14136 OR entry=14137 OR entry=14143 OR entry=14149  OR entry=38389);

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` | 34359738368 WHERE (entry=14057 OR entry=14128 OR entry=14132 OR entry=14135  OR entry=14136 OR entry=14137 OR entry=14143 OR entry=14149  OR entry=38389);

UPDATE `spell_affect` SET `SpellFamilyMask` = '549764202496' WHERE `entry` =34323 AND `effectId` =0 LIMIT 1;

UPDATE `spell_affect` SET  `SpellFamilyMask` = 38658768896 WHERE (entry=14179 OR entry=37171);

UPDATE `spell_affect` SET  `SpellFamilyMask` = 4406678954000 WHERE (entry=15257 OR entry=15331 OR entry=15332 OR entry=15333  OR entry=15334);
UPDATE `spell_affect` SET  `SkillID` = 0 WHERE (entry=15257 OR entry=15331 OR entry=15332 OR entry=15333  OR entry=15334);

UPDATE `spell_affect` SET  `SpellFamilyMask` = 0 WHERE (entry=29836 OR entry=29859);