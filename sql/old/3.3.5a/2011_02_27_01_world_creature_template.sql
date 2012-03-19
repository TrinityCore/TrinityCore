-- Template updates 
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|32 WHERE `entry`=33063; -- Wrecked Siege Engine
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|32 WHERE `entry`=33059; -- Wrecked Demolisher
UPDATE `creature_template` SET `exp`=1 WHERE `entry`=33662; -- Kirin Tor Battle-Mage
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=33377; -- Mortar Targetting Device
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry`=33686; -- Lore Keeper of Norgannon
UPDATE `creature_template` SET `exp`=1 WHERE `entry`=33626; -- Hired Engineer
UPDATE `creature_template` SET `exp`=1 WHERE `entry`=33627; -- Hired Demolitionist
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry`=33624; -- Archmage Pentarus
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=33571; -- Ulduar Gauntlet Generator

-- Model data 
UPDATE `creature_model_info` SET `bounding_radius`=3,`combat_reach`=2.25,`gender`=2 WHERE `modelid`=27658; -- Wrecked Demolisher
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=11686; -- Mortar Targetting Device
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=11686; -- Mortar Targetting Device
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=11686; -- Mortar Targetting Device
UPDATE `creature_model_info` SET `bounding_radius`=1.4288,`combat_reach`=2.4,`gender`=0 WHERE `modelid`=28781; -- Demolisher Engineer Blastwrench
UPDATE `creature_model_info` SET `bounding_radius`=0.2625,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=6589; -- Lore Keeper of Norgannon
UPDATE `creature_model_info` SET `bounding_radius`=0.434,`combat_reach`=1.4,`gender`=0 WHERE `modelid`=28739; -- Goran Steelbreaker
UPDATE `creature_model_info` SET `bounding_radius`=0.434,`combat_reach`=1.4,`gender`=0 WHERE `modelid`=28739; -- Goran Steelbreaker
UPDATE `creature_model_info` SET `bounding_radius`=0.372,`combat_reach`=1.2,`gender`=0 WHERE `modelid`=26662; -- Earthen Stoneshaper
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=1,`gender`=0 WHERE `modelid`=28581; -- Steelforged Defender
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=1,`gender`=0 WHERE `modelid`=28580; -- Steelforged Defender
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=5233; -- Spirit Healer
 
-- Addon data 
DELETE FROM `creature_template_addon` WHERE `entry` IN 
(33059,33063,33662,33672,33167,33626,33060,33377,33062,33067,33579,33669,33214,33109,33666,33701,33686,33696,33622,33627,33779,33620
,32780,33624,33218,33629,33721,34234,33236,33571);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33059,0,0,257,0, '29266 0 29266 1'), -- Wrecked Demolisher; Auras: Permanent Feign Death
(33063,0,0,257,0, '29266 0 29266 1'), -- Wrecked Siege Engine; Aura: Permanent Feign Death
(33060,0,0,257,0, NULL), -- Salvaged Siege Engine
(33662,0,0,1,0, NULL), -- Kirin Tor Battle-Mage
(33672,0,0,1,0, NULL), -- Kirin Tor Mage
(33167,0,0,257,0, NULL), -- Salvaged Demolisher Mechanic Seat
(33626,0,0,1,0, NULL), -- Hired Engineer
(33627,0,0,1,0, NULL), -- Hired Demolitionist
(33377,0,0,1,0, NULL), -- Mortar Targetting Device
(33062,0,0,257,0, NULL), -- Salvaged Chopper
(33067,0,0,257,0, NULL), -- Salvaged Siege Turret
(33579,0,0,1,0, NULL), -- Brann Bronzebeard
(33669,0,0,257,0, NULL), -- Demolisher Engineer Blastwrench
(33214,0,50331648,1,0, NULL), -- Mechanolift 304-A
(33109,0,0,257,0, NULL), -- Salvaged Demolisher
(33666,0,0,257,0, NULL), -- Demolisher Engineer Blastwrench
(33701,0,0,1,0, NULL), -- High Explorer Dellorah
(33686,0,0,1,0, NULL), -- Lore Keeper of Norgannon
(33696,0,0,1,0, NULL), -- Archmage Rhydian
(33622,0,0,1,0, NULL), -- Goran Steelbreaker
(33779,0,0,1,0, NULL), -- Ulduar Shield Bunny
(33620,0,0,1,0, NULL), -- Earthen Stoneshaper
(32780,0,0,1,0, NULL), -- Invisible Stalker (All Phases)
(33624,0,0,1,0, NULL), -- Archmage Pentarus
(33218,0,0,1,0, NULL), -- Pyrite Safety Container
(33629,14374,0,257,0, NULL), -- Weslex Quickwrench
(33721,0,50331648,1,0, NULL), -- Lore Keeper Projection Unit
(34234,0,0,1,0, NULL), -- Runeforged Sentry
(33236,0,0,1,27, NULL), -- Steelforged Defender
(33571,0,0,1,0, NULL); -- Ulduar Gauntlet Generator

-- Addon data for creature 6491 (Spirit Healer)
UPDATE `creature_template_addon` SET `bytes1`=65536,`bytes2`=1,`mount`=0,`emote`=0,`auras`='10848  0' WHERE `entry`=6491; -- Spirit Healer

DELETE FROM `creature_addon` WHERE `guid` IN (136245,136246,136247,136248,136249); -- Wrecked Siege Engine
DELETE FROM `creature_addon` WHERE `guid` IN (136073,136074,136087,136088,136089,136090); -- Wrecked Siege Engine
