UPDATE `creature_template` SET `ScriptName`='npc_atbt_flamewear' WHERE  `entry`=127233;
UPDATE `creature_template` SET `ScriptName`='npc_atbt_battleship_controller' WHERE  `entry`=125819;
UPDATE `creature_template` SET `ScriptName`='npc_atbt_battleship' WHERE  `entry`=125771;
UPDATE `creature_template` SET `ScriptName`='boss_worldbreaker' WHERE  `entry`=122450;
UPDATE `creature_template` SET `ScriptName`='npc_riathia_silverstar' WHERE  `entry`=152238;
UPDATE `creature_template` SET `ScriptName`='npc_shandris_feathermoon' WHERE  `entry`=153617;
UPDATE `creature_template` SET `ScriptName`='npc_hirano' WHERE  `entry`=152889;


DELETE FROM `spell_proc` WHERE `SpellId` IN (135286);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(135286, 0, 7, 0x800, 0x0, 0x0, 0x0, 0x10, 1, 2, 0x403, 0x10, 0, 0, 0, 0, 0);
