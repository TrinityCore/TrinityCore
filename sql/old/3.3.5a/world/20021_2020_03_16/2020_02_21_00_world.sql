-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=25940;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25940 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`,  `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25940, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47123, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 'FK - On spawn - Cast summon scorchling');
 
UPDATE `creature` SET `modelid`=16412 WHERE `guid`=78651;
UPDATE `creature` SET `modelid`=21084 WHERE `guid`=152406;
UPDATE `creature` SET `modelid`=16412 WHERE `guid`=152407;
UPDATE `creature` SET `modelid`=16446 WHERE `guid`=202716;
UPDATE `creature` SET `modelid`=16443 WHERE `guid`=202717;
UPDATE `creature` SET `modelid`=16436 WHERE `guid`=202715;
UPDATE `creature` SET `modelid`=16432 WHERE `guid`=202714;
UPDATE `creature` SET `modelid`=16445 WHERE `guid`=202741;
UPDATE `creature` SET `modelid`=16442 WHERE `guid`=202742;
UPDATE `creature` SET `modelid`=16444 WHERE `guid`=202743;
UPDATE `creature` SET `modelid`=21086 WHERE `guid`=202744;
UPDATE `creature` SET `modelid`=16444 WHERE `guid`=202747;
UPDATE `creature` SET `modelid`=21086 WHERE `guid`=202752;
UPDATE `creature` SET `modelid`=16442 WHERE `guid`=202754;
UPDATE `creature` SET `modelid`=16443 WHERE `guid`=202753;
UPDATE `creature` SET `modelid`=16445 WHERE `guid`=202755;
UPDATE `creature` SET `modelid`=16445 WHERE `guid`=202759;
UPDATE `creature` SET `modelid`=16442 WHERE `guid`=202760;
UPDATE `creature` SET `modelid`=16443 WHERE `guid`=202761;
UPDATE `creature` SET `modelid`=16444 WHERE `guid`=202762;
UPDATE `creature` SET `modelid`=16448 WHERE `guid`=202764;
UPDATE `creature` SET `modelid`=16414 WHERE `guid`=213815;

DELETE FROM `game_event_creature` WHERE `guid` IN (202766, 202767);
DELETE FROM `creature` WHERE `guid` IN (202766, 202767, 1886);
UPDATE `creature` SET `orientation`= 3.318307 WHERE `guid` IN (202759,202760,202761,202762,202763);
UPDATE `creature` SET `orientation`= 1.61 WHERE `guid` IN (202755,202753,202754,202752,202756,202757);
UPDATE `creature` SET `orientation`= 2.874556 WHERE `guid`=202744;
UPDATE `creature` SET `orientation`= 1.504035 WHERE `guid` IN (202742,202745,202741);
UPDATE `creature` SET `orientation`= 4.590652 WHERE `guid`=202740;
UPDATE `creature` SET `orientation`= 2.693916 WHERE `guid`=202747;
UPDATE `creature` SET `orientation`= 5.289657  WHERE `guid` IN (202748,202749,202750,202751);
UPDATE `creature` SET `orientation`= 3.565712 WHERE `guid`=202717;
UPDATE `creature` SET `orientation`= 2.489717 WHERE `guid`=202715;
UPDATE `creature` SET `orientation`= 5.144366 WHERE `guid` IN (202718,202719);
UPDATE `creature` SET `orientation`= 2.324780 WHERE `guid`=202749;
UPDATE `creature` SET `position_x`=944.326477, `position_y`=781.856445, `position_z`=103.963005, `orientation`= 3.955679 WHERE `guid`=86636;
