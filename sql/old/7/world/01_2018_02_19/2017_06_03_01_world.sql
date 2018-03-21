-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=69855 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 69855, 0, 0, 31, 0, 3, 37080, 0, 0, 0, 0, '', 'Spell Heal Wounded Mountaineer (effect 0) will hit the potential target of the spell if target is unit Wounded Coldridge Mountaineer.');

-- Deprecated quest in Dwarf Starting Area
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (3106,3107,3108,3109,3110,24494,24496,24526,24527,24528,24530,24531,24532,24533,26904,31150,31151);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1, 3106,0, '', '', 'Deprecated quest: Simple Rune'),
(1, 3107,0, '', '', 'Deprecated quest: Consecrated Rune'),
(1, 3108,0, '', '', 'Deprecated quest: Etched Rune'),
(1, 3109,0, '', '', 'Deprecated quest: Encrypted Rune'),
(1, 3110,0, '', '', 'Deprecated quest: Hallowed Rune'),
(1, 24494,0, '', '', 'Deprecated quest: Empowered Rune'),
(1, 24496,0, '', '', 'Deprecated quest: Arcane Rune'),
(1, 24526,0, '', '', 'Deprecated quest: Filling Up the Spellbook'),
(1, 24527,0, '', '', 'Deprecated quest: Your Path Begins Here'),
(1, 24528,0, '', '', 'Deprecated quest: The Power of the Light'),
(1, 24530,0, '', '', 'Deprecated quest: Oh, A Hunter''s Life For Me'),
(1, 24531,0, '', '', 'Deprecated quest: Getting Battle-Ready'),
(1, 24532,0, '', '', 'Deprecated quest: Evisceratin'' the Enemy'),
(1, 24533,0, '', '', 'Deprecated quest: Words of Power'),
(1, 26904,0, '', '', 'Deprecated quest: Corruption'),
(1, 31150,0, '', '', 'Deprecated quest: Elegant Rune'),
(1, 31151,0, '', '', 'Deprecated quest: Kick, Punch, It''s All in the Mind');
