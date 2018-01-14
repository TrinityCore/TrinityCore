DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13,17) AND `SourceEntry`=32307;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 32307, 0, 0, 31, 0, 3, 17148, 0, 0, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is unit Kil''sorrow Deathsworn.'),
(13, 3, 32307, 0, 0, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is dead'),
(13, 3, 32307, 0, 1, 31, 0, 3, 18658, 0, 0, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is unit Kil''sorrow Ritualist.'),
(13, 3, 32307, 0, 1, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is dead'),
(13, 3, 32307, 0, 2, 31, 0, 3, 17147, 0, 0, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is unit Kil''sorrow Cultist.'),
(13, 3, 32307, 0, 2, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is dead'),
(13, 3, 32307, 0, 3, 31, 0, 3, 17146, 0, 0, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is unit Kil''sorrow Spellbinder.'),
(13, 3, 32307, 0, 3, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is dead'),
(13, 3, 32307, 0, 4, 31, 0, 3, 18391, 0, 0, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is unit Giselda the Crone.'),
(13, 3, 32307, 0, 4, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Spell Plant Warmaul Ogre Banner (effects 0 & 1) will hit the potential target of the spell if target is dead');
