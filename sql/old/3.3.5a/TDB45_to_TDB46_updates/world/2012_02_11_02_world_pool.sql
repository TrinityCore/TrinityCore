SET @pool_id := 352;

DELETE FROM `pool_template` WHERE `entry` IN (@pool_id, @pool_id+1);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool_id,1, 'The Rokk <Master of Cooking> - Daily Quests'),
(@pool_id+1,1, 'Old Man Barlowned - Daily Quests');

DELETE FROM `pool_quest` WHERE `entry` IN (11377,11379,11380,11381) AND `pool_entry` = @pool_id;
DELETE FROM `pool_quest` WHERE `entry` IN (11665,11666,11667,11668,11669) AND `pool_entry` = @pool_id+1;
INSERT INTO `pool_quest` (`entry`,`pool_entry`,`description`) VALUES
(11377,@pool_id, 'Revenge is Tasty'),
(11379,@pool_id, 'Super Hot Stew'),
(11380,@pool_id, 'Manalicious'),
(11381,@pool_id, 'Soup for the Soul'),
(11665,@pool_id+1, 'Crocolisks in the City'),
(11666,@pool_id+1, 'Bait Bandits'),
(11667,@pool_id+1, 'The One That Got Away'),
(11668,@pool_id+1, 'Shrimpin Aint Easy'),
(11669,@pool_id+1, 'Felblood Fillet');
