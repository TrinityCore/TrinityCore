DELETE FROM `spell_proc` WHERE `SpellId` IN (392988, 405216);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392988,0x00,6,0x10200400,0x00000000,0x00000020,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0), -- Divine Image
(405216,0x00,6,0x10309EC1,0x00020002,0x00508024,0x00620044,0x0,0x0,0x7,0x4,0x403,0x0,0x0,0,0,0,0); -- Divine Image

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_divine_image','spell_pri_divine_image_spell_triggered','spell_pri_divine_image_stack_timer');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(392988,'spell_pri_divine_image'),
(405216,'spell_pri_divine_image_spell_triggered'),
(405963,'spell_pri_divine_image_stack_timer'),
(409387,'spell_pri_divine_image_stack_timer');

UPDATE `creature_template` SET `unit_flags`=0x2000000,`BaseAttackTime`=2000,`ScriptName`='npc_pet_pri_divine_image' WHERE `entry`=198236;

DELETE FROM `creature_template_addon` WHERE `entry`=198236;
INSERT INTO `creature_template_addon` (`entry`,`AnimTier`,`SheathState`) VALUES
(198236,2,0);

DELETE FROM `creature_template_difficulty` WHERE `Entry`=198236 AND `DifficultyID`!=0;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=198236;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(198236, 2, 0, 1, 1, 0, 0, NULL);
