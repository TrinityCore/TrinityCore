-- 2012-05-19 12:48:24 SourceEntry 52264 in `condition` table, has incorrect SourceGroup 0 (spell effectMask) set , ignoring.
UPDATE `conditions` SET `SourceGroup`=1 WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=0 AND `SourceEntry`=52264 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=29 AND `ConditionTarget`=0 AND `ConditionValue1`=28653 AND `ConditionValue2`=5 AND `ConditionValue3`=0;

-- 2012-05-19 12:48:18 Quest 384 has `ZoneOrSort` = -304 but `RequiredSkillId` does not have a corresponding value (185).
-- It is not clear if cooking was required on 3.3.5, so reverting it to its original state (however we are sure it is not required in Cata)
UPDATE `quest_template` SET `RequiredSkillId`=185, `RequiredSkillPoints`=1 WHERE `Id`=384;
