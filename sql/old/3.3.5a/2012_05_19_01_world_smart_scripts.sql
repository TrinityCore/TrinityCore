-- Fix Quest 9962,9967,9970,9972,9973
UPDATE `smart_scripts` SET `target_type`=16 WHERE `entryorguid`=18398 AND `id`=1; -- Brokentoe
UPDATE `smart_scripts` SET `target_type`=16 WHERE `entryorguid`=18399 AND `id`=4; -- Murkblood Twin
UPDATE `smart_scripts` SET `target_type`=16 WHERE `entryorguid`=18400 AND `id`=5; -- Rokdar the Sundered Lord
UPDATE `smart_scripts` SET `target_type`=16 WHERE `entryorguid`=18401 AND `id`=3; -- Skra'gath
UPDATE `smart_scripts` SET `id`=5,`link`=6,`target_type`=16 WHERE `entryorguid`=18402 AND `action_type`=15; -- Warmaul Champion
UPDATE `smart_scripts` SET `id`=6 WHERE `entryorguid`=18402 AND `action_type`=45; -- Warmaul Champion
