SET @EQUIP := 2427;

UPDATE `creature_template` SET `baseattacktime`=2000,`speed_run`=1.7142857142857 WHERE `entry`=36808; -- Deathspeaker Zealot
UPDATE `creature_template` SET `baseattacktime`=2000,`speed_run`=1.1428571428571 WHERE `entry`=37012; -- Ancient Skeletal Soldier
UPDATE `creature_template` SET `baseattacktime`=1000,`unit_flags`=`unit_flags`|33587520,`speed_walk`=2,`speed_run`=1.4285714285714 WHERE `entry`=37007; -- Deathbound Ward
UPDATE `creature_template` SET `exp`=2,`minlevel`=82,`maxlevel`=82,`baseattacktime`=2000,`unit_class`=2,`speed_walk`=2,`speed_run`=1.5873 WHERE `entry`=37528; -- Spire Frostwyrm (Ambient)
UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`speed_run`=0.99206285714286 WHERE `entry`=37947; -- Deathwhisper Spawn Stalker
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=@EQUIP,`speed_run`=1.1428571428571 WHERE `entry`=37149; -- Kor'kron Necrolyte
UPDATE `creature_template` SET `faction_A`=83,`faction_H`=83,`baseattacktime`=2000,`unit_flags`=`unit_flags`|32832,`equipment_id`=@EQUIP+1,`speed_run`=1.1428571428571 WHERE `entry`=37034; -- Kor'kron Templar
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10065,`speed_run`=1.1428571428571 WHERE `entry`=37031; -- Kor'kron Oracle
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10064,`speed_run`=1.1428571428571 WHERE `entry`=37033; -- Kor'kron Invoker
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10057,`speed_run`=1.1428571428571 WHERE `entry`=37030; -- Kor'kron Primalist
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10058,`speed_run`=1.1428571428571 WHERE `entry`=37016; -- Skybreaker Luminary
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10069,`speed_run`=1.1428571428571 WHERE `entry`=37148; -- Skybreaker Summoner
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10057,`speed_run`=1.1428571428571 WHERE `entry`=37027; -- Skybreaker Hierophant
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10060,`speed_run`=1.1428571428571 WHERE `entry`=37026; -- Skybreaker Sorcerer
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10062,`speed_run`=1.1428571428571 WHERE `entry`=37003; -- Skybreaker Vindicator
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10068,`speed_run`=1.1428571428571 WHERE `entry`=37035; -- Kor'kron Vanquisher
UPDATE `creature_template` SET `baseattacktime`=1000,`equipment_id`=@EQUIP+2,`speed_run`=1.1428571428571 WHERE `entry`=37146; -- Kor'kron Sniper
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10063,`speed_run`=1.1428571428571 WHERE `entry`=37032; -- Kor'kron Defender
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=10067,`unit_class`=4,`speed_run`=1.1428571428571 WHERE `entry`=37028; -- Kor'kron Stalker
UPDATE `creature_template` SET `baseattacktime`=2000,`equipment_id`=@EQUIP+3,`speed_run`=1.1428571428571 WHERE `entry`=37029; -- Kor'kron Reaver
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|559168,`speed_walk`=0.8,`speed_run`=0.99205714285714 WHERE `entry`=37545; -- Spire Minion

