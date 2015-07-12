--
DELETE FROM `gameobject` WHERE `guid`=43131;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (164820, 164821, 164822, 164823, 164824, 164825);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (164819, 164820, 164821, 164822, 164823, 164824, 164825) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16481900,16481901,16481902,16481903,16481904,16481905) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(164819, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 87, 16481900, 16481901, 16481902, 16481903, 16481904, 16481905, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Keeper Portrait - ON_STATE_CHANGED - Random action list'),
(16481900, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 50, 164820, 999990, 0, 0, 0, 0, 8, 0, 0, 0, 831.54,-339.529,-46.682,0.802851, 'Dark Keeper Portrait - action list - Summon Dark Keeper Nameplate'),
(16481900, 9, 1, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 164820, 20, 0, 0, 0, 0, 0, 'Dark Keeper Nameplate - action list - Remove flags'),
(16481900, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9437, 8, 0, 0, 0, 0, 8, 0, 0, 0, 914.054688, -164.124573, -49.760696, 2.162512, 'Dark Keeper Portrait - action list - Summon Dark Keeper Vorfalk'),
(16481900, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 916.78241, -163.221985, -49.760696, 2.222960, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481900, 9, 4, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 912.515259, -166.480469, -49.760696, 2.222960, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481901, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 50, 164821, 999990, 0, 0, 0, 0, 8, 0, 0, 0, 831.54,-339.529,-46.682,0.802851, 'Dark Keeper Portrait - action list - Summon Dark Keeper Nameplate'),
(16481901, 9, 1, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 164821, 20, 0, 0, 0, 0, 0, 'Dark Keeper Nameplate - action list - Remove flags'),
(16481901, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9438, 8, 0, 0, 0, 0, 8, 0, 0, 0, 812.245789, -348.875336, -50.578079, 0.710542, 'Dark Keeper Portrait - action list - Summon Dark Keeper Bethek'),
(16481901, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 809.894714, -348.221252, -50.578079, 0.713424, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481901, 9, 4, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 812.574646, -351.317627, -50.578079, 0.713424, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481902, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 50, 164822, 999990, 0, 0, 0, 0, 8, 0, 0, 0, 831.54,-339.529,-46.682,0.802851, 'Dark Keeper Portrait - action list - Summon Dark Keeper Nameplate'),
(16481902, 9, 1, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 164822, 20, 0, 0, 0, 0, 0, 'Dark Keeper Nameplate - action list - Remove flags'),
(16481902, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9439, 8, 0, 0, 0, 0, 8, 0, 0, 0, 888.483093, -361.707306, -49.935787, 0.612107, 'Dark Keeper Portrait - action list - Summon Dark Keeper Uggel'),
(16481902, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 886.981873, -360.477570, -49.935787, 0.612107, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481902, 9, 4, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 888.820007, -363.745789, -49.935787, 0.612107, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481903, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 50, 164823, 999990, 0, 0, 0, 0, 8, 0, 0, 0, 831.54,-339.529,-46.682,0.802851, 'Dark Keeper Portrait - action list - Summon Dark Keeper Nameplate'),
(16481903, 9, 1, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 164823, 20, 0, 0, 0, 0, 0, 'Dark Keeper Nameplate - action list - Remove flags'),
(16481903, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9441, 8, 0, 0, 0, 0, 8, 0, 0, 0, 545.018250, -214.378723, -35.546509, 0.339364, 'Dark Keeper Portrait - action list - Summon Dark Keeper Zimrel'),
(16481903, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 543.336975, -211.983978, -35.511829, 0.401620, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481903, 9, 4, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 546.018433, -217.407089, -35.570370, 0.505293, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481904, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 50, 164824, 999990, 0, 0, 0, 0, 8, 0, 0, 0, 831.54,-339.529,-46.682,0.802851, 'Dark Keeper Portrait - action list - Summon Dark Keeper Nameplate'),
(16481904, 9, 1, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 164824, 20, 0, 0, 0, 0, 0, 'Dark Keeper Nameplate - action list - Remove flags'),
(16481904, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9442, 8, 0, 0, 0, 0, 8, 0, 0, 0, 659.373108, 2.659090, -60.058517, 0.990563, 'Dark Keeper Portrait - action list - Summon Dark Keeper Ofgut'),
(16481904, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 658.681152, 5.299511, -60.058456, 0.990563, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481904, 9, 4, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 661.902344, 2.769512, -60.058456, 0.990563, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481904, 9, 5, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 659.791687, -0.450377, -60.058517, 0.990563, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481904, 9, 6, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 656.212524, 2.171975, -60.058456, 0.99056, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481905, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 50, 164825, 999990, 0, 0, 0, 0, 8, 0, 0, 0, 831.54,-339.529,-46.682,0.802851, 'Dark Keeper Portrait - action list - Summon Dark Keeper Nameplate'),
(16481905, 9, 1, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 164825, 20, 0, 0, 0, 0, 0, 'Dark Keeper Nameplate - action list - Remove flags'),
(16481905, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9443, 8, 0, 0, 0, 0, 8, 0, 0, 0, 804.041260, -247.344772, -43.302856, 2.606160, 'Dark Keeper Portrait - action list - Summon Dark Keeper Pelver'),
(16481905, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 805.992065, -246.460281, -43.302856, 2.525251, 'Dark Keeper Portrait - action list - Summon Dark guard'),
(16481905, 9, 4, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 9445, 8, 0, 0, 0, 0, 8, 0, 0, 0, 803.904053, -249.407654, -43.302856, 2.525251, 'Dark Keeper Portrait - action list - Summon Dark guard');
