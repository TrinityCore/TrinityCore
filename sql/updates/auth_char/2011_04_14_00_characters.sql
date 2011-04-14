ALTER TABLE corpse
    DROP PRIMARY KEY,
    DROP KEY `idx_type`,
    DROP KEY `instance`,
    DROP KEY `Idx_player`,
    DROP KEY `Idx_time`;

ALTER TABLE corpse
    ADD PRIMARY KEY (`corpseGuid`),
    ADD KEY `idx_type`(`corpseType`),
    ADD KEY `idx_instance`(`instanceId`),
    ADD KEY `idx_player`(`guid`),
    ADD KEY `idx_time`(`time`);

ALTER TABLE creature_respawn
    DROP PRIMARY KEY,
    DROP KEY `instance`;

ALTER TABLE creature_respawn
    ADD PRIMARY KEY (`guid`, `instanceId`),
    ADD KEY `idx_instance`(`instanceId`);

ALTER TABLE gameobject_respawn
    DROP PRIMARY KEY,
    DROP KEY `instance`;

ALTER TABLE gameobject_respawn
    ADD PRIMARY KEY (`guid`, `instanceId`),
    ADD KEY `idx_instance`(`instanceId`);
