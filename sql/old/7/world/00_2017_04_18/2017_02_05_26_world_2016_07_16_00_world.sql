--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (12699, 31225);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 31225, 0, 0, 29, 0, 17768, 10, 0, 0, 0, 0, "", "Spell 'Shimmering Vessel' (used for quest 'Redeeming the Dead') requires NPC 'Blood Knight Stillblade' to be within 10 yards"),
(17, 0, 12699, 0, 0, 36, 1, 0, 0, 0, 1, 0, 0, "", "Spell 'Summon Screecher Spirit' (used for quest 'Screecher Spirits') can only be used if target is dead AND"),
(17, 0, 12699, 0, 0, 31, 1, 3, 5307, 0, 0, 0, 0, "", "Spell 'Summon Screecher Spirit' (used for quest 'Screecher Spirits') can only be used if target is NPC 'Vale Screecher'"),
(17, 0, 12699, 0, 1, 36, 1, 0, 0, 0, 1, 0, 0, "", "Spell 'Summon Screecher Spirit' (used for quest 'Screecher Spirits') can only be used if target is dead AND"),
(17, 0, 12699, 0, 1, 31, 1, 3, 5308, 0, 0, 0, 0, "", "Spell 'Summon Screecher Spirit' (used for quest 'Screecher Spirits') can only be used if target is NPC 'Rogue Vale Screecher'");
