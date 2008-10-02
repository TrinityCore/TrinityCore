-- removing old script names that does no longer exist
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (12198,14982,857,12197,7427,347,15007,2804);
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (9564,12136,3149,12137,9566,3150,9559,9558);
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 197;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (11328, 11260);
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (80, 1236, 3578, 40, 1358, 1360, 5996, 1426, 1094, 674);
