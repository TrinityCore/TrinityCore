-- 
DELETE FROM `pool_template` WHERE `entry`=377;
INSERT INTO pool_template (`entry`,`max_limit`,`description`) VALUES
(377,1, 'Tivax the Breaker (1 out 2)');

DELETE FROM `pool_creature` WHERE `pool_entry`=377;
INSERT INTO pool_creature(`guid`,`pool_entry`,`chance`,`description`) VALUES
(109685,377,0, 'Tivax the Breaker 1'),
(109693,377,0, 'Tivax the Breaker 2');
