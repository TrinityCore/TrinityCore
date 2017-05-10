-- Quest item "Drain Schematics" should be only obtainable if:
-- 1) player has completed quest 9720 "Balance Must Be Preserved"
-- 2) player has no quest 9731 "Drain Schematics"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '1' AND `SourceEntry` = '24330';
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`) VALUES
('1','18088','24330','0','0','8','0','9720','0','0','0'),
('1','18088','24330','0','0','9','0','9731','0','0','1'),
('1','18089','24330','0','0','8','0','9720','0','0','0'),
('1','18089','24330','0','0','9','0','9731','0','0','1'),
('1','18340','24330','0','0','8','0','9720','0','0','0'),
('1','18340','24330','0','0','9','0','9731','0','0','1'),
('1','20088','24330','0','0','8','0','9720','0','0','0'),
('1','20088','24330','0','0','9','0','9731','0','0','1'),
('1','20089','24330','0','0','8','0','9720','0','0','0'),
('1','20089','24330','0','0','9','0','9731','0','0','1');

-- Set drop chance to normal(non-quest)
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = abs(`ChanceOrQuestChance`) WHERE (`item` = '24330');
