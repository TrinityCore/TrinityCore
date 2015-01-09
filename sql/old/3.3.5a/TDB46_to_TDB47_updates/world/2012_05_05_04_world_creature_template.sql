-- Fix InhabitType for Eye of the Lich King
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=36913;
-- Updates From CDawg
-- Wrathbone Laborer (heroic) - fix hostility and adds equipment
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~256,`equipment_id`=104 WHERE `entry`=37638;
-- Wrathbone Siegesmith (Heroic) add equipment
UPDATE `creature_template` SET `equipment_id`=122 WHERE `entry`=37639;
-- Fallen Warrior add equipment
UPDATE `creature_template` SET `equipment_id`=2328 WHERE `entry`=37612;
-- Forgemaster Garfrost add equipment
UPDATE `creature_template` SET `equipment_id`=2325 WHERE `entry`=37613;
-- Deathwhisper Necrolyte add equipment
UPDATE `creature_template` SET `equipment_id`=2365 WHERE `entry`=37609;
-- Deathwhisper Shadowcaster - add equipment
UPDATE `creature_template` SET `equipment_id`=2365 WHERE `entry`=38025;
-- Alliance slaves add equipments
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=37645;
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=37646;
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=37647;
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=37648;
-- horde slaves add equipments
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=37649;
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=37650;
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=37651;
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=37652;
-- Ymirjar Skycaller (heroic) - Fix unit flags and add equipment
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32832,`equipment_id`=2438 WHERE `entry`=37643;
