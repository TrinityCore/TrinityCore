-- Gnomish Playback Device (item 52709) Targeting condition -- by norfik closes #2169
DELETE FROM `conditions` WHERE `SourceEntry`=74222 AND `ConditionValue2` IN (1268, 7955, 6119);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 74222, 1, 31, 3, 1268, 0, 63, '', 'Gnomish Playback Device on Ozzie Togglevolt'),
(17, 0, 74222, 2, 31, 3, 7955, 0, 63, '', 'Gnomish Playback Device on Milli Featherwhistle'),
(17, 0, 74222, 3, 31, 3, 6119, 0, 63, '', 'Gnomish Playback Device on Tog Rustsprocket');

-- fix revenge ap coeff -- by ric101 closes #3344
UPDATE `spell_bonus_data` SET `ap_bonus` = 0.310 WHERE `entry` = 6572;

-- fix life seed sp coeff -- by warpten closes #4162
DELETE FROM `spell_bonus_data` WHERE `entry`=48503;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(48503,0,0,0,0, 'Druid - Living Seed Heal');

-- fix glyph of shadowflame proc only allow on damage. by kandera closes #3530
UPDATE `spell_proc_event` SET `procEx` = procEx|262144 WHERE`entry` = 63310; -- Glyph of shadowflame fix

