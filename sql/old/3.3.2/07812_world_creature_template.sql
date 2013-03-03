-- Bone Gryphon
UPDATE `creature_template` SET `spell1`=48766,`spell2`=54469,`spell3`=54467,`spell4`=55214,`spell5`=54422,`VehicleId`=166 WHERE `entry`=29414;
-- Make the chopper mount usable as multimount, horde(i=41505) and ally(i=44413) version
UPDATE `creature_template` SET `vehicleid`=318 WHERE `entry` IN (29929,32286);
