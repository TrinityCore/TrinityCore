-- Woo Ping <Weapon Master> Require level 20 to train polearms
UPDATE `trainer_spell` SET `ReqLevel`=20 WHERE `TrainerId`=53 AND `SpellId`=200;
