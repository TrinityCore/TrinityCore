UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`=184725;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(21039,21898,20767,21504) ;

DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=184725;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(21039,21898,20767,21504);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=2103900;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(184725, 1, 0 ,1, 70, 0, 100, 0, 2, 0, 0,0,45,1,1,0,0,0,0,10,73864,21039,0,0,0,0,0, 'Mana Bomb - On State Changed - Set Data Mana Bomb Kill Credit Trigger'),
(184725, 1, 1 ,2, 61, 0, 100, 0, 0, 0, 0,0,33,21039,0,0,0,0,0,16,0,0,0,0,0,0,0, 'Mana Bomb - Linked with Previous Event - Quest Credit'),
(184725, 1, 2 ,0, 61, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,16769,0,50,0,0,0,0, 'Mana Bomb - Linked with Previous Event - Set Data'),
--
(21039, 0, 0 ,1, 38, 0, 100, 0, 1, 1, 0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - On Data Set - Set Data'),
(21039, 0, 1 ,2, 61, 0, 100, 0, 0, 0, 0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - Linked with Previous Event - Say'),
(21039, 0, 2 ,0, 61, 0, 100, 0, 0, 0, 0,0,80,2103900,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - Linked with Previous Event - Run Script'),
(21039, 0, 3 ,4, 52, 0, 100, 0, 0, 21039, 0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - On Text Over - Say'),
(21039, 0, 4 ,0, 61, 0, 100, 0, 0, 0, 0,0,80,2103900,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - Linked with Previous Event - Run Script'),
(21039, 0, 5 ,6, 52, 0, 100, 0, 1, 21039, 0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - On Text Over Event - Say'),
(21039, 0, 6 ,0, 61, 0, 100, 0, 0, 0, 0,0,80,2103900,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - Linked with Previous Event - Run Script'),
(21039, 0, 7 ,8, 52, 0, 100, 0, 2, 21039, 0,0,1,3,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - On Text Over - Say'),
(21039, 0, 8 ,0, 61, 0, 100, 0, 0, 0, 0,0,80,2103900,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - Linked with Previous Event - Run Script'),
(21039, 0, 9 ,10, 52, 0, 100, 0, 3, 21039, 0,0,1,4,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - On Text Over - Say'),
(21039, 0, 10 ,0, 61, 0, 100, 0, 0, 0, 0,0,80,2103900,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Kill Credit Trigger - Linked with Previous Event - Run Script'),
--
(21039, 0, 12 ,0, 52, 0, 100, 0, 4, 21039, 0,0,45,1,1,0,0,0,0,9,20767,0,200,0,0,0,0, 'Mana Bomb Kill Credit Trigger - On Text Over - Set Data Mana Bomb Explosion Trigger'),
(20767, 0, 0 ,1, 38, 0, 100, 0, 1, 1, 0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Explosion  Trigger - On Data Set - Set Data'),
(20767, 0, 1 ,2, 61, 0, 100, 0, 0, 0, 0,0,11,35513,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Mana Bomb Explosion  Trigger - Linked with Previous Event - Cast Mana Bomb Explosion'),
--
(21898, 0, 0 ,1, 38, 0, 100, 0, 1, 1, 0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mana Bomb Lightning  Trigger - On Data Set - Set Data'),
(21898, 0, 1 ,0, 61, 0, 100, 0, 0, 0, 0,0,11,37843,0,0,0,0,0,9,21899,0,200,0, 0, 0, 0, 'Mana Bomb Lightning  Trigger - Linked with Previous Event - Cast Mana Bomb Lightning'),
(2103900, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,21898,0,200,0, 0, 0, 0, 'Mana Bomb - Script - Set Data');


DELETE FROM `creature_text` WHERE `entry` IN(21039,18554,16769);
DELETE FROM `creature_text` WHERE `entry` =21504 AND `groupid`>3;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(21039,0,0,'5...',41,0,100,0,0,0,'Mana Bomb'),
(21039,1,0,'4...',41,0,100,0,0,0,'Mana Bomb'),
(21039,2,0,'3...',41,0,100,0,0,0,'Mana Bomb'),
(21039,3,0,'2...',41,0,100,0,0,0,'Mana Bomb'),
(21039,4,0,'1...',41,0,100,0,0,0,'Mana Bomb'),
(18554,0,0,'You come into my house and threaten ME? I think not!',12,0,100,0,0,0,'Sharth Voldoun'),
(18554,1,0,'All goes exceedingly well, my lord. Testing of the smaller prototype at the Cenarion Thicket was a complete success. The second bomb is being ritually fueled in the courtyard below even as we speak. And, I''ve sent a courier to Tuurem to bring the rest of the parts to us here.',12,0,100,0,0,0,'Sharth Voldoun'),
(18554,2,0,'You are satisfied?',12,0,100,0,0,0,'Sharth Voldoun'),
(18554,3,0,'I can assure you that we will not fail, my master. I am personally overseeing every aspect of the construction, and I hold the final codes, myself. Within a day''s time, I will have the bomb detonated on those nearby pests.',12,0,100,0,0,0,'Sharth Voldoun'),
(16769,0,0,'Knowing there isn''t enough time, the Firewing Warlock doesn''t even try to run.', 16,0,100,0,0,0,'Firewing Warlock'),
--
(21504,4,0,'For the time being, yes. However, allow my presence to be a motivator. Prince Kael''thas was displeased with the failure of the crystal experiment on Fallen Sky Ridge. This is one of the reasons for why we chose the Cenarion druids as the testing grounds for the bomb.',12,0,100,0,0,0,'Pathaleon the Calculators Image'),
(21504,5,0,'I need not tell you what will happen should the mana bomb down in the courtyard fail to be used on its target soon? Since moving into the forest, they''ve become increasingly annoying to our operations: here, at Tuurem and to the south at the Bonechewer Ruins.',12,0,100,0,0,0,'Pathaleon the Calculators Image'),
(21504,6,0,'I think that we should teach a lesson to both the Horde and the Alliance. One that they will not soon forget!',12,0,100,0,0,0,'Pathaleon the Calculators Image'),
(21504,7,0,'See to it that you do, Sharth, or I will personally see to your slow torture and death.',12,0,100,0,0,0,'Pathaleon the Calculators Image'),
(21504,8,0,'I believe I may recognize them. Deal with this quickly, Sharth. Then take the mana bomb and destroy their town!',12,0,100,0,0,0,'Pathaleon the Calculators Image');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=35958;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 35958, 0, 0, 31, 0, 3, 16769, 0, 0, 0, '','Mana Bomb Explosion Targets Firewing Warlock'),
(13, 3, 35958, 0, 1, 31, 0, 3, 5355, 0, 0, 0, '','Mana Bomb Explosion Targets Firewing Defender');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 18554;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=18554;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18554;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21504,0,0,0,38,0,100,0,1,1,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Pathaleon the Calculators Image - On Data Set - Despawn'),
--
(18554,0,0,0,0,0,100,0,3000,5000,40000,45000,11,15277,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sharth Voldoun - IC - Cast    Seal of Reckoning'),
(18554,0,1,0,2,0,100,0,0,40,15000,20000,11,13952,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sharth Voldoun - On Below 40% HP - Cast Holy Light'),
(18554,0,2,3,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,2000,0,0,0,0,0, 'Sharth Voldoun - On Agro - Say'),
(18554,0,3,4,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,21504,0,200,0,0,0,0, 'Sharth Voldoun - Linked with Previous Event - Despawn Pathaleon the Calculators Image'),
(18554,0,4,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sharth Voldoun - Linked with Previous Event - Set Phase 0'),
--
(18554,0,5,6,25,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sharth Voldoun - On Reset - Set Phase 2'),
(18554,0,6,0,61,0,100,0,0,0,0,0,12,21504,8,0,0,0,0,8,0,0,0,-2281.936523,3099.178711,152.817734,3.699372, 'Sharth Voldoun - Linked with Previous Event - Spawn Pathaleon the Calculators Image'),
(18554,0,7,0,10,2,100,0,1,200,60000,60000,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0, 'Sharth Voldoun - Linked with Previous Event - Spawn Pathaleon the Calculators Image'),
(18554,0,8,0,52,2,100,0,1,18554,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Sharth Voldoun - On Text Over Event - Say'),
(18554,0,9,0,52,2,100,0,2,18554,0,0,1,4,6000,0,0,0,0,9,21504,0,200,0,0,0,0, 'Sharth Voldoun - On Text Over Event - Say'),
(18554,0,10,0,52,2,100,0,4,21504,0,0,1,5,6000,0,0,0,0,9,21504,0,200,0,0,0,0, 'Sharth Voldoun - On Text Over Event - Say'),
(18554,0,11,0,52,2,100,0,5,21504,0,0,1,6,6000,0,0,0,0,9,21504,0,200,0,0,0,0, 'Sharth Voldoun - On Text Over Event - Say'),
(18554,0,12,0,52,2,100,0,6,21504,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0, 'Sharth Voldoun - On Text Over Event - Say'),
(18554,0,13,0,52,2,100,0,3,18554,0,0,1,7,6000,0,0,0,0,9,21504,0,200,0,0,0,0, 'Sharth Voldoun - On Text Over Event - Say'),
(18554,0,14,0,52,0,100,0,0,18554,0,0,1,8,6000,0,0,0,0,9,21504,0,200,0,0,0,0, 'Sharth Voldoun - On Text Over Event - Say');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 16769;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=16769;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16769;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16769,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - On Reset - Prevent Combat Movement'),
(16769,0,1,2,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Firewing Warlock - On Agro - Cast Shadow Bolt'),
(16769,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - Linked with Previous Event - Set Phase 1'),
(16769,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Firewing Warlock - On Range - Cast Shadow Bolt'),
(16769,0,4,5,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Firewing Warlock - On Less than 15% Mana - Allow Combat Movement'),
(16769,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - Linked with Previous Event - Set Phase 2'),
(16769,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - On Range - Allow Combat Movement'),
(16769,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - On Range - Prevent Combat Movement'),
(16769,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - On Range - Allow Combat Movement'),
(16769,0,9,0,3,2,100,0,30,0,0,0,22,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Firewing Warlock - On More than 30% Mana - Set Phase 1'),
(16769,0,10,0,0,0,100,0,5000,9000,25000,35000,11,33483,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - IC - Cast Mana Tap'),
(16769,0,11,0,0,0,100,0,9000,15000,15000,20000,11,33390,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Firewing Warlock - IC - Cast Arcane Torrent'),
(16769,0,12,0,0,0,100,0,3000,5000,18000,24000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Firewing Warlock - IC - Cast Immolate'),
(16769,0,13,0,2,0,100,1,0,30,0,0,11,32932,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - On Less than 30% HP - Cast Sun Shield'),
(16769,0,14,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - On Less than 15% HP - Flee for Assist'),
(16769,0,15,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - On Evade - Set Phase 0'),
(16769,0,16,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Firewing Warlock - On Data Set - Say');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=16769;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 17, 16769, 0, 0, 36, 1, 0, 0, 0, 0, 0, '','Only execute SAI if firewing warlock alive');
