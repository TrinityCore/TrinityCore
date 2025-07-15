--
UPDATE `creature_template_addon` SET `SheathState`=0 WHERE `entry` IN (11280,30731,32643,34045);
UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry` =11316;

UPDATE `creature_addon` SET `SheathState`=0, `StandState`=5 WHERE `guid` =135230;-- fix phantom guest sit on medium chair
UPDATE `creature_addon` SET `SheathState`=1 WHERE `guid` IN (8143,8146,8147,63387,78195,78196,78197,78198,82292,112378);
