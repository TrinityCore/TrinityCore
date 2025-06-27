--
SET @Geant:=24385;
SET @Megalithe:=24381; 

UPDATE `event_scripts` SET `x`=2406.492188 , `y`=-5738.995605, `z`=274.020172 , `o`=0.703918 WHERE `id`=15939;
UPDATE `creature_template` SET `unit_flags`=33600, `AIName`='SmartAI' WHERE `entry` IN (@Geant,@Megalithe);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@Geant,@Megalithe);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@Geant*100,@Megalithe*100);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Megalithe, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Megalithe*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - On Just summoned - action list'),
(@Megalithe*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24385, 7, 0, 0, 0, 0, 8, 0, 0, 0, 2410.138184, -5727.264648, 270.985870, 4.287692, 'Megalithe - action liste -Summon'),
(@Megalithe*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24385, 7, 0, 0, 0, 0, 8, 0, 0, 0, 2414.860596, -5729.499512, 272.095459, 3.982957, 'Megalithe - action liste -Summon'),
(@Megalithe*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24385, 7, 0, 0, 0, 0, 8, 0, 0, 0, 2417.339844, -5733.230957, 273.028992, 3.603609, 'Megalithe - action liste -Summon'),
(@Megalithe*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24385, 7, 0, 0, 0, 0, 8, 0, 0, 0, 2419.397705, -5738.032227, 274.121246, 3.241538, 'Megalithe - action liste -Summon'),
(@Megalithe*100, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Megalithe*100, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Megalithe*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Megalithe*100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 80, @Geant*100, 0, 0, 0, 0, 0, 11, @Geant, 30, 0, 0, 0, 0, 0, 'Megalithe - action liste - Action List'),
(@Megalithe*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43693, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Cast Credit Quest'),
(@Megalithe*100, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Megalithe*100, 9, 10, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Megalithe - action liste - Talk'),
(@Geant*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Geant - action liste - Run off'),
(@Geant*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2515.453369, -5670.358398, 298.778076, 0.618311, 'Geant - action liste - Gotopos'), 
(@Geant*100, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Geant - action liste - Despawnn');

DELETE FROM `creature_text` WHERE `entry` IN (@Megalithe);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Megalithe, 0, 0, 'Arise from the earth, my brothers!', 12, 0, 100, 0, 0, 0, 'Megalithe', 23311),
(@Megalithe, 1, 0, 'Our iron masters have a mission for us!', 12, 0, 100, 0, 0, 0, 'Megalithe', 23312),
(@Megalithe, 2, 0, 'Follow me into the mountains to carry out the plan of the masters!', 12, 0, 100, 0, 0, 0, 'Megalithe', 23315),
(@Megalithe, 3, 0, 'We will not fail!', 12, 0, 100, 0, 0, 0, 'Megalithe', 23332);
