-- Westfall: Lieutenant Horatio Lane set target to -self- when spell -self- cast so he dons his glasses
UPDATE `smart_scripts` SET `target_type`='1' WHERE  `entryorguid`=4230800 AND `source_type`=9 AND `id`=6 AND `link`=0;
