-- Insert npc_text from sniff
DELETE FROM `npc_text` WHERE `ID`=11428;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(11428,'Are you here to relieve me? I''m certain it''s almost time. Well, if you want to relieve me anyway, let me know. I could use a drink or three.','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,12340);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23567;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=23602;

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=7981 WHERE `entry`=19217; -- Ravandwyr <Kirin Tor Apprentice>
UPDATE `creature_template` SET `gossip_menu_id`=7996 WHERE `entry`=19488; -- Custodian Dieworth <Keeper of Kirin'Var>
UPDATE `creature_template` SET `gossip_menu_id`=7995 WHERE `entry`=19489; -- Lieutenant-Sorcerer Morran
UPDATE `creature_template` SET `gossip_menu_id`=7991 WHERE `entry`=19569; -- Netherologist Coppernickels <B.O.O.M.>
UPDATE `creature_template` SET `gossip_menu_id`=7994 WHERE `entry`=19578; -- Bot-Specialist Alley <B.O.O.M.>
UPDATE `creature_template` SET `gossip_menu_id`=8001 WHERE `entry`=19617; -- Boots <B.O.O.M. Master Mixologist>
UPDATE `creature_template` SET `gossip_menu_id`=8003 WHERE `entry`=19634; -- Lead Sapper Blastfizzle <B.O.O.M. Sap Foreman>
UPDATE `creature_template` SET `gossip_menu_id`=8024 WHERE `entry`=19644; -- Image of Archmage Vargoth
UPDATE `creature_template` SET `gossip_menu_id`=8008 WHERE `entry`=19645; -- Papa Wheeler <B.O.O.M. Mech Tech>
UPDATE `creature_template` SET `gossip_menu_id`=8030 WHERE `entry`=19709; -- Chief Engineer Trep <B.O.O.M. Engineering>
UPDATE `creature_template` SET `gossip_menu_id`=8032 WHERE `entry`=19728; -- Mama Wheeler <B.O.O.M. Mech Tech>
UPDATE `creature_template` SET `gossip_menu_id`=8048 WHERE `entry`=19880; -- Nether-Stalker Khay'ji
UPDATE `creature_template` SET `gossip_menu_id`=8054 WHERE `entry`=20066; -- Gahruj
UPDATE `creature_template` SET `gossip_menu_id`=8055 WHERE `entry`=20067; -- Zuben Elgenubi
UPDATE `creature_template` SET `gossip_menu_id`=8056 WHERE `entry`=20068; -- Zuben Eschamali
UPDATE `creature_template` SET `gossip_menu_id`=8071 WHERE `entry`=20071; -- Wind Trader Marid
UPDATE `creature_template` SET `gossip_menu_id`=8063 WHERE `entry`=20092; -- Dealer Hazzin <General Provisioner>
UPDATE `creature_template` SET `gossip_menu_id`=8068 WHERE `entry`=20110; -- Tyri
UPDATE `creature_template` SET `gossip_menu_id`=8070 WHERE `entry`=20112; -- Wind Trader Tuluman <Weapon Merchant>
UPDATE `creature_template` SET `gossip_menu_id`=8084 WHERE `entry`=20194; -- Dealer Dunar <General Provisioner>
UPDATE `creature_template` SET `gossip_menu_id`=8101 WHERE `entry`=20281; -- Drijya
UPDATE `creature_template` SET `gossip_menu_id`=8106 WHERE `entry`=20389; -- Lee Sparks <The Taskmaster>
UPDATE `creature_template` SET `gossip_menu_id`=8107 WHERE `entry`=20393; -- Foreman Sundown
UPDATE `creature_template` SET `gossip_menu_id`=8120 WHERE `entry`=20448; -- Commander Ameer <The Protectorate>
UPDATE `creature_template` SET `gossip_menu_id`=8180 WHERE `entry`=20449; -- Researcher Navuud <The Protectorate>
UPDATE `creature_template` SET `gossip_menu_id`=8183 WHERE `entry`=20450; -- Flesh Handler Viridius
UPDATE `creature_template` SET `gossip_menu_id`=8126 WHERE `entry`=20463; -- Apprentice Andrethan
UPDATE `creature_template` SET `gossip_menu_id`=8128 WHERE `entry`=20551; -- Agent Araxes <The Protectorate>
UPDATE `creature_template` SET `gossip_menu_id`=8231 WHERE `entry`=20810; -- Mehrdad
UPDATE `creature_template` SET `gossip_menu_id`=8229 WHERE `entry`=20903; -- Protectorate Nether Drake
UPDATE `creature_template` SET `gossip_menu_id`=8207 WHERE `entry`=20907; -- Professor Dabiri
UPDATE `creature_template` SET `gossip_menu_id`=8228 WHERE `entry`=20985; -- Captain Saeed
UPDATE `creature_template` SET `gossip_menu_id`=8308 WHERE `entry`=21493; -- Kablamm Farflinger <Transportation Engineer>
UPDATE `creature_template` SET `gossip_menu_id`=8542 WHERE `entry`=22427; -- Zarevhi
UPDATE `creature_template` SET `gossip_menu_id`=8710 WHERE `entry`=23396; -- Krixel Pinchwhistle <Classic Alliance Mail & Plate>
UPDATE `creature_template` SET `gossip_menu_id`=9781 WHERE `entry`=29145; -- Pulik Swiftsnip <Barber>

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7981 AND `text_id` IN (9826,9828);
DELETE FROM `gossip_menu` WHERE `entry`=7991 AND `text_id`=9841;
DELETE FROM `gossip_menu` WHERE `entry`=7994 AND `text_id`=9846;
DELETE FROM `gossip_menu` WHERE `entry`=7995 AND `text_id`=9847;
DELETE FROM `gossip_menu` WHERE `entry`=7996 AND `text_id`=9848;
DELETE FROM `gossip_menu` WHERE `entry`=8001 AND `text_id`=9863;
DELETE FROM `gossip_menu` WHERE `entry`=8003 AND `text_id`=9869;
DELETE FROM `gossip_menu` WHERE `entry`=8008 AND `text_id`=9875;
DELETE FROM `gossip_menu` WHERE `entry`=8024 AND `text_id`=9901;
DELETE FROM `gossip_menu` WHERE `entry`=8030 AND `text_id`=9916;
DELETE FROM `gossip_menu` WHERE `entry`=8032 AND `text_id`=9919;
DELETE FROM `gossip_menu` WHERE `entry`=8048 AND `text_id`=9937;
DELETE FROM `gossip_menu` WHERE `entry`=8054 AND `text_id`=9947;
DELETE FROM `gossip_menu` WHERE `entry`=8055 AND `text_id`=9948;
DELETE FROM `gossip_menu` WHERE `entry`=8056 AND `text_id`=9949;
DELETE FROM `gossip_menu` WHERE `entry`=8063 AND `text_id`=9959;
DELETE FROM `gossip_menu` WHERE `entry`=8068 AND `text_id`=9968;
DELETE FROM `gossip_menu` WHERE `entry`=8070 AND `text_id`=9970;
DELETE FROM `gossip_menu` WHERE `entry`=8071 AND `text_id`=9971;
DELETE FROM `gossip_menu` WHERE `entry`=8084 AND `text_id`=9994;
DELETE FROM `gossip_menu` WHERE `entry`=8101 AND `text_id`=10019;
DELETE FROM `gossip_menu` WHERE `entry`=8106 AND `text_id`=10031;
DELETE FROM `gossip_menu` WHERE `entry`=8107 AND `text_id`=10032;
DELETE FROM `gossip_menu` WHERE `entry`=8120 AND `text_id`=10058;
DELETE FROM `gossip_menu` WHERE `entry`=8121 AND `text_id`=10061;
DELETE FROM `gossip_menu` WHERE `entry`=8122 AND `text_id`=10060;
DELETE FROM `gossip_menu` WHERE `entry`=8123 AND `text_id`=10059;
DELETE FROM `gossip_menu` WHERE `entry`=8126 AND `text_id`=10064;
DELETE FROM `gossip_menu` WHERE `entry`=8128 AND `text_id`=10065;
DELETE FROM `gossip_menu` WHERE `entry`=8180 AND `text_id`=10152;
DELETE FROM `gossip_menu` WHERE `entry`=8183 AND `text_id`=10179;
DELETE FROM `gossip_menu` WHERE `entry`=8207 AND `text_id`=10202;
DELETE FROM `gossip_menu` WHERE `entry`=8228 AND `text_id`=10229;
DELETE FROM `gossip_menu` WHERE `entry`=8229 AND `text_id`=10230;
DELETE FROM `gossip_menu` WHERE `entry`=8231 AND `text_id`=10233;
DELETE FROM `gossip_menu` WHERE `entry`=8308 AND `text_id`=10365;
DELETE FROM `gossip_menu` WHERE `entry`=8542 AND `text_id`=10687;
DELETE FROM `gossip_menu` WHERE `entry`=8710 AND `text_id`=10957;
DELETE FROM `gossip_menu` WHERE `entry`=9781 AND `text_id`=13459;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7981,9828),(7981, 9826),(7991,9841),(7994,9846),(7995,9847),
(7996,9848),(8001,9863),(8003,9869),(8008,9875),(8024,9901),
(8030,9916),(8032,9919),(8048,9937),(8054,9947),(8055,9948),
(8056,9949),(8063,9959),(8068,9968),(8070,9970),(8071,9971),
(8084,9994),(8101,10019),(8106,10031),(8107,10032),(8120,10058),
(8121,10061),(8122,10060),(8123,10059),(8126,10064),(8128,10065),
(8180,10152),(8183,10179),(8207,10202),(8228,10229),(8229,10230),
(8231,10233),(8308,10365),(8542,10687),(8710,10957),(9781,13459);

