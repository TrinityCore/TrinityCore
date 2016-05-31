DELETE FROM `creature_template_addon` WHERE `entry`IN (48,1027,1179,1708,3737,3749,3921,6221,7011,7396);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
-- Removed Battle Stance Aura, it should be set via SAI, same for any fake mining emotes) 
(  48,0,0,1114112,4097,0,''), -- Skeletal Warrior
(1027,0,0,1114112,4097,0,''), -- Bluegill Warrior
(1179,0,0,1114112,4097,0,''), -- Mogrosh Enforcer
(1708,0,0,1114112,4097,0,''), -- Defias Inmate
(3737,0,0,0,285216769,0,''), -- Saltspittle Puddlejumper
(3749,0,0,0,285216769,0,''), -- Foulweald Ursa
(3921,0,0,0,285216769,0,''), -- Thistlefur Ursa
(6221,0,0,1114112,4097,0,''), -- Addled Leper
(7011,0,0,1114112,4097,0,''), -- Earthen Rocksmasher
(7396,0,0,1114112,4097,0,''); -- Earthen Stonebreaker
-- Remove creature_addon templates in favor of general creature_template_addon ones, and possible SAI
DELETE FROM `creature_addon` WHERE `guid` IN (
-- Skeletal Warrior
4914,5008,5968,5974,5984,5985,5986,5987,5988,5989,6005,
-- Bluegill Warrior
9543,9544,9545,9605,9607,9686,9690,9759,9788,9796,9823,10730,10925,10928,11055,11058,
-- Mogrosh Enforcer
8366,8789,9082,9211,9216,9217,9227,9376,
-- Defias Inmate
79082,79095,79097,79103,79106,
-- Saltspittle Puddlejumper
32919,32920,32921,32922,32923,32924,32925,
-- Foulweld Ursa
33080,33081,33082,33083,
-- Thistlefur Ursa
32440,32441,32442,32443,32445,32446,32447,32448,
-- Addled Leper
2446,2447,2448,
-- Earthen Rocksmasher
28369,28370,28371,28374,28376,28377,28532,28535,28536,28537,28538,28539,28541,28542,28543,28544,28546,28547,28784,28795,28796,28797,28798,28799,29384,29488,29573,29574,
-- Earthen Stonebreaker
27764,27766,27767,27770,27789,27790,27791,33505,33506,33507,33508);
-- Remove Battle Stance Aura as that should already be done via SAI:
UPDATE `creature_addon` SET `auras`='' WHERE `auras`='7165' AND `guid` IN (90212,32617,12218,2443); 

