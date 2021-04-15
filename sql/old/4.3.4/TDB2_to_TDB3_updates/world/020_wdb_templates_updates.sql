DELETE FROM `gameobject_template` WHERE `entry` IN (204280, 204279, 195317);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(204280, 3, 9712, 'Bottle of Whiskey', '', '', '', 1634, 30877, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 58798, 0, 0, 0, 0, 0, 0, 14333), -- -Unknown-
(204279, 3, 7538, 'Spool of Rope', '', '', '', 1634, 30876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 58806, 0, 0, 0, 0, 0, 0, 14333), -- -Unknown-
(195317, 5, 2630, 'Raptor Feather', '', '', '', 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 14333); -- -Unknown-

UPDATE `gameobject_template` SET `WDBVerified`=14333 WHERE `entry`=186739; -- Amani Charm Box
UPDATE `gameobject_template` SET `WDBVerified`=14333 WHERE `entry`=203197; -- -Unknown-
UPDATE `gameobject_template` SET `WDBVerified`=14333 WHERE `entry`=203198; -- -Unknown-
UPDATE `gameobject_template` SET `WDBVerified`=14333 WHERE `entry`=203207; -- -Unknown-
UPDATE `gameobject_template` SET `size`=0.75, `WDBVerified`=14333 WHERE `entry`=187292; -- Guild Vault
UPDATE `gameobject_template` SET `WDBVerified`=14333 WHERE `entry`=175306; -- Doodad_MediumBrazierPurple11
UPDATE `gameobject_template` SET `WDBVerified`=14333 WHERE `entry`=175310; -- Doodad_MediumBrazierPurple13

