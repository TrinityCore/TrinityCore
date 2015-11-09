ALTER TABLE `battleground_template`
	DROP COLUMN `StartMaxDist`;

UPDATE `battleground_template` SET `MaxLvl`=100;
