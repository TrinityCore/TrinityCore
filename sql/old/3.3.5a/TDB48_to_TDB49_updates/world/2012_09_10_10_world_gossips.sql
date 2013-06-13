-- gossip assignation from sniff
UPDATE `creature_template` SET `gossip_menu_id`=4534 WHERE `entry`=3047; -- Archmage Shymm <Mage Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=4536 WHERE `entry`=3048; -- Ursyn Ghull <Mage Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=12670 WHERE `entry`=6328; -- Dannie Fizzwizzle <Demon Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=12670 WHERE `entry`=6373; -- Dane Winslow <Demon Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=12670 WHERE `entry`=6374; -- Cylina Darkheart <Demon Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=1622 WHERE `entry`=8965; -- Shawn
UPDATE `creature_template` SET `gossip_menu_id`=4119 WHERE `entry`=11047; -- Kray <Apprentice Alchemist>
UPDATE `creature_template` SET `gossip_menu_id`=4266 WHERE `entry`=11051; -- Vhan <Apprentice Tailor>
UPDATE `creature_template` SET `gossip_menu_id`=4154 WHERE `entry`=11065; -- Thonys Pillarstone <Apprentice Enchanter>
UPDATE `creature_template` SET `gossip_menu_id`=4158 WHERE `entry`=11071; -- Mot Dawnstrider <Apprentice Enchanter>
UPDATE `creature_template` SET `gossip_menu_id`=4204 WHERE `entry`=11081; -- Faldron <Apprentice Leatherworker>
UPDATE `creature_template` SET `gossip_menu_id`=4181 WHERE `entry`=11083; -- Darianna <Apprentice Leatherworker>
UPDATE `creature_template` SET `gossip_menu_id`=4207 WHERE `entry`=11084; -- Tarn <Apprentice Leatherworker>
UPDATE `creature_template` SET `gossip_menu_id`=5142 WHERE `entry`=13442; -- Arch Druid Renferal
UPDATE `creature_template` SET `gossip_menu_id`=5141 WHERE `entry`=13443; -- Druid of the Grove
UPDATE `creature_template` SET `gossip_menu_id`=5081 WHERE `entry`=13447; -- Corporal Noreg Stormpike
UPDATE `creature_template` SET `gossip_menu_id`=5281 WHERE `entry`=13577; -- Stormpike Ram Rider Commander
UPDATE `creature_template` SET `gossip_menu_id`=7993 WHERE `entry`=15991; -- Lady Dena Kennedy
UPDATE `creature_template` SET `gossip_menu_id`=7471 WHERE `entry`=17421; -- Clopper Wizbang <Explorers' League>
UPDATE `creature_template` SET `gossip_menu_id`=7455 WHERE `entry`=17424; -- Anchorite Paetheus <First Aid Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=7459 WHERE `entry`=17434; -- Morae <Herbalism Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=7461 WHERE `entry`=17599; -- Aonar
UPDATE `creature_template` SET `gossip_menu_id`=7462 WHERE `entry`=17649; -- Kessel <Elekk Lord>
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=17666; -- Astur <Stable Master>
UPDATE `creature_template` SET `gossip_menu_id`=7463 WHERE `entry`=17676; -- Achelus
UPDATE `creature_template` SET `gossip_menu_id`=7464 WHERE `entry`=17703; -- Messenger Hermesius
UPDATE `creature_template` SET `gossip_menu_id`=8298 WHERE `entry`=17712; -- Captain Edward Hanes
UPDATE `creature_template` SET `gossip_menu_id`=7835 WHERE `entry`=17927; -- Scout Jorli
UPDATE `creature_template` SET `gossip_menu_id`=7738 WHERE `entry`=18252; -- Andarl
UPDATE `creature_template` SET `gossip_menu_id`=7753 WHERE `entry`=18387; -- Bertelm
UPDATE `creature_template` SET `gossip_menu_id`=7743 WHERE `entry`=18389; -- Thander
UPDATE `creature_template` SET `gossip_menu_id`=7752 WHERE `entry`=18390; -- Ros'eleth
UPDATE `creature_template` SET `gossip_menu_id`=7695 WHERE `entry`=18416; -- Huntress Kima
UPDATE `creature_template` SET `gossip_menu_id`=7698 WHERE `entry`=18459; -- Jenai Starwhisper
UPDATE `creature_template` SET `gossip_menu_id`=7745 WHERE `entry`=18704; -- Taela Everstride
UPDATE `creature_template` SET `gossip_menu_id`=7773 WHERE `entry`=18713; -- Lieutenant Gravelhammer
UPDATE `creature_template` SET `gossip_menu_id`=7814 WHERE `entry`=18745; -- Captain Auric Sunchaser
UPDATE `creature_template` SET `gossip_menu_id`=7833 WHERE `entry`=18804; -- Prospector Nachlan <Explorers' League>
UPDATE `creature_template` SET `gossip_menu_id`=7940 WHERE `entry`=19137; -- "Shotgun" Jones <Nesingwary Safari>
UPDATE `creature_template` SET `gossip_menu_id`=8433 WHERE `entry`=19340; -- Mi'irku Farstep <Portal Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=7973 WHERE `entry`=19375; -- Eli Thunderstrike <Sky'ree's Keeper>
UPDATE `creature_template` SET `gossip_menu_id`=8251 WHERE `entry`=21151; -- Borgrim Stouthammer <Explorers' League>
UPDATE `creature_template` SET `gossip_menu_id`=8247 WHERE `entry`=21158; -- Commander Skyshadow
UPDATE `creature_template` SET `gossip_menu_id`=8252 WHERE `entry`=21197; -- Bronwyn Stouthammer <Explorers' League>
UPDATE `creature_template` SET `gossip_menu_id`=8566 WHERE `entry`=22832; -- Morthis Whisperwing <Druid of the Talon>

