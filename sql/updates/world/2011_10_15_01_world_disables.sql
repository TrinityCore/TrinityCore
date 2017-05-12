
DELETE FROM `disables` WHERE `sourceType` = 0 AND `entry` IN (23397, 23398);
INSERT INTO `disables` VALUES
    (0, 23397, 3, '', '', 'CURRENTLY A SOURCE OF BUG ABUSE - Allows Warriors to stack Berserker Stance passive auras indefinitely and for use in all stances'),
    (0, 23398, 3, '', '', 'CURRENTLY A SOURCE OF BUG ABUSE - Allows Druids to stack Cat Form passive auras indefinitely and for use in all stances');
