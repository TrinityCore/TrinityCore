DELETE FROM `gameobject_template` WHERE `entry`=204120;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(204120, 3, 2450, 'Cache of Shadra', '', '', '', 43, 30296, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 58281, 0, 0, 0, 0, 0, 0, 15595); -- 204120

UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=175889; -- Ancient Egg
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=175890; -- Ancient Egg Aura
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=20979; -- Troll Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=20978; -- Troll Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=20980; -- Troll Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=20977; -- Troll Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=18047; -- 18047
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=18051; -- 18051
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=18050; -- 18050
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=18048; -- 18048
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=18049; -- 18049
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=18052; -- 18052
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=181645; -- Gryphon Egg
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=181649; -- Featherbeard's Journal
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=2558; -- Test
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32583; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=31507; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32582; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32590; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32591; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32594; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=31508; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32593; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32585; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=31504; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32592; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=32584; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=34572; -- Forge
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=31509; -- Wooden Chair

UPDATE `quest_template` SET `RequestItemsText`='I hope you brought enough.' WHERE `Id`=26382; -- Can't Make An Omelette Without...

UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=5951; -- Hare
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2505; -- Saltwater Snapjaw
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=14730; -- Revantusk Watcher
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=14737; -- Smith Slagtree
UPDATE `creature_template` SET `npcflag`=0, `dynamicflags`=0 WHERE `entry`=17598; -- Renn'az
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `dynamicflags`=0 WHERE `entry`=8885; -- Riding Raptor
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=14731; -- Lard
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=14739; -- Mystic Yayo'jin
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=14738; -- Otho Moji'ko
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=14741; -- Huntsman Markhor
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=7825; -- Oran Snakewrithe
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=14734; -- Revantusk Drummer
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=14740; -- Katoom the Angler
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=4314; -- Gorkas
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=7977; -- Gammerita
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=22480; -- Brown Marmot
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2926; -- Silvermane Stalker
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2923; -- Mangy Silvermane
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2656; -- Jade Ooze
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2655; -- Green Sludge
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=16030; -- Maggot
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2929; -- Savage Owlbeast
UPDATE `creature_template` SET `maxlevel`=34, `dynamicflags`=0 WHERE `entry`=2659; -- Razorbeak Skylord
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43570; -- Brock Rockbeard
UPDATE `creature_template` SET `npcflag`=0, `dynamicflags`=0 WHERE `entry`=7865; -- Wildhammer Sentry
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=12036; -- Aerie Peak General Goods
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43699; -- Innkeeper Keirnan
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43770; -- Tathan Thunderstone
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43109; -- Dron Blastbrew
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43108; -- Kerr Ironsight
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=12040; -- Aerie Peak Mail Armor Vendor
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2640; -- Vilebranch Witch Doctor
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4465; -- Vilebranch Warrior
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2680; -- Vilebranch Wolf Pup
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2641; -- Vilebranch Headhunter
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=42724; -- Umboda Three-Heads
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2643; -- Vilebranch Berserker
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2642; -- Vilebranch Shadowcaster
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2645; -- Vilebranch Shadow Hunter
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2644; -- Vilebranch Hideskinner
UPDATE `creature_template` SET `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=2646; -- Vilebranch Blood Drinker
UPDATE `creature_template` SET `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=2647; -- Vilebranch Soul Eater
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2648; -- Vilebranch Aman'zasi Guard
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2681; -- Vilebranch Raiding Wolf
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=4466; -- Vilebranch Scalper
UPDATE `creature_template` SET `dynamicflags`=4 WHERE `entry`=42879; -- Spawn of Shadra
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33, `faction_A`=795, `faction_H`=795, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `dynamicflags`=4 WHERE `entry`=42877; -- Morta'gya the Keeper
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43156; -- Fraggar Thundermantle
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2928; -- Primitive Owlbeast
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35, `dynamicflags`=0 WHERE `entry`=7806; -- Homing Robot OOX-09/HL
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2925; -- Silvermane Howler
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=4467; -- Vilebranch Soothsayer
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2639; -- Vilebranch Axe Thrower
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2658; -- Razorbeak Gryphon
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2924; -- Silvermane Wolf
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2927; -- Vicious Owlbeast
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=46475; -- Anchorite Traska
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43200; -- Gilda Cloudcaller
UPDATE `creature_template` SET `npcflag`=0, `dynamicflags`=0 WHERE `entry`=8214; -- Jalinde Summerdrake
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43298; -- Wildhammer Lookout
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=2657; -- Trained Razorbeak
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=8219; -- Zul'arek Hatefowler
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=5634; -- Rhapsody Shindigger
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=7801; -- Gilveradin Sunchaser
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction_A`=189, `faction_H`=189, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=64, `dynamicflags`=0 WHERE `entry`=8211; -- Old Cliff Jumper
UPDATE `creature_template` SET `maxlevel`=40, `dynamicflags`=0 WHERE `entry`=8276; -- Soaring Razorbeak
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=8161; -- Harggan
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=8018; -- Guthrum Thunderfist
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=5636; -- Gryphon Master Talonaxe
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=1054, `faction_H`=1054, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=12 WHERE `entry`=51923; -- Wildhammer Sentry
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=11097; -- Drakk Stonehand
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=8160; -- Nioma
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=24 WHERE `entry`=49251; -- Wild Gryphon

UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33100;

DELETE FROM `npc_vendor` WHERE `entry` IN (14737, 14737, 14737, 14737, 14737, 14737, 14740, 14740, 14740, 14740, 14740, 14738, 14738, 14738, 14738, 14738, 43766, 43750, 43750, 43750, 43750, 43750, 43750, 43750, 43750, 43750, 43748, 43748, 43748, 43748, 43748, 43748, 43748, 43748, 43748);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 14737 (Smith Slagtree)
(14737, 2901, 1, 0, 0, 1), -- Mining Pick
(14737, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(14737, 2880, 3, 0, 0, 1), -- Weak Flux
(14737, 3466, 4, 0, 0, 1), -- Strong Flux
(14737, 18567, 5, 0, 0, 1), -- Elemental Flux
(14737, 3857, 6, 0, 0, 1), -- Coal
-- 14740 (Katoom the Angler)
(14740, 6256, 455, 0, 0, 1), -- Fishing Pole
(14740, 6365, 456, 1, 0, 1), -- Strong Fishing Pole
(14740, 6529, 457, 0, 0, 1), -- Shiny Bauble
(14740, 6530, 458, 0, 0, 1), -- Nightcrawlers
(14740, 6532, 459, 0, 0, 1), -- Bright Baubles
-- 14738 (Otho Moji'ko)
(14738, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(14738, 30817, 2, 0, 0, 1), -- Simple Flour
(14738, 2678, 3, 0, 0, 1), -- Mild Spices
(14738, 21099, 4, 0, 0, 1), -- Recipe: Smoked Sagefish
(14738, 21219, 5, 0, 0, 1), -- Recipe: Sagefish Delight
-- 43766 (Roslyn Paxton)
(43766, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 43750 (Marvin Winters)
(43750, 2417, 1, 0, 0, 1), -- Augmented Chain Vest
(43750, 2419, 2, 0, 0, 1), -- Augmented Chain Belt
(43750, 2418, 3, 0, 0, 1), -- Augmented Chain Leggings
(43750, 2420, 4, 0, 0, 1), -- Augmented Chain Boots
(43750, 2421, 5, 0, 0, 1), -- Augmented Chain Bracers
(43750, 2422, 6, 0, 0, 1), -- Augmented Chain Gloves
(43750, 3891, 7, 0, 0, 1), -- Augmented Chain Helm
(43750, 17189, 8, 0, 0, 1), -- Metal Buckler
(43750, 2448, 9, 0, 0, 1), -- Heavy Pavise
-- 43748 (Janice Winters)
(43748, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(43748, 1205, 2, 0, 0, 1), -- Melon Juice
(43748, 1708, 3, 0, 0, 1), -- Sweet Nectar
(43748, 1645, 4, 0, 0, 1), -- Moonberry Juice
(43748, 4542, 5, 0, 0, 1), -- Moist Cornbread
(43748, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(43748, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(43748, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(43748, 4470, 9, 0, 0, 1); -- Simple Wood
