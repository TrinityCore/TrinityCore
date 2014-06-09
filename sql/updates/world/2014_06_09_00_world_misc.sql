DELETE FROM `gameobject` WHERE guid IN (33184,33187,33190,33191,33192,33195,33196);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(33184,194955,571,1,1,5988.04,4473.78,-87.3617,1.74533,0,0,0.766045,0.642787,180,255,1),
(33187,194955,571,1,1,6073.83,4463.66,-84.9872,-0.820303,0,0,-0.398748,0.91706,180,255,1),
(33190,194955,571,1,1,6130.8,4462.61,-84.544,2.75761,0,0,0.981626,0.190814,180,255,1),
(33191,194955,571,1,1,6075.99,4523.62,-81.0092,0.698132,0,0,0.34202,0.939693,180,255,1),
(33192,194955,571,1,1,6012.03,4517.3,-86.8614,0.872664,0,0,0.422618,0.906308,180,255,1),
(33195,194955,571,1,1,6092.64,4425.49,-83.9704,-2.72271,0,0,-0.978147,0.207914,180,255,1),
(33196,194955,571,1,1,6102.15,4497.03,-81.3401,-2.63544,0,0,-0.968147,0.250383,180,255,1);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=190590;
DELETE FROM `smart_scripts` WHERE `entryorguid`=190590 AND  `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(190590,1,0,0,70,0,100,0,2,0,0,0,70,60,0,0,0,0,0,1,0,0,0,0,0,0,0,'Unstable Explosives - On State Changed - Despawn for 60 sec');
