-- worgen intro
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 34884;
UPDATE `quest_template_addon` SET `ExclusiveGroup` = -14093 WHERE `ID` IN (14098, 14093);

DELETE FROM `conditions` WHERE `SourceEntry`=4756;
DELETE FROM `conditions` WHERE `SourceGroup`=170 AND `ConditionValue1`=14078;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 169, 4756, 0, 0, 28, 0, 14078, 0, 0, 1, 0, 0, '', 'Phase 169 until Quest 14078 not complete'),
(26, 170, 0, 0, 0, 28, 0, 14078, 0, 0, 0, 0, 0, '', 'Phase 170 until Quest 14078 complete');


DELETE FROM `spell_area` WHERE `area`=4756;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(59073, 4756, 14078, 0, 0, 0, 2, 1, 64, 0), -- phase 170
(49416, 4756, 14078, 0, 0, 0, 2, 1, 64, 0); -- Generic Quest Invisibility 1
