-- Fix dberrors
UPDATE `gameobject` SET `phaseMask`=1 WHERE `guid` BETWEEN 85253 AND 85253+35;
UPDATE `gameobject` SET `phaseMask`=1 WHERE `guid` BETWEEN 93999 AND 93999+47;
