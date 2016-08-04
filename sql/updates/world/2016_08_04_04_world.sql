-- 
SET @CGUID := 85647;
SET @OGUID := 235364;

-- missing creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
DELETE FROM `creature` WHERE `guid` IN (56866,57621,57682);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 15271, 530, 0, 0, 1, 0, 0, 0, 0, 10270.9, -6519.52, 63.4511, 0.647896, 120, 5, 0, 0, 0, 1, 0, 0, 0, 20886),
(@CGUID+1, 15649, 530, 0, 0, 1, 0, 0, 0, 0, 9320.62, -7323.15, 15.5084, 5.89452, 120, 5, 0, 0, 0, 1, 0, 0, 0, 20886),
(@CGUID+2, 15649, 530, 0, 0, 1, 0, 0, 0, 0, 9324.59, -6823.18, 18.9366, 2.39027, 120, 5, 0, 0, 0, 1, 0, 0, 0, 20886),
(@CGUID+3, 15649, 530, 0, 0, 1, 0, 0, 0, 0, 9356, -7347.08, 12.2037, 1.3481, 120, 5, 0, 0, 0, 1, 0, 0, 0, 20886),
(@CGUID+4, 15654, 530, 0, 0, 1, 0, 0, 0, 0, 9280.22, -7007.69, 6.44821, 5.97162, 120, 5, 0, 0, 0, 1, 0, 0, 0, 20886),
(@CGUID+5, 16221, 530, 0, 0, 1, 0, 0, 0, 0, 9363.16, -7314.13, 7.11649, 5.64581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 20886),
(56866, 16192, 530, 0, 0, 1, 0, 0, 0, 0, 9376.08, -7165.45, 9.04866, 3.1765, 120, 0, 0, 0, 0, 0, 0, 0, 0, 20886),
(57621, 16626, 530, 0, 0, 1, 0, 0, 0, 0, 9453.1, -7138.56, 16.1339, 0.0120617, 120, 0, 0, 0, 0, 0, 0, 0, 0, 20886),
(57682, 16693, 530, 0, 0, 1, 0, 0, 0, 0, 9451.74, -7122.86, 16.1392, 6.12848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 20886);

UPDATE `creature` SET `spawntimesecs`=120 WHERE `spawntimesecs`=300 AND `id` IN (1420,6368,15367,15366,15372,15273,15298,13321,721,2914,6271,15271,15294,15649,15654);
UPDATE `creature` SET `spawntimesecs`=120 WHERE `id` IN (27946);
UPDATE `creature` SET `spawntimesecs`=30 WHERE `id` IN (44937);
UPDATE `creature` SET `spawndist`=10 AND `MovementType` =1 WHERE `id` IN (61080,61081,61141,61142,2914,6271) AND `MovementType`=0;
UPDATE `creature` SET `spawndist`=5 AND `MovementType` =1 WHERE `id` IN (6271,15271,15294,15649,15654,15298) AND `MovementType`=0;
DELETE FROM `game_event_creature` WHERE `guid`=375628;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES (10, 375628);

-- missing creature texts
DELETE FROM `creature_text` WHERE `entry` IN (15416) AND `id`=0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15416, 0, 0, "Slay them!  Don't let the Scourge scum defile our city!", 14, 0, 100, 0, 0, 0, 12861, 0, 'Ranger Jaela to Rotlimb Cannibal');
UPDATE `creature_text` SET `comment`='Novice Ranger' WHERE `entry`=16923 AND `id`=0;

-- missing npc_text
UPDATE `npc_text` SET `VerifiedBuild` = 20886 WHERE `ID` = 7882;
UPDATE `npc_text` SET `BroadcastTextID0` = 14774, `VerifiedBuild` = 20886 WHERE `ID` = 7904;
UPDATE `npc_text` SET `BroadcastTextID0` = 14192, `VerifiedBuild` = 20886 WHERE `ID` = 9007;
UPDATE `npc_text` SET `BroadcastTextID0` = 14767, `VerifiedBuild` = 20886 WHERE `ID` = 9188;
UPDATE `npc_text` SET `VerifiedBuild` = 20886 WHERE `ID` = 9190;
UPDATE `npc_text` SET `VerifiedBuild` = 20886 WHERE `ID` = 9191;
UPDATE `npc_text` SET `BroadcastTextID0` = 44401, `VerifiedBuild` = 20886 WHERE `ID` = 16541;

