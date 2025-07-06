-- Delete old spawns
DELETE FROM `creature` WHERE `guid` IN (313903,313896);

-- Update Jorgen
UPDATE `creature` SET `position_x` = -8970.783203125, `position_y` = 411.211822509765625, `position_z` = 74.8286590576171875, `orientation` = 2.580545663833618164 WHERE `guid` = 313907;
