--
DELETE FROM `conditions` WHERE `SourceEntry`=6383 AND SourceTypeOrReferenceId IN(19, 20);
INSERT INTO `conditions` VALUES
(19, 0, 6383, 0, 0, 28, 0, 235, 0, 0, 1, 0, 0, "", "Show quest 'The Ashenvale Hunt' if quest 'The Ashenvale Hunt' (breadcrumb) is not completed"),
(20, 0, 6383, 0, 0, 28, 0, 235, 0, 0, 1, 0, 0, "", "Show quest 'The Ashenvale Hunt' if quest 'The Ashenvale Hunt' (breadcrumb) is not completed"),
(19, 0, 6383, 0, 0, 28, 0, 742, 0, 0, 1, 0, 0, "", "Show quest 'The Ashenvale Hunt' if quest 'The Ashenvale Hunt' (breadcrumb) is not completed"),
(20, 0, 6383, 0, 0, 28, 0, 742, 0, 0, 1, 0, 0, "", "Show quest 'The Ashenvale Hunt' if quest 'The Ashenvale Hunt' (breadcrumb) is not completed"),
(19, 0, 6383, 0, 0, 28, 0, 6382, 0, 0, 1, 0, 0, "", "Show quest 'The Ashenvale Hunt' if quest 'The Ashenvale Hunt' (breadcrumb) is not completed"),
(20, 0, 6383, 0, 0, 28, 0, 6382, 0, 0, 1, 0, 0, "", "Show quest 'The Ashenvale Hunt' if quest 'The Ashenvale Hunt' (breadcrumb) is not completed");
