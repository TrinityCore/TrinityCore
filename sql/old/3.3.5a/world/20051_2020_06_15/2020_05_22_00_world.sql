-- 
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry` IN (18445,18369,20812);
UPDATE `gameobject_template` SET `Data2`=300000, `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE `entry` IN (182521,182349,182350);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (182521,182349,182350) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18445,18369,20812) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1844500,1836900,2081200) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(182521, 1, 0 ,1,70, 0, 100, 0, 2, 0, 0,0,64,1,0,0,0,0,0,16,0,0,0,0, 0, 0, 0, 'Corkis Prison - On State Changed - Store Targetlist'),
(182521, 1, 1 ,2,61, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,19,18445,0,0,0, 0, 0, 0, 'Corkis Prison - Script - Send Targetlist'),
(182521, 1, 2 ,0,61, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,19,18445,0,0,0, 0, 0, 0, 'Corkis Prison - Script - Set Data'),
(18445, 0, 0 ,0,38, 0, 100, 0, 1, 1, 0,0,80,1844500,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Corki - On Data Set - Action list'),
(1844500, 9, 0 ,0,0, 0, 100, 0, 0, 0, 0,0,1,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Corki - Action list - Say'),
(1844500, 9, 1 ,0,0, 0, 100, 0, 0, 0, 0,0,33,18444,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Corki - Action list - Kill Credit'),
(1844500, 9, 2 ,0,0, 0, 100, 0, 4000, 4000, 0,0,69,0,0,0,0,0,0,8,0,0,0,-896.082, 8687.346, 170.455, 3.81311, 'Corki - Action listt - Move Foward'),
(1844500, 9, 3 ,0,0, 0, 100, 0, 4000, 4000, 0,0,41,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Corki - Action list - Despawn after 5 seconds'),
(182349, 1, 0 ,1,70, 0, 100, 0, 2, 0, 0,0,64,1,0,0,0,0,0,16,0,0,0,0, 0, 0, 0, 'Corkis Prison - On State Changed - Store Targetlist'),
(182349, 1, 1 ,2,61, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,19,18369,0,0,0, 0, 0, 0, 'Corkis Prison - Script - Send Targetlist'),
(182349, 1, 2 ,0,61, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,19,18369,0,0,0, 0, 0, 0, 'Corkis Prison - Script - Set Data'),
(18369, 0, 0 ,0,38, 0, 100, 0, 1, 1, 0,0,80,1836900,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Corki - On Data Set - Action list'),
(1836900, 9, 0 , 0, 0, 0, 100, 0, 0, 0, 0,0,1,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Corki - Action list - Say'),
(1836900, 9, 1 , 0, 0, 0, 100, 0, 0, 0, 0,0,33,18369,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Corki - Action list - Kill Credit'),
(1836900, 9, 2 , 0, 0, 0, 100, 0, 4000, 4000, 0,0,114,0,0,0,0,0,0,1,0,0,0,0, 25, 0, 0, 'Corki - Action list - Move Foward'),
(1836900, 9, 3 , 0, 0, 0, 100, 0, 4000, 4000, 0,0,41,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Corki - Action list - Despawn after 5 seconds'),
(182350, 1, 0 ,1,70, 0, 100, 0, 2, 0, 0,0,64,1,0,0,0,0,0,16,0,0,0,0, 0, 0, 0, 'Corkis Prison - On State Changed - Store Targetlist'),
(182350, 1, 1 ,2,61, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,19,20812,0,0,0, 0, 0, 0, 'Corkis Prison - Script - Send Targetlist'),
(182350, 1, 2 ,0,61, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,19,20812,0,0,0, 0, 0, 0, 'Corkis Prison - Script - Set Data'),
(20812, 0, 0 ,0,38, 0, 100, 0, 1, 1, 0,0,80,2081200,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Corki - On Data Set - Action list'),
(2081200, 9, 0 , 0, 0, 0, 100, 0, 0, 0, 0,0,1,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Corki - Action list - Say'),
(2081200, 9, 1 , 0, 0, 0, 100, 0, 0, 0, 0,0,33,20812,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Corki - Action list - Kill Credit'),
(2081200, 9, 2 , 0, 0, 0, 100, 0, 4000, 4000, 0,0,69,0,0,0,0,0,0,8,0,0,0,-1001.022, 8113.366, -95.849, 0.352908, 'Corki - Action list - Move Foward'),
(2081200, 9, 3 , 0, 0, 0, 100, 0, 4000, 4000, 0,0,41,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Corki - Action list - Despawn after 5 seconds');

UPDATE `creature` SET `position_x`=-2563.89,`position_y`=6288.29,`position_z`=15.295,`orientation`=5.23599 WHERE `id` IN (18369);
UPDATE `creature` SET `position_x`=-918.143,`position_y`=8663.94,`position_z`=172.542,`orientation`=0.523599 WHERE `id` IN (18445);

DELETE FROM `creature_questender`  WHERE `id` IN (18369,18445);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(18445, 9954);
  
DELETE FROM `creature_queststarter`  WHERE `id` IN (18369,18445);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(18369, 9923),
(18445, 9955);
