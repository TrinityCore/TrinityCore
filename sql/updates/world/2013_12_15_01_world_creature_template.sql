-- Fix Trained Rock Falcon InhabitType
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=24783;
-- Fix faction for Earthen Dwarf
UPDATE `creature_template` SET `faction_A`=1868,`faction_H`=1868 WHERE entry IN (27980,31391);
