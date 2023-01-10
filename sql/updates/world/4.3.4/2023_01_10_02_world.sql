UPDATE `creature_template_addon` SET `SheathState`= 1 WHERE `entry` IN (11280, 11316, 32643);
UPDATE `creature_template_addon` SET `SheathState`= 2 WHERE `entry` IN (46406, 46417);
UPDATE `creature_addon` SET `SheathState`= 1 WHERE `guid` IN (8143, 8146, 8147, 63387, 82292, 135230);
UPDATE `creature_addon` SET `SheathState`= 0 WHERE `guid`= 112378;
