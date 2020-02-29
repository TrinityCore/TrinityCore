-- Koltira Deathweaver
DELETE FROM `creature_text` WHERE `CreatureID`=28912;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28912,0,0,'Damn the Crusade! I think my ribs are broken and I might be bleeding internally.',12,0,100,1,0,0,29197,0,'Koltira Deathweaver'),
(28912,1,0,'I''ll need to get my runeblade and armor... Just need a little more time.',12,0,100,0,0,0,29201,0,'Koltira Deathweaver'),
(28912,2,0,'I''m still weak, but I think I can get an anti-magic barrier up. Stay inside it or you''ll be destroyed by their spells.',12,0,100,0,0,0,29203,0,'Koltira Deathweaver'),
(28912,3,0,'Maintaining this barrier will require all of my concentration. Kill them all!',12,0,100,0,0,0,29205,0,'Koltira Deathweaver'),
(28912,4,0,'There are more coming. Defend yourself! Don''t fall out of the anti-magic field! They''ll tear you apart without its protection!',12,0,100,0,0,0,29207,0,'Koltira Deathweaver'),
(28912,5,0,'I can''t keep this barrier up much longer... Where is that coward?',12,0,100,0,0,0,29208,0,'Koltira Deathweaver'),
(28912,6,0,'The High Inquisitor comes! Be ready, death knight! Do not let him draw you out of the protective bounds of my anti-magic field! Kill him and take his head!',12,0,100,0,0,0,29210,0,'Koltira Deathweaver'),
(28912,7,0,'Stay in the anti-magic field! Make them come to you!',12,0,100,0,0,0,29225,0,'Koltira Deathweaver'),
(28912,7,1,'Stand your ground! Use my anti-magic barrier to dampen their spells!',12,0,100,0,0,0,29224,0,'Koltira Deathweaver'),
(28912,8,0,'The death of the High Inquisitor of New Avalon will not go unnoticed. You need to get out of here at once! Go, before more of them show up. I''ll be fine on my own.',12,0,100,1,0,0,29239,0,'Koltira Deathweaver'),
(28912,9,0,'I''ll draw their fire, you make your escape behind me.',12,0,100,1,0,0,29240,0,'Koltira Deathweaver'),
(28912,10,0,'Your High Inquisitor is nothing more than a pile of meat, Crusaders! There are none beyond the grasp of the Scourge!',14,0,100,22,0,0,29241,0,'Koltira Deathweaver');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=28912;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(28912,0,0,29007,1640.672,-6032.053,134.8221,4.679538,6,5000),
(28912,0,0,29007,1641.005,-6031.893,134.8221,0.4014257,6,5000),
(28912,0,0,29007,1639.705,-6031.737,134.8221,2.443461,6,5000),
(28912,0,1,29007,1640.404,-6032.289,134.7387,4.517092,6,5000),
(28912,0,1,29007,1641.73,-6030.751,134.8221,6.143559,6,5000),
(28912,0,1,29007,1639.466,-6030.404,134.8221,4.502949,6,5000),
(28912,0,2,29007,1640.286,-6033.075,134.6049,4.679538,6,5000),
(28912,0,2,29007,1642.04,-6030.384,134.8221,1.37881,6,5000),
(28912,0,2,29007,1640.116,-6029.782,134.8221,5.707227,6,5000),
(28912,0,2,29007,1640.995,-6029.803,134.8221,1.605703,6,5000),
(28912,0,3,29001,1640.766,-6032.984,134.5805,4.596632,5,0);

DELETE FROM `waypoint_data` WHERE `id`=28912;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `action`, `orientation`, `action_chance`, `move_type`) VALUES
(28912,1,1640.65,-6032.49,134.739,0,0,0,100,1),
(28912,2,1639.1,-6028.1,134.739,0,0,0,100,1),
(28912,3,1628.37,-6026.34,134.739,0,0,0,100,1),
(28912,4,1625.79,-6021.81,134.739,0,0,0,100,1),
(28912,5,1627.06,-6016.95,134.739,0,0,0,100,1),
(28912,6,1639.85,-6015.64,134.74,0,0,0,100,1),
(28912,7,1653.376,-5971.874,132.2567,0,0,0,100,1),
(28912,8,1653.61,-5927.44,121.345,0,0,0,100,1),
(28912,9,1656.07,-5905.5,116.21,0,0,0,100,1),
(28912,10,1681.736,-5888.621,116.257,0,1188,0,100,1);
UPDATE `creature_addon` SET `bytes1`=0,`auras`='' WHERE `guid`=130354;
UPDATE `creature` SET  `spawntimesecs`=60 WHERE `guid`=130354;

