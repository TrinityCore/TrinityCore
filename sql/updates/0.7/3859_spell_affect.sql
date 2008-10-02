ALTER TABLE `spell_affect` CHANGE `SpellFamilyMask` `SpellFamilyMask` BIGINT( 20 ) UNSIGNED NOT NULL DEFAULT '0';

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 549755813888 WHERE `SpellId` = 469;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 469;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 17179869184 WHERE `SpellId` = 1680;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 1680;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 1099511627776 WHERE `SpellId` = 2895;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 2895;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 4294967296 WHERE `SpellId` = 3600;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 3600;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 2199023255552 WHERE `SpellId` = 6150;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 6150;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 549755813888 WHERE `SpellId` = 11958;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 11958;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 137438953472 WHERE `SpellId` = 12043;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 12043;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 8589934592 WHERE `SpellId` = 12536;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 12536;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 549755813888 WHERE `SpellId` = 16188;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 16188;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 68719476736 WHERE `SpellId` = 17364;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 17364;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 4194304 WHERE `SpellId` = 18223;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 18223;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 1099511627776 WHERE `SpellId` = 20216;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 20216;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 137438953472 WHERE `SpellId` = 20218;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 20218;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 8796093022208 WHERE `SpellId` = 24932;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 24932;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 68719476736 WHERE `SpellId` = 27243;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 27243;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 17592186044416 WHERE `SpellId` = 29166;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 29166;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 17179869184 WHERE `SpellId` = 31789;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 31789;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 68719476736 WHERE `SpellId` = 32175;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 32175;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 17179869184 WHERE `SpellId` = 32546;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 32546;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 137438953472 WHERE `SpellId` = 33076;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 33076;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 1099511627776 WHERE `SpellId` = 33745;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 33745;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 68719476736 WHERE `SpellId` = 33763;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 33763;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 137438953472 WHERE `SpellId` = 33786;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 33786;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 1125899906842624 WHERE `SpellId` = 34074;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 34074;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 4294967296 WHERE `SpellId` = 34120;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 34120;

UPDATE `spell_affect` SET  `SpellFamilyMask` = `SpellFamilyMask` + 1099511627776 WHERE `SpellId` = 34433;
UPDATE `spell_affect` SET  `SpellId` = '0' WHERE `SpellId` = 34433;
