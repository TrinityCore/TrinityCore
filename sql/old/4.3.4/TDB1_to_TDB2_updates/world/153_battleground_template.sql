-- New 4.x Maximum level
UPDATE `battleground_template` SET `MaxLvl`=85;

-- New 4.x Minimum levels
UPDATE `battleground_template` SET `MinLvl`=45 WHERE `id`=1; -- Alterac Valley
UPDATE `battleground_template` SET `MinLvl`=10 WHERE `id`=3; -- Arathi Basin
UPDATE `battleground_template` SET `MinLvl`=35 WHERE `id`=7; -- Eye of the Storm
UPDATE `battleground_template` SET `MinLvl`=65 WHERE `id`=9; -- Strand of the Ancients
UPDATE `battleground_template` SET `MinLvl`=45 WHERE `id`=32; -- Random Battleground
