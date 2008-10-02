-- support multikill bladespire and bloodmaul ogres
UPDATE `creature_template` SET `ScriptName` = 'mobs_bladespire_ogre' WHERE `entry` IN (19998, 20334, 21296, 21975);
UPDATE `creature_template` SET `ScriptName` = 'mobs_bloodmaul_ogre' WHERE `entry` IN (19948, 19952, 19957);
