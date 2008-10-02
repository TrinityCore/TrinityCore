ALTER TABLE `spell_proc_event`
  ADD COLUMN `SpellFamilyName` smallint(6) unsigned NOT NULL default '0' AFTER `SkillID`,
  ADD COLUMN `SpellFamilyMaskNew` bigint(11) unsigned NOT NULL default '0' AFTER `SpellFamilyMask`;

UPDATE `spell_proc_event`
  SET `SpellFamilyMaskNew` = `SpellFamilyMask` WHERE `SpellFamilyMask` > 0;

UPDATE `spell_proc_event`
  SET `SpellFamilyMaskNew` = 4294967295 + `SpellFamilyMask` + 1 WHERE `SpellFamilyMask` < 0;

ALTER TABLE `spell_proc_event`
  DROP COLUMN `SpellFamilyMask`,
  CHANGE COLUMN `SpellFamilyMaskNew` `SpellFamilyMask` bigint(40) unsigned NOT NULL default '0';


DELETE FROM `spell_proc_event` WHERE `entry` IN ( 31833, 31835, 31836 );
INSERT INTO `spell_proc_event` VALUES 
(31833,0,0,0,10,2147483648,16384,0), 
(31835,0,0,0,10,2147483648,16384,0), 
(31836,0,0,0,10,2147483648,16384,0); 

DELETE FROM `spell_proc_event` WHERE `entry` IN ( 33648 );
INSERT INTO `spell_proc_event` VALUES 
(33648,0,0,0,0,0,4096,0); 

DELETE FROM `spell_proc_event` WHERE `entry` IN ( 34749 );
INSERT INTO `spell_proc_event` VALUES 
(34749,0,0,0,0,0,33554432,0); 


DELETE FROM `spell_proc_event` WHERE `entry` IN ( 28789 );
INSERT INTO `spell_proc_event` VALUES 
(28789,0,0,0,10,3221225472,16384,0); /* HL FoL */

DELETE FROM `spell_proc_event` WHERE `entry` IN ( 26119 );
INSERT INTO `spell_proc_event` VALUES 
(26119,0,0,0,10,2416967683,16384,0); /* LB CL and shaman shocks */

UPDATE `spell_proc_event` SET `spellFamilyName`=8 WHERE `entry` IN ( 14195,14194,14190,14193,14186 );

DELETE FROM `spell_proc_event` WHERE `entry` IN ( 20501, 20500 );
INSERT INTO `spell_proc_event` VALUES 
(20500,0,0,0,4,268435456,16384,0), /* BR */
(20501,0,0,0,4,268435456,16384,0); /* BR */

