DELETE FROM spell_script_names WHERE scriptname = "spell_garrison_hearthstone";
INSERT INTO spell_script_names VALUES
(171253, "spell_garrison_hearthstone");

UPDATE `gameobject_template` SET `type` = '10' , `IconName` = 'architect' , `castBarCaption` = 'Finalizing' , `size` = '2' , `Data0` = '1691' , `Data3` = '3000' , `Data10` = '172083' , `Data14` = '83562' , `Data23` = '1' WHERE `entry` = '236192'; 

UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 232651 WHERE hordeGameObjectId = 231217;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 233251 WHERE hordeGameObjectId = 233248;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 232652 WHERE hordeGameObjectId = 231964;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 233250 WHERE hordeGameObjectId = 233249;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 236193 WHERE hordeGameObjectId = 236175;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 236191 WHERE hordeGameObjectId = 236176;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 236190 WHERE hordeGameObjectId = 236177;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 236192 WHERE hordeGameObjectId = 236185;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 236261 WHERE hordeGameObjectId = 236186;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 236262 WHERE hordeGameObjectId = 236187;
UPDATE garrison_plot_finalize_info SET allianceGameObjectId = 236263 WHERE hordeGameObjectId = 236188;

UPDATE garrison_plot_finalize_info SET allianceAnimKitId = 1696;

UPDATE `garrison_plot_finalize_info` SET allianceX = 1821.485474, allianceY = 224.588226, allianceZ = 72.231239, allianceO = 4.989633 WHERE garrPlotInstanceId = 18;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1827.946289, allianceY = 203.761459, allianceZ = 71.985886, allianceO = 1.867673 WHERE garrPlotInstanceId = 19;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1801.333862, allianceY = 196.047028, allianceZ = 70.075287, allianceO = 1.985483 WHERE garrPlotInstanceId = 20;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1866.839478, allianceY = 299.852539, allianceZ = 81.660515, allianceO = 4.773645 WHERE garrPlotInstanceId = 22;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1897.111938, allianceY = 236.802429, allianceZ = 76.639420, allianceO = 2.810147 WHERE garrPlotInstanceId = 23;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1833.271606, allianceY = 272.268951, allianceZ = 76.639786, allianceO = 5.637586 WHERE garrPlotInstanceId = 24;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1876.053101, allianceY = 196.941452, allianceZ = 78.056396, allianceO = 2.535265 WHERE garrPlotInstanceId = 25;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1897.773926, allianceY = 88.440506, allianceZ = 83.526894, allianceO = 0.438259 WHERE garrPlotInstanceId = 59;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1851.819458, allianceY = 140.045349, allianceZ = 78.291664, allianceO = 1.176538 WHERE garrPlotInstanceId = 63;
UPDATE `garrison_plot_finalize_info` SET allianceX = 2016.773926, allianceY = 171.132477, allianceZ = 84.216103, allianceO = 3.811550 WHERE garrPlotInstanceId = 67;
UPDATE `garrison_plot_finalize_info` SET allianceX = 1910.755981, allianceY = 345.062317, allianceZ = 88.965790, allianceO = 4.380958 WHERE garrPlotInstanceId = 81;

DELETE FROM gameobject WHERE guid = 19728061;
