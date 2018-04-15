ALTER TABLE `game_event_creature` DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`,`eventEntry`);
ALTER TABLE `game_event_gameobject` DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`,`eventEntry`);