DELETE FROM `creature_model_info` WHERE `modelid` IN (33530, 38679);
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`) VALUES
(33530, 0.4284, 2.1, 1), -- 33530
(38679, 0.68, 2, 0); -- 38679

UPDATE `creature_model_info` SET `bounding_radius`=0.7 WHERE `modelid`=22475; -- 22475
UPDATE `creature_model_info` SET `bounding_radius`=0.203339 WHERE `modelid`=30301; -- 30301
UPDATE `creature_model_info` SET `bounding_radius`=0.075, `combat_reach`=0.15 WHERE `modelid`=24719; -- 24719
UPDATE `creature_model_info` SET `bounding_radius`=0.3366, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=32563; -- 32563
UPDATE `creature_model_info` SET `bounding_radius`=1.347458, `combat_reach`=1.122881 WHERE `modelid`=666; -- 666
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=32854; -- 32854
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=32849; -- 32849
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=32856; -- 32856
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=32855; -- 32855
UPDATE `creature_model_info` SET `bounding_radius`=0.02, `combat_reach`=0.3 WHERE `modelid`=37867; -- 37867
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95 WHERE `modelid`=22278; -- 22278
UPDATE `creature_model_info` SET `bounding_radius`=0.4340275, `combat_reach`=1.875 WHERE `modelid`=22302; -- 22302
UPDATE `creature_model_info` SET `bounding_radius`=0.7, `combat_reach`=6 WHERE `modelid`=36701; -- 36701
UPDATE `creature_model_info` SET `bounding_radius`=1.86, `combat_reach`=18 WHERE `modelid`=35321; -- 35321
UPDATE `creature_model_info` SET `bounding_radius`=0.525, `combat_reach`=6 WHERE `modelid`=11997; -- 11997
UPDATE `creature_model_info` SET `bounding_radius`=1.16964, `combat_reach`=4.860001, `gender`=0 WHERE `modelid`=31605; -- 31605
UPDATE `creature_model_info` SET `bounding_radius`=0.75, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=32355; -- 32355
UPDATE `creature_model_info` SET `bounding_radius`=0.625, `combat_reach`=1.25 WHERE `modelid`=33947; -- 33947
UPDATE `creature_model_info` SET `bounding_radius`=2.5571, `combat_reach`=1.95, `gender`=0 WHERE `modelid`=32268; -- 32268
UPDATE `creature_model_info` SET `bounding_radius`=1.967, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31508; -- 31508
UPDATE `creature_model_info` SET `bounding_radius`=3, `combat_reach`=3.5, `gender`=0 WHERE `modelid`=32341; -- 32341
UPDATE `creature_model_info` SET `bounding_radius`=0.2496, `combat_reach`=1.8, `gender`=1 WHERE `modelid`=32308; -- 32308
UPDATE `creature_model_info` SET `bounding_radius`=0.6188, `combat_reach`=1.95, `gender`=1 WHERE `modelid`=4578; -- 4578
UPDATE `creature_model_info` SET `bounding_radius`=0.2625, `combat_reach`=0.75 WHERE `modelid`=30126; -- 30126
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=31625; -- 31625
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=2 WHERE `modelid`=1923; -- 1923
UPDATE `creature_model_info` SET `gender`=2 WHERE `modelid`=29418; -- 29418
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=2.25 WHERE `modelid`=29764; -- 29764
UPDATE `creature_model_info` SET `bounding_radius`=0.315, `combat_reach`=1.35 WHERE `modelid`=29405; -- 29405
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=2.25 WHERE `modelid`=29781; -- 29781
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5, `gender`=2 WHERE `modelid`=29412; -- 29412
UPDATE `creature_model_info` SET `bounding_radius`=0.31, `combat_reach`=1.5 WHERE `modelid`=35371; -- 35371
UPDATE `creature_model_info` SET `bounding_radius`=2.25 WHERE `modelid`=38705; -- 38705
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05 WHERE `modelid`=31209; -- 31209
UPDATE `creature_model_info` SET `bounding_radius`=0.295, `combat_reach`=1.875 WHERE `modelid`=31210; -- 31210
UPDATE `creature_model_info` SET `bounding_radius`=0.8, `combat_reach`=8 WHERE `modelid`=29162; -- 29162
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=31208; -- 31208
UPDATE `creature_model_info` SET `bounding_radius`=0.2601, `combat_reach`=1.275, `gender`=1 WHERE `modelid`=38091; -- 38091
UPDATE `creature_model_info` SET `bounding_radius`=0.3, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=38089; -- 38089
UPDATE `creature_model_info` SET `bounding_radius`=1.072881, `combat_reach`=0.8940678 WHERE `modelid`=604; -- 604
UPDATE `creature_model_info` SET `bounding_radius`=0.1440932, `combat_reach`=0.6175424 WHERE `modelid`=9535; -- 9535
UPDATE `creature_model_info` SET `bounding_radius`=0.1395, `combat_reach`=0.45, `gender`=1 WHERE `modelid`=36450; -- 36450
UPDATE `creature_model_info` SET `bounding_radius`=1.0285, `combat_reach`=0.825 WHERE `modelid`=368; -- 368
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34084; -- 34084
UPDATE `creature_model_info` SET `bounding_radius`=0.7 WHERE `modelid`=30210; -- 30210
UPDATE `creature_model_info` SET `bounding_radius`=0.85, `combat_reach`=1.0625 WHERE `modelid`=1938; -- 1938
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=30951; -- 30951
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=30947; -- 30947
UPDATE `creature_model_info` SET `bounding_radius`=0.8584, `combat_reach`=1.2 WHERE `modelid`=23518; -- 23518
UPDATE `creature_model_info` SET `bounding_radius`=0.4464, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=31220; -- 31220
UPDATE `creature_model_info` SET `bounding_radius`=0.7474576, `combat_reach`=0.934322 WHERE `modelid`=1307; -- 1307
UPDATE `creature_model_info` SET `bounding_radius`=0.4164, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=31404; -- 31404
UPDATE `creature_model_info` SET `bounding_radius`=0.8745, `combat_reach`=1.65 WHERE `modelid`=1973; -- 1973
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=1346; -- 1346
UPDATE `creature_model_info` SET `bounding_radius`=0.5, `combat_reach`=1 WHERE `modelid`=38418; -- 38418
UPDATE `creature_model_info` SET `bounding_radius`=0.5, `combat_reach`=1 WHERE `modelid`=38419; -- 38419
UPDATE `creature_model_info` SET `bounding_radius`=0.4, `combat_reach`=2.5 WHERE `modelid`=31425; -- 31425
UPDATE `creature_model_info` SET `bounding_radius`=0.85, `combat_reach`=1.0625 WHERE `modelid`=999; -- 999
UPDATE `creature_model_info` SET `bounding_radius`=0.0775, `combat_reach`=0.375 WHERE `modelid`=35015; -- 35015
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=29242; -- 29242
UPDATE `creature_model_info` SET `bounding_radius`=0.1, `combat_reach`=0.2, `gender`=0 WHERE `modelid`=29237; -- 29237
UPDATE `creature_model_info` SET `bounding_radius`=0.245, `combat_reach`=1.05, `gender`=1 WHERE `modelid`=17090; -- 17090
UPDATE `creature_model_info` SET `bounding_radius`=0.3366, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=37095; -- 37095
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=8149; -- 8149
UPDATE `creature_model_info` SET `bounding_radius`=1.1, `combat_reach`=1.65 WHERE `modelid`=29509; -- 29509
UPDATE `creature_model_info` SET `bounding_radius`=0.85, `combat_reach`=1.0625 WHERE `modelid`=641; -- 641
UPDATE `creature_model_info` SET `bounding_radius`=0.1, `combat_reach`=0.125 WHERE `modelid`=5560; -- 5560
UPDATE `creature_model_info` SET `bounding_radius`=0.94875, `combat_reach`=1.796875 WHERE `modelid`=373; -- 373
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=36864; -- 36864
UPDATE `creature_model_info` SET `gender`=2 WHERE `modelid`=857; -- 857
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=29573; -- 29573
UPDATE `creature_model_info` SET `combat_reach`=1.5 WHERE `modelid`=33323; -- 33323
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=32952; -- 32952
UPDATE `creature_model_info` SET `bounding_radius`=0.3213, `combat_reach`=1.575, `gender`=0 WHERE `modelid`=37119; -- 37119
UPDATE `creature_model_info` SET `bounding_radius`=0.389, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=28390; -- 28390
UPDATE `creature_model_info` SET `bounding_radius`=0.389, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=28383; -- 28383
UPDATE `creature_model_info` SET `bounding_radius`=0.389, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=28392; -- 28392
UPDATE `creature_model_info` SET `bounding_radius`=0.389, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=28389; -- 28389
UPDATE `creature_model_info` SET `bounding_radius`=0.389, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=28382; -- 28382
UPDATE `creature_model_info` SET `bounding_radius`=0.389, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=28384; -- 28384
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=28387; -- 28387

DELETE FROM `page_text` WHERE `entry`=3604;
INSERT INTO `page_text` (`entry`, `text`, `next_page`, `WDBVerified`) VALUES
(3604, 'As Forsaken, we fight against the Lich King, we fight against the Alliance... sometimes we even quarrel with the other races of the Horde.  We are few, and we face great obstacles... but we will survive and prevail.$b$bAs a fellow hunter, you will do so from afar, with a bow in your hand and an animal companion at your side.  Your power comes not from arcane wizardry or martial prowess, but your ability to live off the land.$b$bThe path of the hunter lies before you.  It starts with me, your trainer.  Where it ends... we do not know that yet.', 0, 14333); -- 3604

UPDATE `page_text` SET `text`='Now from this here barrel, face ye North.  Straight as the crow flies, keep ye walkin'' till you see the empty jug next to the lone windmill on the sea bluffs.  If ye poke around that jug, ye just might find what you''re lookin'' for.', `WDBVerified`=14333 WHERE `entry`=46; -- 46
UPDATE `page_text` SET `text`='Hello William,

It''s been years since we''ve spoken, but I trust you and your brother are well, and that your apothecary thrives.

I must ask a favor of you, William.  In short, my grandson Tommy Joe has lost his heart to young Maybell Maclure.  And although they adore each other... our families, well our families have been feuding for years.', `WDBVerified`=14333 WHERE `entry`=26; -- 26
UPDATE `page_text` SET `text`='I fear the war between the Stonefields and the Maclures will kill Tommy Joe and Maybell''s blossoming romance, and in times like these - where dark news and rumors of war loom over us - youth and love must be nurtured.

So, the favor: I ask that you use your skills and concoct a potion or elixir to aid these young lovers in their quest for each other.

Thank you, William.  And please, when you have some time away from work, come visit.  We''ll have a few chuckles over the past.

-Mildred', `WDBVerified`=14333 WHERE `entry`=218; -- 218
UPDATE `page_text` SET `WDBVerified`=14333 WHERE `entry`=78; -- 78

DELETE FROM `npc_text` WHERE `ID` IN (16522, 16003, 15971, 15881, 16670, 17108, 16075, 18150, 18032, 18151, 16076, 18152, 18029, 18030, 18031, 18141, 17977, 17976, 18258, 18144, 15998, 18266, 18159, 18153, 18156, 18157, 15028, 15272, 17637, 17636, 17635, 17634, 17633, 17632, 17631, 17630, 16714, 16579, 15643, 14553, 14555, 16520, 14546, 14565, 14566, 15260, 15252, 16628, 16641);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(16522, 'You are not yet strong enough to do battle in Twin Peaks. Return when you have gained more experience.', 'You are not yet strong enough to do battle in Twin Peaks. Return when you have gained more experience.', 0, 1, 274, 0, 0, 1, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 16522
(15028, 'Keep your sights straight, $N.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 15028
(15272, '', 'Nature will guide ya when all else fails.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 15272
(17637, '', '<Zen''tabra laughs.>$B$BWe spread dose rumors, mon. Keep''n Zalazane and others off our tails. Don''t be believin'' everyting ya hear.$B$BNo, we be new ta de craft, only learnin'' a few years ago. But in some ways, we spent our lives preparin'' ta answer de call....', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 17637
(17636, '', 'Some o'' us be loa priests, witch doctors before. Like Zalazane...$B$B<Zen''tabra''s face grows hard as her gaze drifts south.>$B$BWe thought de spirits be angry wit us; we did not suspect it be Zalazane slowly cuttin'' us off from dem. We knew he be strong, but not dat strong... and by de time his voodoo had reached de other isles, we was powerless ta stop ''im. ', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 17636
(17635, '', '<Zen''tabra closes her eyes and shakes her head.>$B$BWhen Vol''jin called for everyone ta flee, we... we couldn''t face de tribe after failing dem so badly. So, we fled south, ta de untamed jungle islands.$B$BDe wilds claimed a few o'' us dat first night. We found safety in a deep cave in de center o'' de isle, but me dreams dere were not peaceful: I be havin'' a vision!', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 17635
(17634, '', '<Zen''tabra''s head snaps back to you, her eyes bright and her smile wide around her tusks.>$B$B''Twas a jungle bigger and wilder dan I ever seen! And before me, de ancient raptor loa only talked about in Zandalari tales-Gonk, de Great Hunter! $B$BDe raptor spirit spoke ta me, told me he had brought me spirit to a place called de Emerald Dream. De spirit had been trapped, like de other loa on de Echo Isles, by Zalazane''s magic. But Gonk, bein'' an ancient spirit, was able ta reach across and bring me spirit ta him, even through Zalazane''s voodoo. ', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 17634
(17633, '', 'Zalazane''s mindless servants were killin'' all de beasts o'' de isles, burnin'' up de trees and plants too. Gonk needed us ta save de life on de isles. But since we not be able ta draw upon de power o'' de loa wit Zalazane in power, Gonk be showin'' us a new way ta connect wit ALL de spirits o'' nature, ta work WIT de spirits, not just be servin'' a single loa at a time. $B$BIt be difficult at first, ya, mon, but Gonk be showin'' us how ta also reach inta de Emerald Dream ta speak wit de spirits and learn from dem directly!', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 17633
(17632, '', '<Zen''tabra laughs.>$B$BDe other loa, ''specially Shirvallah, did not much care for dis plan. Dey still be wantin'' us ta work just for one o'' dem at a time, not wit all de spirits at once. But Gonk had forced dere hands, and dey knew it was de only way ta save de isles while Zalazane still ruled.$B$BI be tinkin'' dat Gonk did not care for de other loa much either. He be teasin'' de other loa all de time while we be learnin'' from dem.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 17632
(17631, '', 'We been workin'' wit de spirits for many moons now, mon, but many o'' us already knew de forms o'' de loa we served before. It not be easy, but de Emerald Dream be a powerful teacher by itself-havin'' de spirits demselves also teachin'' ya... it hurries tings along.$B$BDat don''t mean ''twas easy keepin'' safe from Zalazane. Even wit our new tricks combined wit de loa givin'' what help dey could, we lost a few bruddas and sistas over de years ta his voodoo and mindless servants. But we kept de life o'' de isles alive, and when Vol''jin and de Darkspears returned, we knew just how ta take Zalazane down.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 17631
(17630, '', 'Ya, mon, for now. Dey not be too keen on teachin'' many more o'' our kind, but dey be helpin'' us ''long as we be keepin'' de life o'' de isles flourishin''. When Gonk left after de fall o'' Zalazane, he be tellin'' us how ta contact him if de other loa don''t keep dey end o'' de bargain.$B$BI be hopin'' it never come ta dat... but just in case, we be openin'' up channels wit dat Cenarion Circle group. $B$B<Zen''tabra cackles madly.>$B$BOh, ya shoulda seen de look on dat night elf''s face....', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 17630
(16714, 'How may I be helpin'' ya, Child of de Earth?', 'How may I be helpin'' ya, Child of de Earth?', 1, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 16714
(16579, 'Return any time ya need trainin''.', '', 0, 1, 1, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 16579
(15643, 'What''s the matter, chum... never seen a worgen before?', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 15643
(14553, '<Snort> Is this how cowards fight, $r?', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 14553
(14555, '<The quilboar fixes his beady black eyes on you.>', '', 0, 1, 0, 0, 0, 0, 0, 0, '<The quilboar wrinkles his nose at you and snorts.>', '', 0, 2, 0, 0, 0, 0, 0, 0, 'What now, $r? Do your worst.', '', 0, 1, 0, 0, 0, 0, 0, 0, 'We''re warriors, $n. <Snort> Many and proud.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 14555
(16520, 'You are not yet strong enough to enter The Battle for Gilneas. Return when you have gained more experience.', 'You are not yet strong enough to enter The Battle for Gilneas. Return when you have gained more experience.', 0, 1, 274, 0, 0, 1, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 16520
(14546, '', 'Well, $N - are you ready to roll? It won''t be easy!', 0, 1, 1, 0, 0, 50, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 14546
(14565, 'Ho, $N! My brother Balgor tells me you''re quite the shot from the back of a kodo. Great work getting that caravan here from Far Watch in one piece.$B$BListen, there''s plenty of work for you here in Grol''dom... but I could use your trigger fingers for the rest of the ride to Crossroads.$B$BCome see me when you''re ready!', '', 0, 1, 3, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 14565
(14566, 'Are you ready to do this, $N?', '', 0, 1, 6, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 14566
(15260, 'I can''t help ya. Go talk ta Zen''Tabra if ya want druid trainin''.', 'I can''t help ya. Go talk ta Zen''Tabra if ya want druid trainin''.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 15260
(15252, 'They''re in mid challenge, mon. Be patient.', 'They''re in mid challenge, mon. Be patient.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 15252
(16628, 'Harrison Jones teaches Archaeology in Stormwind Keep''s Royal Library when not out in the field.', 'Harrison Jones teaches Archaeology in Stormwind Keep''s Royal Library when not out in the field.', 7, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- 16628
(16641, 'Welcome to Stormwind, $c.', '', 0, 1, 1, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14333); -- 16641

UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1242; -- 1242
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1220; -- 1220
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1241; -- 1241
UPDATE `npc_text` SET `em0_0`=2, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=3896; -- 3896
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=7176; -- 7176
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=4863; -- 4863
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=5838; -- 5838
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=273, `em0_3`=0, `WDBVerified`=14333 WHERE `ID`=13474; -- 13474
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=7722; -- 7722
UPDATE `npc_text` SET `text0_1`='Elune''s secrets are many, but they are not to be shared with just anyone. ', `WDBVerified`=14333 WHERE `ID`=5190; -- 5190
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=5475; -- 5475
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=2153; -- 2153
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=2154; -- 2154
UPDATE `npc_text` SET `text0_0`='The blessings of Cenarius be yours, $c.', `em0_0`=1, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=4781; -- 4781
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=12262; -- 12262
UPDATE `npc_text` SET `em0_0`=2, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=12264; -- 12264
UPDATE `npc_text` SET `em0_0`=274, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=12263; -- 12263
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=13321; -- 13321
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=23, `em0_2`=0, `em0_3`=0, `em0_4`=3, `WDBVerified`=14333 WHERE `ID`=12268; -- 12268
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=12279; -- 12279
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=3559; -- 3559
UPDATE `npc_text` SET `text0_0`='Dis here volunteer work be my way of gettin through Witch Doctor School.  Since you help me, I help ya for free.  Whatcha need fixin?', `WDBVerified`=14333 WHERE `ID`=3795; -- 3795
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1216; -- 1216
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=13441; -- 13441
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1239; -- 1239
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=4259; -- 4259
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=4273; -- 4273
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=4283; -- 4283
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=927; -- 927
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=3406; -- 3406
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1118; -- 1118
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=13572; -- 13572
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1226; -- 1226
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=2, `em0_3`=0, `WDBVerified`=14333 WHERE `ID`=6936; -- 6936
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=13593; -- 13593
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1231; -- 1231
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=6104; -- 6104
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=4859; -- 4859
UPDATE `npc_text` SET `text0_0`='Hello, $c.  I hope you''ve come to bolster our ranks.  Beasts and thieves are spilling into our beloved Elwynn, and we barely have enough men to keep the roads safe!$B$BAnd if you haven''t done so, read that notice about Hogger.  He''s a beast in yonder woods that must be dealt with.', `em0_0`=1, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=2287; -- 2287
UPDATE `npc_text` SET `em0_0`=5, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=2286; -- 2286
UPDATE `npc_text` SET `em0_0`=5, `em0_1`=0, `WDBVerified`=14333 WHERE `ID`=2289; -- 2289
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1215; -- 1215
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=5354; -- 5354
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=8238; -- 8238
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1232; -- 1232
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1253; -- 1253
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=16982; -- 16982
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=16983; -- 16983
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1206; -- 1206
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1202; -- 1202
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=11469; -- 11469
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1252; -- 1252
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1207; -- 1207
UPDATE `npc_text` SET `WDBVerified`=14333 WHERE `ID`=1225; -- 1225

DELETE FROM `creature_equip_template` WHERE `entry` IN (197, 42218, 42218, 43278, 42216, 1213, 42216, 152, 78, 49869, 196, 49869, 49874, 49869, 49869, 459, 49874, 49869, 6373, 49874, 911, 49874, 49874, 49869, 49869, 925, 49874, 49869, 198, 375, 49874, 49874, 49874, 49874, 915, 49869, 49869, 49874, 951, 42218, 42218, 42218, 42218, 49874, 49869, 49869, 49874, 1642, 49874, 1642, 1642, 1642, 1642, 1642, 94, 6367, 94, 1423, 6306, 1651, 794, 465, 1430, 3935, 6374, 151, 917, 377, 906, 328, 1423, 240, 514, 2046, 1423, 241, 913, 927, 46983, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 94, 94, 94, 94, 94, 94, 1423, 68, 4959, 1976, 1976, 68, 28569, 28596, 28596, 28569, 28569, 1976, 28569, 28596, 28596, 12779, 52546, 19848, 12784, 12780, 12785, 52545, 35477, 52537, 68, 1302, 1303, 1976, 49877, 68, 51348, 12786, 12781, 12787, 483, 4981, 482, 68, 68, 1285, 28569, 28596, 4974, 1432, 1976, 68, 28569, 28596, 1478, 1477, 1275, 1257, 12480, 28596, 1289, 49748, 1287, 51348, 51348, 51348, 28569, 466, 51348, 28596, 51348, 28569, 68, 68, 12481, 68, 68, 42421, 14439, 51348, 51348, 51348, 14423, 3518, 51348, 51348, 51348, 68, 51348, 68, 51348, 51348, 51348, 51348, 51348, 51348, 51348, 51348, 68, 68, 1431, 1297, 1301, 1298, 1976, 14438, 68, 5494, 68, 5493, 1976, 1366, 1367, 44583, 68, 68, 68, 1976, 1976, 1444, 14497, 1976, 1284, 10782, 68, 51348, 1976, 1371, 1368, 1370, 42421, 51348, 1976, 68, 51348, 51348, 1348, 6171, 5484, 1351, 5491, 928, 5492, 5489, 376, 42421, 68, 68, 42421, 29712, 68, 29712, 68, 29712, 44880, 68, 1976, 5514, 5513, 68, 47688, 51348, 1976, 7232, 5509, 1416, 5510, 54217, 54216, 54218, 5512, 1472, 29725, 7798, 5511, 5413, 957, 656, 45306, 6579, 5384, 68, 68, 5518, 5519, 11026, 68, 68, 44236, 5515, 5517, 5516, 1976, 1976, 52358, 1415, 13116, 13117, 68, 68, 68, 68, 68, 1319, 1321, 11096, 1292, 1339, 28347, 28355, 68, 12783, 1323, 1328, 1976, 12805, 918, 43694, 68, 13283, 51998, 8383, 42421, 1325, 914, 1326, 332, 44249, 5480, 44247, 5479, 43277, 6946, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 116, 94, 116, 474, 474, 474, 474, 116, 99, 116, 116, 116, 116, 116, 116, 94, 94, 94, 94, 94, 1423, 1423, 478, 478, 478, 1423, 1423, 1423, 478, 1423, 1423, 478, 478, 478, 97, 478, 478, 478, 478, 478, 478, 478, 478, 97, 478, 478, 478, 97, 478, 100, 97, 478, 235, 233, 869, 42407, 42407, 42407, 42407, 491, 488, 820, 489, 821, 234, 487, 490, 42407, 42407, 42407, 54372, 54371, 42407, 42407, 42407, 42407, 42407, 42407, 42407, 42407, 52190, 42407, 42407, 42407, 54371, 42407, 54372, 42407, 42407, 51915, 42407, 54372, 42407, 842, 54372, 42407, 42407, 842, 54372, 54372, 876, 54371, 6670, 6670, 842, 51915, 870, 6670, 6670, 842, 49769, 49741, 49736, 49749, 1670, 1668, 843, 42407, 42407, 42407, 42407, 124, 42407, 49760, 43011, 42407, 42407, 54371, 54371, 49745, 54371, 54372, 42407, 42407, 42407, 54371, 42407, 54372, 54372, 54371, 42407, 54371, 51915, 42407, 51915, 452, 124, 123, 123, 123, 123, 123, 123, 123, 517, 517, 517, 517, 517, 123, 517, 517, 517, 517, 123, 517, 123, 123, 517, 517, 517, 123, 458, 517, 123, 123, 517, 517, 458, 517, 123, 517, 123, 458, 458, 171, 171, 171, 458, 458, 123, 171, 123, 171, 458, 458, 171, 171, 171, 171, 458, 123, 123, 458, 171, 171, 458, 458, 171, 458, 458, 171, 513, 171, 458, 171, 171, 171, 171, 171, 171, 171, 458, 171, 458, 458, 458, 123, 171, 458, 513, 513, 458, 513, 123, 513, 513, 123, 123, 123, 513, 171, 513, 171, 513, 513, 171, 171, 513, 456, 513, 513, 513, 456, 117, 117, 117, 456, 117, 456, 513, 117, 513, 513, 456, 513, 456, 513, 456, 513, 456, 513, 456, 513, 456, 456, 456, 513, 456, 513, 513, 513, 513, 513, 513, 456, 456, 513, 46642, 42594, 3296, 3296, 3296, 4485, 3296, 46622, 3296, 3296, 49750, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3353, 46667, 3296, 3354, 3296, 3296, 3296, 3296, 13842, 3296, 3296, 3296, 16076, 50550, 3296, 23635, 3296, 34955, 3296, 35364, 3296, 3296, 49573, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 3296, 51346, 51346, 3296, 3296, 3296, 3333, 3332, 3296, 14304, 3296, 3296, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 7951, 43239, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 14304, 3296, 3296, 7088, 3296, 3296, 47764, 47771, 47788, 3352, 47767, 3357, 3358, 51307, 51307, 51307, 3296, 3296, 51307, 51307, 51307, 51307, 3409, 51307, 7792, 7230, 11177, 5812, 7793, 3356, 3361, 4043, 11176, 7231, 3360, 11178, 7790, 3355, 10266, 3296, 3296, 52938, 52938, 52938, 52938, 52938, 52938, 52938, 52938, 52938, 52938, 52933, 52925, 52924, 52938, 52938, 52938, 52938, 52938, 52938, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23597, 23597, 23889, 23576, 24175, 52956, 52962, 24179, 24180, 53021, 53021, 52958, 53021, 24549, 52962, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 24179, 53021, 24180, 24180, 24179, 24180, 24179, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 52958, 52956, 52962, 52956, 52958, 52962, 23542, 23582, 23542, 23582, 23581, 23582, 23542, 23580, 23580, 23542, 23580, 23580, 23581, 23586, 23596, 23586, 23597, 52962, 23597, 23597, 23596, 23774, 23586, 23774, 23597, 23596, 23597, 23774, 23586, 23586, 23774, 23586, 23586, 23597, 52958, 23596, 23597, 23596, 23596, 23596, 23774, 52956, 23597, 23596, 23596, 23774, 23596, 23597, 52962, 52956, 52958, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 53021, 24065, 52958, 24065, 52956, 23577, 52958, 23597, 24065, 23597, 23597, 24059, 23597, 23597, 23597, 52956, 24065, 24059, 24065, 24239, 23597, 23596, 23581, 52958, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23889, 23863, 52938, 52938, 52938, 52925, 52938, 52924, 52933, 52958, 52956, 52956, 52958, 52962, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 25072, 25074, 25071, 25079, 25083, 25070, 25077, 25077, 25070, 25083, 25079, 25072, 25074, 25071, 25072, 25079, 25074, 25071, 25070, 25083, 25077, 47336, 47321, 47335, 3296, 45244, 3296, 3296, 3296, 51307, 51307, 3296, 44779, 44780, 45230, 45230, 8659, 11046, 3348, 51346, 3296, 3296, 3296, 46181, 11066, 3345, 51346, 46741, 3347, 46742, 12136, 3296, 25077, 45230, 44158, 3296, 25071, 25074, 3296, 25072, 3296, 5875, 3326, 44158, 3296, 9564, 3296, 45230, 3296, 45230, 44726, 45230, 3296, 3296, 45230, 44158, 3296, 3296, 44735, 50477, 5639, 3324, 3325, 5815, 3335, 3296, 3296, 3350, 3351, 3367, 6986, 7010, 46716, 6987, 52032, 3413, 9317, 11017, 25083, 25070, 25079, 44740, 45230, 45230, 44725, 44743, 44723, 45230, 45230, 25081, 24926, 24924, 25080, 24930, 24929, 24931, 51346, 51346, 51346, 43427, 43427, 43427, 43427, 43411, 40278, 43427, 43427, 40254, 40254, 43410, 38915, 40254, 40254, 40254, 40833, 38915, 43427, 43427, 43427, 43427, 38952, 38952, 38952, 38915, 43427, 41861, 43427, 38915, 53536, 53519, 53652, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 42846, 53738, 42917, 53736, 53738, 42885, 42885, 42684, 42885, 42885, 42885, 42885, 42885, 42885, 42885, 42885, 43513, 43513, 42885, 42885, 53905, 53925, 54178, 54177, 54179, 41502, 41502, 41502, 54402, 54401, 6929, 3296, 3296, 5609, 5606, 6466, 5613, 5597, 5610, 5614, 5603, 5611, 3296, 14375, 5817, 3296, 44874, 3296, 3296, 3313, 3296, 3296, 44871, 44872, 14392, 3342, 49750, 3296, 27815, 3370, 3296, 3312, 44878, 3296, 44851, 39605, 51346, 51346, 51346, 51346, 3296, 51346, 51346, 51346, 51307, 44876, 44877, 3144, 4047, 49622, 16012, 46142, 3296, 45339, 23128, 5188, 3296, 3323, 46142, 45337, 46556, 3296, 46555, 47571, 3296, 3296, 35068, 3296, 3314, 3296, 14377, 3296, 3296, 3296, 51346, 3296, 3296, 3296, 3296, 31725, 31724, 44919, 3310, 44158, 31727, 3296, 31726, 50323, 3296, 50488, 44158, 3296, 44158, 31723, 26537, 44158, 3296, 31720, 44158, 3296, 3296, 34765, 3296, 3331, 3296, 3296, 47246, 47248, 47247, 47253, 3329, 47233, 3328, 3327, 3296, 3216, 3189, 3296, 3334, 3296, 5816, 3330, 47663, 3296, 2857, 51346, 51346, 3322, 44781, 3296, 25070, 25079, 25083, 25074, 25072, 25071, 51346, 51346, 3296, 3296, 3296, 3296, 3296, 46359, 3296, 3296, 37072, 46357, 14376, 46358, 3296, 3296, 3296, 3296, 12796, 3296, 3296, 45558, 3296, 45814, 3296, 25077, 43427, 40578, 40336, 40336, 40336, 40333, 40336, 43551, 40333, 40333, 54392, 40331, 39858, 40333, 40333, 40336, 41006, 40336, 40757, 40336, 40336, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41029, 41008, 41008, 40997, 41008, 41008, 41008, 41008, 43493, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 41008, 43481, 39927, 39931, 39931, 39931, 39931, 39931, 39858, 39928, 39931, 41860, 39931, 43381, 52838, 53783, 53781, 52844, 52838, 52843, 52848, 52848, 52848, 52849, 52848, 52847, 52849, 52847, 52849, 52849, 52849, 52848, 52847, 52849, 52849, 52847, 52846, 52846, 52849, 52847, 52849, 52849, 52846, 52846, 52846, 52846, 52846, 52846, 52846, 52899, 53076, 52670, 52669, 52670, 54393, 52863, 52838, 52843, 52844, 52846, 52846, 52846, 52846, 52846, 52846, 52846, 52846, 52846, 52843, 52844, 52843, 52838, 52844, 52791, 52791, 52791, 52899, 53076, 52670, 52669, 52670, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52556, 38915, 38915, 38915, 52791, 52791, 52907, 52838, 52670, 52669, 52670, 52670, 52670, 53076, 52904, 52903, 52843, 52670, 52907, 52844, 52670, 52899, 52670, 52670, 52670, 52838, 52669, 52670, 52844, 52899, 52904, 52903, 53076, 52670, 52791, 52791, 52791, 52791, 52791, 52791, 53841, 53842, 53840, 53844, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 53413, 53412, 53365, 53411, 53412, 53411, 53412, 53411, 53413, 53411, 53412, 53411, 53080, 52822, 53365, 53412, 53413, 53411, 53412, 53413, 53412, 53412, 53411, 53411, 53411, 53411, 52703, 52703, 52501, 52703, 52467, 52824, 52703, 52501, 52501, 52703, 52703, 52501, 52703, 52703, 52501, 52501, 52501, 52502, 52500, 52502, 52500, 52501, 52825, 52502, 52834, 52502, 53085, 52502, 52500, 52502, 52834, 52500, 52500, 52500, 52834, 52501, 52834, 52834, 52500, 52502, 52502, 52502, 52502, 52502, 52500, 52500, 52502, 52501, 52502, 52500, 53093, 53085, 52500, 52501, 52834, 52502, 52834, 52834, 52500, 52500, 52500, 52500, 52834, 52834, 52500, 52500, 52500, 52834, 52834, 52500, 52501, 52834, 52500, 52500, 52500, 52501, 52834, 52834, 52500, 52834, 52834, 52834, 52834, 52834, 52500, 52834, 52834, 52834, 52501, 52834, 52834, 53143, 52834, 53093, 53093, 53143, 53093, 53085, 53143, 53093, 53085, 52834, 52500, 52834, 52834, 52834, 52834, 52834, 53143, 52834, 52834, 52834, 52834, 52834, 52834, 52834, 52834, 52500, 52834, 52834, 52834, 52834, 52834, 52834, 52834, 52444, 52834, 52834, 52834, 53085, 53085, 52834, 52500, 52834, 52834, 52500, 52834, 52500, 52834, 52834, 52500, 52834, 52834, 53080, 52822, 52500, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 50083, 50083, 50084, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50082, 50083, 50083, 50083, 50083, 50070, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 50083, 23635, 51307, 51307, 51307, 51307, 51307, 31725, 31724, 31727, 31726, 31723, 24930, 25081, 25080, 24924, 24926, 25077, 25079, 25070, 25083, 25072, 25074, 25071, 31720, 31727, 31723, 31726, 31724, 31725, 25077, 25070, 25079, 25083, 25072, 25074, 25071, 31720, 31727, 31723, 31724, 31726, 31725, 25077, 25079, 25070, 25083, 25072, 25074, 25071, 31720, 31727, 31723, 31724, 31726, 31725, 25077, 25070, 25079, 25083, 25072, 25074, 25071, 31720, 31723, 31727, 31724, 31726, 31725, 25077, 25070, 25079, 25083, 25072, 25074, 25071, 25081, 25080, 24930, 24924, 24926, 24931, 24929, 25079, 25083, 25077, 25070, 25071, 25074, 25072, 24926, 24930, 25081, 24924, 25080, 24931, 24929, 38915, 38913, 38913, 38915, 38926, 38913, 38915, 38926, 38913, 38915, 38926, 38926, 38915, 38913, 38913, 38952, 38915, 38915, 38926, 38913, 38913, 38915, 38926, 38913, 38913, 38915, 38952, 38913, 38915, 38952, 38915, 38913, 38915, 38926, 38926, 38915, 38913, 38952, 38913, 38915, 38926, 38913, 38913, 38915, 38926, 38915, 38913, 38913, 38915, 38915, 38913, 38926, 38926, 38926, 38915, 38926, 38915, 38915, 38913, 38913, 38915, 38913, 38915, 38926, 38913, 38915, 38913, 38913, 38913, 38915, 38913, 38915, 38913, 38913, 38915, 38915, 38926, 38915, 38913, 38915, 38913, 38913, 38915, 38913, 38915, 38915, 38913, 38915, 38913, 38915, 38913, 39869, 38926, 38926, 38926, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 53073, 52986, 52932, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 52791, 53805, 53823, 53823, 53823, 53823, 52791, 52834, 52834, 52500, 52500, 52834, 52502, 52834, 52500, 52500, 52834, 52834, 52834, 52500, 52834, 53085, 53093, 53143, 53085, 53093, 52502, 52834, 52500, 52500, 52500, 52500, 52500, 1890, 1890, 1890, 1890, 1890, 1570, 1890, 1568, 38898, 2307, 38899, 1737, 5749, 5667, 2126, 1569, 2124, 1661, 2123, 1739, 2117, 38911, 2116, 1740, 2113, 2115, 2122, 1741, 2119, 1736, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 1890, 36602, 36602, 34571, 36132, 50252, 36602, 36190, 36602, 36628, 36630, 36629, 36695, 38791, 36631, 36651, 50567, 36602, 36602, 36717, 36602, 36632, 36602, 36602, 36652, 36170, 36602, 36602, 36698, 36602, 36798, 36797, 36602, 38217, 38268, 38281, 38242, 42619, 42618, 38268, 42619, 38272, 42619, 38268, 39062, 38037, 38268, 38272, 38244, 38272, 38272, 38282, 38282, 38268, 38247, 39062, 38243, 38278, 38245, 38278, 38278, 38217, 38246, 38279, 38278, 38268, 38217, 38217, 38442, 38326, 38326, 38326, 38300, 38300, 38324, 38324, 38324, 38324, 38300, 38326, 38300, 38300, 38324, 38324, 38300, 38300, 38300, 38324, 38301, 38326, 38300, 38300, 38324, 38324, 38300, 38301, 38326, 38300, 38300, 38300, 38324, 38324, 38301, 38300, 38301, 38217, 38217, 38217, 38217, 38217, 38440, 38966, 39027, 38217, 38217, 38938, 38953, 38966, 38938, 38953, 38939, 3297, 5941, 5942, 49997, 50011, 3297, 10578, 3185, 3297, 3297, 3297, 3297, 7952, 3297, 3297, 3297, 3188, 3297, 3140, 3297, 6408, 3297, 3304, 50006, 3187, 3194, 50002, 10676, 3297, 49998, 50001, 3186, 3297, 50004, 50015, 3184, 3933, 10369, 3297, 41142, 51913, 39260, 39260, 39260, 39260, 51913, 51913, 39260, 39261, 39261, 39260, 39261, 39260, 39261, 39260, 39261, 39260, 39261, 39260, 39261, 39260, 39260, 39260, 39261, 39261, 39261, 39261, 39260, 39261, 39261, 39260, 39260, 39260, 51913, 51913, 51913, 51913, 51913, 12430, 5953, 5953, 5953, 5953, 3170, 5953, 3620, 3139, 5953, 3171, 5953, 3142, 5953, 5953, 5953, 3706, 5953, 3169, 3168, 5953, 3173, 5880, 5953, 5953, 9987, 3164, 3165, 5953, 5953, 5953, 6928, 3336, 5953, 3167, 5953, 3881, 5953, 11025, 3175, 3174, 5953, 3163, 5953, 5953, 3294, 5953, 3172, 5953, 5953, 5953, 5953, 5953, 6027, 5953, 3129, 37911, 37911, 39268, 39268, 39268, 39268, 39267, 37912, 37911, 39268, 39270, 37912, 37912, 39270, 39270, 37911, 37911, 37911, 37912, 37911, 37911, 37911, 37911, 37911, 37911, 39268, 39268, 37911, 37911, 39267, 39267, 37911, 39267, 39267, 37912, 37911, 39269, 39268, 39268, 39268, 39267, 39268, 39267, 39267, 37911, 37912, 37912, 39267, 39268, 37911, 37911, 39267, 37912, 39268, 39268, 39267, 39267, 39267, 39268, 39269, 39268, 39267, 39270, 37911, 37912, 39267, 37911, 37911, 37912, 37911, 37911, 39268, 39267, 39269, 39268, 37911, 39268, 39267, 39267, 39268, 37911, 37911, 37911, 39267, 37912, 39268, 39267, 39267, 39267, 39268, 39267, 39268, 39267, 39267, 39267, 39269, 39268, 39268, 39268, 39268, 39268, 39268, 39267, 39267, 39268, 39267, 39268, 39267, 39268, 39267, 39267, 39267, 39267, 39267, 39269, 39269, 39267, 39268, 39267, 39267, 39268, 39267, 5953, 51911, 39270, 39270, 39270, 37911, 39270, 39270, 39270, 37912, 37911, 39270, 37911, 37911, 39270, 37912, 37911, 37911, 37912, 37911, 39270, 39270, 37911, 3129, 37912, 37912, 39268, 39267, 39268, 39270, 5953, 5953, 5953, 5953, 5953, 5953, 5953, 5953, 3113, 3113, 3114, 3111, 3111, 3112, 3112, 3112, 3112, 3112, 3111, 3111, 3111, 3101, 3101, 3112, 3111, 3101, 3101, 3114, 3114, 3113, 3113, 3114, 3183, 3101, 3113, 3114, 3114, 3114, 3114, 3113, 3113, 3114, 3113, 3113, 3113, 3114, 3113, 3113, 3113, 3113, 3111, 3112, 3112, 3112, 3111, 3112, 34261, 3501, 3337, 34261, 34258, 3521, 3501, 3501, 34261, 3501, 3114, 3113, 3113, 3114, 3112, 3112, 3111, 3113, 3113, 3113, 3113, 5824, 3114, 3114, 3113, 3114, 3113, 3193, 3114, 3293, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 3196, 3196, 3199, 3199, 3196, 3199, 3196, 3196, 3199, 3196, 3199, 3199, 3199, 3195, 3195, 3196, 3195, 3195, 3195, 5953, 3195, 3195, 3195, 3199, 3199, 3199, 3199, 3196, 3196, 3196, 3196, 3195, 3195, 3196, 3195, 3195, 5953, 13117, 13116, 3112, 13117, 5953, 3111, 3112, 3112, 3112, 3112, 3112, 5953, 3111, 3111, 3112, 3112, 51911, 5953, 51346, 51346, 4311, 3296, 51346, 51346, 51346, 51346, 51346, 3296, 3296, 51307, 3296, 3296, 51307, 51307, 51307, 51307, 51307, 3296, 51307, 3313, 5817, 14392, 3296, 3296, 5603, 3296, 5606, 5609, 3296, 5610, 6929, 5597, 5611, 5613, 6466, 5614, 3296, 3296, 3296, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 3296, 44874, 44871, 44872, 39605, 3296, 3296, 3296, 3296, 3296, 23635, 3296, 14376, 51307, 3296, 51307, 3367, 51307, 42506, 49737, 46709, 3368, 46708, 3369, 14377, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 3296, 3296, 52032, 50488, 2857, 50323, 46716, 3310, 7010, 50477, 9317, 3412, 3296, 44919, 3296, 3296, 9564, 3296, 44158, 44158, 3296, 44158, 12136, 3329, 44158, 3296, 5639, 47247, 47246, 3296, 3216, 44158, 47248, 3296, 3296, 47253, 3296, 3296, 46741, 3325, 3326, 3324, 5815, 5875, 11066, 3296, 3335, 3330, 5816, 45230, 51346, 51346, 24930, 24924, 24929, 25081, 24931, 44158, 26537, 45230, 14375, 44735, 45230, 3296, 44725, 3331, 3189, 3296, 47233, 3327, 3334, 3328, 3296, 3296, 3296, 3296, 51346, 3296, 3323, 3296, 45230, 44723, 3296, 51346, 51346, 51346, 44158, 3296, 3296, 3296, 25077, 34765, 3296, 25079, 25072, 25070, 25074, 25083, 25071, 3296, 3296, 3296, 47571, 35068, 46556, 46555, 45337, 23128, 16012, 3144, 3296, 5910, 3296, 46142, 46142, 45339, 3314, 3296, 3296, 3296, 45015, 12796, 12798, 12790, 12791, 52549, 12797, 12789, 3296, 31727, 31725, 31724, 49622, 3296, 4047, 5188, 46359, 37072, 46358, 31726, 31723, 46357, 3370, 27815, 49750, 3312, 3342, 3296, 3296, 3296, 3296, 3296, 3296, 44878, 44851, 44877, 44876, 42637, 51346, 25077, 25079, 25070, 25083, 25072, 25074, 25071, 34717, 34715, 3084, 34721, 3084, 34719, 34718, 52536, 34723, 31720, 31723, 31727, 31726, 31724, 31725, 3296, 3296, 3296, 51307, 51307, 51307, 51307, 51307, 51307, 3296, 3296, 51307, 51307, 3296, 51911, 51911, 14498, 25071, 11017, 3413, 25072, 25074, 25070, 25083, 25079, 25077, 31726, 31727, 31724, 31725, 51307, 51307, 51307, 3296, 51307, 51307, 51307, 40891, 40890, 40890, 40890, 40890, 40890, 40890, 40890, 40890, 3197, 3198, 3198, 3198, 3197, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51307, 51307, 51307, 51307, 51307, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 34718, 51346, 3296, 40891, 51307, 3296, 51307, 40890, 40890, 51307, 51307, 51307, 51307, 51307, 3296, 3296, 4311, 51307, 51307, 3296, 3296, 3296, 40890, 40890, 51346, 3296, 51346, 51346, 40890, 40890, 40890, 40890, 3293, 3203, 3193, 3296, 3296, 3296, 3296, 3296, 3296, 51307, 51307, 51307, 51307, 3296, 44876, 51307, 44878, 44877, 14392, 44851, 51307, 51307, 31726, 31723, 31724, 31727, 31720, 3313, 3296, 5817, 3296, 3296, 3296, 3296, 6929, 5609, 3296, 5606, 3296, 5603, 5610, 5597, 6466, 5613, 5611, 5614, 3296, 3296, 3296, 39605, 3296, 3296, 49750, 3296, 44874, 3296, 3296, 3370, 51346, 51346, 51346, 51346, 51346, 3342, 44871, 51346, 14377, 44872, 27815, 5188, 3312, 49622, 4047, 3144, 46142, 3296, 16012, 45339, 23128, 46142, 3323, 3296, 45337, 3296, 3296, 47571, 46556, 46555, 35068, 3296, 3296, 3314, 3296, 3296, 3296, 51307, 3296, 3296, 14375, 47246, 3296, 3329, 47247, 3296, 47248, 3331, 47253, 3216, 3296, 3296, 3310, 44919, 50323, 50488, 46709, 42506, 49737, 3368, 46708, 3296, 3296, 3369, 50477, 51307, 44158, 51307, 14498, 52032, 2857, 3367, 51346, 2855, 5811, 3366, 7088, 46716, 7010, 51346, 51346, 51346, 3296, 3296, 3296, 23635, 3296, 6987, 14304, 46741, 46742, 51346, 6986, 3350, 3296, 3296, 14304, 3351, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 51346, 51346, 51346, 3296, 3296, 47663, 3296, 51346, 51346, 3296, 31724, 44158, 44158, 44158, 31725, 31727, 31726, 3296, 3296, 47233, 3328, 3327, 3296, 3296, 44158, 3296, 3296, 3296, 3296, 26537, 31723, 31720, 3296, 3296, 34765, 3296, 3296, 3296, 3296, 12796, 46359, 37072, 46358, 46357, 14376, 3208, 39353, 39590, 39352, 39351, 41621, 42946, 3197, 3198, 3197, 42946, 3197, 42946, 3197, 3197, 3197, 3198, 3197, 3198, 3198, 3198, 3197, 3197, 3204, 3198, 3197, 3197, 3197, 3198, 3198, 3198, 3198, 3197, 3198, 3197, 3204, 3197, 3197, 3197, 3197, 3198, 3197, 3197, 3197, 3204, 3198, 3198, 3197, 5639, 3325, 3296, 44158, 9564, 3412, 9317, 3315, 3363, 11017, 3413, 42594, 3189, 5815, 5816, 3330, 3296, 44158, 3324, 3326, 5875, 3296, 3296, 3296, 12136, 3296, 3335, 25072, 31727, 31724, 31725, 31723, 31726, 25079, 25072, 25074, 25071, 25070, 25083, 25077, 31720, 31723, 31727, 34719, 31724, 31726, 31725, 5910, 3296, 45015, 12798, 3334, 44735, 44725, 3296, 45230, 44723, 3296, 45230, 44743, 45230, 3296, 3296, 44740, 45230, 44726, 45230, 45230, 24930, 3296, 44223, 44223, 44223, 44217, 44216, 44223, 25083, 25070, 25079, 25074, 25071, 25072, 25081, 25077, 31727, 31724, 31720, 31725, 31726, 31723, 34717, 34721, 3084, 34715, 3084, 52549, 45015, 52536, 12790, 12791, 12789, 12797, 45139, 12793, 7311, 45138, 12795, 12794, 3296, 31726, 31723, 31725, 3296, 3296, 45814, 45558, 45814, 45566, 45714, 45822, 45720, 25079, 25070, 25083, 25072, 25074, 25071, 5953, 5953, 3163, 5953, 3174, 11025, 3175, 5953, 3167, 5953, 3165, 6928, 9987, 5953, 5880, 5953, 3168, 5953, 5953, 5953, 5953, 5953, 3881, 3142, 5953, 5953, 5953, 3139, 3171, 3620, 3169, 5953, 3170, 5953, 5953, 5953, 3706, 3164, 3173, 5953, 5953, 5953, 12430, 5953, 3294, 3172, 6027, 3336, 5953, 5953, 5953, 5953, 3112, 3111, 3111, 3112, 3114, 3113, 3114, 3113, 3114, 3113, 3113, 3114, 34261, 34261, 3337, 34258, 3521, 34261, 3501, 3501, 3501, 3501, 3272, 3272, 3272, 3272, 34718, 34721, 34719, 3084, 34715, 3084, 3501, 3501, 3501, 3488, 3477, 3428, 3483, 3479, 3490, 3390, 3431, 9981, 3481, 3501, 3482, 3615, 5871, 50033, 3934, 3448, 3501, 3429, 3478, 50028, 3501, 50029, 3501, 50027, 50032, 3501, 3480, 3338, 3658, 3501, 50022, 50031, 3501, 34545, 3269, 3269, 34545, 3265, 3269, 34545, 3269, 3269, 3265, 34545, 3269, 3269, 3269, 3269, 3269, 34503, 3296, 3296, 51346, 51346, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 45015, 45015, 45015, 45015, 45015, 5640, 45015, 45015, 45015, 45029, 45008, 3399, 3400, 53081, 8404, 9988, 11814, 45095, 45086, 45081, 45094, 45093, 45015, 45015, 45015, 45015, 45015, 44975, 7311, 3405, 3404, 45015, 51346, 51346, 51346, 45139, 30706, 45137, 45138, 45015, 45019, 45023, 45015, 45015, 52536, 52549, 45015, 45015, 45015, 45015, 12793, 12795, 12790, 12794, 12791, 12798, 12797, 45814, 45814, 3296, 46080, 46082, 46078, 45709, 45814, 45822, 45822, 3296, 52170, 30611, 45548, 45822, 45822, 45549, 45814, 45814, 45566, 45822, 45827, 45822, 51346, 51346, 45717, 45814, 3296, 45563, 45714, 45720, 45713, 3296, 45553, 45558, 12796, 3296, 3296, 3296, 3296, 46358, 37072, 46357, 46359, 3296, 3296, 3296, 3314, 14376, 3296, 3296, 3296, 5188, 39605, 51346, 51346, 51346, 46555, 46142, 45339, 35068, 46556, 46142, 49622, 4047, 3296, 3370, 49750, 3144, 3296, 16012, 45337, 47571, 3296, 27815, 3342, 3296, 3312, 3323, 3296, 3296, 14375, 3296, 14377, 3296, 3296, 44872, 3296, 3296, 3296, 3296, 6929, 44871, 44874, 3296, 3296, 5613, 5614, 5609, 6466, 5606, 5597, 5603, 5611, 5610, 3296, 3296, 3296, 51307, 42506, 49737, 3310, 46709, 51307, 51307, 3368, 50323, 3296, 50488, 46708, 50477, 3329, 3369, 3216, 9564, 3296, 3296, 52032, 14498, 3296, 46716, 5639, 7010, 2857, 3412, 9317, 3296, 11017, 3413, 3296, 3296, 44919, 44158, 44158, 44158, 12136, 3296, 44158, 3296, 44158, 3296, 3296, 31724, 31725, 31727, 3296, 47247, 47246, 44158, 31726, 47248, 26537, 31723, 3296, 3331, 47253, 3326, 3324, 5815, 5875, 3296, 3296, 3335, 47233, 45230, 3189, 45230, 3327, 44735, 3330, 3328, 5816, 44725, 3334, 51346, 51346, 31720, 3296, 3296, 3296, 44158, 3296, 3296, 46741, 3296, 46742, 3296, 3345, 11066, 46181, 3296, 8659, 3366, 3350, 3296, 5811, 3351, 3348, 3296, 3296, 7088, 3347, 11046, 3363, 2855, 3296, 3296, 14304, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 14304, 3296, 3296, 3296, 49750, 3296, 16076, 43239, 3296, 46622, 3296, 3296, 23635, 3332, 3333, 3296, 3296, 47663, 7951, 3296, 46642, 42707, 4485, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 46667, 3353, 3354, 3296, 3296, 13842, 50678, 35364, 3296, 3296, 3296, 3296, 3296, 3296, 34955, 49573, 3296, 3296, 3296, 3296, 3296, 3357, 3358, 3296, 3409, 3361, 7230, 7792, 3360, 7793, 4043, 7231, 7790, 5812, 3356, 3296, 11177, 3355, 11176, 11178, 10266, 51307, 51307, 3296, 51307, 51307, 3296, 51307, 51307, 51307, 25083, 25070, 25077, 25079, 25074, 25071, 25072, 3501, 3489, 3501, 3484, 3485, 50035, 50034, 3486, 3265, 3269, 3269, 45814, 45814, 45718, 45830, 45565, 3296, 3296, 3296, 25072, 3296, 3296, 34765, 44878, 44851, 44877, 44876, 51307, 51307, 51307, 14392, 51307, 51307, 3296, 3296, 51307, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 51307, 51307, 51307, 51307, 51307, 51307, 51307, 3296, 3296, 3296, 4311, 3296, 3293, 5953, 5953, 5953, 3163, 3174, 3175, 11025, 5953, 3167, 5953, 3165, 6928, 9987, 5953, 5953, 5880, 3168, 5953, 5953, 5953, 5953, 5953, 3142, 5953, 3139, 3171, 3620, 3170, 5953, 3169, 3164, 5953, 3173, 3706, 5953, 5953, 5953, 5953, 5953, 12430, 5953, 3294, 3172, 6027, 13117, 13116, 3336, 3313, 5817, 25071, 25074, 45814, 45552, 3501, 34504, 3501, 34503, 34503, 34503, 34504, 34503, 3501, 34503, 3269, 3269, 34503, 3265, 34503, 3271, 34503, 3269, 3501, 3501, 3487, 3501, 3501, 8306, 3443, 14859, 8307, 34545, 3269, 3269, 3269, 34503, 34503, 34503, 34503, 3501, 34503, 34503, 34560, 34503, 34503, 34503, 3432, 34503, 3501, 34503, 34504, 43946, 14873, 34504, 34504, 34503, 34503, 34509, 34503, 5907, 34503, 34503, 34503, 43946, 34503, 34513, 34503, 34503, 34545, 3269, 34545, 3265, 3265, 34545, 3269, 34545, 34544, 34545, 3269, 3269, 3269, 34545, 3269, 3269, 3265, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34513, 5907, 3501, 43946, 3501, 34504, 34503, 3501, 3269, 3269, 34545, 3265, 34545, 34545, 3269, 3269, 34545, 3269, 3269, 34545, 34545, 34545, 3269, 3265, 34503, 34545, 5768, 5767, 3678, 3840, 3673, 3671, 3840, 3840, 3670, 3669, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 36798, 36797, 36628, 36631, 36602, 34571, 36170, 50252, 36652, 36695, 36632, 36190, 50567, 38791, 36651, 36717, 12160, 12160, 12160, 12160, 12160, 12160, 12160, 12160, 3588, 3592, 12160, 3587, 6091, 3589, 3596, 12160, 43006, 12160, 12160, 3595, 12160, 3597, 12160, 12160, 12160, 3594, 12160, 3593, 12160, 12160, 12160, 2079, 2077, 2079, 49477, 2079, 7235, 7235, 2008, 7235, 7235, 7235, 7235, 7235, 2008, 7235, 7235, 2007, 2008, 2007, 2083, 3601, 3571, 43005, 3571, 3567, 3598, 3609, 3610, 3571, 3600, 3608, 3571, 3571, 2078, 34761, 2081, 6736, 3571, 3571, 3571, 3571, 3599, 3614, 4266, 3603, 6286, 3571, 3571, 3602, 12429, 2007, 2008, 2008, 2008, 2008, 2008, 2008, 2008, 2007, 2008, 2007, 2008, 2003, 2002, 2002, 2005, 2003, 2003, 2003, 2002, 2003, 2002, 2005, 2004, 2004, 2004, 2004, 2004, 2005, 2004, 2004, 2004, 2004, 2005, 2004, 2005, 2003, 2005, 2002, 2002, 2003, 2002, 2002, 2003, 2002, 2002, 2003, 2003, 2002, 2002, 2002, 2005, 2002, 2002, 2005, 2002, 2003, 2004, 2005, 2004, 2004, 2004, 2002, 2003, 2003, 2008, 2008, 2008, 2008, 2008, 2007, 2008, 2008, 7235, 7235, 7235, 7235, 7235, 7235, 7235, 7235, 7235, 7235, 2008, 7235, 2008, 7235, 7235, 7235, 7235, 2008, 7235, 2008, 2007, 2010, 10604, 2151, 10606, 2010, 2011, 2010, 2010, 2011, 2011, 2011, 2011, 2010, 2011, 2009, 2009, 2010, 2011, 2009, 2010, 2010, 2010, 2010, 2011, 2010, 2009, 2010, 2010, 2010, 2011, 2011, 2011, 2010, 2009, 2011, 2010, 2010, 7318, 2010, 2010, 2010, 2010, 2010, 2010, 7317, 2009, 2009, 2010, 2009, 2010, 2010, 2011, 2011, 2009, 2009, 2011, 2009, 2010, 2010, 2010, 2009, 2009, 2009, 2009, 2010, 2009, 2009, 2010, 2009, 2010, 2010, 2009, 2010, 2010, 2011, 2011, 2010, 2010, 2011, 2010, 2009, 2009, 2009, 2009, 2009, 2011, 2010, 2011, 2011, 2009, 2009, 2009, 2009, 2009, 2010, 7318, 2009, 2009, 2009, 2010, 2011, 2009, 2011, 2011, 2010, 3517, 6287, 4262, 4262, 4262, 4262, 6735, 4262, 11083, 6292, 4262, 4262, 4262, 4262, 4262, 4262, 4262, 4262, 4262, 4262, 11042, 51371, 4226, 4087, 7315, 51371, 11041, 34988, 4160, 4088, 50668, 51371, 34989, 51371, 4262, 51371, 4262, 51371, 4262, 4262, 4210, 52642, 4223, 49748, 4262, 4262, 4163, 4214, 50307, 4262, 4262, 51371, 51371, 51371, 51371, 4262, 4262, 5782, 4203, 14379, 51371, 8026, 6142, 4089, 52640, 52641, 4262, 4262, 4262, 4262, 4262, 51371, 4262, 4262, 8665, 4262, 4230, 14378, 11709, 4262, 51371, 4169, 4262, 4232, 4171, 4262, 4262, 7907, 4262, 4262, 4262, 4262, 4262, 4262, 3607, 10118, 4262, 4262, 4222, 4221, 4156, 7999, 4262, 4262, 4262, 4204, 4262, 17105, 4262, 4090, 4262, 3562, 4165, 35281, 4091, 52292, 4262, 4262, 4262, 50690, 50715, 4262, 4262, 4262, 4262, 4262, 4262, 8396, 4262, 47569, 7740, 4092, 50714, 36506, 4215, 2796, 3561, 10089, 4146, 4217, 4220, 4205, 4138, 9047, 4218, 4219, 7296, 51371, 52636, 52637, 52643, 30715, 47584, 14380, 25010, 25018, 25013, 25014, 25017, 25016, 25011, 25009, 25012, 25009, 25011, 25012, 25018, 25010, 25014, 25013, 25016, 25017, 28650, 6086, 6086, 29712, 29712, 51348, 51348, 51348, 51348, 25016, 25013, 25018, 25014, 25010, 25011, 25012, 25017, 25009, 25053, 25055, 25054, 25052, 25051, 25056, 25052, 25051, 25056, 25055, 25054, 25053, 34987, 25051, 25052, 25056, 25054, 25055, 25053, 33115, 33115, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 33115, 49942, 32969, 49927, 49968, 32969, 32969, 49923, 49940, 43429, 32969, 32969, 51997, 11037, 32969, 32969, 49939, 32969, 32969, 43431, 32969, 32969, 3841, 32969, 32969, 33115, 3501, 50027, 3501, 3501, 3501, 5768, 5767, 3678, 3840, 3673, 3671, 3840, 3840, 3670, 3669, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3501, 3501, 3490, 3501, 3501, 3501, 46890, 46890, 46902, 46890, 46906, 46889, 46890, 48229, 48229, 47297, 48229, 48229, 48229, 48229, 48229, 48229, 48229, 48229, 48229, 48229, 48229, 48229, 48262, 48262, 48278, 48441, 48440, 48440, 48442, 48442, 48440, 48440, 48441, 48440, 48445, 48441, 48445, 48441, 48278, 48440, 48441, 48278, 48445, 48439, 48445, 48439, 48439, 48445, 48439, 48439, 46890, 46890, 46902, 46890, 46906, 46889, 46890, 48229, 48229, 47297, 48229, 34261, 3337, 34261, 34258, 34261, 3501, 3521, 3501, 3501, 3501, 5810, 43956, 34284, 3267, 3267, 14901, 3267, 14901, 3267, 3265, 3267, 3267, 3267, 3265, 3265, 3265, 3267, 3265, 3267, 3267, 3267, 3266, 3266, 3268, 3265, 3266, 3267, 3265, 3266, 3266, 3268, 3265, 3267, 3268, 3266, 3268, 3266, 3266, 3268, 3268, 3266, 3268, 3266, 3266, 3266, 3266, 3266, 3266, 3268, 3268, 3266, 3268, 3268, 3266, 3266, 3268, 3268, 3266, 3268, 3266, 3268, 3268, 3268, 34545, 3268, 3266, 3266, 34545, 3266, 3266, 3268, 3266, 3268, 3268, 3266, 3268, 3266, 3266, 3268, 3268, 3268, 3265, 3267, 3265, 3267, 3265, 3267, 3267, 3267, 3265, 3267, 3267, 34504, 34503, 34504, 34504, 3501, 3501, 3501, 34513, 5907, 34503, 43946, 34503, 34503, 3432, 3501, 34503, 34503, 34503, 34560, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34503, 34594, 34594, 34594, 34594, 34594, 34594, 14893, 3501, 3501, 3269, 34594, 34594, 34594, 34594, 3501, 14857, 3501, 3501, 34594, 34594, 50029, 50028, 3501, 3501, 3501, 3501, 3501, 38217, 38268, 38281, 38242, 38268, 42619, 42619, 42618, 38272, 42619, 38268, 39062, 38037, 38268, 38272, 38244, 38272, 38272, 38247, 38282, 38282, 38268, 39062, 38243, 38278, 38245, 38278, 38246, 38217, 38278, 38279, 38268, 38278, 38217, 51788, 38442, 38326, 38326, 38326, 38300, 38324, 38324, 38324, 38300, 38326, 38324, 38300, 38300, 38300, 38300, 38324, 38324, 38300, 38301, 38324, 38301, 38326, 38324, 38324, 38300, 38326, 38324, 38300, 38324, 38300, 38300, 38217, 38217, 38217, 38217, 38217, 38440, 38966, 39027, 38217, 38938, 38953, 39072, 39028, 39028, 39028, 39028, 39028, 39028, 39028, 39028, 39028, 39028, 39028, 39028, 39028, 39027, 39028, 38440, 38931, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38301, 38326, 38324, 38300, 38300, 38324, 38300, 38324, 38301, 38300, 38326, 38300, 38324, 38324, 38300, 38300, 38324, 38326, 38300, 38300, 38326, 38300, 38217, 38300, 38442, 38300, 38300, 38300, 38301, 38440, 38300, 38300, 38217, 38300, 38423, 38225, 38437, 38301, 38300, 38300, 38300, 38301, 38301, 38300, 38300, 38300, 38300, 38301, 38217, 38300, 38301, 38300, 38300, 38301, 38300, 38301, 38300, 38300, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38301, 38300, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38301, 38301, 38301, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38301, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38301, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38301, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38300, 38300, 38300, 38300, 38301, 38300, 38300, 38301, 38966, 38939, 5941, 5942, 3297, 51913, 3297, 3297, 3297, 3297, 50011, 49997, 3297, 3297, 3297, 3297, 3297, 10578, 3297, 3185, 3188, 6408, 7952, 3304, 3140, 3187, 3194, 3297, 10676, 50006, 50002, 49998, 50001, 3186, 50004, 3297, 3184, 50015, 3933, 3297, 10369, 3297, 41142, 51913, 39260, 39260, 39260, 39260, 39260, 39260, 51913, 39260, 39261, 39261, 39261, 39260, 39260, 39260, 39261, 39260, 39261, 39260, 39260, 39260, 39261, 39261, 39260, 39260, 39260, 39260, 39261, 39261, 39261, 39261, 39260, 39260, 42218, 42218, 42218, 42218, 951, 49874, 49874, 49869, 49874, 49869, 1642, 1642, 1642, 1642, 152, 49874, 1213, 42216, 42218, 42218, 49874, 197, 49869, 43278, 49874, 49874, 49869, 49874, 49874, 49874, 49874, 49874, 49869, 49874, 78, 49869, 49869, 49874, 49874, 49869, 49869, 49874, 196, 49869, 49874, 50039, 50039, 50039, 49869, 50039, 50039, 49874, 198, 375, 459, 915, 6373, 49874, 49874, 925, 49869, 49874, 49874, 49874, 49869, 49874, 49874, 49874, 11260, 11260, 11260, 50039, 49874, 49874, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 50039, 49874, 49874, 50039, 50039, 62, 50039, 49874, 49874, 49874, 50039, 50039, 50039, 50039, 49874, 49874, 49874, 49874, 49874, 49874, 49874, 49874, 49874, 49874, 49874, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 49874, 49874, 49874, 49874, 49874, 49874, 49874, 49874, 94, 94, 6367, 1423, 42937, 42937, 42937, 42937, 42937, 42938, 42937, 42938, 49874, 94, 6306, 1651, 465, 1430, 3935, 6374, 151, 917, 377, 906, 328, 1423, 240, 514, 2046, 1423, 1423, 241, 913, 927, 46983, 794, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 94, 94, 94, 94, 94, 94, 1423, 4959, 28569, 28596, 28596, 28569, 1976, 28596, 28569, 28596, 12779, 1976, 19848, 52546, 35477, 12780, 68, 1302, 12784, 52545, 12785, 1303, 12786, 52537, 12781, 12787, 49877, 68, 483, 4981, 482, 68, 1976, 1976, 68, 51348, 51348, 51348, 51348, 51348, 42421, 51348, 51348, 51348, 1976, 14423, 51348, 3518, 68, 1285, 51348, 51348, 51348, 28569, 4974, 1432, 28569, 28596, 28596, 1976, 28569, 28596, 1275, 28596, 51348, 51348, 51348, 28569, 1257, 68, 12480, 49748, 1289, 1287, 12481, 14438, 14439, 68, 68, 68, 68, 68, 1297, 1431, 1298, 1301, 51348, 44583, 68, 68, 51348, 51348, 68, 68, 1976, 68, 68, 68, 68, 1976, 1478, 1477, 68, 1319, 1321, 68, 11096, 1292, 1339, 68, 28347, 28355, 1976, 12783, 1323, 1328, 12805, 918, 43694, 13283, 51998, 8383, 1325, 914, 1326, 44249, 5480, 44247, 6946, 5479, 43277, 6089, 1327, 5482, 340, 5483, 6090, 68, 68, 116, 94, 94, 94, 94, 94, 94, 241, 68, 240, 1423, 68, 1976, 42421, 1756, 1756, 68, 5384, 54216, 54217, 54218, 42421, 656, 1371, 1368, 42421, 1370, 42421, 1472, 1976, 5517, 5515, 5516, 1976, 5413, 1976, 68, 957, 1976, 5512, 5511, 29725, 68, 7798, 68, 5510, 45306, 44236, 6579, 20407, 43034, 5519, 5518, 11026, 5513, 68, 5514, 68, 1416, 7232, 68, 49748, 1976, 5509, 68, 68, 68, 42421, 1284, 51348, 51348, 51348, 43840, 44395, 47688, 1976, 94, 1423, 241, 68, 68, 116, 475, 40, 475, 40, 40, 475, 475, 40, 40, 475, 40, 475, 116, 116, 116, 40, 40, 40, 475, 40, 40, 40, 40, 40, 40, 475, 40, 40, 40, 327, 327, 475, 40, 475, 475, 475, 40, 475, 40, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 36602, 36205, 50252, 36630, 36190, 36629, 50567, 38791, 36651, 36717, 36695, 36652, 36631, 36809, 36809, 36809, 36810, 36810, 36810, 36810, 36810, 36809, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36779, 36632, 34571, 36132, 36170, 36798, 36698, 36602, 36602, 36809, 36809, 36809, 36809, 36809, 36809, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36809, 36810, 36810, 36809, 36809, 36809, 36810, 36810, 36810, 36810, 36809, 36809, 36809, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36810, 36809, 36810, 36809, 36810, 36809, 36810, 36810, 36810, 36809, 36809, 36810, 36810, 34864, 34850, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 39095, 34864, 39095, 34916, 34913, 34916, 34916, 34936, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 35840, 38853, 35874, 47091, 35872, 35869, 35870, 35873, 35871, 35839, 47091, 47091, 47091, 39095, 35232, 39095, 35232, 35232, 35232, 35232, 35232, 35232, 35112, 35232, 35232, 35115, 35232, 35232, 35232, 35232, 35232, 35232, 35232, 39095, 35232, 35232, 50371, 39095, 35232, 39095, 35232, 35124, 39095, 35378, 35550, 35504, 35906, 35504, 35504, 35504, 35509, 35509, 35509, 35504, 35509, 35509, 35504, 35504, 35504, 35504, 35509, 35509, 35504, 35509, 35504, 35509, 35509, 50474, 50474, 35915, 35915, 50474, 35915, 50474, 50474, 50474, 50474, 50474, 44469, 44468, 44461, 44460, 44459, 44465, 44464, 35552, 35911, 44455, 35551, 36057, 36057, 36057, 36057, 36057, 36057, 36057, 36057, 36057, 36057, 36057, 35618, 36057, 36057, 36057, 35566, 41015, 41015, 41015, 41015, 41015, 41015, 41015, 41015, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 79, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 40, 475, 40, 40, 40, 40, 40, 40, 475, 327, 40, 40, 327, 475, 40, 475, 40, 40, 475, 40, 475, 40, 475, 475, 40, 40, 475, 40, 475, 40, 475, 475, 475, 475, 475, 475, 475, 40, 475, 475, 475, 475, 475, 475, 40, 40, 475, 475, 475, 475, 475, 40, 475, 40, 40, 40, 475, 40, 40, 475, 475, 475, 40, 475, 475, 475, 40, 40, 475, 40, 475, 40, 40, 475, 40, 40, 475, 475, 475, 40, 68, 241, 1423, 12423, 116, 1423, 285, 116, 735, 735, 735, 735, 285, 285, 735, 735, 735, 116, 116, 116, 1423, 1423, 1423, 1423, 958, 285, 285, 735, 285, 285, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 94, 94, 94, 94, 94, 583, 482, 1367, 1756, 1756, 1756, 51348, 51348, 51348, 1756, 45253, 29611, 1752, 1756, 4960, 1756, 1756, 1756, 1439, 1756, 1756, 1756, 1756, 1756, 1756, 1750, 1756, 34998, 1751, 1756, 1747, 34997, 35365, 1756, 44241, 1756, 44238, 44239, 44243, 2504, 51348, 116, 116, 116, 94, 116, 94, 116, 116, 116, 40, 40, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 285, 285, 735, 735, 735, 735, 285, 285, 285, 285, 285, 285, 285, 285, 94, 94, 94, 94, 94, 116, 116, 116, 94, 116, 94, 116, 116, 116, 94, 94, 474, 474, 474, 116, 116, 474, 474, 116, 116, 116, 474, 474, 116, 116, 116, 116, 94, 583, 94, 94, 94, 94, 94, 474, 474, 99, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 475, 258, 250, 475, 475, 97, 97, 478, 478, 97, 478, 478, 478, 97, 475, 475, 475, 40, 475, 475, 40, 40, 475, 475, 475, 46983, 927, 241, 1423, 514, 240, 1423, 285, 285, 285, 285, 735, 285, 735, 735, 735, 285, 285, 285, 285, 116, 40, 40, 475, 475, 40, 475, 40, 475, 40, 40, 40, 475, 475, 40, 40, 475, 327, 475, 475, 475, 475, 327, 79, 475, 94, 5493, 68, 11068, 46180, 1312, 68, 68, 338, 1316, 5386, 1976, 42288, 49701, 30713, 5566, 1976, 5503, 5500, 1313, 5499, 52031, 1976, 4078, 2485, 1308, 1976, 2708, 68, 68, 68, 68, 68, 1976, 68, 1305, 1976, 5495, 1435, 5520, 6267, 5496, 461, 5498, 5694, 1976, 331, 1976, 68, 68, 5494, 68, 1444, 14497, 1976, 1976, 68, 1348, 10782, 68, 1351, 5491, 5484, 928, 5492, 68, 68, 68, 68, 656, 5384, 68, 1976, 20407, 43034, 68, 49748, 68, 68, 1756, 1756, 51348, 42421, 6090, 116, 94, 94, 94, 94, 94, 94, 94, 94, 913, 46983, 927, 1423, 2046, 240, 1423, 328, 42218, 241, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 12423, 285, 735, 735, 735, 958, 1423, 1423, 1423, 1423, 1423, 11328, 11328, 11328, 11328, 1198, 11328, 42256, 1650, 13159, 732, 46, 732, 732, 46, 732, 732, 732, 46, 474, 478, 478, 40, 40, 476, 476, 40, 40, 40, 40, 40, 476, 40, 40, 476, 40, 40, 476, 476, 40, 40, 40, 40, 40, 476, 40, 40, 40, 40, 40, 476, 40, 40, 40, 40, 40, 40, 40, 40, 735, 116, 735, 285, 735, 735, 735, 116, 116, 735, 116, 285, 735, 474, 116, 735, 735, 844, 732, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 732, 46, 732, 732, 732, 46, 13159, 13159, 13159, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 735, 285, 285, 285, 285, 94, 94, 94, 94, 13116, 97, 478, 478, 478, 1645, 1249, 1423, 1423, 1423, 963, 1423, 1423, 1423, 1423, 955, 1423, 1423, 1423, 1423, 1423, 1423, 1423, 1423, 1423, 1423, 1423, 478, 478, 478, 478, 97, 478, 478, 478, 97, 478, 478, 478, 478, 478, 478, 478, 478, 97, 478, 478, 478, 478, 97, 478, 97, 100, 478, 478, 478, 478, 478, 478, 97, 448, 478, 42259, 478, 478, 478, 478, 46940, 46942, 46941, 448, 97, 478, 478, 478, 478, 478, 478, 51519, 1423, 1423, 237, 42497, 500, 1065, 42387, 42387, 42387, 42387, 117, 117, 117, 117, 500, 94, 94, 474, 474, 94, 116, 94, 116, 116, 116, 116, 99, 116, 94, 116, 474, 94, 94, 94, 94, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 735, 1423, 13116, 732, 732, 1423, 13159, 732, 732, 46, 732, 46, 46, 46, 732, 732, 732, 46, 46, 46, 732, 732, 732, 46, 46, 46, 46, 474, 474, 732, 474, 732, 732, 46, 46, 46, 46, 46, 46, 732, 46, 46, 732, 732, 46, 46, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 51519, 51519, 116, 116, 116, 116, 116, 116, 116, 116, 116, 13159, 42218, 42218, 42218, 42218, 42218, 285, 285, 241, 1423, 94, 94, 94, 94, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 42937, 49874, 42937, 42937, 42937, 42937, 42937, 42938, 14390, 14390, 14390, 14390, 14390, 14393, 14390, 14393, 14390, 14437, 7028, 7028, 7028, 7028, 7028, 7028, 7028, 7028, 7028, 7028, 7028, 24819, 24819, 24819, 24818, 24818, 24818, 8566, 8566, 5861, 5860, 5861, 5860, 5860, 5861, 5862, 47311, 5861, 5861, 5862, 5861, 41175, 41146, 41237, 41237, 41175, 41175, 41175, 41181, 41146, 41175, 41181, 41237, 41175, 41175, 41181, 41175, 41182, 41181, 41175, 41175, 41182, 41182, 41182, 41182, 41182, 41237, 41175, 41181, 41175, 41175, 41237, 41181, 41175, 41175, 41175, 41175, 41181, 41175, 41146, 41146, 41181, 41175, 41182, 41146, 41181, 41181, 41182, 41181, 41181, 41182, 41175, 41146, 41181, 41175, 41146, 41181, 41146, 41175, 41175, 41181, 41181, 41175, 41182, 41146, 41237, 727, 727, 6119, 5612, 6328, 1252, 41335, 40951, 1375, 1234, 1229, 1373, 1247, 9980, 2326, 1691, 1232, 1228, 727, 1226, 6806, 1267, 11941, 43464, 727, 727, 727, 41181, 41393, 41393, 41393, 41335, 41335, 41335, 41363, 7954, 41393, 727, 41393, 41393, 7955, 41335, 41335, 41393, 727, 727, 727, 5595, 5595, 5595, 5595, 5595, 6181, 52335, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 49748, 5595, 5595, 5109, 5595, 5595, 5110, 51383, 5595, 27478, 13843, 27816, 5595, 5112, 5595, 14183, 5111, 14363, 5102, 5106, 5595, 5595, 5103, 5107, 5595, 5595, 5595, 5595, 5595, 5595, 42131, 42928, 5595, 5595, 2918, 5595, 5595, 5595, 5595, 8879, 5595, 5595, 42146, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 5595, 6291, 5595, 5595, 6031, 5595, 11146, 5595, 4259, 11145, 10276, 10277, 51383, 51383, 4258, 5595, 50308, 1573, 5595, 50309, 5595, 5595, 5595, 5595, 5595, 5163, 47582, 5595, 11065, 52584, 4254, 5595, 5595, 30717, 4256, 5160, 35073, 5159, 23127, 5595, 5595, 14367, 11029, 5175, 5137, 11028, 5138, 6169, 5178, 5177, 51383, 51383, 5595, 5101, 5100, 5595, 5130, 2790, 1253, 3177, 1265, 41611, 41611, 41578, 41611, 41611, 1261, 41611, 41611, 41611, 4772, 41611, 13076, 41671, 41671, 1117, 1115, 41671, 1115, 41671, 1115, 41671, 1115, 41671, 1117, 1117, 41671, 1117, 41671, 41671, 41671, 1117, 41671, 1119, 1115, 41671, 41671, 1117, 41671, 41671, 41671, 41671, 727, 727, 727, 41804, 41786, 41763, 41763, 41763, 41763, 41763, 41763, 1960, 13076, 13076, 13076, 44162, 44161, 44162, 44161, 44161, 44162, 1280, 2510, 2512, 49781, 49806, 44345, 1963, 49782, 49793, 1340, 2506, 2517, 49808, 49791, 2516, 44162, 2509, 1278, 44161, 2513, 2508, 1173, 1173, 1173, 1173, 1176, 1279, 44197, 1172, 1176, 1172, 1173, 1172, 1177, 1173, 1172, 1173, 1173, 1173, 1336, 1343, 1334, 44200, 1335, 1331, 1332, 1177, 1173, 1469, 1337, 6241, 49784, 2518, 2514, 44162, 44161, 44161, 44162, 44162, 41763, 41763, 41763, 41763, 41763, 41763, 41671, 1117, 1115, 41671, 1117, 1117, 41671, 1117, 41671, 41671, 1117, 1117, 41671, 41671, 1117, 1117, 1117, 1117, 41671, 1117, 1117, 1115, 1117, 1115, 47395, 47395, 47395, 47395, 47395, 47395, 1701, 1256, 1358, 47395, 47395, 50631, 47395, 13076, 13076, 47395, 47395, 1698, 1237, 1360, 1355, 13076, 1977, 41846, 13076, 1679, 13076, 13076, 13076, 41611, 41611, 41611, 727, 727, 1959, 5595, 5595, 1703, 51383, 5595, 5595, 14365, 5595, 1376, 727, 5392, 1702, 41175, 41181, 41146, 5862, 5861, 5860, 5860, 5860, 7028, 49874, 49869, 49874, 49874, 49874, 49874, 42937, 94, 94, 94, 94, 94, 94, 94, 94, 94, 1218, 1215, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 844, 285, 473, 880, 881, 116, 116, 116, 116, 116, 116, 116, 46, 880, 473, 881, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 3501, 3448, 50028, 50029, 3480, 50032, 3658, 50027, 3934, 3501, 3482, 3501, 3429, 3615, 3501, 3481, 50033, 50022, 50031, 5871, 3390, 3431, 3501, 3490, 3501, 9981, 3484, 3485, 3501, 50035, 3489, 50034, 3486, 3487, 3501, 3501, 3428, 3479, 3483, 3501, 3488, 3478, 3477, 3501, 8307, 8306, 3443, 14859, 3502, 16418, 34651, 34656, 3464, 3491, 3499, 3572, 6791, 10063, 3339, 3492, 3493, 3292, 3502, 8496, 3498, 3446, 5629, 3497, 3496, 8119, 3665, 3453, 9558, 3502, 3502, 3502, 3502, 7161, 3494, 8738, 3391, 3495, 3502, 3502, 3113, 3113, 3113, 3114, 3113, 3265, 40890, 40890, 40890, 40890, 40890, 40890, 40890, 40890, 40891, 4311, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 51307, 51307, 51307, 51307, 3296, 3296, 5817, 14392, 3296, 3296, 5603, 5606, 3296, 5609, 3296, 5610, 6929, 5597, 5611, 5613, 5614, 6466, 3296, 3296, 44871, 44872, 44874, 3342, 3296, 3296, 3296, 39605, 3296, 3296, 51307, 51307, 49737, 3296, 3296, 46709, 3296, 3296, 3368, 3296, 46708, 3369, 14498, 2857, 3412, 52032, 11017, 9317, 46716, 3296, 51346, 3413, 3296, 51346, 50488, 50323, 3310, 50477, 3296, 44158, 3296, 44919, 9564, 3296, 44158, 44158, 12136, 3296, 3329, 3296, 3296, 3296, 47246, 3216, 47247, 31724, 31725, 3296, 47248, 5639, 3331, 3296, 31726, 47253, 26537, 3296, 3325, 31723, 44158, 3296, 3326, 3324, 5815, 5875, 3296, 3296, 3335, 47233, 3327, 3328, 3189, 3330, 5816, 45230, 45230, 44735, 45230, 3296, 44725, 3334, 51346, 3296, 44158, 3296, 3296, 3296, 46556, 46555, 47571, 3323, 3296, 45337, 23128, 35068, 16012, 3144, 3312, 46142, 46142, 45339, 4047, 49622, 3314, 27816, 3296, 3296, 3296, 5188, 3296, 3296, 12796, 3370, 3296, 49750, 3296, 14377, 46359, 37072, 46358, 46357, 3296, 3296, 3296, 3296, 14375, 3296, 3296, 44878, 44851, 44877, 44876, 51307, 3296, 51307, 51307, 51307, 51307, 51307, 3296, 3296, 51307, 51307, 3296, 3296, 3293, 5953, 5953, 5953, 3163, 3174, 3175, 11025, 5953, 3167, 5953, 3165, 6928, 9987, 5953, 5880, 3168, 5953, 5953, 5953, 5953, 5953, 3881, 5953, 3139, 3171, 3620, 3170, 3164, 5953, 3169, 5953, 3336, 3173, 3706, 5953, 5953, 5953, 5953, 12430, 5953, 5953, 3172, 6027, 5953, 23635, 3296, 3296, 25071, 25072, 25074, 25070, 25083, 25079, 25077, 7010, 45230, 44723, 3296, 45230, 45230, 44743, 3296, 45230, 45230, 44740, 34765, 3296, 5910, 3296, 45015, 12798, 12790, 12791, 3296, 52549, 12797, 12789, 34715, 3084, 3084, 34721, 34718, 34719, 14376, 3315, 3363, 2855, 3296, 5811, 3366, 7088, 3367, 46741, 3296, 46742, 14304, 3296, 3296, 3296, 3296, 3296, 14304, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 47663, 3296, 25083, 25071, 25074, 25072, 25077, 25079, 25070, 31727, 31724, 31725, 31720, 31726, 31723, 3296, 45814, 45558, 34723, 34717, 12794, 30611, 3296, 52536, 12795, 45814, 12793, 45566, 45714, 45720, 45822, 45822, 45822, 45822, 45814, 45827, 45814, 45717, 45822, 45553, 45822, 45563, 45015, 45814, 45138, 45709, 45713, 46080, 46078, 30706, 46082, 45137, 45814, 45019, 45552, 45023, 45830, 45814, 45565, 45549, 52170, 45548, 45814, 45015, 45718, 45015, 7311, 45139, 45015, 45015, 44975, 45029, 3399, 3400, 45008, 53081, 45015, 45093, 45094, 45015, 11814, 45015, 45015, 45086, 45081, 9988, 3405, 3404, 45015, 45095, 45015, 45015, 45015, 5640, 3296, 45015, 3296, 3296, 45015, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 3296, 14873, 34504, 3501, 34503, 34504, 34504, 3501, 34503, 34503, 34504, 34503, 3501, 3269, 34503, 34503, 34503, 3269, 3269, 34503, 3265, 3271, 3269, 34594, 34594, 34594, 34594, 34594, 34594, 3501, 3501, 3501, 3840, 3673, 3840, 3840, 5768, 5767, 3678, 3840, 3671, 3840, 3670, 3840, 3669, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 3840, 94, 94, 94, 94, 94, 13116, 68, 11068, 46180, 1312, 68, 1316, 338, 42288, 49701, 30713, 5566, 5503, 1976, 5500, 1313, 52031, 5499, 4078, 2485, 1976, 2708, 331, 1141, 1976, 5498, 1311, 1308, 1976, 1976, 68, 1435, 5496, 5495, 5520, 461, 6267, 1976, 68, 68, 68, 68, 68, 68, 47030, 47030, 47030, 47030, 47293, 51400, 47031, 47031, 3877, 3877, 3877, 3873, 47145, 4278, 3887, 3272, 3272, 3272, 3272, 3273, 3273, 3501, 3501, 3501, 3501, 3501, 3501, 3501, 3501, 3501, 3501, 3501, 3501, 14857, 3501, 14893, 3501, 34503, 34503, 34503, 34509, 34503, 34503, 34503, 3284, 3284, 3282, 3284, 3284, 3284, 3284, 3282, 3282, 3282, 3445, 52356, 3284, 52356, 52356, 3284, 52356, 3284, 52357, 52357, 3284, 3282, 3282, 3284, 3284, 3284, 3284, 3284, 3282, 3282, 3284, 3284, 3284, 3284, 3442, 40558, 34698, 43945, 34674, 43957, 43953, 3283, 3286, 3283, 3283, 3283, 3286, 3283, 3286, 45814, 45551, 3296, 3345, 11066, 24929, 24924, 25081, 24931, 25077, 25070, 25079, 25083, 25074, 25072, 25071, 3296, 3296, 3350, 34864, 34850, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34864, 34913, 34936, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 34916, 35840, 38853, 35874, 47091, 35839, 35869, 35872, 35870, 35873, 35871, 47091, 47091, 47091, 35232, 35232, 35232, 35232, 35232, 35112, 35232, 35115, 35232, 35232, 35232, 35232, 35232, 35232, 35232, 35232, 50371, 35232, 39095, 35124, 35378, 35550, 35906, 35504, 35504, 35504, 35504, 35509, 35509, 35509, 35509, 35509, 35504, 35504, 35504, 35509, 35509, 35504, 35509, 35509, 35509, 35509, 35509, 35915, 35915, 35915, 50474, 50474, 50474, 44469, 44461, 44468, 44460, 44459, 44465, 44464, 35552, 35911, 44455, 35551, 36057, 36057, 36057, 36057, 36057, 36057, 36057, 35618, 36057, 35566, 41015, 41015, 41015, 41015, 41015, 41015, 41015, 41015, 36797, 36698, 36798, 36602, 36602, 36170, 36602, 36602, 36602, 36132, 34571, 36631, 50252, 36652, 36628, 36602, 36629, 36602, 36651, 36695, 36717, 36632, 36190, 36630, 36602, 50567, 38791, 36602, 36602, 36602, 36602, 36602, 36205, 36602, 36211, 36211, 36140, 34511, 36211, 34511, 36211, 36211, 34511, 34511, 34511, 34511, 34511, 34511, 34511, 34511, 34511, 34511, 34511, 36292, 36292, 34511, 34511, 34511, 34511, 36292, 34511, 36292, 36292, 36292, 36292, 34511, 34511, 34511, 34511, 36290, 36690, 36779, 36690, 36690, 36211, 36690, 36211, 36236, 36236, 36236, 36211, 36236, 36211, 36236, 36236, 36211, 36236, 36292, 36236, 36211, 36236, 36211, 36236, 36211, 36236, 36236, 36236, 36211, 36211, 36236, 36211, 36236, 36396, 36211, 36236, 36236, 36396, 36236, 36397, 36396, 36396, 36396, 36236, 36236, 36399, 36396, 36396, 36396, 36397, 36396, 36292, 36396, 36236, 36236, 36396, 36236, 36236, 36396, 36396, 36236, 36399, 36236, 36292, 34511, 34511, 34511, 36236, 36292, 36236, 36236, 36292, 36312, 36236, 36236, 36292, 36292, 36236, 36312, 36451, 36653, 36460, 36460, 36460, 36452, 36457, 36602, 36671, 36671, 36671, 36456, 36454, 36488, 36488, 36455, 36488, 36491, 36492, 36488, 36488, 36488, 36488, 36488, 36488, 36488, 36488, 36671, 36671, 36460, 36460, 36460, 36460, 36488, 36671, 36461, 36458, 38853, 44460, 36138, 43907, 37946, 51409, 36743, 37065, 38762, 38762, 36293, 37067, 37067, 37067, 37067, 37067, 37067, 37067, 37067, 37067, 36293, 36293, 36293, 36293, 36293, 36293, 36293, 36293, 36293, 36293, 36293, 36293, 37806, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37805, 37808, 36293, 38793, 38794, 50252, 37102, 38796, 38792, 38799, 38798, 37815, 43558, 38795, 38797, 68, 68, 68, 6089, 1327, 5482, 340, 5483, 51348, 51348, 1756, 43840, 44395, 42421, 1976, 42421, 68, 1976, 583, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 475, 97, 478, 478, 478, 117, 117, 117, 117, 117, 117, 117, 117, 117, 500, 126, 126, 515, 515, 515, 456, 456, 456, 456, 515, 126, 126, 515, 515, 500, 117, 117, 1065, 126, 515, 126, 515, 126, 500, 117, 500, 117, 42387, 42387, 42387, 42387, 54371, 54371, 54372, 54372, 54372, 874, 54372, 54372, 54371, 54372, 54372, 42407, 54371, 54371, 124, 124, 452, 1424, 1236, 1236, 117, 117, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 1236, 500, 1236, 1236, 1236, 1065, 117, 1065, 1236, 1236, 1236, 1236, 1236, 1236, 117, 94, 474, 94, 116, 94, 474, 116, 116, 94, 116, 99, 116, 94, 116, 474, 116, 474, 94, 94, 94, 116, 94, 68, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 68, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 844, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 42218, 47030, 47030, 47030, 47030, 47293, 51400, 47031, 47031, 3877, 3877, 3877, 3873, 47145, 4278, 3887, 47145, 47146, 3877, 3877, 47293, 47030, 47030, 47030, 47030, 47031, 47031, 3877, 3877, 3877, 47232, 47232, 3873, 47232, 47232, 3877, 47146, 3877, 3877, 3877, 47293, 47030, 47030, 47030, 47030, 47031, 47031, 47294, 47293, 47294, 47030, 47030, 47031, 47031, 47030, 47030, 47293, 47294, 47030, 47030, 47030, 47031, 47031, 47030, 47293, 44223, 44223, 44223, 44217, 44216, 44223, 11318, 11318, 11517, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11520, 11318, 11318, 11318, 11318, 11318, 11318, 11519, 11322, 11324, 11322, 11323, 11322, 11323, 11322, 11323, 11323, 11323, 11322, 11324, 11323, 11323, 11322, 11322, 11324, 11324, 11322, 11518, 11322, 11322, 11324, 11323, 11322, 11323, 11323, 11323, 11322, 11322, 11322, 11324, 11322, 11322, 11322, 11322, 11324, 11322, 11322, 11323, 11323, 11322, 25083, 25074, 25071, 25072, 25079, 25070, 25077, 25072, 25071, 25074, 25083, 25079, 25070, 42387, 42387, 42387, 42387, 1236, 1236, 1236, 42387, 42387, 42387, 42387, 1236, 42387, 42387, 42387, 42387, 1236, 42387, 42387, 42387, 42387, 500, 42387, 42387, 42387, 42387, 123, 123, 123, 123, 458, 171, 171, 171, 517, 517, 517, 517, 517, 517, 517, 517, 517, 517, 517, 123, 123, 517, 517, 517, 520, 124, 458, 517, 517, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 42677, 42407, 42407, 42407, 42407, 42407, 42407, 42407, 42407, 42677, 42677, 42407, 42677, 42677, 42677, 42677, 42677, 42677, 452, 124, 124, 124, 124, 124, 452, 452, 452, 452, 452, 452, 452, 54371, 54371, 54372, 54371, 54371, 54371, 54371, 54372, 54371, 452, 452, 38467, 38221, 38221, 38221, 37784, 37784, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 37784, 38221, 38221, 38553, 38221, 38221, 38221, 38221, 37784, 38221, 38221, 37784, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 37783, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 37784, 38221, 38221, 37784, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 37784, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38466, 37784, 38221, 42853, 38465, 38221, 38221, 38221, 38221, 37784, 37784, 38218, 37784, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38210, 38210, 38210, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38192, 38210, 38192, 38192, 38210, 38192, 38210, 38192, 38192, 38210, 38192, 38192, 38210, 38192, 38192, 38192, 38192, 38192, 38192, 38210, 38210, 38210, 38210, 38210, 38210, 38192, 38192, 38192, 38192, 38192, 38210, 38210, 38210, 38192, 38210, 38192, 38210, 38192, 38210, 38192, 38210, 38192, 38210, 38210, 38210, 38192, 38192, 38192, 38192, 38210, 38192, 38192, 38192, 38192, 38210, 38192, 38192, 38192, 38192, 38210, 38192, 38210, 38192, 38192, 38192, 38192, 38192, 38210, 38210, 38210, 38210, 38464, 38464, 38426, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38415, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38469, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38470, 38192, 38192, 38192, 38192, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38192, 38221, 38221, 38192, 38192, 38192, 38192, 38192, 38192, 38192, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38192, 38192, 38192, 38192, 38192, 38192, 38611, 38192, 38192, 38192, 38192, 38192, 38474, 38467, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38221, 38218, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38210, 38469, 38210, 38210, 38210, 39017, 39017, 38539, 38614, 39017, 39017, 39017, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38618, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 38616, 39017, 39017, 44388, 39017, 44388, 39017, 39017, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 38363, 37885, 38144, 37885, 38781, 38781, 37885, 37885, 38781, 37885, 36616, 38781, 38780, 38780, 38780, 38780, 38780, 38780, 38780, 38780, 38780, 38149, 38783, 43727, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37938, 37938, 37938, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37938, 37916, 37916, 37916, 37916, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37938, 37916, 37916, 37916, 37916, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37916, 37916, 37916, 37916, 37938, 37916, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37938, 37916, 37916, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37916, 37916, 37916, 37916, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37938, 37916, 37916, 37938, 37916, 37916, 37916, 37916, 37916, 37938, 37938, 37916, 37938, 37938, 37916, 37916, 37916, 37938, 37916, 37938, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37938, 37916, 37938, 37938, 37938, 37938, 37938, 37938, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37938, 37916, 37916, 37916, 37938, 37916, 37916, 37916, 37916, 37916, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37938, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 37916, 42141, 42141, 42141, 43703, 43703, 42141, 42141, 42141, 42141, 43566, 42141, 42141, 43703, 42141, 42141, 42141, 42141, 43703, 42141, 42141, 42141, 42141, 42141, 42141, 42141, 42141, 42141, 43703, 43703, 3607, 25053, 25054, 25055, 25052, 25051, 25056, 10118, 4262, 4262, 4262, 7907, 4262, 4262, 4262, 4262, 4262, 4262, 4262, 4262, 50307, 51371, 51371, 51371, 4214, 14379, 51371, 5782, 4262, 4262, 49748, 4262, 4262, 51371, 51371, 51371, 4163, 4215, 4223, 4210, 2796, 3561, 51371, 4146, 4220, 4217, 10089, 4218, 4219, 7296, 4205, 4138, 9047, 52636, 51371, 52637, 52642, 52643, 4262, 4262, 4262, 4262, 4262, 4262, 4262, 52644, 4262, 4262, 4262, 50497, 50500, 50501, 4262, 50499, 36479, 50502, 50498, 51371, 4262, 48736, 48737, 47584, 11070, 30715, 4262, 51371, 51371, 51371, 33115, 33115, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 33115, 32969, 32969, 49942, 32969, 49927, 49968, 32969, 49939, 32969, 49940, 49923, 43429, 32969, 32969, 51997, 11037, 32969, 32969, 32969, 32969, 32969, 43431, 32969, 32969, 3841, 32969, 32969, 33115, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 32969, 33359, 33115, 51915, 54371, 54372, 54372, 54372, 54371, 54372, 51915, 54372, 54372, 54372, 54371, 54372, 54371, 54372, 124, 54371, 54371, 54371, 11517, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11520, 11318, 11318, 11318, 11318, 11318, 11318, 11318, 11519, 11322, 11322, 11324, 11323, 11322, 11323, 11322, 11323, 11323, 11323, 11324, 11322, 11323, 11324, 11518, 11322, 11322, 11324, 11322, 11323, 11322, 11322, 11324, 11322, 11323, 11322, 11322, 11323, 11324, 11322, 5953, 5953, 5953, 5953, 5953, 5953, 3706, 12430, 5953, 5953, 3169, 3142, 5953, 3173, 3620, 3170, 5953, 3139, 5953, 3168, 3171, 3164, 5953, 5953, 51346, 51346, 51346, 51346, 51346, 51346);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(100, 1904, 0, 0), -- Gruff Swiftbite
(10063, 12329, 0, 0), -- Reggifuz
(10089, 5278, 0, 0), -- Silvaria
(10118, 1117, 0, 0), -- Nessa Shadowsong
(10266, 5532, 0, 0), -- Ug'thok
(10276, 1903, 0, 0), -- Rotgath Stonebeard
(10277, 1903, 0, 0), -- Groum Stonebeard
(10369, 0, 0, 5261), -- Trayexir
(10578, 4993, 0, 0), -- Bom'bay
(10604, 5598, 0, 0), -- Huntress Nhemai
(10606, 5598, 0, 0), -- Huntress Yaeliura
(1065, 1908, 0, 0), -- Riverpaw Shaman
(10676, 10615, 0, 0), -- Raider Jhash
(10782, 12751, 0, 0), -- Royal Factor Bathrilor
(11017, 1903, 0, 0), -- Roxxik
(11025, 1911, 0, 0), -- Mukdrak
(11026, 1911, 0, 0), -- Sprite Jumpsprocket
(11028, 1911, 0, 0), -- Jemma Quikswitch
(11029, 4994, 0, 0), -- Trixie Quikswitch
(11037, 1911, 0, 0), -- Jenna Lemkenilli
(11041, 2716, 3694, 0), -- Milla Fairancora
(11042, 3699, 3697, 0), -- Sylvanna Forestmoon
(11046, 3699, 3697, 0), -- Whuut
(11065, 12751, 0, 0), -- Thonys Pillarstone
(11066, 0, 12860, 0), -- Jhag
(11068, 2177, 0, 0), -- Betty Quin
(11070, 13061, 0, 0), -- Lalina Summermoon
(11083, 5278, 0, 0), -- Darianna
(11096, 12742, 0, 0), -- Randal Worth
(11145, 2558, 0, 0), -- Myolor Sunderfury
(11146, 2182, 0, 0), -- Ironus Coldsteel
(1115, 5301, 0, 0), -- Rockjaw Skullthumper
(1117, 3350, 3350, 0), -- Rockjaw Bonesnapper
(11176, 5532, 0, 0), -- Krathok Moltenfist
(11177, 5491, 0, 0), -- Okothos Ironrager
(11178, 1903, 0, 0), -- Borgosh Corebender
(1119, 3326, 0, 0), -- Hammerspine
(11260, 1905, 0, 0), -- Northshire Peasant
(11318, 1904, 0, 0), -- Ragefire Trogg
(11322, 10619, 0, 0), -- Searing Blade Cultist
(11323, 3361, 2052, 0), -- Searing Blade Enforcer
(11324, 12937, 0, 0), -- Searing Blade Warlock
(11328, 1905, 0, 0), -- Eastvale Peasant
(1141, 2827, 0, 0), -- Angus Stern
(11517, 3350, 0, 0), -- Oggleflint
(11518, 2559, 0, 0), -- Jergosh the Invoker
(11519, 2179, 0, 0), -- Bazzalan
(11520, 11321, 0, 0), -- Taragaman the Hungerer
(116, 1896, 0, 0), -- Defias Bandit
(117, 1895, 0, 0), -- Riverpaw Gnoll
(11709, 11762, 0, 0), -- Jareth Wildwoods
(1172, 2184, 0, 0), -- Tunnel Rat Vermin
(1173, 1904, 0, 2551), -- Tunnel Rat Scout
(1176, 2200, 0, 0), -- Tunnel Rat Forager
(1177, 1911, 0, 0), -- Tunnel Rat Surveyor
(11814, 10611, 0, 0), -- Kali Remik
(11941, 13861, 0, 0), -- Yori Crackhelm
(1198, 0, 0, 5260), -- Rallic Finn
(1213, 1903, 0, 0), -- Godric Rothgar
(12136, 4994, 0, 0), -- Snurk Bucksquick
(1215, 2198, 3694, 0), -- Alchemist Mallory
(12160, 5598, 0, 2550), -- Shadowglen Sentinel
(1218, 1907, 0, 0), -- Herbalist Pomeroy
(1226, 2705, 0, 0), -- Maxan Anvol
(1228, 2202, 0, 0), -- Magis Sparkmantle
(1229, 2704, 0, 0), -- Granis Swiftaxe
(123, 1905, 0, 0), -- Riverpaw Mongrel
(1232, 2705, 1984, 0), -- Azar Stronghammer
(1234, 2184, 0, 0), -- Hogral Bakkan
(1236, 1910, 0, 0), -- Kobold Digger
(1237, 2197, 0, 0), -- Kazan Mogosh
(124, 3326, 0, 0), -- Riverpaw Brute
(12423, 1899, 143, 0), -- Guard Roberts
(12429, 5598, 0, 2550), -- Sentinel Shaya
(12430, 5289, 0, 0), -- Grunt Kor'ja
(1247, 2705, 0, 0), -- Innkeeper Belm
(12480, 21573, 21572, 0), -- Melris Malagan
(12481, 21553, 0, 0), -- Justine Demalier
(1249, 1903, 0, 0), -- Quartermaster Hudson
(1252, 2705, 0, 0), -- Senir Whitebeard
(1253, 13750, 0, 0), -- Father Gavin
(1256, 2714, 0, 0), -- Quarrymaster Thesten
(1257, 3699, 0, 0), -- Keldric Boucher
(126, 2184, 0, 0), -- Murloc Coastrunner
(1261, 1907, 0, 0), -- Veron Amberstill
(1265, 2715, 0, 0), -- Rudra Amberstill
(1267, 2705, 0, 0), -- Ragnar Thunderbrew
(1275, 0, 3695, 0), -- Kyra Boucher
(12779, 13750, 0, 0), -- Archmage Gaiman
(1278, 2183, 1984, 2552), -- Mountaineer Stenn
(12780, 0, 0, 13147), -- Sergeant Major Skyshadow
(12781, 12744, 0, 0), -- Master Sergeant Biggins
(12783, 3364, 10616, 0), -- Lieutenant Karter
(12784, 21573, 0, 0), -- Lieutenant Jackspring
(12785, 5288, 0, 0), -- Sergeant Major Clate
(12786, 2178, 143, 0), -- Guard Quine
(12787, 2178, 143, 0), -- Guard Hammon
(12789, 13631, 0, 0), -- Blood Guard Hini'wana
(1279, 2182, 1984, 2552), -- Mountaineer Flint
(12790, 13612, 0, 0), -- Advisor Willington
(12791, 0, 0, 16582), -- Chieftain Earthbind
(12793, 6680, 0, 0), -- Brave Stonehide
(12794, 21580, 0, 0), -- Stone Guard Zarg
(12795, 12786, 0, 0), -- First Sergeant Hola'mahi
(12796, 10611, 0, 0), -- Raider Bork
(12797, 12403, 0, 0), -- Grunt Korf
(12798, 12403, 0, 0), -- Grunt Bek'rah
(1280, 2183, 1984, 2552), -- Mountaineer Droken
(12805, 1899, 1984, 0), -- Officer Areyn
(1284, 14092, 0, 0), -- Archbishop Benedictus
(1285, 2714, 0, 0), -- Thurman Mullby
(1287, 1896, 0, 0), -- Marda Weller
(1289, 1903, 0, 0), -- Gunther Weller
(1292, 5278, 0, 0), -- Maris Granger
(1297, 0, 0, 2552), -- Lina Stover
(1298, 0, 0, 2550), -- Frederick Stover
(1301, 2717, 0, 0), -- Julia Gallina
(1302, 2710, 0, 0), -- Bernard Gump
(1303, 6233, 0, 0), -- Felicia Gump
(1305, 2704, 0, 0), -- Jarel Moor
(13076, 2557, 0, 2552), -- Dun Morogh Mountaineer
(1308, 1908, 0, 0), -- Owen Vaughn
(1311, 2705, 0, 0), -- Joachim Brenlow
(13116, 12591, 0, 0), -- Alliance Spirit Guide
(13117, 13337, 0, 0), -- Horde Spirit Guide
(1312, 0, 0, 6231), -- Ardwyn Cailen
(1313, 1908, 3697, 0), -- Maria Lumere
(13159, 1899, 0, 0), -- James Clark
(1316, 12751, 0, 0), -- Adair Gilroy
(1319, 0, 1984, 0), -- Bryan Cross
(1321, 12854, 0, 0), -- Alyssa Griffith
(1323, 0, 1903, 0), -- Osric Strang
(1325, 5285, 5285, 0), -- Jasper Fel
(1326, 2200, 2201, 0), -- Sloan McCoy
(1327, 2703, 0, 0), -- Reese Langston
(1328, 2716, 0, 0), -- Elly Langston
(13283, 1900, 5284, 0), -- Lord Tony Romano
(1331, 2182, 1984, 2552), -- Mountaineer Luxst
(1332, 2180, 1984, 2552), -- Mountaineer Morran
(1334, 2180, 1984, 2552), -- Mountaineer Hammerfall
(1335, 2183, 1984, 2552), -- Mountaineer Yuttha
(1336, 2180, 1984, 2552), -- Mountaineer Zwarn
(1337, 2183, 1984, 2552), -- Mountaineer Gwarth
(1339, 1902, 0, 0), -- Mayda Thane
(1340, 2809, 1984, 0), -- Mountaineer Kadrell
(1343, 2182, 1984, 0), -- Mountaineer Stormpike
(1348, 5495, 0, 0), -- Gregory Ardus
(1351, 1908, 0, 0), -- Brother Cassius
(1355, 2827, 0, 0), -- Cook Ghilm
(1358, 1910, 0, 0), -- Miner Grothor
(1360, 1910, 0, 0), -- Miner Grumnal
(1366, 1117, 0, 0), -- Adam
(1367, 1117, 0, 0), -- Billy
(1368, 1117, 0, 0), -- Justin
(1370, 1117, 0, 0), -- Brandon
(1371, 1117, 0, 0), -- Roman
(1373, 2705, 0, 0), -- Jarven Thunderbrew
(1375, 2703, 0, 0), -- Marleth Barleybrew
(1376, 1901, 0, 0), -- Beldin Steelgrill
(13842, 13339, 0, 0), -- Frostwolf Ambassador Rokhstrom
(13843, 12742, 0, 0), -- Lieutenant Rotimer
(1415, 1907, 0, 0), -- Suzanne
(1416, 1903, 0, 0), -- Grimand Elmore
(14183, 0, 0, 15460), -- Artilleryman Sheldonore
(1423, 1899, 143, 2551), -- Stormwind Guard
(1424, 1910, 0, 0), -- Master Digger
(1430, 2197, 0, 0), -- Tomas
(14304, 5289, 0, 2507), -- Kor'kron Elite
(1431, 2717, 0, 0), -- Suzetta Gallina
(1432, 2717, 0, 0), -- Renato Gallina
(1435, 12959, 0, 0), -- Zardeth of the Black Claw
(14363, 11763, 11763, 0), -- Thief Catcher Shadowdelve
(14365, 11763, 11763, 0), -- Thief Catcher Farmountain
(14367, 11763, 11763, 0), -- Thief Catcher Thunderbrew
(14375, 10612, 0, 2507), -- Scout Stronghand
(14376, 10612, 0, 2507), -- Scout Manslayer
(14377, 10612, 0, 2507), -- Scout Tharr
(14378, 5598, 5598, 0), -- Huntress Skymane
(14379, 5598, 5598, 0), -- Huntress Ravenoak
(14380, 5598, 5598, 0), -- Huntress Leafrunner
(1439, 12751, 0, 0), -- Lord Baurles K. Wishock
(14390, 1901, 0, 2552), -- Expeditionary Mountaineer
(14392, 18419, 0, 0), -- Overlord Runthak
(14393, 2809, 0, 0), -- Expeditionary Priest
(14423, 2178, 5284, 62285), -- Officer Jaxon
(14437, 5303, 0, 0), -- Gorzeeki Wildeyes
(14438, 2178, 5284, 62285), -- Officer Pomeroy
(14439, 2178, 5284, 62285), -- Officer Brady
(1444, 1907, 0, 0), -- Brother Kristoff
(14497, 3362, 0, 0), -- Shellene
(14498, 12751, 0, 0), -- Tosamina
(1469, 0, 0, 2552), -- Vrok Blunderblast
(1472, 1903, 0, 0), -- Morgg Stormshot
(1477, 2705, 0, 0), -- Christoph Faral
(1478, 2705, 0, 0), -- Aedis Brom
(14857, 6256, 0, 0), -- Erk
(14859, 12285, 0, 5260), -- Guard Taruc
(14873, 12801, 0, 0), -- Okla
(14893, 12285, 0, 2550), -- Guard Kurall
(14901, 12629, 0, 0), -- Peon
(151, 2197, 0, 0), -- Brog Hamfist
(152, 2197, 0, 0), -- Brother Danil
(1568, 2714, 0, 0), -- Undertaker Mordo
(1569, 11365, 0, 0), -- Shadow Priest Sarvis
(1570, 1899, 0, 0), -- Executor Arren
(1573, 2182, 0, 0), -- Gryth Thurden
(16012, 14824, 0, 0), -- Mokvar
(16076, 20468, 0, 0), -- Tharl Stonebleeder
(16418, 3699, 0, 0), -- Mupsi Shacklefridd
(1642, 1899, 143, 2551), -- Northshire Guard
(1645, 2178, 0, 0), -- Quartermaster Hicks
(1650, 1905, 0, 0), -- Terry Palin
(1651, 1117, 0, 0), -- Lee Brown
(1661, 1908, 0, 0), -- Novice Elreth
(1668, 0, 0, 5260), -- William MacGregor
(1670, 1907, 0, 0), -- Mike Miller
(1679, 2182, 0, 0), -- Avarus Kharag
(1691, 2703, 0, 0), -- Kreg Bilmn
(1698, 1905, 0, 0), -- Frast Dokner
(1701, 1910, 0, 0), -- Dank Drizzlecut
(1702, 4994, 0, 0), -- Bronk Guzzlegear
(1703, 12298, 0, 0), -- Uthrar Threx
(171, 2023, 0, 0), -- Murloc Warrior
(17105, 29676, 0, 0), -- Emissary Valustraa
(1736, 1905, 0, 2551), -- Deathguard Randolph
(1737, 1905, 0, 2551), -- Deathguard Oliver
(1739, 1905, 0, 2551), -- Deathguard Phillip
(1740, 1905, 0, 2551), -- Deathguard Saltain
(1741, 1905, 0, 2551), -- Deathguard Bartrand
(1747, 12748, 0, 0), -- Anduin Wrynn
(1750, 2179, 2711, 0), -- Grand Admiral Jes-Tereth
(1751, 2183, 0, 0), -- Mithras Ironhill
(1752, 5285, 0, 5258), -- Caledra Dawnbreeze
(1756, 1899, 143, 2551), -- Stormwind Royal Guard
(1890, 1899, 0, 0), -- Rattlecage Skeleton
(1959, 0, 0, 2552), -- Mountaineer Barleybrew
(196, 1905, 0, 0), -- Eagan Peltskinner
(1960, 1911, 0, 0), -- Pilot Hammerfoot
(1963, 3351, 0, 0), -- Vidra Hearthstove
(197, 1899, 143, 0), -- Marshal McBride
(1976, 1899, 143, 2551), -- Stormwind City Patroller
(1977, 1908, 0, 0), -- Senator Mehr Stonehallow
(198, 1907, 0, 0), -- Khelden Bremen
(19848, 23906, 29640, 0), -- Harbinger Ennarth
(2002, 1896, 0, 0), -- Rascal Sprite
(2003, 1907, 0, 0), -- Shadow Sprite
(2004, 2184, 0, 0), -- Dark Sprite
(2005, 2809, 0, 0), -- Vicious Grell
(2007, 3346, 0, 0), -- Gnarlpine Gardener
(2008, 1901, 0, 0), -- Gnarlpine Warrior
(2009, 1907, 0, 0), -- Gnarlpine Shaman
(2010, 3350, 0, 0), -- Gnarlpine Defender
(2011, 2827, 0, 0), -- Gnarlpine Augur
(20407, 29694, 0, 0), -- Farseer Umbrua
(2046, 1903, 0, 0), -- Andrew Krighton
(2077, 5292, 0, 0), -- Melithar Staghelm
(2078, 2809, 0, 0), -- Athridas Bearmantle
(2079, 1907, 0, 0), -- Conservator Ilthalaine
(2081, 2179, 0, 0), -- Sentinel Kyra Starsong
(2083, 2714, 0, 0), -- Syral Bladeleaf
(2113, 1907, 0, 0), -- Archibald Kava
(2115, 2197, 0, 0), -- Joshua Kien
(2116, 1903, 0, 0), -- Blacksmith Rand
(2117, 1896, 0, 0), -- Harold Raims
(2119, 1899, 0, 0), -- Dannal Stern
(2122, 1900, 0, 0), -- David Trias
(2123, 2813, 0, 0), -- Dark Cleric Duesten
(2124, 11343, 0, 0), -- Isabella
(2126, 5276, 0, 0), -- Maximillion
(2151, 0, 0, 14105), -- Moon Priestess Amara
(2307, 2714, 0, 0), -- Caretaker Caice
(23127, 1908, 0, 0), -- Farseer Javad
(23128, 29403, 27406, 0), -- Master Pyreanor
(2326, 2705, 0, 0), -- Thamner Pol
(233, 3367, 0, 0), -- Farmer Saldean
(234, 2557, 0, 0), -- Gryan Stoutmantle
(235, 3351, 0, 0), -- Salma Saldean
(23542, 33981, 0, 28972), -- Amani'shi Axe Thrower
(23576, 0, 33094, 0), -- Nalorakk
(23577, 33990, 33990, 0), -- Halazzi
(23580, 33982, 33982, 0), -- Amani'shi Warbringer
(23581, 33002, 0, 0), -- Amani'shi Medicine Man
(23582, 33980, 33980, 0), -- Amani'shi Tribesman
(23586, 1906, 0, 5259), -- Amani'shi Scout
(23596, 33983, 0, 0), -- Amani'shi Flame Caster
(23597, 33979, 0, 0), -- Amani'shi Guardian
(23635, 4994, 0, 0), -- Krixx
(237, 3367, 0, 0), -- Farmer Furlbrow
(23774, 13719, 0, 0), -- Amani'shi Trainer
(23863, 69916, 0, 0), -- Zul'jin
(23889, 10617, 0, 0), -- Amani'shi Savage
(240, 3361, 0, 0), -- Marshal Dughan
(24059, 13625, 0, 0), -- Amani'shi Beast Tamer
(24065, 33992, 0, 33991), -- Amani'shi Handler
(241, 1906, 0, 0), -- Remy "Two Times"
(24175, 28914, 0, 0), -- Amani'shi Lookout
(24179, 33793, 0, 0), -- Amani'shi Wind Walker
(24180, 33984, 33789, 0), -- Amani'shi Protector
(24239, 33798, 0, 0), -- Hex Lord Malacrass
(24549, 34045, 34045, 0), -- Amani'shi Tempest
(24818, 2184, 0, 0), -- Anvilrage Taskmaster
(24819, 1895, 1961, 0), -- Anvilrage Enforcer
(2485, 5304, 0, 0), -- Larimaine Purdue
(24924, 3364, 0, 0), -- Sky-Captain Bomblast
(24926, 1897, 0, 0), -- Chief Officer Brassbolt
(24929, 31824, 0, 0), -- Crewman Crosswire
(24930, 31824, 0, 0), -- Crewman Gazzlegear
(24931, 1911, 0, 0), -- Crewman Fastwrench
(250, 3367, 0, 0), -- Pa Maclure
(25009, 3364, 0, 0), -- Captain Angelina Soluna
(25010, 2705, 0, 0), -- Engineer Brightbuckle
(25011, 1897, 0, 0), -- First Mate Wavesinger
(25012, 2703, 3757, 0), -- Galley Chief Gathers
(25013, 5598, 0, 5258), -- Sentinel Brightgrass
(25014, 5598, 0, 2552), -- Sentinel Winterdew
(25016, 5278, 0, 0), -- Sailor Wills
(25017, 5278, 0, 0), -- Sailor Fairfolk
(25018, 5278, 0, 0), -- Sailor Stoneheel
(2504, 12742, 0, 0), -- Donyal Tovald
(25051, 1902, 0, 0), -- Merchant Frostwalker
(25052, 2718, 3756, 0), -- Galley Chief Halumvorea
(25053, 3432, 0, 5258), -- Mariner Farseeker
(25054, 3432, 0, 5258), -- Mariner Keenstar
(25055, 3432, 0, 5258), -- Mariner Frostnight
(25056, 3432, 0, 5258), -- Mariner Stillglider
(2506, 2183, 1984, 2552), -- Mountaineer Harn
(25070, 1897, 0, 0), -- Chief Officer Coppernut
(25071, 1903, 0, 0), -- Crewman Rusthammer
(25072, 1911, 0, 0), -- Crewman Quickfix
(25074, 31824, 0, 0), -- Crewman Sparkfly
(25077, 3364, 0, 0), -- Sky-Captain Cloudkicker
(25079, 1905, 0, 2552), -- Deathguard Fowles
(2508, 2183, 1984, 2552), -- Mountaineer Wuar
(25080, 5289, 0, 5258), -- Grunt Umgor
(25081, 5289, 0, 5258), -- Grunt Ounda
(25083, 1905, 0, 2552), -- Deathguard Lawson
(2509, 2183, 1984, 2552), -- Mountaineer Cragg
(2510, 2183, 1984, 2552), -- Mountaineer Ozmok
(2512, 2183, 1984, 2552), -- Mountaineer Roghan
(2513, 2183, 1984, 2552), -- Mountaineer Janha
(2514, 2183, 1984, 2552), -- Mountaineer Modax
(2516, 2183, 1984, 2552), -- Mountaineer Kamdar
(2517, 2183, 1984, 2552), -- Mountaineer Langarr
(2518, 2183, 1984, 2552), -- Mountaineer Swarth
(258, 0, 3757, 0), -- Joshua Maclure
(26537, 4994, 0, 0), -- Greeb Ramrocket
(2708, 11343, 0, 0), -- Archmage Malin
(27478, 0, 33162, 0), -- Larkin Thunderbrew
(27815, 33161, 0, 0), -- Brew Vendor
(27816, 33161, 0, 0), -- Brew Vendor
(2790, 1903, 0, 0), -- Grand Mason Marblesten
(2796, 1896, 0, 0), -- Faelyssa
(28347, 12862, 2201, 0), -- Miles Sidney
(28355, 2200, 2199, 0), -- Wright Williams
(285, 1895, 0, 0), -- Murloc
(2855, 0, 12745, 0), -- Snang
(28569, 5292, 0, 0), -- Construction Worker
(2857, 31824, 0, 0), -- Thund
(28596, 5292, 0, 0), -- Dwarven Construction Worker
(28650, 2715, 0, 0), -- Nayura
(2918, 5304, 0, 0), -- Advisor Belgrum
(29611, 45899, 0, 0), -- King Varian Wrynn
(29712, 1899, 143, 2551), -- Stormwind Harbor Guard
(29725, 7682, 0, 0), -- Benik Boltshear
(30611, 5289, 0, 2507), -- Greela "The Grunt" Crankchain
(30706, 12862, 0, 0), -- Jo'mah
(30713, 12862, 0, 0), -- Catarina Stanford
(30715, 12862, 0, 0), -- Feyden Darkin
(30717, 12862, 0, 0), -- Elise Brightletter
(3084, 12754, 0, 14642), -- Bluffwatcher
(3101, 2695, 0, 0), -- Vile Familiar
(3111, 1901, 0, 0), -- Razormane Quilboar
(3112, 5281, 0, 5856), -- Razormane Scout
(3113, 1904, 0, 0), -- Razormane Dustrunner
(3114, 5287, 0, 0), -- Razormane Battleguard
(3129, 1899, 2053, 0), -- Kul Tiras Marine
(3139, 3361, 0, 0), -- Gar'Thok
(3140, 2184, 0, 0), -- Lar Prowltusk
(3142, 10611, 0, 0), -- Orgnil Soulscar
(3144, 10612, 0, 0), -- Eitrigg
(3163, 1903, 0, 0), -- Uhgar
(3164, 0, 12745, 0), -- Jark
(3165, 0, 0, 5260), -- Ghrawt
(3167, 5532, 0, 0), -- Wuark
(3168, 2198, 0, 0), -- Flakk
(3169, 1899, 1957, 0), -- Tarshaw Jaggedscar
(3170, 12298, 0, 0), -- Kaplak
(3171, 10612, 0, 0), -- Thotar
(3172, 1907, 0, 0), -- Dhugru Gorelust
(31720, 31824, 0, 0), -- Crewman Shubbscoop
(31723, 31824, 0, 0), -- Crewman Barrowswizzle
(31724, 31824, 0, 0), -- Crewman Paltertop
(31725, 3364, 0, 0), -- Sky-Captain LaFontaine
(31726, 5289, 0, 5258), -- Grunt Gritch
(31727, 5289, 0, 5258), -- Grunt Grikee
(3173, 6334, 0, 0), -- Swart
(3174, 1903, 0, 0), -- Dwukk
(3175, 1910, 0, 0), -- Krunn
(3177, 11762, 0, 0), -- Turuk Amberstill
(3183, 5303, 0, 0), -- Yarrog Baneshadow
(3184, 0, 3697, 0), -- Miao'zan
(3185, 6233, 0, 0), -- Mishiki
(3186, 12744, 0, 0), -- K'waii
(3187, 1910, 0, 0), -- Tai'tasi
(3188, 12322, 0, 0), -- Master Gadrin
(3189, 2023, 0, 0), -- Kor'ghan
(3193, 3362, 0, 0), -- Misha Tor'kren
(3194, 5278, 0, 0), -- Vel'rin Fang
(3195, 2695, 0, 0), -- Burning Blade Thug
(3196, 2809, 0, 0), -- Burning Blade Neophyte
(3197, 1983, 0, 0), -- Burning Blade Fanatic
(3198, 2809, 0, 0), -- Burning Blade Apprentice
(3199, 1907, 0, 0), -- Burning Blade Cultist
(3203, 20468, 0, 0), -- Fizzle Darkstorm
(3204, 5285, 0, 0), -- Gazz'uz
(3208, 1908, 0, 0), -- Margoz
(3216, 2559, 0, 0), -- Neeru Fireblade
(3265, 1905, 0, 2551), -- Razormane Hunter
(3266, 1904, 0, 0), -- Razormane Defender
(3267, 2827, 0, 0), -- Razormane Water Seeker
(3268, 1905, 0, 0), -- Razormane Thornweaver
(3269, 1906, 0, 0), -- Razormane Geomancer
(327, 1903, 0, 0), -- Goldtooth
(3271, 1907, 0, 0), -- Razormane Mystic
(3272, 1895, 0, 5258), -- Kolkar Wrangler
(3273, 5304, 0, 0), -- Kolkar Stormer
(328, 1908, 0, 0), -- Zaldimar Wefhellt
(3282, 1896, 0, 5262), -- Venture Co. Mercenary
(3283, 5288, 0, 0), -- Venture Co. Enforcer
(3284, 3346, 0, 0), -- Venture Co. Drudger
(3286, 2147, 0, 0), -- Venture Co. Overseer
(3292, 2704, 2704, 0), -- Brewmaster Drohn
(3293, 1911, 0, 0), -- Rezlak
(3294, 1904, 0, 0), -- Ophek
(3296, 5289, 0, 2507), -- Orgrimmar Grunt
(32969, 5598, 0, 14105), -- -Unknown-
(3297, 1904, 0, 2507), -- Sen'jin Watcher
(3304, 12329, 0, 0), -- Master Vornal
(331, 2177, 0, 0), -- Maginor Dumas
(3310, 3433, 0, 0), -- Doras
(33115, 5598, 0, 14105), -- -Unknown-
(3312, 2827, 2196, 2551), -- Olvia
(3313, 12850, 12745, 0), -- Trak'gen
(3314, 10611, 0, 0), -- Urtharo
(3315, 1896, 0, 0), -- Tor'phan
(332, 2711, 0, 0), -- Master Mathias Shaw
(3322, 0, 0, 2552), -- Kaja
(3323, 2200, 0, 0), -- Horthus
(3324, 5277, 0, 0), -- Grol'dar
(3325, 5277, 0, 0), -- Mirket
(3326, 5277, 0, 0), -- Zevrost
(3327, 2184, 0, 0), -- Gest
(3328, 5278, 0, 0), -- Ormok
(3329, 3346, 0, 0), -- Kor'jus
(3330, 5304, 0, 0), -- Muragus
(3331, 2179, 2711, 0), -- Kareth
(3332, 1117, 0, 0), -- Lumak
(3333, 1117, 0, 0), -- Shankys
(3334, 2199, 34717, 0), -- Rekkul
(3335, 2199, 0, 0), -- Hagrus
(33359, 5598, 0, 14105), -- -Unknown-
(3336, 5278, 0, 0), -- Takrin Pathseeker
(3337, 5291, 0, 0), -- Kargal Battlescar
(3338, 17383, 0, 0), -- Sergra Darkthorn
(3339, 3364, 0, 0), -- Captain Thalo'thas Brightsun
(3342, 12329, 0, 0), -- Shan'ti
(3345, 12746, 0, 6230), -- Godan
(3347, 3699, 3697, 0), -- Yelmak
(3348, 0, 3698, 0), -- Kor'geld
(3350, 1906, 12745, 0), -- Asoran
(3351, 2717, 0, 0), -- Magenius
(3352, 17383, 0, 5262), -- Ormak Grimshot
(3353, 10612, 10611, 0), -- Grezz Ragefist
(3354, 1983, 0, 0), -- Sorek
(3355, 1903, 0, 0), -- Saru Steelfury
(3356, 1903, 13611, 0), -- Sumi
(3357, 1910, 0, 0), -- Makaru
(3358, 2714, 0, 0), -- Gorina
(3360, 3361, 0, 0), -- Koru
(3361, 1897, 0, 0), -- Shoma
(3363, 1908, 0, 0), -- Magar
(3366, 3699, 0, 0), -- Tamar
(3367, 2197, 0, 0), -- Felika
(3368, 2827, 2196, 0), -- Borstan
(3369, 0, 12745, 0), -- Gotri
(3370, 5303, 0, 0), -- Urtrun Clanbringer
(338, 12937, 0, 0), -- Mazen Mac'Nadir
(3390, 2200, 12870, 0), -- Apothecary Helbrim
(3391, 4994, 13855, 12523), -- Gazlowe
(3399, 2827, 0, 0), -- Zamja
(340, 2705, 12860, 0), -- Kendor Kabonka
(3400, 3351, 0, 0), -- Xen'to
(3404, 6233, 0, 0), -- Jandi
(3405, 3696, 0, 0), -- Zeal'aya
(3409, 1909, 0, 0), -- Zendo'jian
(3412, 4994, 0, 0), -- Nogg
(3413, 1911, 0, 0), -- Sovik
(34258, 13625, 0, 0), -- -Unknown-
(34261, 1902, 0, 0), -- -Unknown-
(3428, 1908, 0, 0), -- Korran
(34284, 12801, 0, 0), -- -Unknown-
(3429, 11322, 0, 0), -- Thork
(3431, 1904, 0, 0), -- Grenthar
(3432, 11019, 2052, 0), -- Mankrik
(3442, 1911, 0, 0), -- Sputtervalve
(3443, 2202, 0, 0), -- Grub
(3445, 1911, 0, 0), -- Supervisor Lugwizzle
(3446, 2704, 0, 0), -- Mebok Mizzyrix
(3448, 12328, 0, 0), -- Tonga Runetotem
(34503, 1901, 0, 0), -- -Unknown-
(34504, 12285, 0, 15460), -- -Unknown-
(34509, 1905, 0, 0), -- -Unknown-
(34511, 31268, 2081, 0), -- -Unknown-
(34513, 12329, 0, 0), -- -Unknown-
(3453, 2695, 0, 0), -- Wharfmaster Dizzywig
(34544, 14879, 0, 0), -- -Unknown-
(34545, 1896, 2051, 0), -- -Unknown-
(34560, 12951, 0, 5262), -- -Unknown-
(34571, 3364, 0, 0), -- -Unknown-
(34594, 1905, 1905, 0), -- -Unknown-
(3464, 11042, 0, 0), -- Gazrog
(34651, 12862, 0, 0), -- -Unknown-
(34656, 10611, 12452, 0), -- -Unknown-
(34674, 1911, 0, 30128), -- -Unknown-
(34698, 2716, 0, 0), -- -Unknown-
(34715, 2809, 0, 0), -- Sky-Captain "Dusty" Blastnut
(34717, 31824, 0, 0), -- Crewman Pipewrench
(34718, 31824, 0, 0), -- Crewman Deadbolt
(34719, 31824, 0, 0), -- Crewman Grit
(34721, 10611, 0, 0), -- Chief Officer Ograh
(34723, 13631, 0, 0), -- Watcher Tolwe
(34761, 5598, 0, 14105), -- -Unknown-
(34765, 4994, 0, 0), -- Zelli Hotnozzle
(3477, 1903, 0, 0), -- Hraq
(3478, 1903, 0, 0), -- Traugh
(3479, 10612, 0, 0), -- Nargal Deatheye
(3480, 2197, 0, 0), -- Moorane Hearthgrain
(3481, 11763, 0, 0), -- Barg
(3482, 1910, 0, 0), -- Tari'qa
(3483, 2711, 0, 0), -- Jahan Hawkwing
(3484, 12991, 0, 0), -- Kil'hala
(3485, 2200, 0, 0), -- Wrahk
(34850, 3364, 0, 2552), -- -Unknown-
(3486, 2184, 0, 0), -- Halija Whitestrider
(34864, 5305, 1984, 2551), -- -Unknown-
(3487, 12744, 12745, 0), -- Kalyimah Stormcloud
(3488, 0, 0, 5262), -- Uthrok
(3489, 2827, 13406, 0), -- Zargh
(3490, 6233, 0, 0), -- Hula'mahi
(3491, 1903, 0, 0), -- Ironzar
(34913, 3364, 0, 52052), -- -Unknown-
(34916, 5305, 1984, 2551), -- -Unknown-
(3492, 2184, 0, 0), -- Vexspindle
(3493, 5532, 0, 0), -- Grazlix
(34936, 3364, 0, 0), -- -Unknown-
(3494, 4994, 0, 0), -- Tinkerwiz
(3495, 1911, 0, 0), -- Gagsprocket
(34955, 47034, 0, 0), -- Karg Skullgore
(3496, 12850, 12859, 0), -- Fuzruckle
(3497, 6227, 0, 0), -- Kilxx
(3498, 12744, 0, 0), -- Jazzik
(34987, 46987, 21572, 0), -- Hunara
(34988, 31253, 0, 0), -- Landuen Moonclaw
(34989, 47013, 0, 47014), -- Rissa Shadeleaf
(3499, 2184, 0, 0), -- Ranik
(34997, 21555, 0, 0), -- Devin Fardale
(34998, 43014, 0, 0), -- Alison Devay
(3501, 12285, 0, 5260), -- Horde Guard
(3502, 3361, 0, 2552), -- Ratchet Bruiser
(35068, 11383, 0, 0), -- Gotura Fourwinds
(35073, 27407, 0, 0), -- Farseer Eannu
(35112, 46737, 0, 0), -- -Unknown-
(35115, 3364, 0, 0), -- -Unknown-
(35124, 2695, 0, 0), -- -Unknown-
(3517, 0, 2081, 0), -- Rellian Greenspyre
(3518, 2197, 0, 0), -- Thomas Miller
(3521, 2177, 0, 0), -- Ak'Zeloth
(35232, 5305, 1984, 2551), -- -Unknown-
(35281, 31743, 29642, 0), -- Rukua
(35364, 47844, 47846, 0), -- Slahtz
(35365, 47844, 47846, 0), -- Behsten
(35378, 0, 0, 52052), -- -Unknown-
(35477, 2708, 0, 0), -- Little Adeline
(35504, 5305, 1984, 52052), -- -Unknown-
(35509, 5305, 1984, 2552), -- -Unknown-
(35550, 46737, 0, 0), -- -Unknown-
(35551, 3364, 0, 0), -- -Unknown-
(35552, 46737, 0, 0), -- -Unknown-
(35566, 56171, 0, 52052), -- -Unknown-
(3561, 5285, 3694, 0), -- Kyrai
(35618, 0, 0, 2552), -- -Unknown-
(3562, 1908, 0, 0), -- Alaindia
(3567, 12328, 0, 0), -- Tallonkai Swiftroot
(3571, 5598, 0, 2550), -- Teldrassil Sentinel
(3572, 1117, 0, 0), -- Zizzek
(35839, 12944, 2445, 0), -- -Unknown-
(35840, 3364, 0, 0), -- -Unknown-
(35869, 2559, 0, 0), -- -Unknown-
(3587, 2197, 0, 0), -- Lyrai
(35870, 5276, 0, 0), -- -Unknown-
(35871, 2184, 0, 0), -- -Unknown-
(35872, 1908, 0, 0), -- -Unknown-
(35873, 1908, 0, 0), -- -Unknown-
(35874, 0, 0, 2552), -- -Unknown-
(3588, 1896, 0, 0), -- Khardan Proudblade
(3589, 0, 0, 5258), -- Keina
(35906, 54824, 0, 0), -- -Unknown-
(35911, 46737, 0, 0), -- -Unknown-
(35915, 5305, 1984, 2552), -- -Unknown-
(3592, 1902, 0, 0), -- Andiss
(3593, 1899, 0, 0), -- Alyissia
(3594, 5281, 0, 0), -- Frahun Shadewhisper
(3595, 2813, 0, 0), -- Shanda
(3596, 1905, 0, 0), -- Ayanna Everstride
(3597, 5292, 0, 0), -- Mardant Strongoak
(3598, 2180, 0, 0), -- Kyra Windblade
(3599, 2178, 0, 0), -- Jannok Breezesong
(3600, 2176, 0, 0), -- Laurna Morninglight
(3601, 2183, 0, 0), -- Dazalar
(3602, 1908, 0, 0), -- Kal
(3603, 3699, 3697, 0), -- Cyndra Kindwhisper
(36057, 5305, 0, 2552), -- -Unknown-
(3607, 1117, 0, 0), -- Androl Oakhand
(3608, 12854, 0, 0), -- Aldia
(3609, 1903, 0, 0), -- Shalomon
(3610, 0, 0, 5259), -- Jeena Featherbow
(36132, 2198, 0, 0), -- -Unknown-
(36138, 2198, 0, 0), -- -Unknown-
(3614, 2718, 0, 0), -- Narret Shadowgrove
(36140, 12791, 0, 2552), -- -Unknown-
(3615, 3433, 0, 0), -- Devrak
(36170, 3364, 0, 0), -- -Unknown-
(36190, 2716, 0, 2552), -- -Unknown-
(3620, 1904, 0, 0), -- Harruk
(36205, 1899, 0, 0), -- -Unknown-
(36211, 3364, 0, 2552), -- -Unknown-
(36236, 25160, 0, 0), -- -Unknown-
(36290, 3364, 0, 0), -- -Unknown-
(36292, 25160, 0, 0), -- -Unknown-
(36293, 4439, 0, 0), -- -Unknown-
(36312, 30403, 30403, 18680), -- -Unknown-
(36396, 3364, 3364, 0), -- -Unknown-
(36397, 3364, 3364, 0), -- -Unknown-
(36399, 3364, 3364, 37692), -- -Unknown-
(36451, 0, 0, 2552), -- -Unknown-
(36452, 3364, 0, 0), -- -Unknown-
(36454, 1161, 0, 0), -- -Unknown-
(36455, 52054, 0, 0), -- -Unknown-
(36456, 2028, 0, 0), -- -Unknown-
(36457, 0, 0, 15460), -- -Unknown-
(36458, 25646, 0, 0), -- -Unknown-
(36460, 25160, 0, 0), -- -Unknown-
(36461, 25160, 0, 2552), -- -Unknown-
(36479, 49311, 0, 0), -- Archmage Mordent Evenshade
(36488, 2695, 0, 0), -- -Unknown-
(36491, 44236, 0, 0), -- -Unknown-
(36492, 44236, 0, 0), -- -Unknown-
(36506, 32610, 0, 0), -- Daros Moonlance
(3658, 5280, 0, 0), -- Lizzarik
(36602, 3364, 0, 2552), -- -Unknown-
(36616, 0, 0, 2552), -- -Unknown-
(36628, 1908, 0, 0), -- -Unknown-
(36629, 0, 0, 2552), -- -Unknown-
(36630, 2184, 0, 0), -- -Unknown-
(36631, 1908, 0, 0), -- -Unknown-
(36632, 5276, 0, 0), -- -Unknown-
(3665, 2717, 0, 0), -- Crane Operator Bigglefuzz
(36651, 12944, 2445, 0), -- -Unknown-
(36652, 2559, 0, 0), -- -Unknown-
(36653, 3364, 0, 2552), -- -Unknown-
(36671, 31268, 2081, 0), -- -Unknown-
(3669, 3494, 1906, 0), -- Lord Cobrahn
(36690, 3364, 0, 2552), -- -Unknown-
(36695, 1908, 0, 0), -- -Unknown-
(36698, 0, 0, 2552), -- -Unknown-
(3670, 1909, 5286, 0), -- Lord Pythas
(3671, 1908, 0, 0), -- Lady Anacondra
(36717, 1908, 0, 0), -- -Unknown-
(3673, 5287, 0, 0), -- Lord Serpentis
(36743, 46737, 0, 0), -- -Unknown-
(36779, 1908, 0, 0), -- -Unknown-
(3678, 1908, 0, 0), -- Disciple of Naralex
(36797, 0, 0, 2552), -- -Unknown-
(36798, 0, 0, 2552), -- -Unknown-
(36809, 31268, 2081, 0), -- -Unknown-
(36810, 25160, 0, 0), -- -Unknown-
(3706, 2176, 0, 0), -- Tai'jin
(37065, 0, 0, 2552), -- -Unknown-
(37067, 2695, 0, 0), -- -Unknown-
(37072, 2182, 0, 0), -- Rogg
(37102, 3364, 0, 0), -- -Unknown-
(375, 1907, 0, 0), -- Priestess Anetta
(376, 2176, 0, 0), -- High Priestess Laurena
(377, 1908, 0, 0), -- Priestess Josetta
(37783, 0, 0, 15460), -- -Unknown-
(37784, 3364, 0, 2552), -- -Unknown-
(37805, 25160, 0, 0), -- -Unknown-
(37806, 25160, 0, 0), -- -Unknown-
(37808, 57214, 0, 0), -- -Unknown-
(37815, 0, 0, 15460), -- -Unknown-
(37885, 2184, 0, 0), -- -Unknown-
(37911, 1897, 0, 0), -- -Unknown-
(37912, 1897, 0, 0), -- -Unknown-
(37916, 10612, 11019, 0), -- -Unknown-
(37938, 10611, 0, 0), -- -Unknown-
(37946, 3364, 0, 2552), -- -Unknown-
(38037, 12469, 0, 0), -- -Unknown-
(38144, 2198, 0, 0), -- -Unknown-
(38149, 56171, 0, 0), -- -Unknown-
(38192, 25160, 0, 0), -- -Unknown-
(38210, 2827, 0, 36629), -- -Unknown-
(38217, 1814, 0, 2507), -- -Unknown-
(38218, 3364, 0, 2552), -- -Unknown-
(38221, 3364, 0, 2552), -- -Unknown-
(38225, 14085, 0, 14118), -- -Unknown-
(38242, 19903, 2040, 0), -- -Unknown-
(38243, 9477, 0, 0), -- -Unknown-
(38244, 9467, 9467, 0), -- -Unknown-
(38245, 18082, 0, 0), -- -Unknown-
(38246, 9482, 0, 0), -- -Unknown-
(38247, 0, 0, 5260), -- -Unknown-
(38268, 8178, 0, 0), -- -Unknown-
(38272, 2184, 2184, 0), -- -Unknown-
(38278, 2813, 0, 0), -- -Unknown-
(38279, 1907, 0, 0), -- -Unknown-
(38281, 2813, 1961, 0), -- -Unknown-
(38282, 8178, 0, 5260), -- -Unknown-
(38300, 15910, 0, 0), -- -Unknown-
(38301, 32841, 0, 5260), -- -Unknown-
(38324, 17123, 12454, 0), -- -Unknown-
(38326, 9477, 0, 0), -- -Unknown-
(38363, 0, 0, 34034), -- -Unknown-
(3840, 3494, 35719, 0), -- Druid of the Fang
(3841, 0, 0, 5259), -- Caylais Moonfeather
(38415, 56171, 0, 0), -- -Unknown-
(38423, 52875, 0, 0), -- -Unknown-
(38426, 10616, 0, 15460), -- -Unknown-
(38437, 19903, 13319, 0), -- -Unknown-
(38440, 36791, 0, 0), -- -Unknown-
(38442, 33981, 19915, 0), -- -Unknown-
(38464, 30403, 30403, 18680), -- -Unknown-
(38465, 1908, 0, 0), -- -Unknown-
(38466, 5276, 0, 0), -- -Unknown-
(38467, 5278, 0, 2552), -- -Unknown-
(38469, 2179, 2179, 42775), -- -Unknown-
(38470, 46737, 0, 0), -- -Unknown-
(38474, 3364, 0, 2552), -- -Unknown-
(38539, 46737, 0, 0), -- -Unknown-
(38553, 2198, 0, 0), -- -Unknown-
(38611, 10616, 0, 15460), -- -Unknown-
(38614, 3364, 0, 2552), -- -Unknown-
(38616, 25160, 0, 0), -- -Unknown-
(38618, 25160, 0, 0), -- -Unknown-
(3873, 2147, 2052, 0), -- Tormented Officer
(38762, 4439, 0, 0), -- -Unknown-
(3877, 3432, 0, 0), -- Wailing Guardsman
(38780, 5598, 0, 2550), -- -Unknown-
(38781, 2714, 0, 0), -- -Unknown-
(38783, 1908, 0, 0), -- -Unknown-
(38791, 1908, 0, 0), -- -Unknown-
(38792, 1908, 0, 0), -- -Unknown-
(38793, 12944, 2445, 0), -- -Unknown-
(38794, 1908, 0, 0), -- -Unknown-
(38795, 5276, 0, 0), -- -Unknown-
(38796, 2184, 0, 0), -- -Unknown-
(38797, 2559, 0, 0), -- -Unknown-
(38798, 0, 0, 2552), -- -Unknown-
(38799, 1908, 0, 0), -- -Unknown-
(3881, 2827, 2202, 0), -- Grimtak
(38853, 1908, 0, 0), -- -Unknown-
(3887, 11264, 0, 0), -- Baron Silverlaine
(38898, 1905, 0, 2551), -- -Unknown-
(38899, 1905, 0, 2551), -- -Unknown-
(38911, 2184, 0, 15807), -- -Unknown-
(38913, 52060, 0, 0), -- -Unknown-
(38915, 29171, 0, 5261), -- -Unknown-
(38926, 52057, 0, 0), -- -Unknown-
(38931, 52875, 0, 0), -- -Unknown-
(38938, 23428, 23428, 0), -- -Unknown-
(38939, 12183, 0, 0), -- -Unknown-
(38952, 31253, 0, 0), -- -Unknown-
(38953, 14085, 0, 14118), -- -Unknown-
(38966, 14085, 0, 14118), -- -Unknown-
(39017, 3364, 0, 2552), -- -Unknown-
(39027, 19903, 13319, 0), -- -Unknown-
(39028, 28914, 0, 0), -- -Unknown-
(39062, 44218, 0, 0), -- -Unknown-
(39072, 33493, 0, 0), -- -Unknown-
(39095, 5305, 1984, 2551), -- -Unknown-
(39260, 1896, 0, 0), -- -Unknown-
(39261, 5278, 0, 5261), -- -Unknown-
(39267, 1897, 0, 0), -- -Unknown-
(39268, 10616, 0, 2552), -- -Unknown-
(39269, 58196, 39660, 0), -- -Unknown-
(39270, 5289, 0, 0), -- -Unknown-
(3933, 2202, 0, 0), -- Hai'zan
(3934, 3362, 0, 0), -- Innkeeper Boorand Plainswind
(3935, 2827, 0, 0), -- Toddrick
(39351, 27791, 0, 0), -- -Unknown-
(39352, 39823, 0, 0), -- -Unknown-
(39353, 28584, 0, 0), -- -Unknown-
(39590, 44735, 0, 0), -- -Unknown-
(39605, 30414, 0, 0), -- -Unknown-
(39858, 63052, 0, 0), -- -Unknown-
(39869, 31253, 0, 0), -- -Unknown-
(39927, 31309, 0, 0), -- -Unknown-
(39928, 24155, 0, 0), -- -Unknown-
(39931, 12329, 0, 0), -- -Unknown-
(40, 1910, 0, 0), -- Kobold Miner
(40254, 31253, 0, 0), -- -Unknown-
(40278, 4564, 0, 0), -- -Unknown-
(40331, 31309, 0, 0), -- -Unknown-
(40333, 41815, 0, 36618), -- -Unknown-
(40336, 12902, 0, 0), -- -Unknown-
(4043, 1903, 0, 0), -- Galthuk
(4047, 5304, 0, 0), -- Zor Lonetree
(40558, 1911, 0, 0), -- -Unknown-
(40578, 33214, 0, 0), -- -Unknown-
(40757, 13337, 0, 0), -- -Unknown-
(4078, 5304, 0, 0), -- Collin Mauren
(40833, 31253, 0, 0), -- -Unknown-
(4087, 5599, 0, 0), -- Arias'ta Bladesinger
(4088, 5598, 0, 0), -- Elanaria
(4089, 2179, 2053, 0), -- Sildanair
(40890, 0, 0, 5258), -- -Unknown-
(40891, 5956, 0, 0), -- -Unknown-
(4090, 2176, 0, 0), -- Astarii Starseeker
(4091, 5277, 0, 0), -- Jandria
(4092, 1907, 0, 0), -- Lariia
(40951, 2714, 0, 0), -- -Unknown-
(40997, 13339, 0, 0), -- -Unknown-
(41006, 5285, 0, 0), -- -Unknown-
(41008, 56004, 0, 0), -- -Unknown-
(41015, 54824, 0, 2552), -- -Unknown-
(41029, 56475, 0, 0), -- -Unknown-
(41142, 6680, 0, 0), -- -Unknown-
(41146, 0, 31824, 0), -- -Unknown-
(41175, 6680, 0, 0), -- -Unknown-
(41181, 14880, 9858, 0), -- -Unknown-
(41182, 14880, 14880, 2100), -- -Unknown-
(41237, 14880, 9858, 0), -- -Unknown-
(41335, 22215, 22215, 0), -- -Unknown-
(41363, 31824, 0, 0), -- -Unknown-
(4138, 5278, 0, 5262), -- Jeen'ra Nightrunner
(41393, 1903, 0, 0), -- -Unknown-
(4146, 0, 0, 5259), -- Jocaste
(41502, 52057, 0, 0), -- -Unknown-
(4156, 1117, 0, 0), -- Astaia
(41578, 12282, 0, 0), -- -Unknown-
(4160, 2716, 3695, 0), -- Ainethil
(41611, 14880, 9858, 0), -- -Unknown-
(41621, 5289, 0, 0), -- -Unknown-
(4163, 5281, 0, 0), -- Syurna
(4165, 2177, 0, 0), -- Elissa Dumas
(41671, 1910, 0, 0), -- -Unknown-
(4169, 2196, 0, 0), -- Jaeana
(4171, 1899, 0, 0), -- Merelyssa
(41763, 14880, 9858, 0), -- -Unknown-
(41786, 12901, 0, 0), -- -Unknown-
(41804, 11383, 1961, 0), -- -Unknown-
(41846, 1911, 0, 0), -- -Unknown-
(41860, 0, 0, 5259), -- -Unknown-
(41861, 0, 0, 5259), -- -Unknown-
(4203, 1899, 0, 0), -- Ariyell Skyshadow
(4204, 1908, 0, 0), -- Firodren Mooncaller
(4205, 0, 0, 5259), -- Dorion
(4210, 2196, 0, 0), -- Alegorn
(42131, 30445, 0, 59023), -- -Unknown-
(4214, 2179, 0, 0), -- Erion Shadewhisper
(42141, 10612, 11019, 0), -- -Unknown-
(42146, 12182, 0, 0), -- -Unknown-
(4215, 2180, 0, 0), -- Anishar
(4217, 5600, 0, 0), -- Mathrengyl Bearwalker
(4218, 5293, 0, 0), -- Denatharion
(4219, 3494, 0, 0), -- Fylerian Nightwing
(4220, 3696, 0, 0), -- Cyroen
(4221, 1117, 0, 0), -- Talaelar
(42216, 1899, 143, 0), -- -Unknown-
(42218, 0, 21572, 2551), -- -Unknown-
(4222, 1117, 0, 0), -- Voloren
(4223, 3351, 0, 0), -- Fyldan
(42256, 21555, 0, 0), -- -Unknown-
(42259, 2184, 0, 0), -- -Unknown-
(4226, 2200, 3695, 0), -- Ulthir
(42288, 2827, 2196, 0), -- -Unknown-
(4230, 12852, 0, 0), -- Yldan
(4232, 1905, 0, 0), -- Glorandiir
(42387, 54879, 0, 0), -- -Unknown-
(42407, 1899, 143, 62285), -- -Unknown-
(42421, 1117, 0, 0), -- -Unknown-
(42497, 2827, 0, 0), -- -Unknown-
(42506, 2827, 0, 0), -- -Unknown-
(4254, 1910, 0, 0), -- Geofram Bouldertoe
(4256, 1910, 0, 0), -- Golnir Bouldertoe
(4258, 1903, 0, 0), -- Bengus Deepforge
(4259, 5532, 0, 0), -- Thurgrum Deepforge
(42594, 2184, 0, 0), -- -Unknown-
(42618, 9482, 0, 0), -- -Unknown-
(42619, 1907, 0, 0), -- -Unknown-
(4262, 5598, 0, 2550), -- Darnassus Sentinel
(42637, 57034, 0, 0), -- -Unknown-
(4266, 12856, 0, 0), -- Danlyia
(42677, 54879, 0, 0), -- -Unknown-
(42684, 58137, 57763, 0), -- -Unknown-
(42707, 19987, 19987, 38150), -- -Unknown-
(4278, 41343, 25818, 0), -- Commander Springvale
(42846, 5745, 0, 0), -- -Unknown-
(42853, 1908, 0, 0), -- -Unknown-
(42885, 52517, 0, 0), -- -Unknown-
(42917, 52057, 0, 0), -- -Unknown-
(42928, 49775, 49774, 0), -- -Unknown-
(42937, 14877, 0, 0), -- -Unknown-
(42938, 56117, 0, 0), -- -Unknown-
(42946, 30178, 0, 0), -- -Unknown-
(43005, 49311, 0, 0), -- -Unknown-
(43006, 49311, 0, 0), -- -Unknown-
(43011, 1909, 0, 65434), -- -Unknown-
(43034, 2703, 0, 0), -- -Unknown-
(4311, 5288, 0, 0), -- Holgar Stormaxe
(43239, 1117, 0, 0), -- -Unknown-
(43277, 3364, 0, 34325), -- -Unknown-
(43278, 37, 0, 2551), -- -Unknown-
(43381, 12744, 0, 0), -- -Unknown-
(43410, 30078, 0, 0), -- -Unknown-
(43411, 12744, 0, 0), -- -Unknown-
(43427, 29171, 0, 5261), -- -Unknown-
(43429, 1903, 0, 0), -- -Unknown-
(43431, 1910, 0, 0), -- -Unknown-
(43464, 59140, 0, 0), -- -Unknown-
(43481, 0, 0, 5259), -- -Unknown-
(43493, 12858, 0, 0), -- -Unknown-
(43513, 1904, 0, 0), -- -Unknown-
(43551, 0, 12853, 0), -- -Unknown-
(43558, 1908, 0, 0), -- -Unknown-
(43566, 52528, 52528, 52052), -- -Unknown-
(43694, 3367, 0, 0), -- -Unknown-
(43703, 3364, 0, 2552), -- -Unknown-
(43727, 52528, 0, 15460), -- -Unknown-
(43840, 45861, 0, 0), -- -Unknown-
(43907, 3364, 0, 2552), -- -Unknown-
(43945, 2703, 0, 0), -- -Unknown-
(43946, 2703, 0, 0), -- -Unknown-
(43953, 12850, 12745, 0), -- -Unknown-
(43956, 2827, 13407, 0), -- -Unknown-
(43957, 0, 1961, 0), -- -Unknown-
(44158, 1903, 0, 0), -- -Unknown-
(44161, 2184, 0, 2551), -- -Unknown-
(44162, 43581, 0, 0), -- -Unknown-
(44197, 58273, 0, 0), -- -Unknown-
(44200, 2184, 0, 0), -- -Unknown-
(44216, 5304, 0, 0), -- -Unknown-
(44217, 5287, 0, 0), -- -Unknown-
(44223, 5289, 0, 0), -- -Unknown-
(44236, 2716, 0, 0), -- -Unknown-
(44238, 12750, 0, 0), -- -Unknown-
(44239, 12742, 0, 0), -- -Unknown-
(44241, 12751, 0, 0), -- -Unknown-
(44243, 12742, 0, 0), -- -Unknown-
(44247, 3191, 0, 36628), -- -Unknown-
(44249, 13631, 0, 57240), -- -Unknown-
(44345, 2704, 3756, 12523), -- -Unknown-
(44388, 3364, 0, 2552), -- -Unknown-
(44395, 1908, 0, 0), -- -Unknown-
(44455, 12944, 2445, 0), -- -Unknown-
(44459, 1908, 0, 0), -- -Unknown-
(44460, 3364, 0, 0), -- -Unknown-
(44461, 0, 0, 2552), -- -Unknown-
(44464, 2184, 0, 0), -- -Unknown-
(44465, 1908, 0, 0), -- -Unknown-
(44468, 5276, 0, 0), -- -Unknown-
(44469, 2559, 0, 0), -- -Unknown-
(44583, 11343, 0, 0), -- -Unknown-
(44723, 10611, 7120, 0), -- -Unknown-
(44725, 31266, 0, 0), -- -Unknown-
(44726, 13337, 0, 0), -- -Unknown-
(44735, 14836, 0, 0), -- -Unknown-
(44740, 45203, 0, 0), -- -Unknown-
(44743, 15424, 0, 45210), -- -Unknown-
(44779, 12854, 0, 0), -- -Unknown-
(44780, 1910, 12870, 0), -- -Unknown-
(44781, 1903, 0, 0), -- -Unknown-
(448, 1905, 0, 0), -- Hogger
(4485, 2183, 2183, 0), -- Belgrom Rockmaul
(44851, 3346, 0, 0), -- -Unknown-
(44871, 5289, 0, 5260), -- -Unknown-
(44872, 5289, 0, 5260), -- -Unknown-
(44874, 5289, 0, 5260), -- -Unknown-
(44876, 5289, 0, 5260), -- -Unknown-
(44877, 5289, 0, 5260), -- -Unknown-
(44878, 5289, 0, 5260), -- -Unknown-
(44880, 0, 0, 8192), -- -Unknown-
(44919, 3433, 0, 0), -- -Unknown-
(44975, 1117, 0, 0), -- -Unknown-
(45008, 6225, 13854, 0), -- -Unknown-
(45015, 13631, 0, 0), -- -Unknown-
(45019, 60822, 60822, 0), -- -Unknown-
(45023, 3433, 0, 19993), -- -Unknown-
(45029, 9482, 0, 0), -- -Unknown-
(45081, 25622, 0, 0), -- -Unknown-
(45086, 2703, 0, 0), -- -Unknown-
(45093, 1910, 12870, 0), -- -Unknown-
(45094, 12854, 0, 0), -- -Unknown-
(45095, 17123, 17123, 0), -- -Unknown-
(45137, 56157, 0, 0), -- -Unknown-
(45138, 4993, 0, 0), -- -Unknown-
(45139, 14873, 0, 0), -- -Unknown-
(452, 2711, 0, 0), -- Riverpaw Bandit
(45230, 12754, 0, 14642), -- -Unknown-
(45244, 39749, 0, 0), -- -Unknown-
(45253, 46737, 0, 0), -- -Unknown-
(45306, 4994, 0, 0), -- -Unknown-
(45337, 12421, 0, 0), -- -Unknown-
(45339, 13709, 0, 0), -- -Unknown-
(45548, 1903, 0, 0), -- -Unknown-
(45549, 1903, 13611, 0), -- -Unknown-
(45551, 3351, 0, 0), -- -Unknown-
(45552, 1910, 12851, 0), -- -Unknown-
(45553, 12854, 12855, 0), -- -Unknown-
(45558, 3696, 0, 0), -- -Unknown-
(45563, 2197, 13855, 0), -- -Unknown-
(45565, 2703, 13859, 0), -- -Unknown-
(45566, 2703, 13859, 0), -- -Unknown-
(456, 1907, 0, 0), -- Murloc Minor Oracle
(45709, 12901, 0, 0), -- -Unknown-
(45713, 1117, 0, 21554), -- -Unknown-
(45714, 2030, 0, 0), -- -Unknown-
(45717, 2711, 2711, 0), -- -Unknown-
(45718, 15274, 0, 0), -- -Unknown-
(45720, 52009, 0, 0), -- -Unknown-
(458, 1897, 0, 5870), -- Murloc Hunter
(45814, 61337, 0, 50150), -- -Unknown-
(45822, 61337, 0, 50150), -- -Unknown-
(45827, 5289, 0, 5260), -- -Unknown-
(45830, 1117, 0, 0), -- -Unknown-
(459, 1907, 0, 0), -- Drusilla La Salle
(46, 1897, 0, 0), -- Murloc Forager
(46078, 3364, 12332, 0), -- -Unknown-
(46080, 12862, 0, 0), -- -Unknown-
(46082, 31824, 0, 0), -- -Unknown-
(461, 2559, 0, 0), -- Demisette Cloyce
(46142, 5286, 0, 2551), -- -Unknown-
(46180, 13709, 0, 0), -- -Unknown-
(46181, 13709, 0, 0), -- -Unknown-
(46357, 1910, 0, 0), -- -Unknown-
(46358, 3346, 0, 0), -- -Unknown-
(46359, 1903, 13604, 0), -- -Unknown-
(465, 2717, 0, 0), -- Barkeep Dobbins
(46555, 17383, 0, 0), -- -Unknown-
(46556, 49671, 49671, 0), -- -Unknown-
(466, 46987, 143, 0), -- General Marcus Jonathan
(46622, 3346, 0, 0), -- -Unknown-
(46642, 2703, 13859, 0), -- -Unknown-
(46667, 10613, 62373, 0), -- -Unknown-
(46708, 3351, 2197, 0), -- -Unknown-
(46709, 2827, 0, 0), -- -Unknown-
(46716, 12862, 0, 0), -- -Unknown-
(46741, 6233, 0, 0), -- -Unknown-
(46742, 6233, 0, 0), -- -Unknown-
(46889, 10611, 10612, 0), -- -Unknown-
(46890, 2711, 0, 0), -- -Unknown-
(46902, 62229, 0, 0), -- -Unknown-
(46906, 10616, 10616, 0), -- -Unknown-
(46940, 2177, 0, 0), -- -Unknown-
(46941, 2177, 0, 0), -- -Unknown-
(46942, 46987, 143, 0), -- -Unknown-
(46983, 853, 0, 25260), -- -Unknown-
(47030, 18167, 18166, 0), -- -Unknown-
(47031, 0, 0, 49711), -- -Unknown-
(47091, 0, 0, 2551), -- -Unknown-
(47145, 49341, 56175, 0), -- -Unknown-
(47146, 57016, 0, 0), -- -Unknown-
(47232, 2029, 0, 0), -- -Unknown-
(47233, 1900, 5281, 0), -- -Unknown-
(47246, 12868, 0, 0), -- -Unknown-
(47247, 12742, 0, 0), -- -Unknown-
(47248, 12751, 0, 0), -- -Unknown-
(47253, 14873, 0, 0), -- -Unknown-
(47293, 57195, 57195, 0), -- -Unknown-
(47294, 47031, 0, 0), -- -Unknown-
(47297, 55193, 55194, 0), -- -Unknown-
(473, 1900, 0, 0), -- Morgan the Collector
(47311, 5303, 0, 0), -- -Unknown-
(47321, 17282, 0, 0), -- -Unknown-
(47335, 42222, 42224, 0), -- -Unknown-
(47336, 42222, 42224, 0), -- -Unknown-
(47395, 1910, 0, 0), -- -Unknown-
(474, 1907, 0, 0), -- Defias Rogue Wizard
(475, 1901, 0, 0), -- Kobold Tunneler
(47569, 12750, 0, 0), -- -Unknown-
(47571, 24324, 24324, 0), -- -Unknown-
(47582, 13709, 0, 0), -- -Unknown-
(47584, 13709, 0, 0), -- -Unknown-
(476, 1907, 0, 0), -- Kobold Geomancer
(47663, 10612, 0, 2507), -- -Unknown-
(47688, 2178, 5284, 62285), -- -Unknown-
(4772, 2715, 0, 0), -- Ultham Ironhorn
(47764, 1908, 0, 0), -- -Unknown-
(47767, 3433, 0, 0), -- -Unknown-
(47771, 6680, 0, 0), -- -Unknown-
(47788, 3433, 0, 0), -- -Unknown-
(478, 1905, 0, 0), -- Riverpaw Outrunner
(482, 2716, 0, 0), -- Elling Trias
(48229, 1910, 0, 0), -- -Unknown-
(48262, 14527, 0, 0), -- -Unknown-
(48278, 0, 62052, 0), -- -Unknown-
(483, 2197, 0, 0), -- Elaine Trias
(48439, 1911, 0, 2552), -- -Unknown-
(48440, 0, 62052, 0), -- -Unknown-
(48441, 0, 62052, 0), -- -Unknown-
(48442, 0, 62052, 0), -- -Unknown-
(48445, 10612, 0, 0), -- -Unknown-
(487, 1899, 2053, 2551), -- Protector Bialon
(48736, 46737, 0, 0), -- -Unknown-
(48737, 5598, 0, 14105), -- -Unknown-
(488, 1896, 2051, 2551), -- Protector Weaver
(489, 1897, 1957, 2551), -- Protector Dutfield
(490, 1897, 2053, 2551), -- Protector Gariel
(491, 1909, 0, 0), -- Quartermaster Lewis
(49477, 5191, 5191, 18713), -- -Unknown-
(49573, 46983, 0, 0), -- -Unknown-
(4959, 1117, 0, 0), -- Jorgen
(4960, 2176, 0, 0), -- Bishop DeLavey
(49622, 1908, 0, 0), -- -Unknown-
(49701, 3351, 0, 0), -- -Unknown-
(49736, 1899, 1985, 0), -- -Unknown-
(49737, 0, 13407, 0), -- -Unknown-
(4974, 2177, 0, 0), -- Aldwin Laughlin
(49741, 2182, 1984, 0), -- -Unknown-
(49745, 1900, 1900, 0), -- -Unknown-
(49748, 1906, 0, 0), -- -Unknown-
(49749, 1908, 0, 0), -- -Unknown-
(49750, 1906, 0, 0), -- -Unknown-
(49760, 1908, 0, 0), -- -Unknown-
(49769, 1908, 0, 0), -- -Unknown-
(49781, 14533, 13922, 0), -- -Unknown-
(49782, 11762, 11762, 0), -- -Unknown-
(49784, 13721, 0, 0), -- -Unknown-
(49791, 12991, 0, 0), -- -Unknown-
(49793, 2557, 0, 0), -- -Unknown-
(49806, 12285, 0, 2552), -- -Unknown-
(49808, 2182, 2182, 0), -- -Unknown-
(4981, 2716, 0, 0), -- Ben Trias
(49869, 21573, 21572, 0), -- -Unknown-
(49874, 5282, 10617, 0), -- -Unknown-
(49877, 21553, 0, 0), -- -Unknown-
(49923, 2180, 2180, 0), -- -Unknown-
(49927, 2183, 0, 34268), -- -Unknown-
(49939, 2178, 2711, 0), -- -Unknown-
(49940, 2176, 0, 0), -- -Unknown-
(49942, 1908, 0, 0), -- -Unknown-
(49968, 2527, 0, 0), -- -Unknown-
(49997, 9477, 0, 0), -- -Unknown-
(49998, 9482, 0, 0), -- -Unknown-
(500, 2184, 1906, 2551), -- Riverpaw Scout
(50001, 18082, 0, 0), -- -Unknown-
(50002, 9482, 0, 0), -- -Unknown-
(50004, 0, 0, 5260), -- -Unknown-
(50006, 12469, 0, 0), -- -Unknown-
(50011, 19903, 2040, 0), -- -Unknown-
(50015, 9467, 9467, 0), -- -Unknown-
(50022, 2813, 0, 0), -- -Unknown-
(50027, 2711, 0, 25861), -- -Unknown-
(50028, 11343, 0, 0), -- -Unknown-
(50029, 5276, 0, 0), -- -Unknown-
(50031, 2558, 0, 0), -- -Unknown-
(50032, 29908, 0, 20438), -- -Unknown-
(50033, 10612, 0, 0), -- -Unknown-
(50034, 13337, 0, 0), -- -Unknown-
(50035, 46737, 0, 0), -- -Unknown-
(50039, 10616, 10616, 0), -- -Unknown-
(50070, 12858, 0, 0), -- -Unknown-
(50082, 13339, 0, 0), -- -Unknown-
(50083, 56004, 0, 0), -- -Unknown-
(50084, 0, 0, 5259), -- -Unknown-
(50252, 1908, 0, 0), -- -Unknown-
(50307, 7944, 0, 0), -- -Unknown-
(50308, 31824, 1911, 0), -- -Unknown-
(50309, 12901, 0, 0), -- -Unknown-
(50323, 17112, 17112, 0), -- -Unknown-
(50371, 12944, 2445, 0), -- -Unknown-
(50474, 5305, 1984, 2552), -- -Unknown-
(50477, 33982, 33980, 0), -- -Unknown-
(50488, 17383, 0, 0), -- -Unknown-
(50497, 0, 0, 52052), -- -Unknown-
(50498, 2184, 0, 0), -- -Unknown-
(50499, 1908, 0, 0), -- -Unknown-
(50500, 12944, 2445, 0), -- -Unknown-
(50501, 5276, 0, 0), -- -Unknown-
(50502, 2559, 0, 0), -- -Unknown-
(50550, 62481, 0, 0), -- -Unknown-
(50567, 2197, 0, 0), -- -Unknown-
(50631, 48663, 48663, 0), -- -Unknown-
(50668, 3364, 0, 0), -- -Unknown-
(50678, 40004, 0, 0), -- -Unknown-
(50690, 49311, 0, 0), -- -Unknown-
(50714, 12421, 0, 0), -- -Unknown-
(50715, 13750, 0, 0), -- -Unknown-
(5100, 1911, 0, 0), -- Fillius Fizzlespinner
(5101, 1906, 0, 0), -- Bryllia Ironbrand
(5102, 1896, 0, 0), -- Dolman Steelfury
(5103, 1909, 0, 0), -- Grenil Steelfury
(5106, 0, 1985, 0), -- Bromiir Ormsen
(5107, 0, 2053, 0), -- Mangorn Flinthammer
(5109, 2197, 0, 0), -- Myra Tyrngaarde
(5110, 2707, 3694, 0), -- Barim Jurgenstaad
(5111, 2705, 0, 0), -- Innkeeper Firebrew
(5112, 2703, 0, 0), -- Gwenna Firebrew
(513, 2023, 0, 0), -- Murloc Netter
(5130, 5303, 0, 0), -- Jondor Steelbrow
(51307, 5292, 0, 0), -- -Unknown-
(51346, 5289, 0, 2507), -- -Unknown-
(51348, 1899, 143, 2551), -- -Unknown-
(5137, 1908, 0, 0), -- Reyna Stonebranch
(51371, 5598, 0, 2550), -- -Unknown-
(5138, 2707, 0, 0), -- Gwina Stonebranch
(51383, 5286, 6254, 2552), -- -Unknown-
(514, 1911, 0, 0), -- Smith Argus
(51400, 62484, 0, 0), -- -Unknown-
(51409, 0, 0, 15460), -- -Unknown-
(515, 1897, 0, 0), -- Murloc Raider
(51519, 1899, 143, 2551), -- -Unknown-
(5159, 2196, 0, 0), -- Daryl Riknussun
(5160, 3351, 0, 0), -- Emrul Riknussun
(5163, 1911, 0, 0), -- Burbik Gearspanner
(517, 1907, 0, 0), -- Murloc Oracle
(5175, 1911, 0, 0), -- Gearcutter Cogspinner
(5177, 2716, 3695, 0), -- Tally Berryfizz
(5178, 2200, 3695, 0), -- Soolie Berryfizz
(51788, 28914, 0, 2507), -- -Unknown-
(5188, 5284, 0, 0), -- Garyl
(51911, 5289, 0, 2507), -- -Unknown-
(51913, 1904, 0, 5262), -- -Unknown-
(51915, 1896, 143, 62285), -- -Unknown-
(51997, 1910, 0, 0), -- -Unknown-
(51998, 1900, 5284, 0), -- -Unknown-
(520, 5745, 0, 0), -- Brack
(52031, 2199, 13341, 0), -- -Unknown-
(52032, 2199, 13341, 0), -- -Unknown-
(52170, 1903, 0, 0), -- -Unknown-
(52190, 1903, 0, 0), -- -Unknown-
(52292, 1908, 0, 0), -- -Unknown-
(52335, 35740, 0, 0), -- -Unknown-
(52356, 3346, 0, 0), -- -Unknown-
(52357, 1896, 0, 5262), -- -Unknown-
(52358, 0, 0, 4046458859), -- -Unknown-
(52444, 57020, 0, 0), -- -Unknown-
(52467, 31309, 0, 0), -- -Unknown-
(52500, 29652, 0, 0), -- -Unknown-
(52501, 12328, 0, 0), -- -Unknown-
(52502, 12403, 0, 35804), -- -Unknown-
(52536, 37123, 0, 0), -- -Unknown-
(52537, 5305, 0, 0), -- -Unknown-
(52545, 34520, 29638, 0), -- -Unknown-
(52546, 5305, 1984, 0), -- -Unknown-
(52549, 14824, 0, 0), -- -Unknown-
(52556, 0, 0, 3758096448), -- -Unknown-
(52584, 11343, 0, 0), -- -Unknown-
(52636, 4994, 0, 0), -- -Unknown-
(52637, 1911, 0, 0), -- -Unknown-
(52640, 30078, 13611, 0), -- -Unknown-
(52641, 12856, 0, 0), -- -Unknown-
(52642, 1910, 0, 0), -- -Unknown-
(52643, 2715, 12745, 0), -- -Unknown-
(52644, 11343, 0, 0), -- -Unknown-
(52669, 24155, 0, 0), -- -Unknown-
(52670, 41815, 0, 36618), -- -Unknown-
(52703, 34874, 0, 0), -- -Unknown-
(52791, 69756, 0, 0), -- -Unknown-
(52822, 42755, 0, 0), -- -Unknown-
(52824, 34305, 0, 0), -- -Unknown-
(52825, 29748, 0, 0), -- -Unknown-
(52834, 29652, 0, 0), -- -Unknown-
(52838, 63052, 0, 0), -- -Unknown-
(52843, 13339, 0, 0), -- -Unknown-
(52844, 32425, 0, 0), -- -Unknown-
(52846, 13339, 0, 0), -- -Unknown-
(52847, 13339, 0, 0), -- -Unknown-
(52848, 13339, 0, 0), -- -Unknown-
(52849, 13339, 0, 0), -- -Unknown-
(52863, 69756, 0, 0), -- -Unknown-
(52899, 31309, 0, 0), -- -Unknown-
(52903, 4564, 0, 0), -- -Unknown-
(52904, 56231, 0, 0), -- -Unknown-
(52907, 57020, 0, 0), -- -Unknown-
(52924, 53835, 0, 14118), -- -Unknown-
(52925, 33354, 0, 0), -- -Unknown-
(52932, 63052, 0, 0), -- -Unknown-
(52933, 29809, 29809, 0), -- -Unknown-
(52938, 5597, 5597, 0), -- -Unknown-
(52956, 28426, 28754, 0), -- -Unknown-
(52958, 69642, 0, 0), -- -Unknown-
(52962, 69643, 0, 0), -- -Unknown-
(52986, 5276, 0, 0), -- -Unknown-
(53021, 768, 0, 0), -- -Unknown-
(53073, 34883, 0, 0), -- -Unknown-
(53076, 0, 12853, 0), -- -Unknown-
(53080, 14882, 10616, 0), -- -Unknown-
(53081, 31801, 0, 0), -- -Unknown-
(53085, 68013, 68013, 0), -- -Unknown-
(53093, 57021, 0, 0), -- -Unknown-
(53143, 69229, 0, 0), -- -Unknown-
(53365, 34305, 0, 0), -- -Unknown-
(53411, 29652, 0, 0), -- -Unknown-
(53412, 12328, 0, 0), -- -Unknown-
(53413, 12403, 0, 35804), -- -Unknown-
(53519, 58137, 57763, 0), -- -Unknown-
(53536, 58137, 57763, 0), -- -Unknown-
(53652, 58137, 57763, 0), -- -Unknown-
(53736, 56228, 0, 0), -- -Unknown-
(53738, 58137, 57763, 0), -- -Unknown-
(53781, 12744, 0, 0), -- -Unknown-
(53783, 0, 0, 5259), -- -Unknown-
(53805, 0, 0, 30906), -- -Unknown-
(53823, 29171, 0, 5261), -- -Unknown-
(5384, 1907, 0, 0), -- Brohann Caskbelly
(53840, 25698, 0, 0), -- -Unknown-
(53841, 43219, 0, 0), -- -Unknown-
(53842, 56343, 0, 0), -- -Unknown-
(53844, 50695, 0, 0), -- -Unknown-
(5386, 12742, 0, 0), -- Acolyte Dellis
(53905, 70936, 0, 0), -- -Unknown-
(5392, 1910, 0, 0), -- Yarr Hammerstone
(53925, 58137, 57763, 0), -- -Unknown-
(5413, 1903, 0, 0), -- Furen Longbeard
(54177, 1908, 0, 0), -- -Unknown-
(54178, 27862, 0, 0), -- -Unknown-
(54179, 5598, 0, 14105), -- -Unknown-
(54216, 13612, 0, 0), -- -Unknown-
(54217, 13612, 0, 0), -- -Unknown-
(54218, 13612, 0, 0), -- -Unknown-
(54371, 2711, 0, 0), -- -Unknown-
(54372, 3326, 0, 0), -- -Unknown-
(54392, 0, 0, 5259), -- -Unknown-
(54393, 0, 0, 5259), -- -Unknown-
(54401, 71713, 0, 0), -- -Unknown-
(54402, 71713, 0, 0), -- -Unknown-
(5479, 3366, 0, 0), -- Wu Shen
(5480, 3433, 0, 0), -- Ilsa Corbin
(5482, 2827, 2196, 0), -- Stephen Ryback
(5483, 3351, 0, 0), -- Erika Tate
(5484, 1907, 0, 0), -- Brother Benjamin
(5489, 5277, 0, 0), -- Brother Joshua
(5491, 5495, 0, 0), -- Arthur the Faithful
(5492, 5495, 0, 0), -- Katherine the Pure
(5493, 1117, 0, 0), -- Arnold Leland
(5494, 1117, 0, 0), -- Catherine Leland
(5495, 1907, 0, 0), -- Ursula Deline
(5496, 5277, 0, 0), -- Sandahl
(5498, 5277, 0, 0), -- Elsharin
(5499, 2716, 3695, 0), -- Lilyssia Nightbreeze
(5500, 2200, 3695, 0), -- Tel'Athir
(5503, 6233, 0, 0), -- Eldraeith
(5509, 5286, 0, 0), -- Kathrum Axehand
(5510, 0, 0, 12523), -- Thulman Flintcrag
(5511, 1903, 0, 0), -- Therum Deepforge
(5512, 5532, 0, 0), -- Kaita Deepforge
(5513, 1910, 0, 0), -- Gelman Stonehand
(5514, 1910, 0, 0), -- Brooke Stonebraid
(5515, 3433, 0, 0), -- Einris Brightspear
(5516, 0, 0, 2552), -- Ulfir Ironbeard
(5517, 1909, 0, 0), -- Thorfin Stoneshield
(5518, 4994, 0, 0), -- Lilliam Sparkspindle
(5519, 1911, 0, 0), -- Billibub Cogspinner
(5520, 2559, 0, 0), -- Spackle Thornberry
(5566, 6234, 0, 0), -- Tannysa
(5595, 5286, 6254, 2552), -- Ironforge Guard
(5597, 2704, 0, 0), -- Grunt Komak
(5603, 5287, 0, 0), -- Grunt Mojka
(5606, 2703, 0, 0), -- Goma
(5609, 2703, 0, 0), -- Zazo
(5610, 2703, 0, 0), -- Kozish
(5611, 0, 0, 2551), -- Barkeep Morag
(5612, 12991, 0, 0), -- Gimrizz Shadowcog
(5613, 2703, 0, 0), -- Doyo'da
(5614, 2716, 0, 0), -- Sarok
(5629, 5278, 0, 0), -- Theramore Commando
(5639, 5277, 0, 0), -- Craven Drok
(5640, 2711, 0, 0), -- Keldran
(5667, 2711, 0, 0), -- Venya Marthand
(5694, 2177, 0, 0), -- High Sorcerer Andromath
(5749, 2184, 0, 0), -- Kayla Smithe
(5767, 1908, 0, 0), -- Nalpak
(5768, 1908, 0, 0), -- Ebru
(5782, 3494, 11506, 0), -- Crildor
(5810, 12290, 12452, 0), -- Uzzek
(5811, 2184, 0, 0), -- Kamari
(5812, 1903, 0, 0), -- Tumi
(5815, 5304, 0, 0), -- Kurgul
(5816, 0, 0, 6231), -- Katis
(5817, 1910, 0, 0), -- Shimra
(5824, 5289, 0, 0), -- Captain Flat Tusk
(583, 2184, 0, 0), -- Defias Ambusher
(5860, 5277, 0, 0), -- Twilight Dark Shaman
(5861, 3361, 1984, 0), -- Twilight Fire Guard
(5862, 5303, 0, 0), -- Twilight Geomancer
(5871, 2705, 0, 0), -- Larhka
(5875, 12864, 0, 0), -- Gan'rul Bloodeye
(5880, 5276, 0, 0), -- Un'Thuwa
(5907, 1908, 0, 0), -- Kranal Fiss
(5910, 12329, 0, 0), -- Zankaja
(5941, 1117, 0, 0), -- Lau'Tiki
(5942, 6227, 6225, 0), -- Zansoa
(5953, 5289, 0, 2507), -- Razor Hill Grunt
(6027, 1908, 0, 0), -- Kitha
(6031, 1903, 0, 0), -- Tormus Deepforge
(6086, 5598, 0, 5258), -- Auberdine Sentinel
(6089, 5502, 0, 0), -- Harry Burlguard
(6090, 2704, 3757, 0), -- Bartleby
(6091, 2717, 0, 0), -- Dellylah
(6119, 12862, 0, 0), -- Tog Rustsprocket
(6142, 2182, 0, 0), -- Mathiel
(6169, 1903, 0, 0), -- Klockmort Spannerspan
(6171, 2557, 0, 0), -- Duthorian Rall
(6181, 1903, 0, 0), -- Jordan Stilwell
(62, 1904, 0, 0), -- Gug Fatcandle
(6241, 5292, 0, 0), -- Bailor Stonehand
(6267, 4993, 0, 0), -- Acolyte Porena
(6286, 2197, 0, 0), -- Zarrin
(6287, 5278, 0, 0), -- Radnaal Maneweaver
(6291, 5278, 0, 0), -- Balthus Stoneflayer
(6292, 5278, 0, 0), -- Eladriel
(6306, 5278, 0, 0), -- Helene Peltskinner
(6328, 1907, 0, 0), -- Dannie Fizzwizzle
(6367, 2827, 0, 0), -- Donni Anthania
(6373, 11343, 0, 0), -- Dane Winslow
(6374, 12937, 0, 0), -- Cylina Darkheart
(6408, 1901, 0, 0), -- Ula'elek
(6466, 63252, 0, 0), -- Gamon
(656, 1910, 0, 0), -- Wilder Thistlenettle
(6579, 1910, 0, 0), -- Shoni the Shilent
(6670, 1902, 0, 0), -- Westfall Woodworker
(6735, 2715, 0, 0), -- Innkeeper Saelienne
(6736, 2715, 0, 0), -- Innkeeper Keldamyr
(6791, 3362, 0, 0), -- Innkeeper Wiley
(68, 1899, 143, 2551), -- Stormwind City Guard
(6806, 2703, 0, 0), -- Tannok Frosthammer
(6928, 2196, 0, 0), -- Innkeeper Grosk
(6929, 6334, 0, 0), -- Innkeeper Gryshka
(6946, 5285, 0, 0), -- Renzik "The Shiv"
(6986, 1911, 0, 0), -- Dran Droffers
(6987, 1903, 0, 0), -- Malton Droffers
(7010, 5303, 0, 0), -- Zilzibin Drumlore
(7028, 2559, 0, 0), -- Blackrock Warlock
(7088, 5278, 0, 0), -- Thuwd
(7161, 2716, 0, 0), -- Wrenix the Wretched
(7230, 2182, 0, 0), -- Shayis Steelfury
(7231, 1903, 0, 0), -- Kelgruk Bloodaxe
(7232, 2182, 0, 0), -- Borgus Steelhand
(7235, 5303, 0, 0), -- Gnarlpine Mystic
(727, 2557, 0, 2552), -- Ironforge Mountaineer
(7296, 6680, 0, 0), -- Corand
(7311, 12328, 0, 0), -- Uthel'nay
(7315, 2179, 0, 0), -- Darnath Bladesinger
(7317, 5289, 0, 0), -- Oben Rageclaw
(7318, 1908, 0, 0), -- Rageclaw
(732, 2184, 0, 0), -- Murloc Lurker
(735, 2695, 0, 0), -- Murloc Streamrunner
(7740, 2709, 0, 0), -- Gracina Spiritmight
(7790, 1903, 0, 0), -- Orokk Omosh
(7792, 2182, 0, 0), -- Aturk the Anvil
(7793, 5491, 0, 0), -- Ox
(7798, 2182, 0, 0), -- Hank the Hammer
(78, 1903, 0, 0), -- Janos Hammerknuckle
(79, 1903, 0, 0), -- Narg the Taskmaster
(7907, 12862, 0, 0), -- Daryn Lightwind
(794, 1117, 0, 0), -- Matt
(7951, 20468, 0, 0), -- Zas'Tysh
(7952, 6680, 0, 0), -- Zjolnir
(7954, 4994, 0, 0), -- Binjy Featherwhistle
(7955, 4994, 0, 0), -- Milli Featherwhistle
(7999, 5598, 0, 14105), -- Tyrande Whisperwind
(8026, 5598, 0, 0), -- Thyn'tel Bladeweaver
(8119, 12744, 12857, 0), -- Zikkel
(820, 1897, 2916, 0), -- Scout Riell
(821, 1909, 2916, 0), -- Captain Danuvin
(8306, 2827, 0, 0), -- Duhng
(8307, 2197, 0, 0), -- Tarban Hearthgrain
(8383, 5287, 0, 0), -- Master Wood
(8396, 5598, 0, 0), -- Sentinel Dalia Sunblade
(8404, 1906, 0, 0), -- Xan'tish
(842, 1909, 0, 0), -- Lumberjack
(843, 1906, 0, 0), -- Gina MacGregor
(844, 1906, 0, 0), -- Antonio Perelli
(8496, 1911, 0, 0), -- Liv Rizzlefix
(8566, 1896, 0, 2552), -- Dark Iron Lookout
(8659, 2711, 10619, 0), -- Jes'rimon
(8665, 5600, 0, 0), -- Shylenai
(869, 1897, 2053, 2551), -- Protector Dorana
(870, 1897, 143, 2551), -- Protector Deni
(8738, 1911, 0, 0), -- Vazario Linkgrease
(874, 1896, 143, 2551), -- Protector Korelor
(876, 1896, 143, 2551), -- Protector Leick
(880, 5289, 0, 0), -- Erlan Drudgemoor
(881, 1907, 0, 0), -- Surena Caledon
(8879, 12742, 0, 0), -- Royal Historian Archesonus
(9047, 3346, 0, 0), -- Jenal
(906, 1908, 0, 0), -- Maximillian Crowe
(911, 1896, 1961, 0), -- Llane Beshere
(913, 1899, 1985, 0), -- Lyria Du Lac
(914, 12890, 0, 0), -- Ander Germaine
(915, 2184, 0, 0), -- Jorik Kerridan
(917, 1900, 0, 0), -- Keryn Sylvius
(918, 2711, 1900, 0), -- Osborne the Night Man
(925, 1903, 0, 0), -- Brother Sammuel
(927, 2182, 1984, 0), -- Brother Wilhelm
(928, 2557, 0, 0), -- Lord Grayson Shadowbreaker
(9317, 1911, 0, 0), -- Rilli Greasygob
(94, 2184, 0, 0), -- Defias Cutpurse
(951, 1907, 0, 0), -- Brother Paxton
(955, 2705, 0, 0), -- Sergeant De Vries
(9558, 2714, 0, 0), -- Grimble
(9564, 4994, 0, 0), -- Frezza
(957, 1903, 0, 0), -- Dane Lindgren
(958, 2177, 0, 0), -- Dawn Brightstar
(963, 1899, 143, 0), -- Deputy Rainer
(97, 1895, 0, 0), -- Riverpaw Runt
(99, 5285, 0, 0), -- Morgaine the Sly
(9980, 2714, 0, 0), -- Shelby Stoneflint
(9981, 11424, 0, 0), -- Sikwa
(9987, 12629, 0, 0), -- Shoja'my
(9988, 1908, 0, 0); -- Xon'cha
