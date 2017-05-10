-- Fix address check for multi-jump hack
UPDATE `warden_checks` SET `result`='75440FB75E', `length`=5 WHERE `id`=785;
