DELETE FROM `instance_encounters` WHERE  `entry` IN (447,793,1086,1121,1133,1135,1141,1271,1299);
DELETE FROM `criteria_data` WHERE  `criteria_id` IN (1826,3805,3806,3807,3808,3809,3810,3811,3812,3813,5544,5545,5546,5547,5548,6084,6133,6180,10066,10067,10219,10220,10568,10570,10758,11498,11500,12818,12825,12826,13041,13048,13049,13052,13059,13060,13094,13099,13102,13103,13109,13124,13133,13136,13187,13198,13255,13309,13311);
UPDATE `conditions` SET `SourceGroup`='3', `ConditionTypeOrReference`='31', `ConditionValue1`='3' WHERE  `SourceEntry`=36325;
UPDATE `conditions` SET `SourceGroup`='2' WHERE  `SourceEntry` IN (74758,75464,82192,88354,102499);
UPDATE `conditions` SET `SourceGroup`='4' WHERE  `SourceEntry`=126040;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='233248' WHERE  `garrPlotInstanceId`=18;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='231964' WHERE  `garrPlotInstanceId`=19;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='236186' WHERE  `garrPlotInstanceId`=20;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='233249' WHERE  `garrPlotInstanceId`=22;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='231217' WHERE  `garrPlotInstanceId`=23;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='236187' WHERE  `garrPlotInstanceId`=24;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='236188' WHERE  `garrPlotInstanceId`=25;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='236176' WHERE  `garrPlotInstanceId`=59;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='236177' WHERE  `garrPlotInstanceId`=63;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='236185' WHERE  `garrPlotInstanceId`=67;
UPDATE `garrison_plot_finalize_info` SET `allianceGameObjectId`='236175' WHERE  `garrPlotInstanceId`=81;
UPDATE `spell_scripts` SET `effIndex`='3' WHERE  `id`=66477;