-- Disable deprecated quests /in 2.4/ from Midsummer Festival - The Festival of Fire {A/H} by trista closes #5982
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` in (9367,9368);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,9367,0,0,0,'Disable quest The Festival of Fire {A}/Deprecated after 2.4 Midsummer Festival revamp/'),
(1,9368,0,0,0,'Disable quest The Festival of Fire {H}/Deprecated after 2.4 Midsummer Festival revamp/');

-- fix gameobject spawn for just maces sign -- by mrsmite closes #5849
DELETE FROM `gameobject` WHERE `guid` = 10714;
UPDATE `gameobject` SET `guid` = 10714 WHERE `guid` = 61895 AND `id` = 2157;

-- update npc texts. by helias closes #6098
DELETE FROM `npc_text` WHERE `ID` IN (10719,10782,10783,10787,10788,2838,9072,9110,10310,13293,13641,14089,15077,15155,15240,15412,15866,15873,15877,8663,8244,8254,8255,8282,8291,8296,8298,11093,3464,4776,4713,12130,13002,9984,12977,12978,10918,10999,10986,10991);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`) VALUES
(10719, '<The chime of A"dal"s voice echoes reassuringly through your mind.>$B$BWorry not, child.  Look in your pack and you will find it once more.', NULL, 0, 1, 0, 0, 0, 0, 0, 0),
(10782, 'Sayoc, da ugly orc here, teach you daggers. You want teaching in other places, you talk to Ileda in da Farstrider Square of Silvermoon or Archibald in the War Quarter of Undercity, hokay?', 'Sayoc, da ugly orc here, teach you daggers. You want teaching in other places, you talk to Ileda in da Farstrider Square of Silvermoon or Archibald in the War Quarter of Undercity, hokay?', 1, 1, 0, 0, 0, 0, 0, 0),
(10783, 'You want to punch things, yah? Talk to Sayoc right here. He teach you.', 'You want to punch things, yah? Talk to Sayoc right here. He teach you.', 1, 1, 0, 0, 0, 0, 0, 0),
(10787, 'Ileda of da blood elves, in Farstrider Square of Silvermoon, train her students in both one and two-handed swords. Archibald, da Undercity"s weapon master, also train you, mon. He in da War Quarter.', 'Ileda of da blood elves, in Farstrider Square of Silvermoon, train her students in both one and two-handed swords. Archibald, da Undercity"s weapon master, also train you, mon. He in da War Quarter.', 1, 1, 0, 0, 0, 0, 0, 0),
(10788, 'Hanashi here knows staves. If you want a sturdier instructor, go to Thunder Bluff. Ansekhwa will teach you on the lower central rise there.', '', 1, 1, 0, 0, 0, 0, 0, 0),
(2838, '', 'Sure thing, $N. Here"s another for you.', 0, 1, 0, 0, 0, 0, 0, 0),
(9072, 'A search of the corpse"s clothing and equipment reveals the insignia you need, undamaged by the battle and foul environment.', '', 0, 1, 0, 0, 0, 0, 0, 0),
(9110, 'Say, you happen to see that arch in the lake to the west?  I wonder where that goes?  I should go divin" over there.', '', 0, 1, 0, 1, 0, 0, 0, 0),
(10310, 'You must be exalted with the blood elves before I will teach you a riding skill, $c.', '', 1, 1, 0, 1, 0, 0, 0, 0),
(13293, 'Please hurry, $N. I am in a great deal of pain and time is running out.', '', 0, 1, 0, 0, 0, 0, 0, 0),
(13641, '<Brann looks at you expectantly.>', '', 0, 1, 0, 0, 0, 0, 0, 0),
(14089, 'I"ve got a lead on Norgannon"s keystone, which guards access to Ulduar"s archives, but the Titans divided it into two pieces and secreted them away.$B$BOne of the pieces, the keystone"s shell, is held within the Inventor"s Library on the northern coast, south of Ulduar itself. The first thing you"ll need to do is retrieve the fragments of an access disk from the library"s guardians.', '', 0, 1, 0, 0, 0, 0, 0, 0),
(15077, 'There you are! I was beginning to think that the Sunreavers had intercepted you. Are you ready to deliver the tome to our representatives in Icecrown?', '', 0, 1, 0, 0, 0, 0, 0, 0),
(15155, 'These appear to be the remains of Thalorien Dawnseeker, the last wielder of Quel"Delar.', '', 0, 1, 0, 0, 0, 0, 0, 0),
(15240, 'I will escort you into the Sunwell when you"re ready.', 'I will escort you into the Sunwell when you"re ready.', 0, 1, 0, 0, 0, 0, 0, 0),
(15412, 'We got the final barrier blockin" entry to Frostwing Halls down, $g lad:lass;. Only Sindragosa stands between the Lich King and divine retribution! What are ye waitin" for?!', '', 0, 1, 0, 5, 0, 0, 0, 0),
(15866, 'De Darkspears have a home again! An" we couldn"t have done it wit"out ya helpin", $N. Now, we celebrate!', '', 0, 1, 0, 1, 0, 1, 0, 0),
(15873, 'Vol"jin told me ta keep hittin" da drum till he gets back.  If ya be waitin" for him, he"d be back soon to take back da Isles.$B$BJust wait here and enjoy da music!', '', 0, 1, 0, 0, 0, 0, 0, 0),
(15877, 'We require da help of allies on da islands.$B$BZen"tabra has been watching over da animals of de Islands for some time now.  We"d need her help and da help of da animal creatures.$B$BBwonsamdi is a powerful loa dat controls de spirits of de dead on da islands.  His blessing is crucial for our attack.$B$BOnce our allies have joined us, Zalazane and his army of mind-controlled trolls will have no chance!  Then, da Echo Isles will be de Darkspears!', '', 0, 1, 0, 0, 0, 0, 0, 0),
(8663, 'Thank you for delivering that list!  My leg is almost recovered enough that I"ll be able to walk back to the crash site.', '', 0, 1, 0, 0, 0, 0, 0, 0),
(8244, 'We"ve been so wrapped up in this war, some of us forgot to make time for love.', '', 0, 1, 0, 0, 0, 0, 0, 0),
(8254, 'You work with machines for so long, sometimes you forget about real hearts.', '', 0, 1, 0, 0, 0, 0, 0, 0),
(8255, '', 'When you have lived as long as I, it becomes easy to forget about love for years. It is always good to be reminded.', 0, 1, 0, 0, 0, 0, 0, 0),
(8282, '', 'You look like you"ve had your heart broken. Come back when you"re not so sad.', 0, 1, 0, 25, 0, 153, 0, 0),
(8291, 'What, you don"t have a token to give me? Don"t you love me?', '', 0, 1, 0, 18, 0, 0, 0, 0),
(8296, 'It looks like you"ve already found love. You can give me a love token, but I"m not giving you anything nice. I"m waiting for someone special.', 'It looks like you"ve already found love. You can give me a love token, but I"m not giving you anything nice. I"m waiting for someone special.', 0, 1, 0, 1, 0, 0, 0, 0),
(8298, 'I"d like you better if you would apply some perfume.', 'I"d like you better if you would apply some perfume.', 0, 1, 0, 24, 0, 0, 0, 0),
(11093, 'Let"s get out of here!', '', 0, 1, 0, 5, 0, 0, 0, 0),
(3464, '', 'You do fine work, but it"s a bit rough around the edges. Don"t worry about it, it will come with practice. Speaking of which, how about we see what you"ve been working on?', 7, 1, 0, 0, 0, 0, 0, 0),
(4776, 'The battle is over, and the people of Darrowshire are saved.', '', 0, 1, 0, 0, 0, 0, 0, 0),
(4713, 'The Nightmare is finally over!  Darrowshire, forgive me!', '', 0, 1, 0, 15, 0, 0, 0, 0),
(12130, '<Old Icefin eyes you warily, his fishy eye blinking as he bobs his head up and down once in a curt dismissal.>', '', 0, 1, 0, 0, 0, 0, 0, 0),
(13002, 'There ya go, mon. Try ta be more careful with this one, won"t ya?$b$bNow head down ta Drak"Zin Ruins and drink it near the pedestal!', NULL, 0, 1, 0, 0, 0, 0, 0, 0),
(9984, 'What are ye doin" here?! Get yer chatty self ta Alterac Vallery, where ye"re needed!', '', 7, 1, 1, 5, 0, 0, 0, 0),
(12977, 'Blight, Blight, Blight... that"s all I hear about around here. I miss the diversity!$b$bHere, here. You have pets, yes? Of course you do. Of course. Little pets. I have a mixture for them. It will make them ca-- ah, clever and strong creatures, yes. Yes. ', '', 1, 1, 396, 5, 0, 0, 0, 0),
(12978, 'Careful with it. It"s unstable and loses its potency quickly. Use it soon! And... preferably within eyesight, yes...', '', 1, 1, 5, 0, 0, 0, 0, 0),
(10918, 'The boy"s too stupid still to say it -- not enough crystal exposure yet -- but, he"s thankful for what you did in getting him those flasks.$B$BNow, only nine more sons to go.  Gah!$B$B<Both of Torkus"s heads sigh.>$B$BWant to take one of them off of our hands?  We"ll sell him to you cheap.', '', 0, 1, 0, 1, 0, 5, 0, 6),
(10999, 'Friend! It"s been too long.  What can we get for you?', '', 0, 1, 1, 1, 0, 0, 0, 0),
(10986, 'Our drinks should quench even the mightiest of thirsts.', '', 0, 1, 1, 396, 0, 0, 0, 0),
(10991, 'What can I say, $N?  Yer the finest o" the Sha"tari Skyguard!$B$BJust don"t be lettin" that go ta yer head.  I can still teach ya a thing or two, $G lad : lass;!$B$B<Sky Commander Keller grins at you and winks.>', '', 0, 0, 0, 0, 0, 0, 0, 0);

