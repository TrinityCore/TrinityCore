DELETE FROM `creature_text` WHERE `entry`=29677;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(29677,0,0,'The %s sniffs the ground to pickup the trail.',16,0,100,0,0,0,30366,'Frosthound to Player'),
(29677,1,0,'You''ve been seen! Use the net and ice slick to keep the dwarves away!',42,0,100,0,0,0,30365,'Frosthound to Player'),
(29677,2,0,'The frosthound has located the thief''s hiding place. Confront him!',42,0,100,377,0,0,30368,'Frosthound to Player'),
(29677,3,0,'The %s has tracked the scent to its source.',16,0,100,377,0,0,30367,'Frosthound to Player');

UPDATE `creature_template` SET `spell1`=54997, `spell2`=54996,`ainame`='SmartAI' WHERE `entry`=29677;

DELETE FROM `smart_scripts` WHERE `entryorguid`=29677 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2967700 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29677,0,0,1,54,0,100,0,0,0,0,0,11,54993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Just Summoned - Cast Frosthound Periodic'),
(29677,0,1,0,61,0,100,0,0,0,0,0,80,2967700,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Just Summoned - Run Script'),
(29677,0,2,0,7,0,100,0,0,0,0,0,11,54993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Evade - Cast Frosthound Periodic'),
(29677,0,3,4,40,0,100,0,33,29677,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Reached WP33 - Say Line 2'),
(29677,0,4,5,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,'Frosthound - On Reached WP33 - Say Line 3'),
(29677,0,5,6,61,0,100,0,0,0,0,0,11,55036,0,0,0,0,0,23,0,0,0,0,0,0,0,'Frosthound - On Reached WP33 - Cast Frosthound Boss Emote 2'),
(29677,0,6,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Reached WP33 - Despawn'),

(2967700,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - Script - Say Line 0'),
(2967700,9,1,0,0,0,100,0,0,0,0,0,11,55026,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - Script - Cast Frosthound Boss Emote'),
(2967700,9,2,0,0,0,100,0,0,0,0,0,53,1,29677,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - Script - Start WP'),
(2967700,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - Script - Say Line 1');

DELETE FROM `waypoints` WHERE `entry`=29677;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(29677,1,7173.071,-777.0275,899.1846,'Frosthound'),
(29677,2,7182.944,-781.4821,904.6174,'Frosthound'),
(29677,3,7193.046,-787.1729,910.843,'Frosthound'),
(29677,4,7205.287,-793.2994,917.2863,'Frosthound'),
(29677,5,7218.268,-802.1098,921.6022,'Frosthound'),
(29677,6,7230.444,-816.3606,924.8938,'Frosthound'),
(29677,7,7232.167,-834.2318,926.6146,'Frosthound'),
(29677,8,7247.474,-848.1854,925.8355,'Frosthound'),
(29677,9,7263.333,-875.3375,925.127,'Frosthound'),
(29677,10,7275.556,-895.3395,926.4728,'Frosthound'),
(29677,11,7283.682,-922.1505,922.8227,'Frosthound'),
(29677,12,7284.952,-947.7603,918.976,'Frosthound'),
(29677,13,7294.833,-985.7026,915.6023,'Frosthound'),
(29677,14,7291.617,-973.3366,916.3897,'Frosthound'),
(29677,15,7321.158,-1040.365,912.3143,'Frosthound'),
(29677,16,7341.228,-1082.531,906.1441,'Frosthound'),
(29677,17,7355.963,-1127.951,907.6265,'Frosthound'),
(29677,18,7359.741,-1156.937,910.1899,'Frosthound'),
(29677,19,7352.817,-1172.477,912.4103,'Frosthound'),
(29677,20,7340.049,-1188.073,914.7924,'Frosthound'),
(29677,21,7330.804,-1201.472,915.7355,'Frosthound'),
(29677,22,7323.127,-1228.335,909.517,'Frosthound'),
(29677,23,7316.839,-1268.214,902.8563,'Frosthound'),
(29677,24,7316.317,-1300.765,904.0386,'Frosthound'),
(29677,25,7315.278,-1332.342,904.7114,'Frosthound'),
(29677,26,7313.02,-1366.275,907.1307,'Frosthound'),
(29677,27,7312.081,-1399.743,910.574,'Frosthound'),
(29677,28,7312.83,-1434.1,912.8854,'Frosthound'),
(29677,29,7311.606,-1466.343,916.7098,'Frosthound'),
(29677,30,7309.714,-1498.702,921.2195,'Frosthound'),
(29677,31,7306.879,-1531.19,928.3399,'Frosthound'),
(29677,32,7305.797,-1558.925,939.4229,'Frosthound'),
(29677,33,7305.19,-1566.019,941.0005,'Frosthound');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` =1 AND `SourceGroup` =29695 AND `SourceEntry` =40971;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(1,29695,40971,0,0,28,0,12855,0,0,0,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,0,2,0,40971,1,1,1,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,1,9,0,12855,0,0,0,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,1,2,0,40971,1,1,1,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,2,8,0,12855,0,0,0,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,2,2,0,40971,1,1,1,0,0,'','Brann\'s Communicator');

UPDATE `creature_loot_template` SET `QuestRequired`=0 WHERE  `Entry`=29695 AND `Item`=40971;
