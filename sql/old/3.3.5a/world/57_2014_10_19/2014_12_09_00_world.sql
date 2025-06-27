DELETE FROM `spell_area` WHERE `spell`=58932;
DELETE FROM `spell_area` WHERE `spell`=60778;

INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`,`racemask`, `autocast`, `gender`, `quest_start_status`, `quest_end_status`) VALUES(58932, 4171, 12499, 0,1101, 1,2,64,11),
(58932, 4171, 12499, 0,0, 1,2,64,11),
(58932, 4172, 12499, 0,0, 1,2,64,11),
(58932, 4171, 12500, 0,0, 1,2,64,11),
(58932, 4172, 12500, 0,0, 1,2,64,11),
(60778, 4171, 12499, 0,0, 1,2,64,11),
(60778, 4172, 12499, 0,0, 1,2,64,11),
(60778, 4171, 12500, 0,0, 1,2,64,11),
(60778, 4172, 12500, 0,0, 1,2,64,11);

DELETE FROM `creature_text` WHERE `entry` IN(31333,31334);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(31333, 0, 0, 'No, my beloved.', 12, 0, 100, 1, 0, 0, 32040, 'Alexstrasza the Life-Binder to Player'),
(31333, 1, 0, 'They must not discover the fate of the young paladin. Not yet.', 12, 11, 100, 5, 0, 0, 32041, 'Alexstrasza the Life-Binder to Player'),
(31333, 2, 0, 'Come to me, $n.', 15, 0, 100, 0, 0, 0, 32048, 'Alexstrasza the Life-Binder to Player'),
(31334, 0, 0, 'My Queen, do they know?', 12, 0, 100, 6, 0, 0, 32038, 'Korialstrasz to Player'),
(31334, 1, 0, '%s nods.', 16, 0, 100, 0, 0, 0, 32046, 'Korialstrasz to Player'),
(31334, 2, 0, 'They will not.', 12, 0, 100, 1, 0, 0, 32047, 'Korialstrasz to Player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10179;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=31333;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10179, 0, 0, 0, 8, 0, 12499, 0, 0, 0, 0, 0, '', 'Alexstrasza the Life-Binder - Show Gossip if player is rewarded for Return To Angrathar'),
(15, 10179, 0, 0, 1, 8, 0, 12500, 0, 0, 0, 0, 0, '', 'Alexstrasza the Life-Binder - Show Gossip if player is rewarded for Return To Angrathar'),
(22, 3, 31333, 0, 0, 8, 0, 12499, 0, 0, 0, 0, 0, '', 'Alexstrasza the Life-Binder - Run AI only if player is rewarded for Return To Angrathar'),
(22, 3, 31333, 0, 1, 8, 0, 12500, 0, 0, 0, 0, 0, '', 'Alexstrasza the Life-Binder - Run AI only if player is rewarded for Return To Angrathar');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='', `npcflag`=3 WHERE `entry`=31333;

DELETE FROM `smart_scripts` WHERE `entryorguid`=31333  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3133300  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31333,0,0,1,62,0,100,0,10179,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - On Gossip Option select - Close Gossip'),
(31333,0,1,0,61,0,100,0,0,0,0,0,68,14,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - On Gossip Option select - Play Movie'),
(31333,0,2,3,10,0,100,0,1,40,120000,120000,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - OOC Los - Store Targetlist'),
(31333,0,3,0,61,0,100,0,0,0,0,0,80,3133300,2,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - OOC Los - Run Script'),
(3133300,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,31334,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 0 (Korialstrasz)'),
(3133300,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 0 (Alexstrasza the Life-Binder)'),
(3133300,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 1 (Alexstrasza the Life-Binder)'),
(3133300,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,31334,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 1 (Korialstrasz)'),
(3133300,9,4,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,19,31334,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 2 (Korialstrasz)'),
(3133300,9,5,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 2 (Alexstrasza the Life-Binder)');

DELETE FROM `creature_template_addon` WHERE `entry` IN (31328, 31330, 26850, 31293, 31333, 28348, 31334, 31292, 31295, 31291, 31308, 31294, 31298, 31285, 31309, 31296, 31358, 31297, 31299, 31313, 31310, 26877);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(31328, 0, 0x0, 0x1, ''), -- 31328
(31330, 0, 0x0, 0x1, ''), -- 31330
(26850, 0, 0x0, 0x101, ''), -- 26850
(31293, 0, 0x10007, 0x1, '29266'), -- 31293 - 29266
(31333, 0, 0x3000001, 0x1, '60778'), -- 31333 - 60778
(28348, 0, 0x10000, 0x1, ''), -- 28348
(31334, 0, 0x3000001, 0x1, ''), -- 31334
(31292, 0, 0x10007, 0x1, '29266'), -- 31292 - 29266
(31295, 0, 0x10007, 0x1, '29266'), -- 31295 - 29266
(31291, 0, 0x10000, 0x1, ''), -- 31291
(31308, 0, 0x10007, 0x1, '29266'), -- 31308 - 29266
(31294, 0, 0x10007, 0x1, '29266'), -- 31294 - 29266
(31298, 0, 0x10007, 0x1, '29266'), -- 31298 - 29266
(31285, 0, 0x10007, 0x1, '29266'), -- 31285 - 29266
(31309, 0, 0x10007, 0x1, '29266'), -- 31309 - 29266
(31296, 0, 0x10007, 0x1, '29266'), -- 31296 - 29266
(31358, 0, 0x0, 0x1, ''), -- 31358
(31297, 0, 0x10007, 0x1, '29266'), -- 31297 - 29266
(31299, 0, 0x10007, 0x1, '29266'), -- 31299 - 29266
(31313, 0, 0x0, 0x1, ''), -- 31313
(31310, 0, 0x0, 0x1, ''), -- 31310
(26877, 0, 0x0, 0x101, ''); -- 26877

