--
DELETE FROM `areatrigger_involvedrelation` WHERE `id` = 4987;
INSERT INTO `areatrigger_involvedrelation` (`id`,`quest`) VALUES
(4987,12274);

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4987;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4987,'SmartTrigger');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND  `SourceEntry`=4987 AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4987,2,0,9,0,12274,0,0,0,0,'','High Abbot Landgren trigger only activates if player is on A Fall from Grace'),
(22,1,4987,2,0,1,0,48753,0,0,0,0,'','High Abbot Landgren trigger only activates if player Has A Fall from Grace: Bell Rung Dummy Aura'),
(22,1,4987,2,0,1,0,48756,0,0,0,0,'','High Abbot Landgren trigger only activates if player Has A Fall from Grace: Ring Kissed Dummy Aura');

UPDATE `creature_template` SET `minlevel`=73, `maxlevel`=73, `exp`=2,`AIName`= 'SmartAI' WHERE  `entry`=27439;

DELETE FROM `smart_scripts` WHERE `entryorguid` =4987 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4987,2,0,1,46,0,100,0,4987,0,0,0,45,1,1,0,0,0,0,10,98593,23837,0,0,0,0,0,"On Trigger - Set Data");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(27350,-98593);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-98593, 0, 0, 1, 38, 0, 100, 0, 1, 1, 90000, 90000, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny -  On Data Set - Set Data'),
(-98593, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48757, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny -  Linked with Previous Event - Cast A Fall from Grace: Summon High Abbot Landgren'),
(27350, 0, 0, 0, 19, 0, 100, 0, 12274, 0, 0, 0, 85, 48763, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Agent Skully - On Quest Accept - Spellcast A Fall from Grace: Scarlet Raven Priest Image (Male)'),
(27350, 0, 1, 0, 62, 0, 100, 0, 9501, 0, 0, 0, 85, 48763, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Agent Skully - On gossip option select - Spellcast A Fall from Grace: Scarlet Raven Priest Image (Male)'),
(27350, 0, 2, 0, 19, 0, 100, 0, 12274, 0, 0, 0, 85, 48761, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Agent Skully - On Quest Accept - Spellcast A Fall from Grace: Scarlet Raven Priest Image (Female)'),
(27350, 0, 3, 0, 62, 0, 100, 0, 9501, 0, 0, 0, 85, 48761, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Agent Skully - On gossip option select - Spellcast A Fall from Grace: Scarlet Raven Priest Image (Female)'),
(27350, 0, 4, 0, 20, 0, 100, 0, 12274, 0, 0, 0, 85, 48765, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Agent Skully - On Quest Complete - Cast A Fall from Grace: Quest Completion');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9532;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9532, 0, 0, 0, 9, 0, 12274, 0, 0, 0, 0, 0, '', 'High Abbot Landgren - Show gossip option only if player has taken A Fall from Grace'),
(15, 9532, 0, 0, 0,29, 0, 27247, 30, 0, 1, 0, 0, '', 'High Abbot Landgren - Show gossip option only if There is no devout Bodyguard'),
(15, 9532, 0, 0, 0, 1, 0, 48753, 0, 0, 0, 0, 0, '', 'High Abbot Landgren - Show gossip option only if player has A Fall from Grace: Bell Rung Dummy Aura');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=27350;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 27350, 0, 0,20, 0, 0, 0, 0, 0, 0, 0, '', 'execute sai only if male character'),
(22, 2, 27350, 0, 0,20, 0, 0, 0, 0, 0, 0, 0, '', 'execute sai only if male character'),
(22, 3, 27350, 0, 0,20, 0, 1, 0, 0, 0, 0, 0, '', 'execute sai only if female character'),
(22, 4, 27350, 0, 0,20, 0, 1, 0, 0, 0, 0, 0, '', 'execute sai only if female character');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`=188713;

DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=188713;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(188713, 1, 0 ,1, 70, 0, 100, 0, 2, 0, 0,0,45,1,1,0,0,0,0,10,105877,27245,0,0,0,0,0, 'Abbey Bell Rope - On Activate - Set Data High Abbot Landgren'),
(188713, 1, 1 ,0, 61, 0, 100, 0, 0, 0, 0,0,85,48753,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Abbey Bell Rope - Linked with Previous Event - Invoker Cast A Fall from Grace: Bell Rung Dummy Aura');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry` IN(27439,27245);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(27439,27245);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27245, 0, 0 ,1,38,  0, 100, 0, 1,1,0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Abbot Landgren - On Data Set - Set Data'),
(27245, 0, 1 ,0,61,  0, 100, 0, 0,0,0,0,45,1,1,0,0,0,0,9,27247,0,30,0,0,0,0,'High Abbot Landgren - Linked with Previous Event - Set Data'),
(27245, 0, 2, 3,62, 0, 100, 0, 9536, 0, 0, 0, 85,48756,0,0,0,0,0,7, 0, 0, 0, 0, 0, 0, 0, 'High Abbot Landgren - On gossip option select - Cast Invoker Cast A Fall from Grace: Ring Kissed Dummy Aura'),
(27439, 0, 0, 0,11, 0, 100, 0, 0, 0, 0, 0, 53,0,27439,0,0,0,0,1, 0, 0, 0, 0, 0, 0, 0, 'High Abbot Landgren - On Spawn - Start WP'),
(27439, 0, 1, 2,40, 0, 100, 0, 2, 0, 0, 0, 1,0,0,0,0,0,0,1, 0, 0, 0, 0, 0, 0, 0, 'High Abbot Landgren - On Reached WP2 - Say'),
(27439, 0, 2, 0,61, 0, 100, 0, 0, 0, 0, 0, 54,6000,0,0,0,0,0,1, 0, 0, 0, 0, 0, 0, 0, 'High Abbot Landgren - Linked with Previous Event - Pause WP'),
(27439, 0, 3, 4,40, 0, 100, 0,9, 0, 0, 0, 66,0,0,0,0,0,0,1, 0, 0, 0, 0, 0, 0, 4.5, 'High Abbot Landgren - On Reached WP10 - Set Orientation'),
(27439, 0, 4, 0,61, 0, 100, 0,0, 0, 0, 0, 1,1,10000,0,0,0,0,21, 50, 0, 0, 0, 0, 0, 0, 'High Abbot Landgren - Linked with Previous Event - Say'),
(27439 ,0, 5, 0,52,0,100,0,1,27439,0,0,1,2,10000,0,0,0,0,21,50,0,0,0,0,0,0, 'High Abbot Landgren - On Text Over Say - Say'),
(27439 ,0, 6, 0,52,0,100,0,2,27439,0,0,1,3,10000,0,0,0,0,21,50,0,0,0,0,0,0, 'High Abbot Landgren - On Text Over Say - Say'),
(27439 ,0, 7, 0,52,0,100,0,3,27439,0,0,1,4,10000,0,0,0,0,21,50,0,0,0,0,0,0, 'High Abbot Landgren - On Text Over Say - Say'),
(27439 ,0, 8, 9,52,0,100,0,4,27439,0,0,1,5,10000,0,0,0,0,21,50,0,0,0,0,0,0, 'High Abbot Landgren - On Text Over Say - Say'),
(27439 ,0, 9,10,61,0,100,0,0,0,0,0,11,48771,0,0,0,0,0,21,50,0,0,0,0,0,0, 'High Abbot Landgren - Linked with Previous Event - Cast A Fall from Grace: Kill Credit'),
(27439 ,0,10,11,61,0,100,0,0,0,0,0,15,12274,0,0,0,0,0,21,50,0,0,0,0,0,0, 'High Abbot Landgren - Linked with Previous Event - Call Areaexploredoreventhappens'),
(27439 ,0,11,12,61,0,100,0,0,0,0,0,11,48773,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Abbot Landgren - Linked with Previous Event - Cast A Fall from Grace: High Abbot Ride Vehicle'),
(27439 ,0,12,13,61,0,100,0,0,0,0,0,11,66733,2,0,0,0,0,1,0,0,0,0,0,0,0, 'High Abbot Landgren - Linked with Previous Event - Cast Jump Back'),
(27439 ,0,13,0,61,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Abbot Landgren - Linked with Previous Event - Despawn After 2 Seconds');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 27247;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27247;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27247,0,0,0,0,0,100,0,4000,7000,10000,15000,11,38256,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Devout Bodyguard - IC - Cast Piercing Howl'),
(27247,0,1,2,38,0,100,0,1,1,0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Devout Bodyguard - On Data Set - Set Data'),
(27247,0,2,3,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Devout Bodyguard - Linked with Previous Event - Say'),
(27247,0,3,4,61,0,100,0,0,0,0,0,53,1,27247,0,0,0,1,1,0,0,0,0,0,0,0, 'Devout Bodyguard - Linked with Previous Event - Start WP'),
(27247,0,4,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Devout Bodyguard - Linked with Previous Event - Set Phase 2'),
(27247,0,5,0,40,0,100,0,14,27247,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Devout Bodyguard - On Reached WP 14 - Say'),
(27247,0,6,7,40,0,100,0,27,27247,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Devout Bodyguard - On Reached WP 27 - Stop WP'),
(27247,0,7,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Devout Bodyguard - Linked with Previous Event - Evade'),
(27247,0,8,0,11,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Devout Bodyguard - On Spawn - Set Home Position');

DELETE FROM `creature_text` WHERE `entry` IN (27245,27247,27439);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(27247, 0, 0, 'Hey, who rang the bell?', 12, 0, 100, 0, 0, 0, 'Devout Bodyguard', 26610),
(27439, 0, 0, 'I know a place nearby where we can speak in private, my child. Follow me.', 12, 0, 100, 0, 0, 0, 'High Abbot Landgren', 26629),
(27439, 1, 0, 'Did you think that I could not see through your flimsy disguise, $N?', 12, 0, 100, 0, 0, 0, 'High Abbot Landgren', 26631),
(27439, 2, 0, 'There is much that you do not understand, $R. The Master sees all.', 12, 0, 100, 0, 0, 0, 'High Abbot Landgren', 26632),
(27439, 3, 0, 'He told me that you would come for me. I won\'t die by your hand, though. I have seen what you have done to my compatriots.', 12, 0, 100, 0, 0, 0, 'High Abbot Landgren', 26633),
(27439, 4, 0, 'No. I will leave this world in a manner of my own choosing. And I will return, the grand admiral\'s will permitting!', 12, 0, 100, 0, 0, 0, 'High Abbot Landgren', 26634),
(27439, 5, 0, 'AAAEEEEIIIiiiiiiiiiiiiiiiiiiiiiiiiiiii........................................', 12, 0, 100, 0, 0, 0, 'High Abbot Landgren', 26636);

DELETE FROM `waypoints` WHERE `entry`IN(27247,27439);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(27247, 1, 2799.233154,-479.702179,119.616562, 'Devout Bodyguard'),
(27247, 2, 2814.937500,-465.844482,119.613434, 'Devout Bodyguard'),
(27247, 3, 2823.792236,-472.341522,125.244446, 'Devout Bodyguard'),
(27247, 4, 2830.335205,-472.019501,131.034653, 'Devout Bodyguard'),
(27247, 5, 2836.603760,-468.373047,135.362701, 'Devout Bodyguard'),
(27247, 6, 2839.449219,-459.743408,135.362701, 'Devout Bodyguard'),
(27247, 7, 2835.552002,-451.271088,135.362701, 'Devout Bodyguard'),
(27247, 8, 2824.675049,-447.810760,135.362701, 'Devout Bodyguard'),
(27247, 9, 2817.437744,-468.281036,135.361267, 'Devout Bodyguard'),
(27247,10, 2821.199707,-471.310425,138.636017, 'Devout Bodyguard'),
(27247,11, 2827.012695,-472.998871,143.907898, 'Devout Bodyguard'),
(27247,12, 2830.540771,-472.438110,147.174271, 'Devout Bodyguard'),
(27247,13, 2837.653076,-467.185547,150.836685, 'Devout Bodyguard'),
(27247,14, 2828.407227,-458.208435,153.165573, 'Devout Bodyguard'),
(27247,15, 2837.653076,-467.185547,150.836685, 'Devout Bodyguard'),
(27247,16, 2830.540771,-472.438110,147.174271, 'Devout Bodyguard'),
(27247,17, 2827.012695,-472.998871,143.907898, 'Devout Bodyguard'),
(27247,18, 2821.199707,-471.310425,138.636017, 'Devout Bodyguard'),
(27247,19, 2817.437744,-468.281036,135.361267, 'Devout Bodyguard'),
(27247,20, 2824.675049,-447.810760,135.362701, 'Devout Bodyguard'),
(27247,21, 2835.552002,-451.271088,135.362701, 'Devout Bodyguard'),
(27247,22, 2839.449219,-459.743408,135.362701, 'Devout Bodyguard'),
(27247,23, 2836.603760,-468.373047,135.362701, 'Devout Bodyguard'),
(27247,24, 2830.335205,-472.019501,131.034653, 'Devout Bodyguard'),
(27247,25, 2823.792236,-472.341522,125.244446, 'Devout Bodyguard'),
(27247,26, 2814.937500,-465.844482,119.613434, 'Devout Bodyguard'),
(27247,27, 2799.233154,-479.702179,119.616562, 'Devout Bodyguard'),
(27439, 1, 2827.939941,-424.861115,119.889359, 'High Abbot Landgren'),
(27439, 2, 2827.616455,-419.490265,118.196106, 'High Abbot Landgren'),
(27439, 3, 2826.310303,-411.833801,118.196106, 'High Abbot Landgren'),
(27439, 4, 2812.848633,-411.278259,118.196106, 'High Abbot Landgren'),
(27439, 5, 2785.380371,-438.162445,118.204048, 'High Abbot Landgren'),
(27439, 6, 2776.644775,-465.078369,116.134209, 'High Abbot Landgren'),
(27439, 7, 2765.220703,-488.269043,113.898613, 'High Abbot Landgren'),
(27439, 8, 2738.468262,-524.502625,103.381577, 'High Abbot Landgren'),
(27439, 9, 2738.541748,-523.856567,103.497971, 'High Abbot Landgren');
