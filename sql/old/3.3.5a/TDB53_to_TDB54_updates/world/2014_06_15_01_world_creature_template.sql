-- inherit vehicleid and accessory from normal mode npc
UPDATE `creature_template` SET `VehicleId`=0 WHERE `entry` IN (
30935, -- Drakkari Rhino (1)
31749, -- Hover Disk (1)
31748, -- Hover Disk (1)
37626  -- Iceborn Proto-Drake (1)
);
