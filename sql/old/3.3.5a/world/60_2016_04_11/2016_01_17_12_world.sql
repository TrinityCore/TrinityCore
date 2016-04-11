--
SET @pool_id=369;
SET @GUID=87572;
DELETE FROM `pool_template` WHERE `entry` = @pool_id;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool_id, 5, 'Ethereum Jailor');

DELETE FROM `pool_creature` WHERE `guid` BETWEEN @GUID AND @GUID+20;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID+0, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+1, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+2, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+3, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+4, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+5, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+6, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+7, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+8, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+9, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+10, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+11, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+12, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+13, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+14, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+15, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+16, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+17, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+18, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+19, @pool_id, 0, 'Ethereum Jailor'),
(@Guid+20, @pool_id, 0, 'Ethereum Jailor');
