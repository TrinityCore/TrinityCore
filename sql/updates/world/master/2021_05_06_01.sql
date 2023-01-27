DELETE FROM `gameobject_template_addon` WHERE `entry` IN (309705 /*Doodad_7NE_Blackrook_Portcullis009*/, 309704 /*Alliance Door*/, 352710 /*Horde Gate*/, 352709 /*Horde Gate*/, 309883 /*Doodad_7NE_Blackrook_Portcullis002*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(309705, 1375, 32, 0, 0), -- Doodad_7NE_Blackrook_Portcullis009
(309704, 1375, 32, 0, 0), -- Alliance Door
(352710, 1375, 32, 0, 0), -- Horde Gate
(352709, 1375, 32, 0, 0), -- Horde Gate
(309883, 1375, 32, 0, 0); -- Doodad_7NE_Blackrook_Portcullis002


UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212082; -- Diamond Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212083; -- Troll Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212080; -- Waterfall Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212081; -- Lava Depot
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=212942; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=212940; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=212941; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=212939; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=214987; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213700; -- Banner
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213705; -- Banner
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=214233; -- Guild Vault
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=214231; -- Guild Vault
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213678; -- Banner
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=211114; -- Meat 06
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=211115; -- Meat 07
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=211113; -- Meat 04
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=211220; -- Mailbox
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=211327; -- Fire Shield Collision Wall
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=211312; -- Explosives Barrel
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=211328; -- Wall of Fire

DELETE FROM `quest_offer_reward` WHERE `ID` IN (31511 /*-Unknown-*/, 30656 /*-Unknown-*/, 30661 /*-Unknown-*/, 30655 /*-Unknown-*/, 30657 /*-Unknown-*/, 30620 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(31511, 396, 0, 0, 0, 0, 0, 0, 0, 'Welcome to the Shrine of Two Moons, traveler.$B$BI know that the Celestials sent you here to help us, but first, take a moment to rest and explore the city.$B$BWelcome to the Vale.', 38134), -- -Unknown-
(30656, 4, 0, 0, 0, 0, 0, 0, 0, 'You can\'t tell me that wasn\'t fun, $n! I knew I should have gone over there with you!', 38134), -- -Unknown-
(30661, 4, 0, 0, 0, 0, 0, 0, 0, 'Once again you\'ve accomplished what no one else could.$B$BWas there any doubt?', 38134), -- -Unknown-
(30655, 2, 0, 0, 0, 0, 0, 0, 0, 'Well, it looks like we\'ve got ourselves a little army, here, thanks to you.\n\nThey may not look like much yet, but a little Horde discipline and we\'ll have them in fighting shape in no time.\n\nBy the way, $n... good work.', 38134), -- -Unknown-
(30657, 0, 0, 0, 0, 0, 0, 0, 0, '<The Ordo lieutenants are dead. The shield is down.>$B$B<Time to take out the Ordo leader!>', 38134), -- -Unknown-
(30620, 6, 0, 0, 0, 0, 0, 0, 0, 'Oh, thank goodness! You\'ve saved all of our skins, believe me.\n\nYou have no idea how much trouble those guys can stir up.\n\nErr, or, I guess you do, now. Kind of. Almost.\n\nImagine that, but a lot worse, and for a couple thousand years.', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=31459 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(31459, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 4, 32, 0, 0, 870, 379, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 3, 2, 254053, 60099, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 2, 1, 254052, 60098, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 1, 0, 254051, 60096, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

DELETE FROM `quest_poi_points` WHERE (`QuestID`=31459 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(31459, 0, 0, 3044, 1251, 655, 38134), -- -Unknown-
(30656, 4, 0, 2280, 901, 482, 38134), -- -Unknown-
(30656, 3, 0, 2217, 1844, 494, 38134), -- -Unknown-
(30656, 2, 0, 2237, 1732, 492, 38134), -- -Unknown-
(30656, 1, 0, 2306, 1651, 508, 38134), -- -Unknown-
(30656, 0, 0, 2285, 910, 482, 38134); -- -Unknown-

DELETE FROM `quest_greeting` WHERE (`ID`=59442 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(59442, 0, 0, 0, '', 38134); -- 59442

DELETE FROM `quest_details` WHERE `ID` IN (32249 /*-Unknown-*/, 31377 /*-Unknown-*/, 31459 /*-Unknown-*/, 31453 /*-Unknown-*/, 31695 /*-Unknown-*/, 31451 /*-Unknown-*/, 31457 /*-Unknown-*/, 30661 /*-Unknown-*/, 30657 /*-Unknown-*/, 30656 /*-Unknown-*/, 30655 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(32249, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31377, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31459, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31453, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31695, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31451, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31457, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30661, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30657, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 5, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30655, 1, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (115230,115267));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(115230, 0, 870, 1701.949951171875, 1371.43994140625, 455.7550048828125, 38134), -- Spell: 115230 (Summon Refugee) Efffect: 28 (SPELL_EFFECT_SUMMON)
(115267, 0, 870, 1696.280029296875, 1371.1700439453125, 453.787994384765625, 38134); -- Spell: 115267 (Summon Refugee) Efffect: 28 (SPELL_EFFECT_SUMMON)

UPDATE `spell_target_position` SET `PositionX`=-11.109999656677246, `PositionY`=6746.18994140625, `VerifiedBuild`=38134 WHERE (`ID`=296901 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=1445.2099609375, `PositionY`=-4499.56005859375, `PositionZ`=18.30999946594238281, `VerifiedBuild`=38134 WHERE (`ID`=3567 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (62672 /*62672 (Harrison Jones) - Ride Vehicle Hardcoded, Read Scroll*/, 60378 /*60378 (Mine Cart)*/, 60140 /*60140 (Mine Cart) - Control Visual (Neutral)*/, 60380 /*60380 (Mine Cart)*/, 62671 /*62671 (BANANAS) - Ride Vehicle Hardcoded, Hold Barrel*/, 60379 /*60379 (Mine Cart)*/, 60145 /*60145 (Points Trigger)*/, 60283 /*60283 (Track Switch)*/, 66239 /*66239 (Aimee Morningbreeze)*/, 66234 /*66234 (Mitsua)*/, 66231 /*66231 (Sona Morningbreeze)*/, 66232 /*66232 (Puya)*/, 66233 /*66233 (Pio)*/, 66225 /*66225 (Cook Tsu)*/, 66980 /*66980 (Grower Miao)*/, 66981 /*66981 (Trapper Ri)*/, 66979 /*66979 (Stonebreaker Ruian)*/, 66227 /*66227 (Wing Hya)*/, 64585 /*64585*/, 63966 /*63966 (Vaultkeeper Shifen)*/, 63838 /*63838 (Gilded Moth)*/, 63964 /*63964 (Vaultkeeper Kan)*/, 63965 /*63965 (Vaultkeeper Goldpenny)*/, 64057 /*64057 (Moko Powderrun)*/, 64056 /*64056 (Hafuna Landwalker)*/, 64048 /*64048 (Sheena Sunweaver)*/, 63752 /*63752 (Wounded Defender)*/, 64127 /*64127 (Frances Lin)*/, 64128 /*64128 (Edward Hanes)*/, 58245 /*58245 (Nala)*/, 64566 /*64566 (Sunwalker Dezco)*/, 63542 /*63542 (Elder Tsulan)*/, 63770 /*63770 (Alliance Yak)*/, 62882 /*62882 (Kai the Restless) - Generic Quest Invisibility 16*/, 59450 /*59450 - Generic Quest Invisibility 16*/, 61744 /*61744 (Tabo the Flyer) - Generic Quest Invisibility 16*/, 63754 /*63754 (Farmhand Bo)*/, 59451 /*59451 - Generic Quest Invisibility 16*/, 60131 /*60131 (Spirit Worg) - Ghost Visual*/, 60550 /*60550 (Wild Spike Sprite)*/, 60511 /*60511*/, 60099 /*60099 (Western Oil Rig)*/, 50332 /*50332 (Korda Torros) - Dual Wield*/, 147662 /*147662 (Owl)*/, 61750 /*61750 (Deer)*/, 147695 /*147695 (Forest Moth)*/, 147694 /*147694 (Rabbit)*/, 147693 /*147693 (Coral Snake)*/, 60127 /*60127 (Ordo Warbringer) - Fire Channeling*/, 60032 /*60032 (Akonu the Embercaller) - In Tents Channeling: Jilvici Fire Channel*/, 60098 /*60098 (Southern Oil Rig)*/, 65773 /*65773 (Ordo Yak)*/, 65774 /*65774 (Ordo Yak Calf)*/, 60031 /*60031 (Pao-kun the Pyromancer) - In Tents Channeling: Jilvici Fire Channel*/, 60038 /*60038 (Pandaren Prisoner) - Cosmetic - Ball & Chain*/, 60096 /*60096 (Eastern Oil Rig)*/, 60030 /*60030 (Harala the Firespeaker) - In Tents Channeling: Jilvici Fire Channel*/, 59968 /*59968 (Ordo Marauder)*/, 59969 /*59969 (Musaan the Blazecaster) - In Tents Channeling: Jilvici Fire Channel*/, 59970 /*59970 (Ordo Battleyak)*/, 67175 /*67175 (Steelbender Jin)*/, 59441 /*59441 - Generic Quest Invisibility 16*/, 59972 /*59972 (Ordo Warrior)*/, 63820 /*63820 (Alliance Trainee)*/, 65440 /*65440*/, 50354 /*50354 - Stone Form*/, 61490 /*61490*/, 61488 /*61488*/, 61489 /*61489*/, 59790 /*59790*/, 60859 /*60859 - Permanent Feign Death*/, 60242 /*60242*/, 59593 /*59593 - Grummle Threat Nuke Aura*/, 58415 /*58415*/, 59443 /*59443*/, 59526 /*59526 - Grummle Threat Nuke Aura, Terrified Grummle*/, 59527 /*59527 - Grummle Threat Nuke Aura, Terrified Grummle*/, 60860 /*60860*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(62672, 0, 0, 0, 1, 0, 0, 0, 0, '46598 122236'), -- 62672 (Harrison Jones) - Ride Vehicle Hardcoded, Read Scroll
(60378, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 60378 (Mine Cart)
(60140, 0, 0, 0, 1, 0, 0, 0, 0, '118001'), -- 60140 (Mine Cart) - Control Visual (Neutral)
(60380, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 60380 (Mine Cart)
(62671, 0, 0, 0, 1, 0, 0, 0, 0, '46598 122297'), -- 62671 (BANANAS) - Ride Vehicle Hardcoded, Hold Barrel
(60379, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 60379 (Mine Cart)
(60145, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60145 (Points Trigger)
(60283, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60283 (Track Switch)
(66239, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66239 (Aimee Morningbreeze)
(66234, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66234 (Mitsua)
(66231, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66231 (Sona Morningbreeze)
(66232, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66232 (Puya)
(66233, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66233 (Pio)
(66225, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66225 (Cook Tsu)
(66980, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66980 (Grower Miao)
(66981, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66981 (Trapper Ri)
(66979, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66979 (Stonebreaker Ruian)
(66227, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66227 (Wing Hya)
(64585, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64585
(63966, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 63966 (Vaultkeeper Shifen)
(63838, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 63838 (Gilded Moth)
(63964, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 63964 (Vaultkeeper Kan)
(63965, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 63965 (Vaultkeeper Goldpenny)
(64057, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64057 (Moko Powderrun)
(64056, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64056 (Hafuna Landwalker)
(64048, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64048 (Sheena Sunweaver)
(63752, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 63752 (Wounded Defender)
(64127, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64127 (Frances Lin)
(64128, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64128 (Edward Hanes)
(58245, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 58245 (Nala)
(64566, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 64566 (Sunwalker Dezco)
(63542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63542 (Elder Tsulan)
(63770, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63770 (Alliance Yak)
(62882, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 62882 (Kai the Restless) - Generic Quest Invisibility 16
(59450, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 59450 - Generic Quest Invisibility 16
(61744, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 61744 (Tabo the Flyer) - Generic Quest Invisibility 16
(63754, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63754 (Farmhand Bo)
(59451, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 59451 - Generic Quest Invisibility 16
(60131, 0, 0, 0, 1, 0, 0, 0, 0, '22650'), -- 60131 (Spirit Worg) - Ghost Visual
(60550, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60550 (Wild Spike Sprite)
(60511, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60511
(60099, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60099 (Western Oil Rig)
(50332, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 50332 (Korda Torros) - Dual Wield
(147662, 0, 0, 50331648, 1, 0, 835, 0, 0, ''), -- 147662 (Owl)
(61750, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61750 (Deer)
(147695, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 147695 (Forest Moth)
(147694, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147694 (Rabbit)
(147693, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147693 (Coral Snake)
(60127, 0, 0, 0, 1, 0, 0, 0, 0, '78192'), -- 60127 (Ordo Warbringer) - Fire Channeling
(60032, 0, 0, 0, 1, 0, 0, 0, 0, '128430'), -- 60032 (Akonu the Embercaller) - In Tents Channeling: Jilvici Fire Channel
(60098, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60098 (Southern Oil Rig)
(65773, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65773 (Ordo Yak)
(65774, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65774 (Ordo Yak Calf)
(60031, 0, 0, 0, 1, 0, 0, 0, 0, '128430'), -- 60031 (Pao-kun the Pyromancer) - In Tents Channeling: Jilvici Fire Channel
(60038, 0, 0, 0, 1, 0, 0, 0, 0, '115533'), -- 60038 (Pandaren Prisoner) - Cosmetic - Ball & Chain
(60096, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60096 (Eastern Oil Rig)
(60030, 0, 0, 0, 1, 0, 0, 0, 0, '128430'), -- 60030 (Harala the Firespeaker) - In Tents Channeling: Jilvici Fire Channel
(59968, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59968 (Ordo Marauder)
(59969, 0, 0, 0, 1, 0, 0, 0, 0, '128430'), -- 59969 (Musaan the Blazecaster) - In Tents Channeling: Jilvici Fire Channel
(59970, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59970 (Ordo Battleyak)
(67175, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67175 (Steelbender Jin)
(59441, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 59441 - Generic Quest Invisibility 16
(59972, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59972 (Ordo Warrior)
(63820, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63820 (Alliance Trainee)
(65440, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 65440
(50354, 0, 0, 0, 1, 0, 0, 0, 0, '130227'), -- 50354 - Stone Form
(61490, 0, 0, 0, 1, 0, 2238, 0, 0, ''), -- 61490
(61488, 0, 0, 0, 1, 0, 2238, 0, 0, ''), -- 61488
(61489, 0, 0, 0, 1, 0, 2238, 0, 0, ''), -- 61489
(59790, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59790
(60859, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 60859 - Permanent Feign Death
(60242, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60242
(59593, 0, 0, 0, 1, 0, 0, 0, 0, '116029'), -- 59593 - Grummle Threat Nuke Aura
(58415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 58415
(59443, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59443
(59526, 0, 0, 0, 1, 0, 0, 0, 0, '116029 125239'), -- 59526 - Grummle Threat Nuke Aura, Terrified Grummle
(59527, 0, 0, 0, 1, 0, 0, 0, 0, '116029 125239'), -- 59527 - Grummle Threat Nuke Aura, Terrified Grummle
(60860, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 60860

UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=982, `VerifiedBuild`=38134 WHERE (`Entry`=13116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=982, `VerifiedBuild`=38134 WHERE (`Entry`=13117 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=62672 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60378 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60140 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=62671 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60145 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60283 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66239 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66234 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66231 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66232 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66233 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66980 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66981 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66979 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=881, `VerifiedBuild`=38134 WHERE (`Entry`=66227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64585 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=63966 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63838 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=63964 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=63965 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64057 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64056 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=63752 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=15, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=59, `VerifiedBuild`=38134 WHERE (`Entry`=58245 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=63542 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=63770 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=62882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59450 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=881, `VerifiedBuild`=38134 WHERE (`Entry`=61744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=63754 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59451 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=6491 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60511 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60099 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=50332 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=972, `VerifiedBuild`=38134 WHERE (`Entry`=147662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=972, `VerifiedBuild`=38134 WHERE (`Entry`=147695 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=972, `VerifiedBuild`=38134 WHERE (`Entry`=147694 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=972, `VerifiedBuild`=38134 WHERE (`Entry`=147693 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=24288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=65773 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=65774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60038 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60096 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59968 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59969 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59970 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=67175 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59441 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59972 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=63820 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=31047 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=65440 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=50354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=61490 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=61488 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=61489 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59790 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60859 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60491 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59593 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=58415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59443 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59526 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59527 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60860 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=13337;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=13339;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42619;
UPDATE `creature_model_info` SET `BoundingRadius`=2.670626640319824218, `VerifiedBuild`=38134 WHERE `DisplayID`=40935;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41243;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42102;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44895;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44890;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44887;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44888;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44889;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44880;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45525;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45526;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45524;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44883;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44358;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43369;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43366;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43368;
UPDATE `creature_model_info` SET `BoundingRadius`=1.780417680740356445, `VerifiedBuild`=38134 WHERE `DisplayID`=41789;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=44365;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=42491;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42489;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44369;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45537;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=40294;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40006;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44053;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44068;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43108;
UPDATE `creature_model_info` SET `BoundingRadius`=0.312499791383743286, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=42766;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=38872;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=42223;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43207;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=38870;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43235;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5233;
UPDATE `creature_model_info` SET `BoundingRadius`=0.485495239496231079, `CombatReach`=1.770408153533935546, `VerifiedBuild`=38134 WHERE `DisplayID`=41000;
UPDATE `creature_model_info` SET `BoundingRadius`=0.685569643974304199, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=40021;
UPDATE `creature_model_info` SET `BoundingRadius`=0.611119985580444335, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=44163;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40353;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36952;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36957;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=328;
UPDATE `creature_model_info` SET `BoundingRadius`=2.062988519668579101, `VerifiedBuild`=38134 WHERE `DisplayID`=64331;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=347;
UPDATE `creature_model_info` SET `BoundingRadius`=0.052500002086162567, `CombatReach`=0.150000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=36944;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36580;
UPDATE `creature_model_info` SET `BoundingRadius`=0.611119985580444335, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=41236;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534729957580566406, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=41201;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40354;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381949990987777709, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44526;
UPDATE `creature_model_info` SET `BoundingRadius`=0.708163261413574218, `CombatReach`=1.062244892120361328, `VerifiedBuild`=38134 WHERE `DisplayID`=44596;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381949990987777709, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44527;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534729957580566406, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=41203;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41520;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41519;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534729957580566406, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=41202;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381949990987777709, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44529;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534729957580566406, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=41200;
UPDATE `creature_model_info` SET `BoundingRadius`=0.458339989185333251, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44523;
UPDATE `creature_model_info` SET `BoundingRadius`=0.458339989185333251, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44524;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=42171;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45971;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43237;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43236;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45964;
UPDATE `creature_model_info` SET `BoundingRadius`=0.458339989185333251, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44525;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43238;
UPDATE `creature_model_info` SET `BoundingRadius`=2.375433683395385742, `CombatReach`=3.75, `VerifiedBuild`=38134 WHERE `DisplayID`=44349;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41781;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41785;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41784;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381949990987777709, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=41116;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41114;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41672;
UPDATE `creature_model_info` SET `BoundingRadius`=0.754126608371734619, `VerifiedBuild`=38134 WHERE `DisplayID`=40025;
UPDATE `creature_model_info` SET `BoundingRadius`=0.754126608371734619, `VerifiedBuild`=38134 WHERE `DisplayID`=45162;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=41674;
UPDATE `creature_model_info` SET `BoundingRadius`=1.068250656127929687, `CombatReach`=1.320000052452087402, `VerifiedBuild`=38134 WHERE `DisplayID`=40995;
UPDATE `creature_model_info` SET `BoundingRadius`=1.60000002384185791, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=41673;
UPDATE `creature_model_info` SET `BoundingRadius`=1.068250656127929687, `CombatReach`=1.320000052452087402, `VerifiedBuild`=38134 WHERE `DisplayID`=41016;
UPDATE `creature_model_info` SET `BoundingRadius`=0.819706082344055175, `VerifiedBuild`=38134 WHERE `DisplayID`=40843;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=40664;


UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=554;
UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=554;
UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=554;


UPDATE `trainer_spell` SET `MoneyCost`=1000, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `ReqLevel`=40, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=34092);
UPDATE `trainer_spell` SET `MoneyCost`=1000, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `ReqLevel`=40, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=34092);
UPDATE `trainer_spell` SET `MoneyCost`=1000, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `ReqLevel`=40, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=34092);

DELETE FROM `npc_vendor` WHERE (`entry`=64001 AND `item`=89304 AND `ExtendedCost`=5846 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(64001, 2, 89304, 0, 5846, 1, 0, 0, 38134); -- Reins of the Thundering August Cloud Serpent

UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Setting
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=60335 AND `ExtendedCost`=0 AND `type`=1); -- Thick Hide Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81400 AND `ExtendedCost`=0 AND `type`=1); -- Pounded Rice Cake
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=58274 AND `ExtendedCost`=0 AND `type`=1); -- Fresh Water
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=74636 AND `ExtendedCost`=0 AND `type`=1); -- Golden Carp Consomme
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81414 AND `ExtendedCost`=0 AND `type`=1); -- Pearl Milk Tea
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81406 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Barley Tea
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81409 AND `ExtendedCost`=0 AND `type`=1); -- Tangy Yogurt
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81401 AND `ExtendedCost`=0 AND `type`=1); -- Yak Cheese Curds
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81415 AND `ExtendedCost`=0 AND `type`=1); -- Pandaren Plum Wine
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81407 AND `ExtendedCost`=0 AND `type`=1); -- Four Wind Soju
UPDATE `npc_vendor` SET `slot`=48, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=84559 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Bracer - Super Intellect
UPDATE `npc_vendor` SET `slot`=47, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=84557 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Bracer - Greater Agility
UPDATE `npc_vendor` SET `slot`=46, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=84561 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Bracer - Exceptional Strength
UPDATE `npc_vendor` SET `slot`=45, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88882 AND `ExtendedCost`=0 AND `type`=1); -- Tiger-Striped Wristguards
UPDATE `npc_vendor` SET `slot`=44, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88881 AND `ExtendedCost`=0 AND `type`=1); -- Fallen Sentinel Bracers
UPDATE `npc_vendor` SET `slot`=43, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88880 AND `ExtendedCost`=0 AND `type`=1); -- Battle Shadow Bracers
UPDATE `npc_vendor` SET `slot`=42, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88879 AND `ExtendedCost`=0 AND `type`=1); -- Braided Black and White Bracer
UPDATE `npc_vendor` SET `slot`=41, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88893 AND `ExtendedCost`=0 AND `type`=1); -- Minh's Beaten Bracers
UPDATE `npc_vendor` SET `slot`=40, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88892 AND `ExtendedCost`=0 AND `type`=1); -- Bracers of Inlaid Jade
UPDATE `npc_vendor` SET `slot`=39, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88885 AND `ExtendedCost`=0 AND `type`=1); -- Clever Ashyo's Armbands
UPDATE `npc_vendor` SET `slot`=38, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88884 AND `ExtendedCost`=0 AND `type`=1); -- Quillpaw Family Bracers
UPDATE `npc_vendor` SET `slot`=37, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88883 AND `ExtendedCost`=0 AND `type`=1); -- Brewmaster Chani's Bracers
UPDATE `npc_vendor` SET `slot`=36, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88749 AND `ExtendedCost`=0 AND `type`=1); -- Gauntlets of Jade Sutras
UPDATE `npc_vendor` SET `slot`=35, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88748 AND `ExtendedCost`=0 AND `type`=1); -- Ravenmane's Gloves
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88747 AND `ExtendedCost`=0 AND `type`=1); -- Streetfighter's Iron Knuckles
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88746 AND `ExtendedCost`=0 AND `type`=1); -- Gloves of the Overwhelming Swarm
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88745 AND `ExtendedCost`=0 AND `type`=1); -- Sentinel Commander's Gauntlets
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88744 AND `ExtendedCost`=0 AND `type`=1); -- Fingers of the Loneliest Monk
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88743 AND `ExtendedCost`=0 AND `type`=1); -- Ogo's Elder Gloves
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88742 AND `ExtendedCost`=0 AND `type`=1); -- Sunspeaker's Flared Gloves
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88741 AND `ExtendedCost`=0 AND `type`=1); -- Gloves of Red Feathers
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88878 AND `ExtendedCost`=0 AND `type`=1); -- Void Flame Slippers
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88877 AND `ExtendedCost`=0 AND `type`=1); -- Storm-Sing Sandals
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88876 AND `ExtendedCost`=0 AND `type`=1); -- Boots of the High Adept
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88868 AND `ExtendedCost`=0 AND `type`=1); -- Tukka-Tuk's Hairy Boots
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88867 AND `ExtendedCost`=0 AND `type`=1); -- Sandals of the Elder Sage
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88866 AND `ExtendedCost`=0 AND `type`=1); -- Steps of the War Serpent
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88865 AND `ExtendedCost`=0 AND `type`=1); -- Bramblestaff Boots
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88864 AND `ExtendedCost`=0 AND `type`=1); -- Yu'lon Guardian Boots
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88862 AND `ExtendedCost`=0 AND `type`=1); -- Tankiss Warstompers
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89659 AND `ExtendedCost`=0 AND `type`=1); -- Leggings of Unfinished Conquest
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89658 AND `ExtendedCost`=0 AND `type`=1); -- Subversive Leggings
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89665 AND `ExtendedCost`=0 AND `type`=1); -- Leggings of Ponderous Advance
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89664 AND `ExtendedCost`=0 AND `type`=1); -- Valiant's Shinguards
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89537 AND `ExtendedCost`=0 AND `type`=1); -- Cloak of the Silent Mountain
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89535 AND `ExtendedCost`=0 AND `type`=1); -- Ribcracker's Cloak
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89534 AND `ExtendedCost`=0 AND `type`=1); -- Pressed Flower Cloak
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89533 AND `ExtendedCost`=0 AND `type`=1); -- Cloak of Ancient Curses
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89532 AND `ExtendedCost`=0 AND `type`=1); -- Bladesong Cloak
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89669 AND `ExtendedCost`=0 AND `type`=1); -- Undergrowth Stalker Chestpiece
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89668 AND `ExtendedCost`=0 AND `type`=1); -- Mountain Stream Ringmail
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89667 AND `ExtendedCost`=0 AND `type`=1); -- Refurbished Zandalari Vestment
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89666 AND `ExtendedCost`=0 AND `type`=1); -- Vestment of the Ascendant Tribe
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89124 AND `ExtendedCost`=0 AND `type`=1); -- Celestial Offering
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=93224 AND `ExtendedCost`=0 AND `type`=1); -- Grand Commendation of the August Celestials
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89799 AND `ExtendedCost`=0 AND `type`=1); -- August Celestials Tabard
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=86377 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Royal Satchel
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=76734 AND `ExtendedCost`=3901 AND `type`=1); -- Serpent's Eye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=79101 AND `ExtendedCost`=3901 AND `type`=1); -- Prismatic Scale
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72120 AND `ExtendedCost`=3901 AND `type`=1); -- Exotic Leather
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72103 AND `ExtendedCost`=3901 AND `type`=1); -- White Trillium Ore
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72094 AND `ExtendedCost`=3901 AND `type`=1); -- Black Trillium Ore
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72093 AND `ExtendedCost`=3901 AND `type`=1); -- Kyparite
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72092 AND `ExtendedCost`=3901 AND `type`=1); -- Ghost Iron Ore
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74247 AND `ExtendedCost`=3901 AND `type`=1); -- Ethereal Shard
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74250 AND `ExtendedCost`=3901 AND `type`=1); -- Mysterious Essence
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74249 AND `ExtendedCost`=3901 AND `type`=1); -- Spirit Dust
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72238 AND `ExtendedCost`=3901 AND `type`=1); -- Golden Lotus
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=89610 AND `ExtendedCost`=3901 AND `type`=1); -- Pandaria Herbs
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72988 AND `ExtendedCost`=3901 AND `type`=1); -- Windwool Cloth
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=79255 AND `ExtendedCost`=3901 AND `type`=1); -- Starlight Ink
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=402 AND `ExtendedCost`=3901 AND `type`=2); -- 402
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=76734 AND `ExtendedCost`=3901 AND `type`=1); -- Serpent's Eye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=79101 AND `ExtendedCost`=3901 AND `type`=1); -- Prismatic Scale
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72120 AND `ExtendedCost`=3901 AND `type`=1); -- Exotic Leather
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72103 AND `ExtendedCost`=3901 AND `type`=1); -- White Trillium Ore
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72094 AND `ExtendedCost`=3901 AND `type`=1); -- Black Trillium Ore
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72093 AND `ExtendedCost`=3901 AND `type`=1); -- Kyparite
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72092 AND `ExtendedCost`=3901 AND `type`=1); -- Ghost Iron Ore
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74247 AND `ExtendedCost`=3901 AND `type`=1); -- Ethereal Shard
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74250 AND `ExtendedCost`=3901 AND `type`=1); -- Mysterious Essence
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74249 AND `ExtendedCost`=3901 AND `type`=1); -- Spirit Dust
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72238 AND `ExtendedCost`=3901 AND `type`=1); -- Golden Lotus
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=89610 AND `ExtendedCost`=3901 AND `type`=1); -- Pandaria Herbs
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72988 AND `ExtendedCost`=3901 AND `type`=1); -- Windwool Cloth
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=79255 AND `ExtendedCost`=3901 AND `type`=1); -- Starlight Ink
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=402 AND `ExtendedCost`=3901 AND `type`=2); -- 402

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=66232 AND `ID`=1) OR (`CreatureID`=58464 AND `ID` IN (5,4)) OR (`CreatureID`=59826 AND `ID`=2);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(66232, 1, 2202, 0, 0, 0, 0, 0, 0, 0, 0), -- Puya
(58464, 5, 14879, 0, 0, 0, 0, 0, 0, 0, 0), -- Golden Lotus Warrior
(58464, 4, 12937, 0, 0, 0, 0, 0, 0, 0, 0), -- Golden Lotus Warrior
(59826, 2, 5956, 0, 0, 0, 0, 0, 0, 0, 0); -- -Unknown-

UPDATE `creature_equip_template` SET `ItemID1`=5289, `ItemID2`=0 WHERE (`CreatureID`=3296 AND `ID`=2); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=4568, `ItemID2`=1906 WHERE (`CreatureID`=3296 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2023 WHERE (`CreatureID`=58464 AND `ID`=3); -- Golden Lotus Warrior
UPDATE `creature_equip_template` SET `ItemID1`=6680 WHERE (`CreatureID`=58464 AND `ID`=2); -- Golden Lotus Warrior
UPDATE `creature_equip_template` SET `ItemID1`=81358 WHERE (`CreatureID`=58464 AND `ID`=1); -- Golden Lotus Warrior
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=61488 AND `ID`=1); -- -Unknown-

DELETE FROM `gossip_menu` WHERE (`MenuId`=14338 AND `TextId`=20245) OR (`MenuId`=14543 AND `TextId`=20565) OR (`MenuId`=14682 AND `TextId`=11714) OR (`MenuId`=14865 AND `TextId`=21026) OR (`MenuId`=14854 AND `TextId`=21012);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(14338, 20245, 38134), -- 64001 (Sage Lotusbloom)
(14543, 20565, 38134), -- 64534 (Bowmaster Ku)
(14682, 11714, 38134), -- 62996 (Madam Vee Luo)
(14865, 21026, 38134), -- 63535
(14854, 21012, 38134); -- 63751


DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=3 AND `MenuId`=14338) OR (`OptionIndex`=2 AND `MenuId`=14338) OR (`OptionIndex`=1 AND `MenuId` IN (14338,14543,14682)) OR (`OptionIndex`=0 AND `MenuId` IN (14543,14682,14865,14854));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(14338, 3, 1, 'I would like to buy from you.', 2583, 38134), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14338, 2, 0, 'Why should I help the August Celestials?', 64740, 38134),
(14338, 1, 0, 'How can I help the August Celestials today?', 64741, 38134),
(14543, 1, 0, 'How will I be rewarded by helping the Klaxxi?', 64761, 38134),
(14543, 0, 0, 'How can I help the Klaxxi?', 64762, 38134),
(14682, 1, 0, 'What can I find here in the city?', 66598, 38134),
(14682, 0, 5, 'Make this inn your home.', 2822, 38134), -- OptionBroadcastTextID: 2822 - 162070
(14865, 0, 0, 'I\'m from the Horde. We\'re here to save you and rebuild your village.', 66980, 38134), -- OptionBroadcastTextID: 66980 - 66994
(14854, 0, 0, 'I\'m from the Horde. We\'re here to save you and rebuild your village.', 66980, 38134); -- OptionBroadcastTextID: 66980 - 66994


UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=13116; -- Alliance Spirit Guide
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=13117; -- Horde Spirit Guide
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=62672; -- Harrison Jones
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=60378; -- Mine Cart
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=60140; -- Mine Cart
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=60380; -- Mine Cart
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=33587456 WHERE `entry`=62671; -- BANANAS
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `VehicleId`=0 WHERE `entry`=60379; -- Mine Cart
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=60145; -- Points Trigger
UPDATE `creature_template` SET `unit_flags`=33817344 WHERE `entry`=14848; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=60283; -- Track Switch
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=55470; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=55379; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=61535; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=55463; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=55464; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66239; -- Aimee Morningbreeze
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66234; -- Mitsua
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66231; -- Sona Morningbreeze
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66232; -- Puya
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66233; -- Pio
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66225; -- Cook Tsu
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66235; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66228; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66980; -- Grower Miao
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66981; -- Trapper Ri
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66979; -- Stonebreaker Ruian
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66237; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=66848; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66430; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66265; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66223; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66219; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66238; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66236; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66230; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=66227; -- Wing Hya
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66346; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags`=2097152 WHERE `entry`=66347; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66222; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=66220; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=62114; -- Spiny Lizard
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `RangeAttackTime`=0 WHERE `entry`=64585; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0 WHERE `entry`=63966; -- Vaultkeeper Shifen
UPDATE `creature_template` SET `maxlevel`=1, `npcflag`=1073741824, `RangeAttackTime`=0, `unit_flags`=512 WHERE `entry`=63838; -- Gilded Moth
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0 WHERE `entry`=63964; -- Vaultkeeper Kan
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0 WHERE `entry`=63965; -- Vaultkeeper Goldpenny
UPDATE `creature_template` SET `minlevel`=35, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=64057; -- Moko Powderrun
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0 WHERE `entry`=64056; -- Hafuna Landwalker
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0 WHERE `entry`=64048; -- Sheena Sunweaver
UPDATE `creature_template` SET `gossip_menu_id`=14682 WHERE `entry`=62996; -- Madam Vee Luo
UPDATE `creature_template` SET `gossip_menu_id`=14543 WHERE `entry`=64534; -- Bowmaster Ku
UPDATE `creature_template` SET `minlevel`=35, `faction`=2481, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=63752; -- Wounded Defender
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `RangeAttackTime`=0 WHERE `entry`=64127; -- Frances Lin
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `RangeAttackTime`=0 WHERE `entry`=64128; -- Edward Hanes
UPDATE `creature_template` SET `gossip_menu_id`=14338 WHERE `entry`=64001; -- Sage Lotusbloom
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags3`=1 WHERE `entry`=58245; -- Nala
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=90, `maxlevel`=90, `RangeAttackTime`=0 WHERE `entry`=64566; -- Sunwalker Dezco
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=59156; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=59486; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=63542; -- Elder Tsulan
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=31, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=63770; -- Alliance Yak
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=62882; -- Kai the Restless
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=59450; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `npcflag`=8192, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=61744; -- Tabo the Flyer
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=63754; -- Farmhand Bo
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=59451; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=16, `speed_walk`=2, `speed_run`=2.142857074737548828, `BaseAttackTime`=1500, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=60131; -- Spirit Worg
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=60550; -- Wild Spike Sprite
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000 WHERE `entry`=6491; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=31, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=60511; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2050 WHERE `entry`=60099; -- Western Oil Rig
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=50332; -- Korda Torros
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2575, `BaseAttackTime`=2000, `unit_flags`=33570816, `unit_flags2`=2048 WHERE `entry`=147662; -- Owl
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.857142865657806396, `RangeAttackTime`=0, `unit_flags`=33554944, `unit_flags2`=2048 WHERE `entry`=61750; -- Deer
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=147695; -- Forest Moth
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048 WHERE `entry`=147694; -- Rabbit
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=2048 WHERE `entry`=147693; -- Coral Snake
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=16, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=60127; -- Ordo Warbringer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=24288; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2099200, `dynamicflags`=4 WHERE `entry`=60032; -- Akonu the Embercaller
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2050 WHERE `entry`=60098; -- Southern Oil Rig
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=15, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=65773; -- Ordo Yak
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=15, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=65774; -- Ordo Yak Calf
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2099200 WHERE `entry`=60031; -- Pao-kun the Pyromancer
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=16777216, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=60038; -- Pandaren Prisoner
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2050 WHERE `entry`=60096; -- Eastern Oil Rig
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2099200 WHERE `entry`=60030; -- Harala the Firespeaker
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=16, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=59968; -- Ordo Marauder
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2099200, `dynamicflags`=4 WHERE `entry`=59969; -- Musaan the Blazecaster
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=16, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags`=32784, `unit_flags2`=33556480 WHERE `entry`=59970; -- Ordo Battleyak
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=67175; -- Steelbender Jin
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=59441; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=59972; -- Ordo Warrior
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=63820; -- Alliance Trainee
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags2`=4196352 WHERE `entry`=31047; -- ELM General Purpose Bunny Gigantic
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `BaseAttackTime`=2000, `unit_flags2`=4229120 WHERE `entry`=65440; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=50354; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=14865 WHERE `entry`=63535; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=14854 WHERE `entry`=63751; -- -Unknown-
UPDATE `creature_template` SET `faction`=15, `unit_flags`=294912, `unit_flags3`=1 WHERE `entry`=59773; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags2`=34816 WHERE `entry`=61490; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags2`=34816 WHERE `entry`=61488; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags2`=34816 WHERE `entry`=61489; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=16, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=59790; -- -Unknown-
UPDATE `creature_template` SET `speed_run`=1.314285635948181152 WHERE `entry`=59859; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=59538; -- -Unknown-
UPDATE `creature_template` SET `speed_run`=1.314285635948181152 WHERE `entry`=59592; -- Grummle Trail Guide
UPDATE `creature_template` SET `speed_run`=1.314285635948181152 WHERE `entry`=59858; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=31, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags2`=2049, `unit_flags3`=8193, `dynamicflags`=0 WHERE `entry`=60859; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=31, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=60242; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=59534; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=2110, `speed_run`=1.314285635948181152, `BaseAttackTime`=2000, `unit_flags`=536903680 WHERE `entry`=59593; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=31, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=58415; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=2111, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=59443; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=2110, `speed_walk`=1, `speed_run`=1.314285635948181152, `RangeAttackTime`=0, `unit_flags`=294912, `unit_flags2`=2048 WHERE `entry`=59526; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=2110, `speed_walk`=1, `speed_run`=1.314285635948181152, `RangeAttackTime`=0, `unit_flags`=294912, `unit_flags2`=2048 WHERE `entry`=59527; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=31, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=60860; -- -Unknown-

UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=42431; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=43241; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=38842; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=40316; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=39371; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=40050; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=38372; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=37779; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=37965; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=40111; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4800 WHERE `ID`=37466; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=35660096, `VerifiedBuild`=38134 WHERE `ID`=42977; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=99850, `RewardBonusMoney`=2400, `RewardSpell`=225995, `FlagsEx`=35725632, `VerifiedBuild`=38134 WHERE `ID`=42187; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=99850, `RewardBonusMoney`=2400, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=36594; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=99850, `RewardBonusMoney`=2400, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29659; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=99850, `RewardBonusMoney`=2400, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29614; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=99850, `RewardBonusMoney`=2400, `Flags`=0, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29598; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62182; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=5850, `FlagsEx`=2097472, `VerifiedBuild`=38134 WHERE `ID`=58582; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=50604; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=32461; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2400, `FlagsEx`=2097216, `FlagsEx2`=4, `RewardSkillLineID`=185, `VerifiedBuild`=38134 WHERE `ID`=29509; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=49925, `RewardBonusMoney`=1200, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=32249; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31377; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31459; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31453; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=99850, `RewardBonusMoney`=2400 WHERE `ID`=30786; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31695; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31451; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31457; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=299550, `RewardBonusMoney`=3000, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=30661; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=47350, `RewardBonusMoney`=2280, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=14072; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1740, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=14045; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=47350, `RewardBonusMoney`=1140, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=14034; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=378800, `RewardBonusMoney`=13800, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=40072; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9470, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=38872; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=378800, `RewardBonusMoney`=9300 WHERE `ID`=44004; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `FlagsEx`=2424896, `VerifiedBuild`=38134 WHERE `ID`=39579; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=39426; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=38721; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=378800, `RewardBonusMoney`=4650, `FlagsEx`=2367554, `VerifiedBuild`=38134 WHERE `ID`=37470; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=378800, `RewardBonusMoney`=4650 WHERE `ID`=37146; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=378800, `RewardBonusMoney`=4650, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=37142; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29433; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=378800, `RewardBonusMoney`=1740, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=26858; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=23675, `RewardBonusMoney`=570 WHERE `ID`=40605; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29862; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29861; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29860; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `Flags`=33554440, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=11911; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2280, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=30657; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=30656; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=94700, `RewardBonusMoney`=2280, `RewardSpell`=126963, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=30655; -- -Unknown-


UPDATE `quest_objectives` SET `Description`='Enlist Li Li Stormstout', `VerifiedBuild`=38134 WHERE `ID`=283921; -- 283921
UPDATE `quest_objectives` SET `Description`='Enlist Chen Stormstout', `VerifiedBuild`=38134 WHERE `ID`=283886; -- 283886
UPDATE `quest_objectives` SET `Description`='Siege Cannon Parts collected', `VerifiedBuild`=38134 WHERE `ID`=274955; -- 274955
UPDATE `quest_objectives` SET `Description`='Black Iron Shells collected', `VerifiedBuild`=38134 WHERE `ID`=274954; -- 274954
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=255602; -- 255602
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=258800; -- 258800
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=258799; -- 258799
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=258798; -- 258798
UPDATE `quest_objectives` SET `Description`='Internment Lodges Set Ablaze', `VerifiedBuild`=38134 WHERE `ID`=252114; -- 252114
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=394413; -- 394413
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336954; -- 336954
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=255311; -- 255311
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=253155; -- 253155
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=255724; -- 255724
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264764; -- 264764
UPDATE `quest_objectives` SET `Description`='Odyn defeated', `VerifiedBuild`=38134 WHERE `ID`=285235; -- 285235
UPDATE `quest_objectives` SET `Description`='Claim the Aegis of Aggramar', `VerifiedBuild`=38134 WHERE `ID`=280268; -- 280268
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=279665; -- 279665
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=279393; -- 279393
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=278336; -- 278336
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=276356; -- 276356
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=277161; -- 277161
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=275640; -- 275640
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=252968; -- 252968
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=254679; -- 254679
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=254678; -- 254678
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=254677; -- 254677
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=254676; -- 254676
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=263744; -- 263744
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=263743; -- 263743
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=263742; -- 263742
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=262705; -- 262705
UPDATE `quest_objectives` SET `Description`='Volkhan Defeated', `VerifiedBuild`=38134 WHERE `ID`=262697; -- 262697
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=262561; -- 262561
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=254057; -- 254057
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=254056; -- 254056
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=254055; -- 254055
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=254054; -- 254054
UPDATE `quest_objectives` SET `Description`='Western Oil Rig destroyed', `VerifiedBuild`=38134 WHERE `ID`=254053; -- 254053
UPDATE `quest_objectives` SET `Description`='Southern Oil Rig destroyed', `VerifiedBuild`=38134 WHERE `ID`=254052; -- 254052
UPDATE `quest_objectives` SET `Description`='Eastern Oil Rig destroyed', `VerifiedBuild`=38134 WHERE `ID`=254051; -- 254051
UPDATE `quest_objectives` SET `Description`='Pandaren Prisoners rescued', `VerifiedBuild`=38134 WHERE `ID`=254001; -- 254001


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=283921 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=283886 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274955 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274954 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394413 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=279665 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=278336 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=277161 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=275640 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=254053 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=254052 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=254051 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=254001 AND `Index`=0);


UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64056; -- Hafuna Landwalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64057; -- Moko Powderrun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63542; -- Elder Tsulan
UPDATE `creature_template` SET `family`=157, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=65773; -- Ordo Yak
UPDATE `creature_template` SET `rank`=6, `family`=157, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=65774; -- Ordo Yak Calf
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=147662; -- Owl
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=22895; -- Summoned Searing Totem
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=64127; -- Frances Lin
UPDATE `creature_template` SET `IconName`='directions', `VerifiedBuild`=38134 WHERE `entry`=64128; -- Edward Hanes
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=147693; -- Coral Snake
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143794; -- Scuttle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=147694; -- Rabbit
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=147695; -- Forest Moth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143814; -- Snapper
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type_flags`=1628439554, `HealthModifier`=1.35000002384185791, `VerifiedBuild`=38134 WHERE `entry`=60283; -- Track Switch
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66979; -- Stonebreaker Ruian
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66980; -- Grower Miao
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66981; -- Trapper Ri
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=48634; -- Guild Battle Standard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62005; -- Beast
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=62020; -- Ruby Sapling
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VignetteID`=159, `family`=0, `type`=7, `type_flags`=2097224, `movementId`=841, `VerifiedBuild`=38134 WHERE `entry`=50332; -- Korda Torros
UPDATE `creature_template` SET `unit_class`=4, `VerifiedBuild`=38134 WHERE `entry`=60378; -- Mine Cart
UPDATE `creature_template` SET `unit_class`=4, `VerifiedBuild`=38134 WHERE `entry`=60379; -- Mine Cart
UPDATE `creature_template` SET `unit_class`=4, `VerifiedBuild`=38134 WHERE `entry`=60380; -- Mine Cart
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=39236; -- Poison Extraction Totem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63752; -- Wounded Defender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63754; -- Farmhand Bo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63770; -- Alliance Yak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=29238; -- Scourge Haunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62671; -- BANANAS
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62672; -- Harrison Jones
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=96649; -- Ashmaw Cub
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=13116; -- Alliance Spirit Guide
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=13117; -- Horde Spirit Guide
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64926; -- End Event Controller Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=58245; -- Nala
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63820; -- Alliance Trainee
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60484; -- Snow Flower
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=95577; -- Void Tendril
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67175; -- Steelbender Jin
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=38134 WHERE `entry`=63838; -- Gilded Moth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143503; -- Aldrusian Sproutling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=59968; -- Ordo Marauder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=59969; -- Musaan the Blazecaster
UPDATE `creature_template` SET `family`=157, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=59970; -- Ordo Battleyak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=59972; -- Ordo Warrior
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=60550; -- Wild Spike Sprite
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=31047; -- ELM General Purpose Bunny Gigantic
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60030; -- Harala the Firespeaker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60031; -- Pao-kun the Pyromancer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60032; -- Akonu the Embercaller
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60038; -- Pandaren Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63964; -- Vaultkeeper Kan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63965; -- Vaultkeeper Goldpenny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63966; -- Vaultkeeper Shifen
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=61744; -- Tabo the Flyer
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=61750; -- Deer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60095; -- Explosives Barrel
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60096; -- Eastern Oil Rig
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62882; -- Kai the Restless
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66225; -- Cook Tsu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60098; -- Southern Oil Rig
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60099; -- Western Oil Rig
UPDATE `creature_template` SET `IconName`='taxi', `VerifiedBuild`=38134 WHERE `entry`=66227; -- Wing Hya
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66231; -- Sona Morningbreeze
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66232; -- Puya
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66233; -- Pio
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66234; -- Mitsua
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64566; -- Sunwalker Dezco
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66239; -- Aimee Morningbreeze
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60127; -- Ordo Warbringer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60131; -- Spirit Worg
UPDATE `creature_template` SET `unit_class`=4, `type_flags`=5242882, `VerifiedBuild`=38134 WHERE `entry`=60140; -- Mine Cart
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60145; -- Points Trigger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64048; -- Sheena Sunweaver


UPDATE `creature_template_model` SET `DisplayScale`=0.349999994039535522 WHERE (`CreatureID`=143794 AND `Idx`=0); -- Scuttle


UPDATE `gameobject_template` SET `name`='Lava Depot', `VerifiedBuild`=38134 WHERE `entry`=212081; -- Lava Depot
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212301; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212313; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212309; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212305; -- Chair
UPDATE `gameobject_template` SET `Data1`=5743776, `VerifiedBuild`=38134 WHERE `entry`=212942; -- Gate
UPDATE `gameobject_template` SET `name`='Diamond Depot', `VerifiedBuild`=38134 WHERE `entry`=212082; -- Diamond Depot
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212306; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212314; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212310; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212302; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212298; -- Chair
UPDATE `gameobject_template` SET `Data1`=5743776, `VerifiedBuild`=38134 WHERE `entry`=212939; -- Gate
UPDATE `gameobject_template` SET `name`='Troll Depot', `VerifiedBuild`=38134 WHERE `entry`=212083; -- Troll Depot
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212315; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212311; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212307; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212303; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212299; -- Chair
UPDATE `gameobject_template` SET `Data1`=5743776, `VerifiedBuild`=38134 WHERE `entry`=212940; -- Gate
UPDATE `gameobject_template` SET `name`='Waterfall Depot', `VerifiedBuild`=38134 WHERE `entry`=212080; -- Waterfall Depot
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212304; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212300; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212312; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=212308; -- Chair
UPDATE `gameobject_template` SET `Data1`=5743776, `VerifiedBuild`=38134 WHERE `entry`=212941; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214987; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213700; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213729; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213705; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213674; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213673; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213672; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214233; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214231; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213678; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213114; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213671; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213355; -- Kun-Lai Feast Platter
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212479; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211115; -- Meat 07
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211114; -- Meat 06
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211113; -- Meat 04
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211220; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212481; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214744; -- Totemfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213814; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=210503; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214745; -- Totemfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=186459; -- Stratholme Fire Medium
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=309883; -- Doodad_7NE_Blackrook_Portcullis002
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=309704; -- Alliance Door
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352709; -- Horde Gate
UPDATE `gameobject_template` SET `name`='Collision PC Size', `VerifiedBuild`=38134 WHERE `entry`=242273; -- Collision PC Size
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=309705; -- Doodad_7NE_Blackrook_Portcullis009
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352710; -- Horde Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211327; -- Fire Shield Collision Wall
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214743; -- Totemfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213815; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212482; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214742; -- Totemfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215867; -- Yaungol Skulls
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215866; -- Yaungol Totem
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213417; -- Yaungol Tactics
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211657; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211656; -- Forge
UPDATE `gameobject_template` SET `Data1`=0, `Data17`=15822, `Data30`=41520, `ContentTuningId`=60, `VerifiedBuild`=38134 WHERE `entry`=211312; -- Explosives Barrel
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214746; -- Totemfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212652; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212651; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211328; -- Wall of Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214766; -- Totemfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214765; -- Totemfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214764; -- Totemfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214763; -- Totemfire


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=211312 AND `Idx`=0); -- Explosives Barrel


UPDATE `page_text` SET `VerifiedBuild`=38134 WHERE `ID`=4528; -- 4528


UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=20565; -- 20565
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=20245; -- 20245
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=11714; -- 11714

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (352710 /*Horde Gate*/, 352709 /*Horde Gate*/, 309705 /*Doodad_7NE_Blackrook_Portcullis009*/, 309704 /*Alliance Door*/, 309883 /*Doodad_7NE_Blackrook_Portcullis002*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(352710, 1375, 32, 0, 0), -- Horde Gate
(352709, 1375, 32, 0, 0), -- Horde Gate
(309705, 1375, 32, 0, 0), -- Doodad_7NE_Blackrook_Portcullis009
(309704, 1375, 32, 0, 0), -- Alliance Door
(309883, 1375, 32, 0, 0); -- Doodad_7NE_Blackrook_Portcullis002



UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=212942; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=212940; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=212941; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=212939; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212082; -- Diamond Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212083; -- Troll Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212080; -- Waterfall Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212081; -- Lava Depot
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=214987; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213700; -- Banner
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213705; -- Banner
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=214233; -- Guild Vault
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=214231; -- Guild Vault
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213678; -- Banner
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=211115; -- Meat 07
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=211114; -- Meat 06
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=211113; -- Meat 04
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=211220; -- Mailbox
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=211327; -- Fire Shield Collision Wall
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=211312; -- Explosives Barrel
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=211328; -- Wall of Fire

DELETE FROM `quest_offer_reward` WHERE `ID` IN (31511 /*-Unknown-*/, 30656 /*-Unknown-*/, 30661 /*-Unknown-*/, 30655 /*-Unknown-*/, 30657 /*-Unknown-*/, 30620 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(31511, 396, 0, 0, 0, 0, 0, 0, 0, 'Welcome to the Shrine of Two Moons, traveler.$B$BI know that the Celestials sent you here to help us, but first, take a moment to rest and explore the city.$B$BWelcome to the Vale.', 38134), -- -Unknown-
(30656, 4, 0, 0, 0, 0, 0, 0, 0, 'You can\'t tell me that wasn\'t fun, $n! I knew I should have gone over there with you!', 38134), -- -Unknown-
(30661, 4, 0, 0, 0, 0, 0, 0, 0, 'Once again you\'ve accomplished what no one else could.$B$BWas there any doubt?', 38134), -- -Unknown-
(30655, 2, 0, 0, 0, 0, 0, 0, 0, 'Well, it looks like we\'ve got ourselves a little army, here, thanks to you.\n\nThey may not look like much yet, but a little Horde discipline and we\'ll have them in fighting shape in no time.\n\nBy the way, $n... good work.', 38134), -- -Unknown-
(30657, 0, 0, 0, 0, 0, 0, 0, 0, '<The Ordo lieutenants are dead. The shield is down.>$B$B<Time to take out the Ordo leader!>', 38134), -- -Unknown-
(30620, 6, 0, 0, 0, 0, 0, 0, 0, 'Oh, thank goodness! You\'ve saved all of our skins, believe me.\n\nYou have no idea how much trouble those guys can stir up.\n\nErr, or, I guess you do, now. Kind of. Almost.\n\nImagine that, but a lot worse, and for a couple thousand years.', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=31459 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=30656 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(31459, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 4, 32, 0, 0, 870, 379, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 3, 2, 254053, 60099, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 2, 1, 254052, 60098, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 1, 0, 254051, 60096, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30661 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30661 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30620 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30620 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30620 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31511 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31511 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31511 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=31459 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=30656 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(31459, 0, 0, 3044, 1251, 655, 38134), -- -Unknown-
(30656, 4, 0, 2280, 901, 482, 38134), -- -Unknown-
(30656, 3, 0, 2217, 1844, 494, 38134), -- -Unknown-
(30656, 2, 0, 2237, 1732, 492, 38134), -- -Unknown-
(30656, 1, 0, 2306, 1651, 508, 38134), -- -Unknown-
(30656, 0, 0, 2285, 910, 482, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30661 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30661 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30657 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30655 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30620 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30620 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=30620 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31511 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31511 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31511 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_greeting` WHERE (`ID`=59442 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(59442, 0, 0, 0, '', 38134); -- 59442


DELETE FROM `quest_details` WHERE `ID` IN (32249 /*-Unknown-*/, 31377 /*-Unknown-*/, 31459 /*-Unknown-*/, 31453 /*-Unknown-*/, 31695 /*-Unknown-*/, 31451 /*-Unknown-*/, 31457 /*-Unknown-*/, 30661 /*-Unknown-*/, 30657 /*-Unknown-*/, 30656 /*-Unknown-*/, 30655 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(32249, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31377, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31459, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31453, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31695, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31451, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31457, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30661, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30657, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30656, 5, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(30655, 1, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (115230,115267));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(115230, 0, 870, 1701.949951171875, 1371.43994140625, 455.7550048828125, 38134), -- Spell: 115230 (Summon Refugee) Efffect: 28 (SPELL_EFFECT_SUMMON)
(115267, 0, 870, 1696.280029296875, 1371.1700439453125, 453.787994384765625, 38134); -- Spell: 115267 (Summon Refugee) Efffect: 28 (SPELL_EFFECT_SUMMON)

UPDATE `spell_target_position` SET `PositionX`=-11.109999656677246, `PositionY`=6746.18994140625, `VerifiedBuild`=38134 WHERE (`ID`=296901 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=1445.2099609375, `PositionY`=-4499.56005859375, `PositionZ`=18.30999946594238281, `VerifiedBuild`=38134 WHERE (`ID`=3567 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (62672 /*62672 (Harrison Jones) - Ride Vehicle Hardcoded, Read Scroll*/, 60378 /*60378 (Mine Cart)*/, 60140 /*60140 (Mine Cart) - Control Visual (Neutral)*/, 60380 /*60380 (Mine Cart)*/, 60145 /*60145 (Points Trigger)*/, 62671 /*62671 (BANANAS) - Ride Vehicle Hardcoded, Hold Barrel*/, 60379 /*60379 (Mine Cart)*/, 60283 /*60283 (Track Switch) - Track Switch Visual (Opened)*/, 66231 /*66231 (Sona Morningbreeze)*/, 66232 /*66232 (Puya)*/, 66233 /*66233 (Pio)*/, 66225 /*66225 (Cook Tsu)*/, 66239 /*66239 (Aimee Morningbreeze)*/, 66234 /*66234 (Mitsua)*/, 66980 /*66980 (Grower Miao)*/, 66981 /*66981 (Trapper Ri)*/, 66979 /*66979 (Stonebreaker Ruian)*/, 66227 /*66227 (Wing Hya)*/, 64585 /*64585*/, 63966 /*63966 (Vaultkeeper Shifen)*/, 63838 /*63838 (Gilded Moth)*/, 63964 /*63964 (Vaultkeeper Kan)*/, 64056 /*64056 (Hafuna Landwalker)*/, 63965 /*63965 (Vaultkeeper Goldpenny)*/, 64057 /*64057 (Moko Powderrun)*/, 64048 /*64048 (Sheena Sunweaver)*/, 64128 /*64128 (Edward Hanes)*/, 64127 /*64127 (Frances Lin)*/, 63752 /*63752 (Wounded Defender)*/, 64566 /*64566 (Sunwalker Dezco)*/, 58245 /*58245 (Nala)*/, 63542 /*63542 (Elder Tsulan)*/, 63770 /*63770 (Alliance Yak)*/, 62882 /*62882 (Kai the Restless) - Generic Quest Invisibility 16*/, 59450 /*59450 - Generic Quest Invisibility 16*/, 61744 /*61744 (Tabo the Flyer) - Generic Quest Invisibility 16*/, 63754 /*63754 (Farmhand Bo)*/, 59451 /*59451 - Generic Quest Invisibility 16*/, 60131 /*60131 (Spirit Worg) - Ghost Visual*/, 60550 /*60550 (Wild Spike Sprite)*/, 60511 /*60511*/, 60099 /*60099 (Western Oil Rig)*/, 50332 /*50332 (Korda Torros) - Dual Wield*/, 147662 /*147662 (Owl)*/, 61750 /*61750 (Deer)*/, 147695 /*147695 (Forest Moth)*/, 147694 /*147694 (Rabbit)*/, 147693 /*147693 (Coral Snake)*/, 60127 /*60127 (Ordo Warbringer) - Fire Channeling*/, 60032 /*60032 (Akonu the Embercaller) - In Tents Channeling: Jilvici Fire Channel*/, 60098 /*60098 (Southern Oil Rig)*/, 65774 /*65774 (Ordo Yak Calf)*/, 65773 /*65773 (Ordo Yak)*/, 60030 /*60030 (Harala the Firespeaker) - In Tents Channeling: Jilvici Fire Channel*/, 60031 /*60031 (Pao-kun the Pyromancer) - In Tents Channeling: Jilvici Fire Channel*/, 60096 /*60096 (Eastern Oil Rig)*/, 60038 /*60038 (Pandaren Prisoner) - Cosmetic - Ball & Chain*/, 59968 /*59968 (Ordo Marauder)*/, 59969 /*59969 (Musaan the Blazecaster) - In Tents Channeling: Jilvici Fire Channel*/, 59970 /*59970 (Ordo Battleyak)*/, 59972 /*59972 (Ordo Warrior)*/, 63820 /*63820 (Alliance Trainee)*/, 67175 /*67175 (Steelbender Jin)*/, 59441 /*59441 - Generic Quest Invisibility 16*/, 65440 /*65440*/, 50354 /*50354 - Stone Form*/, 61490 /*61490*/, 61488 /*61488*/, 61489 /*61489*/, 59790 /*59790*/, 60859 /*60859 - Permanent Feign Death*/, 60242 /*60242*/, 60860 /*60860*/, 59443 /*59443 - Grummle Ambusher Threat Nuke Aura*/, 59593 /*59593 - Grummle Threat Nuke Aura*/, 58415 /*58415*/, 59526 /*59526 - Grummle Threat Nuke Aura, Terrified Grummle*/, 59527 /*59527 - Grummle Threat Nuke Aura, Terrified Grummle*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(62672, 0, 0, 0, 1, 0, 0, 0, 0, '46598 122236'), -- 62672 (Harrison Jones) - Ride Vehicle Hardcoded, Read Scroll
(60378, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 60378 (Mine Cart)
(60140, 0, 0, 0, 1, 0, 0, 0, 0, '118001'), -- 60140 (Mine Cart) - Control Visual (Neutral)
(60380, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 60380 (Mine Cart)
(60145, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60145 (Points Trigger)
(62671, 0, 0, 0, 1, 0, 0, 0, 0, '46598 122297'), -- 62671 (BANANAS) - Ride Vehicle Hardcoded, Hold Barrel
(60379, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 60379 (Mine Cart)
(60283, 0, 0, 0, 1, 0, 0, 0, 0, '120228'), -- 60283 (Track Switch) - Track Switch Visual (Opened)
(66231, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66231 (Sona Morningbreeze)
(66232, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66232 (Puya)
(66233, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66233 (Pio)
(66225, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66225 (Cook Tsu)
(66239, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66239 (Aimee Morningbreeze)
(66234, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66234 (Mitsua)
(66980, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66980 (Grower Miao)
(66981, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66981 (Trapper Ri)
(66979, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66979 (Stonebreaker Ruian)
(66227, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66227 (Wing Hya)
(64585, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64585
(63966, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 63966 (Vaultkeeper Shifen)
(63838, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 63838 (Gilded Moth)
(63964, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 63964 (Vaultkeeper Kan)
(64056, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64056 (Hafuna Landwalker)
(63965, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 63965 (Vaultkeeper Goldpenny)
(64057, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64057 (Moko Powderrun)
(64048, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64048 (Sheena Sunweaver)
(64128, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64128 (Edward Hanes)
(64127, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64127 (Frances Lin)
(63752, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 63752 (Wounded Defender)
(64566, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 64566 (Sunwalker Dezco)
(58245, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 58245 (Nala)
(63542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63542 (Elder Tsulan)
(63770, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63770 (Alliance Yak)
(62882, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 62882 (Kai the Restless) - Generic Quest Invisibility 16
(59450, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 59450 - Generic Quest Invisibility 16
(61744, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 61744 (Tabo the Flyer) - Generic Quest Invisibility 16
(63754, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63754 (Farmhand Bo)
(59451, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 59451 - Generic Quest Invisibility 16
(60131, 0, 0, 0, 1, 0, 0, 0, 0, '22650'), -- 60131 (Spirit Worg) - Ghost Visual
(60550, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60550 (Wild Spike Sprite)
(60511, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60511
(60099, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60099 (Western Oil Rig)
(50332, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 50332 (Korda Torros) - Dual Wield
(147662, 0, 0, 50331648, 1, 0, 835, 0, 0, ''), -- 147662 (Owl)
(61750, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61750 (Deer)
(147695, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 147695 (Forest Moth)
(147694, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147694 (Rabbit)
(147693, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147693 (Coral Snake)
(60127, 0, 0, 0, 1, 0, 0, 0, 0, '78192'), -- 60127 (Ordo Warbringer) - Fire Channeling
(60032, 0, 0, 0, 1, 0, 0, 0, 0, '128430'), -- 60032 (Akonu the Embercaller) - In Tents Channeling: Jilvici Fire Channel
(60098, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60098 (Southern Oil Rig)
(65774, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65774 (Ordo Yak Calf)
(65773, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65773 (Ordo Yak)
(60030, 0, 0, 0, 1, 0, 0, 0, 0, '128430'), -- 60030 (Harala the Firespeaker) - In Tents Channeling: Jilvici Fire Channel
(60031, 0, 0, 0, 1, 0, 0, 0, 0, '128430'), -- 60031 (Pao-kun the Pyromancer) - In Tents Channeling: Jilvici Fire Channel
(60096, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60096 (Eastern Oil Rig)
(60038, 0, 0, 0, 1, 0, 0, 0, 0, '115533'), -- 60038 (Pandaren Prisoner) - Cosmetic - Ball & Chain
(59968, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59968 (Ordo Marauder)
(59969, 0, 0, 0, 1, 0, 0, 0, 0, '128430'), -- 59969 (Musaan the Blazecaster) - In Tents Channeling: Jilvici Fire Channel
(59970, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59970 (Ordo Battleyak)
(59972, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59972 (Ordo Warrior)
(63820, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63820 (Alliance Trainee)
(67175, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67175 (Steelbender Jin)
(59441, 0, 0, 65536, 1, 0, 0, 0, 0, '84667'), -- 59441 - Generic Quest Invisibility 16
(65440, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 65440
(50354, 0, 0, 0, 1, 0, 0, 0, 0, '130227'), -- 50354 - Stone Form
(61490, 0, 0, 0, 1, 0, 2238, 0, 0, ''), -- 61490
(61488, 0, 0, 0, 1, 0, 2238, 0, 0, ''), -- 61488
(61489, 0, 0, 0, 1, 0, 2238, 0, 0, ''), -- 61489
(59790, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59790
(60859, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 60859 - Permanent Feign Death
(60242, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60242
(60860, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60860
(59443, 0, 0, 0, 1, 0, 0, 0, 0, '116031'), -- 59443 - Grummle Ambusher Threat Nuke Aura
(59593, 0, 0, 0, 1, 0, 0, 0, 0, '116029'), -- 59593 - Grummle Threat Nuke Aura
(58415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 58415
(59526, 0, 0, 0, 1, 0, 0, 0, 0, '116029 125239'), -- 59526 - Grummle Threat Nuke Aura, Terrified Grummle
(59527, 0, 0, 0, 1, 0, 0, 0, 0, '116029 125239'); -- 59527 - Grummle Threat Nuke Aura; Terrified Grummle

UPDATE `creature_template_addon` SET `auras`='9036 9617 22011' WHERE `entry`=13116; -- 13116 (Alliance Spirit Guide)
UPDATE `creature_template_addon` SET `auras`='9036 9617 22011' WHERE `entry`=13117; -- 13117 (Horde Spirit Guide)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=55470; -- 55470
UPDATE `creature_template_addon` SET `aiAnimKit`=16759 WHERE `entry`=141693; -- 141693
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=16023 WHERE `entry`=141119; -- 141119
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=64066; -- 64066 (Brewmaster Vudia)
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=2891 WHERE `entry`=63753; -- 63753 (Wounded Defender)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=64121; -- 64121 (Eli)
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=64584; -- 64584 (Dawnchaser Brave)
UPDATE `creature_template_addon` SET `bytes1`=65536 WHERE `entry`=6491; -- 6491
UPDATE `creature_template_addon` SET `auras`='123240' WHERE `entry`=62822; -- 62822
UPDATE `creature_template_addon` SET `auras`='123236' WHERE `entry`=62821; -- 62821
UPDATE `creature_template_addon` SET `bytes1`=65536, `auras`='84667' WHERE `entry`=59442; -- 59442
UPDATE `creature_template_addon` SET `aiAnimKit`=1904 WHERE `entry`=63821; -- 63821
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=59773; -- 59773
UPDATE `creature_template_addon` SET `auras`='129091' WHERE `entry`=59758; -- 59758
UPDATE `creature_template_addon` SET `auras`='129508' WHERE `entry`=65839; -- 65839
UPDATE `creature_template_addon` SET `auras`='115909' WHERE `entry`=55370; -- 55370


UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=982, `VerifiedBuild`=38134 WHERE (`Entry`=13116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=982, `VerifiedBuild`=38134 WHERE (`Entry`=13117 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=62672 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60378 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60140 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60145 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=62671 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=978, `VerifiedBuild`=38134 WHERE (`Entry`=60283 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66231 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66232 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66233 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66239 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66234 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66980 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66981 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66979 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=881, `VerifiedBuild`=38134 WHERE (`Entry`=66227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64585 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=63966 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63838 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=63964 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64056 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=63965 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64057 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=63752 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=173, `VerifiedBuild`=38134 WHERE (`Entry`=64566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=15, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=59, `VerifiedBuild`=38134 WHERE (`Entry`=58245 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=63542 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=63770 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=62882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59450 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=881, `VerifiedBuild`=38134 WHERE (`Entry`=61744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=63754 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59451 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=6491 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60511 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60099 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=50332 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=972, `VerifiedBuild`=38134 WHERE (`Entry`=147662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=972, `VerifiedBuild`=38134 WHERE (`Entry`=147695 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=972, `VerifiedBuild`=38134 WHERE (`Entry`=147694 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=972, `VerifiedBuild`=38134 WHERE (`Entry`=147693 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=24288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=65774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=65773 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60096 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60038 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59968 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59969 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59970 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59972 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=63820 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=67175 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59441 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=31047 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=65440 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=50354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=61490 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=61488 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=61489 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59790 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60859 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60491 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60860 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59443 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59593 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=58415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59526 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=59527 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=13337;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=13339;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42619;
UPDATE `creature_model_info` SET `BoundingRadius`=2.670626640319824218, `VerifiedBuild`=38134 WHERE `DisplayID`=40935;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41243;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42102;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44887;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44888;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44889;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44880;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44895;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44890;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45525;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45526;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45524;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44883;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44358;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43369;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43366;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=44365;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43368;
UPDATE `creature_model_info` SET `BoundingRadius`=1.780417680740356445, `VerifiedBuild`=38134 WHERE `DisplayID`=41789;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45537;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44369;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=42491;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42489;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40006;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=40294;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44053;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44068;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43108;
UPDATE `creature_model_info` SET `BoundingRadius`=0.312499791383743286, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=42766;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=38872;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=42223;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43207;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=38870;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43235;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5233;
UPDATE `creature_model_info` SET `BoundingRadius`=0.485495239496231079, `CombatReach`=1.770408153533935546, `VerifiedBuild`=38134 WHERE `DisplayID`=41000;
UPDATE `creature_model_info` SET `BoundingRadius`=0.685569643974304199, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=40021;
UPDATE `creature_model_info` SET `BoundingRadius`=0.611119985580444335, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=44163;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40353;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36952;
UPDATE `creature_model_info` SET `BoundingRadius`=2.062988519668579101, `VerifiedBuild`=38134 WHERE `DisplayID`=64331;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36957;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=347;
UPDATE `creature_model_info` SET `BoundingRadius`=0.052500002086162567, `CombatReach`=0.150000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=36944;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=328;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36580;
UPDATE `creature_model_info` SET `BoundingRadius`=0.611119985580444335, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=41236;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534729957580566406, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=41201;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40354;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381949990987777709, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44526;
UPDATE `creature_model_info` SET `BoundingRadius`=0.708163261413574218, `CombatReach`=1.062244892120361328, `VerifiedBuild`=38134 WHERE `DisplayID`=44596;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381949990987777709, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44527;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534729957580566406, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=41202;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534729957580566406, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=41203;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41519;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41520;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381949990987777709, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44529;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534729957580566406, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=41200;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=42171;
UPDATE `creature_model_info` SET `BoundingRadius`=0.458339989185333251, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44524;
UPDATE `creature_model_info` SET `BoundingRadius`=0.458339989185333251, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44523;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43238;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43236;
UPDATE `creature_model_info` SET `BoundingRadius`=0.458339989185333251, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44525;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=43237;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45971;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45964;
UPDATE `creature_model_info` SET `BoundingRadius`=2.375433683395385742, `CombatReach`=3.75, `VerifiedBuild`=38134 WHERE `DisplayID`=44349;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41781;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41785;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41784;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381949990987777709, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=41116;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41114;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41672;
UPDATE `creature_model_info` SET `BoundingRadius`=0.754126608371734619, `VerifiedBuild`=38134 WHERE `DisplayID`=40025;
UPDATE `creature_model_info` SET `BoundingRadius`=0.754126608371734619, `VerifiedBuild`=38134 WHERE `DisplayID`=45162;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=41674;
UPDATE `creature_model_info` SET `BoundingRadius`=1.068250656127929687, `CombatReach`=1.320000052452087402, `VerifiedBuild`=38134 WHERE `DisplayID`=40995;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=40664;
UPDATE `creature_model_info` SET `BoundingRadius`=1.068250656127929687, `CombatReach`=1.320000052452087402, `VerifiedBuild`=38134 WHERE `DisplayID`=41016;
UPDATE `creature_model_info` SET `BoundingRadius`=1.60000002384185791, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=41673;
UPDATE `creature_model_info` SET `BoundingRadius`=0.819706082344055175, `VerifiedBuild`=38134 WHERE `DisplayID`=40843;


UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=554;
UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=554;
UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=554;


UPDATE `trainer_spell` SET `MoneyCost`=1000, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `ReqLevel`=40, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=34092);
UPDATE `trainer_spell` SET `MoneyCost`=1000, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `ReqLevel`=40, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=34092);
UPDATE `trainer_spell` SET `MoneyCost`=1000, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `ReqLevel`=40, `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `VerifiedBuild`=38134 WHERE (`TrainerId`=554 AND `SpellId`=34092);

DELETE FROM `npc_vendor` WHERE (`entry`=64001 AND `item`=89304 AND `ExtendedCost`=5846 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(64001, 2, 89304, 0, 5846, 1, 0, 0, 38134); -- Reins of the Thundering August Cloud Serpent

UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Setting
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=60335 AND `ExtendedCost`=0 AND `type`=1); -- Thick Hide Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81400 AND `ExtendedCost`=0 AND `type`=1); -- Pounded Rice Cake
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=58274 AND `ExtendedCost`=0 AND `type`=1); -- Fresh Water
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=74636 AND `ExtendedCost`=0 AND `type`=1); -- Golden Carp Consomme
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81414 AND `ExtendedCost`=0 AND `type`=1); -- Pearl Milk Tea
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81406 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Barley Tea
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81409 AND `ExtendedCost`=0 AND `type`=1); -- Tangy Yogurt
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81401 AND `ExtendedCost`=0 AND `type`=1); -- Yak Cheese Curds
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81415 AND `ExtendedCost`=0 AND `type`=1); -- Pandaren Plum Wine
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `item`=81407 AND `ExtendedCost`=0 AND `type`=1); -- Four Wind Soju
UPDATE `npc_vendor` SET `slot`=48, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=84559 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Bracer - Super Intellect
UPDATE `npc_vendor` SET `slot`=47, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=84557 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Bracer - Greater Agility
UPDATE `npc_vendor` SET `slot`=46, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=84561 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Bracer - Exceptional Strength
UPDATE `npc_vendor` SET `slot`=45, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88882 AND `ExtendedCost`=0 AND `type`=1); -- Tiger-Striped Wristguards
UPDATE `npc_vendor` SET `slot`=44, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88881 AND `ExtendedCost`=0 AND `type`=1); -- Fallen Sentinel Bracers
UPDATE `npc_vendor` SET `slot`=43, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88880 AND `ExtendedCost`=0 AND `type`=1); -- Battle Shadow Bracers
UPDATE `npc_vendor` SET `slot`=42, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88879 AND `ExtendedCost`=0 AND `type`=1); -- Braided Black and White Bracer
UPDATE `npc_vendor` SET `slot`=41, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88893 AND `ExtendedCost`=0 AND `type`=1); -- Minh's Beaten Bracers
UPDATE `npc_vendor` SET `slot`=40, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88892 AND `ExtendedCost`=0 AND `type`=1); -- Bracers of Inlaid Jade
UPDATE `npc_vendor` SET `slot`=39, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88885 AND `ExtendedCost`=0 AND `type`=1); -- Clever Ashyo's Armbands
UPDATE `npc_vendor` SET `slot`=38, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88884 AND `ExtendedCost`=0 AND `type`=1); -- Quillpaw Family Bracers
UPDATE `npc_vendor` SET `slot`=37, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88883 AND `ExtendedCost`=0 AND `type`=1); -- Brewmaster Chani's Bracers
UPDATE `npc_vendor` SET `slot`=36, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88749 AND `ExtendedCost`=0 AND `type`=1); -- Gauntlets of Jade Sutras
UPDATE `npc_vendor` SET `slot`=35, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88748 AND `ExtendedCost`=0 AND `type`=1); -- Ravenmane's Gloves
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88747 AND `ExtendedCost`=0 AND `type`=1); -- Streetfighter's Iron Knuckles
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88746 AND `ExtendedCost`=0 AND `type`=1); -- Gloves of the Overwhelming Swarm
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88745 AND `ExtendedCost`=0 AND `type`=1); -- Sentinel Commander's Gauntlets
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88744 AND `ExtendedCost`=0 AND `type`=1); -- Fingers of the Loneliest Monk
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88743 AND `ExtendedCost`=0 AND `type`=1); -- Ogo's Elder Gloves
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88742 AND `ExtendedCost`=0 AND `type`=1); -- Sunspeaker's Flared Gloves
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88741 AND `ExtendedCost`=0 AND `type`=1); -- Gloves of Red Feathers
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88878 AND `ExtendedCost`=0 AND `type`=1); -- Void Flame Slippers
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88877 AND `ExtendedCost`=0 AND `type`=1); -- Storm-Sing Sandals
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88876 AND `ExtendedCost`=0 AND `type`=1); -- Boots of the High Adept
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88868 AND `ExtendedCost`=0 AND `type`=1); -- Tukka-Tuk's Hairy Boots
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88867 AND `ExtendedCost`=0 AND `type`=1); -- Sandals of the Elder Sage
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88866 AND `ExtendedCost`=0 AND `type`=1); -- Steps of the War Serpent
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88865 AND `ExtendedCost`=0 AND `type`=1); -- Bramblestaff Boots
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88864 AND `ExtendedCost`=0 AND `type`=1); -- Yu'lon Guardian Boots
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=88862 AND `ExtendedCost`=0 AND `type`=1); -- Tankiss Warstompers
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89659 AND `ExtendedCost`=0 AND `type`=1); -- Leggings of Unfinished Conquest
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89658 AND `ExtendedCost`=0 AND `type`=1); -- Subversive Leggings
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89665 AND `ExtendedCost`=0 AND `type`=1); -- Leggings of Ponderous Advance
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89664 AND `ExtendedCost`=0 AND `type`=1); -- Valiant's Shinguards
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89537 AND `ExtendedCost`=0 AND `type`=1); -- Cloak of the Silent Mountain
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89535 AND `ExtendedCost`=0 AND `type`=1); -- Ribcracker's Cloak
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89534 AND `ExtendedCost`=0 AND `type`=1); -- Pressed Flower Cloak
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89533 AND `ExtendedCost`=0 AND `type`=1); -- Cloak of Ancient Curses
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89532 AND `ExtendedCost`=0 AND `type`=1); -- Bladesong Cloak
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89669 AND `ExtendedCost`=0 AND `type`=1); -- Undergrowth Stalker Chestpiece
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89668 AND `ExtendedCost`=0 AND `type`=1); -- Mountain Stream Ringmail
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89667 AND `ExtendedCost`=0 AND `type`=1); -- Refurbished Zandalari Vestment
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89666 AND `ExtendedCost`=0 AND `type`=1); -- Vestment of the Ascendant Tribe
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89124 AND `ExtendedCost`=0 AND `type`=1); -- Celestial Offering
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=93224 AND `ExtendedCost`=0 AND `type`=1); -- Grand Commendation of the August Celestials
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=89799 AND `ExtendedCost`=0 AND `type`=1); -- August Celestials Tabard
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=64001 AND `item`=86377 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Royal Satchel
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=76734 AND `ExtendedCost`=3901 AND `type`=1); -- Serpent's Eye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=79101 AND `ExtendedCost`=3901 AND `type`=1); -- Prismatic Scale
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72120 AND `ExtendedCost`=3901 AND `type`=1); -- Exotic Leather
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72103 AND `ExtendedCost`=3901 AND `type`=1); -- White Trillium Ore
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72094 AND `ExtendedCost`=3901 AND `type`=1); -- Black Trillium Ore
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72093 AND `ExtendedCost`=3901 AND `type`=1); -- Kyparite
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72092 AND `ExtendedCost`=3901 AND `type`=1); -- Ghost Iron Ore
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74247 AND `ExtendedCost`=3901 AND `type`=1); -- Ethereal Shard
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74250 AND `ExtendedCost`=3901 AND `type`=1); -- Mysterious Essence
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74249 AND `ExtendedCost`=3901 AND `type`=1); -- Spirit Dust
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72238 AND `ExtendedCost`=3901 AND `type`=1); -- Golden Lotus
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=89610 AND `ExtendedCost`=3901 AND `type`=1); -- Pandaria Herbs
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72988 AND `ExtendedCost`=3901 AND `type`=1); -- Windwool Cloth
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=79255 AND `ExtendedCost`=3901 AND `type`=1); -- Starlight Ink
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=402 AND `ExtendedCost`=3901 AND `type`=2); -- 402
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=76734 AND `ExtendedCost`=3901 AND `type`=1); -- Serpent's Eye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=79101 AND `ExtendedCost`=3901 AND `type`=1); -- Prismatic Scale
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72120 AND `ExtendedCost`=3901 AND `type`=1); -- Exotic Leather
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72103 AND `ExtendedCost`=3901 AND `type`=1); -- White Trillium Ore
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72094 AND `ExtendedCost`=3901 AND `type`=1); -- Black Trillium Ore
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72093 AND `ExtendedCost`=3901 AND `type`=1); -- Kyparite
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72092 AND `ExtendedCost`=3901 AND `type`=1); -- Ghost Iron Ore
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74247 AND `ExtendedCost`=3901 AND `type`=1); -- Ethereal Shard
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74250 AND `ExtendedCost`=3901 AND `type`=1); -- Mysterious Essence
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=74249 AND `ExtendedCost`=3901 AND `type`=1); -- Spirit Dust
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72238 AND `ExtendedCost`=3901 AND `type`=1); -- Golden Lotus
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=89610 AND `ExtendedCost`=3901 AND `type`=1); -- Pandaria Herbs
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=72988 AND `ExtendedCost`=3901 AND `type`=1); -- Windwool Cloth
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=79255 AND `ExtendedCost`=3901 AND `type`=1); -- Starlight Ink
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=66685 AND `item`=402 AND `ExtendedCost`=3901 AND `type`=2); -- 402

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=66232 AND `ID`=1) OR (`CreatureID`=58464 AND `ID` IN (5,4)) OR (`CreatureID`=59826 AND `ID`=2);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(66232, 1, 2202, 0, 0, 0, 0, 0, 0, 0, 0), -- Puya
(58464, 5, 14879, 0, 0, 0, 0, 0, 0, 0, 0), -- Golden Lotus Warrior
(58464, 4, 12937, 0, 0, 0, 0, 0, 0, 0, 0), -- Golden Lotus Warrior
(59826, 2, 5956, 0, 0, 0, 0, 0, 0, 0, 0); -- -Unknown-

