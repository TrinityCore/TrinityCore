DELETE FROM `waypoints` WHERE `entry`=28308;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(28308, 1, 5268.226 ,4425.439 ,-95.55899, 'Captive Crocolisk'),
(28308, 2, 5249.557 ,4405.892 ,-96.04365, 'Captive Crocolisk'),
(28308, 3, 5266.678 ,4365.464 ,-98.19455, 'Captive Crocolisk'),
(28308, 4, 5289.138 ,4366.553 ,-102.234, 'Captive Crocolisk'),
(28308, 5, 5330.018 ,4363.27 ,-121.0311, 'Captive Crocolisk'),
(28308, 6, 5349.229 ,4341.059 ,-134.0126, 'Captive Crocolisk'),
(28308, 7, 5365.038 ,4333.716 ,-141.5817, 'Captive Crocolisk'),
(28308, 8, 5405.443 ,4307.841 ,-142.03, 'Captive Crocolisk'),
(28308, 9, 5434.999 ,4305.659 ,-136.4706, 'Captive Crocolisk'),
(28308, 10, 5464.708 ,4302.066 ,-133.1981, 'Captive Crocolisk'),
(28308, 11, 5490.555 ,4294.395 ,-127.5203, 'Captive Crocolisk'),
(28308, 12, 5503.808 ,4269.717 ,-110.3168, 'Captive Crocolisk'),
(28308, 13, 5518.324 ,4255.308 ,-103.0638, 'Captive Crocolisk'),
(28308, 14, 5540.53 ,4259.77 ,-102.3979, 'Captive Crocolisk'),
(28308, 15, 5564.194 ,4263.45 ,-102.7574, 'Captive Crocolisk'),
(28308, 16, 5585.45 ,4261.137 ,-99.54807, 'Captive Crocolisk'),
(28308, 17, 5609.614 ,4259.657 ,-98.87333, 'Captive Crocolisk'),
(28308, 18, 5633.434 ,4259.228 ,-98.53442, 'Captive Crocolisk'),
(28308, 19, 5660.568 ,4260.985 ,-98.63537, 'Captive Crocolisk'),
(28308, 20, 5681.639 ,4266.31 ,-99.26748, 'Captive Crocolisk'),
(28308, 21, 5708.126 ,4273.348 ,-102.9183, 'Captive Crocolisk'),
(28308, 22, 5748.732 ,4284.135 ,-112.0557, 'Captive Crocolisk'),
(28308, 23, 5839.82 ,4368.61 ,-112.0805, 'Captive Crocolisk'),
(28308, 24, 5897.276 ,4408.44 ,-95.25065, 'Captive Crocolisk'),
(28308, 25, 5925.311 ,4440.624 ,-94.77592, 'Captive Crocolisk'),
(28308, 26, 5953.005 ,4476.29 ,-94.3763, 'Captive Crocolisk'),
(28308, 27, 5964.229 ,4503.729 ,-92.81553, 'Captive Crocolisk'),
(28308, 28, 5960.583 ,4546.558 ,-95.65462, 'Captive Crocolisk'),
(28308, 29, 5965.167 ,4579.141 ,-97.39779, 'Captive Crocolisk'),
(28308, 30, 5969.295 ,4613.739 ,-98.05751, 'Captive Crocolisk'),
(28308, 31, 5975.809 ,4659.289 ,-99.27143, 'Captive Crocolisk'),
(28308, 32, 5992.961 ,4699.554 ,-99.30317, 'Captive Crocolisk'),
(28308, 33, 6015.139 ,4743.752 ,-97.52377, 'Captive Crocolisk'),
(28308, 34, 6035.183 ,4788.787 ,-94.66938, 'Captive Crocolisk'),
(28308, 35, 6064.951 ,4827.502 ,-94.54885, 'Captive Crocolisk'),
(28308, 36, 6065.57 ,4870.553 ,-94.47726, 'Captive Crocolisk'),
(28308, 37, 6096.612 ,4885.741 ,-94.44479, 'Captive Crocolisk'),
(28308, 38, 6120.387 ,4902.048 ,-95.06882, 'Captive Crocolisk'),
(28308, 39, 6139.616 ,4913.349 ,-94.8635, 'Captive Crocolisk'),
(28308, 40, 6141.208, 4914.293, -92.7175, 'Captive Crocolisk');
 
UPDATE `creature_template` SET `AIName`='SmartAI', `InhabitType`=4 WHERE  `entry`=28307;
UPDATE `smart_scripts` SET `link`=1 WHERE  `entryorguid`=28298 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(28307,28308) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(28216) AND `source_type`=0 AND `id`>17;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(28298) AND `source_type`=0 AND `id`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28216, 0, 18, 19, 38, 0, 100, 0, 1, 3, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 3 - Say Line 6'),
(28216, 0, 19, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 3 - Despawn'),
(28298, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 3, 0, 0, 0, 0, 19, 28216, 0, 0, 0, 0, 0, 0, 'Captive Crocolisk - On Gossip Option 0 Selected - Set Data on Zepik'),
(28307, 0, 0, 0, 1, 0, 100, 0, 0, 0, 3000, 3000, 11, 51256, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Croclisk Chain Bunny - OOC - Cast Captive Crocolisk Chains'),
(28308, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2830800, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captive Crocolisk - On Just Summoned - Run Script (Phase 1) (No Repeat)'),
(28308, 0, 1, 2, 40, 0, 100, 0, 39, 0, 0, 0, 11, 50630, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captive Crocolisk - On reached WP42 - Cast Eject All Passengers'),
(28308, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 15, 12536, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captive Crocolisk - On reached WP42 - Quest Credit \'A Rough Ride\''),
(28308, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 52545, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captive Crocolisk - On reached WP42 - Cast Forceitem Zepik'),
(28308, 0, 4, 0, 40, 0, 100, 0, 40, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captive Crocolisk - On reached WP43 - Despawn');

DELETE FROM `creature_text` WHERE `entry`=28216 AND `groupid`=6;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(28216, 6, 0, 'Enjoy ride! Call me when you get there.', 12, 0, 100, 0, 0, 0, 28881, 0, 'Zepik');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=51256;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 51256, 0, 0, 31, 0, 3, 28298, 0, 0, 0, 0, '', 'Captive Crocolisk Chains targets captive crocolisk');