DELETE FROM `npc_text` WHERE `ID`=19889;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`) VALUES 
(19889, 'How may I help you?', 'How may I help you?', 61023, 0, 1, 0, 0);

-- missing gameobjects
DELETE FROM `gameobject` WHERE `guid` in (182660,182666,182650,182655,182656,182657,182658,182659,182654);
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 185439, 530, 0, 0, 1, 0, 0, 9465.41, -6866.63, 28.3258, 0.37605, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886),
(@OGUID+1, 185440, 530, 0, 0, 1, 0, 0, 9476.1, -6869.84, 17.3941, 1.54311, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886),
(@OGUID+2, 185441, 530, 0, 0, 1, 0, 0, 9473.66, -6867.08, 17.3951, 6.25813, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886),
(@OGUID+3, 185442, 530, 0, 0, 1, 0, 0, 9462.83, -6846.06, 17.442, 5.54763, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886),
(@OGUID+4, 185443, 530, 0, 0, 1, 0, 0, 9461.68, -6849.18, 17.442, 6.18249, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886),
(@OGUID+5, 185444, 530, 0, 0, 1, 0, 0, 9463.28, -6852.17, 17.442, 1.00393, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886),
(@OGUID+6, 185445, 530, 0, 0, 1, 0, 0, 9468.05, -6852.38, 17.442, 2.36928, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886),
(@OGUID+7, 185446, 530, 0, 0, 1, 0, 0, 9469.41, -6848.85, 17.442, 3.33484, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886),
(@OGUID+8, 185447, 530, 0, 0, 1, 0, 0, 9467.33, -6846.16, 17.442, 4.24132, 0, 0, -0.709134, 0.705074, 120, 255, 1, 20886);

-- missing quest stuff
DELETE FROM `quest_details` WHERE `ID` IN (8563,10073);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8563, 1, 1, 0, 0, 0, 0, 0, 0, 20886),
(10073, 1, 1, 0, 0, 0, 1000, 0, 0, 20886);

UPDATE `quest_request_items` SET `EmoteOnComplete` = 2, `VerifiedBuild` = 20886 WHERE `ID` = 8350;
UPDATE `quest_request_items` SET `EmoteOnComplete` = 0, `CompletionText` = 'Have you mastered Corruption?', `VerifiedBuild` = 20886 WHERE `ID` = 10073;

UPDATE `quest_offer_reward` SET `Emote1` = 4, `Emote2` = 1, `VerifiedBuild` = 20886 WHERE `ID` = 8325;
UPDATE `quest_offer_reward` SET `Emote1` = 4, `Emote2` = 1, `RewardText` = 'The tower and surrounding areas should now be relatively secure, though only for the time being.  You have done well in providing us with a buffer of security, but we will need to reassert control over the entire isle if we are to survive here in the long run.  This will involve tackling much greater threats than errant mana wyrms and lynxes.$B$BTake this, $n - you will no doubt make good use of it for the tasks to come.', `VerifiedBuild` = 20886 WHERE `ID` = 8326;
UPDATE `quest_offer_reward` SET `Emote1` = 2, `Emote2` = 1, `VerifiedBuild` = 20886 WHERE `ID` = 8350;
UPDATE `quest_offer_reward` SET `Emote1` = 1, `Emote2` = 1, `RewardText` = '$n - your name has passed my ears as one seeking out a master in the ways of the warlock.  You look capable enough, but I seek more than just looks from my students.  You must be ready to delve where others fear to look to gain your power.  I will teach you, but I will not tolerate failure.$B$BThere will be monetary costs associated with your training, but you should be more concerned with the cost your mind is willing to make.  If you are ready, we shall begin.', `VerifiedBuild` = 20886 WHERE `ID` = 8563;
UPDATE `quest_offer_reward` SET `Emote1` = 1, `RewardText` = 'Well done, $n. You are quickly becoming one of my best students and I look forward to continuing your training in the future.', `VerifiedBuild` = 20886 WHERE `ID` = 10073;

UPDATE `quest_template` SET `RewardBonusMoney` = 60, `VerifiedBuild` = 20886 WHERE `ID` = 8325;
UPDATE `quest_template` SET `RewardBonusMoney` = 300, `VerifiedBuild` = 20886 WHERE `ID` = 8326;
UPDATE `quest_template` SET  `VerifiedBuild` = 20886 WHERE `ID` = 8327;
UPDATE `quest_template` SET `RewardBonusMoney` = 60, `VerifiedBuild` = 20886 WHERE `ID` = 8350;
UPDATE `quest_template` SET `RewardBonusMoney` = 60, `VerifiedBuild` = 20886 WHERE `ID` = 8563;
UPDATE `quest_template` SET `RewardBonusMoney` = 150, `VerifiedBuild` = 20886 WHERE `ID` = 10073;