UPDATE `creature_equip_template` SET `ItemID1`=2023 WHERE (`CreatureID`=58464 AND `ID`=3); -- Golden Lotus Warrior
UPDATE `creature_equip_template` SET `ItemID1`=6680 WHERE (`CreatureID`=58464 AND `ID`=2); -- Golden Lotus Warrior
UPDATE `creature_equip_template` SET `ItemID1`=81358 WHERE (`CreatureID`=58464 AND `ID`=1); -- Golden Lotus Warrior
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=61488 AND `ID`=1); -- -Unknown-

DELETE FROM `gossip_menu` WHERE (`MenuId`=14338 AND `TextId`=20245) OR (`MenuId`=14543 AND `TextId`=20565) OR (`MenuId`=14682 AND `TextId`=11714) OR (`MenuId`=14865 AND `TextId`=21026) OR (`MenuId`=14854 AND `TextId`=21012);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(14338, 20245, 38134), -- 64001 (Sage Lotusbloom)
(14543, 20565, 38134), -- 64534 (Bowmaster Ku)
(14682, 11714, 38134), -- 62996 (Madam Vee Luo)
(14865, 21026, 38134), -- 63535
(14854, 21012, 38134); -- 63751

DELETE FROM `areatrigger_template` WHERE `Id`=10665;
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(10665, 1, 0, 0, 6, 6, 0, 0, 0, 0, 38134);

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12499 AND `AreaTriggerId`=17182); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12499 AND `AreaTriggerId`=17182); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12499 AND `AreaTriggerId`=17182); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12499 AND `AreaTriggerId`=17182); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=43, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=7363 AND `AreaTriggerId`=12515); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (6785,6729,9485));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(6785, 0, 0, 38134),
(6729, 0, 0, 38134), -- Full: 0x2016E4CD408198000010A10000771853 Creature/0 R1465/S4257 Map: 1642 (Zandalar) Entry: 132704 Low: 7805011
(9485, 0, 0, 38134); -- Full: 0x2016E4CD408B50400010A100007E66DC Creature/0 R1465/S4257 Map: 1642 (Zandalar) Entry: 142657 (Loa Speaker Chel'ra) Low: 8283868


DELETE FROM `conversation_line_template` WHERE `Id` IN (15477, 15348, 21519, 21518, 21517, 21516, 21515, 21514);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(15477, 0, 1062, 0, 0, 38134),
(15348, 0, 0, 0, 0, 38134),
(21519, 24650, 0, 0, 0, 38134),
(21518, 17950, 0, 0, 0, 38134),
(21517, 11000, 0, 0, 0, 38134),
(21516, 7850, 0, 0, 0, 38134),
(21515, 4900, 0, 0, 0, 38134),
(21514, 0, 0, 0, 0, 38134);

UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11400;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11399;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14653;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14652;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14648;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14647;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15239;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15238;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15448;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15467;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15466;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18758;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15231;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15230;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15559;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15558;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15470;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15455;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15454;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15380;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=16764;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14518;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14432;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15377;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15376;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15233;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15232;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14734;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14730;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15460;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14731;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15459;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15458;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15449;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15476;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15475;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15474;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15473;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15472;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14729;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14732;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11726;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11725;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14727;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=19800;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14748;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15465;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14728;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13067;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13066;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13065;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13064;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15479;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15478;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=19498;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=19497;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15469;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15468;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15461;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14737;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14736;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14735;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14651;

DELETE FROM `conversation_template` WHERE `Id` IN (6785, 9485, 6729);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(6785, 15477, 8548, 0, 38134),
(9485, 21514, 30500, 0, 38134),
(6729, 15348, 2100, 0, 38134);



UPDATE `conversation_template` SET `LastLineEndTime`=7150, `VerifiedBuild`=38134 WHERE `Id`=5097;
UPDATE `conversation_template` SET `LastLineEndTime`=8000, `VerifiedBuild`=38134 WHERE `Id`=5248;
UPDATE `conversation_template` SET `LastLineEndTime`=6050, `VerifiedBuild`=38134 WHERE `Id`=8710;
UPDATE `conversation_template` SET `LastLineEndTime`=15800, `VerifiedBuild`=38134 WHERE `Id`=5831;
UPDATE `conversation_template` SET `LastLineEndTime`=8000, `VerifiedBuild`=38134 WHERE `Id`=8808;
UPDATE `conversation_template` SET `LastLineEndTime`=25950, `VerifiedBuild`=38134 WHERE `Id`=6784;
UPDATE `conversation_template` SET `LastLineEndTime`=6750, `VerifiedBuild`=38134 WHERE `Id`=6786;
UPDATE `conversation_template` SET `LastLineEndTime`=5300, `VerifiedBuild`=38134 WHERE `Id`=6783;
UPDATE `conversation_template` SET `LastLineEndTime`=6950, `VerifiedBuild`=38134 WHERE `Id`=6782;
UPDATE `conversation_template` SET `LastLineEndTime`=2150, `VerifiedBuild`=38134 WHERE `Id`=6779;
UPDATE `conversation_template` SET `LastLineEndTime`=11500, `VerifiedBuild`=38134 WHERE `Id`=6815;
UPDATE `conversation_template` SET `LastLineEndTime`=9600, `VerifiedBuild`=38134 WHERE `Id`=6778;
UPDATE `conversation_template` SET `LastLineEndTime`=3700, `VerifiedBuild`=38134 WHERE `Id`=6773;
UPDATE `conversation_template` SET `LastLineEndTime`=6200, `VerifiedBuild`=38134 WHERE `Id`=6772;
UPDATE `conversation_template` SET `LastLineEndTime`=10900, `VerifiedBuild`=38134 WHERE `Id`=6745;
UPDATE `conversation_template` SET `LastLineEndTime`=7750, `VerifiedBuild`=38134 WHERE `Id`=6743;
UPDATE `conversation_template` SET `LastLineEndTime`=15828, `VerifiedBuild`=38134 WHERE `Id`=6781;
UPDATE `conversation_template` SET `LastLineEndTime`=1739, `VerifiedBuild`=38134 WHERE `Id`=6510;
UPDATE `conversation_template` SET `LastLineEndTime`=16706, `VerifiedBuild`=38134 WHERE `Id`=6504;
UPDATE `conversation_template` SET `LastLineEndTime`=2449, `VerifiedBuild`=38134 WHERE `Id`=6503;
UPDATE `conversation_template` SET `LastLineEndTime`=11111, `VerifiedBuild`=38134 WHERE `Id`=6502;
UPDATE `conversation_template` SET `LastLineEndTime`=7940, `VerifiedBuild`=38134 WHERE `Id`=6501;
UPDATE `conversation_template` SET `LastLineEndTime`=2431, `VerifiedBuild`=38134 WHERE `Id`=6499;
UPDATE `conversation_template` SET `LastLineEndTime`=7466, `VerifiedBuild`=38134 WHERE `Id`=6500;
UPDATE `conversation_template` SET `LastLineEndTime`=16235, `VerifiedBuild`=38134 WHERE `Id`=6477;
UPDATE `conversation_template` SET `LastLineEndTime`=3947, `VerifiedBuild`=38134 WHERE `Id`=6476;
UPDATE `conversation_template` SET `LastLineEndTime`=14247, `VerifiedBuild`=38134 WHERE `Id`=6473;
UPDATE `conversation_template` SET `LastLineEndTime`=9894, `VerifiedBuild`=38134 WHERE `Id`=6776;
UPDATE `conversation_template` SET `LastLineEndTime`=11800, `VerifiedBuild`=38134 WHERE `Id`=6681;
UPDATE `conversation_template` SET `LastLineEndTime`=8000, `VerifiedBuild`=38134 WHERE `Id`=6678;
UPDATE `conversation_template` SET `LastLineEndTime`=13750, `VerifiedBuild`=38134 WHERE `Id`=6677;
UPDATE `conversation_template` SET `LastLineEndTime`=11009, `VerifiedBuild`=38134 WHERE `Id`=6402;

DELETE FROM `gameobject_template_addon` WHERE `entry`=281176;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(281176, 0, 2113536, 2437, 0); -- Jani's Stash

UPDATE `gameobject_template_addon` SET `flags`=50 WHERE `entry`=270881; -- Gate
UPDATE `gameobject_template_addon` SET `flags`=50 WHERE `entry`=269938; -- Gate
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8870 WHERE `entry`=281173; -- Mysterious Trashpile
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=7337 WHERE `entry`=270040; -- Nearly-hatching Pterrordax Egg
UPDATE `gameobject_template_addon` SET `flags`=262145 WHERE `entry`=279354; -- Mysterious Brew
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=6974 WHERE `entry`=279242; -- [DNT] Whetstone
UPDATE `gameobject_template_addon` SET `flags`=262145 WHERE `entry`=290747; -- Jambani Stockpile
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=278713; -- Treasure Chest

UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48581; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48581; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48581; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47261; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47418; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=51990; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=51998; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47311; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47311; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47311; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47272; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=51980; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47312; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48527; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47259; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47226; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47226; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=50538; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=50297; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49870; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=50268; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=50252; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=50150; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=50074; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=50154; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49814; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49801; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49905; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49905; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49495; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=51663; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49494; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49493; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49492; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49492; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49489; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49489; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49490; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49491; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49810; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49488; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49488; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47435; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47434; -- -Unknown-

DELETE FROM `quest_poi` WHERE (`QuestID`=47310 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47310 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47310 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=31459 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(47310, 0, 2, 32, 0, 0, 1642, 862, 0, 0, 0, 0, 0, 1312598, 0, 38134), -- -Unknown-
(47310, 0, 1, 0, 290844, 123677, 1642, 862, 0, 0, 0, 0, 0, 1337080, 0, 38134), -- -Unknown-
(47310, 0, 0, -1, 0, 0, 1642, 862, 0, 0, 0, 0, 0, 1312598, 0, 38134), -- -Unknown-
(31459, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48581 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48581 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48581 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47418 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47418 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47418 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51980 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51980 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51980 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47312 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47312 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47312 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47226 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47226 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50538 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50538 AND `BlobIndex`=2 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50538 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50538 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50297 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50297 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50297 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50297 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50268 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50268 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50268 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50252 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50252 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50252 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50252 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50074 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50074 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50074 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50150 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50150 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50150 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49663 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49663 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49905 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49905 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49905 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49494 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49494 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49494 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49810 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49810 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49810 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49810 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=47310 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47310 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47310 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=31459 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(47310, 2, 0, -1015, 57, 279, 38134), -- -Unknown-
(47310, 1, 0, -992, -64, 251, 38134), -- -Unknown-
(47310, 0, 0, -1015, 57, 279, 38134), -- -Unknown-
(31459, 0, 0, 3044, 1251, 655, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48581 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48581 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48581 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47261 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47418 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47418 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47418 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51998 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51990 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51980 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51980 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51980 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47312 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47312 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47312 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47272 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47311 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48527 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47259 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47226 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47226 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50538 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50538 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50538 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50538 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50297 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50297 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50297 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50297 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49870 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50268 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50268 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50268 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50252 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50252 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50252 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50252 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50074 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50074 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50074 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50150 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50150 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50150 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49663 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49663 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49905 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49905 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49905 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49495 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51663 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49494 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49494 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49494 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49493 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49492 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49801 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50154 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49814 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49810 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49810 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49810 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49810 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49491 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49490 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49489 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47435 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47434 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-


UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=125486 AND `Type`=0); -- 125486
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=125486 AND `Type`=0); -- 125486
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907
UPDATE `quest_greeting` SET `VerifiedBuild`=38134 WHERE (`ID`=129907 AND `Type`=0); -- 129907

DELETE FROM `quest_details` WHERE `ID` IN (31034 /*-Unknown-*/, 26642 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(31034, 15, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(26642, 2, 1, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47310; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48581; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47261; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47418; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51998; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51990; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51980; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47312; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47312; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47272; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47272; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47311; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48527; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47259; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47226; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50538; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50297; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49870; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50268; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50252; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50074; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50150; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49663; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49905; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49495; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51663; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49494; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49493; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49492; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49801; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50154; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49814; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49810; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49491; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49490; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49489; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47437; -- -Unknown-


UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=49491; -- -Unknown-

UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245461 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245461 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=249906 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245714 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245695 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=243881 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245462 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245460 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245450 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=251397 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245436 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=245433 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=281189 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=1445.2099609375, `PositionY`=-4499.56005859375, `PositionZ`=18.30999946594238281, `VerifiedBuild`=38134 WHERE (`ID`=3567 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=261481 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-11.109999656677246, `PositionY`=6746.18994140625, `VerifiedBuild`=38134 WHERE (`ID`=296901 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (151241 /*151241 (Follow the spirit)*/, 133354 /*133354 (Jani)*/, 149147 /*149147 (N'chala the Egg Thief)*/, 148517 /*148517 (Baby Zandalari Raptor)*/, 139180 /*139180 (Sornoth Slagmane)*/, 136152 /*136152 (7th Legion Scout)*/, 150412 /*150412 (Inert Voodoo Mask) - Inert Voodoo Mask Aura, Inert Golem Stun*/, 136009 /*136009 (7th Legion Marine)*/, 147641 /*147641*/, 147642 /*147642*/, 152020 /*152020*/, 154609 /*154609*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(151241, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 151241 (Follow the spirit)
(133354, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133354 (Jani)
(149147, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 149147 (N'chala the Egg Thief)
(148517, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 148517 (Baby Zandalari Raptor)
(139180, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 139180 (Sornoth Slagmane)
(136152, 0, 0, 0, 258, 0, 0, 0, 0, ''), -- 136152 (7th Legion Scout)
(150412, 0, 0, 0, 1, 0, 15263, 0, 0, '291587 282764'), -- 150412 (Inert Voodoo Mask) - Inert Voodoo Mask Aura, Inert Golem Stun
(136009, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 136009 (7th Legion Marine)
(147641, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 147641
(147642, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147642
(152020, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 152020
(154609, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 154609

UPDATE `creature_template_addon` SET `auras`='35356' WHERE `entry`=126733; -- 126733 (Rezani Handler)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=122224; -- 122224 (Direhorn Bull)
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry`=139440; -- 139440 (Jabra'kan the Poacher)
UPDATE `creature_template_addon` SET `auras`='297112' WHERE `entry`=122107; -- 122107 (Brutosaur)
UPDATE `creature_template_addon` SET `auras`='263057' WHERE `entry`=133910; -- 133910 (Lil' Stompy)
UPDATE `creature_template_addon` SET `bytes2`=256, `auras`='256129' WHERE `entry`=125783; -- 125783 (Apprentice Beastcaller)
UPDATE `creature_template_addon` SET `mount`=48100 WHERE `entry`=131006; -- 131006
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=139634; -- 139634
UPDATE `creature_template_addon` SET `aiAnimKit`=2194 WHERE `entry`=142642; -- 142642
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=130242; -- 130242
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=120900; -- 120900
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=132097; -- 132097
UPDATE `creature_template_addon` SET `auras`='61854 61853' WHERE `entry`=71942; -- 71942 (Xu-Fu, Cub of Xuen)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=132085; -- 132085 (Lofty Libram)
UPDATE `creature_template_addon` SET `auras`='260010' WHERE `entry`=133549; -- 133549
UPDATE `creature_template_addon` SET `auras`='130800 114657' WHERE `entry`=63621; -- 63621 (Feral Vermling)
UPDATE `creature_template_addon` SET `bytes2`=256, `auras`='' WHERE `entry`=132082; -- 132082
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=133065; -- 133065
UPDATE `creature_template_addon` SET `aiAnimKit`=1652 WHERE `entry`=131832; -- 131832 (Tiny Sleeping Ben'jin)
UPDATE `creature_template_addon` SET `auras`='151597' WHERE `entry`=131560; -- 131560 (Feral Ravasaur)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=125253; -- 125253
UPDATE `creature_template_addon` SET `auras`='259221 272314' WHERE `entry`=138408; -- 138408 (Mindslaved Berserker)
UPDATE `creature_template_addon` SET `aiAnimKit`=13413 WHERE `entry`=130305; -- 130305 (Fist of Vol'jamba)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=131044; -- 131044 (Gurubashi Sacrifice)
UPDATE `creature_template_addon` SET `auras`='257998' WHERE `entry`=129752; -- 129752 (Mindslaved Gurubashi)
UPDATE `creature_template_addon` SET `aiAnimKit`=947 WHERE `entry`=130197; -- 130197 (Spite of Vol'jamba)
UPDATE `creature_template_addon` SET `aiAnimKit`=14420 WHERE `entry`=129924; -- 129924 (Atal'jamba Iri)
UPDATE `creature_template_addon` SET `auras`='196285 145953' WHERE `entry`=126725; -- 126725 (Elder Diemetradon)
UPDATE `creature_template_addon` SET `auras`='196285 145953' WHERE `entry`=126726; -- 126726 (Young Diemetradon)
UPDATE `creature_template_addon` SET `auras`='250946' WHERE `entry`=125414; -- 125414 (Spiny Gekkota)
UPDATE `creature_template_addon` SET `auras`='162908' WHERE `entry`=129954; -- 129954 (Gahz'ralka)
UPDATE `creature_template_addon` SET `aiAnimKit`=4828 WHERE `entry`=130929; -- 130929 (Witch Doctor Jangalar)
UPDATE `creature_template_addon` SET `aiAnimKit`=947 WHERE `entry`=130698; -- 130698 ([DNT] Mask)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=130575; -- 130575
UPDATE `creature_template_addon` SET `auras`='259954' WHERE `entry`=131774; -- 131774
UPDATE `creature_template_addon` SET `auras`='256130' WHERE `entry`=129329; -- 129329
UPDATE `creature_template_addon` SET `aiAnimKit`=14635 WHERE `entry`=131659; -- 131659
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=133248; -- 133248
UPDATE `creature_template_addon` SET `auras`='259920' WHERE `entry`=131746; -- 131746
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='130966' WHERE `entry`=127030; -- 127030
UPDATE `creature_template_addon` SET `auras`='243129' WHERE `entry`=138274; -- 138274
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=126623; -- 126623
UPDATE `creature_template_addon` SET `aiAnimKit`=14580 WHERE `entry`=131164; -- 131164
UPDATE `creature_template_addon` SET `mount`=47238 WHERE `entry`=131007; -- 131007
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='270114' WHERE `entry`=132394; -- 132394
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=132687; -- 132687
UPDATE `creature_template_addon` SET `mount`=48100 WHERE `entry`=130995; -- 130995
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=132689; -- 132689
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=132690; -- 132690
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142567; -- 142567
UPDATE `creature_template_addon` SET `auras`='281448' WHERE `entry`=122701; -- 122701
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=40891; -- 40891
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=149522; -- 149522
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=14376; -- 14376
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=141912; -- 141912
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=0 WHERE `entry`=25080; -- 25080
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=45230; -- 45230
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=24929; -- 24929
UPDATE `creature_template_addon` SET `auras`='79865' WHERE `entry`=46716; -- 46716
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=43062; -- 43062
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=3329; -- 3329
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=72559; -- 72559
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=88701; -- 88701
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=141119; -- 141119
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=74228; -- 74228


UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126736 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126732 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126733 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121866 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121854 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122267 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123656 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123215 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=125833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126775 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=139643 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=139703 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=139706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=151241 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134066 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=142151 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131718 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133854 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133857 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=139640 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=139440 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=149147 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130778 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130777 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=139365 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130771 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=148517 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=134619 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=122504 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=139326 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133871 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=125486 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126714 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122402 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122129 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126509 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135249 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122399 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133910 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126562 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126597 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122059 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122447 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=123060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140305 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122445 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140285 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=125783 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140287 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=139180 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136152 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=292, `VerifiedBuild`=38134 WHERE (`Entry`=150412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=136009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130589 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131006 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132641 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=120174 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132715 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132639 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130122 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132640 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129998 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131346 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142671 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142663 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142657 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142751 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132305 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=132089 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140445 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=73668 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131734 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140416 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=196, `VerifiedBuild`=38134 WHERE (`Entry`=93432 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140411 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140422 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140418 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133237 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=77221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=68659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132112 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132083 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=33810 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=66950 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132097 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=64899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=71942 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=132085 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=33227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132103 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=54227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133238 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=82464 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=53225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132106 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=81431 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63621 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=34278 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=48609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132082 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=115152 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=15699 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=147641 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=147642 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132110 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=14629 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132109 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132111 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=132077 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=85517 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133065 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133119 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133371 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133300 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131808 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133366 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123062 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122939 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=139312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=125784 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=3, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129606 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=139311 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131555 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133152 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132628 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132629 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131832 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122940 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133321 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131560 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138408 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138409 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131241 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130304 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130305 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130294 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131219 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123502 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131218 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130260 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132213 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131044 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129752 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130197 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130866 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130208 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129924 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138399 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130219 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126653 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130922 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126722 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126725 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126726 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130921 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=125417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122113 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133167 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133563 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=125414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122223 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130308 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129720 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129954 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129487 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130029 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130707 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130905 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130929 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=133420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130698 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130344 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130035 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130451 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134156 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130034 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132070 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136425 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128933 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132072 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132067 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=152020 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=154609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130713 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130741 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130754 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130756 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130753 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130761 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131753 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130712 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134018 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134017 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130710 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130718 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130749 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130447 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130489 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130577 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133735 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131769 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131768 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141614 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131765 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131767 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130575 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126330 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127072 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129329 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=124040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141957 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129597 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129595 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131741 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126564 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133248 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131746 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141628 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141617 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=130988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=130990 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128150 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126329 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128148 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=130987 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129300 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138274 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126304 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126623 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131164 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131162 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128077 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126618 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127665 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131745 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131170 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128076 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126331 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141956 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140870 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=140869 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=140868 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141954 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122698 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137234 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132686 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137237 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132983 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132984 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141936 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122700 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=130995 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=132711 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132707 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132691 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131574 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132690 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132704 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=132714 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131835 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131403 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132301 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131811 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127123 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131827 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131813 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132012 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=122231 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132296 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=144082 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=144085 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=144078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=144074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131836 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=141912 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=141920 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61367 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=79530;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79531;
UPDATE `creature_model_info` SET `BoundingRadius`=0.026250001043081283, `CombatReach`=0.075000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=86530;
UPDATE `creature_model_info` SET `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=86474;
UPDATE `creature_model_info` SET `BoundingRadius`=2.5, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82974;
UPDATE `creature_model_info` SET `BoundingRadius`=1.299999952316284179, `CombatReach`=7.799999713897705078, `VerifiedBuild`=38134 WHERE `DisplayID`=47234;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83198;
UPDATE `creature_model_info` SET `BoundingRadius`=1.806656956672668457, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=83129;
UPDATE `creature_model_info` SET `BoundingRadius`=1.806656956672668457, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=82313;
UPDATE `creature_model_info` SET `BoundingRadius`=1.317241787910461425, `CombatReach`=1.609999895095825195, `VerifiedBuild`=38134 WHERE `DisplayID`=69809;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520833015441894531, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=86300;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413480490446090698, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=81218;
UPDATE `creature_model_info` SET `BoundingRadius`=0.026250001043081283, `CombatReach`=0.075000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=86533;
UPDATE `creature_model_info` SET `BoundingRadius`=2.763052701950073242, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=83649;
UPDATE `creature_model_info` SET `BoundingRadius`=2.502509117126464843, `CombatReach`=4.800000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=77630;
UPDATE `creature_model_info` SET `BoundingRadius`=0.720405757427215576, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=90027;
UPDATE `creature_model_info` SET `BoundingRadius`=0.720405757427215576, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=90031;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78131;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83208;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=9.600000381469726562, `VerifiedBuild`=38134 WHERE `DisplayID`=86283;
UPDATE `creature_model_info` SET `BoundingRadius`=2.378643512725830078, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=83626;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=31288;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=31482;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=74881;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47935;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=76568;
UPDATE `creature_model_info` SET `BoundingRadius`=3.613313913345336914, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=76655;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76972;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83182;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84038;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16357;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83181;
UPDATE `creature_model_info` SET `BoundingRadius`=2.378643512725830078, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=83627;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83183;
UPDATE `creature_model_info` SET `BoundingRadius`=4.516642093658447265, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76660;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `CombatReach`=3.60000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=47933;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=76567;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19283;
UPDATE `creature_model_info` SET `BoundingRadius`=2.392235517501831054, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=76481;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=9, `VerifiedBuild`=38134 WHERE `DisplayID`=47236;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=79542;
UPDATE `creature_model_info` SET `BoundingRadius`=0.364583075046539306, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=79534;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79581;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79582;
UPDATE `creature_model_info` SET `BoundingRadius`=3.01109480857849121, `CombatReach`=5 WHERE `DisplayID`=76658;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79533;
UPDATE `creature_model_info` SET `BoundingRadius`=0.434027493000030517, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=76502;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79532;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=79529;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=79526;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79528;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86177;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84618;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84617;
UPDATE `creature_model_info` SET `BoundingRadius`=0.234999999403953552, `VerifiedBuild`=38134 WHERE `DisplayID`=91019;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85767;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121 WHERE `DisplayID`=78161;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=28260;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81006;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81067;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82597;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82601;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87887;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87889;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87878;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82602;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87888;
UPDATE `creature_model_info` SET `BoundingRadius`=0.08749999850988388, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=14657;
UPDATE `creature_model_info` SET `BoundingRadius`=0.167755126953125, `CombatReach`=0.559183716773986816, `VerifiedBuild`=38134 WHERE `DisplayID`=58930;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82829;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79527;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75961;
UPDATE `creature_model_info` SET `BoundingRadius`=0.364583075046539306, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=79535;
UPDATE `creature_model_info` SET `BoundingRadius`=8.286098480224609375, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=60286;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82521;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82522;
UPDATE `creature_model_info` SET `BoundingRadius`=2.283836126327514648, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=82077;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79554;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79553;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81897;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58978;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59831;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60715;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61080;
UPDATE `creature_model_info` SET `BoundingRadius`=0.45138859748840332, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=81111;
UPDATE `creature_model_info` SET `BoundingRadius`=3, `CombatReach`=9, `VerifiedBuild`=38134 WHERE `DisplayID`=47511;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=81071;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81073;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81072;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81075;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81112;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81558;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81446;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81445;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81559;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81547;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81074;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81556;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=46565;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79085;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=8512;
UPDATE `creature_model_info` SET `BoundingRadius`=6.851508140563964843, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=81484;
UPDATE `creature_model_info` SET `BoundingRadius`=3.033923625946044921, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=13210;
UPDATE `creature_model_info` SET `BoundingRadius`=4.550885200500488281, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=79075;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68139;
UPDATE `creature_model_info` SET `BoundingRadius`=6.851508140563964843, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=81483;
UPDATE `creature_model_info` SET `BoundingRadius`=0.262499988079071044, `CombatReach`=0.375, `VerifiedBuild`=38134 WHERE `DisplayID`=4268;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82314;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216573551297187805, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=36599;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82741;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47233;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80685;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37888;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81552;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37889;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81546;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80683;
UPDATE `creature_model_info` SET `BoundingRadius`=4.357944488525390625, `CombatReach`=8.75, `VerifiedBuild`=38134 WHERE `DisplayID`=58892;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80682;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37894;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37895;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81557;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81488;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81545;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81241;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81242;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81549;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81240;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81554;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80311;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81553;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80684;
UPDATE `creature_model_info` SET `BoundingRadius`=3.180323123931884765, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=22353;
UPDATE `creature_model_info` SET `BoundingRadius`=1.937266349792480468, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=32649;
UPDATE `creature_model_info` SET `BoundingRadius`=0.564377963542938232, `CombatReach`=1.5 WHERE `DisplayID`=86801;
UPDATE `creature_model_info` SET `BoundingRadius`=0.564377963542938232, `CombatReach`=1.5 WHERE `DisplayID`=86800;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5 WHERE `DisplayID`=77687;
UPDATE `creature_model_info` SET `BoundingRadius`=4.036835670471191406, `CombatReach`=3 WHERE `DisplayID`=47620;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90304;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87513;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=34059;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=2956;
UPDATE `creature_model_info` SET `BoundingRadius`=0.974611639976501464, `CombatReach`=1.980000019073486328 WHERE `DisplayID`=14732;

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (136152,136009));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(136152, 1, 0, 0, 0, 0, 0, 0, 37249, 0, 0), -- 7th Legion Scout
(136009, 1, 1493, 0, 0, 143, 0, 0, 2552, 0, 0); -- 7th Legion Marine


DELETE FROM `gossip_menu` WHERE (`MenuId`=22146 AND `TextId`=33926);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(22146, 33926, 38134); -- 133354 (Jani)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21093 AND `TextId`=31977); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21093 AND `TextId`=31977); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21074 AND `TextId`=31922); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21074 AND `TextId`=31922); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21074 AND `TextId`=31922); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21074 AND `TextId`=31922); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21074 AND `TextId`=31922); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21933 AND `TextId`=33493); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21933 AND `TextId`=33493); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22097 AND `TextId`=33836); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22096 AND `TextId`=33835); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21905 AND `TextId`=33834); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22099 AND `TextId`=33839); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22098 AND `TextId`=33838); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21906 AND `TextId`=33837); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21906 AND `TextId`=33490); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21906 AND `TextId`=33490); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21906 AND `TextId`=33490); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21492 AND `TextId`=32741); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21492 AND `TextId`=32741); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21492 AND `TextId`=32741); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21951 AND `TextId`=33584); -- 0
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=22146 AND `OptionIndex` IN (1,0));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(22146, 1, 0, 'I have a shiny trinket for you, Jani.', 146770, 38134),
(22146, 0, 0, 'Release me.', 137226, 38134);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=131172, `VerifiedBuild`=38134 WHERE (`MenuId`=21093 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=131172, `VerifiedBuild`=38134 WHERE (`MenuId`=21093 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21933 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21933 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=146245, `VerifiedBuild`=38134 WHERE (`MenuId`=22097 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=146242, `VerifiedBuild`=38134 WHERE (`MenuId`=22096 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=146241, `VerifiedBuild`=38134 WHERE (`MenuId`=21905 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=146254, `VerifiedBuild`=38134 WHERE (`MenuId`=22099 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=146253, `VerifiedBuild`=38134 WHERE (`MenuId`=22098 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=146252, `VerifiedBuild`=38134 WHERE (`MenuId`=21906 AND `OptionIndex`=0);

DELETE FROM `gossip_menu_option_action` WHERE (`OptionIndex`=0 AND `MenuId` IN (22096,21905,22098,21906));
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`) VALUES
(22096, 0, 22097),
(21905, 0, 22096),
(22098, 0, 22099),
(21906, 0, 22098);

UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126736; -- Kill Credit: Spanking
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `speed_walk`=2.40000009536743164, `speed_run`=1.428571462631225585, `RangeAttackTime`=0 WHERE `entry`=126732; -- Pinky
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126733; -- Rezani Handler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121866; -- Kill Credit: Training Course - Get Help
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121854; -- Kill Credit: Training Course - Escape out the North Gate
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122267; -- Kill Credit: Training Course Complete
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123656; -- Apprentice Beastcaller
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123634; -- Kill Credit: Training Course - Get Help 2
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123215; -- Rezani Handler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125833; -- Rezani Handler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126775; -- Kraal Master B'khor
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139643; -- Direhorn Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139703; -- Young Savagelands Devilsaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139706; -- Savagelands Devilsaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=151241; -- Follow the spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122060; -- Direhorn Cow
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134066; -- Direhorn Calf
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=25, `RangeAttackTime`=0 WHERE `entry`=142151; -- Jammer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=0 WHERE `entry`=122224; -- Direhorn Bull
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=131718; -- Bramblewing
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=133854; -- Wild Pterrorchick
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133857; -- Shadraspawn Lurker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139640; -- Direhorn Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139440; -- Jabra'kan the Poacher
UPDATE `creature_template` SET `gossip_menu_id`=22146, `minlevel`=50, `maxlevel`=50, `faction`=2028, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=133354; -- Jani
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=149147; -- N'chala the Egg Thief
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130778; -- Dazarian Lizard
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130777; -- Leafy Flutterwing
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139365; -- Queenfeather
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130771; -- Riverbeast Calf
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=148517; -- Baby Zandalari Raptor
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=134619; -- Savagemane Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2904, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=122504; -- Savagemane Ravasaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=139326; -- Invasive Eggsnatcher
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133871; -- [DNT] Raptor Egg
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125486; -- Wingrider Nivek
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122107; -- Brutosaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832, `unit_flags2`=2099200, `unit_flags3`=0 WHERE `entry`=126714; -- Juvenile Brutosaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122402; -- Brute Bodyguard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122129; -- Trader Alexxi Cruzpot
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126509; -- Pinky
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135249; -- Meatminder Teki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122399; -- Pig
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133910; -- Lil' Stompy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_walk`=1, `RangeAttackTime`=0, `unit_flags2`=67110912 WHERE `entry`=123677; -- Kill Credit: Naptime
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=126562; -- Irritable Diemetradon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126597; -- Dino Egg
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122059; -- Direhorn Juvenile
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121688; -- Old Scargiver
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122447; -- Kill Credit: Bush 01
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121680; -- Direhorn Hatchling
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=123060; -- Paku'ai Verraki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140305; -- Kraal Warhauler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122009; -- Kraal Master B'khor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=122445; -- Zandalari Pterrorwing
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122114; -- Pterrordax
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121706; -- Beastlord L'kala
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140285; -- Rez'caza
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125783; -- Apprentice Beastcaller
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140287; -- Barder Zitaki
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=139180; -- Sornoth Slagmane
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136152; -- 7th Legion Scout
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=150412; -- Inert Voodoo Mask
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=136009; -- 7th Legion Marine
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126655; -- Direhorn Juvenile
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130589; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=131006; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132641; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120174; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132715; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132639; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130122; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132640; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130014; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129998; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131346; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21413 WHERE `entry`=126003; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130242; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21413 WHERE `entry`=126004; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=0 WHERE `entry`=143967; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142671; -- Atal'Jani Ack'uff
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142663; -- Atal'Jani Niv'ek
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=142657; -- Loa Speaker Chel'ra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142655; -- Atal'Jani Reveler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142660; -- Gleeful Scamp
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142659; -- Boisterous Vagrant
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142751; -- Atal'Jani Buz'ack
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132305; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=132089; -- Wolpertinger
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140445; -- Beaker
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=73668; -- Bonkers
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140415; -- Kona
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131734; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140416; -- Bailey
UPDATE `creature_template` SET `minlevel`=30, `RangeAttackTime`=0 WHERE `entry`=93432; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140417; -- Bandit
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140413; -- Ashley
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140412; -- Evie
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140411; -- Smudge
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140414; -- Arashi
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140422; -- Nibbler
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140418; -- Piper
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140423; -- Slobberchops
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133237; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=77221; -- Iron Starlette
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=68659; -- Anubisath Idol
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132098; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=132112; -- Enchanted Pen
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132083; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=33810; -- Sen'jin Fetish
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=66950; -- Pandaren Water Spirit
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132097; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=64899; -- Mechanical Pandaren Dragonling
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=71942; -- Xu-Fu, Cub of Xuen
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=132085; -- Lofty Libram
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=33227; -- Enchanted Broom
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132103; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=54227; -- Nuts
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132084; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133238; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132107; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=82464; -- Elekk Plushie
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=53225; -- Pterrordax Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132106; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=81431; -- Teroclaw Hatchling
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=63621; -- Feral Vermling
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=34278; -- Withers
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=48609; -- Clockwork Gnome
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132082; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=115152; -- Wicked Soul
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=15699; -- Tranquil Mechanical Yeti
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147641; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147642; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=132110; -- Emerald Turtle
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=14629; -- Loggerhead Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132109; -- Tortollan Tamer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132111; -- Turquoise Turtle
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=132077; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=85517; -- Challenge Post
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133065; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133119; -- Golma
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133253; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132312; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133371; -- Gentle Ben'jin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133300; -- Gloomtail's Head
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131808; -- Cala Cruzpot
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133366; -- Witch Doctor Jangalar
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123062; -- Jes'tri
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122939; -- Direhorn Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139312; -- Feral Ravasaur
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=125784; -- Beastcaller Guardian
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=-10, `maxlevel`=-10, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=129606; -- Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139311; -- Handler Bazkoji
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=131555; -- Gloomtail
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=133152; -- Raging Ben'jin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132628; -- Voodoo Love Incense
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132629; -- Romantic Brutosaur Meal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131832; -- Tiny Sleeping Ben'jin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122940; -- Savagemane Ravasaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122400; -- Wingrider Bladeguard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=133321; -- Razorwing Defender
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=130568; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131560; -- Feral Ravasaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131558; -- Invasive Razorwing
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131554; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126731; -- Diemetradon Egg
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1665, `RangeAttackTime`=0, `unit_flags3`=0 WHERE `entry`=138408; -- Mindslaved Berserker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1665, `RangeAttackTime`=0, `unit_flags3`=0 WHERE `entry`=138409; -- Jambani Chosen
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags2`=34816, `unit_flags3`=1, `dynamicflags`=4 WHERE `entry`=131241; -- Vol'jamba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130304; -- Fury of Vol'jamba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130305; -- Fist of Vol'jamba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130294; -- Vol'jamba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131219; -- Gong
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=123502; -- King K'tal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131218; -- Urn of Voices
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131217; -- Urn of Voices
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132217; -- Bubbling Cauldron
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=130260; -- Zuvembi Brewer Zekal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132213; -- Weakened Sacrifice
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131044; -- Gurubashi Sacrifice
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129752; -- Mindslaved Gurubashi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130197; -- Spite of Vol'jamba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130866; -- Gurubashi Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130208; -- Eyes of Vol'jamba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130209; -- Voice of Vol'jamba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130221; -- Jambani Chosen
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=129924; -- Atal'jamba Iri
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138399; -- Jambani stockpiles burned
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130219; -- Mindslaved Berserker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126653; -- Hungry Saurid
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130922; -- Irritable Maka'fon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=126722; -- Diemetradon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126725; -- Elder Diemetradon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126726; -- Young Diemetradon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130921; -- Gentle Ben'jin
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=125417; -- Pygmy Anaconda
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=122113; -- Pterrordax Skyrender
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133167; -- Voodoo Cauldron
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=133563; -- Voodoo Spell Target
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=125414; -- Spiny Gekkota
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122223; -- Direhorn Cow
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130308; -- FX STalker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=129720; -- Atal'jamba Ungo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=129954; -- Gahz'ralka
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=129487; -- Jambani Crusher
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130029; -- Tal'gurub Villager
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130707; -- Loa Priestess Izita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130706; -- Izita's Spirit
UPDATE `creature_template` SET `gossip_menu_id`=22097, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130905; -- Cala Cruzpot
UPDATE `creature_template` SET `gossip_menu_id`=22099, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130929; -- Witch Doctor Jangalar
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=133420; -- Dazarian Toad
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=129907; -- Zul the Prophet
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130698; -- [DNT] Mask
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130344; -- Vol'jamba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130035; -- Tal'gurub Headhunter
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130451; -- Bladeguard Elite
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134156; -- Jambani Crusher
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130034; -- Tal'gurub Loa Priest
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129513; -- Jambani Spirit Twister
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130031; -- Tal'gurub Berserker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132070; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136425; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128933; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132071; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132072; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132067; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136424; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136423; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67110912 WHERE `entry`=152020; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67110912 WHERE `entry`=154609; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=130713; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=130741; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130757; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130754; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130756; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130753; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=130761; -- Diemetradon Egg
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=131753; -- Dark Iron Golem
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130712; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=134018; -- T'eem
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=134017; -- Le'xi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130743; -- Adolescent Direhorn
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130710; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=130718; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=130749; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130447; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130489; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130577; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=133735; -- Shadra Betrayer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131769; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131768; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141614; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131765; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131767; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130575; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126330; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131774; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=294912 WHERE `entry`=127072; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131696; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129329; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=124040; -- Caravan Brutosaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141957; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131660; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131659; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131655; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129597; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129595; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131741; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=126564; -- Hexlord Raal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133248; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131746; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=127030; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141628; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141617; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130988; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130990; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128078; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128150; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126329; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=127074; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128148; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130987; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129300; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138274; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126304; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127664; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126623; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131164; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131162; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128077; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126618; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126221; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=131007; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131173; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127665; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131745; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131170; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128076; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126331; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141956; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140870; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=140869; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=140868; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141954; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=147, `RangeAttackTime`=0 WHERE `entry`=122698; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137234; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132686; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137237; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132983; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141609; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132984; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141936; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=147, `RangeAttackTime`=0 WHERE `entry`=122700; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132687; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130995; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=132711; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132707; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132691; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131574; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132689; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132690; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132704; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=132714; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131835; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142567; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=131403; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142565; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132301; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131811; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127123; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131827; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131813; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132012; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122231; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132296; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144082; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144085; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122696; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144078; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122702; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144074; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131836; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21933 WHERE `entry`=131287; -- Natal'hakata
UPDATE `creature_template` SET `gossip_menu_id`=21951 WHERE `entry`=131443; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=141912; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141920; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=44743; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=61367; -- Water Snake
UPDATE `creature_template` SET `gossip_menu_id`=4342 WHERE `entry`=3310; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=46140; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=62114; -- Spiny Lizard
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=74228; -- -Unknown-

REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42548, 79276, 1, 0),
(129595, 224326, 1, 0),
(124040, 46598, 1, 0),
(133167, 262446, 1, 0),
(130197, 257988, 1, 0),
(132629, 261420, 1, 0),
(132628, 261418, 1, 0),
(133300, 262077, 1, 0),
(85517, 163778, 1, 0),
(140418, 224326, 1, 0),
(140414, 224326, 1, 0),
(140411, 224326, 1, 0),
(140412, 224326, 1, 0),
(140413, 224326, 1, 0),
(140417, 224326, 1, 0),
(140416, 224326, 1, 0),
(140415, 224326, 1, 0),
(134619, 264559, 1, 0),
(139640, 277560, 1, 0),
(139643, 243833, 1, 0);


UPDATE `quest_template` SET `RewardMoney`=12445, `RewardBonusMoney`=340, `FlagsEx`=2105408, `RewardFactionID1`=0, `VerifiedBuild`=38134 WHERE `ID`=47310; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=248880, `RewardBonusMoney`=3400, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48581; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=248880, `RewardBonusMoney`=3400, `RewardSpell`=281373, `FlagsEx`=2105410, `VerifiedBuild`=38134 WHERE `ID`=47261; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=12445, `RewardBonusMoney`=340, `FlagsEx`=2105408, `RewardFactionID1`=0, `VerifiedBuild`=38134 WHERE `ID`=47418; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=117960, `RewardBonusMoney`=2650, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=51998; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=117960, `RewardBonusMoney`=2650, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=51990; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=353880, `RewardBonusMoney`=4000, `FlagsEx`=2097216, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=51980; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=235920, `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47312; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=117960, `RewardBonusMoney`=2650, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47272; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=117960, `RewardBonusMoney`=2650, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47311; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=11795, `RewardBonusMoney`=330, `FlagsEx`=2105408, `RewardFactionID1`=0, `VerifiedBuild`=38134 WHERE `ID`=47226; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=111480, `RewardBonusMoney`=2550, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50297; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=222960, `RewardBonusMoney`=3200, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=49870; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=11150, `RewardBonusMoney`=320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50268; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27870, `RewardBonusMoney`=650, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50252; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=111480, `RewardBonusMoney`=2550, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50074; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=55740, `RewardBonusMoney`=1300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50150; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=222960, `RewardBonusMoney`=3200, `FlagsEx`=6291520, `VerifiedBuild`=38134 WHERE `ID`=49905; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=111480, `RewardBonusMoney`=2550, `FlagsEx`=6291520, `VerifiedBuild`=38134 WHERE `ID`=49495; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=105000, `RewardBonusMoney`=2460, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51663; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=210000, `RewardBonusMoney`=3150, `FlagsEx`=6291520, `VerifiedBuild`=38134 WHERE `ID`=49494; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=105000, `RewardBonusMoney`=2460, `FlagsEx`=6291520, `VerifiedBuild`=38134 WHERE `ID`=49493; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=52500, `RewardBonusMoney`=1260, `FlagsEx`=6291520, `VerifiedBuild`=38134 WHERE `ID`=49492; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=105000, `RewardBonusMoney`=2460, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49801; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=105000, `RewardBonusMoney`=2460, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49814; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=52500, `RewardBonusMoney`=1260, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49810; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=105000, `RewardBonusMoney`=2460, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=49491; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=105000, `RewardBonusMoney`=2460, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=49490; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=105000, `RewardBonusMoney`=2460, `FlagsEx`=6291520, `VerifiedBuild`=38134 WHERE `ID`=49489; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=10500, `RewardBonusMoney`=300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47105; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=210000, `RewardBonusMoney`=3150, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47437; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31034; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=49925, `RewardBonusMoney`=1200, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=32249; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31377; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31459; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31453; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31695; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31451; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=9985, `RewardBonusMoney`=300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31457; -- -Unknown-


UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290844; -- 290844
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292569; -- 292569
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290326; -- 290326
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290837; -- 290837
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290753; -- 290753
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290752; -- 290752
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290751; -- 290751
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290434; -- 290434
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290327; -- 290327
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337713; -- 337713
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337693; -- 337693
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337646; -- 337646
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290325; -- 290325
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290288; -- 290288
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290649; -- 290649
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=312143; -- 312143
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=312131; -- 312131
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=312086; -- 312086
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335395; -- 335395
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335394; -- 335394
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296838; -- 296838
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296853; -- 296853
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296795; -- 296795
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296794; -- 296794
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296055; -- 296055
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296660; -- 296660
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296659; -- 296659
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295611; -- 295611
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295596; -- 295596
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295609; -- 295609
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295601; -- 295601
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295600; -- 295600
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294956; -- 294956
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294955; -- 294955
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336652; -- 336652
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294946; -- 294946
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294944; -- 294944
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294890; -- 294890
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294889; -- 294889
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294888; -- 294888
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295291; -- 295291
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295398; -- 295398
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295369; -- 295369
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295368; -- 295368
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294711; -- 294711
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294707; -- 294707
UPDATE `quest_objectives` SET `Order`=2, `Flags`=24, `Description`='', `VerifiedBuild`=38134 WHERE `ID`=294803; -- 294803
UPDATE `quest_objectives` SET `Order`=1, `Flags`=24, `VerifiedBuild`=38134 WHERE `ID`=294802; -- 294802
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294709; -- 294709
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=289994; -- 289994
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292749; -- 292749
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292748; -- 292748
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292539; -- 292539


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290844 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292569 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290434 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290327 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337713 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337693 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337646 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290325 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290288 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290288 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290288 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290649 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290649 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290649 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=312143 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=312131 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=312086 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335395 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335394 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296838 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296853 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296795 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296794 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296055 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296660 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296659 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295611 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295596 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295609 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295601 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294956 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294955 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336652 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336652 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336652 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294946 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294946 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294944 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294944 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294890 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294889 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294888 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295398 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295369 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295368 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294707 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294707 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294707 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294803 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294803 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294802 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294802 AND `Index`=0);


UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131808; -- Cala Cruzpot
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130698; -- [DNT] Mask
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139640; -- Direhorn Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130706; -- Izita's Spirit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139643; -- Direhorn Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130707; -- Loa Priestess Izita
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=134066; -- Direhorn Calf
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131832; -- Tiny Sleeping Ben'jin
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=129606; -- Bwonsamdi
UPDATE `creature_template` SET `name`='Adolescent Direhorn', `HealthScalingExpansion`=7, `family`=138, `type`=1, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=130743; -- Adolescent Direhorn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122939; -- Direhorn Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122940; -- Savagemane Ravasaur
UPDATE `creature_template` SET `type_flags`=65537, `VerifiedBuild`=38134 WHERE `entry`=139703; -- Young Savagelands Devilsaur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139706; -- Savagelands Devilsaur
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=130771; -- Riverbeast Calf
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130777; -- Leafy Flutterwing
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130778; -- Dazarian Lizard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135249; -- Meatminder Teki
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=121854; -- Kill Credit: Training Course - Escape out the North Gate
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=14629; -- Loggerhead Snapjaw
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=121866; -- Kill Credit: Training Course - Get Help
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=134156; -- Jambani Crusher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129720; -- Atal'jamba Ungo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=3527; -- Healing Stream Totem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130866; -- Gurubashi Spirit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129752; -- Mindslaved Gurubashi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123060; -- Paku'ai Verraki
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123062; -- Jes'tri
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133119; -- Golma
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=29238; -- Scourge Haunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130905; -- Cala Cruzpot
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121980; -- Direhorn Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133152; -- Raging Ben'jin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130921; -- Gentle Ben'jin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130922; -- Irritable Maka'fon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130929; -- Witch Doctor Jangalar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133167; -- Voodoo Cauldron
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122009; -- Kraal Master B'khor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122012; -- Direhorn Juvenile
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126509; -- Pinky
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142151; -- Jammer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132109; -- Tortollan Tamer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132110; -- Emerald Turtle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132111; -- Turquoise Turtle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122059; -- Direhorn Juvenile
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122060; -- Direhorn Cow
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123180; -- Controller Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125414; -- Spiny Gekkota
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125417; -- Pygmy Anaconda
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123193; -- Rezani Handler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123194; -- Rezani Handler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129907; -- Zul the Prophet
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126562; -- Irritable Diemetradon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123215; -- Rezani Handler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129924; -- Atal'jamba Iri
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131043; -- Jangalar's Voodoo Totem
UPDATE `creature_template` SET `family`=138, `VerifiedBuild`=38134 WHERE `entry`=122107; -- Brutosaur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131044; -- Gurubashi Sacrifice
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122113; -- Pterrordax Skyrender
UPDATE `creature_template` SET `type_flags`=65537, `VerifiedBuild`=38134 WHERE `entry`=122114; -- Pterrordax
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126597; -- Dino Egg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122129; -- Trader Alexxi Cruzpot
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133300; -- Gloomtail's Head
UPDATE `creature_template` SET `type_flags`=2097225, `VerifiedBuild`=38134 WHERE `entry`=129954; -- Gahz'ralka
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125486; -- Wingrider Nivek
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133321; -- Razorwing Defender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132213; -- Weakened Sacrifice
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132217; -- Bubbling Cauldron
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133354; -- Jani
UPDATE `creature_template` SET `family`=11, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=126653; -- Hungry Saurid
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126655; -- Direhorn Juvenile
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133366; -- Witch Doctor Jangalar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=151241; -- Follow the spirit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133371; -- Gentle Ben'jin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130029; -- Tal'gurub Villager
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130031; -- Tal'gurub Berserker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130034; -- Tal'gurub Loa Priest
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130035; -- Tal'gurub Headhunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122223; -- Direhorn Cow
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122224; -- Direhorn Bull
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126714; -- Juvenile Brutosaur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133420; -- Dazarian Toad
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126722; -- Diemetradon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126725; -- Elder Diemetradon
UPDATE `creature_template` SET `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=126726; -- Young Diemetradon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126731; -- Diemetradon Egg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126732; -- Pinky
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126733; -- Rezani Handler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130084; -- [DNT] Cauldron Vehicle Central
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=122267; -- Kill Credit: Training Course Complete
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=126736; -- Kill Credit: Spanking
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130089; -- Atal'jamba Ungo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122271; -- Direhorn Juvenile
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131217; -- Urn of Voices
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131218; -- Urn of Voices
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131219; -- Gong
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130109; -- Atal'jamba Iri
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130114; -- [DNT] Cauldron Vehicle North
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131241; -- Vol'jamba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126775; -- Kraal Master B'khor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122311; -- Pinky
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=134619; -- Savagemane Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=149147; -- N'chala the Egg Thief
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126820; -- Roaming Nibbler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130197; -- Spite of Vol'jamba
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=85517; -- Challenge Post
UPDATE `creature_template` SET `family`=39, `type_flags`=2147549257, `VerifiedBuild`=38134 WHERE `entry`=123502; -- King K'tal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130208; -- Eyes of Vol'jamba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130209; -- Voice of Vol'jamba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133563; -- Voodoo Spell Target
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122399; -- Pig
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130219; -- Mindslaved Berserker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122400; -- Wingrider Bladeguard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130221; -- Jambani Chosen
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122402; -- Brute Bodyguard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=140285; -- Rez'caza
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=140287; -- Barder Zitaki
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139180; -- Sornoth Slagmane
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125783; -- Apprentice Beastcaller
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=140305; -- Kraal Warhauler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125784; -- Beastcaller Guardian
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130260; -- Zuvembi Brewer Zekal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122445; -- Zandalari Pterrorwing
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=122447; -- Kill Credit: Bush 01
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130294; -- Vol'jamba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125833; -- Rezani Handler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130304; -- Fury of Vol'jamba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130305; -- Fist of Vol'jamba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=150412; -- Inert Voodoo Mask
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130308; -- FX STalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135907; -- A Guttural Voice
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122504; -- Savagemane Ravasaur
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=123634; -- Kill Credit: Training Course - Get Help 2
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130344; -- Vol'jamba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122531; -- Rezani Handler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123656; -- Apprentice Beastcaller
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142655; -- Atal'Jani Reveler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142657; -- Loa Speaker Chel'ra
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142659; -- Boisterous Vagrant
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142660; -- Gleeful Scamp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139311; -- Handler Bazkoji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142663; -- Atal'Jani Niv'ek
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139312; -- Feral Ravasaur
UPDATE `creature_template` SET `RequiredExpansion`=0, `rank`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `movementId`=0, `VerifiedBuild`=38134 WHERE `entry`=123677; -- Kill Credit: Naptime
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142671; -- Atal'Jani Ack'uff
UPDATE `creature_template` SET `rank`=6, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=139326; -- Invasive Eggsnatcher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132628; -- Voodoo Love Incense
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132629; -- Romantic Brutosaur Meal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122600; -- Pet Toy - Fetch Raptor Plush
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136009; -- 7th Legion Marine
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139365; -- Queenfeather
UPDATE `creature_template` SET `type_flags`=2147483720, `VerifiedBuild`=38134 WHERE `entry`=131555; -- Gloomtail
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131558; -- Invasive Razorwing
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131560; -- Feral Ravasaur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130451; -- Bladeguard Elite
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142751; -- Atal'Jani Buz'ack
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=137169; -- Projection of Jangalar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136058; -- Projection of Jangalar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136067; -- Projection of Jangalar
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=55659; -- Wild Imp
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=133854; -- Wild Pterrorchick
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139440; -- Jabra'kan the Poacher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133857; -- Shadraspawn Lurker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133871; -- [DNT] Raptor Egg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=174084; -- Sharpclaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133910; -- Lil' Stompy
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136152; -- 7th Legion Scout
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138399; -- Jambani stockpiles burned
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138408; -- Mindslaved Berserker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138409; -- Jambani Chosen
UPDATE `creature_template` SET `type_flags`=65609, `VerifiedBuild`=38134 WHERE `entry`=131718; -- Bramblewing
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129487; -- Jambani Crusher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121680; -- Direhorn Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121688; -- Old Scargiver
UPDATE `creature_template` SET `KillCredit1`=0, `KillCredit2`=0, `VerifiedBuild`=38134 WHERE `entry`=129513; -- Jambani Spirit Twister
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131753; -- Dark Iron Golem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121706; -- Beastlord L'kala
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=148517; -- Baby Zandalari Raptor
UPDATE `creature_template` SET `name`='Le\'xi', `HealthScalingExpansion`=7, `type`=7, `VerifiedBuild`=38134 WHERE `entry`=134017; -- Le'xi
UPDATE `creature_template` SET `name`='T\'eem', `HealthScalingExpansion`=7, `type`=7, `VerifiedBuild`=38134 WHERE `entry`=134018; -- T'eem


UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=139643 AND `Idx`=0); -- Direhorn Hatchling
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=122060 AND `Idx`=0); -- Direhorn Cow
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=142151 AND `Idx`=0); -- Jammer
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=122224 AND `Idx`=0); -- Direhorn Bull
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=139640 AND `Idx`=0); -- Direhorn Hatchling
UPDATE `creature_template_model` SET `DisplayScale`=1.60000002384185791 WHERE (`CreatureID`=149147 AND `Idx`=0); -- N'chala the Egg Thief
UPDATE `creature_template_model` SET `DisplayScale`=0.150000005960464477 WHERE (`CreatureID`=130777 AND `Idx`=0); -- Leafy Flutterwing
UPDATE `creature_template_model` SET `DisplayScale`=1.399999976158142089 WHERE (`CreatureID`=139365 AND `Idx`=0); -- Queenfeather
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=139440 AND `Idx`=0); -- Jabra'kan the Poacher
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=125486 AND `Idx`=0); -- Wingrider Nivek
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=140305 AND `Idx`=0); -- Kraal Warhauler
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=122445 AND `Idx`=0); -- Zandalari Pterrorwing
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=122114 AND `Idx`=0); -- Pterrordax
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=122939 AND `Idx`=0); -- Direhorn Hatchling
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=131241 AND `Idx`=0); -- Vol'jamba
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=130304 AND `Idx`=0); -- Fury of Vol'jamba
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=130294 AND `Idx`=0); -- Vol'jamba
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=130197 AND `Idx`=0); -- Spite of Vol'jamba
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=122223 AND `Idx`=0); -- Direhorn Cow


UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273838; -- Gate - Open
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=292415; -- Barrier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=271641; -- Barrier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277710; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277704; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273899; -- Raptor Plushie
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281479; -- Fence
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281478; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277714; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277712; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277711; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277709; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277707; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277706; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277701; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277708; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277702; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270881; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273815; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273817; -- Gate
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=273816; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270956; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270955; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270948; -- Soothing Lilybud
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270880; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=269938; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296470; -- Campfire
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=281176; -- Jani's Stash
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281173; -- Mysterious Trashpile
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=291236; -- Steaming Fresh Carrion
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=291235; -- Steaming Fresh Carrion
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=291234; -- Steaming Fresh Carrion
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=291291; -- Wanted: Poacher
UPDATE `gameobject_template` SET `IconName`='', `Data1`=76087, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=276242; -- Anchor Weed
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=271809; -- Gate
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=270918; -- Soothing Lilybud
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=301552; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296302; -- Offering to Jani
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281437; -- Trash Pile
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215635; -- Chewed Carrot
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281250; -- Mojo Mixer
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281249; -- Poorly Aged Juice
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281248; -- Ancient Nuts and Berries
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281247; -- Fish Tacos
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281246; -- Spicy Peppers
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281245; -- Warm Tortillas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296468; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296684; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303134; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296466; -- Forge
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=270040; -- Nearly-hatching Pterrordax Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=290752; -- Zul's Ire
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=279353; -- Urn of Voices
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=279346; -- Urn of Voices
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279363; -- [DNT] Bottle
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279362; -- [DNT] Bottle
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279361; -- [DNT] Bottle
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=279354; -- Mysterious Brew
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=279349; -- Gong of Command
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296473; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279242; -- [DNT] Whetstone
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279241; -- [DNT] Weaponrack 01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296474; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279234; -- [DNT] Anvil
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=290747; -- Jambani Stockpile
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279233; -- [DNT] Skull Pile 2
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279232; -- [DNT] Skull Pile
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=290748; -- Jambani Stockpile
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279240; -- [DNT] Drum
UPDATE `gameobject_template` SET `castBarCaption`='', `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=278537; -- Eyes of Vol'jamba
UPDATE `gameobject_template` SET `castBarCaption`='', `Data0`=2582, `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=278536; -- Voice of Vol'jamba
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=278452; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=278713; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296469; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279251; -- [DNT] Weapon
UPDATE `gameobject_template` SET `Data1`=0, `Data5`=0, `Data6`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=290749; -- Jambani Stockpile
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296467; -- Forge
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=279044; -- Zandalari Rushes
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296472; -- Campfire
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=279304; -- Endangered Brutosaurs [INVISIBLE]
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=279244; -- Endangered Brutosaurs [INVISIBLE]
UPDATE `gameobject_template` SET `Data1`=76263, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=276623; -- Rich Platinum Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278812; -- [DNT] Zanda Mask 01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278811; -- [DNT] Zanda Mask 02
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296471; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278315; -- Witch Doctor's Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=297904; -- Urn of Voices
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=290750; -- Jambani Stockpile
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=278453; -- Voodoo Totem
UPDATE `gameobject_template` SET `ContentTuningId`=686, `VerifiedBuild`=38134 WHERE `entry`=320927; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=290986; -- Hexlord Raal


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=291236 AND `Idx`=0); -- Steaming Fresh Carrion
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=291235 AND `Idx`=0); -- Steaming Fresh Carrion
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=291234 AND `Idx`=0); -- Steaming Fresh Carrion
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=270040 AND `Idx`=0); -- Nearly-hatching Pterrordax Egg
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=279044 AND `Idx`=0); -- Zandalari Rushes
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278453 AND `Idx`=0); -- Voodoo Totem

DELETE FROM `npc_text` WHERE `ID`=33926;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33926, 1, 0, 0, 0, 0, 0, 0, 0, 146769, 0, 0, 0, 0, 0, 0, 0, 38134); -- 33926

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=31977; -- 31977
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=31922; -- 31922
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33836; -- 33836
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33835; -- 33835
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33834; -- 33834
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33839; -- 33839
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33838; -- 33838
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33837; -- 33837
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33490; -- 33490
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33584; -- 33584



