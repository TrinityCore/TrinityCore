-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=52358 AND `item`=137663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=192099 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=44606 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=45057 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=44599 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=44601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=44482 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=54438 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=54437 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=34498 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=44481 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=54343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=54436 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=48601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=46725 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=95482 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=95481 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=95621 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=104324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52358 AND `item`=104323 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `VerifiedBuild`) VALUES
(52358, 25, 137663, 0, 0, 1, 45745), -- Soft Foam Sword
(52358, 24, 192099, 0, 0, 1, 45745), -- Earpieces of Tranquil Focus
(52358, 22, 44606, 0, 0, 1, 45745), -- Toy Train Set
(52358, 21, 45057, 0, 0, 1, 45745), -- Wind-Up Train Wrecker
(52358, 20, 44599, 0, 0, 1, 45745), -- Zippy Copper Racer
(52358, 19, 44601, 0, 0, 1, 45745), -- Heavy Copper Racer
(52358, 18, 44482, 0, 0, 1, 45745), -- Trusty Copper Racer
(52358, 17, 54438, 0, 0, 1, 45745), -- Tiny Blue Ragdoll
(52358, 16, 54437, 0, 0, 1, 45745), -- Tiny Green Ragdoll
(52358, 15, 34498, 0, 0, 1, 45745), -- Paper Zeppelin Kit
(52358, 14, 44481, 0, 0, 1, 45745), -- Grindgear Toy Gorilla
(52358, 13, 54343, 0, 0, 1, 45745), -- Blue Crashin' Thrashin' Racer Controller
(52358, 12, 54436, 0, 0, 1, 45745), -- Blue Clockwork Rocket Bot
(52358, 11, 48601, 0, 0, 1, 45745), -- Red Rider Air Rifle Ammo
(52358, 10, 46725, 0, 0, 1, 45745), -- Red Rider Air Rifle
(52358, 9, 95482, 0, 0, 1, 45745), -- Red War Fuel
(52358, 8, 95481, 0, 0, 1, 45745), -- Blue War Fuel
(52358, 7, 95621, 0, 0, 1, 45745), -- Warbot Ignition Key
(52358, 6, 104324, 0, 0, 1, 45745), -- Foot Ball
(52358, 5, 104323, 0, 0, 1, 45745); -- The Swineskin

-- delete doubled gossip menu
DELETE FROM `gossip_menu_option` WHERE (`MenuID` = 12759 AND `OptionID` = 3); -- Craggle Wobbletop old & bug
