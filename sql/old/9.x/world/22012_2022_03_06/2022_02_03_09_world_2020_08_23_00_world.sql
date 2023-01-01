--
-- Drop previous functions/views if any
DROP VIEW IF EXISTS `vw_disables_with_labels`;

-- Create the view
CREATE SQL SECURITY INVOKER VIEW `vw_disables_with_labels` AS
(SELECT (
        CASE
            WHEN `sourceType` = 0 THEN 'DISABLE_TYPE_SPELL'
        WHEN `sourceType` = 1 THEN 'DISABLE_TYPE_QUEST'
        WHEN `sourceType` = 2 THEN 'DISABLE_TYPE_MAP'
        WHEN `sourceType` = 3 THEN 'DISABLE_TYPE_BATTLEGROUND'
        WHEN `sourceType` = 4 THEN 'DISABLE_TYPE_ACHIEVEMENT_CRITERIA'
        WHEN `sourceType` = 5 THEN 'DISABLE_TYPE_OUTDOORPVP'
        WHEN `sourceType` = 6 THEN 'DISABLE_TYPE_VMAP'
        WHEN `sourceType` = 7 THEN 'DISABLE_TYPE_MMAP'
        WHEN `sourceType` = 8 THEN 'DISABLE_TYPE_LFG_MAP'
            ELSE `sourceType`
        END
    ) AS `sourceType`,
    `entry`,
    `flags`,
    `params_0`,
    `params_1`,
    `comment`
 FROM disables);
