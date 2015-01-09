UPDATE `areatrigger_teleport` SET `target_position_x`=-10700.4, `target_position_y`=-1312.69, `target_position_z`=17.6029, `target_orientation`=3.455752 WHERE `id`=6620; -- Lost City of the Tol'vir (Enterance)
UPDATE `areatrigger_teleport` SET `target_position_x`=-10679.7, `target_position_y`=-1307.1, `target_position_z`=17.3427, `target_orientation`=0.3490659 WHERE `id`=6488; -- Lost City of the Tol'vir (Exit)
UPDATE `areatrigger_teleport` SET `target_position_x`=-11513.3, `target_position_y`=-2309.88, `target_position_z`=608.393, `target_orientation`=0.6283186 WHERE `id`=6610; -- The Vortex Pinnacle (Exit)
UPDATE `areatrigger_teleport` SET `target_position_x`=-954.106, `target_position_y`=462.408, `target_position_z`=51.9705, `target_orientation`=1.570796 WHERE `id`=6485; -- Halls of Origination (Enterance)
UPDATE `areatrigger_teleport` SET `target_position_x`=-10210.5, `target_position_y`=-1837.61, `target_position_z`=20.1278, `target_orientation`=0 WHERE `id`=6487; -- Halls of Origination (Exit)


DELETE FROM `areatrigger_teleport` WHERE `id`=6321;
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(6321, 'Badlands Teleporter', 0, -6547.88, -4443.24, 332.079, 0.6632252);
