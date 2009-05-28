ALTER TABLE db_version CHANGE COLUMN required_7902_01_mangos_pool_creature required_7902_02_mangos_pool_gameobject bit;

ALTER TABLE `pool_gameobject` 
   ADD INDEX `idx_guid`(`guid`);