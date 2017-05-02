-- Brother Keltan position workaround until someone can sniff the correct start location and path he moves on by nelegalno
-- Closes https://github.com/TrinityCore/TrinityCore/issues/1964

SET @GUID=xxxxxx; -- Set by TDB team, need 1

DELETE FROM `creature_transport` WHERE `transport_entry`=192242 AND `npc_entry`=31261; -- Remove from Skybreaker
DELETE FROM `creature_transport` WHERE `transport_entry`=192241 AND `npc_entry`=31261; 
INSERT INTO `creature_transport` (`guid`, `transport_entry`, `npc_entry`, `TransOffsetX`, `TransOffsetY`, `TransOffsetZ`, `TransOffsetO`, `emote`) VALUES
(@GUID,192241,31261,-4.1663,9.0075,34.0151,1.43738,0); -- Add to Orgrim's Hammer