-- gossip from sniff
DELETE FROM `gossip_menu` WHERE (`entry`=1621 AND `text_id`=2273) OR (`entry`=1622 AND `text_id`=2276) OR (`entry`=4119 AND `text_id`=5040) OR (`entry`=4154 AND `text_id`=5184) OR (`entry`=4158 AND `text_id`=5196) OR (`entry`=4181 AND `text_id`=5273) OR (`entry`=4204 AND `text_id`=5325) OR (`entry`=4207 AND `text_id`=5340) OR (`entry`=4266 AND `text_id`=5428) OR (`entry`=4534 AND `text_id`=563) OR (`entry`=4536 AND `text_id`=563) OR (`entry`=5081 AND `text_id`=6288) OR (`entry`=5141 AND `text_id`=6173) OR (`entry`=5142 AND `text_id`=6174) OR (`entry`=5281 AND `text_id`=6313) OR (`entry`=7455 AND `text_id`=9029) OR (`entry`=7459 AND `text_id`=9034) OR (`entry`=7461 AND `text_id`=9037) OR (`entry`=7462 AND `text_id`=9041) OR (`entry`=7463 AND `text_id`=9042) OR (`entry`=7464 AND `text_id`=9043) OR (`entry`=7471 AND `text_id`=9054) OR (`entry`=7695 AND `text_id`=9389) OR (`entry`=7698 AND `text_id`=9393) OR (`entry`=7738 AND `text_id`=9471) OR (`entry`=7743 AND `text_id`=9481) OR (`entry`=7745 AND `text_id`=9484) OR (`entry`=7752 AND `text_id`=9492) OR (`entry`=7753 AND `text_id`=9493) OR (`entry`=7773 AND `text_id`=9521) OR (`entry`=7814 AND `text_id`=9566) OR (`entry`=7833 AND `text_id`=9586) OR (`entry`=7835 AND `text_id`=9591) OR (`entry`=7940 AND `text_id`=9733) OR (`entry`=7973 AND `text_id`=9805) OR (`entry`=7993 AND `text_id`=9845) OR (`entry`=8247 AND `text_id`=10264) OR (`entry`=8251 AND `text_id`=10270) OR (`entry`=8252 AND `text_id`=10271) OR (`entry`=8298 AND `text_id`=10352) OR (`entry`=8432 AND `text_id`=10538) OR (`entry`=8433 AND `text_id`=10291) OR (`entry`=8433 AND `text_id`=10292) OR (`entry`=8566 AND `text_id`=10735);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(1621, 2273), -- 8962
(1622, 2276), -- 8965
(4119, 5040), -- 11047
(4154, 5184), -- 11065
(4158, 5196), -- 11071
(4181, 5273), -- 11083
(4204, 5325), -- 11081
(4207, 5340), -- 11084
(4266, 5428), -- 11051
(4534, 563), -- 3047
(4536, 563), -- 3048
(5081, 6288), -- 13447
(5141, 6173), -- 13443
(5142, 6174), -- 13442
(5281, 6313), -- 13577
(7455, 9029), -- 17424
(7459, 9034), -- 17434
(7461, 9037), -- 17599
(7462, 9041), -- 17649
(7463, 9042), -- 17676
(7464, 9043), -- 17703
(7471, 9054), -- 17421
(7695, 9389), -- 18416
(7698, 9393), -- 18459
(7738, 9471), -- 18252
(7743, 9481), -- 18389
(7745, 9484), -- 18704
(7752, 9492), -- 18390
(7753, 9493), -- 18387
(7773, 9521), -- 18713
(7814, 9566), -- 18745
(7833, 9586), -- 18804
(7835, 9591), -- 17927
(7940, 9733), -- 19137
(7973, 9805), -- 19375
(7993, 9845), -- 15991
(8247, 10264), -- 21158
(8251, 10270), -- 21151
(8252, 10271), -- 21197
(8298, 10352), -- 17712
(8432, 10538), -- 21983
(8433, 10291), -- 19340
(8433, 10292), -- 19340
(8566, 10735); -- 22832

-- correct npc_flags for npc from sniff
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=3210; -- Brave Proudsnout
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=3211; -- Brave Lightninghorn
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=3213; -- Brave Running Wolf
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=3214; -- Brave Greathoof
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=3502; -- Ratchet Bruiser
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=21151; -- Borgrim Stouthammer <Explorers' League>
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=21197; -- Bronwyn Stouthammer <Explorers' League>
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=21469; -- Daranelle

-- Add condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=14 AND `SourceGroup`=8433 AND `SourceEntry`=10291) OR (`SourceTypeOrReferenceId`=14 AND `SourceGroup`=8433 AND `SourceEntry`=10292) OR (`SourceTypeOrReferenceId`=14 AND `SourceGroup`=12670 AND `SourceEntry`=12549);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,8433,10291,0,0,15,0,128,0,0,1,0,'','Show gossip text if player is not a mage'),
(14,8433,10292,0,0,15,0,128,0,0,0,0,'','Show gossip text if player is a mage'),
(14,12670,12549,0,0,15,0,256,0,0,1,0,'','Show gossip text if player is not a Warlock');