-- Fix Kor'kron War Rider flying by trista closes #5569
UPDATE `creature_template` SET `inhabittype`=5,`speed_walk`=1, `speed_run`=1 WHERE `entry`=26813;

-- Gretta the Arbiter (Storm Peaks, Brunhilldar) by mweinelt closes #5493
-- Daily Quest Pooling
-- Source: http://www.wowwiki.com/Gretta_the_Arbiter
SET @pool_id := 354;

DELETE FROM `pool_template` WHERE `entry` = @pool_id;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool_id, 1, 'Gretta the Arbiter - Daily Quests');

DELETE FROM `pool_quest` WHERE `entry` IN (13424, 13423, 13422, 13425);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(13424, @pool_id, 'Back to the Pit'),
(13423, @pool_id, 'Defending Your Title'),
(13422, @pool_id, 'Maintaining Discipline'),
(13425, @pool_id, 'The Aberrations Must Die');

-- Pathing for Arzeth the Merciless Entry: 19354 by kiperr closes #5510
SET @NPC := 69051;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-617.6182,`position_y`=4800.323,`position_z`=38.53064 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-546.5514,4799.893,33.83914,0,0,0,100,0),
(@PATH,2,-512.5808,4799.929,32.09928,0,0,0,100,0),
(@PATH,3,-480.9247,4799.97,28.25657,0,0,0,100,0),
(@PATH,4,-512.6269,4799.873,32.09928,0,0,0,100,0),
(@PATH,5,-542.1885,4799.724,33.71414,0,0,0,100,0),
(@PATH,6,-570.3811,4800.449,34.60215,0,0,0,100,0),
(@PATH,7,-592.3809,4800.299,35.85215,0,0,0,100,0),
(@PATH,8,-617.6182,4800.323,38.53064,0,0,0,100,0),
(@PATH,9,-659.4124,4799.819,49.09505,0,0,0,100,0),
(@PATH,10,-582.4199,4800.242,34.97715,0,0,0,100,0),
(@PATH,11,-546.5514,4799.893,33.83914,0,0,0,100,0),
(@PATH,12,-542.1885,4799.724,33.71414,0,0,0,100,0),
(@PATH,13,-570.3811,4800.449,34.60215,0,0,0,100,0),
(@PATH,14,-592.3809,4800.299,35.85215,0,0,0,100,0),
(@PATH,15,-617.6182,4800.323,38.53064,0,0,0,100,0),
(@PATH,16,-659.4124,4799.819,49.09505,0,0,0,100,0),
(@PATH,17,-512.5808,4799.929,32.09928,0,0,0,100,0),
(@PATH,18,-480.9247,4799.97,28.25657,0,0,0,100,0),
(@PATH,19,-512.6269,4799.873,32.09928,0,0,0,100,0),
(@PATH,20,-542.1885,4799.724,33.71414,0,0,0,100,0),
(@PATH,21,-570.3811,4800.449,34.60215,0,0,0,100,0),
(@PATH,22,-592.3809,4800.299,35.85215,0,0,0,100,0),
(@PATH,23,-617.6182,4800.323,38.53064,0,0,0,100,0),
(@PATH,24,-659.4124,4799.819,49.09505,0,0,0,100,0),
(@PATH,25,-582.4199,4800.242,34.97715,0,0,0,100,0),
(@PATH,26,-512.6269,4799.873,32.09928,0,0,0,100,0),
(@PATH,27,-542.1885,4799.724,33.71414,0,0,0,100,0),
(@PATH,28,-570.3811,4800.449,34.60215,0,0,0,100,0),
(@PATH,29,-592.3809,4800.299,35.85215,0,0,0,100,0),
(@PATH,30,-617.6182,4800.323,38.53064,0,0,0,100,0);

