-- Shadowmoon Houndmaster
DELETE FROM `waypoint_data` WHERE `id` IN (537960,537980);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(537960,1,434.87802,243.7748,164.81467,0,0,0,0,0,0),
(537960,2,434.99503,262.6248,172.75543,0,0,0,0,0,0),
(537960,3,435.3792,304.8838,190.55779,0,0,0,0,0,0),
(537960,4,435.87857,314.20862,192.77426,0,0,0,0,0,0),
(537960,5,435.15295,342.02112,192.76028,0,0,0,0,0,0),
(537960,6,435.87857,314.20862,192.77426,0,0,0,0,0,0),
(537960,7,435.3792,304.8838,190.55779,0,0,0,0,0,0),
(537960,8,434.99503,262.6248,172.75543,0,0,0,0,0,0),
(537980,1,478.6397,209.28668,163.9814,0,0,0,0,0,0),
(537980,2,494.95975,209.30197,163.98141,0,0,0,0,0,0),
(537980,3,514.9418,209.21756,163.98141,0,0,0,0,0,0),
(537980,4,494.95975,209.30197,163.98141,0,0,0,0,0,0),
(537980,5,478.6397,209.28668,163.9814,0,0,0,0,0,0),
(537980,6,462.657,209.41867,163.9814,0,0,0,0,0,0),
(537980,7,446.82523,209.3577,163.9814,0,0,0,0,0,0),
(537980,8,437.1813,201.82146,163.9814,0,0,0,0,0,0),
(537980,9,438.30728,178.51237,163.9814,0,0,0,0,0,0),
(537980,10,442.02756,170.41487,163.9814,0,0,0,0,0,0),
(537980,11,466.12082,170.16032,163.9814,0,0,0,0,0,0),
(537980,12,494.15598,170.14285,163.98141,0,0,0,0,0,0),
(537980,13,513.6078,169.96799,163.98141,0,0,0,0,0,0),
(537980,14,494.15598,170.14285,163.98141,0,0,0,0,0,0),
(537980,15,466.12082,170.16032,163.9814,0,0,0,0,0,0),
(537980,16,442.02756,170.41487,163.9814,0,0,0,0,0,0),
(537980,17,438.30728,178.51237,163.9814,0,0,0,0,0,0),
(537980,18,437.1813,201.82146,163.9814,0,0,0,0,0,0),
(537980,19,446.82523,209.3577,163.9814,0,0,0,0,0,0),
(537980,20,462.657,209.41867,163.9814,0,0,0,0,0,0);

UPDATE `creature_template_addon` SET `bytes2` = 1, `mount` = 14334 WHERE `entry` = 23018;
DELETE FROM `creature_addon` WHERE `guid` IN (53796,53798);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(53796,537960,14334,0,1,0,3,""),
(53798,537980,14334,0,1,0,3,"");

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (53796,53798);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(53796,53796,0,0,515,0,0),
(53796,53797,5,270,515,0,0),
(53798,53798,0,0,515,0,0),
(53798,53799,10,0,515,0,0);

UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0 WHERE `id` = 23018;
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 2 WHERE `guid` IN (53796,53798) AND `id` = 23018;
UPDATE `creature` SET `position_x` = 434.87802, `position_y` = 243.7748, `position_z` = 164.81467 WHERE `guid` IN (53796,53797) AND `id` = 23018;
UPDATE `creature` SET `position_x` = 478.6397, `position_y` = 209.28668, `position_z` = 163.9814 WHERE `guid` IN (53798,53799) AND `id` = 23018;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 23379;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23018,23083,23379) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Shadowmoon Houndmaster
(23018,0,0,0,4,0,100,0,0,0,0,0,0,11,39906,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - On Aggro - Cast 'Summon Riding Warhound'"),
-- Store guid of summoned Warhound
(23018,0,1,0,17,0,100,0,23083,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - On Summoned Unit - Store Targetlist"),
-- He uses specific ranged mode
(23018,0,2,0,0,0,100,0,0,0,3000,3000,0,11,41093,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - In Combat CMC - Cast 'Shoot'"),
(23018,0,3,0,0,0,100,0,20000,30000,20000,20000,0,11,32908,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - In Combat - Cast 'Wing Clip'"),
(23018,0,4,0,0,0,100,0,30000,40000,20000,30000,0,11,41084,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - In Combat - Cast 'Silencing Shot'"),
(23018,0,5,0,0,0,100,0,15000,20000,25000,25000,0,11,41085,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - In Combat - Cast 'Freezing Trap'"),
(23018,0,6,0,0,0,100,0,45000,50000,45000,50000,0,11,41091,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - In Combat - Cast 'Volley'"),
(23018,0,7,0,0,0,100,0,15000,20000,25000,25000,0,11,41094,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - In Combat - Cast 'Flare'"),
-- Inform summoned Warhound we're dead
(23018,0,8,0,6,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,1,0,0,0,0,0,0,0,"Shadowmoon Houndmaster - On Death - Set Data 0 1 (Stored Target)"),

-- Shadowmoon Riding Hound
(23083,0,0,0,37,0,100,0,0,0,0,0,0,116,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - On AI Initialize - Set Corpse Delay"),
(23083,0,1,0,60,0,100,1,1000,1000,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - On Update - Cast 'Invisibility and Stealth Detection' (No Repeat)"),
(23083,0,2,0,0,0,100,0,5000,10000,20000,25000,0,11,25821,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - In Combat - Cast 'Charge'"),
(23083,0,3,0,0,0,100,0,5000,10000,5000,10000,0,11,41092,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - In Combat - Cast 'Carnivorous Bite'"),
-- Now we're angry
-- Nope, we're not because guardians despawns in core after master death
(23083,0,4,0,38,0,100,0,0,1,0,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - On Data Set 0 1 - Cast 'Enrage'"),
(23083,0,5,0,38,0,100,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Riding Hound - On Data Set 0 1 - Say Line 0"),

-- Black Temple - Houndmaster Flare Dummy
(23379,0,0,0,63,0,100,0,0,0,0,0,0,11,41095,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Black Temple - Houndmaster Flare Dummy - On Just Created - Cast 'Flare'"),
-- Not really sure
(23379,0,1,0,60,0,100,1,5000,15000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Black Temple - Houndmaster Flare Dummy - On Update - Despawn Instant (No Repeat)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 23083 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,5,23083,0,0,36,1,0,0,0,0,0,0,"","Group 0: Execute SAI (Action 4) if creature is alive"),
(22,6,23083,0,0,36,1,0,0,0,0,0,0,"","Group 0: Execute SAI (Action 5) if creature is alive");

UPDATE `creature_text` SET `BroadcastTextId` = 19437, `Text` = "%s goes into a rage after seeing its master fall in battle!" WHERE `CreatureID` = 23083 AND `GroupID` = 0 AND `ID` = 0;
UPDATE `creature_template` SET `speed_run` = 1.38571425847, `BaseAttackTime` = 1500 WHERE `entry` = 23083;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.6125, `CombatReach` = 2.625 WHERE `DisplayID` = 21241;
UPDATE `creature_template` SET `speed_run` = 1.38571425847 WHERE `entry` = 23018;

-- Hand of Gorefiend
UPDATE `creature_addon` SET `auras` = "18943" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 23172);
DELETE FROM `creature_addon` WHERE `guid` IN (52482,52483);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(52482,0,0,0,1,375,0,"18943"),
(52483,0,0,0,1,375,0,"18943");

-- Shadowmoon Grunt
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 23147;
UPDATE `creature_addon` SET `auras` = "" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 23147);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-52447,-52449) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-52447,0,0,0,1,0,100,0,0,0,10000,10000,0,11,34664,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Grunt - Out of Combat - Cast 'Sleep Visual - Flavor'"),
(-52449,0,0,0,1,0,100,0,0,0,10000,10000,0,11,34664,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Grunt - Out of Combat - Cast 'Sleep Visual - Flavor'"),
(-52447,0,1,0,4,0,100,0,0,0,0,0,0,28,34664,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Grunt - On Aggro - Remove Aura 'Sleep Visual - Flavor'"),
(-52449,0,1,0,4,0,100,0,0,0,0,0,0,28,34664,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadowmoon Grunt - On Aggro - Remove Aura 'Sleep Visual - Flavor'");

-- Black Temple Captive
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0 WHERE `id` = 22886;
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 22886;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(22886,1,1,1,0,0,0);

-- Shadowmoon Champion
DELETE FROM `waypoint_data` WHERE `id` = 128780;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(128780,1,421.8104,361.95007,192.75839,0,0,0,0,0,0),
(128780,2,426.9455,351.90082,192.757,0,0,0,0,0,0),
(128780,3,435.38986,348.98694,192.75632,0,0,0,0,0,0),
(128780,4,444.1789,351.72852,192.75711,0,0,0,0,0,0),
(128780,5,448.95435,361.81857,192.758,0,0,0,0,0,0),
(128780,6,444.1789,351.72852,192.75711,0,0,0,0,0,0),
(128780,7,435.4411,349.00293,192.75586,0,0,0,0,0,0),
(128780,8,426.9455,351.90082,192.757,0,0,0,0,0,0);

UPDATE `creature_addon` SET `path_id` = 128780 WHERE `guid` = 12878;
UPDATE `creature` SET `position_x` = 421.8104, `position_y` = 361.95007, `position_z` = 192.75839, `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = 12878 AND `id` = 22880;
