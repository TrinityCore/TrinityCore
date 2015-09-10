--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47669;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `Comment`) VALUES
(13, 1, 47669, 0, 1, 0, 48048, 0,0, "Awaken Subboss");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 48048;
INSERT INTO `spell_linked_spell` VALUES (48048, 47669, 0, 'Awaken Subboss');
