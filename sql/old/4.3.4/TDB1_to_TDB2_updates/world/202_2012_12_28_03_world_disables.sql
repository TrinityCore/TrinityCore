-- Remove deprecated older version of  "Ally of the Netherwing"
DELETE FROM `disables` WHERE `entry`=10871 AND `sourceType`=1;
INSERT INTO `disables` (`sourceType`,`entry`,`comment`) VALUES (1,10871, 'Deprecated quest - Ally of the Netherwing (first version - when it was for alliance only, reworked after 3.3.0)');
