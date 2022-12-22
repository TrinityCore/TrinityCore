SET @CGUID := 396007;
SET @OGUID := 243768;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=6590, `minlevel`=60, `maxlevel`=60 WHERE `entry`=15354; -- Rachelle Gothena
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry` IN (54170, 54146); -- Delian Sunshade
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags`=537166080, `unit_flags2`=34817, `unit_flags3`=8192 WHERE `entry`=54142; -- Hired Courier

DELETE FROM `creature_template_addon` WHERE `entry` IN (15354, 54141, 54142, 54146, 54170);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(15354, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 15354 (Rachelle Gothena)
(54141, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 54141 (Edgar Goodwin)
(54142, 0, 0, 0, 1, 0, 0, 0, 0, 0, '29266 28559'), -- 54142 (Hired Courier) - Permanent Feign Death, Untrackable
(54146, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 54146 (Delian Sunshade)
(54170, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- 54170 (Delian Sunshade)

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuID`=6593 AND `TextID`=7812) OR (`MenuID`=6590 AND `TextID`=7806);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6593, 7812, 46366), -- 15354 (Rachelle Gothena)
(6590, 7806, 46366); -- 15354 (Rachelle Gothena)

DELETE FROM `gossip_menu_option` WHERE `MenuID`=6590 OR (`MenuID`=12949 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6590, 0, 1, 'What Hallow''s End candy do you have for sale?', 10815, 0, 0, 0, 0, 0, NULL, 0, 46366),
(6590, 1, 0, 'What is there to do on Hallow''s End?', 10816, 0, 6593, 0, 0, 0, NULL, 0, 46366),
(12949, 0, 0, 'Have you seen anyone suspicious trying to sell a crate of objects recently?', 52757, 0, 0, 0, 0, 0, NULL, 0, 46366);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12949;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,12949,0,0,0,47,0,29416,8,0,0,0,0,'','Show gossip option if quest 29416 is active');

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `Entry` IN (15354, 54141, 54142, 54146, 54170) AND `DifficultyID`=0;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(15354, 0, 0, 0, 425, 46366),
(54141, 0, 0, 0, 861, 46366),
(54142, 0, 0, 0, 861, 46366),
(54146, 0, 0, 0, 861, 46366),
(54170, 0, 0, 0, 861, 46366);

-- Vendor data
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=46366 WHERE (`entry`=15354 AND `item`=18633 AND `ExtendedCost`=0 AND `type`=1); -- Styleen's Sour Suckerpop
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=46366 WHERE (`entry`=15354 AND `item`=18632 AND `ExtendedCost`=0 AND `type`=1); -- Moonbrook Riot Taffy
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=46366 WHERE (`entry`=15354 AND `item`=7228 AND `ExtendedCost`=0 AND `type`=1); -- Tigule's Strawberry Ice Cream
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=46366 WHERE (`entry`=15354 AND `item`=18635 AND `ExtendedCost`=0 AND `type`=1); -- Bellara's Nutterbar
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=46366 WHERE (`entry`=15354 AND `item`=20557 AND `ExtendedCost`=0 AND `type`=1); -- Hallow's End Pumpkin Treat

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=15354;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23,15354,20557,0,0,47,0,8312,64,0,0,0,0,'','Item Hallow''s End Pumpkin Treat sold by Rachelle Gothena requires quest 8312 rewarded');

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=46366 WHERE `entry`=190069; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=190069; -- Candy Bucket

-- Quests
UPDATE `quest_poi` SET `VerifiedBuild`=46366 WHERE (`QuestID`=29428 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=29428 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29428 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=29428 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29427 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29427 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29427 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29431 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29431 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29431 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29426 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=29426 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=29426 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29426 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29426 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29425 AND `BlobIndex`=2 AND `Idx1`=4) OR (`QuestID`=29425 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=29425 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29425 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29425 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29415 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=29415 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29415 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29415 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=11357 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=11357 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=11357 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29400 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29416 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=29416 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29416 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29416 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=46366 WHERE (`QuestID`=29428 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29428 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29428 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29428 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29427 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29427 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29427 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29431 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29431 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29431 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29426 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=29426 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=29426 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29426 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29426 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29425 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=29425 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29425 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29425 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29425 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29415 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29415 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29415 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29415 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=11357 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=11357 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=11357 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29400 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29416 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=29416 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29416 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29416 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (11357, 29415, 29416, 29425, 29426, 29427, 29428);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11357, 1, 0, 0, 0, 0, 0, 0, 0, 46366), -- Masked Orphan Matron
(29415, 1, 1, 0, 0, 0, 0, 0, 0, 46366), -- Missing Heirlooms
(29416, 0, 0, 0, 0, 0, 0, 0, 0, 46366), -- Fencing the Goods
(29425, 1, 1, 0, 0, 0, 0, 0, 0, 46366), -- Shopping Around
(29426, 1, 1, 0, 0, 0, 0, 0, 0, 46366), -- Taking Precautions
(29427, 1, 1, 0, 0, 0, 0, 0, 0, 46366), -- The Collector's Agent
(29428, 1, 1, 0, 0, 0, 0, 0, 0, 46366); -- What Now?

UPDATE `quest_details` SET `VerifiedBuild`=46366 WHERE `ID`=29400;

DELETE FROM `quest_request_items` WHERE `ID` IN (29416, 29425, 29426, 29427, 29428);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29416, 0, 0, 0, 0, 'Why are you still pestering me?', 46366), -- Fencing the Goods
(29425, 0, 1, 0, 0, 'You look like you know something about these missing goods.', 46366), -- Shopping Around
(29426, 1, 1, 0, 0, 'Did you get all the ingredients?', 46366), -- Taking Precautions
(29427, 0, 1, 0, 0, 'This appears to be the sought-after crate.', 46366), -- The Collector's Agent
(29428, 1, 0, 0, 0, 'Have you brought the crate as we discussed?', 0); -- What Now?

DELETE FROM `quest_offer_reward` WHERE `ID` IN (29415, 29416, 29425, 29426, 29427, 29428, 29429, 29431);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29415, 0, 0, 0, 0, 0, 0, 0, 0, '<This courier won''t be meeting with his employer anytime soon and the crate he was hired to transport seems to have disappeared.>', 46366), -- Missing Heirlooms
(29416, 1, 0, 0, 0, 0, 0, 0, 0, 'Keep your voice down and don''t let word of this get out or I''m finished as an auctioneer!', 46366), -- Fencing the Goods
(29425, 1, 1, 0, 0, 0, 0, 0, 0, 'Leave it to Droffers to have a buyer lined up already. We should combine our efforts to track down this thief and keep the crate''s contents from falling into the wrong hands.', 46366), -- Shopping Around
(29426, 1, 1, 0, 0, 0, 0, 0, 0, 'Let''s see what I can remember from the alchemy lessons of my youth. If it explodes, I''ve done something wrong.$B$BThis concoction should protect us from the worst effects of carrying or handling the crate.', 46366), -- Taking Precautions
(29427, 1, 1, 0, 0, 0, 0, 0, 0, 'Tendrils of dark power dance around the crate, but there''s no trace of Sanath Lim-yo. You can now claim the crate and return it to your employer.', 46366), -- The Collector's Agent
(29428, 1, 1, 0, 0, 0, 0, 0, 0, 'I never thought you''d be able to recover it. Well, let''s see it.', 46366), -- What Now?
(29429, 0, 0, 0, 0, 0, 0, 0, 0, 'It''s been sought after, stolen, and sold. Anyone who tried to tap the magic held within has seen that power turn against him.$B$BYet, the crate itself appears unscathed and suffused with magical energy. From time to time, it shakes or bobs as if its contents were alive.$B$BIt seems to have an affinity for you and now, it''s yours.', 46366), -- The Creepy Crate
(29431, 0, 0, 0, 0, 0, 0, 0, 0, 'What do you want?$B$BCandace sent you? She knows me too well. I''ve hit a rut in my research and I''ve been waiting for a very important delivery, but the courier''s late...', 46366); -- A Friend in Need

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=12366;

DELETE FROM `creature_queststarter` WHERE (`quest`=29400 AND `id` IN (19176,19175,19177)) OR (`quest`=11357 AND `id` IN (19175,19176,19177,19178));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(19175, 11357, 46366), -- Masked Orphan Matron offered Orc Commoner
(19175, 29400, 46366), -- A Season for Celebration offered Orc Commoner
(19176, 11357, 46366), -- Masked Orphan Matron offered Tauren Commoner
(19176, 29400, 46366), -- A Season for Celebration offered Tauren Commoner
(19177, 11357, 46366), -- Masked Orphan Matron offered Troll Commoner
(19177, 29400, 46366), -- A Season for Celebration offered Troll Commoner
(19178, 11357, 46366); -- Masked Orphan Matron offered Forsaken Commoner

UPDATE `creature_queststarter` SET `VerifiedBuild`=46366 WHERE (`id`=44866 AND `quest`=29425) OR (`id`=54141 AND `quest`=29415) OR (`id`=54146 AND `quest`=29426) OR (`id`=54142 AND `quest`=29416);
UPDATE `creature_queststarter` SET `VerifiedBuild`=46366 WHERE (`id`=19178 AND `quest`=29400) OR (`id`=54146 AND `quest`=29427);

UPDATE `creature_questender` SET `VerifiedBuild`=46366 WHERE (`id`=54146 AND `quest` IN (29425,29426)) OR (`id`=44866 AND `quest`=29416) OR (`id`=54142 AND `quest`=29415);
UPDATE `creature_questender` SET `VerifiedBuild`=46366 WHERE (`id`=54141 AND `quest` IN (29431,29428));

DELETE FROM `game_event_creature_quest` WHERE (`quest`=29400 AND `id` IN (19176,19175,19177)) OR (`quest`=11357 AND `id` IN (19175,19176,19177,19178));

DELETE FROM `gameobject_queststarter` WHERE `id`=190069 AND `quest`=12366;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190069, 12366, 46366);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=46366 WHERE (`id`=209094 AND `quest`=29428);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=190069 AND `quest`=12366);
UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=209095 AND `quest`=29429) OR (`id`=209094 AND `quest`=29427);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=190069;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=11357;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,11357,0,0,12,0,12,0,0,0,0,0,'','Show quest 11357 only if event "Hallow''s End" is active');

-- Misc
DELETE FROM `spell_area` WHERE `spell` IN (100618, 100619, 100676) AND `area` IN (14, 85, 1637);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(100618, 14, 29416, 0, 0, 0, 2, 3, 10, 0),
(100618, 1637, 29416, 0, 0, 0, 2, 3, 10, 0),
(100619, 85, 29427, 0, 0, 0, 2, 3, 10, 0),
(100676, 1637, 29428, 0, 0, 0, 2, 3, 64, 0);

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (362088, 362089, 362090);
DELETE FROM `game_event_creature` WHERE `guid` IN (362088, 362089, 362090);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 15354, 1, 1637, 5170, '0', 0, 0, 0, 1, 1579.4097900390625, -4427.43212890625, 14.71822929382324218, 1.832595705986022949, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Rachelle Gothena (Area: Valley of Strength - Difficulty: 0)
(@CGUID+1, 40435, 1, 1637, 5170, '0', 0, 0, 0, 0, 1571.1510009765625, -4383.47412109375, 15.42013931274414062, 4.677482128143310546, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Headless Ghost (Area: Valley of Strength - Difficulty: 0)
(@CGUID+2, 53954, 1, 14, 374, '0', 0, 0, 0, 0, 1490.4149169921875, -4993.828125, 17.97515869140625, 5.201081275939941406, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Blood Spatter (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+3, 53954, 1, 14, 374, '0', 0, 0, 0, 0, 1490.1754150390625, -4994.5, 17.96721839904785156, 1.762782573699951171, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Blood Spatter (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+4, 53961, 1, 14, 374, '0', 0, 0, 0, 0, 1490.7916259765625, -4994.77783203125, 17.96333885192871093, 2.600540637969970703, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Blood Spatter (Small) (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+5, 53961, 1, 14, 374, '0', 0, 0, 0, 0, 1489.142333984375, -4992.70849609375, 17.970977783203125, 0, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Blood Spatter (Small) (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+6, 53961, 1, 14, 374, '0', 0, 0, 0, 0, 1491.6805419921875, -4994.88720703125, 17.96005630493164062, 2.58308720588684082, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Blood Spatter (Small) (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+7, 53961, 1, 14, 374, '0', 0, 0, 0, 0, 1491.5069580078125, -4992.10791015625, 17.96331024169921875, 4.799655437469482421, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Blood Spatter (Small) (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+8, 53961, 1, 14, 374, '0', 0, 0, 0, 0, 1492.295166015625, -4993.52978515625, 17.95682144165039062, 2.897246599197387695, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Blood Spatter (Small) (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+9, 53961, 1, 14, 374, '0', 0, 0, 0, 0, 1488.8316650390625, -4993.51904296875, 17.98196601867675781, 6.2657318115234375, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Blood Spatter (Small) (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+10, 53966, 1, 14, 374, '0', 0, 0, 0, 0, 1490.2291259765625, -4994.00341796875, 17.97301292419433593, 3.40339207649230957, 120, 0, 0, 1706, 852, 0, 0, 0, 0, 46366), -- Spider Summoner (Ship) (Area: Bladefist Bay - Difficulty: 0)
(@CGUID+11, 53977, 1, 1637, 5167, '0', 0, 0, 0, 1, 1846.2379150390625, -4390.21533203125, 135.316314697265625, 4.345870018005371093, 120, 0, 0, 93855, 0, 0, 0, 0, 0, 46366), -- Darkcaller Yanka (Area: The Drag - Difficulty: 0)
(@CGUID+12, 54141, 1, 1637, 5170, '0', 0, 0, 0, 1, 1586.8194580078125, -4452.77978515625, 16.13254737854003906, 4.101523876190185546, 120, 0, 0, 1706, 852, 0, 0, 0, 0, 46366), -- Edgar Goodwin (Area: Valley of Strength - Difficulty: 0)
(@CGUID+13, 54142, 1, 14, 374, '0', 0, 0, 0, 0, 1490.7899169921875, -4993.88916015625, 17.97194290161132812, 3.857177734375, 120, 0, 0, 1706, 100, 0, 0, 0, 0, 46366), -- Hired Courier (Area: Bladefist Bay - Difficulty: 0) (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+14, 54146, 1, 1637, 5167, '0', 0, 0, 0, 1, 1925.4114990234375, -4515.8662109375, 29.36326217651367187, 6.161012172698974609, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366), -- Delian Sunshade (Area: The Drag - Difficulty: 0) (Auras: )
(@CGUID+15, 54170, 1, 1637, 5168, '0', 0, 0, 0, 1, 1909.3663330078125, -4754.77978515625, 39.00757598876953125, 1.710422635078430175, 120, 0, 0, 1706, 0, 0, 0, 0, 0, 46366); -- Delian Sunshade (Area: Valley of Honor - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 226662 AND 226794;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 227014 AND 227181;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 226662 AND 226794;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 227014 AND 227181;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+247;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 14, 4982, '0', 0, 0, 1389.326416015625, -4359.14404296875, 28.47490119934082031, 5.837917327880859375, 0, 0, -0.22079944610595703, 0.975319266319274902, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+1, 180405, 1, 14, 4982, '0', 0, 0, 1379.9288330078125, -4383.6162109375, 26.08010482788085937, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+2, 180405, 1, 14, 4982, '0', 0, 0, 1425.501708984375, -4422.5068359375, 25.45359230041503906, 2.323845148086547851, 0, 0, 0.917569160461425781, 0.39757615327835083, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+3, 180405, 1, 14, 4982, '0', 0, 0, 1428.732666015625, -4433.45166015625, 28.45888328552246093, 2.924592494964599609, 0, 0, 0.994119644165039062, 0.108287304639816284, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+4, 180405, 1, 14, 4982, '0', 0, 0, 1423.6632080078125, -4378.8525390625, 25.45464515686035156, 2.402120113372802734, 0, 0, 0.932422637939453125, 0.361369609832763671, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+5, 180405, 1, 14, 4982, '0', 0, 0, 1440.4132080078125, -4361.580078125, 25.45360374450683593, 4.820049285888671875, 0, 0, -0.66803741455078125, 0.74412769079208374, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+6, 180405, 1, 14, 4982, '0', 0, 0, 1442.279541015625, -4410.34716796875, 25.45358657836914062, 5.805665493011474609, 0, 0, -0.23649787902832031, 0.971632003784179687, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+7, 180405, 1, 1637, 5170, '0', 0, 0, 1581.27783203125, -4428.5693359375, 14.59989261627197265, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+8, 180405, 1, 1637, 5170, '0', 0, 0, 1617.217041015625, -4418.80908203125, 15.80371284484863281, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+9, 180405, 1, 1637, 5170, '0', 0, 0, 1633.6475830078125, -4270.99658203125, 43.11837387084960937, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+10, 180405, 1, 1637, 5170, '0', 0, 0, 1796.9114990234375, -4374.9150390625, 113.287139892578125, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+11, 180405, 1, 1637, 5167, '0', 0, 0, 1900.638916015625, -4383.7275390625, 44.02114105224609375, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Drag - Difficulty: 0)
(@OGUID+12, 180405, 1, 1637, 5170, '0', 0, 0, 1586.4097900390625, -4172.5400390625, 51.87001800537109375, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+13, 180405, 1, 1637, 5169, '0', 0, 0, 1738.109375, -4090.616455078125, 67.67290496826171875, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+14, 180406, 1, 14, 4982, '0', 0, 0, 1428.361083984375, -4424.6025390625, 25.45359039306640625, 2.09415292739868164, 0, 0, 0.865964889526367187, 0.500104784965515136, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+15, 180406, 1, 14, 4982, '0', 0, 0, 1437.5572509765625, -4354.6494140625, 28.47406387329101562, 6.110514163970947265, 0, 0, -0.0862283706665039, 0.99627542495727539, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+16, 180406, 1, 14, 4982, '0', 0, 0, 1438.5364990234375, -4364.2119140625, 25.45360374450683593, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+17, 180406, 1, 1637, 5170, '0', 0, 0, 1569.314208984375, -4382.39404296875, 16.33877372741699218, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+18, 180406, 1, 1637, 5170, '0', 0, 0, 1650.4461669921875, -4385.16650390625, 29.56776618957519531, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+19, 180406, 1, 1637, 5170, '0', 0, 0, 1669.9166259765625, -4354.21533203125, 66.84239959716796875, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+20, 180406, 1, 1637, 5170, '0', 0, 0, 1691.3350830078125, -4285.22412109375, 29.56179428100585937, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+21, 180406, 1, 1637, 5170, '0', 0, 0, 1738.609375, -4397.70166015625, 36.50065994262695312, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+22, 180406, 1, 1637, 5168, '0', 0, 0, 1902.484375, -4686.77587890625, 38.49742507934570312, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+23, 180406, 1, 1637, 5167, '0', 0, 0, 1844.234375, -4389.1337890625, 135.2330169677734375, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: The Drag - Difficulty: 0)
(@OGUID+24, 180406, 1, 1637, 5171, '0', 0, 0, 1951.560791015625, -4209.1962890625, 37.22783279418945312, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+25, 180406, 1, 1637, 5170, '0', 0, 0, 1554.5504150390625, -4186.7900390625, 61.35681915283203125, 1.077515482902526855, 0, 0, 0.513070106506347656, 0.85834670066833496, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+26, 180406, 1, 1637, 5170, '0', 0, 0, 1567.5399169921875, -4176.921875, 61.35681915283203125, 1.077515482902526855, 0, 0, 0.513070106506347656, 0.85834670066833496, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+27, 180406, 1, 1637, 5169, '0', 0, 0, 1738.7708740234375, -4067.595458984375, 48.32478713989257812, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+28, 180407, 1, 14, 4982, '0', 0, 0, 1391.8819580078125, -4378.830078125, 28.47291374206542968, 4.645381450653076171, 0, 0, -0.73039627075195312, 0.683023631572723388, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+29, 180407, 1, 14, 4982, '0', 0, 0, 1426.0260009765625, -4427.07275390625, 25.45359230041503906, 1.678660511970520019, 0, 0, 0.744195938110351562, 0.667961359024047851, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+30, 180407, 1, 14, 4982, '0', 0, 0, 1440.5972900390625, -4366.46728515625, 25.45360755920410156, 5.692983627319335937, 0, 0, -0.29083633422851562, 0.956772804260253906, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+31, 180407, 1, 14, 4982, '0', 0, 0, 1444.3941650390625, -4434.111328125, 28.64427757263183593, 4.184699535369873046, 0, 0, -0.86704635620117187, 0.498227506875991821, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+32, 180407, 1, 1637, 0, '0', 0, 0, 1543.55908203125, -4363.61279296875, 20.54503059387207031, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+33, 180407, 1, 1637, 5170, '0', 0, 0, 1574.2742919921875, -4431.283203125, 16.05218887329101562, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+34, 180407, 1, 1637, 5170, '0', 0, 0, 1660.1180419921875, -4336.4599609375, 66.91455841064453125, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+35, 180407, 1, 1637, 5170, '0', 0, 0, 1646.09033203125, -4268.73779296875, 43.217315673828125, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+36, 180407, 1, 1637, 5170, '0', 0, 0, 1747.3211669921875, -4411.61962890625, 36.97034835815429687, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+37, 180407, 1, 1637, 5168, '0', 0, 0, 1913.2257080078125, -4656.91845703125, 33.67508697509765625, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+38, 180407, 1, 1637, 5168, '0', 0, 0, 2033.576416015625, -4672.53125, 31.29389381408691406, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+39, 180407, 1, 1637, 5167, '0', 0, 0, 1893.861083984375, -4364.76416015625, 43.3546142578125, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: The Drag - Difficulty: 0)
(@OGUID+40, 180407, 1, 1637, 5171, '0', 0, 0, 1916.810791015625, -4227.06591796875, 37.10743331909179687, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+41, 180408, 1, 1637, 5170, '0', 0, 0, 1617.173583984375, -4418.87841796875, 17.42322731018066406, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 46366), -- G_WitchHat_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+42, 180408, 1, 1637, 5170, '0', 0, 0, 1633.6822509765625, -4270.984375, 44.76167678833007812, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 46366), -- G_WitchHat_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+43, 180410, 1, 1637, 1637, '0', 0, 0, 1504.62158203125, -4423.64404296875, 24.44908714294433593, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Orgrimmar - Difficulty: 0)
(@OGUID+44, 180410, 1, 1637, 5170, '0', 0, 0, 1602.248291015625, -4372.01220703125, 22.63382148742675781, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+45, 180410, 1, 1637, 5170, '0', 0, 0, 1556.0260009765625, -4179.5244140625, 60.60253143310546875, 5.343693733215332031, 0, 0, -0.45265960693359375, 0.891683399677276611, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+46, 180411, 1, 1637, 5170, '0', 0, 0, 1663.1041259765625, -4340.111328125, 67.769805908203125, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+47, 180411, 1, 1637, 5169, '0', 0, 0, 1713.888916015625, -4079.501708984375, 52.72540283203125, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+48, 180411, 1, 1637, 5169, '0', 0, 0, 1741.3646240234375, -4076.0556640625, 55.94753265380859375, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+49, 180414, 1, 14, 4982, '0', 0, 0, 1375.796875, -4357.2744140625, 26.2229156494140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Cauldron (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+50, 180414, 1, 1637, 11386, '0', 0, 0, 1528.498291015625, -4430.861328125, 21.34195518493652343, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 46366), -- Cauldron (Area: Pathfinder's Den - Difficulty: 0)
(@OGUID+51, 180414, 1, 1637, 5168, '0', 0, 0, 1927.2083740234375, -4729.45654296875, 35.96033859252929687, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 46366), -- Cauldron (Area: Valley of Honor - Difficulty: 0)
(@OGUID+52, 180414, 1, 1637, 5171, '0', 0, 0, 1915.4271240234375, -4268.111328125, 28.04427146911621093, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 46366), -- Cauldron (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+53, 180415, 1, 14, 4982, '0', 0, 0, 1386.9757080078125, -4360.40478515625, 28.40284156799316406, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+54, 180415, 1, 14, 4982, '0', 0, 0, 1394.8853759765625, -4377.54150390625, 28.40526390075683593, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+55, 180415, 1, 14, 4982, '0', 0, 0, 1413.1978759765625, -4375.033203125, 28.440887451171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+56, 180415, 1, 14, 4982, '0', 0, 0, 1402.03125, -4358.34912109375, 28.43107986450195312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+57, 180415, 1, 14, 4982, '0', 0, 0, 1379.795166015625, -4385.2119140625, 26.03386116027832031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+58, 180415, 1, 14, 4982, '0', 0, 0, 1398.3472900390625, -4376.59228515625, 28.43567657470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+59, 180415, 1, 14, 4982, '0', 0, 0, 1396.53125, -4358.90625, 28.43825721740722656, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+60, 180415, 1, 14, 4982, '0', 0, 0, 1392.8177490234375, -4359.68408203125, 28.40653800964355468, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+61, 180415, 1, 14, 4982, '0', 0, 0, 1388.9930419921875, -4378.29150390625, 28.40913963317871093, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+62, 180415, 1, 14, 4982, '0', 0, 0, 1411.204833984375, -4357.2900390625, 28.42864418029785156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+63, 180415, 1, 14, 4982, '0', 0, 0, 1403.9410400390625, -4375.9462890625, 28.43322181701660156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+64, 180415, 1, 14, 4982, '0', 0, 0, 1407.4600830078125, -4375.470703125, 28.4271240234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+65, 180415, 1, 14, 4982, '0', 0, 0, 1405.5555419921875, -4357.90087890625, 28.43321418762207031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+66, 180415, 1, 14, 4982, '0', 0, 0, 1423.7413330078125, -4389.48291015625, 28.42467308044433593, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+67, 180415, 1, 14, 4982, '0', 0, 0, 1425.6007080078125, -4405.30029296875, 28.42828559875488281, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+68, 180415, 1, 14, 4982, '0', 0, 0, 1425.0086669921875, -4431.30224609375, 28.69840431213378906, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+69, 180415, 1, 14, 4982, '0', 0, 0, 1426.1614990234375, -4409.62158203125, 28.42130279541015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+70, 180415, 1, 14, 4982, '0', 0, 0, 1427.1458740234375, -4418.02099609375, 28.41885566711425781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+71, 180415, 1, 14, 4982, '0', 0, 0, 1425.1163330078125, -4402.33837890625, 28.43309974670410156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+72, 180415, 1, 14, 4982, '0', 0, 0, 1422.717041015625, -4380.564453125, 28.42901992797851562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+73, 180415, 1, 14, 4982, '0', 0, 0, 1424.220458984375, -4395.392578125, 28.43674087524414062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+74, 180415, 1, 14, 4982, '0', 0, 0, 1426.2535400390625, -4412.267578125, 28.43393707275390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+75, 180415, 1, 14, 4982, '0', 0, 0, 1428.7413330078125, -4430.83154296875, 28.42680549621582031, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+76, 180415, 1, 14, 4982, '0', 0, 0, 1423.34033203125, -4386.58837890625, 28.43054771423339843, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+77, 180415, 1, 14, 4982, '0', 0, 0, 1416.951416015625, -4357.734375, 28.43033599853515625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+78, 180415, 1, 14, 4982, '0', 0, 0, 1424.8177490234375, -4398.40966796875, 28.420074462890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+79, 180415, 1, 14, 4982, '0', 0, 0, 1422.4166259765625, -4357.109375, 28.4282989501953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+80, 180415, 1, 14, 4982, '0', 0, 0, 1441.060791015625, -4356.955078125, 28.69366073608398437, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+81, 180415, 1, 14, 4982, '0', 0, 0, 1439.107666015625, -4370.3212890625, 28.42203140258789062, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+82, 180415, 1, 14, 4982, '0', 0, 0, 1434.78125, -4351.95166015625, 28.69450569152832031, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+83, 180415, 1, 14, 4982, '0', 0, 0, 1437.564208984375, -4357.4375, 28.43483543395996093, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+84, 180415, 1, 14, 4982, '0', 0, 0, 1435.1910400390625, -4355.62841796875, 28.42593002319335937, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+85, 180415, 1, 14, 4982, '0', 0, 0, 1442.2100830078125, -4396.4130859375, 28.43013954162597656, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+86, 180415, 1, 14, 4982, '0', 0, 0, 1443.015625, -4403.361328125, 28.42104911804199218, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+87, 180415, 1, 14, 4982, '0', 0, 0, 1440.795166015625, -4384.6787109375, 28.42342758178710937, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+88, 180415, 1, 14, 4982, '0', 0, 0, 1441.9271240234375, -4393.35595703125, 28.43030548095703125, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+89, 180415, 1, 14, 4982, '0', 0, 0, 1442.486083984375, -4400.4599609375, 28.41904067993164062, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+90, 180415, 1, 14, 4982, '0', 0, 0, 1440.111083984375, -4378.6474609375, 28.42704200744628906, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+91, 180415, 1, 14, 4982, '0', 0, 0, 1443.59375, -4407.51904296875, 28.42640113830566406, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+92, 180415, 1, 14, 4982, '0', 0, 0, 1439.82470703125, -4376.28662109375, 28.39522743225097656, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+93, 180415, 1, 14, 4982, '0', 0, 0, 1441.1353759765625, -4387.57470703125, 28.42292976379394531, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+94, 180415, 1, 14, 4982, '0', 0, 0, 1431.170166015625, -4432.689453125, 28.42757225036621093, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+95, 180415, 1, 14, 4982, '0', 0, 0, 1455.8629150390625, -4412.15087890625, 28.42436408996582031, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+96, 180415, 1, 14, 4982, '0', 0, 0, 1459.0086669921875, -4411.62353515625, 28.42484474182128906, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+97, 180415, 1, 14, 4982, '0', 0, 0, 1431.295166015625, -4436.328125, 28.69287490844726562, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+98, 180415, 1, 14, 4982, '0', 0, 0, 1443.5538330078125, -4431.18212890625, 28.42453193664550781, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+99, 180415, 1, 14, 4982, '0', 0, 0, 1450.0989990234375, -4412.70166015625, 28.42978668212890625, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+100, 180415, 1, 14, 4982, '0', 0, 0, 1449.2691650390625, -4430.5556640625, 28.42853927612304687, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+101, 180415, 1, 14, 4982, '0', 0, 0, 1467.875, -4410.59033203125, 28.42914009094238281, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+102, 180415, 1, 14, 4982, '0', 0, 0, 1457.890625, -4429.484375, 28.42616462707519531, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+103, 180415, 1, 14, 4982, '0', 0, 0, 1464.935791015625, -4411.04345703125, 28.41997718811035156, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+104, 180415, 1, 14, 4982, '0', 0, 0, 1452.1180419921875, -4430.2099609375, 28.42877006530761718, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+105, 180415, 1, 14, 4982, '0', 0, 0, 1466.87158203125, -4428.3125, 28.41889381408691406, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+106, 180415, 1, 14, 4982, '0', 0, 0, 1460.8853759765625, -4429.23291015625, 28.43379402160644531, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+107, 180415, 1, 14, 4982, '0', 0, 0, 1469.8333740234375, -4428.1962890625, 28.43605995178222656, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- CandleBlack01 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+108, 180415, 1, 1637, 0, '0', 0, 0, 1566.35595703125, -4434.8818359375, 16.05219459533691406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+109, 180415, 1, 1637, 0, '0', 0, 0, 1566.02783203125, -4432.80029296875, 16.05218887329101562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+110, 180415, 1, 1637, 0, '0', 0, 0, 1567.314208984375, -4431.830078125, 16.05218887329101562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+111, 180415, 1, 1637, 5170, '0', 0, 0, 1607.4757080078125, -4381.53125, 22.75407791137695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+112, 180415, 1, 1637, 5168, '0', 0, 0, 1909.3385009765625, -4679.59716796875, 37.34681320190429687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+113, 180415, 1, 1637, 5168, '0', 0, 0, 1924.74658203125, -4728.65478515625, 38.93230056762695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+114, 180415, 1, 1637, 5168, '0', 0, 0, 1924.3194580078125, -4730.21533203125, 38.93230056762695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+115, 180415, 1, 1637, 5168, '0', 0, 0, 1923.4322509765625, -4726.13525390625, 38.18877029418945312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+116, 180415, 1, 1637, 5168, '0', 0, 0, 1920.55908203125, -4722.66162109375, 37.00212478637695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+117, 180415, 1, 1637, 5168, '0', 0, 0, 1923.8819580078125, -4727.35791015625, 38.93230056762695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+118, 180415, 1, 1637, 5168, '0', 0, 0, 1919.9722900390625, -4723.892578125, 38.18405914306640625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+119, 180415, 1, 1637, 5168, '0', 0, 0, 1918.7274169921875, -4723.86474609375, 38.93230056762695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+120, 180415, 1, 1637, 5168, '0', 0, 0, 1924.3021240234375, -4725.16845703125, 37.03638458251953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+121, 180415, 1, 1637, 5168, '0', 0, 0, 1916.8367919921875, -4723.52099609375, 38.93230056762695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+122, 180415, 1, 1637, 5168, '0', 0, 0, 1915.6927490234375, -4724.439453125, 38.93230056762695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+123, 180415, 1, 1637, 5168, '0', 0, 0, 1914.857666015625, -4725.66650390625, 38.93306350708007812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+124, 180415, 1, 1637, 5168, '0', 0, 0, 1923.5069580078125, -4731.4599609375, 38.93230056762695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+125, 180415, 1, 1637, 5171, '0', 0, 0, 1947.9757080078125, -4196.203125, 38.68569183349609375, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- CandleBlack01 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+126, 180425, 1, 1637, 5170, '0', 0, 0, 1607.62158203125, -4424.6650390625, 15.69160747528076171, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+127, 180425, 1, 1637, 5170, '0', 0, 0, 1607.111083984375, -4381.970703125, 22.8822784423828125, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+128, 180425, 1, 1637, 5168, '0', 0, 0, 1909.767333984375, -4678.87841796875, 37.38814544677734375, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+129, 180425, 1, 1637, 5171, '0', 0, 0, 1951.5677490234375, -4207, 38.43329620361328125, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+130, 180425, 1, 1637, 5171, '0', 0, 0, 1921.5399169921875, -4190.751953125, 39.008636474609375, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+131, 180425, 1, 1637, 5169, '0', 0, 0, 1729.9600830078125, -4086.244873046875, 69.57158660888671875, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+132, 180425, 1, 1637, 5169, '0', 0, 0, 1736.8975830078125, -4071.239501953125, 52.20943832397460937, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+133, 180425, 1, 1637, 5169, '0', 0, 0, 1730.2708740234375, -4073.850830078125, 52.13470840454101562, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+134, 180425, 1, 1637, 5169, '0', 0, 0, 1728.5538330078125, -4074.229248046875, 52.35164260864257812, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+135, 180425, 1, 1637, 5169, '0', 0, 0, 1735.34375, -4072.104248046875, 52.14954376220703125, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 120, 255, 1, 46366), -- SkullCandle01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+136, 180426, 1, 1637, 1637, '0', 0, 0, 1505.0867919921875, -4412.1943359375, 23.02982711791992187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Orgrimmar - Difficulty: 0)
(@OGUID+137, 180426, 1, 1637, 1637, '0', 0, 0, 1531.8941650390625, -4404.44775390625, 18.61635971069335937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Orgrimmar - Difficulty: 0)
(@OGUID+138, 180426, 1, 1637, 0, '0', 0, 0, 1558.93408203125, -4378.9599609375, 16.82652473449707031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: 0 - Difficulty: 0)
(@OGUID+139, 180426, 1, 1637, 5170, '0', 0, 0, 1601.5260009765625, -4393.298828125, 18.25049209594726562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+140, 180426, 1, 1637, 5168, '0', 0, 0, 1940.0260009765625, -4686.595703125, 34.80312728881835937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+141, 180426, 1, 1637, 5168, '0', 0, 0, 1936.4132080078125, -4694.87158203125, 35.81434249877929687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+142, 180426, 1, 1637, 5168, '0', 0, 0, 2003.8350830078125, -4716.60791015625, 29.55341529846191406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+143, 180426, 1, 1637, 5171, '0', 0, 0, 1929.079833984375, -4211.923828125, 36.91974639892578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+144, 180426, 1, 1637, 5171, '0', 0, 0, 1923.9166259765625, -4204.44775390625, 37.07407760620117187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+145, 180426, 1, 1637, 5332, '0', 0, 0, 1673.41845703125, -4104.7587890625, 49.44149017333984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Orgrimmar Embassy - Difficulty: 0)
(@OGUID+146, 180426, 1, 1637, 5169, '0', 0, 0, 1695.91845703125, -4093.2587890625, 48.7188873291015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+147, 180427, 1, 1637, 1637, '0', 0, 0, 1521.0711669921875, -4407.26220703125, 20.69618034362792968, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Orgrimmar - Difficulty: 0)
(@OGUID+148, 180427, 1, 1637, 0, '0', 0, 0, 1547.984375, -4404.80224609375, 18.03235054016113281, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+149, 180427, 1, 1637, 0, '0', 0, 0, 1554.138916015625, -4398.75537109375, 17.34508705139160156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: 0 - Difficulty: 0)
(@OGUID+150, 180427, 1, 1637, 5170, '0', 0, 0, 1579.3228759765625, -4407.54345703125, 15.39577198028564453, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+151, 180427, 1, 1637, 5168, '0', 0, 0, 1975.3941650390625, -4667.13525390625, 32.64345932006835937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+152, 180427, 1, 1637, 5168, '0', 0, 0, 1932.810791015625, -4677.939453125, 34.15896224975585937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+153, 180427, 1, 1637, 5168, '0', 0, 0, 1951.0416259765625, -4703.890625, 36.62605667114257812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+154, 180427, 1, 1637, 5171, '0', 0, 0, 1935.71875, -4207.173828125, 36.81645965576171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+155, 180427, 1, 1637, 5171, '0', 0, 0, 1931.329833984375, -4212.51025390625, 36.81130599975585937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+156, 180427, 1, 1637, 5332, '0', 0, 0, 1668.1822509765625, -4107.126953125, 49.95176315307617187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Orgrimmar Embassy - Difficulty: 0)
(@OGUID+157, 180427, 1, 1637, 5169, '0', 0, 0, 1688.5382080078125, -4097.59716796875, 48.68080520629882812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+158, 180428, 1, 1637, 5168, '0', 0, 0, 1947.05908203125, -4689.1943359375, 34.84970855712890625, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 46366), -- G_WitchBroom_01 scale 0.5 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+159, 180428, 1, 1637, 5171, '0', 0, 0, 1916.71533203125, -4267.2099609375, 28.059722900390625, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 46366), -- G_WitchBroom_01 scale 0.5 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+160, 180429, 1, 14, 4982, '0', 0, 0, 1377.060791015625, -4359.28662109375, 28.19597053527832031, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 46366), -- G_WitchHat_01 scale 0.5 (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+161, 180429, 1, 1637, 11386, '0', 0, 0, 1531.5052490234375, -4431.3037109375, 24.00904464721679687, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 46366), -- G_WitchHat_01 scale 0.5 (Area: Pathfinder's Den - Difficulty: 0)
(@OGUID+162, 180429, 1, 1637, 0, '0', 0, 0, 1541.2396240234375, -4373.58154296875, 20.82736396789550781, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 46366), -- G_WitchHat_01 scale 0.5 (Area: 0 - Difficulty: 0)
(@OGUID+163, 180429, 1, 1637, 5168, '0', 0, 0, 1947.611083984375, -4690.00341796875, 38.209747314453125, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 46366), -- G_WitchHat_01 scale 0.5 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+164, 180429, 1, 1637, 5168, '0', 0, 0, 1926.60595703125, -4725.486328125, 38.03469467163085937, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 46366), -- G_WitchHat_01 scale 0.5 (Area: Valley of Honor - Difficulty: 0)
(@OGUID+165, 180429, 1, 1637, 5171, '0', 0, 0, 1916.02783203125, -4266.68408203125, 31.50795555114746093, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 46366), -- G_WitchHat_01 scale 0.5 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+166, 180471, 1, 1637, 0, '0', 0, 0, 1544.673583984375, -4364.1474609375, 25.90085983276367187, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+167, 180471, 1, 1637, 0, '0', 0, 0, 1543.0833740234375, -4363.40283203125, 25.2636260986328125, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+168, 180471, 1, 1637, 5170, '0', 0, 0, 1668.736083984375, -4349.60400390625, 72.24118804931640625, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+169, 180471, 1, 1637, 5170, '0', 0, 0, 1667.8489990234375, -4344.970703125, 72.67189788818359375, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+170, 180471, 1, 1637, 5170, '0', 0, 0, 1668.1024169921875, -4346.3369140625, 70.945098876953125, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+171, 180471, 1, 1637, 5170, '0', 0, 0, 1668.1024169921875, -4346.3369140625, 72.56539154052734375, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+172, 180471, 1, 1637, 5170, '0', 0, 0, 1668.421875, -4347.8125, 72.4328765869140625, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+173, 180471, 1, 1637, 5170, '0', 0, 0, 1668.736083984375, -4349.60400390625, 70.58026885986328125, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+174, 180471, 1, 1637, 5170, '0', 0, 0, 1745.8541259765625, -4387.611328125, 49.78556060791015625, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+175, 180471, 1, 1637, 5170, '0', 0, 0, 1751.3836669921875, -4387.4306640625, 49.16284561157226562, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+176, 180471, 1, 1637, 5170, '0', 0, 0, 1758.9879150390625, -4405.9755859375, 49.10680007934570312, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+177, 180471, 1, 1637, 5170, '0', 0, 0, 1747.9791259765625, -4389.87353515625, 49.16279983520507812, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+178, 180471, 1, 1637, 5170, '0', 0, 0, 1750.1822509765625, -4384.54150390625, 49.82933807373046875, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+179, 180471, 1, 1637, 5170, '0', 0, 0, 1762.4739990234375, -4403.71728515625, 49.22351455688476562, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+180, 180471, 1, 1637, 5170, '0', 0, 0, 1760.0504150390625, -4408.859375, 49.94426345825195312, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+181, 180471, 1, 1637, 5170, '0', 0, 0, 1764.6180419921875, -4405.84375, 49.95634078979492187, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+182, 180471, 1, 1637, 5170, '0', 0, 0, 1794.9913330078125, -4367.93212890625, 105.7371597290039062, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+183, 180471, 1, 1637, 5170, '0', 0, 0, 1794.9913330078125, -4367.93212890625, 107.3436965942382812, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+184, 180471, 1, 1637, 5170, '0', 0, 0, 1695.546875, -4273.37158203125, 41.33503341674804687, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+185, 180471, 1, 1637, 5170, '0', 0, 0, 1697.10595703125, -4278.37841796875, 41.92198562622070312, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+186, 180471, 1, 1637, 5170, '0', 0, 0, 1693.27783203125, -4275.0068359375, 41.87329483032226562, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+187, 180471, 1, 1637, 5170, '0', 0, 0, 1698.4410400390625, -4275.9619140625, 41.29448318481445312, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+188, 180471, 1, 1637, 5167, '0', 0, 0, 1907.30908203125, -4385.01416015625, 51.5375518798828125, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Drag - Difficulty: 0)
(@OGUID+189, 180471, 1, 1637, 5167, '0', 0, 0, 1906.032958984375, -4382.3037109375, 50.82398605346679687, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Drag - Difficulty: 0)
(@OGUID+190, 180471, 1, 1637, 5167, '0', 0, 0, 1902.0399169921875, -4383.02978515625, 50.812652587890625, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Drag - Difficulty: 0)
(@OGUID+191, 180471, 1, 1637, 5167, '0', 0, 0, 1902.0347900390625, -4386.22900390625, 51.63542556762695312, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Drag - Difficulty: 0)
(@OGUID+192, 180471, 1, 1637, 5167, '0', 0, 0, 1902.0538330078125, -4363.251953125, 50.88455581665039062, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Drag - Difficulty: 0)
(@OGUID+193, 180471, 1, 1637, 5167, '0', 0, 0, 1898.05908203125, -4363.94775390625, 50.86245346069335937, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Drag - Difficulty: 0)
(@OGUID+194, 180471, 1, 1637, 5167, '0', 0, 0, 1896.9478759765625, -4361.17529296875, 51.551727294921875, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Drag - Difficulty: 0)
(@OGUID+195, 180471, 1, 1637, 5167, '0', 0, 0, 1902.203125, -4360.15087890625, 51.56628799438476562, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Drag - Difficulty: 0)
(@OGUID+196, 180472, 1, 1637, 0, '0', 0, 0, 1539.279541015625, -4369.12353515625, 26.56698036193847656, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+197, 180472, 1, 1637, 0, '0', 0, 0, 1567.4444580078125, -4434.1787109375, 22.03560829162597656, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+198, 180472, 1, 1637, 5170, '0', 0, 0, 1632.9617919921875, -4384.90283203125, 24.71734619140625, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+199, 180472, 1, 1637, 5170, '0', 0, 0, 1747.0347900390625, -4384.8056640625, 51.74789810180664062, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+200, 180472, 1, 1637, 5170, '0', 0, 0, 1763.12158203125, -4408.6474609375, 51.71094894409179687, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+201, 180472, 1, 1637, 5170, '0', 0, 0, 1803.4375, -4373.29345703125, 108.9540481567382812, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+202, 180472, 1, 1637, 5170, '0', 0, 0, 1694.201416015625, -4277.7412109375, 43.76607131958007812, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Valley of Strength - Difficulty: 0)
(@OGUID+203, 180472, 1, 1637, 5167, '0', 0, 0, 1904.9635009765625, -4387.27783203125, 53.43541336059570312, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: The Drag - Difficulty: 0)
(@OGUID+204, 180472, 1, 1637, 5167, '0', 0, 0, 1899.1875, -4358.98291015625, 53.44948196411132812, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: The Drag - Difficulty: 0)
(@OGUID+205, 180472, 1, 1637, 5171, '0', 0, 0, 1916.2552490234375, -4229.7099609375, 41.88074874877929687, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+206, 180472, 1, 1637, 5169, '0', 0, 0, 1736.49658203125, -4072.453125, 74.11026763916015625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+207, 180472, 1, 1637, 5169, '0', 0, 0, 1747.53125, -4083.279541015625, 74.3189697265625, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+208, 180523, 1, 1637, 5170, '0', 0, 0, 1578.1041259765625, -4441.9619140625, 16.49898338317871093, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 46366), -- Apple Bob (Area: Valley of Strength - Difficulty: 0)
(@OGUID+209, 190069, 1, 1637, 5170, '0', 0, 0, 1571.3055419921875, -4444.27099609375, 16.056488037109375, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 46366), -- Candy Bucket (Area: Valley of Strength - Difficulty: 0)
(@OGUID+210, 207736, 1, 1637, 5170, '0', 0, 0, 1611.1492919921875, -4428.23291015625, 19.80772590637207031, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Scale 2) (Area: Valley of Strength - Difficulty: 0)
(@OGUID+211, 207736, 1, 1637, 5168, '0', 0, 0, 2039.704833984375, -4682.30224609375, 35.147552490234375, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Scale 2) (Area: Valley of Honor - Difficulty: 0)
(@OGUID+212, 207941, 1, 1637, 1637, '0', 0, 0, 1564.607666015625, -4315.2119140625, 32.04160308837890625, 0.79205322265625, 0, 0, 0.385755538940429687, 0.922601044178009033, 120, 255, 1, 46366), -- G_WitchHat_01 scale 2.0 (Area: Orgrimmar - Difficulty: 0)
(@OGUID+213, 209034, 1, 14, 374, '0', 0, 0, 1490.1805419921875, -4994.19970703125, 18.16426467895507812, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 46366), -- Courier Sword (Area: Bladefist Bay - Difficulty: 0)
(@OGUID+214, 209059, 1, 1637, 5167, '0', 0, 0, 1887.2257080078125, -4360.34716796875, 40.67633438110351562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: The Drag - Difficulty: 0)
(@OGUID+215, 209059, 1, 1637, 5167, '0', 0, 0, 1890.095458984375, -4325.81591796875, 24.14210891723632812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: The Drag - Difficulty: 0)
(@OGUID+216, 209059, 1, 1637, 5167, '0', 0, 0, 1914.8333740234375, -4306.66162109375, 23.958160400390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: The Drag - Difficulty: 0)
(@OGUID+217, 209059, 1, 1637, 5167, '0', 0, 0, 1930.7117919921875, -4302.25, 24.21709632873535156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: The Drag - Difficulty: 0)
(@OGUID+218, 209059, 1, 1637, 5167, '0', 0, 0, 1920.935791015625, -4264.23291015625, 28.54404449462890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: The Drag - Difficulty: 0)
(@OGUID+219, 209059, 1, 1637, 5171, '0', 0, 0, 1885.3975830078125, -4276.56787109375, 23.93655967712402343, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+220, 209059, 1, 1637, 5171, '0', 0, 0, 1886.767333984375, -4282.765625, 23.64585113525390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+221, 209059, 1, 1637, 5171, '0', 0, 0, 1865.5103759765625, -4313.80029296875, 24.59487533569335937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+222, 209059, 1, 1637, 5171, '0', 0, 0, 1902.576416015625, -4293.2275390625, 23.98159980773925781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+223, 209059, 1, 1637, 5171, '0', 0, 0, 1948.3021240234375, -4254.517578125, 30.517669677734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+224, 209059, 1, 1637, 5171, '0', 0, 0, 1922.2725830078125, -4261.7412109375, 29.00823593139648437, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+225, 209059, 1, 1637, 5171, '0', 0, 0, 1866.515625, -4306.70166015625, 24.32075119018554687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+226, 209059, 1, 1637, 5171, '0', 0, 0, 1930.04345703125, -4250.86279296875, 31.91396522521972656, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+227, 209059, 1, 1637, 5171, '0', 0, 0, 1925.10595703125, -4239.07275390625, 36.82718658447265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+228, 209059, 1, 1637, 5171, '0', 0, 0, 1930.486083984375, -4252.09716796875, 31.34583473205566406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+229, 209059, 1, 1637, 5171, '0', 0, 0, 1922.0867919921875, -4245.13525390625, 37.05918121337890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+230, 209059, 1, 1637, 5171, '0', 0, 0, 1981.3021240234375, -4262.01025390625, 32.28223037719726562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+231, 209059, 1, 1637, 5171, '0', 0, 0, 1872.625, -4272.001953125, 24.82702064514160156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+232, 209059, 1, 1637, 5171, '0', 0, 0, 1870.3836669921875, -4262.953125, 35.76189804077148437, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+233, 209059, 1, 1637, 5171, '0', 0, 0, 1894.4896240234375, -4231.251953125, 36.98680496215820312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+234, 209059, 1, 1637, 5171, '0', 0, 0, 1909.74658203125, -4233.5380859375, 37.06491851806640625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+235, 209059, 1, 1637, 5171, '0', 0, 0, 1960.3021240234375, -4232.830078125, 37.01038742065429687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+236, 209059, 1, 1637, 5171, '0', 0, 0, 1845.342041015625, -4258.96875, 42.1986083984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+237, 209059, 1, 1637, 5171, '0', 0, 0, 1909.0572509765625, -4220.08154296875, 37.02049636840820312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+238, 209059, 1, 1637, 5171, '0', 0, 0, 1883.1754150390625, -4233.9150390625, 35.97293853759765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+239, 209059, 1, 1637, 5171, '0', 0, 0, 1918.467041015625, -4207.9287109375, 37.31186676025390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+240, 209059, 1, 1637, 5171, '0', 0, 0, 1959.5364990234375, -4208.95849609375, 37.28026199340820312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+241, 209059, 1, 1637, 5171, '0', 0, 0, 1961.60595703125, -4193.2119140625, 36.9796295166015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+242, 209059, 1, 1637, 5171, '0', 0, 0, 1887.77783203125, -4192.0537109375, 37.0442657470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+243, 209059, 1, 1637, 5171, '0', 0, 0, 1934.78125, -4161.6005859375, 36.97964859008789062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+244, 209059, 1, 1637, 5171, '0', 0, 0, 1950.6510009765625, -4164.3125, 37.20854568481445312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+245, 209059, 1, 1637, 5171, '0', 0, 0, 1910.1285400390625, -4165.9912109375, 36.97964859008789062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Blood Nettle (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+246, 209095, 1, 1637, 8618, '0', 0, 0, 1587.3004150390625, -4453.8837890625, 16.04824638366699218, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 46366), -- Edgar's Crate (Area: The Broken Tusk - Difficulty: 0)
(@OGUID+247, 209095, 1, 1637, 5168, '0', 0, 0, 1908.1632080078125, -4754.3681640625, 38.91977691650390625, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 46366); -- Edgar's Crate (Area: Valley of Honor - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` IN (@OGUID+246, @OGUID+247);
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+246, 0, 0, 0, 1, 16, 1500, 0, 0), -- Edgar's Crate
(@OGUID+247, 0, 0, 0, 1, 16, 1500, 0, 0); -- Edgar's Crate

-- Orc/Troll/Tauren Commoner spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN 850376 AND 850387;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, 850376),
(12, 850377),
(12, 850378),
(12, 850379),
(12, 850380),
(12, 850381),
(12, 850382),
(12, 850383),
(12, 850384),
(12, 850385),
(12, 850386),
(12, 850387);

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0),
(12, @CGUID+1),
(12, @CGUID+2),
(12, @CGUID+3),
(12, @CGUID+4),
(12, @CGUID+5),
(12, @CGUID+6),
(12, @CGUID+7),
(12, @CGUID+8),
(12, @CGUID+9),
(12, @CGUID+10),
(12, @CGUID+11),
(12, @CGUID+12),
(12, @CGUID+13),
(12, @CGUID+14),
(12, @CGUID+15);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+247;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12),
(12, @OGUID+13),
(12, @OGUID+14),
(12, @OGUID+15),
(12, @OGUID+16),
(12, @OGUID+17),
(12, @OGUID+18),
(12, @OGUID+19),
(12, @OGUID+20),
(12, @OGUID+21),
(12, @OGUID+22),
(12, @OGUID+23),
(12, @OGUID+24),
(12, @OGUID+25),
(12, @OGUID+26),
(12, @OGUID+27),
(12, @OGUID+28),
(12, @OGUID+29),
(12, @OGUID+30),
(12, @OGUID+31),
(12, @OGUID+32),
(12, @OGUID+33),
(12, @OGUID+34),
(12, @OGUID+35),
(12, @OGUID+36),
(12, @OGUID+37),
(12, @OGUID+38),
(12, @OGUID+39),
(12, @OGUID+40),
(12, @OGUID+41),
(12, @OGUID+42),
(12, @OGUID+43),
(12, @OGUID+44),
(12, @OGUID+45),
(12, @OGUID+46),
(12, @OGUID+47),
(12, @OGUID+48),
(12, @OGUID+49),
(12, @OGUID+50),
(12, @OGUID+51),
(12, @OGUID+52),
(12, @OGUID+53),
(12, @OGUID+54),
(12, @OGUID+55),
(12, @OGUID+56),
(12, @OGUID+57),
(12, @OGUID+58),
(12, @OGUID+59),
(12, @OGUID+60),
(12, @OGUID+61),
(12, @OGUID+62),
(12, @OGUID+63),
(12, @OGUID+64),
(12, @OGUID+65),
(12, @OGUID+66),
(12, @OGUID+67),
(12, @OGUID+68),
(12, @OGUID+69),
(12, @OGUID+70),
(12, @OGUID+71),
(12, @OGUID+72),
(12, @OGUID+73),
(12, @OGUID+74),
(12, @OGUID+75),
(12, @OGUID+76),
(12, @OGUID+77),
(12, @OGUID+78),
(12, @OGUID+79),
(12, @OGUID+80),
(12, @OGUID+81),
(12, @OGUID+82),
(12, @OGUID+83),
(12, @OGUID+84),
(12, @OGUID+85),
(12, @OGUID+86),
(12, @OGUID+87),
(12, @OGUID+88),
(12, @OGUID+89),
(12, @OGUID+90),
(12, @OGUID+91),
(12, @OGUID+92),
(12, @OGUID+93),
(12, @OGUID+94),
(12, @OGUID+95),
(12, @OGUID+96),
(12, @OGUID+97),
(12, @OGUID+98),
(12, @OGUID+99),
(12, @OGUID+100),
(12, @OGUID+101),
(12, @OGUID+102),
(12, @OGUID+103),
(12, @OGUID+104),
(12, @OGUID+105),
(12, @OGUID+106),
(12, @OGUID+107),
(12, @OGUID+108),
(12, @OGUID+109),
(12, @OGUID+110),
(12, @OGUID+111),
(12, @OGUID+112),
(12, @OGUID+113),
(12, @OGUID+114),
(12, @OGUID+115),
(12, @OGUID+116),
(12, @OGUID+117),
(12, @OGUID+118),
(12, @OGUID+119),
(12, @OGUID+120),
(12, @OGUID+121),
(12, @OGUID+122),
(12, @OGUID+123),
(12, @OGUID+124),
(12, @OGUID+125),
(12, @OGUID+126),
(12, @OGUID+127),
(12, @OGUID+128),
(12, @OGUID+129),
(12, @OGUID+130),
(12, @OGUID+131),
(12, @OGUID+132),
(12, @OGUID+133),
(12, @OGUID+134),
(12, @OGUID+135),
(12, @OGUID+136),
(12, @OGUID+137),
(12, @OGUID+138),
(12, @OGUID+139),
(12, @OGUID+140),
(12, @OGUID+141),
(12, @OGUID+142),
(12, @OGUID+143),
(12, @OGUID+144),
(12, @OGUID+145),
(12, @OGUID+146),
(12, @OGUID+147),
(12, @OGUID+148),
(12, @OGUID+149),
(12, @OGUID+150),
(12, @OGUID+151),
(12, @OGUID+152),
(12, @OGUID+153),
(12, @OGUID+154),
(12, @OGUID+155),
(12, @OGUID+156),
(12, @OGUID+157),
(12, @OGUID+158),
(12, @OGUID+159),
(12, @OGUID+160),
(12, @OGUID+161),
(12, @OGUID+162),
(12, @OGUID+163),
(12, @OGUID+164),
(12, @OGUID+165),
(12, @OGUID+166),
(12, @OGUID+167),
(12, @OGUID+168),
(12, @OGUID+169),
(12, @OGUID+170),
(12, @OGUID+171),
(12, @OGUID+172),
(12, @OGUID+173),
(12, @OGUID+174),
(12, @OGUID+175),
(12, @OGUID+176),
(12, @OGUID+177),
(12, @OGUID+178),
(12, @OGUID+179),
(12, @OGUID+180),
(12, @OGUID+181),
(12, @OGUID+182),
(12, @OGUID+183),
(12, @OGUID+184),
(12, @OGUID+185),
(12, @OGUID+186),
(12, @OGUID+187),
(12, @OGUID+188),
(12, @OGUID+189),
(12, @OGUID+190),
(12, @OGUID+191),
(12, @OGUID+192),
(12, @OGUID+193),
(12, @OGUID+194),
(12, @OGUID+195),
(12, @OGUID+196),
(12, @OGUID+197),
(12, @OGUID+198),
(12, @OGUID+199),
(12, @OGUID+200),
(12, @OGUID+201),
(12, @OGUID+202),
(12, @OGUID+203),
(12, @OGUID+204),
(12, @OGUID+205),
(12, @OGUID+206),
(12, @OGUID+207),
(12, @OGUID+208),
(12, @OGUID+209),
(12, @OGUID+210),
(12, @OGUID+211),
(12, @OGUID+212),
(12, @OGUID+213),
(12, @OGUID+214),
(12, @OGUID+215),
(12, @OGUID+216),
(12, @OGUID+217),
(12, @OGUID+218),
(12, @OGUID+219),
(12, @OGUID+220),
(12, @OGUID+221),
(12, @OGUID+222),
(12, @OGUID+223),
(12, @OGUID+224),
(12, @OGUID+225),
(12, @OGUID+226),
(12, @OGUID+227),
(12, @OGUID+228),
(12, @OGUID+229),
(12, @OGUID+230),
(12, @OGUID+231),
(12, @OGUID+232),
(12, @OGUID+233),
(12, @OGUID+234),
(12, @OGUID+235),
(12, @OGUID+236),
(12, @OGUID+237),
(12, @OGUID+238),
(12, @OGUID+239),
(12, @OGUID+240),
(12, @OGUID+241),
(12, @OGUID+242),
(12, @OGUID+243),
(12, @OGUID+244),
(12, @OGUID+245),
(12, @OGUID+246),
(12, @OGUID+247);
