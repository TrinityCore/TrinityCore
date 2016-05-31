SET @RAZUUN            := 21502; -- Image of Warbringer Razuun
SET @JOVAAN            := 21633; -- Deathbringer Jovaan
SET @TRIGGER           := 4548;  -- Smart Trigger
SET @DEVICE            := 184833;-- Legion Communication Device
SET @GO_INFERNAL       := 184834;-- Gobject that needs to be despawned during the script
SET @GO_INFERNAL2      := 184835;-- Gobject that needs to be despawned during the script

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@RAZUUN,@JOVAAN);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@JOVAAN,@RAZUUN) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@JOVAAN*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@RAZUUN,0,0,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On data 0 1 set - Say line'),
(@RAZUUN,0,1,0,38,0,100,0,0,2,0,0,1,1,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On data 0 2 set - Say line'),
(@RAZUUN,0,2,0,52,0,100,0,1,@RAZUUN,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On text over - Play emote'),
(@RAZUUN,0,3,0,38,0,100,0,0,3,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On data 0 3 set - Say line'),
(@RAZUUN,0,4,0,38,0,100,0,0,4,0,0,1,3,1500,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On data 0 4 set - Say line'),
(@RAZUUN,0,5,0,52,0,100,0,3,@RAZUUN,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Warbringer Razuun - On text over - Play emote'),
(@JOVAAN,0,0,1,11,0,100,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - Just summoned - Spellcast Etheral Teleport'),
(@JOVAAN,0,1,0,61,0,100,0,0,0,0,0,53,0,@JOVAAN,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - Just summoned - Start WP movement'),
(@JOVAAN,0,2,3,40,0,100,0,4,@JOVAAN,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - On WP 4 reached - Pause 45 seconds'),
(@JOVAAN,0,3,0,61,0,100,0,0,0,0,0,80,@JOVAAN*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan - On WP 4 reached - Run Script'),

(@JOVAAN*100,9,0,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,14,25736,@DEVICE,0,0,0,0,0,'Deathbringer Jovaan script - Turn to Legion Communication Device'),
(@JOVAAN*100,9,1,0,0,0,100,0,2500,2500,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Play emote'),
(@JOVAAN*100,9,2,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Say line'),
(@JOVAAN*100,9,3,0,0,0,100,0,100,100,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Set unit_field_bytes1 (kneel)'),
(@JOVAAN*100,9,4,0,0,0,100,0,100,100,0,0,12,@RAZUUN,1,37500,0,0,0,8,0,0,0,-3300.087,2927.053,173.3354,2.199115,'Deathbringer Jovaan script - Summon Image of Warbringer Razuun'),
(@JOVAAN*100,9,5,0,0,0,100,0,800,800,0,0,45,0,1,0,0,0,0,19,@RAZUUN,10,0,0,0,0,0,'Deathbringer Jovaan script - Set data 0 1 Image of Warbringer Razuun'),
(@JOVAAN*100,9,6,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Say line'),
(@JOVAAN*100,9,7,0,0,0,100,0,5000,5000,0,0,45,0,2,0,0,0,0,19,@RAZUUN,10,0,0,0,0,0,'Deathbringer Jovaan script - Set data 0 2 Image of Warbringer Razuun'),
(@JOVAAN*100,9,8,0,0,0,100,0,7000,7000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Remove unit_field_bytes1 (kneel)'),
(@JOVAAN*100,9,9,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Say line'),
(@JOVAAN*100,9,10,0,0,0,100,0,6000,6000,0,0,45,0,3,0,0,0,0,19,@RAZUUN,10,0,0,0,0,0,'Deathbringer Jovaan script - Set data 0 3 Image of Warbringer Razuun'),
(@JOVAAN*100,9,11,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Say line'),
(@JOVAAN*100,9,12,0,0,0,100,0,4000,4000,0,0,45,0,4,0,0,0,0,19,@RAZUUN,10,0,0,0,0,0,'Deathbringer Jovaan script - Set data 0 4 Image of Warbringer Razuun'),
(@JOVAAN*100,9,13,0,0,0,100,0,3500,3500,0,0,33,@RAZUUN,0,0,0,0,0,21,20,0,0,0,0,0,0,'Deathbringer Jovaan script - Give Quest Credit'),
(@JOVAAN*100,9,14,0,0,0,100,0,0,0,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathbringer Jovaan script - Play emote');

DELETE FROM `creature_text` WHERE `entry` IN (@RAZUUN,@JOVAAN);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@RAZUUN,0,0,'Doom Lord Kazzak will be pleased. You are to increase the pace of your attacks. Destroy the orcish and dwarven strongholds with all haste.',12,0,100,1,0,0,'Razuun'),
(@RAZUUN,1,0,'Don''t worry about that. I''ve increased production at the Deathforge. You''ll have all the infernals you need to carry out your orders. Don''t fail, Jovaan.',12,0,100,1,0,0,'Razuun'),
(@RAZUUN,2,0,'Yes?',12,0,100,6,0,0,'Razuun'),
(@RAZUUN,3,0,'Crate? I didn''t send you a crate, Jovaan. Don''t you have more important things to worry about? Go see to them!',12,0,100,274,0,0,'Razuun'),
(@JOVAAN,0,0,'Everything is in readiness, warbringer.',12,0,100,0,0,0,'Jovaan'),
(@JOVAAN,1,0,'Warbringer, that will require the use of all the hold''s infernals. It may leave us vulnerable to a counterattack.',12,0,100,0,0,0,'Jovaan'),
(@JOVAAN,2,0,'It shall be as you say, warbringer. One last question, if I may...',12,0,100,6,0,0,'Jovaan'),
(@JOVAAN,3,0,'What''s in the crate?',12,0,100,6,0,0,'Jovaan');

DELETE FROM `waypoints` WHERE `entry`=@JOVAAN;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@JOVAAN, 1, -3310.995, 2951.892, 171.2171, 'Deathbrinder Jovaan'),
(@JOVAAN, 2, -3307.998, 2942.022, 171.1127, 'Deathbrinder Jovaan'),
(@JOVAAN, 3, -3306.255, 2935.729, 171.0294, 'Deathbrinder Jovaan'),
(@JOVAAN, 4, -3304.257, 2930.78, 170.9866, 'Deathbrinder Jovaan'),
(@JOVAAN, 5, -3307.609, 2936.385, 170.9919, 'Deathbrinder Jovaan'),
(@JOVAAN, 6, -3309.415, 2942.621, 171.119, 'Deathbrinder Jovaan');

DELETE FROM `areatrigger_scripts` WHERE `entry`=@TRIGGER;
INSERT INTO `areatrigger_scripts` VALUES (@TRIGGER,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@TRIGGER,2,0,1,46,0,100,0,@TRIGGER,0,0,0,45,0,0,0,0,0,0,14,25736,@DEVICE,0,0,0,0,0,'Smart Trigger - On Trigger - Set Data to GO'),
(@TRIGGER,2,1,2,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,14,25737,@GO_INFERNAL,0,0,0,0,0,'Smart Trigger - On Link - Set Data GO'),
(@TRIGGER,2,2,0,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,14,25738,@GO_INFERNAL2,0,0,0,0,0,'Smart Trigger - On Link - Set Data GO');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@DEVICE,@GO_INFERNAL,@GO_INFERNAL2);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid` IN (@DEVICE,@GO_INFERNAL,@GO_INFERNAL2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@DEVICE,1,0,0,38,0,100,0,0,0,0,0,12,@JOVAAN,1,57000,0,0,0,8,0,0,0,-3310.995, 2951.892, 171.2171, 5.5355,'Legion Communicator - On Data Set - Summon Jovaan'),
(@GO_INFERNAL,1,0,0,38,0,100,0,0,1,0,0,99,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infernal  - On Data Set- Change State'),
(@GO_INFERNAL,1,1,0,70,0,100,0,2,0,0,0,70,50,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infernal - On Data Set- Despawn GO'),
(@GO_INFERNAL2,1,0,0,38,0,100,0,0,2,0,0,99,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infernal 2 - On Data Set- Change State'),
(@GO_INFERNAL2,1,1,0,70,0,100,0,2,0,0,0,70,50,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infernal 2 - On Data Set - Despawn GO');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (@TRIGGER,@DEVICE);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@TRIGGER,2,0,1,0,37097,0,0,0,0,'','SAI areatrigger 4548 triggers only if player has aura Crate Disguise'),
(22,1,@TRIGGER,2,0,29,0,@JOVAAN,50,0,1,0,'','SAI areatrigger 4548 triggers only if there is no Deathbringer Jovaan present'),
(22,1,@DEVICE,2,0,1,0,37097,0,0,0,0,'','SAI Legion Communication Device triggers only if player has aura Crate Disguise');
