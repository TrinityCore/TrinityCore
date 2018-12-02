DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17146,17147,17148,18064,18391);
UPDATE `creature_template` SET `AIname` = '', `ScriptName` = 'npc_nagrand_banner' WHERE `entry` IN (17138,17146,17147,17148,18064,18391,18413);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (32307, 32314);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(32307, 'spell_q9927_plant_warmaul_ogre_banner'),
(32314, 'spell_q9931_plant_kilsorrow_banner');

DELETE FROM `event_scripts` WHERE `id` in (11669, 11674);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (32307, 32314);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 32307, 0, 0, 31, 0, 3, 17146, 0, 0, 0, 0, 'conditition_nagrand_banner', 'Spell "Plant Warmaul Ogre Banner" (effects 0 & 1) will hit Kil\'sorrow Spellbinder.'),
(13, 3, 32307, 0, 0, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell "Plant Warmaul Ogre Banner" (effects 0 & 1) will hit if target is dead'),
(13, 3, 32307, 0, 1, 31, 0, 3, 17147, 0, 0, 0, 0, 'conditition_nagrand_banner', 'Spell "Plant Warmaul Ogre Banner" (effects 0 & 1) will hit Kil\'sorrow Cultist.'),
(13, 3, 32307, 0, 1, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell "Plant Warmaul Ogre Banner" (effects 0 & 1) will hit if target is dead'),
(13, 3, 32307, 0, 2, 31, 0, 3, 17148, 0, 0, 0, 0, 'conditition_nagrand_banner', 'Spell "Plant Warmaul Ogre Banner" (effects 0 & 1) will hit Kil\'sorrow Deathsworn.'),
(13, 3, 32307, 0, 2, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell "Plant Warmaul Ogre Banner" (effects 0 & 1) will hit if target is dead'),
(13, 3, 32307, 0, 3, 31, 0, 3, 18391, 0, 0, 0, 0, 'conditition_nagrand_banner', 'Spell "Plant Warmaul Ogre Banner" (effects 0 & 1) will hit Giselda the Crone.'),
(13, 3, 32307, 0, 3, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell "Plant Warmaul Ogre Banner" (effects 0 & 1) will hit if target is dead'),

(13, 3, 32314, 0, 0, 31, 0, 3, 17138, 0, 0, 0, 0, 'conditition_nagrand_banner', 'Spell "Plant Kil\'Sorrow Banner" (effects 0 & 1) will hit Warmaul Reaver.'),
(13, 3, 32314, 0, 0, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell "Plant Kil\'Sorrow Banner" (effects 0 & 1) will hit if target is dead.'),
(13, 3, 32314, 0, 1, 31, 0, 3, 18064, 0, 0, 0, 0, 'conditition_nagrand_banner', 'Spell "Plant Kil\'Sorrow Banner" (effects 0 & 1) will hit Warmaul Shaman.'),
(13, 3, 32314, 0, 1, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell "Plant Kil\'Sorrow Banner" (effects 0 & 1) will hit if target is dead.'),
(13, 3, 32314, 0, 2, 31, 0, 3, 18413, 0, 0, 0, 0, 'conditition_nagrand_banner', 'Spell "Plant Kil\'Sorrow Banner" (effects 0 & 1) will hit Zorbo the Advisor.'),
(13, 3, 32314, 0, 2, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell "Plant Kil\'Sorrow Banner" (effects 0 & 1) will hit if target is dead.');
