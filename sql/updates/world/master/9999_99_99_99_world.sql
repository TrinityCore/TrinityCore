DELETE FROM `spell_proc` WHERE `SpellId` IN (392988, 405216);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392988,0x00,6,0x10200400,0x00000000,0x00000020,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0), -- Divine Image
(405216,0x00,6,0x10309EC1,0x00020002,0x00508024,0x00620040,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Divine Image

DELETE FROM `spell_script_names` WHERE `spell_id` IN (392988, 405216);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(392988, 'spell_pri_divine_image'),
(405216, 'spell_pri_divine_image_spell_triggered');

UPDATE `creature_template` SET `ScriptName`='npc_pet_pri_divine_image' WHERE `entry`=198236;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=198236;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(198236, 0, 0, 0, 1, 0, 0, NULL);
