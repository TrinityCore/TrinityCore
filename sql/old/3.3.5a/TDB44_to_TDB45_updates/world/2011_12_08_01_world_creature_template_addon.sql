-- Fix the HP sharing of Twin Valkyr - All Modes
DELETE FROM `creature_template_addon` WHERE `entry` IN (34497,35350,35351,35352,34496,35347,35348,35349);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(34497,'66133'),
(35350,'66133'),
(35351,'66133'),
(35352,'66133'),
(34496,'66132'),
(35347,'66132'),
(35348,'66132'),
(35349,'66132');
