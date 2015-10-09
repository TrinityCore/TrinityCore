SET @gob:=192492;
SET @spell:=56649;
SET @Veranus:=30393;
SET @Thorim:= 30390;
SET @Jokkum:=30331;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Veranus, @Thorim, @Jokkum);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Veranus, @Thorim, @Jokkum);
UPDATE `creature_template` SET `ScriptName`="", `MovementType`=2 WHERE `entry`=@Jokkum;

DELETE FROM `creature_template_addon` WHERE `entry`=@Veranus;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@Veranus, 0, 0, 33554432, 0, 0, '55971');

DELETE FROM `vehicle_template_accessory` where `entry` IN (@Veranus) AND `accessory_entry` in (@Thorim);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(@Veranus,@Thorim,0,0,'Veranus',8,0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (@Veranus);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@Veranus, 46598, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9900;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9900,0,0,0,9,0,13010,0,0,0,0,'','Show gossip if player has quest completed'),
(15,9900,0,0,0,5,0,1119,704,0,0,0,'','Show gossip if player is at least friendly');

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Jokkum AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Thorim AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Veranus AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Jokkum*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Thorim*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Thorim*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Thorim*100+2 AND `source_type` = 9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Jokkum, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Jokkum*100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - JustSummoned - Start WP'),
(@Jokkum, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - JustSummoned - Talk1'),
(@Jokkum, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - JustSummoned - Add unit flag'),
(@Jokkum, 0, 3, 0, 40, 0, 100, 0, 22, @Jokkum*100, 0, 0, 80, @Jokkum*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - On way pont 22 - Actionlist'),
(@Jokkum*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @spell, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Cast spell to summon'),
(@Jokkum*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Root'),
(@Jokkum*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Talk2'),
(@Jokkum*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Emote'),
(@Jokkum*100, 9, 4, 0, 0, 0, 100, 0, 24000, 24000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 6, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 8, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 68442, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - remove kneel'),
(@Jokkum*100, 9, 10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 11, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 12, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 80, @Thorim*100+1, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Actionlist'),
(@Jokkum*100, 9, 13, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 14, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Thorim, 30, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 15, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'),
(@Jokkum*100, 9, 16, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - talk'), 
(@Jokkum*100, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 56545, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Cast credit'),
(@Jokkum*100, 9, 18, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Cast eject passenger'),
(@Jokkum*100, 9, 19, 0, 0, 0, 100, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - remove root'),
(@Jokkum*100, 9, 20, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 1, @Jokkum*100+1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jokkum - ActionList - Start WP2'),
(@Thorim*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 50, @gob, 400000, 0, 0, 0, 0, 8, 0, 0, 0, 7867.189453, -3255.752930, 853.379700, 2.321934, 'Thorim - ActionList - Spawn gob'),
(@Thorim*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 50, 188142, 400000, 0, 0, 0, 0, 8, 0, 0, 0, 7867.189453, -3255.752930, 850.467590, 2.321934, 'Thorim - ActionList - Spawn gob'),
(@Thorim, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, @Thorim*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - Just created - actionlist'),
(@Thorim*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - ActionList - set run ON'),
(@Thorim*100, 9, 1, 0, 0, 0, 100, 0, 18000, 18000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 7886.027344, -3239.358887, 849.435791, 3.769581, 'Thorim - ActionList - go to pos'), 
(@Thorim*100, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 75, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - ActionList - Aura state kneel'),
(@Thorim*100, 9, 3, 0, 0, 0, 100, 0, 460000, 460000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - ActionList - Aura state kneel'),
(@Thorim, 0, 1, 0, 19, 0, 100, 0, 13057, 0, 0, 0, 80, @Thorim*100+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - Just created - actionlist'),
(@Thorim*100+2, 9, 0, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thorim - ActionList - Aura state kneel'),
(@Veranus, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Veranus*100, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - JustSummoned - Start WP'),
(@Veranus, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - JustSummoned - Set unit_flag not selectable'),
(@Veranus, 0, 2, 0, 40, 0, 100, 0, 2, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - On waypoint 2 - Eject passenger');

DELETE FROM `waypoint_data` WHERE `id` IN (2072200, 2072201);

DELETE FROM `waypoints` WHERE `entry`IN (@Jokkum*100+1, @Jokkum*100, @Veranus*100);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Jokkum*100+1,1,7837.09, -3235.54, 853.878, '@Jokkum'),
(@Jokkum*100+1,2,7828.62, -3230.38, 855.915, '@Jokkum'),
(@Jokkum*100+1,3,7793.78, -3219.74, 861.146, '@Jokkum'),
(@Jokkum*100+1,4,7765.22, -3225.37, 864.083, '@Jokkum'),
(@Jokkum*100+1,5,7736.73, -3226.5, 861.458, '@Jokkum'),
(@Jokkum*100,1,7357.09,-2865.4,803.501, '@Jokkum'),
(@Jokkum*100,2,7355.18,-2904.32,821.008, '@Jokkum'),
(@Jokkum*100,3,7355.47,-2946.65,833.092, '@Jokkum'),
(@Jokkum*100,4,7358.79,-2974.21,845.018, '@Jokkum'),
(@Jokkum*100,5,7360.87,-2994.78,845.989, '@Jokkum'),
(@Jokkum*100,6,7378.76,-3035.89,840.6, '@Jokkum'),
(@Jokkum*100,7,7411.66,-3072.21,837.577, '@Jokkum'),
(@Jokkum*100,8,7454,-3088.7,837.577, '@Jokkum'),
(@Jokkum*100,9,7496.08,-3113.92,837.583, '@Jokkum'),
(@Jokkum*100,10,7536.84,-3136.49,837.581, '@Jokkum'),
(@Jokkum*100,11,7564.74,-3145.14,844.831, '@Jokkum'),
(@Jokkum*100,12,7604.36,-3171.26,850.887, '@Jokkum'),
(@Jokkum*100,13,7635.47,-3207.21,857.19, '@Jokkum'),
(@Jokkum*100,14,7657.86,-3219.26,863.19, '@Jokkum'),
(@Jokkum*100,15,7685.42,-3218.98,867.141, '@Jokkum'),
(@Jokkum*100,16,7706.54,-3219.74,864.333, '@Jokkum'),
(@Jokkum*100,17,7747.33,-3226.99,862.458, '@Jokkum'),
(@Jokkum*100,18,7796.66,-3221.78,860.646, '@Jokkum'),
(@Jokkum*100,19,7827.6, -3229.27,856.415, '@Jokkum'),
(@Jokkum*100,20,7846.17,-3253.24,852.128, '@Jokkum'),
(@Jokkum*100,21,7849.41,-3270.86,854.538, '@Jokkum'),
(@Jokkum*100,22,7853.12,-3268.03,853.50, '@Jokkum'),
(@Veranus*100,1, 7915.017578, -3202.903076, 899.580872, '@Veranus'),
(@Veranus*100,2, 7889.363770, -3236.394043, 899.580872, '@Veranus'),  
(@Veranus*100,3, 7865.838867, -3266.453369, 899.580872, '@Veranus'),
(@Veranus*100,4, 7929.517578, -3369.971191, 899.580872, '@Veranus');