-- Insert npc_text from sniff
DELETE FROM `npc_text` WHERE `ID` IN (10059,10061);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(10059,'The Ethereum were the ruling class of ethereal on my homeworld of K''aresh. Tragically, we were forced to evacuate K''aresh shortly before the void lord, Dimensius, unleashed his void armies upon the world and utterly decimated all that stood in his way. For this act, the Ethereum vowed vengeance. They have been tracking Dimensius ever since...$B$BThe Protectorate, however, were not a reaction to Dimensius. We were a reaction to Ethereum.','',0,1,0,1,0,1,0,1,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10061,'We feel that the Ethereum are as great a threat to our existence as Dimensius. Both must be stopped...','',0,1,0,1,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340);

-- Creature Gossip_menu_option insert from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8001,8063,8070,8084,8103,8120,8121,8122,8123,8126,8710) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8001, 0, 1, 'Boots, what do you have back there that goes down smooth?', 3, 128, 0, 0, 0, 0, ''),
(8063, 0, 1, 'Dealer Hazzin, what do you have to offer?', 3, 128, 0, 0, 0, 0, ''),
(8070, 0, 1, 'What do you have to sell, Tuluman?', 3, 128, 0, 0, 0, 0, ''),
(8084, 0, 1, 'Dealer Dunar, I wish to browse your wares.', 3, 128, 0, 0, 0, 0, ''),
(8103, 0, 5, 'Make this inn your home.', 8, 65536, 0, 0, 0, 0, ''),
(8120, 0, 0, 'What are Ethereum?', 1, 1, 8123, 0, 0, 0, ''),
(8121, 0, 0, 'I think I understand now. Can I help with any of this? The Ethereum and void creatures are a threat to our survival as well.', 1, 1, 8120, 0, 0, 0, ''),
(8122, 0, 0, 'So what is your purpose?', 1, 1, 8121, 0, 0, 0, ''),
(8123, 0, 0, 'I don''t understand. What do you mean, Ameer?', 1, 1, 8122, 0, 0, 0, ''),
(8126, 0, 1, 'I wish to browse your wares.', 3, 128, 0, 0, 0, 0, ''),
(8710, 0, 1, 'Let me browse your goods.', 3, 128, 0, 0, 0, 0, '');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7981 AND `SourceEntry`=9828;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7981,9828,0,0,9,0,10173,0,0,0,0,'','Ravandwyr - Show different gossip if player has taken quest 10173');

-- Remove some old script text
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000649 AND -1000641;

-- Add missing loot
DELETE FROM `creature_loot_template` WHERE `entry`=30524 AND `item`=35490;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(30524,35490,-100,1,0,1,1);

-- Add a missing gossip
UPDATE `creature_template` SET `gossip_menu_id`=1100 WHERE `entry`=4963;