DELETE FROM `creature_template_addon` WHERE `entry` IN (37012,36808,37528,37007,37947,37030,37146,37032,37029,37027,37149,37031,37034,37016,37148,37026,37028,37003,37033,37035,37545);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(37012,0,0,1,333, NULL), -- Ancient Skeletal Soldier
(36808,0,8,1,0, NULL), -- Deathspeaker Zealot
(37528,0,50331648,1,0, NULL), -- Spire Frostwyrm (Ambient)
(37007,0,0,0,417, NULL), -- Deathbound Ward
(37947,0,0,1,0, NULL), -- Deathwhisper Spawn Stalker
(37030,0,0,1,0, NULL), -- Kor'kron Primalist
(37146,0,0,1,0, NULL), -- Kor'kron Sniper
(37032,0,0,1,0, NULL), -- Kor'kron Defender
(37029,0,0,1,0, NULL), -- Kor'kron Reaver
(37027,0,0,1,0, NULL), -- Skybreaker Hierophant
(37149,0,0,1,0, NULL), -- Kor'kron Necrolyte
(37031,0,0,1,0, NULL), -- Kor'kron Oracle
(37034,0,0,1,0, NULL), -- Kor'kron Templar
(37016,0,0,1,0, NULL), -- Skybreaker Luminary
(37148,0,0,1,0, NULL), -- Skybreaker Summoner
(37026,0,0,1,0, NULL), -- Skybreaker Sorcerer
(37028,0,0,1,0, NULL), -- Kor'kron Stalker
(37003,0,0,1,0, NULL), -- Skybreaker Vindicator
(37033,0,0,1,0, NULL), -- Kor'kron Invoker
(37035,0,0,1,0, NULL), -- Kor'kron Vanquisher
(37545,0,0,1,0, NULL); -- Spire Minion

UPDATE `creature_model_info` SET `bounding_radius`=0.45,`combat_reach`=0.45,`gender`=0 WHERE `modelid`=31124; -- Bone Spike
UPDATE `creature_model_info` SET `bounding_radius`=0.347222,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=30616; -- Ancient Skeletal Soldier
UPDATE `creature_model_info` SET `bounding_radius`=1.388888,`combat_reach`=6,`gender`=0 WHERE `modelid`=30459; -- Deathbound Ward
UPDATE `creature_model_info` SET `bounding_radius`=1.5,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30463; -- Skybreaker Luminary
UPDATE `creature_model_info` SET `bounding_radius`=1.46205,`combat_reach`=6.075,`gender`=0 WHERE `modelid`=30481; -- Kor'kron Primalist
UPDATE `creature_model_info` SET `bounding_radius`=0.459,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30531; -- Kor'kron Sniper
UPDATE `creature_model_info` SET `bounding_radius`=0.5745,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30482; -- Kor'kron Reaver
UPDATE `creature_model_info` SET `bounding_radius`=0.558,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=30475; -- Kor'kron Defender
UPDATE `creature_model_info` SET `bounding_radius`=0.354,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30486; -- Kor'kron Stalker
UPDATE `creature_model_info` SET `bounding_radius`=0.459,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=30453; -- Skybreaker Vindicator
UPDATE `creature_model_info` SET `bounding_radius`=0.5835,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=30472; -- Skybreaker Hierophant
UPDATE `creature_model_info` SET `bounding_radius`=0.52785,`combat_reach`=2.5875,`gender`=1 WHERE `modelid`=30470; -- Skybreaker Sorcerer
UPDATE `creature_model_info` SET `bounding_radius`=0.459,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=30476; -- Kor'kron Invoker
UPDATE `creature_model_info` SET `bounding_radius`=0.5745,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=30534; -- Kor'kron Necrolyte
UPDATE `creature_model_info` SET `bounding_radius`=0.459,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30478; -- Kor'kron Oracle
UPDATE `creature_model_info` SET `bounding_radius`=0.5745,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30487; -- Kor'kron Templar
UPDATE `creature_model_info` SET `bounding_radius`=0.312,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30536; -- Skybreaker Summoner
UPDATE `creature_model_info` SET `bounding_radius`=0.5745,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=30489; -- Kor'kron Vanquisher
UPDATE `creature_model_info` SET `bounding_radius`=0.62,`combat_reach`=2,`gender`=2 WHERE `modelid`=30656; -- Spire Minion


DELETE FROM `creature_equip_template` WHERE `entry` IN (@EQUIP,@EQUIP+1,@EQUIP+2,@EQUIP+3);
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES
(@EQUIP,49764,0,0),
(@EQUIP+1,49736,0,0),
(@EQUIP+2,0,0,49762),
(@EQUIP+3,49733,0,0);
