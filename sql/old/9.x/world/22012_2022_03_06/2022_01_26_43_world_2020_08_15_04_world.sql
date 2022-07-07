-- Warden Treelos
SET @NPC := 65811;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance` = 0,`MovementType` = 2 WHERE `guid` = @NPC;
UPDATE `creature` SET `position_x` = -1803.511, `position_y` = 4646.977, `position_z` = 19.73334, `orientation` = 2.782069, `currentwaypoint` = 1, `MovementType` = 2 WHERE `guid` = @NPC;
DELETE FROM `creature_addon` WHERE `guid` = @NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,'');
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH,1,-1803.511,4646.977,19.73334),
(@PATH,2,-1806.302,4648.026,19.7354), 
(@PATH,3,-1811.729,4650.576,19.73712),
(@PATH,4,-1820.917,4652.651,19.65766), -- Wait Here
(@PATH,5,-1806.76,4647.632,19.73359),
(@PATH,6,-1798.204,4645.634,18.52957),
(@PATH,7,-1792.864,4644.762,15.93469),
(@PATH,8,-1790.345,4644.342,14.63413),
(@PATH,9,-1786.262,4640.202,14.629),
(@PATH,10,-1783.267,4635.107,14.61708),
(@PATH,11,-1778.932,4631.083,14.60766),
(@PATH,12,-1767.724,4630.207,12.65584),
(@PATH,13,-1759.315,4630.365,12.36348),
(@PATH,14,-1752.533,4635.927,11.64559),
(@PATH,15,-1749.859,4641.148,11.4896),
(@PATH,16,-1749.342,4646.9,11.58107),
(@PATH,17,-1749.807,4649.842,11.68124),
(@PATH,18,-1752.798,4654.813,12.00678),
(@PATH,19,-1760.015,4659.648,12.52498),
(@PATH,20,-1765.655,4661.11,13.2111),
(@PATH,21,-1774.116,4662.596,14.87321),
(@PATH,22,-1779.585,4664.445,14.62318),
(@PATH,23,-1782.483,4669.484,14.63375),
(@PATH,24,-1783.937,4675.277,14.38006),
(@PATH,25,-1786.943,4689.771,12.19901),
(@PATH,26,-1795.366,4697.75,12.24373),
(@PATH,27,-1795.366,4697.75,12.24373),
(@PATH,28,-1795.366,4697.75,12.24373),
(@PATH,29,-1796.568,4698.823,12.21809),
(@PATH,30,-1804.996,4704.168,11.23805), 
(@PATH,31,-1812.376,4709.268,10.39271),
(@PATH,32,-1822.081,4716.316,9.892865),
(@PATH,33,-1829.052,4722.574,10.48604),
(@PATH,34,-1831.33,4727.8,11.54623),
(@PATH,35,-1831.766,4736.22,13.99709),
(@PATH,36,-1830.739,4741.621,16.24664),
(@PATH,37,-1829.747,4744.304,17.09319),
(@PATH,38,-1827.362,4745.648,18.20882),
(@PATH,39,-1822.167,4746.989,20.64674),
(@PATH,40,-1816.996,4746.004,23.22047),
(@PATH,41,-1814.754,4744.821,24.12455),
(@PATH,42,-1811.222,4740.513,25.53274),
(@PATH,43,-1805.106,4737.365,27.42546), 
(@PATH,44,-1807.47,4739.047,26.76365), -- wait Here
(@PATH,45,-1812.203,4742.384,25.24649),
(@PATH,46,-1816.665,4745.775,23.24314),
(@PATH,47,-1821.645,4747.158,20.51319),
(@PATH,48,-1826.934,4746.034,18.35211),
(@PATH,49,-1830.59,4742.182,16.41434),
(@PATH,50,-1832.227,4736.953,14.33177),
(@PATH,51,-1832.385,4731.309,12.38629),
(@PATH,52,-1832.348,4725.553,10.82265),
(@PATH,53,-1833.194,4719.703,9.931902),
(@PATH,54,-1835.196,4714.126,9.617038),
(@PATH,55,-1838.714,4705.847,9.487278),
(@PATH,56,-1841.619,4700.646,9.248943),
(@PATH,57,-1847.862,4694.373,8.671054),
(@PATH,58,-1853.649,4692.015,8.139262),
(@PATH,59,-1862.4,4691.255,7.052509),
(@PATH,60,-1874.147,4691.15,4.642838),
(@PATH,61,-1888.559,4688.214,2.286811),
(@PATH,62,-1899.335,4683.292,0.7844561),
(@PATH,63,-1900.897,4682.444,0.5538373),
(@PATH,64,-1913.776,4680.642,-0.7968805),
(@PATH,65,-1925.123,4682.271,-1.525997), -- Wait Here
(@PATH,66,-1919.664,4679.85,-1.22198),
(@PATH,67,-1902.362,4681.39,0.3635311),
(@PATH,68,-1888.539,4686.894,2.282935),
(@PATH,69,-1877.202,4690.228,4.16307),
(@PATH,70,-1868.424,4691.286,5.862486),
(@PATH,71,-1859.586,4691.212,7.495709),
(@PATH,72,-1850.668,4690.899,8.439217),
(@PATH,73,-1839.003,4688.62,9.683162),
(@PATH,74,-1832.957,4687.138,10.25435),
(@PATH,75,-1830.047,4686.461,10.43636),
(@PATH,76,-1824.278,4687.304,10.65615),
(@PATH,77,-1808.639,4696.039,11.07814),
(@PATH,78,-1803.177,4698.232,11.68287),
(@PATH,79,-1787.036,4687.587,12.24434),
(@PATH,80,-1784.982,4682.22,12.63027),
(@PATH,81,-1785.735,4673.635,14.5907),
(@PATH,82,-1785.375,4667.628,14.64867),
(@PATH,83,-1785.108,4664.653,14.64001),
(@PATH,84,-1785.058,4655.656,14.63397),
(@PATH,85,-1787.074,4647.078,14.63508),
(@PATH,86,-1788.819,4645.085,14.63521),
(@PATH,87,-1794.038,4644.671,16.67877),
(@PATH,88,-1796.648,4645.14,17.99133);

-- Warden Treelos pauses at 3 locations. 20 seconds for the inn and tower and 7 for the gate.
UPDATE `waypoint_data` SET `delay` = 20000 where `id` = @PATH AND `point` = 4; 
UPDATE `waypoint_data` SET `delay` = 20000 where `id` = @PATH AND `point` = 44;
UPDATE `waypoint_data` SET `delay` = 7000 where `id` = @PATH AND `point` = 65;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 32373;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,32373,0,0,31,0,3,18437,0,0,0,0,"","Group 0: Spell 'Moonfire' (Effect 0) targets creature 'Viscious Teromoth'");

-- Warden Treelos SAI
SET @ID := 18424;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ID;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ID AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,10000,10000,60000,60000,87,@ID*100+0,@ID*100+1,@ID*100+2,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - Out of Combat - Run Random Script"),
(@ID,0,1,0,1,0,100,0,30000,35000,30000,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - Out of Combat - Say Line 0"),
(@ID,0,2,0,10,0,100,0,0,25,15000,15000,11,32373,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warden Treelos - Within 0-25 Range Out of Combat LoS - Cast 'Moonfire'"),
(@ID,0,3,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Killed Unit - Say Line 1"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,28,32356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Script - Remove Aura 'Cat Form'"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,28,32357,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Script - Remove Aura 'Bear Form'"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,11,32356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Script - Cast 'Cat Form'"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,28,32356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Script - Remove Aura 'Cat Form'"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,28,32357,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Script - Remove Aura 'Bear Form'"),
(@ID*100+1,9,2,0,0,0,100,0,0,0,0,0,11,32357,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Script - Cast 'Bear Form'"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,28,32356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Script - Remove Aura 'Cat Form'"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,28,32357,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Treelos - On Script - Remove Aura 'Bear Form'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 18424 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,18424,0,0,31,0,3,18437,0,0,0,0,"","Group 0: Execute SAI (Action 2) if invoker is creature 'Viscious Teromoth'");

-- All texts are shown in http://web.archive.org/web/20120702153724/www.wowhead.com/npc=18424
-- But grouping may be not accurate, grouping is also based on comments but mostly on ids
DELETE FROM `creature_text` WHERE `CreatureID` = 18424;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(18424,0,0,"Go on, get out of here!  Save yourself!",12,0,100,0,0,0,15391,0,"Warden Treelos"),
(18424,0,1,"BOOM!",12,0,100,0,0,0,15395,0,"Warden Treelos"),
(18424,0,2,"Stop looking at me!",12,0,100,0,0,0,15397,0,"Warden Treelos"),
(18424,0,3,"They broke us all.",12,0,100,0,0,0,15398,0,"Warden Treelos"),
(18424,0,4,"Can't... control... form.",12,0,100,0,0,0,15399,0,"Warden Treelos"),
(18424,0,5,"Meow.",12,0,100,0,0,0,15400,0,"Warden Treelos"),
(18424,0,6,"Roar!",12,0,100,0,0,0,15401,0,"Warden Treelos"),
(18424,0,7,"Blinding white light, and then silence!",12,0,100,0,0,0,15402,0,"Warden Treelos"),
(18424,0,8,"Too close to the truth, too close to the truth!",12,0,100,0,0,0,15403,0,"Warden Treelos"),
(18424,0,9,"Who are you to stare at me and pass judgment?!",12,0,100,0,0,0,15453,0,"Warden Treelos"),
(18424,0,10,"Do I know you?  If you're interested in joining the Cenarion Expedition step right in.",12,0,100,0,0,0,15454,0,"Warden Treelos"),
(18424,0,11,"Careful who you talk to.  The teromoths have ears.",12,0,100,0,0,0,15455,0,"Warden Treelos"),
(18424,0,12,"Not all dinner guests are gracious.  Mind your manners!",12,0,100,0,0,0,15456,0,"Warden Treelos"),
(18424,0,13,"It knows all, it sees all!",12,0,100,0,0,0,15457,0,"Warden Treelos"),
(18424,0,14,"No need to wait outside in the rain.  Come in... you're welcome with us in here.",12,0,100,0,0,0,15458,0,"Warden Treelos"),
(18424,1,0,"You won't get my clothes!  Die!",12,0,100,0,0,0,15418,0,"Warden Treelos"),
(18424,1,1,"Filthy vermin.  Submit or perish!",12,0,100,0,0,0,15450,0,"Warden Treelos"),
(18424,1,2,"You as well, Flutter?  We used to be such good friends.  I will miss you.",12,0,100,0,0,0,15451,0,"Warden Treelos"),
(18424,1,3,"Oops, my bad.  Sometimes I can't control my moonfire.",12,0,100,0,0,0,15452,0,"Warden Treelos"),
(18424,1,4,"The vicious teromoths and I are just fine in here on our own, thank you.",12,0,100,0,0,0,15459,0,"Warden Treelos");