-- Dark Portal - corrects the entry position and orientation by cdawg closes #5470
UPDATE `areatrigger_teleport` SET `target_position_x`=-248.149292, `target_position_y`=921.874953, `target_position_z`=84.388448, `target_orientation`=1.584155 WHERE `id`=4354;

-- Add pamphlets to mail loot by gecko32 closes #5408
DELETE FROM `mail_loot_template` WHERE `entry` BETWEEN 224 AND 233;
INSERT INTO `mail_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(224, 46875, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Elwynn Forest
(225, 46876, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Darnassus
(226, 46877, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Dun Morogh drawf
(227, 46879, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Azuremyst Isle
(228, 46878, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Dun Morogh gnome
(229, 46884, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Mulgore
(230, 46883, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Durator
(231, 46880, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Orgrimmar
(232, 46882, 100, 1, 0, 1, 1), -- Riding Training Pamphlet Eversong Woods
(233, 46881, 100, 1, 0, 1, 1); -- Riding Training Pamphlet Tirisfal Glades

-- fix coordinates for cannoneer whessan by mosoo closes #5406
UPDATE `creature` SET `position_x`=-2093.53, `position_y`=-3496.47, `position_z`=130.084, `orientation`=3.008 WHERE `id`=3455 LIMIT 1;

-- fix quest requirement for the last of her kind by shlomi 1515 closes #4875
UPDATE `quest_template` SET `PrevQuestID` = 12900 WHERE `id` = 12983;

-- Add rep reward to ICC25 Trash by gecko32 closes #5457
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (37655,38031,38057,38058,38059,38061,38062,38063,38064,38072,38073,38074,38075,38076,38098,38099,38100,38101,38102,38103,38105,38108,38110,38126,38130,38131,38132,38133,38139,38151,38219,38220,38418,38445,38446,38479,38480,38481);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(37655, 1156, 0, 7, 0, 45, 0, 0, 0, 0), -- Decaying colossus
(38031, 1156, 0, 7, 0, 45, 0, 0, 0, 0), -- Deathbound Ward
(38057, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Servant of the throne
(38058, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Nerub'ar Broodkeeper
(38059, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Ancient Skeletal Soldier
(38061, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- The Damned
(38062, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Plague Scientist
(38063, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Vengeful Fleshreaper
(38064, 1156, 0, 7, 0, 150, 0, 0, 0, 0), -- Stinky
(38072, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Deathspeacker Attedent
(38073, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Deathspeacker Disciple
(38074, 1156, 0, 7, 0, 45, 0, 0, 0, 0), -- Deathspeacker High Preist
(38075, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Deathspeacker Servant
(38076, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Deathspeacker Zealot
(38098, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Darkfallen Advisor
(38099, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Darkfallen Archmage
(38100, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Darkfallen Blood Knight
(38101, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Darkfallen Lieutenant
(38102, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Darkfallen Commander
(38103, 1156, 0, 7, 0, 150, 0, 0, 0, 0), -- Precious
(38105, 1156, 0, 7, 0, 2, 0, 0, 0, 0), -- Plagued Zombie
(38108, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Blighted Abomination
(38110, 1156, 0, 7, 0, 30, 0, 0, 0, 0), -- Pustulating Horror
(38126, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Ymirjar Frostbinder
(38130, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Ymirjar Deathbringer
(38131, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Ymirjar Huntress
(38132, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Ymirjar Battle-Maiden
(38133, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Ymirjar Warlord
(38139, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Frostwarden Handler
(38151, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Frostwing Whelp
(38219, 1156, 0, 7, 0, 150, 0, 0, 0, 0), -- Spinestalker
(38220, 1156, 0, 7, 0, 150, 0, 0, 0, 0), -- Rimefang
(38418, 1156, 0, 7, 0, 45, 0, 0, 0, 0), -- Val'kyr Herald
(38445, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Spire Minion
(38446, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Frenzied Abomination
(38479, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Darkfallen Tactician
(38480, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Darkfallen Noble
(38481, 1156, 0, 7, 0, 15, 0, 0, 0, 0); -- Spire Gargoyle

-- fix procs by warpten closes #4467 for
-- Needle-Encrusted Scorpion
DELETE FROM `spell_proc_event` WHERE `entry`=71404;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(71404,0,0,0,0,0,0,2,0,0,50);

-- Black Magic
DELETE FROM `spell_proc_event` WHERE `entry`=59630;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(59630,0,0,0,0,0,0,0,0,0,35);

-- Environment Creature Hight Update by shlomi1515 closes #4043
UPDATE `creature` SET `position_z`=558.210022 WHERE `guid` IN (85141,85143,85154,85153,85142,85151,85152,85150);
UPDATE `creature` SET `position_z`=586.302 WHERE `guid` IN (85145,85144,85146);
UPDATE `creature` SET `position_z`=586.263 WHERE `guid` IN (85147,85148,85149);

-- fix winterskorn raider not landing by nayd closes #3899
UPDATE `creature_template` SET `InhabitType`=`InhabitType`|1 WHERE `entry`=23665;

-- fix head of onyxia's loot closes by kandera #3851
UPDATE `item_template` SET `flags` = flags|4096 WHERE `entry` IN (18422,18423,49644,49643);

-- fix visual for plagued dragonsflayer tribesman by shlomi1515 closes #3518
DELETE FROM `creature_addon` WHERE `guid` = 97540;