DELETE FROM `creature_equip_template` WHERE `CreatureID`=28912;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(28912,1,38633,0,0,0);

-- High Inquisitor Valroth
DELETE FROM `creature_text` WHERE `CreatureID`=29011;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(29011,0,0,'Acolytes, chain them all up! Prepare them for questioning!',14,0,100,1,0,0,29202,0,'High Inquisitor Valroth'),
(29011,1,0,'Scourge filth! By the Light be cleansed!',14,0,100,0,0,0,29214,0,'High Inquisitor Valroth'),
(29011,2,0,'The Crusade will purge your kind from this world!',14,0,100,0,0,0,29215,0,'High Inquisitor Valroth'),
(29011,3,0,'It seems that I''ll need to deal with you myself. The High Inquisitor comes for you, Scourge!',14,0,100,0,0,0,29216,0,'High Inquisitor Valroth');

DELETE FROM `creature_text` WHERE `CreatureID`=29001;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(29001,0,0,'Coward!',12,0,100,0,0,0,29219,0,'High Inquisitor Valroth'),
(29001,0,1,'Come out and play.',12,0,100,0,0,0,29220,0,'High Inquisitor Valroth'),
(29001,0,2,'LIGHT PURGE YOU!',12,0,100,1,0,0,29221,0,'High Inquisitor Valroth'),
(29001,0,3,'You have come seeking deliverance? I have come to deliver!',12,0,100,1,0,0,29222,0,'High Inquisitor Valroth'),
(29001,1,0,'%s''s remains fall to the ground.',41,0,100,1,0,0,29223,0,'High Inquisitor Valroth');

DELETE FROM `waypoints` WHERE `entry`=29001;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(29001,1,1639.495,-6043.913,128.2694,'High Inquisitor Valroth'),
(29001,2,1639.186,-6046.568,127.9465,'High Inquisitor Valroth'),
(29001,3,1648.31,-6043.64,127.5836,'High Inquisitor Valroth');
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=29001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29001 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29001,0,0,0,54,0,100,0,0,0,0,0,0,53,1,29001,0,0,0,2,1,0,0,0,0,0,0,0,0,'High Inquisitor Valroth - On just summoned - Start WP'),
(29001,0,1,2,58,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'High Inquisitor Valroth - On WP ended - Remove unit flags'),
(29001,0,2,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,10,0,0,0,0,0,0,0,'High Inquisitor Valroth - Linked event - Attack start'),
(29001,0,3,0,0,0,100,0,0,40,3400,4700,0,11,52926,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'High Inquisitor Valroth - IC CMC - Cast \'Valroth''s Smite\''),
(29001,0,4,5,24,0,100,0,52894,0,7000,12000,0,11,52922,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'High Inquisitor Valroth - On target has \'Anti-Magic Zone\' aura - Cast \'The Inquisitor''s Penance\''),
(29001,0,5,0,61,0,50,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'High Inquisitor Valroth - Linked event - Say line 0'),
(29001,0,6,0,2,0,100,1,0,50,0,0,0,11,38210,64,0,0,0,0,1,0,0,0,0,0,0,0,0,'High Inquisitor Valroth - Between 0-50% HP - Cast \'Renew\' (No Repeat)'),
(29001,0,7,8,6,0,100,0,0,0,0,0,0,11,52929,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'High Inquisitor Valroth - On just died - Cast \'Summon Valroth''s Remains\''),
(29001,0,8,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'High Inquisitor Valroth - Linked event - Say line 1');

-- Crimson Acolyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=29007 AND `source_type`=0 AND `id` IN (3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2900700,2900701,2900702) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29007,0,3,0,54,0,100,0,0,0,0,0,0,88,2900700,2900701,2900702,0,0,0,1,0,0,0,0,0,0,0,0,'Crimson Acolyte - On just summoned - Random action list'),
(29007,0,4,5,34,0,100,0,8,1,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Crimson Acolyte - On movement inform - Remove unit flags'),
(29007,0,5,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,10,0,0,0,0,0,0,0,'Crimson Acolyte - Linked event - Attack start'),
(2900700,9,0,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,1649.966,-6042.571,127.5833,0,'Crimson Acolyte - Action list 0 - Move to position'),
(2900701,9,0,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,1642.704,-6045.236,127.8326,0,'Crimson Acolyte - Action list 1 - Move to position'),
(2900702,9,0,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,1641.506,-6045.676,127.9491,0,'Crimson Acolyte - Action list 2 - Move to position');
