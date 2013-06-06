-- Update mod rep command name
UPDATE `command` SET
    `name` = 'modify reputation',
    `help` = 'Syntax: .modify reputation #repId (#repvalue | $rankname [#delta])\nSets the selected players reputation with faction #repId to #repvalue or to $reprank.\nIf the reputation rank name is provided, the resulting reputation will be the lowest reputation for that rank plus the delta amount, if specified.\nYou can use \'.pinfo rep\' to list all known reputation ids, or use \'.lookup faction $name\' to locate a specific faction id.'
WHERE `name` = 'modify rep';

-- Fix "2012-05-20 06:46:00 ERROR: SourceEntry 52264 in `condition` table, has incorrect SourceGroup 0 (spell effectMask) set , ignoring."
UPDATE `conditions` SET
    `SourceGroup` = 1,
    `SourceId` = 0
WHERE
    `SourceTypeOrReferenceId` = 13 AND
    `SourceEntry` = 52264 AND
    `ConditionTypeOrReference` = 29 AND
    `ConditionValue1` = 28653 AND
    `ConditionValue2` = 5;
