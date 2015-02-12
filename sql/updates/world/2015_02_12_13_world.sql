SET @Spell            := 91938; -- Spell to summon
SET @Darnell          := 49337; -- Darnell Gardian
SET @Caice            := 2307;  -- Caice Quest giver
SET @Saltain          := 1740;  -- Deathguard Saltain
SET @Corpse           := 49340; -- Scarlet Corpse

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100+1  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100+2  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Saltain AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Saltain*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Saltain*100+1  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Caice  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Caice*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Corpse AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Corpse*100  AND `source_type` = 9;

UPDATE `creature_template` SET `AIName`='SmartAI', `npcflag`=16777216, `VehicleId`= 1392 WHERE `entry`=@Darnell;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Caice, @Saltain);
UPDATE `creature_template` SET `AIName`='SmartAI', npcflag=0 WHERE `entry`=@Corpse;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Caice, 0, 0, 0, 19, 0, 100, 0, 25089, 0, 0, 0, 85, @Spell, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Caice - On Quest Accept - Cast Spell To Summon'),
(@Darnell, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Darnell*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Action list'),
(@Darnell*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState passif'),
(@Darnell*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Darnell, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - Action list - Start wp'),
(@Darnell, 0, 1, 0, 40, 0, 100, 0, 5, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell, 0, 2, 0, 40, 0, 100, 0, 7, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Saltain, 0, 0, 0, 19, 0, 100, 0, 26800, 0, 0, 0, 80, @Saltain*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Saltain - On Quest accept- action list'),
(@Saltain*100+1, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 85, @Spell, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Saltain - Action list - Cast Spell To Summon'), -- 3secs delay to avoid the despawn
(@Darnell, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Darnell*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Action list'),
(@Darnell*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState passif'),
(@Darnell*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+1, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Corpse, 0, 0, 0, 75, 0, 100, 1, 0, @Darnell, 3, 0, 80, @Corpse*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corpse - On DISTANCE_CREATURE - Action list'),
(@Corpse*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 46598, 1, 0, 0, 0, 0, 19, @Darnell, 10, 0, 0, 0, 0, 0, 'Corpse - Action list - cast spell'),
(@Corpse*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @Corpse, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Corpse - Actionlist - Credit quest'),
(@Saltain, 0, 1, 0, 20, 0, 100, 0, 26800, 0, 0, 0, 80, @Saltain*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Saltain - On Quest rewarded- action list'),
(@Saltain*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Darnell, 20, 0, 0, 0, 0, 0, 'Saltain - action list - Despawn'),
(@Saltain*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Corpse, 20, 0, 0, 0, 0, 0, 'Saltain - action list - Despawn'),
(@Saltain, 0, 2, 0, 20, 0, 100, 0, 25089, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Darnell, 20, 0, 0, 0, 0, 0, 'Saltain - On Quest rewarded - despawn'); 

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@Darnell;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,4,@Darnell,0,0,9,0,26800,0,0,0,0,'','Event quest 26800'),
(22,1,@Darnell,0,0,9,0,25089,0,0,1,0,'','Event quest 25089'); 

DELETE  FROM `creature_text` WHERE `entry`= @Darnell;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Darnell, 0, 0, 'Hello again.', 12, 0, 100, 3, 0, 0, 'Darnell', 49455),
(@Darnell, 1, 0, 'I know the way to Deathknell. Come with me!', 12, 0, 100, 273, 0, 0, 'Darnell', 49456),
(@Darnell, 2, 0, 'Good, you''re still here. Now, where''s Deathguard Saltain?', 12, 0, 100, 1, 0, 0, 'Darnell', 49457),
(@Darnell, 3, 0, 'Ah, here he is.', 12, 0, 100, 1, 0, 0, 'Darnell', 49458),
(@Darnell, 4, 0, 'Let''s get moving, $n. Saltain said that we''d fine some corpses up here.', 12, 0, 100, 1, 0, 0, 'Darnell', 49459),
(@Darnell, 5, 0, 'I think I see some corpses up ahead. Let''s go, $n! You do the searching and fighting. I''ll do the lifting.', 12, 0, 100, 0, 0, 0, 'Darnell', 49460);

DELETE FROM `waypoints` WHERE `entry`=@Darnell;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Darnell,1,1692.472168, 1653.235474, 130.319809, 'Darnell'), 
(@Darnell,2,1697.396973, 1653.904175, 128.853043, 'Darnell'), 
(@Darnell,3,1721.264160, 1635.621948, 121.329689, 'Darnell'), 
(@Darnell,4,1765.116577, 1602.026978, 109.535789, 'Darnell'), 
(@Darnell,5,1798.010742, 1591.826904, 101.370865, 'Darnell'), 
(@Darnell,6,1847.364136, 1587.727539, 93.158165, 'Darnell'), 
(@Darnell,7,1860.151245, 1601.413208, 94.669510, 'Darnell');
