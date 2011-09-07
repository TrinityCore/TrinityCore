DELETE FROM `spell_target_position` WHERE `id` IN (46233,52462,54963);
INSERT INTO `spell_target_position` (`id` ,`target_map` ,`target_position_x` ,`target_position_y` ,`target_position_z` ,`target_orientation`) VALUES
(46233,571,3202.959961,5274.073730,46.887897,0.015704), -- Call Mammoth Orphan
(52462,609,2387.738525,-5898.617676,108.353539,4.354776), -- Hide In Mine Car
(54963,571,6153.721191,-1075.270142,403.517365,2.232988); -- Teleporter Power Cell
