--
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` IN (381,387,388,389,1162,2024,2032,3211,3212));
UPDATE `gameobject` SET `orientation` = -3.14057135581970214, `rotation0` = -0.69435930252075195, `rotation1` = -0.11721324920654296, `rotation2` = -0.70044517517089843, `rotation3` = 0.116201192140579223, `VerifiedBuild` = 12340 WHERE `guid` = 13764 AND `id` = 381;
UPDATE `gameobject` SET `VerifiedBuild` = 12340 WHERE `guid` = 14230 AND `id` = 387;
UPDATE `gameobject` SET `rotation0` = 0.047839641571044921, `rotation1` = -0.09622573852539062, `rotation2` = -0.66555595397949218, `rotation3` = 0.738571107387542724, `VerifiedBuild` = 12340 WHERE `guid` = 14248 AND `id` = 388;
UPDATE `gameobject` SET `VerifiedBuild` = 12340 WHERE `guid` = 14231 AND `id` = 389;
UPDATE `gameobject` SET `rotation0` = 0.089822769165039062, `rotation1` = 0.053696632385253906, `rotation2` = 0.738206863403320312, `rotation3` = 0.666407644748687744, `VerifiedBuild` = 12340 WHERE `guid` = 13724 AND `id` = 1162;
UPDATE `gameobject` SET `rotation0` = 0.576801776885986328, `rotation1` = -0.173583984375, `rotation2` = 0.779712677001953125, `rotation3` = 0.170928075909614562, `VerifiedBuild` = 12340 WHERE `guid` = 30079 AND `id` = 2024;
UPDATE `gameobject` SET `position_x` = 758.9981689453125, `position_y` = -1467.18017578125, `position_z` = 78.80669403076171875, `orientation` = 3.019399642944335937, `rotation0` = -0.01018571853637695, `rotation1` = -0.09540081024169921, `rotation2` = 0.993555068969726562, `rotation3` = 0.060359541326761245, `VerifiedBuild` = 12340 WHERE `guid` = 30108 AND `id` = 2032;
UPDATE `gameobject` SET `VerifiedBuild` = 12340 WHERE `guid` = 18 AND `id` = 3211;
UPDATE `gameobject` SET `rotation0` = 0.081969738006591796, `rotation1` = -0.05109977722167968, `rotation2` = 0.380990982055664062, `rotation3` = 0.919519245624542236, `VerifiedBuild` = 12340 WHERE `guid` = 22 AND `id` = 3212;
UPDATE `gameobject` SET `animprogress` = 255 WHERE `id` IN (381,387,388,389,1162,2024,2032,3211,3212);
